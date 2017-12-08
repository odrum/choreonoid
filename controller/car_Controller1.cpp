#include <cnoid/SimpleController>
#include <cnoid/Link>

using namespace cnoid;

class car_Controller1 : public cnoid::SimpleController
{
  BodyPtr ioBody; //bodyクラスの宣言。スマートポインタ
  double dt; //制御ループの呼び出し用変数。

public:

  virtual bool initialize(SimpleControllerIO* io) override //初期化関数
  {
    dt = io->timeStep(); //ステップ時間を設定。
    ioBody = io->body(); //bodyオブジェクトを取得し、ioBodyにひも付け


    for(auto joint : ioBody->joints()){ //まとめて設定する。
           joint->setActuationMode(Link::JOINT_TORQUE);
           io->enableIO(joint);
           }

    return true;
  }

  virtual bool control() override
  {

    for(int i=0; i < ioBody->numJoints(); ++i){
          Link* joint = ioBody->joint(i);
          joint->u() = -0.5;
      }
    return true;
  }

};

CNOID_IMPLEMENT_SIMPLE_CONTROLLER_FACTORY(car_Controller1)
