#include "racetimingservices.h
void RaceTimingServices::RaceTimingServices(RaceTimingServices *this, Sim *asim)
{
  std::_Tree_node<std::pair<CarAvatar * const,Lap>,void *> *v3; // eax
  Event<OnNewSessionEvent> *v4; // ecx
  unsigned int i; // esi
  CarAvatar *v6; // edi
  std::wstring v7; // [esp-1Ch] [ebp-44h] BYREF
  Game *v8; // [esp-4h] [ebp-2Ch]
  RaceTimingServices *v9; // [esp+18h] [ebp-10h]
  int v10; // [esp+24h] [ebp-4h]

  v9 = this;
  v8 = asim->game;
  v7._Myres = 7;
  v7._Mysize = 0;
  v7._Bx._Buf[0] = 0;
  std::wstring::assign(&v7, L"RACE_TIMING_SERVICE", 0x13u);
  GameObject::GameObject(this, v7, v8);
  this->__vftable = (RaceTimingServices_vtbl *)&RaceTimingServices::`vftable';
  v10 = 0;
  this->lapDBs._Myfirst = 0;
  this->lapDBs._Mylast = 0;
  this->lapDBs._Myend = 0;
  this->leaderboard._Myfirst = 0;
  this->leaderboard._Mylast = 0;
  this->leaderboard._Myend = 0;
  LOBYTE(v10) = 2;
  this->instanceBestTimes._Myhead = 0;
  this->instanceBestTimes._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<CarAvatar * const,Lap>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,TagDocumentText>> > *)&this->instanceBestTimes);
  this->instanceBestTimes._Myhead = v3;
  this->bestSplits._Myfirst = 0;
  this->bestSplits._Mylast = 0;
  this->bestSplits._Myend = 0;
  v8 = (Game *)this;
  this->globalBestlap = 0;
  this->sim = asim;
  v7._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_aba674e0e7decd065f55cc1ff64dacb4_,0>,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>,void,OnNewSessionEvent const &>::`vftable';
  *(_DWORD *)&v7._Bx._Alias[4] = this;
  v7._Mysize = (unsigned int)&v7;
  v4 = &this->sim->evOnNewSession;
  LOBYTE(v10) = 4;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v4,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v7,
    v8);
  for ( i = 0; i < this->sim->cars._Mylast - this->sim->cars._Myfirst; ++i )
  {
    v6 = Sim::getCar(this->sim, i);
    RaceTimingServices::getLapDB(this, v6);
    v7._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_26946f792b50d43e9d635487129478af_,0>,std::allocator<std::_Func_class<void,OnSectorSplitEvent const &>>,void,OnSectorSplitEvent const &>::`vftable';
    *(_DWORD *)&v7._Bx._Alias[4] = this;
    v7._Mysize = (unsigned int)&v7;
    LOBYTE(v10) = 4;
    Event<float>::addHandler(
      (Event<SessionInfo> *)&v6->evOnSectorSplit,
      (std::function<void __cdecl(SessionInfo const &)>)v7,
      this);
  }
  RaceTimingServices::updateLeaderboard(this);
}
void RaceTimingServices::~RaceTimingServices(RaceTimingServices *this)
{
  unsigned int v2; // edi
  LapDB **v3; // eax
  LapDB *v4; // ebx
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CarAvatar * const,Lap> > > > result; // [esp+10h] [ebp-4h] BYREF

  v2 = 0;
  for ( this->__vftable = (RaceTimingServices_vtbl *)&RaceTimingServices::`vftable';
        v2 < this->lapDBs._Mylast - this->lapDBs._Myfirst;
        ++v2 )
  {
    v3 = this->lapDBs._Myfirst;
    v4 = v3[v2];
    if ( v4 )
    {
      LapDB::~LapDB(v3[v2]);
      operator delete(v4);
    }
  }
  std::_Container_base0::_Orphan_all(&this->lapDBs);
  this->lapDBs._Mylast = this->lapDBs._Myfirst;
  std::_Container_base0::_Orphan_all(&this->leaderboard);
  this->leaderboard._Mylast = this->leaderboard._Myfirst;
  if ( this->bestSplits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->bestSplits);
    operator delete(this->bestSplits._Myfirst);
    this->bestSplits._Myfirst = 0;
    this->bestSplits._Mylast = 0;
    this->bestSplits._Myend = 0;
  }
  std::_Tree<std::_Tmap_traits<CarAvatar *,Lap,std::less<CarAvatar *>,std::allocator<std::pair<CarAvatar * const,Lap>>,0>>::erase(
    &this->instanceBestTimes,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CarAvatar * const,Lap> > > >)this->instanceBestTimes._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<CarAvatar * const,Lap> > > >)this->instanceBestTimes._Myhead);
  operator delete(this->instanceBestTimes._Myhead);
  if ( this->leaderboard._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->leaderboard);
    operator delete(this->leaderboard._Myfirst);
    this->leaderboard._Myfirst = 0;
    this->leaderboard._Mylast = 0;
    this->leaderboard._Myend = 0;
  }
  if ( this->lapDBs._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->lapDBs);
    operator delete(this->lapDBs._Myfirst);
    this->lapDBs._Myfirst = 0;
    this->lapDBs._Mylast = 0;
    this->lapDBs._Myend = 0;
  }
  GameObject::~GameObject(this);
}
RaceTimingServices *RaceTimingServices::`vector deleting destructor'(RaceTimingServices *this, unsigned int a2)
{
  RaceTimingServices::~RaceTimingServices(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
Lap *RaceTimingServices::getBestLap(RaceTimingServices *this, Lap *result, CarAvatar *car)
{
  LapDB *v3; // esi

  v3 = RaceTimingServices::getLapDB(this, car);
  result->time = v3->bestLap.time;
  std::vector<Mesh *>::vector<Mesh *>(
    (std::vector<TyreThermalPatch *> *)&result->splits,
    (const std::vector<TyreThermalPatch *> *)&v3->bestLap.splits);
  result->cuts = v3->bestLap.cuts;
  result->isValid = v3->bestLap.isValid;
  result->compound._Myres = 7;
  result->compound._Mysize = 0;
  result->compound._Bx._Buf[0] = 0;
  std::wstring::assign(&result->compound, &v3->bestLap.compound, 0, 0xFFFFFFFF);
  return result;
}
unsigned int RaceTimingServices::getBestSplit(RaceTimingServices *this, const int *sector, const bool *isGlobal, CarAvatar *car)
{
  unsigned int v5; // edi
  LapDB *v7; // eax
  int v8; // ebx

  v5 = *sector;
  if ( *sector < this->sim->track->physicsTrack.sectorsNormalizedPositions._Mylast
               - this->sim->track->physicsTrack.sectorsNormalizedPositions._Myfirst )
  {
    if ( *isGlobal )
    {
      if ( v5 < this->bestSplits._Mylast - this->bestSplits._Myfirst )
        return this->bestSplits._Myfirst[v5];
    }
    else
    {
      v7 = RaceTimingServices::getLapDB(this, car);
      if ( *sector < (unsigned int)(v7->personalBestSplits._Mylast - v7->personalBestSplits._Myfirst) )
      {
        v8 = *sector;
        return RaceTimingServices::getLapDB(this, car)->personalBestSplits._Myfirst[v8];
      }
    }
  }
  return 0;
}
int RaceTimingServices::getCarLeaderboardPosition(RaceTimingServices *this, CarAvatar *car)
{
  LeaderboardEntry *v2; // eax
  int v3; // edx
  LeaderboardEntry *v4; // ecx

  v2 = this->leaderboard._Myfirst;
  v3 = 1;
  v4 = this->leaderboard._Mylast;
  if ( v2 == v4 )
    return -1;
  while ( car != v2->car )
  {
    ++v2;
    ++v3;
    if ( v2 == v4 )
      return -1;
  }
  return v3;
}
void RaceTimingServices::getCurrentLapSplits(RaceTimingServices *this, CarAvatar *car, std::vector<unsigned int> *currentSplits)
{
  LapDB *v3; // eax

  v3 = RaceTimingServices::getLapDB(this, car);
  std::vector<int>::operator=(currentSplits, &v3->currentSplits);
}
bool RaceTimingServices::getHasCompletedFlag(RaceTimingServices *this, CarAvatar *car)
{
  return RaceTimingServices::getLapDB(this, car)->hasCompletedLastLap;
}
CarAvatar *RaceTimingServices::getInstanceBestTime(RaceTimingServices *this, CarAvatar *car)
{
  return *std::map<CarAvatar *,Lap>::operator[](&this->instanceBestTimes, &car);
}
int RaceTimingServices::getLapCount(RaceTimingServices *this, CarAvatar *car)
{
  LapDB *v2; // eax

  v2 = RaceTimingServices::getLapDB(this, car);
  return v2->laps._Mylast - v2->laps._Myfirst;
}
LapDB *RaceTimingServices::getLapDB(RaceTimingServices *this, CarAvatar *car)
{
  unsigned int v3; // esi
  LapDB *v4; // esi
  LapDB *result; // eax
  LapDB *v6; // eax
  LapDB *v7; // eax
  std::wstring *v8; // eax
  LapDB *db; // [esp+10h] [ebp-2Ch] BYREF
  std::wstring v10; // [esp+14h] [ebp-28h] BYREF
  int v11; // [esp+38h] [ebp-4h]

  if ( car
    && CarAvatar::getGuid(car) >= 0
    && (v3 = this->sim->cars._Mylast - this->sim->cars._Myfirst, CarAvatar::getGuid(car) < v3) )
  {
    v4 = (LapDB *)this->lapDBs._Mylast;
    std::find_if<std::_Vector_iterator<std::_Vector_val<std::_Simple_types<LapDB *>>>,_lambda_7c544edf6e1913ee9bc9dbefa47405ac_>(
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<LapDB *> > > *)&db,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<LapDB *> > >)this->lapDBs._Myfirst,
      (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<LapDB *> > >)v4,
      (RaceTimingServices::getLapDB::__l6::<lambda_7c544edf6e1913ee9bc9dbefa47405ac>)car);
    if ( db == v4 )
    {
      v6 = (LapDB *)operator new(112);
      db = v6;
      v11 = 0;
      if ( v6 )
        LapDB::LapDB(v6, car);
      else
        v7 = 0;
      db = v7;
      v11 = -1;
      std::vector<SpinnerData *>::push_back(
        (std::vector<ICollisionObject *> *)&this->lapDBs,
        (ICollisionObject *const *)&db);
      result = db;
    }
    else
    {
      result = (LapDB *)LODWORD(db->totalTime);
    }
  }
  else
  {
    v10._Myres = 7;
    v10._Mysize = 0;
    v10._Bx._Buf[0] = 0;
    std::wstring::assign(&v10, L"RaceTimingServices CRITICAL ERROR! INVALID GUID CAR REQUESTED", 0x3Du);
    v8 = &v10;
    v11 = 1;
    if ( v10._Myres >= 8 )
      v8 = (std::wstring *)v10._Bx._Ptr;
    _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v8->_Bx._Buf);
    ksGenerateCrash();
    if ( v10._Myres >= 8 )
      operator delete(v10._Bx._Ptr);
    result = 0;
  }
  return result;
}
std::vector<Lap> *RaceTimingServices::getLaps(RaceTimingServices *this, std::vector<Lap> *result, CarAvatar *car)
{
  LapDB *v3; // eax

  v3 = RaceTimingServices::getLapDB(this, car);
  std::vector<Lap>::vector<Lap>(result, &v3->laps);
  return result;
}
Lap *RaceTimingServices::getLastLap(RaceTimingServices *this, Lap *result, CarAvatar *car)
{
  LapDB *v3; // eax
  Lap *v4; // eax
  Lap *v5; // esi

  v3 = RaceTimingServices::getLapDB(this, car);
  if ( v3->laps._Myfirst == v3->laps._Mylast )
  {
    v4 = result;
    result->splits._Myfirst = 0;
    result->splits._Mylast = 0;
    result->splits._Myend = 0;
    result->compound._Myres = 7;
    result->compound._Mysize = 0;
    result->compound._Bx._Buf[0] = 0;
    result->time = 0;
    result->isValid = 0;
    result->cuts = 0;
  }
  else
  {
    v5 = v3->laps._Mylast;
    result->time = v5[-1].time;
    std::vector<Mesh *>::vector<Mesh *>(
      (std::vector<TyreThermalPatch *> *)&result->splits,
      (const std::vector<TyreThermalPatch *> *)&v5[-1].splits);
    result->cuts = v5[-1].cuts;
    result->isValid = v5[-1].isValid;
    result->compound._Myres = 7;
    result->compound._Mysize = 0;
    result->compound._Bx._Buf[0] = 0;
    std::wstring::assign(&result->compound, &v5[-1].compound, 0, 0xFFFFFFFF);
    v4 = result;
  }
  return v4;
}
unsigned int RaceTimingServices::getLastSplit(RaceTimingServices *this, CarAvatar *car, const int *sector)
{
  LapDB *v4; // eax
  Lap *v5; // esi
  unsigned int v6; // esi
  std::vector<Lap> result; // [esp+10h] [ebp-50h] BYREF
  Lap l; // [esp+20h] [ebp-40h] BYREF
  int v10; // [esp+5Ch] [ebp-4h]

  v4 = RaceTimingServices::getLapDB(this, car);
  if ( v4->laps._Mylast - v4->laps._Myfirst > 0 )
  {
    v5 = RaceTimingServices::getLaps(this, &result, car)->_Mylast;
    v10 = 0;
    l.time = v5[-1].time;
    std::vector<Mesh *>::vector<Mesh *>(
      (std::vector<TyreThermalPatch *> *)&l.splits,
      (const std::vector<TyreThermalPatch *> *)&v5[-1].splits);
    l.cuts = v5[-1].cuts;
    l.isValid = v5[-1].isValid;
    LOBYTE(v10) = 1;
    l.compound._Myres = 7;
    l.compound._Mysize = 0;
    l.compound._Bx._Buf[0] = 0;
    std::wstring::assign(&l.compound, &v5[-1].compound, 0, 0xFFFFFFFF);
    v10 = -1;
    if ( result._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&result);
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(result._Myfirst, result._Mylast);
      operator delete(result._Myfirst);
    }
    if ( *sector < (unsigned int)(l.splits._Mylast - l.splits._Myfirst) )
    {
      v6 = l.splits._Myfirst[*sector];
      Lap::~Lap(&l);
      return v6;
    }
    Lap::~Lap(&l);
  }
  return 0;
}
std::vector<LeaderboardEntry> *RaceTimingServices::getLeaderboard(RaceTimingServices *this, std::vector<LeaderboardEntry> *result)
{
  std::vector<LeaderboardEntry>::vector<LeaderboardEntry>(result, &this->leaderboard);
  return result;
}
unsigned int RaceTimingServices::getSplit(RaceTimingServices *this, CarAvatar *car, const int *sector)
{
  LapDB *v3; // eax
  unsigned int result; // eax

  v3 = RaceTimingServices::getLapDB(this, car);
  if ( *sector >= (unsigned int)(v3->currentSplits._Mylast - v3->currentSplits._Myfirst) )
    result = 0;
  else
    result = v3->currentSplits._Myfirst[*sector];
  return result;
}
int RaceTimingServices::getSplit(RaceTimingServices *this, CarAvatar *car)
{
  return RaceTimingServices::getLapDB(this, car)->bestLapSplit;
}
long double RaceTimingServices::getTotalTime(RaceTimingServices *this, CarAvatar *car)
{
  return RaceTimingServices::getLapDB(this, car)->totalTime;
}
bool RaceTimingServices::isBestSplit(RaceTimingServices *this, const int *sector, const int *t, const bool *isGlobal, CarAvatar *car)
{
  int v6; // esi

  if ( !*t )
    return 0;
  if ( *isGlobal )
    return this->bestSplits._Myfirst[*sector] == *t;
  v6 = *sector;
  return RaceTimingServices::getLapDB(this, car)->personalBestSplits._Myfirst[v6] == *t;
}
void RaceTimingServices::onLapCompleted(RaceTimingServices *this, const OnLapCompletedEvent *event)
{
  CarAvatar *v3; // eax
  LapDB *v4; // eax
  LapDB *v5; // edi
  int v6; // ecx
  Sim *v7; // ecx
  bool v8; // zf
  CarAvatar *v9; // eax
  std::wstring *v10; // esi
  int i; // edx
  unsigned int v12; // ecx
  unsigned int *v13; // ecx
  unsigned int *v14; // edx
  unsigned int *v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // eax
  unsigned int v18; // ecx
  CarAvatar *const *v19; // eax
  CarAvatar **v20; // esi
  unsigned int v21; // [esp-8h] [ebp-78h]
  ICollisionObject *_Val; // [esp+14h] [ebp-5Ch] BYREF
  Lap lap; // [esp+18h] [ebp-58h] BYREF
  std::wstring result; // [esp+48h] [ebp-28h] BYREF
  int v25; // [esp+6Ch] [ebp-4h]

  if ( !event->isValid )
    return;
  v3 = Sim::getCar(this->sim, event->carIndex);
  v4 = RaceTimingServices::getLapDB(this, v3);
  v5 = v4;
  if ( v4->hasCompletedLastLap )
  {
    v6 = (char *)v4->laps._Mylast - (char *)v4->laps._Myfirst;
    _printf(
      "Ignoring lap %d from car %d because the session is over\n",
      ((int)((unsigned __int64)(715827883i64 * v6) >> 32) >> 3)
    + ((unsigned int)((unsigned __int64)(715827883i64 * v6) >> 32) >> 31)
    + 1,
      event->carIndex);
    return;
  }
  lap.splits._Myfirst = 0;
  lap.splits._Mylast = 0;
  lap.splits._Myend = 0;
  lap.compound._Myres = 7;
  lap.compound._Mysize = 0;
  lap.compound._Bx._Buf[0] = 0;
  v7 = this->sim;
  v25 = 0;
  lap.time = event->lapTime;
  v8 = event->cuts == 0;
  lap.cuts = event->cuts;
  v21 = event->carIndex;
  lap.isValid = v8;
  v9 = Sim::getCar(v7, v21);
  v10 = CarAvatar::getCurrentCompoundShortName(v9, &result);
  if ( &lap.compound != v10 )
  {
    lap.compound._Myres = 7;
    lap.compound._Mysize = 0;
    lap.compound._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&lap.compound, v10);
  }
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  if ( this->bestSplits._Myfirst != this->bestSplits._Mylast )
  {
    _Val = 0;
    std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&v5->currentSplits, &_Val);
    for ( i = 0;
          i < this->sim->track->physicsTrack.sectorsNormalizedPositions._Mylast
            - this->sim->track->physicsTrack.sectorsNormalizedPositions._Myfirst
            - 1;
          *(v5->currentSplits._Mylast - 1) += v12 )
    {
      v12 = v5->currentSplits._Myfirst[i++];
    }
    *(v5->currentSplits._Mylast - 1) = event->lapTime - *(v5->currentSplits._Mylast - 1);
    if ( !lap.isValid )
      goto LABEL_19;
    v13 = this->bestSplits._Mylast;
    if ( *(v13 - 1) && (v14 = v5->currentSplits._Mylast, *(v13 - 1) <= *(v14 - 1)) )
    {
      v15 = v5->personalBestSplits._Mylast;
      if ( *(v15 - 1) && *(v15 - 1) <= *(v14 - 1) )
        goto LABEL_19;
      v16 = *(v14 - 1);
    }
    else
    {
      *(v13 - 1) = *(v5->currentSplits._Mylast - 1);
      v15 = v5->personalBestSplits._Mylast;
      v16 = *(v5->currentSplits._Mylast - 1);
    }
    *(v15 - 1) = v16;
LABEL_19:
    std::vector<int>::operator=(&lap.splits, &v5->currentSplits);
  }
  v5->bestLapSplit = event->lapTime - v5->bestLap.time;
  std::vector<Lap>::push_back(&v5->laps, &lap);
  v5->totalTime = (double)event->lapTime + v5->totalTime;
  if ( !event->cuts )
  {
    v17 = v5->bestLap.time;
    if ( !v17 || lap.time < v17 )
    {
      v5->bestLap.time = lap.time;
      std::vector<int>::operator=(&v5->bestLap.splits, &lap.splits);
      v5->bestLap.cuts = lap.cuts;
      v5->bestLap.isValid = lap.isValid;
      if ( &v5->bestLap.compound != &lap.compound )
        std::wstring::assign(&v5->bestLap.compound, &lap.compound, 0, 0xFFFFFFFF);
      v18 = this->globalBestlap;
      if ( !v18 || v18 > lap.time )
        this->globalBestlap = lap.time;
    }
    if ( !event->cuts )
    {
      _Val = (ICollisionObject *)Sim::getCar(this->sim, event->carIndex);
      if ( !*std::map<CarAvatar *,Lap>::operator[](&this->instanceBestTimes, (CarAvatar *const *)&_Val)
        || (_Val = (ICollisionObject *)Sim::getCar(this->sim, event->carIndex),
            v19 = std::map<CarAvatar *,Lap>::operator[](&this->instanceBestTimes, (CarAvatar *const *)&_Val),
            (CarAvatar *const)lap.time < *v19) )
      {
        _Val = (ICollisionObject *)Sim::getCar(this->sim, event->carIndex);
        v20 = (CarAvatar **)std::map<CarAvatar *,Lap>::operator[](&this->instanceBestTimes, (CarAvatar *const *)&_Val);
        *v20 = (CarAvatar *)lap.time;
        std::vector<int>::operator=((std::vector<unsigned int> *)(v20 + 1), &lap.splits);
        v20[4] = (CarAvatar *)lap.cuts;
        *((_BYTE *)v20 + 20) = lap.isValid;
        if ( v20 + 6 != (CarAvatar **)&lap.compound )
          std::wstring::assign((std::wstring *)v20 + 1, &lap.compound, 0, 0xFFFFFFFF);
      }
    }
  }
  std::_Container_base0::_Orphan_all(&v5->currentSplits);
  v5->currentSplits._Mylast = v5->currentSplits._Myfirst;
  v5->lastLapStartTime = (unsigned int)event->eventTime;
  RaceTimingServices::updateLeaderboard(this);
  v25 = -1;
  if ( lap.compound._Myres >= 8 )
    operator delete(lap.compound._Bx._Ptr);
  lap.compound._Myres = 7;
  lap.compound._Mysize = 0;
  lap.compound._Bx._Buf[0] = 0;
  if ( lap.splits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&lap.splits);
    operator delete(lap.splits._Myfirst);
  }
}
void RaceTimingServices::onNewSession(RaceTimingServices *this, const OnNewSessionEvent *message)
{
  unsigned int i; // edi
  unsigned int v4; // esi
  Sim *v5; // ecx
  CarAvatar *v6; // eax

  for ( i = 0; i < this->lapDBs._Mylast - this->lapDBs._Myfirst; ++i )
    LapDB::reset(this->lapDBs._Myfirst[i]);
  std::_Container_base0::_Orphan_all(&this->lapDBs);
  v4 = 0;
  this->lapDBs._Mylast = this->lapDBs._Myfirst;
  v5 = this->sim;
  if ( v5->cars._Mylast - v5->cars._Myfirst )
  {
    do
    {
      v6 = Sim::getCar(v5, v4);
      RaceTimingServices::getLapDB(this, v6);
      v5 = this->sim;
      ++v4;
    }
    while ( v4 < v5->cars._Mylast - v5->cars._Myfirst );
  }
  RaceTimingServices::updateLeaderboard(this);
}
void RaceTimingServices::onSectorSplit(RaceTimingServices *this, const OnSectorSplitEvent *event)
{
  CarAvatar *v4; // eax
  LapDB *v5; // eax
  unsigned int v6; // edx
  std::vector<ICollisionObject *> *v7; // esi
  ICollisionObject **v8; // eax
  int v9; // edi
  ICollisionObject **v10; // ecx
  ICollisionObject **v11; // eax
  unsigned int *v12; // eax
  unsigned int v13; // ecx
  unsigned int *v14; // ebp
  unsigned int v15; // edi
  ICollisionObject *v16; // edx
  unsigned int v17; // eax
  unsigned int v18; // esi
  int v19; // [esp+10h] [ebp-4h] BYREF
  const OnSectorSplitEvent *eventa; // [esp+18h] [ebp+4h]

  v4 = Sim::getCar(this->sim, event->carIndex);
  v5 = RaceTimingServices::getLapDB(this, v4);
  v6 = event->sectorIndex;
  v7 = (std::vector<ICollisionObject *> *)&v5->currentSplits;
  eventa = (const OnSectorSplitEvent *)v5;
  if ( v6 >= v5->currentSplits._Mylast - v5->currentSplits._Myfirst )
  {
    if ( v6 != v5->currentSplits._Mylast - v5->currentSplits._Myfirst )
    {
      v19 = 0;
      do
      {
        v8 = v7->_Mylast;
        if ( &v19 >= (int *)v8 || v7->_Myfirst > (ICollisionObject **)&v19 )
        {
          if ( v8 == v7->_Myend )
            std::vector<SVar *>::_Reserve(v7, 1u);
          v11 = v7->_Mylast;
          if ( v11 )
            *v11 = 0;
        }
        else
        {
          v9 = ((char *)&v19 - (char *)v7->_Myfirst) >> 2;
          if ( v8 == v7->_Myend )
            std::vector<SVar *>::_Reserve(v7, 1u);
          v10 = v7->_Mylast;
          if ( v10 )
            *v10 = v7->_Myfirst[v9];
        }
        ++v7->_Mylast;
      }
      while ( event->sectorIndex != v7->_Mylast - v7->_Myfirst );
    }
    std::vector<SpinnerData *>::push_back(v7, (ICollisionObject *const *)&event->sectorTime);
  }
  else
  {
    v7->_Myfirst[v6] = (ICollisionObject *)event->sectorTime;
  }
  v12 = this->bestSplits._Myfirst;
  if ( v12 != this->bestSplits._Mylast && !event->cuts )
  {
    v13 = event->sectorIndex;
    v14 = this->bestSplits._Myfirst;
    v15 = v12[v13];
    if ( v15 && (v16 = v7->_Myfirst[v13], v15 <= (unsigned int)v16) )
    {
      v17 = eventa[5].sectorTime;
      v18 = *(_DWORD *)(v17 + 4 * v13);
      if ( !v18 || v18 > (unsigned int)v16 )
        *(_DWORD *)(v17 + 4 * v13) = v16;
    }
    else
    {
      v14[v13] = (unsigned int)v7->_Myfirst[v13];
      *(_DWORD *)(eventa[5].sectorTime + 4 * event->sectorIndex) = v7->_Myfirst[event->sectorIndex];
    }
  }
}
void RaceTimingServices::resetCurrentLaps(RaceTimingServices *this)
{
  Sim *v2; // eax
  Sim *v3; // ecx
  unsigned int v4; // ebx
  Sim *v5; // ecx
  CarAvatar *v6; // eax
  std::vector<unsigned int> *v7; // esi
  unsigned int *v8; // eax
  CarAvatar *v9; // eax
  LapDB *v10; // esi
  int v11; // [esp-8h] [ebp-40h]
  unsigned int v12; // [esp-8h] [ebp-40h]
  unsigned int _Pval; // [esp+10h] [ebp-28h] BYREF
  std::vector<unsigned int> v14; // [esp+14h] [ebp-24h] BYREF
  std::vector<unsigned int> v15; // [esp+20h] [ebp-18h] BYREF
  int v16; // [esp+34h] [ebp-4h]

  v2 = this->sim;
  _Pval = 0;
  v11 = v2->track->physicsTrack.sectorsNormalizedPositions._Mylast
      - v2->track->physicsTrack.sectorsNormalizedPositions._Myfirst;
  v15._Myfirst = 0;
  v15._Mylast = 0;
  v15._Myend = 0;
  std::vector<unsigned int>::_Construct_n(&v15, v11, &_Pval);
  v16 = 0;
  std::vector<WingState>::operator=((std::vector<WingState> *)&this->bestSplits, (std::vector<WingState> *)&v15);
  v16 = -1;
  if ( v15._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&v15);
    operator delete(v15._Myfirst);
  }
  v3 = this->sim;
  v4 = 0;
  this->globalBestlap = 0;
  if ( v3->cars._Mylast - v3->cars._Myfirst )
  {
    _Pval = 0;
    do
    {
      v12 = this->sim->track->physicsTrack.sectorsNormalizedPositions._Mylast
          - this->sim->track->physicsTrack.sectorsNormalizedPositions._Myfirst;
      v14._Myfirst = 0;
      v14._Mylast = 0;
      v14._Myend = 0;
      std::vector<unsigned int>::_Construct_n(&v14, v12, &_Pval);
      v5 = this->sim;
      v16 = 1;
      v6 = Sim::getCar(v5, v4);
      v7 = &RaceTimingServices::getLapDB(this, v6)->personalBestSplits;
      if ( v7 == &v14 )
      {
        v8 = v14._Myfirst;
      }
      else
      {
        if ( v7->_Myfirst )
        {
          std::_Container_base0::_Orphan_all(v7);
          operator delete(v7->_Myfirst);
          v7->_Myfirst = 0;
          v7->_Mylast = 0;
          v7->_Myend = 0;
        }
        std::_Container_base0::_Swap_all(v7, &v14);
        *v7 = v14;
        v8 = 0;
        v14._Myfirst = 0;
        v14._Mylast = 0;
        v14._Myend = 0;
      }
      v16 = -1;
      if ( v8 )
      {
        std::_Container_base0::_Orphan_all(&v14);
        operator delete(v14._Myfirst);
        v14._Myfirst = 0;
        v14._Mylast = 0;
        v14._Myend = 0;
      }
      v9 = Sim::getCar(this->sim, v4);
      v10 = RaceTimingServices::getLapDB(this, v9);
      std::_Container_base0::_Orphan_all(&v10->currentSplits);
      ++v4;
      v10->currentSplits._Mylast = v10->currentSplits._Myfirst;
    }
    while ( v4 < this->sim->cars._Mylast - this->sim->cars._Myfirst );
  }
}
void RaceTimingServices::setHasCompletedFlag(RaceTimingServices *this, CarAvatar *car, bool flag)
{
  RaceTimingServices::getLapDB(this, car)->hasCompletedLastLap = flag;
}
void RaceTimingServices::shutdown(RaceTimingServices *this)
{
  GameObject *v2; // ebx
  GameObject **v3; // esi
  int v4; // edi
  _DWORD *v5; // esi
  CarAvatar *v6; // eax
  LapDB *v7; // ebp
  std::wstring *v8; // eax
  std::ostream *v9; // eax
  std::ostream *v10; // eax
  Lap *v11; // esi
  int v12; // ebx
  Lap *i; // edi
  std::ostream *v14; // eax
  int v15; // eax
  int v16; // ebp
  int v17; // esi
  int j; // edi
  std::ostream *v19; // eax
  std::ostream *v20; // eax
  std::ostream *v21; // eax
  std::ostream *v22; // eax
  int v23; // eax
  std::ostream *v24; // eax
  int v25; // eax
  unsigned int v26; // ebx
  unsigned int *k; // ecx
  std::ostream *v28; // eax
  std::ostream *v29; // eax
  std::ostream *v30; // eax
  int v31; // eax
  _BYTE *v32; // esi
  FILE *v33; // ecx
  const char *v34; // [esp+4h] [ebp-140h]
  int v35; // [esp+8h] [ebp-13Ch]
  unsigned int v36; // [esp+Ch] [ebp-138h]
  int v37; // [esp+Ch] [ebp-138h]
  unsigned int v38; // [esp+Ch] [ebp-138h]
  int v39; // [esp+Ch] [ebp-138h]
  int v40; // [esp+14h] [ebp-130h]
  int v41; // [esp+14h] [ebp-130h]
  std::ostream _Ostr; // [esp+28h] [ebp-11Ch] BYREF
  int v43; // [esp+78h] [ebp-CCh]
  char v44; // [esp+7Ch] [ebp-C8h]
  FILE *v45; // [esp+80h] [ebp-C4h]
  int v46; // [esp+8Ch] [ebp-B8h] BYREF
  Lap l; // [esp+D4h] [ebp-70h] BYREF
  std::wstring result; // [esp+104h] [ebp-40h] BYREF
  std::wstring filename; // [esp+11Ch] [ebp-28h] BYREF
  int v50; // [esp+140h] [ebp-4h]

  v2 = this->game->root;
  v3 = v2->gameObjects._Myfirst;
  if ( v3 == v2->gameObjects._Mylast )
  {
LABEL_4:
    v4 = 0;
  }
  else
  {
    while ( 1 )
    {
      v4 = __RTDynamicCast(*v3, 0, &GameObject `RTTI Type Descriptor', &Sim `RTTI Type Descriptor', 0);
      if ( v4 )
        break;
      if ( ++v3 == v2->gameObjects._Mylast )
        goto LABEL_4;
    }
  }
  v5 = *(_DWORD **)(v4 + 40);
  if ( v5 != *(_DWORD **)(v4 + 44) )
  {
    while ( 1 )
    {
      v6 = (CarAvatar *)__RTDynamicCast(
                          *v5,
                          0,
                          &GameObject `RTTI Type Descriptor',
                          &CarAvatar `RTTI Type Descriptor',
                          0);
      if ( v6 )
        break;
      if ( ++v5 == *(_DWORD **)(v4 + 44) )
        return;
    }
    v7 = RaceTimingServices::getLapDB(this, v6);
    *(_DWORD *)_Ostr.gap0 = v7;
    v8 = Path::getDocumentPath(&result);
    v50 = 0;
    std::operator+<wchar_t>(&filename, v8, L"/Assetto Corsa/out/laps.ini");
    LOBYTE(v50) = 2;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Bx._Buf[0] = 0;
    result._Mysize = 0;
    std::ofstream::ofstream((std::ofstream *)&_Ostr.gap0[4], &filename, 2, 64, 1);
    LOBYTE(v50) = 3;
    v9 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[4], "[HEADER]");
    std::ostream::operator<<(v9);
    v10 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[4], "VERSION=2");
    std::ostream::operator<<(v10);
    v11 = v7->laps._Myfirst;
    v12 = 0;
    for ( i = v7->laps._Mylast; v11 != i; ++v11 )
    {
      l.time = v11->time;
      std::vector<Mesh *>::vector<Mesh *>(
        (std::vector<TyreThermalPatch *> *)&l.splits,
        (const std::vector<TyreThermalPatch *> *)&v11->splits);
      l.cuts = v11->cuts;
      l.isValid = v11->isValid;
      l.compound._Bx._Buf[0] = 0;
      LOBYTE(v50) = 4;
      l.compound._Myres = 7;
      l.compound._Mysize = 0;
      std::wstring::assign(&l.compound, &v11->compound, 0, 0xFFFFFFFF);
      LOBYTE(v50) = 3;
      if ( l.isValid )
        ++v12;
      if ( l.compound._Myres >= 8 )
        operator delete(l.compound._Bx._Ptr);
      l.compound._Myres = 7;
      l.compound._Mysize = 0;
      l.compound._Bx._Buf[0] = 0;
      if ( l.splits._Myfirst )
      {
        std::_Container_base0::_Orphan_all(&l.splits);
        operator delete(l.splits._Myfirst);
      }
    }
    v14 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[4], "LAPS=");
    v15 = std::ostream::operator<<(v14, v12, std::endl<char,std::char_traits<char>>);
    std::ostream::operator<<(v15);
    v16 = 0;
    v17 = *(_DWORD *)(*(_DWORD *)_Ostr.gap0 + 8);
    for ( j = *(_DWORD *)(*(_DWORD *)_Ostr.gap0 + 12); v17 != j; v17 += 48 )
    {
      l.time = *(_DWORD *)v17;
      std::vector<Mesh *>::vector<Mesh *>(
        (std::vector<TyreThermalPatch *> *)&l.splits,
        (const std::vector<TyreThermalPatch *> *)(v17 + 4));
      l.cuts = *(_DWORD *)(v17 + 16);
      l.isValid = *(_BYTE *)(v17 + 20);
      l.compound._Bx._Buf[0] = 0;
      LOBYTE(v50) = 5;
      l.compound._Myres = 7;
      l.compound._Mysize = 0;
      std::wstring::assign(&l.compound, (const std::wstring *)(v17 + 24), 0, 0xFFFFFFFF);
      LOBYTE(v50) = 6;
      if ( l.isValid )
      {
        std::ostream::operator<<(&_Ostr.gap0[4]);
        v19 = std::operator<<<std::char_traits<char>>(&_Ostr, "[LAP_");
        v20 = (std::ostream *)std::ostream::operator<<(v19, v16, "]");
        v21 = std::operator<<<std::char_traits<char>>(v20, (const char *)std::endl<char,std::char_traits<char>>);
        std::ostream::operator<<(v21);
        v36 = l.time;
        v22 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[4], "TIME=");
        v23 = std::ostream::operator<<(v22, v36, std::endl<char,std::char_traits<char>>, v40);
        std::ostream::operator<<(v23);
        v37 = l.splits._Mylast - l.splits._Myfirst;
        v24 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[4], "SPLITS=");
        v25 = std::ostream::operator<<(v24, v37, std::endl<char,std::char_traits<char>>, v41);
        std::ostream::operator<<(v25);
        v26 = 0;
        for ( k = l.splits._Myfirst; v26 < l.splits._Mylast - l.splits._Myfirst; k = l.splits._Myfirst )
        {
          v38 = k[v26];
          v28 = std::operator<<<std::char_traits<char>>((std::ostream *)&_Ostr.gap0[4], "SPLIT_");
          v29 = (std::ostream *)std::ostream::operator<<(v28, v26, "=", v38);
          v30 = std::operator<<<std::char_traits<char>>(v29, v34);
          v31 = std::ostream::operator<<(v30, v35, v39, std::endl<char,std::char_traits<char>>);
          std::ostream::operator<<(v31);
          ++v26;
        }
        ++v16;
      }
      else
      {
        k = l.splits._Myfirst;
      }
      LOBYTE(v50) = 3;
      if ( l.compound._Myres >= 8 )
      {
        operator delete(l.compound._Bx._Ptr);
        k = l.splits._Myfirst;
      }
      l.compound._Myres = 7;
      l.compound._Mysize = 0;
      l.compound._Bx._Buf[0] = 0;
      if ( k )
      {
        std::_Container_base0::_Orphan_all(&l.splits);
        operator delete(l.splits._Myfirst);
      }
    }
    v32 = &_Ostr.gap0[8];
    if ( v45 )
    {
      if ( !std::filebuf::_Endwrite((std::filebuf *)&_Ostr.gap0[8]) )
        v32 = 0;
      if ( _fclose(v45) )
        v32 = 0;
    }
    else
    {
      v32 = 0;
    }
    v44 = 0;
    _Ostr.gap0[77] = 0;
    std::streambuf::_Init(&_Ostr.gap0[8]);
    v45 = 0;
    v43 = `std::filebuf::_Init'::`2'::_Stinit;
    *(_DWORD *)&_Ostr.gap0[72] = 0;
    if ( !v32 )
      std::ios::setstate(&_Ostr.gap0[*(_DWORD *)(*(_DWORD *)&_Ostr.gap0[4] + 4) + 4], 2, 0);
    LOBYTE(v50) = 2;
    *(_DWORD *)&_Ostr.gap0[*(_DWORD *)(*(_DWORD *)&_Ostr.gap0[4] + 4) + 4] = &std::ofstream::`vftable';
    *(_DWORD *)&_Ostr.gap0[*(_DWORD *)(*(_DWORD *)&_Ostr.gap0[4] + 4)] = *(_DWORD *)(*(_DWORD *)&_Ostr.gap0[4] + 4) - 96;
    v33 = v45;
    *(_DWORD *)&_Ostr.gap0[8] = &std::filebuf::`vftable';
    if ( v45 && **(std::ostream ***)&_Ostr.gap0[20] == (std::ostream *)&_Ostr.gap0[76] )
    {
      std::streambuf::setg(
        &_Ostr.gap0[8],
        *(_DWORD *)&_Ostr.gap0[64],
        *(_DWORD *)&_Ostr.gap0[64],
        *(_DWORD *)&_Ostr.gap0[68]);
      v33 = v45;
    }
    if ( v44 )
    {
      if ( v33 )
      {
        std::filebuf::_Endwrite((std::filebuf *)&_Ostr.gap0[8]);
        _fclose(v45);
      }
      v44 = 0;
      _Ostr.gap0[77] = 0;
      std::streambuf::_Init(&_Ostr.gap0[8]);
      v45 = 0;
      v43 = `std::filebuf::_Init'::`2'::_Stinit;
      *(_DWORD *)&_Ostr.gap0[72] = 0;
    }
    std::streambuf::~streambuf<char,std::char_traits<char>>(&_Ostr.gap0[8]);
    std::ostream::~ostream<char,std::char_traits<char>>(&_Ostr.gap0[12]);
    std::ios::~ios<char,std::char_traits<char>>(&v46);
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
  }
}
void RaceTimingServices::update(RaceTimingServices *this, float dt)
{
  RaceTimingServices::updateLeaderboard(this);
}
void RaceTimingServices::updateLeaderboard(RaceTimingServices *this)
{
  RaceTimingServices *v1; // ebp
  std::vector<LeaderboardEntry> *v2; // ebx
  LapDB **v3; // esi
  LapDB **i; // edi
  LapDB *v5; // ebx
  int v6; // edx
  char v7; // cl
  unsigned int v8; // eax
  __int64 v9; // xmm1_8
  LeaderboardEntry *v10; // ecx
  bool v11; // zf
  int v12; // ebp
  __m128i *v13; // eax
  const __m128i *v14; // ebp
  __m128i *v15; // eax
  Session *v16; // [esp+14h] [ebp-9Ch]
  LapDB *v18; // [esp+1Ch] [ebp-94h]
  __m128i v19; // [esp+20h] [ebp-90h] BYREF
  __m128i v20; // [esp+30h] [ebp-80h] BYREF
  Session result; // [esp+40h] [ebp-70h] BYREF
  int v22; // [esp+ACh] [ebp-4h]

  v1 = this;
  v2 = &this->leaderboard;
  std::_Container_base0::_Orphan_all(&this->leaderboard);
  v2->_Mylast = v2->_Myfirst;
  v3 = v1->lapDBs._Myfirst;
  for ( i = v1->lapDBs._Mylast; v3 != i; ++v3 )
  {
    v5 = *v3;
    v18 = *v3;
    v16 = RaceManager::getCurrentSession(v1->sim->raceManager, &result);
    v6 = (unsigned __int64)(715827883i64 * ((char *)v5->laps._Mylast - (char *)v5->laps._Myfirst)) >> 32;
    v19.m128i_i32[0] = (int)v5->car;
    v7 = *(_BYTE *)(v19.m128i_i32[0] + 3752);
    v20.m128i_i32[2] = (v6 >> 3) + ((unsigned int)v6 >> 31);
    v1 = this;
    v2 = &this->leaderboard;
    v20.m128i_i8[13] = v7;
    v8 = v18->bestLap.time;
    v9 = *(_QWORD *)&v18->totalTime;
    LOBYTE(v6) = v18->hasCompletedLastLap;
    v10 = this->leaderboard._Mylast;
    v22 = 0;
    v20.m128i_i8[14] = v6;
    v19.m128i_i64[1] = v9;
    v11 = v16->sessionType == Race;
    *(double *)v20.m128i_i64 = (double)v8;
    v20.m128i_i8[12] = v11;
    if ( &v19 >= (__m128i *)v10 || v2->_Myfirst > (LeaderboardEntry *)&v19 )
    {
      if ( v10 == this->leaderboard._Myend )
        std::vector<ClientCollisionEvent>::_Reserve((std::vector<ClientCollisionEvent> *)&this->leaderboard, 1u);
      v15 = (__m128i *)this->leaderboard._Mylast;
      if ( v15 )
      {
        *v15 = _mm_loadu_si128(&v19);
        v15[1] = _mm_loadu_si128(&v20);
      }
    }
    else
    {
      v12 = (char *)&v19 - (char *)v2->_Myfirst;
      if ( v10 == this->leaderboard._Myend )
        std::vector<ClientCollisionEvent>::_Reserve((std::vector<ClientCollisionEvent> *)&this->leaderboard, 1u);
      v13 = (__m128i *)this->leaderboard._Mylast;
      v14 = (const __m128i *)((char *)v2->_Myfirst + (v12 & 0xFFFFFFE0));
      if ( v13 )
      {
        *v13 = _mm_loadu_si128(v14);
        v13[1] = _mm_loadu_si128(v14 + 1);
      }
      v1 = this;
    }
    ++this->leaderboard._Mylast;
    v22 = -1;
    if ( result.name._Myres >= 8 )
      operator delete(result.name._Bx._Ptr);
    result.name._Myres = 7;
    result.name._Mysize = 0;
    result.name._Bx._Buf[0] = 0;
    if ( result.spawSet._Myres >= 8 )
      operator delete(result.spawSet._Bx._Ptr);
  }
  std::_Sort<LeaderboardEntry *,int,std::less<void>>(
    v2->_Myfirst,
    v1->leaderboard._Mylast,
    v1->leaderboard._Mylast - v2->_Myfirst,
    0);
}
