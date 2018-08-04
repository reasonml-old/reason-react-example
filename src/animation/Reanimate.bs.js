'use strict';

var Demo = require("./Demo.bs.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Random = require("bs-platform/lib/js/random.js");
var Spring = require("./Spring.bs.js");
var Animation = require("./Animation.bs.js");
var Belt_List = require("bs-platform/lib/js/belt_List.js");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Caml_int32 = require("bs-platform/lib/js/caml_int32.js");
var Pervasives = require("bs-platform/lib/js/pervasives.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var RemoteAction = require("./RemoteAction.bs.js");
var SpringAnimation = require("./SpringAnimation.bs.js");
var Caml_builtin_exceptions = require("bs-platform/lib/js/caml_builtin_exceptions.js");

function pxI(i) {
  return String(i) + "px";
}

function pxF(v) {
  return String(v | 0) + "px";
}

var counter = /* record */[/* contents */0];

function gen() {
  counter[0] = counter[0] + 1 | 0;
  return String(counter[0]);
}

var Key = /* module */[
  /* counter */counter,
  /* gen */gen
];

var displayHeightString = String(200) + "px";

var sizes = /* array */[
  /* tuple */[
    500,
    350
  ],
  /* tuple */[
    800,
    600
  ],
  /* tuple */[
    800,
    400
  ],
  /* tuple */[
    700,
    500
  ],
  /* tuple */[
    200,
    650
  ],
  /* tuple */[
    600,
    600
  ]
];

var displayWidths = Belt_Array.map(sizes, (function (param) {
        return Caml_int32.div(Caml_int32.imul(param[0], 200), param[1]);
      }));

function getWidth(i) {
  return Caml_array.caml_array_get(displayWidths, (i + 6 | 0) % 6);
}

function interpolate(width1, width2, phase) {
  var width1$1 = width1;
  var width2$1 = width2;
  var width = width1$1 * (1 - phase) + width2$1 * phase;
  var left1 = -(width1$1 * phase);
  var left2 = left1 + width1$1;
  return /* tuple */[
          String(width | 0) + "px",
          String(left1 | 0) + "px",
          String(left2 | 0) + "px"
        ];
}

function renderImage(left, i) {
  return React.createElement("img", {
              className: "photo-inner",
              style: {
                height: displayHeightString,
                left: left
              },
              src: "./" + (String((i + 6 | 0) % 6) + ".jpg")
            });
}

function render(phase, image1, image2) {
  var width1 = getWidth(image1);
  var width2 = getWidth(image2);
  var match = interpolate(width1, width2, phase);
  return React.createElement("div", undefined, React.createElement("div", {
                  className: "photo-outer",
                  style: {
                    height: displayHeightString,
                    width: match[0]
                  }
                }, renderImage(match[1], image1), renderImage(match[2], image2)));
}

var ImageTransition = /* module */[
  /* render */render,
  /* displayHeight */200
];

var component = ReasonReact.reducerComponent("ImagesExample");

function make($staropt$star, $staropt$star$1, _) {
  var initialImage = $staropt$star !== undefined ? $staropt$star : 0;
  var animateMount = $staropt$star$1 !== undefined ? $staropt$star$1 : true;
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */(function (param) {
              var send = param[/* send */3];
              var arg = function (cursor) {
                return Curry._1(send, /* SetCursor */[cursor]);
              };
              Curry._2((function (param, param$1, param$2) {
                        return Curry._5(SpringAnimation.setOnChange, param, param$1, 0.05, param$2, arg);
                      })(undefined, undefined, undefined), undefined, param[/* state */1][/* animation */0]);
              if (animateMount) {
                return Curry._1(send, /* Click */0);
              } else {
                return 0;
              }
            }),
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */(function (param) {
              return SpringAnimation.stop(param[/* state */1][/* animation */0]);
            }),
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (param) {
              var send = param[/* send */3];
              var cursor = param[/* state */1][/* cursor */1];
              var image = cursor | 0;
              var phase = cursor - image;
              return React.createElement("div", {
                          onClick: (function () {
                              return Curry._1(send, /* Click */0);
                            })
                        }, render(phase, image, image + 1 | 0));
            }),
          /* initialState */(function () {
              return /* record */[
                      /* animation */SpringAnimation.create(initialImage),
                      /* cursor */initialImage,
                      /* targetImage */initialImage
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (action) {
                return /* Update */Block.__(0, [/* record */[
                            /* animation */state[/* animation */0],
                            /* cursor */action[0],
                            /* targetImage */state[/* targetImage */2]
                          ]]);
              } else {
                return /* UpdateWithSideEffects */Block.__(2, [
                          /* record */[
                            /* animation */state[/* animation */0],
                            /* cursor */state[/* cursor */1],
                            /* targetImage */state[/* targetImage */2] + 1 | 0
                          ],
                          (function (param) {
                              var match = param[/* state */1];
                              return SpringAnimation.setFinalValue(match[/* targetImage */2], match[/* animation */0]);
                            })
                        ]);
              }
            }),
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

var ImageGalleryAnimation = /* module */[
  /* component */component,
  /* make */make
];

var component$1 = ReasonReact.statelessComponent("Text");

function make$1(text, _) {
  return /* record */[
          /* debugName */component$1[/* debugName */0],
          /* reactClassInternal */component$1[/* reactClassInternal */1],
          /* handedOffState */component$1[/* handedOffState */2],
          /* willReceiveProps */component$1[/* willReceiveProps */3],
          /* didMount */component$1[/* didMount */4],
          /* didUpdate */component$1[/* didUpdate */5],
          /* willUnmount */component$1[/* willUnmount */6],
          /* willUpdate */component$1[/* willUpdate */7],
          /* shouldUpdate */component$1[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("button", undefined, text);
            }),
          /* initialState */component$1[/* initialState */10],
          /* retainedProps */component$1[/* retainedProps */11],
          /* reducer */component$1[/* reducer */12],
          /* subscriptions */component$1[/* subscriptions */13],
          /* jsElementWrapped */component$1[/* jsElementWrapped */14]
        ];
}

var Text = /* module */[
  /* component */component$1,
  /* make */make$1
];

var component$2 = ReasonReact.reducerComponent("ButtonAnimation");

function make$2($staropt$star, rAction, $staropt$star$1, onClose, _) {
  var text = $staropt$star !== undefined ? $staropt$star : "Button";
  var animateMount = $staropt$star$1 !== undefined ? $staropt$star$1 : true;
  return /* record */[
          /* debugName */component$2[/* debugName */0],
          /* reactClassInternal */component$2[/* reactClassInternal */1],
          /* handedOffState */component$2[/* handedOffState */2],
          /* willReceiveProps */component$2[/* willReceiveProps */3],
          /* didMount */(function (param) {
              var send = param[/* send */3];
              RemoteAction.subscribe(send, rAction);
              if (animateMount) {
                return Curry._1(send, /* ToggleSize */3);
              } else {
                return 0;
              }
            }),
          /* didUpdate */component$2[/* didUpdate */5],
          /* willUnmount */(function (param) {
              return SpringAnimation.stop(param[/* state */1][/* animation */0]);
            }),
          /* willUpdate */component$2[/* willUpdate */7],
          /* shouldUpdate */component$2[/* shouldUpdate */8],
          /* render */(function (param) {
              var send = param[/* send */3];
              var state = param[/* state */1];
              var buttonLabel = function (state) {
                return text + (" clicks:" + (String(state[/* clickCount */3]) + (" actions:" + String(state[/* actionCount */4]))));
              };
              return React.createElement("div", {
                          className: "exampleButton large",
                          style: {
                            width: String(state[/* width */1]) + "px"
                          },
                          onClick: (function () {
                              return Curry._1(send, /* Click */0);
                            })
                        }, ReasonReact.element(undefined, undefined, make$1(buttonLabel(state), /* array */[])));
            }),
          /* initialState */(function () {
              return /* record */[
                      /* animation */SpringAnimation.create(250),
                      /* width */250,
                      /* size : Small */0,
                      /* clickCount */0,
                      /* actionCount */0
                    ];
            }),
          /* retainedProps */component$2[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (typeof action === "number") {
                switch (action) {
                  case 0 : 
                      return /* UpdateWithSideEffects */Block.__(2, [
                                /* record */[
                                  /* animation */state[/* animation */0],
                                  /* width */state[/* width */1],
                                  /* size */state[/* size */2],
                                  /* clickCount */state[/* clickCount */3] + 1 | 0,
                                  /* actionCount */state[/* actionCount */4] + 1 | 0
                                ],
                                (function (param) {
                                    return Curry._1(param[/* send */3], /* ToggleSize */3);
                                  })
                              ]);
                  case 1 : 
                      return /* Update */Block.__(0, [/* record */[
                                  /* animation */state[/* animation */0],
                                  /* width */state[/* width */1],
                                  /* size */state[/* size */2],
                                  /* clickCount */0,
                                  /* actionCount */state[/* actionCount */4] + 1 | 0
                                ]]);
                  case 2 : 
                      return /* Update */Block.__(0, [/* record */[
                                  /* animation */state[/* animation */0],
                                  /* width */state[/* width */1],
                                  /* size */state[/* size */2],
                                  /* clickCount */state[/* clickCount */3] - 1 | 0,
                                  /* actionCount */state[/* actionCount */4] + 1 | 0
                                ]]);
                  case 3 : 
                      var match = state[/* size */2] === /* Small */0;
                      return /* UpdateWithSideEffects */Block.__(2, [
                                /* record */[
                                  /* animation */state[/* animation */0],
                                  /* width */state[/* width */1],
                                  /* size */match ? /* Large */1 : /* Small */0,
                                  /* clickCount */state[/* clickCount */3],
                                  /* actionCount */state[/* actionCount */4]
                                ],
                                (function (param) {
                                    var send = param[/* send */3];
                                    var match = param[/* state */1];
                                    var arg = function (w) {
                                      return Curry._1(send, /* Width */[w | 0]);
                                    };
                                    var match$1 = match[/* size */2] === /* Small */0;
                                    var arg$1 = match$1 ? 250 : 450;
                                    var arg$2 = function (param, param$1, param$2) {
                                      return Curry._6(SpringAnimation.setOnChange, param, param$1, 10, param$2, arg, arg$1);
                                    };
                                    return (function (eta) {
                                                return Curry._1(arg$2(undefined, undefined, undefined), eta);
                                              })(match[/* animation */0]);
                                  })
                              ]);
                  case 4 : 
                      return /* SideEffects */Block.__(1, [(function (param) {
                                    var send = param[/* send */3];
                                    var arg = Js_primitive.some(onClose);
                                    var arg$1 = function (w) {
                                      return Curry._1(send, /* Width */[w | 0]);
                                    };
                                    var arg$2 = 50;
                                    return Curry._1((function (param) {
                                                    return Curry._6(SpringAnimation.setOnChange, param, 0.3, 10, arg, arg$1, arg$2);
                                                  })(undefined), param[/* state */1][/* animation */0]);
                                  })]);
                  
                }
              } else {
                return /* Update */Block.__(0, [/* record */[
                            /* animation */state[/* animation */0],
                            /* width */action[0],
                            /* size */state[/* size */2],
                            /* clickCount */state[/* clickCount */3],
                            /* actionCount */state[/* actionCount */4]
                          ]]);
              }
            }),
          /* subscriptions */component$2[/* subscriptions */13],
          /* jsElementWrapped */component$2[/* jsElementWrapped */14]
        ];
}

var AnimatedButton = /* module */[
  /* Text */Text,
  /* targetHeight */30,
  /* closeWidth */50,
  /* smallWidth */250,
  /* largeWidth */450,
  /* component */component$2,
  /* make */make$2
];

var component$3 = ReasonReact.reducerComponent("HeightAnim");

function make$3(rAction, targetHeight, children) {
  return /* record */[
          /* debugName */component$3[/* debugName */0],
          /* reactClassInternal */component$3[/* reactClassInternal */1],
          /* handedOffState */component$3[/* handedOffState */2],
          /* willReceiveProps */component$3[/* willReceiveProps */3],
          /* didMount */(function (param) {
              var send = param[/* send */3];
              RemoteAction.subscribe(send, rAction);
              return Curry._1(send, /* Animate */Block.__(3, [
                            targetHeight,
                            undefined
                          ]));
            }),
          /* didUpdate */component$3[/* didUpdate */5],
          /* willUnmount */(function (param) {
              return SpringAnimation.stop(param[/* state */1][/* animation */1]);
            }),
          /* willUpdate */component$3[/* willUpdate */7],
          /* shouldUpdate */component$3[/* shouldUpdate */8],
          /* render */(function (param) {
              return React.createElement("div", {
                          style: {
                            height: String(param[/* state */1][/* height */0] | 0) + "px",
                            overflow: "hidden"
                          }
                        }, children);
            }),
          /* initialState */(function () {
              return /* record */[
                      /* height */0,
                      /* animation */SpringAnimation.create(0)
                    ];
            }),
          /* retainedProps */component$3[/* retainedProps */11],
          /* reducer */(function (action, state) {
              switch (action.tag | 0) {
                case 0 : 
                    var onOpen = action[0];
                    return /* SideEffects */Block.__(1, [(function (param) {
                                  return Curry._1(param[/* send */3], /* Animate */Block.__(3, [
                                                targetHeight,
                                                onOpen
                                              ]));
                                })]);
                case 1 : 
                    var onClose = action[1];
                    var onBeginClosing = action[0];
                    return /* SideEffects */Block.__(1, [(function (param) {
                                  if (onBeginClosing !== undefined) {
                                    Curry._1(onBeginClosing, /* () */0);
                                  }
                                  return Curry._1(param[/* send */3], /* Animate */Block.__(3, [
                                                0,
                                                onClose
                                              ]));
                                })]);
                case 2 : 
                    var onClose$1 = action[0];
                    return /* SideEffects */Block.__(1, [(function (param) {
                                  return Curry._1(param[/* send */3], /* Animate */Block.__(3, [
                                                0,
                                                onClose$1
                                              ]));
                                })]);
                case 3 : 
                    var onStop = action[1];
                    var finalValue = action[0];
                    return /* SideEffects */Block.__(1, [(function (param) {
                                  var send = param[/* send */3];
                                  var arg = Js_primitive.some(onStop);
                                  var arg$1 = function (h) {
                                    return Curry._1(send, /* Height */Block.__(4, [h]));
                                  };
                                  var arg$2 = finalValue;
                                  return Curry._1((function (param, param$1) {
                                                  return Curry._6(SpringAnimation.setOnChange, param, param$1, 10, arg, arg$1, arg$2);
                                                })(undefined, undefined), state[/* animation */1]);
                                })]);
                case 4 : 
                    return /* Update */Block.__(0, [/* record */[
                                /* height */action[0],
                                /* animation */state[/* animation */1]
                              ]]);
                
              }
            }),
          /* subscriptions */component$3[/* subscriptions */13],
          /* jsElementWrapped */component$3[/* jsElementWrapped */14]
        ];
}

var AnimateHeight = /* module */[
  /* component */component$3,
  /* make */make$3
];

function initial() {
  return /* record */[
          /* act */(function () {
              return /* () */0;
            }),
          /* randomAnimation */Animation.create(/* () */0),
          /* items : [] */0
        ];
}

function getElements(param) {
  return Belt_List.toArray(Belt_List.mapReverse(param[/* items */2], (function (x) {
                    return x[/* element */0];
                  })));
}

function createButton(removeFromList, animateMount, number) {
  var rActionButton = RemoteAction.create(/* () */0);
  var rActionHeight = RemoteAction.create(/* () */0);
  var key = gen(/* () */0);
  var onClose = function () {
    return RemoteAction.send(rActionHeight, /* Close */Block.__(2, [(function () {
                      return Curry._1(removeFromList, rActionHeight);
                    })]));
  };
  var element = ReasonReact.element(key, undefined, make$3(rActionHeight, 30, /* array */[ReasonReact.element(key, undefined, make$2("Button#" + String(number), rActionButton, animateMount, onClose, /* array */[]))]));
  return /* record */[
          /* element */element,
          /* rActionButton */rActionButton,
          /* rActionHeight */rActionHeight,
          /* closing */false
        ];
}

function createImage(animateMount, number) {
  var key = gen(/* () */0);
  var rActionButton = RemoteAction.create(/* () */0);
  var imageGalleryAnimation = ReasonReact.element(gen(/* () */0), undefined, make(number, animateMount, /* array */[]));
  var rActionHeight = RemoteAction.create(/* () */0);
  var element = ReasonReact.element(key, undefined, make$3(rActionHeight, 200, /* array */[imageGalleryAnimation]));
  return /* record */[
          /* element */element,
          /* rActionButton */rActionButton,
          /* rActionHeight */rActionHeight,
          /* closing */false
        ];
}

var State = /* module */[
  /* createButton */createButton,
  /* createImage */createImage,
  /* getElements */getElements,
  /* initial */initial
];

function runAll(action) {
  var performSideEffects = function (param) {
    return Belt_List.forEach(param[/* state */1][/* items */2], (function (param) {
                  return RemoteAction.send(param[/* rActionButton */1], action);
                }));
  };
  return /* SideEffects */Block.__(1, [performSideEffects]);
}

var component$4 = ReasonReact.reducerComponent("ReducerAnimationExample");

function make$4(showAllButtons, _) {
  return /* record */[
          /* debugName */component$4[/* debugName */0],
          /* reactClassInternal */component$4[/* reactClassInternal */1],
          /* handedOffState */component$4[/* handedOffState */2],
          /* willReceiveProps */component$4[/* willReceiveProps */3],
          /* didMount */(function (param) {
              var send = param[/* send */3];
              var callback = function () {
                var match = Random.$$int(6);
                var randomAction;
                if (match > 5 || match < 0) {
                  throw [
                        Caml_builtin_exceptions.assert_failure,
                        /* tuple */[
                          "Reanimate.re",
                          424,
                          19
                        ]
                      ];
                } else {
                  switch (match) {
                    case 0 : 
                        randomAction = /* AddButton */Block.__(1, [true]);
                        break;
                    case 1 : 
                        randomAction = /* AddImage */Block.__(3, [true]);
                        break;
                    case 2 : 
                    case 3 : 
                        randomAction = /* RemoveItem */4;
                        break;
                    case 4 : 
                        randomAction = /* DecrementAllButtons */1;
                        break;
                    case 5 : 
                        randomAction = /* IncrementAllButtons */2;
                        break;
                    
                  }
                }
                Curry._1(send, randomAction);
                return /* Continue */0;
              };
              Curry._1(send, /* SetAct */Block.__(0, [send]));
              return Animation.setCallback(param[/* state */1][/* randomAnimation */1], callback);
            }),
          /* didUpdate */component$4[/* didUpdate */5],
          /* willUnmount */(function (param) {
              return Animation.stop(param[/* state */1][/* randomAnimation */1]);
            }),
          /* willUpdate */component$4[/* willUpdate */7],
          /* shouldUpdate */component$4[/* shouldUpdate */8],
          /* render */(function (param) {
              var state = param[/* state */1];
              var button = function ($staropt$star, $staropt$star$1, txt, action) {
                var repeat = $staropt$star !== undefined ? $staropt$star : 1;
                var hide = $staropt$star$1 !== undefined ? $staropt$star$1 : false;
                if (hide) {
                  return null;
                } else {
                  return React.createElement("div", {
                              className: "exampleButton large",
                              style: {
                                width: "220px"
                              },
                              onClick: (function () {
                                  for(var _for = 1; _for <= repeat; ++_for){
                                    Curry._1(state[/* act */0], action);
                                  }
                                  return /* () */0;
                                })
                            }, txt);
                }
              };
              var hide = !showAllButtons;
              var match = Animation.isActive(state[/* randomAnimation */1]);
              return React.createElement("div", {
                          className: "componentBox"
                        }, React.createElement("div", {
                              className: "componentColumn"
                            }, "Control:", button(undefined, undefined, "Add Button", /* AddButton */Block.__(1, [true])), button(undefined, undefined, "Add Image", /* AddImage */Block.__(3, [true])), button(undefined, undefined, "Add Button On Top", /* AddButtonFirst */Block.__(2, [true])), button(undefined, undefined, "Remove Item", /* RemoveItem */4), button(100, hide, "Add 100 Buttons On Top", /* AddButtonFirst */Block.__(2, [false])), button(100, hide, "Add 100 Images", /* AddImage */Block.__(3, [false])), button(undefined, undefined, "Click all the Buttons", /* IncrementAllButtons */2), button(undefined, hide, "Unclick all the Buttons", /* DecrementAllButtons */1), button(undefined, undefined, "Close all the Buttons", /* CloseAllButtons */3), button(10, hide, "Click all the Buttons 10 times", /* IncrementAllButtons */2), button(undefined, hide, "Reset all the Buttons' states", /* ResetAllButtons */5), button(undefined, undefined, "Reverse Items", /* ReverseItemsAnimation */6), button(undefined, undefined, "Random Animation " + (
                                  match ? "ON" : "OFF"
                                ), /* ToggleRandomAnimation */7), button(undefined, undefined, "Add Self", /* AddSelf */0)), React.createElement("div", {
                              className: "componentColumn",
                              style: {
                                width: "500px"
                              }
                            }, React.createElement("div", undefined, "Items:" + String(Belt_List.length(state[/* items */2]))), getElements(state)));
            }),
          /* initialState */(function () {
              return initial(/* () */0);
            }),
          /* retainedProps */component$4[/* retainedProps */11],
          /* reducer */(function (action, state) {
              var items = state[/* items */2];
              var randomAnimation = state[/* randomAnimation */1];
              var act = state[/* act */0];
              if (typeof action === "number") {
                switch (action) {
                  case 0 : 
                      var key = gen(/* () */0);
                      var rActionButton = RemoteAction.create(/* () */0);
                      var rActionHeight = RemoteAction.create(/* () */0);
                      var element = ReasonReact.element(key, undefined, make$3(rActionHeight, 500, /* array */[ReasonReact.element(key, undefined, make$4(showAllButtons, /* array */[]))]));
                      var item = /* record */[
                        /* element */element,
                        /* rActionButton */rActionButton,
                        /* rActionHeight */rActionHeight,
                        /* closing */false
                      ];
                      return /* Update */Block.__(0, [/* record */[
                                  /* act */state[/* act */0],
                                  /* randomAnimation */state[/* randomAnimation */1],
                                  /* items : :: */[
                                    item,
                                    items
                                  ]
                                ]]);
                  case 1 : 
                      return runAll(/* Unclick */2);
                  case 2 : 
                      return runAll(/* Click */0);
                  case 3 : 
                      return runAll(/* Close */4);
                  case 4 : 
                      var match = Belt_List.getBy(items, (function (item) {
                              return item[/* closing */3] === false;
                            }));
                      if (match !== undefined) {
                        var firstItemNotClosing = match;
                        var onBeginClosing = (function () {
                            firstItemNotClosing[/* closing */3] = true;
                            return /* () */0;
                          });
                        var onClose = (function () {
                            return Curry._1(act, /* FilterOutItem */Block.__(4, [firstItemNotClosing[/* rActionHeight */2]]));
                          });
                        return /* SideEffects */Block.__(1, [(function () {
                                      return RemoteAction.send(firstItemNotClosing[/* rActionHeight */2], /* BeginClosing */Block.__(1, [
                                                    onBeginClosing,
                                                    onClose
                                                  ]));
                                    })]);
                      } else {
                        return /* NoUpdate */0;
                      }
                  case 5 : 
                      return runAll(/* Reset */1);
                  case 6 : 
                      var onStopClose = function () {
                        return Curry._1(act, /* ReverseWithSideEffects */Block.__(6, [(function () {
                                          return Curry._1(act, /* OpenHeight */Block.__(7, [undefined]));
                                        })]));
                      };
                      return /* SideEffects */Block.__(1, [(function () {
                                    return Curry._1(act, /* CloseHeight */Block.__(5, [onStopClose]));
                                  })]);
                  case 7 : 
                      return /* SideEffects */Block.__(1, [(function () {
                                    var match = Animation.isActive(randomAnimation);
                                    if (match) {
                                      return Animation.stop(randomAnimation);
                                    } else {
                                      return Animation.start(randomAnimation);
                                    }
                                  })]);
                  
                }
              } else {
                switch (action.tag | 0) {
                  case 0 : 
                      return /* Update */Block.__(0, [/* record */[
                                  /* act */action[0],
                                  /* randomAnimation */state[/* randomAnimation */1],
                                  /* items */state[/* items */2]
                                ]]);
                  case 1 : 
                      var removeFromList = function (rActionHeight) {
                        return Curry._1(act, /* FilterOutItem */Block.__(4, [rActionHeight]));
                      };
                      return /* Update */Block.__(0, [/* record */[
                                  /* act */state[/* act */0],
                                  /* randomAnimation */state[/* randomAnimation */1],
                                  /* items : :: */[
                                    createButton(removeFromList, action[0], Belt_List.length(items)),
                                    items
                                  ]
                                ]]);
                  case 2 : 
                      var removeFromList$1 = function (rActionHeight) {
                        return Curry._1(act, /* FilterOutItem */Block.__(4, [rActionHeight]));
                      };
                      return /* Update */Block.__(0, [/* record */[
                                  /* act */state[/* act */0],
                                  /* randomAnimation */state[/* randomAnimation */1],
                                  /* items */Pervasives.$at(items, /* :: */[
                                        createButton(removeFromList$1, action[0], Belt_List.length(items)),
                                        /* [] */0
                                      ])
                                ]]);
                  case 3 : 
                      return /* Update */Block.__(0, [/* record */[
                                  /* act */state[/* act */0],
                                  /* randomAnimation */state[/* randomAnimation */1],
                                  /* items : :: */[
                                    createImage(action[0], Belt_List.length(items)),
                                    items
                                  ]
                                ]]);
                  case 4 : 
                      var rAction = action[0];
                      var filter = function (item) {
                        return item[/* rActionHeight */2] !== rAction;
                      };
                      return /* Update */Block.__(0, [/* record */[
                                  /* act */state[/* act */0],
                                  /* randomAnimation */state[/* randomAnimation */1],
                                  /* items */Belt_List.keep(items, filter)
                                ]]);
                  case 5 : 
                      var onStop = action[0];
                      var len = Belt_List.length(items);
                      var count = /* record */[/* contents */len];
                      var onClose$1 = function () {
                        count[0] = count[0] - 1 | 0;
                        if (count[0] === 0 && onStop !== undefined) {
                          return Curry._1(onStop, /* () */0);
                        } else {
                          return 0;
                        }
                      };
                      var iter = function () {
                        return Belt_List.forEach(items, (function (item) {
                                      return RemoteAction.send(item[/* rActionHeight */2], /* Close */Block.__(2, [onClose$1]));
                                    }));
                      };
                      return /* SideEffects */Block.__(1, [iter]);
                  case 6 : 
                      var performSideEffects = action[0];
                      return /* UpdateWithSideEffects */Block.__(2, [
                                /* record */[
                                  /* act */state[/* act */0],
                                  /* randomAnimation */state[/* randomAnimation */1],
                                  /* items */Belt_List.reverse(items)
                                ],
                                (function () {
                                    return Curry._1(performSideEffects, /* () */0);
                                  })
                              ]);
                  case 7 : 
                      var onStop$1 = action[0];
                      var len$1 = Belt_List.length(items);
                      var count$1 = /* record */[/* contents */len$1];
                      var onClose$2 = function () {
                        count$1[0] = count$1[0] - 1 | 0;
                        if (count$1[0] === 0 && onStop$1 !== undefined) {
                          return Curry._1(onStop$1, /* () */0);
                        } else {
                          return 0;
                        }
                      };
                      var iter$1 = function () {
                        return Belt_List.forEach(items, (function (item) {
                                      return RemoteAction.send(item[/* rActionHeight */2], /* Open */Block.__(0, [onClose$2]));
                                    }));
                      };
                      return /* SideEffects */Block.__(1, [iter$1]);
                  
                }
              }
            }),
          /* subscriptions */component$4[/* subscriptions */13],
          /* jsElementWrapped */component$4[/* jsElementWrapped */14]
        ];
}

var ReducerAnimationExample = /* module */[
  /* State */State,
  /* runAll */runAll,
  /* component */component$4,
  /* make */make$4
];

var component$5 = ReasonReact.reducerComponent("ChatHead");

function make$5(rAction, headNum, imageGallery, _) {
  return /* record */[
          /* debugName */component$5[/* debugName */0],
          /* reactClassInternal */component$5[/* reactClassInternal */1],
          /* handedOffState */component$5[/* handedOffState */2],
          /* willReceiveProps */component$5[/* willReceiveProps */3],
          /* didMount */(function (param) {
              RemoteAction.subscribe(param[/* send */3], rAction);
              return /* () */0;
            }),
          /* didUpdate */component$5[/* didUpdate */5],
          /* willUnmount */component$5[/* willUnmount */6],
          /* willUpdate */component$5[/* willUpdate */7],
          /* shouldUpdate */component$5[/* shouldUpdate */8],
          /* render */(function (param) {
              var match = param[/* state */1];
              var left = String(match[/* x */0] - 25 | 0) + "px";
              var top = String(match[/* y */1] - 25 | 0) + "px";
              if (imageGallery) {
                return React.createElement("div", {
                            className: "chat-head-image-gallery",
                            style: {
                              left: left,
                              top: top,
                              zIndex: String(-headNum | 0)
                            }
                          }, ReasonReact.element(undefined, undefined, make(headNum, undefined, /* array */[])));
              } else {
                return React.createElement("div", {
                            className: "chat-head chat-head-" + String(headNum % 6),
                            style: {
                              left: left,
                              top: top,
                              zIndex: String(-headNum | 0)
                            }
                          });
              }
            }),
          /* initialState */(function () {
              return /* record */[
                      /* x */0,
                      /* y */0
                    ];
            }),
          /* retainedProps */component$5[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (action.tag) {
                return /* Update */Block.__(0, [/* record */[
                            /* x */state[/* x */0],
                            /* y */action[0]
                          ]]);
              } else {
                return /* Update */Block.__(0, [/* record */[
                            /* x */action[0],
                            /* y */state[/* y */1]
                          ]]);
              }
            }),
          /* subscriptions */component$5[/* subscriptions */13],
          /* jsElementWrapped */component$5[/* jsElementWrapped */14]
        ];
}

