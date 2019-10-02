// TODO: explain we don't encourage that many layers of indirection

[@react.component]
let make = (~label) => {
  // TODO: explain camelCase
  <button ariaLabel=label>
    {React.string(label)}
  </button>;
};
