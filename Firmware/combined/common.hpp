#include <Arduino.h>
#include <EEPROM.h>
#include <avr/sleep.h>
#include <avr/wdt.h>

static const byte micInputPin = 0;
static const byte ledPin = 5;

//Common base class for modes.
class Mode {
public:
	virtual void loop() = 0;  //Called from .ino's loop().
};