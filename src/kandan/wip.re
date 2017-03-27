open ReactDOMRe.Style;

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

module Wip = {
  include ReactRe.Component.Stateful;
  type state = {leftMenuOpened: bool, rightMenuOpened: bool};
  let getInitialState _ => {leftMenuOpened: true, rightMenuOpened: true};
  let name = "Wip";
  type props = {message: string};
  let render {props, state, setState} =>
    <div className="container">
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
            <div className="menu-item"> (text "channel 1") </div>
            <div className="menu-item"> (text "channel 2") </div>
            <div className="menu-item"> (text "channel 3") </div>
            <div className="menu-item"> (text "channel 4") </div>
            <div className="menu-item"> (text "channel 5") </div>
          </div>
        </div>
        <div className="chat">
          <div className="chat-feed"> <div> (text "msg") </div> </div>
          <div className="chat-input">
            <input className="" _type="text" placeholder="chat msg" />
          </div>
        </div>
        <div className="menu right">
          <div className="menu-items songs">
            <div className="menu-item">
              <div className="menu-thumbnail">
                <img src="https://placehold.it/64" />
              </div>
              <div className="menu-text"> (text "song 1") </div>
            </div>
            <div className="menu-item">
              <div className="menu-thumbnail">
                <img src="https://placehold.it/64" />
              </div>
              <div className="menu-text"> (text "song 2") </div>
            </div>
            <div className="menu-item">
              <div className="menu-thumbnail">
                <img src="https://placehold.it/64" />
              </div>
              <div className="menu-text"> (text "song 3") </div>
            </div>
          </div>
        </div>
      </div>
      <div className="player">
        <div className="left controls">(text "<< > >>")</div>
        <div className="current">
          <div className="album">
            <img className="album-art" src="https://placehold.it/64" />
          </div>
          <div className="info">
            <div className="title">
              (text "the name of this song")
            </div>
            <div className="progress">
              <div className="elapsed">(text "0:41")</div>
              <div className="timeline slider">
                <div className="track">
                  <div className="spent" />
                </div>
                <div className="thumb" />
              </div>
              <div className="playtime">(text "2:35")</div>
            </div>
            <div className="artist">(text "artist name")</div>
          </div>
        </div>
        <div className="right controls">
        <div className="mute">
          (text "<))")
        </div>
        <div className="volume slider">
          <div className="track">
            <div className="spent" />
          </div>
          <div className="thumb" />
        </div>
        </div>
      </div>
    </div>;
};

include ReactRe.CreateComponent Wip;

let createElement message::_message => wrapProps {message: _message};
