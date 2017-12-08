#pragma once

#include<iostream>

class Calculation{
public:
  void setNumber1(int num);
  void setNumber2(int num);

  int getNumber1();
  int getNumber2();

  int add();
  int sub();

private:
  int number1;
  int number2;

};
