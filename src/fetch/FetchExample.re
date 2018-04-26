/* The new stdlib additions */
open Belt;

type dog = string;

type state =
  | Loading
  | Error
  | Loaded(array(dog));

type action =
  | DogsFetch
  | DogsFetched(array(dog))
  | DogsFailedToFetch;

module Decode = {
  let dogs = json : array(dog) =>
    Json.Decode.(
      json |> field("message", array(string)) |> Array.map(_, dog => dog)
    );
};

let component = ReasonReact.reducerComponent("FetchExample");

let make = _children => {
  ...component,
  initialState: _state => Loading,
  reducer: (action, _state) =>
    switch (action) {
    | DogsFetch =>
      ReasonReact.UpdateWithSideEffects(
        Loading,
        (
          self =>
            Js.Promise.(
              Fetch.fetch("https://dog.ceo/api/breeds/list")
              |> then_(Fetch.Response.json)
              |> then_(json =>
                   json
                   |> Decode.dogs
                   |> (dogs => self.send(DogsFetched(dogs)))
                   |> resolve
                 )
              |> catch(_err =>
                   Js.Promise.resolve(self.send(DogsFailedToFetch))
                 )
              |> ignore
            )
        ),
      )
    | DogsFetched(dogs) => ReasonReact.Update(Loaded(dogs))
    | DogsFailedToFetch => ReasonReact.Update(Error)
    },
  didMount: self => self.send(DogsFetch),
  render: self =>
    switch (self.state) {
    | Error => <div> (ReasonReact.string("An error occurred!")) </div>
    | Loading => <div> (ReasonReact.string("Loading...")) </div>
    | Loaded(dogs) =>
      <div>
        <h1> (ReasonReact.string("Dogs")) </h1>
        <p> (ReasonReact.string("Source: ")) </p>
        <a href="https://dog.ceo">
          (ReasonReact.string("https://dog.ceo"))
        </a>
        <ul>
          (
            Array.map(dogs, dog =>
              <li key=dog> (ReasonReact.string(dog)) </li>
            )
            |> ReasonReact.array
          )
        </ul>
      </div>
    },
};
