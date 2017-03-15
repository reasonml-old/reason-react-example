Js.log "Do you see this message? If you do, then things should work!";

switch (ReasonJs.Document.getElementById "index" ReasonJs.Dom.document) {
| None => Js.log "Root element 'index' not found on page, unable to start React app"
| Some el => ReactDOMRe.render <Page message="Hello!" /> el
};
