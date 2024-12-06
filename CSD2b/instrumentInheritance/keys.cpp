#include <iostream>
#include "keys.h"

Keys::Keys(std::string name) : Instrument(name) {
    std::cout << "Keys - Constructor: "
        << name << "\n";

    sound = "ding";
}

Keys::~Keys() {
    std::cout << "Keys - Deconstructor: "
        << name << "\n";
}

