'use strict';

var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var RetainedPropsExample = require("./RetainedPropsExample.bs.js");

var toggle = /* record */[/* contents */false];

function render() {
  toggle[0] = !toggle[/* contents */0];
  var match = toggle[/* contents */0];
  return ReactDOMRe.renderToElementWithId(ReasonReact.element(undefined, undefined, RetainedPropsExample.make(match ? "Hello!" : "Goodbye", /* array */[])), "index");
}

setInterval(render, 1000);

render(/* () */0);

exports.toggle = toggle;
exports.render = render;
/*  Not a pure module */
