int pin = 3;
float raw = 0;
float v = 0;

void setup() {

  Serial.begin(57600);
  pinMode(pin, INPUT);
}

void loop() {
  raw = analogRead(pin);
raw = raw * (4.2 / 925.0);
  Serial.println(raw);
  //delay() ;
}
