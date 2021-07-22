#include "performancemeter.h
void PerformanceMeter::~PerformanceMeter(PerformanceMeter *this)
{
  if ( this->bestLap._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->bestLap);
    operator delete(this->bestLap._Myfirst);
    this->bestLap._Myfirst = 0;
    this->bestLap._Mylast = 0;
    this->bestLap._Myend = 0;
  }
  if ( this->currentLap._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->currentLap);
    operator delete(this->currentLap._Myfirst);
    this->currentLap._Myfirst = 0;
    this->currentLap._Mylast = 0;
    this->currentLap._Myend = 0;
  }
}
PerformanceSplit *PerformanceMeter::getCurrentSplit(PerformanceMeter *this, PerformanceSplit *result)
{
  TimeTransponder *v3; // ecx
  bool v4; // zf
  PerformanceSplit *v5; // eax
  PerformanceSplit res; // [esp+4h] [ebp-10h] BYREF

  if ( (_S2_0 & 1) == 0 )
  {
    perfCounter_27.name = "PerformanceMeter::getCurrentSplit";
    _S2_0 |= 1u;
    perfCounter_27.group = Physics;
    perfCounter_27.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"PerformanceMeter::getCurrentSplit" | 0xFF000000;
  }
  v3 = &this->car->transponder;
  res.t = 0.0;
  res.speedMS = 0.0;
  v4 = !TimeTransponder::isInOpenTrackTransition(v3);
  v5 = result;
  if ( v4 )
    res = *(PerformanceSplit *)&this->currentDiff;
  *(__m128i *)result = _mm_loadu_si128((const __m128i *)&res);
  return v5;
}
BOOL PerformanceMeter::hasData(PerformanceMeter *this)
{
  return (unsigned int)(this->bestLap._Mylast - this->bestLap._Myfirst) > 0;
}
void PerformanceMeter::init(PerformanceMeter *this, Car *car)
{
  this->bestLapTime = DOUBLE_N1_0;
  this->car = car;
  this->isEnabled = 1;
  this->lastLapIndex = 0;
  *(_OWORD *)&this->currentDistance = 0i64;
}
void PerformanceMeter::reset(PerformanceMeter *this)
{
  this->bestLapTime = DOUBLE_N1_0;
  this->lastLapIndex = 0;
  *(_OWORD *)&this->currentDistance = 0i64;
  std::_Container_base0::_Orphan_all(&this->currentLap);
  this->currentLap._Mylast = this->currentLap._Myfirst;
  std::_Container_base0::_Orphan_all(&this->bestLap);
  this->bestLap._Mylast = this->bestLap._Myfirst;
}
void PerformanceMeter::step(PerformanceMeter *this, float dt)
{
  Car *v3; // ecx
  long double v4; // xmm0_8
  int v5; // edx
  float v6; // xmm0_4
  Car *v7; // eax
  int v8; // ebx
  Car *v9; // ecx
  Speed result; // [esp+10h] [ebp-1Ch] BYREF
  Speed v11; // [esp+14h] [ebp-18h] BYREF
  PerformancePair _Val; // [esp+18h] [ebp-14h] BYREF
  int v13; // [esp+28h] [ebp-4h]

  if ( (dword_186F108 & 1) == 0 )
  {
    perfCounter_26.name = "PerformanceMeter::step";
    dword_186F108 |= 1u;
    perfCounter_26.group = Physics;
    perfCounter_26.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"PerformanceMeter::step" | 0xFF000000;
  }
  if ( this->isEnabled )
  {
    v3 = this->car;
    if ( v3->transponder.finishLinePassed )
    {
      if ( v3->transponder.wasLastLapValid
        && (this->bestLap._Myfirst == this->bestLap._Mylast || this->bestLapTime > (double)v3->transponder.lastLap) )
      {
        std::vector<PerformancePair>::operator=(&this->bestLap, &this->currentLap);
        this->bestLapTime = (double)this->car->transponder.lastLap;
      }
      *(_OWORD *)&this->currentDistance = 0i64;
      std::_Container_base0::_Orphan_all(&this->currentLap);
      this->currentLap._Mylast = this->currentLap._Myfirst;
    }
    else
    {
      v4 = v3->splineLocatorData.npos;
      this->currentDistance = v4;
      v5 = -1 - (int)(v4 * -999.999952502551);
      if ( v5 >= 0 && v5 >= (unsigned int)(this->currentLap._Mylast - this->currentLap._Myfirst) )
      {
        v6 = Car::getSpeed(v3, &result)->value;
        v7 = this->car;
        v13 = 0;
        _Val.speedMS = v6;
        _Val.t = v7->transponder.t;
        std::vector<DRSWingSetting>::push_back(&this->currentLap, &_Val);
        v13 = -1;
        dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
        this->lastRecordedDistance = this->currentDistance;
        v8 = this->currentLap._Mylast - this->currentLap._Myfirst - 1;
        if ( v8 < 0 || v8 >= (unsigned int)(this->bestLap._Mylast - this->bestLap._Myfirst) )
        {
          this->currentSpeedDiffMS = 0.0;
          this->currentDiff = 0.0;
        }
        else
        {
          v9 = this->car;
          this->currentDiff = ((double)v9->transponder.t - (double)this->bestLap._Myfirst[v8].t) * 0.001;
          this->currentSpeedDiffMS = Car::getSpeed(v9, &v11)->value - this->bestLap._Myfirst[v8].speedMS;
          dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v11);
        }
      }
    }
  }
}
