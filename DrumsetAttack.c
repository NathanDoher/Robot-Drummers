
#include<avr/wdt.h>
#define SIXTEENTH 120
#define NONE 0
#define SWING 1
#define ROCK 2
#define MARCH 3
#define SIXT 4
#define SIXTR 5
#define SIXTL 6


#define CYMBAL 6
#define HIHAT 5
#define SNARE 4
#define HITOM 3
#define LOTOM 2
#define FLTOM 1
#define KICK 0

#define CYMBALPIN 12
#define HIHATPIN 11
#define SNAREPIN 10
#define HITOMPIN 9
#define LOTOMPIN 8
#define FLTOMPIN 7
#define KICKPIN 6
#define BUZZPIN 4

uint8_t song[] = {

//Intro
  0b1000000, 4,
  0b1000000, 2,
  0b1000000, 4,
  0b1000000, 4,
  0b1000000, 4,
  0b1000000, 2,
  0b1000000, 4,
  0b1000000, 4,
  0b1000000, 4,
  0b1000000, 4,
  0b1000000, 2,
  0b1000000, 2,

  0b1000000, 4,
  0b1000000, 2,
  0b1000000, 4,
  0b1000000, 4,
  0b1000000, 4,
  0b1000000, 2,
  0b1000000, 4,
  0b1000000, 4,
  0b1000000, 4,
  0b1000000, 4,
  0b1000000, 2,
  0b1000000, 2,

//Intro2
  0b0110000, 4,
  0b0100001, 2,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0100001, 2,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0100001, 2,
  0b0100001, 2,

  0b0110000, 4,
  0b0100001, 2,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0100001, 2,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0100001, 2,
  0b0100001, 2,

  0b0110000, 4,
  0b0100001, 2,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0100001, 2,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0100001, 2,
  0b0100001, 2,

  0b0110000, 4,
  0b0100001, 2,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0100001, 2,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0001000, 1,
  0b0001000, 1,
  0b0000100, 1,
  0b0000010, 1,

//Intro3
  0b0110000, 4,
  0b0100001, 2,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0100001, 2,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0100001, 2,
  0b0100001, 2,

  0b0110000, 4,
  0b0110000, 2,
  0b0000001, 2,
  0b0100000, 2,
  0b0000001, 2,
  0b0100000, 2,
  0b0000001, 2,
  0b0100000, 2,
  0b0000001, 2,
  0b0110000, 2,
  0b0000001, 2,
  0b0110000, 2,
  0b0000001, 2,
  0b0110000, 2,
  0b0000001, 2,
  0b0110000, 4,
  0b0001000, 1,
  0b0001000, 1,
  0b0000100, 1,
  0b0000010, 1,

  0b0110000, 4,
  0b0100001, 2,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0100001, 2,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0100001, 2,
  0b0100001, 2,

  0b0110000, 4,
  0b0110000, 2,
  0b0000001, 2,
  0b0100000, 2,
  0b0000001, 2,
  0b0100000, 2,
  0b0000001, 2,
  0b0100000, 2,
  0b0000001, 2,
  0b0110000, 2,
  0b0000001, 2,
  0b0110000, 2,
  0b0000001, 2,
  0b0110000, 2,
  0b0000001, 2,
  0b0110000, 4,
  0b0000001, 2,
  0b0000001, 2,

  0b0110000, 4,
  0b0100001, 2,
  0b0110000, 4,
  0b0110000, 4,
  0b0110000, 4,
  0b0100001, 2,
  0b1010000, 4,
  0b1010000, 4,
  0b1010000, 4,
  0b1010000, 4,
  0b0100001, 2,
  0b0100001, 2,
  
//Intro Transition
  0b1000001, 6,
  0b1000001, 4,
  0b1000001, 4,
  0b1000001, 6,
  0b1000001, 4,
  0b1000001, 4,
  0b1000001, 4,
  0b1000001, 4,
  0b1000001, 16,

  0b0010000, 1,
  0b0010000, 1,
  0b0010000, 2,
  0b0010000, 2,
  0b0010000, 2,
  0b0010000, 2,
  0b0010000, 2,
  0b0010000, 2,
  0b0010000, 2,
  0b0010000, 2,
  0b0010000, 2,
  0b0010000, 2,
  0b0010000, 2,
  0b0010000, 2,
  0b1000001, 16,
  
  0b0010000, 2,
  0b0010000, 2,
  0b0010000, 2,
  0b0010000, 12,
  
  0b0010000, 1,
  0b0010000, 1,
  0b0010000, 2,
  0b0010000, 2,
  0b0010000, 2,
  0b0010000, 2,
  0b0010000, 2,
  0b0010000, 2,
  0b0010000, 2,
  0b1000001, 16,

//verse 1
  0b1000001, 4,
  0b0110000, 4,
  0b0100000, 2,
  0b0000001, 2,
  0b0110000, 4,

  0b0100001, 3,
  0b0000001, 1,
  0b0110000, 2,
  0b0000001, 2,
  0b0100000, 2,
  0b0000001, 2,
  0b0110000, 4,
  
  0b0100001, 3,
  0b0000001, 1,
  0b0110000, 4,
  0b0100000, 2,
  0b0000001, 1,
  0b0000001, 1,
  0b0110000, 4,
  
  0b0100001, 3,
  0b0000001, 1,
  0b0110000, 2,
  0b0000001, 2,
  0b0100000, 2,
  0b0000001, 2,
  0b0110000, 2,
  0b0000100, 1,
  0b0000010, 1,

  0b1000001, 4,
  0b0110000, 4,
  0b0100000, 2,
  0b0000001, 2,
  0b0110000, 4,

  0b0100001, 3,
  0b0000001, 1,
  0b0110000, 2,
  0b0000001, 2,
  0b0100000, 2,
  0b0000001, 2,
  0b0110000, 4,
  
  0b0100001, 3,
  0b0000001, 1,
  0b0110000, 4,
  0b0100000, 2,
  0b0000001, 1,
  0b0000001, 1,
  0b0110000, 4,
  
  0b0100001, 3,
  0b0000001, 1,
  0b0110000, 2,
  0b0000001, 2,
  0b0100000, 2,
  0b0000001, 2,
  0b0110000, 2,
  0b0000100, 1,
  0b0000010, 1,

  0b1000001, 16
};




