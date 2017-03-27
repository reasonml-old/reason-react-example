let fullHeight = ReactDOMRe.Style.make height::"100%" ();

let scrollToLatestMessage target channelId =>
  switch (ReasonJs.Dom.Element.querySelector ("#channels-" ^ string_of_int channelId) target) {
  | None => ()
  | Some channelEl =>
    switch (
      ReasonJs.Dom.NodeList.toArray (
        ReasonJs.Dom.Element.querySelectorAll
          ("#channels-" ^ string_of_int channelId ^ "\n  .activity") target
      )
    ) {
    | [||] => ()
    | activities =>
      let latest = activities.(Array.length activities - 1);
      ReasonJs.Dom.Element.setScrollTop
        channelEl (ReasonJs.Dom.HtmlElement.offsetTop (Utils.nodeAsHtmlElement latest));
      ()
    }
  };

let toggleSearchForm (rootEl: ReasonJs.Dom.element) (selector: string) (event: bool) :unit =>
  switch (ReasonJs.Dom.Element.querySelector selector rootEl) {
  | None => ()
  | Some inputEl =>
    event ?
      ReasonJs.Dom.HtmlElement.focus (Utils.domAsHtmlElement inputEl) :
      ReasonJs.Dom.HtmlElement.blur (Utils.domAsHtmlElement inputEl)
  };

