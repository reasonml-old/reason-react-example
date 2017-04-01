type userId = int;

type userStatus =
  | Offline
  | Online
  | Away;

type debug = {botTalkEnabled: bool};

type user = {id: userId, email: string, name: option string, status: userStatus, username: string};

type message = {content: string, userId, createdAt: float};

type channelId = int;

module UserIdType = {
  type t = userId;
  let compare = compare;
};

module UserIdSet = Set.Make UserIdType;

type mediaPlayerState =
  | Playing
  | Paused
  | NotLoaded;

type timeRange = array (float, float);

type media = {
  order: int,
  src: option string,
  duration: option int,
  buffered: option timeRange,
  seekable: option timeRange
};

type mediaRepeatSetting =
  | Off
  | One
  | All;

type channel = {
  id: channelId,
  title: string,
  loading: bool,
  activities: list message,
  userIds: UserIdSet.t,
  media,
  mediaState: mediaPlayerState,
  /* 0.0 => 1.0 */
  mediaProgress: int,
  mediaLoadProgress: option timeRange,
  mediaScrubbedTo: option (float, float),
  mediaRepeat: mediaRepeatSetting,
  playlist: list media
};

type side =
  | Left
  | Right;

type appState = {
  rightSidebarOpen: bool,
  leftSidebarOpen: bool,
  selectedChannelId: channelId,
  userId: option userId,
  users: list user,
  channels: list channel,
  userMessageFocused: bool,
  searchFormFocused: bool,
  userMenuOpen: bool,
  search: option string,
  title: string,
  volume: float,
  lastVolume: float,
  debug
};

type emoji = {key: string, src: string, css: string, title: string};

module EmojiPairs = Map.Make String;

type action =
  | SearchFormFocused bool
  | SidebarToggled side bool
  | SearchUpdated (option string)
  | ChannelSelected channel
  | ChannelSelectedByIndex int
  | SongSelected channel media
  | MediaStateUpdated channel mediaPlayerState
  | MediaPlayerScrubbed channel float float
  | MediaPlaybackFinished channel
  | MediaProgressUpdated channel int int
  | MediaLoadProgressUpdated channel timeRange timeRange
  | ChatBoxFocused bool
  | UserMenuToggled bool
  | MsgSubmitted channel message
  | VolumeSet float
  | VolumeIncremented float
  | VolumeDecremented float
  | VolumeMuteToggled
  | UriNavigated string
  | BotTalkToggled bool
  | Log string
  | Alert string;

let stringOfAction (action: action) =>
  switch action {
  | SearchFormFocused _ => "SearchFormFocused"
  | SidebarToggled _ _ => "SidebarToggled"
  | SearchUpdated _ => "SearchUpdated"
  | ChannelSelected _ => "ChannelSelected"
  | ChannelSelectedByIndex _ => "ChannelSelectedByIndex"
  | SongSelected _ _ [@implicit_arity] => "SongSelected"
  | MediaStateUpdated _ _ [@implicit_arity] => "MediaStateUpdated"
  | MediaPlaybackFinished _ => "MediaPlaybackFinished"
  | MediaPlayerScrubbed _ _ _ => "MediaPlayerScrubbed"
  | MediaProgressUpdated channel _ _ => "MediaProgressUpdated on " ^ channel.title
  | MediaLoadProgressUpdated channel _ _ => "MediaLoadProgressUpdated on " ^ channel.title
  | ChatBoxFocused _ => "ChatBoxFocused"
  | UserMenuToggled _ => "UserMenuToggled"
  | MsgSubmitted _ _ [@implicit_arity] => "MsgSubmitted"
  | VolumeSet _ => "VolumeSet"
  | VolumeIncremented _ => "VolumentIncremented"
  | VolumeDecremented _ => "VolumentDecremented"
  | VolumeMuteToggled => "VolumeMuteToggled"
  | UriNavigated _ => "UriNavigated"
  | BotTalkToggled _ => "BotTalkToggled"
  | Log _ => "Log"
  | Alert _ => "Alert"
  };
