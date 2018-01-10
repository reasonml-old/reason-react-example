'use strict';

var Block       = require("bs-platform/lib/js/block.js");
var Curry       = require("bs-platform/lib/js/curry.js");
var React       = require("react");
var Pervasives  = require("bs-platform/lib/js/pervasives.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var component = ReasonReact.reducerComponent("Counter");

function make() {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function (param) {
      return React.createElement("div", undefined, Pervasives.string_of_int(param[/* state */2][/* count */0]));
    });
  newrecord[/* initialState */10] = (function () {
      return /* record */[/* count */0];
    });
  newrecord[/* reducer */12] = (function (_, state) {
      return /* Update */Block.__(0, [/* record */[/* count */state[/* count */0] + 1 | 0]]);
    });
  newrecord[/* subscriptions */13] = (function (self) {
      return /* :: */[
              /* Sub */[
                (function () {
                    return setInterval((function () {
                                  return Curry._1(self[/* send */4], /* Tick */0);
                                }), 1000);
                  }),
                (function (prim) {
                    clearInterval(prim);
                    return /* () */0;
                  })
              ],
              /* [] */0
            ];
    });
  return newrecord;
}

exports.component = component;
exports.make      = make;
/* component Not a pure module */
