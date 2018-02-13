'use strict';

var Js_boolean = require("bs-platform/lib/js/js_boolean.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");
var MyBanner = require("../../../../src/interop/MyBanner");

function make(show, message, children) {
  return ReasonReact.wrapJsForReason(MyBanner, {
              show: Js_boolean.to_js_boolean(show),
              message: message
            }, children);
}

exports.make = make;
/* ReasonReact Not a pure module */
