#include <iostream>
#include "number.h"
#include "hoge.h"

using namespace std;

int main(){
    Number* pN = 0;
    pN = new Number();
    pN->setNumbers(1, 2);
    cout << pN->getAdd() << endl;
    delete pN;

    Hoge* pH;
    pH = new Hoge();
    pH->foo();
    delete pH;

    //  配列を生成
    int* num = new int[4];
    int i;
    //  配列に値を代入
    for (i = 0; i < 4; i++){
        num[i] = i;
    }
    //  配列の内容を表示
    for (i = 0; i < 4; i++){
        cout << "num[" << i << "]=" << num[i] << " ";
    }
    delete [] num;
    cout << endl;

    return 0;
}
