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
      |> then_(response => response##json())
      |> then_(jsonResponse => {
           Js.log(jsonResponse);
           setState(_previousState => LoadedDogs(jsonResponse##message));
           Js.Promise.resolve();
         })
      |> catch(_err => {
           setState(_previousState => ErrorFetchingDogs);
           Js.Promise.resolve();
         })
      |> ignore
    );

    // TODO: Returning None means we don't have any cleanup to do before unmounting. That's not 100% true
    None;
  });

  switch (state) {
  | ErrorFetchingDogs => <div> {React.string("An error occurred!")} </div>
  | LoadingDogs => <div> {React.string("Loading...")} </div>
  | LoadedDogs(dogs) =>
    <>
      <div>
        {Belt.Array.map(dogs, dog =>
           <img
             key=dog
             src=dog
             style={ReactDOMRe.Style.make(
               ~height="120px",
               ~borderRadius="8px",
               ~marginRight="8px",
               ~boxShadow="rgb(218, 218, 218) 0px 4px 4px",
               (),
             )}
           />
         )
         ->React.array}
      </div>
    </>
  };
};
