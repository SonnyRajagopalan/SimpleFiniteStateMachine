/*
 * Author: Sonny Rajagopalan
 * E-mail: sonny.rajagopalan@gmail.com
 * Date of first creation: 04/05/2010
 *
 * Description:
 * Derived class for wait for authentication resolution state for a simple FSM
 */

#include <iostream>
#include "SFSMBaseState.h"
#include "SFSMWaitForAuthState.h"
#include "SFSMConnectedState.h"
#include "SFSMClosedState.h"
#include "Mutex.h"

using namespace std;

SFSMBaseState* SFSMWaitForAuthState::instance = 0;

/*
 * Use a double-guard mutex protection scheme
 */
SFSMBaseState* SFSMWaitForAuthState::getInstance()
{
  Mutex mutex;
  if (instance == 0) // Assume atomic check
    {
      mutex.AcquireMutex(); // Un-implemented mutex code
      if (instance == 0)
	{
	  instance = new SFSMWaitForAuthState();
	}
      mutex.ReleaseMutex();
    }
  return instance;
}

Session::SessionState SFSMWaitForAuthState::getState()
{
  return Session::WAITFORAUTH;
}

void SFSMWaitForAuthState::printStateName()
{
  cout << "Waiting for authentication state." << endl;
}


void SFSMWaitForAuthState::processAuthResult(Session* pSession, int authResult)
{
  cout << "SFSMBaseState::processAuthResult: Called in the correct state for session object#";
  cout << pSession->getObjectId() << endl;

  if (authResult == 1)
    {
      SFSMBaseState::changeState(pSession, SFSMConnectedState::getInstance());
    }
  else
    {
      SFSMBaseState::changeState(pSession, SFSMClosedState::getInstance());
    }
}

/* 
 * PRIVATE CONSTRUCTOR
 */
SFSMWaitForAuthState::SFSMWaitForAuthState() : SFSMBaseState("SFSMWaitForAuthState")
{
  // Does nothing else
}

SFSMWaitForAuthState::~SFSMWaitForAuthState()
{
}