void setup() {
  watchdogSetup();

  pinMode(CYMBALPIN, OUTPUT);
  pinMode(HIHATPIN, OUTPUT);
  pinMode(SNAREPIN, OUTPUT);
  pinMode(HITOMPIN, OUTPUT);
  pinMode(LOTOMPIN, OUTPUT);
  pinMode(FLTOMPIN, OUTPUT);
  pinMode(KICKPIN, OUTPUT);
  pinMode(BUZZPIN, OUTPUT);
  
  Serial.begin(9600);
}

uint8_t buzzer = 255;

void loop() {
//  drumTest();
  projectSong();
}

void projectSong() {
  for(int i=0; i<sizeof(song)/2; i++) {
    playSong(i); 
  }
}

void playSong(int noteIndex) {

  sendNote(song[2*noteIndex], song[2*noteIndex+1]);

  // kick watchdog 
  wdt_reset();

  
  digitalWrite(CYMBALPIN, LOW);
  digitalWrite(HIHATPIN, LOW);
  digitalWrite(SNAREPIN, LOW);
  digitalWrite(HITOMPIN, LOW);
  digitalWrite(LOTOMPIN, LOW);
  digitalWrite(FLTOMPIN, LOW);
  digitalWrite(KICKPIN, LOW);
}


void drumTest() {
  byte note = 1;
  for(int i=0; i<7; i++) {
    sendNote(note, 4);
    note = note<<1;
    wdt_reset();
  }
  
}

void sendNote(byte toPlay, double len) {
  Serial.println(toPlay);
  if((toPlay & (1<<CYMBAL)) != 0) {
    Serial.println("Cymbal");
    digitalWrite(CYMBALPIN, HIGH);
  }
  if((toPlay & (1<<HIHAT)) != 0) {
    Serial.println("Hihat");
    digitalWrite(HIHATPIN, HIGH);
  }
  if((toPlay & (1<<SNARE)) != 0) {
    Serial.println("Snare");
    digitalWrite(SNAREPIN, HIGH);
  }
  if((toPlay & (1<<HITOM)) != 0) {
    Serial.println("Htom");
    digitalWrite(HITOMPIN, HIGH);
  }
  if((toPlay & (1<<LOTOM)) != 0) {
    Serial.println("Ltom");
    digitalWrite(LOTOMPIN, HIGH);
  }
  if((toPlay & (1<<FLTOM)) != 0) {
    Serial.println("Ftom");
    digitalWrite(FLTOMPIN, HIGH);
  }
  if((toPlay & (1<<KICK)) != 0) {
    Serial.println("Kick");
    digitalWrite(KICKPIN, HIGH);
  }

  
  tone(BUZZPIN, buzzer, 0.5*SIXTEENTH);
  delay(0.5*SIXTEENTH);
  digitalWrite(CYMBALPIN, LOW);
  digitalWrite(HIHATPIN, LOW);
  digitalWrite(SNAREPIN, LOW);
  digitalWrite(HITOMPIN, LOW);
  digitalWrite(LOTOMPIN, LOW);
  digitalWrite(FLTOMPIN, LOW);
  digitalWrite(KICKPIN, LOW);
  delay((len-0.5)*SIXTEENTH);
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
