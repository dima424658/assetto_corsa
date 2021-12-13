#include "speedlimiter.h"
void SpeedLimiter::init(SpeedLimiter *this, Car *car)
{
  this->car = car;
}
void SpeedLimiter::step(SpeedLimiter *this, float dt)
{
  Car *v3; // ecx
  SurfaceDef *v4; // eax
  SurfaceDef *v5; // eax
  SurfaceDef *v6; // eax
  SurfaceDef *v7; // eax
  float v8; // xmm0_4
  Speed result; // [esp+8h] [ebp-20h] BYREF
  float v10; // [esp+Ch] [ebp-1Ch]
  RaceEngineer raceEng; // [esp+10h] [ebp-18h] BYREF
  int v12; // [esp+24h] [ebp-4h]

  RaceEngineer::RaceEngineer(&raceEng, this->car);
  v3 = this->car;
  *(_WORD *)&this->shoudLimit = 0;
  v12 = 0;
  v4 = v3->tyres[0].surfaceDef;
  if ( v4 )
    this->shoudLimit = v4->isPitlane;
  v5 = v3->tyres[1].surfaceDef;
  if ( v5 )
    this->shoudLimit |= v5->isPitlane;
  v6 = v3->tyres[2].surfaceDef;
  if ( v6 )
    this->shoudLimit |= v6->isPitlane;
  v7 = v3->tyres[3].surfaceDef;
  if ( v7 )
    this->shoudLimit |= v7->isPitlane;
  if ( this->shoudLimit )
  {
    v10 = Car::getSpeed(v3, &result)->value * 3.5999999;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
    v8 = v10;
    if ( v10 > 80.0 )
    {
      this->car->drivetrain.acEngine.electronicOverride = 0.0;
      this->isLimiting = 1;
    }
    if ( v8 > 81.0 )
      this->car->brakeSystem.electronicOverride = RaceEngineer::getOptimalBrake(&raceEng);
  }
  v12 = -1;
  RaceEngineer::~RaceEngineer(&raceEng);
}
