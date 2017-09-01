'use strict';

var React       = require("react");
var ReasonReact = require("reason-react/lib/js/src/reasonReact.js");

var component = ReasonReact.statelessComponentWithRetainedProps("RetainedPropsExample");

function make(message, _) {
  var newrecord = component.slice();
  newrecord[/* didUpdate */5] = (function (param) {
      if (param[/* oldSelf */0][/* retainedProps */5][/* message */0] !== param[/* newSelf */1][/* retainedProps */5][/* message */0]) {
        console.log("props `message` changed!");
        return /* () */0;
      } else {
        return 0;
      }
    });
  newrecord[/* render */9] = (function () {
      return React.createElement("div", undefined, message);
    });
  newrecord[/* retainedProps */11] = /* record */[/* message */message];
  return newrecord;
}

exports.component = component;
exports.make      = make;
/* component Not a pure module */
