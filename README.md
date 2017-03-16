This is a repo with examples usages of [Reason-React](https://github.com/reasonml/reason-react), whose docs are [here](https://github.com/reasonml/reason-react/blob/master/documentation.md).
Have something you don't understand? Join us on [Discord](https://discord.gg/reasonml)!

```
git clone https://github.com/chenglou/reason-react-example.git
cd reason-react-example
npm install
npm start
# in another tab
npm run build
# in another tab
cd resources/public
python -m SimpleHTTPServer 8001
```

Then visit http://localhost:8001/ !


After you see the webpack compilation succeed (the `npm run build` step), open up the html files in `src/*`! Then modify whichever file in `src` and refresh the page to see the changes.
