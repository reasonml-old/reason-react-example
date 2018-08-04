module GlobalState = {
  type state = {
    count1: int,
    count2: int,
    toggle: bool,
  };
  let initial = {count1: 0, count2: 0, toggle: false};
};

module Counter1 = {
  open GlobalState;
  let component = ReasonReact.statelessComponent("Counter1");
  let make = (~state, ~update, _children) => {
    ...component,
    render: _ =>
      <div>
        <button
          onClick=(_ => update(state => {...state, count1: state.count1 + 1}))>
          (ReasonReact.string("+"))
        </button>
        <button
          onClick=(_ => update(state => {...state, count1: state.count1 - 1}))>
          (ReasonReact.string("-"))
        </button>
        (ReasonReact.string(" counter:" ++ string_of_int(state.count1)))
      </div>,
  };
};

module Counter2 = {
  open GlobalState;
  let component = ReasonReact.statelessComponent("Counter2");
  let make = (~state, ~update, _children) => {
    ...component,
    render: _ =>
      <div>
        <button
          onClick=(_ => update(state => {...state, count2: state.count2 + 1}))>
          (ReasonReact.string("+"))
        </button>
        <button
          onClick=(_ => update(state => {...state, count2: state.count2 - 1}))>
          (ReasonReact.string("-"))
        </button>
        (ReasonReact.string(" counter:" ++ string_of_int(state.count2)))
      </div>,
  };
};

module Toggle = {
  open GlobalState;
  let component = ReasonReact.statelessComponent("Toggle");
  let make = (~state, ~update, _children) => {
    ...component,
    render: _ =>
      <div>
        <button
          onClick=(_ => update(state => {...state, toggle: !state.toggle}))>
          (ReasonReact.string("Toggle"))
        </button>
        (ReasonReact.string(" toggle:" ++ string_of_bool(state.toggle)))
      </div>,
  };
};

module GlobalStateExample = {
  let component = ReasonReact.reducerComponent("GlobalStateExample");
  let make = _children => {
    ...component,
    initialState: () => GlobalState.initial,
    reducer: (fn, state) => Update(fn(state)),
    render: ({state, send}) => {
      let update = foo => send(foo);
      <div>
        <Counter1 state update />
        <Counter2 state update />
        <Counter2 state update />
        <Toggle state update />
      </div>;
    },
  };
};

module LocalCounter = {
  type state = int;
  type action =
    | Incr
    | Decr;
  let component = ReasonReact.reducerComponent("LocalCounter");
  let make = _children => {
    ...component,
    initialState: () => 0,
    reducer: (action, state) =>
      switch (action) {
      | Incr => Update(state + 1)
      | Decr => Update(state - 1)
      },
    render: ({state, send}) =>
      <div>
        <button onClick=(_ => send(Incr))>
          (ReasonReact.string("+"))
        </button>
        <button onClick=(_ => send(Decr))>
          (ReasonReact.string("-"))
        </button>
        (ReasonReact.string(" counter:" ++ string_of_int(state)))
      </div>,
  };
};

module LocalToggle = {
  type state = bool;
  type action =
    | Toggle;
  let component = ReasonReact.reducerComponent("LocalToggle");
  let make = _children => {
    ...component,
    initialState: () => false,
    reducer: (action, state) =>
      switch (action) {
      | Toggle => Update(!state)
      },
    render: ({state, send}) =>
      <div>
        <button onClick=(_ => send(Toggle))>
          (ReasonReact.string("Toggle"))
        </button>
        (ReasonReact.string(" toggle:" ++ string_of_bool(state)))
      </div>,
  };
};

module LocalStateExample = {
  let component = ReasonReact.statelessComponent("LocalStateExample");
  let make = _children => {
    ...component,
    render: _ =>
      <div>
        <LocalCounter />
        <LocalCounter />
        <LocalCounter />
        <LocalToggle />
      </div>,
  };
};

module TextInput = {
  type state = string;
  type action =
    | Text(string);
  let component = ReasonReact.reducerComponent("TextInput");
  let textOfEvent = e => ReactEvent.Form.target(e)##value;
  let make = (~onChange=_ => (), ~showText=x => x, ~initial="", _children) => {
    ...component,
    initialState: () => initial,
    reducer: (action, _state) =>
      switch (action) {
      | Text(text) => Update(text)
      },
    render: ({state, send}) =>
      <input
        value=(showText(state))
        onChange=(
          event => {
            let text = textOfEvent(event);
            send(Text(text));
            onChange(text);
          }
        )
      />,
  };
};

