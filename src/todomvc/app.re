type router = Js.t {. init : (string => unit) [@bs.meth]};

external routerMake : Js.t {..} => router =
  "Router" [@@bs.module "director"] [@@bs.new];

external unsafeJsonParse : string => 'a = "JSON.parse" [@@bs.val];

external getItem : string => option string =
  "localStorage.getItem" [@@bs.val] [@@bs.return null_to_opt];

external setItem : string => string => unit =
  "localStorage.setItem" [@@bs.val];

let namespace = "reason-react-todos";

let saveLocally todos =>
  switch (Js.Json.stringifyAny todos) {
  | None => ()
  | Some stringifiedTodos => setItem namespace stringifiedTodos
  };

module Top = {
  module TodoApp = {
    include ReactRe.Component.Stateful;
    let name = "TodoAppRe";
    type props = unit;
    type state = {
      nowShowing: TodoFooter.TodoFooter.showingState,
      editing: option string,
      newTodo: string,
      todos: list TodoItem.todo
    };
    let getInitialState _ /* props */ => {
      let todos =
        switch (getItem namespace) {
        | None => []
        | Some todos => unsafeJsonParse todos
        };
      {nowShowing: AllTodos, editing: None, newTodo: "", todos}
    };
    let componentDidMount {updater} => {
      let f1 {state} () => Some {...state, nowShowing: AllTodos};
      let f2 {state} () => Some {...state, nowShowing: ActiveTodos};
      let f3 {state} () => Some {...state, nowShowing: CompletedTodos};
      let router =
        routerMake {
          "/": updater f1,
          "/active": updater f2,
          "/completed": updater f3
        };
      router##init "/";
      None
    };
    let handleChange {state} event =>
      Some {
        ...state,
        newTodo: (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##value
      };
    let handleNewTodoKeyDown {state} event =>
      if (ReactEventRe.Keyboard.keyCode event === 13 /* enter key */) {
        ReactEventRe.Keyboard.preventDefault event;
        switch (String.trim state.newTodo) {
        | "" => None
        | nonEmptyValue =>
          let todos =
            state.todos @ [
              {
                id: string_of_float (Js.Date.now ()),
                title: nonEmptyValue,
                completed: false
              }
            ];
          saveLocally todos;
          Some {...state, newTodo: "", todos}
        }
      } else {
        None
      };
    let toggleAll {state} event => {
      let checked = (
                      ReactDOMRe.domElementToObj (
                        ReactEventRe.Form.target event
                      )
                    )##checked;
      let todos =
        List.map
          (fun todo => {...todo, TodoItem.completed: Js.to_bool checked})
          state.todos;
      saveLocally todos;
      Some {...state, todos}
    };
    let toggle todoToToggle {state} _ => {
      let todos =
        List.map
          (
            fun todo =>
              todo == todoToToggle ?
                {...todo, TodoItem.completed: not TodoItem.(todo.completed)} :
                todo
          )
          state.todos;
      saveLocally todos;
      Some {...state, todos}
    };
    let destroy todo {state} _ => {
      let todos =
        List.filter (fun candidate => candidate !== todo) state.todos;
      saveLocally todos;
      Some {...state, todos}
    };
    let edit todo {state} _ =>
      Some {...state, editing: Some TodoItem.(todo.id)};
    let save todoToSave {state} text => {
      let todos =
        List.map
          (
            fun todo =>
              todo == todoToSave ? {...todo, TodoItem.title: text} : todo
          )
          state.todos;
      Some {...state, editing: None, todos}
    };
    let cancel {state} _ => Some {...state, editing: None};
    let clearCompleted {state} _ => {
      let todos =
        List.filter (fun todo => not TodoItem.(todo.completed)) state.todos;
      saveLocally todos;
      Some {...state, todos}
    };
    let render {state, updater} => {
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
              onToggle=(updater (toggle todo))
              onDestroy=(updater (destroy todo))
              onEdit=(updater (edit todo))
              editing
              onSave=(updater (save todo))
              onCancel=(updater cancel)
            />
          }
        );
      let todosLength = List.length todos;
      let completedCount =
        todos |> List.filter (fun todo => TodoItem.(todo.completed)) |> List.length;
      let activeTodoCount = todosLength - completedCount;
      let footer =
        switch (activeTodoCount, completedCount) {
        | (0, 0) => ReactRe.nullElement
        | _ =>
          <TodoFooter
            count=activeTodoCount
            completedCount
            nowShowing=state.nowShowing
            onClearCompleted=(updater clearCompleted)
          />
        };
      let main =
        todosLength === 0 ?
          ReactRe.nullElement :
          <section className="main">
            <input
              className="toggle-all"
              _type="checkbox"
              onChange=(updater toggleAll)
              checked=(Js.Boolean.to_js_boolean (activeTodoCount === 0))
            />
            <ul className="todo-list">
              (ReactRe.arrayToElement (Array.of_list todoItems))
            </ul>
          </section>;
      <div>
        <header className="header">
          <h1> (ReactRe.stringToElement "todos") </h1>
          <input
            className="new-todo"
            placeholder="What needs to be done?"
            value=state.newTodo
            onKeyDown=(updater handleNewTodoKeyDown)
            onChange=(updater handleChange)
            autoFocus=Js.true_
          />
        </header>
        main
        footer
      </div>
    };
  };
  include ReactRe.CreateComponent TodoApp;
  let createElement = wrapProps ();
};

ReactDOMRe.renderToElementWithClassName <Top /> "todoapp";
