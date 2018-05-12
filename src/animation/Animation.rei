type t;

type onStop = option(unit => unit);

type ctrl =
  | Stop(onStop)
  | Continue;

type callback = (. unit) => ctrl;

let create: unit => t;

let isActive: t => bool;

let setCallback: (t, ~callback: callback) => unit;

let start: t => unit;

let stop: t => unit;