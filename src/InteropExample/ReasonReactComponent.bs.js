'use strict';

var React = require("react");

function ReasonReactComponent(Props) {
  var label = Props.label;
  return React.createElement("button", {
              "aria-label": label
            }, label);
}

var make = ReasonReactComponent;

exports.make = make;
/* react Not a pure module */
