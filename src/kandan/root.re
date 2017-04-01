Utils.setPageTitle "Loading...";

let location = ReasonJs.Dom.Window.location ReasonJs.Dom.window;

let path = ReasonJs.Dom.Location.hash location;

switch (ReasonJs.Dom.Document.getElementById "index" ReasonJs.Dom.document) {
| None => raise (Invalid_argument "Unable to find root 'index' element, cannot start app")
| Some el => ReactDOMRe.render <Wip message="Hello!" rootEl=el path /> el
};
