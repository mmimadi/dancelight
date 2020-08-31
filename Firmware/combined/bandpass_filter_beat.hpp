class BandpassFilterBeat: public Mode {
  public:
    BandpassFilterBeat();
    void loop();
  
  private:
    static const int MODE_INSTANT = 0;
    static const int MODE_FADE = 1;
    static const int MODE;
    unsigned long next_blink = 0;

    //defines for setting and clearing register bits
    static const void cbi(char sfr, char bit) { _SFR_BYTE(sfr) &= ~_BV(bit); }
    static const void sbi(char sfr, char bit) { _SFR_BYTE(sfr) |= _BV(bit); }
    
    const float bassFilter(float sample);
    const float envelopeFilter(float sample);
    const float beatFilter(float sample);

    //light fade
    uint8_t howBumpingIsIt = 0;
    const uint8_t ITS_TOTALLY_LIT = MODE == MODE_INSTANT ? 2 : 27;

    void writeAndDelay(unsigned int brightness, unsigned int ms);
    void SoundFadeDelayless();
};