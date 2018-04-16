'use strict';

var ReactDOMRe = require("reason-react/lib/js/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");
var RetainedPropsExample = require("./RetainedPropsExample.js");

var toggle = [false];

function render() {
  toggle[0] = !toggle[/* contents */0];
  var match = toggle[/* contents */0];
  return ReactDOMRe.renderToElementWithId(ReasonReact.element(/* None */0, /* None */0, RetainedPropsExample.make(match ? "Hello!" : "Goodbye", /* array */[])), "index");
}

setInterval(render, 1000);

render(/* () */0);

exports.toggle = toggle;
exports.render = render;
/*  Not a pure module */
