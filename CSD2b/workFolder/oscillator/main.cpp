#include <iostream>
#include "oscillator.h"

int main() {
    std::cout << "Running main" << std::endl;

    Oscillator Osc;

    std::cout << "Frequency: " << Osc.getFreq() << " & Amplitude: " << Osc.getAmp() << std::endl;

    Osc.setFreq(420);
    Osc.setAmp(100);

    std::cout << "Frequency: " << Osc.getFreq() << " & Amplitude: " << Osc.getAmp() << std::endl;

    return 0;
}