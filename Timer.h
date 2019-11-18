/*
 * Timer.h
 * Handle the timer of the MicroWave
 * Maximum min is 30, max secondes is 59;
 * Uses time.h (obviously) and need a GSM module to synchronise.
*/

#ifndef TIMER_H
#define TIMER_H


#include "Arduino.h"
#include <time.h>
#include <stdlib.h>

#define MAX_TIME 1800 //30 min => 30 * 60

class Timer
{
  private:
    time_t initTime;
    time_t remainingTime;
    time_t endTime;

  public:
    Timer(int min = 0, int sec = 0);
    time_t getInitTime();
    time_t getRemainingTime();
    time_t getEndTime();

    void setInitTime(time_t newTimer);
    void setRemainingTime(time_t newRemainingTime);
    void setEndTime(time_t newEndTime);

    
    void printTimer();
    int rounding(int value, int floor = 0, int ceil = MAX_TIME);
};

#endif
