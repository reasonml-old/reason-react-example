let pxI = i => string_of_int(i) ++ "px";

let pxF = v => pxI(int_of_float(v));

module Key = {
  let counter = ref(0);
  let gen = () => {
    incr(counter);
    string_of_int(counter^);
  };
};

module ImageTransition: {
  /***
   * Render function for a transition between two images.
   * phase is a value between 0.0 (first image) and 1.0 (second image).
   **/
  let render: (~phase: float, int, int) => ReasonReact.reactElement;
  let displayHeight: int;
} = {
  let numImages = 6;
  let displayHeight = 200;
  let displayHeightString = pxI(displayHeight);
  let sizes = [|
    (500, 350),
    (800, 600),
    (800, 400),
    (700, 500),
    (200, 650),
    (600, 600),
  |];
  let displayWidths =
    Belt.Array.map(sizes, ((w, h)) => w * displayHeight / h);
  let getWidth = i => displayWidths[((i + numImages) mod numImages)];

  /***
   * Interpolate width and left for 2 images, phase is between 0.0 and 1.0.
   **/
  let interpolate = (~width1, ~width2, phase) => {
    let width1 = float_of_int(width1);
    let width2 = float_of_int(width2);
    let width = width1 *. (1. -. phase) +. width2 *. phase;
    let left1 = -. (width1 *. phase);
    let left2 = left1 +. width1;
    (pxF(width), pxF(left1), pxF(left2));
  };
  let renderImage = (~left, i) =>
    <img
      className="photo-inner"
      style=(ReactDOMRe.Style.make(~height=displayHeightString, ~left, ()))
      src=("./" ++ string_of_int((i + numImages) mod numImages) ++ ".jpg")
    />;
  let render = (~phase, image1, image2) => {
    let width1 = getWidth(image1);
    let width2 = getWidth(image2);
    let (width, left1, left2) = interpolate(~width1, ~width2, phase);
    <div>
      <div
        className="photo-outer"
        style=(ReactDOMRe.Style.make(~height=displayHeightString, ~width, ()))>
        (renderImage(~left=left1, image1))
        (renderImage(~left=left2, image2))
      </div>
    </div>;
  };
};

module ImageGalleryAnimation = {
  type action =
    | Click
    | SetCursor(float);
  type state = {
    animation: SpringAnimation.t,
    /* cursor value 3.5 means half way between image 3 and image 4 */
    cursor: float,
    targetImage: int,
  };
  let component = ReasonReact.reducerComponent("ImagesExample");
  let make = (~initialImage=0, ~animateMount=true, _children) => {
    ...component,
    initialState: () => {
      animation: SpringAnimation.create(float_of_int(initialImage)),
      cursor: float_of_int(initialImage),
      targetImage: initialImage,
    },
    didMount: ({state: {animation}, send}) => {
      animation
      |> SpringAnimation.setOnChange(~precision=0.05, ~onChange=cursor =>
           send(SetCursor(cursor))
         );
      if (animateMount) {
        send(Click);
      };
    },
    willUnmount: ({state: {animation}}) => SpringAnimation.stop(animation),
    reducer: (action, state) =>
      switch (action) {
      | Click =>
        UpdateWithSideEffects(
          {...state, targetImage: state.targetImage + 1},
          (
            ({state: {animation, targetImage}}) =>
              animation
              |> SpringAnimation.setFinalValue(float_of_int(targetImage))
          ),
        )
      | SetCursor(cursor) => Update({...state, cursor})
      },
    render: ({state: {cursor}, send}) => {
      let image = int_of_float(cursor);
      let phase = cursor -. float_of_int(image);
      <div onClick=(_e => send(Click))>
        (ImageTransition.render(~phase, image, image + 1))
      </div>;
    },
  };
};

