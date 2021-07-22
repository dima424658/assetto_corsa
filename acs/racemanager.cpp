#include "racemanager.h"
void RaceManager::RaceManager(RaceManager *this, Sim *isim)
{
  GameObject **v3; // esi
  Font *v4; // eax
  Font *v5; // eax
  std::_Ref_count_base *v6; // esi
  char v7; // al
  double v8; // st7
  bool v9; // cf
  std::wstring v10; // [esp-10h] [ebp-DCh] BYREF
  Game *v11; // [esp+8h] [ebp-C4h]
  char v12; // [esp+23h] [ebp-A9h]
  std::shared_ptr<Font> _Pval; // [esp+24h] [ebp-A8h] BYREF
  RaceManager *v14; // [esp+2Ch] [ebp-A0h]
  std::wstring section; // [esp+30h] [ebp-9Ch] BYREF
  std::wstring ifilename; // [esp+48h] [ebp-84h] BYREF
  std::wstring key; // [esp+60h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+78h] [ebp-54h] BYREF
  int v19; // [esp+C8h] [ebp-4h]

  v14 = this;
  v11 = isim->game;
  v10._Myres = 7;
  v10._Mysize = 0;
  v10._Bx._Buf[0] = 0;
  std::wstring::assign(&v10, L"RACE_MANAGER", 0xCu);
  GameObject::GameObject(this, v10, v11);
  this->__vftable = (RaceManager_vtbl *)&RaceManager::`vftable';
  v19 = 0;
  this->evOnRaceInit.handlers._Myfirst = 0;
  this->evOnRaceInit.handlers._Mylast = 0;
  this->evOnRaceInit.handlers._Myend = 0;
  this->evOnSessionEnd.handlers._Myfirst = 0;
  this->evOnSessionEnd.handlers._Mylast = 0;
  this->evOnSessionEnd.handlers._Myend = 0;
  this->evOnLapCompleted.handlers._Myfirst = 0;
  this->evOnLapCompleted.handlers._Mylast = 0;
  this->evOnLapCompleted.handlers._Myend = 0;
  *(_DWORD *)&this->penaltiesEnabled = 0;
  this->currentSessionIndex = -1;
  this->overTimeMult = 1.5;
  *(_WORD *)&this->timeRaceEnded = 0;
  this->hasAdditionalLap = 0;
  this->pitWindowStartTime = 0.0;
  this->pitWindowEndTime = 0.0;
  v11 = (Game *)&_Pval;
  v10._Myres = 0;
  LOBYTE(v19) = 3;
  this->windSettings.baseSpeed = 0.0;
  this->windSettings.baseDirection = 0.0;
  _Pval._Ptr = 0;
  this->multiplayerStatus.completedFlags._Myvec._Myfirst = 0;
  this->multiplayerStatus.completedFlags._Myvec._Mylast = 0;
  this->multiplayerStatus.completedFlags._Myvec._Myend = 0;
  std::vector<unsigned int>::_Construct_n(
    &this->multiplayerStatus.completedFlags._Myvec,
    v10._Myres,
    (const unsigned int *)v11);
  this->multiplayerStatus.completedFlags._Mysize = 0;
  LOBYTE(v19) = 4;
  this->leaderLastLap = 0;
  Session::Session(&this->currentSession);
  LOBYTE(v19) = 5;
  Trigger::Trigger(&this->debugTrigger);
  this->sim = isim;
  this->raceTimingServices = 0;
  this->font._Ptr = 0;
  this->font._Rep = 0;
  this->sessions._Myfirst = 0;
  this->sessions._Mylast = 0;
  this->sessions._Myend = 0;
  this->carsRealTimePosition._Myfirst = 0;
  this->carsRealTimePosition._Mylast = 0;
  this->carsRealTimePosition._Myend = 0;
  this->carsRaceStatus._Myfirst = 0;
  this->carsRaceStatus._Mylast = 0;
  this->carsRaceStatus._Myend = 0;
  this->mpCacheLeaderboard._Myfirst = 0;
  this->mpCacheLeaderboard._Mylast = 0;
  this->mpCacheLeaderboard._Myend = 0;
  this->leaderboardHistory._Myfirst = 0;
  this->leaderboardHistory._Mylast = 0;
  this->leaderboardHistory._Myend = 0;
  this->sessionHistoryList._Myfirst = 0;
  this->sessionHistoryList._Mylast = 0;
  this->sessionHistoryList._Myend = 0;
  v3 = isim->gameObjects._Myfirst;
  for ( LOBYTE(v19) = 13; v3 != isim->gameObjects._Mylast; ++v3 )
  {
    if ( __RTDynamicCast(*v3, 0, &GameObject `RTTI Type Descriptor', &PhysicsAvatar `RTTI Type Descriptor', 0) )
      break;
  }
  v4 = (Font *)operator new(24);
  _Pval._Ptr = v4;
  LOBYTE(v19) = 14;
  if ( v4 )
    Font::Font(v4, eFontProportional, 24.0, 0, 0);
  else
    v5 = 0;
  LOBYTE(v19) = 13;
  _Pval._Ptr = 0;
  _Pval._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Pval, v5);
  std::shared_ptr<Font>::operator=(&this->font, &_Pval);
  v6 = _Pval._Rep;
  if ( _Pval._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Pval._Rep->_Uses, 0xFFFFFFFF) )
    {
      v6->_Destroy(v6);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v6->_Weaks) )
        v6->_Delete_this(v6);
    }
  }
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/assetto_corsa.ini", 0x1Cu);
  LOBYTE(v19) = 15;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v19) = 17;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"RACE", 4u);
  LOBYTE(v19) = 18;
  v7 = INIReader::hasSection(&ini, &section);
  v12 = v7;
  LOBYTE(v19) = 17;
  if ( section._Myres >= 8 )
  {
    operator delete(section._Bx._Ptr);
    v7 = v12;
  }
  if ( v7 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"OVER_TIME_MULT", 0xEu);
    LOBYTE(v19) = 19;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"RACE", 4u);
    LOBYTE(v19) = 20;
    v8 = INIReader::getFloat(&ini, &section, &key);
    v9 = section._Myres < 8;
    this->overTimeMult = v8;
    if ( !v9 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  LOBYTE(v19) = 13;
  INIReader::~INIReader(&ini);
}
void RaceManager::~RaceManager(RaceManager *this)
{
  std::vector<OnSessionEndEvent> *v2; // edi
  std::vector<unsigned char> **v3; // edi
  std::vector<LeaderboardEntry> *v4; // edi
  std::vector<RaceStatusCarDesc> *v5; // edi
  std::vector<RealTimeCarDesc> *v6; // edi
  std::vector<Session> *v7; // edi
  std::_Ref_count_base *v8; // edi

  this->__vftable = (RaceManager_vtbl *)&RaceManager::`vftable';
  v2 = &this->sessionHistoryList;
  if ( this->sessionHistoryList._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->sessionHistoryList);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<OnSessionEndEvent>>>(v2->_Myfirst, v2->_Mylast);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  v3 = (std::vector<unsigned char> **)&this->leaderboardHistory;
  if ( this->leaderboardHistory._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->leaderboardHistory);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::vector<ReplayFrameWingStatus>>>>(
      *v3,
      (std::vector<unsigned char> *)this->leaderboardHistory._Mylast);
    operator delete(*v3);
    *v3 = 0;
    this->leaderboardHistory._Mylast = 0;
    this->leaderboardHistory._Myend = 0;
  }
  v4 = &this->mpCacheLeaderboard;
  if ( this->mpCacheLeaderboard._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->mpCacheLeaderboard);
    operator delete(v4->_Myfirst);
    v4->_Myfirst = 0;
    this->mpCacheLeaderboard._Mylast = 0;
    this->mpCacheLeaderboard._Myend = 0;
  }
  v5 = &this->carsRaceStatus;
  if ( this->carsRaceStatus._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->carsRaceStatus);
    operator delete(v5->_Myfirst);
    v5->_Myfirst = 0;
    this->carsRaceStatus._Mylast = 0;
    this->carsRaceStatus._Myend = 0;
  }
  v6 = &this->carsRealTimePosition;
  if ( this->carsRealTimePosition._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->carsRealTimePosition);
    operator delete(v6->_Myfirst);
    v6->_Myfirst = 0;
    this->carsRealTimePosition._Mylast = 0;
    this->carsRealTimePosition._Myend = 0;
  }
  v7 = &this->sessions;
  if ( this->sessions._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->sessions);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<Session>>>(v7->_Myfirst, this->sessions._Mylast);
    operator delete(v7->_Myfirst);
    v7->_Myfirst = 0;
    this->sessions._Mylast = 0;
    this->sessions._Myend = 0;
  }
  v8 = this->font._Rep;
  if ( v8 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v8->_Uses, 0xFFFFFFFF) )
    {
      v8->_Destroy(v8);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v8->_Weaks) )
        v8->_Delete_this(v8);
    }
  }
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->debugTrigger);
  if ( this->currentSession.name._Myres >= 8 )
    operator delete(this->currentSession.name._Bx._Ptr);
  this->currentSession.name._Myres = 7;
  this->currentSession.name._Mysize = 0;
  this->currentSession.name._Bx._Buf[0] = 0;
  if ( this->currentSession.spawSet._Myres >= 8 )
    operator delete(this->currentSession.spawSet._Bx._Ptr);
  this->currentSession.spawSet._Myres = 7;
  this->currentSession.spawSet._Mysize = 0;
  this->currentSession.spawSet._Bx._Buf[0] = 0;
  this->multiplayerStatus.completedFlags._Mysize = 0;
  if ( this->multiplayerStatus.completedFlags._Myvec._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->multiplayerStatus);
    operator delete(this->multiplayerStatus.completedFlags._Myvec._Myfirst);
    this->multiplayerStatus.completedFlags._Myvec._Myfirst = 0;
    this->multiplayerStatus.completedFlags._Myvec._Mylast = 0;
    this->multiplayerStatus.completedFlags._Myvec._Myend = 0;
  }
  if ( this->evOnLapCompleted.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnLapCompleted);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnLapCompleted,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnLapCompleted.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnLapCompleted.handlers._Mylast);
    operator delete(this->evOnLapCompleted.handlers._Myfirst);
    this->evOnLapCompleted.handlers._Myfirst = 0;
    this->evOnLapCompleted.handlers._Mylast = 0;
    this->evOnLapCompleted.handlers._Myend = 0;
  }
  if ( this->evOnSessionEnd.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnSessionEnd);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnSessionEnd,
      (Task *)this->evOnSessionEnd.handlers._Myfirst,
      (Task *)this->evOnSessionEnd.handlers._Mylast);
    operator delete(this->evOnSessionEnd.handlers._Myfirst);
    this->evOnSessionEnd.handlers._Myfirst = 0;
    this->evOnSessionEnd.handlers._Mylast = 0;
    this->evOnSessionEnd.handlers._Myend = 0;
  }
  if ( this->evOnRaceInit.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnRaceInit);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnRaceInit,
      (Task *)this->evOnRaceInit.handlers._Myfirst,
      (Task *)this->evOnRaceInit.handlers._Mylast);
    operator delete(this->evOnRaceInit.handlers._Myfirst);
    this->evOnRaceInit.handlers._Myfirst = 0;
    this->evOnRaceInit.handlers._Mylast = 0;
    this->evOnRaceInit.handlers._Myend = 0;
  }
  GameObject::~GameObject(this);
}
RaceManager *RaceManager::`vector deleting destructor'(RaceManager *this, unsigned int a2)
{
  RaceManager::~RaceManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void RaceManager::checkMandatoryPit(RaceManager *this, int carIndex, float entry, float exit)
{
  float v5; // xmm1_4
  RemoteSession *v6; // eax
  char v7; // cl
  char v8; // bl
  ACClient *v9; // ecx
  OnGearRequestEvent message; // [esp+7h] [ebp-41h] BYREF

  *(GearChangeRequest *)((char *)&message.request + 1) = eNoGearRequest;
  if ( carIndex || this->pitWindowStartTime <= 0.0 || Sim::getCar(this->sim, 0)->mandatoryPitstopDone )
    return;
  v5 = Sim::getCar(this->sim, 0)->lastPitstopTime;
  if ( v5 < entry || exit < v5 )
  {
    v7 = BYTE1(message.request);
LABEL_10:
    v8 = 0;
    goto LABEL_11;
  }
  v6 = ACClient::getCurrentSession(this->sim->client, (RemoteSession *)((char *)&message.nextGear + 1));
  v7 = 1;
  if ( entry - v6->startTime < this->pitWindowStartTime || exit == 0.0 )
    goto LABEL_10;
  v8 = 1;
LABEL_11:
  if ( (v7 & 1) != 0 )
    std::pair<std::wstring,jsonwriter::Node &>::~pair<std::wstring,jsonwriter::Node &>((MD5Result *)((char *)&message.nextGear + 1));
  if ( v8 )
  {
    Sim::getCar(this->sim, 0)->mandatoryPitstopDone = 1;
    v9 = this->sim->client;
    if ( v9 )
    {
      LOBYTE(message.request) = 1;
      Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&v9->evOnMandatoryPitDone, &message);
    }
  }
}
Session *RaceManager::convertRemoteSession(RaceManager *this, Session *result, const RemoteSession *rs)
{
  std::wstring *v3; // ecx
  bool v4; // zf
  Session *v5; // eax

  Session::Session(result);
  result->durationMinutes = (float)rs->time;
  result->laps = rs->laps;
  if ( &result->name != (std::wstring *)rs )
    std::wstring::assign(&result->name, &rs->name, 0, 0xFFFFFFFF);
  result->sessionType = rs->type;
  v3 = &result->spawSet;
  v4 = result->sessionType == Race;
  result->isTimedRace = rs->isTimedRace;
  if ( v4 )
    std::wstring::assign(v3, L"START", 5u);
  else
    std::wstring::assign(v3, L"PIT", 3u);
  if ( rs->isSpectator )
    std::wstring::assign(&result->spawSet, L"PIT", 3u);
  v5 = result;
  result->startTime = rs->startTime;
  return v5;
}
void RaceManager::finalizeCurrentSession(RaceManager *this)
{
  RaceManager *v1; // ebx
  const Session *v2; // eax
  CarAvatar *v3; // eax
  Sim *v4; // ecx
  Sim *v5; // ecx
  unsigned int v6; // edx
  int v7; // ebp
  CarAvatar *v8; // eax
  Lap *v9; // edi
  Lap *v10; // esi
  ACClient *v11; // ecx
  SessionType v12; // esi
  unsigned int v13; // edi
  LeaderboardEntry *v14; // ecx
  int v15; // esi
  int v16; // eax
  Sim *v17; // ecx
  unsigned int v18; // ebp
  int v19; // edi
  CarAvatar *v20; // eax
  std::vector<Lap> *v21; // eax
  Lap *v22; // esi
  std::wstring *v23; // ecx
  unsigned int v24; // edi
  int v25; // esi
  int v26; // eax
  ACClient *v27; // ecx
  unsigned int v28; // esi
  unsigned int v29; // eax
  ACClient *v30; // ecx
  int v31; // eax
  ACClient *v32; // ecx
  int v33; // eax
  int v34; // esi
  std::pair<void *,std::function<void __cdecl(OnSessionEndEvent const &)> > *v35; // esi
  std::_Func_base<void,OnSessionEndEvent const &> **v36; // edi
  const Session *v37; // eax
  CarAvatar *v38; // eax
  unsigned int v39; // ecx
  int *v40; // edx
  CarAvatar *v41; // eax
  CarAvatar *v42; // ebp
  int v43; // eax
  int v44; // eax
  int v45; // ebx
  int v46; // eax
  float *v47; // esi
  int v48; // edi
  int v49; // eax
  unsigned int v50; // eax
  int v51; // eax
  int v52; // esi
  unsigned int v53; // edx
  int *v54; // ecx
  CarAvatar *v55; // eax
  CarAvatar *v56; // edi
  unsigned int v57; // esi
  int v58; // eax
  float v59; // xmm0_4
  unsigned int v60; // esi
  int v61; // eax
  Lap *v62; // edx
  unsigned int v63; // eax
  unsigned int v64; // edx
  int v65; // eax
  int v66; // edx
  bool v67; // cl
  int v68; // eax
  int v69; // ecx
  std::vector<LeaderboardEntry> *v70; // eax
  std::vector<ClientCollisionEvent> *v71; // esi
  ClientCollisionEvent *v72; // ecx
  ClientCollisionEvent *v73; // ebp
  ClientCollisionEvent *v74; // edx
  int v75; // ecx
  unsigned int v76; // edx
  unsigned int v77; // edx
  __m128i *v78; // eax
  const __m128i *v79; // edi
  __m128i v80; // xmm0
  ClientCollisionEvent *v81; // edx
  int v82; // ecx
  unsigned int v83; // edx
  unsigned int v84; // edx
  ACClient *v85; // ecx
  unsigned int v86; // esi
  unsigned int v87; // eax
  ACClient *v88; // ecx
  int v89; // eax
  ACClient *v90; // ecx
  int v91; // eax
  int v92; // esi
  std::pair<void *,std::function<void __cdecl(OnSessionEndEvent const &)> > *v93; // esi
  std::_Func_base<void,OnSessionEndEvent const &> **v94; // edi
  unsigned int v95; // [esp+14h] [ebp-1FCh]
  unsigned int v96; // [esp+14h] [ebp-1FCh]
  unsigned int v97; // [esp+14h] [ebp-1FCh]
  float _Count; // [esp+18h] [ebp-1F8h]
  std::vector<LeaderboardEntry> finalLeaderboard; // [esp+1Ch] [ebp-1F4h] BYREF
  float v100; // [esp+28h] [ebp-1E8h]
  std::vector<Lap> laps; // [esp+2Ch] [ebp-1E4h] BYREF
  SessionResultProcessor srp; // [esp+3Ch] [ebp-1D4h] BYREF
  LeaderboardEntry lb; // [esp+40h] [ebp-1D0h] BYREF
  SessionResult simulatedResult; // [esp+60h] [ebp-1B0h] BYREF
  int v105; // [esp+9Ch] [ebp-174h]
  unsigned int v106; // [esp+A0h] [ebp-170h]
  Session v107; // [esp+C0h] [ebp-150h] BYREF
  SessionResult v108; // [esp+120h] [ebp-F0h] BYREF
  OnSessionEndEvent myEvent; // [esp+160h] [ebp-B0h] BYREF
  int v110; // [esp+20Ch] [ebp-4h]

  v1 = this;
  _Count = *(float *)&this;
  if ( !this->sim->client )
    goto $LN1257;
  Session::Session(&myEvent.currentSession);
  SessionResult::SessionResult(&myEvent.result);
  v110 = 0;
  v2 = RaceManager::getCurrentSession(v1, (Session *)&simulatedResult);
  LOBYTE(v110) = 1;
  Session::operator=(&myEvent.currentSession, v2);
  LOBYTE(v110) = 0;
  if ( v106 >= 8 )
    operator delete(simulatedResult.lapCount._Myend);
  v106 = 7;
  v105 = 0;
  LOWORD(simulatedResult.lapCount._Myend) = 0;
  if ( simulatedResult.lapCount._Mylast >= (int *)8 )
    operator delete(simulatedResult.bestLaps._Myend);
  if ( v1->currentSession.sessionType == Race && !RaceManager::isRaceOver(v1, 0) )
  {
    _printf("RETIRING PLAYER FOR QUITTING THE RACE BEFORE THE END\n");
    v3 = Sim::getCar(v1->sim, 0);
    RaceEngineer::getCar(v3->raceEngineer._Myptr)->isRetired = 1;
  }
  RaceManager::getLeaderboard(v1, &finalLeaderboard);
  v4 = v1->sim;
  LOBYTE(v110) = 2;
  std::vector<std::vector<Lap>>::resize(&myEvent.result.laps, v4->cars._Mylast - v4->cars._Myfirst);
  std::vector<Lap>::resize(&myEvent.result.bestLaps, v1->sim->cars._Mylast - v1->sim->cars._Myfirst);
  std::vector<float>::resize(
    (std::vector<float> *)&myEvent.result.lapCount,
    v1->sim->cars._Mylast - v1->sim->cars._Myfirst);
  std::vector<float>::resize(
    (std::vector<float> *)&myEvent.result.positions,
    v1->sim->cars._Mylast - v1->sim->cars._Myfirst);
  std::vector<float>::resize(&myEvent.result.total, v1->sim->cars._Mylast - v1->sim->cars._Myfirst);
  v5 = v1->sim;
  v6 = 0;
  v95 = 0;
  if ( v5->cars._Mylast - v5->cars._Myfirst )
  {
    v7 = 0;
    do
    {
      laps._Myfirst = 0;
      laps._Mylast = 0;
      laps._Myend = 0;
      LOBYTE(v110) = 3;
      v8 = Sim::getCar(v5, v6);
      ACClient::getLaps(v1->sim->client, v8, &laps);
      v9 = laps._Mylast;
      v10 = laps._Myfirst;
      if ( laps._Myfirst != laps._Mylast )
      {
        do
          std::vector<Lap>::push_back(&myEvent.result.laps._Myfirst[v7], v10++);
        while ( v10 != v9 );
        v10 = laps._Myfirst;
      }
      LOBYTE(v110) = 2;
      if ( v10 )
      {
        std::_Container_base0::_Orphan_all(&laps);
        std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(laps._Myfirst, laps._Mylast);
        operator delete(laps._Myfirst);
        laps._Myfirst = 0;
        laps._Mylast = 0;
        laps._Myend = 0;
      }
      v5 = v1->sim;
      ++v7;
      v6 = v95 + 1;
      v95 = v6;
    }
    while ( v6 < v5->cars._Mylast - v5->cars._Myfirst );
  }
  v11 = v1->sim->client;
  if ( v11 )
  {
    v12 = ACClient::getCurrentSession(v11, (RemoteSession *)&simulatedResult)->type;
    if ( simulatedResult.bestLaps._Myend >= (Lap *)8 )
      operator delete(simulatedResult.laps._Myfirst);
  }
  else
  {
    v12 = v1->currentSession.sessionType;
  }
  if ( v12 == Pratice || v12 == Qualify )
  {
    v17 = v1->sim;
    v18 = 0;
    if ( v17->cars._Mylast - v17->cars._Myfirst )
    {
      v19 = 0;
      do
      {
        v20 = Sim::getCar(v17, v18);
        v21 = (std::vector<Lap> *)ACClient::getBestLap(v1->sim->client, v20);
        simulatedResult.laps._Mylast = 0;
        simulatedResult.laps._Myend = 0;
        simulatedResult.bestLaps._Myfirst = 0;
        simulatedResult.lapCount._Myend = (int *)7;
        simulatedResult.lapCount._Mylast = 0;
        LOWORD(simulatedResult.positions._Myfirst) = 0;
        if ( (int)v21 < 0 )
          v21 = 0;
        simulatedResult.laps._Myfirst = v21;
        simulatedResult.bestLaps._Mylast = 0;
        LOBYTE(simulatedResult.bestLaps._Myend) = 1;
        v22 = myEvent.result.bestLaps._Myfirst;
        LOBYTE(v110) = 4;
        myEvent.result.bestLaps._Myfirst[v19].time = (unsigned int)v21;
        std::vector<int>::operator=(&v22[v19].splits, (const std::vector<unsigned int> *)&simulatedResult.laps._Mylast);
        v22[v19].cuts = (unsigned int)simulatedResult.bestLaps._Mylast;
        v23 = &v22[v19].compound;
        v22[v19].isValid = (bool)simulatedResult.bestLaps._Myend;
        if ( v23 != (std::wstring *)&simulatedResult.positions )
          std::wstring::assign(v23, (const std::wstring *)&simulatedResult.positions, 0, 0xFFFFFFFF);
        LOBYTE(v110) = 2;
        if ( simulatedResult.lapCount._Myend >= (int *)8 )
          operator delete(simulatedResult.positions._Myfirst);
        simulatedResult.lapCount._Myend = (int *)7;
        simulatedResult.lapCount._Mylast = 0;
        LOWORD(simulatedResult.positions._Myfirst) = 0;
        if ( simulatedResult.laps._Mylast )
        {
          std::_Container_base0::_Orphan_all((std::_Container_base0 *)&simulatedResult.laps._Mylast);
          operator delete(simulatedResult.laps._Mylast);
        }
        v17 = v1->sim;
        ++v18;
        ++v19;
      }
      while ( v18 < v17->cars._Mylast - v17->cars._Myfirst );
    }
    v14 = finalLeaderboard._Myfirst;
  }
  else
  {
    v13 = 0;
    v14 = finalLeaderboard._Myfirst;
    if ( finalLeaderboard._Mylast - finalLeaderboard._Myfirst )
    {
      v15 = 0;
      do
      {
        v16 = CarAvatar::getGuid(v14[v15++].car);
        ++v13;
        myEvent.result.total._Myfirst[v16] = finalLeaderboard._Myfirst[v15 - 1].totalTime;
        v14 = finalLeaderboard._Myfirst;
      }
      while ( v13 < finalLeaderboard._Mylast - finalLeaderboard._Myfirst );
    }
  }
  v24 = 0;
  if ( finalLeaderboard._Mylast - v14 )
  {
    v25 = 0;
    do
    {
      v26 = CarAvatar::getGuid(v14[v25++].car);
      myEvent.result.positions._Myfirst[v24++] = v26;
      myEvent.result.lapCount._Myfirst[v26] = finalLeaderboard._Myfirst[v25 - 1].laps;
      v14 = finalLeaderboard._Myfirst;
    }
    while ( v24 < finalLeaderboard._Mylast - finalLeaderboard._Myfirst );
  }
  v27 = v1->sim->client;
  v28 = v1->sessionHistoryList._Mylast - v1->sessionHistoryList._Myfirst;
  if ( v27 )
    v29 = ACClient::getCurrentSessionIndex(v27);
  else
    v29 = v1->currentSessionIndex;
  if ( v28 <= v29 )
  {
    v30 = v1->sim->client;
    if ( v30 )
      v31 = ACClient::getCurrentSessionIndex(v30);
    else
      v31 = v1->currentSessionIndex;
    std::vector<OnSessionEndEvent>::resize(&v1->sessionHistoryList, v31 + 1);
  }
  v32 = v1->sim->client;
  if ( v32 )
    v33 = ACClient::getCurrentSessionIndex(v32);
  else
    v33 = v1->currentSessionIndex;
  v34 = (int)&v1->sessionHistoryList._Myfirst[v33];
  *(_DWORD *)v34 = myEvent.currentSession.sessionType;
  *(_BYTE *)(v34 + 4) = myEvent.currentSession.isTimedRace;
  *(_BYTE *)(v34 + 5) = myEvent.currentSession.hasAdditionalLap;
  *(_DWORD *)(v34 + 8) = myEvent.currentSession.laps;
  *(float *)(v34 + 12) = myEvent.currentSession.durationMinutes;
  *(float *)(v34 + 16) = myEvent.currentSession.overtime_ms;
  if ( (std::wstring *)(v34 + 20) != &myEvent.currentSession.spawSet )
    std::wstring::assign((std::wstring *)(v34 + 20), &myEvent.currentSession.spawSet, 0, 0xFFFFFFFF);
  if ( (std::wstring *)(v34 + 44) != &myEvent.currentSession.name )
    std::wstring::assign((std::wstring *)(v34 + 44), &myEvent.currentSession.name, 0, 0xFFFFFFFF);
  *(long double *)(v34 + 72) = myEvent.currentSession.startTime;
  *(_DWORD *)(v34 + 80) = myEvent.currentSession.forcedPosition;
  *(_BYTE *)(v34 + 84) = myEvent.currentSession.isOver;
  *(_DWORD *)(v34 + 88) = myEvent.currentSession.leaderCompletedLaps;
  std::vector<std::vector<Lap>>::operator=((std::vector<std::vector<Lap>> *)(v34 + 96), &myEvent.result.laps);
  std::vector<Lap>::operator=((std::vector<Lap> *)(v34 + 108), &myEvent.result.bestLaps);
  std::vector<int>::operator=(
    (std::vector<unsigned int> *)(v34 + 120),
    (const std::vector<unsigned int> *)&myEvent.result.positions);
  std::vector<int>::operator=(
    (std::vector<unsigned int> *)(v34 + 132),
    (const std::vector<unsigned int> *)&myEvent.result.lapCount);
  std::vector<float>::operator=(
    (std::vector<unsigned int> *)(v34 + 144),
    (const std::vector<unsigned int> *)&myEvent.result.total);
  v35 = v1->evOnSessionEnd.handlers._Myfirst;
  if ( v35 == v1->evOnSessionEnd.handlers._Mylast )
  {
LABEL_61:
    LOBYTE(v110) = 0;
    if ( finalLeaderboard._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&finalLeaderboard);
      operator delete(finalLeaderboard._Myfirst);
      finalLeaderboard._Myfirst = 0;
      finalLeaderboard._Mylast = 0;
      finalLeaderboard._Myend = 0;
    }
    SessionResult::~SessionResult(&myEvent.result);
    if ( myEvent.currentSession.name._Myres >= 8 )
      operator delete(myEvent.currentSession.name._Bx._Ptr);
    myEvent.currentSession.name._Myres = 7;
    myEvent.currentSession.name._Mysize = 0;
    myEvent.currentSession.name._Bx._Buf[0] = 0;
    if ( myEvent.currentSession.spawSet._Myres >= 8 )
      operator delete(myEvent.currentSession.spawSet._Bx._Ptr);
    return;
  }
  v36 = &v35->second._Impl;
  while ( *v36 )
  {
    (*v36)->_Do_call(*v36, &myEvent);
    ++v35;
    v36 += 8;
    if ( v35 == v1->evOnSessionEnd.handlers._Mylast )
      goto LABEL_61;
  }
  while ( 1 )
  {
    std::_Xbad_function_call();
$LN1257:
    Session::Session(&v107);
    SessionResult::SessionResult(&v108);
    v110 = 5;
    v37 = RaceManager::getCurrentSession(v1, &myEvent.currentSession);
    LOBYTE(v110) = 6;
    Session::operator=(&v107, v37);
    LOBYTE(v110) = 5;
    if ( myEvent.currentSession.name._Myres >= 8 )
      operator delete(myEvent.currentSession.name._Bx._Ptr);
    myEvent.currentSession.name._Myres = 7;
    myEvent.currentSession.name._Mysize = 0;
    myEvent.currentSession.name._Bx._Buf[0] = 0;
    if ( myEvent.currentSession.spawSet._Myres >= 8 )
      operator delete(myEvent.currentSession.spawSet._Bx._Ptr);
    if ( v1->currentSession.sessionType == Race && !RaceManager::isRaceOver(v1, 0) )
    {
      _printf("RETIRING PLAYER FOR QUITTING THE RACE BEFORE THE END\n");
      v38 = Sim::getCar(v1->sim, 0);
      RaceEngineer::getCar(v38->raceEngineer._Myptr)->isRetired = 1;
    }
    CommandItem::CommandItem(
      (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&srp,
      (CarAudioFMOD *)v1->sim);
    LOBYTE(v110) = 7;
    SessionResultProcessor::getCompleteAIResults(&srp, &simulatedResult);
    LOBYTE(v110) = 8;
    std::vector<std::vector<Lap>>::operator=(&v108.laps, &simulatedResult.laps);
    std::vector<int>::operator=(
      (std::vector<unsigned int> *)&v108.positions,
      (const std::vector<unsigned int> *)&simulatedResult.positions);
    std::vector<Lap>::operator=(&v108.bestLaps, &simulatedResult.bestLaps);
    std::vector<int>::operator=(
      (std::vector<unsigned int> *)&v108.lapCount,
      (const std::vector<unsigned int> *)&simulatedResult.lapCount);
    std::vector<float>::resize(&v108.total, v1->sim->cars._Mylast - v1->sim->cars._Myfirst);
    *(float *)&v39 = 0.0;
    v40 = v108.positions._Myfirst;
    v100 = 0.0;
    if ( v108.positions._Mylast - v108.positions._Myfirst )
    {
      do
      {
        v41 = Sim::getCar(v1->sim, v40[v39]);
        v42 = v41;
        if ( v41 )
        {
          v43 = CarAvatar::getGuid(v41);
          v108.total._Myfirst[v43] = 0.0;
          if ( v108.laps._Mylast - v108.laps._Myfirst )
          {
            v96 = 0;
            v44 = CarAvatar::getGuid(v42);
            if ( v108.laps._Myfirst[v44]._Mylast - v108.laps._Myfirst[v44]._Myfirst )
            {
              v45 = 0;
              do
              {
                v46 = CarAvatar::getGuid(v42);
                v47 = v108.total._Myfirst;
                v48 = v46;
                v49 = CarAvatar::getGuid(v42);
                v50 = v108.laps._Myfirst[v49]._Myfirst[v45++].time;
                v47[v48] = (float)v50 + v47[v48];
                ++v96;
                v51 = CarAvatar::getGuid(v42);
              }
              while ( v96 < v108.laps._Myfirst[v51]._Mylast - v108.laps._Myfirst[v51]._Myfirst );
              v1 = (RaceManager *)LODWORD(_Count);
            }
          }
        }
        v40 = v108.positions._Myfirst;
        v39 = LODWORD(v100) + 1;
        v100 = *(float *)&v39;
      }
      while ( v39 < v108.positions._Mylast - v108.positions._Myfirst );
    }
    v52 = (int)&v1->leaderboardHistory._Myfirst[v1->currentSessionIndex];
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)v52);
    v53 = 0;
    *(_DWORD *)(v52 + 4) = *(_DWORD *)v52;
    v54 = v108.positions._Myfirst;
    v97 = 0;
    if ( v108.positions._Mylast - v108.positions._Myfirst )
    {
      while ( 1 )
      {
        v55 = Sim::getCar(v1->sim, v54[v53]);
        v56 = v55;
        if ( v55 )
          break;
LABEL_120:
        v54 = v108.positions._Myfirst;
        v53 = v97 + 1;
        v97 = v53;
        if ( v53 >= v108.positions._Mylast - v108.positions._Myfirst )
          goto LABEL_121;
      }
      v57 = v108.total._Mylast - v108.total._Myfirst;
      if ( CarAvatar::getGuid(v55) >= v57 )
      {
        v59 = 0.0;
      }
      else
      {
        v58 = CarAvatar::getGuid(v56);
        v59 = v108.total._Myfirst[v58];
      }
      v100 = v59;
      v60 = v108.bestLaps._Mylast - v108.bestLaps._Myfirst;
      if ( CarAvatar::getGuid(v56) >= v60 )
      {
        v62 = v108.bestLaps._Myfirst;
        v63 = 0;
      }
      else
      {
        v61 = CarAvatar::getGuid(v56);
        v62 = v108.bestLaps._Myfirst;
        v63 = v108.bestLaps._Myfirst[v61].time;
      }
      v64 = (int)((unsigned __int64)(715827883i64 * ((char *)v108.bestLaps._Mylast - (char *)v62)) >> 32) >> 3;
      _Count = (float)v63;
      if ( CarAvatar::getGuid(v56) >= v64 + (v64 >> 31) )
      {
        v66 = 0;
      }
      else
      {
        v65 = CarAvatar::getGuid(v56);
        v66 = v108.lapCount._Myfirst[v65];
      }
      v67 = v56->isBlackFlagged;
      lb.isRaceMode = v107.sessionType == Race;
      v68 = v1->currentSessionIndex;
      lb.isBlackFlagged = v67;
      lb.car = v56;
      lb.laps = v66;
      v69 = v68;
      lb.hasCompletedLastLap = 1;
      v70 = v1->leaderboardHistory._Myfirst;
      lb.totalTime = v100;
      v71 = (std::vector<ClientCollisionEvent> *)&v70[v69];
      v72 = v71->_Mylast;
      lb.bestLap = _Count;
      if ( &lb >= (LeaderboardEntry *)v72 || (v73 = v71->_Myfirst, v71->_Myfirst > (ClientCollisionEvent *)&lb) )
      {
        v81 = v71->_Myend;
        if ( v72 == v81 && !(v81 - v72) )
        {
          v82 = v72 - v71->_Myfirst;
          if ( v82 == 0x7FFFFFF )
LABEL_123:
            std::_Xlength_error("vector<T> too long");
          v83 = v81 - v71->_Myfirst;
          if ( 0x7FFFFFF - (v83 >> 1) >= v83 )
            v84 = (v83 >> 1) + v83;
          else
            v84 = 0;
          if ( v84 < v82 + 1 )
            v84 = v82 + 1;
          std::vector<ClientCollisionEvent>::_Reallocate(v71, v84);
        }
        v78 = (__m128i *)v71->_Mylast;
        if ( !v78 )
          goto LABEL_119;
        *v78 = _mm_loadu_si128((const __m128i *)&lb);
        v80 = _mm_loadu_si128((const __m128i *)&lb.bestLap);
      }
      else
      {
        v74 = v71->_Myend;
        if ( v72 == v74 && !(v74 - v72) )
        {
          v75 = v72 - v73;
          if ( v75 == 0x7FFFFFF )
            goto LABEL_123;
          v76 = v74 - v73;
          LODWORD(_Count) = v75 + 1;
          if ( 0x7FFFFFF - (v76 >> 1) >= v76 )
            v77 = (v76 >> 1) + v76;
          else
            v77 = 0;
          if ( v77 < LODWORD(_Count) )
            v77 = v75 + 1;
          std::vector<ClientCollisionEvent>::_Reallocate(v71, v77);
        }
        v78 = (__m128i *)v71->_Mylast;
        v79 = (const __m128i *)((char *)v71->_Myfirst + (((char *)&lb - (char *)v73) & 0xFFFFFFE0));
        if ( !v78 )
          goto LABEL_119;
        *v78 = _mm_loadu_si128(v79);
        v80 = _mm_loadu_si128(v79 + 1);
      }
      v78[1] = v80;
LABEL_119:
      ++v71->_Mylast;
      goto LABEL_120;
    }
LABEL_121:
    v85 = v1->sim->client;
    v86 = v1->sessionHistoryList._Mylast - v1->sessionHistoryList._Myfirst;
    if ( v85 )
      v87 = ACClient::getCurrentSessionIndex(v85);
    else
      v87 = v1->currentSessionIndex;
    if ( v86 <= v87 )
    {
      v88 = v1->sim->client;
      if ( v88 )
        v89 = ACClient::getCurrentSessionIndex(v88);
      else
        v89 = v1->currentSessionIndex;
      std::vector<OnSessionEndEvent>::resize(&v1->sessionHistoryList, v89 + 1);
    }
    v90 = v1->sim->client;
    if ( v90 )
      v91 = ACClient::getCurrentSessionIndex(v90);
    else
      v91 = v1->currentSessionIndex;
    v92 = (int)&v1->sessionHistoryList._Myfirst[v91];
    *(_DWORD *)v92 = v107.sessionType;
    *(_BYTE *)(v92 + 4) = v107.isTimedRace;
    *(_BYTE *)(v92 + 5) = v107.hasAdditionalLap;
    *(_DWORD *)(v92 + 8) = v107.laps;
    *(float *)(v92 + 12) = v107.durationMinutes;
    *(float *)(v92 + 16) = v107.overtime_ms;
    if ( (std::wstring *)(v92 + 20) != &v107.spawSet )
      std::wstring::assign((std::wstring *)(v92 + 20), &v107.spawSet, 0, 0xFFFFFFFF);
    if ( (std::wstring *)(v92 + 44) != &v107.name )
      std::wstring::assign((std::wstring *)(v92 + 44), &v107.name, 0, 0xFFFFFFFF);
    *(long double *)(v92 + 72) = v107.startTime;
    *(_DWORD *)(v92 + 80) = v107.forcedPosition;
    *(_BYTE *)(v92 + 84) = v107.isOver;
    *(_DWORD *)(v92 + 88) = v107.leaderCompletedLaps;
    std::vector<std::vector<Lap>>::operator=((std::vector<std::vector<Lap>> *)(v92 + 96), &v108.laps);
    std::vector<Lap>::operator=((std::vector<Lap> *)(v92 + 108), &v108.bestLaps);
    std::vector<int>::operator=(
      (std::vector<unsigned int> *)(v92 + 120),
      (const std::vector<unsigned int> *)&v108.positions);
    std::vector<int>::operator=(
      (std::vector<unsigned int> *)(v92 + 132),
      (const std::vector<unsigned int> *)&v108.lapCount);
    std::vector<float>::operator=(
      (std::vector<unsigned int> *)(v92 + 144),
      (const std::vector<unsigned int> *)&v108.total);
    v93 = v1->evOnSessionEnd.handlers._Myfirst;
    if ( v93 == v1->evOnSessionEnd.handlers._Mylast )
      break;
    v94 = &v93->second._Impl;
    while ( *v94 )
    {
      (*v94)->_Do_call(*v94, (const OnSessionEndEvent *)&v107);
      ++v93;
      v94 += 8;
      if ( v93 == v1->evOnSessionEnd.handlers._Mylast )
        goto LABEL_141;
    }
  }
