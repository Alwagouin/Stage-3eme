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

void SR04::Ping() {
    _distance = Distance();
}
void setup() {
   Serial.begin(9600);
   delay(1000);
 }
void loop() {
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
}
long SR04::DistanceAvg(int wait, int count) {
    long min, max, avg, d;
    min = 999;
    max = 0;
    avg = d = 0;
    if (wait < 25) {
        wait = 25;
    }
    if (count < 1) {
        count = 1;
    }
    for (int x = 0; x < count + 2; x++) {
        d = Distance();
        if (d < min) {
            min = d;
        }
        if (d > max) {
            max = d;
        }
        avg += d;
    }

    avg -= (max + min);
    avg /= count;
    return avg;
}
SR04::SR04(int echoPin, int triggerPin) {
    _echoPin = echoPin;
    _triggerPin = triggerPin;
    pinMode(_echoPin, INPUT);
    pinMode(_triggerPin, OUTPUT);
    _autoMode = false;
    _distance = 999;
}
long SR04::Distance() {
    long d = 0;
    _duration = 0;
    digitalWrite(_triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_triggerPin, LOW);
    delayMicroseconds(2);
    _duration = pulseIn(_echoPin, HIGH, PULSE_TIMEOUT);
    d = MicrosecondsToCentimeter(_duration);
    delay(25);
    return d;
}
long SR04::getDistance() {
    return _distance;
}
long SR04::MicrosecondsToCentimeter(long duration) {
    long d = (duration * 100) / 5882;
    return d;
}
