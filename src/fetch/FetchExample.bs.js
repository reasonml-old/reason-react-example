'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");
var Json_decode = require("@glennsl/bs-json/src/Json_decode.bs.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");

function dogs(json) {
  var __x = Json_decode.field("message", (function (param) {
          return Json_decode.array(Json_decode.string, param);
        }), json);
  return Belt_Array.map(__x, (function (dog) {
                return dog;
              }));
}

var Decode = /* module */[/* dogs */dogs];

var component = ReasonReact.reducerComponent("FetchExample");

function make() {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */(function (self) {
              return Curry._1(self[/* send */3], /* DogsFetch */0);
            }),
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              var match = self[/* state */1];
              if (typeof match === "number") {
                if (match !== 0) {
                  return React.createElement("div", undefined, "An error occurred!");
                } else {
                  return React.createElement("div", undefined, "Loading...");
                }
              } else {
                return React.createElement("div", undefined, React.createElement("h1", undefined, "Dogs"), React.createElement("p", undefined, "Source: "), React.createElement("a", {
                                href: "https://dog.ceo"
                              }, "https://dog.ceo"), React.createElement("ul", undefined, Belt_Array.map(match[0], (function (dog) {
                                      return React.createElement("li", {
                                                  key: dog
                                                }, dog);
                                    }))));
              }
            }),
          /* initialState */(function () {
              return /* Loading */0;
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, _) {
              if (typeof action === "number") {
                if (action !== 0) {
                  return /* Update */Block.__(0, [/* Error */1]);
                } else {
                  return /* UpdateWithSideEffects */Block.__(2, [
                            /* Loading */0,
                            (function (self) {
                                fetch("https://dog.ceo/api/breeds/list").then((function (prim) {
                                            return prim.json();
                                          })).then((function (json) {
                                          var dogs$1 = dogs(json);
                                          return Promise.resolve(Curry._1(self[/* send */3], /* DogsFetched */[dogs$1]));
                                        })).catch((function () {
                                        return Promise.resolve(Curry._1(self[/* send */3], /* DogsFailedToFetch */1));
                                      }));
                                return /* () */0;
                              })
                          ]);
                }
              } else {
                return /* Update */Block.__(0, [/* Loaded */[action[0]]]);
              }
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.Decode = Decode;
exports.component = component;
exports.make = make;
/* component Not a pure module */
