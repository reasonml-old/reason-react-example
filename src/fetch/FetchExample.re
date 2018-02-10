type dog = string;

type arrayDogs = array(dog);

type state = { dogs: arrayDogs, isLoading: bool, error: bool };

type action =
  | DogsFetch
  | DogsFetched(arrayDogs)
  | DogsFailedToFetch;

module Decode = {
  let dogs = json : arrayDogs =>
  Json.Decode.(
    json |> field("message", array(string))
         |> Array.map(dog => dog)
  );
};

let component = ReasonReact.reducerComponent("FetchExample");

let make = _children => {
  ...component,
  initialState: () => { dogs: [||], isLoading: true, error: false },
  reducer: (action, state) => 
    switch action {
    | DogsFetch =>
        ReasonReact.SideEffects(self => 
          Js.Promise.(
            Fetch.fetch("https://dog.ceo/api/breeds/list")
            |> then_(Fetch.Response.json)
            |> then_(json => 
              json
                |> Decode.dogs
                |> (dogs => {
                  self.send(DogsFetched(dogs));
                })
            |> resolve)
            |> catch(_err => Js.Promise.resolve(self.send(DogsFailedToFetch)) )
          |> ignore )
        )
    | DogsFetched(dogs) =>
      ReasonReact.Update({
        ...state,
        isLoading: false,
        dogs
      })
    | DogsFailedToFetch => 
      ReasonReact.Update({
        ...state,
        error: true
      })
    },
  didMount: self => {
    self.send(DogsFetch);
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
            |> Array.mapi((_index, dog) =>
              <li key={dog}>
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
