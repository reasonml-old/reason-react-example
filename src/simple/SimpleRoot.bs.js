'use strict';

var Page = require("./Page.bs.js");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");

ReactDOMRe.renderToElementWithId(ReasonReact.element(/* None */0, /* None */0, Page.make("Hello!", /* array */[])), "index");

/*  Not a pure module */
