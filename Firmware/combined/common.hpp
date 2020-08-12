#include <Arduino.h>

////Arduino UNO and NANO Compatible Port////

/*
static const byte micInputPin = 11; //0 to 11 fpr [pcb
static constexpr byte button = digitalPinToInterrupt(1); //from 2 to 1 for pcb
static const uint8_t batteryPin = 3;
static const byte ledPin = 4; //changed to 4 for pcb from 5
*/

////Main Board Rev 1.0 Compatible Port////

static const byte micInputPin = 10; //0 to 11 fpr [pcb
static constexpr byte button = digitalPinToInterrupt(1); 
static const uint8_t batteryPin = 6;
static const byte ledPin = 7;

//Common base class for modes.
class Mode {
public:
	virtual void loop() = 0;  //Called from .ino's loop().
};


static uint8_t maxDutyCycle = 255;
