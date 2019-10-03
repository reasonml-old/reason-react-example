[@bs.val] external fetch: string => Js.Promise.t('a) = "fetch";

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
           // TODO: Js.log(jsonResponse);
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

  <div
    style={ReactDOMRe.Style.make(
      ~height="120px",
      ~display="flex",
      ~alignItems="center",
      ~justifyContent="center",
      (),
    )}>
    {switch (state) {
     | ErrorFetchingDogs => React.string("An error occurred!")
     | LoadingDogs => React.string("Loading...")
     | LoadedDogs(dogs) =>
       dogs
       ->Belt.Array.mapWithIndex((i, dog) => {
          let imageStyle = ReactDOMRe.Style.make(
            ~height="120px",
            ~width="100%",
            ~marginRight=(i === Js.Array.length(dogs) - 1 ? "0px" : "8px"),
            ~borderRadius="8px",
            ~boxShadow="0px 4px 16px rgb(200, 200, 200)",
            ~backgroundSize="cover",
            ~backgroundImage={j|url($dog)|j},
            ~backgroundPosition="center",
            (),
          );
          <div key=dog style=imageStyle />
        })
       ->React.array
     }}
  </div>;
};
