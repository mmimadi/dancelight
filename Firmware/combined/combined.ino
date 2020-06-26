#include<Arduino.h>
#include<EEPROM.h>
#include<avr/sleep.h>
#include<avr/wdt.h>

#define END 0
#define START 1
#define BLINK 2
#define UBLINK 3
#define REPEAT 4
#define LOG_SEEK false
#define LOG_EXEC false
#define LOG_MODE false

const byte batteryPin = 3;
float batteryVoltage = 0;
static const byte micInputPin = 0;
static const byte ledPin = 5;
const byte button = 2;

byte buttonState = 0; //HIGH/LOW
byte buttonHandler = 0; //Double Tap Variable Count
byte holdCounter = 0;
byte doubleTapSleep = 0;
byte doubleTapState = 0;
byte powerStatus = 1;
static byte mode = 1;
byte flash = 0;
byte blinkDelay = 0;

void setup() {
  Serial.begin(57600);
  pinMode(ledPin, OUTPUT);
  resetPreset();
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(button), iHandler, FALLING);
  pinMode(button, INPUT);
  pinMode(batteryPin, INPUT);
}

void loop() {
  buttonLogic();
  modeHandler();
}
void buttonLogic() {
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
    if (powerStatus == 0 && doubleTapSleep > 30) {
      
      byte wait = 0;
      while (wait <= 100) {
        //Serial.println(wait);
        delay(25);
        buttonState = digitalRead(button);
        if (buttonState == LOW) {
          buttonHandler++;
          buttonLogic();
        }
        analogWrite(ledPin, 10);
        wait++;
      }
      if (powerStatus == 0) {
        doubleTapState = 0;
        Sleep();
      }
    }
  }
  ////////////Old Polling Button Code///////////////////
  /*
    Monitor preset advancement button and run right preset.
    static const byte numModes = 3;
    static const unsigned long buttonPressConfirmationTimeMs = 50;

    static bool pressed = true;
    static bool lastProcessedPressed = false;
    static unsigned long eventTimeMs = 0;


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
}

void modeHandler() {
  if (mode == 1 && powerStatus == 1) {
    LOG_MODE && Serial.println("mode 1: react to sound");
    ringBufferLoop(); //use ring buffer beat detection

  } else if (mode == 2 && powerStatus == 1) {
    LOG_MODE && Serial.println("mode 2: blink");
    processPreset();

  } else if (mode == 3 && powerStatus == 1) {
    LOG_MODE && Serial.println("mode 3: solid");
    analogWrite(ledPin, 255);

  } else if (mode >= 4 && powerStatus == 1) {
    //Serial.print("Bad mode: ");
    // Serial.print(mode);
    //  Serial.println(". Reset to 1.");
    mode = 1;
  }
}