var ChatHead = /* module */[
  /* component */component$5,
  /* make */make$5
];

function createControl() {
  return /* record */[
          /* rAction */RemoteAction.create(/* () */0),
          /* animX */SpringAnimation.create(0),
          /* animY */SpringAnimation.create(0)
        ];
}

var component$6 = ReasonReact.reducerComponent("ChatHeadsExample");

function make$6(imageGallery, _) {
  return /* record */[
          /* debugName */component$6[/* debugName */0],
          /* reactClassInternal */component$6[/* reactClassInternal */1],
          /* handedOffState */component$6[/* handedOffState */2],
          /* willReceiveProps */component$6[/* willReceiveProps */3],
          /* didMount */(function (param) {
              var controls = param[/* state */1][/* controls */0];
              Belt_Array.forEachWithIndex(controls, (function (i, _) {
                      var headNum = i;
                      var setOnChange = function (isX, afterChange) {
                        var control = Caml_array.caml_array_get(controls, headNum);
                        var arg = function (v) {
                          RemoteAction.send(control[/* rAction */0], isX ? /* MoveX */Block.__(0, [v]) : /* MoveY */Block.__(1, [v]));
                          return Curry._1(afterChange, v);
                        };
                        var arg$1 = function (param, param$1) {
                          return Curry._5(SpringAnimation.setOnChange, Spring.gentle, 2, param, param$1, arg);
                        };
                        return (function (eta) {
                                    return Curry._2(arg$1(undefined, undefined), undefined, eta);
                                  })(isX ? control[/* animX */1] : control[/* animY */2]);
                      };
                      var isLastHead = headNum === 5;
                      var afterChangeX = function (x) {
                        if (isLastHead) {
                          return /* () */0;
                        } else {
                          return SpringAnimation.setFinalValue(x, Caml_array.caml_array_get(controls, headNum + 1 | 0)[/* animX */1]);
                        }
                      };
                      var afterChangeY = function (y) {
                        if (isLastHead) {
                          return /* () */0;
                        } else {
                          return SpringAnimation.setFinalValue(y, Caml_array.caml_array_get(controls, headNum + 1 | 0)[/* animY */2]);
                        }
                      };
                      setOnChange(true, afterChangeX);
                      return setOnChange(false, afterChangeY);
                    }));
              var onMove = function (e) {
                var x = e.pageX;
                var y = e.pageY;
                SpringAnimation.setFinalValue(x, Caml_array.caml_array_get(controls, 0)[/* animX */1]);
                return SpringAnimation.setFinalValue(y, Caml_array.caml_array_get(controls, 0)[/* animY */2]);
              };
              window.addEventListener("mousemove", onMove);
              window.addEventListener("touchmove", onMove);
              return /* () */0;
            }),
          /* didUpdate */component$6[/* didUpdate */5],
          /* willUnmount */(function (param) {
              return Belt_Array.forEach(param[/* state */1][/* controls */0], (function (param) {
                            SpringAnimation.stop(param[/* animX */1]);
                            return SpringAnimation.stop(param[/* animY */2]);
                          }));
            }),
          /* willUpdate */component$6[/* willUpdate */7],
          /* shouldUpdate */component$6[/* shouldUpdate */8],
          /* render */(function (param) {
              return React.createElement("div", undefined, param[/* state */1][/* chatHeads */1]);
            }),
          /* initialState */(function () {
              var controls = Belt_Array.makeBy(6, (function () {
                      return createControl(/* () */0);
                    }));
              var chatHeads = Belt_Array.makeBy(6, (function (i) {
                      return ReasonReact.element(gen(/* () */0), undefined, make$5(Caml_array.caml_array_get(controls, i)[/* rAction */0], i, imageGallery, /* array */[]));
                    }));
              return /* record */[
                      /* controls */controls,
                      /* chatHeads */chatHeads
                    ];
            }),
          /* retainedProps */component$6[/* retainedProps */11],
          /* reducer */(function (_, _$1) {
              return /* NoUpdate */0;
            }),
          /* subscriptions */component$6[/* subscriptions */13],
          /* jsElementWrapped */component$6[/* jsElementWrapped */14]
        ];
}

