let lobbyPlaylist =
  State.[
    {
      src:
        Some "https://dl.dropboxusercontent.com/u/412963/music/%E4%BA%B2%E7%88%B1%E7%9A%84%E4%BD%A0%E6%80%8E%E4%B9%88%E4%B8%8D%E5%9C%A8%E6%88%91%E8%BA%AB%E8%BE%B9.m4a",
      order: 0,
      duration: None,
      buffered: None,
      seekable: None
    },
    {
      src:
        Some "https://dl.dropboxusercontent.com/u/412963/music/%E5%A5%BD%E5%BF%83%E5%88%86%E6%89%8B%20Candy%20Lo%20feat.%20%E7%8E%8B%E5%8A%9B%E5%AE%8F.mp3",
      order: 1,
      duration: None,
      buffered: None,
      seekable: None
    },
    {
      src: Some "https://dl.dropboxusercontent.com/u/412963/music/Why%20This%20Kolaveri%20Di.mp3",
      order: 2,
      duration: None,
      buffered: None,
      seekable: None
    },
    {
      src:
        Some "https://dl.dropboxusercontent.com/u/412963/music/%E4%BA%B2%E7%88%B1%E7%9A%84%20%EF%BC%8D%20%E5%BE%90%E8%8B%A5%E7%91%84.mp3",
      order: 3,
      duration: None,
      buffered: None,
      seekable: None
    },
    {
      src:
        Some "https://dl.dropboxusercontent.com/u/412963/music/Money%20Trees%20-%20Kendrick%20Lamar.mp3",
      order: 4,
      duration: None,
      buffered: None,
      seekable: None
    },
    {
      src:
        Some "https://dl.dropboxusercontent.com/u/412963/music/Armin%20van%20Buuren%20feat.%20Trevor%20Guthrie%20-%20This%20Is%20What%20It%20Feels%20Like.mp3",
      order: 5,
      duration: None,
      buffered: None,
      seekable: None
    },
    {
      src: Some "https://dl.dropboxusercontent.com/u/412963/music/05_Last_Train_To_New_Jersey.mp3",
      order: 6,
      duration: None,
      buffered: None,
      seekable: None
    }
  ];

