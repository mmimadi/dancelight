/*
  The Goertzel algorithm is long standing so see 
  http://en.wikipedia.org/wiki/Goertzel_algorithm for a full description.
  It is often used in DTMF tone detection as an alternative to the Fast 
  Fourier Transform because it is quick with low overheard because it
  is only searching for a single frequency rather than showing the 
  occurrence of all frequencies.
  
  This work is entirely based on the Kevin Banks code found at
  http://www.embedded.com/design/configurable-systems/4024443/The-Goertzel-Algorithm 
  so full credit to him for his generic implementation and breakdown. I've
  simply massaged it into an Arduino library. I recommend reading his article
  for a full description of whats going on behind the scenes.

  Created by Jacob Rosenthal, June 20, 2012.
  Released into the public domain.
*/

//copied from https://github.com/jacobrosenthal/Goertzel

// include core Wiring API
#include "Arduino.h"

// include this library's description file
#include "libgoertzel.hpp"

Goertzel::Goertzel(float TARGET_FREQUENCY, float N, float SAMPLING_FREQUENCY) {
  _SAMPLING_FREQUENCY=SAMPLING_FREQUENCY;	//on 16mhz, ~8928.57142857143, on 8mhz ~44444
  _TARGET_FREQUENCY=TARGET_FREQUENCY; //should be integer of SAMPLING_RATE/N
  if (N>MAXN) {
     _N=MAXN;
  } else {
    _N=N;
  }
  
  float omega = (2.0 * PI * _TARGET_FREQUENCY) / _SAMPLING_FREQUENCY;

  coeff = 2.0 * cos(omega);

  ResetGoertzel();
}


/* Call this routine before every "block" (size=N) of samples. */
void Goertzel::ResetGoertzel(void) {
  Q2 = 0;
  Q1 = 0;
}


/* Call this routine for every sample. */
void Goertzel::ProcessSample(uint8_t sample, uint8_t adcCenter) {
  float Q0;
  Q0 = coeff * Q1 - Q2 + ((float) sample - (float) adcCenter);
  Q2 = Q1;
  Q1 = Q0;
}


/* Sample some test data. */
void Goertzel::sample(uint8_t sensorPin, uint8_t testData[]) {
  for (int index = 0; index < _N; index++) {
    testData[index] = analogRead(sensorPin);
  }
}


float Goertzel::detect(uint8_t testData[]) {
  float	magnitude;

  /* Process the samples. */
  for (int index = 0; index < _N; index++) {
    ProcessSample(testData[index], 60); //DDR 2020-06-30: 60 is placeholder, best guess atm, will change in final hardware - cornflakes, update this!
  }

  /* Do the "standard Goertzel" processing. */
  magnitude = sqrt(Q1*Q1 + Q2*Q2 - coeff*Q1*Q2);

  ResetGoertzel();
  return magnitude;
}