LABEL_141:
  SessionResult::~SessionResult(&simulatedResult);
  LOBYTE(v110) = 5;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&srp);
  SessionResult::~SessionResult(&v108);
  if ( v107.name._Myres >= 8 )
    operator delete(v107.name._Bx._Ptr);
  v107.name._Myres = 7;
  v107.name._Mysize = 0;
  v107.name._Bx._Buf[0] = 0;
  if ( v107.spawSet._Myres >= 8 )
    operator delete(v107.spawSet._Bx._Ptr);
}
void RaceManager::generateWind(RaceManager *this)
{
  Sim *v1; // ecx
  std::function<void __cdecl(void)> v2; // [esp-18h] [ebp-30h] BYREF
  int v3; // [esp+14h] [ebp-4h]

  v2._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_cc8171a7d91ee604e177af52ab7bbe20_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
  v2._Space._Pfn[1] = (void (__cdecl *)())this;
  v2._Impl = (std::_Func_base<void> *)&v2;
  v1 = this->sim;
  v3 = -1;
  PhysicsAvatar::executeOnPhysicsThread(v1->physicsAvatar, v2);
}
Lap *RaceManager::getBestLap(RaceManager *this, Lap *result, CarAvatar *car)
{
  ACClient *v4; // ecx
  Lap *v5; // ecx
  RaceTimingServices *v6; // ecx
  Lap lap; // [esp+18h] [ebp-70h] BYREF
  Lap l; // [esp+48h] [ebp-40h] BYREF
  int v10; // [esp+84h] [ebp-4h]

  v4 = this->sim->client;
  if ( v4 )
  {
    lap.splits._Myfirst = 0;
    lap.splits._Mylast = 0;
    lap.splits._Myend = 0;
    lap.compound._Myres = 7;
    lap.compound._Mysize = 0;
    lap.compound._Bx._Buf[0] = 0;
    lap.cuts = 0;
    v10 = 0;
    lap.isValid = 1;
    lap.time = ACClient::getBestLap(v4, car);
    result->time = lap.time;
    std::vector<Mesh *>::vector<Mesh *>(
      (std::vector<TyreThermalPatch *> *)&result->splits,
      (const std::vector<TyreThermalPatch *> *)&lap.splits);
    result->cuts = lap.cuts;
    result->isValid = lap.isValid;
    result->compound._Myres = 7;
    result->compound._Mysize = 0;
    result->compound._Bx._Buf[0] = 0;
    LOBYTE(v10) = 1;
    std::wstring::assign(&result->compound, &lap.compound, 0, 0xFFFFFFFF);
    v5 = &lap;
LABEL_8:
    Lap::~Lap(v5);
    return result;
  }
  if ( ReplayManager::isInReplaymode(car->sim->replayManager) )
  {
    lap.splits._Myfirst = 0;
    lap.splits._Mylast = 0;
    lap.splits._Myend = 0;
    lap.compound._Myres = 7;
    lap.compound._Mysize = 0;
    lap.compound._Bx._Buf[0] = 0;
    lap.isValid = 0;
    lap.cuts = 0;
    lap.time = car->physicsState.bestLap;
    v10 = 2;
    Lap::Lap(result, &lap);
    v5 = &lap;
    goto LABEL_8;
  }
  v6 = this->raceTimingServices;
  if ( !v6 )
  {
    l.splits._Myfirst = 0;
    l.splits._Mylast = 0;
    l.splits._Myend = 0;
    l.compound._Myres = 7;
    l.compound._Mysize = 0;
    l.compound._Bx._Buf[0] = 0;
    l.isValid = 0;
    l.cuts = 0;
    l.time = car->physicsState.bestLap;
    v10 = 3;
    Lap::Lap(result, &l);
    v5 = &l;
    goto LABEL_8;
  }
  RaceTimingServices::getBestLap(v6, result, car);
  return result;
}
unsigned int RaceManager::getBestLap(RaceManager *this)
{
  ACClient *v1; // eax
  unsigned int result; // eax
  RaceTimingServices *v3; // eax

  v1 = this->sim->client;
  if ( v1 )
    return v1->globalBestlap;
  v3 = this->raceTimingServices;
  if ( v3 )
    result = v3->globalBestlap;
  else
    result = 0;
  return result;
}
unsigned int RaceManager::getBestSplit(RaceManager *this, const int *sector, const bool *isGlobal, CarAvatar *car)
{
  unsigned int result; // eax
  ACClient *v5; // ecx

  if ( this->raceTimingServices )
    return RaceTimingServices::getBestSplit(this->raceTimingServices, sector, isGlobal, car);
  v5 = this->sim->client;
  if ( v5 )
    result = ACClient::getBestSplit(v5, sector, isGlobal, car);
  else
    result = 0;
  return result;
}
unsigned int RaceManager::getCarLeaderboardPosition(RaceManager *this, CarAvatar *car)
{
  unsigned int result; // eax
  ACClient *v4; // ecx
  RaceTimingServices *v5; // ecx

  if ( ReplayManager::isInReplaymode(this->sim->replayManager) )
    return ReplayManager::getCarLeaderboardPosition(this->sim->replayManager, car);
  v4 = this->sim->client;
  if ( v4 )
    return ACClient::getCarPosition(v4, car);
  v5 = this->raceTimingServices;
  if ( !v5 )
    return -1;
  result = RaceTimingServices::getCarLeaderboardPosition(v5, car);
  if ( result == -1 )
    result = RaceManager::getCarRealTimePosition(this, car);
  return result;
}
unsigned int RaceManager::getCarRealTimePosition(RaceManager *this, CarAvatar *car)
{
  unsigned int v3; // ebp
  unsigned int result; // eax
  RealTimeCarDesc *v5; // esi
  RealTimeCarDesc *v6; // edi
  int v7; // ebx
  std::wstring v8; // [esp-18h] [ebp-38h] BYREF
  void **pExceptionObject; // [esp+10h] [ebp-10h] BYREF
  std::exception v10; // [esp+14h] [ebp-Ch] BYREF

  v3 = 0;
  if ( ReplayManager::isInReplaymode(this->sim->replayManager) )
    return 0;
  if ( this->currentSession.sessionType != Race || RaceManager::hasSessionStarted(this) )
  {
    v5 = this->carsRealTimePosition._Myfirst;
    v6 = this->carsRealTimePosition._Mylast;
    if ( v5 == v6 )
    {
LABEL_11:
      car = (CarAvatar *)"guid not found in getCarRealTimePosition";
      std::exception::exception(&v10, (const char *const *)&car);
      pExceptionObject = &std::logic_error::`vftable';
      _CxxThrowException(&pExceptionObject, (_ThrowInfo *)&_TI2_AVlogic_error_std__);
    }
    while ( 1 )
    {
      v7 = CarAvatar::getGuid(v5->car);
      if ( v7 == CarAvatar::getGuid(car) )
        break;
      ++v5;
      ++v3;
      if ( v5 == v6 )
        goto LABEL_11;
    }
    result = v3;
  }
  else
  {
    std::wstring::wstring(&v8, L"START");
    result = CarAvatar::getSpawnPositionIndex(car, v8);
  }
  return result;
}
Lap *RaceManager::getCurrentLap(RaceManager *this, Lap *result, CarAvatar *car)
{
  ACClient *v4; // ecx
  unsigned int v5; // edx
  RaceTimingServices *v6; // ecx
  Lap l; // [esp+14h] [ebp-40h] BYREF
  int v9; // [esp+50h] [ebp-4h]

  v4 = this->sim->client;
  if ( v4 )
  {
    ACClient::getCurrentLap(v4, result, car);
  }
  else
  {
    l.splits._Myfirst = 0;
    l.splits._Mylast = 0;
    l.splits._Myend = 0;
    l.compound._Myres = 7;
    l.compound._Mysize = 0;
    l.compound._Bx._Buf[0] = 0;
    l.isValid = 0;
    l.cuts = 0;
    v5 = car->physicsState.lapTime;
    v9 = 0;
    v6 = this->raceTimingServices;
    l.time = v5;
    if ( v6 )
    {
      RaceTimingServices::getCurrentLapSplits(v6, car, &l.splits);
      v5 = l.time;
    }
    result->time = v5;
    std::vector<Mesh *>::vector<Mesh *>(
      (std::vector<TyreThermalPatch *> *)&result->splits,
      (const std::vector<TyreThermalPatch *> *)&l.splits);
    result->cuts = l.cuts;
    result->isValid = l.isValid;
    result->compound._Myres = 7;
    result->compound._Mysize = 0;
    result->compound._Bx._Buf[0] = 0;
    LOBYTE(v9) = 1;
    std::wstring::assign(&result->compound, &l.compound, 0, 0xFFFFFFFF);
    Lap::~Lap(&l);
  }
  return result;
}
Session *RaceManager::getCurrentSession(RaceManager *this, Session *result)
{
  ACClient *v3; // ecx
  RemoteSession rs; // [esp+10h] [ebp-48h] BYREF
  int v6; // [esp+54h] [ebp-4h]

  v3 = this->sim->client;
  if ( v3 )
  {
    ACClient::getCurrentSession(v3, &rs);
    v6 = 0;
    RaceManager::convertRemoteSession(this, result, &rs);
    if ( rs.name._Myres >= 8 )
      operator delete(rs.name._Bx._Ptr);
  }
  else
  {
    Session::Session(result, &this->currentSession);
  }
  return result;
}
int RaceManager::getCurrentSessionIndex(RaceManager *this)
{
  int result; // eax

  if ( this->sim->client )
    result = ACClient::getCurrentSessionIndex(this->sim->client);
  else
    result = this->currentSessionIndex;
  return result;
}
SessionType RaceManager::getCurrentSessionType(RaceManager *this)
{
  ACClient *v1; // eax
  SessionType v2; // esi
  RemoteSession result; // [esp+0h] [ebp-3Ch] BYREF

  v1 = this->sim->client;
  if ( !v1 )
    return this->currentSession.sessionType;
  v2 = ACClient::getCurrentSession(v1, &result)->type;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  return v2;
}
bool RaceManager::getHasCompletedFlag(RaceManager *this, CarAvatar *car)
{
  RaceTimingServices *v3; // ecx
  unsigned int v5; // eax

  v3 = this->raceTimingServices;
  if ( v3 )
    return RaceTimingServices::getHasCompletedFlag(v3, car);
  if ( !this->sim->client )
    return 0;
  v5 = CarAvatar::getGuid(car);
  return (this->multiplayerStatus.completedFlags._Myvec._Myfirst[v5 >> 5] & (1 << (v5 & 0x1F))) != 0;
}
CarAvatar *RaceManager::getInstanceBestLap(RaceManager *this, CarAvatar *car)
{
  Sim *v3; // ecx
  RemoteSessionResult *v4; // eax
  unsigned int v5; // esi
  int v6; // eax
  CarAvatar *v7; // esi
  CarAvatar *result; // eax
  RaceTimingServices *v9; // ecx
  RemoteSessionResult results; // [esp+10h] [ebp-44h] BYREF
  int v11; // [esp+50h] [ebp-4h]

  v3 = this->sim;
  if ( !v3->client || car == Sim::getCar(v3, 0) )
  {
    v9 = this->raceTimingServices;
    if ( v9 )
      result = RaceTimingServices::getInstanceBestTime(v9, car);
    else
      result = (CarAvatar *)car->physicsState.bestLap;
  }
  else
  {
    v4 = ACClient::getCurrentSessionResults(this->sim->client);
    RemoteSessionResult::RemoteSessionResult(&results, v4);
    v11 = 0;
    v5 = results.times._Mylast - results.times._Myfirst;
    if ( CarAvatar::getGuid(car) >= v5 )
    {
      v7 = (CarAvatar *)ACClient::getInstanceBestLap(this->sim->client, car);
    }
    else
    {
      v6 = CarAvatar::getGuid(car);
      v7 = (CarAvatar *)results.times._Myfirst[v6];
    }
    RemoteSessionResult::~RemoteSessionResult(&results);
    result = v7;
  }
  return result;
}
int RaceManager::getInvertedGridPositions(RaceManager *this)
{
  ACClient *v1; // eax
  int result; // eax

  v1 = this->sim->client;
  if ( v1 )
    result = v1->invertedGridPositions;
  else
    result = 0;
  return result;
}
int RaceManager::getLapCount(RaceManager *this, CarAvatar *car)
{
  Sim *v3; // ecx
  RemoteSessionResult *v4; // eax
  unsigned int v5; // esi
  int v6; // eax
  int v7; // esi
  int result; // eax
  RaceTimingServices *v9; // ecx
  RemoteSessionResult results; // [esp+10h] [ebp-44h] BYREF
  int v11; // [esp+50h] [ebp-4h]

  v3 = this->sim;
  if ( !v3->client || car == Sim::getCar(v3, 0) )
  {
    v9 = this->raceTimingServices;
    if ( v9 )
      result = RaceTimingServices::getLapCount(v9, car);
    else
      result = car->physicsState.lapCount;
  }
  else
  {
    v4 = ACClient::getCurrentSessionResults(this->sim->client);
    RemoteSessionResult::RemoteSessionResult(&results, v4);
    v11 = 0;
    v5 = results.lapCounter._Mylast - results.lapCounter._Myfirst;
    if ( CarAvatar::getGuid(car) >= v5 )
    {
      v7 = ACClient::getLapCount(this->sim->client, car);
    }
    else
    {
      v6 = CarAvatar::getGuid(car);
      v7 = results.lapCounter._Myfirst[v6];
    }
    RemoteSessionResult::~RemoteSessionResult(&results);
    result = v7;
  }
  return result;
}
std::vector<Lap> *RaceManager::getLaps(RaceManager *this, std::vector<Lap> *result, CarAvatar *car, bool readReplayModeIfActive)
{
  Sim *v5; // ecx
  ACClient *v6; // eax
  std::vector<Lap> *v7; // eax
  RaceTimingServices *v8; // ecx
  std::vector<Lap> laps; // [esp+10h] [ebp-18h] BYREF
  int v10; // [esp+24h] [ebp-4h]

  v5 = this->sim;
  v6 = v5->client;
  if ( v6 )
  {
    laps._Myfirst = 0;
    laps._Mylast = 0;
    laps._Myend = 0;
    v10 = 0;
    ACClient::getLaps(v6, car, &laps);
    result->_Myfirst = 0;
    result->_Mylast = 0;
    result->_Myend = 0;
    std::_Container_base0::_Swap_all(result, &laps);
    v7 = result;
    *result = laps;
  }
  else if ( ReplayManager::isInReplaymode(v5->replayManager) && readReplayModeIfActive )
  {
    ReplayManager::getLaps(this->sim->replayManager, result, car);
    v7 = result;
  }
  else
  {
    v8 = this->raceTimingServices;
    if ( v8 )
    {
      RaceTimingServices::getLaps(v8, result, car);
      v7 = result;
    }
    else
    {
      v7 = result;
      result->_Myfirst = 0;
      result->_Mylast = 0;
      result->_Myend = 0;
    }
  }
  return v7;
}
Lap *RaceManager::getLastLap(RaceManager *this, Lap *result, CarAvatar *car)
{
  ACClient *v4; // ecx
  Lap *v5; // ecx
  RaceTimingServices *v6; // ecx
  Lap __that; // [esp+14h] [ebp-70h] BYREF
  Lap l; // [esp+44h] [ebp-40h] BYREF
  int v10; // [esp+80h] [ebp-4h]

  v4 = this->sim->client;
  if ( !v4 )
  {
    if ( ReplayManager::isInReplaymode(car->sim->replayManager) )
    {
      __that.splits._Myfirst = 0;
      __that.splits._Mylast = 0;
      __that.splits._Myend = 0;
      __that.compound._Myres = 7;
      __that.compound._Mysize = 0;
      __that.compound._Bx._Buf[0] = 0;
      __that.isValid = 0;
      __that.cuts = 0;
      v10 = 0;
      __that.time = car->physicsState.lastLap;
      Lap::Lap(result, &__that);
      v5 = &__that;
    }
    else
    {
      v6 = this->raceTimingServices;
      if ( v6 )
      {
        RaceTimingServices::getLastLap(v6, result, car);
        return result;
      }
      l.splits._Myfirst = 0;
      l.splits._Mylast = 0;
      l.splits._Myend = 0;
      l.compound._Myres = 7;
      l.compound._Mysize = 0;
      l.compound._Bx._Buf[0] = 0;
      l.isValid = 0;
      l.cuts = 0;
      l.time = car->physicsState.lastLap;
      v10 = 1;
      Lap::Lap(result, &l);
      v5 = &l;
    }
    Lap::~Lap(v5);
    return result;
  }
  ACClient::getLastLap(v4, result, car);
  return result;
}
unsigned int RaceManager::getLastSplit(RaceManager *this, CarAvatar *car, const int *sector)
{
  unsigned int result; // eax
  ACClient *v4; // ecx

  if ( this->raceTimingServices )
    return RaceTimingServices::getLastSplit(this->raceTimingServices, car, sector);
  v4 = this->sim->client;
  if ( v4 )
    result = ACClient::getLastSplit(v4, car, sector);
  else
    result = 0;
  return result;
}
unsigned int RaceManager::getLeaderLapCount(RaceManager *this)
{
  RemoteSessionResult *v2; // edi
  unsigned int v3; // esi
  RemoteSessionResult r; // [esp+Ch] [ebp-44h] BYREF
  int v5; // [esp+4Ch] [ebp-4h]

  if ( !this->sim->client )
    return this->currentSession.leaderCompletedLaps;
  v2 = ACClient::getCurrentSessionResults(this->sim->client);
  std::vector<Mesh *>::vector<Mesh *>(
    (std::vector<TyreThermalPatch *> *)&r,
    (const std::vector<TyreThermalPatch *> *)v2);
  v5 = 0;
  std::vector<Mesh *>::vector<Mesh *>(
    (std::vector<TyreThermalPatch *> *)&r.times,
    (const std::vector<TyreThermalPatch *> *)&v2->times);
  LOBYTE(v5) = 1;
  std::vector<Mesh *>::vector<Mesh *>(
    (std::vector<TyreThermalPatch *> *)&r.lapCounter,
    (const std::vector<TyreThermalPatch *> *)&v2->lapCounter);
  LOBYTE(v5) = 2;
  std::vector<unsigned int>::vector<unsigned int>(&r.hasFinished._Myvec, &v2->hasFinished._Myvec);
  r.hasFinished._Mysize = v2->hasFinished._Mysize;
  r.leaderLapCount = v2->leaderLapCount;
  v3 = r.leaderLapCount;
  RemoteSessionResult::~RemoteSessionResult(&r);
  return v3;
}
std::vector<LeaderboardEntry> *RaceManager::getLeaderboard(RaceManager *this, std::vector<LeaderboardEntry> *result)
{
  std::vector<LeaderboardEntry> *v3; // eax
  RaceTimingServices *v4; // ecx

  if ( ReplayManager::isInReplaymode(this->sim->replayManager) )
  {
    ReplayManager::getLeaderboard(this->sim->replayManager, result);
    v3 = result;
  }
  else if ( this->sim->client )
  {
    std::vector<LeaderboardEntry>::vector<LeaderboardEntry>(result, &this->mpCacheLeaderboard);
    v3 = result;
  }
  else
  {
    v4 = this->raceTimingServices;
    if ( v4 )
    {
      RaceTimingServices::getLeaderboard(v4, result);
      v3 = result;
    }
    else
    {
      v3 = result;
      result->_Myfirst = 0;
      result->_Mylast = 0;
      result->_Myend = 0;
    }
  }
  return v3;
}
std::vector<LeaderboardEntry> *RaceManager::getLeaderboardFromSession(RaceManager *this, std::vector<LeaderboardEntry> *result, int sessionID)
{
  ACClient *v4; // ecx
  int v6; // ecx

  v4 = this->sim->client;
  if ( v4 )
  {
    if ( sessionID >= ACClient::getCurrentSessionIndex(v4) )
    {
LABEL_3:
      RaceManager::getLeaderboard(this, result);
      return result;
    }
    v6 = sessionID;
  }
  else
  {
    if ( sessionID >= this->currentSessionIndex )
      goto LABEL_3;
    v6 = sessionID;
  }
  std::vector<LeaderboardEntry>::vector<LeaderboardEntry>(result, &this->leaderboardHistory._Myfirst[v6]);
  return result;
}
std::vector<std::wstring> *RaceManager::getModelSkins(RaceManager *this, std::vector<std::wstring> *result, const std::wstring *model)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  std::wstring _Left; // [esp+10h] [ebp-58h] BYREF
  std::wstring v7; // [esp+28h] [ebp-40h] BYREF
  std::wstring v8; // [esp+40h] [ebp-28h] BYREF
  int v9; // [esp+64h] [ebp-4h]

  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  v9 = 0;
  v3 = std::operator+<wchar_t>(&v8, &_Left, model);
  LOBYTE(v9) = 1;
  v4 = std::operator+<wchar_t>(&v7, v3, L"/skins/*.*");
  LOBYTE(v9) = 2;
  Path::getFolders(result, v4);
  if ( v7._Myres >= 8 )
    operator delete(v7._Bx._Ptr);
  v7._Myres = 7;
  v7._Mysize = 0;
  v7._Bx._Buf[0] = 0;
  if ( v8._Myres >= 8 )
    operator delete(v8._Bx._Ptr);
  v8._Myres = 7;
  v8._Mysize = 0;
  v8._Bx._Buf[0] = 0;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  return result;
}
unsigned __int16 RaceManager::getPitWindowEnd(RaceManager *this)
{
  ACClient *v1; // eax
  unsigned __int16 result; // ax

  v1 = this->sim->client;
  if ( v1 )
    result = v1->pitWindowEnd;
  else
    result = 0;
  return result;
}
unsigned __int16 RaceManager::getPitWindowStart(RaceManager *this)
{
  ACClient *v1; // eax
  unsigned __int16 result; // ax

  v1 = this->sim->client;
  if ( v1 )
    result = v1->pitWindowStart;
  else
    result = 0;
  return result;
}
std::wstring *RaceManager::getPracticeQualifyText(RaceManager *this, std::wstring *result)
{
  RaceManager *v3; // ebx
  double v4; // xmm0_8
  ACClient *v5; // ecx
  Sim *v6; // ecx
  ACClient *v7; // eax
  bool v8; // bl
  bool v9; // bl
  bool v10; // bl
  Sim *v11; // ecx
  bool v12; // bl
  CarAvatar *v13; // eax
  bool v14; // bl
  std::wstring text; // [esp+1Ch] [ebp-A0h] BYREF
  std::wstring v17; // [esp+34h] [ebp-88h] BYREF
  Session v18; // [esp+4Ch] [ebp-70h] BYREF
  int v19; // [esp+B8h] [ebp-4h]

  v3 = this->sim->raceManager;
  if ( ReplayManager::isInReplaymode(v3->sim->replayManager) )
  {
    v4 = DOUBLE_N1_0;
  }
  else
  {
    v5 = v3->sim->client;
    if ( v5 )
      v4 = ACClient::getSessionTimeLeft(v5);
    else
      v4 = v3->currentSession.durationMinutes * 60.0 * 1000.0 + v3->currentSession.startTime - v3->game->gameTime.now;
  }
  if ( (int)v4 >= 0 )
  {
    timeToWString(result, (int)v4, 0, 0);
    return result;
  }
  v6 = this->sim;
  v7 = v6->client;
  if ( v7 )
  {
    if ( v7->hasPlayerFinished )
    {
      v8 = RaceManager::getCurrentSession(v6->raceManager, &v18)->sessionType == Pratice;
      Session::~Session(&v18);
      if ( v8 )
      {
        std::wstring::wstring(&text, L"PRACTICE OVER");
        v19 = 0;
LABEL_12:
        acTranslate(result, &text);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
        return result;
      }
      v9 = RaceManager::getCurrentSession(this->sim->raceManager, &v18)->sessionType == Qualify;
      Session::~Session(&v18);
      if ( v9 )
      {
        std::wstring::wstring(&text, L"QUALIFY OVER");
        v19 = 1;
        goto LABEL_12;
      }
    }
  }
  else
  {
    v10 = RaceManager::getCurrentSession(v6->raceManager, &v18)->sessionType == Pratice;
    Session::~Session(&v18);
    v11 = this->sim;
    if ( v10 )
    {
      v12 = RaceManager::getCurrentSession(v11->raceManager, &v18)->durationMinutes != 0.0;
      Session::~Session(&v18);
      if ( !v12 )
      {
        std::wstring::wstring(result, word_17BE9D8);
        return result;
      }
      std::wstring::wstring(&text, L"PRACTICE OVER");
      v19 = 2;
      goto LABEL_12;
    }
    v13 = Sim::getCar(v11, 0);
    if ( RaceManager::getHasCompletedFlag(this, v13) )
    {
      v14 = RaceManager::getCurrentSession(this->sim->raceManager, &v18)->sessionType == Qualify;
      Session::~Session(&v18);
      if ( v14 )
      {
        std::wstring::wstring(&text, L"QUALIFY OVER");
        v19 = 3;
        goto LABEL_12;
      }
    }
  }
  std::wstring::wstring(&v17, L"OVERTIME");
  v19 = 4;
  acTranslate(result, &v17);
  if ( v17._Myres >= 8 )
    operator delete(v17._Bx._Ptr);
  return result;
}
std::wstring *RaceManager::getRaceText(RaceManager *this, std::wstring *result)
{
  ACClient *v3; // eax
  std::wstring *v4; // esi
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  int v7; // ebx
  Sim *v8; // ecx
  unsigned __int16 v9; // ax
  std::wstring *v10; // esi
  std::wstring *v11; // eax
  std::wstring *v12; // eax
  std::wstring *v13; // eax
  ACClient *v14; // ecx
  unsigned int v15; // ebp
  CarAvatar *v16; // eax
  int v17; // eax
  unsigned int v18; // ebx
  const std::wstring *v19; // eax
  std::wostream *v20; // eax
  std::wstring *v21; // ebx
  ACClient *v22; // eax
  std::wstring *v23; // eax
  ACClient *v24; // eax
  unsigned __int16 v25; // ax
  std::wstring *v26; // eax
  std::wstring *v27; // eax
  const std::wstring *v28; // eax
  const char *v30; // [esp-4h] [ebp-1C4h]
  float timeToStart; // [esp+18h] [ebp-1A8h]
  float timeToStarta; // [esp+18h] [ebp-1A8h]
  long double v33; // [esp+20h] [ebp-1A0h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v34; // [esp+28h] [ebp-198h] BYREF
  Session ses; // [esp+D8h] [ebp-E8h] BYREF
  std::wstring v36; // [esp+138h] [ebp-88h] BYREF
  std::wstring v37; // [esp+150h] [ebp-70h] BYREF
  std::wstring textToRender; // [esp+168h] [ebp-58h] BYREF
  std::wstring v39; // [esp+180h] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement text; // [esp+198h] [ebp-28h] BYREF
  int v41; // [esp+1BCh] [ebp-4h]

  RaceManager::getCurrentSession(this, &ses);
  v41 = 0;
  if ( ses.isTimedRace )
  {
    timeToStart = RaceManager::getTimeToSessionStart(this);
    if ( timeToStart >= 10000.0 )
    {
      v3 = this->sim->client;
      if ( v3 && LOWORD(v3->pitWindowStart) )
      {
        std::wstring::wstring(
          &text.name,
          L"Remember to add min. 1 litre of fuel or do a tyre change while the Pit Window is open");
        LOBYTE(v41) = 1;
        v4 = acTranslate(&v36, &text.name);
        LOBYTE(v41) = 2;
        v5 = timeToWString(&v37, (int)timeToStart, 0, 0);
        LOBYTE(v41) = 3;
        v6 = std::operator+<wchar_t>(&v39, v5, L" - ");
        LOBYTE(v41) = 4;
        std::operator+<wchar_t>(result, v6, v4);
        if ( v39._Myres >= 8 )
          operator delete(v39._Bx._Ptr);
        v39._Myres = 7;
        v39._Mysize = 0;
        v39._Bx._Buf[0] = 0;
        if ( v37._Myres >= 8 )
          operator delete(v37._Bx._Ptr);
        v37._Myres = 7;
        v37._Mysize = 0;
        v37._Bx._Buf[0] = 0;
        if ( v36._Myres >= 8 )
          operator delete(v36._Bx._Ptr);
        v36._Myres = 7;
        v36._Mysize = 0;
        v36._Bx._Buf[0] = 0;
        if ( text.name._Myres >= 8 )
          operator delete(text.name._Bx._Ptr);
        text.name._Myres = 7;
        text.name._Mysize = 0;
        text.name._Bx._Buf[0] = 0;
        Session::~Session(&ses);
        return result;
      }
      timeToWString(result, (int)timeToStart, 0, 0);
LABEL_15:
      Session::~Session(&ses);
      return result;
    }
    v33 = RaceManager::getSessionTimeLeft(this);
    v7 = (int)v33;
    if ( (int)v33 <= 0 )
    {
      v14 = this->sim->client;
      if ( v14 )
      {
        if ( v14->hasPlayerFinished )
        {
          std::wstring::wstring(&v36, L"RACE OVER");
          LOBYTE(v41) = 9;
        }
        else if ( v14->hasLeaderFinished )
        {
          std::wstring::wstring(&v36, L"FINAL LAP");
          LOBYTE(v41) = 10;
        }
        else if ( !v14->hasExtraLap || v14->isLastLap )
        {
          std::wstring::wstring(&v36, L"LEADER IS ON FINAL LAP");
          LOBYTE(v41) = 12;
        }
        else
        {
          std::wstring::wstring(&v36, L"LEADER HAS 2 LAPS TO GO");
          LOBYTE(v41) = 11;
        }
        acTranslate(result, &v36);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v36);
        Session::~Session(&ses);
        return result;
      }
    }
    else
    {
      v8 = this->sim;
      if ( ses.startTime < v8->game->gameTime.now )
      {
        if ( this->pitWindowStartTime > 0.0
          && this->pitWindowEndTime == 0.0
          && !Sim::getCar(v8, 0)->mandatoryPitstopDone )
        {
          v9 = RaceManager::getPitWindowEnd(this);
          v10 = timeToWString(
                  &text.name,
                  (int)((double)(60000 * v9) - (this->game->gameTime.now - ses.startTime)),
                  0,
                  0);
          LOBYTE(v41) = 5;
          v11 = timeToWString(&v39, v7, 0, 0);
          LOBYTE(v41) = 6;
          v12 = std::operator+<wchar_t>(&v37, v11, L"  -  PIT OPEN (");
          LOBYTE(v41) = 7;
          v13 = std::operator+<wchar_t>(&v36, v12, v10);
          LOBYTE(v41) = 8;
          std::operator+<wchar_t>(result, v13, L")");
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v36);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v37);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v39);
          std::wstring::~wstring(&text);
          Session::~Session(&ses);
          return result;
        }
        timeToWString(result, v7, 0, 0);
        goto LABEL_15;
      }
    }
    std::wstring::wstring(result, word_17BE9D8);
    Session::~Session(&ses);
    return result;
  }
  *(_DWORD *)v34.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v34.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v34.gap68);
  LOBYTE(v41) = 13;
  std::wiostream::basic_iostream<wchar_t>(&v34, &v34.gap10[8], 0);
  v41 = 14;
  *(_DWORD *)&v34.gap0[*(_DWORD *)(*(_DWORD *)v34.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v33 + *(_DWORD *)(*(_DWORD *)v34.gap0 + 4) + 4) = *(_DWORD *)(*(_DWORD *)v34.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v34.gap10[8]);
  *(_DWORD *)&v34.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v34.gap10[64] = 0;
  *(_DWORD *)&v34.gap10[68] = 0;
  LOBYTE(v41) = 16;
  v15 = RaceManager::getLeaderLapCount(this);
  v16 = Sim::getCar(this->sim, 0);
  v17 = RaceManager::getLapCount(this, v16);
  v18 = ses.laps;
  LODWORD(v33) = v17;
  timeToStarta = RaceManager::getTimeToSessionStart(this);
  if ( timeToStarta < 10000.0 )
  {
    std::wostream::operator<<(v34.gap10, v15 + 1);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&v34.gap10[4], L" / ");
    v20 = (std::wostream *)std::wostream::operator<<(&v34.gap10[4], v18);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v20, v30);
  }
  else
  {
    v19 = timeToWString(&v36, (int)timeToStarta, 0, 0);
    LOBYTE(v41) = 17;
    std::operator<<<wchar_t>((std::wostream *)v34.gap10, v19);
    LOBYTE(v41) = 16;
    if ( v36._Myres >= 8 )
      operator delete(v36._Bx._Ptr);
  }
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v34, &textToRender);
  LOBYTE(v41) = 18;
  if ( v15 == v18 - 1 )
  {
    std::wstring::wstring(&v37, L"LEADER IS ON FINAL LAP");
    LOBYTE(v41) = 19;
    v21 = acTranslate(&v36, &v37);
    if ( &textToRender != v21 )
    {
      if ( textToRender._Myres >= 8 )
        operator delete(textToRender._Bx._Ptr);
      textToRender._Myres = 7;
      textToRender._Mysize = 0;
      textToRender._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&textToRender, v21);
    }
    if ( v36._Myres >= 8 )
      operator delete(v36._Bx._Ptr);
    v36._Myres = 7;
    v36._Mysize = 0;
    v36._Bx._Buf[0] = 0;
    LOBYTE(v41) = 18;
    if ( v37._Myres >= 8 )
      operator delete(v37._Bx._Ptr);
  }
  else if ( v15 >= v18 )
  {
    v22 = this->sim->client;
    if ( v22 )
    {
      if ( v22->hasPlayerFinished )
      {
        std::wstring::wstring(&v36, L"RACE OVER");
        LOBYTE(v41) = 21;
      }
      else
      {
        std::wstring::wstring(&v36, L"FINAL LAP");
        LOBYTE(v41) = 20;
      }
    }
    else if ( LODWORD(v33) >= v18 )
    {
      std::wstring::wstring(&v36, L"RACE OVER");
      LOBYTE(v41) = 23;
    }
    else
    {
      std::wstring::wstring(&v36, L"FINAL LAP");
      LOBYTE(v41) = 22;
    }
    v23 = acTranslate(&v37, &v36);
    std::wstring::operator=(&textToRender, v23);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v37);
    LOBYTE(v41) = 18;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v36);
  }
  if ( this->pitWindowStartTime > 0.0
    && this->pitWindowEndTime == 0.0
    && !Sim::getCar(this->sim, 0)->mandatoryPitstopDone )
  {
    v24 = this->sim->raceManager->sim->client;
    if ( v24 )
      v25 = v24->pitWindowEnd;
    else
      v25 = 0;
    v26 = std::to_wstring(&v39, v25 - v15 - 2);
    LOBYTE(v41) = 24;
    v27 = std::operator+<wchar_t>(&v37, L"  -  PIT OPEN (", v26);
    LOBYTE(v41) = 25;
    v28 = std::operator+<wchar_t>(&v36, v27, L"L)");
    LOBYTE(v41) = 26;
    std::wstring::append(&textToRender, v28, 0, 0xFFFFFFFF);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v36);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v37);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v39);
  }
  std::wstring::wstring(result, &textToRender);
  if ( textToRender._Myres >= 8 )
    operator delete(textToRender._Bx._Ptr);
  textToRender._Myres = 7;
  textToRender._Bx._Buf[0] = 0;
  LOBYTE(v41) = 0;
  textToRender._Mysize = 0;
  *(_DWORD *)&v34.gap0[*(_DWORD *)(*(_DWORD *)v34.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v33 + *(_DWORD *)(*(_DWORD *)v34.gap0 + 4) + 4) = *(_DWORD *)(*(_DWORD *)v34.gap0 + 4) - 104;
  *(_DWORD *)&v34.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v34.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v34.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v34.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v34.gap68);
  if ( ses.name._Myres >= 8 )
    operator delete(ses.name._Bx._Ptr);
  ses.name._Myres = 7;
  ses.name._Mysize = 0;
  ses.name._Bx._Buf[0] = 0;
  if ( ses.spawSet._Myres >= 8 )
    operator delete(ses.spawSet._Bx._Ptr);
  return result;
}
int RaceManager::getSessionCount(RaceManager *this)
{
  ACClient *v2; // ecx
  int result; // eax

  v2 = this->sim->client;
  if ( v2 )
    result = ACClient::getSessionCount(v2);
  else
    result = this->sessions._Mylast - this->sessions._Myfirst;
  return result;
}
OnSessionEndEvent *RaceManager::getSessionHistory(RaceManager *this, OnSessionEndEvent *result, const int *sessionID)
{
  if ( (unsigned int)(this->sessionHistoryList._Mylast - this->sessionHistoryList._Myfirst) <= *sessionID )
  {
    Session::Session(&result->currentSession);
    SessionResult::SessionResult(&result->result);
  }
  else
  {
    OnSessionEndEvent::OnSessionEndEvent(result, &this->sessionHistoryList._Myfirst[*sessionID]);
  }
  return result;
}
Session *RaceManager::getSessionInfo(RaceManager *this, Session *result, int sessionIndex)
{
  ACClient *v4; // ecx
  const RemoteSession *v5; // eax
  RemoteSession v7; // [esp+14h] [ebp-48h] BYREF
  int v8; // [esp+58h] [ebp-4h]

  v4 = this->sim->client;
  if ( v4 )
  {
    v5 = ACClient::getSessionInfo(v4, &v7, sessionIndex);
    v8 = 0;
    RaceManager::convertRemoteSession(this, result, v5);
    if ( v7.name._Myres >= 8 )
      operator delete(v7.name._Bx._Ptr);
  }
  else if ( sessionIndex < 0 || sessionIndex >= (unsigned int)(this->sessions._Mylast - this->sessions._Myfirst) )
  {
    Session::Session(result);
  }
  else
  {
    Session::Session(result, &this->sessions._Myfirst[sessionIndex]);
  }
  return result;
}
long double RaceManager::getSessionTimeLeft(RaceManager *this)
{
  long double result; // st7
  ACClient *v3; // ecx

  if ( ReplayManager::isInReplaymode(this->sim->replayManager) )
    return -1.0;
  v3 = this->sim->client;
  if ( v3 )
    result = ACClient::getSessionTimeLeft(v3);
  else
    result = this->currentSession.durationMinutes * 60.0 * 1000.0
           + this->currentSession.startTime
           - this->game->gameTime.now;
  return result;
}
int RaceManager::getSessionTotalTime(RaceManager *this, unsigned int carIndex)
{
  Sim *v3; // ecx
  RemoteSessionResult *v4; // eax
  int v5; // esi
  int result; // eax
  CarAvatar *v7; // eax
  RemoteSessionResult results; // [esp+Ch] [ebp-38h] BYREF

  v3 = this->sim;
  if ( v3->client )
  {
    if ( RaceManager::getCurrentSessionType(this) == Race && RaceManager::getTimeToSessionStart(this) < 0.0 )
    {
      v4 = ACClient::getCurrentSessionResults(this->sim->client);
      RemoteSessionResult::RemoteSessionResult(&results, v4);
      if ( carIndex < results.times._Mylast - results.times._Myfirst )
      {
        v5 = results.times._Myfirst[carIndex];
        RemoteSessionResult::~RemoteSessionResult(&results);
        return v5;
      }
      RemoteSessionResult::~RemoteSessionResult(&results);
    }
    result = 0;
  }
  else
  {
    v7 = Sim::getCar(v3, carIndex);
    result = (int)RaceTimingServices::getTotalTime(this->raceTimingServices, v7);
  }
  return result;
}
int RaceManager::getSplit(RaceManager *this, CarAvatar *car)
{
  Sim *v3; // ecx
  RaceTimingServices *v4; // ecx
  int result; // eax

  v3 = this->sim;
  if ( (!v3->client || car == Sim::getCar(v3, 0)) && (v4 = this->raceTimingServices) != 0 )
    result = RaceTimingServices::getSplit(v4, car);
  else
    result = -1;
  return result;
}
unsigned int RaceManager::getSplit(RaceManager *this, CarAvatar *car, const int *sector)
{
  unsigned int result; // eax
  ACClient *v4; // ecx

  if ( this->raceTimingServices )
    return RaceTimingServices::getSplit(this->raceTimingServices, car, sector);
  v4 = this->sim->client;
  if ( v4 )
    result = ACClient::getSplit(v4, car, sector);
  else
    result = 0;
  return result;
}
double RaceManager::getTimeToSessionStart(RaceManager *this)
{
  ACClient *v2; // ecx
  double v4; // [esp+4h] [ebp-44h]
  RemoteSession result; // [esp+Ch] [ebp-3Ch] BYREF

  v2 = this->sim->client;
  if ( !v2 )
    return this->currentSession.startTime - this->game->gameTime.now;
  v4 = ACClient::getCurrentSession(v2, &result)->startTime - this->game->gameTime.now;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  return v4;
}
long double RaceManager::getTimetoWait(RaceManager *this)
{
  ACClient *v1; // ecx
  long double result; // st7

  v1 = this->sim->client;
  if ( v1 )
    result = ACClient::getTimetoWait(v1);
  else
    result = 0.0;
  return result;
}
bool RaceManager::hasExtraLap(RaceManager *this)
{
  ACClient *v1; // eax
  bool result; // al

  v1 = this->sim->client;
  if ( v1 )
    result = v1->hasExtraLap;
  else
    result = 0;
  return result;
}
bool RaceManager::hasSessionStarted(RaceManager *this)
{
  ACClient *v2; // ecx
  bool v3; // bl
  RemoteSession result; // [esp+4h] [ebp-3Ch] BYREF

  v2 = this->sim->client;
  if ( !v2 )
    return this->game->gameTime.now > this->currentSession.startTime;
  v3 = this->game->gameTime.now > ACClient::getCurrentSession(v2, &result)->startTime;
  if ( result.name._Myres >= 8 )
    operator delete(result.name._Bx._Ptr);
  return v3;
}
void RaceManager::initGhostcar(RaceManager *this, INIReaderDocuments *ini)
{
  bool v3; // bh
  bool v4; // bl
  CarAvatar *v5; // eax
  BOOL gplay; // [esp+10h] [ebp-78h]
  std::wstring section; // [esp+18h] [ebp-70h] BYREF
  std::wstring v8; // [esp+30h] [ebp-58h] BYREF
  std::wstring v9; // [esp+48h] [ebp-40h] BYREF
  std::wstring key; // [esp+60h] [ebp-28h] BYREF
  int v11; // [esp+84h] [ebp-4h]

  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"RECORDING", 9u);
  v11 = 0;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"GHOST_CAR", 9u);
  LOBYTE(v11) = 1;
  v3 = INIReader::getInt(ini, &section, &key) != 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  v11 = -1;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v8._Myres = 7;
  v8._Mysize = 0;
  v8._Bx._Buf[0] = 0;
  std::wstring::assign(&v8, L"PLAYING", 7u);
  v11 = 2;
  v9._Myres = 7;
  v9._Mysize = 0;
  v9._Bx._Buf[0] = 0;
  std::wstring::assign(&v9, L"GHOST_CAR", 9u);
  LOBYTE(v11) = 3;
  v4 = INIReader::getInt(ini, &v9, &v8) != 0;
  LOBYTE(gplay) = v4;
  if ( v9._Myres >= 8 )
    operator delete(v9._Bx._Ptr);
  v9._Myres = 7;
  v9._Mysize = 0;
  v9._Bx._Buf[0] = 0;
  v11 = -1;
  if ( v8._Myres >= 8 )
    operator delete(v8._Bx._Ptr);
  v8._Myres = 7;
  v8._Mysize = 0;
  v8._Bx._Buf[0] = 0;
  if ( v3 || v4 )
  {
    this->sim->beforeCarsNode->isActive = 1;
    v5 = Sim::getCar(this->sim, 0);
    CarAvatar::initGhostCar(v5, v3, gplay);
  }
}
void RaceManager::initLighting(RaceManager *this, INIReaderDocuments *ini)
{
  bool v3; // al
  float *v4; // esi
  SunAnimator *v5; // eax
  float v6; // eax
  float v7; // edi
  Sim *v8; // esi
  float v9; // xmm0_4
  bool v10; // [esp+1Fh] [ebp-55h]
  float cloudspeed; // [esp+20h] [ebp-54h] BYREF
  float v12; // [esp+24h] [ebp-50h] BYREF
  float sunangle; // [esp+28h] [ebp-4Ch]
  int v14[2]; // [esp+2Ch] [ebp-48h] BYREF
  std::wstring section; // [esp+34h] [ebp-40h] BYREF
  std::wstring key; // [esp+4Ch] [ebp-28h] BYREF
  int v17; // [esp+70h] [ebp-4h]

  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"LIGHTING", 8u);
  v17 = 0;
  v3 = INIReader::hasSection(ini, &section);
  v10 = v3;
  v17 = -1;
  if ( section._Myres >= 8 )
  {
    operator delete(section._Bx._Ptr);
    v3 = v10;
  }
  if ( v3 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SUN_ANGLE", 9u);
    v17 = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"LIGHTING", 8u);
    LOBYTE(v17) = 2;
    sunangle = INIReader::getFloat(ini, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    v17 = -1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v14[0] = 1065353216;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"TIME_MULT", 9u);
    v17 = 3;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"LIGHTING", 8u);
    LOBYTE(v17) = 4;
    v4 = (float *)v14;
    v12 = INIReader::getFloat(ini, &section, &key);
    if ( v12 >= 1.0 )
      v4 = &v12;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    v17 = -1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"CLOUD_SPEED", 0xBu);
    v17 = 5;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"LIGHTING", 8u);
    LOBYTE(v17) = 6;
    cloudspeed = INIReader::getFloat(ini, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    v17 = -1;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v5 = (SunAnimator *)operator new(88);
    v14[1] = (int)v5;
    v17 = 7;
    if ( v5 )
    {
      SunAnimator::SunAnimator(v5, this->sim, sunangle, *v4, cloudspeed);
      v7 = v6;
    }
    else
    {
      v7 = 0.0;
    }
    v8 = this->sim;
    v17 = -1;
    cloudspeed = v7;
    std::vector<SpinnerData *>::push_back(
      (std::vector<ICollisionObject *> *)&v8->gameObjects,
      (ICollisionObject *const *)&cloudspeed);
    v9 = sunangle;
    *(_DWORD *)(LODWORD(v7) + 36) = v8;
    this->game->graphics->lightingSettings.angle = v9;
    GraphicsManager::updateLightingSetttings(this->game->graphics);
  }
}
char __userpurge RaceManager::initOffline@<al>(RaceManager *this@<ecx>, __m128 a2@<xmm0>, __m128 a3@<xmm3>, __m128 a4@<xmm4>, INIReaderDocuments *anIniReader)
{
  char v6; // al
  char v7; // al
  void (*v8)(const char *const, ...); // esi
  unsigned int v9; // edi
  std::wostream *v10; // eax
  std::wostream *v11; // eax
  const std::wstring *v12; // eax
  char v13; // al
  const std::wstring *v14; // eax
  std::wstring *v15; // eax
  const std::wstring *v16; // esi
  const std::wstring *v17; // eax
  std::vector<char> *v18; // eax
  const std::wstring *v19; // eax
  std::wstring *v20; // edi
  const wchar_t *v21; // eax
  std::wstring *v22; // ebx
  std::wstring *i; // esi
  std::wstring *v24; // eax
  const wchar_t *v25; // ecx
  std::wstring *v26; // ebx
  std::wstring *v27; // esi
  RaceManager *v28; // edi
  int v29; // ebx
  std::wostream *v30; // eax
  const std::wstring *v31; // eax
  char v32; // al
  const std::wstring *v33; // eax
  std::wstring *v34; // esi
  const std::wstring *v35; // eax
  const std::wstring *v36; // eax
  int v37; // eax
  const std::wstring *v38; // eax
  const std::wstring *v39; // eax
  int v40; // eax
  const std::wstring *v41; // eax
  int v42; // eax
  bool v43; // cf
  std::wstring *v44; // esi
  const std::wstring *v45; // eax
  const std::wstring *v46; // eax
  std::wstring *v47; // esi
  Session *v48; // eax
  const std::wstring *v49; // esi
  const std::wstring *v50; // eax
  Sim *v51; // ecx
  TrackAvatar *v52; // esi
  TyreCompoundDef *v53; // eax
  bool v54; // al
  bool v55; // bl
  bool v56; // al
  bool v57; // bl
  float v58; // xmm0_4
  int *v59; // eax
  int v60; // eax
  PhysicsAvatar *v61; // esi
  double v62; // st7
  int v63; // edi
  std::wostream *v64; // eax
  const std::wstring *v65; // eax
  bool v66; // al
  bool v67; // bl
  const std::wstring *v68; // eax
  const std::wstring *v69; // eax
  const std::wstring *v70; // eax
  std::wstring *v71; // eax
  const std::wstring *v72; // eax
  const std::wstring *v73; // eax
  char v74; // bl
  const std::wstring *v75; // eax
  RaceManager *v76; // ebx
  std::wstring *v77; // eax
  std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,int> > > > *v78; // eax
  unsigned int v79; // esi
  unsigned int *v80; // eax
  const std::wstring *v81; // eax
  unsigned int *v82; // eax
  unsigned int *v83; // esi
  CarAvatar *v84; // eax
  CarAvatar *v85; // esi
  const std::wstring *v86; // eax
  int v87; // eax
  const std::wstring *v88; // eax
  std::wostream *v89; // eax
  const std::wstring *v90; // eax
  std::wstring *v91; // eax
  const std::wstring *v92; // eax
  char v93; // bl
  const std::wstring *v94; // eax
  std::wstring *v95; // eax
  const std::wstring *v96; // eax
  std::wstring *v97; // eax
  const std::wstring *v98; // eax
  char v99; // bl
  const std::wstring *v100; // eax
  std::wstring *v101; // eax
  AIDriverDrag *v102; // ebx
  RaceEngineer *v103; // eax
  Car *v104; // eax
  int v105; // eax
  RaceManager::initOffline::__l127::<lambda_5c8e18c6096c34f7d85a3c1b4614f402> *v106; // eax
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *v107; // ebx
  unsigned int v108; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v109; // ecx
  int v110; // ebx
  RaceManager *v111; // esi
  bool v112; // bl
  PhysicsAvatar *v113; // ecx
  char v114; // bl
  JumpStartPenaltyMode v115; // edi
  __int16 v116; // ax
  std::_Tree_node<std::pair<std::wstring const ,enum DynamicControllerInput>,void *> *v117; // eax
  PitCrew *v118; // eax
  PitCrew *v119; // eax
  bool v120; // al
  bool v121; // bl
  const std::wstring *v122; // eax
  Sim *v123; // ecx
  Sim *v124; // ecx
  PhysicsAvatar *v125; // eax
  int v126; // ebx
  int v127; // edi
  unsigned int j; // edi
  CarAvatar *v129; // eax
  std::wstring *v130; // eax
  _BYTE v[56]; // [esp+Ch] [ebp-760h] BYREF
  int v133; // [esp+68h] [ebp-704h]
  float dir; // [esp+6Ch] [ebp-700h] BYREF
  int v135; // [esp+70h] [ebp-6FCh] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Session> > > _S24; // [esp+74h] [ebp-6F8h] BYREF
  float ballast; // [esp+78h] [ebp-6F4h]
  float smax; // [esp+7Ch] [ebp-6F0h] BYREF
  int ncars; // [esp+80h] [ebp-6ECh] BYREF
  float global_ai_level; // [esp+84h] [ebp-6E8h] BYREF
  float ref; // [esp+88h] [ebp-6E4h]
  double var; // [esp+8Ch] [ebp-6E0h] OVERLAPPED BYREF
  int v143; // [esp+94h] [ebp-6D8h]
  RaceManager *v144; // [esp+A0h] [ebp-6CCh]
  std::map<std::wstring,int> currentSkin; // [esp+A4h] [ebp-6C8h] BYREF
  INIReader *v146; // [esp+ACh] [ebp-6C0h]
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *v147; // [esp+B0h] [ebp-6BCh]
  int v148; // [esp+B4h] [ebp-6B8h]
  std::vector<std::wstring> sections; // [esp+B8h] [ebp-6B4h] BYREF
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,enum DynamicControllerInput> > > > v150; // [esp+C4h] [ebp-6A8h] BYREF
  std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > v151; // [esp+C8h] [ebp-6A4h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v152; // [esp+CCh] [ebp-6A0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v153; // [esp+17Ch] [ebp-5F0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > ssINI; // [esp+22Ch] [ebp-540h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v155; // [esp+2DCh] [ebp-490h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > ssCar; // [esp+38Ch] [ebp-3E0h] BYREF
  std::wstring cconfig; // [esp+43Ch] [ebp-330h] BYREF
  std::wstring section; // [esp+454h] [ebp-318h] BYREF
  std::wstring cmodel; // [esp+46Ch] [ebp-300h] BYREF
  std::vector<std::wstring> skins; // [esp+484h] [ebp-2E8h] BYREF
  int v161; // [esp+494h] [ebp-2D8h]
  unsigned int v162; // [esp+498h] [ebp-2D4h]
  std::wstring setName; // [esp+49Ch] [ebp-2D0h] BYREF
  std::wstring v164; // [esp+4B4h] [ebp-2B8h] BYREF
  std::wstring v165; // [esp+4CCh] [ebp-2A0h] BYREF
  INIReader r; // [esp+4E4h] [ebp-288h] BYREF
  std::wstring v167; // [esp+52Ch] [ebp-240h] BYREF
  std::wstring v168; // [esp+544h] [ebp-228h] BYREF
  std::wstring result; // [esp+55Ch] [ebp-210h] BYREF
  std::wstring v170; // [esp+574h] [ebp-1F8h] BYREF
  std::wstring model; // [esp+58Ch] [ebp-1E0h] BYREF
  std::wstring v172; // [esp+5A4h] [ebp-1C8h] BYREF
  std::wstring skin; // [esp+5BCh] [ebp-1B0h] BYREF
  Session s; // [esp+5D4h] [ebp-198h] BYREF
  std::wstring key; // [esp+634h] [ebp-138h] BYREF
  INIReader newINI; // [esp+64Ch] [ebp-120h] BYREF
  std::wstring v177; // [esp+694h] [ebp-D8h] BYREF
  std::wstring config; // [esp+6ACh] [ebp-C0h] BYREF
  DynamicTempData td; // [esp+6C4h] [ebp-A8h] BYREF
  int v180; // [esp+764h] [ebp-8h]
  int v181; // [esp+768h] [ebp-4h]
  char vars0; // [esp+76Ch] [ebp+0h]

  v144 = this;
  v146 = anIniReader;
  dir = 0.0;
  *(float *)&_S24._Ptr = 0.0;
  RaceManager::initLighting(this, anIniReader);
  INIReader::INIReader(&r, anIniReader);
  v181 = 0;
  INIReader::setVerboseMode(&r, 1);
  v162 = 7;
  v161 = 0;
  LOWORD(skins._Myfirst) = 0;
  std::wstring::assign((std::wstring *)&skins, L"AI_LEVEL", 8u);
  LOBYTE(v181) = 1;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"RACE", 4u);
  LOBYTE(v181) = 2;
  global_ai_level = INIReader::getFloat(&r, &section, (const std::wstring *)&skins);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v181) = 0;
  if ( v162 >= 8 )
    operator delete(skins._Myfirst);
  v148 = 1;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"HEADER", 6u);
  LOBYTE(v181) = 3;
  v6 = INIReader::hasSection(&r, &section);
  HIBYTE(v133) = v6;
  LOBYTE(v181) = 0;
  if ( section._Myres >= 8 )
  {
    operator delete(section._Bx._Ptr);
    v6 = HIBYTE(v133);
  }
  if ( v6 )
  {
    v162 = 7;
    v161 = 0;
    LOWORD(skins._Myfirst) = 0;
    std::wstring::assign((std::wstring *)&skins, L"VERSION", 7u);
    LOBYTE(v181) = 4;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HEADER", 6u);
    LOBYTE(v181) = 5;
    v148 = INIReader::getInt(&r, &section, (const std::wstring *)&skins);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v181) = 0;
    if ( v162 >= 8 )
      operator delete(skins._Myfirst);
  }
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"SPECIAL_EVENT", 0xDu);
  LOBYTE(v181) = 6;
  v7 = INIReader::hasSection(&r, &section);
  HIBYTE(v133) = v7;
  LOBYTE(v181) = 0;
  if ( section._Myres >= 8 )
  {
    operator delete(section._Bx._Ptr);
    v7 = HIBYTE(v133);
  }
  v8 = (void (*)(const char *const, ...))_printf;
  if ( v7 )
  {
    v162 = 7;
    v161 = 0;
    LOWORD(skins._Myfirst) = 0;
    std::wstring::assign((std::wstring *)&skins, L"GUID", 4u);
    LOBYTE(v181) = 7;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SPECIAL_EVENT", 0xDu);
    LOBYTE(v181) = 8;
    v9 = INIReader::getInt(&r, &section, (const std::wstring *)&skins);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v181) = 0;
    if ( v162 >= 8 )
      operator delete(skins._Myfirst);
    *(_DWORD *)v153.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v153.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v153.gap68);
    vars0 = 9;
    v135 = 4;
    LODWORD(ballast) = 4;
    std::wiostream::basic_iostream<wchar_t>(&v153.gap0[4], &v153.gap10[12], 0);
    v180 = 10;
    *(_DWORD *)&v152.gap68[*(_DWORD *)(*(_DWORD *)&v152.gap68[68] + 4) + 68] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)&v152.gap68[*(_DWORD *)(*(_DWORD *)&v152.gap68[68] + 4) + 64] = *(_DWORD *)(*(_DWORD *)&v152.gap68[68] + 4)
                                                                             - 104;
    std::wstreambuf::wstreambuf(&v153.gap10[4]);
    *(_DWORD *)&v153.gap10[4] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v153.gap10[60] = 0;
    *(_DWORD *)&v153.gap10[64] = 0;
    LOBYTE(v180) = 12;
    v10 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(
            (std::wostream *)((char *)&v153._Chcount + 4),
            "system/data/se/SPECIAL_EVENT_");
    v11 = (std::wostream *)std::wostream::operator<<(v10, v9);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v11, *(const char **)&v[24]);
    v12 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v153, &cconfig);
    LOBYTE(v181) = 13;
    v13 = Path::fileExists((unsigned int)this, v12, 0);
    HIBYTE(v133) = v13;
    LOBYTE(v181) = 12;
    if ( cconfig._Myres >= 8 )
    {
      operator delete(cconfig._Bx._Ptr);
      v13 = HIBYTE(v133);
    }
    if ( v13 )
    {
      *(_DWORD *)ssINI.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)ssINI.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(ssINI.gap68);
      LOBYTE(v181) = 14;
      _S24._Ptr = (Session *)12;
      std::wiostream::basic_iostream<wchar_t>(&ssINI, &ssINI.gap10[8], 0);
      v181 = 15;
      *(_DWORD *)&ssINI.gap0[*(_DWORD *)(*(_DWORD *)ssINI.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v153.gap68[*(_DWORD *)(*(_DWORD *)ssINI.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)ssINI.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&ssINI.gap10[8]);
      *(_DWORD *)&ssINI.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&ssINI.gap10[64] = 0;
      *(_DWORD *)&ssINI.gap10[68] = 0;
      LOBYTE(v181) = 17;
      v14 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v153, &cconfig);
      LOBYTE(v181) = 18;
      v15 = Path::getFileNameWithoutExtension(&result, v14);
      LOBYTE(v181) = 19;
      v16 = std::operator+<wchar_t>(&v170, L"ARUMBA_", v15);
      LOBYTE(v181) = 20;
      v17 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v153, &v165);
      LOBYTE(v181) = 21;
      v18 = SimpleFileEncrypter::decryptFile(v9, (std::vector<char> *)&var, v17, v16);
      LOBYTE(v181) = 22;
      v19 = ksDecodeUtf8(&v164, v18);
      LOBYTE(v181) = 23;
      std::operator<<<wchar_t>((std::wostream *)ssINI.gap10, v19);
      if ( v164._Myres >= 8 )
        operator delete(v164._Bx._Ptr);
      v164._Myres = 7;
      v164._Mysize = 0;
      v164._Bx._Buf[0] = 0;
      LOBYTE(v181) = 21;
      if ( LODWORD(var) )
      {
        std::_Container_base0::_Orphan_all((std::_Container_base0 *)&var);
        operator delete(LODWORD(var));
        var = 0.0;
        v143 = 0;
      }
      if ( v165._Myres >= 8 )
        operator delete(v165._Bx._Ptr);
      v165._Myres = 7;
      v165._Mysize = 0;
      v165._Bx._Buf[0] = 0;
      if ( v170._Myres >= 8 )
        operator delete(v170._Bx._Ptr);
      v170._Myres = 7;
      v170._Mysize = 0;
      v170._Bx._Buf[0] = 0;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      LOBYTE(v181) = 17;
      if ( cconfig._Myres >= 8 )
        operator delete(cconfig._Bx._Ptr);
      INIReader::INIReader(&newINI, &ssINI);
      skins._Myfirst = 0;
      skins._Mylast = 0;
      skins._Myend = 0;
      LOBYTE(v181) = 25;
      INIReader::getSections(&newINI, &skins);
      newINI.ready = 1;
      std::wstring::wstring(&cmodel, L"GUID");
      LOBYTE(v181) = 26;
      std::wstring::wstring(&section, L"SPECIAL_EVENT");
      v181 = 27;
      _S24._Ptr = (Session *)15;
      HIBYTE(v133) = v9 == INIReader::getInt(&newINI, &section, &cmodel);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Bx._Buf[0] = 0;
      section._Mysize = 0;
      v181 = 25;
      LODWORD(dir) = 12;
      if ( cmodel._Myres >= 8 )
        operator delete(cmodel._Bx._Ptr);
      if ( HIBYTE(v133) )
      {
        this->officialSpecialEvent = 1;
        INIReader::operator=(&r, &newINI);
      }
      LOBYTE(v181) = 24;
      if ( skins._Myfirst )
      {
        std::_Container_base0::_Orphan_all(&skins);
        *(float *)&v[24] = global_ai_level;
        *(_DWORD *)&v[20] = (char *)&v135 + 3;
        std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(skins._Myfirst, skins._Mylast);
        operator delete(skins._Myfirst);
        skins._Myfirst = 0;
        skins._Mylast = 0;
        skins._Myend = 0;
      }
      LOBYTE(v181) = 17;
      INIReader::~INIReader(&newINI);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&ssINI);
      v8 = (void (*)(const char *const, ...))_printf;
    }
    else
    {
      _printf("NOT LOADING OFFICIAL SPECIAL EVENT ENCRIPTED, INI IS NOT READY\n");
    }
    LOBYTE(v181) = 0;
    *(_DWORD *)&v153.gap0[*(_DWORD *)(*(_DWORD *)v153.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)&v152.gap68[*(_DWORD *)(*(_DWORD *)v153.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v153.gap0 + 4) - 104;
    *(_DWORD *)&v153.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&v153.gap10[8]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v153.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v153.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v153.gap68);
  }
  v8("-----------PRINTING RACE INI-----------\n");
  sections._Myfirst = 0;
  sections._Mylast = 0;
  sections._Myend = 0;
  LOBYTE(v181) = 28;
  INIReader::getSections(&r, &sections);
  v20 = sections._Myfirst;
  ref = *(float *)&sections._Mylast;
  if ( sections._Myfirst != sections._Mylast )
  {
    do
    {
      if ( v20->_Myres < 8 )
        v21 = (const wchar_t *)v20;
      else
        v21 = v20->_Bx._Ptr;
      v8("[%S]\n", v21);
      skins._Myfirst = 0;
      skins._Mylast = 0;
      skins._Myend = 0;
      LOBYTE(v181) = 29;
      *(_DWORD *)&v[24] = &skins;
      *(_DWORD *)&v[20] = 7;
      *(_DWORD *)&v[16] = 0;
      *(_WORD *)v = 0;
      std::wstring::assign((std::wstring *)v, v20, 0, 0xFFFFFFFF);
      INIReader::getKeyes(&r, *(std::wstring *)v, *(std::vector<std::wstring> **)&v[24]);
      v22 = skins._Mylast;
      for ( i = skins._Myfirst; i != v22; ++i )
      {
        v24 = INIReader::getString(&r, &cconfig, v20, i);
        if ( v24->_Myres >= 8 )
          v24 = (std::wstring *)v24->_Bx._Ptr;
        if ( i->_Myres < 8 )
          v25 = (const wchar_t *)i;
        else
          v25 = i->_Bx._Ptr;
        _printf("%S=%S\n", v25, v24->_Bx._Buf);
        if ( cconfig._Myres >= 8 )
          operator delete(cconfig._Bx._Ptr);
      }
      v8 = (void (*)(const char *const, ...))_printf;
      _printf("\n");
      LOBYTE(v181) = 28;
      if ( skins._Myfirst )
      {
        std::_Container_base0::_Orphan_all(&skins);
        v26 = skins._Mylast;
        v27 = skins._Myfirst;
        if ( skins._Myfirst != skins._Mylast )
        {
          do
          {
            if ( v27->_Myres >= 8 )
              operator delete(v27->_Bx._Ptr);
            v27->_Myres = 7;
            v27->_Mysize = 0;
            v27->_Bx._Buf[0] = 0;
            ++v27;
          }
          while ( v27 != v26 );
          v27 = skins._Myfirst;
        }
        operator delete(v27);
        v8 = (void (*)(const char *const, ...))_printf;
        skins._Myfirst = 0;
        skins._Mylast = 0;
        skins._Myend = 0;
      }
      ++v20;
    }
    while ( v20 != (std::wstring *)LODWORD(ref) );
  }
  v8("-----------END RACE INI-----------\n");
  v28 = v144;
  v29 = 0;
  HIBYTE(v133) = 0;
  ref = 0.0;
  while ( 1 )
  {
    *(_DWORD *)v152.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v152.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v152.gap68);
    LOBYTE(v181) = 30;
    LODWORD(dir) |= 0x10u;
    *(float *)&_S24._Ptr = dir;
    std::wiostream::basic_iostream<wchar_t>(&v152, &v152.gap10[8], 0);
    v181 = 31;
    *(_DWORD *)&v152.gap0[*(_DWORD *)(*(_DWORD *)v152.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(TyreCompoundDef **)((char *)&v151._Ptr + *(_DWORD *)(*(_DWORD *)v152.gap0 + 4)) = (TyreCompoundDef *)(*(_DWORD *)(*(_DWORD *)v152.gap0 + 4) - 104);
    std::wstreambuf::wstreambuf(&v152.gap10[8]);
    *(_DWORD *)&v152.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v152.gap10[64] = 0;
    *(_DWORD *)&v152.gap10[68] = 0;
    *(_DWORD *)&v[24] = v29;
    LOBYTE(v181) = 33;
    v30 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v152.gap10, "SESSION_");
    std::wostream::operator<<(v30, *(_DWORD *)&v[24]);
    v31 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v152, &cconfig);
    LOBYTE(v181) = 34;
    v32 = INIReader::hasSection(&r, v31);
    HIBYTE(v135) = v32;
    LOBYTE(v181) = 33;
    if ( cconfig._Myres >= 8 )
    {
      operator delete(cconfig._Bx._Ptr);
      v32 = HIBYTE(v135);
    }
    if ( !v32 )
      break;
    Session::Session(&s);
    LOBYTE(v181) = 35;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"NAME", 4u);
    LOBYTE(v181) = 36;
    v33 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v152, &v165);
    LOBYTE(v181) = 37;
    v34 = INIReader::getString(&r, &v164, v33, &section);
    if ( &s.name != v34 )
    {
      if ( s.name._Myres >= 8 )
        operator delete(s.name._Bx._Ptr);
      s.name._Myres = 7;
      s.name._Mysize = 0;
      s.name._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&s.name, v34);
    }
    if ( v164._Myres >= 8 )
      operator delete(v164._Bx._Ptr);
    v164._Myres = 7;
    v164._Mysize = 0;
    v164._Bx._Buf[0] = 0;
    if ( v165._Myres >= 8 )
      operator delete(v165._Bx._Ptr);
    v165._Myres = 7;
    v165._Mysize = 0;
    v165._Bx._Buf[0] = 0;
    LOBYTE(v181) = 35;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"TYPE", 4u);
    LOBYTE(v181) = 38;
    v35 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v152, &v164);
    LOBYTE(v181) = 39;
    s.sessionType = INIReader::getInt(&r, v35, &section);
    if ( v164._Myres >= 8 )
      operator delete(v164._Bx._Ptr);
    v164._Myres = 7;
    v164._Mysize = 0;
    v164._Bx._Buf[0] = 0;
    LOBYTE(v181) = 35;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    switch ( s.sessionType )
    {
      case Pratice:
      case Qualify:
        std::wstring::wstring(&cconfig, L"DURATION_MINUTES");
        LOBYTE(v181) = 40;
        v36 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v152, &v172);
        LOBYTE(v181) = 41;
        v37 = INIReader::getInt(&r, v36, &cconfig);
        a2 = (__m128)COERCE_UNSIGNED_INT((float)v37);
        s.durationMinutes = (float)v37;
        if ( v172._Myres >= 8 )
          operator delete(v172._Bx._Ptr);
        v172._Myres = 7;
        v172._Mysize = 0;
        v172._Bx._Buf[0] = 0;
        LOBYTE(v181) = 35;
        if ( cconfig._Myres >= 8 )
          operator delete(cconfig._Bx._Ptr);
        break;
      case Race:
        std::wstring::wstring(&section, L"LAPS");
        LOBYTE(v181) = 42;
        v38 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v152, &v168);
        LOBYTE(v181) = 43;
        s.laps = INIReader::getInt(&r, v38, &section);
        if ( v168._Myres >= 8 )
          operator delete(v168._Bx._Ptr);
        v168._Myres = 7;
        v168._Mysize = 0;
        v168._Bx._Buf[0] = 0;
        LOBYTE(v181) = 35;
        if ( section._Myres >= 8 )
          operator delete(section._Bx._Ptr);
        section._Myres = 7;
        section._Mysize = 0;
        section._Bx._Buf[0] = 0;
        s.durationMinutes = 0.0;
        s.isTimedRace = 0;
        v28->hasAdditionalLap = 0;
        if ( !s.laps )
        {
          std::wstring::wstring(&key, L"DURATION_MINUTES");
          LOBYTE(v181) = 44;
          v39 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v152, &v167);
          LOBYTE(v181) = 45;
          v40 = INIReader::getInt(&r, v39, &key);
          a2 = (__m128)COERCE_UNSIGNED_INT((float)v40);
          s.durationMinutes = (float)v40;
          if ( v167._Myres >= 8 )
            operator delete(v167._Bx._Ptr);
          v167._Myres = 7;
          v167._Mysize = 0;
          v167._Bx._Buf[0] = 0;
          LOBYTE(v181) = 35;
          if ( key._Myres >= 8 )
            operator delete(key._Bx._Ptr);
          key._Myres = 7;
          key._Mysize = 0;
          key._Bx._Buf[0] = 0;
          s.isTimedRace = 1;
          std::wstring::wstring(&result, L"ADDITITIONAL_LAP");
          LOBYTE(v181) = 46;
          v41 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v152, &setName);
          LOBYTE(v181) = 47;
          v42 = INIReader::getInt(&r, v41, &result);
          v43 = setName._Myres < 8;
          v28->hasAdditionalLap = v42 != 0;
          if ( !v43 )
            operator delete(setName._Bx._Ptr);
          setName._Myres = 7;
          setName._Mysize = 0;
          setName._Bx._Buf[0] = 0;
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          result._Myres = 7;
          result._Mysize = 0;
          result._Bx._Buf[0] = 0;
        }
        ref = *(float *)&s.laps;
        skins._Myfirst = 0;
        skins._Mylast = 0;
        skins._Myend = 0;
        LOBYTE(v181) = 48;
        *(_DWORD *)&v[24] = &skins;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
          &v152,
          (std::wstring *)v);
        INIReader::getKeyes(&r, *(std::wstring *)v, *(std::vector<std::wstring> **)&v[24]);
        v44 = skins._Mylast;
        LOBYTE(smax) = 0;
        *(float *)&v[24] = smax;
        if ( std::_Find<std::wstring *,wchar_t const [20]>(
               skins._Myfirst,
               skins._Mylast,
               (const wchar_t (*)[20])L"STARTING_POSITION") == v44 )
        {
          std::wstring::wstring(&v164, L"CARS");
          LOBYTE(v181) = 51;
          std::wstring::wstring(&v165, L"RACE");
          LOBYTE(v181) = 52;
          s.forcedPosition = INIReader::getInt(&r, &v165, &v164);
          if ( v165._Myres >= 8 )
            operator delete(v165._Bx._Ptr);
          v165._Myres = 7;
          v165._Mysize = 0;
          v165._Bx._Buf[0] = 0;
          if ( v164._Myres >= 8 )
            operator delete(v164._Bx._Ptr);
          v164._Myres = 7;
          v164._Mysize = 0;
          v164._Bx._Buf[0] = 0;
        }
        else
        {
          std::wstring::wstring(&v170, L"STARTING_POSITION");
          LOBYTE(v181) = 49;
          v45 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v152, &cmodel);
          LOBYTE(v181) = 50;
          s.forcedPosition = INIReader::getInt(&r, v45, &v170);
          if ( cmodel._Myres >= 8 )
            operator delete(cmodel._Bx._Ptr);
          cmodel._Myres = 7;
          cmodel._Mysize = 0;
          cmodel._Bx._Buf[0] = 0;
          if ( v170._Myres >= 8 )
            operator delete(v170._Bx._Ptr);
          v170._Myres = 7;
          v170._Mysize = 0;
          v170._Bx._Buf[0] = 0;
        }
        LOBYTE(v181) = 35;
        if ( skins._Myfirst )
        {
          std::_Container_base0::_Orphan_all(&skins);
          *(float *)&v[24] = global_ai_level;
          *(_DWORD *)&v[20] = (char *)&v135 + 3;
          std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(skins._Myfirst, skins._Mylast);
          operator delete(skins._Myfirst);
          skins._Myfirst = 0;
          skins._Mylast = 0;
          skins._Myend = 0;
        }
        break;
      case Hotlap:
        HIBYTE(v133) = 1;
        break;
      default:
        break;
    }
    std::wstring::wstring(&cconfig, L"SPAWN_SET");
    LOBYTE(v181) = 53;
    v46 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v152, &setName);
    LOBYTE(v181) = 54;
    v47 = INIReader::getString(&r, &cmodel, v46, &cconfig);
    if ( &s.spawSet != v47 )
    {
      if ( s.spawSet._Myres >= 8 )
        operator delete(s.spawSet._Bx._Ptr);
      s.spawSet._Myres = 7;
      s.spawSet._Mysize = 0;
      s.spawSet._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&s.spawSet, v47);
    }
    if ( cmodel._Myres >= 8 )
      operator delete(cmodel._Bx._Ptr);
    cmodel._Myres = 7;
    cmodel._Mysize = 0;
    cmodel._Bx._Buf[0] = 0;
    if ( setName._Myres >= 8 )
      operator delete(setName._Bx._Ptr);
    setName._Myres = 7;
    setName._Mysize = 0;
    setName._Bx._Buf[0] = 0;
    LOBYTE(v181) = 35;
    if ( cconfig._Myres >= 8 )
      operator delete(cconfig._Bx._Ptr);
    std::vector<Session>::push_back(&v28->sessions, &s);
    Session::~Session(&s);
    LOBYTE(v181) = 28;
    ++v29;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v152);
  }
  LOBYTE(v181) = 28;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v152);
  v48 = v28->sessions._Myfirst;
  v147 = (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&v28->sessions;
  if ( v48 == v28->sessions._Mylast )
  {
    Session::Session((Session *)&newINI);
    LOBYTE(v181) = 55;
    newINI.__vftable = (INIReader_vtbl *)1;
    *(_QWORD *)newINI.filename._Bx._Buf = 0x42F0000000000000i64;
    std::wstring::assign((std::wstring *)&newINI.filename._Bx._Alias[12], L"PIT");
    a2 = 0i64;
    *(_QWORD *)v177._Bx._Buf = 0i64;
    std::vector<Session>::push_back(&v28->sessions, (const Session *)&newINI);
    LOBYTE(v181) = 28;
    Session::~Session((Session *)&newINI);
  }
  std::wstring::wstring(&v167, L"CONFIG_TRACK");
  LOBYTE(v181) = 56;
  std::wstring::wstring(&setName, L"RACE");
  LOBYTE(v181) = 57;
  std::wstring::wstring(&cmodel, L"TRACK");
  LOBYTE(v181) = 58;
  std::wstring::wstring(&cconfig, L"RACE");
  LOBYTE(v181) = 59;
  v49 = INIReader::getString(&r, &v172, &setName, &v167);
  LOBYTE(v181) = 60;
  v50 = INIReader::getString(&r, &v168, &cconfig, &cmodel);
  v51 = v28->sim;
  LOBYTE(v181) = 61;
  Sim::loadTrack(v51, a2, a3, a4, v50, v49, 0);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v168);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v172);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
  LOBYTE(v181) = 28;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v167);
  v52 = GameObject::getGameObject<TrackAvatar>(v28->sim);
  std::vector<SetupTab *>::begin(
    (std::vector<TyreCompoundDef> *)&v28->sessions,
    (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&dir);
  std::vector<Mesh *>::end(
    (std::vector<TyreCompoundDef> *)&v28->sessions,
    (std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S24);
  while ( std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<DigitalItem *>>>::operator!=(
            (std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&dir,
            (const std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&_S24) )
  {
    v53 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&dir);
    TrackAvatar::initRespawnPositionSet(v52, (const std::wstring *)&v53->name._Mysize);
    std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Session>>>::operator++((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<Session> > > *)&dir);
  }
  std::wstring::wstring(&cmodel, L"FIXED_SETUP");
  LOBYTE(v181) = 62;
  std::wstring::wstring(&cconfig, L"RACE");
  LOBYTE(v181) = 63;
  v28->fixedSetup = INIReader::getInt(&r, &cconfig, &cmodel) > 0;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
  LOBYTE(v181) = 28;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
  std::wstring::wstring(&setName, L"TEMPERATURE");
  LOBYTE(v181) = 64;
  v54 = INIReader::hasSection(&r, &setName);
  LOBYTE(v181) = 28;
  v55 = v54;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
  if ( v55 )
  {
    std::wstring::wstring(&cmodel, L"AMBIENT");
    LOBYTE(v181) = 65;
    std::wstring::wstring(&cconfig, L"TEMPERATURE");
    LOBYTE(v181) = 66;
    v28->sim->physicsAvatar->engine.ambientTemperature = INIReader::getFloat(&r, &cconfig, &cmodel);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
    LOBYTE(v181) = 28;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
    std::wstring::wstring(&setName, L"ROAD");
    LOBYTE(v181) = 67;
    std::wstring::wstring(&cconfig, L"TEMPERATURE");
    LOBYTE(v181) = 68;
    v28->sim->physicsAvatar->engine.roadTemperature = INIReader::getFloat(&r, &cconfig, &setName);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
    LOBYTE(v181) = 28;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
  }
  std::wstring::wstring(&cconfig, L"WIND");
  LOBYTE(v181) = 69;
  v56 = INIReader::hasSection(&r, &cconfig);
  LOBYTE(v181) = 28;
  v57 = v56;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
  if ( v57 )
  {
    std::wstring::wstring(&cmodel, L"SPEED_KMH_MIN");
    LOBYTE(v181) = 70;
    std::wstring::wstring(&cconfig, L"WIND");
    LOBYTE(v181) = 71;
    *(_DWORD *)&v[24] = 1109393408;
    *(_DWORD *)&v[20] = 0;
    *(float *)&v[16] = INIReader::getFloat(&r, &cconfig, &cmodel);
    ballast = clamp<float>(*(float *)&v[16], *(float *)&v[20], *(float *)&v[24]);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
    LOBYTE(v181) = 28;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
    std::wstring::wstring(&setName, L"SPEED_KMH_MAX");
    LOBYTE(v181) = 72;
    std::wstring::wstring(&cconfig, L"WIND");
    LOBYTE(v181) = 73;
    *(_DWORD *)&v[24] = 1109393408;
    *(_DWORD *)&v[20] = 0;
    *(float *)&v[16] = INIReader::getFloat(&r, &cconfig, &setName);
    smax = clamp<float>(*(float *)&v[16], *(float *)&v[20], *(float *)&v[24]);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
    LOBYTE(v181) = 28;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
    *(float *)&v[24] = ksRand(ballast, smax);
    Speed::fromKMH((Speed *)&_S24, *(float *)&v[24]);
    LOBYTE(v181) = 74;
    std::wstring::wstring(&v167, L"DIRECTION_DEG");
    LOBYTE(v181) = 75;
    std::wstring::wstring(&cconfig, L"WIND");
    LOBYTE(v181) = 76;
    dir = INIReader::getFloat(&r, &cconfig, &v167);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
    LOBYTE(v181) = 74;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v167);
    v58 = dir;
    if ( dir < 0.0 )
    {
      dir = ksRand(0.0, 360.0);
      v58 = dir;
    }
    v28->windSettings.baseDirection = v58;
    v28->windSettings.baseSpeed = Speed::kmh((Speed *)&_S24);
    RaceManager::generateWind(v28);
    LOBYTE(v181) = 28;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&_S24);
  }
  std::wstring::wstring(&cmodel, L"CARS");
  LOBYTE(v181) = 77;
  std::wstring::wstring(&cconfig, L"RACE");
  LOBYTE(v181) = 78;
  ncars = INIReader::getInt(&r, &cconfig, &cmodel);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
  LOBYTE(v181) = 28;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
  LODWORD(smax) = 1;
  ncars = *std::max<int>((const int *)&smax, &ncars);
  std::wstring::wstring(&setName, L"PIT");
  LOBYTE(v181) = 79;
  smax = COERCE_FLOAT(TrackAvatar::getMaxSlotsAvailable(v52, &setName));
  v59 = (int *)std::min<int>(&ncars, (const int *)&smax);
  LOBYTE(v181) = 28;
  ncars = *v59;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
  v60 = ncars;
  if ( !ncars )
  {
    std::wstring::wstring(&cconfig, L"CANNOT HAVE 0 CARS IN RACE.INI");
    LOBYTE(v181) = 80;
    ks_critical_error(&cconfig);
    LOBYTE(v181) = 28;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
    v60 = ncars;
  }
  RaceManager::carsToBeLoaded = v60;
  std::wstring::wstring(&cmodel, L"MODEL");
  LOBYTE(v181) = 81;
  std::wstring::wstring(&cconfig, L"RACE");
  LOBYTE(v181) = 82;
  INIReader::getString(&r, &model, &cconfig, &cmodel);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
  LOBYTE(v181) = 85;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
  std::wstring::wstring(&v167, L"MODEL_CONFIG");
  LOBYTE(v181) = 86;
  std::wstring::wstring(&setName, L"RACE");
  LOBYTE(v181) = 87;
  INIReader::getString(&r, &config, &setName, &v167);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
  LOBYTE(v181) = 90;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v167);
  v61 = GameObject::getGameObject<PhysicsAvatar>(v28->sim);
  v62 = ksRand();
  *(_DWORD *)&v[24] = word_17BE9D8;
  smax = FLOAT_1_0;
  *(float *)&_S24._Ptr = FLOAT_1_0;
  dir = 0.0;
  v61->engine.lockGearboxAtStartTimeMS = v62 * 1000.0 + 5000.0;
  std::wstring::wstring(&skin, *(const wchar_t **)&v[24]);
  LOBYTE(v181) = 91;
  std::map<std::wstring,int>::map<std::wstring,int>(&currentSkin);
  v63 = 0;
  LOBYTE(v181) = 92;
  if ( ncars > 0 )
  {
    while ( 1 )
    {
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v155,
        3,
        1);
      *(_DWORD *)&v[24] = v63;
      LOBYTE(v181) = 93;
      v64 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v155.gap10, "CAR_");
      std::wostream::operator<<(v64, *(_DWORD *)&v[24]);
      v65 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v155, &cconfig);
      LOBYTE(v181) = 94;
      v66 = INIReader::hasSection(&r, v65);
      LOBYTE(v181) = 93;
      v67 = v66;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
      if ( v67 )
      {
        std::wstring::wstring(&setName, L"MODEL");
        LOBYTE(v181) = 95;
        v68 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v155, &v168);
        LOBYTE(v181) = 96;
        INIReader::getString(&r, &cmodel, v68, &setName);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v168);
        LOBYTE(v181) = 99;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
        std::wstring::wstring(&v167, L"MODEL_CONFIG");
        LOBYTE(v181) = 100;
        v69 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v155, &v172);
        LOBYTE(v181) = 101;
        INIReader::getString(&r, &cconfig, v69, &v167);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v172);
        LOBYTE(v181) = 104;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v167);
        std::wstring::wstring(&setName, L"SKIN");
        LOBYTE(v181) = 105;
        v70 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v155, &v164);
        LOBYTE(v181) = 106;
        v71 = INIReader::getString(&r, &v168, v70, &setName);
        std::wstring::operator=(&skin, v71);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v168);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v164);
        LOBYTE(v181) = 104;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
        if ( std::operator!=<wchar_t>(&cmodel, L"-") )
          std::wstring::operator=(&model, &cmodel);
        if ( std::operator!=<wchar_t>(&cconfig, L"-") )
          std::wstring::operator=(&config, &cconfig);
        if ( v63 > 0 || PhysicsEngine::isTestMode )
        {
          std::wstring::wstring(&setName, L"AI_LEVEL");
          LOBYTE(v181) = 107;
          v72 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v155, &v168);
          LOBYTE(v181) = 108;
          *(float *)&_S24._Ptr = INIReader::getFloat(&r, v72, &setName);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v168);
          LOBYTE(v181) = 104;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
          smax = *(float *)&_S24._Ptr;
        }
        std::wstring::wstring(&setName, L"AI_AGGRESSION");
        LOBYTE(v181) = 109;
        v73 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v155, &v168);
        LOBYTE(v181) = 110;
        v74 = INIReader::hasKey(&r, v73, &setName);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v168);
        LOBYTE(v181) = 104;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
        if ( v74 )
        {
          std::wstring::wstring(&setName, L"AI_AGGRESSION");
          LOBYTE(v181) = 111;
          v75 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v155, &v168);
          LOBYTE(v181) = 112;
          *(float *)&v[24] = INIReader::getFloat(&r, v75, &setName) * 0.0099999998;
          dir = saturate(*(float *)&v[24]) * 0.94999999;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v168);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
        }
        else
        {
          dir = 0.0;
        }
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
        LOBYTE(v181) = 93;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
      }
      v76 = v144;
      if ( !RaceManager::isSkinAvailable(v144, &model, &skin) || std::wstring::empty(&skin) )
      {
        v77 = std::wstring::c_str(&skin);
        _printf("Skin %S not available, selecting random skin\n", v77->_Bx._Buf);
        RaceManager::getModelSkins(v76, &skins, &model);
        LOBYTE(v181) = 113;
        if ( !std::vector<Turbo>::empty((std::vector<TyreCompoundDef> *)&skins) )
        {
          *(_DWORD *)&v[24] = std::vector<SetupTab *>::begin((std::vector<TyreCompoundDef> *)&currentSkin, &v151);
          v78 = (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,int> > > > *)std::_Tree<std::_Tmap_traits<std::wstring,CBuffer *,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,CBuffer *>>,0>>::find((std::_Tree<std::_Tmap_traits<std::wstring,enum DynamicControllerInput,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,enum DynamicControllerInput> >,0> > *)&currentSkin, &v150, &model);
          if ( std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const,int>>>>::operator==(
                 v78,
                 *(const std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,int> > > > **)&v[24]) )
          {
            var = (double)(unsigned int)std::vector<std::wstring>::size(&skins);
            ballast = ksRand() * (float)var;
            v79 = (int)ballast;
            *std::map<std::wstring,int>::operator[](&currentSkin, &model) = v79;
          }
          v80 = std::map<std::wstring,int>::operator[](&currentSkin, &model);
          v81 = (const std::wstring *)std::vector<VisualDamageManager::GlassBreakablePart>::operator[](
                                        (std::vector<VisualDamageManager::GlassBreakablePart> *)&skins,
                                        *v80);
          std::wstring::operator=(&skin, v81);
          v82 = std::map<std::wstring,int>::operator[](&currentSkin, &model);
          ++*v82;
          v83 = std::map<std::wstring,int>::operator[](&currentSkin, &model);
          if ( *v83 >= std::vector<std::wstring>::size(&skins) )
            *std::map<std::wstring,int>::operator[](&currentSkin, &model) = 0;
        }
        LOBYTE(v181) = 93;
        std::vector<std::wstring>::_Tidy(&skins);
      }
      v84 = Sim::addCar(v76->sim, a3, a4, &model, &config, &skin);
      v85 = v84;
      LODWORD(var) = v84;
      if ( HIBYTE(v133) )
        CarAvatar::armFirstLap(v84);
      if ( v148 >= 2 )
      {
        std::wstring::wstring(&cconfig, L"BALLAST");
        LOBYTE(v181) = 114;
        v86 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v155, &cmodel);
        LOBYTE(v181) = 115;
        ballast = INIReader::getFloat(&r, v86, &cconfig);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
        LOBYTE(v181) = 93;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
        if ( ballast > 0.0 )
        {
          *(double *)&v[20] = ballast;
          v87 = CarAvatar::getGuid(v85);
          _printf("Setting ballast for car %d to %f\n", v87, *(double *)&v[20]);
          CarAvatar::setBallastKG(v85, ballast);
        }
        std::wstring::wstring(&cconfig, L"RESTRICTOR");
        LOBYTE(v181) = 116;
        v88 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v155, &cmodel);
        LOBYTE(v181) = 117;
        ballast = INIReader::getFloat(&r, v88, &cconfig);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
        LOBYTE(v181) = 93;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
        if ( ballast > 0.0 )
          CarAvatar::setRestrictor(v85, ballast);
      }
      SetupItemText::SetupItemText((DriverInfo *)&newINI);
      LOBYTE(v181) = 118;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &ssCar,
        3,
        1);
      *(_DWORD *)&v[24] = v63;
      LOBYTE(v181) = 119;
      v89 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)ssCar.gap10, L"CAR_");
      std::wostream::operator<<(v89, *(_DWORD *)&v[24]);
      std::wstring::assign(&v177, word_17BE9D8);
      std::wstring::wstring(&cconfig, L"DRIVER_NAME");
      LOBYTE(v181) = 120;
      v90 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&ssCar, &setName);
      LOBYTE(v181) = 121;
      v91 = INIReader::getString(&r, &cmodel, v90, &cconfig);
      std::wstring::operator=((std::wstring *)&newINI, v91);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
      LOBYTE(v181) = 119;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
      std::wstring::wstring(&cconfig, L"NATION_CODE");
      LOBYTE(v181) = 122;
      v92 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&ssCar, &cmodel);
      LOBYTE(v181) = 123;
      v93 = INIReader::hasKey(&r, v92, &cconfig);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
      LOBYTE(v181) = 119;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
      if ( v93 )
      {
        std::wstring::wstring(&cconfig, L"NATION_CODE");
        LOBYTE(v181) = 124;
        v94 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&ssCar, &setName);
        LOBYTE(v181) = 125;
        v95 = INIReader::getString(&r, &cmodel, v94, &cconfig);
        std::wstring::operator=(&v177, v95);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
        LOBYTE(v181) = 119;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
      }
      if ( !v63 )
      {
        std::wstring::wstring(&cconfig, L"DRIVER_NAME");
        LOBYTE(v181) = 126;
        v96 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&ssCar, &setName);
        LOBYTE(v181) = 127;
        v97 = INIReader::getString(v146, &cmodel, v96, &cconfig);
        std::wstring::operator=((std::wstring *)&newINI, v97);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
        LOBYTE(v181) = 119;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
        std::wstring::wstring(&cconfig, L"NATION_CODE");
        LOBYTE(v181) = 0x80;
        v98 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&ssCar, &cmodel);
        LOBYTE(v181) = -127;
        v99 = INIReader::hasKey(v146, v98, &cconfig);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
        LOBYTE(v181) = 119;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
        if ( v99 )
        {
          std::wstring::wstring(&cconfig, L"NATION_CODE");
          LOBYTE(v181) = -126;
          v100 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                   &ssCar,
                   &setName);
          LOBYTE(v181) = -125;
          v101 = INIReader::getString(v146, &cmodel, v100, &cconfig);
          std::wstring::operator=(&v177, v101);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
          LOBYTE(v181) = 119;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
        }
      }
      std::wstring::assign((std::wstring *)&newINI.code._Bx._Alias[4], word_17BE9D8);
      std::wstring::assign((std::wstring *)&newINI.filename._Mysize, word_17BE9D8);
      CarAvatar::setDriverInfo(v85, (const DriverInfo *)&newINI);
      if ( v63 > 0 || PhysicsEngine::isTestMode )
      {
        if ( std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*(v147)->index == 7 )
        {
          v102 = (AIDriverDrag *)operator new(216);
          LODWORD(var) = v102;
          LOBYTE(v181) = -124;
          if ( v102 )
          {
            v103 = (RaceEngineer *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&v85->raceEngineer);
            v104 = RaceEngineer::getCar(v103);
            AIDriverDrag::AIDriverDrag(v102, v104);
          }
          else
          {
            v105 = 0;
          }
          *(_DWORD *)&v[24] = v105;
          LOBYTE(v181) = 119;
          *(float *)(v105 + 16) = smax;
          CarAvatar::setControlsProvider(v85, *(ICarControlsProvider **)&v[24]);
        }
        else
        {
          lambda_5c8e18c6096c34f7d85a3c1b4614f402_::_lambda_5c8e18c6096c34f7d85a3c1b4614f402_(
            (RaceManager::initOffline::__l127::<lambda_5c8e18c6096c34f7d85a3c1b4614f402> *)&section,
            (const float *)&_S24,
            &global_ai_level,
            (CarAvatar *const *)&var,
            &dir);
          std::function<void __cdecl (void)>::function<void __cdecl (void)>(
            (std::function<void __cdecl(void)> *)&v[4],
            v106);
          PhysicsAvatar::executeOnPhysicsThread(v144->sim->physicsAvatar, *(std::function<void __cdecl(void)> *)&v[4]);
        }
      }
      v107 = v147;
      v108 = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*(v147)->index;
      if ( v108 == 3 )
        break;
      if ( v108 == 7 )
      {
        std::wstring::wstring(&cconfig, L"START");
        LOBYTE(v181) = -123;
        CarAvatar::setSpawnPositionIndex(v85, &cconfig, v63);
        v109 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig;
LABEL_190:
        std::wstring::~wstring(v109);
      }
LABEL_191:
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&ssCar);
      SetupItemText::~SetupItemText((DriverInfo *)&newINI);
      LOBYTE(v181) = 92;
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v155);
      if ( ++v63 >= ncars )
        goto LABEL_192;
    }
    if ( v63 )
      v110 = v63;
    else
      v110 = LODWORD(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*(v107)->modelData.speedSensitivity);
    std::wstring::wstring(&cmodel, L"START");
    LOBYTE(v181) = -122;
    CarAvatar::setSpawnPositionIndex(v85, &cmodel, v110 - 1);
    LOBYTE(v181) = 119;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
    if ( !v63
      || v110 < SLODWORD(std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*(v147)->modelData.speedSensitivity) )
    {
      goto LABEL_191;
    }
    std::wstring::wstring(&setName, L"START");
    LOBYTE(v181) = -121;
    CarAvatar::setSpawnPositionIndex(v85, &setName, v110);
    v109 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName;
    goto LABEL_190;
  }
LABEL_192:
  v111 = v144;
  RaceManager::initGhostcar(v144, (INIReaderDocuments *)v146);
  std::wstring::wstring(&cmodel, L"PENALTIES");
  LOBYTE(v181) = -120;
  std::wstring::wstring(&cconfig, L"RACE");
  LOBYTE(v181) = -119;
  v112 = INIReader::getInt(&r, &cconfig, &cmodel) > 0;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
  LOBYTE(v181) = 92;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
  v113 = v111->sim->physicsAvatar;
  if ( v112 )
  {
    PhysicsAvatar::setAllowedTyresOut(v113, 2);
    v111->penaltiesEnabled = 1;
  }
  else
  {
    PhysicsAvatar::setAllowedTyresOut(v113, -1);
    v111->penaltiesEnabled = 0;
  }
  std::wstring::wstring(&cmodel, L"JUMP_START_PENALTY");
  LOBYTE(v181) = -118;
  std::wstring::wstring(&cconfig, L"RACE");
  LOBYTE(v181) = -117;
  v114 = INIReader::hasKey(&r, &cconfig, &cmodel);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
  LOBYTE(v181) = 92;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
  if ( v114 )
  {
    std::wstring::wstring(&cmodel, L"JUMP_START_PENALTY");
    LOBYTE(v181) = -116;
    std::wstring::wstring(&cconfig, L"RACE");
    LOBYTE(v181) = -115;
    v115 = INIReader::getInt(&r, &cconfig, &cmodel);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
    LOBYTE(v181) = 92;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
    if ( v115 == eDriveThroughMode )
    {
      v116 = PhysicsAvatar::getBasePitPenaltyLaps(v111->sim->physicsAvatar);
      if ( v116 >= SLODWORD(ref) && ref != 0.0 )
        v115 = eTeleportToPitMode;
    }
    PhysicsAvatar::setJumpStartPenaltyMode(v111->sim->physicsAvatar, v115);
  }
  v117 = (std::_Tree_node<std::pair<std::wstring const ,enum DynamicControllerInput>,void *> *)operator new(104);
  v150._Ptr = v117;
  LOBYTE(v181) = -114;
  if ( v117 )
    RaceTimingServices::RaceTimingServices((RaceTimingServices *)v117, v111->sim);
  else
    v118 = 0;
  LOBYTE(v181) = 92;
  v119 = GameObject::addGameObject<ProximityIndicator>(v111, v118);
  *(_DWORD *)&v[24] = L"WEATHER";
  v111->raceTimingServices = (RaceTimingServices *)v119;
  std::wstring::wstring(&cconfig, *(const wchar_t **)&v[24]);
  LOBYTE(v181) = -113;
  v120 = INIReader::hasSection(&r, &cconfig);
  LOBYTE(v181) = 92;
  v121 = v120;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
  if ( v121 )
  {
    std::wstring::wstring(&cmodel, L"NAME");
    LOBYTE(v181) = -112;
    std::wstring::wstring(&cconfig, L"WEATHER");
    LOBYTE(v181) = -111;
    v122 = INIReader::getString(&r, &setName, &cconfig, &cmodel);
    v123 = v111->sim;
    LOBYTE(v181) = -110;
    Sim::applyCustomWeather(v123, v122);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&setName);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cconfig);
    LOBYTE(v181) = 92;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&cmodel);
  }
  RaceManager::setCurrentSession(v111, 0);
  DynamicTempData::DynamicTempData(&td);
  v124 = v111->sim;
  LOBYTE(v181) = -109;
  v125 = v124->physicsAvatar;
  *(_DWORD *)&v[24] = 1092616192;
  *(_DWORD *)&v[20] = 1082130432;
  td.baseAir = v125->engine.ambientTemperature;
  td.baseRoad = v124->physicsAvatar->engine.roadTemperature;
  global_ai_level = ksRand(4.0, 10.0);
  v126 = (int)global_ai_level;
  global_ai_level = 720000000.0 / (float)(int)global_ai_level;
  Curve::addValue(&td.temperatureCurve, 0.0, 0.0);
  v127 = 0;
  while ( v127 < v126 )
  {
    ref = (float)++v127 * global_ai_level;
    *(float *)&var = ksRand(-20.0, 20.0);
    Curve::addValue(&td.temperatureCurve, ref, *(float *)&var);
  }
  PhysicsEngine::setDynamicTempData(&v111->sim->physicsAvatar->engine, &td);
  _printf("\nPOWER CLASS INDEX\n");
  for ( j = 0; j < Sim::getCarsCount(v111->sim); ++j )
  {
    v129 = Sim::getCar(v111->sim, j);
    *(double *)&v[20] = v129->physicsInfo.powerClassIndex;
    v130 = std::wstring::c_str(&v129->unixName);
    _printf("%S: %.1f\n", v130->_Bx._Buf, *(double *)&v[20]);
  }
  RaceManager::resetCurrentLaps(v111);
  RaceManager::resetMandatoryPit(v111);
  LOBYTE(v181) = 92;
  ClutchSequence::~ClutchSequence((ClutchSequence *)&td);
  std::map<std::wstring,AudioEngine::GUID>::~map<std::wstring,AudioEngine::GUID>((std::map<std::wstring,TyreCompoundStrategy> *)&currentSkin);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&skin);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&config);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&model);
  std::vector<std::wstring>::_Tidy(&sections);
  v181 = -1;
  INIReader::~INIReader(&r);
  return 1;
}
char __userpurge RaceManager::initOnline@<al>(RaceManager *this@<ecx>, __m128 a2@<xmm3>, __m128 a3@<xmm4>, INIReaderDocuments *ini)
{
  RaceManager *v4; // ebx
  void (*v5)(const char *const, ...); // ebp
  std::wstring *v6; // eax
  ACClient *v7; // eax
  ACClient *v8; // edi
  Sim *v9; // esi
  Sim *v10; // eax
  Sim *v11; // eax
  Sim *v12; // eax
  char v13; // bl
  SplashScreen *v14; // esi
  std::wstring *v15; // eax
  std::wstring *v16; // eax
  int v17; // eax
  int v18; // eax
  std::wstring *v19; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v20; // ecx
  std::wstring *v21; // eax
  std::wstring *v22; // eax
  int v23; // eax
  int v24; // eax
  std::wstring *v25; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v26; // ecx
  std::wstring *v27; // eax
  std::wstring *v28; // eax
  std::wstring *v29; // eax
  std::wstring *v30; // eax
  const std::wstring *v31; // eax
  Sim *v32; // ecx
  std::wostream *v33; // eax
  std::wostream *v34; // eax
  std::wstring *v35; // eax
  std::wstring *v36; // eax
  const std::wstring *v37; // eax
  Sim *v38; // ecx
  std::wostream *v39; // eax
  std::wostream *v40; // eax
  std::wstring *v41; // eax
  std::wstring *v42; // eax
  const std::wstring *v43; // eax
  Sim *v44; // ecx
  std::wostream *v45; // eax
  std::wostream *v46; // eax
  std::wstring *v47; // eax
  JumpStartPenaltyMode v48; // eax
  __int32 v49; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v50; // ecx
  __m128 v51; // xmm0
  PhysicsAvatar *v52; // eax
  std::wstring *v53; // esi
  std::wostream *v54; // eax
  const std::wstring *v55; // eax
  Sim *v56; // ecx
  std::wstring *v57; // esi
  std::wstring *v58; // eax
  std::wostream *v59; // eax
  const std::wstring *v60; // eax
  Sim *v61; // ecx
  ClientRemoteCarDef *v62; // edi
  ClientRemoteCarDef *v63; // esi
  char v64; // al
  Sim *v65; // ecx
  CarAvatar *v66; // esi
  std::vector<unsigned char> *v67; // eax
  unsigned __int8 *v68; // ecx
  unsigned __int8 *i; // eax
  Sim *v70; // eax
  ClientRemoteCarDef *v71; // esi
  unsigned int *v72; // edi
  const wchar_t *v73; // eax
  const wchar_t *v74; // eax
  const wchar_t *v75; // eax
  DriverInfo *v76; // ebx
  const wchar_t *v77; // eax
  DriverInfo *v78; // ebp
  const wchar_t *v79; // eax
  Sim *v80; // ecx
  ACClient *v81; // ecx
  RaceTimingServices *v82; // ecx
  std::function<void __cdecl(SessionInfo const &)> v84; // [esp-1Ch] [ebp-34Ch] BYREF
  int v85; // [esp-4h] [ebp-334h]
  int v86; // [esp+24h] [ebp-30Ch] BYREF
  std::vector<std::wstring> hints; // [esp+28h] [ebp-308h] BYREF
  std::vector<ClientRemoteCarDef> remoteCars; // [esp+34h] [ebp-2FCh] BYREF
  ACClient *client; // [esp+40h] [ebp-2F0h]
  int v90; // [esp+44h] [ebp-2ECh]
  std::vector<unsigned char> final_checksum; // [esp+48h] [ebp-2E8h] BYREF
  std::vector<unsigned char> loading_checksum; // [esp+54h] [ebp-2DCh] BYREF
  RaceManager *v93; // [esp+60h] [ebp-2D0h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v94; // [esp+64h] [ebp-2CCh] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v95; // [esp+114h] [ebp-21Ch] BYREF
  std::wstring result; // [esp+1C4h] [ebp-16Ch] BYREF
  std::wstring v97; // [esp+1DCh] [ebp-154h] BYREF
  std::wstring _Val; // [esp+1F4h] [ebp-13Ch] BYREF
  DriverInfo v99; // [esp+20Ch] [ebp-124h] BYREF
  std::wstring v100; // [esp+26Ch] [ebp-C4h] BYREF
  std::wstring v101; // [esp+284h] [ebp-ACh] BYREF
  std::wstring v102; // [esp+29Ch] [ebp-94h] BYREF
  ClientHandshakeResult res; // [esp+2B4h] [ebp-7Ch] BYREF
  int v104; // [esp+328h] [ebp-8h]
  int v105; // [esp+32Ch] [ebp-4h]
  void *retaddr; // [esp+330h] [ebp+0h]

  v4 = this;
  v93 = this;
  v90 = 0;
  v5 = (void (*)(const char *const, ...))_printf;
  _printf("RaceManager::initOnline\n");
  v6 = (std::wstring *)operator new(66912);
  hints._Myfirst = v6;
  v105 = 0;
  if ( v6 )
  {
    ACClient::ACClient((ACClient *)v6, v4->sim);
    v8 = v7;
    client = v7;
  }
  else
  {
    v8 = 0;
    client = 0;
  }
  v9 = v4->sim;
  v105 = -1;
  hints._Myfirst = (std::wstring *)v8;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&v9->gameObjects,
    (ICollisionObject *const *)&hints);
  v8->parent = v9;
  v10 = v4->sim;
  v85 = 3;
  v10->client = v8;
  std::vector<std::vector<LeaderboardEntry>>::resize(
    (std::vector<std::vector<WingState>> *)&v4->leaderboardHistory,
    v85);
  v85 = (int)v4;
  v84._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_169506d575188a429382108dea5a3ad3_,0>,std::allocator<std::_Func_class<void,RemoteSession const &>>,void,RemoteSession const &>::`vftable';
  v84._Space._Pfn[1] = (void (__cdecl *)())v4;
  v84._Impl = (std::_Func_base<void,SessionInfo const &> *)&v84;
  v11 = v4->sim;
  v105 = -1;
  Event<float>::addHandler((Event<SessionInfo> *)&v11->client->evOnOnlineNewSession, v84, v4);
  v85 = (int)v4;
  v84._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_4cc3dee08bd3ddb5881c065c8a6f5e4b_,0>,std::allocator<std::_Func_class<void,RemoteSessionResume const &>>,void,RemoteSessionResume const &>::`vftable';
  v84._Space._Pfn[1] = (void (__cdecl *)())v4;
  v84._Impl = (std::_Func_base<void,SessionInfo const &> *)&v84;
  v12 = v4->sim;
  v105 = -1;
  Event<float>::addHandler((Event<SessionInfo> *)&v12->client->evOnOnlineEndSession, v84, v4);
  ACClient::handshakeTCP(v8, (unsigned int)v4, &res);
  v105 = 3;
  if ( !res.success )
  {
    _printf("ERROR: RaceManager :: Handshake FAILED\n");
    v13 = 0;
    goto LABEL_159;
  }
  v14 = GameObject::getGameObject<SplashScreen>(v4->game->root);
  if ( v14 )
  {
    hints._Myfirst = 0;
    hints._Mylast = 0;
    hints._Myend = 0;
    LOBYTE(v105) = 4;
    std::wstring::wstring(&result, L"SERVER: ");
    LOBYTE(v105) = 5;
    v15 = acTranslate(&v97, &result);
    LOBYTE(v105) = 6;
    v16 = std::operator+<wchar_t>(&_Val, v15, &v8->serverName);
    LOBYTE(v105) = 7;
    std::vector<std::wstring>::push_back(&hints, v16);
    if ( _Val._Myres >= 8 )
      operator delete(_Val._Bx._Ptr);
    _Val._Myres = 7;
    _Val._Mysize = 0;
    _Val._Bx._Buf[0] = 0;
    if ( v97._Myres >= 8 )
      operator delete(v97._Bx._Ptr);
    v97._Myres = 7;
    v97._Mysize = 0;
    v97._Bx._Buf[0] = 0;
    LOBYTE(v105) = 4;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v17 = v8->serverDrivingAssists.tc;
    if ( v17 )
    {
      v18 = v17 - 1;
      if ( v18 )
      {
        if ( v18 != 1 )
          goto LABEL_20;
        std::wstring::wstring(&result, L"Traction Control: Yes");
        LOBYTE(v105) = 12;
        v19 = acTranslate(&v102, &result);
        LOBYTE(v105) = 13;
        std::vector<std::wstring>::push_back(&hints, v19);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v102);
        v20 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result;
      }
      else
      {
        std::wstring::wstring(&v97, L"Traction Control: Factory");
        LOBYTE(v105) = 10;
        v21 = acTranslate(&v101, &v97);
        LOBYTE(v105) = 11;
        std::vector<std::wstring>::push_back(&hints, v21);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v101);
        v20 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v97;
      }
    }
    else
    {
      std::wstring::wstring(&_Val, L"Traction Control: No");
      LOBYTE(v105) = 8;
      v22 = acTranslate(&v100, &_Val);
      LOBYTE(v105) = 9;
      std::vector<std::wstring>::push_back(&hints, v22);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v100);
      v20 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Val;
    }
    LOBYTE(v105) = 4;
    std::wstring::~wstring(v20);
LABEL_20:
    v23 = v8->serverDrivingAssists.abs;
    if ( v23 )
    {
      v24 = v23 - 1;
      if ( v24 )
      {
        if ( v24 != 1 )
          goto LABEL_27;
        std::wstring::wstring(&result, L"ABS: Yes");
        LOBYTE(v105) = 18;
        v25 = acTranslate(&v100, &result);
        LOBYTE(v105) = 19;
        std::vector<std::wstring>::push_back(&hints, v25);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v100);
        v26 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result;
      }
      else
      {
        std::wstring::wstring(&v97, L"ABS: Factory");
        LOBYTE(v105) = 16;
        v27 = acTranslate(&v101, &v97);
        LOBYTE(v105) = 17;
        std::vector<std::wstring>::push_back(&hints, v27);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v101);
        v26 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v97;
      }
    }
    else
    {
      std::wstring::wstring(&_Val, L"ABS: No");
      LOBYTE(v105) = 14;
      v28 = acTranslate(&v102, &_Val);
      LOBYTE(v105) = 15;
      std::vector<std::wstring>::push_back(&hints, v28);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v102);
      v26 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Val;
    }
    LOBYTE(v105) = 4;
    std::wstring::~wstring(v26);
LABEL_27:
    if ( v8->serverDrivingAssists.stability )
    {
      std::wstring::wstring(&result, L"Stability Control: Allowed");
      LOBYTE(v105) = 20;
      v29 = acTranslate(&v97, &result);
      LOBYTE(v105) = 21;
    }
    else
    {
      std::wstring::wstring(&result, L"Stability Control: Not Allowed");
      LOBYTE(v105) = 22;
      v29 = acTranslate(&v97, &result);
      LOBYTE(v105) = 23;
    }
    std::vector<std::wstring>::push_back(&hints, v29);
    if ( v97._Myres >= 8 )
      operator delete(v97._Bx._Ptr);
    LOBYTE(v105) = 4;
    v97._Bx._Buf[0] = 0;
    v97._Mysize = 0;
    v97._Myres = 7;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( v8->serverDrivingAssists.autoClutch )
    {
      std::wstring::wstring(&result, L"Auto Clutch: Allowed");
      LOBYTE(v105) = 24;
      v30 = acTranslate(&v97, &result);
      LOBYTE(v105) = 25;
    }
    else
    {
      std::wstring::wstring(&result, L"Auto Clutch: Not Allowed");
      LOBYTE(v105) = 26;
      v30 = acTranslate(&v97, &result);
      LOBYTE(v105) = 27;
    }
    std::vector<std::wstring>::push_back(&hints, v30);
    if ( v97._Myres >= 8 )
      operator delete(v97._Bx._Ptr);
    LOBYTE(v105) = 4;
    v97._Bx._Buf[0] = 0;
    v97._Mysize = 0;
    v97._Myres = 7;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    *(_DWORD *)v94.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v94.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v94.gap68);
    LOBYTE(retaddr) = 28;
    final_checksum._Myfirst = (unsigned __int8 *)1;
    std::wiostream::basic_iostream<wchar_t>(&v94.gap0[4], &v94.gap10[12], 0);
    v104 = 29;
    *(RaceManager **)((char *)&v93 + (unsigned int)v93->game) = (RaceManager *)&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(unsigned __int8 **)((char *)&loading_checksum._Myend + (unsigned int)v93->game) = (unsigned __int8 *)&v93->game[-1].keyboardManager.listeners._Myend;
    std::wstreambuf::wstreambuf(&v94.gap10[4]);
    *(_DWORD *)&v94.gap10[4] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v94.gap10[60] = 0;
    *(_DWORD *)&v94.gap10[64] = 0;
    LOBYTE(v104) = 31;
    std::wstring::wstring((std::wstring *)&v95.gap68[68], L"Damage: ");
    LOBYTE(v104) = 32;
    v31 = acTranslate((std::wstring *)&result._Myres, (const std::wstring *)&v95.gap68[68]);
    v32 = v4->sim;
    (&v84._Impl)[1] = (std::_Func_base<void,SessionInfo const &> *)L"%";
    LOBYTE(v104) = 33;
    v84._Impl = (std::_Func_base<void,SessionInfo const &> *)(int)(float)(v32->physicsAvatar->engine.mechanicalDamageRate
                                                                        * 100.0);
    v33 = std::operator<<<wchar_t>((std::wostream *)((char *)&v94._Chcount + 4), v31);
    v34 = (std::wostream *)std::wostream::operator<<(v33, v84._Impl);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v34, (const wchar_t *)v85);
    if ( v97._Myres >= 8 )
      operator delete(v97._Bx._Ptr);
    v97._Myres = 7;
    v97._Mysize = 0;
    v97._Bx._Buf[0] = 0;
    LOBYTE(v105) = 31;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v35 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v94, &result);
    LOBYTE(v105) = 34;
    std::vector<std::wstring>::push_back(&hints, v35);
    LOBYTE(v105) = 31;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&_Val, word_17BE9D8);
    LOBYTE(v105) = 35;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v94.gap10[8]);
    v85 = *(_DWORD *)&v94.gap10[68];
    v36 = &_Val;
    (&v84._Impl)[1] = (std::_Func_base<void,SessionInfo const &> *)_Val._Mysize;
    if ( _Val._Myres >= 8 )
      v36 = (std::wstring *)_Val._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v94.gap10[8], v36->_Bx._Buf, (unsigned int)(&v84._Impl)[1], v85);
    LOBYTE(v105) = 31;
    if ( _Val._Myres >= 8 )
      operator delete(_Val._Bx._Ptr);
    std::wstring::wstring(&result, L"Fuel Rate: ");
    LOBYTE(v105) = 36;
    v37 = acTranslate(&v97, &result);
    v38 = v4->sim;
    v85 = (int)L"%";
    LOBYTE(v105) = 37;
    (&v84._Impl)[1] = (std::_Func_base<void,SessionInfo const &> *)(int)(float)(v38->physicsAvatar->engine.fuelConsumptionRate
                                                                              * 100.0);
    v39 = std::operator<<<wchar_t>((std::wostream *)v94.gap10, v37);
    v40 = (std::wostream *)std::wostream::operator<<(v39, (&v84._Impl)[1]);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v40, (const wchar_t *)v85);
    if ( v97._Myres >= 8 )
      operator delete(v97._Bx._Ptr);
    v97._Myres = 7;
    v97._Mysize = 0;
    v97._Bx._Buf[0] = 0;
    LOBYTE(v105) = 31;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v41 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v94, &result);
    LOBYTE(v105) = 38;
    std::vector<std::wstring>::push_back(&hints, v41);
    LOBYTE(v105) = 31;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&_Val, word_17BE9D8);
    LOBYTE(v105) = 39;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v94.gap10[8]);
    v85 = *(_DWORD *)&v94.gap10[68];
    v42 = &_Val;
    (&v84._Impl)[1] = (std::_Func_base<void,SessionInfo const &> *)_Val._Mysize;
    if ( _Val._Myres >= 8 )
      v42 = (std::wstring *)_Val._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v94.gap10[8], v42->_Bx._Buf, (unsigned int)(&v84._Impl)[1], v85);
    LOBYTE(v105) = 31;
    if ( _Val._Myres >= 8 )
      operator delete(_Val._Bx._Ptr);
    std::wstring::wstring(&result, L"Tyre Wear Rate: ");
    LOBYTE(v105) = 40;
    v43 = acTranslate(&v97, &result);
    v44 = v4->sim;
    v85 = (int)L"%";
    LOBYTE(v105) = 41;
    (&v84._Impl)[1] = (std::_Func_base<void,SessionInfo const &> *)(int)(float)(v44->physicsAvatar->engine.tyreConsumptionRate
                                                                              * 100.0);
    v45 = std::operator<<<wchar_t>((std::wostream *)v94.gap10, v43);
    v46 = (std::wostream *)std::wostream::operator<<(v45, (&v84._Impl)[1]);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v46, (const wchar_t *)v85);
    if ( v97._Myres >= 8 )
      operator delete(v97._Bx._Ptr);
    v97._Myres = 7;
    v97._Mysize = 0;
    v97._Bx._Buf[0] = 0;
    LOBYTE(v105) = 31;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v47 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v94, &result);
    LOBYTE(v105) = 42;
    std::vector<std::wstring>::push_back(&hints, v47);
    LOBYTE(v105) = 31;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( v4->sim->physicsAvatar->engine.allowTyreBlankets )
    {
      std::wstring::wstring(&result, L"Tyre Blankets: Yes");
      LOBYTE(v105) = 43;
    }
    else
    {
      std::wstring::wstring(&result, L"Tyre Blankets: No");
      LOBYTE(v105) = 44;
    }
    std::vector<std::wstring>::push_back(&hints, &result);
    LOBYTE(v105) = 31;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( v4->sim->isVirtualMirrorForced )
    {
      std::wstring::wstring(&result, L"Virtual Mirror: Forced On");
      LOBYTE(v105) = 45;
      std::vector<std::wstring>::push_back(&hints, &result);
      LOBYTE(v105) = 31;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
    v48 = v4->sim->physicsAvatar->engine.penaltyRules.jumpStartPenaltyMode;
    if ( v48 )
    {
      v49 = v48 - 1;
      if ( v49 )
      {
        if ( v49 != 1 )
        {
LABEL_82:
          SplashScreen::setServerHints(v14, &hints);
          std::wstring::wstring(&result, word_17BE9D8);
          LOBYTE(v105) = 49;
          SplashScreen::setOnlinePlayerCar(v14, (unsigned int)v4, &res.model, &result);
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v94);
          LOBYTE(v105) = 3;
          if ( hints._Myfirst )
          {
            std::_Container_base0::_Orphan_all(&hints);
            v85 = (int)hints._Myfirst;
            (&v84._Impl)[1] = (std::_Func_base<void,SessionInfo const &> *)((char *)&v86 + 3);
            std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(hints._Myfirst, hints._Mylast);
            operator delete(hints._Myfirst);
          }
          goto LABEL_86;
        }
        std::wstring::wstring(&result, L"Jump-start: Drive-through");
        LOBYTE(v105) = 48;
        std::vector<std::wstring>::push_back(&hints, &result);
        v50 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result;
      }
      else
      {
        std::wstring::wstring(&v97, L"Jump-start: Teleport To Pits");
        LOBYTE(v105) = 47;
        std::vector<std::wstring>::push_back(&hints, &v97);
        v50 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v97;
      }
    }
    else
    {
      std::wstring::wstring(&_Val, L"Jump-start: No");
      LOBYTE(v105) = 46;
      std::vector<std::wstring>::push_back(&hints, &_Val);
      v50 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Val;
    }
    LOBYTE(v105) = 31;
    std::wstring::~wstring(v50);
    goto LABEL_82;
  }
LABEL_86:
  v51 = (__m128)LODWORD(res.sunAngle);
  v4->game->graphics->lightingSettings.angle = res.sunAngle;
  GraphicsManager::updateLightingSetttings(v4->game->graphics);
  Sim::loadTrack(v4->sim, v51, a2, a3, &res.track, &res.track_config, res.sessionID);
  v52 = GameObject::getGameObject<PhysicsAvatar>(v4->sim);
  v85 = (int)"--------REQUESTING CAR LIST --------\n";
  v52->engine.lockGearboxAtStartTimeMS = DOUBLE_12000_0;
  _printf((const char *const)v85);
  remoteCars._Myfirst = 0;
  remoteCars._Mylast = 0;
  remoteCars._Myend = 0;
  LOBYTE(v105) = 50;
  v53 = 0;
  *(_DWORD *)v95.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v95.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v95.gap68);
  v90 |= 2u;
  LOBYTE(v105) = 51;
  std::wiostream::basic_iostream<wchar_t>(&v95, &v95.gap10[8], 0);
  v105 = 52;
  *(_DWORD *)&v95.gap0[*(_DWORD *)(*(_DWORD *)v95.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)&v94.gap68[*(_DWORD *)(*(_DWORD *)v95.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v95.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v95.gap10[8]);
  *(_DWORD *)&v95.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v95.gap10[64] = 0;
  *(_DWORD *)&v95.gap10[68] = 0;
  v85 = 1;
  LOBYTE(v105) = 54;
  v54 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v95.gap10, "Requesting car list, attempt ");
  std::wostream::operator<<(v54, v85);
  v55 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v95, &result);
  v56 = v4->sim;
  LOBYTE(v105) = 55;
  Sim::setSplashMessage(v56, v55);
  LOBYTE(v105) = 54;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  HIBYTE(v86) = ACClient::getRemoteCarList(v8, &remoteCars);
  if ( !HIBYTE(v86) )
  {
    do
    {
      if ( (int)v53 >= 5 )
        break;
      ksSleep(2000);
      _Val._Myres = 7;
      _Val._Mysize = 0;
      v57 = (std::wstring *)((char *)v53->_Bx._Buf + 1);
      _Val._Bx._Buf[0] = 0;
      hints._Myfirst = v57;
      std::wstring::assign(&_Val, word_17BE9D8, 0);
      LOBYTE(v105) = 56;
      std::wstringbuf::_Tidy((std::wstringbuf *)&v95.gap10[8]);
      v85 = *(_DWORD *)&v95.gap10[68];
      v58 = &_Val;
      (&v84._Impl)[1] = (std::_Func_base<void,SessionInfo const &> *)_Val._Mysize;
      if ( _Val._Myres >= 8 )
        v58 = (std::wstring *)_Val._Bx._Ptr;
      std::wstringbuf::_Init((std::wstringbuf *)&v95.gap10[8], v58->_Bx._Buf, (unsigned int)(&v84._Impl)[1], v85);
      LOBYTE(v105) = 54;
      if ( _Val._Myres >= 8 )
        operator delete(_Val._Bx._Ptr);
      v85 = (int)v57->_Bx._Buf + 1;
      v59 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(
              (std::wostream *)v95.gap10,
              "Requesting car list, attempt ");
      std::wostream::operator<<(v59, v85);
      v60 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v95, &result);
      v61 = v4->sim;
      LOBYTE(v105) = 57;
      Sim::setSplashMessage(v61, v60);
      LOBYTE(v105) = 54;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      std::_Container_base0::_Orphan_all(&remoteCars);
      v62 = remoteCars._Mylast;
      v63 = remoteCars._Myfirst;
      if ( remoteCars._Myfirst != remoteCars._Mylast )
      {
        do
          ClientRemoteCarDef::~ClientRemoteCarDef(v63++);
        while ( v63 != v62 );
        v63 = remoteCars._Myfirst;
      }
      v8 = client;
      remoteCars._Mylast = v63;
      v64 = ACClient::getRemoteCarList(client, &remoteCars);
      v53 = hints._Myfirst;
      HIBYTE(v86) = v64;
    }
    while ( !v64 );
  }
  _printf("Received %d cars\n", remoteCars._Mylast - remoteCars._Myfirst);
  if ( HIBYTE(v86) )
  {
    RaceManager::carsToBeLoaded = ((int)((unsigned __int64)(818089009i64
                                                          * ((char *)remoteCars._Mylast - (char *)remoteCars._Myfirst)) >> 32) >> 5)
                                + ((unsigned int)((unsigned __int64)(818089009i64
                                                                   * ((char *)remoteCars._Mylast
                                                                    - (char *)remoteCars._Myfirst)) >> 32) >> 31)
                                + 1;
    std::vector<bool>::resize(&v4->multiplayerStatus.completedFlags, RaceManager::carsToBeLoaded, 0);
    ACClient::getCarMD5(v8, (unsigned int)v4, &loading_checksum, &res.model);
    LOBYTE(v105) = 58;
    std::wstring::wstring(&_Val, word_17BE9D8);
    v65 = v4->sim;
    LOBYTE(v105) = 59;
    v66 = Sim::addCar(v65, a2, a3, &res.model, &_Val, &res.skin);
    LOBYTE(v105) = 58;
    if ( _Val._Myres >= 8 )
      operator delete(_Val._Bx._Ptr);
    _Val._Myres = 7;
    _Val._Bx._Buf[0] = 0;
    _Val._Mysize = 0;
    ACClient::getCarMD5(v8, (unsigned int)v4, &final_checksum, &res.model);
    LOBYTE(v105) = 60;
    if ( std::operator==<unsigned char,std::allocator<unsigned char>>(&loading_checksum, &final_checksum) )
    {
      v67 = &loading_checksum;
    }
    else
    {
      _printf("Finalizing Physics Engine\n");
      v68 = final_checksum._Mylast;
      for ( i = final_checksum._Myfirst; i != v68; ++i )
        *i += 66;
      v67 = &final_checksum;
    }
    std::vector<unsigned char>::operator=(&v8->playerCarMD5, v67);
    CarAvatar::setDriverInfo(v66, &v8->driverInfo);
    if ( v8->invertedGridPositions < 0 )
      v8->invertedGridPositions = RaceManager::carsToBeLoaded;
    std::wstring::wstring(&result, L"START");
    v70 = v4->sim;
    LOBYTE(v105) = 61;
    CarAvatar::setSpawnPositionIndex(v66, &result, v70->client->handshakeCarPosition);
    LOBYTE(v105) = 60;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&result, L"PIT");
    LOBYTE(v105) = 62;
    CarAvatar::setSpawnPositionIndex(v66, &result, res.sessionID);
    LOBYTE(v105) = 60;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( RaceManager::getCurrentSessionType(v4) == Race
      && (*(double *)&hints._Myfirst = RaceManager::getTimeToSessionStart(v4->sim->raceManager),
          *(double *)&hints._Myfirst > 0.0) )
    {
      std::wstring::wstring(&result, L"START");
      LOBYTE(v105) = 63;
    }
    else
    {
      std::wstring::wstring(&result, L"PIT");
      LOBYTE(v105) = 64;
    }
    CarAvatar::goToSpawnPosition(v66, &result);
    LOBYTE(v105) = 60;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    CarAvatar::resetTimeTransponder(v66);
    v71 = remoteCars._Mylast;
    if ( remoteCars._Myfirst != remoteCars._Mylast )
    {
      v72 = &remoteCars._Myfirst->driverName._Myres;
      do
      {
        v5("REMOTE CAR: %d\n", *((unsigned __int8 *)v72 + 52));
        if ( *(v72 - 18) < 8 )
          v73 = (const wchar_t *)(v72 - 23);
        else
          v73 = (const wchar_t *)*(v72 - 23);
        v5("MODEL: %S\n", v73);
        if ( *(v72 - 6) < 8 )
          v74 = (const wchar_t *)(v72 - 11);
        else
          v74 = (const wchar_t *)*(v72 - 11);
        v5("SKIN: %S\n", v74);
        if ( *v72 < 8 )
          v75 = (const wchar_t *)(v72 - 5);
        else
          v75 = (const wchar_t *)*(v72 - 5);
        v5("DRIVER: %S\n", v75);
        v76 = (DriverInfo *)(v72 + 1);
        if ( v72[6] < 8 )
          v77 = (const wchar_t *)(v72 + 1);
        else
          v77 = v76->name._Bx._Ptr;
        v5("TEAM: %S\n", v77);
        v78 = (DriverInfo *)(v72 + 7);
        if ( v72[12] < 8 )
          v79 = (const wchar_t *)(v72 + 7);
        else
          v79 = v78->name._Bx._Ptr;
        _printf("NATION: %S\n", v79);
        hints._Myfirst = (std::wstring *)Sim::addNetCar(v93->sim, (ClientRemoteCarDef *)(v72 - 23), client);
        v99.name._Myres = 7;
        v99.name._Mysize = 0;
        v99.name._Bx._Buf[0] = 0;
        v99.team._Myres = 7;
        v99.team._Mysize = 0;
        v99.team._Bx._Buf[0] = 0;
        v99.nationality._Myres = 7;
        v99.nationality._Mysize = 0;
        v99.nationality._Bx._Buf[0] = 0;
        v99.nationCode._Myres = 7;
        v99.nationCode._Mysize = 0;
        v99.nationCode._Bx._Buf[0] = 0;
        LOBYTE(v105) = 65;
        if ( &v99 != (DriverInfo *)(v72 - 5) )
          std::wstring::assign(&v99.name, (const std::wstring *)(v72 - 5), 0, 0xFFFFFFFF);
        if ( &v99.team != (std::wstring *)v76 )
          std::wstring::assign(&v99.team, (const std::wstring *)(v72 + 1), 0, 0xFFFFFFFF);
        if ( &v99.nationCode != (std::wstring *)v78 )
          std::wstring::assign(&v99.nationCode, (const std::wstring *)(v72 + 7), 0, 0xFFFFFFFF);
        CarAvatar::setDriverInfo((CarAvatar *)hints._Myfirst, &v99);
        std::wstring::wstring(&result, L"START");
        v85 = *((unsigned __int8 *)v72 + 52);
        LOBYTE(v105) = 66;
        CarAvatar::setSpawnPositionIndex((CarAvatar *)hints._Myfirst, &result, v85);
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        LOBYTE(v105) = 60;
        SetupItemText::~SetupItemText(&v99);
        v5 = (void (*)(const char *const, ...))_printf;
        v72 += 42;
      }
      while ( v72 - 23 != (unsigned int *)v71 );
      v4 = v93;
      v8 = client;
    }
    std::wstring::wstring(&result, L"4_mid_clear");
    v80 = v4->sim;
    LOBYTE(v105) = 67;
    Sim::applyCustomWeather(v80, &result);
    LOBYTE(v105) = 60;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    ACClient::beginUpdateMode(v8);
    ACClient::askForP2Pvalue(v8);
    v81 = v4->sim->client;
    if ( v81 )
      ACClient::resetCurrentLaps(v81);
    v82 = v4->raceTimingServices;
    if ( v82 )
      RaceTimingServices::resetCurrentLaps(v82);
    RaceManager::resetMandatoryPit(v4);
    v13 = 1;
    LOBYTE(v105) = 58;
    if ( final_checksum._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&final_checksum);
      operator delete(final_checksum._Myfirst);
      final_checksum._Myfirst = 0;
      final_checksum._Mylast = 0;
      final_checksum._Myend = 0;
    }
    LOBYTE(v105) = 54;
    if ( loading_checksum._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&loading_checksum);
      operator delete(loading_checksum._Myfirst);
      loading_checksum._Myfirst = 0;
      loading_checksum._Mylast = 0;
      loading_checksum._Myend = 0;
    }
  }
  else
  {
    _printf("RaceManager :: getRemoteCarList FAILED\n");
    v13 = 0;
  }
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v95);
  LOBYTE(v105) = 3;
  std::vector<ClientRemoteCarDef>::_Tidy(&remoteCars);
LABEL_159:
  ClientHandshakeResult::~ClientHandshakeResult(&res);
  return v13;
}
char __userpurge RaceManager::initReplay@<al>(RaceManager *this@<ecx>, __m128 a2@<xmm3>, __m128 a3@<xmm4>, INIReaderDocuments *r)
{
  ICollisionObject *v5; // esi
  PhysicsAvatar *v6; // eax
  ICollisionObject *v7; // eax
  ICollisionObject *v8; // ebx
  Sim *v9; // esi
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  const std::wstring *v12; // eax
  Sim *v13; // ecx
  double v14; // st7
  Sim *v15; // ecx
  ICollisionObject *_Val; // [esp+10h] [ebp-A4h] BYREF
  std::wstring v18; // [esp+14h] [ebp-A0h] BYREF
  std::wstring key; // [esp+2Ch] [ebp-88h] BYREF
  std::wstring section; // [esp+44h] [ebp-70h] BYREF
  std::wstring v21; // [esp+5Ch] [ebp-58h] BYREF
  std::wstring filename; // [esp+74h] [ebp-40h] BYREF
  std::wstring result; // [esp+8Ch] [ebp-28h] BYREF
  int v24; // [esp+B0h] [ebp-4h]

  RaceManager::initLighting(this, r);
  v5 = (ICollisionObject *)operator new(264);
  _Val = v5;
  v24 = 0;
  if ( v5 )
  {
    v6 = GameObject::getGameObject<PhysicsAvatar>(this->sim);
    ReplayManager::ReplayManager((ReplayManager *)v5, this->sim, v6);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  v9 = this->sim;
  v24 = -1;
  _Val = v8;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&v9->gameObjects, &_Val);
  v8[9].__vftable = (ICollisionObject_vtbl *)v9;
  this->sim->replayManager = (ReplayManager *)v8;
  if ( Sim::benchmarkMode )
  {
    v14 = ksGetTime();
    v18._Myres = 7;
    v18._Mysize = 0;
    BenchmarkMode::loadingStartTime = v14;
    v18._Bx._Buf[0] = 0;
    std::wstring::assign(&v18, L"content/benchmark/benchmark.acr", 0x1Fu);
    v15 = this->sim;
    v24 = 9;
    ReplayManager::load(v15->replayManager, a2, a3, &v18);
    if ( v18._Myres >= 8 )
      operator delete(v18._Bx._Ptr);
  }
  else
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"FILENAME", 8u);
    v24 = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"REPLAY", 6u);
    LOBYTE(v24) = 2;
    INIReader::getString(r, &filename, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v24) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Bx._Buf[0] = 0;
    key._Mysize = 0;
    v10 = Path::getDocumentPath(&result);
    LOBYTE(v24) = 6;
    v11 = std::operator+<wchar_t>(&v21, v10, L"/Assetto Corsa/replay/");
    LOBYTE(v24) = 7;
    v12 = std::operator+<wchar_t>(&v18, v11, &filename);
    v13 = this->sim;
    LOBYTE(v24) = 8;
    ReplayManager::load(v13->replayManager, a2, a3, v12);
    if ( v18._Myres >= 8 )
      operator delete(v18._Bx._Ptr);
    v18._Myres = 7;
    v18._Mysize = 0;
    v18._Bx._Buf[0] = 0;
    if ( v21._Myres >= 8 )
      operator delete(v21._Bx._Ptr);
    v21._Myres = 7;
    v21._Mysize = 0;
    v21._Bx._Buf[0] = 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
  }
  return 1;
}
bool RaceManager::isBestSplit(RaceManager *this, const int *sector, const int *t, const bool *isGlobal, CarAvatar *car)
{
  bool result; // al
  ACClient *v6; // ecx

  if ( !*t )
    goto LABEL_6;
  if ( this->raceTimingServices )
    return RaceTimingServices::isBestSplit(this->raceTimingServices, sector, t, isGlobal, car);
  v6 = this->sim->client;
  if ( v6 )
    result = ACClient::isBestSplit(v6, sector, t, isGlobal, car);
  else
LABEL_6:
    result = 0;
  return result;
}
char RaceManager::isRaceOver(RaceManager *this, unsigned int carIndex)
{
  Sim *v3; // ecx
  ACClient *v4; // eax
  CarAvatar *v6; // eax

  v3 = this->sim;
  v4 = v3->client;
  if ( v4 )
    return v4->hasPlayerFinished;
  if ( this->currentSession.sessionType == Race )
  {
    if ( !this->currentSession.isTimedRace )
    {
      v6 = Sim::getCar(v3, carIndex);
      if ( (unsigned int)RaceManager::getLapCount(this, v6) >= this->currentSession.laps )
        return 1;
    }
    if ( this->currentSession.isOver
      && (RaceManager::getHasCompletedFlag(this, this->carsRaceStatus._Myfirst[carIndex].car)
       || this->currentSession.isOver
       && (CarAvatar::isInPit(this->carsRaceStatus._Myfirst[carIndex].car)
        || this->carsRaceStatus._Myfirst[carIndex].car->filteredSpeed < 1.0)) )
    {
      return 1;
    }
  }
  return 0;
}
bool RaceManager::isSkinAvailable(RaceManager *this, const std::wstring *model, const std::wstring *skin)
{
  std::wstring *v3; // eax
  std::wstring *v4; // eax
  bool v5; // bl
  std::wstring result; // [esp+Ch] [ebp-58h] BYREF
  std::wstring v8; // [esp+24h] [ebp-40h] BYREF
  std::wstring folder_name; // [esp+3Ch] [ebp-28h] BYREF
  int v10; // [esp+60h] [ebp-4h]

  v3 = std::operator+<wchar_t>(&result, L"content/cars/", model);
  v10 = 0;
  v4 = std::operator+<wchar_t>(&v8, v3, L"/skins/");
  LOBYTE(v10) = 1;
  std::operator+<wchar_t>(&folder_name, v4, skin);
  if ( v8._Myres >= 8 )
    operator delete(v8._Bx._Ptr);
  v8._Myres = 7;
  v8._Mysize = 0;
  v8._Bx._Buf[0] = 0;
  LOBYTE(v10) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  v5 = Path::folderExists(&folder_name);
  if ( folder_name._Myres >= 8 )
    operator delete(folder_name._Bx._Ptr);
  return v5;
}
char __usercall RaceManager::loadSessions@<al>(RaceManager *this@<ecx>, unsigned int a2@<ebx>, __m128 a3@<xmm0>, __m128 a4@<xmm3>, __m128 a5@<xmm4>)
{
  char v6; // bl
  bool v7; // bl
  bool v8; // bl
  bool v9; // bl
  char v10; // al
  Sim *v11; // ecx
  unsigned int i; // edi
  ACClient *v13; // ecx
  unsigned int v14; // eax
  Sim *v15; // ecx
  Sim *v16; // eax
  unsigned int v17; // edi
  Sim *v18; // ecx
  CarAvatar *v19; // eax
  std::wstring *v20; // eax
  std::wstring v22; // [esp-1Ch] [ebp-C0h] BYREF
  INIReaderDocuments *v23; // [esp-4h] [ebp-A8h]
  int v24; // [esp+1Ch] [ebp-88h]
  std::wstring section; // [esp+20h] [ebp-84h] BYREF
  std::wstring key; // [esp+38h] [ebp-6Ch] BYREF
  INIReaderDocuments r; // [esp+50h] [ebp-54h] BYREF
  int v28; // [esp+A0h] [ebp-4h]

  v23 = 0;
  v24 = 0;
  v22._Myres = 7;
  v22._Mysize = 0;
  v22._Bx._Buf[0] = 0;
  std::wstring::assign(&v22, L"cfg/race.ini", 0xCu);
  INIReaderDocuments::INIReaderDocuments(&r, a2, v22, (bool)v23);
  v28 = 0;
  INIReader::setVerboseMode(&r, 1);
  v6 = 0;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  if ( r.ready )
  {
    std::wstring::assign(&section, L"BENCHMARK", 9u);
    LOBYTE(v28) = 1;
    v7 = INIReader::hasSection(&r, &section);
    LOBYTE(v28) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v7 )
    {
      std::wstring::wstring(&key, L"ACTIVE");
      LOBYTE(v28) = 2;
      std::wstring::wstring(&section, L"BENCHMARK");
      LOBYTE(v28) = 3;
      Sim::benchmarkMode = INIReader::getInt(&r, &section, &key) != 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v28) = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      if ( Sim::benchmarkMode )
        _printf("************ BENCHMARK MODE **************\n");
    }
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ACTIVE", 6u);
    LOBYTE(v28) = 4;
    v24 = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"REPLAY", 6u);
    v28 = 5;
    v24 = 3;
    v8 = INIReader::getInt(&r, &section, &key) || Sim::benchmarkMode;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    v28 = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v8 )
    {
      v6 = RaceManager::initReplay(this, a4, a5, &r);
    }
    else
    {
      std::wstring::wstring(&key, L"ACTIVE");
      LOBYTE(v28) = 6;
      v24 = 4;
      std::wstring::wstring(&section, L"REMOTE");
      v28 = 7;
      v24 = 12;
      v9 = INIReader::getInt(&r, &section, &key) || Sim::forceOnline;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      v28 = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      v23 = &r;
      if ( v9 )
        v10 = RaceManager::initOnline(this, a4, a5, v23);
      else
        v10 = RaceManager::initOffline(this, a3, a4, a5, v23);
      v11 = this->sim;
      v6 = v10;
      for ( i = 0; i < v11->cars._Mylast - v11->cars._Myfirst; ++i )
      {
        *(_QWORD *)section._Bx._Buf = (unsigned int)Sim::getCar(v11, i) | 0x40A0000000000000i64;
        section._Bx._Alias[8] = 0;
        *(_DWORD *)&section._Bx._Alias[12] = 0;
        section._Mysize = 1084227584;
        std::vector<CubicSpline<float,float>::Element,std::allocator<CubicSpline<float,float>::Element>>::push_back(
          (std::vector<TyreTestFrame> *)&this->carsRaceStatus,
          (const TyreTestFrame *)&section);
        key._Bx._Ptr = (wchar_t *)Sim::getCar(this->sim, i);
        *(_DWORD *)&key._Bx._Alias[8] = -1082130432;
        key._Bx._Alias[4] = 0;
        std::vector<PitStopStrategy>::push_back(
          (std::vector<PenaltyRecord> *)&this->carsRealTimePosition,
          (PenaltyRecord *)&key);
        v11 = this->sim;
      }
      v13 = this->sim->client;
      if ( v13 )
        v14 = ACClient::getSessionCount(v13);
      else
        v14 = this->sessions._Mylast - this->sessions._Myfirst;
      std::vector<std::vector<LeaderboardEntry>>::resize(
        (std::vector<std::vector<WingState>> *)&this->leaderboardHistory,
        v14);
      v15 = this->sim;
      if ( v15->client )
      {
        v23 = (INIReaderDocuments *)this;
        v22._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_f6a64d8a54227b2f743428c631e617f1_,0>,std::allocator<std::_Func_class<void,OnLapCompletedEvent const &>>,void,OnLapCompletedEvent const &>::`vftable';
        *(_DWORD *)&v22._Bx._Alias[4] = this;
        v22._Mysize = (unsigned int)&v22;
        v16 = this->sim;
        LOBYTE(v28) = 0;
        Event<std::wstring>::addHandler(
          (Event<OnPhysicsStepCompleted> *)&v16->client->evOnLapCompleted,
          (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v22,
          this);
      }
      else
      {
        v17 = 0;
        if ( v15->cars._Mylast - v15->cars._Myfirst )
        {
          do
          {
            v23 = (INIReaderDocuments *)this;
            v24 = (int)&v22;
            v22._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_c4116babb8d0c89a747015575c7e2744_,0>,std::allocator<std::_Func_class<void,OnLapCompletedEvent const &>>,void,OnLapCompletedEvent const &>::`vftable';
            *(_DWORD *)&v22._Bx._Alias[4] = this;
            v22._Mysize = (unsigned int)&v22;
            v18 = this->sim;
            LOBYTE(v28) = 10;
            v19 = Sim::getCar(v18, v17);
            LOBYTE(v28) = 0;
            Event<std::wstring>::addHandler(
              (Event<OnPhysicsStepCompleted> *)&v19->evOnLapCompleted,
              (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v22,
              v23);
            ++v17;
          }
          while ( v17 < this->sim->cars._Mylast - this->sim->cars._Myfirst );
        }
      }
    }
  }
  else
  {
    std::wstring::assign(&section, L"race.ini not found", 0x12u);
    v20 = &section;
    LOBYTE(v28) = 11;
    if ( section._Myres >= 8 )
      v20 = (std::wstring *)section._Bx._Ptr;
    _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v20->_Bx._Buf);
    ksGenerateCrash();
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
  }
  v28 = -1;
  INIReaderDocuments::~INIReaderDocuments(&r);
  return v6;
}
void RaceManager::onLapCompleted(RaceManager *this, const OnLapCompletedEvent *message)
{
  RaceTimingServices *v3; // ecx
  Sim *v4; // ecx
  CarAvatar *v5; // eax
  CarAvatar *v6; // eax
  unsigned int *v7; // ecx
  bool v8; // zf
  CarAvatar *v9; // eax
  CarAvatar *v10; // eax
  RaceTimingServices *v11; // ecx
  CarAvatar *v12; // esi
  unsigned int v13; // eax
  std::pair<void *,std::function<void __cdecl(OnLapCompletedEvent const &)> > *v14; // esi
  std::_Func_base<void,OnLapCompletedEvent const &> **v15; // edi

  v3 = this->raceTimingServices;
  if ( v3 )
    RaceTimingServices::onLapCompleted(v3, message);
  v4 = this->sim;
  if ( !v4->client )
  {
    if ( this->currentSession.sessionType == Qualify )
    {
      if ( this->currentSession.overtime_ms > 0.0 )
      {
        v10 = Sim::getCar(v4, message->carIndex);
        v11 = this->raceTimingServices;
        v12 = v10;
        if ( v11 )
          RaceTimingServices::setHasCompletedFlag(v11, v10, 1);
        if ( this->sim->client )
        {
          v13 = CarAvatar::getGuid(v12);
          this->multiplayerStatus.completedFlags._Myvec._Myfirst[v13 >> 5] |= 1 << (v13 & 0x1F);
        }
      }
    }
    else if ( this->currentSession.sessionType == Race )
    {
      if ( this->currentSession.isTimedRace )
      {
        if ( this->timeRaceEnded )
        {
          if ( this->hasAdditionalLap )
          {
            if ( this->isTimedLastLap )
            {
              v5 = Sim::getCar(v4, message->carIndex);
              RaceManager::setHasCompletedFlag(this, v5, 1);
            }
            this->isTimedLastLap = 1;
          }
          else
          {
            v6 = Sim::getCar(v4, message->carIndex);
            RaceManager::setHasCompletedFlag(this, v6, 1);
          }
        }
      }
      else
      {
        v7 = &this->currentSession.leaderCompletedLaps;
        if ( this->currentSession.leaderCompletedLaps < message->lapCount )
          v7 = &message->lapCount;
        v8 = !this->currentSession.isOver;
        this->currentSession.leaderCompletedLaps = *v7;
        if ( !v8 )
          goto LABEL_19;
        if ( RaceManager::isRaceOver(this, message->carIndex) )
          this->currentSession.isOver = 1;
        if ( this->currentSession.isOver )
        {
LABEL_19:
          v9 = Sim::getCar(this->sim, message->carIndex);
          RaceManager::setHasCompletedFlag(this, v9, 1);
        }
      }
    }
  }
  v14 = this->evOnLapCompleted.handlers._Myfirst;
  if ( v14 != this->evOnLapCompleted.handlers._Mylast )
  {
    v15 = &v14->second._Impl;
    do
    {
      if ( !*v15 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x635646);
      }
      (*v15)->_Do_call(*v15, message);
      ++v14;
      v15 += 8;
    }
    while ( v14 != this->evOnLapCompleted.handlers._Mylast );
  }
}
void RaceManager::renderHUD(RaceManager *this, float dt)
{
  Sim *v3; // ecx
  std::wstring *v4; // eax
  std::wstring *v5; // eax
  RaceStatusCarDesc *v6; // edi
  int v7; // ebp
  RaceStatusCarDesc *i; // esi
  std::wstring *v9; // esi
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  const std::wstring *v12; // eax
  Sim *v13; // ecx
  EndSessionDisplayer *v14; // eax
  Sim *v15; // ecx
  CarAvatar *v16; // eax
  unsigned int v17; // esi
  const std::wstring *v18; // eax
  std::wostream *v19; // eax
  std::wostream *v20; // eax
  unsigned int v21; // esi
  unsigned int v22; // esi
  const std::wstring *v23; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v24; // ecx
  const std::wstring *v25; // eax
  const std::wstring *v26; // eax
  const std::wstring *v27; // eax
  std::wostream *v28; // eax
  std::wostream *v29; // eax
  const std::wstring *v30; // eax
  std::wostream *v31; // eax
  Game *v32; // eax
  Font *v33; // ecx
  const std::wstring *v34; // [esp+1Ch] [ebp-1A8h]
  const std::wstring *ascale; // [esp+20h] [ebp-1A4h]
  int v36; // [esp+40h] [ebp-184h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v37; // [esp+44h] [ebp-180h] BYREF
  std::wstring text; // [esp+F4h] [ebp-D0h] BYREF
  std::wstring v39; // [esp+10Ch] [ebp-B8h] BYREF
  std::wstring result; // [esp+124h] [ebp-A0h] BYREF
  std::wstring s; // [esp+13Ch] [ebp-88h] BYREF
  std::wstring v42; // [esp+154h] [ebp-70h] BYREF
  std::wstring v43; // [esp+16Ch] [ebp-58h] BYREF
  std::wstring v44; // [esp+184h] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v45; // [esp+19Ch] [ebp-28h] BYREF
  int v46; // [esp+1C0h] [ebp-4h]

  v36 = 0;
  v3 = this->sim;
  if ( !v3->pauseMenu->visible && !v3->escMenu->visible && !ReplayManager::isInReplaymode(v3->replayManager) )
  {
    if ( this->currentSession.sessionType == Qualify
      && CarAvatar::isInPit(this->carsRaceStatus._Myfirst->car)
      && RaceManager::getHasCompletedFlag(this, this->carsRaceStatus._Myfirst->car) )
    {
      s._Myres = 7;
      s._Mysize = 0;
      s._Bx._Buf[0] = 0;
      v46 = 0;
      std::wstring::wstring(&text, L"Qualify finished waiting for");
      LOBYTE(v46) = 1;
      v4 = acTranslate(&result, &text);
      LOBYTE(v46) = 2;
      v5 = std::operator+<wchar_t>(&v39, v4, L" ");
      std::wstring::operator=(&s, v5);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v39);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      LOBYTE(v46) = 0;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
      v6 = this->carsRaceStatus._Mylast;
      v7 = 0;
      for ( i = this->carsRaceStatus._Myfirst; i != v6; ++i )
      {
        if ( !RaceManager::getHasCompletedFlag(this, i->car) )
          ++v7;
      }
      std::wstring::wstring(&text, L"cars");
      LOBYTE(v46) = 3;
      v9 = acTranslate(&v39, &text);
      LOBYTE(v46) = 4;
      v10 = std::to_wstring(&result, v7);
      LOBYTE(v46) = 5;
      v11 = std::operator+<wchar_t>(&v42, v10, L" ");
      LOBYTE(v46) = 6;
      v12 = std::operator+<wchar_t>(&v43, v11, v9);
      LOBYTE(v46) = 7;
      std::wstring::append(&s, v12, 0, 0xFFFFFFFF);
      if ( v43._Myres >= 8 )
        operator delete(v43._Bx._Ptr);
      v43._Myres = 7;
      v43._Mysize = 0;
      v43._Bx._Buf[0] = 0;
      if ( v42._Myres >= 8 )
        operator delete(v42._Bx._Ptr);
      v42._Myres = 7;
      v42._Mysize = 0;
      v42._Bx._Buf[0] = 0;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      if ( v39._Myres >= 8 )
        operator delete(v39._Bx._Ptr);
      v39._Myres = 7;
      v39._Mysize = 0;
      v39._Bx._Buf[0] = 0;
      LOBYTE(v46) = 0;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      Font::blitString(
        this->font._Ptr,
        (float)(this->game->graphics->videoSettings.width / 2),
        90.0,
        &s,
        1.0,
        eAlignCenter);
      v46 = -1;
      if ( s._Myres >= 8 )
        operator delete(s._Bx._Ptr);
    }
    if ( this->currentSession.sessionType == Race )
    {
      if ( RaceManager::isRaceOver(this, 0) )
      {
        v13 = this->sim;
        v14 = v13->endSessionDisplayer;
        if ( (!v14 || !v14->isActive) && !Sim::getCar(v13, 0)->isBlackFlagged )
        {
          *(_DWORD *)v37.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v37.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v37.gap68);
          v46 = 8;
          v36 = 1;
          std::wiostream::basic_iostream<wchar_t>(&v37, &v37.gap10[8], 0);
          v46 = 9;
          *(_DWORD *)&v37.gap0[*(_DWORD *)(*(_DWORD *)v37.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(int *)((char *)&v36 + *(_DWORD *)(*(_DWORD *)v37.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v37.gap0 + 4) - 104;
          std::wstreambuf::wstreambuf(&v37.gap10[8]);
          *(_DWORD *)&v37.gap10[8] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v37.gap10[64] = 0;
          *(_DWORD *)&v37.gap10[68] = 0;
          v15 = this->sim;
          v46 = 11;
          v16 = Sim::getCar(v15, 0);
          v17 = RaceManager::getCarLeaderboardPosition(this, v16);
          std::wstring::wstring(&text, L"Race");
          LOBYTE(v46) = 12;
          v18 = acTranslate(&v39, &text);
          LOBYTE(v46) = 13;
          v19 = std::operator<<<wchar_t>((std::wostream *)v37.gap10, v18);
          v20 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v19, " : ");
          std::wostream::operator<<(v20, v17);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v39);
          LOBYTE(v46) = 11;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
          v21 = v17 - 1;
          if ( v21 )
          {
            v22 = v21 - 1;
            if ( v22 )
            {
              if ( v22 == 1 )
              {
                std::wstring::wstring(&v39, L"rd");
                LOBYTE(v46) = 18;
                v25 = acTranslate(&s, &v39);
                LOBYTE(v46) = 19;
                std::operator<<<wchar_t>((std::wostream *)v37.gap10, v25);
                std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
                v24 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v39;
              }
              else
              {
                std::wstring::wstring(&text, L"th");
                LOBYTE(v46) = 20;
                v23 = acTranslate(&v43, &text);
                LOBYTE(v46) = 21;
                std::operator<<<wchar_t>((std::wostream *)v37.gap10, v23);
                std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v43);
                v24 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text;
              }
            }
            else
            {
              std::wstring::wstring(&result, L"nd");
              LOBYTE(v46) = 16;
              v26 = acTranslate(&v45.name, &result);
              LOBYTE(v46) = 17;
              std::operator<<<wchar_t>((std::wostream *)v37.gap10, v26);
              std::wstring::~wstring(&v45);
              v24 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result;
            }
          }
          else
          {
            std::wstring::wstring(&v42, L"st");
            LOBYTE(v46) = 14;
            v27 = acTranslate(&v44, &v42);
            LOBYTE(v46) = 15;
            std::operator<<<wchar_t>((std::wostream *)v37.gap10, v27);
            std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v44);
            v24 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v42;
          }
          LOBYTE(v46) = 11;
          std::wstring::~wstring(v24);
          std::wstring::wstring(&text, L"place");
          LOBYTE(v46) = 22;
          ascale = acTranslate(&v44, &text);
          LOBYTE(v46) = 23;
          v28 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v37.gap10, " ");
          v29 = std::operator<<<wchar_t>(v28, ascale);
          std::wostream::operator<<(v29);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v44);
          LOBYTE(v46) = 11;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
          std::wstring::wstring(&text, L"Session Over");
          LOBYTE(v46) = 24;
          v30 = acTranslate(&v44, &text);
          LOBYTE(v46) = 25;
          v31 = std::operator<<<wchar_t>((std::wostream *)v37.gap10, v30);
          std::wostream::operator<<(v31);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v44);
          LOBYTE(v46) = 11;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
          v34 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v37, &v44);
          v32 = this->game;
          v33 = this->font._Ptr;
          LOBYTE(v46) = 26;
          Font::blitString(v33, (float)(v32->graphics->videoSettings.width / 2), 90.0, v34, 1.0, eAlignCenter);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v44);
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v37);
        }
      }
    }
  }
}
void RaceManager::resetCurrentLaps(RaceManager *this)
{
  ACClient *v2; // ecx
  RaceTimingServices *v3; // ecx

  v2 = this->sim->client;
  if ( v2 )
    ACClient::resetCurrentLaps(v2);
  v3 = this->raceTimingServices;
  if ( v3 )
    RaceTimingServices::resetCurrentLaps(v3);
}
void RaceManager::resetInvalidStateCarsToPits(RaceManager *this, float dt)
{
  std::map<std::wstring,float> *v3; // ecx
  float v4; // xmm0_4
  RaceStatusCarDesc *v5; // esi
  RaceStatusCarDesc *i; // edi
  RaceEngineer *v7; // ecx
  int v8; // ebp
  int j; // ebx
  CarAvatar *v10; // ecx
  std::wstring setName; // [esp+14h] [ebp-40h] BYREF
  std::wstring _Keyval; // [esp+2Ch] [ebp-28h] BYREF
  int v13; // [esp+50h] [ebp-4h]

  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"AUTOFLIP_RECOVERY", 0x11u);
  v3 = &this->sim->optionsManager.options;
  v13 = 0;
  v4 = *std::map<std::wstring,float>::operator[](v3, &_Keyval);
  v13 = -1;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  if ( v4 != 0.0 )
  {
    if ( dt > 0.5 )
      dt = FLOAT_0_5;
    v5 = this->carsRaceStatus._Myfirst;
    for ( i = this->carsRaceStatus._Mylast; v5 != i; ++v5 )
    {
      v7 = v5->car->raceEngineer._Myptr;
      if ( v7 && RaceEngineer::getCar(v7) )
      {
        v8 = 0;
        for ( j = 0; j < 4; ++j )
        {
          if ( RaceEngineer::getCar(v5->car->raceEngineer._Myptr)->tyres[j].status.load > 0.0 )
            ++v8;
        }
        if ( v8 < 2 )
          v5->invalidStateTimer = v5->invalidStateTimer + dt;
        else
          v5->invalidStateTimer = 0.0;
      }
      if ( v5->invalidStateTimer >= v5->maxInvalidStateTimer )
      {
        _printf("INVALID STATE RESET\n");
        setName._Myres = 7;
        setName._Mysize = 0;
        setName._Bx._Buf[0] = 0;
        std::wstring::assign(&setName, L"PIT", 3u);
        v10 = v5->car;
        v13 = 1;
        CarAvatar::goToSpawnPosition(v10, &setName);
        v13 = -1;
        if ( setName._Myres >= 8 )
          operator delete(setName._Bx._Ptr);
        setName._Myres = 7;
        setName._Mysize = 0;
        setName._Bx._Buf[0] = 0;
        v5->invalidStateTimer = 0.0;
      }
    }
  }
}
void RaceManager::resetMandatoryPit(RaceManager *this)
{
  unsigned int i; // edi
  CarAvatar *v3; // eax
  CarAvatar *v4; // eax
  CarAvatar *v5; // eax

  for ( i = 0; i < this->sim->cars._Mylast - this->sim->cars._Myfirst; v5->pitLaneExitTime = 0.0 )
  {
    v3 = Sim::getCar(this->sim, i);
    CarAvatar::lockControlsUntilTime(v3, 0.0, 0.0, 0);
    v4 = Sim::getCar(this->sim, i);
    CarAvatar::resetPenalty(v4, 1);
    Sim::getCar(this->sim, i)->lastPitstopTime = 0.0;
    Sim::getCar(this->sim, i)->mandatoryPitstopDone = 0;
    v5 = Sim::getCar(this->sim, i++);
    v5->pitLaneEntryTime = 0.0;
  }
  this->pitWindowStartTime = 0.0;
  this->pitWindowEndTime = 0.0;
}
void RaceManager::restartCurrentSession(RaceManager *this)
{
  ACCameraManager *v2; // ecx
  Sim *v3; // ecx
  Sim *v4; // ecx
  ACCameraManager *v5; // ecx
  std::function<void __cdecl(bool const &)> v6; // [esp-1Ch] [ebp-48h] BYREF
  RaceManager *v7; // [esp-4h] [ebp-30h]
  __m128i v8; // [esp+10h] [ebp-1Ch] BYREF
  int v9; // [esp+28h] [ebp-4h]

  v2 = this->sim->cameraManager;
  if ( v2 )
  {
    if ( (((char *)v2->evOnFadeInFinished.handlers._Mylast - (char *)v2->evOnFadeInFinished.handlers._Myfirst) & 0xFFFFFFE0) == 0 )
    {
      v7 = this;
      v6._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_dbba9b0d9e9513ca461adfb6c16f36e3_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
      v6._Space._Pfn[1] = (void (__cdecl *)())this;
      v6._Impl = (std::_Func_base<void,bool const &> *)&v6;
      v3 = this->sim;
      v9 = -1;
      ACCameraManager::registerToFadeInEvent(v3->cameraManager, v6, this);
      v4 = this->sim;
      v8.m128i_i32[0] = 0;
      v8.m128i_i32[3] = (int)this;
      v5 = v4->cameraManager;
      *(__int64 *)((char *)v8.m128i_i64 + 4) = 0x3F80000000000000i64;
      ACCameraManager::fadeIn(v5, (FadeModeDef)_mm_loadu_si128(&v8));
    }
  }
  else
  {
    RaceManager::setCurrentSession(this, this->currentSessionIndex);
  }
}
void RaceManager::setCurrentSession(RaceManager *this, unsigned int index)
{
  RaceManager *v2; // ebx
  Session *v3; // esi
  SessionType v4; // eax
  PhysicsAvatar *v5; // eax
  unsigned int i; // edi
  CarAvatar *v7; // eax
  CarAvatar *v8; // eax
  CarAvatar *v9; // eax
  RealTimeCarDesc *v10; // ecx
  RealTimeCarDesc *j; // eax
  float v12; // xmm0_4
  float v13; // xmm0_4
  long double v14; // xmm0_8
  int v15; // eax
  unsigned int *v16; // esi
  unsigned int v17; // edi
  RaceStatusCarDesc *v18; // edi
  RaceStatusCarDesc *k; // esi
  CarAvatar *v20; // ecx
  unsigned int v21; // edx
  int v22; // eax
  unsigned int *v23; // ecx
  int v24; // edi
  ACClient *v25; // ecx
  RaceTimingServices *v26; // ecx
  int v27; // [esp+5Ch] [ebp-BCh]
  unsigned int *v28; // [esp+5Ch] [ebp-BCh]
  OnNewSessionEvent ev; // [esp+68h] [ebp-B0h] BYREF
  int v31; // [esp+114h] [ebp-4h]

  v2 = this;
  if ( index >= this->sessions._Mylast - this->sessions._Myfirst )
    return;
  v3 = &this->currentSession;
  Session::operator=(&this->currentSession, &this->sessions._Myfirst[index]);
  v4 = v2->currentSession.sessionType;
  v2->currentSessionIndex = index;
  if ( v4 != Race || v2->sim->client )
    v2->currentSession.startTime = ksGetTime();
  else
    v2->currentSession.startTime = DOUBLE_1_797693134862316e308;
  v5 = v2->sim->physicsAvatar;
  v5->engine.penaltyMode = v3->sessionType != Race;
  for ( i = 0; i < v2->sim->cars._Mylast - v2->sim->cars._Myfirst; v9->pitLaneExitTime = 0.0 )
  {
    v7 = Sim::getCar(v2->sim, i);
    CarAvatar::lockControlsUntilTime(v7, 0.0, 0.0, 0);
    v8 = Sim::getCar(v2->sim, i);
    CarAvatar::resetPenalty(v8, 1);
    Sim::getCar(v2->sim, i)->lastPitstopTime = 0.0;
    Sim::getCar(v2->sim, i)->mandatoryPitstopDone = 0;
    v9 = Sim::getCar(v2->sim, i++);
    v9->pitLaneEntryTime = 0.0;
  }
  v2->pitWindowStartTime = 0.0;
  v2->pitWindowEndTime = 0.0;
  *(_WORD *)&v2->timeRaceEnded = 0;
  v2->currentSession.isOver = 0;
  v10 = v2->carsRealTimePosition._Mylast;
  for ( j = v2->carsRealTimePosition._Myfirst; j != v10; ++j )
  {
    j->crossedForTheFirstTime = 0;
    j->approxPos = -1.0;
  }
  *(_WORD *)&ev.newSession.isTimedRace = 0;
  ev.newSession.spawSet._Myres = 7;
  ev.newSession.spawSet._Mysize = 0;
  ev.newSession.spawSet._Bx._Buf[0] = 0;
  v31 = 1;
  ev.newSession.name._Myres = 7;
  ev.newSession.name._Mysize = 0;
  ev.newSession.name._Bx._Buf[0] = 0;
  ev.newSession.leaderCompletedLaps = 0;
  std::wstring::assign(&ev.newSession.name, L"UNNAMED", 7u);
  ev.newSession.isOver = 0;
  ev.newSession.startTime = 0.0;
  ev.newSession.forcedPosition = -1;
  v12 = v2->currentSession.durationMinutes;
  ev.index = index;
  ev.newSession.sessionType = v3->sessionType;
  *(_WORD *)&ev.newSession.isTimedRace = v2->currentSession.isTimedRace;
  ev.newSession.hasAdditionalLap = v2->currentSession.hasAdditionalLap;
  ev.newSession.laps = v2->currentSession.laps;
  ev.newSession.durationMinutes = v12;
  v13 = v2->currentSession.overtime_ms;
  v31 = 2;
  ev.newSession.overtime_ms = v13;
  if ( &ev.newSession.spawSet != &v2->currentSession.spawSet )
    std::wstring::assign(&ev.newSession.spawSet, &v2->currentSession.spawSet, 0, 0xFFFFFFFF);
  if ( &ev.newSession.name != &v2->currentSession.name )
    std::wstring::assign(&ev.newSession.name, &v2->currentSession.name, 0, 0xFFFFFFFF);
  v14 = v2->currentSession.startTime;
  ev.newSession.forcedPosition = v2->currentSession.forcedPosition;
  ev.newSession.isOver = v2->currentSession.isOver;
  ev.newSession.leaderCompletedLaps = v2->currentSession.leaderCompletedLaps;
  v15 = (int)&v2->sim->evOnNewSession;
  ev.newSession.startTime = v14;
  v27 = v15;
  v16 = *(unsigned int **)v15;
  if ( *(_DWORD *)v15 != *(_DWORD *)(v15 + 4) )
  {
    v17 = (unsigned int)(v16 + 6);
    while ( *(_DWORD *)v17 )
    {
      (*(void (**)(_DWORD, OnNewSessionEvent *))(**(_DWORD **)v17 + 8))(*(_DWORD *)v17, &ev);
      v16 += 8;
      v17 += 32;
      if ( v16 == *(unsigned int **)(v27 + 4) )
        goto LABEL_21;
    }
    std::_Xbad_function_call();
$LN530:
    v28 = &v23[v17 >> 5];
    goto LABEL_28;
  }
LABEL_21:
  v18 = v2->carsRaceStatus._Mylast;
  for ( k = v2->carsRaceStatus._Myfirst; k != v18; ++k )
  {
    v20 = k->car;
    k->resetTimer = 5.0;
    CarAvatar::setControlsLock(v20, 0);
    k->retired = 0;
  }
  v16 = v2->multiplayerStatus.completedFlags._Myvec._Myfirst;
  v21 = 0;
  v22 = v2->multiplayerStatus.completedFlags._Mysize;
  v23 = v16;
  v24 = 0;
  v28 = v16;
  if ( !v22 )
    goto LABEL_29;
  v17 = v2->multiplayerStatus.completedFlags._Mysize;
  if ( v22 >= 0 )
    goto $LN530;
  v28 = (unsigned int *)((char *)v16 - 4 - 4 * ((unsigned int)(-1 - v22) >> 5));
LABEL_28:
  v24 = v17 & 0x1F;
LABEL_29:
  while ( v16 != v28 || v21 != v24 )
  {
    *v16 &= ~(1 << v21);
    if ( v21 >= 0x1F )
    {
      v21 = 0;
      ++v16;
    }
    else
    {
      ++v21;
    }
  }
  v25 = this->sim->client;
  if ( v25 )
    ACClient::resetCurrentLaps(v25);
  v26 = this->raceTimingServices;
  if ( v26 )
    RaceTimingServices::resetCurrentLaps(v26);
  RaceManager::resetMandatoryPit(this);
  if ( ev.newSession.name._Myres >= 8 )
    operator delete(ev.newSession.name._Bx._Ptr);
  ev.newSession.name._Myres = 7;
  ev.newSession.name._Mysize = 0;
  ev.newSession.name._Bx._Buf[0] = 0;
  if ( ev.newSession.spawSet._Myres >= 8 )
    operator delete(ev.newSession.spawSet._Bx._Ptr);
}
void RaceManager::setHasCompletedFlag(RaceManager *this, CarAvatar *car, bool value)
{
  RaceTimingServices *v4; // ecx
  unsigned int v5; // eax
  unsigned int *v6; // edx
  int v7; // eax

  v4 = this->raceTimingServices;
  if ( v4 )
    RaceTimingServices::setHasCompletedFlag(v4, car, value);
  if ( this->sim->client )
  {
    v5 = CarAvatar::getGuid(car);
    v6 = &this->multiplayerStatus.completedFlags._Myvec._Myfirst[v5 >> 5];
    v7 = 1 << (v5 & 0x1F);
    if ( value )
      *v6 |= v7;
    else
      *v6 &= ~v7;
  }
}
void RaceManager::shutdown(RaceManager *this)
{
  ReplayManager *v1; // eax

  v1 = this->sim->replayManager;
  if ( v1 )
  {
    if ( !v1->hasLoadedReplay )
      RaceManager::finalizeCurrentSession(this);
  }
}
char RaceManager::skipCurrentSession(RaceManager *this)
{
  ACCameraManager *v2; // ecx
  Sim *v3; // ecx
  Sim *v4; // ecx
  ACCameraManager *v5; // ecx
  std::function<void __cdecl(bool const &)> v7; // [esp-1Ch] [ebp-48h] BYREF
  RaceManager *v8; // [esp-4h] [ebp-30h]
  __m128i v9; // [esp+10h] [ebp-1Ch] BYREF
  int v10; // [esp+28h] [ebp-4h]

  if ( this->currentSessionIndex < (signed int)(((int)((unsigned __int64)(715827883i64
                                                                        * ((char *)this->sessions._Mylast
                                                                         - (char *)this->sessions._Myfirst)) >> 32) >> 4)
                                              + ((unsigned int)((unsigned __int64)(715827883i64
                                                                                 * ((char *)this->sessions._Mylast
                                                                                  - (char *)this->sessions._Myfirst)) >> 32) >> 31)
                                              - 1) )
  {
    v2 = this->sim->cameraManager;
    if ( v2 )
    {
      if ( (((char *)v2->evOnFadeInFinished.handlers._Mylast - (char *)v2->evOnFadeInFinished.handlers._Myfirst) & 0xFFFFFFE0) == 0 )
      {
        v8 = this;
        v7._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_813bf8c3df5835004fac3e0e9e32445e_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
        v7._Space._Pfn[1] = (void (__cdecl *)())this;
        v7._Impl = (std::_Func_base<void,bool const &> *)&v7;
        v3 = this->sim;
        v10 = -1;
        ACCameraManager::registerToFadeInEvent(v3->cameraManager, v7, this);
        v4 = this->sim;
        v9.m128i_i32[0] = 0;
        v9.m128i_i32[3] = (int)this;
        v5 = v4->cameraManager;
        *(__int64 *)((char *)v9.m128i_i64 + 4) = 0x4020000000000000i64;
        ACCameraManager::fadeIn(v5, (FadeModeDef)_mm_loadu_si128(&v9));
      }
    }
  }
  return 1;
}
void RaceManager::startRace(RaceManager *this, float millisecondsToStart)
{
  Sim *v3; // ecx
  std::function<void __cdecl(void)> v4; // [esp-18h] [ebp-38h] BYREF
  double v5; // [esp+Ch] [ebp-14h]
  int v6; // [esp+1Ch] [ebp-4h]

  if ( this->currentSession.sessionType == Race && !this->sim->client )
  {
    v5 = RaceManager::getTimeToSessionStart(this);
    if ( v5 > 0.0 )
    {
      this->currentSession.startTime = millisecondsToStart
                                     + this->game->gameTime.now
                                     + (float)((float)((float)((float)_rand() * 0.000030518509) * 2000.0) - 1000.0);
      v4._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_f0eb2e86a25b9a117567327b8bc66e48_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
      v4._Space._Pfn[1] = (void (__cdecl *)())this;
      v4._Impl = (std::_Func_base<void> *)&v4;
      v3 = this->sim;
      v6 = -1;
      PhysicsAvatar::executeOnPhysicsThread(v3->physicsAvatar, v4);
    }
  }
  this->leaderLastLap = 0;
}
void RaceManager::update(RaceManager *this, float deltaT)
{
  RaceManager *v2; // ebx
  int v3; // ebp
  Sim *v4; // ecx
  Sim *v5; // ecx
  Game *v6; // eax
  float v7; // xmm0_4
  ACClient *v8; // ecx
  SessionType v9; // esi
  RaceStatusCarDesc *v10; // esi
  RaceStatusCarDesc *v11; // edi
  CarAvatar *v12; // ecx
  std::wostream *v13; // eax
  std::wostream *v14; // eax
  std::wostream *v15; // eax
  const std::wstring *v16; // eax
  RaceStatusCarDesc *v17; // esi
  float v18; // xmm1_4
  RaceStatusCarDesc *v19; // edi
  __m128i v20; // xmm0
  CarAvatar *v21; // ebp
  Lap *v22; // eax
  int v23; // ecx
  bool v24; // zf
  Lap *v25; // eax
  unsigned int v26; // eax
  float v27; // xmm0_4
  float v28; // xmm0_4
  char v29; // al
  RaceStatusCarDesc *v30; // edi
  CarAvatar **j; // esi
  RaceTimingServices *v32; // ecx
  CarAvatar *v33; // ebp
  unsigned int v34; // eax
  CarAvatar **v35; // eax
  RaceTimingServices *v36; // ecx
  bool v37; // al
  unsigned int v38; // eax
  ACCameraManager *v39; // ecx
  Sim *v40; // ecx
  Sim *v41; // ecx
  ACCameraManager *v42; // ecx
  float v43; // xmm0_4
  int v44; // ecx
  ACCameraManager *v45; // ecx
  Sim *v46; // ecx
  Sim *v47; // ecx
  ACCameraManager *v48; // ecx
  ACClient *v49; // ecx
  RemoteSessionResult *v50; // edi
  std::vector<ClientCollisionEvent> *v51; // ebp
  char v52; // al
  Sim *v53; // ecx
  ACClient *v54; // edx
  char v55; // al
  unsigned __int16 v56; // ax
  double v57; // xmm1_8
  ACClient *v58; // eax
  unsigned __int16 v59; // ax
  unsigned int v60; // esi
  unsigned __int16 v61; // ax
  ACClient *v62; // eax
  unsigned __int16 v63; // ax
  CarAvatar *v64; // eax
  Sim *v65; // ecx
  CarAvatar *v66; // eax
  CarAvatar *v67; // eax
  unsigned int v68; // edx
  int *v69; // ecx
  unsigned int v70; // esi
  Sim *v71; // ecx
  CarAvatar *v72; // eax
  unsigned int *v73; // edi
  unsigned int v74; // eax
  unsigned int v75; // edx
  long double v76; // xmm0_8
  LeaderboardEntry *v77; // eax
  int v78; // esi
  __m128i *v79; // eax
  const __m128i *v80; // esi
  __m128i v81; // xmm0
  double v82; // xmm0_8
  LeaderboardEntry *v83; // eax
  int v84; // esi
  Sim *v85; // ecx
  unsigned int v86; // esi
  CarAvatar *v87; // eax
  char v88; // bl
  CarAvatar *v89; // eax
  ClientCollisionEvent *v90; // ecx
  ClientCollisionEvent *v91; // edi
  ClientCollisionEvent *v92; // edx
  int v93; // ecx
  unsigned int v94; // edx
  unsigned int v95; // edx
  __m128i *v96; // eax
  const __m128i *v97; // esi
  ClientCollisionEvent *v98; // edx
  int v99; // ecx
  unsigned int v100; // edx
  unsigned int v101; // edx
  __m128i *v102; // eax
  _BYTE v103[56]; // [esp-18h] [ebp-23Ch] BYREF
  int v104; // [esp+28h] [ebp-1FCh]
  unsigned int v105; // [esp+2Ch] [ebp-1F8h]
  float i; // [esp+30h] [ebp-1F4h]
  float v107; // [esp+34h] [ebp-1F0h]
  int v108; // [esp+38h] [ebp-1ECh]
  float v109; // [esp+3Ch] [ebp-1E8h]
  unsigned int k; // [esp+40h] [ebp-1E4h]
  unsigned int v111; // [esp+44h] [ebp-1E0h]
  RaceManager *v112; // [esp+48h] [ebp-1DCh]
  LeaderboardEntry l; // [esp+4Ch] [ebp-1D8h] BYREF
  __m128i v114; // [esp+6Ch] [ebp-1B8h] BYREF
  __m128i v115; // [esp+7Ch] [ebp-1A8h] BYREF
  _DWORD v116[2]; // [esp+8Ch] [ebp-198h] BYREF
  __int128 v117; // [esp+94h] [ebp-190h] BYREF
  int v118; // [esp+A4h] [ebp-180h]
  char v119; // [esp+A8h] [ebp-17Ch]
  char v120; // [esp+A9h] [ebp-17Bh]
  char v121; // [esp+AAh] [ebp-17Ah]
  RemoteSessionResult results; // [esp+ACh] [ebp-178h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > ws; // [esp+E4h] [ebp-140h] BYREF
  RaceStatusCarDesc c; // [esp+194h] [ebp-90h] BYREF
  unsigned int v125; // [esp+1A8h] [ebp-7Ch]
  RemoteSession result; // [esp+1ACh] [ebp-78h] BYREF
  Lap description; // [esp+1E4h] [ebp-40h] BYREF
  int v128; // [esp+218h] [ebp-Ch]
  int v129; // [esp+220h] [ebp-4h]

  v2 = this;
  v112 = this;
  v3 = 0;
  v111 = 0;
  v4 = this->sim;
  v105 = 0;
  if ( (ReplayManager::isInReplaymode(v4->replayManager) || v2->pauseMode) && !v2->sim->client )
  {
    v2->currentSession.startTime = (float)(deltaT * 1000.0) + v2->currentSession.startTime;
    *(_DWORD *)&v103[4] = &std::_Func_impl<std::_Callable_obj<_lambda_a507984fee0d9ba3947b22da73d6b594_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_DWORD *)&v103[8] = v2;
    *(_DWORD *)&v103[20] = &v103[4];
    v5 = v2->sim;
    v129 = -1;
    PhysicsAvatar::executeOnPhysicsThread(v5->physicsAvatar, *(std::function<void __cdecl(void)> *)&v103[4]);
    return;
  }
  *(double *)&c.car = RaceManager::getTimeToSessionStart(v2);
  if ( *(double *)&c.car < 0.0 )
    RaceManager::resetInvalidStateCarsToPits(v2, deltaT);
  v6 = v2->game;
  v7 = v2->currentSession.durationMinutes * 60.0 * 1000.0;
  v109 = v7;
  v8 = v2->sim->client;
  v107 = v6->gameTime.now - v2->currentSession.startTime;
  if ( v8 )
  {
    v9 = ACClient::getCurrentSession(v8, &result)->type;
    if ( result.name._Myres >= 8 )
      operator delete(result.name._Bx._Ptr);
  }
  else
  {
    v9 = v2->currentSession.sessionType;
  }
  if ( v9 == Race )
  {
    if ( !RaceManager::isRaceOver(v2, 0) )
      RaceManager::updateCarsRealTimePositions(v2, deltaT);
    if ( v2->currentSession.isTimedRace && !v2->timeRaceEnded && v107 > v109 )
    {
      v2->timeRaceEnded = 1;
      v2->currentSession.isOver = 1;
    }
    if ( v2->currentSession.isOver )
    {
      RaceManager::updateCarsEndRace(v2, deltaT);
    }
    else
    {
      v10 = v2->carsRaceStatus._Myfirst;
      v11 = v2->carsRaceStatus._Mylast;
      if ( v10 != v11 )
      {
        do
        {
          if ( !v10->retired && v10->car->physicsState.isRetired )
          {
            *(_DWORD *)ws.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
            *(_DWORD *)ws.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
            std::wios::wios(ws.gap68);
            v129 = 1;
            v3 |= 4u;
            v111 = v3;
            std::wiostream::basic_iostream<wchar_t>(&ws, &ws.gap10[8], 0);
            v128 = 2;
            *(unsigned int *)((char *)&results.hasFinished._Mysize + *(_DWORD *)(results.hasFinished._Mysize + 4)) = (unsigned int)&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
            *(unsigned int **)((char *)&results.hasFinished._Myvec._Myend + *(_DWORD *)(results.hasFinished._Mysize + 4)) = (unsigned int *)(*(_DWORD *)(results.hasFinished._Mysize + 4) - 104);
            std::wstreambuf::wstreambuf(ws.gap10);
            *(_DWORD *)ws.gap10 = &std::wstringbuf::`vftable';
            *(_DWORD *)&ws.gap10[56] = 0;
            *(_DWORD *)&ws.gap10[60] = 0;
            v12 = v10->car;
            v128 = 4;
            *(_DWORD *)&v103[12] = " : ";
            *(_DWORD *)&v103[8] = CarAvatar::getGuid(v12);
            v13 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&ws._Chcount, "Driver ");
            v14 = (std::wostream *)std::wostream::operator<<(v13, *(_DWORD *)&v103[8]);
            v15 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v14, *(const char **)&v103[20]);
            std::operator<<<wchar_t>(v15, *(const std::wstring **)&v103[24]);
            std::wstring::wstring((std::wstring *)&description, L"Retired");
            LOBYTE(v129) = 5;
            v16 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                    &ws,
                    (std::wstring *)&c);
            LOBYTE(v129) = 6;
            SystemMessage::addMessage(v2->sim->systemMessage, v16, (const std::wstring *)&description, eDefault);
            if ( v125 >= 8 )
              operator delete(c.car);
            v125 = 7;
            c.maxInvalidStateTimer = 0.0;
            LOWORD(c.car) = 0;
            if ( *(_DWORD *)&description.isValid >= 8u )
              operator delete(description.time);
            v10->retired = 1;
            v129 = -1;
            std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&ws);
          }
          ++v10;
        }
        while ( v10 != v11 );
        v105 = v3;
      }
    }
  }
  if ( v2->currentSession.startTime != 0.0
    && v2->currentSession.durationMinutes > 0.0
    && v107 > v109
    && v2->currentSession.overtime_ms == -1.0 )
  {
    v17 = v2->carsRaceStatus._Myfirst;
    v18 = 0.0;
    v19 = v2->carsRaceStatus._Mylast;
    for ( i = 0.0; v17 != v19; ++v17 )
    {
      v20 = _mm_loadu_si128((const __m128i *)v17);
      c.maxInvalidStateTimer = v17->maxInvalidStateTimer;
      *(__m128i *)&c.car = v20;
      v21 = (CarAvatar *)v20.m128i_i32[0];
      if ( v18 == 0.0 )
      {
        i = (float)RaceManager::getBestLap(v2, &description, (CarAvatar *)v20.m128i_i32[0])->time;
        Lap::~Lap(&description);
      }
      v22 = RaceManager::getBestLap(v2, (Lap *)&result, (CarAvatar *)v20.m128i_i32[0]);
      v23 = v105 | 1;
      v129 = 7;
      v24 = v22->time == 0;
      v105 = v23;
      v111 = v23;
      if ( v24
        || (v25 = RaceManager::getBestLap(v2, &description, (CarAvatar *)v20.m128i_i32[0]),
            v23 = v105 | 2,
            v105 |= 2u,
            v26 = v25->time,
            HIBYTE(v104) = 1,
            v27 = (float)v26,
            i <= v27) )
      {
        HIBYTE(v104) = 0;
      }
      if ( (v23 & 2) != 0 )
      {
        v105 = v23 & 0xFFFFFFFD;
        Lap::~Lap(&description);
        v23 = v105;
      }
      v129 = -1;
      if ( (v23 & 1) != 0 )
      {
        v105 = v23 & 0xFFFFFFFE;
        Lap::~Lap((Lap *)&result);
      }
      if ( HIBYTE(v104) )
      {
        i = (float)RaceManager::getBestLap(v2, (Lap *)&result, v21)->time;
        Lap::~Lap((Lap *)&result);
      }
      v18 = i;
    }
    v28 = v2->overTimeMult * v18;
    if ( v28 < 10000.0 )
      v28 = FLOAT_10000_0;
    v24 = v2->currentSession.sessionType == Qualify;
    v2->currentSession.overtime_ms = v28;
    if ( !v24 )
      v2->currentSession.overtime_ms = 0.0;
  }
  v24 = v2->currentSession.sessionType == Qualify;
  v29 = 1;
  HIBYTE(v104) = 1;
  if ( v24 && v2->currentSession.overtime_ms >= 0.0 )
  {
    if ( !v2->sim->client )
    {
      v30 = v2->carsRaceStatus._Mylast;
      for ( j = &v2->carsRaceStatus._Myfirst->car; j != (CarAvatar **)v30; j += 5 )
      {
        if ( CarAvatar::isInPit(*j) )
        {
          v32 = v2->raceTimingServices;
          v33 = *j;
          if ( v32 )
            RaceTimingServices::setHasCompletedFlag(v32, v33, 1);
          if ( v2->sim->client )
          {
            v34 = CarAvatar::getGuid(v33);
            v2->multiplayerStatus.completedFlags._Myvec._Myfirst[v34 >> 5] |= 1 << (v34 & 0x1F);
            v2 = v112;
          }
        }
        if ( HIBYTE(v104) )
          HIBYTE(v104) &= -RaceManager::getHasCompletedFlag(v2, *j);
      }
      v35 = &v2->carsRaceStatus._Myfirst->car;
      v36 = v2->raceTimingServices;
      if ( v36 )
      {
        v37 = RaceTimingServices::getHasCompletedFlag(v36, *v35);
LABEL_67:
        if ( v37 && !CarAvatar::isInPit(v2->carsRaceStatus._Myfirst->car) )
        {
          v39 = v2->sim->cameraManager;
          if ( v39 )
          {
            if ( (((char *)v39->evOnFadeInFinished.handlers._Mylast - (char *)v39->evOnFadeInFinished.handlers._Myfirst) & 0xFFFFFFE0) == 0 )
            {
              *(_DWORD *)&v103[24] = v2;
              *(_DWORD *)v103 = &std::_Func_impl<std::_Callable_obj<_lambda_4d6bd21bdb55aea7c890483ecf567272_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
              *(_DWORD *)&v103[4] = v2;
              *(_DWORD *)&v103[16] = v103;
              v40 = v2->sim;
              v129 = -1;
              ACCameraManager::registerToFadeInEvent(
                v40->cameraManager,
                *(std::function<void __cdecl(bool const &)> *)v103,
                v2);
              v41 = v2->sim;
              c.car = 0;
              LODWORD(c.invalidStateTimer) = v2;
              *(_DWORD *)&c.retired = 1075838976;
              v42 = v41->cameraManager;
              c.resetTimer = 0.0;
              ACCameraManager::fadeIn(v42, (FadeModeDef)_mm_loadu_si128((const __m128i *)&c));
            }
          }
        }
        goto LABEL_72;
      }
      if ( v2->sim->client )
      {
        v38 = CarAvatar::getGuid(*v35);
        v37 = ((1 << (v38 & 0x1F)) & v2->multiplayerStatus.completedFlags._Myvec._Myfirst[v38 >> 5]) != 0;
        goto LABEL_67;
      }
    }
LABEL_72:
    v29 = HIBYTE(v104);
  }
  v43 = v2->currentSession.overtime_ms;
  if ( v43 != -1.0 && ((float)(v107 - v109) > v43 || v29) )
  {
    v44 = (char *)v2->sessions._Mylast - (char *)v2->sessions._Myfirst;
    if ( v2->currentSessionIndex < (signed int)(((int)((unsigned __int64)(715827883i64 * v44) >> 32) >> 4)
                                              + ((unsigned int)((unsigned __int64)(715827883i64 * v44) >> 32) >> 31)
                                              - 1) )
    {
      v45 = v2->sim->cameraManager;
      if ( v45 )
      {
        if ( (((char *)v45->evOnFadeInFinished.handlers._Mylast - (char *)v45->evOnFadeInFinished.handlers._Myfirst) & 0xFFFFFFE0) == 0 )
        {
          *(_DWORD *)&v103[24] = v2;
          *(_DWORD *)v103 = &std::_Func_impl<std::_Callable_obj<_lambda_e66b8fb25d8cccd64d42f98c9162898c_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
          *(_DWORD *)&v103[4] = v2;
          *(_DWORD *)&v103[16] = v103;
          v46 = v2->sim;
          v129 = -1;
          ACCameraManager::registerToFadeInEvent(
            v46->cameraManager,
            *(std::function<void __cdecl(bool const &)> *)v103,
            v2);
          v47 = v2->sim;
          c.car = 0;
          LODWORD(c.invalidStateTimer) = v2;
          *(_DWORD *)&c.retired = 1075838976;
          v48 = v47->cameraManager;
          c.resetTimer = 0.0;
          ACCameraManager::fadeIn(v48, (FadeModeDef)_mm_loadu_si128((const __m128i *)&c));
        }
      }
    }
  }
  v49 = v2->sim->client;
  if ( v49 )
  {
    v50 = ACClient::getCurrentSessionResults(v49);
    std::vector<Mesh *>::vector<Mesh *>(
      (std::vector<TyreThermalPatch *> *)&results,
      (const std::vector<TyreThermalPatch *> *)v50);
    v129 = 10;
    std::vector<Mesh *>::vector<Mesh *>(
      (std::vector<TyreThermalPatch *> *)&results.times,
      (const std::vector<TyreThermalPatch *> *)&v50->times);
    LOBYTE(v129) = 11;
    std::vector<Mesh *>::vector<Mesh *>(
      (std::vector<TyreThermalPatch *> *)&results.lapCounter,
      (const std::vector<TyreThermalPatch *> *)&v50->lapCounter);
    LOBYTE(v129) = 12;
    std::vector<unsigned int>::vector<unsigned int>(&results.hasFinished._Myvec, &v50->hasFinished._Myvec);
    results.hasFinished._Mysize = v50->hasFinished._Mysize;
    results.leaderLapCount = v50->leaderLapCount;
    v51 = (std::vector<ClientCollisionEvent> *)&v2->mpCacheLeaderboard;
    v129 = 13;
    std::_Container_base0::_Orphan_all(&v2->mpCacheLeaderboard);
    v2->mpCacheLeaderboard._Mylast = v2->mpCacheLeaderboard._Myfirst;
    v52 = ACClient::getCurrentSession(v2->sim->client, &result)->type == Race;
    HIBYTE(v104) = v52;
    if ( result.name._Myres >= 8 )
    {
      operator delete(result.name._Bx._Ptr);
      v52 = HIBYTE(v104);
    }
    if ( v52 )
    {
      *(double *)&c.car = v2->sim->game->gameTime.now - ACClient::getCurrentSession(v2->sim->client, &result)->startTime;
      if ( result.name._Myres >= 8 )
        operator delete(result.name._Bx._Ptr);
      v53 = v2->sim;
      v54 = v53->client;
      if ( v54 && LOWORD(v54->pitWindowEnd) && v2->pitWindowEndTime == 0.0 )
      {
        v55 = ACClient::getCurrentSession(v53->client, &result)->isTimedRace;
        HIBYTE(v108) = v55;
        if ( result.name._Myres >= 8 )
        {
          operator delete(result.name._Bx._Ptr);
          v55 = HIBYTE(v108);
        }
        if ( v55 )
        {
          if ( v2->pitWindowStartTime == 0.0 )
          {
            v56 = RaceManager::getPitWindowStart(v2);
            v57 = *(double *)&c.car;
            if ( *(double *)&c.car >= (double)(60000 * v56) )
              v2->pitWindowStartTime = *(double *)&c.car;
          }
          else
          {
            v57 = *(double *)&c.car;
          }
          v53 = v2->sim;
          v58 = v53->client;
          if ( v58 )
            v59 = v58->pitWindowEnd;
          else
            v59 = 0;
          if ( v57 >= (double)(60000 * v59) )
            v2->pitWindowEndTime = v57;
        }
        else
        {
          v60 = RaceManager::getLeaderLapCount(v2);
          if ( v2->pitWindowStartTime == 0.0 )
          {
            v61 = RaceManager::getPitWindowStart(v2);
            v57 = *(double *)&c.car;
            if ( v60 >= v61 )
              v2->pitWindowStartTime = *(double *)&c.car;
          }
          else
          {
            v57 = *(double *)&c.car;
          }
          v53 = v2->sim;
          v62 = v53->client;
          if ( v62 )
            v63 = v62->pitWindowEnd;
          else
            v63 = 0;
          if ( v60 >= (unsigned int)v63 - 1 )
            v2->pitWindowEndTime = v57;
        }
      }
      else
      {
        v57 = *(double *)&c.car;
      }
      if ( v57 > 0.0 && v2->pitWindowEndTime > 0.0 && !Sim::getCar(v53, 0)->mandatoryPitstopDone )
      {
        v64 = Sim::getCar(v2->sim, 0);
        if ( !CarAvatar::isInPitlane(v64) )
        {
          _printf("Blackflagged due to Manadatory Pit rule\n");
          v65 = v2->sim;
          *(_DWORD *)&v103[24] = 3;
          v66 = Sim::getCar(v65, 0);
          CarAvatar::setBlackFlag(v66, *(PenaltyDescription *)&v103[24]);
          v67 = Sim::getCar(v2->sim, 0);
          RaceEngineer::getCar(v67->raceEngineer._Myptr)->isRetired = 1;
        }
      }
    }
    v68 = 0;
    v69 = results.positions._Myfirst;
    for ( k = 0; v68 < results.positions._Mylast - results.positions._Myfirst; k = v68 )
    {
      v70 = v69[v68];
      v71 = v2->sim;
      v105 = v70;
      v72 = Sim::getCar(v71, v70);
      v73 = results.hasFinished._Myvec._Myfirst;
      LODWORD(v109) = 4 * (v70 >> 5);
      c.car = v72;
      v74 = CarAvatar::getGuid(v72);
      i = *(float *)&v2->multiplayerStatus.completedFlags._Myvec._Myfirst;
      v75 = v74 >> 5;
      v111 = v74 & 0x1F;
      LODWORD(v107) = 1 << (v70 & 0x1F);
      if ( (LODWORD(v107) & *(unsigned int *)((char *)v73 + LODWORD(v109))) != 0 )
        *(_DWORD *)(LODWORD(i) + 4 * v75) |= 1 << v111;
      else
        *(_DWORD *)(LODWORD(i) + 4 * v75) &= ~(1 << v111);
      if ( !c.car )
        goto LABEL_144;
      if ( HIBYTE(v104) )
      {
        l.isRaceMode = HIBYTE(v104);
        l.car = c.car;
        v76 = (double)results.times._Myfirst[v105];
        l.laps = results.lapCounter._Myfirst[v105];
        l.isBlackFlagged = c.car->isBlackFlagged;
        l.totalTime = v76;
        l.bestLap = DOUBLE_N1_0;
        v77 = v2->mpCacheLeaderboard._Mylast;
        l.hasCompletedLastLap = (LODWORD(v107) & *(unsigned int *)((_BYTE *)results.hasFinished._Myvec._Myfirst
                                                                 + LODWORD(v109))) != 0;
        if ( &l >= v77 || v51->_Myfirst > (ClientCollisionEvent *)&l )
        {
          if ( v77 == v2->mpCacheLeaderboard._Myend )
            std::vector<ClientCollisionEvent>::_Reserve(
              (std::vector<ClientCollisionEvent> *)&v2->mpCacheLeaderboard,
              1u);
          v79 = (__m128i *)v2->mpCacheLeaderboard._Mylast;
          if ( !v79 )
            goto LABEL_143;
          *v79 = _mm_loadu_si128((const __m128i *)&l);
          v81 = _mm_loadu_si128((const __m128i *)&l.bestLap);
          goto LABEL_142;
        }
        v78 = (char *)&l - (char *)v51->_Myfirst;
        if ( v77 == v2->mpCacheLeaderboard._Myend )
          std::vector<ClientCollisionEvent>::_Reserve((std::vector<ClientCollisionEvent> *)&v2->mpCacheLeaderboard, 1u);
        v79 = (__m128i *)v2->mpCacheLeaderboard._Mylast;
        v80 = (const __m128i *)((char *)v51->_Myfirst + (v78 & 0xFFFFFFE0));
        if ( !v79 )
          goto LABEL_143;
      }
      else
      {
        *(double *)&v114.m128i_i64[1] = DOUBLE_N1_0;
        v114.m128i_i32[0] = (int)c.car;
        v82 = (double)results.times._Myfirst[v105];
        v115.m128i_i8[12] = 0;
        v115.m128i_i32[2] = results.lapCounter._Myfirst[v105];
        v115.m128i_i8[13] = c.car->isBlackFlagged;
        *(double *)v115.m128i_i64 = v82;
        v83 = v2->mpCacheLeaderboard._Mylast;
        v115.m128i_i8[14] = (LODWORD(v107) & *(unsigned int *)((_BYTE *)results.hasFinished._Myvec._Myfirst
                                                             + LODWORD(v109))) != 0;
        if ( &v114 >= (__m128i *)v83 || v51->_Myfirst > (ClientCollisionEvent *)&v114 )
        {
          if ( v83 == v2->mpCacheLeaderboard._Myend )
            std::vector<ClientCollisionEvent>::_Reserve(
              (std::vector<ClientCollisionEvent> *)&v2->mpCacheLeaderboard,
              1u);
          v79 = (__m128i *)v2->mpCacheLeaderboard._Mylast;
          if ( !v79 )
            goto LABEL_143;
          *v79 = _mm_loadu_si128(&v114);
          v81 = _mm_loadu_si128(&v115);
          goto LABEL_142;
        }
        v84 = (char *)&v114 - (char *)v51->_Myfirst;
        if ( v83 == v2->mpCacheLeaderboard._Myend )
          std::vector<ClientCollisionEvent>::_Reserve((std::vector<ClientCollisionEvent> *)&v2->mpCacheLeaderboard, 1u);
        v79 = (__m128i *)v2->mpCacheLeaderboard._Mylast;
        v80 = (const __m128i *)((char *)v51->_Myfirst + (v84 & 0xFFFFFFE0));
        if ( !v79 )
          goto LABEL_143;
      }
      *v79 = _mm_loadu_si128(v80);
      v81 = _mm_loadu_si128(v80 + 1);
LABEL_142:
      v79[1] = v81;
LABEL_143:
      ++v2->mpCacheLeaderboard._Mylast;
LABEL_144:
      v69 = results.positions._Myfirst;
      v68 = k + 1;
    }
    if ( v2->mpCacheLeaderboard._Myfirst == v2->mpCacheLeaderboard._Mylast )
    {
      v85 = v2->sim;
      v86 = 0;
      k = 0;
      if ( v85->cars._Mylast - v85->cars._Myfirst )
      {
        do
        {
          v87 = Sim::getCar(v2->sim, v86);
          *(_DWORD *)&v103[24] = v86;
          v88 = v87->isBlackFlagged;
          v89 = Sim::getCar(v112->sim, v86);
          v90 = v51->_Mylast;
          v116[0] = v89;
          v119 = HIBYTE(v104);
          v118 = 0;
          v120 = v88;
          v121 = 0;
          v117 = _xmm;
          if ( v116 >= (_DWORD *)v90 || (v91 = v51->_Myfirst, v51->_Myfirst > (ClientCollisionEvent *)v116) )
          {
            v98 = v51->_Myend;
            if ( v90 == v98 && !(v98 - v90) )
            {
              v99 = v90 - v51->_Myfirst;
              if ( v99 == 0x7FFFFFF )
LABEL_175:
                std::_Xlength_error("vector<T> too long");
              v100 = v98 - v51->_Myfirst;
              if ( 0x7FFFFFF - (v100 >> 1) >= v100 )
                v101 = (v100 >> 1) + v100;
              else
                v101 = 0;
              if ( v101 < v99 + 1 )
                v101 = v99 + 1;
              std::vector<ClientCollisionEvent>::_Reallocate(v51, v101);
            }
            v102 = (__m128i *)v51->_Mylast;
            if ( v102 )
            {
              *v102 = _mm_loadu_si128((const __m128i *)v116);
              v102[1] = _mm_loadu_si128((const __m128i *)((char *)&v117 + 8));
            }
          }
          else
          {
            v92 = v51->_Myend;
            if ( v90 == v92 && !(v92 - v90) )
            {
              v93 = v90 - v91;
              if ( v93 == 0x7FFFFFF )
                goto LABEL_175;
              v94 = v92 - v91;
              if ( 0x7FFFFFF - (v94 >> 1) >= v94 )
                v95 = (v94 >> 1) + v94;
              else
                v95 = 0;
              if ( v95 < v93 + 1 )
                v95 = v93 + 1;
              std::vector<ClientCollisionEvent>::_Reallocate(v51, v95);
            }
            v96 = (__m128i *)v51->_Mylast;
            v97 = (const __m128i *)((char *)v51->_Myfirst + (((char *)v116 - (char *)v91) & 0xFFFFFFE0));
            if ( v96 )
            {
              *v96 = _mm_loadu_si128(v97);
              v96[1] = _mm_loadu_si128(v97 + 1);
            }
            v86 = k;
          }
          v2 = v112;
          ++v86;
          ++v51->_Mylast;
          k = v86;
        }
        while ( v86 < v2->sim->cars._Mylast - v2->sim->cars._Myfirst );
      }
    }
    RemoteSessionResult::~RemoteSessionResult(&results);
  }
}
void RaceManager::updateCarsEndRace(RaceManager *this, float dt)
{
  RaceStatusCarDesc *v3; // esi
  RaceStatusCarDesc *v4; // edi
  unsigned int v5; // eax
  unsigned int v6; // eax
  CarAvatar *v7; // eax
  float v8; // xmm0_4
  ACCameraManager *v9; // ecx
  Sim *v10; // ecx
  Sim *v11; // ecx
  ACCameraManager *v12; // ecx
  char v13; // al
  Sim *v14; // ecx
  EndSessionDisplayer *v15; // eax
  Sim *v16; // ecx
  Sim *v17; // ecx
  ACCameraManager *v18; // ecx
  std::function<void __cdecl(bool const &)> v19; // [esp-1Ch] [ebp-58h] BYREF
  RaceManager *v20; // [esp-4h] [ebp-40h]
  char v21; // [esp+1Bh] [ebp-21h]
  __m128i v22; // [esp+20h] [ebp-1Ch] BYREF
  int v23; // [esp+38h] [ebp-4h]

  v3 = this->carsRaceStatus._Myfirst;
  v4 = this->carsRaceStatus._Mylast;
  v21 = 1;
  if ( v3 == v4 )
    goto LABEL_12;
  do
  {
    v5 = CarAvatar::getGuid(v3->car);
    if ( RaceManager::isRaceOver(this, v5) )
    {
      v6 = CarAvatar::getGuid(v3->car);
      v7 = Sim::getCar(this->sim, v6);
      if ( !CarAvatar::isInPit(v7) )
      {
        v8 = v3->resetTimer - dt;
        v3->resetTimer = v8;
        if ( v8 < 0.0 && !CarAvatar::getGuid(v3->car) )
        {
          v9 = this->sim->cameraManager;
          if ( v9 )
          {
            if ( (((char *)v9->evOnFadeInFinished.handlers._Mylast - (char *)v9->evOnFadeInFinished.handlers._Myfirst) & 0xFFFFFFE0) == 0 )
            {
              v20 = this;
              v19._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_14bcb8e7bd7af2afe68e06f5a26767e9_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
              v19._Space._Pfn[1] = (void (__cdecl *)())v3;
              v19._Impl = (std::_Func_base<void,bool const &> *)&v19;
              v10 = this->sim;
              v23 = -1;
              ACCameraManager::registerToFadeInEvent(v10->cameraManager, v19, this);
              v11 = this->sim;
              v22.m128i_i32[0] = 0;
              v22.m128i_i32[3] = (int)this;
              v12 = v11->cameraManager;
              *(__int64 *)((char *)v22.m128i_i64 + 4) = 0x4020000000000000i64;
              ACCameraManager::fadeIn(v12, (FadeModeDef)_mm_loadu_si128(&v22));
            }
          }
        }
      }
      v13 = v21;
    }
    else
    {
      v13 = 0;
      v21 = 0;
    }
    ++v3;
  }
  while ( v3 != v4 );
  if ( v13 )
  {
LABEL_12:
    v14 = this->sim;
    v15 = v14->endSessionDisplayer;
    if ( (!v15 || !v15->isActive)
      && (((char *)v14->cameraManager->evOnFadeInFinished.handlers._Mylast
         - (char *)v14->cameraManager->evOnFadeInFinished.handlers._Myfirst) & 0xFFFFFFE0) == 0 )
    {
      v20 = this;
      v19._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_03d4a4e38214184ac663a9958eafa959_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
      v19._Space._Pfn[1] = (void (__cdecl *)())this;
      v19._Impl = (std::_Func_base<void,bool const &> *)&v19;
      v16 = this->sim;
      v23 = -1;
      ACCameraManager::registerToFadeInEvent(v16->cameraManager, v19, this);
      v17 = this->sim;
      v22.m128i_i32[0] = 0;
      v22.m128i_i32[3] = (int)this;
      v18 = v17->cameraManager;
      *(__int64 *)((char *)v22.m128i_i64 + 4) = 0x4020000000000000i64;
      ACCameraManager::fadeIn(v18, (FadeModeDef)_mm_loadu_si128(&v22));
    }
  }
}
void RaceManager::updateCarsRealTimePositions(RaceManager *this, float dt)
{
  RealTimeCarDesc *v3; // edi
  RealTimeCarDesc *v4; // esi
  float v5; // xmm0_4
  ACClient *v6; // ecx
  double v7; // xmm0_8
  bool v8; // cc
  unsigned int v9; // edi
  int v10; // esi
  RealTimeCarDesc *v11; // ecx
  unsigned int v12; // eax
  __m128i v13; // xmm0
  double v14; // [esp+10h] [ebp-48h]
  RemoteSession result; // [esp+18h] [ebp-40h] BYREF

  v3 = this->carsRealTimePosition._Mylast;
  v4 = this->carsRealTimePosition._Myfirst;
  if ( v4 != v3 )
  {
    v5 = FLOAT_0_5;
    do
    {
      if ( v5 > v4->car->physicsState.normalizedSplinePosition )
      {
        v6 = this->sim->client;
        if ( v6 )
        {
          v7 = ACClient::getCurrentSession(v6, &result)->startTime - this->game->gameTime.now;
          v14 = v7;
          if ( result.name._Myres >= 8 )
            operator delete(result.name._Bx._Ptr);
        }
        else
        {
          v7 = this->currentSession.startTime - this->game->gameTime.now;
        }
        v8 = v7 >= 0.0;
        v5 = FLOAT_0_5;
        if ( !v8 )
          v4->crossedForTheFirstTime = 1;
      }
      ++v4;
    }
    while ( v4 != v3 );
  }
  std::_Sort<RealTimeCarDesc *,int,_lambda_59c3976748667e1e7edd4d54891c675d_>(
    this->carsRealTimePosition._Myfirst,
    this->carsRealTimePosition._Mylast,
    this->carsRealTimePosition._Mylast - this->carsRealTimePosition._Myfirst,
    (RaceManager::updateCarsRealTimePositions::__l34::<lambda_59c3976748667e1e7edd4d54891c675d>)this);
  v9 = 0;
  if ( this->carsRealTimePosition._Mylast - this->carsRealTimePosition._Myfirst )
  {
    v10 = 0;
    do
    {
      v11 = this->carsRealTimePosition._Myfirst;
      if ( v11[v10].approxPos == -1.0 )
        v11[v10].approxPos = (float)v9;
      v12 = v9;
      v13 = _mm_cvtsi32_si128(v9++);
      this->carsRealTimePosition._Myfirst[v10].approxPos = (float)((float)((float)(_mm_cvtepi32_pd(v13).m128d_f64[0]
                                                                                 + _xmm[v12 >> 31])
                                                                         - this->carsRealTimePosition._Myfirst[v10].approxPos)
                                                                 * dt)
                                                         + this->carsRealTimePosition._Myfirst[v10].approxPos;
      ++v10;
    }
    while ( v9 < this->carsRealTimePosition._Mylast - this->carsRealTimePosition._Myfirst );
  }
  std::_Sort<RealTimeCarDesc *,int,_lambda_43f065e4bf3ce08fa9c962bd292d54b7_>(
    this->carsRealTimePosition._Myfirst,
    this->carsRealTimePosition._Mylast,
    this->carsRealTimePosition._Mylast - this->carsRealTimePosition._Myfirst,
    LOBYTE(v14));
}
bool RaceManager::isOfficialSpecialEvent(RaceManager *this)
{
  return this->officialSpecialEvent;
}
