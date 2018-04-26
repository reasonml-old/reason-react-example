'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var component = ReasonReact.reducerComponent("Counter");

function make() {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (param) {
              return React.createElement("div", undefined, String(param[/* state */1][/* count */0]));
            }),
          /* initialState */(function () {
              return /* record */[/* count */0];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (_, state) {
              return /* Update */Block.__(0, [/* record */[/* count */state[/* count */0] + 1 | 0]]);
            }),
          /* subscriptions */(function (self) {
              return /* :: */[
                      /* Sub */[
                        (function () {
                            return setInterval((function () {
                                          return Curry._1(self[/* send */3], /* Tick */0);
                                        }), 1000);
                          }),
                        (function (prim) {
                            clearInterval(prim);
                            return /* () */0;
                          })
                      ],
                      /* [] */0
                    ];
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.component = component;
exports.make = make;
/* component Not a pure module */
