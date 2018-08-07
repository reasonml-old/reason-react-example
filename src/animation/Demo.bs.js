'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var Printf = require("bs-platform/lib/js/printf.js");
var $$String = require("bs-platform/lib/js/string.js");
var Pervasives = require("bs-platform/lib/js/pervasives.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var RemoteAction = require("./RemoteAction.bs.js");
var SpringAnimation = require("./SpringAnimation.bs.js");

var initial = /* record */[
  /* count1 */0,
  /* count2 */0,
  /* toggle */false
];

var GlobalState = /* module */[/* initial */initial];

var component = ReasonReact.statelessComponent("Counter1");

function make(state, update, _) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("div", undefined, React.createElement("button", {
                              onClick: (function () {
                                  return Curry._1(update, (function (state) {
                                                return /* record */[
                                                        /* count1 */state[/* count1 */0] + 1 | 0,
                                                        /* count2 */state[/* count2 */1],
                                                        /* toggle */state[/* toggle */2]
                                                      ];
                                              }));
                                })
                            }, "+"), React.createElement("button", {
                              onClick: (function () {
                                  return Curry._1(update, (function (state) {
                                                return /* record */[
                                                        /* count1 */state[/* count1 */0] - 1 | 0,
                                                        /* count2 */state[/* count2 */1],
                                                        /* toggle */state[/* toggle */2]
                                                      ];
                                              }));
                                })
                            }, "-"), " counter:" + String(state[/* count1 */0]));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

var Counter1 = /* module */[
  /* component */component,
  /* make */make
];

var component$1 = ReasonReact.statelessComponent("Counter2");

function make$1(state, update, _) {
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
              return React.createElement("div", undefined, React.createElement("button", {
                              onClick: (function () {
                                  return Curry._1(update, (function (state) {
                                                return /* record */[
                                                        /* count1 */state[/* count1 */0],
                                                        /* count2 */state[/* count2 */1] + 1 | 0,
                                                        /* toggle */state[/* toggle */2]
                                                      ];
                                              }));
                                })
                            }, "+"), React.createElement("button", {
                              onClick: (function () {
                                  return Curry._1(update, (function (state) {
                                                return /* record */[
                                                        /* count1 */state[/* count1 */0],
                                                        /* count2 */state[/* count2 */1] - 1 | 0,
                                                        /* toggle */state[/* toggle */2]
                                                      ];
                                              }));
                                })
                            }, "-"), " counter:" + String(state[/* count2 */1]));
            }),
          /* initialState */component$1[/* initialState */10],
          /* retainedProps */component$1[/* retainedProps */11],
          /* reducer */component$1[/* reducer */12],
          /* jsElementWrapped */component$1[/* jsElementWrapped */13]
        ];
}

var Counter2 = /* module */[
  /* component */component$1,
  /* make */make$1
];

var component$2 = ReasonReact.statelessComponent("Toggle");

function make$2(state, update, _) {
  return /* record */[
          /* debugName */component$2[/* debugName */0],
          /* reactClassInternal */component$2[/* reactClassInternal */1],
          /* handedOffState */component$2[/* handedOffState */2],
          /* willReceiveProps */component$2[/* willReceiveProps */3],
          /* didMount */component$2[/* didMount */4],
          /* didUpdate */component$2[/* didUpdate */5],
          /* willUnmount */component$2[/* willUnmount */6],
          /* willUpdate */component$2[/* willUpdate */7],
          /* shouldUpdate */component$2[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("div", undefined, React.createElement("button", {
                              onClick: (function () {
                                  return Curry._1(update, (function (state) {
                                                return /* record */[
                                                        /* count1 */state[/* count1 */0],
                                                        /* count2 */state[/* count2 */1],
                                                        /* toggle */!state[/* toggle */2]
                                                      ];
                                              }));
                                })
                            }, "Toggle"), " toggle:" + Pervasives.string_of_bool(state[/* toggle */2]));
            }),
          /* initialState */component$2[/* initialState */10],
          /* retainedProps */component$2[/* retainedProps */11],
          /* reducer */component$2[/* reducer */12],
          /* jsElementWrapped */component$2[/* jsElementWrapped */13]
        ];
}

