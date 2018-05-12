'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var Spring = require("./Spring.bs.js");
var Animation = require("./Animation.bs.js");

function create(initialValue) {
  var animation = Animation.create(/* () */0);
  var state = Spring.createState(initialValue);
  return /* record */[
          /* animation */animation,
          /* state */state
        ];
}

function setOnChange(preset, speedup, precision, $staropt$star, onChange, finalValue, a) {
  var onStop = $staropt$star ? $staropt$star[0] : /* None */0;
  var callback = function () {
    a[/* state */1] = Spring.stepper(/* None */0, speedup, precision, preset, a[/* state */1]);
    var isFinished = Spring.isFinished(a[/* state */1]);
    Curry._1(onChange, a[/* state */1][/* value */0]);
    if (isFinished) {
      return /* Stop */[onStop];
    } else {
      return /* Continue */0;
    }
  };
  Animation.stop(a[/* animation */0]);
  ((function (param) {
          return Animation.setCallback(param, callback);
        })(a[/* animation */0]));
  if (finalValue) {
    var init = a[/* state */1];
    a[/* state */1] = /* record */[
      /* value */init[/* value */0],
      /* velocity */init[/* velocity */1],
      /* finalValue */finalValue[0]
    ];
    return Animation.start(a[/* animation */0]);
  } else {
    return /* () */0;
  }
}

function setFinalValue(finalValue, a) {
  Animation.stop(a[/* animation */0]);
  var init = a[/* state */1];
  a[/* state */1] = /* record */[
    /* value */init[/* value */0],
    /* velocity */init[/* velocity */1],
    /* finalValue */finalValue
  ];
  return Animation.start(a[/* animation */0]);
}

function stop(a) {
  return Animation.stop(a[/* animation */0]);
}

exports.create = create;
exports.setOnChange = setOnChange;
exports.setFinalValue = setFinalValue;
exports.stop = stop;
/* No side effect */
