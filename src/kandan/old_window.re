module Uint16Array = {
  type t;
  external create : int => t = "window.Uint16Array" [@@bs.new];
  external get : t => int => int = "" [@@bs.get_index];
  external set : t => int => int => unit = "" [@@bs.set_index];
};

module Crypto = {
  external getRandomValues : Uint16Array.t => Uint16Array.t =
    "window.crypto.getRandomValues" [@@bs.val];
};

module Date = {
  type t;
  external create : int => t = "window.Date" [@@bs.new];
  external now : unit => t = "window.Date" [@@bs.new];
  external get_time : t => int = "getTime" [@@bs.send];
  let now_ts () => get_time @@ now ();
};

external toString : 'a => int => string = "toString" [@@bs.send];
