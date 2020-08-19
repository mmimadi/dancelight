// Arduino Beat Detector By Damian Peckett 2015
// License: Public Domain.

/////CHANGES////////
/*took out cycle waster
 *thresh nuked from POT to static 40;
 */

#include "common.hpp"
#include "bandpass_filter_beat.hpp"

// Our Global Sample Rate, 5000hz
// #define SAMPLEPERIODUS 200

static const int BandpassFilterBeat::MODE = BandpassFilterBeat::MODE_FADE;

BandpassFilterBeat::BandpassFilterBeat() { //////////////////these registers set the ADC SETTINGS. We need to find equivilent ones to the ARDUINO UNO/NANO for the ATTIY1614. See the datasheet///////////////////////
    // Set ADC to 77khz, max for 10bit
//    sbi(STCONV); //i think this part is broken? Refer to original code to fix 
//    cbi(ADCSRA,ADPS1);
  //  cbi(ADCSRA,ADPS0);

    //The pin with the LED
    pinMode(7, OUTPUT); 
}

// 20 - 200hz Single Pole Bandpass IIR Filter
const float BandpassFilterBeat::bassFilter(float sample) {
    static float xv[3] = {0,0,0}, yv[3] = {0,0,0};
    xv[0] = xv[1]; xv[1] = xv[2]; 
    xv[2] = (sample) / 3.f; // change here to values close to 2, to adapt for stronger or weeker sources of line level audio  
    

    yv[0] = yv[1]; yv[1] = yv[2]; 
    yv[2] = (xv[2] - xv[0])
        + (-0.7960060012f * yv[0]) + (1.7903124146f * yv[1]);
    return yv[2];
}

// 10hz Single Pole Lowpass IIR Filter
const float BandpassFilterBeat::envelopeFilter(float sample) { //10hz low pass
    static float xv[2] = {0,0}, yv[2] = {0,0};
    xv[0] = xv[1]; 
    xv[1] = sample / 50.f;
    yv[0] = yv[1]; 
    yv[1] = (xv[0] + xv[1]) + (0.9875119299f * yv[0]);
    return yv[1];
}

// 1.7 - 3.0hz Single Pole Bandpass IIR Filter
const float BandpassFilterBeat::beatFilter(float sample) {
    static float xv[3] = {0,0,0}, yv[3] = {0,0,0};
    xv[0] = xv[1]; xv[1] = xv[2]; 
    xv[2] = sample / 2.7f;
    yv[0] = yv[1]; yv[1] = yv[2]; 
    yv[2] = (xv[2] - xv[0])
        + (-0.7169861741f * yv[0]) + (1.4453653501f * yv[1]);
    return yv[2];
}

void BandpassFilterBeat::loop() {
    const float bias = 500.3f;
    static unsigned long nextSampleTime = 0; // Used to track rate. A bit optimistic, quite frankly, with skew wandering between 0, 8, 255, and a handful of other values.
    static uint8_t sample_count = 0;
    float sample;

    //Code to detect beat.
    unsigned long currentSampleTime = micros();
    if (currentSampleTime >= nextSampleTime) {
        nextSampleTime = currentSampleTime + 20;
        sample_count++;

        // Read ADC and center so +-512
        sample = (float)analogRead(micInputPin)-bias;

        // Filter only bass component
        float value = bassFilter(sample);

        // Take signal amplitude and filter
        float envelope = envelopeFilter(abs(value));

        // Every 200 samples (25hz) filter the envelope 
        if(sample_count >= 200) {
            // Filter out repeating bass sounds 100 - 180bpm
            float beat = beatFilter(envelope);

            // Threshold it based on potentiometer on AN1
            float thresh = 40;

            // If we are above threshold, light up LED
            //if(beat < thresh) analogWrite(5, 0);
            //else analogWrite(5, 255);
            if(beat > thresh) {
                howBumpingIsIt = ITS_TOTALLY_LIT; // ヽ( •_)ᕗ
            }

            //Reset sample counter
            sample_count = 0;
        }
    }

    //Serial.print("sample "); Serial.print(sample);
    howLoudIsIt = (0.99 * howLoudIsIt + 0.01 * abs(sample));
    //Serial.print(", howLoudIsIt "); Serial.println(howLoudIsIt);
    if (howBumpingIsIt) { SoundFadeDelayless(); }
}

void BandpassFilterBeat::writeAndDelay(unsigned int brightness, unsigned int ms) {
  analogWrite(ledPin, 
    min(255, brightness + howLoudIsIt/5) * maxDutyCycle / 255);
  next_blink = millis() + ms;
}

void BandpassFilterBeat::SoundFadeDelayless() {
  if (millis() >= next_blink) {
    if (MODE == MODE_INSTANT) {
      switch (howBumpingIsIt) {
        case  2: writeAndDelay(255, 16); break;
        case  1: writeAndDelay(  5, 16); break;
      }
    } else {
      switch (howBumpingIsIt) {
        case 27: writeAndDelay(255, 20/4); break;
        case 26: writeAndDelay(250, 20/4); break;
        case 25: writeAndDelay(240, 20/4); break;
        case 24: writeAndDelay(230, 20/4); break;
        case 23: writeAndDelay(220, 20/4); break;
        case 22: writeAndDelay(210, 30/4); break;
        case 21: writeAndDelay(200, 30/4); break;
        case 20: writeAndDelay(190, 30/4); break;
        case 19: writeAndDelay(180, 30/4); break;
        case 18: writeAndDelay(170, 20/4); break;
        case 17: writeAndDelay(160, 30/4); break;
        case 16: writeAndDelay(150, 40/4); break;
        case 15: writeAndDelay(140, 50/4); break;
        case 14: writeAndDelay(130, 50/4); break;
        case 13: writeAndDelay(120, 60/4); break;
        case 12: writeAndDelay(110, 50/4); break;
        case 11: writeAndDelay(100, 50/4); break;
        case 10: writeAndDelay( 90, 50/4); break;
        case  9: writeAndDelay( 80, 50/4); break;
        case  8: writeAndDelay( 70, 30/4); break;
        case  7: writeAndDelay( 60, 30/4); break;
        case  6: writeAndDelay( 50, 30/4); break;
        case  5: writeAndDelay( 40, 30/4); break;
        case  4: writeAndDelay( 30, 30/4); break;
        case  3: writeAndDelay( 20, 30/4); break;
        case  2: writeAndDelay( 10, 30/4); break;
        case  1: writeAndDelay(  0, 10/4); break;
      }
    }
    howBumpingIsIt--;
  }
}
