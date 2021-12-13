#include "fuellapevaluator.h"
long double FuelLapEvaluator::getFuelLaps(FuelLapEvaluator *this)
{
  long double result; // st7

  if ( this->fuelPerLap == 0.0 )
    result = -1.0;
  else
    result = this->car->fuel / this->fuelPerLap;
  return result;
}
long double FuelLapEvaluator::getFuelPerLap(FuelLapEvaluator *this)
{
  long double result; // st7

  if ( this->lapCount <= 1 )
    result = this->oldFuelPerLap;
  else
    result = this->fuelPerLap;
  return result;
}
void FuelLapEvaluator::init(FuelLapEvaluator *this, Car *icar)
{
  Event<OnLapCompletedEvent> *v3; // ecx
  Car *v4; // eax
  std::function<void __cdecl(SessionInfo const &)> v5; // [esp-1Ch] [ebp-38h] BYREF
  FuelLapEvaluator *v6; // [esp-4h] [ebp-20h]
  int v7; // [esp+18h] [ebp-4h]

  v6 = this;
  this->car = icar;
  this->lapCount = 0;
  *(_OWORD *)&this->lapStartFuel = 0i64;
  this->ignoreLap = 0;
  v5._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_cfb5c74fb229346d1f4509bd482d289b_,0>,std::allocator<std::_Func_class<void,OnLapCompletedEvent const &>>,void,OnLapCompletedEvent const &>::`vftable';
  v5._Space._Pfn[1] = (void (__cdecl *)())this;
  v5._Impl = (std::_Func_base<void,SessionInfo const &> *)&v5;
  v3 = &this->car->evOnLapCompleted;
  v7 = -1;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v3,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v5,
    v6);
  v6 = this;
  v5._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_4a879c77ef71faeb7e217cda83a00b58_,0>,std::allocator<std::_Func_class<void,SessionInfo const &>>,void,SessionInfo const &>::`vftable';
  v5._Space._Pfn[1] = (void (__cdecl *)())this;
  v5._Impl = (std::_Func_base<void,SessionInfo const &> *)&v5;
  v4 = this->car;
  v7 = -1;
  Event<float>::addHandler(&v4->ksPhysics->evOnNewSessionPhysics, v5, this);
}
void FuelLapEvaluator::setIgnoreLap(FuelLapEvaluator *this, bool value)
{
  this->ignoreLap = value;
}
void FuelLapEvaluator::step(FuelLapEvaluator *this, float dt)
{
  float v3; // xmm2_4
  Car *v4; // ecx
  double v5; // xmm1_8
  Speed result; // [esp+4h] [ebp-8h] BYREF
  float v7; // [esp+8h] [ebp-4h]

  v7 = Car::getSpeed(this->car, &result)->value;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  v3 = v7;
  v4 = this->car;
  this->totalM = (float)(v7 * dt) + this->totalM;
  v5 = v4->fuel;
  if ( this->startFuel < -50.0 && v3 > 5.0 )
    this->startFuel = v5;
  this->totalLiters = this->startFuel - v5;
  if ( Car::isInPitLane(v4) )
    this->ignoreLap = 1;
}
