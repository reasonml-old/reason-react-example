/**
 Example usage:

    /* Mapping of keystroke(+modifiers) to handler (taking unit) */
   let keyMap = [
     (["ctrl+esc"], fun _ => Js.log "ctrl esc yo!"),
     (
       ["up", "up", "down", "down", "left", "right", "left", "right", "a", "b"],
       fun _ => ReasonJs.Window.alert "Konami code!"
     ),
     (["ctrl+/"], fun _ => ReasonJs.Window.alert "Wow!"),
     (["ctrl+shift+esc"], fun _ => ReasonJs.Window.alert "ctrl shift esc yo!")
   ];

   /* This component will add an event listener to window for
   "keydown". In this case, any key chord will have to be
   pressed within 2 seconds, but you can get no timeout via None. */

   <Key_queue keyMap timeout=(Some 2000) />

 */
external charCodeAt : string => int => int = "charCodeAt" [@@bs.send];

type modifiers =
  | Shift
  | Alt
  | Ctrl
  | Meta;

type namedKey =
  | Enter
  | Esc
  | Left
  | Up
  | Right
  | Down
  | Del
  | Semicolon
  | Slash
  | Plus
  | BracketLeft
  | BracketRight;

type keyCode =
  | Special namedKey
  | Literal string;

let codeOfKey (event: ReasonJs.Dom.keyboardEvent) =>
  switch (ReasonJs.Dom.KeyboardEvent.key event) {
  | "Enter" => Special Enter
  | "Escape" => Special Esc
  | "ArrowLeft" => Special Left
  | "ArrowUp" => Special Up
  | "ArrowRight" => Special Right
  | "ArrowDown" => Special Down
  | "Delete" => Special Del
  | "BracketLeft" => Special BracketLeft
  | "BracketRigth" => Special BracketRight
  | ";" => Special Semicolon
  | "/" => Special Slash
  | code => Literal code
  };

type keyStroke = {code: keyCode, shift: bool, alt: bool, ctrl: bool, meta: bool};

let stroke ::shift=false ::alt=false ::ctrl=false ::meta=false code => {
  code,
  shift,
  alt,
  ctrl,
  meta
};

let parseStroke keyStroke => {
  let rec helper ::shift=false ::alt=false ::ctrl=false ::meta=false ::code=None tokens =>
    switch tokens {
    | [] =>
      switch code {
      | None => raise (Failure ("No code provided for key stroke: " ^ keyStroke))
      | Some code => stroke ::shift ::alt ::ctrl ::meta code
      }
    | [token, ...xs] =>
      switch token {
      | "shift" => helper shift::true ::alt ::ctrl ::meta ::code xs
      | "alt" => helper ::shift alt::true ::ctrl ::meta ::code xs
      | "ctrl" => helper ::shift ::alt ctrl::true ::meta ::code xs
      | "meta" => helper ::shift ::alt ::ctrl meta::true ::code xs
      | "esc" => helper ::shift ::alt ::ctrl ::meta code::(Some (Special Esc)) xs
      | "up" => helper ::shift ::alt ::ctrl ::meta code::(Some (Special Up)) xs
      | "down" => helper ::shift ::alt ::ctrl ::meta code::(Some (Special Down)) xs
      | "left" => helper ::shift ::alt ::ctrl ::meta code::(Some (Special Left)) xs
      | "right" => helper ::shift ::alt ::ctrl ::meta code::(Some (Special Right)) xs
      | "/" => helper ::shift ::alt ::ctrl ::meta code::(Some (Special Slash)) xs
      | "plus" => helper ::shift ::alt ::ctrl ::meta code::(Some (Special Plus)) xs
      | "{" => helper ::shift ::alt ::ctrl ::meta code::(Some (Special BracketLeft)) xs
      | "}" => helper ::shift ::alt ::ctrl ::meta code::(Some (Special BracketRight)) xs
      | str when String.length str == 1 =>
        helper ::shift ::alt ::ctrl ::meta code::(Some (Literal str)) xs
      | str =>
        raise (
          Failure (
            "Invalid keymap character length, non-modifiers should be one char long, is: " ^ str
          )
        )
      }
    };
  let tokens = Local_string.split keyStroke [%bs.re "/\\+/"];
  helper (Array.to_list tokens)
};

let parseStrokes keyStrokes => List.map parseStroke keyStrokes;

let stringOfStroke stroke =>
  (stroke.ctrl ? "ctrl+" : "") ^
  (stroke.alt ? "alt+" : "") ^
  (stroke.meta ? "meta+" : "") ^
  (stroke.shift ? "shift+" : "") ^ (
    switch stroke.code {
    | Special Up => "up"
    | Special Down => "down"
    | Special Left => "left"
    | Special Right => "right"
    | Special Enter => "enter"
    | Special Esc => "esc"
    | Special Del => "del"
    | Special Semicolon => "semicolon"
    | Special Slash => "slash"
    | Special Plus => "plus"
    | Special BracketLeft => "{"
    | Special BracketRight => "}"
    | Literal code => code
    }
  );

