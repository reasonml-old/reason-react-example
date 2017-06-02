type router = Js.t {. init : (string => unit) [@bs.meth]};

external unsafeJsonParse : string => 'a = "JSON.parse" [@@bs.val];

external getItem : string => option string =
  "localStorage.getItem" [@@bs.val] [@@bs.return null_to_opt];

external setItem : string => string => unit = "localStorage.setItem" [@@bs.val];

let namespace = "reason-react-todos";

let saveLocally todos =>
  switch (Js.Json.stringifyAny todos) {
  | None => ()
  | Some stringifiedTodos => setItem namespace stringifiedTodos
  };

module Top = {
  type state = {
    nowShowing: TodoFooter.showingState,
    editing: option string,
    newTodo: string,
    todos: list TodoItem.todo
  };
  let handleChange event state _self =>
    ReasonReact.Update {
      ...state,
      newTodo: (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##value
    };
  let handleNewTodoKeyDown event state _self =>
    if (ReactEventRe.Keyboard.keyCode event === 13 /* enter key */) {
      ReactEventRe.Keyboard.preventDefault event;
      switch (String.trim state.newTodo) {
      | "" => ReasonReact.NoUpdate
      | nonEmptyValue =>
        let todos =
          state.todos @ [
            {id: string_of_float (Js.Date.now ()), title: nonEmptyValue, completed: false}
          ];
        saveLocally todos;
        ReasonReact.Update {...state, newTodo: "", todos}
      }
    } else {
      ReasonReact.NoUpdate
    };
  let toggleAll event state _self => {
    let checked = (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##checked;
    let todos =
      List.map (fun todo => {...todo, TodoItem.completed: Js.to_bool checked}) state.todos;
    saveLocally todos;
    ReasonReact.Update {...state, todos}
  };
  let toggle todoToToggle _event state _self => {
    let todos =
      List.map
        (
          fun todo =>
            todo == todoToToggle ?
              {...todo, TodoItem.completed: not TodoItem.(todo.completed)} : todo
        )
        state.todos;
    saveLocally todos;
    ReasonReact.Update {...state, todos}
  };
  let destroy todo _event state _self => {
    let todos = List.filter (fun candidate => candidate !== todo) state.todos;
    saveLocally todos;
    ReasonReact.Update {...state, todos}
  };
  let edit todo _event state _self =>
    ReasonReact.Update {...state, editing: Some TodoItem.(todo.id)};
  let save todoToSave text state _self => {
    let todos =
      List.map
        (fun todo => todo == todoToSave ? {...todo, TodoItem.title: text} : todo) state.todos;
    saveLocally todos;
    ReasonReact.Update {...state, editing: None, todos}
  };
  let cancel _event state _self => ReasonReact.Update {...state, editing: None};
  let clearCompleted _event state _self => {
    let todos = List.filter (fun todo => not TodoItem.(todo.completed)) state.todos;
    saveLocally todos;
    ReasonReact.Update {...state, todos}
  };
  let component = ReasonReact.createComponent "TodoAppRe";
  let make _children => {
    ...component,
    initialState: fun () => {
      let todos =
        switch (getItem namespace) {
        | None => []
        | Some todos => unsafeJsonParse todos
        };
      {nowShowing: AllTodos, editing: None, newTodo: "", todos}
    },
    didMount: fun _state self => {
      let f1 () state _self => ReasonReact.Update {...state, nowShowing: AllTodos};
      let f2 () state _self => ReasonReact.Update {...state, nowShowing: ActiveTodos};
      let f3 () state _self => ReasonReact.Update {...state, nowShowing: CompletedTodos};
      let router =
        DirectorRe.makeRouter {
          "/": self.update f1,
          "/active": self.update f2,
          "/completed": self.update f3
        };
      DirectorRe.init router "/";
      ReasonReact.NoUpdate
    },
    render: fun state self => {
      let {todos, editing} = state;
      let todoItems =
        todos |>
        List.filter (
          fun todo =>
            TodoItem.(
              switch state.nowShowing {
              | ActiveTodos => not todo.completed
              | CompletedTodos => todo.completed
              | AllTodos => true
              }
            )
        ) |>
        List.map (
          fun todo => {
            let editing =
              switch editing {
              | None => false
              | Some editing => editing === TodoItem.(todo.id)
              };
            <TodoItem
              key=todo.id
              todo
              onToggle=(self.update (toggle todo))
              onDestroy=(self.update (destroy todo))
              onEdit=(self.update (edit todo))
              editing
              onSave=(self.update (save todo))
              onCancel=(self.update cancel)
            />
          }
        );
      let todosLength = List.length todos;
      let completedCount =
        todos |> List.filter (fun todo => TodoItem.(todo.completed)) |> List.length;
      let activeTodoCount = todosLength - completedCount;
      let footer =
        switch (activeTodoCount, completedCount) {
        | (0, 0) => ReasonReact.nullElement
        | _ =>
          <TodoFooter
            count=activeTodoCount
            completedCount
            nowShowing=state.nowShowing
            onClearCompleted=(self.update clearCompleted)
          />
        };
      let main =
        todosLength === 0 ?
          ReasonReact.nullElement :
          <section className="main">
            <input
              className="toggle-all"
              _type="checkbox"
              onChange=(self.update toggleAll)
              checked=(Js.Boolean.to_js_boolean (activeTodoCount === 0))
            />
            <ul className="todo-list"> (ReasonReact.arrayToElement (Array.of_list todoItems)) </ul>
          </section>;
      <div>
        <header className="header">
          <h1> (ReasonReact.stringToElement "todos") </h1>
          <input
            className="new-todo"
            placeholder="What needs to be done?"
            value=state.newTodo
            onKeyDown=(self.update handleNewTodoKeyDown)
            onChange=(self.update handleChange)
            autoFocus=Js.true_
          />
        </header>
        main
        footer
      </div>
    }
  };
};

ReactDOMRe.renderToElementWithClassName <Top /> "todoapp";