let state =
  State.{
    title: "Kandan",
    debug: {botTalkEnabled: false},
    volume: 0.75,
    lastVolume: 0.75,
    State.userId: Some 1,
    userMessageFocused: false,
    searchFormFocused: false,
    userMenuOpen: false,
    rightSidebarOpen: false,
    leftSidebarOpen: false,
    selectedChannelId: 2,
    users: [
      {id: 1, email: "sean@bushi.do", name: Some "Sean Grove", status: Online, username: "sgrove"},
      {
        id: 2,
        email: "info@sachagreif.com",
        name: Some "Sacha Greif",
        status: Away,
        username: "sg"
      },
      {id: 3, email: "sbensu@gmail.com", name: None, status: Offline, username: "sbensu"},
      {
        id: 4,
        email: "dwwoelfel@gmail.com",
        name: Some "Daniel Woelfel",
        status: Online,
        username: "dww"
      },
      {
        id: 5,
        email: "danny.newidea@gmail.com",
        name: Some "Danny King",
        status: Online,
        username: "dannykingme"
      },
      {id: 6, email: "oh@zaiste.net", name: Some "Zaiste _", status: Online, username: "zaiste"}
    ],
    channels: [
      {
        id: 0,
        title: "Classical",
        loading: false,
        userIds:
          State.UserIdSet.empty |> State.UserIdSet.add 1 |> State.UserIdSet.add 2 |>
          State.UserIdSet.add 6,
        activities: [
          {userId: 3, content: "Move along", createdAt: 0.},
          {userId: 1, content: "Nothing to see here, eh?", createdAt: 1.},
          {
            userId: 1,
            content: "When are we going to get a more interesting lobby?",
            createdAt: 2.
          },
          {userId: 3, content: "Sir, move along", createdAt: 3.},
          {
            userId: 3,
            content: "This message contains the phrase \"search\" as the seventh to last word.",
            createdAt: 3.
          },
          {userId: 3, content: "Sir, move along", createdAt: 3.}
        ],
        media: {src: None, order: 0, duration: None, buffered: None, seekable: None},
        mediaState: Paused,
        mediaRepeat: All,
        mediaProgress: 0,
        mediaLoadProgress: None,
        mediaScrubbedTo: None,
        playlist: [
          {
            src:
              Some "http://www.mfiles.co.uk/mp3-downloads/frederic-chopin-piano-sonata-2-op35-3-funeral-march.mp3",
            order: 0,
            duration: None,
            buffered: None,
            seekable: None
          },
          {
            src:
              Some "http://www.mfiles.co.uk/mp3-downloads/Dvorak-Symphony9-2-from-the-New-World.mp3",
            order: 1,
            duration: None,
            buffered: None,
            seekable: None
          },
          {
            src: Some "http://www.mfiles.co.uk/mp3-downloads/moonlight-movement1.mp3",
            order: 2,
            duration: None,
            buffered: None,
            seekable: None
          },
          {
            src:
              Some "http://www.mfiles.co.uk/mp3-downloads/beethoven-piano-sonata-pathetique-2.mp3",
            order: 3,
            duration: None,
            buffered: None,
            seekable: None
          }
        ]
      },
      {
        id: 1,
        title: "Trance",
        loading: false,
        activities: [
          {userId: 2, content: "Not enough progressive trance in here, really...", createdAt: 0.}
        ],
        userIds:
          State.UserIdSet.empty |> State.UserIdSet.add 1 |> State.UserIdSet.add 2 |>
          State.UserIdSet.add 6,
        media: {src: None, order: 0, duration: None, buffered: None, seekable: None},
        mediaProgress: 0,
        mediaLoadProgress: None,
        mediaRepeat: All,
        mediaScrubbedTo: None,
        mediaState: Paused,
        playlist: [
          {
            src:
              Some "https://dl.dropboxusercontent.com/u/412963/music/Gareth%20Emery%20feat.%20Christina%20Novelli%20-%20Concrete%20Angel.mp3",
            order: 0,
            duration: None,
            buffered: None,
            seekable: None
          }
        ]
      },
      {
        id: 2,
        title: "Lobby",
        loading: false,
        userIds:
          State.UserIdSet.empty |> State.UserIdSet.add 1 |> State.UserIdSet.add 2 |>
          State.UserIdSet.add 3 |>
          State.UserIdSet.add 4 |>
          State.UserIdSet.add 6,
        activities: [
          {
            userId: 2,
            content: "> The ReasonCup logo http://reasoncup.com/resources/public/img/ReasonCup2016.png",
            createdAt: 1.
          },
          {userId: 5, content: "this is the last", createdAt: 99.},
          {
            userId: 5,
            content: "/me agrees with the previous message :+1: rgb(150,0,0) #000 #ff00ff",
            createdAt: 5.
          },
          {
            userId: 1,
            content: {|Paaassstttiiieee!!!

          Nice!
          ...right? |},
            createdAt: 4.
          },
          {
            userId: 1,
            content: "this is https://pbs.twimg.com/profile_images/766692876105289729/NZ16ZsLq_normal.jpg third",
            createdAt: 2.
          },
          {userId: 4, content: "this is second to last rgb(111,222,000)", createdAt: 3.},
          {userId: 4, content: "Reason will prevail!", createdAt: 9.},
          {userId: 4, content: "Right, @sgrove?", createdAt: 10.},
          {userId: 3, content: "If you can see this, SEARCH WORKS~~~!", createdAt: 100.}
        ],
        media: List.nth lobbyPlaylist 4,
        mediaProgress: 0,
        mediaRepeat: All,
        mediaLoadProgress: None,
        mediaScrubbedTo: None,
        mediaState: Paused,
        playlist: lobbyPlaylist
      }
    ],
    search: None
  };

