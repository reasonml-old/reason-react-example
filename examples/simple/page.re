let renderIcon = [%bs.raw "window.renderIcon"];

let eventIcon = [%bs.raw "window.eventIcon"];

let propsReceivedIcon = [%bs.raw "window.propsReceivedIcon"];

let updateIcon = [%bs.raw "window.updateIcon"];

let elbowIcon = [%bs.raw "window.elbowIcon"];

let consoleStyle: string => unit = [%bs.raw "console.style.bind(console)"];

let style
    ::icon=""
    ::backgroundColor="rgba(255,255,255,0)"
    ::fontWeight="normal"
    ::border="transparent "
    text =>
  "<css='box-sizing: border-box; border-radius:1px; padding-left: 3px; padding-right:3px; " ^
  "border: 1px solid " ^
  border ^
  "; background:" ^
  backgroundColor ^
  "; font-weight:" ^ fontWeight ^ ";'>" ^ (icon == "" ? "" : icon ^ " ") ^ text ^ "</css>";

let print lst => consoleStyle (String.concat " " lst);

let childStyle =
  style backgroundColor::"rgba(210,200,250, 0.3)" fontWeight::"bold" border::"rgba(0,0,0,0.2)";

let parentStyle =
  style backgroundColor::"rgba(250,200,210, 0.3)" fontWeight::"bold" border::"rgba(0,0,0,0.2)";

let dataStyle =
  style backgroundColor::"rgba(200,200,200, 0.1)" fontWeight::"bold" border::"rgba(0,0,0,0.1)";

module Button = {
  type display =
    | Inline
    | Block;
  type size =
    | Small
    | Medium
    | Large;
  let component = ReasonReact.createComponent "Button";
  let computeClassName size display => {
    let className =
      switch display {
      | Inline => "exampleButton inline"
      | Block => "exampleButton"
      };
    let className =
      switch size {
      | Small => className ^ " small"
      | Medium => className ^ " medium"
      | Large => className ^ " large"
      };
    className
  };
  let make
      onClick::(onClick: ReasonReact.Callback.t ReactEventRe.Mouse.t)
      ::size=Medium
      ::display=(size === Medium ? Inline : Block)
      ::text="Button"
      _children => {
    ...component,
    render: fun _state _self =>
      <div className=(computeClassName size display) onClick> (ReasonReact.stringToElement text) </div>
  };
};

module ButtonExample = {
  let component = ReasonReact.createComponent "ButtonExample";
  let handleClick _curState _self _e => ReasonReact.NoUpdate;
  let make _children => {
    ...component,
    render: fun _state self =>
      <div className="componentBox">
        (
          ReasonReact.element (
            Button.make text::"click" size::Button.Large onClick::(self.enqueue handleClick) [||]
          )
        )
      </div>
  };
};


/**
 * Shows the evolution of a non-stateful component to a stateful one.
 */
module StatefulButton = {
  type state = {clickCount: int, value: string};
  type size =
    | Medium
    | Large;
  let handleClick _e curState _self =>
    ReasonReact.Update {...curState, clickCount: curState.clickCount + 1};
  let component = ReasonReact.createComponent "StatefulButton";
  let make ::size=Medium ::text="Button" _children => {
    ...component,
    initialState: fun () => {clickCount: 0, value: "abc"},
    render: fun state {ReasonReact.enqueue: enqueue} => {
      let className =
        switch size {
        | Medium => "exampleButton medium"
        | Large => "exampleButton large"
        };
      let buttonLabel state => text ^ " button-clicks:" ^ string_of_int state.clickCount;
      <div className onClick=(enqueue handleClick)> (ReasonReact.stringToElement (buttonLabel state)) </div>
    }
  };
};

module StatefulButtonExample = {
  let component = ReasonReact.createComponent "StatefulButtonExample";
  let make _children => {
    ...component,
    render: fun _state _ =>
      <div className="componentBox">
        (ReasonReact.element (StatefulButton.make text::"Hello" size::StatefulButton.Large [||]))
      </div>
  };
};

