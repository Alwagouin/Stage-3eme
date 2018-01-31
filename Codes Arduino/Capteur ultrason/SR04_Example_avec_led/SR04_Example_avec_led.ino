#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include <inttypes.h>
#include "SR04.h"
#ifndef SR04_H
#define SR04_H
class SR04 {
public:
  SR04(int echoPin, int triggerPin);
  long Distance();
  long DistanceAvg(int wait=DEFAULT_DELAY, int count=DEFAULT_PINGS);
  void Ping() ;
  long getDistance();
private:
  long MicrosecondsToCentimeter(long duration);
  long _currentDistance;
  int _echoPin, _triggerPin;
  long _duration, _distance;
  bool _autoMode;
};
#endif
#define PULSE_TIMEOUT 150000L 
#define DEFAULT_DELAY 10
#define DEFAULT_PINGS 5
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a=0;

void setup() {
   Serial.begin(9600);
   delay(1000);
 }


void loop() {
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
}

