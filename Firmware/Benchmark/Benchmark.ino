int mic = 0;
int val = 0;


void setup() {

  Serial.begin(9600);
  pinMode(mic, INPUT);
  pinMode(5, OUTPUT);

}

void loop() {

  val = analogRead(mic);
  analogWrite(5, 200);

  Serial.println(val);


}