module SilentUpdater = {
  let handleClick _domEvent curState _self => {
    let nextState = curState + 1;
    Js.log (
      "clicked " ^ string_of_int curState ^ " times and updating to " ^ string_of_int nextState
    );
    if (nextState mod 2 === 0) {
      ReasonReact.SilentUpdate nextState
    } else if (nextState mod 5 === 0) {
      /*
       * Actually, you'r not supposed to have side effects in here.
       */
      Js.log "SilentUpdateEffect for multiples of 5";
      ReasonReact.SilentUpdate nextState
    } else {
      ReasonReact.Update nextState
    }
  };

  /**
   * In this example, we create the component and also add a lifecycle method.
   */
  let component = {
    ...ReasonReact.createComponent "SilentUpdater",
    didMount: fun _ _ => {
      Js.log "componentDidMount of Page.re!";
      Js.log "Another Side Effect At Mount Time in Page.re!";
      ReasonReact.NoUpdate
    }
  };
  let make _children => {
    ...component,
    initialState: fun () => 0,
    render: fun state {ReasonReact.enqueue: enqueue} =>
      <div className="componentBox">
        (ReasonReact.stringToElement "Click ")
        (
          ReasonReact.element (
            Button.make text::"This Button" size::Button.Small onClick::(enqueue handleClick) [||]
          )
        )
        (
          ReasonReact.stringToElement "to increment the state counter. Counts that are multiples of 2 or 5 are performed 'silently'. That means they still take place, but won't trigger a rerender. Rerenderings may still happen due to other reasons."
        )
        (
          ReasonReact.createDomElement
            "div"
            props::{"className": "stateLogger"}
            [|ReasonReact.stringToElement ("Rendered Click Count State: " ^ string_of_int state)|]
        )
      </div>
  };
};

module LifecycleLogger = {
  let component = ReasonReact.createComponent "LifecycleLogger";
  let component = {
    ...component,
    didMount: fun curState _self => ReasonReact.Update ["nowMounting", ...curState]
  };
  let stateToString lst => "[" ^ String.concat ", " lst ^ "]";
  let make _children => {
    ...component,
    initialState: fun () => ["initialState"],
    render: fun state _self =>
      <div className="componentBox">
        (
          ReasonReact.stringToElement "The state will start out as a single item list, and then upon mounting, will append a second item."
        )
        <div className="stateLogger">
          (ReasonReact.stringToElement ("Appended State History: " ^ stateToString state))
        </div>
      </div>
  };
};

module CascadingUpdatesExample = {
  type state = {outerClicks: int};
  let component = ReasonReact.createComponent "CascadingUpdatesExample";
  let handleClick _domEvent curState _self =>
    ReasonReact.Update {outerClicks: curState.outerClicks + 1};
  let make _children => {
    ...component,
    initialState: fun () => {outerClicks: 0},
    render: fun state {ReasonReact.enqueue: enqueue} =>
      <div className="componentBox" onMouseDown=(enqueue handleClick)>
        (
          ReasonReact.element (
            StatefulButton.make
              size::StatefulButton.Large
              text::("outer-state: " ^ string_of_int state.outerClicks ^ " ")
              [||]
          )
        )
      </div>
  };
};

module MultipleStateUpdatesPerEvent = {
  type state = {count: int, latestProp: int};
  let component = ReasonReact.createComponent "MultipleStateUpdatesPerEvent";
  let handleClick name _e => {
    Js.log ("First phase in handleClick " ^ name);
    fun curState _self => {
      Js.log ("Second phase in handleClick " ^ name);
      ReasonReact.Update {...curState, count: curState.count + curState.latestProp}
    }
  };
  let make ::prop _children => {
    ...component,
    initialState: fun () => {count: 0, latestProp: prop},
    propsReceived: fun prevState _self => {...prevState, latestProp: prop},
    render: fun state self =>
      <div className="componentBox" onClick=(self.update (handleClick "outer"))>
        <div className="componentBox" onClick=(self.update (handleClick "inner")) />
        (ReasonReact.stringToElement ("State:" ^ string_of_int state.count))
      </div>
  };
};


/**
 * Same example as before, but using `self.queued`.
 */
