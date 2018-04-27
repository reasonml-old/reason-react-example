const path = require('path');

const isProd = process.env.NODE_ENV === 'production';

module.exports = {
  entry: {
    async: './src/async/CounterRoot.js',
    simple: './src/simple/SimpleRoot.js',
    fetch: './src/fetch/FetchExampleRoot.js',
    todomvc: './src/todomvc/App.js',
    interop: './src/interop/InteropRoot.js',
    retainedProps: './src/retainedProps/RetainedPropsRoot.js',
  },
  mode: isProd ? 'production' : 'development',
  output: {
    path: path.join(__dirname, "bundledOutputs"),
    filename: '[name].js',
  },
};