var Toggle = /* module */[
  /* component */component$2,
  /* make */make$2
];

var component$3 = ReasonReact.reducerComponent("GlobalStateExample");

function make$3() {
  return /* record */[
          /* debugName */component$3[/* debugName */0],
          /* reactClassInternal */component$3[/* reactClassInternal */1],
          /* handedOffState */component$3[/* handedOffState */2],
          /* willReceiveProps */component$3[/* willReceiveProps */3],
          /* didMount */component$3[/* didMount */4],
          /* didUpdate */component$3[/* didUpdate */5],
          /* willUnmount */component$3[/* willUnmount */6],
          /* willUpdate */component$3[/* willUpdate */7],
          /* shouldUpdate */component$3[/* shouldUpdate */8],
          /* render */(function (param) {
              var send = param[/* send */3];
              var state = param[/* state */1];
              var update = Curry.__1(send);
              return React.createElement("div", undefined, ReasonReact.element(undefined, undefined, make(state, update, /* array */[])), ReasonReact.element(undefined, undefined, make$1(state, update, /* array */[])), ReasonReact.element(undefined, undefined, make$1(state, update, /* array */[])), ReasonReact.element(undefined, undefined, make$2(state, update, /* array */[])));
            }),
          /* initialState */(function () {
              return initial;
            }),
          /* retainedProps */component$3[/* retainedProps */11],
          /* reducer */(function (fn, state) {
              return /* Update */Block.__(0, [Curry._1(fn, state)]);
            }),
          /* jsElementWrapped */component$3[/* jsElementWrapped */13]
        ];
}

var GlobalStateExample = /* module */[
  /* component */component$3,
  /* make */make$3
];

var component$4 = ReasonReact.reducerComponent("LocalCounter");

function make$4() {
  return /* record */[
          /* debugName */component$4[/* debugName */0],
          /* reactClassInternal */component$4[/* reactClassInternal */1],
          /* handedOffState */component$4[/* handedOffState */2],
          /* willReceiveProps */component$4[/* willReceiveProps */3],
          /* didMount */component$4[/* didMount */4],
          /* didUpdate */component$4[/* didUpdate */5],
          /* willUnmount */component$4[/* willUnmount */6],
          /* willUpdate */component$4[/* willUpdate */7],
          /* shouldUpdate */component$4[/* shouldUpdate */8],
          /* render */(function (param) {
              var send = param[/* send */3];
              return React.createElement("div", undefined, React.createElement("button", {
                              onClick: (function () {
                                  return Curry._1(send, /* Incr */0);
                                })
                            }, "+"), React.createElement("button", {
                              onClick: (function () {
                                  return Curry._1(send, /* Decr */1);
                                })
                            }, "-"), " counter:" + String(param[/* state */1]));
            }),
          /* initialState */(function () {
              return 0;
            }),
          /* retainedProps */component$4[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (action) {
                return /* Update */Block.__(0, [state - 1 | 0]);
              } else {
                return /* Update */Block.__(0, [state + 1 | 0]);
              }
            }),
          /* jsElementWrapped */component$4[/* jsElementWrapped */13]
        ];
}

var LocalCounter = /* module */[
  /* component */component$4,
  /* make */make$4
];

var component$5 = ReasonReact.reducerComponent("LocalToggle");

function make$5() {
  return /* record */[
          /* debugName */component$5[/* debugName */0],
          /* reactClassInternal */component$5[/* reactClassInternal */1],
          /* handedOffState */component$5[/* handedOffState */2],
          /* willReceiveProps */component$5[/* willReceiveProps */3],
          /* didMount */component$5[/* didMount */4],
          /* didUpdate */component$5[/* didUpdate */5],
          /* willUnmount */component$5[/* willUnmount */6],
          /* willUpdate */component$5[/* willUpdate */7],
          /* shouldUpdate */component$5[/* shouldUpdate */8],
          /* render */(function (param) {
              var send = param[/* send */3];
              return React.createElement("div", undefined, React.createElement("button", {
                              onClick: (function () {
                                  return Curry._1(send, /* Toggle */0);
                                })
                            }, "Toggle"), " toggle:" + Pervasives.string_of_bool(param[/* state */1]));
            }),
          /* initialState */(function () {
              return false;
            }),
          /* retainedProps */component$5[/* retainedProps */11],
          /* reducer */(function (_, state) {
              return /* Update */Block.__(0, [!state]);
            }),
          /* jsElementWrapped */component$5[/* jsElementWrapped */13]
        ];
}

