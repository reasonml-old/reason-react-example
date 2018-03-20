const path = require('path');

const isProd = process.env.NODE_ENV === 'production';

module.exports = {
  entry: {
    async: './lib/js/src/async/CounterRoot.js',
    simple: './lib/js/src/simple/SimpleRoot.js',
    fetch: './lib/js/src/fetch/FetchExampleRoot.js',
    logo: './lib/js/src/logo/LogoRoot.js',
    todomvc: './lib/js/src/todomvc/App.js',
    interop: './src/interop/InteropRoot.js',
    retainedProps: './lib/js/src/retainedProps/RetainedPropsRoot.js',
  },
  mode: isProd ? 'production' : 'development',
  output: {
    path: path.join(__dirname, "bundledOutputs"),
    filename: '[name].js',
  },
};
