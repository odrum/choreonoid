#include "hoge.h"
#include <iostream>

using namespace std;

void Hoge::foo()
{
    cout << "fooメソッド" << endl;
}

Hoge::Hoge(){
  std::cout << "コンストラクタ" << endl;
}

Hoge::~Hoge(){
  std::cout << "デストラクタ" << endl;
}
