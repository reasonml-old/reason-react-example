type messageContent =
  | String string
  | Elem ReactRe.reactElement;

type nextAction =
  | Terminate
  | Continue;

type toBeRendered = array messageContent;

let dummyEmbed
    _me
    _users
    _channel
    _message
    (activityPieces: toBeRendered)
    :(nextAction, toBeRendered) => (
  Continue,
  activityPieces
);

let pastieRe = [%bs.re "/\\n/"];

let pastie (message: State.message) => {
  let maxPreviewLength = 300;
  let maxPreviewLines = 4;
  switch (Local_string.matchRegex message.content [%bs.re "/\\n/"]) {
  | None => String message.content
  | Some _ =>
    let lines = Local_string.split message.content [%bs.re "/\\n/"];
    let previewTrimmedLines =
      if (Array.length lines > maxPreviewLines) {
        Local_string.join (Array.sub lines 0 maxPreviewLines) "\n"
      } else {
        Local_string.join lines "\n"
      };
    let finalPreview =
      if (String.length previewTrimmedLines > maxPreviewLength) {
        Local_string.sub previewTrimmedLines 0 maxPreviewLength
      } else {
        previewTrimmedLines
      };
    Elem <pre className="pastie">
           (ReactRe.stringToElement finalPreview)
           (
             if (message.content !== finalPreview) {
               ReactRe.stringToElement "..."
             } else {
               ReactRe.stringToElement ""
             }
           )
           <br />
           <a
             className="pastie-link"
             href="#"
             onClick=(fun _ => ())
             style=(ReactDOMRe.Style.make cursor::"pointer" ())>
             (ReactRe.stringToElement "View pastie")
           </a>
         </pre>
  }
};

let embedPastie
    _me
    _users
    _channel
    (message: State.message)
    (activityPieces: toBeRendered)
    :(nextAction, toBeRendered) =>
  switch (Local_string.matchRegex message.content [%bs.re "/\\n/"]) {
  | None => (Continue, activityPieces)
  | Some _ =>
    try (Terminate, [|pastie message|]) {
    | Not_found => (Continue, activityPieces)
    }
  };

let slashPlay = dummyEmbed;

let embedEmoticon
    _me
    _users
    _channel
    _message
    (activityPieces: toBeRendered)
    :(nextAction, toBeRendered) => (
  Continue,
  Array.map
    (
      fun piece =>
        switch piece {
        | Elem e => Elem e
        | String s =>
          try {
            let emoji: State.emoji = State.EmojiPairs.(find (String.trim s) Emojis.emojiMap);
            Elem <img className=("emoticon-embed " ^ emoji.css) src=emoji.src title=emoji.src />
          } {
          | Not_found => String s
          }
        }
    )
    activityPieces
);

let spaceRe = [%bs.re "/ /"];

let dummyElement = ReactRe.stringToElement "";

let reactSpaceEl = ReactRe.stringToElement " ";

let mentionRe = [%bs.re "/(.*)@(\\w+)(.*)/"];

let embedMention
    _me
    users
    _channel
    _message
    (activityPieces: toBeRendered)
    :(nextAction, toBeRendered) => (
  Continue,
  Array.map
    (
      fun piece =>
        switch piece {
        | Elem e => Elem e
        | String s =>
          switch (Local_string.matchRegex s mentionRe) {
          | None => String s
          | Some [||] => assert false
          | Some [|_, pre, username, post|] =>
            try {
              let _ = List.find (fun (user: State.user) => user.username == username) users;
              Elem <span>
                     (ReactRe.stringToElement pre)
                     <span className="mention"> (ReactRe.stringToElement username) </span>
                     (ReactRe.stringToElement " ")
                     (ReactRe.stringToElement post)
                   </span>
            } {
            | Not_found => String s
            }
          | Some _damn => assert false
          }
        }
    )
    activityPieces
);

let linkRe = [%bs.re "/https?:\\/\\/.*/"];

