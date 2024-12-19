#pragma once

#include <iostream>

#define NUM_NOTES 10

class Melody
{
public:
  Melody();
  ~Melody();

  // setters and getters
  float getNote();
  // float* getMelody(const std::string& melodyName);

protected:
  // // Cmaj7 -  arpeggio
  // float melody[NUM_NOTES] = {60, 64, 67, 71, 64, 67, 64, 69, 60, 55};

  // Dmin7 - arpeggio
  float melody[NUM_NOTES] = {62, 65, 69, 72, 62, 65, 69, 72, 69, 65};

  // the index of the current note - readIndex
  int index = 0;
};
