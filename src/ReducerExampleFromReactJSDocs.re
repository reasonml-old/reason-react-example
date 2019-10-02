// This is the ReactJS documentation's useReducer example, directly ported over
// https://reactjs.org/docs/hooks-reference.html#usereducer

// Record and variant need explicit declarations.
type state = {count: int};

type action =
  | Increment
  | Decrement;

let initialState = {count: 0};

let reducer = (state, action) => {
  switch (action) {
  | Increment => {count: state.count + 1}
  | Decrement => {count: state.count - 1}
  }
};

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  <>
    {React.string("Count: ")}
    {React.string(string_of_int(state.count))}
    <button
      style={
        ReactDOMRe.Style.make(
          ~boxShadow="0 0 0px 1px #48a9dc",
          ~border="none",
          ~borderRadius="4px 0px 0px 4px",
          ~marginLeft="8px",
          ~width="24px",
          ()
        )
      }
      onClick={_event => dispatch(Increment)}>{React.string("+")}</button>
    <button
      style={
        ReactDOMRe.Style.make(
          ~boxShadow="0 0 0px 1px #48a9dc",
          ~border="none",
          ~borderRadius="0px 4px 4px 0px",
          ~width="24px",
          ()
        )
      }
      onClick={_event => dispatch(Decrement)}>{React.string("-")}</button>
  </>
};
