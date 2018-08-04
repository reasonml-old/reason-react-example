'use strict';


var defaultSecondsPerFrame = 1 / 60;

var noWobble = /* record */[
  /* stiffness */170,
  /* damping */26
];

function createState(value) {
  return /* record */[
          /* value */value,
          /* velocity */0,
          /* finalValue */value
        ];
}

function stepper($staropt$star, speedup, $staropt$star$1, $staropt$star$2, state) {
  var finalValue = state[/* finalValue */2];
  var velocity = state[/* velocity */1];
  var value = state[/* value */0];
  var secondsPerFrame = $staropt$star !== undefined ? $staropt$star : defaultSecondsPerFrame;
  var precision = $staropt$star$1 !== undefined ? $staropt$star$1 : 0.01;
  var preset = $staropt$star$2 !== undefined ? $staropt$star$2 : noWobble;
  var secondsPerFrame$1 = speedup !== undefined ? secondsPerFrame * speedup : secondsPerFrame;
  var forceSpring = -preset[/* stiffness */0] * (value - finalValue);
  var forceDamper = -preset[/* damping */1] * velocity;
  var acceleration = forceSpring + forceDamper;
  var newVelocity = velocity + acceleration * secondsPerFrame$1;
  var newValue = value + newVelocity * secondsPerFrame$1;
  var match = Math.abs(newVelocity) < precision && Math.abs(newValue - finalValue) < precision;
  if (match) {
    return /* record */[
            /* value */finalValue,
            /* velocity */0.0,
            /* finalValue */state[/* finalValue */2]
          ];
  } else {
    return /* record */[
            /* value */newValue,
            /* velocity */newVelocity,
            /* finalValue */state[/* finalValue */2]
          ];
  }
}

function isFinished(param) {
  if (param[/* value */0] === param[/* finalValue */2]) {
    return param[/* velocity */1] === 0;
  } else {
    return false;
  }
}

function test() {
  var _state = /* record */[
    /* value */0.0,
    /* velocity */0.0,
    /* finalValue */1.0
  ];
  while(true) {
    var state = _state;
    console.log(state);
    if (isFinished(state)) {
      return 0;
    } else {
      _state = stepper(undefined, undefined, undefined, undefined, state);
      continue ;
    }
  };
}

var defaultPrecision = 0.01;

var gentle = /* record */[
  /* stiffness */120,
  /* damping */14
];

var wobbly = /* record */[
  /* stiffness */180,
  /* damping */12
];

var stiff = /* record */[
  /* stiffness */210,
  /* damping */20
];

var defaultPreset = noWobble;

exports.defaultSecondsPerFrame = defaultSecondsPerFrame;
exports.defaultPrecision = defaultPrecision;
exports.noWobble = noWobble;
exports.gentle = gentle;
exports.wobbly = wobbly;
exports.stiff = stiff;
exports.defaultPreset = defaultPreset;
exports.createState = createState;
exports.stepper = stepper;
exports.isFinished = isFinished;
exports.test = test;
/* No side effect */
