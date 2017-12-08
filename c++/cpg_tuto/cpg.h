// 松岡振動子のCPGネットワークプログラム。
// プログラムのコンセプト：
// パッケージみたいにしたい。なので、ここではCPGの計算とそのファイル出力だけを担当する。
// CPGネットワークは個別に作るか、それ用のプログラムを作る。
// CPG間の結合を自動にやってほしい。switch文でできそう。

#pragma once
#include<iostream>

using namespace std;


class CPG{
public:
 double max1(double x);  //閾値の関数。
 double dif_x1(double x,double y,double f);
 double dif_x2(double x,double y1, double y2,double f);
 double dif_x3(double x,double y1,double y2, double y3,double f);
 double dif_f(double y,double f);

};
