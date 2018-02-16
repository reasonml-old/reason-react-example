let mergeDiff = [%raw
  {| function(
  prev,
  next,
  onRemove,
  trulyRemove
) {
  // bookkeeping for easier access of a key's index below. This is 2 allocations +
  // potentially triggering chrome hash map mode for objs (so it might be faster
  // to loop through and find a key's index each time), but I no longer care
  let prevKeyIndex = {};
  for (let i = 0; i < prev.length; i++) {
    prevKeyIndex[prev[i]] = i;
  }
  let nextKeyIndex = {};
  for (let i = 0; i < next.length; i++) {
    nextKeyIndex[next[i]] = i;
  }

  // first, an overly elaborate way of merging prev and next, eliminating
  // duplicates (in terms of keys). If there's dupe, keep the item in next).
  // This way of writing it saves allocations
  let ret = [];
  for (let i = 0; i < next.length; i++) {
    ret[i] = next[i];
  }
  for (let i = 0; i < prev.length; i++) {
    if (!Object.prototype.hasOwnProperty.call(nextKeyIndex, prev[i])) {
      // this is called my TM's `mergeAndSync`, which calls willLeave. We don't
      // merge in keys that the user desires to kill
      // const fill = onRemove(i, prev[i]);
      const asd = prev[i];
      onRemove(i, prev[i], () => trulyRemove(asd));
      const fill = prev[i];
      if (fill != null) {
        ret.push(fill);
      }
    }
  }

  // now all the items all present. Core sorting logic to have the right order
  return ret.sort((a, b) => {
    const nextOrderA = nextKeyIndex[a];
    const nextOrderB = nextKeyIndex[b];
    const prevOrderA = prevKeyIndex[a];
    const prevOrderB = prevKeyIndex[b];

    if (nextOrderA != null && nextOrderB != null) {
      // both keys in next
      return nextKeyIndex[a] - nextKeyIndex[b];
    } else if (prevOrderA != null && prevOrderB != null) {
      // both keys in prev
      return prevKeyIndex[a] - prevKeyIndex[b];
    } else if (nextOrderA != null) {
      // key a in next, key b in prev

      // how to determine the order between a and b? We find a "pivot" (term
      // abuse), a key present in both prev and next, that is sandwiched between
      // a and b. In the context of our above example, if we're comparing a and
      // d, b's (the only) pivot
      for (let i = 0; i < next.length; i++) {
        const pivot = next[i];
        if (!Object.prototype.hasOwnProperty.call(prevKeyIndex, pivot)) {
          continue;
        }

        if (nextOrderA < nextKeyIndex[pivot] && prevOrderB > prevKeyIndex[pivot]) {
          return -1;
        } else if (nextOrderA > nextKeyIndex[pivot] && prevOrderB < prevKeyIndex[pivot]) {
          return 1;
        }
      }
      // pluggable. default to: next bigger than prev
      return 1;
    }
    // prevOrderA, nextOrderB
    for (let i = 0; i < next.length; i++) {
      const pivot = next[i];
      if (!Object.prototype.hasOwnProperty.call(prevKeyIndex, pivot)) {
        continue;
      }
      if (nextOrderB < nextKeyIndex[pivot] && prevOrderA > prevKeyIndex[pivot]) {
        return 1;
      } else if (nextOrderB > nextKeyIndex[pivot] && prevOrderA < prevKeyIndex[pivot]) {
        return -1;
      }
    }
    // pluggable. default to: next bigger than prev
    return -1;
  });
}
|}
];

/*module Fragment = {
    [@bs.module "react"] external fragment : ReasonReact.reactClass = "Fragment";
    let make = children =>
      ReasonReact.wrapJsForReason(
        ~reactClass=fragment,
        ~props=Js.Obj.empty(),
        children,
      );
  };
  */
type animation =
  | Timeout(int)
  | Callback(unit => unit)
  | CSSClass(string, int);

module RR2 = {
  type action =
    | KillItem(string);
  let component = ReasonReact.reducerComponent("keyed");
  let make = (~keys, ~f, ~onLeave, ()) => {
    ...component,
    initialState: () => keys,
    willReceiveProps: self =>
      mergeDiff(
        self.state |> Belt.List.toArray, keys |> Belt.List.toArray, onLeave, (key) =>
        self.send(KillItem(key))
      )
      |> Belt.List.ofArray,
    reducer: (action, state) =>
      switch (action) {
      | KillItem(key) =>
        Js.log2("received kill order", key);
        let newState = Belt.List.keep(state, key1 => key1 !== key);
        ReasonReact.Update(newState);
      },
    render: ({state}) => {
      let children =
        Belt.List.map(state, key => <div key> (f(key)) </div>)
        |> Belt.List.toArray;
      <div>
        (ReasonReact.stringToElement("hi"))
        (ReasonReact.arrayToElement(children))
      </div>;
    },
  };
  let dynamic = (~keys, ~onLeave, f) =>
    ReasonReact.element(make(~keys, ~f, ~onLeave, ()));
};

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
      /*      let todoItems =
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
              */
      let displayableTodoKeys =
        Belt.List.keepMap(todos, todo =>
          TodoItem.(
            switch (state.nowShowing, todo.completed) {
            | (ActiveTodos, false)
            | (CompletedTodos, true)
            | (AllTodos, _) => Some(todo.id)
            | _ => None
            }
          )
        );
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
              (
                RR2.dynamic(
                  ~keys=displayableTodoKeys,
                  ~onLeave=
                    (i, b, cb) => {
                      /* TODO: callbacks are nice but troublesome; might kill an item but it's already back */
                      Js.log3("remove", i, b);
                      Js.Global.setTimeout(
                        () => {
                          Js.log3("kill now: ", i, b);
                          cb();
                        },
                        1000 * (i + 1),
                      )
                      |> ignore;
                      Timeout(1000);
                    },
                  key => {
                    let todo =
                      switch (Belt.List.getBy(todos, ({id}) => id === key)) {
                      | None => assert false
                      | Some(todo) => todo
                      };
                    let editing =
                      switch (editing) {
                      | None => false
                      | Some(editing) => editing === TodoItem.(todo.id)
                      };
                    <TodoItem
                      todo
                      onToggle=(_event => send(Toggle(todo)))
                      onDestroy=(_event => send(Destroy(todo)))
                      onEdit=(_event => send(Edit(todo)))
                      editing
                      onSave=(text => send(Save(todo, text)))
                      onCancel=(_event => send(Cancel))
                    />;
                  },
                )
              )
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
