#include<avr/wdt.h>

#define ATTACKLENGTH 90

#define PININ 12
#define RIGHTUP 9
#define RIGHTDOWN 8
#define LEFTUP 11
#define LEFTDOWN 10

void setup() {
   watchdogSetup();   
  
   pinMode(PININ, INPUT); // from master
   
   pinMode(RIGHTUP, OUTPUT);  //input 4
   pinMode(RIGHTDOWN, OUTPUT);//input 3
   pinMode(LEFTUP, OUTPUT);   //input 2
   pinMode(LEFTDOWN, OUTPUT); //input 1
   
  digitalWrite(RIGHTUP, HIGH);  //up
  digitalWrite(RIGHTDOWN, LOW);
  digitalWrite(LEFTUP, HIGH); //up
  digitalWrite(LEFTDOWN, LOW);

  digitalWrite(RIGHTUP, LOW);  //brake
  digitalWrite(RIGHTDOWN, LOW);
  digitalWrite(LEFTUP, LOW); //brake
  digitalWrite(LEFTDOWN, LOW);

  Serial.begin(9600);
}

uint8_t prevReadIn = LOW;
bool rightLast = false;

void loop() {
  uint8_t readIn = digitalRead(PININ);
  Serial.println(readIn);

  if(prevReadIn == LOW && readIn == HIGH) {
    if(rightLast) {
      attackLeft();
      rightLast = false;
    } else {
      attackRight();
      rightLast = true;
    }
  }

  prevReadIn = readIn;
  wdt_reset();
}


void attackRight() {
  Serial.println("RIGHT");
  digitalWrite(RIGHTUP, LOW); //down
  digitalWrite(RIGHTDOWN, HIGH);
  delay(2*ATTACKLENGTH/3);
  digitalWrite(RIGHTUP, HIGH);  //up
  digitalWrite(RIGHTDOWN, LOW);
  delay(ATTACKLENGTH/3);
  digitalWrite(RIGHTUP, LOW);  //brake
  digitalWrite(RIGHTDOWN, LOW);
  
}

void attackLeft() {
  Serial.println("LEFT");
  digitalWrite(LEFTUP, LOW);  //down
  digitalWrite(LEFTDOWN, HIGH);
  delay(2*ATTACKLENGTH/3);
  digitalWrite(LEFTUP, HIGH); //up
  digitalWrite(LEFTDOWN, LOW);
  delay(ATTACKLENGTH/3);
  digitalWrite(LEFTUP, LOW);  //brake
  digitalWrite(LEFTDOWN, LOW);
}


void watchdogSetup() {
  cli();
  wdt_reset();
  WDTCSR |= (1<<WDCE) | (1<<WDE);
  WDTCSR = (1<<WDE) | (1<<WDP3) | (0<<WDP2) | (0<<WDP1) | (0<<WDP0); // 2 seconds
  sei();

}
