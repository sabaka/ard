// YL-39 + HC-68 humidity sensor

// some constants
const unsigned long vetDelay = 43200000; // wait if all sensors are wet
const unsigned long dryDelay = 1800000; // wait if some sensors are dry (probably someone will wet soil)
const int humidityThreshold = 500; // minimum value for "vet"
const int sensorReadDelay = 1000; // defines how long sensor read operation takes

// Register 74HC595 pins
const int latchPin = 11; // (11) ST_CP [RCK] on 74HC595
const int clockPin = 9; // (9) SH_CP [SCK] on 74HC595
const int dataPin = 12; // (12) DS [S1] on 74HC595

// Mappings between analog and digital ports for sensors
const byte pins[] = {A0, A1, A2, A3};
const byte vccs[] = {8,7,4,2};


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
  bool status = true;

  for (int i = 0; i < 4; i++) {
    int humidity = readHumidity(pins[i], vccs[i]);
    Serial.print("Humidity Level ");
    Serial.print(i + 1);
    Serial.print(" ");
    Serial.println(humidity);
    if (humidity < humidityThreshold && humidity > 20) {
      bitSet(leds, 4 + i); // left bits are meaningfull here
      status = false;
    }
  }
  lightLeds(leds);
  if (status) {
    Serial.print("All plants are vet. Sleep for: ");
    Serial.print(vetDelay / 1000 / 60);
    Serial.println(" mins.");
    delay(vetDelay);
  } else {
    Serial.print("Some plants are dry. Sleep for: ");
    Serial.print(dryDelay / 1000 / 60);
    Serial.println(" mins.");
    delay(dryDelay);
  }
}

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
