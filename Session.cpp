/*
 * Author: Sonny Rajagopalan
 * E-mail: sonny.rajagopalan@gmail.com
 * Date of first creation: 04/05/2010
 *
 * Description:
 * A session object declaration that will be used in a simple FSM.
 *
 */

#include <iostream>
#include <stdio.h>
#include "Session.h"
#include "SFSMDormantState.h"
using namespace std;

int Session::objectId = 0;

Session::Session()
{
  objectId++;
  myObjectId             = objectId;
  currentCallDuration    = 0;
  lastCallDuration       = 0;
  cumulativeCallDuration = 0;
  numberOfCalls          = 0;
  myState                = Session::DORMANT;
  pCurrentState          = SFSMDormantState::getInstance();

  cout << "Session object " << myObjectId << " initialized." << endl;

}

int Session::getObjectId()
{
  return myObjectId;
}

Session::SessionState Session::getState()
{
  return myState;
}

char* Session::getStateName()
{
  return pCurrentState->getStateName();
}

int Session::getLastCallDuration()
{
  return lastCallDuration;
}

int Session::getCurrentCallDuration()
{
  return currentCallDuration;
}

int Session::getTotalCallDuration()
{
  return cumulativeCallDuration;
}

int Session::getNumberOfCalls()
{
  return numberOfCalls;
}

void Session::getSessionStats()
{
  cout << "Object ID             : " << myObjectId << "." << endl;
  cout << "Current call duration : " << currentCallDuration << "." << endl;
  cout << "Total call duration   : " << cumulativeCallDuration << "." << endl;
  
}

void Session::changeState(SFSMBaseState* pNextState, Session::SessionState nextState)
{
  pCurrentState = pNextState;
  myState       = nextState;
}

Session::~Session()
{
  if (currentCallDuration != 0)
    {
      cout << "Dropping a call currently going on at session " << myObjectId << " to end session." << endl;
    }
  else
    {
      cout << "Session " << myObjectId << " ended." << endl;
    }
}

SFSMBaseState* Session::getCurrentState()
{
  return pCurrentState;
}
