int mic = 0;
int val = 0;
int p = 0;

void setup() {

  Serial.begin(9600);
  pinMode(mic, INPUT);
}

void loop() {
  val = analogRead(mic);
  p = val;
  
 if ((val >= 100) && (val <= 100)) {
  p = 60;
 }

  Serial.println(p);
  //delay() ;
}
