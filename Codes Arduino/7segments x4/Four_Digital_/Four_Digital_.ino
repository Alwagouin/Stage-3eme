//www.elegoo.com
//2016.12.12

int latch=9;  //74HC595  pin 9 STCP
int clock=10; //74HC595  pin 10 SHCP
int data=8;   //74HC595  pin 8 DS
unsigned char table[]=
{0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7C, 0x07, 0x7F, 0x67};

void setup() {
   //Serial.begin(9600);
  pinMode(latch,OUTPUT);
  pinMode(clock,OUTPUT);
  pinMode(data,OUTPUT);
   delay(1000);
}
void Display(unsigned char num)
{

  digitalWrite(latch,LOW);
  shiftOut(data,clock,MSBFIRST,table[num]);
  digitalWrite(latch,HIGH);
  
}
void loop() {
  Display(0);
  for(int i=0;i<10;i++) {
    Display(i);
    delay(400);
  }
}
