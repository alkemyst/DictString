#include "DictString.h"

typedef DictString DS;

DS::dict_container DS::dict;

const DS::dict_index& DS::findIndex(const string& str) {
  const auto& myWord = dict.find(str);
  if (myWord != dict.end()) return myWord;
  // New word in dictionary
  auto newEntry = std::make_pair(str, nullptr);
  const DS::dict_index& insertedIterator = dict.insert(newEntry).first;
  return insertedIterator;
}

// findString for my index
const DS::string& DS::findString(const dict_index& i) {
  return i->first;
}

DS::string DS::str() {
  return findString(m_index);
}

const DS::dict_index& DS::index() {
  return m_index;
}

// Assignment and constructor operators with char*
DS::DictString(const char* s) {
  m_index = findIndex(string(s));
}
DS& DS::operator= (const char* s) {
  m_index = findIndex(string(s));
}

// Assignment and constructor operators with std::string
DS::DictString(const std::string& s) {
  m_index = findIndex(s);
}
DS& DS::operator= (const std::string& s) {
  m_index = findIndex(s);
}

bool operator==(const DictString& lhs, const DictString& rhs) {
  return lhs.m_index == rhs.m_index;
}

bool operator!=(const DictString& lhs, const DictString& rhs) {
  return lhs.m_index != rhs.m_index;
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
//  // Operators for DS
//  DS& operator=(const basic_string& str) {
//    index = findString(str);
//  }
//  DS& operator=(const DS& str) {
//    index = str.index;
//  }

//  DS& operator=(CharT ch) {
//    index =
//  }
//  DS& operator=(std::initializer_list<CharT> ilist) {
//    index = findString(ilist);
//  }
//
