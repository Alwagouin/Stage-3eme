#include <LiquidCrystal.h>
#include "SR04.h"
#define TRIG_PIN 4
#define ECHO_PIN 5

#define DEBUG true

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);

void printLcdLine(int row, const char* text) {
  lcd.setCursor(0, row);
  lcd.print(text);
}

void setupLcd() {
  lcd.begin(16, 2); // set up the LCD's number of columns and rows:
}

void setupDebug() {
  Serial.begin(9600);
}

void setup() {
#ifdef DEBUG
  setupDebug();
#endif
  setupLcd();
  delay(1000);
}

void printDistance(int distanceCm) {
#ifdef DEBUG
  printDistanceDebug(distanceCm);
#endif
  printDistanceLcd(distanceCm);
}

#ifdef DEBUG
void printDistanceDebug(int distanceCm) {
  Serial.print("La distance est de ");
  Serial.print(distanceCm);
  Serial.println(" cm");
}
#endif

// (note: line 1 is the second row, since counting begins with 0):
void printDistanceLcd(int distanceCm) {
  printLcdLine(0, "La distance est");
  printLcdLine(1, "                ");
  char buffer[17];
  sprintf(buffer, "de %d cm", distanceCm);
  printLcdLine(1, buffer);
}

void loop() {
  printDistance(sr04.Distance());
  delay(500);
}

