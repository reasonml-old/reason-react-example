'use strict';

var React = require("react");
var ReactDom = require("react-dom");
var InteropExample$ReactHooks = require("./InteropExample/InteropExample.bs.js");
var BlinkingGreeting$ReactHooks = require("./BlinkingGreeting/BlinkingGreeting.bs.js");
var FetchedDogPictures$ReactHooks = require("./FetchedDogPictures/FetchedDogPictures.bs.js");
var ReducerExampleFromReactJSDocs$ReactHooks = require("./ReducerExampleFromReactJSDocs/ReducerExampleFromReactJSDocs.bs.js");

document.body.style.fontSize = "16px";

function makeContainer(text) {
  var container = document.createElement("div");
  container.style.margin = "24px 0px";
  container.style.boxShadow = "0px 4px 16px #dadada";
  container.style.flexDirection = "column";
  var title = document.createElement("div");
  title.innerText = text;
  title.style.backgroundColor = "rgb(242, 243, 245)";
  title.style.borderRadius = "12px 12px 0px 0px";
  title.style.padding = "12px";
  title.style.fontWeight = "bold";
  var content = document.createElement("div");
  content.style.display = "flex";
  content.style.alignItems = "center";
  content.style.backgroundColor = "white";
  content.style.padding = "16px";
  content.style.borderRadius = "0px 0px 12px 12px";
  container.appendChild(title);
  container.appendChild(content);
  document.body.appendChild(container);
  return content;
}

ReactDom.render(React.createElement(BlinkingGreeting$ReactHooks.make, {
          children: React.createElement("div", undefined, "Hello!")
        }), makeContainer("Blinking Greeting"));

ReactDom.render(React.createElement(ReducerExampleFromReactJSDocs$ReactHooks.make, { }), makeContainer("Reducer Example From ReactJS Docs"));

ReactDom.render(React.createElement(FetchedDogPictures$ReactHooks.make, { }), makeContainer("Fetched Dog Pictures"));

ReactDom.render(React.createElement(InteropExample$ReactHooks.make, { }), makeContainer("Interop Example"));

exports.makeContainer = makeContainer;
/*  Not a pure module */
