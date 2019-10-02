'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var $$String = require("bs-platform/lib/js/string.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.reducerComponent("TodoItemRe");

function setEditFieldRef(r, param) {
  param[/* state */1][/* editFieldRef */2][0] = (r == null) ? undefined : Caml_option.some(r);
  return /* () */0;
}

function make(todo, editing, onDestroy, onSave, onEdit, onToggle, onCancel, _children) {
  var submitHelper = function (state) {
    var nonEmptyValue = $$String.trim(state[/* editText */0]);
    if (nonEmptyValue === "") {
      return /* SideEffects */Block.__(1, [(function (_self) {
                    return Curry._1(onDestroy, /* () */0);
                  })]);
    } else {
      return /* UpdateWithSideEffects */Block.__(2, [
                /* record */[
                  /* editText */nonEmptyValue,
                  /* editing */state[/* editing */1],
                  /* editFieldRef */state[/* editFieldRef */2]
                ],
                (function (_self) {
                    return Curry._1(onSave, nonEmptyValue);
                  })
              ]);
    }
  };
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */(function (param) {
              var state = param[/* state */1];
              return /* record */[
                      /* editText */state[/* editText */0],
                      /* editing */editing,
                      /* editFieldRef */state[/* editFieldRef */2]
                    ];
            }),
          /* didMount */component[/* didMount */4],
          /* didUpdate */(function (param) {
              var match = param[/* oldSelf */0][/* state */1][/* editing */1];
              var match$1 = param[/* newSelf */1][/* state */1][/* editFieldRef */2][0];
              if (match || !(editing && match$1 !== undefined)) {
                return /* () */0;
              } else {
                var field = Caml_option.valFromOption(match$1);
                field.focus();
                field.setSelectionRange(field.value.length, field.value.length);
                return /* () */0;
              }
            }),
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (param) {
              var send = param[/* send */3];
              var match = todo[/* completed */2];
              var className = $$String.concat(" ", /* :: */[
                    match ? "completed" : "",
                    /* :: */[
                      editing ? "editing" : "",
                      /* [] */0
                    ]
                  ]);
              return React.createElement("li", {
                          className: className
                        }, React.createElement("div", {
                              className: "view"
                            }, React.createElement("input", {
                                  className: "toggle",
                                  checked: todo[/* completed */2],
                                  type: "checkbox",
                                  onChange: (function (param) {
                                      return Curry._1(onToggle, /* () */0);
                                    })
                                }), React.createElement("label", {
                                  onDoubleClick: (function (_event) {
                                      Curry._1(onEdit, /* () */0);
                                      return Curry._1(send, /* Edit */0);
                                    })
                                }, todo[/* title */1]), React.createElement("button", {
                                  className: "destroy",
                                  onClick: (function (param) {
                                      return Curry._1(onDestroy, /* () */0);
                                    })
                                })), React.createElement("input", {
                              ref: Curry._1(param[/* handle */0], setEditFieldRef),
                              className: "edit",
                              value: param[/* state */1][/* editText */0],
                              onKeyDown: (function ($$event) {
                                  return Curry._1(send, /* KeyDown */Block.__(0, [$$event.which]));
                                }),
                              onBlur: (function (_event) {
                                  return Curry._1(send, /* Submit */1);
                                }),
                              onChange: (function ($$event) {
                                  return Curry._1(send, /* Change */Block.__(1, [$$event.target.value]));
                                })
                            }));
            }),
          /* initialState */(function (param) {
              return /* record */[
                      /* editText */todo[/* title */1],
                      /* editing */editing,
                      /* editFieldRef : record */[/* contents */undefined]
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action) {
              if (typeof action === "number") {
                if (action === 0) {
                  return (function (state) {
                      return /* Update */Block.__(0, [/* record */[
                                  /* editText */todo[/* title */1],
                                  /* editing */state[/* editing */1],
                                  /* editFieldRef */state[/* editFieldRef */2]
                                ]]);
                    });
                } else {
                  return submitHelper;
                }
              } else if (action.tag) {
                var text = action[0];
                return (function (state) {
                    if (editing) {
                      return /* Update */Block.__(0, [/* record */[
                                  /* editText */text,
                                  /* editing */state[/* editing */1],
                                  /* editFieldRef */state[/* editFieldRef */2]
                                ]]);
                    } else {
                      return /* NoUpdate */0;
                    }
                  });
              } else {
                var match = action[0];
                if (match !== 13) {
                  if (match !== 27) {
                    return (function (_state) {
                        return /* NoUpdate */0;
                      });
                  } else {
                    Curry._1(onCancel, /* () */0);
                    return (function (state) {
                        return /* Update */Block.__(0, [/* record */[
                                    /* editText */todo[/* title */1],
                                    /* editing */state[/* editing */1],
                                    /* editFieldRef */state[/* editFieldRef */2]
                                  ]]);
                      });
                  }
                } else {
                  return submitHelper;
                }
              }
            }),
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.setEditFieldRef = setEditFieldRef;
exports.make = make;
/* component Not a pure module */
