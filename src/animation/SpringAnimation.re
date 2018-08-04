type t = {
  animation: Animation.t,
  mutable state: Spring.state,
};

let create = initialValue => {
  let animation = Animation.create();
  let state = Spring.createState(initialValue);
  {animation, state};
};

type onChange = float => unit;

let setOnChange =
    (
      ~preset=?,
      ~speedup=?,
      ~precision=?,
      ~onStop=None,
      ~onChange,
      ~finalValue=?,
      a,
    ) => {
  let callback =
    (.) => {
      a.state = Spring.stepper(~preset?, ~speedup?, ~precision?, a.state);
      let isFinished = Spring.isFinished(a.state);
      onChange(a.state.value);
      isFinished ? Animation.Stop(onStop) : Continue;
    };
  a.animation |> Animation.stop;
  a.animation |> Animation.setCallback(~callback);
  switch (finalValue) {
  | None => ()
  | Some(finalValue) =>
    a.state = {...a.state, finalValue};
    a.animation |> Animation.start;
  };
};

let setFinalValue = (finalValue, a) => {
  a.animation |> Animation.stop;
  a.state = {...a.state, finalValue};
  a.animation |> Animation.start;
};

let stop = a => a.animation |> Animation.stop;
