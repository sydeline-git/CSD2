#include <iostream>
#include "strings.h"

Strings::Strings(std::string name) : Instrument(name) {
    std::cout << "Strings - Constructor: "
        << name << "\n";

    sound = "boing";
    type = "string";
    lowestNote = "48";
    highestNote = "84";
}

Strings::~Strings() {
    std::cout << "Strings - Deconstructor: "
        << name << "\n";
}

