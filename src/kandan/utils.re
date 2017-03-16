external querySelector : string => Js.null ReasonJs.Dom.element =
  "" [@@bs.send.pipe : ReasonJs.Dom.element];

external querySelectorAll : string => array ReasonJs.Dom.element =
  "" [@@bs.send.pipe : ReasonJs.Dom.element];

external eventTargetAsHtmlElement : ReasonJs.Dom.eventTarget => ReasonJs.Dom.htmlElement =
  "%identity";

external domAsHtmlElement : ReasonJs.Dom.element => ReasonJs.Dom.htmlElement = "%identity";

external nodeAsHtmlElement : ReasonJs.Dom.node => ReasonJs.Dom.htmlElement = "%identity";

let querySelector: string => ReasonJs.Dom.element => option ReasonJs.Dom.element =
  fun selector self => Js.Null.to_opt (querySelector selector self);

external setAttribute : ReasonJs.Dom.element => string => string => unit =
  "setAttribute" [@@bs.send];

let findMeOpt (state: State.appState) =>
  switch state.userId {
  | None => None
  | Some id => Some (List.find (fun (user: State.user) => id === user.id) state.users)
  };

let nameOfUser user =>
  switch State.(user.name) {
  | None => State.(user.email)
  | Some name => name
  };

let md5 str => Digest.to_hex @@ Digest.string str;

let gravatarUrl ::size=30 ::default="identicon" email =>
  "http://gravatar.com/avatar/" ^ md5 email ^ "?s=" ^ string_of_int size ^ "&amp;d=" ^ default;

/* Units of time in seconds (approximate) */
let minute = 60.0;

let hour = minute *. 60.0;

let day = hour *. 24.0;

let month = day *. 30.0;

let year = month *. 12.0;

let timeAgo (time: float) :string => {
  let now = ReasonJs.Date.now ();
  let agoMs = now -. time;
  let ago = agoMs /. 1000.0;
  let (divisor, unit) =
    switch () {
    | _ when ago < minute => (minute, "minute")
    | _ when ago < hour => (hour, "hour")
    | _ when ago < day => (day, "day")
    | _ when ago < month => (month, "month")
    | _ => (year, "year")
    };
  let count = ago /. divisor;
  string_of_int (int_of_float count) ^ " " ^ unit ^ (count === 1.0 ? "" : "s")
};

let randomRgb () => (
  Int32.to_int (Random.int32 (Int32.of_int 255)),
  Int32.to_int (Random.int32 (Int32.of_int 255)),
  Int32.to_int (Random.int32 (Int32.of_int 255))
);

let randomRgbString () => {
  let (r, g, b) = randomRgb ();
  "rgb(" ^ string_of_int r ^ "," ^ string_of_int g ^ "," ^ string_of_int b ^ ")"
};

let setPageTitle title =>
  switch (ReasonJs.Dom.document |> ReasonJs.Document.asHtmlDocument) {
  | None => ()
  | Some doc => ReasonJs.HtmlDocument.setTitle doc title
  };
