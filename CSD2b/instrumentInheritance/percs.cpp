#include <iostream>
#include "percs.h"

Percs::Percs(std::string name) : Instrument(name) {
    std::cout << "Percs - Constructor: "
        << name << "\n";

    sound = "doof";
}

Percs::~Percs() {
    std::cout << "Percs - Deconstructor: "
        << name << "\n";
}

