type showingState =
  | AllTodos
  | ActiveTodos
  | CompletedTodos;

type footerProps = {
  count: int,
  completedCount: int,
  nowShowing: showingState,
  onClearCompleted: ReactRe.event => unit
};

include
  ReactRe.CreateComponent {
    include ReactRe.Component;
    let name = "TodoFooterRe";
    type props = footerProps;
    let render {props} => {
      let activeTodoWord = props.count === 1 ? "item" : "items";
      let clearButton =
        props.completedCount > 0 ?
          <button className="clear-completed" onClick=props.onClearCompleted>
            (ReactRe.stringToElement "Clear completed")
          </button> :
          ReactRe.nullElement;
      let (all, active, completed) =
        switch props.nowShowing {
        | AllTodos => ("selected", "", "")
        | ActiveTodos => ("", "selected", "")
        | CompletedTodos => ("", "", "selected")
        };
      <footer className="footer">
        <span className="todo-count">
          <strong> (ReactRe.stringToElement (string_of_int props.count)) </strong>
          (ReactRe.stringToElement (" " ^ activeTodoWord ^ " left"))
        </span>
        <ul className="filters">
          <li> <a href="#/" className=all> (ReactRe.stringToElement "All") </a> </li>
          (ReactRe.stringToElement " ")
          <li> <a href="#/active" className=active> (ReactRe.stringToElement "Active") </a> </li>
          (ReactRe.stringToElement " ")
          <li>
            <a href="#/completed" className=completed> (ReactRe.stringToElement "Completed") </a>
          </li>
        </ul>
        clearButton
      </footer>
    };
  };

let createElement ::count ::completedCount ::nowShowing ::onClearCompleted =>
  wrapProps {count, completedCount, nowShowing, onClearCompleted};
