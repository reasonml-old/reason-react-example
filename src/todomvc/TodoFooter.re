type showingState =
  | AllTodos
  | ActiveTodos
  | CompletedTodos;

let component = ReasonReact.statelessComponent("TodoFooterRe");

let make = (~count, ~completedCount, ~nowShowing, ~onClearCompleted, _children) => {
  ...component,
  render: (_self) => {
    let activeTodoWord = count === 1 ? "item" : "items";
    let clearButton =
      completedCount > 0 ?
        <button className="clear-completed" onClick=onClearCompleted>
          (ReasonReact.stringToElement("Clear completed"))
        </button> :
        ReasonReact.nullElement;
    let (all, active, completed) =
      switch nowShowing {
      | AllTodos => ("selected", "", "")
      | ActiveTodos => ("", "selected", "")
      | CompletedTodos => ("", "", "selected")
      };
    <footer className="footer">
      <span className="todo-count">
        <strong> (ReasonReact.stringToElement(string_of_int(count))) </strong>
        (ReasonReact.stringToElement(" " ++ (activeTodoWord ++ " left")))
      </span>
      <ul className="filters">
        <li> <a href="#/" className=all> (ReasonReact.stringToElement("All")) </a> </li>
        (ReasonReact.stringToElement(" "))
        <li>
          <a href="#/active" className=active> (ReasonReact.stringToElement("Active")) </a>
        </li>
        (ReasonReact.stringToElement(" "))
        <li>
          <a href="#/completed" className=completed>
            (ReasonReact.stringToElement("Completed"))
          </a>
        </li>
      </ul>
      clearButton
    </footer>
  }
};