module AnimatedButton = {
  module Text = {
    let component = ReasonReact.statelessComponent("Text");
    let make = (~text, _children) => {
      ...component,
      render: _ => <button> (ReasonReact.string(text)) </button>,
    };
  };
  type size =
    | Small
    | Large;
  let targetHeight = 30.;
  let closeWidth = 50.;
  let smallWidth = 250.;
  let largeWidth = 450.;
  type state = {
    animation: SpringAnimation.t,
    width: int,
    size,
    clickCount: int,
    actionCount: int,
  };
  type action =
    | Click
    | Reset
    | Unclick
    /* Width action triggered during animation.  */
    | Width(int)
    /* Toggle the size between small and large, and animate the width. */
    | ToggleSize
    /* Close the button by animating the width to shrink. */
    | Close;
  let component = ReasonReact.reducerComponent("ButtonAnimation");
  let make =
      (~text="Button", ~rAction, ~animateMount=true, ~onClose=?, _children) => {
    ...component,
    initialState: () => {
      animation: SpringAnimation.create(smallWidth),
      width: int_of_float(smallWidth),
      size: Small,
      clickCount: 0,
      actionCount: 0,
    },
    didMount: ({send}) => {
      RemoteAction.subscribe(~send, rAction) |> ignore;
      if (animateMount) {
        send(ToggleSize);
      };
    },
    willUnmount: ({state: {animation}}) => SpringAnimation.stop(animation),
    reducer: (action, state) =>
      switch (action) {
      | Click =>
        UpdateWithSideEffects(
          {
            ...state,
            clickCount: state.clickCount + 1,
            actionCount: state.actionCount + 1,
          },
          (({send}) => send(ToggleSize)),
        )
      | Reset =>
        Update({...state, clickCount: 0, actionCount: state.actionCount + 1})
      | Unclick =>
        Update({
          ...state,
          clickCount: state.clickCount - 1,
          actionCount: state.actionCount + 1,
        })
      | Width(width) => Update({...state, width})
      | ToggleSize =>
        UpdateWithSideEffects(
          {...state, size: state.size === Small ? Large : Small},
          (
            ({state: {animation, size}, send}) =>
              animation
              |> SpringAnimation.setOnChange(
                   ~finalValue=size === Small ? smallWidth : largeWidth,
                   ~precision=10.,
                   ~onChange=w =>
                   send(Width(int_of_float(w)))
                 )
          ),
        )
      | Close =>
        SideEffects(
          (
            ({state: {animation}, send}) =>
              animation
              |> SpringAnimation.setOnChange(
                   ~finalValue=closeWidth,
                   ~speedup=0.3,
                   ~precision=10.,
                   ~onStop=onClose,
                   ~onChange=w =>
                   send(Width(int_of_float(w)))
                 )
          ),
        )
      },
    render: ({state: {width} as state, send}) => {
      let buttonLabel = state =>
        text
        ++ " clicks:"
        ++ string_of_int(state.clickCount)
        ++ " actions:"
        ++ string_of_int(state.actionCount);
      <div
        className="exampleButton large"
        onClick=(_e => send(Click))
        style=(ReactDOMRe.Style.make(~width=pxI(width), ()))>
        <Text text=(buttonLabel(state)) />
      </div>;
    },
  };
};

module AnimateHeight = {
  /* When the closing animation begins */
  type onBeginClosing = Animation.onStop;
  type action =
    | Open(Animation.onStop)
    | BeginClosing(onBeginClosing, Animation.onStop)
    | Close(Animation.onStop)
    | Animate(float, Animation.onStop)
    | Height(float);
  type state = {
    height: float,
    animation: SpringAnimation.t,
  };
  let component = ReasonReact.reducerComponent("HeightAnim");
  let make = (~rAction, ~targetHeight, children) => {
    ...component,
    initialState: () => {height: 0., animation: SpringAnimation.create(0.)},
    didMount: ({send}) => {
      RemoteAction.subscribe(~send, rAction) |> ignore;
      send(Animate(targetHeight, None));
    },
    reducer: (action, state) =>
      switch (action) {
      | Height(v) => Update({...state, height: v})
      | Animate(finalValue, onStop) =>
        SideEffects(
          (
            ({send}) =>
              state.animation
              |> SpringAnimation.setOnChange(
                   ~finalValue, ~precision=10., ~onStop, ~onChange=h =>
                   send(Height(h))
                 )
          ),
        )
      | Close(onClose) =>
        SideEffects((({send}) => send(Animate(0., onClose))))
      | BeginClosing(onBeginClosing, onClose) =>
        SideEffects(
          (
            ({send}) => {
              switch (onBeginClosing) {
              | None => ()
              | Some(f) => f()
              };
              send(Animate(0., onClose));
            }
          ),
        )
      | Open(onOpen) =>
        SideEffects((({send}) => send(Animate(targetHeight, onOpen))))
      },
    willUnmount: ({state}) => SpringAnimation.stop(state.animation),
    render: ({state}) =>
      <div
        style=(
          ReactDOMRe.Style.make(
            ~height=pxF(state.height),
            ~overflow="hidden",
            (),
          )
        )>
        (ReasonReact.array(children))
      </div>,
  };
};

