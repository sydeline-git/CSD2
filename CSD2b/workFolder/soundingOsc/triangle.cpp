

#include "triangle.h"
#include "math.h"

Triangle::Triangle(float frequency, float samplerate) : Osc(frequency, samplerate)
{
    std::cout << "Square - Constructor\n";
}


Triangle::~Triangle() {
    std::cout << "Square - Deconstructor\n";
}


void Triangle::calculate() {
    float quadruplePhase = phase*4;

    if (phase <= 0.25) 
    {
        sample = (quadruplePhase * 1.0f); //   /
    } 

    else if ((phase > 0.25) && (phase <= 0.75)) //   
    {
        sample = (quadruplePhase * -1.0f + 2);
    }

    else if ((phase > 0.75) && (phase <= 1)) 
    {
        sample = (quadruplePhase * 1.0f -  4);
    }
  
}


