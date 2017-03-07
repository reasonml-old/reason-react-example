module StandardTesterImpl = {
  include ReactRe.Component.Stateful;
  type props = {incrOnDidMount: bool, initialCount: int, incr: int};
  type state = {clicks: int};
  let name = "StandardTester";
  let getInitialState props => {clicks: props.initialCount};
  let handleClick {props, state} _ /* event */ => Some {clicks: state.clicks + props.incr};
  let componentDidMount {props, state} => {
    print_string "IN MOUNT";
    print_newline ();
    props.incrOnDidMount ? Some {clicks: state.clicks + props.incr} : None
  };
  let render {state, updater} =>
    <div>
      <button onClick=(updater handleClick)>
        (ReactRe.stringToElement ("Clicked " ^ string_of_int state.clicks ^ " time(s)"))
      </button>
      <Logo message="Hello!" />
    </div>;
};

module StandardTester = {
  include ReactRe.CreateComponent StandardTesterImpl;
  let createElement ::incrOnDidMount=false ::incr=0 ::initialCount=0 =>
    wrapProps {incrOnDidMount, initialCount, incr};
};

module WithStatefulInstanceVarsImpl = {
  include ReactRe.Component.Stateful.InstanceVars;
  type props = {incrOnDidMount: bool, initialCount: int, incr: int};
  type state = {clicks: int};
  type instanceVars = (int, string);
  let name = "LifecycleTester";
  let getInitialState props => {clicks: props.initialCount};
  let getInstanceVars () => (10, "test");
  let handleClick {props, state} _ /* event */ => Some {clicks: state.clicks + props.incr};
  let componentDidMount {props, state} =>
    props.incrOnDidMount ? Some {clicks: state.clicks + props.incr} : None;
  let render {state, updater} =>
    <div>
      <button onClick=(updater handleClick)>
        (ReactRe.stringToElement ("Clicked " ^ string_of_int state.clicks ^ " time(s)"))
      </button>
      <Logo message="Hello!" />
    </div>;
};

module WithStatefulInstanceVars = {
  include ReactRe.CreateComponent WithStatefulInstanceVarsImpl;
  let createElement ::incrOnDidMount=false ::incr=0 ::initialCount=0 =>
    wrapProps {incrOnDidMount, initialCount, incr};
};
