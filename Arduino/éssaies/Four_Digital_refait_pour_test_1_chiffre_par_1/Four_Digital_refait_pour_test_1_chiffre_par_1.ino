//www.elegoo.com
//2016.12.12

int latch=9;  //74HC595  pin 9 STCP
int clock=10; //74HC595  pin 10 SHCP
int data=8;   //74HC595  pin 8 DS
int ledM = 3;
int ledC =2;
int ledD =1;
int ledU =0;
unsigned char table[]=
{0x00, 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7C, 0x07, 0x7F, 0x67};

void setup() {
   Serial.begin(9600);
   delay(1000);
   ledWrite(ledM, LOW);
   ledWrite(ledC, LOW);
   ledWrite(ledD, LOW);
   ledWrite(ledU, LOW);
   pinMode(latch,OUTPUT);
   pinMode(clock,OUTPUT);
   pinMode(data,OUTPUT);
   Display(0);
}

void ledWrite(int ledPin, int level) {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, level);
}
void Display(unsigned char num)
{

  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,table[num]);
  digitalWrite(latch,HIGH);
  
}
void loop() {
  digitalWrite(ledD, LOW);
  digitalWrite(ledM, LOW);
  digitalWrite(ledC, LOW);
  digitalWrite(ledU, HIGH);
 
}
