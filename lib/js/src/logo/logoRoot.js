'use strict';

var Logo        = require("./Logo.js");
var ReactDOMRe  = require("reason-react/lib/js/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

ReactDOMRe.renderToElementWithId(ReasonReact.element(/* None */0, /* None */0, Logo.make("REASON REACT", /* array */[])), "index");

/*  Not a pure module */
