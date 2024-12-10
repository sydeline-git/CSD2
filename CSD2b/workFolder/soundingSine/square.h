#pragma once

#include <iostream>
#include <cmath>

class Square {

public:
    Square(float frequency, float samplerate = 44100);
    ~Square();

    void setSamplerate(float samplerate);

    //return current sample from private sawclass
    float getSample();

    void setFrequency(float frequency);
    float getFrequency();

    //goes to next sample (like clocks ticks to next second)
    void tick(); 


private:
    const float pi = acos (-1); //cos of -1 = pi
    float frequency;
    float amplitude;
    float phase;

    float sample; //current sample
    float samplerate;
};