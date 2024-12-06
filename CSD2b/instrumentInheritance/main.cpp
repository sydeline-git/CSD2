#include <iostream>
#include "strings.h"
#include "percs.h"
#include "keys.h"

int main() { 
    Strings string1("Violin");
    Percs perc1("Bongo");
    Keys key1("Piano");

    string1.play();
    perc1.play();
    key1.play();

    return 0;
}