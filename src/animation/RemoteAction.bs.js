'use strict';

var Curry = require("bs-platform/lib/js/curry.js");

function sendDefault() {
  return /* () */0;
}

function create() {
  return /* record */[/* send */sendDefault];
}

function subscribe(send, x) {
  if (x[/* send */0] === sendDefault) {
    x[/* send */0] = send;
    return x;
  }
  
}

function unsubscribe(x) {
  x[/* send */0] = sendDefault;
  return /* () */0;
}

function send(x, action) {
  return Curry._1(x[/* send */0], action);
}

exports.create = create;
exports.subscribe = subscribe;
exports.unsubscribe = unsubscribe;
exports.send = send;
/* No side effect */
