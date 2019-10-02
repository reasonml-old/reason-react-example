// This file isn't used directly by JS; it's used to myBanner.re, which is then
// used by the ReasonReact component GreetingRe.

var ReactDOM = require('react-dom');
var React = require('react');

var App = function(props) {
  // We're not using JSX here, to avoid folks needing to install the related
  // React toolchains just for this example.
  // <button disabled={props.disabled} aria-label={props.label}>
  //   {props.label}
  // </button>
  return React.createElement(
    'button',
    {
      "disabled": props.disabled,
      "aria-label": props.label,
    },
    props.label
  );
};
App.displayName = "MyBanner";

module.exports = App;
