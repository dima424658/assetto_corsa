#include "penaltymanager.h
void PenaltyManager::~PenaltyManager(PenaltyManager *this)
{
  if ( this->penaltyRecords._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->penaltyRecords);
    operator delete(this->penaltyRecords._Myfirst);
    this->penaltyRecords._Myfirst = 0;
    this->penaltyRecords._Mylast = 0;
    this->penaltyRecords._Myend = 0;
  }
  if ( this->evOnPenalty.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)this);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)this,
      (Task *)this->evOnPenalty.handlers._Myfirst,
      (Task *)this->evOnPenalty.handlers._Mylast);
    operator delete(this->evOnPenalty.handlers._Myfirst);
    this->evOnPenalty.handlers._Myfirst = 0;
    this->evOnPenalty.handlers._Mylast = 0;
    this->evOnPenalty.handlers._Myend = 0;
  }
}
void PenaltyManager::addJumpStartPenalty(PenaltyManager *this)
{
  Car *v2; // ecx
  PhysicsEngine *v3; // eax
  std::pair<void *,std::function<void __cdecl(OnPenaltyEvent const &)> > *v4; // esi
  std::_Func_base<void,OnPenaltyEvent const &> **i; // edi
  float v6; // xmm1_4
  float v7; // xmm2_4
  Car *v8; // ecx
  float v9; // xmm2_4
  float v10; // xmm0_4
  Car *v11; // ecx
  const __m128i *v12; // eax
  long double start; // xmm1_8
  PenaltyRecord _Val; // [esp+1Ch] [ebp-44h] BYREF
  vec3f pos; // [esp+28h] [ebp-38h] BYREF
  vec3f ihed; // [esp+34h] [ebp-2Ch] BYREF
  _QWORD v17[3]; // [esp+48h] [ebp-18h]

  v2 = this->car;
  if ( v2->ksPhysics->penaltyRules.jumpStartPenaltyMode == eTeleportToPitMode )
  {
$LN95_4:
    v6 = v2->pitPosition.M42;
    v7 = v2->pitPosition.M43;
    pos.x = v2->pitPosition.M41;
    pos.y = v6;
    pos.z = v7;
    Car::forcePosition(v2, &pos, 1);
    v8 = this->car;
    LODWORD(v9) = LODWORD(v8->pitPosition.M33) ^ _xmm;
    LODWORD(v10) = LODWORD(v8->pitPosition.M31) ^ _xmm;
    LODWORD(ihed.y) = LODWORD(v8->pitPosition.M32) ^ _xmm;
    ihed.x = v10;
    ihed.z = v9;
    Car::forceRotation(v8, &ihed);
    v11 = this->car;
    v12 = (const __m128i *)v11->ksPhysics;
    start = *(double *)&v12[17].m128i_i64[1];
    *(__m128i *)&v17[1] = _mm_loadu_si128(v12 + 18);
    Car::lockControlsUntil(v11, 20000.0, start);
    return;
  }
  if ( v2->ksPhysics->penaltyRules.jumpStartPenaltyMode == eDriveThroughMode )
  {
    this->pendingPenaltyType = eDriveThrough;
    v3 = v2->ksPhysics;
    _Val.lap = 0;
    _Val.seconds = 0;
    this->pitPenaltyLaps = v3->penaltyRules.basePitPenaltyLaps;
    _Val.descr = eSecsOnResult5;
    std::vector<PitStopStrategy>::push_back(&this->penaltyRecords, &_Val);
    v4 = this->evOnPenalty.handlers._Myfirst;
    _Val.lap = (unsigned int)this->car;
    _Val.seconds = this->pendingPenaltyType;
    if ( v4 != this->evOnPenalty.handlers._Mylast )
    {
      for ( i = &v4->second._Impl; *i; i += 8 )
      {
        (*i)->_Do_call(*i, (const OnPenaltyEvent *)&_Val);
        if ( ++v4 == this->evOnPenalty.handlers._Mylast )
          return;
      }
      std::_Xbad_function_call();
      goto $LN95_4;
    }
  }
}
bool PenaltyManager::checkBlackFlag(PenaltyManager *this)
{
  bool result; // al

  if ( this->pendingPenaltyType == eDriveThrough && this->pitPenaltyLaps == 1 )
    result = !this->isServingPitPenalty;
  else
    result = 0;
  return result;
}
void PenaltyManager::decreasePitPenaltyLaps(PenaltyManager *this, bool isValidLap)
{
  __int16 v2; // ax

  v2 = this->pitPenaltyLaps;
  if ( v2 > 0 && !this->isServingPitPenalty && isValidLap )
    this->pitPenaltyLaps = v2 - 1;
}
void PenaltyManager::init(PenaltyManager *this, Car *car)
{
  std::vector<PenaltyRecord> *v2; // esi

  v2 = &this->penaltyRecords;
  this->car = car;
  std::_Container_base0::_Orphan_all(&this->penaltyRecords);
  v2->_Mylast = v2->_Myfirst;
}
void PenaltyManager::reset(PenaltyManager *this)
{
  this->penaltySecs = 0;
  this->pitPenaltyLaps = 0;
  std::_Container_base0::_Orphan_all(&this->penaltyRecords);
  this->penaltyRecords._Mylast = this->penaltyRecords._Myfirst;
  *(_WORD *)&this->isServingPitPenalty = 0;
  this->inPitMeterCounter = 0.0;
}
void PenaltyManager::resetPenalty(PenaltyManager *this)
{
  Car *v2; // eax
  std::pair<void *,std::function<void __cdecl(OnPenaltyEvent const &)> > *v3; // esi
  std::_Func_base<void,OnPenaltyEvent const &> **v4; // ebx
  int v5[2]; // [esp+8h] [ebp-8h] BYREF

  if ( this->pendingPenaltyType == eDriveThrough )
  {
    *(_DWORD *)&this->isServingPitPenalty = 0;
    this->inPitMeterCounter = 0.0;
  }
  v2 = this->car;
  this->pendingPenaltyType = eNothing;
  v3 = this->evOnPenalty.handlers._Myfirst;
  v5[0] = (int)v2;
  v5[1] = 0;
  if ( v3 != this->evOnPenalty.handlers._Mylast )
  {
    v4 = &v3->second._Impl;
    do
    {
      if ( !*v4 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x7273DE);
      }
      (*v4)->_Do_call(*v4, (const OnPenaltyEvent *)v5);
      ++v3;
      v4 += 8;
    }
    while ( v3 != this->evOnPenalty.handlers._Mylast );
  }
}
void PenaltyManager::step(PenaltyManager *this, float dt)
{
  __int16 v3; // ax
  __int16 v4; // ax
  Speed result; // [esp+4h] [ebp-4h] BYREF

  if ( this->pitPenaltyLaps > 0 )
  {
    if ( Car::isInPitLane(this->car) )
    {
      this->inPitMeterCounter = (float)(Car::getSpeed(this->car, &result)->value * dt) + this->inPitMeterCounter;
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
      this->isServingPitPenalty = 1;
      return;
    }
    if ( this->isServingPitPenalty )
    {
      if ( this->pendingPenaltyType == eDriveThrough )
      {
        if ( this->rearmPitPenalty )
        {
          v4 = this->pitPenaltyLaps;
          if ( v4 == 1 )
          {
            Car::setBlackFlag(this->car, 1, eSecsOnResult5);
            *(_WORD *)&this->isServingPitPenalty = 0;
            this->inPitMeterCounter = 0.0;
            return;
          }
          v3 = v4 - 1;
          goto LABEL_12;
        }
        if ( this->inPitMeterCounter >= 160.0 )
        {
          v3 = 0;
LABEL_12:
          this->pitPenaltyLaps = v3;
          goto LABEL_13;
        }
      }
LABEL_13:
      *(_WORD *)&this->isServingPitPenalty = 0;
      this->inPitMeterCounter = 0.0;
      return;
    }
  }
}
