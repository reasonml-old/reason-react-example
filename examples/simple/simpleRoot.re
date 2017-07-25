/*
   <Page key=key ref=ref message="Hello!" />

   Should Become in JS::

    ReasonReact.createElement Page.jsComponent {
     "key": key,
     "ref": ref,
     "reasonProps": Element Page.component (Page.make message::message [])
    }

 */
type domElement;

external renderReactDOM : ReasonReact.reactElement => domElement => unit =
  "render" [@@bs.val] [@@bs.module "react-dom"];

external _getElementById : string => option domElement =
  "document.getElementById" [@@bs.val] [@@bs.return null_to_opt];

let renderToElementWithId reactElement id =>
  switch (_getElementById id) {
  | None =>
    raise (
      Invalid_argument ("ReactDOMRE.renderToElementWithId : no element of id " ^ id ^ " found in the HTML.")
    )
  | Some domElement => renderReactDOM reactElement domElement
  };

renderToElementWithId
  (ReasonReact.element (Page.ComponentGallery.make [||])) "index";
