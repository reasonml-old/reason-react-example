/**
 This illustrates JS to Reason interop in both directions.
  */
let component = ReasonReact.createComponent "PageReason";

let make ::message _ => {
  ...component,
  render: fun _state _ =>
    ReasonReact.createDomElement
      "div"
      props::{"className": "componentBox"}
      [|
        ReasonReact.stringToElement message,
        /** use the byBanner.js wrapper: Illustrates how a Reason component uses a JS component */
        ReasonReact.element (MyBannerRe.make message::"Hello from Reason!" num::42 [||])
      |]
};

let jsPropsToReason jsProps => make message::jsProps##message [||];


/** Wrap the Reason component defined in this file as a JS component.
    Illustrates how a JS component uses a Reason component. */
let reactClass = ReasonReact.createJsReactClass ::jsPropsToReason component;
