const path = require("path");

module.exports = {
  entry: {
    kandan: "./lib/js/src/kandan/root.js"
  },
  output: {
    path: path.join(__dirname, "resources/public/js/"),
    filename: "[name].js"
  }
};
