int mic = 0;

void setup() {
	Serial.begin(115200);
	pinMode(mic, INPUT);
	pinMode(5, OUTPUT);
}

void loop() {
	int val = analogRead(mic);
	analogWrite(5, val);
	Serial.print((char) val);
}