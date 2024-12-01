#include <iostream>

class Speaker {
public:
    Speaker();


};

Speaker::Speaker() {
    std::cout << "Speaker - constructor\n";
}

class Tweeter {
public:
    // constructor
    Tweeter(float diam);
    
    float diameter;
    float conePosition;  
};

Tweeter::Tweeter(float diam) {
    std::cout << "Tweeter - constructor\n";

    diameter = diam;
    conePosition = 0.0f;  // Number with an f -> indicate its a float
}

int main() {
    Tweeter aTweeter(2.4f);

    std::cout << "The diameter of the tweeter is: "
        << aTweeter.diameter << "\n"; 
}
