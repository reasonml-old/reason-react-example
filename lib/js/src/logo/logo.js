'use strict';

var Block       = require("bs-platform/lib/js/block.js");
var Curry       = require("bs-platform/lib/js/curry.js");
var React       = require("react");
var Constants   = require("./constants.js");
var Pervasives  = require("bs-platform/lib/js/pervasives.js");
var ReasonReact = require("reason-react/lib/js/src/reasonReact.js");

function renderGraphic(rotationStyle) {
  return React.createElement("g", {
              fill: "none",
              stroke: "none"
            }, React.createElement("g", {
                  transform: "scale(1.5, 1.5) translate(100.000000, 105.000000)"
                }, React.createElement("path", {
                      d: Constants.border_path,
                      fill: "rgba(0,0,0,0.1)"
                    }), React.createElement("path", {
                      d: Constants.bg_path,
                      fill: "#dd4b39"
                    }), React.createElement("g", {
                      transform: "translate(55, 29)"
                    }, React.createElement("g", {
                          style: rotationStyle
                        }, React.createElement("path", {
                              d: Constants.center_dot_path,
                              fill: "#FFFFFF"
                            }), React.createElement("g", {
                              stroke: "#FFFFFF",
                              strokeWidth: "8"
                            }, React.createElement("path", {
                                  d: Constants.ring_one_path
                                }), React.createElement("path", {
                                  d: Constants.ring_two_path,
                                  transform: Constants.ring_two_rotate
                                }), React.createElement("path", {
                                  d: Constants.ring_three_path,
                                  transform: Constants.ring_three_rotate
                                }))))));
}

var component = ReasonReact.reducerComponent("LogoRe");

function make(message, _) {
  var newrecord = component.slice();
  newrecord[/* didMount */4] = (function (param) {
      var reduce = param[/* reduce */3];
      var onAnimationFrame = function () {
        Curry._2(reduce, (function () {
                return /* Spin */2;
              }), /* () */0);
        requestAnimationFrame(onAnimationFrame);
        return /* () */0;
      };
      requestAnimationFrame(onAnimationFrame);
      return /* NoUpdate */0;
    });
  newrecord[/* render */9] = (function (param) {
      var reduce = param[/* reduce */3];
      var transform = "rotate(" + (Pervasives.string_of_float(param[/* state */4][/* degrees */0]) + "deg)");
      var rotationStyle = {
        transform: transform,
        transformOrigin: "50% 50%"
      };
      return React.createElement("div", {
                  style: {
                    color: "#444444",
                    fontFamily: "Montserrat",
                    fontSize: "68px",
                    paddingTop: "40px",
                    textAlign: "center",
                    userSelect: "none"
                  }
                }, message, React.createElement("svg", {
                      style: {
                        cursor: "pointer"
                      },
                      height: "100%",
                      width: "100%",
                      onMouseDown: Curry._1(reduce, (function () {
                              return /* MouseDown */1;
                            })),
                      onMouseUp: Curry._1(reduce, (function () {
                              return /* MouseUp */0;
                            })),
                      version: "1.1",
                      viewBox: "0 0 700 700"
                    }, renderGraphic(rotationStyle)));
    });
  newrecord[/* initialState */10] = (function () {
      return /* float array */[
              0.0,
              0.1,
              Constants.mouseUpDrag,
              Date.now()
            ];
    });
  newrecord[/* reducer */12] = (function (action, state) {
      switch (action) {
        case 0 : 
            var withAccel = state[/* velocity */1] + Constants.clickAccel;
            var match = +(withAccel < Constants.maxVel);
            var nextVelocity = match !== 0 ? withAccel : Constants.maxVel;
            return /* Update */Block.__(0, [/* float array */[
                        state[/* degrees */0],
                        nextVelocity,
                        Constants.mouseUpDrag,
                        state[/* lastMs */3]
                      ]]);
        case 1 : 
            return /* Update */Block.__(0, [/* float array */[
                        state[/* degrees */0],
                        state[/* velocity */1],
                        Constants.mouseDownDrag,
                        state[/* lastMs */3]
                      ]]);
        case 2 : 
            var now = Date.now();
            var idealFramesSinceLast = 1 + (now - state[/* lastMs */3]) / 16;
            var nextDegrees = state[/* degrees */0] + (Constants.baseVel + state[/* velocity */1]) * idealFramesSinceLast;
            var nextVelocity$1 = state[/* velocity */1] * state[/* drag */2];
            return /* Update */Block.__(0, [/* float array */[
                        nextDegrees,
                        nextVelocity$1,
                        state[/* drag */2],
                        now
                      ]]);
        
      }
    });
  return newrecord;
}

exports.renderGraphic = renderGraphic;
exports.component     = component;
exports.make          = make;
/* component Not a pure module */
