#include "sine.h"
#include "math.h"

#ifndef M_PI        //ERROR if i dont 
    #define M_PI 3.14159265358979323846
#endif

Sine::Sine(float frequency) {
  // initialize members
  this->frequency = frequency;
  std::cout << "Sine - constructor\n";
}

Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}

float Sine::getSample() {
  return sample;
}

void Sine::tick() {
  // NOTE
  // • frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / SAMPLERATE;
  sample = sin(M_PI * 2 * phase);
  // float quadruplePhase = phase*4;

  // if (phase <= 0.25) 
  // {
  //   sample = (quadruplePhase * 1.0f); //   /
  // } 

  // else if ((phase > 0.25) && (phase <= 0.75)) //   
  // {
  //   sample = (quadruplePhase * -1.0f + 2);
  // }

  // else if ((phase > 0.75) && (phase <= 1)) 
  // {
  //   sample = (quadruplePhase * 1.0f -  4);
  // }
  

}

//getters and setters
void Sine::setFrequency(float frequency)
{
  // TODO
  // • add check to see if parameter is valid
  this->frequency = frequency;
}

float Sine::getFrequency()
{
  return frequency;
}
