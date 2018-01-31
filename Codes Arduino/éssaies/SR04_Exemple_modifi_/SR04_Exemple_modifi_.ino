//www.elegoo.com
//2016.12.08
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

void setup() {
   Serial.begin(9600);
   delay(1000);
}

void loop() {
   a=sr04.Distance();
   if(a<=20) {
    Serial.println("très proche");
   }   
   else {
    if(a<=30) and(a>=21){ 
   
    Serial.println("proche")
    }
    else {
     if(a<=50) and(a>=31) { 
   
    Serial.println("normal")
     }
     else {
       if(a>=51) 
   
    Serial.println("loin")
     }}}
   delay(50);
}
