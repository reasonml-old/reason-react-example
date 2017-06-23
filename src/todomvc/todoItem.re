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

let component = ReasonReact.statefulComponent "TodoItemRe";

let setEditFieldRef r {ReasonReact.state: state} =>
  ReasonReact.SilentUpdate {...state, editFieldRef: Js.Null.to_opt r};

let make ::todo ::editing ::onDestroy ::onSave ::onEdit ::onToggle ::onCancel _children => {
  let handleSubmit _event {ReasonReact.state: state} =>
    switch (String.trim state.editText) {
    | "" =>
      onDestroy ();
      ReasonReact.NoUpdate
    | nonEmptyValue =>
      onSave nonEmptyValue;
      ReasonReact.Update {...state, editText: nonEmptyValue}
    };
  let handleKeyDown event self =>
    if (ReactEventRe.Keyboard.which event === escapeKey) {
      onCancel ();
      ReasonReact.Update {...self.ReasonReact.state, editText: todo.title}
    } else if (
      ReactEventRe.Keyboard.which event === enterKey
    ) {
      handleSubmit event self
    } else {
      ReasonReact.NoUpdate
    };
  let handleChange event {ReasonReact.state: state} =>
    editing ?
      ReasonReact.Update {
        ...state,
        editText: (ReactDOMRe.domElementToObj (ReactEventRe.Form.target event))##value
      } :
      ReasonReact.NoUpdate;
  let handleEdit _event {ReasonReact.state: state} => {
    onEdit ();
    ReasonReact.Update {...state, editText: todo.title}
  };
  {
    ...component,
    initialState: fun () => {editText: todo.title, editFieldRef: None, editing},
    willReceiveProps: fun {state} => {...state, editing},
    didUpdate: fun {oldSelf, newSelf} =>
      switch (oldSelf.state.editing, editing, newSelf.state.editFieldRef) {
      | (false, true, Some field) =>
        let node = ReactDOMRe.domElementToObj field;
        ignore (node##focus ());
        ignore (node##setSelectionRange node##value##length node##value##length)
      | _ => ()
      },
    render: fun {state, update} => {
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
          <label onDoubleClick=(update handleEdit)>
            (ReasonReact.stringToElement todo.title)
          </label>
          <button className="destroy" onClick=(fun _ => onDestroy ()) />
        </div>
        <input
          ref=(update setEditFieldRef)
          className="edit"
          value=state.editText
          onBlur=(update handleSubmit)
          onChange=(update handleChange)
          onKeyDown=(update handleKeyDown)
        />
      </li>
    }
  }
};
