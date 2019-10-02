[@bs.val] external document: Js.t({..}) = "document";

document##body##style##fontSize #= "16px";

// TODO: make this into a RR component too or not?
let makeContainer = text => {
  let container = document##createElement("div");
  container##style##margin #= "24px 0px";
  container##style##boxShadow #= "0px 4px 16px #dadada";
  container##style##flexDirection #= "column";

  let title = document##createElement("div");
  title##innerText #= text;
  title##style##backgroundColor #= "rgb(242, 243, 245)";
  title##style##borderRadius #= "12px 12px 0px 0px";
  title##style##padding #= "12px";
  title##style##fontWeight #= "bold";

  let content = document##createElement("div");
  content##style##display #= "flex";
  content##style##alignItems #= "center";
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
    <div> {React.string("Hello!")} </div>
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
