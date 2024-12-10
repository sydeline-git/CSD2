#include "osc.h"
#include "math.h"

Osc::Osc(float frequency, float samplerate) : frequency(frequency),
    amplitude(1.0), phase(0), sample(0), samplerate(samplerate)
{
    std::cout << "Osc - constructor\n";
}

Osc::~Osc() {
    std::cout << "Osc - destructor\n";
}

void Osc::setSamplerate(float samplerate) {
    this->samplerate =samplerate;
}

float Osc::getSample() {
    return sample;
}

void Osc::tick() {
    phase += frequency / samplerate;
    if(phase > 1.0f) {
        phase -= 1.0f;
    }

    calculate();
}

//getters and setters
void Osc::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
    this->frequency = frequency;
}

float Osc::getFrequency()
{
    return frequency;
}
