/*
 * Author: Sonny Rajagopalan
 * E-mail: sonny.rajagopalan@gmail.com
 * Date of first creation: 04/05/2010
 *
 * Description:
 * Bogus mutex generation/release for use with a simple FSM.
 */

#ifndef MUTEX_H
#define MUTEX_H

class Mutex
{
 public:
  inline void AcquireMutex();
  inline void ReleaseMutex();
 private:
  int mutexId;
};

void Mutex::AcquireMutex()
{
  // Does nothing as of now
}

void Mutex::ReleaseMutex()
{
  // Does nothing as of now
}
#endif
