
/*
 * Parameter of MicroWave Responses.
 * MicroWave Status => MicroWave [ON|OFF] MicroWave Timer : XminY
 * MicroWave State => MicroWave [ON|OFF]
 * MicroWave Timer => MicroWave Timer : XminY
*/

/*
 * Define a MicroWave Object.
 * Contant a timer and a status.
 */

#ifndef MICROWAVE_H
#define MICROWAVE_H

#include "Timer.h"

class MicroWave
{
  private:
    Timer timer;
    bool active;
  
  public:
    MicroWave(int min = 0, int sec = 0);
    Timer getTimer();
    bool getActive();
    void setTimer(Timer timer);
    void setActive(bool active);

    void printMicroWaveStatus();
};

#endif