var ChatHeadsExample = /* module */[
  /* numHeads */6,
  /* createControl */createControl,
  /* component */component$6,
  /* make */make$6
];

var component$7 = ReasonReact.reducerComponent("ChatHeadsExampleStarter");

function make$7() {
  return /* record */[
          /* debugName */component$7[/* debugName */0],
          /* reactClassInternal */component$7[/* reactClassInternal */1],
          /* handedOffState */component$7[/* handedOffState */2],
          /* willReceiveProps */component$7[/* willReceiveProps */3],
          /* didMount */component$7[/* didMount */4],
          /* didUpdate */component$7[/* didUpdate */5],
          /* willUnmount */component$7[/* willUnmount */6],
          /* willUpdate */component$7[/* willUpdate */7],
          /* shouldUpdate */component$7[/* shouldUpdate */8],
          /* render */(function (param) {
              var send = param[/* send */3];
              switch (param[/* state */1]) {
                case 0 : 
                    return React.createElement("div", undefined, React.createElement("div", undefined, React.createElement("button", {
                                        onClick: (function () {
                                            return Curry._1(send, /* ChatHeads */1);
                                          })
                                      }, "Start normal chatheads")), React.createElement("button", {
                                    onClick: (function () {
                                        return Curry._1(send, /* ImageGalleryHeads */2);
                                      })
                                  }, "Start image gallery chatheads"));
                case 1 : 
                    return ReasonReact.element(undefined, undefined, make$6(false, /* array */[]));
                case 2 : 
                    return ReasonReact.element(undefined, undefined, make$6(true, /* array */[]));
                
              }
            }),
          /* initialState */(function () {
              return /* StartMessage */0;
            }),
          /* retainedProps */component$7[/* retainedProps */11],
          /* reducer */(function (actionIsState, _) {
              return /* Update */Block.__(0, [actionIsState]);
            }),
          /* subscriptions */component$7[/* subscriptions */13],
          /* jsElementWrapped */component$7[/* jsElementWrapped */14]
        ];
}