var LocalToggle = /* module */[
  /* component */component$5,
  /* make */make$5
];

var component$6 = ReasonReact.statelessComponent("LocalStateExample");

function make$6() {
  return /* record */[
          /* debugName */component$6[/* debugName */0],
          /* reactClassInternal */component$6[/* reactClassInternal */1],
          /* handedOffState */component$6[/* handedOffState */2],
          /* willReceiveProps */component$6[/* willReceiveProps */3],
          /* didMount */component$6[/* didMount */4],
          /* didUpdate */component$6[/* didUpdate */5],
          /* willUnmount */component$6[/* willUnmount */6],
          /* willUpdate */component$6[/* willUpdate */7],
          /* shouldUpdate */component$6[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("div", undefined, ReasonReact.element(undefined, undefined, make$4(/* array */[])), ReasonReact.element(undefined, undefined, make$4(/* array */[])), ReasonReact.element(undefined, undefined, make$4(/* array */[])), ReasonReact.element(undefined, undefined, make$5(/* array */[])));
            }),
          /* initialState */component$6[/* initialState */10],
          /* retainedProps */component$6[/* retainedProps */11],
          /* reducer */component$6[/* reducer */12],
          /* jsElementWrapped */component$6[/* jsElementWrapped */13]
        ];
}

var LocalStateExample = /* module */[
  /* component */component$6,
  /* make */make$6
];

var component$7 = ReasonReact.reducerComponent("TextInput");

function textOfEvent(e) {
  return e.target.value;
}

function make$7($staropt$star, $staropt$star$1, $staropt$star$2, _) {
  var onChange = $staropt$star !== undefined ? $staropt$star : (function () {
        return /* () */0;
      });
  var showText = $staropt$star$1 !== undefined ? $staropt$star$1 : (function (x) {
        return x;
      });
  var initial = $staropt$star$2 !== undefined ? $staropt$star$2 : "";
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
              return React.createElement("input", {
                          value: Curry._1(showText, param[/* state */1]),
                          onChange: (function ($$event) {
                              var text = $$event.target.value;
                              Curry._1(send, /* Text */[text]);
                              return Curry._1(onChange, text);
                            })
                        });
            }),
          /* initialState */(function () {
              return initial;
            }),
          /* retainedProps */component$7[/* retainedProps */11],
          /* reducer */(function (action, _) {
              return /* Update */Block.__(0, [action[0]]);
            }),
          /* jsElementWrapped */component$7[/* jsElementWrapped */13]
        ];
}

var TextInput = /* module */[
  /* component */component$7,
  /* textOfEvent */textOfEvent,
  /* make */make$7
];

var component$8 = ReasonReact.reducerComponent("Spring");