let rec headMatches haystack needle matches =>
  switch (haystack, needle) {
  | ([], _) => matches
  | (_, []) => false
  | ([hx, ...hxs], [nx, ...nxs]) => hx == nx ? headMatches hxs nxs true : false
  };

let matchKeySequence keyMap (strokes: list keyStroke) => {
  let matches =
    List.filter
      (fun (targetStrokes, _) => headMatches (List.rev targetStrokes) strokes false) keyMap;
  List.map (fun (_, action) => action) matches
};

let nativeModifiers (event: ReasonJs.Dom.keyboardEvent) =>
  ReasonJs.Dom.KeyboardEvent.{
    code: codeOfKey event,
    shift: shiftKey event,
    alt: altKey event,
    ctrl: ctrlKey event,
    meta: metaKey event
  };

external asKeyboardEvent : ReasonJs.Dom.event => ReasonJs.Dom.keyboardEvent = "%identity";

external asHtmlElement : ReasonJs.Dom.eventTarget => ReasonJs.Dom.htmlElement = "%identity";

/* TODO: Should each key-seq get its own copy of the window
   key-strokes, so they can be individually cleared rather than all at
   once? */
module Key_queue = {
  include ReactRe.Component.Stateful;
  let name = "KeyQueue";
  type props = {
    keyMap: list (list string, State.action),
    onMatch: State.action => unit => unit,
    timeout: option int,
    filter: option (ReasonJs.Dom.keyboardEvent => keyStroke => bool)
  };
  type state = {
    counter: int,
    processedKeyMap: list (list keyStroke, State.action),
    keyPresses: list (keyStroke, int),
    keyListener: option (ReasonJs.Dom.event => unit)
  };
  let propsToKeyMap someProps => {
    let keyMap = someProps.keyMap;
    {
      counter: 0,
      processedKeyMap: List.map (fun (keyStr, action) => (parseStrokes keyStr, action)) keyMap,
      keyPresses: [],
      keyListener: None
    }
  };
  let getInitialState props => propsToKeyMap props;
  let stateSetter newStroke {props, state} => {
    let now = int_of_float (ReasonJs.Date.now ());
    let strokes =
      switch props.timeout {
      | None => [(newStroke, now), ...state.keyPresses]
      | Some timeout => [
          (newStroke, now),
          ...List.filter (fun (_, time) => now - time < timeout) state.keyPresses
        ]
      };
    let matches =
      matchKeySequence state.processedKeyMap (List.map (fun (stroke, _) => stroke) strokes);
    /* Dispatch matches */
    List.iter (fun action => props.onMatch action ()) matches;
    let matchOccurred = 0 < List.length matches;
    {...state, keyPresses: matchOccurred ? [] : strokes, counter: state.counter + 1}
  };
  let keyLogger props setState (rawEvent: ReasonJs.Dom.event) => {
    let event = asKeyboardEvent rawEvent;
    switch props.filter {
    | None =>
      if (not (ReasonJs.Dom.KeyboardEvent.repeat event)) {
        let target = ReasonJs.Dom.KeyboardEvent.target event;
        let type_ = ReasonJs.Dom.HtmlElement.tagName (asHtmlElement target);
        let isInputEl =
          switch (Local_string.lowerCase type_) {
          | "text"
          | "textarea"
          | "input" => true
          | _ => false
          };
        if (not isInputEl) {
          let stroke = nativeModifiers event;
          setState (stateSetter stroke)
        }
      }
    | Some predicate =>
      let stroke = nativeModifiers event;
      predicate event stroke ? setState (stateSetter stroke) : ()
    }
  };
  let componentDidMount {state, props, setState} => {
    let keyListener = keyLogger props setState;
    ReasonJs.Dom.Window.addEventListener "keydown" keyListener ReasonJs.Dom.window;
    Some {...state, keyListener: Some keyListener}
  };
  let componentWillUnmount {state} =>
    switch state.keyListener {
    | None => ()
    | Some listener =>
      ReasonJs.Dom.Window.removeEventListener "keydown" listener ReasonJs.Dom.window
    };
  let componentWillReceiveProps {props} ::nextProps =>
    props.keyMap == nextProps.keyMap ? None : Some (propsToKeyMap nextProps);
  let render _ => <div className="key_queue" />;
};

include ReactRe.CreateComponent Key_queue;

let createElement ::keyMap ::onMatch ::timeout=? ::filter=? =>
  wrapProps {keyMap, timeout, onMatch, filter};
