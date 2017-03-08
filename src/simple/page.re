module Page = {
  include ReactRe.Component;
  type props = {message: string};
  let name = "Page";
  let handleClick _ _ => {
    Js.log "clicked!";
    None
  };
  let render {props, updater} =>
    <div onClick=(updater handleClick)> (ReactRe.stringToElement props.message) </div>;
};

include ReactRe.CreateComponent Page;

let createElement ::message => wrapProps {message: message};
