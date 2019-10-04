'use strict';

var React = require("react");
var ReactDom = require("react-dom");
var InteropExample$ReasonReactExamples = require("./InteropExample/InteropExample.bs.js");
var BlinkingGreeting$ReasonReactExamples = require("./BlinkingGreeting/BlinkingGreeting.bs.js");
var ExampleContainer$ReasonReactExamples = require("./ExampleContainer.bs.js");
var FetchedDogPictures$ReasonReactExamples = require("./FetchedDogPictures/FetchedDogPictures.bs.js");
var ReducerExampleFromReactJSDocs$ReasonReactExamples = require("./ReducerExampleFromReactJSDocs/ReducerExampleFromReactJSDocs.bs.js");

var style = document.createElement("style");

document.head.appendChild(style);

style.innerHTML = ExampleContainer$ReasonReactExamples.globalStyle;

var container = document.createElement("div");

document.body.appendChild(container);

ReactDom.render(React.createElement(React.Fragment, undefined, React.createElement(ExampleContainer$ReasonReactExamples.make, {
              title: "Blinking Greeting",
              children: React.createElement(BlinkingGreeting$ReasonReactExamples.make, {
                    children: "Hello!"
                  })
            }), React.createElement(ExampleContainer$ReasonReactExamples.make, {
              title: "Reducer Example From ReactJS Docs",
              children: React.createElement(ReducerExampleFromReactJSDocs$ReasonReactExamples.make, { })
            }), React.createElement(ExampleContainer$ReasonReactExamples.make, {
              title: "Fetched Dog Pictures",
              children: React.createElement(FetchedDogPictures$ReasonReactExamples.make, { })
            }), React.createElement(ExampleContainer$ReasonReactExamples.make, {
              title: "Interop Example",
              children: React.createElement(InteropExample$ReasonReactExamples.make, { })
            })), container);

exports.style = style;
exports.container = container;
/* style Not a pure module */
