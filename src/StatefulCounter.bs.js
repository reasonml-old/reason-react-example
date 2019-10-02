'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");

function StatefulCounter(Props) {
  var greeting = Props.greeting;
  var match = React.useState((function () {
          return 0;
        }));
  var setCount = match[1];
  var count = match[0];
  var countTimesText = count === 1 ? "time" : "times";
  return React.createElement("button", {
              onClick: (function (_event) {
                  return Curry._1(setCount, (function (prevCount) {
                                return prevCount + 1 | 0;
                              }));
                })
            }, greeting, " You've clicked ", String(count), " " + countTimesText);
}

var make = StatefulCounter;

exports.make = make;
/* react Not a pure module */
