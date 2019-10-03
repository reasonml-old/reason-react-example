'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");

var leftButtonStyle = {
  border: "none",
  width: "48px",
  borderRadius: "4px 0px 0px 4px",
  boxShadow: "0 0 0px 1px #48a9dc"
};

var rightButtonStyle = {
  border: "none",
  width: "48px",
  borderRadius: "0px 4px 4px 0px",
  boxShadow: "0 0 0px 1px #48a9dc"
};

var initialState = /* record */[/* count */0];

function reducer(state, action) {
  if (action) {
    return /* record */[/* count */state[/* count */0] - 1 | 0];
  } else {
    return /* record */[/* count */state[/* count */0] + 1 | 0];
  }
}

function ReducerExampleFromReactJSDocs(Props) {
  var match = React.useReducer(reducer, initialState);
  var dispatch = match[1];
  return React.createElement("div", {
              style: {
                display: "flex",
                alignItems: "center",
                justifyContent: "space-between"
              }
            }, React.createElement("div", undefined, "Count: ", String(match[0][/* count */0])), React.createElement("div", undefined, React.createElement("button", {
                      style: leftButtonStyle,
                      onClick: (function (_event) {
                          return Curry._1(dispatch, /* Decrement */1);
                        })
                    }, "-"), React.createElement("button", {
                      style: rightButtonStyle,
                      onClick: (function (_event) {
                          return Curry._1(dispatch, /* Increment */0);
                        })
                    }, "+")));
}

var make = ReducerExampleFromReactJSDocs;

exports.leftButtonStyle = leftButtonStyle;
exports.rightButtonStyle = rightButtonStyle;
exports.initialState = initialState;
exports.reducer = reducer;
exports.make = make;
/* react Not a pure module */
