**Don't tweet about this please!**

Prerequisite: having [Ninja](https://ninja-build.org/) installed (version 1.7+), e.g. `brew install ninja` if you're on macOS. Then do `npm install -g git://github.com/reasonml/reason-cli.git`

```
git clone https://github.com/chenglou/rehydrate-example.git
npm install
npm start
# in another tab
npm run build
```

After you see the webpack compilation succeed (the `npm run build` step), open up `src/index.html`! Then modify `src/index.re` and refresh the page to see the changes.
