

#include "triangle.h"
#include "math.h"

Triangle::Triangle(float frequency, float samplerate) : Osc(frequency, samplerate)
{
    std::cout << "Triangle - Constructor\n";
}


Triangle::~Triangle() {
    std::cout << "Triangle - Deconstructor\n";
}


void Triangle::calculate() {
    float quadruplePhase = phase*4; //devide in 4 partitions

    //not the most efficient way but it works

    //from 0 to 1 from phase 0.0 to 0.25
    if (phase < 0.25) 
    {
        sample = (quadruplePhase * 1.0f);   
    } 

    //from 1 to -1 from phase 0.25 to phase 0.75
    else if ((phase >= 0.25) && (phase < 0.75)) //   
    {
        sample = (quadruplePhase * -1.0f + 2);
    }

    //from -1 to 0 from phase 0.75 to phase 1
    else if ((phase >= 0.75) && (phase < 1)) 
    {
        sample = (quadruplePhase * 1.0f -  4);
    }
  
}