module ReducerAnimationExample = {
  type action =
    | SetAct(action => unit)
    | AddSelf
    | AddButton(bool)
    | AddButtonFirst(bool)
    | AddImage(bool)
    | DecrementAllButtons
    /* Remove from the list the button uniquely identified by its height RemoteAction */
    | FilterOutItem(RemoteAction.t(AnimateHeight.action))
    | IncrementAllButtons
    | CloseAllButtons
    | RemoveItem
    | ResetAllButtons
    | ReverseItemsAnimation
    | CloseHeight(Animation.onStop) /* Used by ReverseAnim */
    | ReverseWithSideEffects(unit => unit) /* Used by ReverseAnim */
    | OpenHeight(Animation.onStop) /* Used by ReverseAnim */
    | ToggleRandomAnimation;
  type item = {
    element: ReasonReact.reactElement,
    rActionButton: RemoteAction.t(AnimatedButton.action),
    rActionHeight: RemoteAction.t(AnimateHeight.action),
    /* used while removing items, to find the first item not already closing */
    mutable closing: bool,
  };
  module State: {
    type t = {
      act: action => unit,
      randomAnimation: Animation.t,
      items: list(item),
    };
    let createButton:
      (
        ~removeFromList: RemoteAction.t(AnimateHeight.action) => unit,
        ~animateMount: bool=?,
        int
      ) =>
      item;
    let createImage: (~animateMount: bool=?, int) => item;
    let getElements: t => array(ReasonReact.reactElement);
    let initial: unit => t;
  } = {
    type t = {
      act: action => unit,
      randomAnimation: Animation.t,
      items: list(item),
    };
    let initial = () => {
      act: _action => (),
      randomAnimation: Animation.create(),
      items: [],
    };
    let getElements = ({items}) =>
      Belt.List.toArray(Belt.List.mapReverse(items, x => x.element));
    let createButton = (~removeFromList, ~animateMount=?, number) => {
      let rActionButton = RemoteAction.create();
      let rActionHeight = RemoteAction.create();
      let key = Key.gen();
      let onClose = () =>
        RemoteAction.send(
          rActionHeight,
          ~action=
            AnimateHeight.Close(Some(() => removeFromList(rActionHeight))),
        );
      let element: ReasonReact.reactElement =
        <AnimateHeight
          key rAction=rActionHeight targetHeight=AnimatedButton.targetHeight>
          <AnimatedButton
            key
            text=("Button#" ++ string_of_int(number))
            rAction=rActionButton
            ?animateMount
            onClose
          />
        </AnimateHeight>;
      {element, rActionButton, rActionHeight, closing: false};
    };
    let createImage = (~animateMount=?, number) => {
      let key = Key.gen();
      let rActionButton = RemoteAction.create();
      let imageGalleryAnimation =
        <ImageGalleryAnimation
          key=(Key.gen())
          initialImage=number
          ?animateMount
        />;
      let rActionHeight = RemoteAction.create();
      let element =
        <AnimateHeight
          key
          rAction=rActionHeight
          targetHeight=(float_of_int(ImageTransition.displayHeight))>
          imageGalleryAnimation
        </AnimateHeight>;
      {element, rActionButton, rActionHeight, closing: false};
    };
  };
  let runAll = action => {
    let performSideEffects = ({ReasonReact.state: {State.items}}) =>
      Belt.List.forEach(items, ({rActionButton}) =>
        RemoteAction.send(rActionButton, ~action)
      );
    ReasonReact.SideEffects(performSideEffects);
  };
  let component = ReasonReact.reducerComponent("ReducerAnimationExample");
  let rec make = (~showAllButtons, _children) => {
    ...component,
    initialState: () => State.initial(),
    didMount: ({state: {State.randomAnimation: animation}, send}) => {
      let callback =
        (.) => {
          let randomAction =
            switch (Random.int(6)) {
            | 0 => AddButton(true)
            | 1 => AddImage(true)
            | 2 => RemoveItem
            | 3 => RemoveItem
            | 4 => DecrementAllButtons
            | 5 => IncrementAllButtons
            | _ => assert(false)
            };
          send(randomAction);
          Animation.Continue;
        };
      send(SetAct(send));
      Animation.setCallback(animation, ~callback);
    },
    willUnmount: ({state: {randomAnimation}}) =>
      Animation.stop(randomAnimation),
    reducer: (action, {act, items, randomAnimation} as state) =>
      switch (action) {
      | SetAct(act) => Update({...state, act})
      | AddSelf =>
        module Self = {
          let make = make(~showAllButtons);
        };
        let key = Key.gen();
        let rActionButton = RemoteAction.create();
        let rActionHeight = RemoteAction.create();
        let element =
          <AnimateHeight key rAction=rActionHeight targetHeight=500.>
            <Self key />
          </AnimateHeight>;
        let item = {element, rActionButton, rActionHeight, closing: false};
        Update({...state, items: [item, ...items]});
      | AddButton(animateMount) =>
        let removeFromList = rActionHeight =>
          act(FilterOutItem(rActionHeight));
        Update({
          ...state,
          items: [
            State.createButton(
              ~removeFromList,
              ~animateMount,
              Belt.List.length(items),
            ),
            ...items,
          ],
        });
      | AddButtonFirst(animateMount) =>
        let removeFromList = rActionHeight =>
          act(FilterOutItem(rActionHeight));
        Update({
          ...state,
          items:
            items
            @ [
              State.createButton(
                ~removeFromList,
                ~animateMount,
                Belt.List.length(items),
              ),
            ],
        });
      | AddImage(animateMount) =>
        Update({
          ...state,
          items: [
            State.createImage(~animateMount, Belt.List.length(items)),
            ...items,
          ],
        })
      | FilterOutItem(rAction) =>
        let filter = item => item.rActionHeight !== rAction;
        Update({...state, items: Belt.List.keep(items, filter)});
      | DecrementAllButtons => runAll(Unclick)
      | IncrementAllButtons => runAll(Click)
      | CloseAllButtons => runAll(Close)
      | RemoveItem =>
        switch (Belt.List.getBy(items, item => item.closing === false)) {
        | Some(firstItemNotClosing) =>
          let onBeginClosing =
            Some((() => firstItemNotClosing.closing = true));
          let onClose =
            Some(
              (() => act(FilterOutItem(firstItemNotClosing.rActionHeight))),
            );
          SideEffects(
            (
              _ =>
                RemoteAction.send(
                  firstItemNotClosing.rActionHeight,
                  ~action=BeginClosing(onBeginClosing, onClose),
                )
            ),
          );
        | None => NoUpdate
        }
      | ResetAllButtons => runAll(Reset)
      | CloseHeight(onStop) =>
        let len = Belt.List.length(items);
        let count = ref(len);
        let onClose = () => {
          decr(count);
          if (count^ === 0) {
            switch (onStop) {
            | None => ()
            | Some(f) => f()
            };
          };
        };
        let iter = _ =>
          Belt.List.forEach(items, item =>
            RemoteAction.send(
              item.rActionHeight,
              ~action=Close(Some(onClose)),
            )
          );
        SideEffects(iter);
      | OpenHeight(onStop) =>
        let len = Belt.List.length(items);
        let count = ref(len);
        let onClose = () => {
          decr(count);
          if (count^ === 0) {
            switch (onStop) {
            | None => ()
            | Some(f) => f()
            };
          };
        };
        let iter = _ =>
          Belt.List.forEach(items, item =>
            RemoteAction.send(
              item.rActionHeight,
              ~action=Open(Some(onClose)),
            )
          );
        SideEffects(iter);
      | ReverseWithSideEffects(performSideEffects) =>
        UpdateWithSideEffects(
          {...state, items: Belt.List.reverse(items)},
          (_ => performSideEffects()),
        )
      | ReverseItemsAnimation =>
        let onStopClose = () =>
          act(ReverseWithSideEffects(() => act(OpenHeight(None))));
        SideEffects((_ => act(CloseHeight(Some(onStopClose)))));
      | ToggleRandomAnimation =>
        SideEffects(
          (
            _ =>
              Animation.isActive(randomAnimation) ?
                Animation.stop(randomAnimation) :
                Animation.start(randomAnimation)
          ),
        )
      },
    render: ({state}) => {
      let button = (~repeat=1, ~hide=false, txt, action) =>
        hide ?
          ReasonReact.null :
          <div
            className="exampleButton large"
            style=(ReactDOMRe.Style.make(~width="220px", ()))
            onClick=(
              _e =>
                for (_ in 1 to repeat) {
                  state.act(action);
                }
            )>
            (ReasonReact.string(txt))
          </div>;
      let hide = !showAllButtons;
      <div className="componentBox">
        <div className="componentColumn">
          (ReasonReact.string("Control:"))
          (button("Add Button", AddButton(true)))
          (button("Add Image", AddImage(true)))
          (button("Add Button On Top", AddButtonFirst(true)))
          (button("Remove Item", RemoveItem))
          (
            button(
              ~hide,
              ~repeat=100,
              "Add 100 Buttons On Top",
              AddButtonFirst(false),
            )
          )
          (button(~hide, ~repeat=100, "Add 100 Images", AddImage(false)))
          (button("Click all the Buttons", IncrementAllButtons))
          (button(~hide, "Unclick all the Buttons", DecrementAllButtons))
          (button("Close all the Buttons", CloseAllButtons))
          (
            button(
              ~hide,
              ~repeat=10,
              "Click all the Buttons 10 times",
              IncrementAllButtons,
            )
          )
          (button(~hide, "Reset all the Buttons' states", ResetAllButtons))
          (button("Reverse Items", ReverseItemsAnimation))
          (
            button(
              "Random Animation "
              ++ (Animation.isActive(state.randomAnimation) ? "ON" : "OFF"),
              ToggleRandomAnimation,
            )
          )
          (button("Add Self", AddSelf))
        </div>
        <div
          className="componentColumn"
          style=(ReactDOMRe.Style.make(~width="500px", ()))>
          <div>
            (
              ReasonReact.string(
                "Items:" ++ string_of_int(Belt.List.length(state.items)),
              )
            )
          </div>
          (ReasonReact.array(State.getElements(state)))
        </div>
      </div>;
    },
  };
};

