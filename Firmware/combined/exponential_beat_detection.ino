//////////////////////////////////
//   Cornflakes' Dancing Code   //
//////////////////////////////////

void processAudio() {

  int sampleCounter = 0;
  float micRawValue = analogRead(micInputPin);
  float processedResult = 0;

  while (sampleCounter < 100) {

    micRawValue = analogRead(micInputPin); //uncomment with actual mic attached
    processedResult = processedResult + micRawValue;
    delay(7);
    // Serial.println(micRawValue); //debug
    sampleCounter++;
  }
  ////////////////debug///////////////////
  //  Serial.println("totaledPin");
  //  Serial.println(processedResult);
  // delay(100);
  ///////////////////////////////////////

  processedResult = ((processedResult * percent) + processedResult) / sampleCounter;

  ///////////////debug///////////////////
  // Serial.println("DB threshold");
  //  Serial.println(processedResult);
  //////////////////////////////////////

  BumpIt(); //LETTSS GOOOOOOOO

}

void BumpIt() {
  /*  float micRawValue = analogRead(micInputPin);
    micRawValue = analogRead(micInputPin); //uncomment with actual mic attached
    pinMode(ledPin, OUTPUT);
    float processedResult = 0;
    if (micRawValue > processedResult) {

      SoundFade();

    } else {

      analogWrite(ledPin, 20); //standbye brightness
    }


  */

  delay(20);
  delay(20);
  analogWrite(ledPin, 240);
  delay(20);
  analogWrite(ledPin, 230);
  delay(20);
  analogWrite(ledPin, 100);
  delay(20);
  analogWrite(ledPin, 10);

}

void SoundFade() {
  analogWrite(ledPin, 255);
  delay(60);
  analogWrite(ledPin, 250);
  delay(20);
  analogWrite(ledPin, 240);
  delay(20);
  analogWrite(ledPin, 230);
  delay(20);
  analogWrite(ledPin, 220);
  delay(20);
  analogWrite(ledPin, 210);
  delay(30);
  analogWrite(ledPin, 200);
  delay(30);
  analogWrite(ledPin, 190);
  delay(30);
  analogWrite(ledPin, 180);
  delay(30);
  analogWrite(ledPin, 170);
  delay(20);
  BumpIt();
  analogWrite(ledPin, 160);
  delay(30);
  analogWrite(ledPin, 150);
  delay(40);
  analogWrite(ledPin, 140);
  delay(50);
  BumpIt();
  analogWrite(ledPin, 130);
  delay(55);
  analogWrite(ledPin, 120);
  delay(60);
  analogWrite(ledPin, 110);
  delay(50);
  analogWrite(ledPin, 100);
  delay(50);
  analogWrite(ledPin, 90);
  delay(50);
  BumpIt();
  analogWrite(ledPin, 80);
  delay(50);
  analogWrite(ledPin, 70);
  delay(30);
  analogWrite(ledPin, 60);
  delay(30);
  analogWrite(ledPin, 50);
  delay(30);
  BumpIt();
  analogWrite(ledPin, 40);
  delay(30);
  analogWrite(ledPin, 30);
  delay(30);
  analogWrite(ledPin, 20);
  delay(30);
  BumpIt();
  analogWrite(ledPin, 10);
  delay(30);
  analogWrite(ledPin, 5);
  delay(100);
}