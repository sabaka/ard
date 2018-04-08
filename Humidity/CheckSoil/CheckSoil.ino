// YL-39 + HC-68 humidity sensor

byte pins[] = {A0, A1, A2, A3};
byte vccs[] = {8,7,4,2};

int sensorReadDelay = 1000;
int latchPin = 11;      // (11) ST_CP [RCK] on 74HC595
int clockPin = 9;      // (9) SH_CP [SCK] on 74HC595
int dataPin = 12;     // (12) DS [S1] on 74HC595

int humidityThreshold = 500;

void setup() {
  // Init pins for register
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  // Init the humidity sensors
  for (int i=0; i < 4; i++) {
    pinMode(vccs[i], OUTPUT);
    digitalWrite(vccs[i], LOW);
  }

  // Setup Serial
  while (!Serial);
  delay(1000);
  Serial.begin(9600);
}

void loop() {
  byte leds = 0;

  for (int i = 0; i < 4; i++) {
    int humidity = readHumidity(pins[i], vccs[i]);
    Serial.print("Humidity Level ");
    Serial.print(i);
    Serial.print(" ");
    Serial.println(humidity);
    if (humidity < humidityThreshold && humidity > 10) {
      bitSet(leds, 4 + i);
    }
  }
  lightLeds(leds);

  delay(100);
}

/*
 # 0 ~300 dry soil
 # 300~700 humid soil
 # 700~950 in water
*/
int readHumidity(byte pin, byte vcc) {
  digitalWrite(vcc, HIGH);
  delay(sensorReadDelay);
  int humidity = analogRead(pin);
  digitalWrite(vcc, LOW);
  return 1023 - humidity;
}

void lightLeds(byte leds) {
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
