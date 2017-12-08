#include "data.h"

void TwoStrings::setString1(string s){
  m_string1 = s;
}

void TwoStrings::setString2(string s){
  m_string2 = s;
}

string TwoStrings::getString1(){
  return m_string1;
}

string TwoStrings::getString2(){
  return m_string2;
}

string TwoStrings::getConnectedString(){
  sum_string = m_string1 + m_string2;
  return sum_string;
}

int TwoStrings::getConnectedLength(){
  return sum_string.length();
}
