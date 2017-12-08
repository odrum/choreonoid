#include "data.h"

void CData::init()
{
    number = 0;
    comment = "";
}

void CData::setNumber(int num){
  number = num;
}

void CData::setComment(string com){
   comment = com;
}

int CData::getNumber(){
  return number;
}

string CData::getComment(){
  return comment;
}