module MultipleStateUpdatesPerEventQueued = {
  type state = {count: int, latestProp: int};
  let component = ReasonReact.createComponent "MultipleStateUpdatesPerEvent";
  let handleClick name _e => {
    Js.log ("First phase in handleClick " ^ name);
    fun curState _self => {
      Js.log ("Second phase in handleClick " ^ name);
      ReasonReact.Update {...curState, count: curState.count + curState.latestProp}
    }
  };
  let make ::prop _children => {
    ...component,
    initialState: fun () => {count: 0, latestProp: prop},
    propsReceived: fun prevState _ => {...prevState, latestProp: prop},
    render: fun state self =>
      <div className="componentBox" onClick=(self.enqueue (handleClick "outer"))>
        <div className="componentBox" onClick=(self.enqueue (handleClick "inner"))>
          (ReasonReact.stringToElement ("State:" ^ string_of_int state.count))
        </div>
      </div>
  };
};


/**
 * Wrapper around Button that records and displays how many times the size has
 * changed.
 */
module ReceiveProps = {
  type state = {changes: int, latestSize: Button.size};
  let dummyHandleClick _state _self _e => ReasonReact.NoUpdate;
  let component = ReasonReact.createComponent "IncrementByProp";
  let make ::size _children => {
    ...component,
    initialState: fun () => {changes: 0, latestSize: size},
    propsReceived: fun state _self =>
      state.latestSize === size ? state : {changes: state.changes + 1, latestSize: size},
    render: fun state self =>
      <div className="componentBox">
        (ReasonReact.stringToElement "Click the outer box to toggle size:")
        (
          ReasonReact.element (
            Button.make
              text::("changes:" ^ string_of_int state.changes)
              size::state.latestSize
              onClick::(self.enqueue dummyHandleClick)
              [||]
          )
        )
      </div>
  };
};

module ReceivePropsExample = {
  let component = ReasonReact.createComponent "ReceivePropsExample";
  let handleClick _e curState _self =>
    ReasonReact.Update (curState === Button.Large ? Button.Small : Button.Large);
  let make _children => {
    ...component,
    initialState: fun () => Button.Small,
    render: fun state self =>
      <div className="componentBox" onClick=(self.enqueue handleClick)>
        (ReasonReact.element (ReceiveProps.make size::state [||]))
      </div>
  };
};


/**
 * Demonstrates how side effects may be performed as part of event handlers,
 * and how state updates may play with those side effects. Also demonstrates
 * one other interesting way in which callbacks will not always have the
 * freshest props. We know that callbacks passed down to components that do
 * shouldComponentUpdate=false will not have the freshest props, but this shows
 * that the nuance is not limited to that scenario.
 *
 * Rendered components returning false from shouldComponentUpdate will prevent
 * your callback from seeing the freshest props since your new callback can't
 * be attached.
 *
 * But even ignore that case, any enqueue can at *best* only see the freshest
 * props during the "first phase" of the event handler. When it may perform
 * imperative side effects. The second phase of the enqueue, (invoking the
 * remaining args after the first) will occur *after* the props from other
 * component updaters have been flushed down - and therefore your callback will
 * see the freshest state, after next: is reran, but it won't and cannot see
 * the freshest props.
 *
 * A reducer() API that we add on top of this API would allow action handlers
 * to see the freshest props.
 *
 * In the mean time, we encourage the following pattern:
 *
 * 1. Handlers only rely on state. Note it can rely on the event, but it should
 *    not touch dom Events outside of the event loop!
 *
 *
 *     let handle event state self => nextState;
 *     let make ::props children => {
 *       ...,
 *       fun ::state self =>
 *         ...
 *         self.enqueue(handleEvent)
 *     };
 *
 *
 * 2.
 *     let handle event => {
 *       imperativeThing event;
 *       fun state self => nextState;
 *     };
 *     let make ::props children => {
 *       ...,
 *       fun ::state self =>
 *         ...
 *         self.enqueue(handleEvent)
 *     };
 *
 * 3. "First stage" of the handler can reference props, but second stage must
 * be predeclared outside of the create factory. Handler declared outside so
 * it cannot reference props.
 *
 *     let myHandler state self => nextState;
 *     let make ::props children => {
 *       ...,
 *       fun ::state self =>
 *         let handle event => {
 *           imperativeThing event props.foo;
 *           handleNextState
 *         };
 *         ...
 *         self.enqueue(handleEvent)
 *     };
 */
