/*
David Roberts
Michael Madi
www.flaketechnologies.ca
*/


//This version is ported for Mainboard REV 1.0 

#include "common.hpp"
#include "power_sequences.hpp"
#include "preset_pattern_formulaic.hpp"
#include "bandpass_filter_beat.hpp"

Power power = Power();
Mode* program = NULL; //how we're blinking, what mode

void setup() {
  Serial.begin(115200);
  power.setup();
  digitalWrite(3, HIGH);
}

void loop() {
  power.buttonLogic();
  checkCurrentModeChanged();
  program->loop();
  digitalWrite(3, HIGH);
}


class Pause: public Mode {
  public:
    void loop() {};
};
class Solid: public Mode {
  public:
    Solid::Solid() { analogWrite(ledPin, maxDutyCycle - 55); };
    void loop() {};
};

uint8_t lastMode = 0; 
void checkCurrentModeChanged() {
  //Wrap mode back around, so it loops when you press the button.
  if (power.mode >= 4 && power.powerStatus == 1) {
    //Serial.print("Unknown mode, "); Serial.print(mode); Serial.println(". Reset to 1.");
    power.mode = 1;
  }
  
  if (power.mode == lastMode) { return; }
  lastMode = power.mode;
  
  delete program;
  Serial.print("mode ");
  Serial.println(power.mode);
  switch (power.mode) {
    case 0: program = new Pause();                   break;
    case 1: program = new BandpassFilterBeat();      break;
    case 2: program = new PresetBlinkPattern();      break;
    case 3: program = new Solid();                   break;
  }
}
