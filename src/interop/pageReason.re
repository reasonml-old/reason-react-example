module PageReason = {
  include ReactRe.Component.JsProps;
  type props = {message: string, extraGreeting: option string};
  let name = "PageReason";
  let render {props} => {
    let greeting =
      switch props.extraGreeting {
      | None => "How are you?"
      | Some g => g
      };
    <div> <MyBannerRe show=true message=(props.message ^ " " ^ greeting) /> </div>
  };
  /* extraGreeting is optional, which means the JS side might pass in a null or undefined */
  type jsProps = Js.t {. message : string, extraGreeting : Js.null_undefined string};
  let jsPropsToReasonProps =
    Some (
      fun jsProps => {
        message: jsProps##message,
        extraGreeting: Js.Null_undefined.to_opt jsProps##extraGreeting
      }
    );
};

include ReactRe.CreateComponent PageReason;

let createElement ::message ::extraGreeting=? => wrapProps {message, extraGreeting};
