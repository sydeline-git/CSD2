#include "dog.h"
#include "cat.h"

int main ()
{
  Pet aPet("Peter");
  Cat aCat("Foo");
  Dog aDog("Bar");

  aPet.sleep();
  aCat.sleep();
  aDog.sleep();

  aPet.eat();
  aCat.eat();
  aDog.eat();

  aDog.bark();
  aCat.climb();

  // end program
  return 0;
}
