///////SEXY REVISION//////

int micInputPin = 0;
int ledPin = 5;
int sampleCounter = 0;

float micRawValue = 10;
float percent = 100; //set sound threshold percentage
float processedResult = 0;


void setup() {
  Serial.begin(9600);
  percent = percent / 100;
}


void loop() {

  while (sampleCounter < 100) {

    micRawValue = analogRead(micInputPin); //uncomment with actual mic attached
    processedResult = processedResult + micRawValue;
    delay(7);
    Serial.println(micRawValue); //debug
    sampleCounter++;
  }
  ////////////////debug///////////////////
  Serial.println("totaled");
  Serial.println(processedResult);
  delay(100);
  ///////////////////////////////////////

  processedResult = ((processedResult * percent) + processedResult) / sampleCounter;

  ///////////////debug///////////////////
  Serial.println("DB threshold");
  Serial.println(processedResult);
  //////////////////////////////////////

  micRawValue = analogRead(micInputPin); //uncomment with actual mic attached
  pinMode(ledPin, OUTPUT);

  if (micRawValue > processedResult) {

    SoundFade();

  } else {

    analogWrite(ledPin, 20); //standbye brightness
  }
}

void SoundFade() {
  
  micRawValue = analogRead(micInputPin);
  analogWrite(ledPin, 255);
  delay(30);
  analogWrite(ledPin, 210);
  delay(10);
  analogWrite(ledPin, 200);
  delay(25);
  micRawValue = analogRead(micInputPin);
  analogWrite(ledPin, 190);
  delay(25);
  analogWrite(ledPin, 150);
  delay(25);
  micRawValue = analogRead(micInputPin);
  analogWrite(ledPin, 110);
  delay(25);
  analogWrite(ledPin, 50);
  delay(25);
  analogWrite(ledPin, 5);
  delay(100);
  micRawValue = analogRead(micInputPin);
}
