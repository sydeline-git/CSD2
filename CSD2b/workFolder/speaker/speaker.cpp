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

class Woofer {
public:
    Woofer(float diam);

    float diameter;
    float conePosition;
};

Woofer::Woofer(float diam) {
    std::cout << "Woofer - Constructor\n";

    diameter = diam;
    conePosition = 0.0f;

}

int main() {
    Speaker aSpeaker;

    Tweeter aTweeter(2.4f);

    Woofer aWoofer(6.0f);

    std::cout << "The diameter of the tweeter is: "
        << aTweeter.diameter << "\n"; 

    std::cout << "The diameter of the woofer is: "
        << aWoofer.diameter << "\n";
}
