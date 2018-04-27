/* See https://reasonml.github.io/reason-react/docs/en/counter.html for another possible way of doing this */
/* This is a stateful component. In ReasonReact, we call them reducer components */
/* A list of state transitions, to be used in self.send and reducer */
type action =
  | Tick;

/* The component's state type. It can be anything, including, commonly, being a record type */
type state = {count: int};

let component = ReasonReact.reducerComponent("Counter");

let make = _children => {
  ...component,
  initialState: () => {count: 0},
  reducer: (action, state) =>
    switch (action) {
    | Tick => ReasonReact.Update({count: state.count + 1})
    },
  didMount: self => {
    let intervalId = Js.Global.setInterval(() => self.send(Tick), 1000);
    self.onUnmount(() => Js.Global.clearInterval(intervalId));
  },
  render: ({state}) =>
    <div> (ReasonReact.string(string_of_int(state.count))) </div>,
};
