/* Useful for converting e.g. hex  */
external toString : 'a => int => string = "toString" [@@bs.send];

/* Define this so we don't have to bring in the Bytes/String module */
let repeat_string str count =>
  switch count {
  | 0 => ""
  | _ =>
    let half = count / 2;
    let result = ref str;
    ignore (
      while (String.length !result <= half) {
        result := !result ^ !result
      }
    );
    let r = !result ^ Local_string.sub !result 0 (count - String.length !result);
    r
  };

let to_hex_string n l => {
  let s = toString n 16;
  let c = String.length s;
  if (c > l) {
    Local_string.sub s 0 l
  } else if (c < l) {
    repeat_string "0" (l - c) ^ s
  } else {
    s
  }
};

external getUint16 : Js.Typed_array.Uint16Array.t => int => int = "" [@@bs.get_index];

external setUint16 : Js.Typed_array.Uint16Array.t => int => int => unit = "" [@@bs.set_index];

module Crypto = {
  external getRandomValues : Js.Typed_array.Uint16Array.t => Js.Typed_array.Uint16Array.t =
    "window.crypto.getRandomValues" [@@bs.val];
};

let squuid () => {
  let a = Crypto.getRandomValues (Js.Typed_array.Uint16Array.make [|6|]);
  let b1 = getUint16 a 0;
  let b2 = getUint16 a 1;
  let b3 = getUint16 a 2;
  let b4 = getUint16 a 3;
  let b5 = getUint16 a 4;
  let b6 = getUint16 a 5;
  let _base = Js.Date.now ();
  let base = to_hex_string (_base /. 1000.0 |> Math.round) 8;
  let final =
    base ^
    "-" ^
    to_hex_string b1 4 ^
    "-" ^
    to_hex_string
      (Int32.logor (Int32.logand (Int32.of_int b2) (Int32.of_int 4095)) (Int32.of_int 16384)) 4 ^
    "-" ^
    to_hex_string
      (Int32.logor (Int32.logand (Int32.of_int b3) (Int32.of_int 16383)) (Int32.of_int 32768)) 4 ^
    "-" ^ to_hex_string b4 4 ^ to_hex_string b5 4 ^ to_hex_string b6 4;
  final
};
