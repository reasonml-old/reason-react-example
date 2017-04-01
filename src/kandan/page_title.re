module Page_title = {
  include ReactRe.Component;
  type props = {title: string, dummy: option bool};
  let name = "PageTitle";
  let componentDidUpdate ::prevProps prevState::_ {props} => {
    if (prevProps.title != props.title) {
      Utils.setPageTitle props.title
    };
    None
  };
  let render _ => <span />;
  let componentDidMount {props} => {
    Utils.setPageTitle props.title;
    None
  };
};

include ReactRe.CreateComponent Page_title;

let createElement ::title ::dummy=? => wrapProps {title, dummy};