type outerState = {value: int};

type sideEffecterState = {innerState: int, retainedProp: outerState};

module SideEffecterPrinter = {
  let printState s =>
    "{innerState:" ^
    string_of_int s.innerState ^ ", retainedProp:" ^ string_of_int s.retainedProp.value ^ "}";
  let toString outerStateAsProp state =>
    " prop:" ^
    dataStyle (string_of_int outerStateAsProp.value) ^ " state:" ^ dataStyle (printState state);
  let printPropsReceived outerStateAsProp curState =>
    print [
      childStyle icon::propsReceivedIcon "Child ",
      "PropsReceived props:",
      dataStyle (string_of_int outerStateAsProp.value),
      " supplied state:",
      dataStyle (printState curState)
    ];
  let printPropsReceivedUpdate nextState =>
    print [
      elbowIcon,
      childStyle icon::updateIcon "Child ",
      "next state:",
      dataStyle (printState nextState)
    ];
  let printChildHandleUpdateEnter outerStateAsProp curState =>
    print [
      childStyle icon::eventIcon "Child ",
      "Event closure prop:",
      dataStyle (string_of_int outerStateAsProp.value),
      " supplied state:",
      dataStyle (printState curState)
    ];
  let printChildHandleUpdateExit nextState =>
    print [
      elbowIcon,
      childStyle icon::updateIcon "Child ",
      "Event next state:",
      dataStyle (printState nextState)
    ];
  let printHandleQueuePhaseOneEnter outerStateAsProp state =>
    print [
      childStyle icon::eventIcon "Child ",
      "Event Stage One closure prop:",
      dataStyle (string_of_int outerStateAsProp.value),
      " closure state:",
      dataStyle (printState state)
    ];
  let printHandleQueuePhaseTwoEnter curState =>
    print [
      childStyle icon::eventIcon "Child ",
      "Event Stage Two supplied state:",
      dataStyle (printState curState)
    ];
  let printHandleQueuePhaseTwoLeave nextState =>
    print [
      elbowIcon,
      childStyle icon::updateIcon "Child ",
      "Event Stage Two next state:",
      dataStyle (printState nextState)
    ];
};

module SideEffecter = {
  open SideEffecterPrinter;
  let component = ReasonReact.createComponent "SideEffecter";
  let make ::outerCallback ::outerStateAsProp _children => {
    ...component,
    initialState: fun () => {innerState: 0, retainedProp: outerStateAsProp},
    propsReceived: fun curState _self => {
      printPropsReceived outerStateAsProp curState;
      let nextState = {...curState, retainedProp: outerStateAsProp};
      printPropsReceivedUpdate nextState;
      nextState
    },
    didUpdate: fun ::previous ::current _self =>
      print [
        childStyle "Child ",
        "DidUpdate from:",
        dataStyle (printState previous),
        "to:",
        dataStyle (printState current)
      ],
    render: fun state {ReasonReact.enqueue: enqueue, update} => {
      print [childStyle icon::renderIcon "Child ", "Rendering", toString outerStateAsProp state];
      let handleUpdate _e curState _self => {
        printChildHandleUpdateEnter outerStateAsProp curState;
        let nextState = {...curState, innerState: curState.innerState + 1};
        printChildHandleUpdateExit nextState;
        ReasonReact.Update nextState
      };
      let handleQueue _e => {
        printHandleQueuePhaseOneEnter outerStateAsProp state;
        fun curState _self => {
          printHandleQueuePhaseTwoEnter curState;
          let nextState = {...curState, innerState: curState.innerState + 1};
          printHandleQueuePhaseTwoLeave nextState;
          ReasonReact.Update nextState
        }
      };
      <div className="dummy">
        (ReasonReact.stringToElement "(View The Console Log): ")
        (ReasonReact.stringToElement ("Child State:" ^ string_of_int state.innerState))
        (ReasonReact.stringToElement ("Parent State As Prop:" ^ string_of_int outerStateAsProp.value))
        (
          ReasonReact.element (
            Button.make
              display::Button.Block
              size::Button.Large
              text::"Click For .enqueue Side Effect + Update + No Chained Callback"
              onClick::(enqueue handleQueue)
              [||]
          )
        )
        (
          ReasonReact.element (
            Button.make
              display::Button.Block
              size::Button.Large
              text::"Click For .update Side Effect + Update + No Chained Callback"
              onClick::(update handleUpdate)
              [||]
          )
        )
        (
          ReasonReact.element (
            Button.make
              display::Button.Block
              size::Button.Large
              text::"Click For .enqueue Side Effect + Update + Chained Callback"
              onClick::(ReasonReact.Callback.chain (enqueue handleQueue) outerCallback)
              [||]
          )
        )
        (
          ReasonReact.element (
            Button.make
              display::Button.Block
              size::Button.Large
              text::"Click For .update Side Effect + Update + Chained Callback"
              onClick::(ReasonReact.Callback.chain (update handleUpdate) outerCallback)
              [||]
          )
        )
      </div>
    }
  };
};

