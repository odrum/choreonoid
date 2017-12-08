#include <iostream>
#include "function.h"
#include "object.h"
#include "counter.h"

using namespace std;

int main(){
    int m = 3, n = 1;
    cout << m << "と" << n << "のうち、最大のものは" << Function::max(m, n) << endl;
    cout << m << "と" << n << "のうち、最小のものは" << Function::min(m, n) << endl;

    Object *o1, *o2, *o3;
    o1 = new Object();
    o2 = new Object();
    o3 = new Object();
    cout << "オブジェクトの数:" << Object::getObjectNum() << endl;
    delete o3;
    cout << "オブジェクトの数:" << Object::getObjectNum() << endl;
    delete o2;
    delete o1;

    Counter c1, c2;
    c1.count();
    c2.count();
    c2.count();
    c2.reset();
    c1.count();
    c1.count();
    c2.count();
    cout << "c1のカウント数：" << c1.getCount() << endl;
    cout << "c2のカウント数：" << c2.getCount() << endl;
    cout << "トータルのカウント数:" << Counter::getTotalCount() << endl;

    return 0;
}
