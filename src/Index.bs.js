'use strict';

var React = require("react");
var ReactDom = require("react-dom");
var InteropExample$ReactHooks = require("./ReactJSUsingReasonReact/InteropExample.bs.js");
var StatefulCounter$ReactHooks = require("./StatefulCounter.bs.js");
var BlinkingGreeting$ReactHooks = require("./BlinkingGreeting.bs.js");
var FetchDogPictures$ReactHooks = require("./FetchDogPictures.bs.js");
var ButtonFromReactJS$ReactHooks = require("./ReasonReactUsingReactJS/ButtonFromReactJS.bs.js");
var ReducerExampleFromReactJSDocs$ReactHooks = require("./ReducerExampleFromReactJSDocs.bs.js");

document.body.style.fontSize = "16px";

function makeContainer(text) {
  var container = document.createElement("div");
  container.className = "container";
  container.style.margin = "24px 0px";
  container.style.backgroundColor = "#fafafa";
  container.style.borderRadius = "12px";
  container.style.padding = "12px";
  container.style.boxShadow = "0px 4px 16px #dadada";
  container.style.display = "flex";
  container.style.alignItems = "center";
  var title = document.createElement("div");
  title.innerText = text;
  var content = document.createElement("div");
  container.appendChild(title);
  container.appendChild(content);
  document.body.appendChild(container);
  return content;
}

ReactDom.render(React.createElement(StatefulCounter$ReactHooks.make, {
          greeting: "Hi!"
        }), makeContainer("hi"));

ReactDom.render(React.createElement(BlinkingGreeting$ReactHooks.make, {
          children: React.createElement("div", undefined, "hi")
        }), makeContainer("hi"));

ReactDom.render(React.createElement(ReducerExampleFromReactJSDocs$ReactHooks.make, { }), makeContainer("hi"));

ReactDom.render(React.createElement(FetchDogPictures$ReactHooks.make, { }), makeContainer("hi"));

ReactDom.render(React.createElement(ButtonFromReactJS$ReactHooks.make, {
          disabled: false,
          label: "ReasonReact using a ReactJS button"
        }), makeContainer("hi"));

ReactDom.render(React.createElement(InteropExample$ReactHooks.make, { }), makeContainer("hi"));

exports.makeContainer = makeContainer;
/*  Not a pure module */
