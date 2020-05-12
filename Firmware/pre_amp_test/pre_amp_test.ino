int mic = 0;
int val = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(mic, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(mic);
  Serial.println(val);
}
