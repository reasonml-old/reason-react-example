'use strict';

var React = require("react");

var style = {
  backgroundColor: "rgba(0, 0, 0, 0.05)",
  padding: "12px",
  borderRadius: "4px"
};

function ReasonReactButton(Props) {
  return React.createElement("div", {
              style: style
            }, "This is a ReasonReact card");
}

var make = ReasonReactButton;

exports.style = style;
exports.make = make;
/* react Not a pure module */
