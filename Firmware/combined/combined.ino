/*
David Roberts
Michael Madi
www.flaketechnologies.ca
*/


//This version is ported for Mainboard REV 1.0 

#include "common.hpp"
#include "preset_pattern_formulaic.hpp"
#include "bandpass_filter_beat.hpp"

uint8_t mode = 1;
uint8_t powerStatus = 1; 

Mode* program = NULL; //how we're blinking, what mode

void setup() {
  Serial.begin(115200);
  power_setup();
}

void loop() {
  buttonLogic();
  checkCurrentModeChanged();
  program->loop();
}



//Mode logic.

class Pause: public Mode {
  public:
    void loop() {};
};
class Solid: public Mode {
  public:
    Solid::Solid() { analogWrite(ledPin, maxDutyCycle - 40); };
    void loop() {};
};

void checkCurrentModeChanged() {
  static uint8_t lastMode = 0;
  //Wrap mode back around, so it loops when you press the button.
  if (mode >= 4 && powerStatus == 1) {
    //Serial.print("Unknown mode, "); Serial.print(mode); Serial.println(". Reset to 1.");
    mode = 1;
  }
  
  if (mode == lastMode) { return; }
  lastMode = mode;
  
  delete program;
  Serial.print("mode ");
  Serial.println(mode);
  switch (mode) {
    case 0: program = new Pause();              break;
    case 1: program = new BandpassFilterBeat(); break;
    case 2: program = new PresetBlinkPattern(); break;
    case 3: program = new Solid();              break;
  }
}