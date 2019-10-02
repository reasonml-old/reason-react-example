[@bs.val] external document: Js.t({..}) = "document";

document##body##style##fontSize #= "16px";

let makeContainer = (text) => {
  let container = document##createElement("div");
  container##className #= "container";
  container##style##margin #= "24px 0px";
  container##style##backgroundColor #= "#fafafa";
  // container##style##border #= "1px solid #eee";
  container##style##borderRadius #= "12px";
  container##style##padding #= "12px";
  container##style##boxShadow #= "0px 4px 16px #dadada";
  container##style##display #= "flex";
  container##style##alignItems #= "center";

  let title = document##createElement("div");
  title##innerText #= text

  let content = document##createElement("div");

  let () = container##appendChild(title);
  let () = container##appendChild(content);
  let () = document##body##appendChild(container);

  content
};

// let styleElement = document##createElement("style")
// let () = document##head##appendChild(styleElement)
// styleElement##sheet##insertRule("
//   button {
//     background-color: red;
//   }
// ")

// =============

ReactDOMRe.render(
  <StatefulCounter greeting="Hi!" />,
  makeContainer("hi")
);

ReactDOMRe.render(
  <BlinkingGreeting>
    <div> {React.string("hi")} </div>
  </BlinkingGreeting>,
  makeContainer("hi")
);

ReactDOMRe.render(
  <ReducerExampleFromReactJSDocs />,
  makeContainer("hi")
);

ReactDOMRe.render(
  <FetchDogPictures />,
  makeContainer("hi")
);

ReactDOMRe.render(
  <ButtonFromReactJS disabled=false label="ReasonReact using a ReactJS button" />,
  makeContainer("hi")
);

ReactDOMRe.render(
  <InteropExample />,
  makeContainer("hi")
);

