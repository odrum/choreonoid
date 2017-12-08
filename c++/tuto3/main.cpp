#include <iostream>
#include "data.h"
#include "calculation.h"

using namespace std;

int main(){
    CData d;
    d.init();   //  パラメータを初期化
    d.setNumber(100);
    d.setComment("Programming C++");
    cout << "number = " << d.getNumber() << " comment = " << d.getComment() << endl;

    TwoStrings s;
    s.setString1("Hello");
    s.setString2("World");
    cout << "一つ目の文字列は" << s.getString1() << endl;
    cout << "二つ目の文字列は" << s.getString2() << endl;
    cout << "二つの文字列を合成したものは" << s.getConnectedString() << endl;
    cout << "合成した文字列の長さは" << s.getConnectedLength() << "文字" << endl;

    Calculation c;
    c.setNumber1(8);    //  一つ目の数をセット
    c.setNumber2(9);    //  二つ目の数をセット
    //  二つの数の和を表示
    cout << c.getNumber1() << " + " << c.getNumber2() << " = " << c.add() << endl;
    //  二つの数の差を表示
    cout << c.getNumber1() << " - " << c.getNumber2() << " = " << c.sub() << endl;

    return 0;
}
