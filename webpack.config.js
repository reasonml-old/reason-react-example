const path = require('path');

module.exports = {
  entry: {
    index: './lib/js/src/index.js',
  },
  output: {
    path: path.join(__dirname, "src"),
    filename: '[name].js',
  },
};
