type showingState =
  | AllTodos
  | ActiveTodos
  | CompletedTodos;

let component = ReasonReact.statelessComponent("TodoFooterRe");

let push = (path, event) => {
  ReactEventRe.Mouse.preventDefault(event);
  ReasonReact.Router.push("#" ++ path);
};

let make =
    (~count, ~completedCount, ~nowShowing, ~onClearCompleted, _children) => {
  ...component,
  render: _self => {
    let activeTodoWord = count === 1 ? "item" : "items";
    let clearButton =
      completedCount > 0 ?
        <button className="clear-completed" onClick=onClearCompleted>
          (ReasonReact.string("Clear completed"))
        </button> :
        ReasonReact.null;
    let (all, active, completed) =
      switch (nowShowing) {
      | AllTodos => ("selected", "", "")
      | ActiveTodos => ("", "selected", "")
      | CompletedTodos => ("", "", "selected")
      };
    <footer className="footer">
      <span className="todo-count">
        <strong> (ReasonReact.string(string_of_int(count))) </strong>
        (ReasonReact.string(" " ++ activeTodoWord ++ " left"))
      </span>
      <ul className="filters">
        <li>
          <a onClick=(push("")) className=all>
            (ReasonReact.string("All"))
          </a>
        </li>
        (ReasonReact.string(" "))
        <li>
          <a onClick=(push("active")) className=active>
            (ReasonReact.string("Active"))
          </a>
        </li>
        (ReasonReact.string(" "))
        <li>
          <a onClick=(push("completed")) className=completed>
            (ReasonReact.string("Completed"))
          </a>
        </li>
      </ul>
      clearButton
    </footer>;
  },
};
