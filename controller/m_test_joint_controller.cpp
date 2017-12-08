#include <cnoid/SimpleController>
#include <iostream>
#include <cnoid/Link>


using namespace cnoid;

#define Tr 0.17
#define a 1.5
#define b 2
#define Ta 0.5
#define s 4
#define h 0.01


class m_test_joint_Controller : public cnoid::SimpleController
{
  BodyPtr ioBody; //bodyクラスの宣言。スマートポインタ
  double dt; //制御ループの呼び出し用変数。
  std::ostream& os();
  Link* RR_9;
  Link* RR_7;

  double xe;
  double xf;
  double ye;
  double yf;
  double fe;
  double ff;
  double Y;

public:
  virtual bool initialize(SimpleControllerIO* io) override //初期化関数
  {
    dt = io->timeStep(); //ステップ時間を設定。
    ioBody = io->body(); //bodyオブジェクトを取得し、ioBodyにひも付け

    RR_9 = io->body()->link("RR_9");
    RR_7 = io->body()->link("RR_7");

    RR_9->setActuationMode(Link::JOINT_TORQUE);
    RR_7->setActuationMode(Link::JOINT_TORQUE);
    io->enableOutput(RR_9);
    io->enableOutput(RR_7);

    io->os() << ioBody->numJoints() << std::endl;


    xe = 5;
    xf = 0;
    ye = 0;
    yf = 0;
    fe = 0;
    ff = 0;
    Y = 0;

    return true;
  }

  virtual bool control() override //制御ループ
  {

    // 下位ネットワーク（歩容生成部）
    xe += dt* ((-xe -a*yf +s -b*fe)/Tr);
    xf += dt* ((-xf -a*ye +s -b*ff)/Tr);

    fe += dt* ((-fe+ye)/Ta);
    ff += dt* ((-ff+yf)/Ta);

    if(xe > 0){
      ye = xe;
    }
    else{
      ye = 0;
    }

    if(xf > 0){
      yf = xf;
    }
    else{
      yf =0;
    }

    Y = ye - yf;

    // RR_9->u() = Y;
    RR_7->u() = Y;



    return true;

  }

};

CNOID_IMPLEMENT_SIMPLE_CONTROLLER_FACTORY(m_test_joint_Controller)
