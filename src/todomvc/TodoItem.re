type todo = {
  id: string,
  title: string,
  completed: bool,
};

type state = {
  editText: string,
  editing: bool,
  editFieldRef: ref(option(Dom.element)),
};

type action =
  | Edit
  | Submit
  | KeyDown(int)
  | Change(string);

let component = ReasonReact.reducerComponent("TodoItemRe");

let setEditFieldRef = (r, {ReasonReact.state}) =>
  state.editFieldRef := Js.Nullable.to_opt(r);

let make =
    (
      ~todo,
      ~editing,
      ~onDestroy,
      ~onSave,
      ~onEdit,
      ~onToggle,
      ~onCancel,
      _children,
    ) => {
  let submitHelper = state =>
    switch (String.trim(state.editText)) {
    | "" => ReasonReact.SideEffects((_self => onDestroy()))
    | nonEmptyValue =>
      ReasonReact.UpdateWithSideEffects(
        {...state, editText: nonEmptyValue},
        (_self => onSave(nonEmptyValue)),
      )
    };
  {
    ...component,
    initialState: () => {
      editText: todo.title,
      editFieldRef: ref(None),
      editing,
    },
    reducer: action =>
      switch (action) {
      | Edit => (
          state => ReasonReact.Update({...state, editText: todo.title})
        )
      | Submit => submitHelper
      | Change(text) => (
          state =>
            editing ?
              ReasonReact.Update({...state, editText: text}) :
              ReasonReact.NoUpdate
        )
      | KeyDown(27) =>
        onCancel();
        (state => ReasonReact.Update({...state, editText: todo.title}));
      | KeyDown(13) => submitHelper
      | KeyDown(_) => (_state => ReasonReact.NoUpdate)
      },
    willReceiveProps: ({state}) => {...state, editing},
    didUpdate: ({oldSelf, newSelf}) =>
      switch (oldSelf.state.editing, editing, newSelf.state.editFieldRef^) {
      | (false, true, Some(field)) =>
        let node = ReactDOMRe.domElementToObj(field);
        ignore(node##focus());
        ignore(
          node##setSelectionRange(node##value##length, node##value##length),
        );
      | _ => ()
      },
    /* escape key */
    render: ({state, handle, send}) => {
      let className =
        [todo.completed ? "completed" : "", editing ? "editing" : ""]
        |> String.concat(" ");
      <li className>
        <div className="view">
          <input
            className="toggle"
            _type="checkbox"
            checked=(Js.Boolean.to_js_boolean(todo.completed))
            onChange=((_) => onToggle())
          />
          <label
            onDoubleClick=(
              _event => {
                onEdit();
                send(Edit);
              }
            )>
            (ReasonReact.stringToElement(todo.title))
          </label>
          <button className="destroy" onClick=((_) => onDestroy()) />
        </div>
        <input
          ref=(handle(setEditFieldRef))
          className="edit"
          value=state.editText
          onBlur=(_event => send(Submit))
          onChange=(
            event =>
              send(
                Change(
                  ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value,
                ),
              )
          )
          onKeyDown=(
            event => send(KeyDown(ReactEventRe.Keyboard.which(event)))
          )
        />
      </li>;
    },
  };
};
