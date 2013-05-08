/*
 * Author: Sonny Rajagopalan
 * E-mail: sonny.rajagopalan@gmail.com
 * Date of first creation: 04/05/2010
 *
 * Description:
 * Derived class for the dormant state of a simple FSM.
 */

#include <iostream>
#include "SFSMBaseState.h"
#include "SFSMDormantState.h"
#include "SFSMWaitForAuthState.h"
#include "Mutex.h"

using namespace std;

SFSMBaseState* SFSMDormantState::instance = 0;

/*
 * Use a double-guard mutex protection scheme
 */
SFSMBaseState* SFSMDormantState::getInstance()
{
  Mutex mutex;
  if (instance == 0) // Assume atomic check
    {
      mutex.AcquireMutex(); // Un-implemented mutex code
      if (instance == 0)
	{
	  instance = new SFSMDormantState();
	}
      mutex.ReleaseMutex();
    }
  return instance;
}

Session::SessionState SFSMDormantState::getState()
{
  return Session::DORMANT;
}

void SFSMDormantState::printStateName()
{
  cout << "Dormant state." << endl;
}


void SFSMDormantState::processConnectRequest(Session* pSession)
{
  cout << "SFSMBaseState::processConnectRequest: Called in the correct state for session object#";
  cout << pSession->getObjectId() << endl;

  // First, change state to WAITFORAUTH
  SFSMBaseState::changeState(pSession, SFSMWaitForAuthState::getInstance());
}

/* 
 * PRIVATE CONSTRUCTOR
 */
SFSMDormantState::SFSMDormantState() : SFSMBaseState("SFSMDormantState")
{
  // Does nothing else
}

SFSMDormantState::~SFSMDormantState()
{
}
