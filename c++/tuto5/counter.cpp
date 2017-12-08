#include <iostream>
#include "counter.h"

int Counter::m_totalcount = 0;

//  コンストラクタ（カウント回数を0で初期化）
Counter::Counter() : m_count(0)
{
}
void Counter::reset(){
    m_count = 0;
    m_totalcount = 0;
}
void Counter::count(){
    m_count++;
    m_totalcount++;
}
int Counter::getCount(){
    return m_count;
}

int Counter::getTotalCount(){
 return m_totalcount;
}
