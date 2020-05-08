///////SEXY REVISION//////

int micInputPin = 0;
int ledPin = 5;
float sampleCounter = 0;
float micRawValue = 0;
float processedResult = 0;

float percent = 10; //Set the % above the ambient sound to hit the light
int samples = 10; //Set # samples to calculate ambient sound

void setup() {
  Serial.begin(9600);
  percent = percent / 100;
}

void loop() {

  while (sampleCounter <= samples) {

    micRawValue = analogRead(micInputPin); //uncomment with actual mic attached
    processedResult = processedResult + micRawValue;

    delay(100);
    Serial.println(micRawValue); //debug
    sampleCounter++;

    while (sampleCounter == samples + 1) {
      processedResult = ((processedResult * percent) + processedResult) / sampleCounter;
      sampleCounter++;
    }

  }

 // Serial.println(processedResult);
micRawValue = analogRead(micInputPin);
  BumpIt(); //LETTSS GOOOOOOOO

}

void BumpIt() {

  pinMode(ledPin, OUTPUT);
   micRawValue = analogRead(micInputPin);
  Serial.println(micRawValue);

  if (micRawValue > processedResult) {
    SoundFade();

  } else {

    analogWrite(ledPin, 5); //standbye brightness
  }
}

void SoundFade() {

  analogWrite(ledPin, 255);
  BumpIt();
  delay(60);
  BumpIt();
  analogWrite(ledPin, 250);
  delay(20);
  BumpIt();
  analogWrite(ledPin, 240);
  delay(20);
  BumpIt();
  analogWrite(ledPin, 230);
  delay(20);
  BumpIt();
  analogWrite(ledPin, 220);
  delay(20);
  BumpIt();
  analogWrite(ledPin, 210);
  delay(30);
  BumpIt();
  analogWrite(ledPin, 200);
  delay(30);
  BumpIt();
  analogWrite(ledPin, 190);
  delay(30);
  BumpIt();
  analogWrite(ledPin, 180);
  delay(30);
  BumpIt();
  analogWrite(ledPin, 170);
  delay(20);
  BumpIt();
  analogWrite(ledPin, 160);
  delay(30);
  BumpIt();
  analogWrite(ledPin, 150);
  delay(40);
  BumpIt();
  analogWrite(ledPin, 140);
  delay(50);
  BumpIt();
  analogWrite(ledPin, 130);
  delay(55);
  BumpIt();
  analogWrite(ledPin, 120);
  delay(60);
  BumpIt();
  analogWrite(ledPin, 110);
  delay(50);
  BumpIt();
  analogWrite(ledPin, 100);
  delay(50);
  BumpIt();
  analogWrite(ledPin, 90);
  delay(50);
  BumpIt();
  analogWrite(ledPin, 80);
  delay(50);
  BumpIt();
  analogWrite(ledPin, 70);
  delay(30);
  BumpIt();
  analogWrite(ledPin, 60);
  delay(30);
  BumpIt();
  analogWrite(ledPin, 50);
  delay(30);
  BumpIt();
  analogWrite(ledPin, 40);
  delay(30);
  BumpIt();
  analogWrite(ledPin, 30);
  delay(30);
  BumpIt();
  analogWrite(ledPin, 20);
  delay(30);
  BumpIt();
  analogWrite(ledPin, 10);
  delay(30);
  BumpIt();
  analogWrite(ledPin, 5);
  delay(10);
  BumpIt();
 // analogWrite(ledPin, 200);
 // delay(50);
 // BumpIt();
 // analogWrite(ledPin, 10);
 // delay(50);
//  BumpIt();
//  analogWrite(ledPin, 100);
 // delay(30);
 // BumpIt();
 // analogWrite(ledPin, 5);
 // delay(50);
 // BumpIt();
}
