let component = ReasonReact.statelessComponent "Page";

let handleClick _event _self => Js.log "clicked!";

let make ::message _children => {
  ...component,
  render: fun {handle} =>
    <div onClick=(handle handleClick)> (ReasonReact.stringToElement message) </div>
};