module Kandan = {
  include ReactRe.Component.Stateful;
  let name = "KandanAppRe";
  type props = {message: string, rootEl: ReasonJs.Dom.element};
  type state = State.appState;
  let getInitialState _props => Demo.state;
  let sidebarToggled {state} which opened =>
    State.(
      switch which {
      | Left => Some {...state, leftSidebarOpen: opened}
      | Right => Some {...state, rightSidebarOpen: opened}
      }
    );
  let searchUpdated {state} needle =>
    switch needle {
    | None => Some {...state, State.search: None}
    | Some "" => Some {...state, State.search: None}
    | Some search => Some {...state, State.search: Some search}
    };
  let volumeSet {state} volume => Some State.{...state, volume, lastVolume: state.volume};
  let volumeDecremented {state} delta =>
    Some State.{...state, volume: max 0.0 (state.volume -. delta), lastVolume: state.volume};
  let volumeIncremented {state} delta =>
    Some State.{...state, volume: min 1.0 (state.volume +. delta), lastVolume: state.volume};
  let volumeMuteToggled {state} =>
    Some State.{
           ...state,
           volume: state.volume == 0.0 ? state.lastVolume : 0.0,
           lastVolume: state.volume
         };
  let channelSelected {state} channel =>
    Some State.{...state, selectedChannelId: channel.id, title: channel.title ^ " - Kandan"};
  let songSelected {state} (channel: State.channel) (media: State.media) => {
    let currentChannel =
      State.(List.find (fun haystack => haystack.id === channel.id) state.channels);
    let otherChannels =
      List.filter (fun haystack => State.(haystack.id) !== channel.id) State.(state.channels);
    let newChannel = {...currentChannel, media};
    let newChannels = List.append otherChannels [newChannel];
    Some {...state, channels: newChannels}
  };
  let mediaStateUpdated {state} (channel: State.channel) (newState: State.mediaPlayerState) => {
    let currentChannel =
      List.find (fun haystack => State.(haystack.id) === channel.id) State.(state.channels);
    let otherChannels =
      List.filter (fun haystack => State.(haystack.id) !== channel.id) State.(state.channels);
    let newChannel =
      switch newState {
      | NotLoaded
      | Paused => {...currentChannel, mediaState: newState, media: currentChannel.media}
      | Playing =>
        let media =
          switch (currentChannel.media.src, List.length currentChannel.playlist) {
          /* Media selected, use that */
          | (Some _, _) => currentChannel.media
          /* No media selected, but none in the playlist */
          | (None, 0) => currentChannel.media
          /* No media selected,  pick the first media in channel playlist */
          | (None, _) => List.nth currentChannel.playlist 0
          };
        {...currentChannel, mediaState: newState, media}
      };
    let newChannels = List.append otherChannels [newChannel];
    Some {...state, channels: newChannels}
  };
  let chatBoxFocused {state} focused => Some State.{...state, userMessageFocused: focused};
  let searchFormFocused {state} focused => Some State.{...state, searchFormFocused: focused};
  let userMenuToggled {state} opened => Some State.{...state, userMenuOpen: opened};
  let msgSubmitted {state} (channel: State.channel) (_me: State.user) (msg: State.message) => {
    let newMsg = {...msg, content: Local_string.trim msg.content};
    let mediaToQueue: option State.media =
      switch (Local_string.indexOf newMsg.content "/queue") {
      | 0 =>
        let parts = Local_string.split newMsg.content [%bs.re "/ /"];
        switch (Array.length parts) {
        | 0 => assert false
        | 1 => None
        | _ => Some {order: List.length channel.playlist, src: Some parts.(1)}
        }
      | _ => None
      };
    let currentChannel =
      List.find (fun haystack => State.(haystack.id) === channel.id) State.(state.channels);
    let otherChannels =
      List.filter (fun haystack => State.(haystack.id) !== channel.id) State.(state.channels);
    let newChannel = {
      ...currentChannel,
      activities: List.append currentChannel.activities [newMsg],
      playlist:
        switch mediaToQueue {
        | None => currentChannel.playlist
        | Some newMedia => List.append currentChannel.playlist [newMedia]
        }
    };
    let newChannels = List.append otherChannels [newChannel];
    Some {...state, channels: newChannels}
  };
  let processEffects {props} (action: State.action) _oldState newState => {
    open State;
    /* Maybe this should take a list of Effect instead of an action, elm style?  */
    Js.log ("Processing effect for action: " ^ State.stringOfAction action);
    switch action {
    | SearchFormFocused focused =>
      ignore (
        ReasonJs.setTimeout (fun () => toggleSearchForm props.rootEl "input.query" focused) 100
      )
    | SidebarToggled _ _ => ()
    | SearchUpdated _ => ()
    | ChannelSelected channel =>
      ignore (ReasonJs.setTimeout (fun () => scrollToLatestMessage props.rootEl channel.id) 100)
    | ChannelSelectedByIndex idx =>
      let sortedChannels =
        List.sort
          (fun (a: State.channel) (b: State.channel) => compare a.title b.title) newState.channels;
      let channel = List.nth sortedChannels idx;
      ignore (ReasonJs.setTimeout (fun () => scrollToLatestMessage props.rootEl channel.id) 100)
    | SongSelected _ _ => ()
    | MediaStateUpdated _ _ => ()
    | ChatBoxFocused _ => ()
    | UserMenuToggled _ => ()
    | MsgSubmitted channel _ _ =>
      ignore (ReasonJs.setTimeout (fun () => scrollToLatestMessage props.rootEl channel.id) 100)
    | AppTitleUpdated title _badge_count => Utils.setPageTitle title
    | VolumeSet _
    | VolumeDecremented _
    | VolumeIncremented _
    | VolumeMuteToggled => ()
    | Log str => Js.log str
    | Alert str => ReasonJs.Window.alert str ReasonJs.Dom.window
    };
    ()
  };
  let notAEventlessAction action =>
    Failure (
      State.stringOfAction action ^ " is not an eventless action, you must add it to the dispatchEventless switch"
    );
  /* Used when calling from outside of React (window keydown event, etc.) */
  let dispatchEventless (action: State.action) componentBag () => {
    open State;
    Js.log ("New EL action: " ^ stringOfAction action);
    let newState =
      switch action {
      | SearchFormFocused focused => searchFormFocused componentBag focused
      | VolumeSet volume => volumeSet componentBag volume
      | VolumeDecremented delta => volumeDecremented componentBag delta
      | VolumeIncremented delta => volumeIncremented componentBag delta
      | VolumeMuteToggled => volumeMuteToggled componentBag
      | SearchUpdated needle => searchUpdated componentBag needle
      | SidebarToggled which opened => sidebarToggled componentBag which opened
      | ChannelSelected channel => channelSelected componentBag channel
      | ChannelSelectedByIndex idx =>
        let sortedChannels =
          List.sort
            (fun (a: State.channel) (b: State.channel) => compare a.title b.title)
            componentBag.state.channels;
        channelSelected componentBag (List.nth sortedChannels idx)
      | Log _
      | Alert _ => None
      | SongSelected channel media => songSelected componentBag channel media
      | MediaStateUpdated channel state => mediaStateUpdated componentBag channel state
      | ChatBoxFocused focused => chatBoxFocused componentBag focused
      | UserMenuToggled opened => userMenuToggled componentBag opened
      | MsgSubmitted channel user msg => msgSubmitted componentBag channel user msg
      | AppTitleUpdated _ _ => raise (notAEventlessAction action)
      };
    let {state} = componentBag;
    processEffects
      componentBag
      action
      state
      (
        switch newState {
        | None => state
        | Some newState => newState
        }
      );
    newState
  };
  let killEventAndRedispatch action componentBag event => {
    ReactEventRe.Synthetic.preventDefault event;
    dispatchEventless action componentBag ()
  };
  /* Used when calling from a React handler. Most of the time they'll delegate to the eventless dispatcher, but they may need to do something to an event first */
  let dispatchEventful (action: State.action) componentBag (event: ReactEventRe.Synthetic.t) => {
    open State;
    Js.log ("New EF action: " ^ stringOfAction action);
    let (effectAlreadyProcessed, newState) =
      switch action {
      /* eventful */
      | VolumeDecremented _
      | VolumeIncremented _
      | VolumeMuteToggled => (true, killEventAndRedispatch action componentBag event)
      /* eventless */
      | _ => (true, dispatchEventless action componentBag ())
      };
    if (not effectAlreadyProcessed) {
      processEffects
        componentBag
        action
        componentBag.state
        (
          switch newState {
          | None => componentBag.state
          | Some newState => newState
          }
        )
    };
    newState
  };
  let render {state, updater} => {
    let _dispatch action => updater (dispatchEventful action);
    let dispatchEL action => updater (dispatchEventless action);
    let sortedChannels =
      List.sort
        (fun (a: State.channel) (b: State.channel) => compare a.title b.title) state.channels;
    let currentChannel =
      List.find
        (fun (channel: State.channel) => channel.id === State.(state.selectedChannelId))
        State.(state.channels);
    let keyMap =
      State.[
        (["ctrl+esc"], Log "ctrl esc yo!"),
        (["ctrl+?"], UserMenuToggled state.userMenuOpen),
        (["/"], SearchFormFocused true),
        (["ctrl+-"], VolumeDecremented 0.1),
        (
          ["ctrl+shift+<"],
          try (SongSelected currentChannel (Utils.findNextMedia currentChannel (-1))) {
          | _ => Log "No previous media in channel"
          }
        ),
        (
          ["ctrl+shift+>"],
          try (SongSelected currentChannel (Utils.findNextMedia currentChannel 1)) {
          | _ => Log "No previous media in channel"
          }
        ),
        (
          ["ctrl+p"],
          MediaStateUpdated
            currentChannel
            (
              switch currentChannel.mediaState {
              | NotLoaded => NotLoaded
              | Paused => Playing
              | Playing => Paused
              }
            )
        ),
        (["ctrl+shift+="], VolumeIncremented 0.1),
        (["ctrl+1"], ChannelSelectedByIndex 0),
        (["ctrl+2"], ChannelSelectedByIndex 1),
        (["ctrl+3"], ChannelSelectedByIndex 2),
        (["ctrl+4"], ChannelSelectedByIndex 3),
        (["ctrl+5"], ChannelSelectedByIndex 4),
        (["ctrl+6"], ChannelSelectedByIndex 5),
        (["ctrl+7"], ChannelSelectedByIndex 6),
        (["ctrl+8"], ChannelSelectedByIndex 7),
        (["ctrl+9"], ChannelSelectedByIndex 9),
        (["ctrl+0"], VolumeMuteToggled),
        (["esc"], SearchFormFocused false),
        (["ctrl+shift+esc"], Alert "ctrl shift esc yo!"),
        (
          ["up", "up", "down", "down", "left", "right", "left", "right", "a", "b"],
          Alert "Konami code!"
        )
      ];
    let me =
      switch (Utils.findMeOpt state) {
      | None => assert false
      | Some user => user
      };
    let className =
      switch (state.rightSidebarOpen, state.leftSidebarOpen) {
      | (true, true) => "slide-right slide-left"
      | (true, false) => "slide-left"
      | (false, true) => "slide-right"
      | (false, false) => ""
      };
    let audioChannels =
      List.map
        (
          fun (channel: State.channel) =>
            <Audio_player
              channel
              id=channel.id
              key=(string_of_int channel.id)
              volume=(channel.id == currentChannel.id ? state.volume : 0.0)
              audioState=channel.mediaState
            />
        )
        state.channels;
    <div id="app" style=fullHeight> <Wip message="Hi there" /> </div>
    /* <div className style=fullHeight>
         (ReactRe.arrayToElement (Array.of_list audioChannels))
         <Key_queue keyMap onMatch=dispatchEL />
         <Sidebar
           channel=currentChannel
           users=State.(state.users)
           me
           menuOpen=state.userMenuOpen
           onUserMenuToggled=(fun opened => dispatchEL State.(UserMenuToggled opened) ())
           onSongSelected=(fun media => dispatchEL State.(SongSelected currentChannel media) ())
           onMediaStateUpdated=(
                                 fun (newState: State.mediaPlayerState) =>
                                   dispatchEL State.(MediaStateUpdated currentChannel newState) ()
                               )
           onVolumeAdjusted=(fun volume => dispatchEL State.(VolumeSet volume) ())
           lastVolume=state.lastVolume
           volume=state.volume
         />
         <Main_area
           me
           users=state.users
           channel=currentChannel
           leftSidebarOpen=state.leftSidebarOpen
           rightSidebarOpen=state.rightSidebarOpen
           searchTerm=state.search
           onFocus=(fun focused => dispatchEL State.(ChatBoxFocused focused) ())
           onMessageSubmitted=(fun channel msg => dispatchEL State.(MsgSubmitted channel me msg) ())
           onLeftSidebarToggled=(fun opened => dispatchEL State.(SidebarToggled Left opened) ())
           onRightSidebarToggled=(fun opened => dispatchEL State.(SidebarToggled Right opened) ())
         />
         <Navbar
           selectedChannelId=state.selectedChannelId
           channels=sortedChannels
           focused=state.searchFormFocused
           searchTerm=state.search
           onSearchUpdated=(fun term => dispatchEL (SearchUpdated term) ())
           onFocus=(fun focused => dispatchEL State.(SearchFormFocused focused) ())
           onChannelSelected=(fun channel => dispatchEL State.(ChannelSelected channel) ())
         />
         <div className="at-view" id="at-view"> <ul id="at-view-ul" /> </div>
       </div> */
  };
  let componentDidMount ({state} as componentBag) => {
    open State;
    let currentChannel =
      List.find
        (fun (channel: State.channel) => channel.id === state.selectedChannelId) state.channels;
    ignore (
      ReasonJs.setTimeout
        (fun _ => processEffects componentBag (ChannelSelected currentChannel) state state) 250
    );
    processEffects componentBag (AppTitleUpdated state.title 0) state state;
    None
  };
  let componentDidUpdate prevProps::_prevProps prevState::(prevState: State.appState) componentBag => {
    open State;
    let state: State.appState = componentBag.state;
    if (not (state.title == prevState.title)) {
      processEffects componentBag (AppTitleUpdated state.title 0) state state
    };
    None
  };
};

include ReactRe.CreateComponent Kandan;

let createElement ::message ::rootEl => wrapProps {message, rootEl};
