//Ideally, we'd figure out how to put this in the Power class, and make it so we didn't have to instantiate Power as power. 😕
static byte buttonHandler = 0; //Double Tap Variable Count

class Power {
  public:
    static void setup();
    void buttonLogic();
    uint8_t mode = 1;
    uint8_t powerStatus = 1;
  
  private:
    byte buttonState = 0; //HIGH/LOW
    byte holdCounter = 0;
    byte doubleTapSleep = 0;
    byte doubleTapState = 0;
    float batteryVoltage = 0;
    
    static void iHandler();
    void BatteryReport();
    void BatteryBlink(uint8_t flash, const uint8_t blinkDelay) const;
    void PowerUp();
    void PowerDown();
    static void Sleep();
};