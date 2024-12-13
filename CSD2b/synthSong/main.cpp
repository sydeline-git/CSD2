#include <iostream>
#include "customCallback.h"
// #include "input.cpp"

float askFreq() {
    float freq;
    std::cout << "What frequency would you like?";
    std::cin >> freq;

    return freq;
}

int main() {
    ScopedMessageThreadEnabler scopedMessageThreadEnabler;
    CustomCallback audioSource (44100);
    JUCEModule juceModule (audioSource);
    juceModule.init(1,1);

    std::cout << "Press q + Enter to quit..." << std::endl;
    bool running = true;
    while (running) {
        audioSource.setFrequency(askFreq());
        switch (std::cin.get()) {
            case 'q':
                running = false;
                break;
        }
    }

    return 0;
}
