#include "square.h"
#include "math.h"

Square::Square(float frequency, float samplerate) : Osc(frequency, samplerate)
{
    std::cout << "Square - Constructor\n";
}


Square::~Square() {
    std::cout << "Square - Deconstructor\n";
}


void Square::calculate() {
      //phase 0 -> 0.5, sample = 1    phase 0.5 -> 1.0, sample = -1
    if (phase <= 0.5) {
      sample = 1.0;
    } else if (phase > 0.5) {
      sample = -1.0;
    }
}
