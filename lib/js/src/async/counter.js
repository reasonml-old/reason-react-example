'use strict';

var Block       = require("bs-platform/lib/js/block.js");
var Curry       = require("bs-platform/lib/js/curry.js");
var React       = require("react");
var Pervasives  = require("bs-platform/lib/js/pervasives.js");
var ReasonReact = require("reason-react/lib/js/src/reasonReact.js");

var component = ReasonReact.reducerComponent("Counter");

function make() {
  var newrecord = component.slice();
  newrecord[/* didMount */4] = (function (self) {
      self[/* state */4][/* timerId */1][0] = /* Some */[setInterval(Curry._1(self[/* reduce */3], (function () {
                    return /* Tick */0;
                  })), 1000)];
      return /* NoUpdate */0;
    });
  newrecord[/* render */9] = (function (param) {
      return React.createElement("div", undefined, Pervasives.string_of_int(param[/* state */4][/* count */0]));
    });
  newrecord[/* initialState */10] = (function () {
      return /* record */[
              /* count */0,
              /* timerId */[/* None */0]
            ];
    });
  newrecord[/* reducer */12] = (function (_, state) {
      return /* Update */Block.__(0, [/* record */[
                  /* count */state[/* count */0] + 1 | 0,
                  /* timerId */state[/* timerId */1]
                ]]);
    });
  return newrecord;
}

exports.component = component;
exports.make      = make;
/* component Not a pure module */
