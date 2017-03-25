external refToDom : ReactRe.reactRef => Dom.element = "%identity";

module AudioElement = {
  type t;
  external ofDom : Dom.element => t = "%identity";
  external toDom : t => Dom.element = "%identity";
  external load : t => unit = "load" [@@bs.send];
  external play : t => unit = "play" [@@bs.send];
  external pause : t => unit = "pause" [@@bs.send];
  external paused : t => Js.boolean = "paused" [@@bs.get];
  external setVolume : t => float => unit = "volume" [@@bs.set];
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

module Audio_player = {
  include ReactRe.Component.Stateful.InstanceVars;
  type instanceVars = {mutable domRef: option Dom.element};
  type state = unit;
  let getInitialState _ => ();
  let name = "AudioPlayer";
  type props = {
    id: int,
    channel: State.channel,
    audioState: State.mediaPlayerState,
    volume: float
  };
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
      }
    };
    None
  };
  let setAudioRef {instanceVars} r => instanceVars.domRef = Some r;
  let render {props, handler} =>
    <div style=(ReactDOMRe.Style.make display::"block" ())>
      <audio
        className=("audio-player audio-" ^ string_of_int props.channel.id)
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

let createElement ::channel ::id ::volume ::audioState =>
  wrapProps {channel, id, audioState, volume};
