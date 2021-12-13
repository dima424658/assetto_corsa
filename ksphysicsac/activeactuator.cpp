#include "activeactuator.h"
void ActiveActuator::~ActiveActuator(CarControlsInput *this)
{
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->speed);
}
void ActiveActuator::ActiveActuator(ActiveActuator *this)
{
  this->targetTravel = 0.0;
  PIDController::PIDController(&this->pid);
}
double ActiveActuator::eval(ActiveActuator *this, float dt, float currentTravel)
{
  return PIDController::eval(&this->pid, this->targetTravel, currentTravel, dt);
}