module SideEffecterExamplePrinter = {
  let printHandleCallbackPhaseOneEnter outerStateAsProp =>
    print [
      parentStyle icon::eventIcon "Parent",
      "Event Stage One closure state:",
      dataStyle (string_of_int outerStateAsProp.value)
    ];
  let printHandleCallbackPhaseTwoEnter curState =>
    print [
      parentStyle icon::eventIcon "Parent",
      "Event Stage Two supplied state:",
      dataStyle (string_of_int curState.value)
    ];
  let printHandleCallbackPhaseTwoLeave curState =>
    print [
      elbowIcon,
      parentStyle icon::updateIcon "Parent",
      "Event Stage Two next state:",
      dataStyle (string_of_int (curState.value + 1))
    ];
};

module SideEffecterExample = {
  open SideEffecterExamplePrinter;
  let component = ReasonReact.createComponent "SideEffecterExample";
  let make _children => {
    ...component,
    initialState: fun () => {value: 0},
    render: fun state {ReasonReact.enqueue: enqueue} => {
      let handleCallback _e => {
        printHandleCallbackPhaseOneEnter state;
        fun curState _self => {
          printHandleCallbackPhaseTwoEnter curState;
          printHandleCallbackPhaseTwoLeave curState;
          ReasonReact.Update {value: curState.value + 1}
        }
      };
      <div className="componentBox">
        (
          ReasonReact.element (
            SideEffecter.make outerCallback::(enqueue handleCallback) outerStateAsProp::state [||]
          )
        )
      </div>
    }
  };
};


/**
 * Here's how you would implement the SideEffecter example "correctly", putting
 * all the callbacks in the right place. The previous example was only written
 * that way to demonstrate potential pitfalls.
 */
module SideEffecterCorrect = {
  type state = {innerState: int, retainedProp: int};
  let component = ReasonReact.createComponent "SideEffecter";
  let nextStateForHandler curState _self =>
    ReasonReact.Update {...curState, innerState: curState.innerState + 1};
  let make ::outerCallback ::outerStateAsProp _children => {
    ...component,
    initialState: fun () => {innerState: 0, retainedProp: outerStateAsProp},
    propsReceived: fun prevState _self => {...prevState, retainedProp: outerStateAsProp},
    render: fun _state {ReasonReact.enqueue: enqueue} => {
      /* You'd perform a side effect here on the event and refer to props,
       * but return the continuation which is declared outside. */
      let handle _e => {
        let _ = ignore outerStateAsProp;
        nextStateForHandler
      };
      <div className="dummy">
        (
          ReasonReact.element (
            Button.make
              display::Button.Block
              size::Button.Large
              text::"Click For Side Effect + Update + Chained Callback"
              onClick::(ReasonReact.Callback.chain (enqueue handle) outerCallback)
              [||]
          )
        )
      </div>
    }
  };
};


/**
 * Wraps all children in a box so you know it's working!
 */
module ChildRouting = {
  let component = ReasonReact.createComponent "ChildRoutingExample";
  let make children => {
    ...component,
    initialState: fun () => 0,
    render: fun _state _self => {
      let style =
        ReactDOMRe.Style.make opacity::"0.7" border::"5px solid #555" backgroundColor::"#ddd" ();
      <div className="componentBox" style> (ReasonReact.arrayToElement children) </div>
    }
  };
};

