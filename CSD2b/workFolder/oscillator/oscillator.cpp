#include <iostream>
#include "oscillator.h"

Oscillator::Oscillator() : Oscillator(220, 0) {                    //constructor
    std::cout << "Oscillator - Constructor \n";

}

Oscillator::Oscillator(float frequency, int amplitude) : freq(frequency), amp(amplitude) {     //initializer list
    std::cout << "Oscillator - Constructor (frequency) \n";
}


Oscillator::~Oscillator() {                                     //destructor
    std::cout << "Oscillator - Destructor \n";

}

void Oscillator::setFreq(float freq) {                          //setter
    this->freq = freq;
}

float Oscillator::getFreq() {                                   //getter
    return freq;    
}

void Oscillator::setAmp(int amp) {
    this->amp = amp;
}

int Oscillator::getAmp() {
    return amp;
}