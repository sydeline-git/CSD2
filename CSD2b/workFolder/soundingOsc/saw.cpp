#include "saw.h"
#include "math.h"

Saw::Saw(float frequency, float samplerate) : Osc (frequency, samplerate)
{
    std::cout << "Saw - Constructor";
}


Saw::~Saw() 
{
    std::cout << "Saw - Deconstructor";
}

void Saw::calculate() {
    sample = (2.0f * phase - 1.0f) * amplitude; //1 to -1;
}