module RefHaver = {
  type state = {reference: option Dom.element};
  let handleRefMount theRef _curState _self => ReasonReact.SilentUpdate {reference: Js.Null.to_opt theRef};
  let component = {
    ...ReasonReact.createComponent "RefHaver",
    initialState: fun () => {reference: None},
    didMount: fun state _self => {
      switch state.reference {
      | None => Js.log "RefHaver: No reference at mount time"
      | Some _ => Js.log "RefHaver: Some reference at mount time"
      };
      NoUpdate
    }
  };
  let make _children => {
    ...component,
    render: fun state {ReasonReact.update: update} => {
      let text =
        switch state.reference {
        | None => {|
            No ref at render time, but there is a ref at mount time! Render won't be called again when a ref
            does get set because that re-bound (updater handleRefMount) will be called because it looks like
            the ref changes. That's just how React works. The SilentUpdate fixes this. However, on every
            subsequent render (for whatever reason), the ref will be rebound and it will invoke the new one
            again - as long as we handle the ref with a silent update it should be fine (it won't trigger)
            infinite loop updates etc.
          |}
        | Some _theReference => "There was a ref at render time"
        };
      <div ref=(update handleRefMount)> (ReasonReact.stringToElement text) </div>
    }
  };
};

let _ =
  ignore (
    SideEffecterCorrect.make outerCallback::ReasonReact.Callback.default outerStateAsProp::0 [||]
  );

let createFilenameDiv filename =>
  {|
    <div style="position: absolute;"><div class="fileName" > |} ^
  filename ^ {| </div></div>
  |};

module GalleryItem = {
  let component = ReasonReact.createComponent "GalleryItem";
  let make ::filename="file.re" ::title="Untitled" ::description="no description" children => {
    let _filename = createFilenameDiv filename;
    let title = <div className="header"> (ReasonReact.stringToElement title) </div>;
    let description =
      <div className="headerSubtext" dangerouslySetInnerHTML={"__html": description} />;
    let leftRight =
      <div className="galleryItemDemo leftRightContainer">
        <div className="right interactionContainer"> (ReasonReact.arrayToElement children) </div>
      </div>;
    {
      ...component,
      render: fun _state _self => <div className="galleryItem"> title description leftRight </div>
    }
  };
};

module GalleryContainer = {
  let component = ReasonReact.createComponent "GalleryContainer";
  let megaHeaderTitle = "Reason React";
  let megaHeaderSubtext = {|
    First Class React.
  |};
  let megaHeaderSubtextDetails = {|
    Reason React is a safer, simpler way to build React components. It models
    React components using language level features to create a more expressive
    API, within a smaller surface area.

    Reason React binds directly to ReactJS giving you full access to the entire
    React ecosystem, for web and native applications, so you can adopt
    incrementally.

  |};
  let make children => {
    ...component,
    render: fun _state _self =>
      <div className="mainGallery">
        <div key="megaHeader" className="megaHeader"> (ReasonReact.stringToElement megaHeaderTitle) </div>
        <div key="degaHeaderSubtext" className="megaHeaderSubtext">
          (ReasonReact.stringToElement megaHeaderSubtext)
        </div>
        <div key="headerSubtext" className="megaHeaderSubtextDetails">
          (ReasonReact.stringToElement megaHeaderSubtextDetails)
        </div>
        (ReasonReact.arrayToElement children)
      </div>
  };
};

module ComponentGallery = {
  let component = ReasonReact.createComponent "ComponentGallery";
  let make _children => {
    let buttonGalleryItem =
      ReasonReact.element
        key::"button"
        (
          GalleryItem.make
            filename::"button.re"
            title::"A Simple Button"
            description::{| |}
            [|ReasonReact.element (ButtonExample.make [||])|]
        );
    let statefulButtonGalleryItem =
      ReasonReact.element
        key::"statefulButton"
        (
          GalleryItem.make
            filename::"statefulButton.re"
            title::"Stateful Functional Components"
            description::{| |}
            [|ReasonReact.element (StatefulButtonExample.make [||])|]
        );
    let cascadingUpdates =
      ReasonReact.element
        key::"cascadingUpdates"
        (
          GalleryItem.make
            title::"Cascading Updates"
            filename::"cascading.re"
            description::{| |}
            [|ReasonReact.element (CascadingUpdatesExample.make [||])|]
        );
    let multipleStateUpdatesPerEvent =
      ReasonReact.element
        key::"multipleStateUpdatesPerEvent"
        (
          GalleryItem.make
            title::"Multiple State Updates In One Event Loop"
            description::{|
              This demonstrates the order that ReasonReact+React will call your
                event handlers, and supply your events when using .update().
                This maps closely to regular event handlers in React that call
                `setState` without using the callback form.  Notice that just
                like with ReactJS and non-callback form of setState, two event
                handlers cannot see each other's state updates in the same
                event loop because they're not using the callback form of
                setState. That's why this example only increments by 3, whereas
                the next example increments by 6.
            |}
            [|ReasonReact.element (MultipleStateUpdatesPerEvent.make prop::3 [||])|]
        );
    let multipleStateUpdatesPerEventQueued =
      ReasonReact.element
        key::"multipleStateUpdatesPerEventQueued"
        (
          GalleryItem.make
            title::"Multiple State Updates In One Event Loop (Queued)"
            description::{|
              This demonstrates the order that ReasonReact+React will call your
                event handlers, and supply your events when using .queue().
                This maps more closely to the ReactJS pattern of attaching an
                event handler, doing what you like with the event, and then
                afterwards, invoking setState and passing setState a callback.
                Notice the ordering is drastically different than
                MultipleStateUpdatesPerEvent.
            |}
            [|ReasonReact.element (MultipleStateUpdatesPerEventQueued.make prop::3 [||])|]
        );
    let silentUpdater =
      ReasonReact.element
        key::"two"
        (
          GalleryItem.make
            title::"Silent enqueue Example"
            description::{| |}
            [|ReasonReact.element (SilentUpdater.make [||])|]
        );
    let callbacks =
      ReasonReact.element
        key::"callbacks" (GalleryItem.make title::"Callbacks in Props" description::"" [||]);
    let lifecycles =
      ReasonReact.element
        key::"lifecycles"
        (GalleryItem.make title::"Various Lifecycles Hooks" description::"" [||]);
    let lifecycleLogger =
      ReasonReact.element
        key::"three"
        (
          GalleryItem.make
            title::"Updates On Mount"
            description::"Demonstrates updating a component's state on mount."
            [|ReasonReact.element (LifecycleLogger.make [||])|]
        );
    let receiveProps =
      ReasonReact.element
        key::"receiveProps"
        (
          GalleryItem.make
            title::"Receiving Props Updating State"
            description::"Demonstrates receiving props in order to alter state."
            [|ReasonReact.element (ReceivePropsExample.make [||])|]
        );
    let sideEffectsAndChaining =
      ReasonReact.element
        key::"enqueue chaining and side effects"
        (
          GalleryItem.make
            title::"Performing side effects and chaining"
            description::"Demonstrates when side effects occur, and how it plays with chaining"
            [|ReasonReact.element (SideEffecterExample.make [||])|]
        );
    let childRouting =
      ReasonReact.element
        key::"child routing"
        (
          GalleryItem.make
            title::"Routing Children"
            description::"Demonstrates how components may route children into their rendered output"
            [|ReasonReact.element (ChildRouting.make [|sideEffectsAndChaining|])|]
        );
    let refHaver =
      ReasonReact.element
        key::"refExample"
        (
          GalleryItem.make
            filename::"button.re"
            title::"Refs"
            description::{|This is how you use references.|}
            [|ReasonReact.element (RefHaver.make [||])|]
        );
    {
      ...component,
      render: fun _state _self =>
        ReasonReact.element (
          GalleryContainer.make [|
            buttonGalleryItem,
            statefulButtonGalleryItem,
            cascadingUpdates,
            multipleStateUpdatesPerEvent,
            multipleStateUpdatesPerEventQueued,
            callbacks,
            silentUpdater,
            lifecycles,
            lifecycleLogger,
            receiveProps,
            sideEffectsAndChaining,
            childRouting,
            refHaver
          |]
        )
    }
  };
};
