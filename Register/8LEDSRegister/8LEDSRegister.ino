int tDelay = 100;

int latchPin = 11;      // (11) ST_CP [RCK] on 74HC595
int clockPin = 9;      // (9) SH_CP [SCK] on 74HC595
int dataPin = 12;     // (12) DS [S1] on 74HC595


void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() {
  byte leds = 0;
  updateShiftRegister(leds);
  delay(tDelay);
  for (int i = 8; i >= 0; i--) {
    bitSet(leds, i);
    updateShiftRegister(leds);
    delay(tDelay);
  }
}

void updateShiftRegister(byte leds) {
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}


