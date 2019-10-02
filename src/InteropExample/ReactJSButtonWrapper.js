var ReactDOM = require('react-dom');
var React = require('react');

var ReasonReactButton = require('./ReasonReactButton.bs').make;

var ReactJSComponent = function(props) {
  // We're not using JSX here, to avoid folks needing to install the related
  // React toolchains just for this example.

  // <ReasonReactButton label="I'm a ReactJS component, wrapping a ReasonReact component!" />
  return React.createElement(
    ReasonReactButton,
    {"label": "I'm a ReactJS component, wrapping a ReasonReact component!"},
    null,
  );
};
ReactJSComponent.displayName = "MyBanner";

module.exports = ReactJSComponent;