module ChatHead = {
  type action =
    | MoveX(float)
    | MoveY(float);
  type state = {
    x: float,
    y: float,
  };
  let component = ReasonReact.reducerComponent("ChatHead");
  let make = (~rAction, ~headNum, ~imageGallery, _children) => {
    ...component,
    initialState: () => {x: 0., y: 0.},
    didMount: ({send}) => RemoteAction.subscribe(~send, rAction) |> ignore,
    reducer: (action, state: state) =>
      switch (action) {
      | MoveX(x) => Update({...state, x})
      | MoveY(y) => Update({...state, y})
      },
    render: ({state: {x, y}}) => {
      let left = pxF(x -. 25.);
      let top = pxF(y -. 25.);
      imageGallery ?
        <div
          className="chat-head-image-gallery"
          style=(
            ReactDOMRe.Style.make(
              ~left,
              ~top,
              ~zIndex=string_of_int(- headNum),
              (),
            )
          )>
          <ImageGalleryAnimation initialImage=headNum />
        </div> :
        <div
          className=("chat-head chat-head-" ++ string_of_int(headNum mod 6))
          style=(
            ReactDOMRe.Style.make(
              ~left,
              ~top,
              ~zIndex=string_of_int(- headNum),
              (),
            )
          )
        />;
    },
  };
};

