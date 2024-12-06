#include <iostream>
#include "strings.h"

Strings::Strings(std::string name) : Instrument(name) {
    std::cout << "Strings - Constructor: "
        << name << "\n";

    sound = "boing";
}

Strings::~Strings() {
    std::cout << "Strings - Deconstructor: "
        << name << "\n";
}

