'use strict';

var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.statelessComponentWithRetainedProps("RetainedPropsExample");

function make(message, _) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */(function (param) {
              if (param[/* oldSelf */0][/* retainedProps */2][/* message */0] !== param[/* newSelf */1][/* retainedProps */2][/* message */0]) {
                console.log("props `message` changed!");
                return /* () */0;
              } else {
                return 0;
              }
            }),
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("div", undefined, message);
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps : record */[/* message */message],
          /* reducer */component[/* reducer */12],
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.component = component;
exports.make = make;
/* component Not a pure module */