module ChatHeadsExample = {
  [@bs.val]
  external addEventListener: (string, Js.t({..}) => unit) => unit =
    "window.addEventListener";
  let numHeads = 6;
  type control = {
    rAction: RemoteAction.t(ChatHead.action),
    animX: SpringAnimation.t,
    animY: SpringAnimation.t,
  };
  type state = {
    controls: array(control),
    chatHeads: array(ReasonReact.reactElement),
  };
  let createControl = () => {
    rAction: RemoteAction.create(),
    animX: SpringAnimation.create(0.),
    animY: SpringAnimation.create(0.),
  };
  let component = ReasonReact.reducerComponent("ChatHeadsExample");
  let make = (~imageGallery, _children) => {
    ...component,
    initialState: () => {
      let controls = Belt.Array.makeBy(numHeads, _ => createControl());
      let chatHeads =
        Belt.Array.makeBy(numHeads, i =>
          <ChatHead
            key=(Key.gen())
            imageGallery
            rAction=controls[i].rAction
            headNum=i
          />
        );
      {controls, chatHeads};
    },
    didMount: ({state: {controls}}) => {
      let setupAnimation = headNum => {
        let setOnChange = (~isX, afterChange) => {
          let control = controls[headNum];
          let animation = isX ? control.animX : control.animY;
          animation
          |> SpringAnimation.setOnChange(
               ~preset=Spring.gentle,
               ~speedup=2.,
               ~onChange=v => {
                 RemoteAction.send(
                   control.rAction,
                   ~action=isX ? MoveX(v) : MoveY(v),
                 );
                 afterChange(v);
               },
             );
        };
        let isLastHead = headNum == numHeads - 1;
        let afterChangeX = x =>
          isLastHead ?
            () :
            controls[(headNum + 1)].animX |> SpringAnimation.setFinalValue(x);
        let afterChangeY = y =>
          isLastHead ?
            () :
            controls[(headNum + 1)].animY |> SpringAnimation.setFinalValue(y);
        setOnChange(~isX=true, afterChangeX);
        setOnChange(~isX=false, afterChangeY);
      };
      Belt.Array.forEachWithIndex(controls, (i, _) => setupAnimation(i));
      let onMove = e => {
        let x = e##pageX;
        let y = e##pageY;
        controls[0].animX |> SpringAnimation.setFinalValue(x);
        controls[0].animY |> SpringAnimation.setFinalValue(y);
      };
      addEventListener("mousemove", onMove);
      addEventListener("touchmove", onMove);
    },
    willUnmount: ({state: {controls}}) =>
      Belt.Array.forEach(
        controls,
        ({animX, animY}) => {
          SpringAnimation.stop(animX);
          SpringAnimation.stop(animY);
        },
      ),
    reducer: ((), _) => NoUpdate,
    render: ({state: {chatHeads}}) =>
      <div> (ReasonReact.array(chatHeads)) </div>,
  };
};

