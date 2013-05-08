/*
 * Author: Sonny Rajagopalan
 * E-mail: sonny.rajagopalan@gmail.com
 * Date of first creation: 04/05/2010
 *
 * Description:
 * Derived class for the closed state for a simple FSM.
 *
 * Note: We assume that nothing useful is done in the closed state.
 * In a real application, we could possibly clean up the Session
 * object for such sessions.
 */

#ifndef SFSM_CLOSEDSTATE_H
#define SFSM_CLOSEDSTATE_H

#include "Session.h"
#include "SFSMBaseState.h"

class SFSMClosedState : public SFSMBaseState
{
 public: 
  static SFSMBaseState* getInstance();
  virtual Session::SessionState getState();
  virtual void printStateName();
  virtual ~SFSMClosedState();

 private:
  SFSMClosedState(); // Only the getInstance method will get access to this
  static SFSMBaseState* instance;
};

#endif
