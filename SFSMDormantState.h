/*
 * Author: Sonny Rajagopalan
 * E-mail: sonny.rajagopalan@gmail.com
 * Date of first creation: 04/05/2010
 *
 * Description:
 * Derived class for the dormant state of a simple FSM.
 */

#ifndef SFSM_DORMANT_H
#define SFSM_DORMANT_H

#include "Session.h"
#include "SFSMBaseState.h"

class SFSMDormantState : public SFSMBaseState
{
 public: 
  static SFSMBaseState* getInstance();
  virtual Session::SessionState getState();
  virtual void printStateName();
  virtual ~SFSMDormantState();

  virtual void processConnectRequest(Session* pSession);
 private:
  SFSMDormantState(); // Only the getInstance method will get access to this
  static SFSMBaseState* instance;
};

#endif