module ChatHeadsExampleStarter = {
  type state =
    | StartMessage
    | ChatHeads
    | ImageGalleryHeads;
  let component = ReasonReact.reducerComponent("ChatHeadsExampleStarter");
  let make = _children => {
    ...component,
    initialState: () => StartMessage,
    reducer: (actionIsState, _) => Update(actionIsState),
    render: ({state, send}) =>
      switch (state) {
      | StartMessage =>
        <div>
          <div>
            <button onClick=(_e => send(ChatHeads))>
              (ReasonReact.string("Start normal chatheads"))
            </button>
          </div>
          <button onClick=(_e => send(ImageGalleryHeads))>
            (ReasonReact.string("Start image gallery chatheads"))
          </button>
        </div>
      | ChatHeads => <ChatHeadsExample imageGallery=false />
      | ImageGalleryHeads => <ChatHeadsExample imageGallery=true />
      },
  };
};

module GalleryItem = {
  let component = ReasonReact.statelessComponent("GalleryItem");
  let make = (~title="Untitled", ~description="no description", child) => {
    let title = <div className="header"> (ReasonReact.string(title)) </div>;
    let description =
      <div
        className="headerSubtext"
        dangerouslySetInnerHTML={"__html": description}
      />;
    let leftRight =
      <div className="galleryItemDemo leftRightContainer">
        <div className="right interactionContainer"> child </div>
      </div>;
    {
      ...component,
      render: _self =>
        <div className="galleryItem"> title description leftRight </div>,
    };
  };
};

