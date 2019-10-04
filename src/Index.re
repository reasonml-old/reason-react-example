// TODO: explain this file

[@bs.val] external document: Js.t({..}) = "document";

let reasonReactBlue = "#48a9dc";

let style = document##createElement("style");
document##head##appendChild(style);
style##innerHTML #= {j|
  body {
    background-color: rgb(224, 226, 229);
    display: flex;
    flex-direction: column;
    align-items: center;
  }
  button {
    background-color: white;
    color: $reasonReactBlue;
    box-shadow: 0 0 0 1px $reasonReactBlue;
    border: none;
    padding: 8px;
    font-size: 16px;
  }
  button:active {
    background-color: $reasonReactBlue;
    color: white;
  }
|j};

// TODO: make this into a RR component too or not?
let makeContainer = text => {
  let container = document##createElement("div");
  container##style##margin #= "12px 0px";
  container##style##boxShadow #= "0px 4px 16px rgb(200, 200, 200)";
  container##style##width #= "720px";
  container##style##borderRadius #= "12px";
  container##style##fontFamily #= "sans-serif";

  let title = document##createElement("div");
  title##innerText #= text;
  title##style##backgroundColor #= "rgb(242, 243, 245)";
  title##style##borderRadius #= "12px 12px 0px 0px";
  title##style##padding #= "12px";
  title##style##fontWeight #= "bold";

  let content = document##createElement("div");
  content##style##backgroundColor #= "white";
  content##style##padding #= "16px";
  content##style##borderRadius #= "0px 0px 12px 12px";

  let () = container##appendChild(title);
  let () = container##appendChild(content);
  let () = document##body##appendChild(container);

  content;
};

// =============

ReactDOMRe.render(
  <BlinkingGreeting>
    {React.string("Hello!")}
  </BlinkingGreeting>,
  makeContainer("Blinking Greeting"),
);

ReactDOMRe.render(
  <ReducerExampleFromReactJSDocs />,
  makeContainer("Reducer Example From ReactJS Docs"),
);

ReactDOMRe.render(
  <FetchedDogPictures />,
  makeContainer("Fetched Dog Pictures"),
);

ReactDOMRe.render(
  <InteropExample />,
  makeContainer("Interop Example"),
);
