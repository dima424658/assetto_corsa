#include "timetransponder.h
void TimeTransponder::TimeTransponder(TimeTransponder *this)
{
  this->t = 0;
  this->lastLap = 0;
  this->bestLap = 0;
  this->lapCount = 0;
  *(_WORD *)&this->finishLinePassed = 0;
  this->status._Myfirst = 0;
  this->status._Mylast = 0;
  this->status._Myend = 0;
  this->lastLapSplits._Myfirst = 0;
  this->lastLapSplits._Mylast = 0;
  this->lastLapSplits._Myend = 0;
  this->bestLapSplits._Myfirst = 0;
  this->bestLapSplits._Mylast = 0;
  this->bestLapSplits._Myend = 0;
  this->currentSplits._Myfirst = 0;
  this->currentSplits._Mylast = 0;
  this->currentSplits._Myend = 0;
  this->isFirstLapArmed = 0;
  this->cuts = 0;
  this->extInvalid = 0;
  this->openTrackState = NotStarted;
  this->isOpenTrack = 0;
}
void TimeTransponder::~TimeTransponder(TimeTransponder *this)
{
  if ( this->currentSplits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->currentSplits);
    operator delete(this->currentSplits._Myfirst);
    this->currentSplits._Myfirst = 0;
    this->currentSplits._Mylast = 0;
    this->currentSplits._Myend = 0;
  }
  if ( this->bestLapSplits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->bestLapSplits);
    operator delete(this->bestLapSplits._Myfirst);
    this->bestLapSplits._Myfirst = 0;
    this->bestLapSplits._Mylast = 0;
    this->bestLapSplits._Myend = 0;
  }
  if ( this->lastLapSplits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->lastLapSplits);
    operator delete(this->lastLapSplits._Myfirst);
    this->lastLapSplits._Myfirst = 0;
    this->lastLapSplits._Mylast = 0;
    this->lastLapSplits._Myend = 0;
  }
  if ( this->status._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->status);
    operator delete(this->status._Myfirst);
    this->status._Myfirst = 0;
    this->status._Mylast = 0;
    this->status._Myend = 0;
  }
}
void TimeTransponder::addCut(TimeTransponder *this)
{
  ++this->cuts;
}
void TimeTransponder::armFirstLap(TimeTransponder *this)
{
  this->isFirstLapArmed = 1;
}
int TimeTransponder::getCuts(TimeTransponder *this)
{
  return this->cuts;
}
std::vector<unsigned int> *TimeTransponder::getLastLapSplits(TimeTransponder *this, std::vector<unsigned int> *result)
{
  std::vector<Mesh *>::vector<Mesh *>(
    (std::vector<TyreThermalPatch *> *)result,
    (const std::vector<TyreThermalPatch *> *)&this->lastLapSplits);
  return result;
}
TimeLineStatus *TimeTransponder::getStatus(TimeTransponder *this, int index)
{
  std::wstring *v3; // eax
  std::wstring v5; // [esp+Ch] [ebp-28h] BYREF
  int v6; // [esp+30h] [ebp-4h]

  if ( index < 0 || index >= (unsigned int)(this->status._Mylast - this->status._Myfirst) )
  {
    v5._Myres = 7;
    v5._Mysize = 0;
    v5._Bx._Buf[0] = 0;
    std::wstring::assign(&v5, L"ERROR: TimeTransponder::getStatus, index out of bound:", 0x36u);
    v3 = &v5;
    v6 = 0;
    if ( v5._Myres >= 8 )
      v3 = (std::wstring *)v5._Bx._Ptr;
    _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v3->_Bx._Buf);
    ksGenerateCrash();
    if ( v5._Myres >= 8 )
      operator delete(v5._Bx._Ptr);
  }
  return &this->status._Myfirst[index];
}
void TimeTransponder::init(TimeTransponder *this, Car *car)
{
  Car *v2; // edx
  unsigned int v4; // edx
  int v5; // ecx
  int v6; // ecx

  v2 = car;
  this->car = car;
  this->t = 0;
  this->lapCount = 0;
  this->lastLap = 0;
  this->bestLap = 0;
  this->cuts = 0;
  *(_WORD *)&this->finishLinePassed = 0;
  this->isOpenTrack = v2->ksPhysics->track->isOpen;
  v4 = (int)((unsigned __int64)(1321528399i64
                              * ((char *)v2->ksPhysics->track->timeLines._Mylast
                               - (char *)v2->ksPhysics->track->timeLines._Myfirst)) >> 32) >> 4;
  std::vector<TimeLineStatus>::resize(&this->status, v4 + (v4 >> 31));
  v5 = (char *)this->status._Mylast - (char *)this->status._Myfirst;
  car = 0;
  std::vector<unsigned int>::resize(&this->lastLapSplits, v5 / 12, (const unsigned int *)&car);
  v6 = (char *)this->status._Mylast - (char *)this->status._Myfirst;
  car = 0;
  std::vector<unsigned int>::resize(&this->bestLapSplits, v6 / 12, (const unsigned int *)&car);
  car = 0;
  std::vector<unsigned int>::resize(
    &this->currentSplits,
    this->status._Mylast - this->status._Myfirst,
    (const unsigned int *)&car);
}
void TimeTransponder::invalidate(TimeTransponder *this)
{
  TimeLineStatus *v2; // edx
  TimeLineStatus *i; // eax
  unsigned int *v4; // ecx
  int v5; // edx
  unsigned int *v6; // eax
  unsigned int v7; // esi

  v2 = this->status._Mylast;
  for ( i = this->status._Myfirst; i != v2; ++i )
  {
    i->isValid = 0;
    i->lastResponse = eOutOfRange;
    i->lastTime = 0;
  }
  v4 = this->currentSplits._Myfirst;
  v5 = 0;
  v6 = this->currentSplits._Mylast;
  v7 = (unsigned int)((char *)v6 - (char *)v4 + 3) >> 2;
  if ( v4 > v6 )
    v7 = 0;
  if ( v7 )
  {
    do
    {
      ++v5;
      *v4++ = 0;
    }
    while ( v5 != v7 );
  }
}
bool TimeTransponder::isInOpenTrackTransition(TimeTransponder *this)
{
  bool result; // al

  if ( this->isOpenTrack )
    result = this->openTrackState == NotStarted;
  else
    result = 0;
  return result;
}
char TimeTransponder::isValid(TimeTransponder *this)
{
  int v2; // ebx
  TimeLineStatus *i; // edi

  if ( this->isOpenTrack )
    return 1;
  v2 = 0;
  if ( !(this->status._Mylast - this->status._Myfirst) )
    return this->status._Mylast - this->status._Myfirst && !this->extInvalid;
  for ( i = this->status._Myfirst; i->isValid; ++i )
  {
    if ( ++v2 >= (unsigned int)(this->status._Mylast - this->status._Myfirst) )
      return this->status._Mylast - this->status._Myfirst && !this->extInvalid;
  }
  return 0;
}
void TimeTransponder::lap(TimeTransponder *this, bool valid)
{
  Car *v3; // eax
  std::vector<WingState> *v4; // eax
  Car *v5; // ecx
  long double v6; // xmm0_8
  TimeLineStatus *v7; // ecx
  TimeLineStatus *i; // eax
  bool v9; // zf
  std::vector<unsigned int> result; // [esp+Ch] [ebp-40h] BYREF
  OnLapCompletedEvent ev; // [esp+18h] [ebp-34h] BYREF
  int v12; // [esp+48h] [ebp-4h]

  if ( this->lastLap )
  {
    _printf("LAP VALID: %d CUTS:%d, COUNT: %u\n", valid, this->cuts, this->lapCount);
    ev.splits._Myfirst = 0;
    ev.splits._Mylast = 0;
    ev.splits._Myend = 0;
    ev.cuts = 0;
    ev.carIndex = 0;
    ev.lapTime = 0;
    ev.lapCount = 0;
    ev.eventTime = 0.0;
    ev.isValid = 0;
    v3 = this->car;
    v12 = 0;
    ev.carIndex = v3->physicsGUID;
    ev.lapCount = this->lapCount;
    ev.lapTime = this->lastLap;
    v4 = (std::vector<WingState> *)TimeTransponder::getLastLapSplits(this, &result);
    LOBYTE(v12) = 1;
    std::vector<WingState>::operator=((std::vector<WingState> *)&ev.splits, v4);
    LOBYTE(v12) = 0;
    if ( result._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&result);
      operator delete(result._Myfirst);
    }
    v5 = this->car;
    v6 = v5->ksPhysics->physicsTime;
    ev.cuts = this->cuts;
    ev.eventTime = v6;
    ev.isValid = valid;
    Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&v5->evOnLapCompleted, (const OnGearRequestEvent *)&ev);
    v7 = this->status._Mylast;
    for ( i = this->status._Myfirst; i != v7; ++i )
    {
      i->isValid = 0;
      i->lastResponse = eOutOfRange;
      i->lastTime = 0;
    }
    v9 = ev.splits._Myfirst == 0;
    this->cuts = 0;
    v12 = -1;
    if ( !v9 )
    {
      std::_Container_base0::_Orphan_all(&ev.splits);
      operator delete(ev.splits._Myfirst);
    }
  }
}
void TimeTransponder::onTimeLinePassed(TimeTransponder *this, int index, bool isFinishLine)
{
  unsigned int v4; // ebp
  long double v5; // st7
  Car *v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // ecx
  bool v10; // zf
  Car *v11; // ecx
  Car *v12; // ecx
  Car *v13; // ecx
  bool v14; // al
  TimeLineStatus *v15; // eax

  this->status._Myfirst[index].isValid = 1;
  v4 = (unsigned int)(PhysicsEngine::getOddTimeOffset(this->car->ksPhysics) + (double)this->t);
  this->status._Myfirst[index].lastTime = v4;
  if ( isFinishLine )
  {
    v5 = Car::getPenaltyTime(this->car);
    v6 = this->car;
    if ( v5 <= 0.0 )
    {
      if ( PenaltyManager::checkBlackFlag(&v6->penaltyManager) )
      {
        Car::setBlackFlag(this->car, 1, eSecsOnResult5);
        TimeTransponder::invalidate(this);
      }
      else
      {
        this->finishLinePassed = 1;
        if ( TimeTransponder::isValid(this) )
        {
          v7 = this->bestLap;
          this->wasLastLapValid = 1;
          if ( this->t < v7 || !v7 )
            this->bestLap = v4;
          ++this->lapCount;
          v8 = 0;
          for ( this->lastLap = v4; v8 < this->lastLapSplits._Mylast - this->lastLapSplits._Myfirst; ++v8 )
          {
            if ( v8 )
            {
              if ( v8 == this->lastLapSplits._Mylast - this->lastLapSplits._Myfirst - 1 )
                v9 = this->status._Myfirst->lastTime - this->status._Myfirst[v8].lastTime;
              else
                v9 = this->status._Myfirst[v8 + 1].lastTime - this->status._Myfirst[v8].lastTime;
              this->lastLapSplits._Myfirst[v8] = v9;
            }
            else
            {
              *this->lastLapSplits._Myfirst = this->status._Myfirst[1].lastTime;
            }
          }
          this->t = 0;
        }
        else
        {
          v10 = this->lapCount == 0;
          this->wasLastLapValid = 0;
          if ( v10 && this->isFirstLapArmed )
          {
            v11 = this->car;
            this->t = 0;
            this->cuts = 0;
            if ( v11->kers.present )
              Kers::reset(&v11->kers);
            v12 = this->car;
            if ( v12->ers.present )
              ERS::reset(&v12->ers);
          }
        }
        v13 = this->car;
        v14 = this->lastLap != 0;
        this->extInvalid = 0;
        PenaltyManager::decreasePitPenaltyLaps(&v13->penaltyManager, v14);
      }
    }
    else
    {
      Car::setBlackFlag(v6, 1, eSecsOnResult30);
      TimeTransponder::invalidate(this);
    }
  }
  else
  {
    v15 = this->status._Myfirst;
    if ( index == 1 )
      *this->currentSplits._Myfirst = v15[1].lastTime;
    else
      this->currentSplits._Myfirst[index - 1] = v15[index].lastTime - v15[index - 1].lastTime;
  }
}
void TimeTransponder::reset(TimeTransponder *this)
{
  TimeLineStatus *v2; // ecx
  TimeLineStatus *i; // eax
  unsigned int *v4; // ecx
  int v5; // edx
  unsigned int v6; // edi
  unsigned int *v7; // ecx
  int v8; // edx
  unsigned int v9; // edi
  __int64 v10; // [esp+8h] [ebp-Ch]

  this->t = 0;
  this->lapCount = 0;
  this->lastLap = 0;
  this->bestLap = 0;
  this->cuts = 0;
  this->extInvalid = 0;
  v2 = this->status._Mylast;
  for ( i = this->status._Myfirst; i != v2; ++i )
  {
    LOBYTE(v10) = 0;
    HIDWORD(v10) = 0;
    *(_QWORD *)&i->isValid = (unsigned int)v10;
    i->lastTime = 0;
  }
  v4 = this->bestLapSplits._Myfirst;
  v5 = 0;
  v6 = (unsigned int)((char *)this->bestLapSplits._Mylast - (char *)v4 + 3) >> 2;
  if ( v4 > this->bestLapSplits._Mylast )
    v6 = 0;
  if ( v6 )
  {
    do
    {
      ++v5;
      *v4++ = 0;
    }
    while ( v5 != v6 );
  }
  v7 = this->lastLapSplits._Myfirst;
  v8 = 0;
  v9 = (unsigned int)((char *)this->lastLapSplits._Mylast - (char *)v7 + 3) >> 2;
  if ( v7 > this->lastLapSplits._Mylast )
    v9 = 0;
  if ( v9 )
  {
    do
    {
      ++v8;
      *v7++ = 0;
    }
    while ( v8 != v9 );
    this->openTrackState = NotStarted;
  }
  else
  {
    this->openTrackState = NotStarted;
  }
}
void TimeTransponder::split(TimeTransponder *this, int sectorIndex)
{
  Car *v2; // ebx
  unsigned int *v3; // eax
  std::pair<void *,std::function<void __cdecl(OnSectorSplitEvent const &)> > *v4; // esi
  std::_Func_base<void,OnSectorSplitEvent const &> **v5; // edi
  OnSectorSplitEvent ev; // [esp+8h] [ebp-14h] BYREF

  v2 = this->car;
  ev.carIndex = v2->physicsGUID;
  v3 = this->currentSplits._Myfirst;
  ev.sectorIndex = sectorIndex;
  ev.sectorTime = v3[sectorIndex];
  ev.cuts = this->cuts;
  v4 = v2->evOnSectorSplit.handlers._Myfirst;
  if ( v4 != v2->evOnSectorSplit.handlers._Mylast )
  {
    v5 = &v4->second._Impl;
    do
    {
      if ( !*v5 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x7541B7);
      }
      (*v5)->_Do_call(*v5, &ev);
      ++v4;
      v5 += 8;
    }
    while ( v4 != v2->evOnSectorSplit.handlers._Mylast );
  }
}
void TimeTransponder::step(TimeTransponder *this, float dt)
{
  Car *v3; // eax
  int v4; // ebp
  Track *v5; // edi
  TimeLine *v6; // esi
  TimeLine *i; // edi
  const vec3f *v8; // eax
  TimeLineStatus *v9; // eax
  int v10; // edx
  TimeLineStatus *v11; // ecx
  PhysicsEngine *v12; // ecx
  __m128i v13; // xmm0
  bool v14; // zf
  int v15; // [esp+10h] [ebp-38h]
  TimeLineStatus *v16; // [esp+14h] [ebp-34h]
  bool isvalid; // [esp+18h] [ebp-30h]
  vec3f result; // [esp+1Ch] [ebp-2Ch] BYREF
  SessionInfo sessionInfo; // [esp+28h] [ebp-20h]

  v3 = this->car;
  v4 = 0;
  this->finishLinePassed = 0;
  v5 = v3->ksPhysics->track;
  v6 = v5->timeLines._Myfirst;
  for ( i = v5->timeLines._Mylast; v6 != i; ++v4 )
  {
    v8 = Tyre::getWorldPosition(this->car->tyres, &result);
    v15 = TimeLine::check(v6, v8);
    v9 = TimeTransponder::getStatus(this, v4);
    v10 = v15;
    v11 = v9;
    v16 = v9;
    if ( v15 == 2 && v9->lastResponse == eNegativeSide )
    {
      if ( this->isOpenTrack )
      {
        if ( v6->type == Skinned )
        {
          this->openTrackState = Started;
          this->cuts = 0;
          this->t = 0;
          this->extInvalid = 0;
        }
        else if ( v6->type == Particle )
        {
          TimeTransponder::onTimeLinePassed(this, v4, 1);
          TimeTransponder::lap(this, 1);
          v11 = v16;
          v10 = 2;
          this->openTrackState = NotStarted;
        }
      }
      else if ( v6->type == Default )
      {
        TimeTransponder::onTimeLinePassed(this, v4, v4 == 0);
        if ( !this->wasLastLapValid || (isvalid = 1, !TimeTransponder::isValid(this)) )
          isvalid = 0;
        if ( v4 )
          TimeTransponder::split(this, v4 - 1);
        else
          TimeTransponder::lap(this, isvalid);
        v11 = v16;
        v10 = 2;
      }
    }
    ++v6;
    v11->lastResponse = v10;
  }
  v12 = this->car->ksPhysics;
  v13 = _mm_loadu_si128((const __m128i *)&v12->sessionInfo.timeSecs);
  *(__m128i *)&sessionInfo.type = _mm_loadu_si128((const __m128i *)&v12->sessionInfo);
  *(__m128i *)&sessionInfo.timeSecs = v13;
  if ( _mm_cvtsi128_si32(*(__m128i *)&sessionInfo.type) != 3 || sessionInfo.startTimeMS - v12->physicsTime <= 0.0 )
  {
    v14 = !this->isOpenTrack;
    this->t = (unsigned int)((double)this->t + 3.0);
    if ( !v14 && this->openTrackState == NotStarted )
    {
      this->cuts = 0;
      this->t = 0;
    }
  }
}
