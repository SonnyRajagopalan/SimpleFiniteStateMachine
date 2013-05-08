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

#include <iostream>
#include "SFSMBaseState.h"
#include "SFSMClosedState.h"
#include "Mutex.h"

using namespace std;

SFSMBaseState* SFSMClosedState::instance = 0;

/*
 * Use a double-guard mutex protection scheme
 */
SFSMBaseState* SFSMClosedState::getInstance()
{
  Mutex mutex;
  if (instance == 0) // Assume atomic check
    {
      mutex.AcquireMutex(); // Un-implemented mutex code
      if (instance == 0)
	{
	  instance = new SFSMClosedState();
	}
      mutex.ReleaseMutex();
    }
  return instance;
}

Session::SessionState SFSMClosedState::getState()
{
  return Session::CLOSED;
}

void SFSMClosedState::printStateName()
{
  cout << "Closed state." << endl;
}

/* 
 * PRIVATE CONSTRUCTOR
 */
SFSMClosedState::SFSMClosedState() : SFSMBaseState("SFSMClosedState")
{
  // Does nothing else
}

SFSMClosedState::~SFSMClosedState()
{
}
