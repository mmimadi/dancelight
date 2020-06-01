int mic = 0;
int val = 0;
int led = 5;

void setup() {

  Serial.begin(9600);
  pinMode(mic, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  val = analogRead(mic);
  analogWrite(led, 100);

  Serial.println(val);
  
  //delay() ;
}
