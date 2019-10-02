'use strict';

var React = require("react");

function ReasonReactButton(Props) {
  var label = Props.label;
  return React.createElement("button", {
              "aria-label": label
            }, label);
}

var make = ReasonReactButton;

exports.make = make;
/* react Not a pure module */
