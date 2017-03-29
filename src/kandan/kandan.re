let fullHeight = ReactDOMRe.Style.make height::"100%" ();

module Kandan = {
  include ReactRe.Component;
  let name = "KandanAppRe";
  type props = {message: string, rootEl: Dom.element};
  let render {props} =>
    <div id="app" style=fullHeight> <Wip message=props.message rootEl=props.rootEl /> </div>;
};

include ReactRe.CreateComponent Kandan;

let createElement ::message ::rootEl => wrapProps {message, rootEl};
