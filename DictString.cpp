#include "DictString.h"

typedef DictString ds;

ds::dict_container ds::dict;
ds::dict_inverseContainer ds::inverseDict;

ds::dict_index ds::findIndex(const string& str) {
  auto myWord = dict.find(str);
  if (myWord != dict.end()) return myWord->second;
  dict_index result = inverseDict.size();
  dict.insert(std::make_pair(str, result));
  inverseDict.push_back(str);
  return result;
}
// findString for my index
const ds::string& ds::findString(dict_index i) {
  return inverseDict.at(i);
}

ds::string ds::str() {
  return findString(m_index);
}

ds::dict_index ds::index() {
  return m_index;
}

// Assignment operators (more or less)
ds& ds::operator= (const char* s) {
  m_index = findIndex(string(s));
}


// int findString(const CharT* s) {
//   std::string str = std::string(s);
//   return dictionary[s];
// }
//  int findString(CharT ch) {
//    std::string str = std::string(s);
//    return dictionary[s];
//  }


//  template <typename T> int findString(const T s) {
//    std::string str = std::string(s);
//    return dictionary[str];
//  }
//  template <typename T> int findString(const T& s) {
//    std::string str = std::string(s);
//    return dictionary[str];
//  }
//
//  // Operators for ds
//  ds& operator=(const basic_string& str) {
//    index = findString(str);
//  }
//  ds& operator=(const ds& str) {
//    index = str.index;
//  }

//  ds& operator=(CharT ch) {
//    index =
//  }
//  ds& operator=(std::initializer_list<CharT> ilist) {
//    index = findString(ilist);
//  }
//
