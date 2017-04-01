/* Define this so `substring` doesn't bring in the String module */
external sub : string => int => int => string = "substring" [@@bs.send];

external split : string => Js.Re.t => array string = "split" [@@bs.send];

external join : array string => string => string = "join" [@@bs.send];

external trim : string => string = "trim" [@@bs.send];

external indexOf : string => string => int = "indexOf" [@@bs.send];

external matchRegex_ : string => Js.Re.t => Js.null (array string) = "match" [@@bs.send];

external matchString_ : string => string => Js.null (array string) = "match" [@@bs.send];

external lowerCase : string => string = "toLowerCase" [@@bs.send];

external upperCase : string => string = "toUpperCase" [@@bs.send];

let matchRegex string regex => Js.Null.to_opt (matchRegex_ string regex);

let matchString s1 s2 => Js.Null.to_opt (matchString_ s1 s2);

external decodeURI : string => string = "window.decodeURI" [@@bs.val];

external fromCharCode : int => string = "String.fromCharCode" [@@bs.val];

external replace : string => Js.Re.t => string => string = "replace" [@@bs.send];
