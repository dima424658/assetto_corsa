#include "lapinvalidator.h
void LapInvalidator::init(LapInvalidator *this, Car *car)
{
  this->car = car;
}
void LapInvalidator::onEnterPenaltyZone(LapInvalidator *this, int tyre_count, float black_flag_time)
{
  char v4; // dl
  Car *v5; // ecx
  Speed *v6; // eax
  bool v7; // bl
  Speed *v8; // eax
  bool v9; // bl
  Speed result; // [esp+10h] [ebp-18h] BYREF
  Speed v11; // [esp+14h] [ebp-14h] BYREF
  PerformanceSplit v12; // [esp+18h] [ebp-10h] BYREF

  v4 = 0;
  LODWORD(v11.value) = 0;
  v5 = this->car;
  switch ( v5->ksPhysics->penaltyMode )
  {
    case CutGas:
      v7 = 0;
      if ( black_flag_time > 0.0 )
      {
        v6 = Car::getSpeed(v5, &result);
        v4 = 1;
        if ( (float)(v6->value * 3.5999999) > 35.0 )
          v7 = 1;
      }
      if ( (v4 & 1) != 0 )
        dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
      if ( v7 )
        Car::addPenalty(this->car, black_flag_time);
      break;
    case InvalidateLap:
      goto $LN8_25;
    case RecoverTime:
      if ( !this->isInPenaltyZone )
      {
        if ( PerformanceMeter::hasData(&v5->performanceMeter) )
        {
          Car::addPenalty(this->car, 5.0);
          this->car->penaltyPerfTarget = PerformanceMeter::getCurrentSplit(&this->car->performanceMeter, &v12)->t + 5.0;
          _printf("SETTING PENALTY TARGET:%f\n", (double)this->car->penaltyPerfTarget);
        }
        this->isInPenaltyZone = 1;
      }
      break;
    case CutDetection:
      v9 = 0;
      if ( black_flag_time > 0.0 )
      {
        v8 = Car::getSpeed(v5, &v11);
        v4 = 2;
        if ( (float)(v8->value * 3.5999999) > 35.0 )
          v9 = 1;
      }
      if ( (v4 & 2) != 0 )
        dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v11);
      if ( v9 )
      {
        v5 = this->car;
$LN8_25:
        TimeTransponder::addCut(&v5->transponder);
      }
      break;
    default:
      return;
  }
}
void LapInvalidator::step(LapInvalidator *this, float dt)
{
  Car *v3; // ebx
  PhysicsEngine *v4; // ebp
  int v5; // edi
  float v6; // xmm0_4
  SurfaceDef **v7; // edx
  SurfaceDef *v8; // eax
  PenaltyMode v9; // eax
  int v10; // eax
  Car *v11; // ecx
  float v12; // xmm1_4
  Speed result; // [esp+14h] [ebp-Ch] BYREF
  long double v14; // [esp+18h] [ebp-8h]

  v3 = this->car;
  v4 = v3->ksPhysics;
  if ( this->collisionSafeTime > v4->physicsTime - v3->lastCollisionWithCarTime )
  {
    this->currentTyresOut = 0;
    return;
  }
  LODWORD(result.value) = 0;
  v5 = 0;
  v6 = 0.0;
  if ( v3->tyres != (Tyre *)&v3->suspensions )
  {
    v7 = &v3->tyres[0].surfaceDef;
    do
    {
      v8 = *v7;
      if ( *v7 )
      {
        if ( !v8->isValidTrack )
        {
          ++v5;
          if ( v8->blackFlagTime > v6 )
            v6 = v8->blackFlagTime;
        }
      }
      v7 += 408;
    }
    while ( v7 - 204 != (SurfaceDef **)&v3->suspensions );
    result.value = v6;
  }
  v9 = v4->penaltyMode;
  if ( v9 )
  {
    if ( v9 != CutDetection )
      goto LABEL_20;
    if ( v6 == 0.0 )
      this->lastBlackFlagTime = 0.0;
  }
  else
  {
    v14 = Car::getPenaltyTime(v3);
    if ( v14 == 0.0 )
      this->lastBlackFlagTime = 0.0;
    v6 = result.value;
  }
  if ( v6 > this->lastBlackFlagTime )
  {
    this->isInPenaltyZone = 0;
    this->lastBlackFlagTime = v6;
  }
LABEL_20:
  if ( this->isInPenaltyZone )
  {
    if ( !v5 )
    {
      this->currentTyresOut = 0;
      this->isInPenaltyZone = 0;
      return;
    }
    v11 = this->car;
    if ( v11->ksPhysics->penaltyMode == CutGas )
    {
      v12 = Car::getSpeed(v11, &result)->value * 3.5999999;
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
      if ( v12 < 35.0 )
        Car::clearPenalty(this->car);
    }
  }
  else if ( Car::getControlsProvider(this->car) )
  {
    if ( !Car::getControlsProvider(this->car)->suppressPenalties )
    {
      v10 = this->car->ksPhysics->allowedTyresOut;
      if ( v5 > v10 && v10 != -1 )
      {
        LapInvalidator::onEnterPenaltyZone(this, v5, result.value);
        this->currentTyresOut = v5;
        this->isInPenaltyZone = 1;
        return;
      }
    }
  }
  this->currentTyresOut = v5;
}
