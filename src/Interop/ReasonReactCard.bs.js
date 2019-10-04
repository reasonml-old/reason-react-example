'use strict';

var React = require("react");

function ReasonReactCard(Props) {
  var style = Props.style;
  return React.createElement("div", {
              style: style
            }, "This is a ReasonReact card");
}

var make = ReasonReactCard;

exports.make = make;
/* react Not a pure module */
