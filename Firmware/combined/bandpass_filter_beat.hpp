class BandpassFilterBeat: public Mode {
  public:
    BandpassFilterBeat();
    void loop();
  
  private:
  	//defines for setting and clearing register bits
  	static const void cbi(char sfr, char bit) { _SFR_BYTE(sfr) &= ~_BV(bit); }
  	static const void sbi(char sfr, char bit) { _SFR_BYTE(sfr) |= _BV(bit); }
    
    const float bassFilter(float sample);
    const float envelopeFilter(float sample);
    const float beatFilter(float sample);
};