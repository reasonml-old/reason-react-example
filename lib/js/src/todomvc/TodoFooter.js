'use strict';

var React = require("react");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var component = ReasonReact.statelessComponent("TodoFooterRe");

function push(path, $$event) {
  $$event.preventDefault();
  return ReasonReact.Router[/* push */0]("#" + path);
}

function make(count, completedCount, nowShowing, onClearCompleted, _) {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      var match = +(count === 1);
      var activeTodoWord = match !== 0 ? "item" : "items";
      var match$1 = +(completedCount > 0);
      var clearButton = match$1 !== 0 ? React.createElement("button", {
              className: "clear-completed",
              onClick: onClearCompleted
            }, "Clear completed") : null;
      var match$2;
      switch (nowShowing) {
        case 0 : 
            match$2 = /* tuple */[
              "selected",
              "",
              ""
            ];
            break;
        case 1 : 
            match$2 = /* tuple */[
              "",
              "selected",
              ""
            ];
            break;
        case 2 : 
            match$2 = /* tuple */[
              "",
              "",
              "selected"
            ];
            break;
        
      }
      return React.createElement("footer", {
                  className: "footer"
                }, React.createElement("span", {
                      className: "todo-count"
                    }, React.createElement("strong", undefined, String(count)), " " + (activeTodoWord + " left")), React.createElement("ul", {
                      className: "filters"
                    }, React.createElement("li", undefined, React.createElement("a", {
                              className: match$2[0],
                              onClick: (function (param) {
                                  return push("", param);
                                })
                            }, "All")), " ", React.createElement("li", undefined, React.createElement("a", {
                              className: match$2[1],
                              onClick: (function (param) {
                                  return push("active", param);
                                })
                            }, "Active")), " ", React.createElement("li", undefined, React.createElement("a", {
                              className: match$2[2],
                              onClick: (function (param) {
                                  return push("completed", param);
                                })
                            }, "Completed"))), clearButton);
    });
  return newrecord;
}

exports.component = component;
exports.push = push;
exports.make = make;
/* component Not a pure module */
