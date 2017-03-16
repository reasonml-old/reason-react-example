module Navbar = {
  include ReactRe.Component;
  let name = "Navbar";
  type props = {
    selectedChannelId: State.channelId,
    channels: list State.channel,
    onChannelSelected: State.channel => ReactRe.event => unit,
    focused: bool,
    onFocus: bool => ReactRe.event => unit,
    onSearchUpdated: ReactRe.event => unit,
    searchTerm: option string
  };
  let render {props} => {
    let tabs =
      props.channels |>
      List.map (
        fun (channel: State.channel) =>
          <li
            key=(string_of_int channel.id)
            onClick=(props.onChannelSelected channel)
            className=(
                        "protected example" ^ (
                          if (props.selectedChannelId === State.(channel.id)) {
                            " active"
                          } else {
                            ""
                          }
                        )
                      )>
            <a className="show_channel">
              <span> (ReactRe.stringToElement channel.title) </span>
            </a>
          </li>
      );
    <nav className=("nav" ^ (props.focused ? " search-focus" : ""))>
      <form action="/search" className="search" method="get">
        <input
          onBlur=(props.onFocus false)
          onFocus=(props.onFocus true)
          className="query"
          name="query"
          _type="text"
          value=(
                  switch props.searchTerm {
                  | None => ""
                  | Some term => term
                  }
                )
          onChange=props.onSearchUpdated
          onKeyDown=(
                      fun event =>
                        if (event##which == 13) {
                          event##preventDefault ()
                        }
                    )
        />
        <input className="submit" _type="submit" value="Search" />
      </form>
      <ul id="channel_nav"> (ReactRe.arrayToElement (Array.of_list tabs)) </ul>
    </nav>
  };
};

include ReactRe.CreateComponent Navbar;

let createElement
    ::selectedChannelId
    ::channels
    ::onChannelSelected
    ::onFocus
    ::focused
    ::onSearchUpdated
    ::searchTerm =>
  wrapProps {
    selectedChannelId,
    channels,
    onChannelSelected,
    onFocus,
    focused,
    onSearchUpdated,
    searchTerm
  };
