#include <iostream>
#include "tweeter.h"

Tweeter::Tweeter(float diam) {
    std::cout << "Tweeter - constructor\n";

    diameter = diam;
    conePosition = 0.0f;  // Number with an f -> indicate its a float
}

