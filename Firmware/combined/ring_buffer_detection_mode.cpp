#include "common.hpp"
#include "ring_buffer_detection_mode.hpp"

//Add a sample to the buffer.
void RingBufferThresholdBeat::addSample(unsigned int sample) {
  last_sample_index = ++last_sample_index % SAMPLE_LENGTH;
  samples[last_sample_index] = sample;
}

//Get the average sample.
unsigned int RingBufferThresholdBeat::averageSample() const {
  unsigned int accum = 0;
  for (int i = 0; i < SAMPLE_LENGTH; i++) accum += samples[i];
  return accum / SAMPLE_LENGTH;
}

static int RingBufferThresholdBeat::sampleSortCriteria(const void* a, const void* b) {
  return *(unsigned int*)a - *(unsigned int*)b;
}

//Get the top/bottom nth percentile values.
void RingBufferThresholdBeat::findBoundingPercentiles(
  unsigned int& min,
  unsigned int& lower,
  unsigned int& middle,
  unsigned int& upper,
  unsigned int& max
) const {
  const unsigned int PERCENTILE_INVERSE = 20; //3 = 33%, 5 = 20%, 10 = 10%, etc.
  static unsigned int sortedSamples[SAMPLE_LENGTH] = {0};
  memcpy(sortedSamples, samples, SAMPLE_LENGTH * sizeof(samples[0]));
  qsort(sortedSamples, SAMPLE_LENGTH, sizeof(samples[0]), sampleSortCriteria);

  min = sortedSamples[0];
  lower = sortedSamples[SAMPLE_LENGTH / PERCENTILE_INVERSE];
  middle = sortedSamples[SAMPLE_LENGTH / 2];
  upper = sortedSamples[SAMPLE_LENGTH - SAMPLE_LENGTH / PERCENTILE_INVERSE];
  max = sortedSamples[SAMPLE_LENGTH - 1];
}


void RingBufferThresholdBeat::loop() {
  const float threshold = 0.9; //0..1 of max value in buffer
  auto sample = analogRead(micInputPin); //0..16000-ish, I think?

  unsigned int min, lower, middle, upper, max;
  findBoundingPercentiles(min, lower, middle, upper, max);
  
  if (LOG_LEVELS) {
    Serial.print("max "); Serial.print(max); Serial.print(", ");
    Serial.print("min "); Serial.print(min); Serial.print(", ");
    Serial.print("lower "); Serial.print(lower); Serial.print(", ");
    Serial.print("upper "); Serial.print(upper); Serial.print(", ");
    Serial.print("middle "); Serial.print(middle); Serial.print(", ");
    Serial.print("sample "); Serial.print(sample); Serial.println("");
  }
  
  auto average = averageSample();

  if ((sample > upper || sample < lower) && upper - lower > rbdm_silence_threshold && millis() > next_beat) {
    howBumpingIsIt = ITS_TOTALLY_LIT; // ヽ( •_)ᕗ
    //Serial.print("beat 120");
    next_beat = millis() + rbdm_min_beat_delay_ms;
  } else {
    //Serial.println("beat 80");
  }
  if (howBumpingIsIt) SoundFadeDelayless();

  if (!(loop_iterations % 2)) addSample(sample);
  //addSample(sample);
  loop_iterations++;
}

void RingBufferThresholdBeat::writeAndDelay(unsigned int brightness, unsigned int ms) {
  analogWrite(ledPin, brightness * 190 / 255);
  next_blink = millis() + ms;
}

void RingBufferThresholdBeat::SoundFadeDelayless() {
  if (millis() >= next_blink) {
    if (MODE == MODE_INSTANT) {
      switch (howBumpingIsIt) {
        case  2: writeAndDelay(255, 16); break;
        case  1: writeAndDelay(  5, 16); break;
      }
    } else {
      switch (howBumpingIsIt) {
        case 27: writeAndDelay(255, 2); break;
        case 26: writeAndDelay(250, 2); break;
        case 25: writeAndDelay(240, 2); break;
        case 24: writeAndDelay(230, 2); break;
        case 23: writeAndDelay(220, 2); break;
        case 22: writeAndDelay(210, 3); break;
        case 21: writeAndDelay(200, 3); break;
        case 20: writeAndDelay(190, 3); break;
        case 19: writeAndDelay(180, 3); break;
        case 18: writeAndDelay(170, 2); break;
        case 17: writeAndDelay(160, 3); break;
        case 16: writeAndDelay(150, 4); break;
        case 15: writeAndDelay(140, 5); break;
        case 14: writeAndDelay(130, 5); break;
        case 13: writeAndDelay(120, 6); break;
        case 12: writeAndDelay(110, 5); break;
        case 11: writeAndDelay(100, 5); break;
        case 10: writeAndDelay( 90, 5); break;
        case  9: writeAndDelay( 80, 5); break;
        case  8: writeAndDelay( 70, 3); break;
        case  7: writeAndDelay( 60, 3); break;
        case  6: writeAndDelay( 50, 3); break;
        case  5: writeAndDelay( 40, 3); break;
        case  4: writeAndDelay( 30, 3); break;
        case  3: writeAndDelay( 20, 3); break;
        case  2: writeAndDelay( 10, 3); break;
        case  1: writeAndDelay(  5, 1); break;
      }
    }
    howBumpingIsIt--;
  }
}
