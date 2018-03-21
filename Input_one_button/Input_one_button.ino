int ledPin = 5;
int buttonApin = 9;

byte leds = 0;

int state = LOW;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonApin) == LOW) {
    if( state == LOW) {
      state = HIGH;
    } else {
      state = LOW;
    }
  }
  digitalWrite(ledPin, state);
  delay(100);
}
