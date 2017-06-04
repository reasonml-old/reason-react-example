/** Package the JS component defined in myBanner.js as a Reason component. */

/** Typing the component defined in myBanner.js as a `reactClass`.
    Note that this file's JS output will be at lib/js/src/interop/myBannerRe.js;
    we're specifying the relative path to myBanner.js in the string below */
external myBanner : ReasonReact.reactClass = "../../../../src/interop/myBanner" [@@bs.module];

let make ::message ::num children =>
  ReasonReact.wrapJsComponentForReason reactClass::myBanner props::{"message": message, "num": num} children;
