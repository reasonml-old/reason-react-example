var ReactDOM = require('react-dom');
var React = require('react');

var ReasonReactButton = require('./ReasonReactButton.bs').make;

var ReactJSComponent = function() {
  let backgroundColor = "rgba(0, 0, 0, 0.05)";
  let padding = "12px";

  // We're not using JSX here, to avoid folks needing to install the related
  // React toolchains just for this example.
  // <div style={...}>
  //   <div style={...}>This is a ReactJS card</div>
  //   <ReasonReactButton style={...} />
  // </div>
  return React.createElement(
    "div",
    {style: {backgroundColor, padding, borderRadius: "8px"}},
    React.createElement("div", {style: {marginBottom: "8px"}}, "This is a ReactJS card"),
    React.createElement(ReasonReactButton, {style: {backgroundColor, padding, borderRadius: "4px"}}),
  )
};
ReactJSComponent.displayName = "MyBanner";

module.exports = ReactJSComponent;
