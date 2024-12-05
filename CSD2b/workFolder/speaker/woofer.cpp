#include <iostream>
#include "woofer.h"

Woofer::Woofer(float diam) {
    std::cout << "Woofer - Constructor\n";

    diameter = diam;
    conePosition = 0.0f;
}