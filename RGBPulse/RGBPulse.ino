// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6
#define delayTime 10

void setup() {
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
}

int redValue = 255;
int greenValue = 0;
int blueValue = 0;

void loop() {
    for(int i = 0; i < 255; i++) {
        analogWrite(RED, redValue--);
        analogWrite(GREEN, greenValue++);
        delay(delayTime);
    }

    for(int i = 0; i < 255; i++) {
        analogWrite(GREEN, greenValue--);
        analogWrite(BLUE, blueValue++);
        delay(delayTime);
    }

    for(int i = 0; i < 255; i++) {
        analogWrite(BLUE, blueValue--);
        analogWrite(RED, redValue++);
        delay(delayTime);
    }
}

