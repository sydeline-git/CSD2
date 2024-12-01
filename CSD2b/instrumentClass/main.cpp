#include <iostream>
#include <string>

class Instrument {
public:
    Instrument();

    std::string sound = "Boink";

    void play();
    void roll(int times);
};

Instrument::Instrument() {
    std::cout << "Instrument - Constructor\n";
}

void Instrument::play() {
    std::cout << sound << std::endl;
}

void Instrument::roll(int times) {
    for (int i = 0; i < times; i++) {
        std::cout << sound << std::endl;
    }
}

int main(){
    Instrument aInstrument;

    aInstrument.play();

    std::cout << "How many times to repeat the sound for?" << std::endl;

    int input;
    std::cin >> input; 

    aInstrument.roll(input);

    return 0;
}