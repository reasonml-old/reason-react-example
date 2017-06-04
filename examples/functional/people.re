module Person = {
  let component = ReasonReact.createComponent "Person";
  let make ::name ::age _children => {
    ...component,
    render: fun _state _self =>
      ReasonReact.stringToElement (name ^ " is " ^ string_of_int age ^ "years old")
  };
};

module Mary = {
  let make = Person.make name::"Mary" age::42;
};

let awesomePeople = <div> <Person name="Mario" age=12 /> <Mary /> </div>;

let listOfPeople people => <div> (ReasonReact.arrayToElement people) </div>;

let awesomePeople2 = {
  let mario = <Person name="Mario" age=12 />;
  let mary = <Mary />;
  listOfPeople [|mary, mario, mary|]
};
