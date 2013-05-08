/*
 * Author: Sonny Rajagopalan
 * E-mail: sonny.rajagopalan@gmail.com
 * Date of first creation: 04/05/2010
 *
 * Description:
 * Base class for a simple FSM
 */
#ifndef SFSM_BASE_STATE_H
#define SFSM_BASE_STATE_H

#include "Session.h"

class SFSMBaseState
{
 public:
  // Not declared pure virtual because some of these base methods
  // will be used as "catchalls" when derived class methods won't
  // be called.
  virtual void printStateName();
  virtual void printSessionInformation(Session* pSession);
  virtual void processConnectRequest(Session* pSession);
  virtual void processAuthResult(Session* pSession, int authResult);
  virtual void processTerminateRequest(Session* pSession);
  char* getStateName();
  virtual Session::SessionState getState();
  SFSMBaseState(char*);

 protected:
  int changeState(Session* pSession, SFSMBaseState* pNextState);

 private:
  char stateName[40];
};

#endif
