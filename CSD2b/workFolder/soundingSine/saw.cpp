#include "saw.h"
#include "math.h"

Saw::Saw(float frequency, float samplerate) : 
    frequency(frequency),
    amplitude(1.0),
    phase(0),
    sample(0),
    samplerate(samplerate) 
{
    std::cout << "Constructor - Saw";
}


Saw::~Saw() 
{
    std::cout << "Deconstructor - Saw";
}

void Saw::setSampleRate(float samplerate) { //updates samplerate variable inside saw class
    this->samplerate = samplerate;
}

float Saw::getSample() {                    //gets private sample variable inside saw class
    return sample;
}

void Saw::setFrequency(float frequency) {   //updates frequency variable inside saw class
    this->frequency = frequency;
}

float Saw::getFrequency() {                 //gets private frequency variable inside saw class
    return frequency;
}

void Saw::tick() {
    phase += frequency/samplerate;

    if (phase >= 1.0f) {
        phase -= 1.0f;
    }

    sample = (2.0f * phase - 1.0f) * amplitude; //1 to -1;
}


