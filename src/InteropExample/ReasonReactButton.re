// TODO: explain we don't encourage that many layers of indirection

let style = ReactDOMRe.Style.make(
  ~backgroundColor="rgba(0, 0, 0, 0.05)",
  ~borderRadius="4px",
  ~padding="12px",
  ()
);

[@react.component]
let make = () => {
  // TODO: explain camelCase
  <div style>
    (React.string("This is a ReasonReact card"))
  </div>;
};
