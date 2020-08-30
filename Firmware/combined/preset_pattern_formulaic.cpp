#include "common.hpp"
#include "preset_pattern_formulaic.hpp"

PresetBlinkPattern::PresetBlinkPattern() {
  c = randWave(nullptr);
  n = randWave(c);
  t = f = 0;
  d = millis()+phaseMS;
};


void PresetBlinkPattern::loop() {
  delay(24);
  t+=0.02;
  f=min(1,f+0.005);
  float i = c(t)*(1-f) + n(t)*f;
  // Serial.print("ret: "); Serial.println(i);
  // Serial.print("f  : "); Serial.println(f);
  analogWrite(ledPin, floor(pow(i, 2)*maxDutyCycle));
  
  //Next preset.
  if (d<millis()) {
    c=n;
    n=randWave(n);
    f=0;
    d+=phaseMS;
  }
}


//Waveforms. (Visualise on http://fooplot.com.)

float PresetBlinkPattern::weird_waves(float x) {
  return -(sin(x/10*pi) * sin(x/10*pi)) * (-fmod(x,2.f)) / 2; //using pow() here causes an internal compiler error
};

float PresetBlinkPattern::buzz_pulse(float x) {
  return sin(tan(x))/2+0.5;
};

float PresetBlinkPattern::wiggle_waggle(float x) {
  return sin(pow((cos(x)*2),2)) * cos(x/2) / 2+0.5;
};

float PresetBlinkPattern::square(float x) {
  return float(uint32_t(x/3)%2);
};

float PresetBlinkPattern::sawtooth(float x) {
  return x - uint32_t(x);
};

float PresetBlinkPattern::grand_canyon(float x) {
  return min(1, sqrt(abs(tan(x)))/2) * 0.8 + (sin(x*40)/2+0.5) * 0.2;
};

float PresetBlinkPattern::fuzzy_waves(float x) {
  return (sin(x) / 2.0 + 0.5) * 0.8 + (cos(x*103.0) > tan(x*157.0)) * 0.2;
};


PresetBlinkPattern::Func PresetBlinkPattern::randWave(PresetBlinkPattern::Func prev) {
  const static Func waves[] = {
    weird_waves,
    buzz_pulse,
    wiggle_waggle,
    square,
    sawtooth,
    grand_canyon,
    fuzzy_waves,
  };
  
  auto next = waves[random(0,(sizeof(waves)/sizeof(*waves))+1)];
  return next == prev ? randWave(prev) : next;
}
