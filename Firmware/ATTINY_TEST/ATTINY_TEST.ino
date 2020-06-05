int mic = 0;
int val = 0;
float v = 0;

void setup() {

  Serial.begin(9600);
  pinMode(mic, INPUT);
}

void loop() {
  val = analogRead(mic);
v = val * (4.2 / 925.0);
  Serial.println(v);
  //delay() ;
}
