let defaultSecondsPerFrame = 1. /. 60.;

let defaultPrecision = 0.01;

type preset = {
  stiffness: float,
  damping: float,
};

let noWobble = {stiffness: 170., damping: 26.};

let gentle = {stiffness: 120., damping: 14.};

let wobbly = {stiffness: 180., damping: 12.};

let stiff = {stiffness: 210., damping: 20.};

let defaultPreset = noWobble;

type state = {
  value: float,
  velocity: float,
  finalValue: float,
};

let createState = value => {value, velocity: 0., finalValue: value};

let stepper =
    (
      ~secondsPerFrame=defaultSecondsPerFrame,
      ~speedup=?,
      ~precision=defaultPrecision,
      ~preset=defaultPreset,
      {value, velocity, finalValue} as state,
    ) => {
  let secondsPerFrame =
    switch (speedup) {
    | None => secondsPerFrame
    | Some(x) => secondsPerFrame *. x
    };
  let forceSpring = -. preset.stiffness *. (value -. finalValue);
  let forceDamper = -. preset.damping *. velocity;
  let acceleration = forceSpring +. forceDamper;
  let newVelocity = velocity +. acceleration *. secondsPerFrame;
  let newValue = value +. newVelocity *. secondsPerFrame;
  abs_float(newVelocity) < precision
  && abs_float(newValue -. finalValue) < precision ?
    {...state, value: finalValue, velocity: 0.0} :
    {...state, value: newValue, velocity: newVelocity};
};

let isFinished = ({value, velocity, finalValue}) =>
  value == finalValue && velocity == 0.;

let test = () => {
  let rec iterate = state => {
    Js.log(state);
    if (!isFinished(state)) {
      iterate(stepper(state));
    };
  };
  iterate({value: 0.0, velocity: 0.0, finalValue: 1.0});
};
