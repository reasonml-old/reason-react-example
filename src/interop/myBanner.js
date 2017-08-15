var ReactDOM = require('react-dom');
var React = require('react');

var App = function(props) {
  if (props.show) {
    return React.createElement('div', null,
      props.message
    );
  } else {
    return null;
  }
}
App.displayName = "MyBanner";

module.exports = App;
