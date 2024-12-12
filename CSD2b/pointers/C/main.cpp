#include <iostream>
#include <string>

class Simple {
public:
    Simple();
    ~Simple();

    std::string getName();
    void setName(std::string newName);

private:
    std::string name = "jeff";
};

Simple::Simple() {
    std::cout << "Constructor \n";
}

Simple::~Simple() {
    std::cout << "Deconstructor \n";
}

std::string Simple::getName() {
    return name;
}

void Simple::setName(std::string newName) {
    name = newName;
}

int main() {
    Simple obj1;
    Simple obj2;
    Simple obj3;

    std::cout << obj1.getName() << "\n";

    obj1.setName("dick");

    std::cout << obj1.getName() << "\n";

    Simple* pointerObj1 = &obj1;    

    std::cout << pointerObj1->getName() << "\n";

    pointerObj1->setName("jeff");
    
    std::cout << pointerObj1->getName() << "\n";



    Simple* array[50];  //array of 50 pointers

    Simple objects[50]; //dont know if this is the right way to do it but it works

    for (int i = 0; i < 50; i++) {
        array[i] = &objects[i];
        array[i]->setName("jeff" + std::to_string(i));
    }

    for (int i = 0; i < 50; i++) {
        std::cout << array[i]->getName() << "\n";
    }

    return 0;
}