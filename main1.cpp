/*
 * Author: Sonny Rajagopalan
 * E-mail: sonny.rajagopalan@gmail.com
 * Date of first creation: 04/05/2010
 * 
 * Description:
 * Main file for example of a simple FSM showing transitions from
 * (a) Dormant->WaitForAuthentication upon connection request;
 * (b) WaitForAuthentication to Connected upon authentication success;
 * (c) WaitForAuthentication to Closed state upon authentication failure; and
 * (d) Connected to dormant upon connection close/termination notification.
 * 
 */
#include <iostream>
#include "Session.h"
#include "SFSMBaseState.h"
#include "SFSMDormantState.h"
#include "SFSMWaitForAuthState.h"
#include "SFSMConnectedState.h"
#include "SFSMClosedState.h"
#include "SFSMConnectedState.h"

using namespace std;

int main()
{
  int i=0;
  Session* sessions[100];
  SFSMBaseState* dormantStateInstance     = SFSMDormantState::getInstance();
  SFSMBaseState* waitForAuthStateInstance = SFSMWaitForAuthState::getInstance();
  SFSMBaseState* connectedStateInstance   = SFSMConnectedState::getInstance();

  // In a real application, these session objects will come from, say,
  // a memory pool, and will be created as new users come in;
  // not arbitraily, like this example
  for (i=0; i < 100; i++)
    {
      sessions[i] = new Session();
    }

  // The following transitions are also "bogus," in the sense that
  // typically the state transitions occur on the basis of events
  // and these events cannot typically be blocking the whole system.
  // In other words, we need a notion of timers, callbacks, and
  // queues to take this example to the next level of sophistication.
  //
  // Another way of looking at these state transitions is that
  // these transitions happen after a timer expires or when
  // a message is received from a remote machine or even a locally
  // running remote task;  most likely, all of these transitions
  // will require one or all of timers, callbacks and message queues.
  // I have skipped those sophisticated aspects of FSM design here.

  sessions[23]->getSessionStats();
  cout << "Printing state name:" << endl;
  sessions[23]->getCurrentState()->printStateName(); // Dormant state
  cout << "A valid transition:" << endl;
  sessions[23]->getCurrentState()->processConnectRequest(sessions[23]); // Valid call in this state
  // The statement above will call the following changeState():
  // sessions[23]->changeState(waitForAuthStateInstance, Session::WAITFORAUTH);
  // Also, the above (uncommented) statement is the same as the following statement:
  // dormantStateInstance->processConnectRequest(sessions[23]);

  cout << "Printing state name after (expected) state change..." << endl;
  sessions[23]->getCurrentState()->printStateName();  
  
  // Now, we are in the wait for authentication state

  sessions[23]->getCurrentState()->processAuthResult(sessions[23], 1); // Valid call in this state
  // Now, the following statement will not bomb, but only because we have a
  // base class catchall method for processConnectRequest().
  // Note that the previous statement (processAuthResult()) had actually
  // changed the state of the Session object to ConnectedState.
  sessions[23]->getCurrentState()->processConnectRequest(sessions[23]);
}