var ChatHeadsExampleStarter = /* module */[
  /* component */component$7,
  /* make */make$7
];

var component$8 = ReasonReact.statelessComponent("GalleryItem");

function make$8($staropt$star, $staropt$star$1, child) {
  var title = $staropt$star !== undefined ? $staropt$star : "Untitled";
  var description = $staropt$star$1 !== undefined ? $staropt$star$1 : "no description";
  var title$1 = React.createElement("div", {
        className: "header"
      }, title);
  var description$1 = React.createElement("div", {
        className: "headerSubtext",
        dangerouslySetInnerHTML: {
          __html: description
        }
      });
  var leftRight = React.createElement("div", {
        className: "galleryItemDemo leftRightContainer"
      }, React.createElement("div", {
            className: "right interactionContainer"
          }, child));
  return /* record */[
          /* debugName */component$8[/* debugName */0],
          /* reactClassInternal */component$8[/* reactClassInternal */1],
          /* handedOffState */component$8[/* handedOffState */2],
          /* willReceiveProps */component$8[/* willReceiveProps */3],
          /* didMount */component$8[/* didMount */4],
          /* didUpdate */component$8[/* didUpdate */5],
          /* willUnmount */component$8[/* willUnmount */6],
          /* willUpdate */component$8[/* willUpdate */7],
          /* shouldUpdate */component$8[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("div", {
                          className: "galleryItem"
                        }, title$1, description$1, leftRight);
            }),
          /* initialState */component$8[/* initialState */10],
          /* retainedProps */component$8[/* retainedProps */11],
          /* reducer */component$8[/* reducer */12],
          /* subscriptions */component$8[/* subscriptions */13],
          /* jsElementWrapped */component$8[/* jsElementWrapped */14]
        ];
}

