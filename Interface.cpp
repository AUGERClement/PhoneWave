#include "Interface.h"


Interface::Interface()
{
  Serial.println("Building interface");
  this->connected = false;

  //While GSM connection isn't ok.
  while (!this->connected) {
    if (this->gsmAccess.begin(PINNUMBER) == GSM_READY) {
      this->connected = true;
    } else {
      Serial.println("Failed to log. Check your SIM");
      delay(1000);
    }
  }
  Serial.println("SMS Interface ready !");
  Serial.println("GSM initialised");
}

//Parse the content of a dMail (SMS). extract the message.
char *Interface::getDMailContent()
{
  int i = 0;
  char c = '\0';
  //char dString[(__SS_MAX_RX_BUFF + 1)];
  char *dString = (char *)malloc(sizeof(char) * (64 + 1));
  //Arduino limit SMS to 64 char by default. And I don't need more.
  //Maybe I should reduce it to 36, because Stein's;Gate.

  if (!dString)
    return (NULL);
  while (c = this->dMail.read()) {
    dString[i] = c;
    i++;
    if (i == 63) //dMail too long.
      break;
  }
  dString[i] = '\0';
  return (dString);
}

//Parse the content of a dString. May edit MicroWave or send answer with dMailSender()
//Valid SMS ("MicroWave Timer 3 30"). => 3min30
//Valid SMS ("MicroWave ON"); => Activate MicroWave
//Valid SMS ("MicroWave Status") => return true;
enum request Interface::dMailParser(char *dString, MicroWave microwave)
{
  //uses of small parsers in testLed ?
    free(dString);
    return (EMPTY);
}

//Return the content of a dMail if one is available. Otherwise, NULL;
char *Interface::dMailReceiver()
{
  char *dString = NULL;
  
  if (this->dMail.available()) {
    this->dMail.remoteNumber(this->client, 20);

    dString = this->getDMailContent();
    this->dMail.flush();
    return (dString);
  }
  return (NULL);
}

//Request enum en arg
//If client ask for Status, we will answer with MicroWave data.

/*
 * Parameter des Reponses du microWave.
 * MicroWave Status => MicroWave [ON|OFF]\nMicroWave Timer : XminY
 * MicroWave Active => MicroWave [ON|OFF]
 * MicroWave Timer => MicroWave Timer : XminY
 */
 
char *Interface::buildDMailAnswer(enum request req, MicroWave microwave)
{
  bool active = microwave.getActive();
  time_t remainingTime = microwave.getTimer().getRemainingTime();
  //char *dMail = (char *)malloc(sizeof(char) * (_SS_MAX_RX_BUFF + 1)); //C++ don't like malloc...
  char *dMail = (char *)malloc(sizeof(char) * (64 + 1));
  char arr[3]; //Will host timer values.

  if (!dMail)
    return NULL;

  strcpy(dMail, "MicroWave ");

  // Best implementation ? Switch ?
  switch (req){
    case STATUS:
    case ACTIVE:
      if (active)
        strcat(dMail, "ON");
      else
        strcat(dMail, "OFF");
      
      if (req == ACTIVE)
        break;
      else
        strcat(dMail, "\nMicroWave ");
    case TIMER:
      strcat(dMail, "Timer ");
      //strcat(dMail, gcvt(remainingTime / 60, 2, arr));
      sprintf(arr, "%d", remainingTime / 60);
      strcat(dMail, arr);
      strcat(dMail, "min");
      sprintf(arr, "%d", remainingTime % 60);
      strcat(dMail, arr);
      //strcat(dMail, gcvt(remainingTime % 60), é, arr));
    default:
      free(dMail);
      return (NULL);
  }
  return dMail;
}


void Interface::dMailSender(char *dString)
{
  if (!dString)
    return;
  this->dMail.beginSMS(this->client);
  this->dMail.print(dString);
  this->dMail.endSMS();

  free(dString);
}
