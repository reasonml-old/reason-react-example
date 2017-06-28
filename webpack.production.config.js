const path = require('path');
const webpack = require('webpack');

module.exports = {
  entry: {
    async: './lib/js/src/async/counterRoot.js',
    simple: './lib/js/src/simple/simpleRoot.js',
    logo: './lib/js/src/logo/logoRoot.js',
    todomvc: './lib/js/src/todomvc/app.js',
    interop: './src/interop/interopRoot.js',
  },
  output: {
    path: path.join(__dirname, "bundledOutputs"),
    filename: '[name].js',
  },
  plugins: [
    new webpack.LoaderOptionsPlugin({ minimize: true }),
    new webpack.DefinePlugin({ 'process.env': {'NODE_ENV': JSON.stringify('production')} }),
    new webpack.optimize.UglifyJsPlugin({ comments: false }),
    new webpack.optimize.AggressiveMergingPlugin()
  ]
};
