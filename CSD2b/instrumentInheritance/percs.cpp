#include <iostream>
#include "percs.h"

Percs::Percs(std::string name) : Instrument(name) {
    std::cout << "Percs - Constructor: "
        << name << "\n";

    sound = "doof";
    type = "perc";
    lowestNote = "60";
    highestNote = "61";
}

Percs::~Percs() {
    std::cout << "Percs - Deconstructor: "
        << name << "\n";
}

