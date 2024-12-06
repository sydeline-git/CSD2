#include <iostream>
#include "instrument.h"

Instrument::Instrument(std::string name) {
    std::cout << "Instrument - Constructor: "
        << name << "\n";
    this-> name = name;
}

Instrument::~Instrument() {
    std::cout << "Instrument - Deconstructor: "
        << name << "\n";
}


void Instrument::play() {
    std::cout << name << " makes the sound " << sound << "\n";
}
