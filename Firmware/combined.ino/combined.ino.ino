#include<Arduino.h>
#include<EEPROM.h>

#define END 0
#define START 1
#define BLINK 2
#define UBLINK 3
#define REPEAT 4

#define LOG_SEEK false
#define LOG_EXEC false
#define LOG_MODE false

static const byte micInputPin = 0;
static const byte ledPin = 5;

const byte button = 2;
byte buttonState = 0; //HIGH/LOW
byte buttonHandler = 0; //Double Tap Variable Count
byte holdCounter = 0;
byte doubleTapSleep = 0;
byte doubleTapState = 0;
byte powerStatus = 0;
static byte mode = 1;

float percent = 100; //set sound threshold percentage


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  percent = percent / 100;
  resetPreset();

  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), iHandler, FALLING);
  pinMode(button, INPUT);

  mode = EEPROM.read(0);

}

void loop() {

  //Monitor preset advancement button and run right preset.
  static const byte numModes = 3;
  static const unsigned long buttonPressConfirmationTimeMs = 50;

  static bool pressed = true;
  static bool lastProcessedPressed = false;
  static unsigned long eventTimeMs = 0;

  /////////////New Intertupt Based Button////////////////////

  buttonState = 0;
  doubleTapSleep = 0;
  doubleTapState = 0;
  holdCounter = 0;

  Serial.println(mode);

  while (buttonHandler >= 1 && holdCounter < 250) {   //!!!should be ==, >= is for crappy (temporary) debounce!!!
    doubleTapState = 1;

    buttonState = digitalRead(button);

    if (buttonState == HIGH) { //Exit on button release
      buttonHandler = 0;
      mode++;
    }
    if (holdCounter > 248 && powerStatus == 0) {
      holdCounter = 0;
      PowerUp();
    }
    if (holdCounter > 248 && powerStatus == 1) {
      holdCounter = 0;
      PowerDown();
    }
    holdCounter++;
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


  ////////////Old Button Code///////////////////
  /*
    int buttonState = digitalRead(buttonPin);
    if (buttonState == LOW) { // low means the D2 pin is pulledPin to ground aka connect D2 to GND on the arduino
     if (!pressed) {
       pressed = true;
       eventTimeMs = millis() + buttonPressConfirmationTimeMs;
     }
    } else {
     if (pressed) {
       pressed = false;
       eventTimeMs = millis() + buttonPressConfirmationTimeMs;
     }
    }

    if (lastProcessedPressed != pressed && millis() >= eventTimeMs) {
     lastProcessedPressed = pressed;
     pressed && (mode = ++mode % numModes);
    }

  */
  if (mode == 1) {
    LOG_MODE && Serial.println("mode 0: solid");
    analogWrite(ledPin, 255);
  } else if (mode == 2) {
    LOG_MODE && Serial.println("mode 1: react to sound");
    processAudio();
  } else if (mode == 3) {
    LOG_MODE && Serial.println("mode 2: blink");
    processPreset();
  } else if (mode >= 3 | mode <= 0) {
    mode = 1;
    delay(100);
    Serial.println(mode);
    delay(100); //flush the buffer
    //exit(5); //Invalid command. Ruh roh.
  }


}






//////////////////////////////////
//   Cornflakes' Dancing Code   //
//////////////////////////////////

void processAudio() {

  int sampleCounter = 0;
  float micRawValue = analogRead(micInputPin);
  float processedResult = 0;

  while (sampleCounter < 100) {

    micRawValue = analogRead(micInputPin); //uncomment with actual mic attached
    processedResult = processedResult + micRawValue;
    delay(7);
    // Serial.println(micRawValue); //debug
    sampleCounter++;
  }
  ////////////////debug///////////////////
  //  Serial.println("totaledPin");
  //  Serial.println(processedResult);
  // delay(100);
  ///////////////////////////////////////

  processedResult = ((processedResult * percent) + processedResult) / sampleCounter;

  ///////////////debug///////////////////
  // Serial.println("DB threshold");
  //  Serial.println(processedResult);
  //////////////////////////////////////

  BumpIt(); //LETTSS GOOOOOOOO

}

void BumpIt() {
  /*  float micRawValue = analogRead(micInputPin);
    micRawValue = analogRead(micInputPin); //uncomment with actual mic attached
    pinMode(ledPin, OUTPUT);
    float processedResult = 0;
    if (micRawValue > processedResult) {

      SoundFade();

    } else {

      analogWrite(ledPin, 20); //standbye brightness
    }


  */

  delay(20);
  delay(20);
  analogWrite(ledPin, 240);
  delay(20);
  analogWrite(ledPin, 230);
  delay(20);
  analogWrite(ledPin, 100);
  delay(20);
  analogWrite(ledPin, 10);

}

void SoundFade() {
  analogWrite(ledPin, 255);
  delay(60);
  analogWrite(ledPin, 250);
  delay(20);
  analogWrite(ledPin, 240);
  delay(20);
  analogWrite(ledPin, 230);
  delay(20);
  analogWrite(ledPin, 220);
  delay(20);
  analogWrite(ledPin, 210);
  delay(30);
  analogWrite(ledPin, 200);
  delay(30);
  analogWrite(ledPin, 190);
  delay(30);
  analogWrite(ledPin, 180);
  delay(30);
  analogWrite(ledPin, 170);
  delay(20);
  BumpIt();
  analogWrite(ledPin, 160);
  delay(30);
  analogWrite(ledPin, 150);
  delay(40);
  analogWrite(ledPin, 140);
  delay(50);
  BumpIt();
  analogWrite(ledPin, 130);
  delay(55);
  analogWrite(ledPin, 120);
  delay(60);
  analogWrite(ledPin, 110);
  delay(50);
  analogWrite(ledPin, 100);
  delay(50);
  analogWrite(ledPin, 90);
  delay(50);
  BumpIt();
  analogWrite(ledPin, 80);
  delay(50);
  analogWrite(ledPin, 70);
  delay(30);
  analogWrite(ledPin, 60);
  delay(30);
  analogWrite(ledPin, 50);
  delay(30);
  BumpIt();
  analogWrite(ledPin, 40);
  delay(30);
  analogWrite(ledPin, 30);
  delay(30);
  analogWrite(ledPin, 20);
  delay(30);
  BumpIt();
  analogWrite(ledPin, 10);
  delay(30);
  analogWrite(ledPin, 5);
  delay(100);
}

/////////////////////////////
//   DDR's Blinking Code   //
/////////////////////////////

static const unsigned short int pattern_data[] PROGMEM = {
  START,  0, BLINK, 255, 10000,
  START,  0, BLINK, 255, 100, BLINK, 0, 50, REPEAT, 6, 4,
  START,  0, UBLINK, 255, 1000, UBLINK, 0, 10000, REPEAT, 6, 200,
  START,  0, BLINK, 255, 1000,

  //Decreasing Sweep, 1.4s
  START, 10, BLINK, 255, 16, BLINK, 252, 16, BLINK, 250, 16, BLINK, 247, 16, BLINK, 245, 16, BLINK, 242, 16, BLINK, 240, 16, BLINK, 237, 16, BLINK, 235, 16, BLINK, 232, 16, BLINK, 230, 16, BLINK, 227, 16, BLINK, 224, 16, BLINK, 222, 16, BLINK, 219, 16, BLINK, 217, 16, BLINK, 214, 16, BLINK, 212, 16, BLINK, 209, 16, BLINK, 207, 16, BLINK, 204, 16, BLINK, 201, 16, BLINK, 199, 16, BLINK, 196, 16, BLINK, 194, 16, BLINK, 191, 16, BLINK, 189, 16, BLINK, 186, 16, BLINK, 184, 16, BLINK, 181, 16, BLINK, 179, 16, BLINK, 176, 16, BLINK, 173, 16, BLINK, 171, 16, BLINK, 168, 16, BLINK, 166, 16, BLINK, 163, 16, BLINK, 161, 16, BLINK, 158, 16, BLINK, 156, 16, BLINK, 153, 16, BLINK, 150, 16, BLINK, 148, 16, BLINK, 145, 16, BLINK, 143, 16, BLINK, 140, 16, BLINK, 138, 16, BLINK, 135, 16, BLINK, 133, 16, BLINK, 130, 16, BLINK, 128, 16, BLINK, 125, 16, BLINK, 122, 16, BLINK, 120, 16, BLINK, 117, 16, BLINK, 115, 16, BLINK, 112, 16, BLINK, 110, 16, BLINK, 107, 16, BLINK, 105, 16, BLINK, 102, 16, BLINK, 99, 16, BLINK, 97, 16, BLINK, 94, 16, BLINK, 92, 16, BLINK, 89, 16, BLINK, 87, 16, BLINK, 84, 16, BLINK, 82, 16, BLINK, 79, 16, BLINK, 77, 16, BLINK, 74, 16, BLINK, 71, 16, BLINK, 69, 16, BLINK, 66, 16, BLINK, 64, 16, BLINK, 61, 16, BLINK, 59, 16, BLINK, 56, 16, BLINK, 54, 16, BLINK, 51, 16, BLINK, 48, 16, BLINK, 46, 16, BLINK, 43, 16, BLINK, 41, 16, BLINK, 38, 16, BLINK, 36, 16, BLINK, 33, 16, BLINK, 31, 16, BLINK, 28, 16, BLINK, 25, 16, BLINK, 23, 16, BLINK, 20, 16, BLINK, 18, 16, BLINK, 15, 16, BLINK, 13, 16, BLINK, 10, 16, BLINK, 8, 16, BLINK, 5, 16, BLINK, 3, 16, BLINK, 0, 16,

  //Increasing Sweep, 1.4s
  START, 10, BLINK, 0, 16, BLINK, 3, 16, BLINK, 5, 16, BLINK, 8, 16, BLINK, 10, 16, BLINK, 13, 16, BLINK, 15, 16, BLINK, 18, 16, BLINK, 20, 16, BLINK, 23, 16, BLINK, 26, 16, BLINK, 28, 16, BLINK, 31, 16, BLINK, 33, 16, BLINK, 36, 16, BLINK, 38, 16, BLINK, 41, 16, BLINK, 43, 16, BLINK, 46, 16, BLINK, 48, 16, BLINK, 51, 16, BLINK, 54, 16, BLINK, 56, 16, BLINK, 59, 16, BLINK, 61, 16, BLINK, 64, 16, BLINK, 66, 16, BLINK, 69, 16, BLINK, 71, 16, BLINK, 74, 16, BLINK, 77, 16, BLINK, 79, 16, BLINK, 82, 16, BLINK, 84, 16, BLINK, 87, 16, BLINK, 89, 16, BLINK, 92, 16, BLINK, 94, 16, BLINK, 97, 16, BLINK, 99, 16, BLINK, 102, 16, BLINK, 105, 16, BLINK, 107, 16, BLINK, 110, 16, BLINK, 112, 16, BLINK, 115, 16, BLINK, 117, 16, BLINK, 120, 16, BLINK, 122, 16, BLINK, 125, 16, BLINK, 128, 16, BLINK, 130, 16, BLINK, 133, 16, BLINK, 135, 16, BLINK, 138, 16, BLINK, 140, 16, BLINK, 143, 16, BLINK, 145, 16, BLINK, 148, 16, BLINK, 150, 16, BLINK, 153, 16, BLINK, 156, 16, BLINK, 158, 16, BLINK, 161, 16, BLINK, 163, 16, BLINK, 166, 16, BLINK, 168, 16, BLINK, 171, 16, BLINK, 173, 16, BLINK, 176, 16, BLINK, 179, 16, BLINK, 181, 16, BLINK, 184, 16, BLINK, 186, 16, BLINK, 189, 16, BLINK, 191, 16, BLINK, 194, 16, BLINK, 196, 16, BLINK, 199, 16, BLINK, 201, 16, BLINK, 204, 16, BLINK, 207, 16, BLINK, 209, 16, BLINK, 212, 16, BLINK, 214, 16, BLINK, 217, 16, BLINK, 219, 16, BLINK, 222, 16, BLINK, 224, 16, BLINK, 227, 16, BLINK, 230, 16, BLINK, 232, 16, BLINK, 235, 16, BLINK, 237, 16, BLINK, 240, 16, BLINK, 242, 16, BLINK, 245, 16, BLINK, 247, 16, BLINK, 250, 16, BLINK, 252, 16, BLINK, 255, 16,

  //1-(sin(x/10*pi)^2) * (x%2) / 1.8 - modulated sawteeth of various formats, 5s
  START, 10, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 1, 16, BLINK, 1, 16, BLINK, 1, 16, BLINK, 1, 16, BLINK, 1, 16, BLINK, 2, 16, BLINK, 2, 16, BLINK, 3, 16, BLINK, 3, 16, BLINK, 4, 16, BLINK, 4, 16, BLINK, 5, 16, BLINK, 5, 16, BLINK, 6, 16, BLINK, 7, 16, BLINK, 8, 16, BLINK, 9, 16, BLINK, 10, 16, BLINK, 11, 16, BLINK, 12, 16, BLINK, 14, 16, BLINK, 15, 16, BLINK, 16, 16, BLINK, 18, 16, BLINK, 20, 16, BLINK, 21, 16, BLINK, 23, 16, BLINK, 25, 16, BLINK, 27, 16, BLINK, 29, 16, BLINK, 31, 16, BLINK, 34, 16, BLINK, 36, 16, BLINK, 38, 16, BLINK, 41, 16, BLINK, 44, 16, BLINK, 47, 16, BLINK, 50, 16, BLINK, 53, 16, BLINK, 56, 16, BLINK, 59, 16, BLINK, 62, 16, BLINK, 66, 16, BLINK, 69, 16, BLINK, 73, 16, BLINK, 77, 16, BLINK, 81, 16, BLINK, 85, 16, BLINK, 89, 16, BLINK, 93, 16, BLINK, 0, 16, BLINK, 2, 16, BLINK, 3, 16, BLINK, 5, 16, BLINK, 7, 16, BLINK, 9, 16, BLINK, 12, 16, BLINK, 14, 16, BLINK, 16, 16, BLINK, 19, 16, BLINK, 21, 16, BLINK, 24, 16, BLINK, 27, 16, BLINK, 29, 16, BLINK, 32, 16, BLINK, 35, 16, BLINK, 39, 16, BLINK, 42, 16, BLINK, 45, 16, BLINK, 49, 16, BLINK, 52, 16, BLINK, 56, 16, BLINK, 60, 16, BLINK, 63, 16, BLINK, 67, 16, BLINK, 71, 16, BLINK, 75, 16, BLINK, 80, 16, BLINK, 84, 16, BLINK, 88, 16, BLINK, 93, 16, BLINK, 97, 16, BLINK, 102, 16, BLINK, 107, 16, BLINK, 111, 16, BLINK, 116, 16, BLINK, 121, 16, BLINK, 126, 16, BLINK, 131, 16, BLINK, 136, 16, BLINK, 142, 16, BLINK, 147, 16, BLINK, 152, 16, BLINK, 158, 16, BLINK, 163, 16, BLINK, 169, 16, BLINK, 174, 16, BLINK, 180, 16, BLINK, 186, 16, BLINK, 191, 16, BLINK, 197, 16, BLINK, 203, 16, BLINK, 209, 16, BLINK, 215, 16, BLINK, 220, 16, BLINK, 226, 16, BLINK, 232, 16, BLINK, 238, 16, BLINK, 244, 16, BLINK, 250, 16, BLINK, 0, 16, BLINK, 4, 16, BLINK, 9, 16, BLINK, 13, 16, BLINK, 18, 16, BLINK, 22, 16, BLINK, 27, 16, BLINK, 31, 16, BLINK, 36, 16, BLINK, 40, 16, BLINK, 45, 16, BLINK, 50, 16, BLINK, 55, 16, BLINK, 59, 16, BLINK, 64, 16, BLINK, 69, 16, BLINK, 74, 16, BLINK, 79, 16, BLINK, 84, 16, BLINK, 89, 16, BLINK, 93, 16, BLINK, 98, 16, BLINK, 103, 16, BLINK, 108, 16, BLINK, 113, 16, BLINK, 118, 16, BLINK, 123, 16, BLINK, 127, 16, BLINK, 132, 16, BLINK, 137, 16, BLINK, 142, 16, BLINK, 146, 16, BLINK, 151, 16, BLINK, 156, 16, BLINK, 160, 16, BLINK, 165, 16, BLINK, 169, 16, BLINK, 174, 16, BLINK, 178, 16, BLINK, 183, 16, BLINK, 187, 16, BLINK, 191, 16, BLINK, 195, 16, BLINK, 199, 16, BLINK, 203, 16, BLINK, 207, 16, BLINK, 211, 16, BLINK, 215, 16, BLINK, 219, 16, BLINK, 222, 16, BLINK, 226, 16, BLINK, 229, 16, BLINK, 233, 16, BLINK, 236, 16, BLINK, 239, 16, BLINK, 242, 16, BLINK, 245, 16, BLINK, 248, 16, BLINK, 251, 16, BLINK, 254, 16, BLINK, 0, 16, BLINK, 4, 16, BLINK, 8, 16, BLINK, 13, 16, BLINK, 17, 16, BLINK, 21, 16, BLINK, 24, 16, BLINK, 28, 16, BLINK, 32, 16, BLINK, 36, 16, BLINK, 39, 16, BLINK, 43, 16, BLINK, 46, 16, BLINK, 50, 16, BLINK, 53, 16, BLINK, 56, 16, BLINK, 59, 16, BLINK, 62, 16, BLINK, 65, 16, BLINK, 68, 16, BLINK, 71, 16, BLINK, 73, 16, BLINK, 76, 16, BLINK, 78, 16, BLINK, 81, 16, BLINK, 83, 16, BLINK, 85, 16, BLINK, 87, 16, BLINK, 89, 16, BLINK, 91, 16, BLINK, 93, 16, BLINK, 94, 16, BLINK, 96, 16, BLINK, 97, 16, BLINK, 99, 16, BLINK, 100, 16, BLINK, 101, 16, BLINK, 102, 16, BLINK, 103, 16, BLINK, 104, 16, BLINK, 104, 16, BLINK, 105, 16, BLINK, 105, 16, BLINK, 106, 16, BLINK, 106, 16, BLINK, 106, 16, BLINK, 106, 16, BLINK, 106, 16, BLINK, 106, 16, BLINK, 106, 16, BLINK, 106, 16, BLINK, 105, 16, BLINK, 105, 16, BLINK, 104, 16, BLINK, 104, 16, BLINK, 103, 16, BLINK, 102, 16, BLINK, 101, 16, BLINK, 100, 16, BLINK, 99, 16, BLINK, 0, 16, BLINK, 2, 16, BLINK, 3, 16, BLINK, 4, 16, BLINK, 6, 16, BLINK, 7, 16, BLINK, 8, 16, BLINK, 9, 16, BLINK, 10, 16, BLINK, 11, 16, BLINK, 12, 16, BLINK, 13, 16, BLINK, 13, 16, BLINK, 14, 16, BLINK, 14, 16, BLINK, 15, 16, BLINK, 15, 16, BLINK, 15, 16, BLINK, 15, 16, BLINK, 16, 16, BLINK, 16, 16, BLINK, 16, 16, BLINK, 16, 16, BLINK, 16, 16, BLINK, 15, 16, BLINK, 15, 16, BLINK, 15, 16, BLINK, 15, 16, BLINK, 14, 16, BLINK, 14, 16, BLINK, 14, 16, BLINK, 13, 16, BLINK, 13, 16, BLINK, 12, 16, BLINK, 12, 16, BLINK, 11, 16, BLINK, 11, 16, BLINK, 10, 16, BLINK, 9, 16, BLINK, 9, 16, BLINK, 8, 16, BLINK, 8, 16, BLINK, 7, 16, BLINK, 6, 16, BLINK, 6, 16, BLINK, 5, 16, BLINK, 5, 16, BLINK, 4, 16, BLINK, 4, 16, BLINK, 3, 16, BLINK, 3, 16, BLINK, 2, 16, BLINK, 2, 16, BLINK, 1, 16, BLINK, 1, 16, BLINK, 1, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16,

  //modulated blinkies, 5s
  START, 10, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 26, 16, BLINK, 28, 16, BLINK, 29, 16, BLINK, 31, 16, BLINK, 33, 16, BLINK, 35, 16, BLINK, 36, 16, BLINK, 38, 16, BLINK, 40, 16, BLINK, 42, 16, BLINK, 44, 16, BLINK, 46, 16, BLINK, 48, 16, BLINK, 50, 16, BLINK, 53, 16, BLINK, 55, 16, BLINK, 57, 16, BLINK, 59, 16, BLINK, 61, 16, BLINK, 64, 16, BLINK, 66, 16, BLINK, 68, 16, BLINK, 71, 16, BLINK, 73, 16, BLINK, 76, 16, BLINK, 78, 16, BLINK, 81, 16, BLINK, 83, 16, BLINK, 86, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 169, 16, BLINK, 172, 16, BLINK, 174, 16, BLINK, 177, 16, BLINK, 179, 16, BLINK, 182, 16, BLINK, 184, 16, BLINK, 187, 16, BLINK, 189, 16, BLINK, 191, 16, BLINK, 194, 16, BLINK, 196, 16, BLINK, 198, 16, BLINK, 200, 16, BLINK, 202, 16, BLINK, 205, 16, BLINK, 207, 16, BLINK, 209, 16, BLINK, 211, 16, BLINK, 213, 16, BLINK, 215, 16, BLINK, 217, 16, BLINK, 219, 16, BLINK, 220, 16, BLINK, 222, 16, BLINK, 224, 16, BLINK, 226, 16, BLINK, 227, 16, BLINK, 229, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 254, 16, BLINK, 254, 16, BLINK, 254, 16, BLINK, 253, 16, BLINK, 253, 16, BLINK, 252, 16, BLINK, 252, 16, BLINK, 251, 16, BLINK, 250, 16, BLINK, 250, 16, BLINK, 249, 16, BLINK, 248, 16, BLINK, 247, 16, BLINK, 246, 16, BLINK, 245, 16, BLINK, 244, 16, BLINK, 243, 16, BLINK, 242, 16, BLINK, 240, 16, BLINK, 239, 16, BLINK, 238, 16, BLINK, 237, 16, BLINK, 235, 16, BLINK, 234, 16, BLINK, 232, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 164, 16, BLINK, 162, 16, BLINK, 159, 16, BLINK, 157, 16, BLINK, 154, 16, BLINK, 151, 16, BLINK, 149, 16, BLINK, 146, 16, BLINK, 143, 16, BLINK, 141, 16, BLINK, 138, 16, BLINK, 136, 16, BLINK, 133, 16, BLINK, 130, 16, BLINK, 128, 16, BLINK, 125, 16, BLINK, 122, 16, BLINK, 119, 16, BLINK, 117, 16, BLINK, 114, 16, BLINK, 112, 16, BLINK, 109, 16, BLINK, 106, 16, BLINK, 104, 16, BLINK, 101, 16, BLINK, 98, 16, BLINK, 96, 16, BLINK, 93, 16, BLINK, 91, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 23, 16, BLINK, 21, 16, BLINK, 20, 16, BLINK, 18, 16, BLINK, 17, 16, BLINK, 16, 16, BLINK, 15, 16, BLINK, 13, 16, BLINK, 12, 16, BLINK, 11, 16, BLINK, 10, 16, BLINK, 9, 16, BLINK, 8, 16, BLINK, 7, 16, BLINK, 6, 16, BLINK, 5, 16, BLINK, 5, 16, BLINK, 4, 16, BLINK, 3, 16, BLINK, 3, 16, BLINK, 2, 16, BLINK, 2, 16, BLINK, 1, 16, BLINK, 1, 16, BLINK, 1, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16,

  //gentle waves w/ flicker, 5s
  START, 10, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 132, 16, BLINK, 132, 16, BLINK, 133, 16, BLINK, 134, 16, BLINK, 134, 16, BLINK, 135, 16, BLINK, 135, 16, BLINK, 136, 16, BLINK, 137, 16, BLINK, 137, 16, BLINK, 138, 16, BLINK, 139, 16, BLINK, 140, 16, BLINK, 140, 16, BLINK, 141, 16, BLINK, 142, 16, BLINK, 143, 16, BLINK, 144, 16, BLINK, 145, 16, BLINK, 146, 16, BLINK, 147, 16, BLINK, 148, 16, BLINK, 149, 16, BLINK, 150, 16, BLINK, 151, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 161, 16, BLINK, 162, 16, BLINK, 163, 16, BLINK, 164, 16, BLINK, 165, 16, BLINK, 167, 16, BLINK, 168, 16, BLINK, 169, 16, BLINK, 170, 16, BLINK, 172, 16, BLINK, 173, 16, BLINK, 174, 16, BLINK, 175, 16, BLINK, 177, 16, BLINK, 178, 16, BLINK, 179, 16, BLINK, 181, 16, BLINK, 182, 16, BLINK, 183, 16, BLINK, 185, 16, BLINK, 186, 16, BLINK, 187, 16, BLINK, 189, 16, BLINK, 190, 16, BLINK, 191, 16, BLINK, 193, 16, BLINK, 194, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 212, 16, BLINK, 213, 16, BLINK, 215, 16, BLINK, 216, 16, BLINK, 217, 16, BLINK, 218, 16, BLINK, 220, 16, BLINK, 221, 16, BLINK, 222, 16, BLINK, 223, 16, BLINK, 224, 16, BLINK, 225, 16, BLINK, 227, 16, BLINK, 228, 16, BLINK, 229, 16, BLINK, 230, 16, BLINK, 231, 16, BLINK, 232, 16, BLINK, 233, 16, BLINK, 234, 16, BLINK, 235, 16, BLINK, 236, 16, BLINK, 237, 16, BLINK, 238, 16, BLINK, 239, 16, BLINK, 240, 16, BLINK, 240, 16, BLINK, 241, 16, BLINK, 242, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 250, 16, BLINK, 251, 16, BLINK, 251, 16, BLINK, 251, 16, BLINK, 252, 16, BLINK, 252, 16, BLINK, 253, 16, BLINK, 253, 16, BLINK, 253, 16, BLINK, 254, 16, BLINK, 254, 16, BLINK, 254, 16, BLINK, 254, 16, BLINK, 254, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 252, 16, BLINK, 251, 16, BLINK, 251, 16, BLINK, 251, 16, BLINK, 250, 16, BLINK, 249, 16, BLINK, 249, 16, BLINK, 248, 16, BLINK, 248, 16, BLINK, 247, 16, BLINK, 246, 16, BLINK, 246, 16, BLINK, 245, 16, BLINK, 244, 16, BLINK, 244, 16, BLINK, 243, 16, BLINK, 242, 16, BLINK, 241, 16, BLINK, 240, 16, BLINK, 240, 16, BLINK, 239, 16, BLINK, 238, 16, BLINK, 237, 16, BLINK, 236, 16, BLINK, 235, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 217, 16, BLINK, 216, 16, BLINK, 215, 16, BLINK, 213, 16, BLINK, 212, 16, BLINK, 211, 16, BLINK, 210, 16, BLINK, 208, 16, BLINK, 207, 16, BLINK, 206, 16, BLINK, 205, 16, BLINK, 203, 16, BLINK, 202, 16, BLINK, 201, 16, BLINK, 199, 16, BLINK, 198, 16, BLINK, 197, 16, BLINK, 195, 16, BLINK, 194, 16, BLINK, 193, 16, BLINK, 191, 16, BLINK, 190, 16, BLINK, 189, 16, BLINK, 187, 16, BLINK, 186, 16, BLINK, 185, 16, BLINK, 183, 16, BLINK, 182, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 174, 16, BLINK, 173, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 165, 16, BLINK, 164, 16, BLINK, 163, 16, BLINK, 162, 16, BLINK, 161, 16, BLINK, 159, 16, BLINK, 158, 16, BLINK, 157, 16, BLINK, 156, 16, BLINK, 155, 16, BLINK, 154, 16, BLINK, 153, 16, BLINK, 152, 16, BLINK, 151, 16, BLINK, 150, 16, BLINK, 149, 16, BLINK, 148, 16, BLINK, 147, 16, BLINK, 146, 16, BLINK, 145, 16, BLINK, 144, 16, BLINK, 143, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 134, 16, BLINK, 133, 16, BLINK, 132, 16, BLINK, 132, 16, BLINK, 131, 16, BLINK, 131, 16, BLINK, 131, 16, BLINK, 130, 16, BLINK, 130, 16, BLINK, 130, 16, BLINK, 129, 16, BLINK, 129, 16, BLINK, 129, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16, BLINK, 128, 16,

  //chopped waves, 1.5s
  START, 20, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 12, 16, BLINK, 16, 16, BLINK, 21, 16, BLINK, 27, 16, BLINK, 34, 16, BLINK, 42, 16, BLINK, 51, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 100, 16, BLINK, 116, 16, BLINK, 135, 16, BLINK, 156, 16, BLINK, 180, 16, BLINK, 207, 16, BLINK, 238, 16, BLINK, 255, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 238, 16, BLINK, 207, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 100, 16, BLINK, 85, 16, BLINK, 72, 16, BLINK, 61, 16, BLINK, 51, 16, BLINK, 42, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 0, 16, BLINK, 12, 16, BLINK, 8, 16, BLINK, 5, 16, BLINK, 3, 16, BLINK, 1, 16, BLINK, 0, 16, BLINK, 0, 16,

  //swoops, 0.75s
  START, 40, BLINK, 0, 16, BLINK, 1, 16, BLINK, 5, 16, BLINK, 12, 16, BLINK, 21, 16, BLINK, 34, 16, BLINK, 51, 16, BLINK, 72, 16, BLINK, 100, 16, BLINK, 135, 16, BLINK, 180, 16, BLINK, 238, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 238, 16, BLINK, 180, 16, BLINK, 135, 16, BLINK, 100, 16, BLINK, 72, 16, BLINK, 51, 16, BLINK, 34, 16, BLINK, 21, 16, BLINK, 12, 16, BLINK, 5, 16, BLINK, 1, 16, BLINK, 0, 16,

  //inverse swoops, 0.5s
  START, 50, BLINK, 0, 16, BLINK, 0, 16, BLINK, 1, 16, BLINK, 3, 16, BLINK, 5, 16, BLINK, 9, 16, BLINK, 13, 16, BLINK, 21, 16, BLINK, 31, 16, BLINK, 48, 16, BLINK, 76, 16, BLINK, 129, 16, BLINK, 242, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 255, 16, BLINK, 242, 16, BLINK, 129, 16, BLINK, 77, 16, BLINK, 48, 16, BLINK, 31, 16, BLINK, 21, 16, BLINK, 13, 16, BLINK, 9, 16, BLINK, 5, 16, BLINK, 3, 16, BLINK, 1, 16, BLINK, 0, 16, BLINK, 0, 16,

  END,
};
unsigned short int patterns(unsigned short int i) {
  return pgm_read_word(&pattern_data[i]);
}

unsigned int pc; //Preset Counter
unsigned int pRepeat; //Repeat Counter


void resetPreset() {
  //Serial.println("reset presets");
  pc = 0;
  pRepeat = 0;
}

void selectRandomPreset() {
  short int increment = random(0, 200);
  LOG_SEEK && Serial.print("s: seeking preset +");
  LOG_SEEK && Serial.println(increment);
  while (increment > 0) {
    switch (patterns(pc)) {
      case END:
        resetPreset();
        continue;
      case START:
        LOG_SEEK && Serial.println("s: new pattern");
        increment -= patterns(pc + 1);
        pc += 2;
        continue;
      case BLINK:
      case UBLINK:
        LOG_SEEK && Serial.println("s: blink");
        pc += 3;
        continue;
      case REPEAT:
        LOG_SEEK && Serial.println("s: repeat");
        pc += 3; //skip delay value
        continue;
      default: //Unknown command, we probably mucked up the number of args to a command or something.
        Serial.print("s: invalid command ");
        Serial.print(patterns(pc));
        Serial.print("@");
        Serial.println(pc);
        delay(100); //flush the buffer
        exit(5); //Invalid command. Ruh roh.
    }
  }
}

void processPreset() {
  LOG_EXEC && Serial.print("p: command ");
  LOG_EXEC && Serial.print(patterns(pc));
  LOG_EXEC && Serial.print("@");
  LOG_EXEC && Serial.println(pc);
  switch (patterns(pc)) {
    return; case END:
      resetPreset();
    return; case START: //Seek random preset when we enholdCounter the start of one.
      selectRandomPreset();
    return; case BLINK:
      LOG_EXEC && Serial.println("p: blink ledPin");
      pc++; //consume instruction
      analogWrite(ledPin, patterns(pc++));
      delay(patterns(pc++));
    return; case UBLINK:
      LOG_EXEC && Serial.println("p: ublink ledPin");
      pc++; //consume instruction
      analogWrite(ledPin, patterns(pc++));
      delayMicroseconds(patterns(pc++));
    return; case REPEAT:
      LOG_EXEC && Serial.print("p: loop ");
      LOG_EXEC && Serial.println(pRepeat);
      switch (pRepeat) {
        break; case 0: //First loop.
          pRepeat = patterns(pc + 2) + 1;
          pc -= patterns(pc + 1);
        break; case 1: //Last loop. Skip the repeat this time.
          pRepeat--;
          pc += 3;
        break; default:
          pRepeat--;
          pc -= patterns(pc + 1);
      }
    return; default:
      Serial.print("p: invalid command ");
      Serial.print(patterns(pc));
      Serial.print("@");
      Serial.println(pc);
      delay(100);
      exit(5); //Invalid command. Ruh roh.
  }
}


//Power Sequences

void iHandler() {
  sei();
  buttonHandler++;
  cli();
}

int BatteryReport() {
  mode--;
  mode--;

  delay(200);
  //battery feedback here
  analogWrite(ledPin, 10);
  delay(2000);
  analogWrite(ledPin, 255);
  delay(100);
  analogWrite(ledPin, 10);
  delay(100);
  analogWrite(ledPin, 255);
  delay(100);
  analogWrite(ledPin, 10);
  delay(100);
  analogWrite(ledPin, 255);
  delay(100);
  analogWrite(ledPin, 0);
  delay(2000);
}

int PowerUp() {
  mode--;
  analogWrite(ledPin, 10);
  delay(70);
  analogWrite(ledPin, 50);
  delay(70);
  analogWrite(ledPin, 100);
  delay(70);
  analogWrite(ledPin, 150);
  delay(70);
  analogWrite(ledPin, 200);
  delay(70);
  analogWrite(ledPin, 255);
  delay(1000);
  powerStatus = 1;
  mode = EEPROM.read(0);
  void setup();
  //PSU pullup
}

int PowerDown() {
  mode--;


  analogWrite(ledPin, 255);
  delay(70);
  analogWrite(ledPin, 200);
  delay(70);
  analogWrite(ledPin, 150);
  delay(70);
  analogWrite(ledPin, 100);
  delay(70);
  analogWrite(ledPin, 50);
  delay(70);
  analogWrite(ledPin, 10);
  EEPROM.write(0, mode);
  delay(1000);
  analogWrite(ledPin, 0);

  powerStatus = 0;
  //psu pullup
  //low power mode
}
