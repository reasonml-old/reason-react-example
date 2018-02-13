'use strict';

var React = require("react");
var MyBannerRe = require("./MyBannerRe.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");

var component = ReasonReact.statelessComponent("PageReason");

function make(message, extraGreeting, _) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      var greeting = extraGreeting ? extraGreeting[0] : "How are you?";
      return React.createElement("div", undefined, ReasonReact.element(/* None */0, /* None */0, MyBannerRe.make(/* true */1, message + (" " + greeting), /* array */[])));
    });
  return newrecord;
}

var jsComponent = ReasonReact.wrapReasonForJs(component, (function (jsProps) {
        return make(jsProps.message, Js_primitive.null_undefined_to_opt(jsProps.extraGreeting), /* array */[]);
      }));

exports.component = component;
exports.make = make;
exports.jsComponent = jsComponent;
/* component Not a pure module */
