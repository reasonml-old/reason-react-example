let escapeKey = 27;

let enterKey = 13;

module Chatbox = {
  include ReactRe.Component.Stateful;
  let name = "MainArea";
  type props = {
    channel: State.channel,
    me: State.user,
    users: list State.user,
    onFocus: bool => unit,
    onMessageSubmitted: State.channel => State.message => unit
  };
  type state = {editText: string};
  let getInitialState _props => {editText: ""};
  let handleSubmit {props, state} =>
    switch (String.trim state.editText) {
    | "" => None
    | _ =>
      props.onMessageSubmitted
        props.channel
        State.{createdAt: Js.Date.now (), content: state.editText, userId: props.me.id};
      Some {editText: ""}
    };
  let handleButtonSubmit componentBag _event => handleSubmit componentBag;
  let handleKeyUp componentBag (event: ReactEventRe.Keyboard.t) =>
    if (
      ReactEventRe.Keyboard.which event === enterKey && not (ReactEventRe.Keyboard.shiftKey event)
    ) {
      handleSubmit componentBag
    } else {
      None
    };
  let handleChange _ (event: ReactEventRe.Form.t) =>
    Some {
      editText:
        ReasonJs.Dom.HtmlElement.value (Utils.domAsHtmlElement (ReactEventRe.Form.target event))
    };
  let render {props, state, updater} =>
    <textarea
      className="chat-input"
      onBlur=(fun _event => props.onFocus false)
      onFocus=(fun _event => props.onFocus true)
      placeholder=("Chat in #" ^ Local_string.lowerCase props.channel.title)
      value=state.editText
      onChange=(updater handleChange)
      onKeyUp=(updater handleKeyUp)
    />;
};

include ReactRe.CreateComponent Chatbox;

let createElement ::channel ::users ::onMessageSubmitted ::me ::onFocus =>
  wrapProps {channel, users, onMessageSubmitted, me, onFocus};
