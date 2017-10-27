type router = {. "init": [@bs.meth] (string => unit)};

[@bs.val] external unsafeJsonParse : string => 'a = "JSON.parse";

let namespace = "reason-react-todos";

let saveLocally = (todos) =>
  switch (Js.Json.stringifyAny(todos)) {
  | None => ()
  | Some(stringifiedTodos) => Dom.Storage.(localStorage |> setItem(namespace, stringifiedTodos))
  };

module Top = {
  type action =
    /* router actions */
    | ShowAll
    | ShowActive
    | ShowCompleted
    /* todo actions */
    | NewTodoEnterKeyDown
    | NewTodoOtherKeyDown
    | ClearCompleted
    | Cancel
    | ChangeTodo(string)
    | Save(TodoItem.todo, string)
    | Edit(TodoItem.todo)
    | Destroy(TodoItem.todo)
    | Toggle(TodoItem.todo)
    | ToggleAll(bool);
  type state = {
    nowShowing: TodoFooter.showingState,
    editing: option(string),
    newTodo: string,
    todos: list(TodoItem.todo)
  };
  let changeTodo = (event) =>
    ChangeTodo(ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value);
  let newTodoKeyDown = (event) =>
    if (ReactEventRe.Keyboard.keyCode(event) === 13) {
      ReactEventRe.Keyboard.preventDefault(event);
      NewTodoEnterKeyDown
    } else {
      NewTodoOtherKeyDown
    };
  let toggleAll = (event) => {
    let checked = Js.to_bool(ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##checked);
    ToggleAll(checked)
  };
  let toggle = (todo, _event) => Toggle(todo);
  let destroy = (todo, _event) => Destroy(todo);
  let edit = (todo, _event) => Edit(todo);
  let save = (todoToSave, text) => Save(todoToSave, text);
  let cancel = (_event) => Cancel;
  let clearCompleted = (_event) => ClearCompleted;
  let component = ReasonReact.reducerComponent("TodoAppRe");
  let make = (_children) => {
    ...component,
    reducer: (action, state) =>
      switch action {
      /* router actions */
      | ShowAll => ReasonReact.Update({...state, nowShowing: AllTodos})
      | ShowActive => ReasonReact.Update({...state, nowShowing: ActiveTodos})
      | ShowCompleted => ReasonReact.Update({...state, nowShowing: CompletedTodos})
      /* todo actions */
      | Cancel => ReasonReact.Update({...state, editing: None})
      | ChangeTodo(text) => ReasonReact.Update({...state, newTodo: text})
      | NewTodoOtherKeyDown => ReasonReact.NoUpdate
      | NewTodoEnterKeyDown =>
        switch (String.trim(state.newTodo)) {
        | "" => ReasonReact.NoUpdate
        | nonEmptyValue =>
          let todos =
            state.todos
            @ [{id: string_of_float(Js.Date.now()), title: nonEmptyValue, completed: false}];
          saveLocally(todos);
          ReasonReact.Update({...state, newTodo: "", todos})
        }
      | ClearCompleted =>
        let todos = List.filter((todo) => ! TodoItem.(todo.completed), state.todos);
        ReasonReact.UpdateWithSideEffects({...state, todos}, ((_self) => saveLocally(todos)))
      | ToggleAll(checked) =>
        let todos = List.map((todo) => {...todo, TodoItem.completed: checked}, state.todos);
        ReasonReact.UpdateWithSideEffects({...state, todos}, ((_self) => saveLocally(todos)))
      | Save(todoToSave, text) =>
        let todos =
          List.map(
            (todo) => todo == todoToSave ? {...todo, TodoItem.title: text} : todo,
            state.todos
          );
        ReasonReact.UpdateWithSideEffects(
          {...state, editing: None, todos},
          ((_self) => saveLocally(todos))
        )
      | Edit(todo) => ReasonReact.Update({...state, editing: Some(TodoItem.(todo.id))})
      | Destroy(todo) =>
        let todos = List.filter((candidate) => candidate !== todo, state.todos);
        ReasonReact.UpdateWithSideEffects({...state, todos}, ((_self) => saveLocally(todos)))
      | Toggle(todoToToggle) =>
        let todos =
          List.map(
            (todo) =>
              todo == todoToToggle ?
                {...todo, TodoItem.completed: ! TodoItem.(todo.completed)} : todo,
            state.todos
          );
        ReasonReact.UpdateWithSideEffects({...state, todos}, ((_self) => saveLocally(todos)))
      },
    initialState: () => {
      let todos =
        switch Dom.Storage.(localStorage |> getItem(namespace)) {
        | None => []
        | Some(todos) => unsafeJsonParse(todos)
        };
      {nowShowing: AllTodos, editing: None, newTodo: "", todos}
    },
    didMount: ({reduce}) => {
      let router =
        DirectorRe.makeRouter({
          "/": reduce((_) => ShowAll),
          "/active": reduce((_) => ShowActive),
          "/completed": reduce((_) => ShowCompleted)
        });
      DirectorRe.init(router, "/");
      ReasonReact.NoUpdate
    },
    render: ({state, reduce}) => {
      let {todos, editing} = state;
      let todoItems =
        todos
        |> List.filter(
             (todo) =>
               TodoItem.(
                 switch state.nowShowing {
                 | ActiveTodos => ! todo.completed
                 | CompletedTodos => todo.completed
                 | AllTodos => true
                 }
               )
           )
        |> List.map(
             (todo) => {
               let editing =
                 switch editing {
                 | None => false
                 | Some(editing) => editing === TodoItem.(todo.id)
                 };
               <TodoItem
                 key=todo.id
                 todo
                 onToggle=(reduce(toggle(todo)))
                 onDestroy=(reduce(destroy(todo)))
                 onEdit=(reduce(edit(todo)))
                 editing
                 onSave=(reduce(save(todo)))
                 onCancel=(reduce(cancel))
               />
             }
           );
      let todosLength = List.length(todos);
      let completedCount =
        todos |> List.filter((todo) => TodoItem.(todo.completed)) |> List.length;
      let activeTodoCount = todosLength - completedCount;
      let footer =
        switch (activeTodoCount, completedCount) {
        | (0, 0) => ReasonReact.nullElement
        | _ =>
          <TodoFooter
            count=activeTodoCount
            completedCount
            nowShowing=state.nowShowing
            onClearCompleted=(reduce(clearCompleted))
          />
        };
      let main =
        todosLength === 0 ?
          ReasonReact.nullElement :
          <section className="main">
            <input
              className="toggle-all"
              _type="checkbox"
              onChange=(reduce(toggleAll))
              checked=(Js.Boolean.to_js_boolean(activeTodoCount === 0))
            />
            <ul className="todo-list"> (ReasonReact.arrayToElement(Array.of_list(todoItems))) </ul>
          </section>;
      <div>
        <header className="header">
          <h1> (ReasonReact.stringToElement("todos")) </h1>
          <input
            className="new-todo"
            placeholder="What needs to be done?"
            value=state.newTodo
            onKeyDown=(reduce(newTodoKeyDown))
            onChange=(reduce(changeTodo))
            autoFocus=Js.true_
          />
        </header>
        main
        footer
      </div>
    }
  };
};

ReactDOMRe.renderToElementWithClassName(<Top />, "todoapp");
