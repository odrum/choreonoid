#include <iostream>
#include "fighter.h"
#include "newcalc.h"

using namespace std;

int main(){
    Fighter f;  //  戦闘機クラス
    Airplane a; //  飛行機クラス
    //  飛行機が飛行する
    a.fly();
    //  戦闘機が飛行する
    f.fly();
    //  戦闘機が戦闘する
    f.fight();

    NewCalc n;
    n.setNumber1(10);   //  一つ目の数を設定
    n.setNumber2(2);    //  二つ目の数を設定
    cout << n.getNumber1() << " + " << n.getNumber2() << " = " << n.add() << endl;
    cout << n.getNumber1() << " - " << n.getNumber2() << " = " << n.sub() << endl;
    cout << n.getNumber1() << " * " << n.getNumber2() << " = " << n.mul() << endl;
    cout << n.getNumber1() << " / " << n.getNumber2() << " = " << n.div() << endl;

    return 0;
}