var GalleryItem = /* module */[
  /* component */component$8,
  /* make */make$8
];

var component$9 = ReasonReact.statelessComponent("GalleryContainer");

var megaHeaderTitle = "Animating With Reason React Reducers";

var megaHeaderSubtext = "\n    Examples With Animations.\n  ";

var megaHeaderSubtextDetails = "\n    Explore animation with ReasonReact and reducers.\n\n  ";

function make$9(children) {
  return /* record */[
          /* debugName */component$9[/* debugName */0],
          /* reactClassInternal */component$9[/* reactClassInternal */1],
          /* handedOffState */component$9[/* handedOffState */2],
          /* willReceiveProps */component$9[/* willReceiveProps */3],
          /* didMount */component$9[/* didMount */4],
          /* didUpdate */component$9[/* didUpdate */5],
          /* willUnmount */component$9[/* willUnmount */6],
          /* willUpdate */component$9[/* willUpdate */7],
          /* shouldUpdate */component$9[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("div", {
                          className: "mainGallery",
                          style: {
                            width: "850px"
                          }
                        }, React.createElement("div", {
                              key: "megaHeader",
                              className: "megaHeader"
                            }, megaHeaderTitle), React.createElement("div", {
                              key: "degaHeaderSubtext",
                              className: "megaHeaderSubtext"
                            }, megaHeaderSubtext), React.createElement("div", {
                              key: "headerSubtext",
                              className: "megaHeaderSubtextDetails"
                            }, megaHeaderSubtextDetails), $$Array.map((function (c) {
                                return React.createElement("div", {
                                            key: gen(/* () */0)
                                          }, c);
                              }), children));
            }),
          /* initialState */component$9[/* initialState */10],
          /* retainedProps */component$9[/* retainedProps */11],
          /* reducer */component$9[/* reducer */12],
          /* subscriptions */component$9[/* subscriptions */13],
          /* jsElementWrapped */component$9[/* jsElementWrapped */14]
        ];
}

