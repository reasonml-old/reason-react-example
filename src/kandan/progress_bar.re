external asHtmlElement : 'a => ReasonJs.Dom.HtmlElement.t_htmlElement = "%identity";

external asMouseEvent : 'a => ReactEventRe.Mouse.t = "%identity";

let kill event => {
  ReactEventRe.Synthetic.preventDefault event;
  ReactEventRe.Synthetic.stopPropagation event
};

module Progress_bar = {
  include ReactRe.Component.Stateful.InstanceVars;
  let name = "ProgressBar";
  type props = {
    progress: (float, float),
    onChanged: option (float => unit),
    cursor: option string,
    buffered: option (array (float, float))
  };
  type state = {listeners: option string, mouseDown: bool};
  type instanceVars = {mutable domRef: option Dom.element};
  let getInstanceVars () => {domRef: None};
  let getInitialState _props => {listeners: None, mouseDown: false};
  let mouseXAsPercentage el event :option float =>
    switch (el |> ReasonJs.Dom.Element.asHtmlElement) {
    | None => None
    | Some clickTarget =>
      let offsetX = ReasonJs.Dom.HtmlElement.offsetLeft clickTarget;
      let width = ReasonJs.Dom.HtmlElement.offsetWidth clickTarget;
      let pageX = ReactEventRe.Mouse.pageX event;
      Some (max 0.0 (min 1.0 (float_of_int (pageX - offsetX) /. float_of_int width)))
    };
  let handleMouseMoved {state, props, instanceVars} event =>
    switch instanceVars.domRef {
    | None => None
    | Some el =>
      state.mouseDown ?
        switch (props.onChanged, mouseXAsPercentage el event) {
        | (Some clickHandler, Some percent) =>
          kill event;
          clickHandler percent;
          None
        | _ => None
        } :
        None
    };
  let setTrackRef {instanceVars} el => instanceVars.domRef = Some el;
  let maybeDragged isDown {instanceVars, props, state} event =>
    switch instanceVars.domRef {
    | None => None
    | Some el =>
      switch (state.mouseDown, isDown, props.onChanged, mouseXAsPercentage el event) {
      | (false, true, Some clickHandler, Some percent) =>
        clickHandler percent;
        Some {...state, mouseDown: isDown}
      | (true, false, Some clickHandler, Some percent) =>
        clickHandler percent;
        Some {...state, mouseDown: isDown}
      | _ => None
      }
    };
  let componentDidMount {updater} => {
    ReasonJs.Dom.Document.addEventListener
      "mouseup"
      (fun event => updater (maybeDragged false) (asMouseEvent event))
      ReasonJs.Dom.document;
    ReasonJs.Dom.Document.addEventListener
      "mousemove"
      (fun event => updater handleMouseMoved (asMouseEvent event))
      ReasonJs.Dom.document;
    None
  };
  let render {props, updater, handler, state} => {
    let buffered = props.buffered;
    <div
      ref=(handler setTrackRef)
      className="track"
      onMouseUp=(fun event => state.mouseDown ? updater (maybeDragged false) event : ())
      onMouseDown=(
                    fun event => {
                      kill event;
                      updater (maybeDragged true) event
                    }
                  )
      style=(
              switch props.cursor {
              | None => ReactDOMRe.Style.make ()
              | Some cursor => ReactDOMRe.Style.make ::cursor ()
              }
            )>
      <div
        className="spent"
        style={
                let (progressStart, progressEnd) = props.progress;
                ReactDOMRe.Style.make
                  marginLeft::(string_of_float progressStart ^ "%")
                  width::(string_of_float progressEnd ^ "%")
                  ()
              }
      />
      (
        switch buffered {
        | None => ReactRe.nullElement
        | Some timeRanges =>
          timeRanges |>
          Array.map (
            fun timeRange => {
              let (progressStart, progressEnd) = timeRange;
              <div
                className="spent"
                key=(string_of_float progressStart)
                style=(
                        ReactDOMRe.Style.make
                          backgroundColor::"#717171"
                          marginLeft::(string_of_float progressStart ^ "%")
                          width::(string_of_float progressEnd ^ "%")
                          ()
                      )
              />
            }
          ) |> ReactRe.arrayToElement
        }
      )
    </div>
  };
};

include ReactRe.CreateComponent Progress_bar;

let createElement ::progress ::onChanged=? ::cursor=? ::buffered =>
  wrapProps {progress, onChanged, cursor, buffered};
