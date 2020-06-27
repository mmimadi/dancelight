#include "common.hpp"
#include "combined.hpp"
#include "preset_pattern_state_machine.hpp"
#include "power_sequences.hpp"
#include "ring_buffer_detection_mode.hpp"

#define LOG_MODE false

const byte button = digitalPinToInterrupt(2);

byte buttonState = 0; //HIGH/LOW
byte buttonHandler = 0; //Double Tap Variable Count
byte holdCounter = 0;
byte doubleTapSleep = 0;
byte doubleTapState = 0;
Mode* program = NULL;

void setup() {
  Serial.begin(57600);
  pinMode(ledPin, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(button, iHandler, FALLING);
  pinMode(button, INPUT);
  pinMode(batteryPin, INPUT);
  
  //test = new RingBufferThresholdBeat();
}

void loop() {
  buttonLogic();
  checkCurrentModeChanged();
  program->loop();
}

void iHandler() {
  sei();
  sleep_disable();
  buttonHandler++;
  cli();
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
}


class Pause: public Mode {
  public:
    void loop() {};
};
class Solid: public Mode {
  public:
    Solid::Solid() { analogWrite(ledPin, 255); };
    void loop() {};
};

uint8_t lastMode = 0;
void checkCurrentModeChanged() {
  //Wrap mode back around, so it loops when you press the button.
  if (mode >= 4 && powerStatus == 1) {
    //Serial.print("Unknown mode, "); Serial.print(mode); Serial.println(". Reset to 1.");
    mode = 1;
  }
  
  if (mode == lastMode) { return; }
  lastMode = mode;
  
  delete program;
  switch (mode) {
    case 0: program = new Pause();                   break;
    case 1: program = new RingBufferThresholdBeat(); break;
    case 2: program = new PresetBlinkPattern();      break;
    case 3: program = new Solid();                   break;
  }
}