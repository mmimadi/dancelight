/*
  The Goertzel algorithm is long standing so see 
  http://en.wikipedia.org/wiki/Goertzel_algorithm for a full description.
  It is often used in DTMF tone detection as an alternative to the Fast 
  Fourier Transform because it is quick with low overheard because it
  is only searching for a single frequency rather than showing the 
  occurrence of all frequencies.
  
  This work is entirely based on the Kevin Banks code found at
  http://www.eetimes.com/design/embedded/4024443/The-Goertzel-Algorithm 
  so full credit to him for his generic implementation and breakdown. I've
  simply massaged it into an Arduino library. I recommend reading his article
  for a full description of whats going on behind the scenes.

  See Contributors.md and add yourself for pull requests
  Released into the public domain.
*/

//copied from https://github.com/jacobrosenthal/Goertzel

// ensure this library description is only included once
#ifndef Goertzel_h
#define Goertzel_h

// include types & constants of Wiring core API
#include "Arduino.h"

#define MAXN 200
//#define ADCCENTER 512

// library interface description
class Goertzel
{
  public:
  Goertzel(float,float,float);
	void sample(uint8_t, uint8_t testData[]);
	float detect(uint8_t testData[]);

  private:
  float _SAMPLING_FREQUENCY = 0;
  float _TARGET_FREQUENCY = 0;
  int _N = 0;
  float coeff = 0;
  float Q1 = 0;
  float Q2 = 0;
  
	void ProcessSample(uint8_t sample, uint8_t adcCenter);
	void Goertzel::ResetGoertzel(void);
};

#endif

