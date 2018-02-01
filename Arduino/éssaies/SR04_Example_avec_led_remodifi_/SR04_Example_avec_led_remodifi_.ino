#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
#define LEDr 7
#define LEDg 6
#define LEDb 5
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a=0;

void setup() {
   Serial.begin(9600);
   delay(1000);
   ledWrite(LEDr, LOW);
   ledWrite(LEDg, LOW);
   ledWrite(LEDb, LOW);
}

void ledWrite(int ledPin, int level) {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, level);
}

void loop() {
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   digitalwrite(LEDr);
   digitalwrite(LEDg);
   digitalwrite(LEDb);   
   delay(0000);
}

void digitalwrite(int ledPin) {
  digitalWrite(ledPin, HIGH);
  delay(250);
  digitalWrite(ledPin, LOW);
  delay(50);
}

