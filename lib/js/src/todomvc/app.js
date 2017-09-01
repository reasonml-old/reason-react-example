'use strict';

var List                              = require("bs-platform/lib/js/list.js");
var $$Array                           = require("bs-platform/lib/js/array.js");
var Block                             = require("bs-platform/lib/js/block.js");
var Curry                             = require("bs-platform/lib/js/curry.js");
var React                             = require("react");
var $$String                          = require("bs-platform/lib/js/string.js");
var Caml_obj                          = require("bs-platform/lib/js/caml_obj.js");
var TodoItem                          = require("./todoItem.js");
var Js_boolean                        = require("bs-platform/lib/js/js_boolean.js");
var Pervasives                        = require("bs-platform/lib/js/pervasives.js");
var ReactDOMRe                        = require("reason-react/lib/js/src/reactDOMRe.js");
var TodoFooter                        = require("./todoFooter.js");
var ReasonReact                       = require("reason-react/lib/js/src/reasonReact.js");
var Director$slashbuild$slashdirector = require("director/build/director");

var namespace = "reason-react-todos";

function saveLocally(todos) {
  var match = JSON.stringify(todos);
  if (match !== undefined) {
    localStorage.setItem(namespace, match);
    return /* () */0;
  } else {
    return /* () */0;
  }
}

function changeTodo($$event) {
  return /* ChangeTodo */Block.__(0, [$$event.target.value]);
}

function newTodoKeyDown($$event) {
  if ($$event.keyCode === 13) {
    $$event.preventDefault();
    return /* NewTodoEnterKeyDown */3;
  } else {
    return /* NewTodoOtherKeyDown */4;
  }
}

function toggleAll($$event) {
  var checked = +$$event.target.checked;
  return /* ToggleAll */Block.__(5, [checked]);
}

function toggle(todo, _) {
  return /* Toggle */Block.__(4, [todo]);
}

function destroy(todo, _) {
  return /* Destroy */Block.__(3, [todo]);
}

function edit(todo, _) {
  return /* Edit */Block.__(2, [todo]);
}

function save(todoToSave, text) {
  return /* Save */Block.__(1, [
            todoToSave,
            text
          ]);
}

function cancel() {
  return /* Cancel */6;
}

function clearCompleted() {
  return /* ClearCompleted */5;
}

var component = ReasonReact.reducerComponent("TodoAppRe");