let embedLink
    _me
    _users
    _channel
    _message
    (activityPieces: toBeRendered)
    :(nextAction, toBeRendered) => (
  Continue,
  Array.map
    (
      fun piece =>
        switch piece {
        | Elem e => Elem e
        | String s =>
          switch (Local_string.matchRegex s linkRe) {
          | None => String s
          | Some [||] => assert false
          | Some [|link|] => Elem <a href=link target="_blank"> (ReactRe.stringToElement link) </a>
          | Some _damn => assert false
          }
        }
    )
    activityPieces
);

let rgbRe = [%bs.re "/(.*)rgb\\((\\d{1,3}),(\\d{1,3}),(\\d{1,3})\\)(.*)/"];

let embedRgb
    _me
    _users
    _channel
    _message
    (activityPieces: toBeRendered)
    :(nextAction, toBeRendered) => (
  Continue,
  Array.map
    (
      fun piece =>
        switch piece {
        | Elem e => Elem e
        | String s =>
          switch (Local_string.matchRegex s rgbRe) {
          | None => String s
          | Some [||] => assert false
          | Some [|_, _pre, r, g, b, _post|] =>
            Elem
              <span
                className="color-preview"
                title=("rgb(" ^ r ^ "," ^ g ^ "," ^ b ^ ")")
                style=(
                        ReactDOMRe.Style.make
                          borderRadius::"12px"
                          backgroundColor::("rgb(" ^ r ^ "," ^ g ^ "," ^ b ^ ")")
                          ()
                      )
              />
          | Some _damn => assert false
          }
        }
    )
    activityPieces
);

let hexRe = [%bs.re "/(.*)#([A-Fa-f0-9]{6}|[A-Fa-f0-9]{3})(.*)/"];

let embedHex
    _me
    _users
    _channel
    _message
    (activityPieces: toBeRendered)
    :(nextAction, toBeRendered) => (
  Continue,
  Array.map
    (
      fun piece =>
        switch piece {
        | Elem e => Elem e
        | String s =>
          switch (Local_string.matchRegex s hexRe) {
          | None => String s
          | Some [||] => assert false
          | Some [|_, _pre, hex, _post|] =>
            Elem
              <span
                className="color-preview"
                title=("#" ^ hex)
                style=(ReactDOMRe.Style.make borderRadius::"12px" backgroundColor::("#" ^ hex) ())
              />
          | Some _damn => assert false
          }
        }
    )
    activityPieces
);

let renderableOfActivityPieces (pieces: toBeRendered) =>
  Array.map
    (
      fun (piece: messageContent) => (
        switch piece {
        | Elem e => e
        | String s => ReactRe.stringToElement s
        }: ReactRe.reactElement
      )
    )
    pieces;

let processPlugins me users channel message messageContentPieces plugins =>
  List.fold_left
    (
      fun (earlyTerminate, messageContentPieces) f =>
        switch earlyTerminate {
        | Terminate => (Terminate, messageContentPieces)
        | Continue => f me users channel message messageContentPieces
        }
    )
    (Continue, messageContentPieces)
    plugins;

/* Only these plugins are allowed to follow a /me */
let mePlugins = [embedMention, embedEmoticon, embedLink, embedRgb, embedHex];

let meRe = [%bs.re "/^\\/me /"];

let embedMe
    (me: State.user)
    users
    channel
    (message: State.message)
    (activityPieces: toBeRendered)
    :(nextAction, toBeRendered) =>
  switch (Local_string.matchRegex message.content meRe) {
  | None => (Continue, activityPieces)
  | Some [||] => assert false
  | Some [|_|] =>
    let (_, pieces) = processPlugins me users channel message activityPieces mePlugins;
    let pieces = renderableOfActivityPieces pieces;
    pieces.(0) = <span> (ReactRe.stringToElement me.username) </span>;
    let final = Array.make (Array.length pieces * 2 - 1) dummyElement;
    Array.iteri
      (
        fun index item => {
          final.(index * 2) = item;
          if (index * 2 + 1 < Array.length final) {
            final.(index * 2 + 1) = reactSpaceEl
          }
        }
      )
      pieces;
    let elem = [|Elem <em> (ReactRe.arrayToElement final) </em>|];
    (Terminate, elem)
  | Some _damn => assert false
  };

