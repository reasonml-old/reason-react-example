open Constants;

type logoProps = {message: string};

include
  ReactRe.CreateComponent {

    /**
     * Include Stateful Component Base!
     */
    include ReactRe.Component.Stateful;
    type state = {degrees: float, velocity: float, drag: float, lastMs: float};
    type props = logoProps;
    let getInitialState _ /* props */ => {
      drag: mouseUpDrag,
      degrees: 0.0,
      velocity: 0.1,
      lastMs: Js.Date.now ()
    };
    let componentDidMount {setState} => {
      let rec onAnimationFrame () => {
        let stateSetter {state} => {
          let now = Js.Date.now ();
          /* How many 16ms virtual frames elapsed, even if clock runs at 30hz */
          let idealFramesSinceLast = 1. +. (now -. state.lastMs) /. 16.;
          let nextDegrees = state.degrees +. (baseVel +. state.velocity) *. idealFramesSinceLast;
          let nextVelocity = state.velocity *. state.drag;
          {...state, degrees: nextDegrees, velocity: nextVelocity, lastMs: now}
        };
        setState stateSetter;
        ReasonJs.requestAnimationFrame onAnimationFrame
      };
      ReasonJs.requestAnimationFrame onAnimationFrame;
      None
    };
    let name = "Logo";
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
    let handleMouseUp {state} _ /* event */ => {
      let withAccel = state.velocity +. clickAccel;
      let nextVelocity = withAccel < maxVel ? withAccel : maxVel;
      Some {...state, velocity: nextVelocity, drag: mouseUpDrag}
    };

    /**
     * On Mouse Down.
     */
    let handleMouseDown {state} _ /* event */ => Some {...state, drag: mouseDownDrag};
    let render {props, state, updater} => {
      let transform = Printf.sprintf "rotate(%fdeg)" state.degrees;
      /* To create JS Objects in Reason, */
      let rotationStyle = {"transformOrigin": "50% 50%", "transform": transform};
      <div
        style={
                "color": "#444444",
                "WebkitUserSelect": "none",
                "paddingTop": "40px",
                "fontSize": "68px",
                "fontFamily": "Montserrat",
                "textAlign": "center"
              }>
        (ReactRe.stringToElement props.message)
        <svg
          width="100%"
          height="100%"
          viewBox="0 0 700 700"
          version="1.1"
          style={"cursor": "pointer"}
          onMouseUp=(updater handleMouseUp)
          onMouseDown=(updater handleMouseDown)>
          (renderGraphic rotationStyle)
        </svg>
      </div>
    };
  };

let createElement ::message => wrapProps {message: message};
