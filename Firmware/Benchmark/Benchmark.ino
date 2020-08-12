int mic = 0;
int val = 0;

void setup() {

  Serial.begin(9600);
  pinMode(mic, INPUT);
  pinMode(4, OUTPUT);
    pinMode(3, OUTPUT);

}

void loop() {
  
  val = analogRead(mic);
  analogWrite(4, 120);
 delay(1000);
  analogWrite(4, 240);
  delay(1000);
  digitalWrite(3, HIGH);
  Serial.println(val);
  
}
