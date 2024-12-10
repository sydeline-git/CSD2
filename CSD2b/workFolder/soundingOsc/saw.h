#pragma once
#include "osc.h"

class Saw : public Osc {
public:
    Saw(float frequency = 0, float samplerate = 44100);
    ~Saw();

    void calculate();
};