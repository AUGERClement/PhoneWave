#include "Timer.h"

Timer::Timer(int min, int sec)
{
  this->initTime = time(NULL);
  this->remainingTime = this->rounding(min * 60 + sec);
  this->endTime = (time(NULL) + this->remainingTime);
}


time_t Timer::getInitTime()
{
  return (this->initTime);
}

time_t Timer::getRemainingTime()
{
  this->remainingTime = this->endTime - time(NULL);
  return (this->remainingTime);
}

time_t Timer::getEndTime()
{
  return (this->endTime);
}


void Timer::setInitTime(time_t newInitTime)
{
  this->initTime = newInitTime;
}

void Timer::setRemainingTime(time_t newRemainingTime)
{
  this->remainingTime = newRemainingTime;
  this->endTime = this->initTime + newRemainingTime;
}

//Print a timer content
void Timer::printTimer()
{
  this->remainingTime = this->endTime - time(NULL); //Time of end - actual time.

  Serial.println(time(NULL));
  Serial.print(remainingTime / 60);
  Serial.print("min ");
  Serial.println(remainingTime % 60);
}

//Force a value between floor and ceil.
int Timer::rounding(int value, int floor, int ceil)
{
  if (value > ceil) {
    return ceil;
  } else if (value < floor) {
    return floor;
  }
  return value;
}
