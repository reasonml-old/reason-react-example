const rollup = require('rollup').rollup;
const commonjs = require('rollup-plugin-commonjs');
const nodeResolve = require('rollup-plugin-node-resolve');
const replace = require('rollup-plugin-replace');
const path = require('path');

const config = {
  entry: {
    simple: './lib/es6/src/simple/simpleRoot.js',
    logo: './lib/es6/src/logo/logoRoot.js',
    // TODO: enable these
    // todomvc: './lib/es6/src/todomvc/app.js',
    // interop: './src/interop/interopRoot.js',
  },
};
Object.keys(config.entry)
  .forEach(key => {
    const entry = config.entry[key];
    rollup({
      entry: entry, // 'lib/es6/src/' + entry + '.js',
      plugins: [
        replace({
          'process.env.NODE_ENV': JSON.stringify(process.env.NODE_ENV || 'production'),
        }),
        nodeResolve({
          jsnext: true,
          main: true,
          module: true,
        }),

        commonjs({
          // non-CommonJS modules will be ignored, but you can also
          // specifically include/exclude files
          include: 'node_modules/**',
          // exclude: [ 'node_modules/foo/**', 'node_modules/bar/**' ],

          // if true then uses of `global` won't be dealt with by this plugin
          ignoreGlobal: false,
          preferBuiltins: true,

          // if false then skip sourceMap generation for CommonJS modules
          sourceMap: false,

          // explicitly specify unresolvable named exports
          // (see below for more details)
          namedExports: {
            'react': [
              'createClass',
              'createElement',
            ],
            'react-dom': [
              'render'
            ]
          },

          // sometimes you have to leave require statements
          // unconverted. Pass an array containing the IDs
          // or a `id => boolean` function. Only use this
          // option if you know what you're doing!
          // ignore: [ 'conditional-runtime-dependency' ]
        }),
      ]
    })
    .then((result) => {
      // const filename = last(entry.split('/'));
      return result.write({
        dest: path.join(__dirname, 'rollupOutputs', key + '.js'),
        format: 'iife'
      });
    })
    .catch(console.log);
  });
