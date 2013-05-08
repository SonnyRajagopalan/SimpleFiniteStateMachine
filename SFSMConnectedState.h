/*
 * Author: Sonny Rajagopalan
 * E-mail: sonny.rajagopalan@gmail.com
 * Date of first creation: 04/05/2010
 *
 * Description:
 * Derived class for connected state for a simple FSM
 */

#ifndef SFSM_CONNECTEDSTATE_H
#define SFSM_CONNECTEDSTATE_H

#include "Session.h"
#include "SFSMBaseState.h"

class SFSMConnectedState : public SFSMBaseState
{
 public: 
  static SFSMBaseState* getInstance();
  virtual Session::SessionState getState();
  virtual ~SFSMConnectedState();

  virtual void processTerminateRequest(Session* pSession);
  virtual void printStateName();
 private:
  SFSMConnectedState(); // Only the getInstance method will get access to this
  static SFSMBaseState* instance;
};

#endif
