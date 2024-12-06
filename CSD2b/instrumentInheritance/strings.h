#include <iostream>
#include "instrument.h"

class Strings : public Instrument {
public:
    Strings(std::string name);
    ~Strings();
};