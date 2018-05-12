'use strict';

var Curry = require("bs-platform/lib/js/curry.js");

function defaultCallback() {
  return /* Stop */[/* None */0];
}

function create() {
  return /* record */[
          /* id : None */0,
          /* callback */defaultCallback
        ];
}

function onAnimationFrame(animation, _) {
  if (animation[/* id */0] !== /* None */0) {
    var match = animation[/* callback */1]();
    if (match) {
      var match$1 = match[0];
      if (match$1) {
        animation[/* id */0] = /* None */0;
        return Curry._1(match$1[0], /* () */0);
      } else {
        animation[/* id */0] = /* None */0;
        return /* () */0;
      }
    } else {
      animation[/* id */0] = /* Some */[requestAnimationFrame((function (param) {
                return onAnimationFrame(animation, param);
              }))];
      return /* () */0;
    }
  } else {
    return 0;
  }
}

function start(animation) {
  animation[/* id */0] = /* Some */[requestAnimationFrame((function (param) {
            return onAnimationFrame(animation, param);
          }))];
  return /* () */0;
}

function stop(animation) {
  var match = animation[/* id */0];
  if (match) {
    cancelAnimationFrame(match[0]);
    animation[/* id */0] = /* None */0;
    return /* () */0;
  } else {
    return /* () */0;
  }
}

function setCallback(animation, callback) {
  stop(animation);
  animation[/* callback */1] = callback;
  return /* () */0;
}

function isActive(animation) {
  return animation[/* id */0] !== /* None */0;
}

exports.create = create;
exports.isActive = isActive;
exports.setCallback = setCallback;
exports.start = start;
exports.stop = stop;
/* No side effect */
