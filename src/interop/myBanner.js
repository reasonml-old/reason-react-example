var ReactDOM = require('react-dom');
var React = require('react');

var App = React.createClass({
  displayName: "MyBanner",
  render: function() {
    if (this.props.show) {
      return React.createElement('div', null,
        this.props.message
      );
    } else {
      return null;
    }
  }
});

module.exports = App;
