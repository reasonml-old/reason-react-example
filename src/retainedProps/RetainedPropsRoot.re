let toggle = ref false;

let render () => {
  toggle := not toggle.contents;
  ReactDOMRe.renderToElementWithId
    <RetainedPropsExample message=(toggle.contents ? "Hello!" : "Goodbye") /> "index"
};

Js.Global.setInterval render 1000;

/* render once first! */
render ();
