module Navbar = {
  include ReactRe.Component;
  let name = "Navbar";
  type props = {
    selectedChannelId: State.channelId,
    channels: list State.channel,
    onChannelSelected: State.channel => unit,
    focused: bool,
    onFocus: bool => unit,
    onSearchUpdated: option string => unit,
    searchTerm: option string
  };
  let render {props} => {
    let tabs =
      props.channels |>
      List.map (
        fun (channel: State.channel) =>
          <li
            key=(string_of_int channel.id)
            onClick=(fun _event => props.onChannelSelected channel)
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
          onBlur=(fun _event => props.onFocus false)
          onFocus=(fun _event => props.onFocus true)
          className="query"
          name="query"
          _type="text"
          value=(
                  switch props.searchTerm {
                  | None => ""
                  | Some term => term
                  }
                )
          onChange=(
                     fun event => {
                       let x =
                         switch (
                           ReasonJs.Dom.HtmlElement.value (
                             Utils.domAsHtmlElement (ReactEventRe.Form.target event)
                           )
                         ) {
                         | "" => None
                         | term => Some term
                         };
                       props.onSearchUpdated x
                     }
                   )
          onKeyDown=(
                      fun event =>
                        if (ReactEventRe.Keyboard.which event == 13) {
                          ReactEventRe.Keyboard.preventDefault event
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
