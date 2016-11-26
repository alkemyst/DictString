#include "DictString.h"
#include <fstream>
#include <iostream>

#include <chrono>

void report_duration_us(const std::chrono::high_resolution_clock::time_point& t0,
                        const std::chrono::high_resolution_clock::time_point& t1) {
  using namespace std::chrono;
  auto duration = duration_cast<microseconds>(t1-t0).count();
  std::cout << "Duration was " << duration << " us" << std::endl;
}

int main() {
  // Load the entire english dictionary
  std::ifstream myFile("/usr/share/dict/american-english");
  std::string myLine;
  if (myFile.is_open()) {
    while (!myFile.eof()) {
      getline(myFile, myLine);
      DictString aDictString = myLine.c_str();
      // std::cout << aDictString.str() << std::endl;
    }
  }
  std::cout << "Dictionary size is " << DictString::size() << std::endl;
  std::cout << "Please type an English word : ";
  std::cin >> myLine;
  DictString aDictString1 = myLine;
  std::cout << "Please type another English word : ";
  std::cin >> myLine;
  DictString aDictString2 = myLine;
  std::cout << "Dictionary size is now " << DictString::size() << std::endl;

  // Let's do some performance test
  {
    long nLoops = 1e8;
    using namespace std::chrono;
    std::string aString1 = "firstString";
    std::string aString2 = "secondString";
    aDictString1 = aString1;
    aDictString2 = aString2;
    high_resolution_clock::time_point t0, t1;
    std::cout << "Empty loop: ";
    t0 = high_resolution_clock::now();
    for (int i=0; i<nLoops; ++i);
    t1 = high_resolution_clock::now();
    report_duration_us(t0, t1);

    std::cout << "DictString comparison loop: ";
    t0 = high_resolution_clock::now();
    for (int i=0; i<nLoops; ++i) {
      if (aDictString1==aDictString2) {
        std::cerr << "The two strings are identical" << std::endl;
      }
    }
    t1 = high_resolution_clock::now();
    report_duration_us(t0, t1);

    std::cout << "string comparison loop: ";
    t0 = high_resolution_clock::now();
    for (int i=0; i<nLoops; ++i) {
      if (aString1==aString2) {
        std::cerr << "The two strings are identical" << std::endl;
      }
    }
    t1 = high_resolution_clock::now();
    report_duration_us(t0, t1);

    std::cout << "integer comparison loop: ";
    int n1=45;
    int n2=33;
    t0 = high_resolution_clock::now();
    for (int i=0; i<nLoops; ++i) {
      if (n1==n2) {
        std::cerr << "The two numbers are identical" << std::endl;
      }
    }
    t1 = high_resolution_clock::now();
    report_duration_us(t0, t1);

    // results using iterator comparison
    // Dictionary size is now 99174
    // Empty loop: Duration was 235499 us
    // DictString comparison loop: Duration was 583130 us
    // string comparison loop: Duration was 649295 us
    // integer comparison loop: Duration was 234547 us

  }

  return 0;

  /*
    DictString myString, myString1, myString2;
    myString = "Hello, world";
    myString1 = "Hello, world";
    myString2 = "Hello, world2";

    std::cout << myString.str() << std::endl;

    std::cout << myString1.str() << std::endl;

    std::cout << myString2.str() << std::endl;
  */

}
