#include "sharedmemorywriter.h"
void __userpurge SharedMemoryWriter::SharedMemoryWriter(SharedMemoryWriter *this@<ecx>, unsigned int a2@<ebx>, Sim *aSim)
{
  Sim *v4; // eax
  Event<SessionInfo> *v5; // ecx
  bool v6; // bl
  std::wstring *v7; // eax
  bool v8; // bl
  _BYTE v9[56]; // [esp-1Ch] [ebp-DCh] BYREF
  int v10; // [esp+1Ch] [ebp-A4h]
  SharedMemoryWriter *v11; // [esp+20h] [ebp-A0h]
  std::wstring section; // [esp+24h] [ebp-9Ch] BYREF
  std::wstring key; // [esp+3Ch] [ebp-84h] BYREF
  std::wstring result; // [esp+54h] [ebp-6Ch] BYREF
  INIReaderDocuments iniDoc; // [esp+6Ch] [ebp-54h] BYREF
  int v16; // [esp+BCh] [ebp-4h]

  v10 = 0;
  v11 = this;
  *(_DWORD *)&v9[24] = aSim->game;
  *(_DWORD *)&v9[20] = 7;
  *(_DWORD *)&v9[16] = 0;
  *(_WORD *)v9 = 0;
  std::wstring::assign((std::wstring *)v9, L"SharedMemoryWriter", 0x12u);
  GameObject::GameObject(this, *(std::wstring *)v9, *(Game **)&v9[24]);
  this->__vftable = (SharedMemoryWriter_vtbl *)&SharedMemoryWriter::`vftable';
  this->sim = aSim;
  this->car = 0;
  this->avatar = 0;
  this->lapInvalidator = 0;
  this->flagManager = 0;
  v16 = 0;
  this->sharedMemories[0].packetId = 0;
  this->sharedMemories[0].nullCounts = 0;
  this->sharedMemories[1].packetId = 0;
  this->sharedMemories[1].nullCounts = 0;
  this->sharedMemories[2].packetId = 0;
  this->sharedMemories[2].nullCounts = 0;
  CarPhysicsInfo::CarPhysicsInfo(&this->physicsInfo);
  this->lastPosition.x = 0.0;
  this->lastPosition.y = 0.0;
  this->lastPosition.z = 0.0;
  this->staticWrote = 0;
  this->currentDistance = 0.0;
  this->hotlapMode = 0;
  *(_DWORD *)&v9[24] = 7;
  *(_DWORD *)&v9[20] = 0;
  LOBYTE(v16) = 1;
  *(_WORD *)&v9[4] = 0;
  std::wstring::assign((std::wstring *)&v9[4], L"acpmf_static", 0xCu);
  if ( !SharedMemoryWriter::initSharedMemory(this, 0, *(std::wstring *)&v9[4]) )
    goto LABEL_4;
  *(_DWORD *)&v9[24] = 7;
  *(_DWORD *)&v9[20] = 0;
  *(_WORD *)&v9[4] = 0;
  std::wstring::assign((std::wstring *)&v9[4], L"acpmf_graphics", 0xEu);
  if ( !SharedMemoryWriter::initSharedMemory(this, 1u, *(std::wstring *)&v9[4])
    || (*(_DWORD *)&v9[24] = 7,
        *(_DWORD *)&v9[20] = 0,
        *(_WORD *)&v9[4] = 0,
        std::wstring::assign((std::wstring *)&v9[4], L"acpmf_physics", 0xDu),
        !SharedMemoryWriter::initSharedMemory(this, 2u, *(std::wstring *)&v9[4])) )
  {
LABEL_4:
    _printf("ERROR: SharedMemoryWriter :: ERROR initializing shared memory\n");
  }
  *(_DWORD *)&v9[24] = this;
  *(_DWORD *)v9 = &std::_Func_impl<std::_Callable_obj<_lambda_b66af63a2cd2d5a863a3454a72924bb0_,0>,std::allocator<std::_Func_class<void,OnPhysicsStepCompleted const &>>,void,OnPhysicsStepCompleted const &>::`vftable';
  *(_DWORD *)&v9[4] = this;
  *(_DWORD *)&v9[16] = v9;
  v4 = this->sim;
  LOBYTE(v16) = 1;
  Event<std::wstring>::addHandler(
    &v4->physicsAvatar->evOnStepCompleted,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)v9,
    this);
  *(_DWORD *)&v9[24] = this;
  *(_DWORD *)v9 = &std::_Func_impl<std::_Callable_obj<_lambda_d2fc0c42a80ea3e59c28bb6b7036a081_,0>,std::allocator<std::_Func_class<void,OnNewCarLoadedEvent const &>>,void,OnNewCarLoadedEvent const &>::`vftable';
  *(_DWORD *)&v9[4] = this;
  *(_DWORD *)&v9[16] = v9;
  v5 = (Event<SessionInfo> *)&this->sim->evNewCarLoaded;
  LOBYTE(v16) = 1;
  Event<float>::addHandler(v5, *(std::function<void __cdecl(SessionInfo const &)> *)v9, this);
  *(_DWORD *)&v9[24] = 0;
  *(_DWORD *)&v9[20] = 7;
  *(_DWORD *)&v9[16] = 0;
  *(_WORD *)v9 = 0;
  std::wstring::assign((std::wstring *)v9, L"cfg/race.ini", 0xCu);
  INIReaderDocuments::INIReaderDocuments(&iniDoc, a2, *(std::wstring *)v9, v9[24]);
  LOBYTE(v16) = 4;
  v6 = 0;
  if ( iniDoc.ready )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SESSION_0", 9u);
    LOBYTE(v16) = 5;
    v10 = 1;
    if ( INIReader::hasSection(&iniDoc, &section) )
      v6 = 1;
  }
  v16 = 4;
  if ( (v10 & 1) != 0 && section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( v6 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SPAWN_SET", 9u);
    LOBYTE(v16) = 6;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SESSION_0", 9u);
    LOBYTE(v16) = 7;
    v7 = INIReader::getString(&iniDoc, &result, &section, &key);
    *(_DWORD *)&v9[24] = 12;
    *(_DWORD *)&v9[20] = L"HOTLAP_START";
    *(_DWORD *)&v9[16] = v7->_Mysize;
    LOBYTE(v16) = 8;
    v8 = std::wstring::compare(v7, 0, *(unsigned int *)&v9[16], L"HOTLAP_START", 0xCu) == 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v8 )
      this->hotlapMode = 1;
  }
  LOBYTE(v16) = 1;
  INIReaderDocuments::~INIReaderDocuments(&iniDoc);
}
SharedMemoryWriter *SharedMemoryWriter::`vector deleting destructor'(SharedMemoryWriter *this, unsigned int a2)
{
  this->__vftable = (SharedMemoryWriter_vtbl *)&SharedMemoryWriter::`vftable';
  if ( UnmapViewOfFile(this->sharedMemories[1].mapFileBuffer) )
    CloseHandle(this->sharedMemories[1].hMapFile);
  if ( UnmapViewOfFile(this->sharedMemories[0].mapFileBuffer) )
    CloseHandle(this->sharedMemories[0].hMapFile);
  if ( UnmapViewOfFile(this->sharedMemories[2].mapFileBuffer) )
    CloseHandle(this->sharedMemories[2].hMapFile);
  CarPhysicsInfo::~CarPhysicsInfo(&this->physicsInfo);
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
char SharedMemoryWriter::initSharedMemory(SharedMemoryWriter *this, unsigned int memoryIndex, std::wstring memoryName)
{
  _WORD *v4; // edi
  std::wstring *v5; // ecx
  char *v6; // eax
  std::wstring *v7; // ecx
  HANDLE v8; // eax
  unsigned int v9; // ebx
  HWND v10; // eax
  char v11; // bl
  unsigned __int8 *v12; // eax
  bool v13; // zf
  HWND v14; // eax
  std::wstring fullName; // [esp+10h] [ebp-28h] BYREF
  int v17; // [esp+34h] [ebp-4h]

  v17 = 0;
  std::operator+<wchar_t>(&fullName, L"Local\\", &memoryName);
  LOBYTE(v17) = 1;
  v4 = (_WORD *)operator new[](2 * (fullName._Mysize + 1));
  v4[fullName._Mysize] = 0;
  v5 = &fullName;
  if ( fullName._Myres >= 8 )
    v5 = (std::wstring *)fullName._Bx._Ptr;
  v6 = &v5->_Bx._Alias[2 * fullName._Mysize];
  v7 = &fullName;
  if ( fullName._Myres >= 8 )
    v7 = (std::wstring *)fullName._Bx._Ptr;
  _memmove(v4, v7, (v6 - (char *)v7) & 0xFFFFFFFE);
  v8 = CreateFileMappingW((HANDLE)0xFFFFFFFF, 0, 4u, 0, 0x250u, v4);
  v9 = memoryIndex;
  this->sharedMemories[memoryIndex].hMapFile = v8;
  if ( v8 )
  {
    v12 = (unsigned __int8 *)MapViewOfFile(v8, 0xF001Fu, 0, 0, 0x250u);
    v13 = this->sharedMemories[v9].hMapFile == 0;
    this->sharedMemories[v9].mapFileBuffer = v12;
    if ( v13 )
    {
      v14 = GetActiveWindow();
      MessageBoxA(v14, "MapViewOfFile failed", "AssettoCorsa", 0);
      v11 = 0;
    }
    else
    {
      v11 = 1;
    }
  }
  else
  {
    v10 = GetActiveWindow();
    MessageBoxA(v10, "CreateFileMapping failed", "AssettoCorsa", 0);
    v11 = 0;
  }
  if ( fullName._Myres >= 8 )
    operator delete(fullName._Bx._Ptr);
  fullName._Myres = 7;
  fullName._Mysize = 0;
  fullName._Bx._Buf[0] = 0;
  if ( memoryName._Myres >= 8 )
    operator delete(memoryName._Bx._Ptr);
  return v11;
}
void SharedMemoryWriter::shutdown(SharedMemoryWriter *this)
{
  int v2; // eax
  unsigned __int8 *v3; // edi
  SPageFileGraphic v4; // [esp+8h] [ebp-130h] BYREF

  SPageFileGraphic::SPageFileGraphic(&v4);
  v2 = this->sharedMemories[1].packetId;
  v3 = this->sharedMemories[1].mapFileBuffer;
  v4.packetId = v2;
  v4.status = 0;
  qmemcpy(v3, &v4, 0x130u);
}
void SharedMemoryWriter::update(SharedMemoryWriter *this, float dt)
{
  CarAvatar *v3; // eax
  unsigned __int64 v4; // xmm2_8
  unsigned int *v5; // eax
  Sim *v6; // ecx
  int v7; // ecx
  wchar_t v8; // ax
  int v9; // eax
  Sim *v10; // ecx
  Sim *v11; // ecx
  FlagManager *v12; // ecx
  long double v13; // st7
  Sim *v14; // ecx
  long double v15; // st7
  Sim *v16; // ecx
  unsigned int v17; // eax
  CarAvatar *v18; // ecx
  Car *v19; // eax
  IRigidBody *v20; // ecx
  int v21; // xmm0_4
  IRigidBody_vtbl *v22; // eax
  int v23; // xmm0_4
  Car *v24; // eax
  int v25; // xmm0_4
  Car *v26; // eax
  int v27; // eax
  CarAvatar *v28; // ecx
  int v29; // xmm0_4
  Sim *v30; // eax
  float v31; // xmm2_4
  float v32; // xmm1_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  float v35; // xmm0_4
  float v36; // xmm2_4
  float v37; // xmm3_4
  unsigned __int64 v38; // xmm2_8
  unsigned int *v39; // eax
  bool v40; // al
  Sim *v41; // ecx
  unsigned int *v42; // edx
  unsigned int *v43; // ecx
  Sim *v44; // eax
  CarAvatar *v45; // ecx
  bool v46; // al
  Sim *v47; // edx
  PhysicsAvatar *v48; // ecx
  CarAvatar *v49; // eax
  int v50; // xmm0_4
  TimeLimitedTest *v51; // eax
  unsigned __int8 *v52; // edi
  std::wstring v53; // [esp-4h] [ebp-310h] BYREF
  Lap v54; // [esp+24h] [ebp-2E8h] BYREF
  Lap result; // [esp+54h] [ebp-2B8h] BYREF
  Lap ll; // [esp+84h] [ebp-288h] BYREF
  std::wstring blString; // [esp+B4h] [ebp-258h] BYREF
  std::wstring clString; // [esp+CCh] [ebp-240h] BYREF
  std::wstring llString; // [esp+E4h] [ebp-228h] BYREF
  Lap previousLap; // [esp+FCh] [ebp-210h] BYREF
  int v61[76]; // [esp+13Ch] [ebp-1D0h] BYREF
  Lap lap; // [esp+26Ch] [ebp-A0h] BYREF
  Session session; // [esp+29Ch] [ebp-70h] BYREF
  int v64; // [esp+308h] [ebp-4h]

  SharedMemoryWriter::writeStatic(this);
  if ( this->sharedMemories[1].nullCounts >= 30 )
  {
    if ( this->avatar )
    {
      memset(v61, 0, sizeof(v61));
      v6 = this->sim;
      v61[0] = this->sharedMemories[1].packetId;
      this->sharedMemories[1].packetId = v61[0] + 1;
      if ( ReplayManager::isInReplaymode(v6->replayManager) )
        v61[1] = 1;
      else
        v61[1] = this->sim->pauseMenu->visible + 2;
      RaceManager::getBestLap(this->avatar->sim->raceManager, &result, this->avatar);
      v64 = 0;
      timeToString(&blString, result.time, 3);
      LOBYTE(v64) = 1;
      v53._Myres = 7;
      v53._Mysize = 0;
      v53._Bx._Buf[0] = 0;
      std::wstring::assign(&v53, &blString, 0, 0xFFFFFFFF);
      stringToSM<wchar_t,15>((wchar_t (*)[15])&v61[18], v53);
      RaceManager::getLastLap(this->avatar->sim->raceManager, &ll, this->avatar);
      LOBYTE(v64) = 2;
      timeToString(&llString, ll.time, 3);
      LOBYTE(v64) = 3;
      v53._Myres = 7;
      v53._Mysize = 0;
      v53._Bx._Buf[0] = 0;
      std::wstring::assign(&v53, &llString, 0, 0xFFFFFFFF);
      stringToSM<wchar_t,15>((wchar_t (*)[15])((char *)&v61[10] + 2), v53);
      RaceManager::getCurrentLap(this->avatar->sim->raceManager, &v54, this->avatar);
      LOBYTE(v64) = 4;
      timeToString(&clString, v54.time, 3);
      LOBYTE(v64) = 5;
      v53._Myres = 7;
      v53._Mysize = 0;
      v53._Bx._Buf[0] = 0;
      std::wstring::assign(&v53, &clString, 0, 0xFFFFFFFF);
      stringToSM<wchar_t,15>((wchar_t (*)[15])&v61[3], v53);
      if ( v54.splits._Myfirst == v54.splits._Mylast )
      {
        v7 = 0;
        do
        {
          v8 = Source[v7++];
          *(_WORD *)((char *)&v61[25] + v7 * 2) = v8;
        }
        while ( v8 );
      }
      else
      {
        timeToSectorString((std::wstring *)&previousLap, *(v54.splits._Mylast - 1), 1);
        LOBYTE(v64) = 6;
        v53._Myres = 7;
        v53._Mysize = 0;
        v53._Bx._Buf[0] = 0;
        std::wstring::assign(&v53, (const std::wstring *)&previousLap, 0, 0xFFFFFFFF);
        stringToSM<wchar_t,15>((wchar_t (*)[15])((char *)&v61[25] + 2), v53);
        LOBYTE(v64) = 5;
        if ( *(_DWORD *)&previousLap.isValid >= 8u )
          operator delete(previousLap.time);
      }
      v9 = RaceManager::getLapCount(this->avatar->sim->raceManager, this->avatar);
      v10 = this->sim;
      v61[33] = v9;
      RaceManager::getCurrentSession(v10->raceManager, &session);
      v11 = this->sim;
      LOBYTE(v64) = 7;
      v61[43] = session.laps;
      switch ( RaceManager::getCurrentSessionType(v11->raceManager) )
      {
        case Pratice:
          v61[2] = 0;
          break;
        case Qualify:
          v61[2] = 1;
          break;
        case Race:
          v61[2] = 2;
          break;
        case Hotlap:
          v61[2] = 3;
          break;
        case TimeAttack:
          v61[2] = 4;
          break;
        case Drift:
          v61[2] = 5;
          break;
        case Drag:
          v61[2] = 6;
          break;
        default:
          v61[2] = -1;
          break;
      }
      v12 = this->flagManager;
      if ( v12 )
      {
        switch ( FlagManager::getCurrentFlag(v12) )
        {
          case eBlueFlag:
            v61[67] = 1;
            break;
          case eBlackFlag:
            v61[67] = 3;
            break;
          case eCheckeredFlag:
            v61[67] = 5;
            break;
          case eYellowFlag:
            v61[67] = 2;
            break;
          case eWhiteFlag:
            v61[67] = 4;
            break;
          case ePenaltyFlag:
            v61[67] = 6;
            break;
          default:
            v61[67] = 0;
            break;
        }
      }
      else
      {
        this->flagManager = GameObject::getGameObject<FlagManager>(this->sim);
      }
      v13 = CarAvatar::hasPenalty(this->avatar);
      v14 = this->sim;
      *(float *)&v61[66] = v13;
      v15 = RaceManager::getSessionTimeLeft(v14->raceManager);
      v16 = this->sim;
      v53._Myres = (unsigned int)this->avatar;
      *(float *)&v61[38] = v15;
      v17 = RaceManager::getCarLeaderboardPosition(v16->raceManager, (CarAvatar *)v53._Myres);
      v18 = this->avatar;
      v61[34] = v17;
      v61[35] = v18->physicsState.lapTime;
      v61[36] = v18->physicsState.lastLap;
      v61[37] = v18->physicsState.bestLap;
      v61[0] = this->sharedMemories[1].packetId;
      this->sharedMemories[1].packetId = v61[0] + 1;
      CarAvatar::getTyreCompound(v18, &v53, 0, 1);
      stringToSM<wchar_t,33>((wchar_t (*)[33])&v61[44], v53);
      v19 = this->car;
      v20 = v19->body;
      v53._Myres = 0;
      v21 = LODWORD(v19->splineLocatorData.npos);
      v53._Mysize = (unsigned int)&previousLap;
      v22 = v20->__vftable;
      v61[62] = v21;
      v23 = *(_DWORD *)(((int (*)(IRigidBody *, Lap *, _DWORD))v22->getWorldMatrix)(v20, &previousLap, 0) + 48);
      v24 = this->car;
      v61[63] = v23;
      v25 = *(_DWORD *)(((int (*)(IRigidBody *, Lap *, _DWORD))v24->body->getWorldMatrix)(
                          v24->body,
                          &previousLap,
                          0)
                      + 52);
      v26 = this->car;
      v61[64] = v25;
      v27 = ((int (*)(IRigidBody *, Lap *, _DWORD))v26->body->getWorldMatrix)(v26->body, &previousLap, 0);
      v28 = this->avatar;
      v29 = *(_DWORD *)(v27 + 56);
      v30 = this->sim;
      v31 = this->lastPosition.x - v28->bodyMatrix.M41;
      v32 = this->lastPosition.z - v28->bodyMatrix.M43;
      v61[65] = v29;
      v61[61] = LODWORD(v30->replayManager->timeMult);
      v33 = this->lastPosition.y - v28->bodyMatrix.M42;
      v34 = (float)(v31 * v31) + (float)(v33 * v33);
      v35 = 0.0;
      v36 = v34 + (float)(v32 * v32);
      if ( v36 != 0.0 )
        v35 = fsqrt(v36);
      v37 = this->currentDistance + v35;
      this->currentDistance = v37;
      v38 = _mm_unpacklo_ps((__m128)LODWORD(v28->bodyMatrix.M41), (__m128)LODWORD(v28->bodyMatrix.M42)).m128_u64[0];
      previousLap.splits._Mylast = (unsigned int *)LODWORD(v28->bodyMatrix.M43);
      v39 = previousLap.splits._Mylast;
      *(_QWORD *)&this->lastPosition.x = v38;
      LODWORD(this->lastPosition.z) = v39;
      *(float *)&v61[39] = v37;
      v40 = CarAvatar::isInPit(v28);
      v41 = this->sim;
      v53._Myres = (unsigned int)this->avatar;
      v61[40] = v40;
      RaceManager::getCurrentLap(v41->raceManager, &lap, (CarAvatar *)v53._Myres);
      v42 = lap.splits._Myfirst;
      v43 = lap.splits._Mylast;
      LOBYTE(v64) = 8;
      if ( lap.splits._Myfirst == lap.splits._Mylast )
      {
        RaceManager::getLastLap(this->sim->raceManager, &previousLap, this->avatar);
        if ( !previousLap.time || previousLap.splits._Myfirst == previousLap.splits._Mylast )
          v61[42] = 0;
        else
          v61[42] = *(previousLap.splits._Mylast - 1);
        Lap::~Lap(&previousLap);
        v43 = lap.splits._Mylast;
        v42 = lap.splits._Myfirst;
      }
      else
      {
        v61[42] = *(lap.splits._Mylast - 1);
      }
      v44 = this->sim;
      v61[41] = v43 - v42;
      v45 = this->avatar;
      v61[68] = v44->drivingAidsManager->idealLine;
      v46 = CarAvatar::isInPitlane(v45);
      v47 = this->sim;
      v61[69] = v46;
      v48 = v47->physicsAvatar;
      v49 = this->avatar;
      v61[70] = LODWORD(v48->engine.track->dynamicGripLevel);
      *(float *)&v50 = v48->windData.speed.value * 3.5999999;
      v61[71] = v49->mandatoryPitstopDone;
      v51 = v47->timeLimitedTest;
      v61[72] = v50;
      v61[73] = LODWORD(v48->windData.directionDEG);
      if ( v51 )
        v61[74] = v51->lastRemainingTime;
      else
        v61[74] = -1;
      v52 = this->sharedMemories[1].mapFileBuffer;
      v61[75] = v47->escMenu->visible;
      qmemcpy(v52, v61, 0x130u);
      Lap::~Lap(&lap);
      Session::~Session(&session);
      if ( clString._Myres >= 8 )
        operator delete(clString._Bx._Ptr);
      clString._Myres = 7;
      clString._Mysize = 0;
      clString._Bx._Buf[0] = 0;
      Lap::~Lap(&v54);
      if ( llString._Myres >= 8 )
        operator delete(llString._Bx._Ptr);
      llString._Myres = 7;
      llString._Mysize = 0;
      llString._Bx._Buf[0] = 0;
      Lap::~Lap(&ll);
      if ( blString._Myres >= 8 )
        operator delete(blString._Bx._Ptr);
      blString._Myres = 7;
      blString._Mysize = 0;
      blString._Bx._Buf[0] = 0;
      Lap::~Lap(&result);
    }
  }
  else
  {
    if ( Sim::getCar(this->sim, 0) )
    {
      v3 = Sim::getCar(this->sim, 0);
      v4 = _mm_unpacklo_ps((__m128)LODWORD(v3->bodyMatrix.M41), (__m128)LODWORD(v3->bodyMatrix.M42)).m128_u64[0];
      previousLap.splits._Mylast = (unsigned int *)LODWORD(v3->bodyMatrix.M43);
      v5 = previousLap.splits._Mylast;
      *(_QWORD *)&this->lastPosition.x = v4;
      LODWORD(this->lastPosition.z) = v5;
    }
    ++this->sharedMemories[1].nullCounts;
  }
}
void SharedMemoryWriter::updatePhysics(SharedMemoryWriter *this, const long double *dt)
{
  int v3; // eax
  Car *v4; // ecx
  int v5; // eax
  float v6; // xmm0_4
  double v7; // st7
  Car *v8; // ecx
  float v9; // xmm0_4
  double v10; // st7
  Car *v11; // ecx
  int v12; // edx
  int v13; // esi
  _BYTE *v14; // edi
  float *v15; // eax
  int v16; // ecx
  _BYTE *v17; // esi
  float v18; // xmm0_4
  Car *v19; // eax
  double v20; // st7
  Car *v21; // ecx
  int v22; // edx
  int v23; // eax
  int v24; // eax
  int v25; // esi
  float v26; // edx
  int v27; // eax
  Car *v28; // ecx
  Car *v29; // eax
  mat44f *v30; // eax
  Car *v31; // ecx
  bool v32; // zf
  BOOL v33; // eax
  float v34; // xmm0_4
  double v35; // st7
  LapInvalidator *v36; // eax
  Car *v37; // ecx
  CarAvatar *v38; // eax
  float v39; // xmm0_4
  int v40; // eax
  float v41; // xmm0_4
  PhysicsEngine *v42; // eax
  Car *v43; // ecx
  double v44; // st7
  PerformanceMeter *v45; // ecx
  PerformanceSplit *v46; // eax
  CarAvatar *v47; // ecx
  float v48; // xmm0_4
  CarAvatar *v49; // ecx
  Car *v50; // ecx
  float v51; // xmm0_4
  float v52; // xmm0_4
  ICarControlsProvider *v53; // eax
  CarAvatar *v54; // ecx
  float ref; // [esp+4h] [ebp-304h]
  Speed result; // [esp+18h] [ebp-2F0h] BYREF
  int v57; // [esp+1Ch] [ebp-2ECh]
  int v58; // [esp+20h] [ebp-2E8h]
  int v59; // [esp+24h] [ebp-2E4h]
  int v60; // [esp+28h] [ebp-2E0h]
  vec3f velocity; // [esp+2Ch] [ebp-2DCh] BYREF
  vec3f lvel; // [esp+38h] [ebp-2D0h] BYREF
  vec3f local_av; // [esp+44h] [ebp-2C4h] BYREF
  char v64[64]; // [esp+50h] [ebp-2B8h] BYREF
  float imo[3]; // [esp+90h] [ebp-278h] BYREF
  unsigned int v66; // [esp+A8h] [ebp-260h]
  _BYTE v67[592]; // [esp+B0h] [ebp-258h] BYREF

  if ( !this->car )
    return;
  v3 = this->sharedMemories[2].nullCounts;
  if ( v3 < 300 )
  {
    this->sharedMemories[2].nullCounts = v3 + 1;
    return;
  }
  memset(v67, 0, sizeof(v67));
  *(_DWORD *)v67 = this->sharedMemories[2].packetId;
  this->sharedMemories[2].packetId = *(_DWORD *)v67 + 1;
  v4 = this->car;
  v5 = v4->drivetrain.currentGear;
  *(float *)&v67[44] = v4->accG.x;
  *(_QWORD *)&v67[48] = *(_QWORD *)&v4->accG.y;
  v6 = v4->controls.brake;
  *(_DWORD *)&v67[16] = v5;
  *(float *)&v67[8] = v6;
  *(float *)&v67[4] = v4->controls.gas;
  *(float *)&v67[28] = Car::getSpeed(v4, &result)->value * 3.5999999;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  v7 = Drivetrain::getEngineRPM(&this->car->drivetrain);
  v8 = this->car;
  result.value = v7;
  v9 = v8->fuel;
  *(_DWORD *)&v67[20] = (int)result.value;
  *(float *)&v67[12] = v9;
  v10 = BrakeSystem::getFrontBias(&v8->brakeSystem);
  v11 = this->car;
  result.value = COERCE_FLOAT(&v67[424]);
  v12 = 0;
  v13 = 0;
  v57 = 0;
  v59 = 0;
  *(float *)&v67[564] = v10;
  v58 = 0;
  v60 = 11704 - (_DWORD)&v67[72];
  do
  {
    v14 = &v67[v12 + 72];
    *((_DWORD *)v14 - 4) = *(_DWORD *)((char *)&v11->tyres[0].status.ndSlip + v13);
    *(float *)v14 = *(float *)((char *)&v11->tyres[0].status.load + v13);
    *((_DWORD *)v14 + 4) = *(_DWORD *)((char *)&v11->tyres[0].status.pressureDynamic + v13);
    *((_DWORD *)v14 + 8) = *(_DWORD *)((char *)&v11->tyres[0].status.angularVelocity + v13);
    v15 = (float *)(*(int (**)(_DWORD))(**(_DWORD **)((char *)v11->suspensions._Myfirst + v12) + 36))(*(ISuspension **)((char *)v11->suspensions._Myfirst + v12));
    v16 = v57;
    v17 = &v14[v60];
    v18 = *v15;
    v19 = this->car;
    *((float *)v14 + 28) = v18 - *(float *)&v14[v60 - 11480 + (_DWORD)this];
    ref = *(double *)((char *)&v19->tyres[0].status.virtualKM + v16);
    v20 = Curve::getValue((Curve *)((char *)&v19->tyres[0].modelData.wearCurve + v16), ref);
    v21 = this->car;
    v22 = v57;
    v23 = *(_DWORD *)((char *)&v21->tyres[0].status.dirtyLevel + v57);
    *((float *)v14 + 12) = v20 * 100.0;
    *((_DWORD *)v14 + 16) = v23;
    *((_DWORD *)v14 + 24) = *(_DWORD *)((char *)&v21->tyres[0].status.camberRAD + v22);
    *((_DWORD *)v14 + 20) = *(_DWORD *)((char *)&v21->tyres[0].thermalModel.coreTemp + v22);
    v24 = *(_DWORD *)&v17[(_DWORD)v21];
    v25 = v22;
    *((_DWORD *)v14 + 38) = v24;
    *((_DWORD *)v14 + 69) = LODWORD(v21->brakeSystem.discs[v58 / 0x5Cu].t);
    TyreThermalModel::getIMO((TyreThermalModel *)((char *)&v21->tyres[0].thermalModel + v22), imo);
    v11 = this->car;
    v26 = result.value;
    *((float *)v14 + 74) = imo[0];
    v27 = *(_DWORD *)((char *)&v11->tyres[0].contactPoint.x + v25);
    *((float *)v14 + 78) = imo[1];
    v59 += 4;
    *((float *)v14 + 82) = imo[2];
    *(_DWORD *)(LODWORD(v26) - 4) = v27;
    *(_DWORD *)LODWORD(v26) = *(_DWORD *)((char *)&v11->tyres[0].contactPoint.y + v25);
    *(float *)(LODWORD(v26) + 4) = *(float *)((char *)&v11->tyres[0].contactPoint.z + v25);
    *(float *)(LODWORD(v26) + 44) = *(float *)((char *)&v11->tyres[0].contactNormal.x + v25);
    *(float *)(LODWORD(v26) + 48) = *(float *)((char *)&v11->tyres[0].contactNormal.y + v25);
    *(float *)(LODWORD(v26) + 52) = *(float *)((char *)&v11->tyres[0].contactNormal.z + v25);
    *(float *)(LODWORD(v26) + 92) = *(float *)((char *)&v11->tyres[0].roadHeading.x + v25);
    *(float *)(LODWORD(v26) + 96) = *(float *)((char *)&v11->tyres[0].roadHeading.y + v25);
    *(float *)(LODWORD(v26) + 100) = *(float *)((char *)&v11->tyres[0].roadHeading.z + v25);
    v13 = v25 + 1632;
    v58 += 92;
    v57 = v13;
    LODWORD(result.value) = (Speed)(LODWORD(v26) + 12);
    v12 = v59;
  }
  while ( v58 < 368 );
  *(float *)&v67[240] = v11->damageZoneLevel[4];
  Car::getVelocity(v11, &velocity);
  v28 = this->car;
  *(vec3f *)&v67[32] = velocity;
  Car::getLocalVelocity(v28, &lvel);
  *(float *)&v67[576] = lvel.z;
  v29 = this->car;
  *(_QWORD *)&v67[568] = *(_QWORD *)&lvel.x;
  v30 = (mat44f *)((int (*)(IRigidBody *, char *, _DWORD))v29->body->getWorldMatrix)(v29->body, v64, 0);
  mat44f::toEuler(v30, (vec3f *)imo);
  v31 = this->car;
  *(_QWORD *)&v67[208] = *(_QWORD *)imo;
  v32 = !v31->drs.isPresent;
  *(float *)&v67[216] = imo[2];
  v33 = !v32 && v31->drs.isActive;
  v32 = !v31->abs.isPresent;
  *(float *)&v67[200] = (float)v33;
  *(float *)&v67[204] = v31->tractionControl.slipRatioLimit;
  if ( v32 || !v31->abs.isActive )
    *(_DWORD *)&v67[252] = 0;
  else
    *(float *)&v67[252] = v31->abs.slipRatioLimit;
  v34 = v31->controls.steer;
  *(_DWORD *)&v67[248] = v31->speedLimiter.isLimiting;
  *(float *)&v67[24] = v34;
  v35 = Car::getCGHeight(v31);
  v36 = this->lapInvalidator;
  *(float *)&v67[220] = v35;
  if ( v36 )
    *(_DWORD *)&v67[244] = v36->currentTyresOut;
  v37 = this->car;
  v32 = !v37->tractionControl.isActive;
  *(_DWORD *)&v67[264] = v37->autoShift.isActive;
  if ( v32 )
    *(_DWORD *)&v67[204] = 0;
  v38 = this->avatar;
  *(float *)&v67[268] = v38->physicsState.rideHeight[0];
  v39 = v38->physicsState.rideHeight[1];
  v40 = v38->physicsState.limiterRPM;
  *(float *)&v67[272] = v39;
  *(float *)&v67[276] = v37->drivetrain.acEngine.status.turboBoost;
  v41 = v37->ballastKG;
  *(_DWORD *)&v67[588] = v40;
  v42 = v37->ksPhysics;
  *(float *)&v67[280] = v41;
  *(float *)&v67[284] = v37->aeroMap.airDensity;
  *(_QWORD *)&v67[288] = *(_QWORD *)&v42->ambientTemperature;
  Car::getLocalAngularVelocity(v37, &local_av);
  v43 = this->car;
  *(vec3f *)&v67[296] = local_av;
  v44 = Car::getFinalFF(v43);
  v45 = &this->car->performanceMeter;
  *(float *)&v67[308] = v44;
  v46 = PerformanceMeter::getCurrentSplit(v45, (PerformanceSplit *)imo);
  v47 = this->avatar;
  v48 = v46->t;
  *(_DWORD *)&v67[316] = v47->currentEngineBrakeSetting;
  v32 = !this->car->ers.present;
  *(float *)&v67[312] = v48;
  if ( v32 )
  {
    *(_QWORD *)&v67[320] = 0i64;
    *(_QWORD *)&v67[328] = 0i64;
  }
  else
  {
    *(_DWORD *)&v67[324] = CarAvatar::getERSPower(v47, (std::pair<int,std::wstring > *)imo)->first;
    if ( v66 >= 8 )
      operator delete(LODWORD(imo[1]));
    v49 = this->avatar;
    *(_DWORD *)&v67[320] = v49->currentERSRecovery;
    *(_DWORD *)&v67[332] = v49->physicsState.kersIsCharging;
    *(_DWORD *)&v67[328] = v49->isHeatChargingBatteries;
  }
  v50 = this->car;
  if ( v50->ers.present )
  {
    v51 = v50->ers.charge;
    *(float *)&v67[256] = v51;
    *(float *)&v67[260] = v50->ers.input;
    v52 = v50->ers.currentJ;
  }
  else
  {
    if ( !v50->kers.present )
    {
      *(_QWORD *)&v67[256] = 0i64;
      *(_DWORD *)&v67[336] = 0;
      goto LABEL_29;
    }
    *(float *)&v67[256] = v50->kers.charge;
    *(float *)&v67[260] = v50->kers.input;
    v52 = v50->kers.currentJ;
  }
  *(float *)&v67[336] = v52 * 0.001;
LABEL_29:
  if ( v50->drs.isPresent )
  {
    *(_DWORD *)&v67[340] = v50->drs.isAvailable;
    *(_DWORD *)&v67[344] = v50->drs.isActive;
  }
  else
  {
    *(_DWORD *)&v67[340] = 0;
    *(_DWORD *)&v67[344] = 0;
  }
  *(float *)&v67[364] = v50->controls.clutch;
  v53 = Car::getControlsProvider(v50);
  *(_DWORD *)&v67[416] = __RTDynamicCast(
                           v53,
                           0,
                           &ICarControlsProvider `RTTI Type Descriptor',
                           &AIDriver `RTTI Type Descriptor',
                           0) != 0;
  if ( this->car->drivetrain.acEngine.p2p.enabled )
  {
    v54 = this->avatar;
    *(_DWORD *)&v67[580] = v54->physicsState.p2pActivations;
    *(_DWORD *)&v67[584] = v54->physicsState.p2pStatus;
  }
  qmemcpy(this->sharedMemories[2].mapFileBuffer, v67, 0x250u);
}
void SharedMemoryWriter::writeStatic(SharedMemoryWriter *this)
{
  wchar_t v2; // ax
  std::wstring *v3; // eax
  TrackData *v4; // eax
  CarAvatar *v5; // ecx
  int v6; // eax
  double v7; // xmm0_8
  Sim *v8; // ecx
  int v9; // eax
  RaceManager *v10; // ecx
  CarAvatar *v11; // eax
  CarAvatar *v12; // esi
  Car *v13; // eax
  Sim *v14; // edx
  TrackAvatar *v15; // ecx
  float v16; // xmm0_4
  RaceManager *v17; // eax
  bool v18; // zf
  PhysicsAvatar *v19; // eax
  DrivingAssistManager *v20; // ecx
  float v21; // xmm0_4
  BOOL v22; // eax
  double v23; // st7
  CarAvatar *v24; // ecx
  CarAvatar *v25; // ecx
  BOOL v26; // eax
  float v27; // xmm0_4
  int v28; // eax
  Sim *v29; // ecx
  TrackData *v30; // eax
  AISpline *v31; // eax
  Sim *v32; // ecx
  unsigned int v33; // esi
  bool v34; // bl
  Sim *v35; // ecx
  int v36; // eax
  Sim *v37; // ecx
  unsigned __int16 v38; // ax
  Sim *v39; // ecx
  std::wstring v40; // [esp-18h] [ebp-448h] BYREF
  std::wifstream is; // [esp+14h] [ebp-41Ch] BYREF
  std::wstring driverName; // [esp+CCh] [ebp-364h] BYREF
  std::wstring acVersion; // [esp+E4h] [ebp-34Ch] BYREF
  Session result; // [esp+FCh] [ebp-334h] BYREF
  std::wstring smVersion; // [esp+15Ch] [ebp-2D4h] BYREF
  wchar_t dest[342]; // [esp+174h] [ebp-2BCh] BYREF
  int v47; // [esp+42Ch] [ebp-4h]

  if ( this->avatar && !this->staticWrote && this->car )
  {
    memset(dest, 0, sizeof(dest));
    std::wstring::wstring(&smVersion, L"1.7");
    v47 = 0;
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    std::wstring::assign(&v40, &smVersion, 0, 0xFFFFFFFF);
    stringToSM<wchar_t,15>((wchar_t (*)[15])dest, v40);
    acVersion._Myres = 7;
    acVersion._Mysize = 0;
    acVersion._Bx._Buf[0] = 0;
    LOBYTE(v47) = 1;
    std::wifstream::wifstream(&is, L"changelog.txt", 1, 64, 1);
    LOBYTE(v47) = 2;
    if ( (unsigned __int8)std::ios_base::operator bool((char *)&is + *(_DWORD *)(*(_DWORD *)is.gap0 + 4)) )
    {
      v2 = std::wios::widen((char *)&is + *(_DWORD *)(*(_DWORD *)is.gap0 + 4), 10);
      std::getline<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(&is, &acVersion, v2);
    }
    if ( !std::wfilebuf::close((std::wfilebuf *)is.gap10) )
      std::wios::setstate((char *)&is + *(_DWORD *)(*(_DWORD *)is.gap0 + 4), 2, 0);
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    std::wstring::assign(&v40, &acVersion, 0, 0xFFFFFFFF);
    stringToSM<wchar_t,15>((wchar_t (*)[15])&dest[15], v40);
    v3 = &this->avatar->unixName;
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    std::wstring::assign(&v40, v3, 0, 0xFFFFFFFF);
    stringToSM<wchar_t,33>((wchar_t (*)[33])&dest[34], v40);
    v4 = Sim::getTrackData(this->avatar->sim, (TrackData *)&result);
    std::wstring::wstring(&v40, &v4->name);
    stringToSM<wchar_t,33>((wchar_t (*)[33])&dest[67], v40);
    TrackData::~TrackData((ChatElement *)&result);
    v5 = this->avatar;
    v6 = v5->physicsInfo.maxRpm;
    *(float *)&dest[204] = v5->physicsInfo.maxPowerW;
    *(float *)&dest[202] = v5->physicsInfo.maxTorqueNM;
    v7 = v5->physicsInfo.maxFuel;
    v8 = this->sim;
    *(_DWORD *)&dest[206] = v6;
    v9 = (char *)v8->cars._Mylast - (char *)v8->cars._Myfirst;
    v10 = v8->raceManager;
    *(_DWORD *)&dest[32] = v9 >> 2;
    *(float *)&dest[208] = v7;
    *(_DWORD *)&dest[30] = RaceManager::getSessionCount(v10);
    v11 = this->avatar;
    driverName._Bx._Buf[0] = 0;
    driverName._Myres = 7;
    driverName._Mysize = 0;
    std::wstring::assign(&driverName, &v11->driverInfo.name, 0, 0xFFFFFFFF);
    LOBYTE(v47) = 3;
    if ( driverName._Mysize > 0x1E )
      std::wstring::resize(&driverName, 0x1Eu);
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    std::wstring::assign(&v40, &driverName, 0, 0xFFFFFFFF);
    stringToSM<wchar_t,33>((wchar_t (*)[33])&dest[100], v40);
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    std::wstring::assign(&v40, &driverName, 0, 0xFFFFFFFF);
    stringToSM<wchar_t,33>((wchar_t (*)[33])&dest[133], v40);
    v40._Myres = 7;
    v40._Mysize = 0;
    v40._Bx._Buf[0] = 0;
    std::wstring::assign(&v40, &driverName, 0, 0xFFFFFFFF);
    stringToSM<wchar_t,33>((wchar_t (*)[33])&dest[166], v40);
    v12 = this->avatar;
    v13 = this->car;
    v14 = this->sim;
    v15 = v14->track;
    *(float *)&dest[210] = v12->physicsInfo.bumpStopsUp[0] - v12->physicsInfo.bumpStopsDn[0];
    *(float *)&dest[218] = v13->tyres[0].data.radius;
    *(float *)&dest[212] = v12->physicsInfo.bumpStopsUp[1] - v12->physicsInfo.bumpStopsDn[1];
    *(float *)&dest[220] = v13->tyres[1].data.radius;
    *(float *)&dest[214] = v12->physicsInfo.bumpStopsUp[2] - v12->physicsInfo.bumpStopsDn[2];
    *(float *)&dest[222] = v13->tyres[2].data.radius;
    *(float *)&dest[216] = v12->physicsInfo.bumpStopsUp[3] - v12->physicsInfo.bumpStopsDn[3];
    v16 = v13->tyres[3].data.radius;
    *(_DWORD *)&dest[200] = v15->physicsTrack.sectorsNormalizedPositions._Mylast
                          - v15->physicsTrack.sectorsNormalizedPositions._Myfirst;
    v17 = v14->raceManager;
    *(float *)&dest[224] = v16;
    *(float *)&dest[226] = v12->physicsInfo.maxTurboBoost;
    v18 = !v17->penaltiesEnabled;
    v19 = v14->physicsAvatar;
    *(_DWORD *)&dest[232] = !v18;
    *(float *)&dest[234] = v19->engine.fuelConsumptionRate;
    v20 = v14->drivingAidsManager;
    *(float *)&dest[236] = v19->engine.tyreConsumptionRate;
    v21 = v19->engine.mechanicalDamageRate;
    v22 = v19->engine.allowTyreBlankets;
    *(float *)&dest[238] = v21;
    *(_DWORD *)&dest[240] = v22;
    v23 = DrivingAssistManager::getStabilityControl(v20);
    v24 = this->avatar;
    *(float *)&dest[242] = v23;
    *(_DWORD *)&dest[244] = v24->physics->autoClutch.useAutoOnChange;
    *(_DWORD *)&dest[246] = CarAvatar::getAutoBlip(v24);
    v25 = this->avatar;
    v26 = v25->physicsInfo.hasDRS;
    *(float *)&dest[254] = v25->physicsInfo.kersMaxJ;
    v27 = v25->physicsInfo.ersMaxJ;
    *(_DWORD *)&dest[248] = v26;
    v18 = !v25->physicsInfo.hasERS;
    *(float *)&dest[296] = v27;
    *(_DWORD *)&dest[250] = !v18;
    *(_DWORD *)&dest[252] = v25->physicsInfo.hasKERS;
    *(_DWORD *)&dest[256] = v25->physicsInfo.engineBrakeSettingsCount;
    v28 = v25->physicsInfo.ersPowerControllerCount;
    v29 = v25->sim;
    *(_DWORD *)&dest[258] = v28;
    v30 = Sim::getTrackData(v29, (TrackData *)&result);
    std::wstring::wstring(&v40, &v30->configuration);
    stringToSM<wchar_t,33>((wchar_t (*)[33])&dest[262], v40);
    if ( result.name._Bx._Ptr >= (wchar_t *)8 )
      operator delete(*(_DWORD *)&result.spawSet._Bx._Alias[4]);
    result.name._Bx._Ptr = (wchar_t *)7;
    result.spawSet._Myres = 0;
    result.spawSet._Bx._Buf[2] = 0;
    if ( result.spawSet._Bx._Ptr >= (wchar_t *)8 )
      operator delete(result.sessionType);
    if ( TrackAvatar::getAISpline(this->avatar->sim->track) )
    {
      v31 = TrackAvatar::getAISpline(this->avatar->sim->track);
      *(float *)&dest[260] = Spline::length(&v31->spline);
    }
    else
    {
      *(_DWORD *)&dest[260] = 0;
    }
    v32 = this->sim;
    *(_DWORD *)&dest[298] = 0;
    if ( v32->client )
    {
      v33 = 0;
      if ( RaceManager::getSessionCount(v32->raceManager) )
      {
        do
        {
          v34 = RaceManager::getSessionInfo(this->sim->raceManager, &result, v33)->sessionType == Race;
          if ( result.name._Myres >= 8 )
            operator delete(result.name._Bx._Ptr);
          result.name._Myres = 7;
          result.name._Mysize = 0;
          result.name._Bx._Buf[0] = 0;
          if ( result.spawSet._Myres >= 8 )
            operator delete(result.spawSet._Bx._Ptr);
          if ( v34 )
          {
            *(_DWORD *)&dest[298] = RaceManager::getSessionInfo(this->sim->raceManager, &result, v33)->isTimedRace;
            if ( result.name._Myres >= 8 )
              operator delete(result.name._Bx._Ptr);
            result.name._Myres = 7;
            result.name._Mysize = 0;
            result.name._Bx._Buf[0] = 0;
            if ( result.spawSet._Myres >= 8 )
              operator delete(result.spawSet._Bx._Ptr);
          }
          ++v33;
        }
        while ( v33 < RaceManager::getSessionCount(this->sim->raceManager) );
      }
      *(_DWORD *)&dest[300] = RaceManager::hasExtraLap(this->sim->raceManager);
    }
    else
    {
      *(_DWORD *)&dest[300] = 0;
    }
    CarAvatar::getCurrentSkin(this->avatar, &v40);
    stringToSM<wchar_t,33>((wchar_t (*)[33])&dest[302], v40);
    v35 = this->sim;
    if ( v35->client )
    {
      v36 = RaceManager::getInvertedGridPositions(v35->raceManager);
      v37 = this->sim;
      *(_DWORD *)&dest[336] = v36;
      v38 = RaceManager::getPitWindowStart(v37->raceManager);
      v39 = this->sim;
      *(_DWORD *)&dest[338] = v38;
      *(_DWORD *)&dest[340] = RaceManager::getPitWindowEnd(v39->raceManager);
    }
    else
    {
      *(_DWORD *)&dest[336] = 0;
      *(_DWORD *)&dest[338] = 0;
      *(_DWORD *)&dest[340] = 0;
    }
    this->staticWrote = 1;
    qmemcpy(this->sharedMemories[0].mapFileBuffer, dest, 0x2ACu);
    if ( driverName._Myres >= 8 )
      operator delete(driverName._Bx._Ptr);
    driverName._Myres = 7;
    driverName._Mysize = 0;
    driverName._Bx._Buf[0] = 0;
    std::wifstream::~wifstream<wchar_t,std::char_traits<wchar_t>>((std::wifstream *)&is.gap64[12]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&is.gap64[12]);
    if ( acVersion._Myres >= 8 )
      operator delete(acVersion._Bx._Ptr);
    if ( smVersion._Myres >= 8 )
      operator delete(smVersion._Bx._Ptr);
  }
}
