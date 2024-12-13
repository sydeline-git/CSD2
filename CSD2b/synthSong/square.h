#pragma once
#include "osc.h"

class Square : public Osc {

public:
    Square(float frequency = 0, float samplerate = 44100);
    ~Square();

    void calculate();
};