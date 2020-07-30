#include <Arduino.h>

static const byte micInputPin = 0;
static constexpr byte button = digitalPinToInterrupt(2);
static const uint8_t batteryPin = 3;
static const byte ledPin = 5;

//Common base class for modes.
class Mode {
public:
	virtual void loop() = 0;  //Called from .ino's loop().
};

static uint8_t maxDutyCycle = 255;