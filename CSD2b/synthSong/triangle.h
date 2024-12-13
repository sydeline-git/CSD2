#pragma once
#include "osc.h"

class Triangle : public Osc {

public:
    Triangle(float frequency = 0, float samplerate = 44100);
    ~Triangle();

    void calculate();
};