type userId = int;

type userStatus =
  | Offline
  | Online
  | Away;

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

type media = {order: int, src: option string, duration: option int};

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
  mediaScrubbedTo: option (float, float),
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
  lastVolume: float
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
  | MediaProgressUpdated channel int int
  | ChatBoxFocused bool
  | UserMenuToggled bool
  | MsgSubmitted channel user message
  | AppTitleUpdated string int
  | VolumeSet float
  | VolumeIncremented float
  | VolumeDecremented float
  | VolumeMuteToggled
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
  | MediaPlayerScrubbed _ _ _ => "MediaPlayerScrubbed"
  | MediaProgressUpdated channel _ _ => "MediaProgressUpdated on " ^ channel.title
  | ChatBoxFocused _ => "ChatBoxFocused"
  | UserMenuToggled _ => "UserMenuToggled"
  | MsgSubmitted _ _ _ [@implicit_arity] => "MsgSubmitted"
  | AppTitleUpdated _ _ => "AppTitleUpdated"
  | VolumeSet _ => "VolumeSet"
  | VolumeIncremented _ => "VolumentIncremented"
  | VolumeDecremented _ => "VolumentDecremented"
  | VolumeMuteToggled => "VolumeMuteToggled"
  | Log _ => "Log"
  | Alert _ => "Alert"
  };
