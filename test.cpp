#include "DictString.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
  // Load the entire english dictionary
  ifstream myFile;
  string myLine;

  myFile.open("/usr/share/dict/american-english");
  int wordCount=0;
  if (myFile.is_open()) {
    while (!myFile.eof()) {
      getline(myFile, myLine);
      DictString* aDictString = new DictString(myLine.c_str());
    }
  }
  myFile.close();
  cout << "Dictionary size is " << DictString::size() << endl;

  DictString ds0, ds1, ds2;
  ds0 = "Hello, world0";
  ds1 = "Hello, world0";
  ds2 = "hello";
  cout << ds0.str() << " : " << ds0.index() << endl;
  cout << ds1.str() << " : " << ds1.index() << endl;
  cout << ds2.str() << " : " << ds2.index() << endl;

  DictString ds3;
  cout << ds3.str() << " : " << ds3.index() << endl;

  return 0;
}
