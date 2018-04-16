'use strict';

var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");
var MyBanner = require("../../../../src/interop/MyBanner");

function make(show, message, children) {
  return ReasonReact.wrapJsForReason(MyBanner, {
              show: show,
              message: message
            }, children);
}

exports.make = make;
/* ReasonReact Not a pure module */