function make$8(renderValue, _) {
  return /* record */[
          /* debugName */component$8[/* debugName */0],
          /* reactClassInternal */component$8[/* reactClassInternal */1],
          /* handedOffState */component$8[/* handedOffState */2],
          /* willReceiveProps */component$8[/* willReceiveProps */3],
          /* didMount */(function (param) {
              var send = param[/* send */3];
              var state = param[/* state */1];
              var eta = state[/* animation */0];
              var arg = function (value) {
                return Curry._1(send, /* Value */[value]);
              };
              var arg$1 = state[/* target */2];
              Curry._1((function (param, param$1, param$2, param$3) {
                        return (function (param$4) {
                            return SpringAnimation.setOnChange(param, param$1, param$2, param$3, arg, arg$1, param$4);
                          });
                      })(undefined, undefined, undefined, undefined), eta);
              return Curry._1(param[/* onUnmount */4], (function () {
                            return SpringAnimation.stop(state[/* animation */0]);
                          }));
            }),
          /* didUpdate */component$8[/* didUpdate */5],
          /* willUnmount */component$8[/* willUnmount */6],
          /* willUpdate */component$8[/* willUpdate */7],
          /* shouldUpdate */component$8[/* shouldUpdate */8],
          /* render */(function (param) {
              var send = param[/* send */3];
              var state = param[/* state */1];
              return React.createElement("div", undefined, React.createElement("button", {
                              onClick: (function () {
                                  return Curry._1(send, /* Click */0);
                                })
                            }, "target: " + Pervasives.string_of_float(state[/* target */2])), React.createElement("div", undefined, Curry._1(renderValue, state[/* value */1])));
            }),
          /* initialState */(function () {
              return /* record */[
                      /* animation */SpringAnimation.create(0.0),
                      /* value */0.0,
                      /* target */1.0
                    ];
            }),
          /* retainedProps */component$8[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (action) {
                return /* Update */Block.__(0, [/* record */[
                            /* animation */state[/* animation */0],
                            /* value */action[0],
                            /* target */state[/* target */2]
                          ]]);
              } else {
                var match = state[/* target */2] === 0.0;
                var target = match ? 1.0 : 0.0;
                return /* UpdateWithSideEffects */Block.__(2, [
                          /* record */[
                            /* animation */state[/* animation */0],
                            /* value */state[/* value */1],
                            /* target */target
                          ],
                          (function () {
                              return SpringAnimation.setFinalValue(target, state[/* animation */0]);
                            })
                        ]);
              }
            }),
          /* jsElementWrapped */component$8[/* jsElementWrapped */13]
        ];
}

var Spring = /* module */[
  /* component */component$8,
  /* make */make$8
];

function renderValue(value) {
  return Curry._1(Printf.sprintf(/* Format */[
                  /* String_literal */Block.__(11, [
                      "value: ",
                      /* Float */Block.__(8, [
                          /* Float_f */0,
                          /* No_padding */0,
                          /* Lit_precision */[3],
                          /* End_of_format */0
                        ])
                    ]),
                  "value: %.3f"
                ]), value);
}

var component$9 = ReasonReact.statelessComponent("SimpleSpring");

function make$9() {
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
              return ReasonReact.element(undefined, undefined, make$8(renderValue, /* array */[]));
            }),
          /* initialState */component$9[/* initialState */10],
          /* retainedProps */component$9[/* retainedProps */11],
          /* reducer */component$9[/* reducer */12],
          /* jsElementWrapped */component$9[/* jsElementWrapped */13]
        ];
}

var SimpleSpring = /* module */[
  /* renderValue */renderValue,
  /* component */component$9,
  /* make */make$9
];

function shrinkText(text, value) {
  var match = value >= 1.0;
  if (match) {
    return text;
  } else {
    var len = Math.round(value * text.length);
    return $$String.sub(text, 0, len | 0);
  }
}

function renderValue$1(value) {
  return ReasonReact.element(undefined, undefined, make$7(undefined, (function (text) {
                    return shrinkText(text, value);
                  }), "edit this or click target", /* array */[]));
}

var component$10 = ReasonReact.statelessComponent("AnimatedTextInput");

function make$10() {
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
              return ReasonReact.element(undefined, undefined, make$8(renderValue$1, /* array */[]));
            }),
          /* initialState */component$10[/* initialState */10],
          /* retainedProps */component$10[/* retainedProps */11],
          /* reducer */component$10[/* reducer */12],
          /* jsElementWrapped */component$10[/* jsElementWrapped */13]
        ];
}

var AnimatedTextInput = /* module */[
  /* shrinkText */shrinkText,
  /* renderValue */renderValue$1,
  /* component */component$10,
  /* make */make$10
];

var component$11 = ReasonReact.reducerComponent("TextInputRemote");

function textOfEvent$1(e) {
  return e.target.value;
}