let quotePlugins = [embedMention, embedEmoticon, embedLink, embedRgb, embedHex];

let quoteRe = [%bs.re "/^> /"];

let embedQuote
    (me: State.user)
    users
    channel
    (message: State.message)
    (activityPieces: toBeRendered)
    :(nextAction, toBeRendered) =>
  switch (Local_string.matchRegex message.content quoteRe) {
  | None => (Continue, activityPieces)
  | Some [||] => assert false
  | Some [|_|] =>
    let (_, pieces) = processPlugins me users channel message activityPieces quotePlugins;
    let pieces = renderableOfActivityPieces pieces;
    pieces.(0) =
      <div
        className="quote-color"
        style=(ReactDOMRe.Style.make backgroundColor::"rgb(131, 104, 214)" ())>
        (ReactRe.stringToElement "")
      </div>;
    let final = Array.make (Array.length pieces * 2 - 1) dummyElement;
    Array.iteri
      (
        fun index item => {
          final.(index * 2) = item;
          if (index * 2 + 1 < Array.length final) {
            final.(index * 2 + 1) = reactSpaceEl
          }
        }
      )
      pieces;
    let elem = [|Elem <div className="quote-wrapper"> (ReactRe.arrayToElement final) </div>|];
    (Terminate, elem)
  | Some _damn => assert false
  };

let allPlugins = [
  embedQuote,
  embedMe,
  embedPastie,
  embedMention,
  slashPlay,
  embedEmoticon,
  embedLink,
  embedRgb,
  embedHex
];

/* Not a perfect regex, bad extension recognition, but written offline */
let imageRe = [%bs.re "/(https?:\\/\\/[\\w|\\.\\/]+[jpg|jpeg|gif|png|svg]{3,4})/gi"];

let extractImages (message: State.message) :array ReactRe.reactElement =>
  switch (Local_string.matchRegex message.content imageRe) {
  | None => [||]
  | Some matches =>
    Array.map
      (
        fun src =>
          <div className="image-preview">
            <a target="_blank" href=src>
              <img
                style=(ReactDOMRe.Style.make maxWidth::"100%" maxHeight::"10%" ())
                title=src
                className="image-embed"
                src
              />
            </a>
            <div name=src />
          </div>
      )
      matches
  };

let youtubeTopRe = [%bs.re "/https?:\\/\\/www.youtube.com\\/watch.+v=([a-zA-Z0-9\\-]+)/"];

let extractYoutubes (message: State.message) :array ReactRe.reactElement =>
  switch (Local_string.matchRegex message.content youtubeTopRe) {
  | None => [||]
  | Some [|_, videoId|] => [|
      <div className="youtube-preview">
        <iframe
          width="560"
          height="315"
          src=("http://www.youtube.com/embed/" ^ videoId)
          /* allowFullScreen=Js.true_ */
        />
      </div>
    |]
  | Some _damn => assert false
  };

let extractMedia (message: State.message) => {
  let images = extractImages message;
  let youtubes = extractYoutubes message;
  Array.concat [images, youtubes]
};

let renderableOfMessage
    me
    users
    (channel: State.channel)
    (message: State.message)
    :(array ReactRe.reactElement, ReactRe.reactElement, int) => {
  let messageContentPieces =
    Local_string.split message.content spaceRe |> Array.map (fun piece => String piece);
  let (_, pieces) = processPlugins me users channel message messageContentPieces allPlugins;
  let pieces = renderableOfActivityPieces pieces;
  let final = Array.make (Array.length pieces * 2 - 1) dummyElement;
  Array.iteri
    (
      fun index item => {
        final.(index * 2) = item;
        if (index * 2 + 1 < Array.length final) {
          if (index * 2 + 1 < Array.length final) {
            final.(index * 2 + 1) = reactSpaceEl
          }
        }
      }
    )
    pieces;
  let media = extractMedia message;
  let mediaEl = <div className="media-section"> (ReactRe.arrayToElement media) </div>;
  (final, mediaEl, Array.length media)
};
