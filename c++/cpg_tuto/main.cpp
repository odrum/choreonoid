#include "cpg.h"
#include <iostream>
#include <fstream>

using namespace std;

#define Tr 0.17
#define a 1.5
#define b 7
#define Ta 0.5
#define s 2

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
  double *xe = new double[ cpg_n ];
  double *xf = new double[ cpg_n ];
  double *ye = new double[ cpg_n ];
  double *yf = new double[ cpg_n ];
  double *fe = new double[ cpg_n ];
  double *ff = new double[ cpg_n ];
  double *Y = new double[ cpg_n ];


  for (int i = 0; i < cpg_n; i++) {
    xe[i] = cpg_s;
    xf[i] = 0;
  }

  ofstream outputfile("cpg_test.txt");

  // main部開始
  for (double t = 0; t < TMAX; t = t + h) {
    for (int i = 0; i < cpg_n; i++) {
      ye[i] = cpg.max1(xe[i]);
      yf[i] = cpg.max1(xf[i]);

      fe[i] += h * cpg.dif_f(ye[i], fe[i]);
      ff[i] += h * cpg.dif_f(yf[i], ff[i]);
    }
    // 上位ネットワーク（歩容生成部）
    xe[0] += h* cpg.dif_x3(xe[0], yf[0], ye[1], yf[3], fe[0]);
    xf[0] += h* cpg.dif_x3(xf[0], ye[0], yf[1], ye[3], ff[0]);
    xe[1] += h* cpg.dif_x3(xe[1], yf[1], ye[0], ye[2], fe[1]);
    xf[1] += h* cpg.dif_x3(xf[1], ye[1], yf[0], yf[2], ff[1]);
    xe[2] += h* cpg.dif_x3(xe[2], yf[2], ye[3], ye[1], fe[2]);
    xf[2] += h* cpg.dif_x3(xf[2], ye[2], yf[3], yf[1], ff[2]);
    xe[3] += h* cpg.dif_x3(xe[3], yf[3], ye[2], yf[0], fe[3]);
    xf[3] += h* cpg.dif_x3(xf[3], ye[3], yf[2], ye[0], ff[3]);


    outputfile << t << " ";
    for (int i = 0; i < cpg_n; i++) {
      Y[i] = ye[i] - yf[i];
      outputfile<< Y[i] << " ";
    }

    outputfile<<endl;
  }
}
