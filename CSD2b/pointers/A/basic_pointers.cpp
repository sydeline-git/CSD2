#include <iostream>

/*
  Assignment: complete this program by putting your code in all the locations
    that say -- your code here --

  Make sure that the program compiles and builds and check the output
    after every change.

  Tip: before you look at the output, always think ahead what you expect to
    see and then check if your assumption was correct.
 */

int main()
{
char letter = 97; // find this in the ASCII table (type 'man ascii') 0x61 of a
char *letterpointer;

  std::cout << "Contents of the variable letter: "
    << letter << "\n";

  letterpointer = &letter;
  std::cout << "Contents of letterpointer: "
    << letterpointer << "\n";

  std::cout << "Contents of what letterpointer points to: "
    << *letterpointer << "\n";

  *letterpointer = 'b';
  std::cout << "The variabele letter has gotten a new value through letterpointer.";
  std::cout << "Contents of what letterpointer points to: "
    << letterpointer << "\n";

  std::cout << "Contents of the variable letter: "
    << letter << "\n";


  /*
   * Create the necessary pointer(s) and use them
   */

  unsigned short *yearpointer;

  unsigned short year = 2019;
  std::cout << "Contents of the variabele year: "
     << year << "\n";
  
  // create a pointer to year
    yearpointer = &year;

  std::cout << "Contents of yearpointer: "
    << yearpointer << "\n";    //2019

  std::cout << "Contents of what yearpointer points to: "
    << *yearpointer << "\n";       //adress

  // give year a new value via yearpointer
  *yearpointer = 2020;      //adress

  std::cout << "Contents of the variabele year: "
    << year << "\n";        //2020


  // create another pointer to year, named anotheryearpointer
  unsigned short *anotheryearpointer;
  anotheryearpointer = &year;

  std::cout << "Contents of anotheryearpointer: "
    << anotheryearpointer << "\n";  //2020

  std::cout << "Contents of what anotheryearpointer points to: "
    << *anotheryearpointer << "\n";                // another adress

  // give year a new value via anotheryearpointer
  *anotheryearpointer = 2021;

  std::cout << "Contents of year: "
    << year << "\n"; //2021

  std::cout << "Contents of what anotheryearpointer points to: "
    << *anotheryearpointer << "\n";   //adress

  anotheryearpointer++;

  std::cout << "Contents of anotheryearpointer after ++: "
    << anotheryearpointer << "\n"; //2022
} // main()

