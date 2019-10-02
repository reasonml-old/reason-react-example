[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

// === Actual component logic ===
type state =
  | LoadingDogs
  | ErrorFetchingDogs
  | LoadedDogs(array(string));

[@react.component]
let make = () => {
  let (state, setState) = React.useState(() => LoadingDogs);

  // TODO: explain the 0 part
  React.useEffect0(() => {
    Js.Promise.(
      fetch("https://dog.ceo/api/breeds/image/random/3")
      |> then_(response => {
        response##json();
      })
      |> then_(jsonResponse => {
        Js.log(jsonResponse);
        setState(_previousState => LoadedDogs(jsonResponse##message));
        Js.Promise.resolve();
      })
      |> catch(_err => {
        setState(_previousState => ErrorFetchingDogs);
        Js.Promise.resolve();
      })
      |>ignore
    );

    // Returning None means we don't have
    None;
  });

  switch (state) {
  | ErrorFetchingDogs => <div> (React.string("An error occurred!")) </div>
  | LoadingDogs => <div> (React.string("Loading...")) </div>
  | LoadedDogs(dogs) =>
    <>
      // <div style={
      //   ReactDOMRe.Style.make(
      //     ~marginBottom="8px",
      //     ()
      //   )}
      // >
      // Dog pictures, asynchronously loaded from https://dog.ceo
        // (React.string("Dog pictures, asynchronously loaded from "))
        // <a href="https://dog.ceo">
        //   (React.string("https://dog.ceo"))
        // </a>
      // </div>
      <div>
        (
          Belt.Array.map(dogs, dog => {
            <img key=dog src=dog style={ReactDOMRe.Style.make(
              ~height="120px",
              ~borderRadius="8px",
              ~marginRight="8px",
              ~boxShadow="rgb(218, 218, 218) 0px 4px 4px",
              ())} />
          }
          )
          -> React.array
        )
      </div>
    </>
  }
};
