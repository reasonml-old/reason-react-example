'use strict';

var List = require("bs-platform/lib/js/list.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var $$String = require("bs-platform/lib/js/string.js");
var Caml_obj = require("bs-platform/lib/js/caml_obj.js");
var TodoItem = require("./TodoItem.js");
var Belt_List = require("bs-platform/lib/js/belt_List.js");
var Js_boolean = require("bs-platform/lib/js/js_boolean.js");
var Pervasives = require("bs-platform/lib/js/pervasives.js");
var ReactDOMRe = require("reason-react/lib/js/src/ReactDOMRe.js");
var TodoFooter = require("./TodoFooter.js");
var ReasonReact = require("reason-react/lib/js/src/ReasonReact.js");

var mergeDiff = ( function(
  prev,
  next,
  onRemove,
  trulyRemove
) {
  // bookkeeping for easier access of a key's index below. This is 2 allocations +
  // potentially triggering chrome hash map mode for objs (so it might be faster
  // to loop through and find a key's index each time), but I no longer care
  let prevKeyIndex = {};
  for (let i = 0; i < prev.length; i++) {
    prevKeyIndex[prev[i]] = i;
  }
  let nextKeyIndex = {};
  for (let i = 0; i < next.length; i++) {
    nextKeyIndex[next[i]] = i;
  }

  // first, an overly elaborate way of merging prev and next, eliminating
  // duplicates (in terms of keys). If there's dupe, keep the item in next).
  // This way of writing it saves allocations
  let ret = [];
  for (let i = 0; i < next.length; i++) {
    ret[i] = next[i];
  }
  for (let i = 0; i < prev.length; i++) {
    if (!Object.prototype.hasOwnProperty.call(nextKeyIndex, prev[i])) {
      // this is called my TM's `mergeAndSync`, which calls willLeave. We don't
      // merge in keys that the user desires to kill
      // const fill = onRemove(i, prev[i]);
      const asd = prev[i];
      onRemove(i, prev[i], () => trulyRemove(asd));
      const fill = prev[i];
      if (fill != null) {
        ret.push(fill);
      }
    }
  }

  // now all the items all present. Core sorting logic to have the right order
  return ret.sort((a, b) => {
    const nextOrderA = nextKeyIndex[a];
    const nextOrderB = nextKeyIndex[b];
    const prevOrderA = prevKeyIndex[a];
    const prevOrderB = prevKeyIndex[b];

    if (nextOrderA != null && nextOrderB != null) {
      // both keys in next
      return nextKeyIndex[a] - nextKeyIndex[b];
    } else if (prevOrderA != null && prevOrderB != null) {
      // both keys in prev
      return prevKeyIndex[a] - prevKeyIndex[b];
    } else if (nextOrderA != null) {
      // key a in next, key b in prev

      // how to determine the order between a and b? We find a "pivot" (term
      // abuse), a key present in both prev and next, that is sandwiched between
      // a and b. In the context of our above example, if we're comparing a and
      // d, b's (the only) pivot
      for (let i = 0; i < next.length; i++) {
        const pivot = next[i];
        if (!Object.prototype.hasOwnProperty.call(prevKeyIndex, pivot)) {
          continue;
        }

        if (nextOrderA < nextKeyIndex[pivot] && prevOrderB > prevKeyIndex[pivot]) {
          return -1;
        } else if (nextOrderA > nextKeyIndex[pivot] && prevOrderB < prevKeyIndex[pivot]) {
          return 1;
        }
      }
      // pluggable. default to: next bigger than prev
      return 1;
    }
    // prevOrderA, nextOrderB
    for (let i = 0; i < next.length; i++) {
      const pivot = next[i];
      if (!Object.prototype.hasOwnProperty.call(prevKeyIndex, pivot)) {
        continue;
      }
      if (nextOrderB < nextKeyIndex[pivot] && prevOrderA > prevKeyIndex[pivot]) {
        return 1;
      } else if (nextOrderB > nextKeyIndex[pivot] && prevOrderA < prevKeyIndex[pivot]) {
        return -1;
      }
    }
    // pluggable. default to: next bigger than prev
    return -1;
  });
}
);

var Animated = /* module */[];

var RR2 = /* module */[/* Animated */Animated];

var localStorageNamespace = "reason-react-todos";

function saveLocally(todos) {
  var todos$1 = Belt_List.map(todos, (function (prim) {
          return prim[1];
        }));
  var match = JSON.stringify(todos$1);
  if (match !== undefined) {
    localStorage.setItem(localStorageNamespace, match);
    return /* () */0;
  } else {
    return /* () */0;
  }
}

function urlToShownPage(hash) {
  switch (hash) {
    case "active" : 
        return /* ActiveTodos */1;
    case "completed" : 
        return /* CompletedTodos */2;
    default:
      return /* AllTodos */0;
  }
}

var component = ReasonReact.reducerComponent("TodoAppRe");

function make() {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function (param) {
      var state = param[/* state */2];
      var todos = state[/* todos */3];
      var editing = state[/* editing */1];
      var send = param[/* send */4];
      var todoItems = Belt_List.toArray(Belt_List.keepMap(todos, (function (param) {
                  var todo = param[1];
                  var match = state[/* nowShowing */0];
                  var match$1 = todo[/* completed */2];
                  var exit = 0;
                  switch (match) {
                    case 0 : 
                        exit = 1;
                        break;
                    case 1 : 
                        if (match$1 !== 0) {
                          return /* None */0;
                        } else {
                          exit = 1;
                        }
                        break;
                    case 2 : 
                        if (match$1 !== 0) {
                          exit = 1;
                        } else {
                          return /* None */0;
                        }
                        break;
                    
                  }
                  if (exit === 1) {
                    var editing$1 = editing ? +(editing[0] === todo[/* id */0]) : /* false */0;
                    var todo$1;
                    switch (param[0]) {
                      case 0 : 
                          todo$1 = React.createElement("div", {
                                key: todo[/* id */0],
                                className: "fade-in"
                              }, React.createElement("div", undefined, "imagine an animation here!"), ReasonReact.element(/* None */0, /* None */0, TodoItem.make(todo, editing$1, (function () {
                                          return Curry._1(send, /* Destroy */Block.__(4, [todo]));
                                        }), (function (text) {
                                          return Curry._1(send, /* Save */Block.__(2, [
                                                        todo,
                                                        text
                                                      ]));
                                        }), (function () {
                                          return Curry._1(send, /* Edit */Block.__(3, [todo]));
                                        }), (function () {
                                          return Curry._1(send, /* Toggle */Block.__(6, [todo]));
                                        }), (function () {
                                          return Curry._1(send, /* Cancel */3);
                                        }), /* array */[])));
                          break;
                      case 1 : 
                          todo$1 = ReasonReact.element(/* Some */[todo[/* id */0]], /* None */0, TodoItem.make(todo, editing$1, (function () {
                                      return Curry._1(send, /* Destroy */Block.__(4, [todo]));
                                    }), (function (text) {
                                      return Curry._1(send, /* Save */Block.__(2, [
                                                    todo,
                                                    text
                                                  ]));
                                    }), (function () {
                                      return Curry._1(send, /* Edit */Block.__(3, [todo]));
                                    }), (function () {
                                      return Curry._1(send, /* Toggle */Block.__(6, [todo]));
                                    }), (function () {
                                      return Curry._1(send, /* Cancel */3);
                                    }), /* array */[]));
                          break;
                      case 2 : 
                          todo$1 = React.createElement("div", {
                                key: todo[/* id */0],
                                className: "fade-out"
                              }, React.createElement("div", undefined, "unmounting!"), ReasonReact.element(/* None */0, /* None */0, TodoItem.make(todo, editing$1, (function () {
                                          return Curry._1(send, /* Destroy */Block.__(4, [todo]));
                                        }), (function (text) {
                                          return Curry._1(send, /* Save */Block.__(2, [
                                                        todo,
                                                        text
                                                      ]));
                                        }), (function () {
                                          return Curry._1(send, /* Edit */Block.__(3, [todo]));
                                        }), (function () {
                                          return Curry._1(send, /* Toggle */Block.__(6, [todo]));
                                        }), (function () {
                                          return Curry._1(send, /* Cancel */3);
                                        }), /* array */[])));
                          break;
                      
                    }
                    return /* Some */[todo$1];
                  }
                  
                })));
      var todosLength = List.length(todos);
      var completedCount = List.length(Belt_List.keep(todos, (function (param) {
                  return param[1][/* completed */2];
                })));
      var activeTodoCount = todosLength - completedCount | 0;
      var footer;
      var exit = 0;
      if (activeTodoCount !== 0 || completedCount !== 0) {
        exit = 1;
      } else {
        footer = null;
      }
      if (exit === 1) {
        footer = ReasonReact.element(/* None */0, /* None */0, TodoFooter.make(activeTodoCount, completedCount, state[/* nowShowing */0], (function () {
                    return Curry._1(send, /* ClearCompleted */2);
                  }), /* array */[]));
      }
      var match = +(todosLength === 0);
      var main = match !== 0 ? null : React.createElement("section", {
              className: "main"
            }, React.createElement("input", {
                  className: "toggle-all",
                  checked: Js_boolean.to_js_boolean(+(activeTodoCount === 0)),
                  type: "checkbox",
                  onChange: (function ($$event) {
                      var checked = +$$event.target.checked;
                      return Curry._1(send, /* ToggleAll */Block.__(7, [checked]));
                    })
                }), React.createElement("ul", {
                  className: "todo-list"
                }, todoItems));
      return React.createElement("div", undefined, React.createElement("header", {
                      className: "header"
                    }, React.createElement("h1", undefined, "todos"), React.createElement("input", {
                          className: "new-todo",
                          autoFocus: true,
                          placeholder: "What needs to be done?",
                          value: state[/* newTodo */2],
                          onKeyDown: (function ($$event) {
                              if ($$event.keyCode === 13) {
                                $$event.preventDefault();
                                return Curry._1(send, /* NewTodoEnterKeyDown */0);
                              } else {
                                return Curry._1(send, /* NewTodoOtherKeyDown */1);
                              }
                            }),
                          onChange: (function ($$event) {
                              return Curry._1(send, /* ChangeTodo */Block.__(1, [$$event.target.value]));
                            })
                        })), main, footer);
    });
  newrecord[/* initialState */10] = (function () {
      var match = localStorage.getItem(localStorageNamespace);
      var todos = match !== null ? JSON.parse(match) : /* [] */0;
      return /* record */[
              /* nowShowing */urlToShownPage(ReasonReact.Router[/* dangerouslyGetInitialUrl */3](/* () */0)[/* hash */1]),
              /* editing : None */0,
              /* newTodo */"",
              /* todos */Belt_List.map(todos, (function (todo) {
                      return /* tuple */[
                              /* Mounted */1,
                              todo
                            ];
                    }))
            ];
    });
  newrecord[/* reducer */12] = (function (action, state) {
      if (typeof action === "number") {
        switch (action) {
          case 0 : 
              var nonEmptyValue = $$String.trim(state[/* newTodo */2]);
              if (nonEmptyValue === "") {
                return /* NoUpdate */0;
              } else {
                var todos = Pervasives.$at(state[/* todos */3], /* :: */[
                      /* tuple */[
                        /* Mounting */0,
                        /* record */[
                          /* id */Pervasives.string_of_float(Date.now()),
                          /* title */nonEmptyValue,
                          /* completed : false */0
                        ]
                      ],
                      /* [] */0
                    ]);
                saveLocally(todos);
                return /* Update */Block.__(0, [/* record */[
                            /* nowShowing */state[/* nowShowing */0],
                            /* editing */state[/* editing */1],
                            /* newTodo */"",
                            /* todos */todos
                          ]]);
              }
              break;
          case 1 : 
              return /* NoUpdate */0;
          case 2 : 
              var todos$1 = Belt_List.map(state[/* todos */3], (function (param) {
                      var todo = param[1];
                      if (todo[/* completed */2] !== 0) {
                        return /* tuple */[
                                /* Unmounting */2,
                                todo
                              ];
                      } else {
                        return [
                                param[0],
                                todo
                              ];
                      }
                    }));
              return /* UpdateWithSideEffects */Block.__(3, [
                        /* record */[
                          /* nowShowing */state[/* nowShowing */0],
                          /* editing */state[/* editing */1],
                          /* newTodo */state[/* newTodo */2],
                          /* todos */todos$1
                        ],
                        (function () {
                            return saveLocally(todos$1);
                          })
                      ]);
          case 3 : 
              return /* Update */Block.__(0, [/* record */[
                          /* nowShowing */state[/* nowShowing */0],
                          /* editing : None */0,
                          /* newTodo */state[/* newTodo */2],
                          /* todos */state[/* todos */3]
                        ]]);
          
        }
      } else {
        switch (action.tag | 0) {
          case 0 : 
              return /* Update */Block.__(0, [/* record */[
                          /* nowShowing */action[0],
                          /* editing */state[/* editing */1],
                          /* newTodo */state[/* newTodo */2],
                          /* todos */state[/* todos */3]
                        ]]);
          case 1 : 
              return /* Update */Block.__(0, [/* record */[
                          /* nowShowing */state[/* nowShowing */0],
                          /* editing */state[/* editing */1],
                          /* newTodo */action[0],
                          /* todos */state[/* todos */3]
                        ]]);
          case 2 : 
              var text = action[1];
              var todoToSave = action[0];
              var todos$2 = Belt_List.map(state[/* todos */3], (function (param) {
                      var todo = param[1];
                      var transition = param[0];
                      var match = Caml_obj.caml_equal(todo, todoToSave);
                      if (match !== 0) {
                        return /* tuple */[
                                transition,
                                /* record */[
                                  /* id */todo[/* id */0],
                                  /* title */text,
                                  /* completed */todo[/* completed */2]
                                ]
                              ];
                      } else {
                        return /* tuple */[
                                transition,
                                todo
                              ];
                      }
                    }));
              return /* UpdateWithSideEffects */Block.__(3, [
                        /* record */[
                          /* nowShowing */state[/* nowShowing */0],
                          /* editing : None */0,
                          /* newTodo */state[/* newTodo */2],
                          /* todos */todos$2
                        ],
                        (function () {
                            return saveLocally(todos$2);
                          })
                      ]);
          case 3 : 
              return /* Update */Block.__(0, [/* record */[
                          /* nowShowing */state[/* nowShowing */0],
                          /* editing : Some */[action[0][/* id */0]],
                          /* newTodo */state[/* newTodo */2],
                          /* todos */state[/* todos */3]
                        ]]);
          case 4 : 
              var todo = action[0];
              var todos$3 = Belt_List.map(state[/* todos */3], (function (param) {
                      var candidate = param[1];
                      if (candidate[/* id */0] === todo[/* id */0]) {
                        return /* tuple */[
                                /* Unmounting */2,
                                candidate
                              ];
                      } else {
                        return /* tuple */[
                                param[0],
                                candidate
                              ];
                      }
                    }));
              return /* UpdateWithSideEffects */Block.__(3, [
                        /* record */[
                          /* nowShowing */state[/* nowShowing */0],
                          /* editing */state[/* editing */1],
                          /* newTodo */state[/* newTodo */2],
                          /* todos */todos$3
                        ],
                        (function (self) {
                            var todos = Belt_List.keep(state[/* todos */3], (function (param) {
                                    return +(param[1][/* id */0] !== todo[/* id */0]);
                                  }));
                            saveLocally(todos);
                            setTimeout((function () {
                                    return Curry._1(self[/* send */4], /* TrulyDestroy */Block.__(5, [todo]));
                                  }), 5000);
                            return /* () */0;
                          })
                      ]);
          case 5 : 
              var todo$1 = action[0];
              var todos$4 = Belt_List.keep(state[/* todos */3], (function (param) {
                      return +(param[1][/* id */0] !== todo$1[/* id */0]);
                    }));
              return /* Update */Block.__(0, [/* record */[
                          /* nowShowing */state[/* nowShowing */0],
                          /* editing */state[/* editing */1],
                          /* newTodo */state[/* newTodo */2],
                          /* todos */todos$4
                        ]]);
          case 6 : 
              var todoToToggle = action[0];
              var todos$5 = Belt_List.map(state[/* todos */3], (function (param) {
                      var todo = param[1];
                      var transition = param[0];
                      var match = Caml_obj.caml_equal(todo, todoToToggle);
                      if (match !== 0) {
                        return /* tuple */[
                                transition,
                                /* record */[
                                  /* id */todo[/* id */0],
                                  /* title */todo[/* title */1],
                                  /* completed */1 - todo[/* completed */2]
                                ]
                              ];
                      } else {
                        return /* tuple */[
                                transition,
                                todo
                              ];
                      }
                    }));
              return /* UpdateWithSideEffects */Block.__(3, [
                        /* record */[
                          /* nowShowing */state[/* nowShowing */0],
                          /* editing */state[/* editing */1],
                          /* newTodo */state[/* newTodo */2],
                          /* todos */todos$5
                        ],
                        (function () {
                            return saveLocally(todos$5);
                          })
                      ]);
          case 7 : 
              var checked = action[0];
              var todos$6 = Belt_List.map(state[/* todos */3], (function (param) {
                      var todo = param[1];
                      return /* tuple */[
                              param[0],
                              /* record */[
                                /* id */todo[/* id */0],
                                /* title */todo[/* title */1],
                                /* completed */checked
                              ]
                            ];
                    }));
              return /* UpdateWithSideEffects */Block.__(3, [
                        /* record */[
                          /* nowShowing */state[/* nowShowing */0],
                          /* editing */state[/* editing */1],
                          /* newTodo */state[/* newTodo */2],
                          /* todos */todos$6
                        ],
                        (function () {
                            return saveLocally(todos$6);
                          })
                      ]);
          
        }
      }
    });
  newrecord[/* subscriptions */13] = (function (self) {
      return /* :: */[
              /* Sub */[
                (function () {
                    return ReasonReact.Router[/* watchUrl */1]((function (url) {
                                  return Curry._1(self[/* send */4], /* Navigate */Block.__(0, [urlToShownPage(url[/* hash */1])]));
                                }));
                  }),
                ReasonReact.Router[/* unwatchUrl */2]
              ],
              /* [] */0
            ];
    });
  return newrecord;
}

var Top = /* module */[
  /* urlToShownPage */urlToShownPage,
  /* component */component,
  /* make */make
];

ReactDOMRe.renderToElementWithClassName(ReasonReact.element(/* None */0, /* None */0, make(/* array */[])), "todoapp");

exports.mergeDiff = mergeDiff;
exports.RR2 = RR2;
exports.localStorageNamespace = localStorageNamespace;
exports.saveLocally = saveLocally;
exports.Top = Top;
/* mergeDiff Not a pure module */
