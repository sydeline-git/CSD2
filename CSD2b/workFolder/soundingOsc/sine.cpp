#include "sine.h"
#include "math.h"

Sine::Sine(float frequency, float samplerate) : Osc (frequency, samplerate)
{
    std::cout << "Sine - Constructor\n";
}

Sine::~Sine() {
    std::cout << "Sine - Deconstructor\n";
}

void Sine::calculate() {
    sample = sin(pi * 2 * phase) * amplitude;
}