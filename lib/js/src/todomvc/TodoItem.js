'use strict';

var Block       = require("bs-platform/lib/js/block.js");
var Curry       = require("bs-platform/lib/js/curry.js");
var React       = require("react");
var $$String    = require("bs-platform/lib/js/string.js");
var Js_boolean  = require("bs-platform/lib/js/js_boolean.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var component = ReasonReact.reducerComponent("TodoItemRe");

function setEditFieldRef(r, param) {
  param[/* state */2][/* editFieldRef */2][0] = (r == null) ? /* None */0 : [r];
  return /* () */0;
}

function make(todo, editing, onDestroy, onSave, onEdit, onToggle, onCancel, _) {
  var submitHelper = function (state) {
    var nonEmptyValue = $$String.trim(state[/* editText */0]);
    if (nonEmptyValue === "") {
      return /* SideEffects */Block.__(2, [(function () {
                    return Curry._1(onDestroy, /* () */0);
                  })]);
    } else {
      return /* UpdateWithSideEffects */Block.__(3, [
                /* record */[
                  /* editText */nonEmptyValue,
                  /* editing */state[/* editing */1],
                  /* editFieldRef */state[/* editFieldRef */2]
                ],
                (function () {
                    return Curry._1(onSave, nonEmptyValue);
                  })
              ]);
    }
  };
  var newrecord = component.slice();
  newrecord[/* willReceiveProps */3] = (function (param) {
      var state = param[/* state */2];
      return /* record */[
              /* editText */state[/* editText */0],
              /* editing */editing,
              /* editFieldRef */state[/* editFieldRef */2]
            ];
    });
  newrecord[/* didUpdate */5] = (function (param) {
      var match = param[/* oldSelf */0][/* state */2][/* editing */1];
      var match$1 = param[/* newSelf */1][/* state */2][/* editFieldRef */2][0];
      if (match !== 0) {
        return /* () */0;
      } else if (editing !== 0) {
        if (match$1) {
          var field = match$1[0];
          field.focus();
          field.setSelectionRange(field.value.length, field.value.length);
          return /* () */0;
        } else {
          return /* () */0;
        }
      } else {
        return /* () */0;
      }
    });
  newrecord[/* render */9] = (function (param) {
      var send = param[/* send */4];
      var match = todo[/* completed */2];
      var className = $$String.concat(" ", /* :: */[
            match !== 0 ? "completed" : "",
            /* :: */[
              editing !== 0 ? "editing" : "",
              /* [] */0
            ]
          ]);
      return React.createElement("li", {
                  className: className
                }, React.createElement("div", {
                      className: "view"
                    }, React.createElement("input", {
                          className: "toggle",
                          checked: Js_boolean.to_js_boolean(todo[/* completed */2]),
                          type: "checkbox",
                          onChange: (function () {
                              return Curry._1(onToggle, /* () */0);
                            })
                        }), React.createElement("label", {
                          onDoubleClick: (function () {
                              Curry._1(onEdit, /* () */0);
                              return Curry._1(send, /* Edit */0);
                            })
                        }, todo[/* title */1]), React.createElement("button", {
                          className: "destroy",
                          onClick: (function () {
                              return Curry._1(onDestroy, /* () */0);
                            })
                        })), React.createElement("input", {
                      ref: Curry._1(param[/* handle */0], setEditFieldRef),
                      className: "edit",
                      value: param[/* state */2][/* editText */0],
                      onKeyDown: (function ($$event) {
                          return Curry._1(send, /* KeyDown */Block.__(0, [$$event.which]));
                        }),
                      onBlur: (function () {
                          return Curry._1(send, /* Submit */1);
                        }),
                      onChange: (function ($$event) {
                          return Curry._1(send, /* Change */Block.__(1, [$$event.target.value]));
                        })
                    }));
    });
  newrecord[/* initialState */10] = (function () {
      return /* record */[
              /* editText */todo[/* title */1],
              /* editing */editing,
              /* editFieldRef */[/* None */0]
            ];
    });
  newrecord[/* reducer */12] = (function (action) {
      if (typeof action === "number") {
        if (action) {
          return submitHelper;
        } else {
          return (function (state) {
              return /* Update */Block.__(0, [/* record */[
                          /* editText */todo[/* title */1],
                          /* editing */state[/* editing */1],
                          /* editFieldRef */state[/* editFieldRef */2]
                        ]]);
            });
        }
      } else if (action.tag) {
        var text = action[0];
        return (function (state) {
            if (editing !== 0) {
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
            return (function () {
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
    });
  return newrecord;
}

exports.component       = component;
exports.setEditFieldRef = setEditFieldRef;
exports.make            = make;
/* component Not a pure module */
