# ReasonReact Template & Examples

This is:
- A template for your new ReasonReact project.
- A collection of thin examples illustrating ReasonReact usage.
- Extra helper documentation for ReasonReact (full ReasonReact docs [here](https://reasonml.github.io/reason-react/)).

`src` contains 4 sub-folders, each an independent ReasonReact example. Feel free to delete any of them and shape this into your project!

## Run

```sh
npm install
npm run server
# in a new tab
npm start
```

Open a new web page to `http://localhost:8000/`. Change any `.re` file in `src` to see the page auto-reload.

# Features Used

|                           | BlinkingGreeting | ReducerExampleFromReactJSDocs | FetchDogPictures | InteropExample |
|---------------------------|------------------|-------------------------------|------------------|----------------|
| No props                  |                  | ✓                             |                  |               |
| Has props                 |                  |                               |                  | ✓             |
| Children props            | ✓                |                               |                  |               |
| No state                  |                  |                               |                  | ✓             |
| Has state                 | ✓                |                               |  ✓               |               |
| Has state with useReducer |                  | ✓                             |                  |               |
| ReasonReact using ReactJS |                  |                               |                  | ✓             |
| ReactJS using ReasonReact |                  |                               |                  | ✓             |
| useEffect                 | ✓                |                               |  ✓              |                |
| Dom attribute             | ✓                | ✓                             |                 | ✓             |
| Styling                   | ✓                | ✓                             |  ✓              | ✓             |
| React.array               |                  |                               |  ✓               |               |

# Build Pipeline

TODO:

talk about our bundle pipeline
check index.html
webpack, rollup (only for prod)