var ReactDOM = require('react-dom');
var React = require('react');

var App = React.createClass({
  render: function() {
    return React.createElement('div', null, (this.props.message + " num: " + this.props.num));
  }
});

module.exports = App;
