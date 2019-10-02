// A basic, stateful ReasonReact hooks component.
// Note that it looks similar to what you'd have written for React.js!

// Don't forget to check the output, StatefulExample.bs.js. We recommend you
// keeping the output file open while developing, for correctness and learning
// purposes.

[@react.component]
let make = (~greeting) => {
  let (count, setCount) = React.useState(() => 0);

  let countTimesText = if (count === 1) {
    "time"
  } else {
    "times"
  };

  <button onClick={_event => setCount(prevCount => prevCount + 1)}>
    {React.string(greeting)}
    {React.string(" You've clicked ")}
    {React.string(string_of_int(count))}
    {React.string(" " ++ countTimesText)}
  </button>
}
