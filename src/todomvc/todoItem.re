let escapeKey = 27;

let enterKey = 13;

type todo = {id: string, title: string, completed: bool};

external asKeyboardEvent : ReactEventRe.Synthetic.t => ReactEventRe.Keyboard.t = "%identity";

external asFocusEvent : ReactEventRe.Synthetic.t => ReactEventRe.Focus.t = "%identity";

external keyboardAsSyntheticEvent : ReactEventRe.Keyboard.t => ReactEventRe.Synthetic.t =
  "%identity";

external formAsSyntheticEvent : ReactEventRe.Form.t => ReactEventRe.Synthetic.t = "%identity";

external mouseAsSyntheticEvent : ReactEventRe.Mouse.t => ReactEventRe.Synthetic.t = "%identity";

external focusAsSyntheticEvent : ReactEventRe.Focus.t => ReactEventRe.Synthetic.t = "%identity";

module TodoItem = {
  include ReactRe.Component.Stateful.InstanceVars;
  let name = "TodoItemRe";
  type props = {
    todo,
    editing: bool,
    onDestroy: ReactEventRe.Synthetic.t => unit,
    onSave: string => unit,
    onEdit: unit => unit,
    onToggle: ReactEventRe.Synthetic.t => unit,
    onCancel: ReactEventRe.Synthetic.t => unit
  };
  type state = {editText: string};
  type instanceVars = {mutable editFieldRef: option ReactRe.reactRef};
  let getInstanceVars () => {editFieldRef: None};
  let getInitialState props => {editText: props.todo.title};
  let handleSubmit {props, state} (event: ReactEventRe.Synthetic.t) =>
    switch (String.trim state.editText) {
    | "" =>
      props.onDestroy (keyboardAsSyntheticEvent (asKeyboardEvent event));
      None
    | nonEmptyValue =>
      props.onSave nonEmptyValue;
      Some {editText: nonEmptyValue}
    };
  let handleEdit {props} _ /* event */ => {
    props.onEdit ();
    Some {editText: props.todo.title}
  };
  let handleKeyDown ({props} as componentBag) (event: ReactEventRe.Synthetic.t) =>
    if (ReactEventRe.Keyboard.which (asKeyboardEvent event) === escapeKey) {
      props.onCancel event;
      Some {editText: props.todo.title}
    } else if (
      ReactEventRe.Keyboard.which (asKeyboardEvent event) === enterKey
    ) {
      handleSubmit componentBag event
    } else {
      None
    };
  let handleChange {props} (event: ReactEventRe.Synthetic.t) =>
    switch (
      props.editing,
      ReasonJs.Dom.Element.asHtmlElement (ReactEventRe.Synthetic.target event)
    ) {
    | (true, Some el) => Some {editText: ReasonJs.Dom.HtmlElement.value el}
    | (true, None) => raise (Failure "Invalid event target passed to todoItem handleChange")
    | _ => None
    };
  let setEditFieldRef {instanceVars} r => instanceVars.editFieldRef = Some r;

  /**
   * Safely manipulate the DOM after updating the state when invoking
   * `props.onEdit()` in the `handleEdit` method above.
   * For more info refer to notes at https://facebook.github.io/react/docs/component-api.html#setstate
   * and https://facebook.github.io/react/docs/component-specs.html#updating-componentdidupdate
   */
  let componentDidUpdate ::prevProps prevState::_ {props, instanceVars} =>
    switch (prevProps.editing, props.editing, instanceVars.editFieldRef) {
    | (false, true, Some field) =>
      let node = ReactDOMRe.domElementToObj (ReactDOMRe.findDOMNode field);
      ignore (node##focus ());
      ignore (node##setSelectionRange node##value##length node##value##length);
      None
    | _ => None
    };
  let render {props, state, updater, refSetter} => {
    let {todo, editing, onDestroy, onToggle} = props;
    let className =
      [todo.completed ? "completed" : "", editing ? "editing" : ""] |> String.concat " ";
    <li className>
      <div className="view">
        <input
          className="toggle"
          _type="checkbox"
          checked=(Js.Boolean.to_js_boolean todo.completed)
          onChange=(fun event => onToggle (formAsSyntheticEvent event))
        />
        <label onDoubleClick=(updater handleEdit)> (ReactRe.stringToElement todo.title) </label>
        <button
          className="destroy"
          onClick=(fun event => onDestroy (mouseAsSyntheticEvent event))
        />
      </div>
      <input
        ref=(refSetter setEditFieldRef)
        className="edit"
        value=state.editText
        onBlur=(fun event => (updater handleSubmit) (focusAsSyntheticEvent event))
        onChange=(fun event => (updater handleChange) (formAsSyntheticEvent event))
        onKeyDown=(fun event => (updater handleKeyDown) (keyboardAsSyntheticEvent event))
      />
    </li>
  };
};

include ReactRe.CreateComponent TodoItem;

let createElement ::todo ::editing ::onDestroy ::onSave ::onEdit ::onToggle ::onCancel =>
  wrapProps {todo, editing, onDestroy, onSave, onEdit, onToggle, onCancel};
