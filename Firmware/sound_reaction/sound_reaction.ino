const int mic = 0; //pin 0
const int led = 5; //pin 5
int pwm = 0;
int micRaw = 0; //raw
int valc = 0;
int samplec = 0; //sample counter
float  LEDout = 0; //processed value for led

void setup()
If
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);

}

void loop()
{

  while (samplec < 1000) {

    micRaw = analogRead(mic);
    //micRaw = (micRaw - 522);
   // valc = valc + micRaw;
    samplec++;
    Serial.println(micRaw);
    delay(100);
  }

LEDout = valc/100;

//Serial.println("value");
Serial.println(LEDout);

//Serial.println("RAW");
//Serial.println(micRaw);

  //Serial.print(out);
}