/* Random activity generation */
let messageBodies = [|
  "<mention!> <mention!> This has been pretty darn helpful to understand how it works https://gist.github.com/domenic/ec8b0fc8ab45f39403dd",
  "<mention!> Thanks!!",
  "<mention!> Are you interested in collaborating on this?",
  "I am. I sent you a DM.",
  "<mention!> I'm also updating Reason cli  to latest tonight.",
  "But prebuilt binaries are in the works too",
  "<mention!> I really like that approach",
  "Opam is a good source of truth for this level of stuff and if we get reliable binary distribution then it can be installed instantly from npm",
  "I'm struggling a bit with types. Given a simple module:\n\nlet createElement collapse::(collapse: bool) children::_ () => <div />;\n\n\nHow could it be used as the type of a list? e.g., items: list Foo.t or something similar.(edited)",
  "<mention!> for rendering?",
  "https://github.com/reasonml/reason-react/blob/master/documentation.md#working-with-children",
  "I'm currying the module Foo.createElement causing list ReactRe.reactElement to error on the type since it's a function. items: list 'a works, but feels too permissive and incorrect.(edited)",
  "mmmm... tough one, but IIRC the typing of createElement is not quite static yet",
  "createElement is just a function. I'm struggling with how to  type a module for use as a list type.(edited)",
  "Passing partially applied functions as children doesn't really work right now. I'd recommend using a dedicated prop for that.",
  "No sure i follow on typing a module as a list type",
  "I am using a dedicated prop. items::(items: list <PartiallyAppliedFunctionType>) is what I'm trying to accomplish. Maybe I'm doing something wrong.(edited)",
  "how can i type an external that returns an object with a method? basically, I want to avoid this: \nlet x = (create tree) ## toJSON;\n create is a function that returns an obj with toJSON method on it",
  "<mention!> Idiomatically, you should type the object as an abstract type, then define an external toJSON that operates on that type(edited)",
  "type t;\nexternal create : tree => t = \"\" [@@bs.val];\nexternal toJSON : t => Js.Json.t = \"\" [@@bs.send];\nlet x = create tree |> toJSON\n(edited)",
  "dang, that works so good.",
  "thanks for your help, again, @glennsl",
  "np ",
  "<mention!> should be able to type as a list of the function calls that you are expecting to be passed. myProps => children::list ReactRe.element => etc =>  ReactRe.element cc <mention!> in case im missing a simpler solution(edited)",
  "I was hoping to use a type. If the signature changed, I would rather change in a single file versus two.",
  "You could write a type like:\n\ntype finalReactElementApplication = children::list ReactRe.element => ref::(ReactRe.reactRef => unit)? => key::string? => unit => ReactRe.element\n(edited)",
  "and then type in your components items::(items: list (myProps => finalReactElementApplication))(edited)",
  "maybe with a better name tho.",
  "<mention!> I appreciate the help. Below is some code that hopefully illustrates when I'm trying to accomplish.\n/*\n * navItem.re\n */\ntype t =\n  collapse::bool =>\n  children::ReactRe.reactElement =>\n  unit =>\n  ReactRe.reactElement;\n\nlet createElement collapse::(collapse: bool) ::children () =>\n  <div>\n    (collapse ? ReactRe.nullElement : ReactRe.stringToElement children)\n  </div>;\n\n/*\n * nav.re\n */\nlet createElement items::(items: list NavItem.t) children::_ () =>\n  <div>\n    (\n      items |> List.map (fun item => item collapse::false ()) |> ReactRe.listToElement\n    )\n  </div>;\n\nError: This expression has type (collapse:bool -> unit -> 'a) list -> 'a list\n  but an expression was expected of type NavItem.t list -> 'b\n  Type collapse:bool -> unit -> 'a is not compatible with type\n    NavItem.t =\n      collapse:bool ->\n      children:ReactRe.reactElement -> unit -> ReactRe.reactElement\n    Type unit -> 'a is not compatible with type\n      children:ReactRe.reactElement -> unit -> ReactRe.reactElement\n",
  "<mention!> \n\nmodule NavItem = {\n  type t = collapse::bool => children::list ReactRe.reactElement => unit => ReactRe.reactElement;\n  let createElement collapse::(collapse: bool) ::children () =>\n    <div> (collapse ? ReactRe.nullElement : children) </div>;\n};\n\nlet createElement items::(items: list NavItem.t) children::_ () =>\n  <div>\n    (items |> List.map (fun item => item collapse::false children::[] ()) |> ReactRe.listToElement)\n  </div>;\n",
  "There were a couple type issues around children being a required param. the way i narrowed it down was to add type params to the map function forcing it to take a NavItem.t and return a ReactRe.reactElement. That pointed out more specific errors.",
  "NavItem.createElement curries children in a parent component. The items list contains a partial of NavItem. Maybe that's where I'm getting stuck.",
  "<mention!> instead of children, try just another random prop name",
  "<mention!> not as pretty ",
  "<mention!> Omg",
  "Is there a work around in reason-react for existing JS libs that take components as props. I ask because react-router takes a component prop for routing, but in reason I recall seeing that we can't pass them that prop because it's a module(edited)",
  "<mention!> MyCompnent.comp",
  "Thats all we have to do in reason land?",
  "Yep, should be all the magic you need",
  "Awesome",
  "<mention!> if you wanna port the idiom over: fun () => <Foo />",
  "don't forget that first-class function exists!",
  "Hrm, I have some problem with stale state, sadly",
  "I add event listeners to an audio tag, but the problem is when the events fire, the app state has moved on. So the update function is passing in an old version of app state. Not sure how to get around this...",
  "<mention!> That shouldn't happen. Code?",
  "Btw setState escape hatch will give you the newest bag",
  "Usage https://github.com/sgrove/reason-react-example/blob/kandan-danny/src/kandan/wip.re#L644 - adding the listener https://github.com/sgrove/reason-react-example/blob/kandan-danny/src/kandan/audio_player.re#L151",
  "<mention!> Hrm, I don't know if I can really use that here",
  "<mention!> setState is safe",
  "asks for a cb",
  "Figuring out a basic routing solution right now, will check on the stale state problem afterwards",
  "<mention!> \": Btw setState escape hatch will give you the newest bag\"\nAre you sure about that - it should and we need it to, but I believe that React doesn't currently support that ability.",
  "Or rather, it doesn't support the ability to not update if you don't want to, based on that freshest bag.",
  "It won't respect our return value. (Actually - fiber will IIRC, but classic React won't)",
  "(We could/should fix that)",
  "it does give you the newest bag though",
  "<mention!> I guess you also discussed with sebastian on what the return of updater should be? Fiber's setState \"rebasing\" would break our current updater return logic(edited)",
  "I recall we're more compatible with Fiber, and less compatible with stack.",
  "Do you have a particular conversation you're recalling?",
  "<mention!> ^",
  "so the conversation we were talking about is about where handleClick happens in fiber:\n\nlet handleClick {state} => {\n  logSomeEvent \"click\";\n  Some {...state, clicks: state.clicks + 1}\n};\n\nlet render {state} => <div onClick=(updater handleClick)> (state.clicks) </div>;\n\n\nRight now, it happens in the event callback as expected, but that means that the return value is based on possibly stale state.\n\nIn order to make this handle correcly, you actually want it in the \"reducer callback\" version of setstate so it has access to fresh props/state. but then updater cbs need to (should) be pure functions. in fiber they may need to call setstate more than once if different priority work shifts the queue. this means that if moved, that log side effect would potentially get called more than once.",
  "sebastian was advocating for updater callbacks to be pure by convention and to return a tuple of state and a side effectual callback to be made later (or some variant that allows for both of those to be returned). one issue there is that event-specific side effects like preventdefault become impossible because the function doesnt get run until the event has already propogated.",
  "\"sebastian was advocating for updater callbacks to be pure by convention and to return a tuple of state and a side effectual callback to be made later (\"\nAbsolutely. I would do this even if Fiber didn't exist.",
  "<mention!> I think the problem is that I pass updater to a event listener on the document, outside of React's world. Does that updater fn have access to the latest state later on when the event happens, even if lots of other events have happened in the interim?",
  "But the reason we can't use the callback version of setState, is only because React itself doesn't provide us a way to say \"Oh actually I don't want to set any state\" in the callback version. I tried to use it and found that React doesn't respect it. We are very much in alignment with the callback version - React just has one issue there.(edited)",
  "<mention!> setState does",
  "Hrm...",
  "I believe returning null or undefined says \"oh actually i don't want to set any state\"",
  "<mention!> It doesn't - only in Fiber.",
  "They might have backported that feature to Stack version of React.",
  "ahhh. do we need to work well with stack?",
  "Yes, I think so.",
  "or we should get this feature backported.",
  "the tuple return type is awkward, but manageable.",
  "<mention!> We can make a custom return type.",
  "Instead of None/Some",
  "| NoUpdate\n| UpdateState 's\n| UpdateStateAndMutate 's (list (unit => unit))\n(edited)",
  "and i think you can get around the prevent default with handler:\n\nlet incrementClicks {state} => UpdateWithSideEffects {...state, clicks: state.clicks + 1} (fun _ => logSomeEvent \"click\");\nlet handleClick {state, updater} e => {\n  preventDefault e;\n  updater incrementClicks ();\n};\n\nlet render {state} => <div onClick=(handler handleClick)> (state.clicks) </div>;\n",
  "yeah yeah ^^ that ",
  "<mention!> I recall we needed to go with the callback approach to avoid hacking the impl bc of staleness?",
  "side effect functions probably need to be passed up-to-date componentBag, not just unit.",
  "yeah. so many opportunities to read stale state.",
  "<mention!> setState has the same problem.",
  "<mention!> really? It's a callback that reads the newest state?",
  "I'm certain this is an opportunity for us to provide a Fiber-centric API that plays well with the language and culture of immutability.",
  "<mention!> https://github.com/reasonml/reason-react/blob/6821f2e794d635ed32d58d6db46fce16692667e8/src/reactRe.re#L401",
  "<mention!> We should just really get this backported ASAP, because we want to change the bindings so that everything is using the callback form by default. I would hate to update the bindings, and then have a bunch of stuff break that was relying on subtle event ordering or stale state.",
  "<mention!> My bad, it's too late for me to be coding, I was still calling updater",
  "<mention!> Ah, I think it's that I closed over some state somewhere. Works now, but wonder if I can get away without setState. Will look at it tomorrow.",
  "lol i was curious so i thought id try and poke around the react codebase to see if i could find where Stack is handling the cb setState. #dogscience all night long. Lots of stuff going on in there.",
  "<mention!> now you know the pain lol",
  "<mention!> I think it's actually a really easy fix.",
  "It would be a check if if return value === null || return value === undefined, then do nothing.",
  "Easiest way, is to pause in the debugger in your setState callback. Then step through to see what it does with your return value.",
  "<mention!> I'm trying to subscribe to https://developer.mozilla.org/en-US/docs/Web/API/WindowEventHandlers/onhashchange - just a manual external to access the oldUrl newUrl fields?",
  "<mention!> My plan is to finish writing this demo app with all of the features I can think of, see what requires externals once it's finished, and then merge that upstream.",
  "<mention!> The event should ideally be similar to any of these: https://github.com/BuckleTypes/reason-js/tree/master/src/dom/events",
  "The handler is just an external on Window, I guess",
  "But in the fuiture addEventListener should probably use a polymprhic variant to support the right arguments",
  "<mention!> Yeah, that'd be pretty cool",
  "I'll phrase it like this to people: \"Each are equally terribly bad rotten casing conventions for file names due to case sensitive file systems - but the suggested Reason convention is...\".",
  "My earlier misunderstanding was that I thought you were advocating fileName but you were actually advocating file_name which does appear to be a justified position.",
  "<mention!> You should go fix up all the README files though ",
  "Come on, we don't write read me",
  "Hey, I included a (  ) - that gives me license to poke fun.",
  "I mean a LICENSE ",
  "Just noticed that Bucklescript is totally consistent with that convention: https://github.com/bloomberg/bucklescript/tree/master/jscomp/core",
  "<mention!> are the artifacts bucklescript generates on Linux still case preserving?",
  "Foo.re -> Foo.js",
  "Ocaml's stdlib isn't diligent about avoiding upper case though.",
  "We consistently generate little case file after Chengqi filed that issue",
  "",
  "Btw. I want to propose introducing the Dim keyword. And also the Sub keyword.",
  "edit: hehehe(edited)",
  "<mention!> <mention!> Spies.re <mention!> <mention!> <mention!> I had the idea yesterday that maybe a language can provide a built-in version of combinator (aka function but disallow closure)",
  "Jai has that I think. This way you can maybe enforce that \"this thing you're passing me shouldn't read into the closure\"",
  "it's also a tool-less, language-level way of easily refactoring code. Just lift it out through copy pasting. No closure retained",
  "you can \"trivially\" build this with a ppx plugin no?",
  "You annotate functions as [@doYouEvenLift], and then it will ensure that it actually can be lifted ahead of time.",
  "right now in ocamlc/ocamlopt, functions that don't utilize free variables, are reliably lifted ahead of time to the data section of the binary - allocated once IIRC.",
  "and likely easily optimized away, so you'd use a new pattern where you write a huge function but have multiple combinators inside for code organization, instead of introducing another indirection for readers to go search for the function callsite",
  "ah, nice",
  "well then, a reason syntax for combinator",
  "yeah, functions are great ways to abstract things - apart from their ability to capture the closure.",
  "hell yeah",
  "and then we can ensure statically that some setState callback or something else are reading into closures",
  "reason syntax: func foo a b => ...",
  "for \"fun combinator\"",
  "If we add unicode support, we can use some kind of annotation like:\n\n\nlet  myFunctionToLift x y => x + y;\n\nGet it, lift?(edited)",
  "List.map is a great example of where this is super useful.",
  "humm",
  "ok another idea: discourage bad patterns through emojis that are hard to type",
  "(The callback you pass to it, I mean)",
  "let foo =  5",
  "that's a ref",
  "but millennials will just use those bad patterns more then.",
  "ok ANOTHER IDEA: encourage good pattern through emojis or unicode:",
  "haha, Before you use Reason - Please enter your age range: [ ] followed by the enter key",
  "let foo = {...bar, baz: 1}",
  "notice it's a tasteful unicode ellipsis",
  "I actually want that one",
  "(Ascii too not unicode IIRC) (edit: I'm right - it's extended ASCII)(edited)",
  "Vim's conceal can easily do this one though.",
  "let newList = 1 :: oldList",
  "lol",
  "<mention!> can we finally tell everyone the new name of Reason already?",
  "(ES 2020)",
  "OCaml will be changed to ES 2030",
  "<mention!> Spies.re careful of the people who come in and start transpiling your code with babel",
  "We can rename BuckleScript to Babel..."
|];

let randArrEl arr => {
  let n = Random.int (Array.length arr);
  arr.(n)
};

let mentionRe = [%bs.re "/<mention!>/"];

let generateMessage _authorId users => {
  open State;
  let rawBody = randArrEl messageBodies;
  let users = Array.of_list users;
  let rec helper input =>
    Local_string.indexOf input "<mention!>" == (-1) ?
      input : helper (Local_string.replace input mentionRe ("@" ^ (randArrEl users).username));
  {content: helper rawBody, userId: (randArrEl users).id, createdAt: Js.Date.now ()}
};
