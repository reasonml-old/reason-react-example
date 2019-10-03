'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");

var imageStyle = {
  height: "120px",
  marginRight: "8px",
  borderRadius: "8px",
  boxShadow: "rgb(218, 218, 218) 0px 4px 4px"
};

function FetchedDogPictures(Props) {
  var match = React.useState((function () {
          return /* LoadingDogs */0;
        }));
  var setState = match[1];
  var state = match[0];
  React.useEffect((function () {
          fetch("https://dog.ceo/api/breeds/image/random/3").then((function (response) {
                      return response.json();
                    })).then((function (jsonResponse) {
                    Curry._1(setState, (function (_previousState) {
                            return /* LoadedDogs */[jsonResponse.message];
                          }));
                    return Promise.resolve(/* () */0);
                  })).catch((function (_err) {
                  Curry._1(setState, (function (_previousState) {
                          return /* ErrorFetchingDogs */1;
                        }));
                  return Promise.resolve(/* () */0);
                }));
          return undefined;
        }), ([]));
  return React.createElement("div", {
              style: {
                display: "flex",
                height: "120px",
                alignItems: "center"
              }
            }, typeof state === "number" ? (
                state !== 0 ? "An error occurred!" : "Loading..."
              ) : Belt_Array.map(state[0], (function (dog) {
                      return React.createElement("img", {
                                  key: dog,
                                  style: imageStyle,
                                  src: dog
                                });
                    })));
}

var make = FetchedDogPictures;

exports.imageStyle = imageStyle;
exports.make = make;
/* react Not a pure module */
