#include "calculation.h"

void Calculation::setNumber1(int num){
  number1 = num;
}

void Calculation::setNumber2(int num){
  number2 = num;
}

int Calculation::getNumber1(){
  return number1;
}

int Calculation::getNumber2(){
  return number2;
}

int Calculation::add(){
  return number1 +number2;
}

int Calculation::sub(){
  return number1 - number2;
}
