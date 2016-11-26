#include "DictString.h"

int main() {
  DictString myString, myString1, myString2;
  myString = "Hello, world";
  myString1 = "Hello, world";
  myString2 = "Hello, world2";

  std::cout << myString.str() << std::endl;
  std::cout << myString.index() << std::endl;

  std::cout << myString1.str() << std::endl;
  std::cout << myString1.index() << std::endl;

  std::cout << myString2.str() << std::endl;
  std::cout << myString2.index() << std::endl;
}