module GalleryContainer = {
  let component = ReasonReact.statelessComponent("GalleryContainer");
  let megaHeaderTitle = "Animating With Reason React Reducers";
  let megaHeaderSubtext = {|
    Examples With Animations.
  |};
  let megaHeaderSubtextDetails = {|
    Explore animation with ReasonReact and reducers.

  |};
  let make = children => {
    ...component,
    render: _self =>
      <div
        className="mainGallery"
        style=(ReactDOMRe.Style.make(~width="850px", ()))>
        <div key="megaHeader" className="megaHeader">
          (ReasonReact.string(megaHeaderTitle))
        </div>
        <div key="degaHeaderSubtext" className="megaHeaderSubtext">
          (ReasonReact.string(megaHeaderSubtext))
        </div>
        <div key="headerSubtext" className="megaHeaderSubtextDetails">
          (ReasonReact.string(megaHeaderSubtextDetails))
        </div>
        (
          ReasonReact.array(
            Array.map(c => <div key=(Key.gen())> c </div>, children),
          )
        )
      </div>,
  };
};

module ComponentGallery = {
  let component = ReasonReact.statelessComponent("ComponentGallery");
  let make = _children => {
    let globalStateExample =
      <GalleryItem title="Global State Example" description={||}>
        ...<Demo.GlobalStateExample />
      </GalleryItem>;
    let localStateExample =
      <GalleryItem title="Local State Example" description={||}>
        ...<Demo.LocalStateExample />
      </GalleryItem>;
    let simpleTextInput =
      <GalleryItem
        title="Simple Text Input" description={|Edit the text field|}>
        ...<Demo.TextInput onChange=(text => Js.log2("onChange:", text)) />
      </GalleryItem>;
    let simpleSpring =
      <GalleryItem
        title="Simple Spring" description={|Click on target to toggle|}>
        ...<Demo.SimpleSpring />
      </GalleryItem>;
    let animatedTextInput =
      <GalleryItem
        title="Animated Text Input"
        description={|Edit text, or click on target to toggle animation|}>
        ...<Demo.AnimatedTextInput />
      </GalleryItem>;
    let animatedTextInputRemote =
      <GalleryItem
        title="Animated Text Input With Remote Actions"
        description={|Edit text, or click on target to toggle animation|}>
        ...<Demo.AnimatedTextInputRemote />
      </GalleryItem>;
    let callActionsOnGrandChild =
      <GalleryItem
        title="Call actions on grandchild directly" description={||}>
        ...<Demo.Parent />
      </GalleryItem>;
    let chatHeads =
      <GalleryItem title="Chat Heads" description={||}>
        ...<ChatHeadsExampleStarter />
      </GalleryItem>;
    let imageGallery =
      <GalleryItem
        title="Image Gallery"
        description={| Click on the image to transition to the next one. |}>
        ...<ImageGalleryAnimation />
      </GalleryItem>;
    let reducerAnimation =
      <GalleryItem title="Animation Based On Reducers" description={||}>
        ...<ReducerAnimationExample showAllButtons=false />
      </GalleryItem>;
    {
      ...component,
      render: _self =>
        <GalleryContainer>
          globalStateExample
          localStateExample
          simpleTextInput
          simpleSpring
          animatedTextInput
          animatedTextInputRemote
          callActionsOnGrandChild
          chatHeads
          imageGallery
          reducerAnimation
        </GalleryContainer>,
    };
  };
};
