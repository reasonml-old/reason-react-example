var qnd = require('qnd');

qnd(
  'development',
  {
    simple: './src/simple/simpleRoot.re',
    logo: './src/logo/logoRoot.re',
    todomvc: './src/todomvc/app.re',
    interop: './src/interop/interopRoot.js'
  },
  __dirname,
  'bundledOutputs',
  '/src/todomvc/index.html'
)();
