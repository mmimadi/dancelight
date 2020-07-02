// Arduino Beat Detector By Damian Peckett 2015
// License: Public Domain.

/////CHANGES////////
/*took out cycle waster
 *thresh nuked from POT to static 40;
 */

#include "common.hpp"
#include "bandpass_filter_beat.hpp"

// Our Global Sample Rate, 5000hz
#define SAMPLEPERIODUS 200

BandpassFilterBeat::BandpassFilterBeat() {
    // Set ADC to 77khz, max for 10bit
    sbi(ADCSRA,ADPS2);
    cbi(ADCSRA,ADPS1);
    cbi(ADCSRA,ADPS0);

    //The pin with the LED
    pinMode(5, OUTPUT);
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
    unsigned long time = micros(); // Used to track rate
    static uint8_t sample_count = 0;
    static unsigned long nextSampleTime = 0;

    unsigned long currentSampleTime = micros();
    if (currentSampleTime < nextSampleTime) { return; }
    nextSampleTime = currentSampleTime + 20;
    sample_count++;

    // Read ADC and center so +-512
    float sample = (float)analogRead(0)-503.f;

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
        if(beat < thresh) analogWrite(5, 0);
        else analogWrite(5, 255);

        //Reset sample counter
        sample_count = 0;
    }
}