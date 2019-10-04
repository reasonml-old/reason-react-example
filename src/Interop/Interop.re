// In this Interop example folder, we have:
// - A ReasonReact component, ReasonReactCard.re
// - Used by a ReactJS component, ReactJSCard.js
// - ReactJSCard can be used by ReasonReact, through bindings in Interop.re (this file)
// - Interop.re is used by Index.re

// All you need to do to use a ReactJS component in ReasonReact, is to write the lines below!
// reasonml.github.io/reason-react/docs/en/components#import-from-js
[@react.component] [@bs.module]
external make: unit => React.element = "./ReactJSCard";
