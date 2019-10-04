'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");

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
          return ;
        }), ([]));
  var tmp;
  if (typeof state === "number") {
    tmp = state !== 0 ? "An error occurred!" : "Loading...";
  } else {
    var dogs = state[0];
    tmp = Belt_Array.mapWithIndex(dogs, (function (i, dog) {
            var match = i === (dogs.length - 1 | 0);
            var imageStyle = {
              backgroundImage: "url(" + (String(dog) + ")"),
              backgroundPosition: "center",
              height: "120px",
              marginRight: match ? "0px" : "8px",
              width: "100%",
              backgroundSize: "cover",
              borderRadius: "8px",
              boxShadow: "0px 4px 16px rgb(200, 200, 200)"
            };
            return React.createElement("div", {
                        key: dog,
                        style: imageStyle
                      });
          }));
  }
  return React.createElement("div", {
              style: {
                display: "flex",
                height: "120px",
                alignItems: "center",
                justifyContent: "center"
              }
            }, tmp);
}

var make = FetchedDogPictures;

exports.make = make;
/* react Not a pure module */
