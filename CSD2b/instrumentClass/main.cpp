#include <iostream>
#include <string>
#include "instrument.h"

int main(){
    Instrument aInstrument;

    aInstrument.play();

    std::cout << "How many times to repeat the sound for?" << std::endl;

    int input;
    std::cin >> input; 

    aInstrument.roll(input);

    return 0;
}