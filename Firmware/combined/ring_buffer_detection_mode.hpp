class RingBufferThresholdBeat: public Mode {
  public:
    void loop();
  
  private:
    float sampleCounter = 0;
    float micRawValue = 0;
    float processedResult = 0;

    static const int MODE_INSTANT = 0;
    static const int MODE_FADE = 1;
    static const int MODE = MODE_FADE;
    static const bool LOG_LEVELS = false;

    unsigned long next_blink = 0;
    unsigned long next_beat = 0;
    unsigned int loop_iterations = 0;
    static const unsigned int rbdm_silence_threshold = 15;//44; //I changed this to from 15. //15 at ~300. TODO: determine if this scales with battery level.
    static const unsigned int rbdm_min_beat_delay_ms = 100; //10 bps, or detect at most 600bpm.

    unsigned int howBumpingIsIt = 0;
    const unsigned int ITS_TOTALLY_LIT = MODE == MODE_INSTANT ? 2 : 27;
    
    static const unsigned int SAMPLE_LENGTH = 100;
    unsigned int samples[SAMPLE_LENGTH] = {0};
    unsigned int last_sample_index = SAMPLE_LENGTH - 1; //We just filled the array with 0s, so point to the last zero. (Makes initial sample code start from 0 instead of 1, not that it matters.)

    
    void addSample(unsigned int sample);
    unsigned int averageSample() const;
    static int sampleSortCriteria(const void* a, const void* b);
    void findBoundingPercentiles(unsigned int& min, unsigned int& lower, unsigned int& middle, unsigned int& upper, unsigned int& max ) const;
    void ringBufferLoop();
    void writeAndDelay(unsigned int brightness, unsigned int ms);
    void SoundFadeDelayless();
};