#include "common.hpp"
#include "preset_pattern_state_machine.hpp"
#include "power_sequences.hpp"
#include "ring_buffer_detection_mode.hpp"

Power power = Power();
Mode* program = NULL; //how we're blinking, what mode

void setup() {
  Serial.begin(57600);
  power.setup();
}

void loop() {
  power.buttonLogic();
  checkCurrentModeChanged();
  program->loop();
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
  if (power.mode >= 4 && power.powerStatus == 1) {
    //Serial.print("Unknown mode, "); Serial.print(mode); Serial.println(". Reset to 1.");
    power.mode = 1;
  }
  
  if (power.mode == lastMode) { return; }
  lastMode = power.mode;
  
  delete program;
  switch (power.mode) {
    case 0: program = new Pause();                   break;
    case 1: program = new RingBufferThresholdBeat(); break;
    case 2: program = new PresetBlinkPattern();      break;
    case 3: program = new Solid();                   break;
  }
}