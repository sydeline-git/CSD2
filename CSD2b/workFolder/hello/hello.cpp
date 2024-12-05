#include <iostream>
#include <string>

int main () {
    std::cout << "Hello, what is your name?" << std::endl;

    std::string yourName;
    std::cin >> yourName;

    std::cout << "Hi " << yourName << std::endl;

    std::cout << "How old are you?" << std::endl;

    std::string yourAge;
    std::cin >> yourAge;

    std::cout << "Thanks " << yourName << " for telling me your age of " << yourAge << std::endl;
}

