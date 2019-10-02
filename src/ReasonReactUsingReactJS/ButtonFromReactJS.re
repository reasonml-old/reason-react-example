// ReasonReact using a ReactJS component

// All you need to do is to use the same @bs.module BuckleScript interop call, but add @react.component to it

// @bs.module documentation: https://bucklescript.github.io/docs/en/import-export#import
// @react.component interop documentation: https://reasonml.github.io/reason-react/docs/en/components#interop

[@react.component][@bs.module]
external make: (~disabled: bool, ~label: string) => React.element = "./Button";
