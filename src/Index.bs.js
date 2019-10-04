'use strict';

var React = require("react");
var ReactDom = require("react-dom");
var InteropExample$ReasonReactExamples = require("./InteropExample/InteropExample.bs.js");
var BlinkingGreeting$ReasonReactExamples = require("./BlinkingGreeting/BlinkingGreeting.bs.js");
var FetchedDogPictures$ReasonReactExamples = require("./FetchedDogPictures/FetchedDogPictures.bs.js");
var ReducerExampleFromReactJSDocs$ReasonReactExamples = require("./ReducerExampleFromReactJSDocs/ReducerExampleFromReactJSDocs.bs.js");

var reasonReactBlue = "#48a9dc";

var style = document.createElement("style");

document.head.appendChild(style);

style.innerHTML = "\n  body {\n    background-color: rgb(224, 226, 229);\n    display: flex;\n    flex-direction: column;\n    align-items: center;\n  }\n  button {\n    background-color: white;\n    color: " + (String(reasonReactBlue) + (";\n    box-shadow: 0 0 0 1px " + (String(reasonReactBlue) + (";\n    border: none;\n    padding: 8px;\n    font-size: 16px;\n  }\n  button:active {\n    background-color: " + (String(reasonReactBlue) + ";\n    color: white;\n  }\n")))));

function makeContainer(text) {
  var container = document.createElement("div");
  container.style.margin = "12px 0px";
  container.style.boxShadow = "0px 4px 16px rgb(200, 200, 200)";
  container.style.width = "720px";
  container.style.borderRadius = "12px";
  container.style.fontFamily = "sans-serif";
  var title = document.createElement("div");
  title.innerText = text;
  title.style.backgroundColor = "rgb(242, 243, 245)";
  title.style.borderRadius = "12px 12px 0px 0px";
  title.style.padding = "12px";
  title.style.fontWeight = "bold";
  var content = document.createElement("div");
  content.style.backgroundColor = "white";
  content.style.padding = "16px";
  content.style.borderRadius = "0px 0px 12px 12px";
  container.appendChild(title);
  container.appendChild(content);
  document.body.appendChild(container);
  return content;
}

ReactDom.render(React.createElement(BlinkingGreeting$ReasonReactExamples.make, {
          children: "Hello!"
        }), makeContainer("Blinking Greeting"));

ReactDom.render(React.createElement(ReducerExampleFromReactJSDocs$ReasonReactExamples.make, { }), makeContainer("Reducer Example From ReactJS Docs"));

ReactDom.render(React.createElement(FetchedDogPictures$ReasonReactExamples.make, { }), makeContainer("Fetched Dog Pictures"));

ReactDom.render(React.createElement(InteropExample$ReasonReactExamples.make, { }), makeContainer("Interop Example"));

exports.reasonReactBlue = reasonReactBlue;
exports.style = style;
exports.makeContainer = makeContainer;
/* style Not a pure module */
