/*
 * Author: Sonny Rajagopalan
 * E-mail: sonny.rajagopalan@gmail.com
 * Date of first creation: 04/05/2010
 *
 * Description:
 * A session object declaration that will be used in a simple FSM.
 *
 */

#ifndef SESSION_H
#define SESSION_H

// Forward declaration for SFSMBaseState
class SFSMBaseState;

class Session
{
 public:

  enum SessionState
    {
      DORMANT,
      WAITFORAUTH,
      CONNECTED,
      CLOSED,
      INVALID
    };
  Session();
  ~Session();
  Session::SessionState getState();
  char* getStateName();
  int getObjectId();
  int getLastCallDuration();
  int getTotalCallDuration();
  int getNumberOfCalls();
  int getCurrentCallDuration();
  void getSessionStats();
  SFSMBaseState* getCurrentState();
  void changeState(SFSMBaseState* pNextState, Session::SessionState nextState);

 private:
  static int objectId;
  int myObjectId;
  int currentCallDuration; // In epochs
  int lastCallDuration; // In epochs
  int cumulativeCallDuration;
  int numberOfCalls;
  Session::SessionState myState;
  SFSMBaseState* pCurrentState;

};

#endif