function make$11(remoteAction, $staropt$star, $staropt$star$1, $staropt$star$2, _) {
  var onChange = $staropt$star !== undefined ? $staropt$star : (function () {
        return /* () */0;
      });
  var showText = $staropt$star$1 !== undefined ? $staropt$star$1 : (function (x) {
        return x;
      });
  var initial = $staropt$star$2 !== undefined ? $staropt$star$2 : "";
  return /* record */[
          /* debugName */component$11[/* debugName */0],
          /* reactClassInternal */component$11[/* reactClassInternal */1],
          /* handedOffState */component$11[/* handedOffState */2],
          /* willReceiveProps */component$11[/* willReceiveProps */3],
          /* didMount */(function (param) {
              var token = RemoteAction.subscribe(param[/* send */3], remoteAction);
              return Curry._1(param[/* onUnmount */4], (function () {
                            if (token !== undefined) {
                              return RemoteAction.unsubscribe(Js_primitive.valFromOption(token));
                            } else {
                              return /* () */0;
                            }
                          }));
            }),
          /* didUpdate */component$11[/* didUpdate */5],
          /* willUnmount */component$11[/* willUnmount */6],
          /* willUpdate */component$11[/* willUpdate */7],
          /* shouldUpdate */component$11[/* shouldUpdate */8],
          /* render */(function (param) {
              var send = param[/* send */3];
              return React.createElement("input", {
                          value: Curry._1(showText, param[/* state */1]),
                          onChange: (function ($$event) {
                              var text = $$event.target.value;
                              Curry._1(send, /* Text */[text]);
                              return Curry._1(onChange, text);
                            })
                        });
            }),
          /* initialState */(function () {
              return initial;
            }),
          /* retainedProps */component$11[/* retainedProps */11],
          /* reducer */(function (action, _) {
              if (action) {
                return /* Update */Block.__(0, [action[0]]);
              } else {
                return /* Update */Block.__(0, ["the text has been reset"]);
              }
            }),
          /* jsElementWrapped */component$11[/* jsElementWrapped */13]
        ];
}

var TextInputRemote = /* module */[
  /* component */component$11,
  /* textOfEvent */textOfEvent$1,
  /* make */make$11
];

function shrinkText$1(text, value) {
  var match = value >= 1.0;
  if (match) {
    return text;
  } else {
    var len = Math.round(value * text.length);
    return $$String.sub(text, 0, len | 0);
  }
}

var remoteAction = RemoteAction.create(/* () */0);

function renderValue$2(value) {
  return ReasonReact.element(undefined, undefined, make$11(remoteAction, undefined, (function (text) {
                    return shrinkText$1(text, value);
                  }), "edit this or click target", /* array */[]));
}

var component$12 = ReasonReact.statelessComponent("AnimatedTextInput");

function make$12() {
  return /* record */[
          /* debugName */component$12[/* debugName */0],
          /* reactClassInternal */component$12[/* reactClassInternal */1],
          /* handedOffState */component$12[/* handedOffState */2],
          /* willReceiveProps */component$12[/* willReceiveProps */3],
          /* didMount */component$12[/* didMount */4],
          /* didUpdate */component$12[/* didUpdate */5],
          /* willUnmount */component$12[/* willUnmount */6],
          /* willUpdate */component$12[/* willUpdate */7],
          /* shouldUpdate */component$12[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("div", undefined, React.createElement("button", {
                              onClick: (function () {
                                  return RemoteAction.send(remoteAction, /* Reset */0);
                                })
                            }, "reset text"), React.createElement("div", undefined, "-----"), ReasonReact.element(undefined, undefined, make$8(renderValue$2, /* array */[])));
            }),
          /* initialState */component$12[/* initialState */10],
          /* retainedProps */component$12[/* retainedProps */11],
          /* reducer */component$12[/* reducer */12],
          /* jsElementWrapped */component$12[/* jsElementWrapped */13]
        ];
}

var AnimatedTextInputRemote = /* module */[
  /* shrinkText */shrinkText$1,
  /* remoteAction */remoteAction,
  /* renderValue */renderValue$2,
  /* component */component$12,
  /* make */make$12
];

var component$13 = ReasonReact.reducerComponent("GrandChild");

