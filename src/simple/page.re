let component = ReasonReact.statelessComponent "Page";

let handleClick _event _ _ => Js.log "clicked!";

let make ::message _children => {
  ...component,
  render: fun () self =>
    <div onClick=(self.handle handleClick)> (ReasonReact.stringToElement message) </div>
};
