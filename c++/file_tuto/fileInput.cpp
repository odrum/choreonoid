// ファイルの読み込みにはifstreamを使う・
// ファイルデータの代入は>>演算子を使うと実行でき、スペースを区切りに読み込みを行う。
// getlineは第一因数に入力するファイル、第二引数にデータ受け取り用のstring変数を入れる。
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int countfileline( const char* targetfile);

int main(){

  int count = countfileline("test.txt");
  std::ifstream x;
  x.open("test.txt");
  for(int  i=0; i < count; i++){
    std::string str;
    x >> str;
    cout << str << endl;
  }
}

int countfileline( const char* targetfile){
  int i = 0;
  string str;

  ifstream ifs(targetfile);
  if(ifs){
    while(1){
      ifs >> str;
      i++;
      if(ifs.eof()){
        break;
      }
    }
  }
  return i;
}
