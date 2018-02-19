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

/*mergeDiff(self.state |> Belt.List.toArray, keys |> Belt.List.toArray, onLeave, key =>
    self.send(KillItem(key))
  )
  |> Belt.List.ofArray;
  */
type animation =
  | Timeout(int)
  | Callback(unit => unit)
  | CSSClass(string, int);

module RR2 = {
  module Animated = {
    type t =
      | Mounting
      | Mounted
      | Unmounting;
  };
};

[@bs.val] external unsafeJsonParse : string => list(TodoItem.todo) = "JSON.parse";

let localStorageNamespace = "reason-react-todos";

let saveLocally = todos => {
  let todos = Belt.List.map(todos, snd);
  switch (Js.Json.stringifyAny(todos)) {
  | None => ()
  | Some(stringifiedTodos) =>
    Dom.Storage.(localStorage |> setItem(localStorageNamespace, stringifiedTodos))
  };
};

/* TODO:

   - new item animation
   - deletion animation
   - deletion while deleting animation
   - delete item while it's being created
   
   - change view animation
   - reorder animation

   - filter items animation
   - clear all animation

   */
/*[(t, a), (t2, c), (t3, b)]
  [b, c]

  willReceiveProps: a => {

  }
  */
module Top = {
  type howAnimatedIn =
    | NewItem
    | ChangedView;
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
    | TrulyDestroy(TodoItem.todo)
    | Toggle(TodoItem.todo)
    | ToggleAll(bool);
  type state = {
    nowShowing: TodoFooter.showingState,
    editing: option(string),
    newTodo: string,
    todos: list((RR2.Animated.t, TodoItem.todo)),
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
    initialState: () => {
      let todos =
        switch (Dom.Storage.(localStorage |> getItem(localStorageNamespace))) {
        | None => []
        | Some(todos) => unsafeJsonParse(todos)
        };
      {
        nowShowing: urlToShownPage(ReasonReact.Router.dangerouslyGetInitialUrl().hash),
        editing: None,
        newTodo: "",
        todos: Belt.List.map(todos, todo => (RR2.Animated.Mounted, todo)),
      };
    },
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
              (
                Mounting,
                {id: string_of_float(Js.Date.now()), title: nonEmptyValue, completed: false},
              ),
            ];
          saveLocally(todos);
          ReasonReact.Update({...state, newTodo: "", todos});
        }
      | ClearCompleted =>
        /* TODO: what if we need a clear animation that's different from the typical unmounting one */
        /*        let todos =
                            Belt.List.filter(state.todos, todo =>
                              switch (todo) {
                              | Mounting(todo) => ! TodoItem.(todo.completed)
                              | Mounted(todo) => ! TodoItem.(todo.completed)
                              | Unmounting(todo) => ! TodoItem.(todo.completed)
                              }
                            );
                  */
        let todos =
          Belt.List.map(state.todos, ((transition, todo)) =>
            switch (transition, todo) {
            | (Mounting | Mounted | Unmounting, {completed: true}) => (
                RR2.Animated.Unmounting,
                todo,
              )
            | todo => todo
            }
          );
        ReasonReact.UpdateWithSideEffects({...state, todos}, (_self => saveLocally(todos)));
      | ToggleAll(checked) =>
        let todos =
          Belt.List.map(state.todos, ((transition, todo)) =>
            (transition, {...todo, TodoItem.completed: checked})
          );
        ReasonReact.UpdateWithSideEffects({...state, todos}, (_self => saveLocally(todos)));
      | Save(todoToSave, text) =>
        let todos =
          Belt.List.map(state.todos, ((transition, todo)) =>
            todo == todoToSave ?
              (transition, {...todo, TodoItem.title: text}) : (transition, todo)
          );
        ReasonReact.UpdateWithSideEffects(
          {...state, editing: None, todos},
          (_self => saveLocally(todos)),
        );
      | Edit(todo) => ReasonReact.Update({...state, editing: Some(TodoItem.(todo.id))})
      | Destroy(todo) =>
        let todos =
          Belt.List.map(state.todos, ((transition, candidate)) =>
            if (candidate.id === todo.id) {
              (RR2.Animated.Unmounting, candidate);
            } else {
              (transition, candidate);
            }
          );
        ReasonReact.UpdateWithSideEffects(
          {...state, todos},
          (
            self => {
              let todos =
                Belt.List.keep(state.todos, ((_, candidate)) => candidate.id !== todo.id);
              saveLocally(todos);
              Js.Global.setTimeout(() => self.ReasonReact.send(TrulyDestroy(todo)), 5000)
              |> ignore;
            }
          ),
        );
      | TrulyDestroy(todo) =>
        let todos = Belt.List.keep(state.todos, ((_, candidate)) => candidate.id !== todo.id);
        ReasonReact.Update({...state, todos});
      | Toggle(todoToToggle) =>
        let todos =
          Belt.List.map(state.todos, ((transition, todo)) =>
            todo == todoToToggle ?
              (transition, {...todo, TodoItem.completed: ! TodoItem.(todo.completed)}) :
              (transition, todo)
          );
        ReasonReact.UpdateWithSideEffects({...state, todos}, (_self => saveLocally(todos)));
      },
    subscriptions: self => [
      Sub(
        () => ReasonReact.Router.watchUrl(url => self.send(Navigate(urlToShownPage(url.hash)))),
        ReasonReact.Router.unwatchUrl,
      ),
    ],
    /* router actions */
    render: ({state, send}) => {
      let {todos, editing} = state;
      let todoItems =
        Belt.List.keepMap(todos, ((transition, todo)) =>
          TodoItem.(
            switch (state.nowShowing, todo.completed) {
            | (ActiveTodos, false)
            | (CompletedTodos, true)
            | (AllTodos, _) =>
              let editing =
                switch (editing) {
                | None => false
                | Some(editing) => editing === todo.id
                };
              let todo =
                switch (transition) {
                | Mounting =>
                  <div key=todo.id className="fade-in">
                    <div> (ReasonReact.stringToElement("imagine an animation here!")) </div>
                    <TodoItem
                      todo
                      onToggle=(_event => send(Toggle(todo)))
                      onDestroy=(_event => send(Destroy(todo)))
                      onEdit=(_event => send(Edit(todo)))
                      editing
                      onSave=(text => send(Save(todo, text)))
                      onCancel=(_event => send(Cancel))
                    />
                  </div>
                | Unmounting =>
                  <div key=todo.id className="fade-out">
                    <div> (ReasonReact.stringToElement("unmounting!")) </div>
                    <TodoItem
                      todo
                      onToggle=(_event => send(Toggle(todo)))
                      onDestroy=(_event => send(Destroy(todo)))
                      onEdit=(_event => send(Edit(todo)))
                      editing
                      onSave=(text => send(Save(todo, text)))
                      onCancel=(_event => send(Cancel))
                    />
                  </div>
                | _ =>
                  <TodoItem
                    key=todo.id
                    todo
                    onToggle=(_event => send(Toggle(todo)))
                    onDestroy=(_event => send(Destroy(todo)))
                    onEdit=(_event => send(Edit(todo)))
                    editing
                    onSave=(text => send(Save(todo, text)))
                    onCancel=(_event => send(Cancel))
                  />
                };
              Some(todo);
            | _ => None
            }
          )
        )
        |> Belt.List.toArray
        |> ReasonReact.arrayToElement;
      let todosLength = List.length(todos);
      let completedCount =
        Belt.List.keep(todos, ((_, todo)) => TodoItem.(todo.completed)) |> List.length;
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
                      ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##checked,
                    );
                  send(ToggleAll(checked));
                }
              )
              checked=(Js.Boolean.to_js_boolean(activeTodoCount === 0))
            />
            <ul className="todo-list"> todoItems </ul>
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
                    ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value,
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
