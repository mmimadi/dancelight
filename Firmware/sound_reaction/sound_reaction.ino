const int mic = 0; //pin 0
const int led = 5; //pin 5
int pwm = 0;
float micRaw = 0; //raw
float valc = 0;
int samplec = 0; //sample counter
float  LEDout = 0; //processed value for led
int percent = 0;

void setup()

{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
micRaw = analogRead(mic);
}

void loop()
{

  while (samplec < 100) {

    
   // micRaw = (micRaw - 522);
    valc = valc + micRaw;
    samplec++;
    Serial.println(micRaw);
    delay(100);
  }

//LEDout = (valc / 100);
//percent = (LEDout * 1) + percent;


Serial.println(percent);
micRaw = analogRead(mic);
if (micRaw > 4) {
  analogWrite(led, 255);
  delay(15);

} else {
  analogWrite(led, 20);
}

}
