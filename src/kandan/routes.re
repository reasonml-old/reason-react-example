external encodeUri : string => string = "encodeURI" [@@bs.val];

external decodeUri : string => string = "decodeURI" [@@bs.val];

module HashChange = {
  type t = Js.t {. newURL : string, oldURL : string};
  external ofEvent : Dom.event => t = "%identity";
  external newUrl : t => string = "newURL" [@@bs.get];
  external oldUrl : t => string = "oldURL" [@@bs.get];
};

let stateToPath appState => {
  let currentChannel =
    State.(
      List.find (fun haystack => haystack.id === appState.selectedChannelId) appState.channels
    );
  encodeUri currentChannel.title
};

let pagePath window => {
  let location = ReasonJs.Dom.Window.location window;
  let path = decodeUri (ReasonJs.Dom.Location.hash location);
  Local_string.sub path 1 (String.length path)
};

let hashOfUri (uri: string) :string => {
  let interim = Local_string.split uri [%bs.re "/#/"];
  let last = Array.sub interim 1 (Array.length interim - 1);
  Local_string.join last "#"
};

module Routes = {
  include ReactRe.Component;
  type props = {
    path: string,
    isHistorical: bool,
    onHashChange: string => string => string => unit
  };
  let name = "Routes";
  let componentDidUpdate ::prevProps prevState::_ {props} => {
    if (prevProps.path != props.path) {
      Utils.setHash props.path
    };
    None
  };
  let render _ => <span />;
  let componentDidMount {handler} => {
    ReasonJs.Dom.Window.addEventListener
      "hashchange"
      (
        fun rawEvent => {
          let event = HashChange.ofEvent rawEvent;
          handler
            (
              fun latestComponentBag _ =>
                latestComponentBag.props.onHashChange
                  latestComponentBag.props.path (HashChange.oldUrl event) (HashChange.newUrl event)
            )
            ()
        }
      )
      ReasonJs.Dom.window;
    None
  };
};

include ReactRe.CreateComponent Routes;

let createElement ::path ::isHistorical ::onHashChange =>
  wrapProps {path, isHistorical, onHashChange};
