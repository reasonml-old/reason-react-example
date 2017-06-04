let escapeKey = 27;

let enterKey = 13;

type todo = {
  id: string,
  title: string,
  completed: bool
};

type state = {
  editText: string,
  editFieldRef: option Dom.element,
  editing: bool
};

let component = ReasonReact.createComponent "TodoItemRe";

let setEditFieldRef r state _self =>
  ReasonReact.SilentUpdate {...state, editFieldRef: Js.Null.to_opt r};

let make ::todo ::editing ::onDestroy ::onSave ::onEdit ::onToggle ::onCancel _children => {
  let handleSubmit _event state _self =>
    switch (String.trim state.editText) {
    | "" =>
      onDestroy ();
      ReasonReact.NoUpdate
    | nonEmptyValue =>
      onSave nonEmptyValue;
      ReasonReact.Update {...state, editText: nonEmptyValue}
    };
  let handleKeyDown event state self =>
    if (ReactEventRe.Keyboard.which event === escapeKey) {
      onCancel ();
      ReasonReact.Update {...state, editText: todo.title}
    } else if (
      ReactEventRe.Keyboard.which event === enterKey
    ) {
      handleSubmit event state self
    } else {
      ReasonReact.NoUpdate
    };
  let handleChange event state _self =>
    editing ?
      ReasonReact.Update {
        ...state,
        editText: (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##value
      } :
      ReasonReact.NoUpdate;
  let handleEdit _event state _self => {
    onEdit ();
    ReasonReact.Update {...state, editText: todo.title}
  };
  {
    ...component,
    initialState: fun () => {editText: todo.title, editFieldRef: None, editing},
    willReceiveProps: fun state _self => {...state, editing},
    didUpdate: fun ::previousState ::currentState _ =>
      switch (previousState.editing, editing, currentState.editFieldRef) {
      | (false, true, Some field) =>
        let node = ReactDOMRe.domElementToObj field;
        ignore (node##focus ());
        ignore (node##setSelectionRange node##value##length node##value##length)
      | _ => ()
      },
    render: fun state self => {
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
          <label onDoubleClick=(self.update handleEdit)>
            (ReasonReact.stringToElement todo.title)
          </label>
          <button className="destroy" onClick=(fun _ => onDestroy ()) />
        </div>
        <input
          ref=(self.update setEditFieldRef)
          className="edit"
          value=state.editText
          onBlur=(self.update handleSubmit)
          onChange=(self.update handleChange)
          onKeyDown=(self.update handleKeyDown)
        />
      </li>
    }
  }
};
