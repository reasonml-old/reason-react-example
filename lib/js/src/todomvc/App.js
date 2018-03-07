'use strict';

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

var localStorageNamespace = "reason-react-todos";

function saveLocally(todos) {
  var match = JSON.stringify(todos);
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
      var __x = Belt_List.keep(todos, (function (todo) {
              var match = state[/* nowShowing */0];
              switch (match) {
                case 0 : 
                    return /* true */1;
                case 1 : 
                    return 1 - todo[/* completed */2];
                case 2 : 
                    return todo[/* completed */2];
                
              }
            }));
      var todoItems = Belt_List.map(__x, (function (todo) {
              var editing$1 = editing ? +(editing[0] === todo[/* id */0]) : /* false */0;
              return ReasonReact.element(/* Some */[todo[/* id */0]], /* None */0, TodoItem.make(todo, editing$1, (function () {
                                return Curry._1(send, /* Destroy */Block.__(4, [todo]));
                              }), (function (text) {
                                return Curry._1(send, /* Save */Block.__(2, [
                                              todo,
                                              text
                                            ]));
                              }), (function () {
                                return Curry._1(send, /* Edit */Block.__(3, [todo]));
                              }), (function () {
                                return Curry._1(send, /* Toggle */Block.__(5, [todo]));
                              }), (function () {
                                return Curry._1(send, /* Cancel */3);
                              }), /* array */[]));
            }));
      var todosLength = Belt_List.length(todos);
      var completedCount = Belt_List.length(Belt_List.keep(todos, (function (todo) {
                  return todo[/* completed */2];
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
                      return Curry._1(send, /* ToggleAll */Block.__(6, [checked]));
                    })
                }), React.createElement("ul", {
                  className: "todo-list"
                }, Belt_List.toArray(todoItems)));
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
              /* todos */todos
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
                      /* record */[
                        /* id */Pervasives.string_of_float(Date.now()),
                        /* title */nonEmptyValue,
                        /* completed : false */0
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
              var todos$1 = Belt_List.keep(state[/* todos */3], (function (todo) {
                      return 1 - todo[/* completed */2];
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
              var todos$2 = Belt_List.map(state[/* todos */3], (function (todo) {
                      var match = Caml_obj.caml_equal(todo, todoToSave);
                      if (match !== 0) {
                        return /* record */[
                                /* id */todo[/* id */0],
                                /* title */text,
                                /* completed */todo[/* completed */2]
                              ];
                      } else {
                        return todo;
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
              var todos$3 = Belt_List.keep(state[/* todos */3], (function (candidate) {
                      return +(candidate !== todo);
                    }));
              return /* UpdateWithSideEffects */Block.__(3, [
                        /* record */[
                          /* nowShowing */state[/* nowShowing */0],
                          /* editing */state[/* editing */1],
                          /* newTodo */state[/* newTodo */2],
                          /* todos */todos$3
                        ],
                        (function () {
                            return saveLocally(todos$3);
                          })
                      ]);
          case 5 : 
              var todoToToggle = action[0];
              var todos$4 = Belt_List.map(state[/* todos */3], (function (todo) {
                      var match = Caml_obj.caml_equal(todo, todoToToggle);
                      if (match !== 0) {
                        return /* record */[
                                /* id */todo[/* id */0],
                                /* title */todo[/* title */1],
                                /* completed */1 - todo[/* completed */2]
                              ];
                      } else {
                        return todo;
                      }
                    }));
              return /* UpdateWithSideEffects */Block.__(3, [
                        /* record */[
                          /* nowShowing */state[/* nowShowing */0],
                          /* editing */state[/* editing */1],
                          /* newTodo */state[/* newTodo */2],
                          /* todos */todos$4
                        ],
                        (function () {
                            return saveLocally(todos$4);
                          })
                      ]);
          case 6 : 
              var checked = action[0];
              var todos$5 = Belt_List.map(state[/* todos */3], (function (todo) {
                      return /* record */[
                              /* id */todo[/* id */0],
                              /* title */todo[/* title */1],
                              /* completed */checked
                            ];
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

exports.localStorageNamespace = localStorageNamespace;
exports.saveLocally = saveLocally;
exports.Top = Top;
/* component Not a pure module */
