//#include <EEPROM.h>
#include <avr/sleep.h>
//#include <avr/wdt.h> //Watchdog timer handling is not used right now.

uint8_t ENBL = 3;
static byte buttonHandler = 0; //Double Tap Variable Counter

byte buttonState = 1; //i think this is the button pin
byte holdCounter = 0;
byte doubleTapSleep = 0;
byte doubleTapState = 0;
float batteryVoltage = 0;

static void power_setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(button, iHandler, FALLING);
  pinMode(button, INPUT);
  pinMode(batteryPin, INPUT);
  pinMode(ENBL, OUTPUT);
}

static void iHandler() {
  sei();
  sleep_disable();
  digitalWrite(ENBL, HIGH);
  buttonHandler++;
  cli();
}

void buttonLogic() {
  buttonState = 0;
  doubleTapSleep = 0;
  doubleTapState = 0;
  holdCounter = 0;

  while (buttonHandler >= 1 && holdCounter < 250) {  //!!!should be ==, >= is for crappy (temporary) debounce!!!
    doubleTapState = 1;
    buttonState = digitalRead(button);

    if (buttonState == HIGH) { //Exit on button release
      buttonHandler = 0;
      mode++;
    }
    if (holdCounter > 248 && powerStatus == 0) {
      holdCounter = 0;
      PowerUp();
    }
    if (holdCounter > 248 && powerStatus == 1) {
      holdCounter = 0;
      PowerDown();
    }
    holdCounter++;
    delay(7);
  }

  while (doubleTapState == 1) {
    buttonState = digitalRead(button);
    if (buttonState == HIGH) {
      buttonHandler = 0;
    }
    doubleTapSleep++;
    delay(5);
    if (buttonState == LOW) {
      doubleTapState = 2;
      BatteryReport();
    }
    if (doubleTapSleep > 30) { //sleep timeout
      doubleTapState = 0;
    }
    if (powerStatus == 0 && doubleTapSleep > 30) { //idle light
      
      uint8_t wait = 0;
      while (wait <= 100) {
        //Serial.println(wait);
        delay(25);
        buttonState = digitalRead(button);
        if (buttonState == LOW) {
          buttonHandler++;
          buttonLogic();
        }
        analogWrite(ledPin, 10);
        wait++;
      }
      if (powerStatus == 0) {
        doubleTapState = 0;
        Sleep();
      }
    }
  }
}


void BatteryReport() {
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

void BatteryBlink(uint8_t flash, const uint8_t blinkDelay) {
  while(flash--) {
    analogWrite(ledPin, 255);
    delay(blinkDelay);
    analogWrite(ledPin, 0);
    delay(blinkDelay);
  }
  delay(1500);
}

void PowerUp() {
  digitalWrite(ENBL, HIGH);
  sleep_disable();
  powerStatus = 1;
  mode--;
  uint8_t intensity = 0;
  while (intensity < 254) {
    intensity ++;
    analogWrite(ledPin, intensity);
    delay(11);
  }

  //mode = EEPROM.read(0);
  
  delay(500);
  //PSU pullup
}

void PowerDown() {
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
//  EEPROM.write(0, mode);
  delay(500);
  Sleep();
  /*Debug for Production! If the LED stays on, the power supply is faulty and won't turn off
    analogWrite(ledPin, 200);
    delay(500);
   digitalWrite(ENBL, LOW)
  */
}

static void Sleep() {
 buttonHandler --;
  analogWrite(ledPin, 0);
  digitalWrite(ENBL, LOW);
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
 // interrupts ();
 // sleep_cpu ();
 // sleep_disable();
  
}
