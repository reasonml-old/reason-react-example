/***
 * RemoteAction provides a way to send actions to a remote component.
 * The sender creates a fresh RemoteAction and passes it down.
 * The recepient component calls subscribe in the didMount method.
 * The caller can then send actions to the recipient components via send.
 */
type t('action);

type token('action);


/*** Create a new remote action, to which one component will subscribe. */
let create: unit => t('action);


/***
 * Subscribe to the remote action, via the component's `send` function.
 * Returns an unsubscribe token which can be used to end the connection
 * to this particular send function. Will only return a token if the remote
 * action passed does not already have an active subscription.
 */
let subscribe:
  (~send: 'action => unit, t('action)) => option(token('action));


/*** Unsubscribe from a subscription  */
let unsubscribe: token('action) => unit;


/*** Perform an action on the subscribed component. */
let send: (t('action), ~action: 'action) => unit;