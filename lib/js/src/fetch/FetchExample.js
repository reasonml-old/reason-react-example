'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Json_decode = require("@glennsl/bs-json/lib/js/src/Json_decode.bs.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

function dogs(json) {
  return $$Array.map((function (dog) {
                return dog;
              }), Json_decode.field("message", (function (param) {
                    return Json_decode.array(Json_decode.string, param);
                  }), json));
}

var Decode = /* module */[/* dogs */dogs];

var component = ReasonReact.reducerComponent("FetchExample");

function make() {
  var newrecord = component.slice();
  newrecord[/* didMount */4] = (function (self) {
      Curry._1(self[/* send */4], /* DogsFetch */0);
      return /* NoUpdate */0;
    });
  newrecord[/* render */9] = (function (self) {
      var match = self[/* state */2];
      if (typeof match === "number") {
        if (match !== 0) {
          return React.createElement("div", undefined, "An error occurred!");
        } else {
          return React.createElement("div", undefined, "Loading...");
        }
      } else {
        return React.createElement("div", undefined, React.createElement("h1", undefined, "Dogs"), React.createElement("p", undefined, "Source: "), React.createElement("a", {
                        href: "https://dog.ceo"
                      }, "https://dog.ceo"), React.createElement("ul", undefined, $$Array.map((function (dog) {
                              return React.createElement("li", {
                                          key: dog
                                        }, dog);
                            }), match[0])));
      }
    });
  newrecord[/* initialState */10] = (function () {
      return /* Loading */0;
    });
  newrecord[/* reducer */12] = (function (action, _) {
      if (typeof action === "number") {
        if (action !== 0) {
          return /* Update */Block.__(0, [/* Error */1]);
        } else {
          return /* UpdateWithSideEffects */Block.__(3, [
                    /* Loading */0,
                    (function (self) {
                        fetch("https://dog.ceo/api/breeds/list").then((function (prim) {
                                    return prim.json();
                                  })).then((function (json) {
                                  var dogs$1 = dogs(json);
                                  return Promise.resolve(Curry._1(self[/* send */4], /* DogsFetched */[dogs$1]));
                                })).catch((function () {
                                return Promise.resolve(Curry._1(self[/* send */4], /* DogsFailedToFetch */1));
                              }));
                        return /* () */0;
                      })
                  ]);
        }
      } else {
        return /* Update */Block.__(0, [/* Loaded */[action[0]]]);
      }
    });
  return newrecord;
}

exports.Decode = Decode;
exports.component = component;
exports.make = make;
/* component Not a pure module */
