'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");

function BlinkingGreeting(Props) {
  var children = Props.children;
  var match = React.useState((function () {
          return true;
        }));
  var setShow = match[1];
  React.useEffect((function () {
          var id = setInterval((function (param) {
                  return Curry._1(setShow, (function (previousShow) {
                                return !previousShow;
                              }));
                }), 1000);
          return (function (param) {
                    clearInterval(id);
                    return /* () */0;
                  });
        }), ([]));
  var style = match[0] ? ({
        opacity: "1",
        transition: "opacity 1s"
      }) : ({
        opacity: "0",
        transition: "opacity 1s"
      });
  return React.createElement("div", {
              style: style
            }, children);
}

var make = BlinkingGreeting;

exports.make = make;
/* react Not a pure module */
