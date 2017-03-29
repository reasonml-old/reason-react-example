open ReactDOMRe.Style;

let cursorPointer = ReactDOMRe.Style.make cursor::"pointer" ();

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

let toggleSearchForm (rootEl: Dom.element) (selector: string) (event: bool) :unit =>
  switch (ReasonJs.Dom.Element.querySelector selector rootEl) {
  | None => ()
  | Some inputEl =>
    event ?
      ReasonJs.Dom.HtmlElement.focus (Utils.domAsHtmlElement inputEl) :
      ReasonJs.Dom.HtmlElement.blur (Utils.domAsHtmlElement inputEl)
  };

/* let coloring2 = make backgroundColor::"red" color::"white" ();

   let coloring3 = make backgroundColor::"blue" color::"white" ();

   let coloring4 color => make backgroundColor::color ::color (); */
let menuItem = make display::"flex" alignItems::"center" height::"4rem" padding::"1.5rem" ();

let menuIcon =
  make
    display::"flex" alignItems::"center" justifyContent::"center" width::"4rem" height::"4rem" ();

let annexGroup = make marginBottom::"1.5rem" ();

let annexTitle =
  make
    fontSize::"1.5rem"
    lineHeight::"1"
    display::"flex"
    alignItems::"center"
    marginTop::".5rem"
    marginBottom::".5rem"
    padding::"0 1.5rem"
    ();

let annexItem = make display::"flex" alignItems::"center" padding::".25rem 1.5rem" ();

let text = ReactRe.stringToElement;

/*
 <div
   style=(
           switch state.counter {
           | 0 => coloring2
           | 1 => coloring3
           | 2 => coloring3
           | myValue when myValue mod 2 == 0 => coloring4 "blue"
           | myValue when myValue mod 2 != 0 => coloring2
           | _ => coloring2
           }
         )>
   (
     text (
       props.message ^
       ": " ^ string_of_int state.counter ^ " ~~~ " ^ (state.counter == 10 ? "YAY" : "BOO")
     )
   )
   <button onClick=(fun _ => setState (fun {state} => {...state, counter: state.counter + 1}))>
     (text "Click me")
   </button>
 </div>
  */
/* module Item = {
     include ReactRe.Component;
     let name = "Item";
     type props = {message: string};
     let render {props} =>
       <div style=(make display::"flex" flexDirection::"column" minHeight::"100vh" ())>
         (text props.message)
       </div>;
   }; */
/* module Wip = {
     include ReactRe.Component.Stateful;
     type state = {leftMenuOpened: bool, rightMenuOpened: bool};
     let getInitialState _ => {leftMenuOpened: true, rightMenuOpened: true};
     let name = "Wip";
     type props = {message: string};
     let render {props, state, setState} =>
       <div style=(make display::"flex" flexDirection::"column" minHeight::"100vh" ())>
         <div style=(make display::"flex" height::"4rem" ())>
           <div style=menuIcon> (text "X") </div>
           <div
             style=(make flex::"1" display::"flex" alignItems::"center" justifyContent::"center" ())>
             <input
               _type="text"
               placeholder="Search"
               style=(make width::"100%" textAlign::"center" ())
             />
           </div>
           <div
             style=menuIcon
             onClick=(
                       fun _ =>
                         setState (
                           fun {state} => {...state, rightMenuOpened: not state.rightMenuOpened}
                         )
                     )>
             (text "X")
           </div>
         </div>
         <div style=(make display::"flex" flex::"1" ())>
           <div style=(make width::"16rem" ())>
             <div style=menuItem> (text "channel 1") </div>
             <div style=menuItem> (text "channel 2") </div>
             <div style=menuItem> (text "channel 3") </div>
             <div style=menuItem> (text "channel 4") </div>
             <div style=menuItem> (text "channel 5") </div>
           </div>
           <div
             style=(
                     make
                       flex::"1"
                       flexDirection::"column"
                       display::"flex"
                       borderTop::"1px solid #eee"
                       borderRight::"1px solid #eee"
                       borderLeft::"1px solid #eee"
                       ()
                   )>
             <div style=(make flex::"1" padding::"1.5rem" ())> <div> (text "msg") </div> </div>
             <div style=(make borderTop::"1px solid #eee" ())>
               <input
                 _type="text"
                 placeholder="chat msg"
                 style=(make height::"4rem" padding::"1.25rem" ())
               />
             </div>
           </div>
           <div style=(make display::"flex" flexDirection::"column" width::"16rem" ())>
             <div style=(make flex::"1" ())>
               <div style=menuItem> (text "person 1") </div>
               <div style=menuItem> (text "person 2") </div>
               <div style=menuItem> (text "person 3") </div>
             </div>
             <div style=(make display::"flex" alignItems::"center" height::"4rem" ())>
               <div style=(make padding::"0 1.5rem" ())> (text "song 1") </div>
             </div>
           </div>
         </div>
       </div>;
   }; */
