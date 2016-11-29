#include "DictString.h"
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
  // Load the entire english dictionary
  std::ifstream myFile;
  std::string myLine;

  myFile.open("/usr/share/dict/american-english");
  if (myFile.is_open()) {
    while (!myFile.eof()) {
      getline(myFile, myLine);
      DictString aDictString = myLine.c_str();
    }
  }
  myFile.close();
  std::cerr << "Dictionary size is " << DictString::size() << std::endl;

  std::cerr << "Please type an English word : ";
  std::cin >> myLine;
  DictString aDictString1 = myLine;
  std::cerr << "Word '"<< aDictString1.str()<<"' is word #" << aDictString1.index() << std::endl;
  std::cerr << "Please type another English word : ";
  std::cin >> myLine;
  DictString aDictString2 = myLine;
  std::cerr << "Word '"<< aDictString2.str()<<"' is word #" << aDictString2.index() << std::endl;
  std::cerr << "Dictionary size is now " << DictString::size() << std::endl;

  DictString myString, myString1, myString2;
  myString = "Hello, world";
  myString1 = "Hello, world";
  myString2 = "Hello, world2";

  std::cout << myString.str() << std::endl;
  std::cout << myString1.str() << std::endl;
  std::cout << myString2.str() << std::endl;

  return 0;
}
