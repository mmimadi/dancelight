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
  Serial.begin(57600);
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
  
  if (mode == 0) {
    LOG_MODE && Serial.println("mode 1: react to sound");
    // processAudio(); //use exponential decay beat detection
    ringBufferLoop(); //use ring buffer beat detection
  } else if (mode == 1) {
    LOG_MODE && Serial.println("mode 2: blink");
    processPreset();
  } else if (mode == 2) {
    LOG_MODE && Serial.println("mode 0: solid");
    analogWrite(ledPin, 255);
  } else if (mode >= 3) {
    Serial.print("Bad mode: ");
    Serial.print(mode);
    Serial.println(". Reset to 0.");
    mode = 0;
  }
}