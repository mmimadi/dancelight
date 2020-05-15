unsigned int micInputPin = 0;
unsigned int ledPin = 5;
float sampleCounter = 0;
float micRawValue = 0;
float processedResult = 0;

const float percent = 1; //Set the % above the ambient sound to hit the light
float beat_sensitivity = 1.0; //Adjusted to try to stay within target bpm range.

const int MODE_INSTANT = 0;
const int MODE_FADE = 1;
const int MODE = MODE_INSTANT;

unsigned int howBumpingIsIt = 0;
const unsigned int ITS_TOTALLY_LIT = MODE == MODE_INSTANT ? 2 : 27;

#define SAMPLE_LENGTH 100
unsigned int samples[SAMPLE_LENGTH] = {0};
unsigned int last_sample_index = SAMPLE_LENGTH - 1; //We just filled the array with 0s, so point to the last zero. (Makes initial sample code start from 0 instead of 1, not that it matters.)

//Add a sample to the buffer.
void addSample(unsigned int sample) {
  last_sample_index = ++last_sample_index % SAMPLE_LENGTH;
  samples[last_sample_index] = sample;
}

//Get the average sample.
unsigned int averageSample() {
  unsigned int accum = 0;
  for (int i = 0; i < SAMPLE_LENGTH; i++) accum += samples[i];
  return accum/SAMPLE_LENGTH;
}

//Get the top/bottom nth percentile values.
void findBoundingPercentiles(
  unsigned int* min, 
  unsigned int* lower, 
  unsigned int* middle, 
  unsigned int* upper,
  unsigned int* max
) {
  const unsigned int PERCENTILE_INVERSE = 10; //3 = 33%, 5 = 20%, 10 = 10%, etc.
  static unsigned int sortedSamples[SAMPLE_LENGTH] = {0};
  memcpy(sortedSamples, samples, SAMPLE_LENGTH * sizeof(samples[0]));
  qsort(sortedSamples, SAMPLE_LENGTH, sizeof(samples[0]), 
    [](unsigned int* a, unsigned int* b) { return &a < &b; });
  *min = sortedSamples[0];
  *lower = sortedSamples[SAMPLE_LENGTH/PERCENTILE_INVERSE];
  *middle = sortedSamples[SAMPLE_LENGTH/2];
  *upper = sortedSamples[SAMPLE_LENGTH - SAMPLE_LENGTH/PERCENTILE_INVERSE];
  *max = sortedSamples[SAMPLE_LENGTH];
}


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  analogWrite(ledPin, 5); //standby brightness
}


void loop() {
  const float threshold = 0.9; //0..1 of max value in buffer
  auto sample = analogRead(micInputPin); //0..16000-ish, I think?
  
  unsigned int min, lower, middle, upper, max;
  findBoundingPercentiles(&min, &lower, &middle, &upper, &max);
  auto average = averageSample();
  
  if (sample - min > (max - min) * 0.9) {
    howBumpingIsIt = ITS_TOTALLY_LIT; // ヽ( •_)ᕗ
  }
  if (howBumpingIsIt) SoundFade();
  
  addSample(sample);
}

void writeAndDelay(unsigned int brightness, unsigned int ms) {
  analogWrite(ledPin, brightness);
  if (ms) delay(ms);
}

void SoundFade() {
  if (MODE == MODE_INSTANT) {
    switch (howBumpingIsIt) {
      case  2: writeAndDelay(255,  0); break;
      case  1: writeAndDelay(  5,  0); break;
    }
  } else {
    switch (howBumpingIsIt) {
      case 27: writeAndDelay(255, 60); break;
      case 26: writeAndDelay(250, 20); break;
      case 25: writeAndDelay(240, 20); break;
      case 24: writeAndDelay(230, 20); break;
      case 23: writeAndDelay(220, 20); break;
      case 22: writeAndDelay(210, 30); break;
      case 21: writeAndDelay(200, 30); break;
      case 20: writeAndDelay(190, 30); break;
      case 19: writeAndDelay(180, 30); break;
      case 18: writeAndDelay(170, 20); break;
      case 17: writeAndDelay(160, 30); break;
      case 16: writeAndDelay(150, 40); break;
      case 15: writeAndDelay(140, 50); break;
      case 14: writeAndDelay(130, 55); break;
      case 13: writeAndDelay(120, 60); break;
      case 12: writeAndDelay(110, 50); break;
      case 11: writeAndDelay(100, 50); break;
      case 10: writeAndDelay( 90, 50); break;
      case  9: writeAndDelay( 80, 50); break;
      case  8: writeAndDelay( 70, 30); break;
      case  7: writeAndDelay( 60, 30); break;
      case  6: writeAndDelay( 50, 30); break;
      case  5: writeAndDelay( 40, 30); break;
      case  4: writeAndDelay( 30, 30); break;
      case  3: writeAndDelay( 20, 30); break;
      case  2: writeAndDelay( 10, 30); break;
      case  1: writeAndDelay(  5, 10); break;
    }
  }
  howBumpingIsIt--;
}
