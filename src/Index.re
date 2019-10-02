[@bs.val] external document: Js.t({..}) = "document";

document##body##style##fontSize #= "16px";

let makeContainer = (text) => {
  let container = document##createElement("div");
  container##style##margin #= "24px 0px";
  container##style##boxShadow #= "0px 4px 16px #dadada";
  container##style##flexDirection #= "column";

  let title = document##createElement("div");
  title##innerText #= text
  title##style##backgroundColor #= "rgb(242, 243, 245)"
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

  content
};

// =============

ReactDOMRe.render(
  <StatefulCounter greeting="Hi!" />,
  makeContainer("Stateful Counter, using useState")
);

ReactDOMRe.render(
  <BlinkingGreeting>
    <div> {React.string("How are you")} </div>
  </BlinkingGreeting>,
  makeContainer("Blinking Greeting, using useState & useEffect")
);

ReactDOMRe.render(
  <ReducerExampleFromReactJSDocs />,
  makeContainer("ReactJS Documentation Example, using useReducer")
);

ReactDOMRe.render(
  <FetchDogPictures />,
  makeContainer("Randomly Fetched Dogs, using useEffect & useState & promises")
);

ReactDOMRe.render(
  <ButtonFromReactJS disabled=false label="ReasonReact using a ReactJS button" />,
  makeContainer("Interop Example 1")
);

ReactDOMRe.render(
  <InteropExample />,
  makeContainer("Interop Example 2")
);

