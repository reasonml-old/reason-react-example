type t('action) = {mutable send: 'action => unit};

type token('action) = t('action);

let sendDefault = _action => ();

let create = () => {send: sendDefault};

/***
 * The return type of subscribe is constrained as a token
 * by the interface file. This means that only the caller of
 * a given RemoteAction has the ability to unsubscribe.
 */
let subscribe = (~send, x) =>
  if (x.send === sendDefault) {
    x.send = send;
    Some(x);
  } else {
    None;
  };

let unsubscribe = x => x.send = sendDefault;

let send = (x, ~action) => x.send(action);
