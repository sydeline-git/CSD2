#pragma once //only include if not included yet

#include <iostream>
#include <cmath>

class Osc {

public:
  //Constructor and destructor
    Osc(float frequency, float samplerate = 44100);
    ~Osc();
    void setSamplerate(float samplerate);
    //return the current sample
    float getSample();
    // go to next sample
    void tick();

    //getters and setters
    void setFrequency(float frequency);
    float getFrequency();

    virtual void calculate() = 0;

    const float pi = acos (-1);  //acos(-1) = pi (180*)

protected:
    float amplitude;
    float phase;
    float sample;

private:
    float frequency;
    float samplerate;
};

