var ReactDOM = require('react-dom');
var React = require('react');

var ReasonReactComponent = require('./ReasonReactComponent.bs').make;

var ReactJSComponent = function(props) {
  // We're not using JSX here, to avoid folks needing to install the related
  // React toolchains just for this example.

  // <ReasonReactComponent label="ReactJS using a ReasonReact button" />
  return React.createElement(
    ReasonReactComponent,
    {"label": "ReactJS using a ReasonReact button"},
    null,
  );
};
ReactJSComponent.displayName = "MyBanner";

module.exports = ReactJSComponent;
