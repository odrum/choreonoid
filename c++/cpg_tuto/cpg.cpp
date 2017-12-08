#include "cpg.h"
#include <iostream>
#include<fstream>

#define Tr 0.17
#define a 1.5
#define b 7
#define Ta 0.5
#define s 2

#define TMAX 20
#define h 0.01

double CPG::max1(double x){
  if(x>0){
    return x;
  }
  else{
    return 0;
  }
}

double CPG::dif_x1(double x,double y,double f){
  double dx;
  dx = (-x -a*y +s -b*f)/Tr;
  return dx;
}

double CPG::dif_x2(double x,double y1, double y2,double f){
  double dx;
  dx = (-x -a*y1 -a*y2 +s -b*f)/Tr;
  return dx;
}

double CPG::dif_x3(double x,double y1,double y2, double y3,double f){
  double dx;
  dx = (-x -a*y1 -a*y2 -0.01*y3 +s -b*f)/Tr;
  return dx;
}

double CPG::dif_f(double y,double f){
  double df;
  df = (-f+y)/Ta;
  return df;
}
