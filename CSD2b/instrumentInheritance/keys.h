#include <iostream>
#include "instrument.h"

class Keys : public Instrument {
public:
    Keys(std::string name);
    ~Keys();
};