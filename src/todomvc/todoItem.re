let escapeKey = 27;

let enterKey = 13;

type todo = {id: string, title: string, completed: bool};

module TodoItem = {
  include ReactRe.Component.Stateful.InstanceVars;
  let name = "TodoItemRe";
  type props = {
    todo,
    editing: bool,
    onDestroy: unit => unit,
    onSave: string => unit,
    onEdit: unit => unit,
    onToggle: unit => unit,
    onCancel: unit => unit
  };
  type state = {editText: string};
  type instanceVars = {mutable editFieldRef: option Dom.element};
  let getInstanceVars () => {editFieldRef: None};
  let getInitialState props => {editText: props.todo.title};
  let handleSubmit {props, state} _ =>
    switch (String.trim state.editText) {
    | "" =>
      props.onDestroy ();
      None
    | nonEmptyValue =>
      props.onSave nonEmptyValue;
      Some {editText: nonEmptyValue}
    };
  let handleEdit {props} _ /* event */ => {
    props.onEdit ();
    Some {editText: props.todo.title}
  };
  let handleKeyDown ({props} as componentBag) event =>
    if (ReactEventRe.Keyboard.which event === escapeKey) {
      props.onCancel ();
      Some {editText: props.todo.title}
    } else if (
      ReactEventRe.Keyboard.which event === enterKey
    ) {
      handleSubmit componentBag ()
    } else {
      None
    };
  let handleChange {props} event =>
    props.editing ?
      Some {editText: (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##value} : None;
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
      let node = ReactDOMRe.domElementToObj field;
      ignore (node##focus ());
      ignore (node##setSelectionRange node##value##length node##value##length);
      None
    | _ => None
    };
  let render {props, state, updater, handler} => {
    let {todo, editing, onDestroy, onToggle} = props;
    let className =
      [todo.completed ? "completed" : "", editing ? "editing" : ""] |> String.concat " ";
    <li className>
      <div className="view">
        <input
          className="toggle"
          _type="checkbox"
          checked=(Js.Boolean.to_js_boolean todo.completed)
          onChange=(fun _ => onToggle ())
        />
        <label onDoubleClick=(updater handleEdit)> (ReactRe.stringToElement todo.title) </label>
        <button className="destroy" onClick=(fun _ => onDestroy ()) />
      </div>
      <input
        ref=(handler setEditFieldRef)
        className="edit"
        value=state.editText
        onBlur=(updater handleSubmit)
        onChange=(updater handleChange)
        onKeyDown=(updater handleKeyDown)
      />
    </li>
  };
};

include ReactRe.CreateComponent TodoItem;

let createElement ::todo ::editing ::onDestroy ::onSave ::onEdit ::onToggle ::onCancel =>
  wrapProps {todo, editing, onDestroy, onSave, onEdit, onToggle, onCancel};
