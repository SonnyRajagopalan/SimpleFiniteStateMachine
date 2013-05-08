/*
 * Author: Sonny Rajagopalan
 * E-mail: sonny.rajagopalan@gmail.com
 * Date of first creation: 04/05/2010
 *
 * Description:
 * Derived class for wait for authentication resolution state for a simple FSM
 */

#ifndef SFSM_WAITFORAUTH_H
#define SFSM_WAITFORAUTH_H

#include "Session.h"
#include "SFSMBaseState.h"

class SFSMWaitForAuthState : public SFSMBaseState
{
 public: 
  static SFSMBaseState* getInstance();
  virtual Session::SessionState getState();
  virtual ~SFSMWaitForAuthState();

  virtual void processAuthResult(Session* pSession, int authResult); // Auth result: 1 = OK, 0 = Not OK.
  virtual void printStateName();
 private:
  SFSMWaitForAuthState(); // Only the getInstance method will get access to this
  static SFSMBaseState* instance;
};

#endif
