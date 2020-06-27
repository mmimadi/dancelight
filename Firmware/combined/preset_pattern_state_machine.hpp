class PresetBlinkPattern: public Mode {
  public:
    PresetBlinkPattern::PresetBlinkPattern();
    void loop();
  
  private:
    static const bool LOG_SEEK = false;
    static const bool LOG_EXEC = false;

    static const uint8_t END = 0;
    static const uint8_t START = 1;
    static const uint8_t BLINK = 2;
    static const uint8_t UBLINK = 3;
    static const uint8_t REPEAT = 4;
    static const unsigned short int pattern_data[] PROGMEM;
    
    unsigned short int patterns(unsigned short int i) const {
      return pgm_read_word(&pattern_data[i]);
    }
    
    unsigned int pc;      //Preset Counter
    unsigned int pRepeat; //Repeat Counter
    void resetPreset() {  //Serial.println("reset presets");
      pc = 0;
      pRepeat = 0;
    }
    
    void selectRandomPreset();
};