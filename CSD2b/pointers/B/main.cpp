#include <iostream>

//a by value
//b by a pointer
//c by reference

void by_value(int value) {
    std::cout << value << " given to function (value) \n";          //maakt kopie
    value = value + 1;                                              //past waarde aan binnen functie niet erbuiten
    std::cout << value << "\n";
}   

void by_pointer(int* pValue) {
    std::cout << *pValue << " given to function (pointer) \n";      //wijst naar inhoud adress ofwel number
    *pValue = *pValue + 1;                                          //past originele number aan
    std::cout << *pValue << "\n";                                   
}

void by_reference(int& rValue) {
    std::cout << rValue << " given to function (reference) \n";     //hetzelfde als number met andere naam
    rValue = rValue + 1;
    std::cout << rValue << "\n";
}   


int main() {
    int number = 1;

    //A value
    by_value(number);

    //B pointer
    by_pointer(&number);    //geeft adress

    //C reference
    by_reference(number);   //geeft value
};