function make() {
  var newrecord = component.slice();
  newrecord[/* didMount */4] = (function (param) {
      var reduce = param[/* reduce */3];
      var router = new Director$slashbuild$slashdirector.Router({
            "/": Curry._1(reduce, (function () {
                    return /* ShowAll */0;
                  })),
            "/active": Curry._1(reduce, (function () {
                    return /* ShowActive */1;
                  })),
            "/completed": Curry._1(reduce, (function () {
                    return /* ShowCompleted */2;
                  }))
          });
      router.init("/");
      return /* NoUpdate */0;
    });
  newrecord[/* render */9] = (function (param) {
      var state = param[/* state */4];
      var todos = state[/* todos */3];
      var editing = state[/* editing */1];
      var reduce = param[/* reduce */3];
      var todoItems = List.map((function (todo) {
              var editing$1 = editing ? +(editing[0] === todo[/* id */0]) : /* false */0;
              return ReasonReact.element(/* Some */[todo[/* id */0]], /* None */0, TodoItem.make(todo, editing$1, Curry._1(reduce, (function () {
                                    return /* Destroy */Block.__(3, [todo]);
                                  })), Curry._1(reduce, (function (param) {
                                    return /* Save */Block.__(1, [
                                              todo,
                                              param
                                            ]);
                                  })), Curry._1(reduce, (function () {
                                    return /* Edit */Block.__(2, [todo]);
                                  })), Curry._1(reduce, (function () {
                                    return /* Toggle */Block.__(4, [todo]);
                                  })), Curry._1(reduce, cancel), /* array */[]));
            }), List.filter((function (todo) {
                    var match = state[/* nowShowing */0];
                    switch (match) {
                      case 0 : 
                          return /* true */1;
                      case 1 : 
                          return 1 - todo[/* completed */2];
                      case 2 : 
                          return todo[/* completed */2];
                      
                    }
                  }))(todos));
      var todosLength = List.length(todos);
      var completedCount = List.length(List.filter((function (todo) {
                    return todo[/* completed */2];
                  }))(todos));
      var activeTodoCount = todosLength - completedCount | 0;
      var footer;
      var exit = 0;
      if (activeTodoCount !== 0 || completedCount !== 0) {
        exit = 1;
      } else {
        footer = null;
      }
      if (exit === 1) {
        footer = ReasonReact.element(/* None */0, /* None */0, TodoFooter.make(activeTodoCount, completedCount, state[/* nowShowing */0], Curry._1(reduce, clearCompleted), /* array */[]));
      }
      var match = +(todosLength === 0);
      var main = match !== 0 ? null : React.createElement("section", {
              className: "main"
            }, React.createElement("input", {
                  className: "toggle-all",
                  checked: Js_boolean.to_js_boolean(+(activeTodoCount === 0)),
                  type: "checkbox",
                  onChange: Curry._1(reduce, toggleAll)
                }), React.createElement("ul", {
                  className: "todo-list"
                }, $$Array.of_list(todoItems)));
      return React.createElement("div", undefined, React.createElement("header", {
                      className: "header"
                    }, React.createElement("h1", undefined, "todos"), React.createElement("input", {
                          className: "new-todo",
                          autoFocus: true,
                          placeholder: "What needs to be done?",
                          value: state[/* newTodo */2],
                          onKeyDown: Curry._1(reduce, newTodoKeyDown),
                          onChange: Curry._1(reduce, changeTodo)
                        })), main, footer);
    });
  newrecord[/* initialState */10] = (function () {
      var match = localStorage.getItem(namespace);
      var todos = match !== null ? JSON.parse(match) : /* [] */0;
      return /* record */[
              /* nowShowing : AllTodos */0,
              /* editing : None */0,
              /* newTodo */"",
              /* todos */todos
            ];
    });
  newrecord[/* reducer */12] = (function (action, state) {
      if (typeof action === "number") {
        switch (action) {
          case 0 : 
              return /* Update */Block.__(0, [/* record */[
                          /* nowShowing : AllTodos */0,
                          /* editing */state[/* editing */1],
                          /* newTodo */state[/* newTodo */2],
                          /* todos */state[/* todos */3]
                        ]]);
          case 1 : 
              return /* Update */Block.__(0, [/* record */[
                          /* nowShowing : ActiveTodos */1,
                          /* editing */state[/* editing */1],
                          /* newTodo */state[/* newTodo */2],
                          /* todos */state[/* todos */3]
                        ]]);
          case 2 : 
              return /* Update */Block.__(0, [/* record */[
                          /* nowShowing : CompletedTodos */2,
                          /* editing */state[/* editing */1],
                          /* newTodo */state[/* newTodo */2],
                          /* todos */state[/* todos */3]
                        ]]);
          case 3 : 
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
          case 4 : 
              return /* NoUpdate */0;
          case 5 : 
              var todos$1 = List.filter((function (todo) {
                        return 1 - todo[/* completed */2];
                      }))(state[/* todos */3]);
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
          case 6 : 
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
                          /* nowShowing */state[/* nowShowing */0],
                          /* editing */state[/* editing */1],
                          /* newTodo */action[0],
                          /* todos */state[/* todos */3]
                        ]]);
          case 1 : 
              var text = action[1];
              var todoToSave = action[0];
              var todos$2 = List.map((function (todo) {
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
                    }), state[/* todos */3]);
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
          case 2 : 
              return /* Update */Block.__(0, [/* record */[
                          /* nowShowing */state[/* nowShowing */0],
                          /* editing : Some */[action[0][/* id */0]],
                          /* newTodo */state[/* newTodo */2],
                          /* todos */state[/* todos */3]
                        ]]);
          case 3 : 
              var todo = action[0];
              var todos$3 = List.filter((function (candidate) {
                        return +(candidate !== todo);
                      }))(state[/* todos */3]);
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
          case 4 : 
              var todoToToggle = action[0];
              var todos$4 = List.map((function (todo) {
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
                    }), state[/* todos */3]);
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
          case 5 : 
              var checked = action[0];
              var todos$5 = List.map((function (todo) {
                      return /* record */[
                              /* id */todo[/* id */0],
                              /* title */todo[/* title */1],
                              /* completed */checked
                            ];
                    }), state[/* todos */3]);
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
  return newrecord;
}

var Top = /* module */[
  /* changeTodo */changeTodo,
  /* newTodoKeyDown */newTodoKeyDown,
  /* toggleAll */toggleAll,
  /* toggle */toggle,
  /* destroy */destroy,
  /* edit */edit,
  /* save */save,
  /* cancel */cancel,
  /* clearCompleted */clearCompleted,
  /* component */component,
  /* make */make
];

ReactDOMRe.renderToElementWithClassName(ReasonReact.element(/* None */0, /* None */0, make(/* array */[])), "todoapp");

exports.namespace   = namespace;
exports.saveLocally = saveLocally;
exports.Top         = Top;
/* component Not a pure module */
