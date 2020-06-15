int mic = 0;
int val = 0;


void setup() {

  Serial.begin(9600);
  pinMode(mic, INPUT);
 
}

void loop() {
  val = analogRead(mic);
  

  Serial.println(val);
  

}
