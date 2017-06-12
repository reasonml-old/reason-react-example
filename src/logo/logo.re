external requestAnimationFrame : (unit => unit) => unit = "" [@@bs.val];

open Constants;

type state = {
  degrees: float,
  velocity: float,
  drag: float,
  lastMs: float
};

let renderGraphic rotationStyle =>
  <g fill="none" stroke="none">
    <g transform="scale(1.5, 1.5) translate(100.000000, 105.000000)">
      <path fill="rgba(0,0,0,0.1)" d=border_path />
      <path fill="#dd4b39" d=bg_path />
      <g transform="translate(55, 29)">
        <g style=rotationStyle>
          <path fill="#FFFFFF" d=center_dot_path />
          <g stroke="#FFFFFF" strokeWidth="8">
            <path d=ring_one_path />
            <path d=ring_two_path transform=ring_two_rotate />
            <path d=ring_three_path transform=ring_three_rotate />
          </g>
        </g>
      </g>
    </g>
  </g>;


/**
 * On Mouse Up.
 */
let handleMouseUp _event state _self => {
  let withAccel = state.velocity +. clickAccel;
  let nextVelocity = withAccel < maxVel ? withAccel : maxVel;
  ReasonReact.Update {...state, velocity: nextVelocity, drag: mouseUpDrag}
};


/**
 * On Mouse Down.
 */
let handleMouseDown _event state _self => ReasonReact.Update {...state, drag: mouseDownDrag};

let component = ReasonReact.statefulComponent "LogoRe";

let make ::message _children => {
  ...component,
  initialState: fun () => {drag: mouseUpDrag, degrees: 0.0, velocity: 0.1, lastMs: Js.Date.now ()},
  didMount: fun _state self => {
    let rec onAnimationFrame () => {
      let stateSetter () state _self => {
        let now = Js.Date.now ();
        /* How many 16ms virtual frames elapsed, even if clock runs at 30hz */
        let idealFramesSinceLast = 1. +. (now -. state.lastMs) /. 16.;
        let nextDegrees = state.degrees +. (baseVel +. state.velocity) *. idealFramesSinceLast;
        let nextVelocity = state.velocity *. state.drag;
        ReasonReact.Update {...state, degrees: nextDegrees, velocity: nextVelocity, lastMs: now}
      };
      self.update stateSetter ();
      requestAnimationFrame onAnimationFrame
    };
    requestAnimationFrame onAnimationFrame;
    ReasonReact.NoUpdate
  },
  render: fun state self => {
    let transform = "rotate(" ^ string_of_float state.degrees ^ "deg)";
    /* To create JS Objects in Reason, */
    let rotationStyle = ReactDOMRe.Style.make transformOrigin::"50% 50%" ::transform ();
    <div
      style=(
        ReactDOMRe.Style.make
          color::"#444444"
          userSelect::"none"
          paddingTop::"40px"
          fontSize::"68px"
          fontFamily::"Montserrat"
          textAlign::"center"
          ()
      )>
      (ReasonReact.stringToElement message)
      <svg
        width="100%"
        height="100%"
        viewBox="0 0 700 700"
        version="1.1"
        style=(ReactDOMRe.Style.make cursor::"pointer" ())
        onMouseUp=(self.update handleMouseUp)
        onMouseDown=(self.update handleMouseDown)>
        (renderGraphic rotationStyle)
      </svg>
    </div>
  }
};
