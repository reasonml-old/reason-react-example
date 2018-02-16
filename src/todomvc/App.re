[@bs.val] external unsafeJsonParse : string => 'a = "JSON.parse";

let localStorageNamespace = "reason-react-todos";

let saveLocally = todos =>
  switch (Js.Json.stringifyAny(todos)) {
  | None => ()
  | Some(stringifiedTodos) =>
    Dom.Storage.(
      localStorage |> setItem(localStorageNamespace, stringifiedTodos)
    )
  };

module Top = {
  type action =
    | Navigate(TodoFooter.showingState)
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
    todos: list(TodoItem.todo),
  };
  let urlToShownPage = hash =>
    switch (hash) {
    | "active" => TodoFooter.ActiveTodos
    | "completed" => CompletedTodos
    | _ => AllTodos
    };
  let component = ReasonReact.reducerComponent("TodoAppRe");
  let make = _children => {
    ...component,
    reducer: (action, state) =>
      switch (action) {
      | Navigate(page) => ReasonReact.Update({...state, nowShowing: page})
      | Cancel => ReasonReact.Update({...state, editing: None})
      | ChangeTodo(text) => ReasonReact.Update({...state, newTodo: text})
      | NewTodoOtherKeyDown => ReasonReact.NoUpdate
      | NewTodoEnterKeyDown =>
        switch (String.trim(state.newTodo)) {
        | "" => ReasonReact.NoUpdate
        | nonEmptyValue =>
          let todos =
            state.todos
            @ [
              {
                id: string_of_float(Js.Date.now()),
                title: nonEmptyValue,
                completed: false,
              },
            ];
          saveLocally(todos);
          ReasonReact.Update({...state, newTodo: "", todos});
        }
      | ClearCompleted =>
        let todos =
          List.filter(todo => ! TodoItem.(todo.completed), state.todos);
        ReasonReact.UpdateWithSideEffects(
          {...state, todos},
          (_self => saveLocally(todos)),
        );
      | ToggleAll(checked) =>
        let todos =
          List.map(
            todo => {...todo, TodoItem.completed: checked},
            state.todos,
          );
        ReasonReact.UpdateWithSideEffects(
          {...state, todos},
          (_self => saveLocally(todos)),
        );
      | Save(todoToSave, text) =>
        let todos =
          List.map(
            todo =>
              todo == todoToSave ? {...todo, TodoItem.title: text} : todo,
            state.todos,
          );
        ReasonReact.UpdateWithSideEffects(
          {...state, editing: None, todos},
          (_self => saveLocally(todos)),
        );
      | Edit(todo) =>
        ReasonReact.Update({...state, editing: Some(TodoItem.(todo.id))})
      | Destroy(todo) =>
        let todos = List.filter(candidate => candidate !== todo, state.todos);
        ReasonReact.UpdateWithSideEffects(
          {...state, todos},
          (_self => saveLocally(todos)),
        );
      | Toggle(todoToToggle) =>
        let todos =
          List.map(
            todo =>
              todo == todoToToggle ?
                {...todo, TodoItem.completed: ! TodoItem.(todo.completed)} :
                todo,
            state.todos,
          );
        ReasonReact.UpdateWithSideEffects(
          {...state, todos},
          (_self => saveLocally(todos)),
        );
      },
    initialState: () => {
      let todos =
        switch (Dom.Storage.(localStorage |> getItem(localStorageNamespace))) {
        | None => []
        | Some(todos) => unsafeJsonParse(todos)
        };
      {
        nowShowing:
          urlToShownPage(ReasonReact.Router.dangerouslyGetInitialUrl().hash),
        editing: None,
        newTodo: "",
        todos,
      };
    },
    subscriptions: self => [
      Sub(
        () =>
          ReasonReact.Router.watchUrl(url =>
            self.send(Navigate(urlToShownPage(url.hash)))
          ),
        ReasonReact.Router.unwatchUrl,
      ),
    ],
    /* router actions */
    render: ({state, send}) => {
      let {todos, editing} = state;
      let todoItems =
        todos
        |> List.filter(todo =>
             TodoItem.(
               switch (state.nowShowing) {
               | ActiveTodos => ! todo.completed
               | CompletedTodos => todo.completed
               | AllTodos => true
               }
             )
           )
        |> List.map(todo => {
             let editing =
               switch (editing) {
               | None => false
               | Some(editing) => editing === TodoItem.(todo.id)
               };
             <TodoItem
               key=todo.id
               todo
               onToggle=(_event => send(Toggle(todo)))
               onDestroy=(_event => send(Destroy(todo)))
               onEdit=(_event => send(Edit(todo)))
               editing
               onSave=(text => send(Save(todo, text)))
               onCancel=(_event => send(Cancel))
             />;
           });
      let todosLength = List.length(todos);
      let completedCount =
        todos |> List.filter(todo => TodoItem.(todo.completed)) |> List.length;
      let activeTodoCount = todosLength - completedCount;
      let footer =
        switch (activeTodoCount, completedCount) {
        | (0, 0) => ReasonReact.nullElement
        | _ =>
          <TodoFooter
            count=activeTodoCount
            completedCount
            nowShowing=state.nowShowing
            onClearCompleted=(_event => send(ClearCompleted))
          />
        };
      let main =
        todosLength === 0 ?
          ReasonReact.nullElement :
          <section className="main">
            <input
              className="toggle-all"
              _type="checkbox"
              onChange=(
                event => {
                  let checked =
                    Js.to_bool(
                      ReactDOMRe.domElementToObj(
                        ReactEventRe.Form.target(event),
                      )##checked,
                    );
                  send(ToggleAll(checked));
                }
              )
              checked=(Js.Boolean.to_js_boolean(activeTodoCount === 0))
            />
            <ul className="todo-list">
              (ReasonReact.arrayToElement(Array.of_list(todoItems)))
            </ul>
          </section>;
      <div>
        <header className="header">
          <h1> (ReasonReact.stringToElement("todos")) </h1>
          <input
            className="new-todo"
            placeholder="What needs to be done?"
            value=state.newTodo
            onKeyDown=(
              event =>
                if (ReactEventRe.Keyboard.keyCode(event) === 13) {
                  ReactEventRe.Keyboard.preventDefault(event);
                  send(NewTodoEnterKeyDown);
                } else {
                  send(NewTodoOtherKeyDown);
                }
            )
            onChange=(
              event =>
                send(
                  ChangeTodo(
                    ReactDOMRe.domElementToObj(
                      ReactEventRe.Form.target(event),
                    )##value,
                  ),
                )
            )
            autoFocus=Js.true_
          />
        </header>
        main
        footer
      </div>;
    },
  };
};

ReactDOMRe.renderToElementWithClassName(<Top />, "todoapp");
