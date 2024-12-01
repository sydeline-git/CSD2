#include <iostream>
#include <string>

class Instrument {
public:
    Instrument();

    std::string sound = "Boink";

    void play();
    void roll(int times);
};
