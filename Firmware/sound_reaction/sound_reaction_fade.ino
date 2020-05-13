///////SEXY REVISION//////

unsigned int micInputPin = 0;
unsigned int ledPin = 5;
float sampleCounter = 0;
float micRawValue = 0;
float processedResult = 0;

float percent = 10; //Set the % above the ambient sound to hit the light
int samples = 10; //Set # samples to calculate ambient sound
int grabSample = 0;
int grabCounter = 0;
unsigned int howBumpingIsIt = 0;
const unsigned int ITS_TOTALLY_LIT = 27;

void setup() {
  Serial.begin(9600);
  percent = percent / 100;
}

void loop() {

  while (sampleCounter <= samples) {

    Serial.println("processedResult");
    Serial.println(processedResult);
    delay(10);

    micRawValue = analogRead(micInputPin);
    processedResult = processedResult + micRawValue;

    delay(0);
    Serial.println(micRawValue); //debug
    sampleCounter++;

    while (sampleCounter == samples + 1) {
      //   processedResult = ((processedResult * percent) + processedResult) / sampleCounter; //old method
      processedResult = (processedResult / sampleCounter);

      //Ready animation
      analogWrite(ledPin, 255);
      delay(20);
      analogWrite(ledPin, 10);
      delay(20);
      analogWrite(ledPin, 255);
      delay(20);
      analogWrite(ledPin, 10);

      sampleCounter++;


    }

  }

  analogWrite(ledPin, 5); //standby brightness

  grabCounter++;

  if (grabCounter == 50) {
    grabSample = analogRead(micInputPin);
    processedResult = (grabSample + processedResult) / 2;
    sampleCounter++;
    grabCounter = 0;
    //Serial.println("grabbed");
  }


  //Serial.println("g");
  //Serial.println(grabCounter);




  // Serial.println(processedResult);
  micRawValue = analogRead(micInputPin);
  delay(0);
  BumpIt(); //LETTSS GOOOOOOOO
  if (howBumpingIsIt) {
    SoundFade();
  }
}

void BumpIt() {

  pinMode(ledPin, OUTPUT);
  micRawValue = analogRead(micInputPin);
  Serial.println(micRawValue);

  if (micRawValue > (processedResult * percent) + processedResult || micRawValue < (processedResult * percent) - processedResult) {
    howBumpingIsIt = ITS_TOTALLY_LIT;
  }
}
void writeAndDelay(unsigned int brightness, unsigned int ms) {
  analogWrite(ledPin, brightness);
  delay(ms);
}

void SoundFade() {
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
  howBumpingIsIt--;
}
