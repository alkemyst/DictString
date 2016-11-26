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
  typedef size_t dict_index;
  typedef __gnu_pbds::trie< string, dict_index> dict_container;
  typedef dict_container::iterator dict_iterator;
  static dict_container dict;
  // findIndex for my string
  static const dict_iterator& findIterator(const string&);
  // findString for my index
  static const string& findString(const dict_iterator& i);
protected:
  dict_index m_index;
  dict_iterator m_iterator;
public:
  DictString() {};
  DictString(const char* s);
  DictString(const string& s);
  string str();
  const dict_index& index();
  static size_t size() { return dict.size() ;}

  // Assignment operators (more or less)
  DictString& operator= (const char* s);
  DictString& operator= (const std::string& s);

  // Comparison operators <- here's the real gain :-)
  friend bool operator==(const DictString& lhs, const DictString& rhs);
  friend bool operator!=(const DictString& lhs, const DictString& rhs);
};

#endif /* INCLUDE_DICTSTRING_H */
