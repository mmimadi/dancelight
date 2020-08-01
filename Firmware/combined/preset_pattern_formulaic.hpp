class PresetBlinkPattern: public Mode {
  public:
    PresetBlinkPattern::PresetBlinkPattern();
    void loop();
  
  private:
    static const double pi = 2*acos(0);
    static const double phaseMS = 6000;

    static float PresetBlinkPattern::weird_waves(float x);
    static float PresetBlinkPattern::buzz_pulse(float x);
    static float PresetBlinkPattern::wiggle_waggle(float x);
    static float PresetBlinkPattern::square(float x);
    static float PresetBlinkPattern::sawtooth(float x);
    static float PresetBlinkPattern::grand_canyon(float x);
    static float PresetBlinkPattern::fuzzy_waves(float x);
    
    float(*c)(float x) = nullptr; //current function
    float(*n)(float x) = nullptr; //next function
    float t = 0;                  //time
    unsigned long d = 0;          //duration (t+millis)
    float f = 0;                  //factor of fade
    
    typedef float (*Func)(float a);
    Func randWave(Func prev);
};