//Power Sequences

void iHandler() {
  //sei();
 
  buttonHandler++;
  // cli();
}

int BatteryReport() {
  mode--;
  mode--;

  delay(200);
  //battery feedback here
  analogWrite(ledPin, 10);
  delay(2000);
  analogWrite(ledPin, 255);
  delay(100);
  analogWrite(ledPin, 10);
  delay(100);
  analogWrite(ledPin, 255);
  delay(100);
  analogWrite(ledPin, 10);
  delay(100);
  analogWrite(ledPin, 255);
  delay(100);
  analogWrite(ledPin, 0);
  delay(2000);


}

int PowerUp() {
  sleep_disable();
  mode--;
  analogWrite(ledPin, 10);
  delay(70);
  analogWrite(ledPin, 50);
  delay(70);
  analogWrite(ledPin, 100);
  delay(70);
  analogWrite(ledPin, 150);
  delay(70);
  analogWrite(ledPin, 200);
  delay(70);
  analogWrite(ledPin, 255);
  delay(1000);
  powerStatus = 1;
  mode = EEPROM.read(0);
  void setup();
  //PSU pullup
}

int PowerDown() {
  mode--;
  analogWrite(ledPin, 255);
  delay(70);
  analogWrite(ledPin, 200);
  delay(70);
  analogWrite(ledPin, 150);
  delay(70);
  analogWrite(ledPin, 100);
  delay(70);
  analogWrite(ledPin, 50);
  delay(70);
  analogWrite(ledPin, 10);
  EEPROM.write(0, mode);
  delay(1000);
  analogWrite(ledPin, 0);
  powerStatus = 0;
  Sleep();
}

int Sleep() {

  ADCSRA = 0;
  MCUSR = 0;
  WDTCSR = bit (WDCE) | bit (WDE);
  WDTCSR = bit (WDIE) | bit (WDP3) | bit (WDP0);    // set WDIE, and 8 seconds delay
  wdt_reset();
  set_sleep_mode (SLEEP_MODE_PWR_DOWN);
  noInterrupts ();           
  sleep_enable();
  MCUCR = bit (BODS) | bit (BODSE);
  MCUCR = bit (BODS);
  interrupts ();             
  sleep_cpu ();


}