let searchField searchTerm onSearchUpdated =>
  <input
    _type="text"
    placeholder="Search..."
    value=(
            switch searchTerm {
            | None => ""
            | Some term => term
            }
          )
    onChange=(
               fun event => {
                 let x =
                   switch (
                     ReasonJs.Dom.HtmlElement.value (
                       Utils.domAsHtmlElement (ReactEventRe.Form.target event)
                     )
                   ) {
                   | "" => None
                   | term => Some term
                   };
                 onSearchUpdated x
               }
             )
    onKeyDown=(
                fun event =>
                  if (ReactEventRe.Keyboard.which event == 13) {
                    ReactEventRe.Keyboard.preventDefault event
                  }
              )
  />;

module Wip = {
  include ReactRe.Component.Stateful;
  let name = "Wip";
  type props = {message: string, rootEl: Dom.element};
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
  let mediaProgressUpdated {state} (channel: State.channel) (progress: int) (duration: int) => {
    let currentChannel =
      List.find (fun haystack => State.(haystack.id) === channel.id) State.(state.channels);
    let otherChannels =
      List.filter (fun haystack => State.(haystack.id) !== channel.id) State.(state.channels);
    let media = {...currentChannel.media, duration: Some duration};
    let newChannel = {...currentChannel, mediaProgress: progress, media};
    let newChannels = List.append otherChannels [newChannel];
    Some {...state, channels: newChannels}
  };
  let mediaScrubbedTo {state} (channel: State.channel) (percent: float) (time: float) => {
    let currentChannel =
      List.find (fun haystack => State.(haystack.id) === channel.id) State.(state.channels);
    let otherChannels =
      List.filter (fun haystack => State.(haystack.id) !== channel.id) State.(state.channels);
    let newChannel = {...currentChannel, mediaScrubbedTo: Some (percent, time)};
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
        | _ => Some {order: List.length channel.playlist, src: Some parts.(1), duration: None}
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
        Js.Global.setTimeout (fun () => toggleSearchForm props.rootEl "input.query" focused) 100
      )
    | SidebarToggled _ _ => ()
    | SearchUpdated _ => ()
    | ChannelSelected channel =>
      ignore (Js.Global.setTimeout (fun () => scrollToLatestMessage props.rootEl channel.id) 100)
    | ChannelSelectedByIndex idx =>
      let sortedChannels =
        List.sort
          (fun (a: State.channel) (b: State.channel) => compare a.title b.title) newState.channels;
      let channel = List.nth sortedChannels idx;
      ignore (Js.Global.setTimeout (fun () => scrollToLatestMessage props.rootEl channel.id) 100)
    | SongSelected _ _ => ()
    | MediaStateUpdated _ _
    | MediaPlayerScrubbed _ _ _
    | MediaProgressUpdated _ _ _ => ()
    | ChatBoxFocused _ => ()
    | UserMenuToggled _ => ()
    | MsgSubmitted channel _ _ =>
      ignore (Js.Global.setTimeout (fun () => scrollToLatestMessage props.rootEl channel.id) 100)
    | AppTitleUpdated title _badge_count => Utils.setPageTitle title
    | VolumeSet _
    | VolumeDecremented _
    | VolumeIncremented _
    | VolumeMuteToggled => ()
    | Log str => Js.log str
    | Alert str => ReasonJs.Dom.Window.alert str ReasonJs.Dom.window
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
      | MediaPlayerScrubbed channel percent time =>
        mediaScrubbedTo componentBag channel percent time
      | MediaProgressUpdated channel progress duration =>
        mediaProgressUpdated componentBag channel progress duration
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
    let me =
      switch (Utils.findMeOpt state) {
      | None => assert false
      | Some user => user
      };
    let sortedChannels =
      State.(
        List.sort
          (fun (a: State.channel) (b: State.channel) => compare a.title b.title) state.channels
      );
    let currentChannel =
      List.find
        (fun (channel: State.channel) => channel.id === State.(state.selectedChannelId))
        State.(state.channels);
    let activities =
      State.(currentChannel.activities) |>
      List.sort (fun a b => compare State.(a.createdAt) State.(b.createdAt));
    let filteredActivities =
      switch state.search {
      | None => activities
      | Some term =>
        State.(
          activities |>
          List.filter (
            fun (activity: message) =>
              switch (
                Local_string.indexOf
                  (Local_string.lowerCase activity.content) (Local_string.lowerCase term)
              ) {
              | (-1) => false
              | _ => true
              }
          )
        )
      };
    let filteredChannels =
      switch state.search {
      | None => sortedChannels
      | Some term =>
        State.(
          sortedChannels |>
          List.filter (
            fun (channel: channel) =>
              switch (
                Local_string.indexOf
                  (Local_string.lowerCase channel.title) (Local_string.lowerCase term)
              ) {
              | (-1) => false
              | _ => true
              }
          )
        )
      };
    let filteredPlaylist =
      switch state.search {
      | None => currentChannel.playlist
      | Some term =>
        State.(
          currentChannel.playlist |>
          List.filter (
            fun (media: media) =>
              switch media.src {
              | None => false
              | Some src =>
                switch (
                  Local_string.indexOf (Local_string.lowerCase src) (Local_string.lowerCase term)
                ) {
                | (-1) => false
                | _ => true
                }
              }
          )
        )
      };
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
    let dispatchEL action => updater (dispatchEventless action);
    let audioChannels =
      sortedChannels |>
      List.map (
        fun (channel: State.channel) =>
          <Audio_player
            channel
            id=channel.id
            key=(string_of_int channel.id)
            volume=(channel.id == currentChannel.id ? state.volume : 0.0)
            audioState=channel.mediaState
            percent=channel.mediaScrubbedTo
            onTimeUpdated=(
                            fun el => {
                              let duration = Audio_player.AudioElement.duration el;
                              let currentTime = Audio_player.AudioElement.currentTime el;
                              dispatchEL
                                State.(MediaProgressUpdated channel currentTime duration) ()
                            }
                          )
          />
      ) |> Array.of_list;
    let userEntry (user: State.user) =>
      State.(
        <li className="user" title=(Utils.nameOfUser user) key=(string_of_int user.id)>
          <img className="avatar" src=(Utils.gravatarUrl user.email) />
          <span> (ReactRe.stringToElement (Utils.nameOfUser user)) </span>
        </li>
      );
    let channelEntry (channel: State.channel) => {
      open State;
      let channelUsers =
        state.users |>
        List.filter (fun (user: State.user) => State.UserIdSet.mem user.id channel.userIds) |>
        List.sort (
          fun a b =>
            compare (String.lowercase (Utils.nameOfUser a)) (String.lowercase (Utils.nameOfUser b))
        );
      <div onClick=(fun _ => dispatchEL (ChannelSelected channel) ()) className="menu-item">
        (text channel.title)
        <ul className="channel-users-list">
          (ReactRe.listToElement (List.map userEntry channelUsers))
        </ul>
      </div>
    };
    let songEntry media =>
      <li
        className="menu-item"
        onClick=(fun _ => dispatchEL State.(SongSelected currentChannel media) ())>
        <div className="menu-thumbnail"> <img src="https://placehold.it/64" /> </div>
        <div className="menu-text"> (text (Utils.mediaSrcToTitle media)) </div>
      </li>;
    <div className="container">
      (ReactRe.arrayToElement audioChannels)
      <Key_queue keyMap onMatch=dispatchEL />
      /* <div className="atop">
           <div className="atop-button"> (text "X") </div>
           <div className="atop-title">
             (text "Title")
           </div>
           <div
             className="atop-button"
             onClick=(
                       fun _ =>
                         setState (
                           fun {state} => {...state, rightMenuOpened: not state.rightMenuOpened}
                         )
                     )>
             (text "X")
           </div>
         </div> */
      <div className="main">
        <div className="menu left">
          <div className="menu-items channels">
            (searchField state.search (fun term => dispatchEL (SearchUpdated term) ()))
            (ReactRe.listToElement (List.map channelEntry filteredChannels))
          </div>
        </div>
        <div className="chat">
          <div className="chat-feed">
            State.(
              filteredActivities |>
              List.map (
                fun (activity: message) => {
                  let user =
                    List.find (fun (user: State.user) => user.id === activity.userId) state.users;
                  let (renderableMessage, media, _media_count) =
                    Plugins.renderableOfMessage me state.users currentChannel activity;
                  <div>
                    <img className="avatar" src=(Utils.gravatarUrl user.email) />
                    (ReactRe.arrayToElement renderableMessage)
                    <div className="media-container"> media </div>
                  </div>
                }
              ) |> ReactRe.listToElement
            )
          </div>
          <Chatbox
            me
            channel=currentChannel
            users=state.users
            onFocus=(fun focused => dispatchEL State.(ChatBoxFocused focused) ())
            onMessageSubmitted=(
                                 fun channel msg =>
                                   dispatchEL State.(MsgSubmitted channel me msg) ()
                               )
          />
        </div>
        <div className="menu right">
          <div className="menu-items songs">
            <ul> (ReactRe.listToElement (List.map songEntry filteredPlaylist)) </ul>
          </div>
        </div>
      </div>
      <div className="player">
        <div className="left controls">
          <span
            onClick=(
                      fun _event =>
                        dispatchEL
                          State.(
                            SongSelected currentChannel (Utils.findNextMedia currentChannel (-1))
                          )
                          ()
                    )>
            (text "<<")
          </span>
          <span
            onClick=State.(
                      fun _event => {
                        let newState =
                          switch currentChannel.mediaState {
                          | Playing => Paused
                          | Paused => Playing
                          | NotLoaded => NotLoaded
                          };
                        dispatchEL (MediaStateUpdated currentChannel newState) ()
                      }
                    )>
            (
              text (
                switch currentChannel.mediaState {
                | Playing => " || "
                | Paused => " > "
                | NotLoaded => " > "
                }
              )
            )
          </span>
          <span
            onClick=(
                      fun _event =>
                        dispatchEL
                          State.(
                            SongSelected currentChannel (Utils.findNextMedia currentChannel 1)
                          )
                          ()
                    )>
            (text ">>")
          </span>
        </div>
        <div className="current">
          <div className="album">
            <img className="album-art" src="https://placehold.it/64" />
          </div>
          <div className="info">
            <div className="title"> (text (Utils.mediaSrcToTitle currentChannel.media)) </div>
            <div className="progress">
              <div className="elapsed">
                (
                  text {
                    let seconds =
                      int_of_float (float_of_int (currentChannel.mediaProgress mod 60));
                    string_of_int (currentChannel.mediaProgress / 60) ^
                    ":" ^ (seconds < 10 ? "0" : "") ^ string_of_int seconds
                  }
                )
              </div>
              <div className="timeline slider">
                <Progress_bar
                  progress=(Utils.channelMediaProgress currentChannel currentChannel.media)
                  cursor="ew-resize"
                  onChanged=(
                              fun offset => {
                                Js.log offset;
                                dispatchEL
                                  State.(
                                    MediaPlayerScrubbed currentChannel offset (Js.Date.now ())
                                  )
                                  ()
                              }
                            )
                />
                <div className="thumb" />
              </div>
              <div className="playtime">
                (
                  text (
                    switch currentChannel.media.duration {
                    | None => "Not Loaded"
                    | Some duration =>
                      let seconds = int_of_float (float_of_int (duration mod 60));
                      string_of_int (duration / 60) ^
                      ":" ^ (seconds < 10 ? "0" : "") ^ string_of_int seconds
                    }
                  )
                )
              </div>
            </div>
            <div className="artist"> (text "artist name (Probably can't get this)") </div>
          </div>
        </div>
        <div className="right controls">
          <div className="mute" onClick=(fun _ => dispatchEL VolumeMuteToggled ())>
            (text "<))")
          </div>
          <div className="volume slider">
            <Progress_bar
              cursor="ew-resize"
              progress=(state.volume *. 100.0)
              onChanged=(fun offset => dispatchEL State.(VolumeSet offset) ())
            />
            <div className="thumb" />
          </div>
        </div>
      </div>
    </div>
  };
};

include ReactRe.CreateComponent Wip;

let createElement ::message ::rootEl => wrapProps {message, rootEl};
