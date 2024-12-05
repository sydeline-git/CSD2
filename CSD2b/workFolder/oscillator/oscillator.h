#include <iostream>

class Oscillator {
public:
    Oscillator();                   //construtor default
    Oscillator(float frequency, int amplitude);    //changeable freq
    ~Oscillator();                  //destructor

    void setFreq(float freq);       //setter of freq
    float getFreq();                //getter of freq

    void setAmp(int amp);           //setter of amp
    int getAmp();                //getter of amp
    
private:
    float freq;
    int amp;
};