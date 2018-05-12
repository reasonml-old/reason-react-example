type t;

let create: float => t;

type onChange = float => unit;

/**
 * Set the onChange function and other parameters of a spring animation.
 * The animation is stopped, and only re-started if finalValue is supplied.
 */
let setOnChange:
  (
    ~preset: Spring.preset=?,
    ~speedup: float=?,
    ~precision: float=?,
    ~onStop: Animation.onStop=?,
    ~onChange: onChange,
    ~finalValue: float=?,
    t
  ) =>
  unit;

/**
 * Update the final value of the animation, and start it if it was stopped.
 */
let setFinalValue: (float, t) => unit;

let stop: t => unit;