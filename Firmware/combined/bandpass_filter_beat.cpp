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
        return; //We don't have this figured out yet, so it listens at too high a frequency. But it listens…
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
    xv[2] = (sample) / 3.f; // change here to values close to 2, to adapt for stronger or weaker sources of line level audio  
    

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
    // In the original project, threshold was based on a potentiometer on AN1. On ours, it auto-adjusts.
    static const float envelopeThreshold = 25;
    static unsigned long nextSampleTime = 0; // Used to track rate. A bit optimistic, quite frankly, with skew wandering between 0, 8, 255, and a handful of other values.
    static uint8_t sample_count = 0;
    float sample, raw_sample;
    
    static float bias = 275.f; //Usually in the neighbourhood.
    static float threshold = 0;
    static float silence = 15.0; //arbitrary units 🙄 - this is min threshold
    static float cycles_since_beat;
    static float cycles_since_beat_deviance;
    static bool beatDetected = false;
    static float envelopeAvg = 0;
    const float envelopeConfidenceFactor = 0.50; //Higher = less confident.
    static float currentAvgVolume = 0; //long-term average, fast attack/slow decay
    static float currentSmlVolume = 0; //short-term average

    //Pump the beat detection.
    unsigned long currentSampleTime = micros();
    raw_sample = (float)analogRead(micInputPin);
    if (currentSampleTime >= nextSampleTime) {
        nextSampleTime = currentSampleTime + 20;
        sample_count++;

        // Read ADC and center so +-512
        bias = 0.9999*bias + 0.0001*raw_sample;
        sample = raw_sample - bias;

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
            
            //Serial.print(", bias "); Serial.print(bias);
            //Serial.print(", sample "); Serial.print(sample);
            //Serial.print(", fadeDuration "); Serial.print(fadeDuration);
            //Serial.print(", beat "); Serial.print(beat);
            //Serial.print(", envelopeAvg "); Serial.print(envelopeAvg);
            //Serial.print(", envelopeThreshold "); Serial.print(envelopeThreshold);
            //Serial.print(", ECF "); Serial.print(currentAvgVolume*envelopeConfidenceFactor);
            //Serial.print(", thresh "); Serial.print(envelopeThreshold);
            
            if(
                beat > 0
                && envelopeAvg > max(envelopeThreshold, currentAvgVolume*envelopeConfidenceFactor)
            ) {
                if (!beatDetected) {
                    unsigned long now = millis();
                    if (now - beatAtMs < 500) { //beat quickness → fade time - requires at least 120 bpm.
                        fadeDuration = fadeDuration * 0.95 + (now - beatAtMs) * 0.05;
                    } else { //fall back to the normal ¼sec fades.
                        fadeDuration = fadeDuration * 0.95 + (250           ) * 0.05;
                    }
                    beatAtMs = now;
                    howBumpingIsIt = ITS_TOTALLY_LIT; // ヽ( •_)ᕗ
                    beatDetected = true;
                    //Serial.print(", hi "); Serial.print(20);
                } else {
                    //Serial.print(", hi "); Serial.print(10);
                }
            } else {
                beatDetected = false;
                //Serial.print(", hi "); Serial.print(0);
            }
            Serial.println("");

            //Reset sample counter
            sample_count = 0;
        }
        
        //Serial.print("sample "); Serial.print(sample);
        if (sample > currentAvgVolume) { //Increase fast, fade slow.
            currentAvgVolume = (0.99 * currentAvgVolume + 0.01 * abs(sample));
        } else {
            currentAvgVolume = (0.9997 * currentAvgVolume + 0.0003 * abs(sample));
        }
    }
    
    
    currentSmlVolume = (0.97 * currentSmlVolume + 0.03 * abs(sample));

    
    //Pump the fade.
    if (MODE == MODE_INSTANT) {
        analogWrite(
            ledPin, 
            (beatAtMs+16 > millis()) * maxDutyCycle
        );
    } else {
        const float maxSmlVolume = 30.f;
        const float beatLightNormalized = 
            1 - ( //Light defaults to off, not on.
                + 0.95 * min( //95% of the light comes from 0..1 of the fade duration fade.
                    (float)(millis() - beatAtMs) / fadeDuration,
                    1
                )
                + 0.05 //Always keep the light on at 5%…
            );
        const float volumeLightNormalized = 
            1-pow(1-( //Make it x³ more sensitive.
                min(maxSmlVolume, 
                    max(0, currentSmlVolume-3.5) //Compensate for noise floor a bit.
                )/maxSmlVolume
            ), 3);
        
        const float envelopeThresholdMax = (max(envelopeThreshold, currentAvgVolume*envelopeConfidenceFactor));
        const float envelopeThresholdMin = envelopeThresholdMax - 10;
        const float mixFactor = max(0.05, min(1, (envelopeAvg - envelopeThresholdMin) / (envelopeThresholdMax - envelopeThresholdMin)));
        
        //Serial.print(", s1 "), Serial.print((envelopeAvg - envelopeThresholdMin));
        //Serial.print(", s2 "), Serial.print((envelopeThresholdMax - envelopeThresholdMin));
        //Serial.print(", mixFactor "), Serial.print(mixFactor);
        //Serial.println("");
        
        analogWrite(
            ledPin,
            (beatLightNormalized*(mixFactor) + volumeLightNormalized*(1-mixFactor)) * maxDutyCycle
        );
    }
}