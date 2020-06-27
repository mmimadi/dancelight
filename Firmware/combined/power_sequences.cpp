#include "common.hpp"
#include "combined.hpp"
#include "power_sequences.hpp"

float batteryVoltage = 0;

int BatteryReport() {
  mode--;
  mode--;
  analogWrite(ledPin, 0),
              delay(1000);
  batteryVoltage = analogRead(batteryPin);
  batteryVoltage = batteryVoltage * (4.2 / 925.0);
  Serial.println(batteryVoltage);

  if (batteryVoltage > 3.9) {
    Serial.println("100%");
    BatteryBlink(4, 200);

  } else if (batteryVoltage < 3.89 && batteryVoltage > 3.7) {
    Serial.println("75%");
    BatteryBlink(3, 200);

  } else if (batteryVoltage < 3.69 && batteryVoltage > 3.4) {
    Serial.println("50%");
    BatteryBlink(2, 200);

  } else if (batteryVoltage < 3.39 && batteryVoltage > 3.01) {
    Serial.println("25%");
    BatteryBlink(1, 200);

  } else if (batteryVoltage < 3.00) {
    Serial.println("Charge Now");
    BatteryBlink(8, 50);
  }

  if (powerStatus == 0) {
    Sleep();
  }
}

int BatteryBlink(uint8_t flash, const uint8_t blinkDelay) {
  while(flash--) {
    analogWrite(ledPin, 255);
    delay(blinkDelay);
    analogWrite(ledPin, 0);
    delay(blinkDelay);
  }
  delay(1500);
}

int PowerUp() {
  sleep_disable();
  powerStatus = 1;
  mode--;
  byte intensity = 0;
  while (intensity < 254) {
    intensity ++;
    //intensity ++;
    analogWrite(ledPin, intensity);
    delay(11);
  }

  mode = EEPROM.read(0);
  
  delay(500);
  //PSU pullup
}

int PowerDown() {
    powerStatus = 0;
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

  delay(500);
  Sleep();
  /*Debug for Production! If the LED stays on, the power supply is faulty and won't turn off
    analogWrite(ledPin, 200);
    delay(500);
    PSU Pull Down
  */
}

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
