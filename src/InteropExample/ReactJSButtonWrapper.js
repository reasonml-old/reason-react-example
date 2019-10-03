var ReactDOM = require('react-dom');
var React = require('react');

var ReasonReactButton = require('./ReasonReactButton.bs').make;

var ReactJSComponent = function(props) {
  // We're not using JSX here, to avoid folks needing to install the related
  // React toolchains just for this example.

  return React.createElement(
    "div",
    {style: {"backgroundColor": "rgba(0, 0, 0, 0.05)", "borderRadius": "8px", "padding": "12px"}},
    React.createElement("div", {style: {marginBottom: "8px"}}, "This is a ReactJS card"),
    React.createElement(ReasonReactButton),
  )
};
ReactJSComponent.displayName = "MyBanner";

module.exports = ReactJSComponent;
