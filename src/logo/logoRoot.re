switch (ReasonJs.Document.getElementById "index" ReasonJs.Dom.document) {
| None => Js.log "Root element 'index' not found on page, unable to start React app"
| Some el => ReactDOMRe.render <Logo message="REASON REACT" /> el
};
