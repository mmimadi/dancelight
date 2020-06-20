#include<Arduino.h>

const byte button = 7  ;

byte buttonState = 0; //HIGH/LOW
byte buttonHandler = 0; //Variable Count
byte counter = 0;

byte doubleTapSleep = 0;
byte doubleTapState = 0;

byte led = 6;
byte DevicePower = 0;

void setup() {

  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), iHandler, FALLING);

  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  buttonState = digitalRead(button);

}

void loop() {

  buttonState = 0;
  doubleTapSleep = 0;
  doubleTapState = 0;
  counter = 0;

  Serial.println("MAIN");

  while (buttonHandler >= 1 && counter < 250) {   //!!!should be ==, >= is for crappy (temporary) debounce!!!
    doubleTapState = 1;
    buttonState = digitalRead(button);

    if (buttonState == HIGH) { //Exit on button release
      buttonHandler = 0;
    }
    if (counter > 248 && DevicePower == 0) {
      counter = 0;
      PowerUp();
    }
    if (counter > 248 && DevicePower == 1) {
      counter = 0;
      PowerDown();
    }
    counter++;
    delay(7);
  }

  while (doubleTapState == 1) {

    buttonState = digitalRead(button);
    if (buttonState == HIGH) {
      buttonHandler = 0;
    }
    doubleTapSleep++;
    delay(5);

    if (buttonState == LOW) {
      doubleTapState = 2;
      BatteryReport();
    }
    if (doubleTapSleep > 30) { //sleep timeout
      doubleTapState = 0;
    }
  }

}

void iHandler() {
  sei();
  buttonHandler++;
  cli();
}

//Power Sequences
int BatteryReport() {
  analogWrite(led, 255);
  delay(100);
  analogWrite(led, 10);
  delay(100);
  analogWrite(led, 255);
  delay(100);
  analogWrite(led, 10);
  delay(100);
  analogWrite(led, 255);
  delay(100);
  analogWrite(led, 0);
}

int PowerUp() {

  analogWrite(led, 10);
  delay(70);
  analogWrite(led, 50);
  delay(70);
  analogWrite(led, 100);
  delay(70);
  analogWrite(led, 150);
  delay(70);
  analogWrite(led, 200);
  delay(70);
  analogWrite(led, 255);
  delay(1000);
  DevicePower = 1;
  //PSU pullup
}

int PowerDown() {

  analogWrite(led, 255);
  delay(70);
  analogWrite(led, 200);
  delay(70);
  analogWrite(led, 150);
  delay(70);
  analogWrite(led, 100);
  delay(70);
  analogWrite(led, 50);
  delay(70);
  analogWrite(led, 10);
  delay(1000);
  analogWrite(led, 0);

  DevicePower = 0;
  //psu pullup
  //low power mode
}
