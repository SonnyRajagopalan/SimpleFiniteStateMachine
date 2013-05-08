/*
 * Author: Sonny Rajagopalan
 * E-mail: sonny.rajagopalan@gmail.com
 * Date of first creation: 04/05/2010
 *
 * Description:
 * Derived class for connected state for a simple FSM
 */

#include <iostream>
#include "SFSMBaseState.h"
#include "SFSMConnectedState.h"
#include "SFSMDormantState.h"
#include "Mutex.h"

using namespace std;

SFSMBaseState* SFSMConnectedState::instance = 0;

/*
 * Use a double-guard mutex protection scheme
 */
SFSMBaseState* SFSMConnectedState::getInstance()
{
  Mutex mutex;
  if (instance == 0) // Assume atomic check
    {
      mutex.AcquireMutex(); // Un-implemented mutex code
      if (instance == 0)
	{
	  instance = new SFSMConnectedState();
	}
      mutex.ReleaseMutex();
    }
  return instance;
}

Session::SessionState SFSMConnectedState::getState()
{
  return Session::CONNECTED;
}

void SFSMConnectedState::printStateName()
{
  cout << "Connected state." << endl;
}


void SFSMConnectedState::processTerminateRequest(Session* pSession)
{
  cout << "SFSMBaseState::processTerminateRequest: Called in the correct state for session object#";
  cout << pSession->getObjectId() << endl;

  // First, change state to WAITFORAUTH
  SFSMBaseState::changeState(pSession, SFSMDormantState::getInstance());
}

/* 
 * PRIVATE CONSTRUCTOR
 */
SFSMConnectedState::SFSMConnectedState() : SFSMBaseState("SFSMConnectedState")
{
  // Does nothing else
}

SFSMConnectedState::~SFSMConnectedState()
{
}
