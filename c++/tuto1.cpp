#include <iostream>
#include<string>

using namespace std;

int main(){
  std::cout << "Hello!world!" << endl;
  std::cout << "ONE TWO THREE" << endl << "FOUR FIVE SIX" << endl;
  int s,t;
  std::cout << "数値を入力してください：" ;
  std::cin >> s;
  t = s*2;
  std::cout << s << "を２倍した数は" << t <<endl;

  string a,b;
  std::cout << "姓を入力してください：";
  std::cin >> a;
  std::cout << "名を入力してください：";
  std::cin >> b;
  std::cout << "あなたの名前は" << a+b << "です" << endl;

  return 0;

}
