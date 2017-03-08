type pageProps = {message: string};

include
  ReactRe.CreateComponent {
    include ReactRe.Component;
    type props = pageProps;
    let name = "Page";
    let handleClick _ _ => {
      Js.log "clicked!";
      None
    };
    let render {props, updater} =>
      <div onClick=(updater handleClick)> (ReactRe.stringToElement props.message) </div>;
  };

let createElement ::message => wrapProps {message: message};
