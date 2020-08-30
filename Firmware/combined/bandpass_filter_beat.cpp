// Arduino Beat Detector By Damian Peckett 2015
// License: Public Domain.

/////CHANGES////////
/*took out cycle waster
 *thresh nuked from POT to static 40;
 */

#include "common.hpp"
#include "bandpass_filter_beat.hpp"

//Switch the modes - use MODE_INSTANT to (more or less) eliminate the variable of the fade.
static const int BandpassFilterBeat::MODE = BandpassFilterBeat::MODE_FADE;

BandpassFilterBeat::BandpassFilterBeat() { //////////////////these registers set the ADC SETTINGS. We need to find equivilent ones to the ARDUINO UNO/NANO for the ATTIY1614. See the datasheet///////////////////////
    //Set ADC to 77khz, max for 10bit
    
    #ifdef DEV_BOARD
        sbi(ADCSRA,ADPS2);
        cbi(ADCSRA,ADPS1);
        cbi(ADCSRA,ADPS0);
    #else
        //This *SHOULD* set the ADC to freerunning mode. Try replacing 3 with 10)
        ADC0.MUXPOS  = 3;
        ADC0.COMMAND = ADC_STCONV_bm;

        //this sets the prescaler. it should be set to 77khz but I have no idea how to do that. it is set way higher right now.
        ADC0.CTRLC = ADC_PRESC_DIV2_gc  
           | ADC_REFSEL_INTREF_gc  
           | 0 << ADC_SAMPCAP_bp;  
    #endif
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
    const float bias = 80.0f;
    
    // In the original project, threshold was based on a potentiometer on AN1. On ours, it auto-adjusts.
    const float envelopeThreshold = 30;
    static unsigned long nextSampleTime = 0; // Used to track rate. A bit optimistic, quite frankly, with skew wandering between 0, 8, 255, and a handful of other values.
    static uint8_t sample_count = 0;
    float sample;
    
    static float threshold = 0;
    static float silence = 15.0; //arbitrary units 🙄 - this is min threshold
    static float cycles_since_beat;
    static float cycles_since_beat_deviance;
    static bool beatDetected = false;
    static float envelopeAvg = 0;

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
            envelopeAvg = envelopeAvg*0.9 + envelope*0.1;
            
            
            // If we are above threshold, light up LED
            //analogWrite(ledPin, 255 * (beat < envelopeThreshold));
            Serial.print(", howLoudIsIt1 "); Serial.print(howLoudIsIt*0.10);
            Serial.print(", howLoudIsIt2 "); Serial.print(howLoudIsIt*0.50);
            Serial.print(", envelopeAvg "); Serial.print(envelopeAvg);
            Serial.print(", beat "); Serial.print(beat);
            Serial.print(", thresh "); Serial.print(envelopeThreshold);
            
            if(beat > 0 && envelopeAvg > envelopeThreshold && envelopeAvg > howLoudIsIt*0.50) {
                if (!beatDetected) {
                    howBumpingIsIt = ITS_TOTALLY_LIT; // ヽ( •_)ᕗ
                    beatDetected = true;
                    Serial.print(", hi "); Serial.print(20);
                } else {
                    Serial.print(", hi "); Serial.print(10);
                }
            } else {
                beatDetected = false;
                Serial.print(", hi "); Serial.print(0);
            }
            Serial.println("");

            //Reset sample counter
            sample_count = 0;
        }
    }

    //Serial.print("sample "); Serial.print(sample);
    if (sample > howLoudIsIt) { //Increase fast, fade slow.
        howLoudIsIt = (0.99 * howLoudIsIt + 0.01 * abs(sample));
    } else {
        howLoudIsIt = (0.99999 * howLoudIsIt + 0.00001 * abs(sample));
    }
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
        case  2: writeAndDelay(255, 4); break;
        case  1: writeAndDelay(  5, 0); break;
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
