#include<iostream>
#include "keisan.h"

using namespace std;

int main(){
  // 引き算・足し算
  keisan k;
  k.a = 4;
  k.b = 3;
  std::cout << k.a << " + " << k.b << " = " << k.add() << endl;
  std::cout << k.a << " - " << k.b << " = " << k.sub() << endl;

 // 最大値・最小値
   Maxmin m;
   int x = 6;
   int y = 8;
   std::cout << x << "と"  << y << "のうち最大値は" << m.max(x,y) << endl;
   std::cout << x << "と"  << y << "のうち最小値は" << m.min(x,y) << endl;

  return 0;
}
