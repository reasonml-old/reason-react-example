switch (ReasonJs.Document.getElementById "index" ReasonJs.Dom.document) {
| None => raise (Invalid_argument "Root element 'index' not found in document")
| Some el => ReactDOMRe.render <Logo message="REASON REACT" /> el
};
