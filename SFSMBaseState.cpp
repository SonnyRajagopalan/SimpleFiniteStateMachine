/*
 * Author: Sonny Rajagopalan
 * E-mail: sonny.rajagopalan@gmail.com
 * Date of first creation: 04/05/2010
 *
 * Description:
 * Base class for a simple FSM
 */

#include <iostream>
#include "SFSMBaseState.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

SFSMBaseState::SFSMBaseState(char* name)
{
  strcpy(stateName, name);
}

/* 
 * This method will only be defined in the base state
 */
int SFSMBaseState::changeState(Session* pSession, SFSMBaseState* pNextState)
{
  if (pSession == 0)
    {
      cout << "Unknown session object. Aborting!" << endl;
      return -1;
    }
  else
    {
      if (pNextState != 0)
	{
	  Session::SessionState nextState = pNextState->getState();
	  cout << "Session object " << pSession->getObjectId() << " changing state from ";
	  cout << pSession->getStateName() << " to " << pNextState->getStateName() << "." << endl;
	  	  
	  pSession->changeState(pNextState, nextState);

	  return 0;
	}
      else
	{
	  cout << "Unknown next state. Aborting!" << endl;
	  return -1;	  	  
	}
    }
}

Session::SessionState SFSMBaseState::getState()
{
  return Session::INVALID;
}

/*
 * This method will only be present in the base state
 */
char* SFSMBaseState::getStateName()
{
  return stateName;
}

void SFSMBaseState::printStateName()
{
  cout << "Base state." << endl;
}

void SFSMBaseState::printSessionInformation(Session* pSession)
{
  pSession->getSessionStats();
}

/*
 * In the following catchall base class methods, I abort, but in the real world
 * we can do several more useful things:
 * (a) Print out a log message;
 * (b) Assert;
 * (c) Kill the task creating this issue (potentially hazardous)
 * and many, many more such useful things.
 */
void SFSMBaseState::processConnectRequest(Session* pSession)
{
  cout << "SFSMBaseState::processConnectRequest: Called in the base state for session object#";
  cout << pSession->getObjectId() << " (INCORRECT CALL)." << endl;
  cout << "Cannot call processConnectRequest() from state " << pSession->getStateName() << ". Aborting!" << endl;
  exit (1);
}

void SFSMBaseState::processAuthResult(Session* pSession, int authResult)
{
  cout << "SFSMBaseState::processAuthResult: Called in the base state for session object#";
  cout << pSession->getObjectId() << " (INCORRECT CALL)." << endl;
  cout << "Cannot call processAuthResult() from state " << pSession->getStateName() << ". Aborting!" << endl;;
  exit (1);
}


void SFSMBaseState::processTerminateRequest(Session* pSession)
{
  cout << "SFSMBaseState::processTerminateRequest(): Called in the base state for session object#";
  cout << pSession->getObjectId() << " (INCORRECT CALL)." << endl;
  cout << "Cannot call processTerminateRequest() from state " << pSession->getStateName() << ". Aborting!" << endl;
  exit (1);
}
