const path = require('path');

const isProd = process.env.NODE_ENV === 'production';

module.exports = {
  entry: {
    async: './src/async/CounterRoot.bs.js',
    simple: './src/simple/SimpleRoot.bs.js',
    fetch: './src/fetch/FetchExampleRoot.bs.js',
    todomvc: './src/todomvc/App.bs.js',
    interop: './src/interop/InteropRoot.js',
    retainedProps: './src/retainedProps/RetainedPropsRoot.bs.js',
  },
  mode: isProd ? 'production' : 'development',
  output: {
    path: path.join(__dirname, "bundledOutputs"),
    filename: '[name].js',
  },
};
