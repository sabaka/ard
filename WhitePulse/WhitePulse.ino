// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6
#define delayTime 10

void setup() {
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
}

void loop() {
    for(int i = 1; i < 255; i++) {
        analogWrite(RED, i);
        analogWrite(GREEN, i);
        analogWrite(BLUE, i);
        delay(delayTime);
    }
    for(int i = 255; i > 1; i--) {
        analogWrite(RED, i);
        analogWrite(GREEN, i);
        analogWrite(BLUE, i);
        delay(delayTime);
    }
}

