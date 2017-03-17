Js.log "Do you see this message? If you do, then things should work!";

switch (ReasonJs.Document.getElementById "index" ReasonJs.Dom.document) {
| None => raise (Invalid_argument "Root element 'index' not found in document")
| Some el => ReactDOMRe.render <Page message="Hello!" /> el
};
