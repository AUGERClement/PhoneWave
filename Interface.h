/*
 * Interface of the for the communications.
 * Handle the SMS and edit MicroWave object.
 * By using GSM, it can also access time function for the Timer object.
 */

/*
 * dMail => DeLorean Mail.
 */

#ifndef INTERFACE_H
#define INTERFACE_H

#include <GSM.h>
//#include <SoftwareSerial.h>
#include <stdio.h>
#include "MicroWave.h"

#define PINNUMBER ""

enum request {EMPTY, STATUS, ACTIVE, TIMER};

class Interface
{
  private:
    GSM gsmAccess; //Define what is needed for our protocol
    GSM_SMS dMail; //Contain our dMail, or SMS in this case.
    char client[20]; //Sender
    bool connected;
   
  public:
    Interface();

    enum request dMailParser(char *dString, MicroWave microwave);
    char *getDMailContent();
    char *dMailReceiver();
    char *buildDMailAnswer(enum request req, MicroWave microwave);
    void dMailSender(char *dString);
};

#endif
