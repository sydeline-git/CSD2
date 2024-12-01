#include <iostream>
#include <string>
#include "instrument.h"


Instrument::Instrument() {
    std::cout << "Instrument - Constructor\n";
}

void Instrument::play() {
    std::cout << sound << std::endl;
}

void Instrument::roll(int times) {
    for (int i = 0; i < times; i++) {
        std::cout << sound << std::endl;
    }
}