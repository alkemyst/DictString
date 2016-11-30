#include "DictString.h"

typedef DictString DS;

DS::dict_container DS::dict;
const DictString DS::emptyDictString("");

const DS::dict_iterator& DS::findIterator(const string& str) {
  const auto& myWord = dict.find(str);
  if (myWord != dict.end()) return myWord;
  // New word in dictionary
  auto newEntry = std::make_pair(str, dict.size());
  const DS::dict_iterator& insertedIterator = dict.insert(newEntry).first;
  return insertedIterator;
}

// findString for my index
const DS::string& DS::findString(const dict_iterator& i) {
  return i->first;
}

const DS::string& DS::str() const {
  return findString(m_iterator);
}

const DS::dict_index& DS::index() {
  return m_index;
}

// Default constructor
DS::DictString() {
  (*this) = emptyDictString;
}

// Assignment and constructor operators with char*
DS::DictString(const char* s) {
  m_iterator = findIterator(string(s));
  m_index = m_iterator->second;
}
DS& DS::operator= (const char* s) {
  m_iterator = findIterator(string(s));
  m_index = m_iterator->second;
}

// Assignment and constructor operators with std::string
DS::DictString(const std::string& s) {
  m_iterator = findIterator(s);
  m_index = m_iterator->second;
}
DS& DS::operator=(const std::string& s) {
  m_iterator = findIterator(s);
  m_index = m_iterator->second;
}

bool operator==(const DictString& lhs, const DictString& rhs) {
  return lhs.m_index == rhs.m_index;
}

bool operator!=(const DictString& lhs, const DictString& rhs) {
  return lhs.m_index != rhs.m_index;
}

bool operator<(const DictString& lhs, const DictString& rhs) {
  return lhs.m_index < rhs.m_index;
}

bool operator<= (const DictString& lhs, const DictString& rhs) {
  return lhs.m_index <= rhs.m_index;
}

bool operator>  (const DictString& lhs, const DictString& rhs) {
  return lhs.m_index > rhs.m_index;
}

bool operator>= (const DictString& lhs, const DictString& rhs) {
  return lhs.m_index >= rhs.m_index;
}

DictString operator+ (const DictString& lhs, const DictString& rhs){
  return DictString(lhs.str()+rhs.str());
}

DictString operator+ (const DictString& lhs, const DS::string& rhs){
  return DictString(lhs.str()+rhs);
}

DictString operator+ (const DictString& lhs, const char*   rhs){
  return DictString(lhs.str()+rhs);
}

DictString operator+ (const DictString& lhs, const char    rhs){
  return DictString(lhs.str()+rhs);
}

DictString operator+ (const DS::string&     lhs, const DictString& rhs){
  return DictString(lhs+rhs.str());
}

DictString operator+ (const char*       lhs, const DictString& rhs){
  return DictString(lhs+rhs.str());
}

DictString operator+ (char              lhs, const DictString& rhs){
  std::string lhs_string;
  lhs_string = lhs;
  return DictString(lhs_string+rhs.str());
}
