#include <iostream>
#include "woofer.h"
#include "speaker.h"
#include "tweeter.h"

int main() {
    Speaker aSpeaker;

    Tweeter aTweeter(2.4f);

    Woofer aWoofer(6.0f);

    std::cout << "The diameter of the tweeter is: "
        << aTweeter.diameter << "\n"; 

    std::cout << "The diameter of the woofer is: "
        << aWoofer.diameter << "\n";
}
