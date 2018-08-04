'use strict';

var Counter = require("./Counter.bs.js");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");

ReactDOMRe.renderToElementWithId(ReasonReact.element(undefined, undefined, Counter.make(/* array */[])), "index");

/*  Not a pure module */
