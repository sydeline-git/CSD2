#include <iostream>
#ifndef INSTRUMENT_H
#define INSTRUMENT_H

// #include "key.h"
// #include "perc.h"
// #include "string.h"

class Instrument { 
public:
    Instrument(std::string name);
    ~Instrument();

    void play();

protected:
    std::string name;
    std::string sound;
};

#endif