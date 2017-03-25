Utils.setPageTitle "Loading...";

switch (ReasonJs.Dom.Document.getElementById "index" ReasonJs.Dom.document) {
| None => raise (Invalid_argument "Unable to find root 'index' element, cannot start app")
| Some el => ReactDOMRe.render <Kandan message="Hello!" rootEl=el /> el
};
