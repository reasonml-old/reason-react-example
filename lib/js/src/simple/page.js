'use strict';

var Curry       = require("bs-platform/lib/js/curry.js");
var React       = require("react");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("Page");

function handleClick(_, _$1) {
  console.log("clicked!");
  return /* () */0;
}

function make(message, _) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function (self) {
      return React.createElement("div", {
                  onClick: Curry._1(self[/* handle */0], handleClick)
                }, message);
    });
  return newrecord;
}

exports.component   = component;
exports.handleClick = handleClick;
exports.make        = make;
/* component Not a pure module */
