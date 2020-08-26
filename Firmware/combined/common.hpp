#include <Arduino.h>

//#define DEV_BOARD

#ifdef DEV_BOARD
	////Arduino UNO and NANO Compatible Port////
	//Use Arduino Nano/ port ttyUSB0
	
	static const byte micInputPin = 0;
	static constexpr byte button = digitalPinToInterrupt(1); //from 2 to 1 for pcb
	static const uint8_t batteryPin = 3;
	static const byte ledPin = 5;

#else
	////Main Board Rev 1.0 Compatible Port////
	//Use ATtiny 1614/jtag2udpi port ttyACM0

	static const byte micInputPin = 10; //0 to 11 fpr [pcb
	static constexpr byte button = digitalPinToInterrupt(1); 
	static const uint8_t batteryPin = 6;
	static const byte ledPin = 7;
#endif

//Common base class for modes.
class Mode {
public:
	virtual void loop() = 0;  //Called from .ino's loop().
};

static uint8_t maxDutyCycle = 255;