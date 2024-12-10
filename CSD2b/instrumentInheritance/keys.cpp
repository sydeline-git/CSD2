#include <iostream>
#include "keys.h"

Keys::Keys(std::string name) : Instrument(name) {
    std::cout << "Keys - Constructor: "
        << name << "\n";

    sound = "ploing";
    type = "key";
    lowestNote = "0";
    highestNote = "127";
}

Keys::~Keys() {
    std::cout << "Keys - Deconstructor: "
        << name << "\n";
}

