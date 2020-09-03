
#include<avr/wdt.h>
#define SIXTEENTH 120
#define NONE 0
#define SWING 1
#define ROCK 2
#define MARCH 3
#define SIXT 4
#define SIXTR 5
#define SIXTL 6


void setup() {
  watchdogSetup();
  
  // pins connected to motor shield to drive motors to play drumsticks
  pinMode(7, OUTPUT); // input4
  pinMode(8, OUTPUT); // input3
  pinMode(11, OUTPUT);// input2
  pinMode(12, OUTPUT);// input1
  
  Serial.begin(9600);
}

uint8_t beat = NONE;
uint8_t measure = 1;

void loop() {
  // put your main code here, to run repeatedly:
  measure = runSongs(measure);
  // kick watchdog
  wdt_reset();
}

uint8_t runSongs(uint8_t meas) {
  byte a = Serial.read();
  // code reads input, and on <CR>, selects what beat to play.
  if(a == '1') {
    beat = NONE;
    meas = 1;
  } else if(a == '2') {
    beat = SWING;
  } else if(a == '3') {
    beat = ROCK; 
  } else if(a == '4') {
    beat = MARCH;
  } else if(a == '5') {
    beat = SIXT;
  } else if(a == '6') {
    beat = SIXTR;
  } else if(a == '7') {
    beat = SIXTL;
  }

  // after beat is selected, actually play the beat.
  if(beat == SWING) {
    meas = swing(meas);
  } else if(beat == ROCK) {
    meas = rock(meas);
  } else if(beat == MARCH) {
    meas = march(meas);
  } else if(beat == SIXT) {
    sixteenths();
  } else if(beat == SIXTR) {
    sixteenthsRight();
  } else if(beat == SIXTL) {
    sixteenthsLeft();
  }

  return meas;
}

uint8_t swing(uint8_t meas) {
  
  if(meas == 1) {
    attackRight(4*SIXTEENTH);
    attackLeft(3*SIXTEENTH);
    attackLeft(SIXTEENTH);
    attackRight(4*SIXTEENTH);
    attackLeft(3*SIXTEENTH);
    attackLeft(SIXTEENTH);
    
    return 2;
    
  } else if(meas == 2) {
    attackRight(4*SIXTEENTH);
    attackLeft(3*SIXTEENTH);
    attackLeft(SIXTEENTH);
    attackRight(4*SIXTEENTH/3);
    attackLeft(4*SIXTEENTH/3);
    attackRight(4*SIXTEENTH/3);
    attackLeft(4*SIXTEENTH/3);
    attackRight(4*SIXTEENTH/3);
    attackLeft(4*SIXTEENTH/3);

    return 3;
    
  } else if(meas == 3) {
    attackRight(4*SIXTEENTH/3);
    attackLeft(8*SIXTEENTH/3);
    attackLeft(8*SIXTEENTH/3);
    attackLeft(4*SIXTEENTH/3);
    attackRight(4*SIXTEENTH/3);
    attackLeft(8*SIXTEENTH/3);
    attackLeft(8*SIXTEENTH/3);
    attackLeft(4*SIXTEENTH/3);

    return 4;
    
  } else if(meas == 4) {
    attackRight(4*SIXTEENTH/3);
    attackLeft(8*SIXTEENTH/3);
    attackLeft(4*SIXTEENTH/3);
    attackRight(4*SIXTEENTH/3);
    attackLeft(4*SIXTEENTH/3);
    attackRight(4*SIXTEENTH/3);
    attackLeft(4*SIXTEENTH/3);
    attackRight(4*SIXTEENTH/3);
    attackLeft(4*SIXTEENTH);

    return 5;
  } else {
    return 1;
  }
}

