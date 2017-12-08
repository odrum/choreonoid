
#include <cnoid/SimpleController>
#include <cnoid/Link>
#include <cnoid/BodyMotion>
#include <cnoid/ExecutablePath>
#include <cnoid/FileUtil>

using namespace std;
using namespace cnoid;

static double pgain[] = {
  8000.0, 8000.0, 8000.0, 8000.0, 8000.0, 8000.0,
  3000.0, 3000.0, 3000.0, 3000.0, 3000.0, 3000.0, 3000.0,
  8000.0, 8000.0, 8000.0, 8000.0, 8000.0, 8000.0,
  3000.0, 3000.0, 3000.0, 3000.0, 3000.0, 3000.0, 3000.0,
  8000.0, 8000.0, 8000.0 };

  static double dgain[] = {
    100.0, 100.0, 100.0, 100.0, 100.0, 100.0,
    100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0,
    100.0, 100.0, 100.0, 100.0, 100.0, 100.0,
    100.0, 100.0, 100.0, 100.0, 100.0, 100.0, 100.0,
    100.0, 100.0, 100.0 };


    class Neko_gain_Controller : public cnoid::SimpleController
    {
      Body* ioBody;
      int currentFrameIndex;
      int lastFrameIndex;
      MultiValueSeqPtr qseq;
      MultiValueSeq::Frame qref0;
      MultiValueSeq::Frame qref1;
      vector<double> q0;
      double dt;

    public:

      virtual bool initialize(SimpleControllerIO* io) override
      {
        ioBody = io->body();
        dt = io->timeStep();

        for(auto joint : ioBody->joints()){
          joint->setActuationMode(actuationMode);
          io->enableIO(joint);
        }

        currentFrameIndex = 0;
        lastFrameIndex = std::max(0, qseq->numFrames() - 1);
        qref1 = qseq->frame(0);

        q0.resize(qseq->numParts());
        for(int i=0; i < ioBody->numJoints(); ++i){
          q0[i] = ioBody->joint(i)->q();
        }

        return true;
      }

      virtual bool control() override
      {

        qref0 = qref1;
        qref1 = qseq->frame(currentFrameIndex);
        for(int i=0; i < ioBody->numJoints(); ++i){
          Link* joint = ioBody->joint(i);
          double q_ref = qref1[i];
          double q = joint->q();
          double dq_ref = (q_ref - qref0[i]) / dt;
          double dq = (q - q0[i]) / dt;
          joint->u() = (q_ref - q) * pgain[i] + (dq_ref - dq) * dgain[i];
          q0[i] = q;

        }
        if(currentFrameIndex < qseq->numFrames()){
            ++currentFrameIndex;
            return true;
        } else {
            return false;
        }
      }
    };

    CNOID_IMPLEMENT_SIMPLE_CONTROLLER_FACTORY(Neko_gain_Controller)
