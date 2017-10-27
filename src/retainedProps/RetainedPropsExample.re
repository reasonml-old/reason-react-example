/* The component's retainedProps type. It can be anything, including, commonly, being a record type */
/* retainedProps allows you to access the previous props information, like how ReactJS does it for you in lifecycle events */
type retainedProps = {message: string};

let component = ReasonReact.statelessComponentWithRetainedProps("RetainedPropsExample");

let make = (~message, _children) => {
  ...component,
  retainedProps: {message: message},
  didUpdate: ({oldSelf, newSelf}) =>
    if (oldSelf.retainedProps.message !== newSelf.retainedProps.message) {
      /* do whatever sneaky imperative things here */
      Js.log("props `message` changed!")
    },
  render: (_self) => <div> (ReasonReact.stringToElement(message)) </div>
};
