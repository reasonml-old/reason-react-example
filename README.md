This is a repo with examples usages of [Reason-React](https://github.com/reasonml/reason-react), whose docs are [here](https://github.com/reasonml/reason-react/blob/master/documentation.md).
Have something you don't understand? Join us on [Discord](https://discord.gg/reasonml)!

## Usage

Clone the repo and move into the project:
```bash
git clone https://github.com/chenglou/reason-react-example.git

cd reason-react-example
```

Install dependencies:
```bash
npm install
```

Compile your reason:
```bash
npm start
```

After you see the qnd compilation succeed (the `npm start` step), open up your browser to `localhost:8000` . You should see todomvc app. 

If you want to change the example project, navigate to `qnd.js` and change the following:
```js
qnd(
  ... ,
  '/src/todomvc/index.html' // <---- change folder name todomvc to simple, logo, etc.
)();
```
