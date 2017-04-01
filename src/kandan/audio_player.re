module TimeRanges = {
  type t;
  external length : t => int = "" [@@bs.get];
  external start : t => int => float = "" [@@bs.send];
  external _end : t => int => float = "end" [@@bs.send];
};

module AudioElement = {
  type t;
  external ofDom : Dom.element => t = "%identity";
  external toDom : t => Dom.element = "%identity";
  external load : t => unit = "load" [@@bs.send];
  external play : t => unit = "play" [@@bs.send];
  external pause : t => unit = "pause" [@@bs.send];
  external paused : t => Js.boolean = "paused" [@@bs.get];
  external setVolume : t => float => unit = "volume" [@@bs.set];
  external currentTime : t => int = "" [@@bs.get];
  external duration : t => int = "" [@@bs.get];
  external setCurrentTime : t => int => unit = "currentTime" [@@bs.set];
  external buffered : t => TimeRanges.t = "" [@@bs.get];
  external seekable : t => TimeRanges.t = "" [@@bs.get];
};

let setAudioPlayerMedia (player: AudioElement.t) audioSrc => {
  Utils.setAttribute (AudioElement.toDom player) "src" audioSrc;
  AudioElement.paused player == Js.false_ ?
    {
      AudioElement.load player;
      ignore (Js.Global.setTimeout (fun _ => AudioElement.play player) 2500)
    } :
    AudioElement.load player
};

let throttleOneArg (quiet_interval_ms: float) fn => {
  let timeout: ref (option float) = ref None;
  let throttledFn fnArg1 =>
    switch !timeout {
    | None =>
      let now = Js.Date.now ();
      timeout := Some now;
      fn fnArg1
    | Some lastFired =>
      let now = Js.Date.now ();
      let elapsed = now -. lastFired;
      quiet_interval_ms < elapsed ?
        {
          timeout := Some now;
          fn fnArg1
        } :
        ()
    };
  throttledFn
};

/* TODO: Add optional handlers for all the other audio tag events */
module Audio_player = {
  include ReactRe.Component.Stateful.InstanceVars;
  type props = {
    id: int,
    channel: State.channel,
    audioState: State.mediaPlayerState,
    volume: float,
    onEnded: option (AudioElement.t => unit),
    onLoadProgress: option (AudioElement.t => TimeRanges.t => TimeRanges.t => unit),
    onTimeUpdated: AudioElement.t => unit,
    percent: option (float, float),
    time: option float,
    showBuffered: option bool
  };
  type instanceVars = {mutable domRef: option Dom.element};
  type state = {
    onEnded: option (AudioElement.t => unit),
    onTimeUpdated: AudioElement.t => unit,
    onLoadProgress: option (AudioElement.t => TimeRanges.t => TimeRanges.t => unit)
  };
  let getInitialState (props: props) => {
    onEnded: props.onEnded,
    onTimeUpdated: props.onTimeUpdated,
    onLoadProgress: props.onLoadProgress
  };
  let name = "AudioPlayer";
  let getInstanceVars () => {domRef: None};
  let componentDidUpdate ::prevProps ::prevState {props, instanceVars} => {
    ignore prevState;
    switch instanceVars.domRef {
    | None => ()
    | Some ref =>
      let player = AudioElement.ofDom ref;

      /** Check for:
       * State change
       * Src change
       * Volume change
       * Progress percent change (set time as a percent)
       * Time change (set time in seconds, beats progress)
        */
      if (
        prevProps.audioState != props.audioState ||
        prevProps.channel.media.src != props.channel.media.src
      ) {
        switch props.audioState {
        | NotLoaded => ()
        | Playing => AudioElement.play player
        | Paused => AudioElement.pause player
        }
      };
      if (prevProps.volume != props.volume) {
        AudioElement.setVolume player props.volume
      };
      switch props.percent {
      | None => ()
      | Some (percent, time) =>
        let offset = int_of_float (floor (float_of_int (AudioElement.duration player) *. percent));
        switch prevProps.percent {
        | None => AudioElement.setCurrentTime player offset
        | Some (_, oldTime) => oldTime == time ? () : AudioElement.setCurrentTime player offset
        }
      }
    };
    None
  };
  let setAudioRef {state, instanceVars} el => {
    instanceVars.domRef = Some el;
    let audioElement = AudioElement.ofDom el;
    ReasonJs.Dom.Element.addEventListener
      "timeupdate" (throttleOneArg 100.0 (fun _event => state.onTimeUpdated audioElement)) el;
    switch state.onLoadProgress {
    | None => ()
    | Some handler =>
      ReasonJs.Dom.Element.addEventListener
        "progress"
        (
          throttleOneArg
            100.0
            (
              fun _event =>
                handler
                  audioElement
                  (AudioElement.buffered audioElement)
                  (AudioElement.seekable audioElement)
            )
        )
        el
    };
    switch state.onEnded {
    | None => ()
    | Some handler =>
      ReasonJs.Dom.Element.addEventListener "ended" (fun _event => handler audioElement) el
    }
  };
  let render {props, handler} =>
    <div style=(ReactDOMRe.Style.make display::"block" ())>
      <audio
        className=(
                    "audio-player audio-" ^
                    string_of_int props.channel.id ^
                    " " ^ (
                      switch props.audioState {
                      | NotLoaded => "NotLoaded"
                      | Playing => "Playing"
                      | Paused => "Paused"
                      }
                    )
                  )
        src=(
              switch props.channel.media.src {
              | None => ""
              | Some src => src
              }
            )
        ref=(handler setAudioRef)
      />
    </div>;
};

include ReactRe.CreateComponent Audio_player;

let createElement
    ::channel
    ::id
    ::volume
    ::audioState
    ::onTimeUpdated
    ::percent
    ::time=?
    ::showBuffered=?
    ::onLoadProgress=?
    ::onEnded=? =>
  wrapProps {
    channel,
    id,
    audioState,
    volume,
    onEnded,
    onTimeUpdated,
    onLoadProgress,
    percent,
    time,
    showBuffered
  };