function make$13(remoteAction, _) {
  return /* record */[
          /* debugName */component$13[/* debugName */0],
          /* reactClassInternal */component$13[/* reactClassInternal */1],
          /* handedOffState */component$13[/* handedOffState */2],
          /* willReceiveProps */component$13[/* willReceiveProps */3],
          /* didMount */(function (param) {
              var token = RemoteAction.subscribe(param[/* send */3], remoteAction);
              return Curry._1(param[/* onUnmount */4], (function () {
                            if (token !== undefined) {
                              return RemoteAction.unsubscribe(Js_primitive.valFromOption(token));
                            } else {
                              return /* () */0;
                            }
                          }));
            }),
          /* didUpdate */component$13[/* didUpdate */5],
          /* willUnmount */component$13[/* willUnmount */6],
          /* willUpdate */component$13[/* willUpdate */7],
          /* shouldUpdate */component$13[/* shouldUpdate */8],
          /* render */(function (param) {
              return React.createElement("div", undefined, "in grandchild state: " + String(param[/* state */1]));
            }),
          /* initialState */(function () {
              return 0;
            }),
          /* retainedProps */component$13[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (action) {
                return /* Update */Block.__(0, [state - 1 | 0]);
              } else {
                return /* Update */Block.__(0, [state + 1 | 0]);
              }
            }),
          /* jsElementWrapped */component$13[/* jsElementWrapped */13]
        ];
}

var GrandChild = /* module */[
  /* component */component$13,
  /* make */make$13
];

var component$14 = ReasonReact.statelessComponent("Child");

function make$14(remoteAction, _) {
  return /* record */[
          /* debugName */component$14[/* debugName */0],
          /* reactClassInternal */component$14[/* reactClassInternal */1],
          /* handedOffState */component$14[/* handedOffState */2],
          /* willReceiveProps */component$14[/* willReceiveProps */3],
          /* didMount */component$14[/* didMount */4],
          /* didUpdate */component$14[/* didUpdate */5],
          /* willUnmount */component$14[/* willUnmount */6],
          /* willUpdate */component$14[/* willUpdate */7],
          /* shouldUpdate */component$14[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("div", undefined, "in child", ReasonReact.element(undefined, undefined, make$13(remoteAction, /* array */[])));
            }),
          /* initialState */component$14[/* initialState */10],
          /* retainedProps */component$14[/* retainedProps */11],
          /* reducer */component$14[/* reducer */12],
          /* jsElementWrapped */component$14[/* jsElementWrapped */13]
        ];
}

var Child = /* module */[
  /* component */component$14,
  /* make */make$14
];

var component$15 = ReasonReact.reducerComponent("Parent");

function make$15() {
  return /* record */[
          /* debugName */component$15[/* debugName */0],
          /* reactClassInternal */component$15[/* reactClassInternal */1],
          /* handedOffState */component$15[/* handedOffState */2],
          /* willReceiveProps */component$15[/* willReceiveProps */3],
          /* didMount */component$15[/* didMount */4],
          /* didUpdate */component$15[/* didUpdate */5],
          /* willUnmount */component$15[/* willUnmount */6],
          /* willUpdate */component$15[/* willUpdate */7],
          /* shouldUpdate */component$15[/* shouldUpdate */8],
          /* render */(function (param) {
              var state = param[/* state */1];
              return React.createElement("div", undefined, React.createElement("button", {
                              onClick: (function () {
                                  return RemoteAction.send(state, /* Incr */0);
                                })
                            }, "in parent"), ReasonReact.element(undefined, undefined, make$14(state, /* array */[])));
            }),
          /* initialState */(function () {
              return RemoteAction.create(/* () */0);
            }),
          /* retainedProps */component$15[/* retainedProps */11],
          /* reducer */(function (_, _$1) {
              return /* NoUpdate */0;
            }),
          /* jsElementWrapped */component$15[/* jsElementWrapped */13]
        ];
}

var Parent = /* module */[
  /* component */component$15,
  /* make */make$15
];

exports.GlobalState = GlobalState;
exports.Counter1 = Counter1;
exports.Counter2 = Counter2;
exports.Toggle = Toggle;
exports.GlobalStateExample = GlobalStateExample;
exports.LocalCounter = LocalCounter;
exports.LocalToggle = LocalToggle;
exports.LocalStateExample = LocalStateExample;
exports.TextInput = TextInput;
exports.Spring = Spring;
exports.SimpleSpring = SimpleSpring;
exports.AnimatedTextInput = AnimatedTextInput;
exports.TextInputRemote = TextInputRemote;
exports.AnimatedTextInputRemote = AnimatedTextInputRemote;
exports.GrandChild = GrandChild;
exports.Child = Child;
exports.Parent = Parent;
/* component Not a pure module */