uint8_t rock(uint8_t meas) {
  if(meas == 1) {
    attackLeft(4*SIXTEENTH);
    attackRight(4*SIXTEENTH);
    attackLeft(2*SIXTEENTH);
    attackLeft(2*SIXTEENTH);
    attackRight(4*SIXTEENTH);

    return 2;
    
  } else if(meas == 2) {
    attackLeft(2*SIXTEENTH);
    attackLeft(2*SIXTEENTH);
    attackRight(2*SIXTEENTH);
    attackLeft(4*SIXTEENTH);
    attackLeft(2*SIXTEENTH);
    attackRight(4*SIXTEENTH);
  
    return 3;
    
  } else if(meas == 3) {

    attackLeft(2*SIXTEENTH);
    attackLeft(2*SIXTEENTH);
    attackRight(2*SIXTEENTH);
    attackLeft(2*SIXTEENTH);
    attackLeft(2*SIXTEENTH);
    attackLeft(2*SIXTEENTH);
    attackRight(2*SIXTEENTH);
    attackLeft(2*SIXTEENTH);

    return 4;
    
  } else if(meas == 4) {
    attackRight(SIXTEENTH);
    attackRight(2*SIXTEENTH);
    attackLeft(SIXTEENTH);
    attackLeft(2*SIXTEENTH);
    attackRight(SIXTEENTH);
    attackRight(2*SIXTEENTH);
    attackLeft(SIXTEENTH);
    attackLeft(2*SIXTEENTH);
    attackRight(2*SIXTEENTH);
    attackRight(2*SIXTEENTH);

    return 5;
    
  } else {  
    return 1;
  }
}


uint8_t march(uint8_t meas) {
  
  if(meas == 1) {
    attackRight(2*SIXTEENTH);
    attackLeft(SIXTEENTH);
    attackLeft(SIXTEENTH);
    attackRight(2*SIXTEENTH);
    attackLeft(SIXTEENTH);
    attackLeft(SIXTEENTH);
    attackRight(SIXTEENTH);
    attackRight(SIXTEENTH);
    attackLeft(2*SIXTEENTH);
    attackRight(2*SIXTEENTH);
    attackLeft(2*SIXTEENTH);

    return 2;
    
  } else if(meas == 2) {
    attackRight(SIXTEENTH);
    attackLeft(SIXTEENTH);
    attackRight(SIXTEENTH);
    attackRight(SIXTEENTH);
    attackLeft(SIXTEENTH);
    attackRight(SIXTEENTH);
    attackLeft(SIXTEENTH);
    attackLeft(SIXTEENTH);
    attackRight(SIXTEENTH);
    attackLeft(SIXTEENTH);
    attackRight(SIXTEENTH);
    attackRight(SIXTEENTH);
    attackLeft(4*SIXTEENTH);

    return 3;
  } else {
    return 1;
  }
  
}

void sixteenths() {
  attackRight(SIXTEENTH);
  attackLeft(SIXTEENTH);
}

void sixteenthsRight() {
  attackRight(SIXTEENTH);
} 

void sixteenthsLeft() {
  attackLeft(SIXTEENTH);  
}

void attackRight(int t) {
  digitalWrite(7, LOW); //down
  digitalWrite(8, HIGH);
  delay(3*SIXTEENTH/4);
  digitalWrite(7, HIGH);  //up
  digitalWrite(8, LOW);
  delay(t-3*SIXTEENTH/4);
}

void attackLeft(int t) {
  digitalWrite(11, LOW);  //down
  digitalWrite(12, HIGH);
  delay(3*SIXTEENTH/4);
  digitalWrite(11, HIGH); //up
  digitalWrite(12, LOW);
  delay(t-3*SIXTEENTH/4);
}





void watchdogSetup() {
  cli();
  wdt_reset();
  WDTCSR |= (1<<WDCE) | (1<<WDE);
  WDTCSR = (1<<WDE) | (0<<WDP3) | (1<<WDP2) | (1<<WDP1) | (1<<WDP0); // 2 seconds
  sei();

 // pinMode(7, OUTPUT);
}

void watchdog() {
    for(uint8_t i=1; i<255; i++) {
    digitalWrite(7, HIGH);
    delay(i*100);
    digitalWrite(7, LOW);
    delay(i*100);

    wdt_reset(); 
  }

}