module Spring = {
  type state = {
    animation: SpringAnimation.t,
    value: float,
    target: float,
  };
  type action =
    | Click
    | Value(float);
  let component = ReasonReact.reducerComponent("Spring");
  let make = (~renderValue, _children) => {
    ...component,
    initialState: () => {
      animation: SpringAnimation.create(0.0),
      value: 0.0,
      target: 1.0,
    },
    didMount: ({state, send, onUnmount}) => {
      state.animation
      |> SpringAnimation.setOnChange(
           ~onChange=value => send(Value(value)),
           ~finalValue=state.target,
         );
      onUnmount(() => SpringAnimation.stop(state.animation));
    },
    reducer: (action, state) =>
      switch (action) {
      | Click =>
        let target = state.target == 0.0 ? 1.0 : 0.0;
        UpdateWithSideEffects(
          {...state, target},
          (_ => state.animation |> SpringAnimation.setFinalValue(target)),
        );
      | Value(value) => Update({...state, value})
      },
    render: ({state, send}) =>
      <div>
        <button onClick=(_ => send(Click))>
          (ReasonReact.string("target: " ++ string_of_float(state.target)))
        </button>
        <div> (renderValue(state.value)) </div>
      </div>,
  };
};

module SimpleSpring = {
  let renderValue = value =>
    ReasonReact.string(Printf.sprintf("value: %.3f", value));
  let component = ReasonReact.statelessComponent("SimpleSpring");
  let make = _children => {...component, render: _ => <Spring renderValue />};
};

module AnimatedTextInput = {
  let shrinkText = (~text, ~value) =>
    value >= 1.0 ?
      text :
      {
        let len = Js.Math.round(value *. float_of_int(String.length(text)));
        String.sub(text, 0, int_of_float(len));
      };
  let renderValue = value =>
    <TextInput
      showText=(text => shrinkText(~text, ~value))
      initial="edit this or click target"
    />;
  let component = ReasonReact.statelessComponent("AnimatedTextInput");
  let make = _children => {...component, render: _ => <Spring renderValue />};
};

module TextInputRemote = {
  type state = string;
  type action =
    | Text(string)
    | Reset;
  let component = ReasonReact.reducerComponent("TextInputRemote");
  let textOfEvent = e => ReactEvent.Form.target(e)##value;
  let make =
      (
        ~remoteAction,
        ~onChange=_ => (),
        ~showText=x => x,
        ~initial="",
        _children,
      ) => {
    ...component,
    initialState: () => initial,
    didMount: ({send, onUnmount}) => {
      let token = RemoteAction.subscribe(~send, remoteAction);
      let cleanup = () =>
        switch (token) {
        | Some(token) => RemoteAction.unsubscribe(token)
        | None => ()
        };
      onUnmount(cleanup);
    },
    reducer: (action, _state) =>
      switch (action) {
      | Text(text) => Update(text)
      | Reset => Update("the text has been reset")
      },
    render: ({state, send}) =>
      <input
        value=(showText(state))
        onChange=(
          event => {
            let text = textOfEvent(event);
            send(Text(text));
            onChange(text);
          }
        )
      />,
  };
};

module AnimatedTextInputRemote = {
  let shrinkText = (~text, ~value) =>
    value >= 1.0 ?
      text :
      {
        let len = Js.Math.round(value *. float_of_int(String.length(text)));
        String.sub(text, 0, int_of_float(len));
      };
  let remoteAction = RemoteAction.create();
  let renderValue = value =>
    <TextInputRemote
      remoteAction
      showText=(text => shrinkText(~text, ~value))
      initial="edit this or click target"
    />;
  let component = ReasonReact.statelessComponent("AnimatedTextInput");
  let make = _children => {
    ...component,
    render: _ =>
      <div>
        <button
          onClick=(
            _ =>
              RemoteAction.send(remoteAction, ~action=TextInputRemote.Reset)
          )>
          (ReasonReact.string("reset text"))
        </button>
        <div> (ReasonReact.string("-----")) </div>
        <Spring renderValue />
      </div>,
  };
};

module GrandChild = {
  type action =
    | Incr
    | Decr;
  let component = ReasonReact.reducerComponent("GrandChild");
  let make = (~remoteAction, _) => {
    ...component,
    initialState: () => 0,
    didMount: ({send, onUnmount}) => {
      let token = RemoteAction.subscribe(~send, remoteAction);
      let cleanup = () =>
        switch (token) {
        | Some(token) => RemoteAction.unsubscribe(token)
        | None => ()
        };
      onUnmount(cleanup);
    },
    reducer: (action, state) =>
      switch (action) {
      | Incr => Update(state + 1)
      | Decr => Update(state - 1)
      },
    render: ({state}) =>
      <div>
        (ReasonReact.string("in grandchild state: " ++ string_of_int(state)))
      </div>,
  };
};

module Child = {
  let component = ReasonReact.statelessComponent("Child");
  let make = (~remoteAction, _) => {
    ...component,
    render: _ =>
      <div>
        (ReasonReact.string("in child"))
        <GrandChild remoteAction />
      </div>,
  };
};

module Parent = {
  let component = ReasonReact.reducerComponent("Parent");
  let make = _ => {
    ...component,
    initialState: () => RemoteAction.create(),
    reducer: ((), _) => NoUpdate,
    render: ({state}) =>
      <div>
        <button
          onClick=(_ => RemoteAction.send(state, ~action=GrandChild.Incr))>
          (ReasonReact.string("in parent"))
        </button>
        <Child remoteAction=state />
      </div>,
  };
};
