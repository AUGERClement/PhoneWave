#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "Interface.h"


/*Utilité du projet :
 * Quelques chose que je révais de faire depuis la 4ème (El psy kongroo)
 * Coder en faible mémoire (optimiser le code, chosir judicieusement les lib...)
 * Notions de base en electronics
 * C'est fucking fun d'avoir un micro-onde connecté.
 */

/*
 * Difficulté.
 * Bricoler des trucs en electronics : Merci Guillian
 * Communiquer par SMS.
 * Réduire l'utilisation de ressources, la taille du code, sans le rendre vulnerable. (Les free lol)
 * Time.h qui n'est pas utilisable tel quel sur Arduino (time(NULL) => 0). Necessite une synchro NTP
 * Faire du code à thème. Length des DMail a modifier ?
 * Transporter le micro-onde (Tek <=> Chez moi) et vivre sans le temps des travaux.
 */

/*
 * Pitch : commencer par l'envoi de SMS, et finir par l'ouverture du micro-onde.
 * Dire "El psy kongroo"  : Absolument
 * Filmer le pitch.
 */

/*
 * Se faire sponso par Orange.
 */

//Parse a SMS, Error is timer {0,0}.
//Valid SMS ("MicroWave 3 30"). => 3min30
//0 < min < 30
//0 < sec < 60
/*
Timer SMSParser(char *str)
{
  Timer timer;
  Timer fail; //returned if anything fail
  char delim = ' ';
  char *token = strtok(str, &delim);

  if (strcmp(token, "MicroWave")) { // if first Token != "MicroWave"
    return fail;
  }

  token = strtok(NULL, &delim); //Get Minutes from Msg

  if (!token || !atoi(token)) {
    return fail;
  }
  timer.setMin(atoi(token));

  token = strtok(NULL, &delim); //Get Secondes from Msg

  if (!token || !atoi(token)) {
    return fail;
  }

  timer.setSec(atoi(token));

  timer.formatTimer();

  if (strtok(NULL, &delim)) { //If there is more data, formattage is invalid and exit with timer 0;0
    return fail;
  }
  
  return timer;
}
*/
/*
//Bool function editing MicroWave State.
//Valid input : "MicroWave ON"
bool ChangeMicroWaveState(char *msg)
{
  char delim = ' ';
  char *token  = strtok(msg, &delim);

  if (!token || strcmp(token, "MicroWave")) {
    return false; // Turn OFF MicroWave
  }

  token = strtok(NULL, &delim);

  if (!token || strcmp(token, "ON")) {
    return false;
  }

  return true;
}*/

/*
 * Parameter des Reponses du microWave.
 * MicroWave Status => MicroWave [ON|OFF]\nMicroWave Timer : XminY
 * MicroWave State => MicroWave [ON|OFF]
 * MicroWave Timer => MicroWave Timer : XminY
 */

MicroWave gateOfSteiner(2, 30); //Stein's;Gate reference everywhere !!
//Interface interface; //interface for DMail com
char *input; //SMS message content (going inside)
char *output; //SMS message content (going outside)
enum request req = EMPTY;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  Serial.begin(9600);
  Serial.println("Start communication");
}

//Interface interface; //interface for DMail com

void loop()
{
  /*
  input = interface.dMailReceiver();
  if (input) {
    if (req = interface.dMailParser(input, gateOfSteiner)) {
      output = interface.buildDMailAnswer(req, gateOfSteiner);
      interface.dMailSender(output); //Free inside
    }
  }
  delay(500);
  digitalWrite(13, LOW);
  delay(1000);
  digitalWrite(13, HIGH);
  delay(1000);
  */
}
