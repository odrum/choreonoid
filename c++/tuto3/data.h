#ifndef _CDATA_H_
#define _CDATA_H_

#include <iostream>
#include <string>

using namespace std;

class CData{
private:
    //  メンバ変数number
    int number;
    //  メンバ変数comment
    string comment;
public:
    //  初期化
    void init();
    void setNumber(int num);
    void setComment(string com);
    int getNumber();
    string getComment();
};

class TwoStrings{
private:
    //  一つ目の文字列
    string m_string1;
    //  二つ目の文字列
    string m_string2;
    string sum_string;
public:
    //  一つ目の文字列を設定
    void setString1(string s);
    //  二つ目の文字列を設定
    void setString2(string s);
    //  一つ目の文字列を取得
    string getString1();
    //  二つ目の文字列を取得
    string getString2();
    //  二つの文字列をつないだものを取得
    string getConnectedString();
    //  getConnectedString()で得られる文字列の長さを取得
    int getConnectedLength();
};

#endif // _CDATA_H_
