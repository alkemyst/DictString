#include "DictString.h"
#include <fstream>
#include <iostream>
#include <map>

using namespace std;

void testString(const DictString& ds) {
  cout << "str()=\"" << ds.str() << "\"" << endl;
  cout << "c_str()=\"" << ds.c_str() <<"\"" << endl;
  cout << "length()=" << ds.length() << endl;
  cout << "index=" << ds.index() << endl;
}

int main(int argc, char* argv[]) {
  // Load the entire english dictionary
  ifstream myFile;
  string myLine;
  map<DictString, int> en_dict;

  myFile.open("/usr/share/dict/american-english");
  int wordCount=1; // the empty string is allocated first
  if (myFile.is_open()) {
    while (!myFile.eof()) {
      getline(myFile, myLine);
      DictString* aDictString = new DictString(myLine.c_str());
      en_dict[*aDictString] = wordCount;
      wordCount++;
    }
  }
  myFile.close();
  cout << "Dictionary size is " << DictString::dictSize() << endl;

  DictString ds0, ds1, ds2;
  ds0 = "aString";
  ds1 = "aString";
  ds2 = "hello";
  cout << ds0.str() << " : " << ds0.index() << endl;
  cout << ds1.str() << " : " << ds1.index() << endl;
  cout << ds2.str() << " : " << ds2.index() << endl;
  cout << en_dict[ds2] << endl;
  cout << "Does the map work? ";
  if (en_dict[ds2]==ds2.index()) cout << " yes!";
  else cout << " no!";
  cout << endl;
  ds2 += '0';
  ds2 += "1";
  ds2 += std::string("2");
  ds2 += ds0;
  testString(ds2);

  DictString ds3;
  ds3 = '0' + ds3;
  ds3 = "1" + ds3;
  ds3 = std::string("2") + ds3;
  ds3 = ds3 + ds3;
  testString(ds3);

  DictString ds4 = "012345";
  ds4 = ds4.substr(2);
  testString(ds4);

  return 0;
}
