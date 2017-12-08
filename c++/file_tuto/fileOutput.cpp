// ファイル出力のプログラム。
// ofstreamを使用することでファイルを出力できる。

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

  ofstream outputfile("test_output.txt");
  int count = 100;
  for(int i = 0; i < count; i++){
    outputfile << i << endl;
  }
}
