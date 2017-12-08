#include <cnoid/SimpleController>
#include <iostream>
#include <cnoid/Link>


using namespace cnoid;

#define Tr 0.5
#define a 3
#define b 10
#define Ta 0.5
#define s 5
#define h 0.01

#define cpg_n 4
#define cpg_s 1

class Neko_test_Controller : public cnoid::SimpleController
{
  BodyPtr ioBody; //bodyクラスの宣言。スマートポインタ
  double dt; //制御ループの呼び出し用変数。
  std::ostream& os();
  Link* RR_9;
  Link* RR_7;

public:
  virtual bool initialize(SimpleControllerIO* io) override //初期化関数
  {
    dt = io->timeStep(); //ステップ時間を設定。
    ioBody = io->body(); //bodyオブジェクトを取得し、ioBodyにひも付け

    FL_1 = io->body()->link("FL_1");
    FL_2 =io->body()->link("FL_2");
    FL_3=io->body()->link("FL_3");
    FL_5=io->body()->link("FL_5");
    FL_7=io->body()->link("FL_7");
    FR_1=io->body()->link("FR_1");
    FR_2=io->body()->link("FR_2");
    FR_3=io->body()->link("FR_3");
    FR_5=io->body()->link("FR_5");
    FR_7=io->body()->link("FR_7");

    RL_1=io->body()->link("RL_1");
    RL_2=io->body()->link("RL_2");
    RL_3=io->body()->link("RL_3");
    RL_5=io->body()->link("RL_5");
    RL_7=io->body()->link("RL_7");
    RL_9=io->body()->link("RL_9");
    RL_10=io->body()->link("RL_10");
    RR_1=io->body()->link("RR_1");
    RR_2=io->body()->link("RR_2");
    RR_3=io->body()->link("RR_3");
    RR_5=io->body()->link("RR_5");
    RR_7=io->body()->link("RR_7");
    RR_9=io->body()->link("RR_9");
    RR_10=io->body()->link("RR_10");

    FL_1->setActuationMode(Link::JOINT_TORQUE);
    FL_2->setActuationMode(Link::JOINT_TORQUE);
    FL_3->setActuationMode(Link::JOINT_TORQUE);
    FL_5->setActuationMode(Link::JOINT_TORQUE);
    FL_7->setActuationMode(Link::JOINT_TORQUE);
    FR_1->setActuationMode(Link::JOINT_TORQUE);
    FR_2->setActuationMode(Link::JOINT_TORQUE);
    FR_3->setActuationMode(Link::JOINT_TORQUE);
    FR_5->setActuationMode(Link::JOINT_TORQUE);
    FR_7->setActuationMode(Link::JOINT_TORQUE);
    RL_1->setActuationMode(Link::JOINT_TORQUE);
    RL_2->setActuationMode(Link::JOINT_TORQUE);
    RL_3->setActuationMode(Link::JOINT_TORQUE);
    RL_5->setActuationMode(Link::JOINT_TORQUE);
    RL_7->setActuationMode(Link::JOINT_TORQUE);
    RL_9->setActuationMode(Link::JOINT_TORQUE);
    RL_10->setActuationMode(Link::JOINT_TORQUE);
    RR_1->setActuationMode(Link::JOINT_TORQUE);
    RR_2->setActuationMode(Link::JOINT_TORQUE);
    RR_3->setActuationMode(Link::JOINT_TORQUE);
    RR_5->setActuationMode(Link::JOINT_TORQUE);
    RR_7->setActuationMode(Link::JOINT_TORQUE);
    RR_9->setActuationMode(Link::JOINT_TORQUE);
    RR_10->setActuationMode(Link::JOINT_TORQUE);

    io->enableOutput(FL_1);
    io->enableOutput(FL_2);
    io->enableOutput(FL_3);
    io->enableOutput(FL_5);
    io->enableOutput(FL_7);
    io->enableOutput(FR_1);
    io->enableOutput(FR_2);
    io->enableOutput(FR_3);
    io->enableOutput(FR_5);
    io->enableOutput(FR_7);
    io->enableOutput(RL_1);
    io->enableOutput(RL_2);
    io->enableOutput(RL_3);
    io->enableOutput(RL_5);
    io->enableOutput(RL_7);
    io->enableOutput(RL_9);
    io->enableOutput(RL_10);
    io->enableOutput(RR_1);
    io->enableOutput(RR_2);
    io->enableOutput(RR_3);
    io->enableOutput(RR_5);
    io->enableOutput(RR_7);
    io->enableOutput(RR_9);
    io->enableOutput(RR_10);

    io->os() << ioBody->numJoints() << std::endl;
    dt = h;

    return true;
  }

  virtual bool control() override //制御ループ
  {
    double xe = 5;
    double xf = 0;
    double ye = 0;
    double yf = 0;
    double fe = 0;
    double ff = 0;
    double Y = 0;

    // 下位ネットワーク（歩容生成部）
    xe += dt* (-xe -a*yf +s -b*fe)/Tr;
    xf += dt* (-xf -a*ye +s -b*ff)/Tr;

    fe += dt* (-fe+ye)/Ta;
    ff += dt* (-ff+yf)/Ta;

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

    FL_1->u() = Y;
    FL_2->u() = Y;
    FL_3->u() = Y;
    FL_5->u() = Y;
    FL_7->u() = Y;
    FR_1->u() = Y;
    FR_2->u() = Y;
    FR_3->u() = Y;
    FR_5->u() = Y;
    FR_7->u() = Y;
    RL_1->u() = Y;
    RL_2->u() = Y;
    RL_3->u() = Y;
    RL_5->u() = Y;
    RL_7->u() = Y;
    RL_9->u() = Y;
    RL_10->u() = Y;
    RR_1->u() = Y;
    RR_2->u() = Y;
    RR_3->u() = Y;
    RR_5->u() = Y;
    RR_9->u() = Y;
    RR_10->u() = Y;



    return true;

  }

};

CNOID_IMPLEMENT_SIMPLE_CONTROLLER_FACTORY(Neko_test_Controller)
