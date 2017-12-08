#include <iostream>
#include <fstream>
#include "cpg.h"

using namespace std;

#define Tr 0.17
#define a 1.5
#define b 14
#define Ta 0.5
#define s 7

#define TMAX 20
#define h 0.01

int main(){
    CPG cpg;
  int cpg_n,cpg_s;
  // std::cout << "必要なCPG数を入力してください:";
  // std::cin >>  cpg_n;
  // std::cout << "初期値を入力してください:";
  // std::cin >> cpg_s;

  cpg_n = 6;
  cpg_s = 1;


  double xe = 10;
  double xf = 0;
  double ye = 0;
  double yf = 0;
  double fe = 0;
  double ff = 0;
  double Y = 0;

    xe = cpg_s;
    xf = 0;

  ofstream outputfile("cpg_test2.txt");

  // main部開始
  for (double t = 0; t < TMAX; t = t + h) {
    xe += h* (-xe -a*yf +s -b*fe)/Tr;
    xf += h* (-xf -a*ye +s -b*ff)/Tr;

    fe += h* (-fe+ye)/Ta;
    ff += h* (-ff+yf)/Ta;

    ye = cpg.max1(xe);
    yf = cpg.max1(xf);

    outputfile << t << " ";
      Y = ye - yf;
      outputfile<< Y << " ";
      outputfile<<endl;
    }


}
