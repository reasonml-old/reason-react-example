'use strict';

var ReactDOMRe           = require("reason-react/lib/js/src/reactDOMRe.js");
var ReasonReact          = require("reason-react/lib/js/src/reasonReact.js");
var RetainedPropsExample = require("./RetainedPropsExample.js");

var toggle = [/* false */0];

function render() {
  toggle[0] = 1 - toggle[/* contents */0];
  var match = toggle[/* contents */0];
  return ReactDOMRe.renderToElementWithId(ReasonReact.element(/* None */0, /* None */0, RetainedPropsExample.make(match !== 0 ? "Hello!" : "Goodbye", /* array */[])), "index");
}

setInterval(render, 1000);

render(/* () */0);

exports.toggle = toggle;
exports.render = render;
/*  Not a pure module */
