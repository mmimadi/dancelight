///////SEXY REVISION//////


int micInputPin = 0;
int ledPin = 5;
int sampleCounter = 0;

float micRawValue = 10;
float percent = 200; //set sound threshold percentage
float processedResult = 0;


void setup() {
  Serial.begin(9600);
  percent = percent / 100;
}


void loop() {

  while (sampleCounter < 100) {

    //micRawValue = analogRead(micInputPin); //uncomment with actual mic attached
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

  //micRawValue = analogRead(micInputPin); //uncomment with actual mic attached
  pinMode(ledPin, OUTPUT);

  if (micRawValue > processedResult) {

    analogWrite(ledPin, 255); //use a DAC to generate sine wave and create a fade?
    delay(15);

  } else {

    analogWrite(ledPin, 20); //standbye brightness
  }
}
