let escapeKey = 27;

let enterKey = 13;

module Main_area = {
  include ReactRe.Component.Stateful;
  let name = "MainArea";
  type props = {
    channel: State.channel,
    users: list State.user,
    me: State.user,
    onFocus: bool => unit,
    onLeftSidebarToggled: bool => unit,
    onRightSidebarToggled: bool => unit,
    onMessageSubmitted: State.channel => State.message => unit,
    leftSidebarOpen: bool,
    rightSidebarOpen: bool,
    searchTerm: option string
  };
  let _onFocus onFocus focused _ => onFocus focused;
  let _onLeftSidebarToggled onLeftSidebarToggled opened _ => onLeftSidebarToggled opened;
  let _onRightSidebarToggled onRightSidebarToggled opened _ => onRightSidebarToggled opened;
  let _onMessageSubmitted onMessageSubmitted channel message _ =>
    onMessageSubmitted channel message;
  type state = {editText: string};
  let getInitialState _props => {editText: ""};
  let handleSubmit {props, state} event =>
    switch (String.trim state.editText) {
    | "" => None
    | _ =>
      _onMessageSubmitted
        props.onMessageSubmitted
        props.channel
        State.{createdAt: Js.Date.now (), content: state.editText, userId: props.me.id}
        event;
      Some {editText: ""}
    };
  let handleButtonSubmit componentBag event => handleSubmit componentBag event;
  let handleKeyUp componentBag (event: ReactEventRe.Keyboard.t) =>
    if (
      ReactEventRe.Keyboard.which event === enterKey && not (ReactEventRe.Keyboard.shiftKey event)
    ) {
      handleSubmit componentBag event
    } else {
      None
    };
  let handleChange _ (event: ReactEventRe.Form.t) =>
    Some {
      editText:
        ReasonJs.HtmlElement.value (Utils.domAsHtmlElement (ReactEventRe.Form.target event))
    };
  let render {props, state, updater} => {
    let activityItem (activity: State.message) => {
      let user =
        List.find (fun (user: State.user) => State.(user.id === activity.userId)) props.users;
      let (renderableMessage, media, _media_count) =
        Plugins.renderableOfMessage props.me props.users props.channel activity;
      let key =
        "activity-" ^
        string_of_int State.(props.channel.id) ^ "-" ^ string_of_float State.(activity.createdAt);
      <div
        className="activity"
        id=(
             "activity-" ^
             string_of_int props.channel.id ^
             "-" ^ string_of_float activity.createdAt ^ activity.content
           )
        key>
        <span className="posted_at">
          (ReactRe.stringToElement (Utils.timeAgo activity.createdAt ^ " ago"))
        </span>
        <img className="avatar" src=(Utils.gravatarUrl user.email) />
        <div className="readable">
          <span className="user"> (ReactRe.stringToElement (Utils.nameOfUser user)) </span>
          <span className="content">
            (
              ReactRe.arrayToElement (
                Array.mapi
                  (fun idx el => <span key=(string_of_int idx)> el </span>) renderableMessage
              )
            )
          </span>
          <div className="media-container"> media </div>
        </div>
      </div>
    };
    let activityItems =
      State.(props.channel.activities) |>
      List.filter (
        fun (activity: State.message) =>
          switch props.searchTerm {
          | None => true
          | Some term =>
            switch (
              Local_string.indexOf
                (Local_string.lowerCase activity.content) (Local_string.lowerCase term)
            ) {
            | (-1) => false
            | _ => true
            }
          }
      ) |>
      List.sort (fun a b => compare State.(a.createdAt) State.(b.createdAt)) |>
      List.map activityItem |> Array.of_list;
    <article className="main-area">
      <header className="header">
        <a
          className="nav-toggle button left"
          href="#"
          onClick=(_onLeftSidebarToggled props.onLeftSidebarToggled (not props.leftSidebarOpen))>
          <i className="icon-comments" />
        </a>
        <a
          className="sidebar-toggle button right"
          href="#"
          onClick=(_onRightSidebarToggled props.onRightSidebarToggled (not props.rightSidebarOpen))>
          <i className="icon-reorder" />
        </a>
        <a className="logo" href="#/">
          <img alt="Omchaya" src="images/logo.png" title="Omchaya - A Kandan Client" />
        </a>
      </header>
      <div id="channels">
        <div className="channels-pane active" id=("channels-" ^ string_of_int props.channel.id)>
          <div className="paginated-activities"> (ReactRe.arrayToElement activityItems) </div>
          <div className="chatbox">
            <textarea
              className="chat-input"
              onBlur=(_onFocus props.onFocus false)
              onFocus=(_onFocus props.onFocus true)
              value=state.editText
              onChange=(updater handleChange)
              onKeyUp=(updater handleKeyUp)
            />
            <button onClick=(updater handleButtonSubmit) className="post">
              (ReactRe.stringToElement "Post")
            </button>
          </div>
        </div>
      </div>
    </article>
  };
};

include ReactRe.CreateComponent Main_area;

let createElement
    ::channel
    ::users
    ::me
    ::onMessageSubmitted
    ::onFocus
    ::onLeftSidebarToggled
    ::onRightSidebarToggled
    ::leftSidebarOpen
    ::rightSidebarOpen
    ::searchTerm =>
  wrapProps {
    channel,
    users,
    me,
    onMessageSubmitted,
    onFocus,
    onLeftSidebarToggled,
    onRightSidebarToggled,
    leftSidebarOpen,
    rightSidebarOpen,
    searchTerm
  };
