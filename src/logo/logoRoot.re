switch (ReasonJs.Dom.Document.getElementById "index" ReasonJs.Dom.document) {
| None =>
  failwith "Cannot find the element with the ID `index` onto which to mount our React root."
| Some root => ReactDOMRe.render <Logo message="REASON REACT" /> root
};
