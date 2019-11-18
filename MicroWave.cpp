#include "MicroWave.h"

MicroWave::MicroWave(int min, int sec)
{
  this->timer = Timer(min, sec);
  this->active = false;  
}

Timer MicroWave::getTimer()
{
  return (this->timer);  
}

bool MicroWave::getActive()
{
  return (this->active);
}

void MicroWave::setTimer(Timer timer)
{
  this->timer = timer;
}

void MicroWave::setActive(bool active)
{
  this->active = active;
}

void MicroWave::printMicroWaveStatus()
{
  Serial.print("MicroWave status : ");
  
  if (this->active) {
    Serial.println("ON");
  } else {
    Serial.println("OFF");
  }

  Serial.print("MicroWave timer : ");
  this->timer.printTimer();
}
