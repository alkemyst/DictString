#ifndef INCLUDE_DICTSTRING_H
#define INCLUDE_DICTSTRING_H

#include <ext/pb_ds/assoc_container.hpp>
#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace __gnu_pbds;

class DictString {

private:
  typedef std::string string;
  typedef unsigned int dict_index;
  typedef __gnu_pbds::trie< string, dict_index> dict_container;
  typedef std::vector< string > dict_inverseContainer;
  static dict_container dict;
  static dict_inverseContainer inverseDict;
  dict_index m_index;
  // findIndex for my string
  static dict_index findIndex(const string& str);
  // findString for my index
  static const string& findString(dict_index i);

public:
  string str();
  dict_index index();

  // Assignment operators (more or less)
  DictString& operator= (const char* s);

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
  //  // Operators for DictString
  //  DictString& operator=(const basic_string& str) {
  //    index = findString(str);
  //  }
  //  DictString& operator=(const DictString& str) {
  //    index = str.index;
  //  }

  //  DictString& operator=(CharT ch) {
  //    index =
  //  }
  //  DictString& operator=(std::initializer_list<CharT> ilist) {
  //    index = findString(ilist);
  //  }
  //
};

#endif /* INCLUDE_DICTSTRING_H */
