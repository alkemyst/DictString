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
  static const DictString emptyDictString;
protected:
  dict_index m_index;
  dict_iterator m_iterator;
public:
  // Static (dictionary) functions
  static size_t dictSize() {
    return dict.size() ;
  }

  // Object functions
  DictString();
  DictString(const char* s);
  DictString(const string& s);
  dict_index index() const {
    return m_index;
  }

  // Assignment operators (more or less)
  DictString& operator= (const char* s);
  DictString& operator= (const std::string& s);

  // Comparison operators <- here's the real gain :-)
  friend bool operator== (const DictString& lhs, const DictString& rhs);
  friend bool operator!= (const DictString& lhs, const DictString& rhs);
  friend bool operator< (const DictString& lhs, const DictString& rhs);
  friend bool operator<= (const DictString& lhs, const DictString& rhs);
  friend bool operator> (const DictString& lhs, const DictString& rhs);
  friend bool operator>= (const DictString& lhs, const DictString& rhs);

  // Sum operators
  friend DictString operator+ (const DictString& lhs, const DictString& rhs);
  friend DictString operator+ (const DictString& lhs, const string& rhs);
  friend DictString operator+ (const DictString& lhs, const char*   rhs);
  friend DictString operator+ (const DictString& lhs, const char    rhs);
  friend DictString operator+ (const string&     lhs, const DictString& rhs);
  friend DictString operator+ (const char*       lhs, const DictString& rhs);
  friend DictString operator+ (char              lhs, const DictString& rhs);

  // Sum and assign
  template<typename T> DictString& operator+= (const T& rhs) {
    (*this) = (*this) + rhs;
  }

  // std::string interface cloning
  const string& str() const {
    return findString(m_iterator);
  }
  size_t length() const {
    return str().length();
  }
  const char* c_str() const {
    return str().c_str();
  }
  DictString substr (size_t pos = 0, size_t len = string::npos) const;

};

#endif /* INCLUDE_DICTSTRING_H */
