#pragma once //only include if not included yet

#include "osc.h"

class Sine : public Osc
{
public:
    //Constructor and destructor
    Sine(float frequency = 0, float samplerate = 44100);
    ~Sine();
    
    void calculate();
};

