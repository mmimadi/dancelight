//Power Sequences

void iHandler() {
  sei();
  sleep_disable();
  buttonHandler++;

  cli();
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
  delay(1000);

  if (powerStatus == 0) {
    Sleep();
  }

}

int PowerUp() {
  sleep_disable();
  mode--;

  int intensity = 0;
  while (intensity < 254) {
    intensity ++;
    //intensity ++;
    analogWrite(ledPin, intensity);
    delay(11);
  }
  mode = EEPROM.read(0);
  powerStatus = 1;
  delay(500);

  //PSU pullup
}

int PowerDown() {

  mode--;
  int intensity = 255;
  while (intensity > 1) {
    intensity --;
    //  intensity --;
    analogWrite(ledPin, intensity);
    delay(4);
  }
   analogWrite(ledPin, 0);
   EEPROM.write(0, mode);
  powerStatus = 0;
  delay(500);
  Sleep();

  /*Debug for Production! If the LED stays on, the power supply is faulty and won't turn off
    analogWrite(ledPin, 200);
    delay(500);
    PSU Pull Down
  */

}

//////sleep needs optimization////////////

int Sleep() {
  analogWrite(ledPin, 0);
  // ADCSRA = 0;
  //  MCUSR = 0;
  //WDTCSR = bit (WDCE) | bit (WDE);
  //WDTCSR = bit (WDIE) | bit (WDP3) | bit (WDP0);    // set WDIE, and 8 seconds delay
  // wdt_reset();
  set_sleep_mode (SLEEP_MODE_PWR_DOWN);
  //noInterrupts ();
  sleep_enable();
  //  MCUCR = bit (BODS) | bit (BODSE);
  // MCUCR = bit (BODS);
  interrupts ();
  sleep_cpu ();
  sleep_disable();


}
