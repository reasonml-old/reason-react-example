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
      json |> field("message", array(string)) |> Array.map(dog => dog)
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
  didMount: self => {
    self.send(DogsFetch);
    ReasonReact.NoUpdate;
  },
  render: self =>
    switch (self.state) {
    | Error =>
      <div> (ReasonReact.stringToElement("An error occurred!")) </div>
    | Loading => <div> (ReasonReact.stringToElement("Loading...")) </div>
    | Loaded(dogs) =>
      <div>
        <h1> (ReasonReact.stringToElement("Dogs")) </h1>
        <p> (ReasonReact.stringToElement("Source: ")) </p>
        <a href="https://dog.ceo">
          (ReasonReact.stringToElement("https://dog.ceo"))
        </a>
        <ul>
          (
            dogs
            |> Array.map(dog =>
                 <li key=dog> (ReasonReact.stringToElement(dog)) </li>
               )
            |> ReasonReact.arrayToElement
          )
        </ul>
      </div>
    },
};