var GalleryContainer = /* module */[
  /* component */component$9,
  /* megaHeaderTitle */megaHeaderTitle,
  /* megaHeaderSubtext */megaHeaderSubtext,
  /* megaHeaderSubtextDetails */megaHeaderSubtextDetails,
  /* make */make$9
];

var component$10 = ReasonReact.statelessComponent("ComponentGallery");

function make$10() {
  var globalStateExample = ReasonReact.element(undefined, undefined, make$8("Global State Example", "", ReasonReact.element(undefined, undefined, Demo.GlobalStateExample[/* make */1](/* array */[]))));
  var localStateExample = ReasonReact.element(undefined, undefined, make$8("Local State Example", "", ReasonReact.element(undefined, undefined, Demo.LocalStateExample[/* make */1](/* array */[]))));
  var simpleTextInput = ReasonReact.element(undefined, undefined, make$8("Simple Text Input", "Edit the text field", ReasonReact.element(undefined, undefined, Demo.TextInput[/* make */2]((function (text) {
                      console.log("onChange:", text);
                      return /* () */0;
                    }), undefined, undefined, /* array */[]))));
  var simpleSpring = ReasonReact.element(undefined, undefined, make$8("Simple Spring", "Click on target to toggle", ReasonReact.element(undefined, undefined, Demo.SimpleSpring[/* make */2](/* array */[]))));
  var animatedTextInput = ReasonReact.element(undefined, undefined, make$8("Animated Text Input", "Edit text, or click on target to toggle animation", ReasonReact.element(undefined, undefined, Demo.AnimatedTextInput[/* make */3](/* array */[]))));
  var animatedTextInputRemote = ReasonReact.element(undefined, undefined, make$8("Animated Text Input With Remote Actions", "Edit text, or click on target to toggle animation", ReasonReact.element(undefined, undefined, Demo.AnimatedTextInputRemote[/* make */4](/* array */[]))));
  var callActionsOnGrandChild = ReasonReact.element(undefined, undefined, make$8("Call actions on grandchild directly", "", ReasonReact.element(undefined, undefined, Demo.Parent[/* make */1](/* array */[]))));
  var chatHeads = ReasonReact.element(undefined, undefined, make$8("Chat Heads", "", ReasonReact.element(undefined, undefined, make$7(/* array */[]))));
  var imageGallery = ReasonReact.element(undefined, undefined, make$8("Image Gallery", " Click on the image to transition to the next one. ", ReasonReact.element(undefined, undefined, make(undefined, undefined, /* array */[]))));
  var reducerAnimation = ReasonReact.element(undefined, undefined, make$8("Animation Based On Reducers", "", ReasonReact.element(undefined, undefined, make$4(false, /* array */[]))));
  return /* record */[
          /* debugName */component$10[/* debugName */0],
          /* reactClassInternal */component$10[/* reactClassInternal */1],
          /* handedOffState */component$10[/* handedOffState */2],
          /* willReceiveProps */component$10[/* willReceiveProps */3],
          /* didMount */component$10[/* didMount */4],
          /* didUpdate */component$10[/* didUpdate */5],
          /* willUnmount */component$10[/* willUnmount */6],
          /* willUpdate */component$10[/* willUpdate */7],
          /* shouldUpdate */component$10[/* shouldUpdate */8],
          /* render */(function () {
              return ReasonReact.element(undefined, undefined, make$9(/* array */[
                              globalStateExample,
                              localStateExample,
                              simpleTextInput,
                              simpleSpring,
                              animatedTextInput,
                              animatedTextInputRemote,
                              callActionsOnGrandChild,
                              chatHeads,
                              imageGallery,
                              reducerAnimation
                            ]));
            }),
          /* initialState */component$10[/* initialState */10],
          /* retainedProps */component$10[/* retainedProps */11],
          /* reducer */component$10[/* reducer */12],
          /* subscriptions */component$10[/* subscriptions */13],
          /* jsElementWrapped */component$10[/* jsElementWrapped */14]
        ];
}

var ComponentGallery = /* module */[
  /* component */component$10,
  /* make */make$10
];

exports.pxI = pxI;
exports.pxF = pxF;
exports.Key = Key;
exports.ImageTransition = ImageTransition;
exports.ImageGalleryAnimation = ImageGalleryAnimation;
exports.AnimatedButton = AnimatedButton;
exports.AnimateHeight = AnimateHeight;
exports.ReducerAnimationExample = ReducerAnimationExample;
exports.ChatHead = ChatHead;
exports.ChatHeadsExample = ChatHeadsExample;
exports.ChatHeadsExampleStarter = ChatHeadsExampleStarter;
exports.GalleryItem = GalleryItem;
exports.GalleryContainer = GalleryContainer;
exports.ComponentGallery = ComponentGallery;
/* displayHeightString Not a pure module */
