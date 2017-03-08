type pageProps = {message: string, name: option string};

include
  ReactRe.CreateComponent {
    include ReactRe.Component.JsProps;
    type props = pageProps;
    let name = "PageReason";
    let render {props} => <div> (ReactRe.stringToElement props.message) </div>;
    /* name is optional, which means the JS side might pass in a null or undefined */
    type jsProps = Js.t {. message : string, name : Js.null_undefined string};
    let jsPropsToReasonProps =
      Some (
        fun jsProps => {message: jsProps##message, name: Js.Null_undefined.to_opt jsProps##name}
      );
  };

let createElement ::message ::name=? => wrapProps {message, name};
