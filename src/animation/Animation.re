type animationFrameID;

[@bs.val]
external requestAnimationFrame: (unit => unit) => animationFrameID = "";

[@bs.val] external cancelAnimationFrame: animationFrameID => unit = "";

type onStop = option(unit => unit);

type ctrl =
  | Stop(onStop)
  | Continue;

type callback = (. unit) => ctrl;

type t = {
  mutable id: option(animationFrameID),
  mutable callback,
};

let defaultCallback = (.) => Stop(None);

let create = () => {id: None, callback: defaultCallback};

let rec onAnimationFrame = (animation, ()) =>
  if (animation.id != None) {
    switch (animation.callback(.)) {
    | Stop(None) => animation.id = None
    | Stop(Some(onStop)) =>
      animation.id = None;
      onStop();
    | Continue =>
      animation.id =
        Some(requestAnimationFrame(onAnimationFrame(animation)))
    };
  };

let start = animation =>
  animation.id = Some(requestAnimationFrame(onAnimationFrame(animation)));

let stop = animation =>
  switch (animation.id) {
  | Some(id) =>
    cancelAnimationFrame(id);
    animation.id = None;
  | None => ()
  };

let setCallback = (animation, ~callback) => {
  stop(animation);
  animation.callback = callback;
};

let isActive = animation => animation.id != None;
