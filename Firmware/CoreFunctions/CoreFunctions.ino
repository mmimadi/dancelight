#include<Arduino.h>

const byte button = 2;

byte buttonstate = 0;

byte counter = 0;

byte doubleTapSleep = 0;
byte doubleTapState = 0;

byte led = 5;
byte DevicePower = 0;


void setup() {

  Serial.begin(9600);

  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  buttonstate = digitalRead(button);

}

void loop() {
  buttonstate = digitalRead(button);

  doubleTapSleep = 0;
  doubleTapState = 0;
  counter = 0;

  Serial.println("MAIN");

  while (buttonstate == LOW && counter < 250) {
    doubleTapState = 1;
    buttonstate = digitalRead(button);

    if (counter > 248 && DevicePower == 0) {
      //Serial.print("on");
      counter = 0;
      PowerUp();
    }

    if (counter > 248 && DevicePower == 1) {
      //Serial.print(doubleTapSleep);
      counter = 0;
      PowerDown();
    }

    counter++;
    Serial.println(counter); /////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }

  while (doubleTapState == 1) {
    buttonstate = digitalRead(button);
    doubleTapSleep++;
    Serial.println(doubleTapSleep); ///////////////////!!!!!!!!!!!!!!!!!!!!!!!!

    if (buttonstate == LOW) {
      doubleTapState = 2;
      BatteryReport();

    }

    if (doubleTapSleep > 30) {
      doubleTapState = 0;
    }

  }
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
