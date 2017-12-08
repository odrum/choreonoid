// CPGの制御プログラムをモジュール化しようとしたけど僕の力量じゃむりだった。
// ごちゃごちゃするけど直接計算式を書いていく。

#include <cnoid/SimpleController>
#include <iostream>
#include <cnoid/Link>
#include <vector>

using namespace cnoid;
using namespace std;

#define Tr 0.17
#define a 2
#define b 2
#define Ta 0.8
#define s 100
#define h 0.1

#define cpg_n 5

class m_test_oneleg_Controller : public cnoid::SimpleController
{
  BodyPtr ioBody; //bodyクラスの宣言。スマートポインタ
  double dt; //制御ループの呼び出し用変数。

  std::vector<double> xe;
  std::vector<double> xf;
  std::vector<double> ye;
  std::vector<double> yf;
  std::vector<double> fe;
  std::vector<double> ff;
  std::vector<double> Y;
  std::ostream& os();

  // Link* RR_3;
  // Link* RR_5;
  Link* RR_7;
  Link* RR_9;
  // Link* RR_10;

public:
  virtual bool initialize(SimpleControllerIO* io) override //初期化関数
  {
    dt = io->timeStep();  //ステップ時間を設定。
    ioBody = io->body(); //bodyオブジェクトを取得し、ioBodyにひも付け
    ostream& os = io->os();

    for(int i=0; i < cpg_n; ++i){
      xe.push_back(5);
      xf.push_back(0);
      ye.push_back(0);
      yf.push_back(0);
      fe.push_back(0);
      ff.push_back(0);
      Y.push_back(0);
    }

    // RR_3 = io->body()->link("RR_3");
    // RR_5 = io->body()->link("RR_5");
    RR_7 = io->body()->link("RR_7");
    RR_9 = io->body()->link("RR_9");
    // RR_10 = io->body()->link("RR_10");

    // RR_3->setActuationMode(Link::JOINT_TORQUE);
    // RR_5->setActuationMode(Link::JOINT_TORQUE);
    RR_7->setActuationMode(Link::JOINT_TORQUE);
    RR_9->setActuationMode(Link::JOINT_TORQUE);
    // RR_10->setActuationMode(Link::JOINT_TORQUE);

    // io->enableOutput(RR_3);
    // io->enableOutput(RR_5);
    io->enableOutput(RR_7);
    io->enableOutput(RR_9);
    // io->enableOutput(RR_10);

    io->os() << ioBody->numJoints() << std::endl;
    dt = h;

    return true;
  }

  virtual bool control() override //制御ループ
  {
    // 下位ネットワーク（歩容生成部）
    xe[0] += dt* ((-xe[0] -a*yf[0] +s -b*fe[0])/Tr);
    xf[0] += dt* ((-xf[0] -a*ye[0] +s -b*ff[0])/Tr);
    xe[1] += dt* ((-xe[1] -a*yf[1] +a*yf[0] +s -b*fe[1])/Tr);
    xf[1] += dt* ((-xf[1] -a*ye[1] +a*ye[0] +s -b*ff[1])/Tr);
    xe[2] += dt* ((-xe[2] -a*yf[2] +a*yf[1] +s -b*fe[2])/Tr);
    xf[2] += dt* ((-xf[2] -a*ye[2] +a*ye[1] +s -b*ff[2])/Tr);
    xe[3] += dt* ((-xe[3] -a*yf[3] +a*yf[2] +s -b*fe[3])/Tr);
    xf[3] += dt* ((-xf[3] -a*ye[3] +a*ye[2] +s -b*ff[3])/Tr);
    // xe[4] += dt* ((-xe[4] -a*yf[4] -a*ye[2] -a*yf[0] +s -b*fe[4])/Tr);
    // xf[4] += dt* ((-xf[4] -a*ye[4] -a*yf[2] -a*ye[0] +s -b*ff[4])/Tr);

    for(int i = 0; i < cpg_n; i++){
      fe[i] += dt * ((ye[i]-fe[i])/Ta);
      ff[i] += dt * ((yf[i]-ff[i])/Ta);
    }

    for (int i = 0; i < cpg_n; i++) {
      if( xe[i] > 0){
        ye[i] = xe[i];
      }
      else{
        ye[i] = 0;
      }
    }

    for (int i = 0; i < cpg_n; i++) {
      if(xf[i] > 0){
        yf[i] = xf[i];
      }
      else{
        yf[i] = 0;
      }
    }

    for (int i = 0; i < cpg_n; i++) {
      Y[i] = ye[i] - yf[i];
    }

    // RR_3->u() = Y[0];
    // RR_5->u() = Y[0];
    RR_7->u() = Y[1];
    RR_9->u() = Y[2];
    // RR_10->u() = Y[4];

    return true;
  }

};

CNOID_IMPLEMENT_SIMPLE_CONTROLLER_FACTORY(m_test_oneleg_Controller)
