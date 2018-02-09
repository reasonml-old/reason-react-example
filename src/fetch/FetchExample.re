type tDog = string;

type tArrayDogs = array(tDog);

type state = { dogs: tArrayDogs, isLoading: bool, error: bool };

type action =
  | DogFetch
  | DogFetched(tArrayDogs)
  | DogFailedToFetch;

let component = ReasonReact.reducerComponent("FetchExample");

module Decode = {
  let dogs = json : tArrayDogs =>
    Array.map(
      dog => dog,
      json |> Json.Decode.field("message", 
        Json.Decode.array(Json.Decode.string)
      )
    );
};

let make = _children => {
  ...component,
  initialState: () => { dogs: [||], isLoading: false, error: false },
  reducer: (action, state) => 
    switch action {
    | DogFetch =>
        ReasonReact.Update({
          ...state,
          isLoading: true
        })
    | DogFetched(dogs) =>
      ReasonReact.Update({
        ...state,
        isLoading: false,
        dogs
      })
    | DogFailedToFetch => 
      ReasonReact.Update({
        ...state,
        error: true
      })
    },
  didMount: self => {
    self.send(DogFetch);

    Js.Promise.(
      Fetch.fetch("https://dog.ceo/api/breeds/list")
      |> then_(Fetch.Response.json)
      |> then_(json => {
        json
          |> Decode.dogs
          |> (dogs => {
            self.send(DogFetched(dogs));
          })
      }
      |> resolve)
      |> catch(_err => Js.Promise.resolve(self.send(DogFailedToFetch)) )
    |> ignore );
    ReasonReact.NoUpdate
  },
  render: self => {
    switch (self.state.error, self.state.isLoading) {
      | (true, _) => 
      <div>
          (ReasonReact.stringToElement("An error occurred!"))
        </div>
      | (false, true) =>
        <div>
          (ReasonReact.stringToElement("Loading..."))
        </div>
      | (false, false) => 
        <div>
          <h1>
            (ReasonReact.stringToElement("Dogs"))
          </h1>
          <ul>
          (
            self.state.dogs
            |> Array.mapi((index, dog) =>
              <li key={string_of_int(index)}>
                (ReasonReact.stringToElement(dog))
              </li>
            )
            |> ReasonReact.arrayToElement
          )
          </ul>
        </div>
    }
  }
};
