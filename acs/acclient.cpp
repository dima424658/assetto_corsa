#include "acclient.h
void ACClient::ACClient(ACClient *this, Sim *isim)
{
  float *v3; // ecx
  int v4; // edx
  int v5; // esi
  std::wofstream *v6; // ebp
  int v7; // eax
  bool v8; // cf
  int v9; // eax
  Sim *v10; // ecx
  Console *v11; // eax
  Sim *v12; // ecx
  Console *v13; // eax
  Sim *v14; // ecx
  Console *v15; // eax
  Font *v16; // eax
  Font *v17; // eax
  Event<SessionInfo> *v18; // ecx
  Sim *v19; // eax
  int v20; // eax
  std::wstring *v21; // eax
  std::wstring *v22; // eax
  bool v23; // zf
  int v24; // eax
  int v25; // ecx
  ACClientVotingManager *v26; // eax
  ICollisionObject *v27; // eax
  ICollisionObject *v28; // esi
  QOSOverlay *v29; // eax
  ICollisionObject *v30; // eax
  ICollisionObject *v31; // esi
  Event<OnMouseDownEvent> *v32; // ecx
  _BYTE v33[36]; // [esp-1Ch] [ebp-194h] BYREF
  float multiplier; // [esp+8h] [ebp-170h]
  ServerInfo *v35; // [esp+2Ch] [ebp-14Ch]
  char v36; // [esp+33h] [ebp-145h]
  ICollisionObject *_Val[2]; // [esp+34h] [ebp-144h] BYREF
  std::wstring filename; // [esp+3Ch] [ebp-13Ch] BYREF
  std::wstring key; // [esp+54h] [ebp-124h] BYREF
  std::wstring section; // [esp+6Ch] [ebp-10Ch] BYREF
  std::wstring ifilename; // [esp+84h] [ebp-F4h] BYREF
  INIReader iniOptions; // [esp+9Ch] [ebp-DCh] BYREF
  INIReaderDocuments ini; // [esp+E0h] [ebp-98h] BYREF
  INIReader iniDebug; // [esp+124h] [ebp-54h] BYREF
  int v45; // [esp+174h] [ebp-4h]

  _Val[0] = (ICollisionObject *)isim;
  _Val[1] = (ICollisionObject *)this;
  multiplier = *(float *)&isim->game;
  *(_DWORD *)&v33[32] = 7;
  *(_DWORD *)&v33[28] = 0;
  *(_WORD *)&v33[12] = 0;
  std::wstring::assign((std::wstring *)&v33[12], L"AC_CLIENT", 9u);
  GameObject::GameObject(this, *(std::wstring *)&v33[12], (Game *)LODWORD(multiplier));
  this->__vftable = (ACClient_vtbl *)&ACClient::`vftable';
  v45 = 0;
  this->evOnChatMessage.handlers._Myfirst = 0;
  this->evOnChatMessage.handlers._Mylast = 0;
  this->evOnChatMessage.handlers._Myend = 0;
  this->evOnOnlineNewSession.handlers._Myfirst = 0;
  this->evOnOnlineNewSession.handlers._Mylast = 0;
  this->evOnOnlineNewSession.handlers._Myend = 0;
  this->evOnOnlineEndSession.handlers._Myfirst = 0;
  this->evOnOnlineEndSession.handlers._Mylast = 0;
  this->evOnOnlineEndSession.handlers._Myend = 0;
  this->evOnLapCompleted.handlers._Myfirst = 0;
  this->evOnLapCompleted.handlers._Mylast = 0;
  this->evOnLapCompleted.handlers._Myend = 0;
  this->evOnVoteReceived.handlers._Myfirst = 0;
  this->evOnVoteReceived.handlers._Mylast = 0;
  this->evOnVoteReceived.handlers._Myend = 0;
  this->evOnVoteNotPassed.handlers._Myfirst = 0;
  this->evOnVoteNotPassed.handlers._Mylast = 0;
  this->evOnVoteNotPassed.handlers._Myend = 0;
  this->evOnMandatoryPitDone.handlers._Myfirst = 0;
  this->evOnMandatoryPitDone.handlers._Mylast = 0;
  this->evOnMandatoryPitDone.handlers._Myend = 0;
  this->serverName._Myres = 7;
  this->serverName._Mysize = 0;
  this->serverName._Bx._Buf[0] = 0;
  this->driverInfo.name._Myres = 7;
  this->driverInfo.name._Mysize = 0;
  this->driverInfo.name._Bx._Buf[0] = 0;
  this->driverInfo.team._Myres = 7;
  this->driverInfo.team._Mysize = 0;
  this->driverInfo.team._Bx._Buf[0] = 0;
  this->driverInfo.nationality._Myres = 7;
  this->driverInfo.nationality._Mysize = 0;
  this->driverInfo.nationality._Bx._Buf[0] = 0;
  this->driverInfo.nationCode._Myres = 7;
  this->driverInfo.nationCode._Mysize = 0;
  this->driverInfo.nationCode._Bx._Buf[0] = 0;
  this->serverInfo.name._Myres = 7;
  this->serverInfo.name._Mysize = 0;
  v35 = &this->serverInfo;
  this->serverInfo.name._Bx._Buf[0] = 0;
  this->serverInfo.ip._Myres = 7;
  this->serverInfo.ip._Mysize = 0;
  this->serverInfo.ip._Bx._Buf[0] = 0;
  LOBYTE(v45) = 11;
  std::wstring::assign(&this->serverInfo.name, L"SERVER_NAME", 0xBu);
  std::wstring::assign(&this->serverInfo.ip, L"0.0.0.0", 7u);
  *(_DWORD *)&this->serverInfo.httpPort = 0;
  this->serverInfo.tcpPort = 0;
  this->guid._Myres = 7;
  this->guid._Mysize = 0;
  this->guid._Bx._Buf[0] = 0;
  this->rules.maxMetersWrongWay = 100.0;
  this->serverDrivingAssists.tc = 1;
  this->serverDrivingAssists.abs = 1;
  *(_WORD *)&this->serverDrivingAssists.stability = 257;
  this->handshakeServerTimeS = 0.0;
  this->playerCarMD5._Myfirst = 0;
  this->playerCarMD5._Mylast = 0;
  this->playerCarMD5._Myend = 0;
  LOBYTE(v45) = 14;
  *(_WORD *)&this->debugStartingLights = 0;
  ACClient::ClientSessionTransition::ClientSessionTransition(&this->transitionInfo);
  LOBYTE(v45) = 15;
  RemoteSessionResult::RemoteSessionResult(&this->sessionResultsGT);
  LOBYTE(v45) = 16;
  UDPSocket::UDPSocket(&this->sok);
  this->checksumResults._Myfirst = 0;
  this->checksumResults._Mylast = 0;
  this->checksumResults._Myend = 0;
  LOBYTE(v45) = 18;
  this->votingManager = 0;
  this->avatar = 0;
  *(_OWORD *)&this->lastSendTime = 0i64;
  *(_OWORD *)&this->lastChatMessage = 0i64;
  IPAddress::IPAddress(&this->serverIP);
  this->netCars._Myfirst = 0;
  this->netCars._Mylast = 0;
  this->netCars._Myend = 0;
  LOBYTE(v45) = 20;
  this->handshakeCarPosition = -1;
  this->wrongWayIndicator = 0;
  this->numWrongWayInfractions = 0;
  TCPSocket::TCPSocket(&this->tcpSock);
  this->currentSession.name._Myres = 7;
  LODWORD(multiplier) = 7;
  this->currentSession.name._Mysize = 0;
  *(_DWORD *)&v33[32] = L"UNNAMED";
  LOBYTE(v45) = 21;
  this->currentSession.name._Bx._Buf[0] = 0;
  std::wstring::assign(&this->currentSession.name, *(const wchar_t **)&v33[32], LODWORD(multiplier));
  this->currentSession.index = 0;
  this->currentSession.time = 0;
  this->currentSession.laps = 0;
  this->currentSession.startTime = 0.0;
  *(_WORD *)&this->currentSession.isSpectator = 0;
  this->currentSession.hasExtraLap = 0;
  this->sessions._Myfirst = 0;
  this->sessions._Mylast = 0;
  this->sessions._Myend = 0;
  this->dcCountdown.isSignaled = 0;
  this->dcCountdown.timeToDisconnection = 0.0;
  this->dcCountdown.message._Myres = 7;
  this->dcCountdown.message._Mysize = 0;
  this->dcCountdown.message._Bx._Buf[0] = 0;
  this->lastSessionCheckTime = DOUBLE_N1_0;
  this->welcomeMessage._Myres = 7;
  this->welcomeMessage._Mysize = 0;
  this->welcomeMessage._Bx._Buf[0] = 0;
  v3 = this->damageReport.damageZoneLevel;
  this->damageReport.lastSendTime = 0.0;
  v4 = 0;
  v5 = 5;
  if ( this->damageReport.damageZoneLevel > &this->damageReport.damageZoneLevel[5] )
    v5 = 0;
  if ( v5 )
  {
    do
    {
      ++v4;
      *v3++ = 0.0;
    }
    while ( v4 != v5 );
  }
  this->isFlashingCache = 0;
  this->wreckerProtection.maxContactsPerKM = 5.0;
  this->wreckerProtection.warningCount = 0;
  this->wreckerProtection.contacts = 0;
  this->wreckerProtection.blackListRequested = 0;
  this->resultScreenTime = 0;
  this->raceOverTime = 0;
  this->isGasPenaltyDisabled = 0;
  this->pitWindowStart = 0;
  this->pitWindowEnd = 0;
  *(_WORD *)&this->hasLeaderFinished = 0;
  this->raceClosingTime = 0.0;
  *(_DWORD *)&this->isResultScreenOn = 0;
  this->invertedGridPositions = 0;
  this->localCarCurrentSplits._Myfirst = 0;
  this->localCarCurrentSplits._Mylast = 0;
  this->localCarCurrentSplits._Myend = 0;
  this->localCarBestSplits._Myfirst = 0;
  this->localCarBestSplits._Mylast = 0;
  this->localCarBestSplits._Myend = 0;
  this->bestSplits._Myfirst = 0;
  this->bestSplits._Mylast = 0;
  this->bestSplits._Myend = 0;
  this->globalBestlap = 0;
  this->localCarLaps._Myfirst = 0;
  this->localCarLaps._Mylast = 0;
  this->localCarLaps._Myend = 0;
  this->localCarLastLap.splits._Myfirst = 0;
  this->localCarLastLap.splits._Mylast = 0;
  this->localCarLastLap.splits._Myend = 0;
  this->localCarLastLap.compound._Myres = 7;
  this->localCarLastLap.compound._Mysize = 0;
  this->localCarLastLap.compound._Bx._Buf[0] = 0;
  this->localCarLastLap.time = 0;
  this->localCarLastLap.isValid = 0;
  this->localCarLastLap.cuts = 0;
  v6 = &this->log;
  LOBYTE(v45) = 30;
  LODWORD(multiplier) = 1;
  *(_WORD *)&this->useLog = 0;
  std::wofstream::wofstream(&this->log, SLODWORD(multiplier));
  this->qos.usingMegapackets = 0;
  this->qos.counter = 0;
  this->qos.startTime = 0.0;
  this->qos.lastQOS = 0;
  this->endSession.isConnectionFinished = 0;
  this->endSession.sendToPitsTimer = 5.0;
  this->endSession.shutdownTimer = 10.0;
  this->clientColissionEvents._Myfirst = 0;
  this->clientColissionEvents._Mylast = 0;
  this->clientColissionEvents._Myend = 0;
  LODWORD(multiplier) = 28;
  LOBYTE(v45) = 32;
  *(_DWORD *)&v33[32] = L"system/cfg/assetto_corsa.ini";
  this->lastClientEventSendTime = 0.0;
  this->useLog = 0;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, *(const wchar_t **)&v33[32], LODWORD(multiplier));
  LOBYTE(v45) = 33;
  INIReader::INIReader(&iniDebug, &ifilename);
  LOBYTE(v45) = 35;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( iniDebug.ready )
  {
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    std::wstring::assign(&filename, L"MULTI_LOG", 9u);
    LOBYTE(v45) = 36;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"DEBUG", 5u);
    LOBYTE(v45) = 37;
    v7 = INIReader::getInt(&iniDebug, &section, &filename);
    v8 = section._Myres < 8;
    this->useLog = v7 > 0;
    if ( !v8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v45) = 35;
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
  }
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"system/cfg/options.ini", 0x16u);
  LOBYTE(v45) = 38;
  INIReader::INIReader(&iniOptions, &section);
  LOBYTE(v45) = 40;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  if ( iniOptions.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"IGNORE_RESULT_TELEPORT", 0x16u);
    LOBYTE(v45) = 41;
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    std::wstring::assign(&filename, L"OPTIONS", 7u);
    LOBYTE(v45) = 42;
    v36 = INIReader::hasKey(&iniOptions, &filename, &key);
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
    filename._Myres = 7;
    filename._Mysize = 0;
    filename._Bx._Buf[0] = 0;
    LOBYTE(v45) = 40;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v36 )
    {
      std::wstring::wstring(&filename, L"IGNORE_RESULT_TELEPORT");
      LOBYTE(v45) = 43;
      std::wstring::wstring(&key, L"OPTIONS");
      LOBYTE(v45) = 44;
      v9 = INIReader::getInt(&iniOptions, &key, &filename);
      v8 = key._Myres < 8;
      this->ignoreResultTeleport = v9 > 0;
      if ( !v8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v45) = 40;
      if ( filename._Myres >= 8 )
        operator delete(filename._Bx._Ptr);
    }
  }
  multiplier = 1.0;
  *(_DWORD *)&v33[32] = 0;
  this->sim = (Sim *)_Val[0];
  *(_DWORD *)&v33[28] = 0;
  *(_DWORD *)&v33[24] = &this->remoteSpring;
  this->remoteSpring = 76.0;
  v35 = (ServerInfo *)v33;
  this->localCarBestLap = 0;
  this->instanceLocalCarBestLap = 0;
  this->finishPosition = -1;
  this->remoteDamper = 25.5;
  this->remoteFactor = 250.0;
  *(_DWORD *)&v33[20] = 7;
  *(_DWORD *)&v33[16] = 0;
  *(_WORD *)v33 = 0;
  std::wstring::assign((std::wstring *)v33, L"remoteSpring", 0xCu);
  v10 = this->sim;
  LOBYTE(v45) = 45;
  v11 = Sim::getConsole(v10);
  LOBYTE(v45) = 40;
  Console::addVar(v11, *(std::wstring *)v33, *(float **)&v33[24], *(IVarCallback **)&v33[28], v33[32], multiplier);
  multiplier = 1.0;
  *(_DWORD *)&v33[32] = 0;
  *(_DWORD *)&v33[28] = 0;
  *(_DWORD *)&v33[24] = &this->remoteDamper;
  v35 = (ServerInfo *)v33;
  *(_DWORD *)&v33[20] = 7;
  *(_DWORD *)&v33[16] = 0;
  *(_WORD *)v33 = 0;
  std::wstring::assign((std::wstring *)v33, L"remoteDamper", 0xCu);
  v12 = this->sim;
  LOBYTE(v45) = 46;
  v13 = Sim::getConsole(v12);
  LOBYTE(v45) = 40;
  Console::addVar(v13, *(std::wstring *)v33, *(float **)&v33[24], *(IVarCallback **)&v33[28], v33[32], multiplier);
  multiplier = 1.0;
  *(_DWORD *)&v33[32] = 0;
  *(_DWORD *)&v33[28] = 0;
  *(_DWORD *)&v33[24] = &this->remoteFactor;
  v35 = (ServerInfo *)v33;
  *(_DWORD *)&v33[20] = 7;
  *(_DWORD *)&v33[16] = 0;
  *(_WORD *)v33 = 0;
  std::wstring::assign((std::wstring *)v33, L"remoteFactor", 0xCu);
  v14 = this->sim;
  LOBYTE(v45) = 47;
  v15 = Sim::getConsole(v14);
  LOBYTE(v45) = 40;
  Console::addVar(v15, *(std::wstring *)v33, *(float **)&v33[24], *(IVarCallback **)&v33[28], v33[32], multiplier);
  UDPSocket::setBlockingMode(&this->sok, 0);
  this->lastSendTime = 0.0;
  LODWORD(multiplier) = 24;
  this->sendInterval = DOUBLE_96_0;
  this->sessionID = 0;
  v16 = (Font *)operator new(LODWORD(multiplier));
  v35 = (ServerInfo *)v16;
  LOBYTE(v45) = 48;
  if ( v16 )
    Font::Font(v16, eFontProportional, 32.0, 0, 0);
  else
    v17 = 0;
  LODWORD(multiplier) = this;
  this->font = v17;
  *(_DWORD *)&v33[12] = &std::_Func_impl<std::_Callable_obj<_lambda_dd422d109689ec70c09d8082b616f3cd_,0>,std::allocator<std::_Func_class<void,OnNewCarLoadedEvent const &>>,void,OnNewCarLoadedEvent const &>::`vftable';
  *(_DWORD *)&v33[16] = this;
  *(_DWORD *)&v33[28] = &v33[12];
  v18 = (Event<SessionInfo> *)&this->sim->evNewCarLoaded;
  LOBYTE(v45) = 40;
  Event<float>::addHandler(
    v18,
    *(std::function<void __cdecl(SessionInfo const &)> *)&v33[12],
    (void *)LODWORD(multiplier));
  LODWORD(multiplier) = this;
  this->pakSequenceIndex = 0;
  *(_DWORD *)&v33[12] = &std::_Func_impl<std::_Callable_obj<_lambda_4e6b98f2a357c503939cf32a3459a579_,0>,std::allocator<std::_Func_class<void,double const &>>,void,double const &>::`vftable';
  *(_DWORD *)&v33[16] = this;
  *(_DWORD *)&v33[28] = &v33[12];
  v19 = this->sim;
  LOBYTE(v45) = 40;
  Event<float>::addHandler(
    (Event<SessionInfo> *)&v19->physicsAvatar->engine.evOnStepCompleted,
    *(std::function<void __cdecl(SessionInfo const &)> *)&v33[12],
    (void *)LODWORD(multiplier));
  multiplier = 0.0;
  this->isTVMode = 0;
  std::wstring::wstring((std::wstring *)&v33[12], L"cfg/client.ini");
  INIReaderDocuments::INIReaderDocuments(&ini, (unsigned int)this, *(std::wstring *)&v33[12], SLOBYTE(multiplier));
  LOBYTE(v45) = 51;
  if ( ini.ready )
  {
    std::wstring::wstring(&filename, L"USE_TV_MODE");
    LOBYTE(v45) = 52;
    std::wstring::wstring(&key, L"CLIENT");
    LOBYTE(v45) = 53;
    v20 = INIReader::getInt(&ini, &key, &filename);
    v8 = key._Myres < 8;
    this->isTVMode = v20 != 0;
    if ( !v8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v45) = 51;
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
  }
  if ( this->useLog )
  {
    v21 = Path::getDocumentPath(&key);
    LOBYTE(v45) = 54;
    std::operator+<wchar_t>(&filename, v21, L"/Assetto Corsa/logs/aclient.log");
    LOBYTE(v45) = 56;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Bx._Buf[0] = 0;
    v22 = &filename;
    if ( filename._Myres >= 8 )
      v22 = (std::wstring *)filename._Bx._Ptr;
    key._Mysize = 0;
    v23 = std::wfilebuf::open((std::wfilebuf *)&this->log.gap0[4], v22->_Bx._Buf, 2, 64) == 0;
    v24 = *(_DWORD *)v6->gap0;
    multiplier = 0.0;
    v25 = *(_DWORD *)(v24 + 4);
    if ( v23 )
      std::wios::setstate((char *)v6 + v25, 2, LODWORD(multiplier));
    else
      std::wios::clear((char *)v6 + v25, 0, LODWORD(multiplier));
    LOBYTE(v45) = 51;
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
  }
  v26 = (ACClientVotingManager *)operator new(100);
  v35 = (ServerInfo *)v26;
  LOBYTE(v45) = 57;
  if ( v26 )
  {
    ACClientVotingManager::ACClientVotingManager(v26, this->sim, this);
    v28 = v27;
  }
  else
  {
    v28 = 0;
  }
  LOBYTE(v45) = 51;
  _Val[0] = v28;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, _Val);
  v28[9].__vftable = (ICollisionObject_vtbl *)this;
  LODWORD(multiplier) = 60;
  this->votingManager = (ACClientVotingManager *)v28;
  v29 = (QOSOverlay *)operator new(LODWORD(multiplier));
  v35 = (ServerInfo *)v29;
  LOBYTE(v45) = 58;
  if ( v29 )
  {
    QOSOverlay::QOSOverlay(v29, this);
    v31 = v30;
  }
  else
  {
    v31 = 0;
  }
  LOBYTE(v45) = 51;
  _Val[0] = v31;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, _Val);
  LODWORD(multiplier) = this;
  v31[9].__vftable = (ICollisionObject_vtbl *)this;
  *(_DWORD *)&v33[12] = &std::_Func_impl<std::_Callable_obj<_lambda_0b107ea97fe1b13b90339c7c22972ffe_,0>,std::allocator<std::_Func_class<void,OnMouseDownEvent const &>>,void,OnMouseDownEvent const &>::`vftable';
  *(_DWORD *)&v33[16] = this;
  *(_DWORD *)&v33[28] = &v33[12];
  v32 = &this->game->window.evOnMouseDown;
  LOBYTE(v45) = 51;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)v32,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)&v33[12],
    (void *)LODWORD(multiplier));
  LOBYTE(v45) = 40;
  INIReaderDocuments::~INIReaderDocuments(&ini);
  LOBYTE(v45) = 35;
  INIReader::~INIReader(&iniOptions);
  LOBYTE(v45) = 32;
  INIReader::~INIReader(&iniDebug);
}
void ACClient::~ACClient(ACClient *this)
{
  Font *v2; // esi
  std::vector<ClientCollisionEvent> *v3; // esi
  std::vector<unsigned int> *v4; // esi
  std::vector<Lap> *v5; // esi
  std::vector<unsigned int> *v6; // esi
  std::vector<unsigned int> *v7; // esi
  std::vector<unsigned int> *v8; // esi
  std::vector<RemoteSession> *v9; // esi
  std::vector<NetCarStateProvider *> *v10; // esi
  std::vector<std::vector<unsigned char>> *v11; // esi
  std::vector<unsigned char> *v12; // esi

  this->__vftable = (ACClient_vtbl *)&ACClient::`vftable';
  v2 = this->font;
  if ( v2 )
  {
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v2);
    operator delete(v2);
  }
  v3 = &this->clientColissionEvents;
  if ( this->clientColissionEvents._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->clientColissionEvents);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    this->clientColissionEvents._Mylast = 0;
    this->clientColissionEvents._Myend = 0;
  }
  std::wofstream::~wofstream<wchar_t,std::char_traits<wchar_t>>((std::wofstream *)&this->log.gap58[8]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&this->log.gap58[8]);
  if ( this->localCarLastLap.compound._Myres >= 8 )
    operator delete(this->localCarLastLap.compound._Bx._Ptr);
  this->localCarLastLap.compound._Myres = 7;
  this->localCarLastLap.compound._Mysize = 0;
  v4 = &this->localCarLastLap.splits;
  this->localCarLastLap.compound._Bx._Buf[0] = 0;
  if ( this->localCarLastLap.splits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->localCarLastLap.splits);
    operator delete(v4->_Myfirst);
    v4->_Myfirst = 0;
    this->localCarLastLap.splits._Mylast = 0;
    this->localCarLastLap.splits._Myend = 0;
  }
  v5 = &this->localCarLaps;
  if ( this->localCarLaps._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->localCarLaps);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(v5->_Myfirst, this->localCarLaps._Mylast);
    operator delete(v5->_Myfirst);
    v5->_Myfirst = 0;
    this->localCarLaps._Mylast = 0;
    this->localCarLaps._Myend = 0;
  }
  v6 = &this->bestSplits;
  if ( this->bestSplits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->bestSplits);
    operator delete(v6->_Myfirst);
    v6->_Myfirst = 0;
    this->bestSplits._Mylast = 0;
    this->bestSplits._Myend = 0;
  }
  v7 = &this->localCarBestSplits;
  if ( this->localCarBestSplits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->localCarBestSplits);
    operator delete(v7->_Myfirst);
    v7->_Myfirst = 0;
    this->localCarBestSplits._Mylast = 0;
    this->localCarBestSplits._Myend = 0;
  }
  v8 = &this->localCarCurrentSplits;
  if ( this->localCarCurrentSplits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->localCarCurrentSplits);
    operator delete(v8->_Myfirst);
    v8->_Myfirst = 0;
    this->localCarCurrentSplits._Mylast = 0;
    this->localCarCurrentSplits._Myend = 0;
  }
  if ( this->welcomeMessage._Myres >= 8 )
    operator delete(this->welcomeMessage._Bx._Ptr);
  this->welcomeMessage._Myres = 7;
  this->welcomeMessage._Mysize = 0;
  this->welcomeMessage._Bx._Buf[0] = 0;
  if ( this->dcCountdown.message._Myres >= 8 )
    operator delete(this->dcCountdown.message._Bx._Ptr);
  this->dcCountdown.message._Myres = 7;
  this->dcCountdown.message._Mysize = 0;
  v9 = &this->sessions;
  this->dcCountdown.message._Bx._Buf[0] = 0;
  if ( this->sessions._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->sessions);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<RemoteSession>>>(v9->_Myfirst, this->sessions._Mylast);
    operator delete(v9->_Myfirst);
    v9->_Myfirst = 0;
    this->sessions._Mylast = 0;
    this->sessions._Myend = 0;
  }
  if ( this->currentSession.name._Myres >= 8 )
    operator delete(this->currentSession.name._Bx._Ptr);
  this->currentSession.name._Myres = 7;
  this->currentSession.name._Mysize = 0;
  this->currentSession.name._Bx._Buf[0] = 0;
  TCPSocket::~TCPSocket(&this->tcpSock);
  v10 = &this->netCars;
  if ( this->netCars._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->netCars);
    operator delete(v10->_Myfirst);
    v10->_Myfirst = 0;
    this->netCars._Mylast = 0;
    this->netCars._Myend = 0;
  }
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->serverIP);
  v11 = &this->checksumResults;
  if ( this->checksumResults._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->checksumResults);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::vector<ReplayFrameWingStatus>>>>(
      v11->_Myfirst,
      this->checksumResults._Mylast);
    operator delete(v11->_Myfirst);
    v11->_Myfirst = 0;
    this->checksumResults._Mylast = 0;
    this->checksumResults._Myend = 0;
  }
  UDPSocket::~UDPSocket(&this->sok);
  RemoteSessionResult::~RemoteSessionResult(&this->sessionResultsGT);
  RemoteSessionResult::~RemoteSessionResult(&this->transitionInfo.sessionResume.results);
  if ( this->transitionInfo.sessionResume.session.name._Myres >= 8 )
    operator delete(this->transitionInfo.sessionResume.session.name._Bx._Ptr);
  this->transitionInfo.sessionResume.session.name._Myres = 7;
  this->transitionInfo.sessionResume.session.name._Mysize = 0;
  this->transitionInfo.sessionResume.session.name._Bx._Buf[0] = 0;
  UDPPacket::~UDPPacket(&this->transitionInfo.sessionPacket);
  v12 = &this->playerCarMD5;
  if ( this->playerCarMD5._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->playerCarMD5);
    operator delete(v12->_Myfirst);
    v12->_Myfirst = 0;
    this->playerCarMD5._Mylast = 0;
    this->playerCarMD5._Myend = 0;
  }
  if ( this->guid._Myres >= 8 )
    operator delete(this->guid._Bx._Ptr);
  this->guid._Myres = 7;
  this->guid._Mysize = 0;
  this->guid._Bx._Buf[0] = 0;
  if ( this->serverInfo.ip._Myres >= 8 )
    operator delete(this->serverInfo.ip._Bx._Ptr);
  this->serverInfo.ip._Myres = 7;
  this->serverInfo.ip._Mysize = 0;
  this->serverInfo.ip._Bx._Buf[0] = 0;
  if ( this->serverInfo.name._Myres >= 8 )
    operator delete(this->serverInfo.name._Bx._Ptr);
  this->serverInfo.name._Myres = 7;
  this->serverInfo.name._Mysize = 0;
  this->serverInfo.name._Bx._Buf[0] = 0;
  SetupItemText::~SetupItemText(&this->driverInfo);
  if ( this->serverName._Myres >= 8 )
    operator delete(this->serverName._Bx._Ptr);
  this->serverName._Myres = 7;
  this->serverName._Mysize = 0;
  this->serverName._Bx._Buf[0] = 0;
  if ( this->evOnMandatoryPitDone.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnMandatoryPitDone);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnMandatoryPitDone,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnMandatoryPitDone.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnMandatoryPitDone.handlers._Mylast);
    operator delete(this->evOnMandatoryPitDone.handlers._Myfirst);
    this->evOnMandatoryPitDone.handlers._Myfirst = 0;
    this->evOnMandatoryPitDone.handlers._Mylast = 0;
    this->evOnMandatoryPitDone.handlers._Myend = 0;
  }
  if ( this->evOnVoteNotPassed.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnVoteNotPassed);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnVoteNotPassed,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnVoteNotPassed.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnVoteNotPassed.handlers._Mylast);
    operator delete(this->evOnVoteNotPassed.handlers._Myfirst);
    this->evOnVoteNotPassed.handlers._Myfirst = 0;
    this->evOnVoteNotPassed.handlers._Mylast = 0;
    this->evOnVoteNotPassed.handlers._Myend = 0;
  }
  if ( this->evOnVoteReceived.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnVoteReceived);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnVoteReceived,
      (Task *)this->evOnVoteReceived.handlers._Myfirst,
      (Task *)this->evOnVoteReceived.handlers._Mylast);
    operator delete(this->evOnVoteReceived.handlers._Myfirst);
    this->evOnVoteReceived.handlers._Myfirst = 0;
    this->evOnVoteReceived.handlers._Mylast = 0;
    this->evOnVoteReceived.handlers._Myend = 0;
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
  if ( this->evOnOnlineEndSession.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnOnlineEndSession);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnOnlineEndSession,
      (Task *)this->evOnOnlineEndSession.handlers._Myfirst,
      (Task *)this->evOnOnlineEndSession.handlers._Mylast);
    operator delete(this->evOnOnlineEndSession.handlers._Myfirst);
    this->evOnOnlineEndSession.handlers._Myfirst = 0;
    this->evOnOnlineEndSession.handlers._Mylast = 0;
    this->evOnOnlineEndSession.handlers._Myend = 0;
  }
  if ( this->evOnOnlineNewSession.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnOnlineNewSession);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnOnlineNewSession,
      (Task *)this->evOnOnlineNewSession.handlers._Myfirst,
      (Task *)this->evOnOnlineNewSession.handlers._Mylast);
    operator delete(this->evOnOnlineNewSession.handlers._Myfirst);
    this->evOnOnlineNewSession.handlers._Myfirst = 0;
    this->evOnOnlineNewSession.handlers._Mylast = 0;
    this->evOnOnlineNewSession.handlers._Myend = 0;
  }
  if ( this->evOnChatMessage.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnChatMessage);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnChatMessage,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnChatMessage.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnChatMessage.handlers._Mylast);
    operator delete(this->evOnChatMessage.handlers._Myfirst);
    this->evOnChatMessage.handlers._Myfirst = 0;
    this->evOnChatMessage.handlers._Mylast = 0;
    this->evOnChatMessage.handlers._Myend = 0;
  }
  GameObject::~GameObject(this);
}
ACClient *ACClient::`scalar deleting destructor'(ACClient *this, unsigned int a2)
{
  ACClient::~ACClient(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void ACClient::addCollisionEvent(ACClient *this, NetCarStateProvider *netCar, float speed, const vec3f *worldPos, const vec3f *relPos)
{
  ClientCollisionEvent *v5; // eax
  std::vector<ClientCollisionEvent> *v6; // esi
  ClientCollisionEvent *v7; // ecx
  __int64 v8; // xmm0_8
  __int64 v9; // xmm0_8
  int v10; // edi
  __m128i *v11; // eax
  const __m128i *v12; // edi
  __m128i *v13; // eax
  ClientCollisionEvent ev; // [esp+4h] [ebp-20h] BYREF

  v5 = this->clientColissionEvents._Myfirst;
  v6 = &this->clientColissionEvents;
  v7 = this->clientColissionEvents._Mylast;
  if ( v5 == v7 )
  {
LABEL_4:
    ev.netCar = netCar;
    v8 = *(_QWORD *)&relPos->x;
    ev.relPos.z = relPos->z;
    *(_QWORD *)&ev.relPos.x = v8;
    v9 = *(_QWORD *)&worldPos->x;
    ev.worldPos.z = worldPos->z;
    *(_QWORD *)&ev.worldPos.x = v9;
    ev.speed = speed;
    if ( &ev >= v7 || v6->_Myfirst > &ev )
    {
      if ( v7 == v6->_Myend )
        std::vector<ClientCollisionEvent>::_Reserve(v6, 1u);
      v13 = (__m128i *)v6->_Mylast;
      if ( v13 )
      {
        *v13 = _mm_loadu_si128((const __m128i *)&ev);
        v13[1] = _mm_loadu_si128((const __m128i *)&ev.worldPos.z);
      }
      ++v6->_Mylast;
    }
    else
    {
      v10 = (char *)&ev - (char *)v6->_Myfirst;
      if ( v7 == v6->_Myend )
        std::vector<ClientCollisionEvent>::_Reserve(v6, 1u);
      v11 = (__m128i *)v6->_Mylast;
      v12 = (const __m128i *)((char *)v6->_Myfirst + (v10 & 0xFFFFFFE0));
      if ( v11 )
      {
        *v11 = _mm_loadu_si128(v12);
        v11[1] = _mm_loadu_si128(v12 + 1);
      }
      ++v6->_Mylast;
    }
  }
  else
  {
    while ( v5->netCar != netCar )
    {
      if ( ++v5 == v7 )
        goto LABEL_4;
    }
    if ( speed > v5->speed )
    {
      v5->speed = speed;
      v5->relPos = *relPos;
      v5->worldPos = *worldPos;
    }
  }
}
void ACClient::addNetCar(ACClient *this, NetCarStateProvider *nc)
{
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->netCars,
    (ICollisionObject *const *)&nc);
}
void ACClient::addSplitToBest(ACClient *this, std::vector<unsigned int> *splits, std::vector<unsigned int> *personalSplits, const unsigned int *sector, const unsigned int *time, const unsigned int *cuts)
{
  unsigned int v7; // eax
  unsigned int *v8; // eax
  int v9; // edi
  unsigned int *v10; // ecx
  unsigned int *v11; // eax
  unsigned int *v12; // eax
  unsigned int v13; // ecx
  unsigned int *v14; // ebx
  unsigned int v15; // edi
  unsigned int v16; // edx
  unsigned int v17; // esi
  int v18; // [esp+10h] [ebp-4h] BYREF

  v7 = splits->_Mylast - splits->_Myfirst;
  if ( *sector >= v7 )
  {
    if ( *sector != v7 )
    {
      v18 = 0;
      do
      {
        v8 = splits->_Mylast;
        if ( &v18 >= (int *)v8 || splits->_Myfirst > (unsigned int *)&v18 )
        {
          if ( v8 == splits->_Myend )
            std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)splits, 1u);
          v11 = splits->_Mylast;
          if ( v11 )
            *v11 = 0;
        }
        else
        {
          v9 = ((char *)&v18 - (char *)splits->_Myfirst) >> 2;
          if ( v8 == splits->_Myend )
            std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)splits, 1u);
          v10 = splits->_Mylast;
          if ( v10 )
            *v10 = splits->_Myfirst[v9];
        }
        ++splits->_Mylast;
      }
      while ( *sector != splits->_Mylast - splits->_Myfirst );
    }
    std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)splits, (ICollisionObject *const *)time);
  }
  else
  {
    splits->_Myfirst[*sector] = *time;
  }
  if ( !*cuts )
  {
    v12 = this->bestSplits._Myfirst;
    if ( v12 != this->bestSplits._Mylast )
    {
      v13 = *sector;
      v14 = this->bestSplits._Myfirst;
      v15 = v12[*sector];
      if ( v15 && (v16 = splits->_Myfirst[v13], v15 <= v16) )
      {
        v17 = personalSplits->_Myfirst[v13];
        if ( !v17 || v17 > v16 )
          personalSplits->_Myfirst[v13] = v16;
      }
      else
      {
        v14[v13] = splits->_Myfirst[v13];
        personalSplits->_Myfirst[*sector] = splits->_Myfirst[*sector];
      }
    }
  }
}
void ACClient::askForP2Pvalue(ACClient *this)
{
  UDPPacket pak; // [esp+8h] [ebp-2Ch] BYREF
  int v3; // [esp+30h] [ebp-4h]

  _printf("ASK ACP_CE_P2P For Value \n");
  UDPPacket::UDPPacket(&pak);
  v3 = 0;
  pak.data[pak.size] = 13;
  *(_WORD *)&pak.data[++pak.size] = -1;
  pak.size += 2;
  pak.data[pak.size++] = 0;
  UDPPacket::send(&pak, &this->tcpSock);
  v3 = -1;
  UDPPacket::~UDPPacket(&pak);
}
void ACClient::associate(ACClient *this)
{
  IPAddress v2; // xmm0
  unsigned __int8 v3; // cl
  UDPPacket pak; // [esp+8h] [ebp-2Ch] BYREF
  int v5; // [esp+30h] [ebp-4h]

  UDPPacket::UDPPacket(&pak);
  v2 = (IPAddress)_mm_loadu_si128((const __m128i *)&this->serverIP);
  v5 = 0;
  pak.targetIP = v2;
  pak.data[pak.size] = 78;
  v3 = this->sessionID;
  pak.data[++pak.size] = v3;
  ++pak.size;
  UDPPacket::send(&pak, &this->sok);
  v5 = -1;
  UDPPacket::~UDPPacket(&pak);
}
void ACClient::beginUpdateMode(ACClient *this)
{
  Event<double> *v2; // ecx
  Event<std::pair<int,int> > *v3; // ecx
  _BYTE v4[56]; // [esp-1Ch] [ebp-4Ch] BYREF
  int v5; // [esp+2Ch] [ebp-4h]

  *(_DWORD *)&v4[4] = &std::_Func_impl<std::_Callable_obj<_lambda_72d6c208b2f588c7f596fbc6b848f281_,0>,std::allocator<std::_Func_class<void,UDPMessage const &>>,void,UDPMessage const &>::`vftable';
  *(_DWORD *)&v4[8] = this;
  *(_DWORD *)&v4[20] = &v4[4];
  v5 = -1;
  UDPSocket::addListener(&this->sok, *(std::function<void __cdecl(UDPMessage const &)> *)&v4[4]);
  TCPSocket::setBlockingMode(&this->tcpSock, 0);
  *(_DWORD *)&v4[4] = &std::_Func_impl<std::_Callable_obj<_lambda_ae6852c6929ac58c83df49ac0fd41c69_,0>,std::allocator<std::_Func_class<void,UDPMessage const &>>,void,UDPMessage const &>::`vftable';
  *(_DWORD *)&v4[8] = this;
  *(_DWORD *)&v4[20] = &v4[4];
  v5 = -1;
  TCPSocket::addListener(&this->tcpSock, *(std::function<void __cdecl(UDPMessage const &)> *)&v4[4]);
  *(_DWORD *)&v4[24] = this;
  *(_DWORD *)v4 = &std::_Func_impl<std::_Callable_obj<_lambda_741d07ea55c671ad6a5e98e2316ddd25_,0>,std::allocator<std::_Func_class<void,double const &>>,void,double const &>::`vftable';
  *(_DWORD *)&v4[4] = this;
  *(_DWORD *)&v4[16] = v4;
  v2 = &this->car->evOnJumpStartEvent;
  v5 = -1;
  Event<float>::addHandler((Event<SessionInfo> *)v2, *(std::function<void __cdecl(SessionInfo const &)> *)v4, this);
  *(_DWORD *)&v4[24] = this;
  *(_DWORD *)v4 = &std::_Func_impl<std::_Callable_obj<_lambda_756b393c455025f826bc8e9c32383614_,0>,std::allocator<std::_Func_class<void,std::pair<int,int> const &>>,void,std::pair<int,int> const &>::`vftable';
  *(_DWORD *)&v4[4] = this;
  *(_DWORD *)&v4[16] = v4;
  v3 = &this->car->evOnPush2Pass;
  v5 = -1;
  Event<float>::addHandler((Event<SessionInfo> *)v3, *(std::function<void __cdecl(SessionInfo const &)> *)v4, this);
  *(_DWORD *)v4 = &std::_Func_impl<std::_Callable_obj<_lambda_de388cf18b7af9d57af7ae36b67c897e_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
  *(_DWORD *)&v4[4] = this;
  *(_DWORD *)&v4[16] = v4;
  v5 = -1;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&this->evOnMandatoryPitDone,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)v4,
    this);
}
unsigned int ACClient::getBestLap(ACClient *this, CarAvatar *car)
{
  int v2; // esi
  NetCarStateProvider **v3; // ebx
  NetCarStateProvider **i; // edx

  v2 = 0;
  if ( !(this->netCars._Mylast - this->netCars._Myfirst) )
    return this->localCarBestLap;
  v3 = this->netCars._Myfirst;
  for ( i = v3; (*i)->avatar != car; ++i )
  {
    if ( ++v2 >= (unsigned int)(this->netCars._Mylast - v3) )
      return this->localCarBestLap;
  }
  return v3[v2]->bestLap;
}
unsigned int ACClient::getBestSplit(ACClient *this, const int *sector, const bool *isGlobal, CarAvatar *car)
{
  char v6; // al
  NetCarStateProvider **v7; // ecx
  NetCarStateProvider **v8; // edx
  NetCarStateProvider *v9; // esi

  if ( *isGlobal )
    return this->bestSplits._Myfirst[*sector];
  if ( CarAvatar::getGuid(car) )
  {
    v6 = ACClient::getSessionIDFromCarAvatar(this, car);
    v7 = this->netCars._Myfirst;
    v8 = this->netCars._Mylast;
    if ( v7 == v8 )
    {
LABEL_9:
      v9 = 0;
    }
    else
    {
      while ( 1 )
      {
        v9 = *v7;
        if ( (*v7)->sessionID == v6 )
          break;
        if ( ++v7 == v8 )
          goto LABEL_9;
      }
    }
    if ( *sector < (unsigned int)(v9->personalBestSplits._Mylast - v9->personalBestSplits._Myfirst) )
      return v9->personalBestSplits._Myfirst[*sector];
  }
  else if ( *sector < (unsigned int)(this->localCarBestSplits._Mylast - this->localCarBestSplits._Myfirst) )
  {
    return this->localCarBestSplits._Myfirst[*sector];
  }
  return 0;
}
CarAvatar *ACClient::getCarAvatarFromSessionID(ACClient *this, unsigned __int8 sesid)
{
  CarAvatar *result; // eax
  NetCarStateProvider **v3; // eax
  NetCarStateProvider **v4; // ecx

  if ( sesid == this->sessionID )
    return Sim::getCar(this->sim, 0);
  v3 = this->netCars._Myfirst;
  v4 = this->netCars._Mylast;
  if ( v3 == v4 )
  {
LABEL_6:
    _printf("ERROR: Cannot find car with sessionID: %d\n", sesid);
    result = 0;
  }
  else
  {
    while ( (*v3)->sessionID != sesid )
    {
      if ( ++v3 == v4 )
        goto LABEL_6;
    }
    result = (*v3)->avatar;
  }
  return result;
}
std::vector<unsigned char> *__userpurge ACClient::getCarMD5@<eax>(ACClient *this@<ecx>, unsigned int a2@<ebx>, std::vector<unsigned char> *result, const std::wstring *unix_name)
{
  std::wstring *v4; // eax
  std::wstring *v5; // eax
  std::wstring acdPath; // [esp+10h] [ebp-70h] BYREF
  std::wstring folderPath; // [esp+28h] [ebp-58h] BYREF
  std::wstring v9; // [esp+40h] [ebp-40h] BYREF
  std::wstring v10; // [esp+58h] [ebp-28h] BYREF
  int v11; // [esp+7Ch] [ebp-4h]

  v4 = std::operator+<wchar_t>(&v9, L"content/cars/", unix_name);
  v11 = 0;
  std::operator+<wchar_t>(&acdPath, v4, L"/data.acd");
  LOBYTE(v11) = 2;
  if ( v9._Myres >= 8 )
    operator delete(v9._Bx._Ptr);
  v9._Myres = 7;
  v9._Bx._Buf[0] = 0;
  v9._Mysize = 0;
  if ( Path::fileExists(a2, &acdPath, 0) )
  {
    md5(result, &acdPath);
  }
  else
  {
    v5 = std::operator+<wchar_t>(&v10, L"content/cars/", unix_name);
    LOBYTE(v11) = 3;
    std::operator+<wchar_t>(&folderPath, v5, L"/data/");
    LOBYTE(v11) = 5;
    if ( v10._Myres >= 8 )
      operator delete(v10._Bx._Ptr);
    v10._Myres = 7;
    v10._Bx._Buf[0] = 0;
    v10._Mysize = 0;
    md5Folder(result, &folderPath);
    if ( folderPath._Myres >= 8 )
      operator delete(folderPath._Bx._Ptr);
    folderPath._Myres = 7;
    folderPath._Mysize = 0;
    folderPath._Bx._Buf[0] = 0;
  }
  if ( acdPath._Myres >= 8 )
    operator delete(acdPath._Bx._Ptr);
  return result;
}
unsigned int ACClient::getCarPosition(ACClient *this, CarAvatar *car)
{
  int v3; // ebp
  int v4; // ebx
  int *v5; // edi
  CarAvatar *v6; // eax

  v3 = 0;
  v4 = 0;
  if ( !(this->sessionResultsGT.positions._Mylast - this->sessionResultsGT.positions._Myfirst) )
    return 0;
  while ( 1 )
  {
    v5 = &this->sessionResultsGT.positions._Myfirst[v4];
    if ( *v5 == CarAvatar::getGuid(car) )
      break;
    v6 = Sim::getCar(this->sim, this->sessionResultsGT.positions._Myfirst[v4]);
    if ( CarAvatar::isConnected(v6) )
      ++v3;
    if ( ++v4 >= (unsigned int)(this->sessionResultsGT.positions._Mylast - this->sessionResultsGT.positions._Myfirst) )
      return 0;
  }
  return v3 + 1;
}
Lap *ACClient::getCurrentLap(ACClient *this, Lap *result, CarAvatar *car)
{
  char v4; // al
  NetCarStateProvider **v5; // ecx
  char v6; // bl
  NetCarStateProvider **v7; // edx
  NetCarStateProvider *v8; // eax

  result->splits._Myfirst = 0;
  result->splits._Mylast = 0;
  result->splits._Myend = 0;
  result->compound._Myres = 7;
  result->compound._Mysize = 0;
  result->compound._Bx._Buf[0] = 0;
  result->time = 0;
  result->isValid = 0;
  result->cuts = 0;
  if ( CarAvatar::getGuid(car) )
  {
    v4 = ACClient::getSessionIDFromCarAvatar(this, car);
    v5 = this->netCars._Myfirst;
    v6 = v4;
    v7 = this->netCars._Mylast;
    if ( v5 == v7 )
    {
LABEL_6:
      v8 = 0;
    }
    else
    {
      while ( 1 )
      {
        v8 = *v5;
        if ( (*v5)->sessionID == v6 )
          break;
        if ( ++v5 == v7 )
          goto LABEL_6;
      }
    }
    std::vector<int>::operator=(&result->splits, &v8->currentSplits);
  }
  else
  {
    result->time = car->physicsState.lapTime;
    std::vector<int>::operator=(&result->splits, &this->localCarCurrentSplits);
  }
  return result;
}
RemoteSession *ACClient::getCurrentSession(ACClient *this, RemoteSession *result)
{
  RemoteSession *v2; // esi
  RemoteSession *v3; // eax

  v2 = &this->currentSession;
  result->name._Myres = 7;
  result->name._Mysize = 0;
  result->name._Bx._Buf[0] = 0;
  std::wstring::assign(&result->name, &this->currentSession.name, 0, 0xFFFFFFFF);
  result->type = v2->type;
  result->index = v2->index;
  result->time = v2->time;
  v3 = result;
  result->laps = v2->laps;
  result->startTime = v2->startTime;
  result->isSpectator = v2->isSpectator;
  result->isTimedRace = v2->isTimedRace;
  result->hasExtraLap = v2->hasExtraLap;
  return v3;
}
int ACClient::getCurrentSessionIndex(ACClient *this)
{
  int v1; // edi
  SessionType *i; // esi

  v1 = 0;
  if ( !(this->sessions._Mylast - this->sessions._Myfirst) )
    return 0;
  for ( i = &this->sessions._Myfirst->type; this->currentSession.type != *i; i += 14 )
  {
    if ( ++v1 >= (unsigned int)(this->sessions._Mylast - this->sessions._Myfirst) )
      return 0;
  }
  return v1;
}
RemoteSessionResult *ACClient::getCurrentSessionResults(ACClient *this)
{
  return &this->sessionResultsGT;
}
VoteType ACClient::getCurrentVoteType(ACClient *this)
{
  return this->votingManager->currentVote.voteType;
}
CarAvatar *ACClient::getCurrentVotingTarget(ACClient *this)
{
  return this->votingManager->currentVote.target;
}
unsigned int ACClient::getInstanceBestLap(ACClient *this, CarAvatar *car)
{
  int v2; // esi
  NetCarStateProvider **v3; // ebx
  NetCarStateProvider **i; // edx

  v2 = 0;
  if ( !(this->netCars._Mylast - this->netCars._Myfirst) )
    return this->instanceLocalCarBestLap;
  v3 = this->netCars._Myfirst;
  for ( i = v3; (*i)->avatar != car; ++i )
  {
    if ( ++v2 >= (unsigned int)(this->netCars._Mylast - v3) )
      return this->instanceLocalCarBestLap;
  }
  return v3[v2]->bestLap;
}
int ACClient::getLapCount(ACClient *this, CarAvatar *car)
{
  unsigned int v3; // esi
  NetCarStateProvider **v4; // ebx
  NetCarStateProvider **v5; // ecx
  int v6; // ecx

  v3 = 0;
  if ( this->netCars._Mylast - this->netCars._Myfirst )
  {
    v4 = this->netCars._Myfirst;
    v5 = v4;
    while ( (*v5)->avatar != car )
    {
      ++v3;
      ++v5;
      if ( v3 >= this->netCars._Mylast - v4 )
        goto LABEL_5;
    }
    v6 = (char *)v4[v3]->laps._Mylast - (char *)v4[v3]->laps._Myfirst;
  }
  else
  {
LABEL_5:
    v6 = (char *)this->localCarLaps._Mylast - (char *)this->localCarLaps._Myfirst;
  }
  return v6 / 48;
}
void ACClient::getLaps(ACClient *this, CarAvatar *car, std::vector<Lap> *laps)
{
  unsigned int v4; // edi
  NetCarStateProvider **v5; // esi
  NetCarStateProvider **v6; // ecx
  Lap *v7; // esi
  Lap *j; // edi
  NetCarStateProvider *v9; // edi
  Lap *v10; // esi
  Lap *i; // edi
  Lap ui; // [esp+1Ch] [ebp-70h] BYREF
  Lap _Val; // [esp+4Ch] [ebp-40h] BYREF
  int v14; // [esp+88h] [ebp-4h]

  std::_Container_base0::_Orphan_all(laps);
  std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(laps->_Myfirst, laps->_Mylast);
  laps->_Mylast = laps->_Myfirst;
  v4 = 0;
  if ( this->netCars._Mylast - this->netCars._Myfirst )
  {
    v5 = this->netCars._Myfirst;
    v6 = v5;
    while ( (*v6)->avatar != car )
    {
      ++v4;
      ++v6;
      if ( v4 >= this->netCars._Mylast - v5 )
        goto LABEL_5;
    }
    v9 = v5[v4];
    v10 = v9->laps._Myfirst;
    for ( i = v9->laps._Mylast; v10 != i; ++v10 )
    {
      ui.time = v10->time;
      std::vector<Mesh *>::vector<Mesh *>(
        (std::vector<TyreThermalPatch *> *)&ui.splits,
        (const std::vector<TyreThermalPatch *> *)&v10->splits);
      ui.cuts = v10->cuts;
      ui.isValid = v10->isValid;
      ui.compound._Bx._Buf[0] = 0;
      v14 = 0;
      ui.compound._Myres = 7;
      ui.compound._Mysize = 0;
      std::wstring::assign(&ui.compound, &v10->compound, 0, 0xFFFFFFFF);
      v14 = 1;
      std::vector<Lap>::push_back(laps, &ui);
      v14 = -1;
      if ( ui.compound._Myres >= 8 )
        operator delete(ui.compound._Bx._Ptr);
      ui.compound._Myres = 7;
      ui.compound._Mysize = 0;
      ui.compound._Bx._Buf[0] = 0;
      if ( ui.splits._Myfirst )
      {
        std::_Container_base0::_Orphan_all(&ui.splits);
        operator delete(ui.splits._Myfirst);
      }
    }
  }
  else
  {
LABEL_5:
    v7 = this->localCarLaps._Myfirst;
    for ( j = this->localCarLaps._Mylast; v7 != j; ++v7 )
    {
      _Val.time = v7->time;
      std::vector<Mesh *>::vector<Mesh *>(
        (std::vector<TyreThermalPatch *> *)&_Val.splits,
        (const std::vector<TyreThermalPatch *> *)&v7->splits);
      _Val.cuts = v7->cuts;
      _Val.isValid = v7->isValid;
      _Val.compound._Bx._Buf[0] = 0;
      v14 = 2;
      _Val.compound._Myres = 7;
      _Val.compound._Mysize = 0;
      std::wstring::assign(&_Val.compound, &v7->compound, 0, 0xFFFFFFFF);
      v14 = 3;
      std::vector<Lap>::push_back(laps, &_Val);
      v14 = -1;
      if ( _Val.compound._Myres >= 8 )
        operator delete(_Val.compound._Bx._Ptr);
      _Val.compound._Myres = 7;
      _Val.compound._Mysize = 0;
      _Val.compound._Bx._Buf[0] = 0;
      if ( _Val.splits._Myfirst )
      {
        std::_Container_base0::_Orphan_all(&_Val.splits);
        operator delete(_Val.splits._Myfirst);
      }
    }
  }
}
Lap *ACClient::getLastLap(ACClient *this, Lap *result, CarAvatar *car)
{
  NetCarStateProvider **v3; // eax
  NetCarStateProvider **v4; // edx
  NetCarStateProvider *v5; // esi
  Lap *v6; // esi
  Lap *v7; // edi
  Lap *v8; // eax

  v3 = this->netCars._Myfirst;
  v4 = this->netCars._Mylast;
  if ( v3 == v4 )
  {
LABEL_4:
    if ( this->localCarLaps._Myfirst != this->localCarLaps._Mylast )
    {
      v6 = this->localCarLaps._Mylast;
      v7 = result;
      result->time = v6[-1].time;
      std::vector<Mesh *>::vector<Mesh *>(
        (std::vector<TyreThermalPatch *> *)&result->splits,
        (const std::vector<TyreThermalPatch *> *)&v6[-1].splits);
LABEL_6:
      v7->cuts = v6[-1].cuts;
      v7->isValid = v6[-1].isValid;
      v7->compound._Myres = 7;
      v7->compound._Mysize = 0;
      v7->compound._Bx._Buf[0] = 0;
      std::wstring::assign(&v7->compound, &v6[-1].compound, 0, 0xFFFFFFFF);
      return v7;
    }
  }
  else
  {
    while ( 1 )
    {
      v5 = *v3;
      if ( (*v3)->avatar == car )
        break;
      if ( ++v3 == v4 )
        goto LABEL_4;
    }
    if ( v5->laps._Myfirst != v5->laps._Mylast )
    {
      v6 = v5->laps._Mylast;
      v7 = result;
      result->time = v6[-1].time;
      std::vector<Mesh *>::vector<Mesh *>(
        (std::vector<TyreThermalPatch *> *)&result->splits,
        (const std::vector<TyreThermalPatch *> *)&v6[-1].splits);
      goto LABEL_6;
    }
  }
  v8 = result;
  result->splits._Myfirst = 0;
  result->splits._Mylast = 0;
  result->splits._Myend = 0;
  result->compound._Myres = 7;
  result->compound._Mysize = 0;
  result->compound._Bx._Buf[0] = 0;
  result->isValid = 1;
  result->cuts = 0;
  result->time = 0;
  return v8;
}
unsigned int ACClient::getLastSplit(ACClient *this, CarAvatar *car, const int *sector)
{
  unsigned int *v3; // ecx
  unsigned int v4; // esi
  Lap l; // [esp+4h] [ebp-34h] BYREF

  ACClient::getLastLap(this, &l, car);
  v3 = l.splits._Myfirst;
  if ( *sector >= (unsigned int)(l.splits._Mylast - l.splits._Myfirst) )
    v4 = 0;
  else
    v4 = l.splits._Myfirst[*sector];
  if ( l.compound._Myres >= 8 )
  {
    operator delete(l.compound._Bx._Ptr);
    v3 = l.splits._Myfirst;
  }
  l.compound._Myres = 7;
  l.compound._Mysize = 0;
  l.compound._Bx._Buf[0] = 0;
  if ( v3 )
  {
    std::_Container_base0::_Orphan_all(&l.splits);
    operator delete(l.splits._Myfirst);
  }
  return v4;
}
NetCarStateProvider *ACClient::getNetCarFromSessionID(ACClient *this, unsigned __int8 id)
{
  NetCarStateProvider **v2; // eax
  NetCarStateProvider **v3; // ecx

  v2 = this->netCars._Myfirst;
  v3 = this->netCars._Mylast;
  if ( v2 == v3 )
    return 0;
  while ( (*v2)->sessionID != id )
  {
    if ( ++v2 == v3 )
      return 0;
  }
  return *v2;
}
long double ACClient::getPhysicsTime(ACClient *this)
{
  return this->sim->physicsAvatar->engine.physicsTime;
}
int ACClient::getPing(ACClient *this, CarAvatar *anAvatar)
{
  NetCarStateProvider **v2; // eax
  NetCarStateProvider **v3; // ecx

  if ( anAvatar == this->avatar || !anAvatar )
    return this->sok.ping;
  v2 = this->netCars._Myfirst;
  v3 = this->netCars._Mylast;
  if ( v2 == v3 )
    return 0;
  while ( (*v2)->avatar != anAvatar )
  {
    if ( ++v2 == v3 )
      return 0;
  }
  return (*v2)->ping;
}
char ACClient::getRemoteCarList(ACClient *this, std::vector<ClientRemoteCarDef> *remoteCars)
{
  int v3; // esi
  unsigned __int8 v4; // bh
  std::wostream *v5; // eax
  std::wostream *v6; // eax
  const std::wstring *v7; // eax
  Sim *v8; // ecx
  std::wstring *v9; // eax
  const std::wstring *v10; // eax
  unsigned __int8 v11; // bl
  std::wstring *v12; // eax
  const std::wstring *v13; // eax
  unsigned __int8 v14; // bl
  std::wstring *v15; // eax
  const std::wstring *v16; // eax
  int v17; // ebx
  std::wstring *v18; // eax
  std::wostream *v19; // eax
  std::wostream *v20; // eax
  const std::wstring *v21; // eax
  const std::wstring *v22; // eax
  Sim *v23; // ecx
  const std::string *v24; // eax
  ClientRemoteCarDef *v25; // esi
  ClientRemoteCarDef *v26; // ecx
  ClientRemoteCarDef *v27; // ebx
  wchar_t *v28; // eax
  ClientRemoteCarDef *v29; // ecx
  const std::string *v30; // eax
  ClientRemoteCarDef *v31; // esi
  const std::string *v32; // eax
  ClientRemoteCarDef *v33; // esi
  const std::string *v34; // eax
  ClientRemoteCarDef *v35; // esi
  const std::string *v36; // eax
  ClientRemoteCarDef *v37; // esi
  bool v38; // bl
  int i; // esi
  float v40; // xmm0_4
  std::wstring *v41; // ecx
  std::wstring *v42; // eax
  std::wstring *v43; // esi
  std::wstring *v44; // eax
  std::wstring *v45; // eax
  std::wstring *v46; // eax
  std::wstring *v47; // eax
  std::wstring *v48; // eax
  std::wstring *v49; // eax
  std::wstring *v50; // eax
  std::wstring *v51; // eax
  std::wstring *v52; // eax
  std::wstring *v53; // eax
  const std::wstring *v54; // eax
  Sim *v55; // ecx
  std::wostream *v56; // eax
  std::wostream *v57; // eax
  std::wostream *v58; // eax
  std::wstring *v59; // eax
  const std::wstring *v60; // eax
  std::allocator<wchar_t> *v61; // eax
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > *v62; // ecx
  Sim *v63; // ecx
  std::wostream *v64; // eax
  std::wostream *v65; // eax
  std::wstring *v66; // eax
  std::wstring *v67; // eax
  const std::wstring *v68; // eax
  Sim *v70; // ecx
  std::wstring *v71; // eax
  std::wstring *v72; // eax
  const std::wstring *v73; // eax
  const char *v74; // [esp+Ch] [ebp-524h]
  wchar_t *v75; // [esp+10h] [ebp-520h]
  const char *v76; // [esp+14h] [ebp-51Ch]
  unsigned int v77; // [esp+14h] [ebp-51Ch]
  char v78; // [esp+31h] [ebp-4FFh]
  char v79; // [esp+32h] [ebp-4FEh]
  std::vector<unsigned char> ret; // [esp+34h] [ebp-4FCh] BYREF
  int v81; // [esp+40h] [ebp-4F0h] BYREF
  int v82; // [esp+44h] [ebp-4ECh]
  int v83; // [esp+48h] [ebp-4E8h]
  int v84; // [esp+4Ch] [ebp-4E4h]
  std::vector<ClientRemoteCarDef> *v85; // [esp+50h] [ebp-4E0h]
  int v86; // [esp+54h] [ebp-4DCh]
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v87; // [esp+58h] [ebp-4D8h] BYREF
  float v88; // [esp+5Ch] [ebp-4D4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v89; // [esp+60h] [ebp-4D0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v90; // [esp+110h] [ebp-420h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > ss2; // [esp+1C0h] [ebp-370h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v92; // [esp+270h] [ebp-2C0h] BYREF
  ClientRemoteCarDef rc; // [esp+320h] [ebp-210h] BYREF
  std::wstring v94; // [esp+3C8h] [ebp-168h] BYREF
  std::wstring result; // [esp+3E0h] [ebp-150h] BYREF
  std::wstring msg; // [esp+3F8h] [ebp-138h] BYREF
  _BYTE rpak[56]; // [esp+410h] [ebp-120h] OVERLAPPED BYREF
  std::wstring v98; // [esp+448h] [ebp-E8h] BYREF
  std::wstring v99; // [esp+460h] [ebp-D0h] BYREF
  std::wstring v100; // [esp+478h] [ebp-B8h] BYREF
  std::wstring v101; // [esp+490h] [ebp-A0h] BYREF
  std::wstring v102; // [esp+4A8h] [ebp-88h] BYREF
  std::wstring v103; // [esp+4C0h] [ebp-70h] BYREF
  std::wstring v104; // [esp+4D8h] [ebp-58h] BYREF
  std::wstring v105; // [esp+4F0h] [ebp-40h] BYREF
  std::wstring v106; // [esp+508h] [ebp-28h] BYREF
  int v107; // [esp+528h] [ebp-8h]
  int v108; // [esp+52Ch] [ebp-4h]
  void *retaddr; // [esp+530h] [ebp+0h]

  v3 = 0;
  v84 = 0;
  v4 = 0;
  v85 = remoteCars;
  v78 = 0;
  while ( 1 )
  {
    *(_DWORD *)v89.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v89.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v89.gap68);
    retaddr = 0;
    v85 = (std::vector<ClientRemoteCarDef> *)(v3 | 1);
    std::wiostream::basic_iostream<wchar_t>(&v89.gap0[4], &v89.gap10[12], 0);
    v107 = 1;
    *(_DWORD *)((char *)&v88 + *(_DWORD *)(LODWORD(v88) + 4)) = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(const wchar_t **)((char *)&v87._Ptr + *(_DWORD *)(LODWORD(v88) + 4)) = (const wchar_t *)(*(_DWORD *)(LODWORD(v88) + 4)
                                                                                             - 104);
    std::wstreambuf::wstreambuf(&v89.gap10[4]);
    *(_DWORD *)&v89.gap10[4] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v89.gap10[60] = 0;
    *(_DWORD *)&v89.gap10[64] = 0;
    v107 = 3;
    UDPPacket::UDPPacket((UDPPacket *)&rpak[24]);
    *(__m128i *)&rpak[24] = _mm_loadu_si128((const __m128i *)&this->serverIP);
    *(_BYTE *)(*(_DWORD *)&rpak[48] + *(_DWORD *)&rpak[40]) = 63;
    ++*(_DWORD *)&rpak[48];
    LOBYTE(v107) = 4;
    v82 = v4;
    v5 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(
           (std::wostream *)((char *)&v89._Chcount + 4),
           "requesting car list (");
    v6 = (std::wostream *)std::wostream::operator<<(v5, v4);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v6, v76);
    v7 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v89, &result);
    v8 = this->sim;
    LOBYTE(v108) = 5;
    Sim::setSplashMessage(v8, v7);
    LOBYTE(v108) = 4;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    *(_BYTE *)(*(_DWORD *)&rpak[52] + *(_DWORD *)&rpak[44]) = v4;
    ++*(_DWORD *)&rpak[52];
    v9 = std::to_wstring(&result, v4);
    LOBYTE(v108) = 6;
    v10 = std::operator+<wchar_t>(&v94, L"SENDING CAR LIST REQUEST:", v9);
    LOBYTE(v108) = 7;
    ACClient::logMessage(this, v10);
    if ( v94._Myres >= 8 )
      operator delete(v94._Bx._Ptr);
    v94._Myres = 7;
    v94._Mysize = 0;
    v94._Bx._Buf[0] = 0;
    LOBYTE(v108) = 4;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    UDPPacket::send((UDPPacket *)&rpak[28], &this->tcpSock);
    TCPSocket::receivePacket(&this->tcpSock, &ret);
    LOBYTE(v108) = 8;
    if ( ret._Myfirst == ret._Mylast )
    {
      std::wstring::wstring(&msg, L"TIMED OUT");
      LOBYTE(v108) = 45;
      ACClient::logMessage(this, &msg);
      LOBYTE(v108) = 8;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&msg);
      std::wstring::wstring(&result, L"Requesting car list timed out");
      v70 = this->sim;
      LOBYTE(v108) = 46;
      Sim::setSplashMessage(v70, &result);
      LOBYTE(v108) = 8;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      ksSleep(1000);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v92,
        3,
        1);
      LOBYTE(v108) = 47;
      std::operator<<<wchar_t,std::char_traits<wchar_t>>(
        (std::wostream *)v92.gap10,
        "ACCLIENT ERROR: TIMEDOUT WAITING FOR ACP_CAR_LIST_RESPONSE");
      v71 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v92, &v99);
      v72 = std::wstring::c_str(v71);
      _printf("ERROR: %S\n", v72->_Bx._Buf);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v99);
      v73 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v92, &v98);
      LOBYTE(v108) = 48;
      ACClient::logMessage(this, v73);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v98);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v92);
      std::vector<LeaderboardEntry>::_Tidy((std::vector<vec3f> *)&ret);
      LOBYTE(v108) = 3;
      UDPPacket::~UDPPacket((UDPPacket *)&rpak[28]);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v89);
      return 0;
    }
    UDPPacket::UDPPacket((UDPPacket *)rpak, &ret);
    LOBYTE(v108) = 9;
    v11 = UDPPacket::read<unsigned char>((UDPPacket *)rpak);
    v12 = std::to_wstring(&result, v11);
    LOBYTE(v108) = 10;
    v13 = std::operator+<wchar_t>(&v94, L"RECEIVED:", v12);
    LOBYTE(v108) = 11;
    ACClient::logMessage(this, v13);
    if ( v94._Myres >= 8 )
      operator delete(v94._Bx._Ptr);
    v94._Myres = 7;
    v94._Mysize = 0;
    v94._Bx._Buf[0] = 0;
    LOBYTE(v108) = 9;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( v11 != 64 )
    {
      std::wstring::wstring(&msg, L"Requesting car list :: unexpected packet received");
      v63 = this->sim;
      LOBYTE(v108) = 41;
      Sim::setSplashMessage(v63, &msg);
      LOBYTE(v108) = 9;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&msg);
      std::wstring::wstring(&msg, L"UNEXPECTED PACKET");
      LOBYTE(v108) = 42;
      ACClient::logMessage(this, &msg);
      LOBYTE(v108) = 9;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&msg);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v90,
        3,
        1);
      LOBYTE(v108) = 43;
      v64 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(
              (std::wostream *)v90.gap10,
              "ACCLIENT ERROR: UNEXPECTED PACKET ");
      v65 = (std::wostream *)std::wostream::operator<<(v64, v11);
      std::operator<<<wchar_t,std::char_traits<wchar_t>>(v65, " RECEIVED INSTEAD OF ACP_CAR_LIST_RESPONSE");
      v66 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v90, &msg);
      v67 = std::wstring::c_str(v66);
      _printf("ERROR: %S\n", v67->_Bx._Buf);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&msg);
      v68 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v90, &msg);
      LOBYTE(v108) = 44;
      ACClient::logMessage(this, v68);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&msg);
      v62 = &v90;
LABEL_147:
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(v62);
      goto LABEL_148;
    }
    v14 = UDPPacket::read<unsigned char>((UDPPacket *)rpak);
    v15 = std::to_wstring(&result, v14);
    LOBYTE(v108) = 12;
    v16 = std::operator+<wchar_t>(&v94, L"Index received:", v15);
    LOBYTE(v108) = 13;
    ACClient::logMessage(this, v16);
    if ( v94._Myres >= 8 )
      operator delete(v94._Bx._Ptr);
    v94._Myres = 7;
    v94._Mysize = 0;
    v94._Bx._Buf[0] = 0;
    LOBYTE(v108) = 9;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( v4 != v14 )
    {
      std::wstring::wstring(&result, L"Requesting car list :: UNEXPECTED ACP_CAR_LIST_RESPONSE");
      v55 = this->sim;
      LOBYTE(v108) = 38;
      Sim::setSplashMessage(v55, &result);
      LOBYTE(v108) = 9;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &ss2,
        3,
        1);
      LOBYTE(v108) = 39;
      v56 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(
              (std::wostream *)ss2.gap10,
              "ACCLIENT ERROR: UNEXPECTED ACP_CAR_LIST_RESPONSE WITH INDEX ");
      v57 = (std::wostream *)std::wostream::operator<<(v56, v14);
      v58 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v57, v74);
      std::wostream::operator<<(v58, " RECEIVED INSTEAD OF ");
      v59 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&ss2, &msg);
      if ( v59->_Myres >= 8 )
        v59 = (std::wstring *)v59->_Bx._Ptr;
      _printf("ERROR: %S\n", v59->_Bx._Buf);
      if ( msg._Myres >= 8 )
        operator delete(msg._Bx._Ptr);
      v60 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&ss2, &result);
      LOBYTE(v108) = 40;
      ACClient::logMessage(this, v60);
      if ( result._Myres >= 8 )
      {
        v77 = result._Myres + 1;
        v75 = result._Bx._Ptr;
        v61 = (std::allocator<wchar_t> *)std::_String_alloc<0,std::_String_base_types<wchar_t>>::_Getal(
                                           (std::_Vector_alloc<0,std::_Vec_base_types<std::vector<LeaderboardEntry>> > *)&result,
                                           (std::_Wrap_alloc<std::allocator<std::vector<LeaderboardEntry> > > *)&v81 + 3);
        std::allocator<wchar_t>::deallocate(v61, v75, v77);
      }
      result._Myres = 7;
      std::wstring::_Eos(&result, 0);
      v62 = &ss2;
      goto LABEL_147;
    }
    LOBYTE(v17) = UDPPacket::read<unsigned char>((UDPPacket *)rpak);
    v94._Myres = 7;
    v79 = v17;
    v94._Mysize = 0;
    v94._Bx._Buf[0] = 0;
    std::wstring::assign(&v94, word_17BE9D8, 0);
    LOBYTE(v108) = 14;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v89.gap10[8]);
    v18 = &v94;
    if ( v94._Myres >= 8 )
      v18 = (std::wstring *)v94._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v89.gap10[8], v18->_Bx._Buf, v94._Mysize, *(int *)&v89.gap10[68]);
    LOBYTE(v108) = 9;
    if ( v94._Myres >= 8 )
      operator delete(v94._Bx._Ptr);
    v17 = (unsigned __int8)v17;
    v86 = (unsigned __int8)v17;
    v19 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v89.gap10, "received ");
    v20 = (std::wostream *)std::wostream::operator<<(v19, (unsigned __int8)v17);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v20, " cars");
    v21 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v89, &result);
    LOBYTE(v108) = 15;
    ACClient::logMessage(this, v21);
    LOBYTE(v108) = 9;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v22 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v89, &result);
    v23 = this->sim;
    LOBYTE(v108) = 16;
    Sim::setSplashMessage(v23, v22);
    LOBYTE(v108) = 9;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v82 = 0;
    if ( v17 > 0 )
    {
      do
      {
        rc.model._Myres = 7;
        rc.model._Mysize = 0;
        rc.model._Bx._Buf[0] = 0;
        rc.config._Myres = 7;
        rc.config._Mysize = 0;
        rc.config._Bx._Buf[0] = 0;
        rc.skin._Myres = 7;
        rc.skin._Mysize = 0;
        rc.skin._Bx._Buf[0] = 0;
        rc.driverName._Myres = 7;
        rc.driverName._Mysize = 0;
        rc.driverName._Bx._Buf[0] = 0;
        rc.team._Myres = 7;
        rc.team._Mysize = 0;
        rc.team._Bx._Buf[0] = 0;
        rc.nationCode._Myres = 7;
        rc.nationCode._Mysize = 0;
        rc.nationCode._Bx._Buf[0] = 0;
        rc.sessionID = 0;
        LOBYTE(v108) = 17;
        rc.sessionID = UDPPacket::read<unsigned char>((UDPPacket *)rpak);
        v24 = UDPPacket::readString((UDPPacket *)rpak, (std::string *)&result);
        LOBYTE(v108) = 18;
        v25 = (ClientRemoteCarDef *)string2wstring(&v94, v24);
        if ( &rc != v25 )
        {
          if ( rc.model._Myres >= 8 )
            operator delete(rc.model._Bx._Ptr);
          rc.model._Myres = 7;
          rc.model._Mysize = 0;
          rc.model._Bx._Buf[0] = 0;
          if ( v25->model._Myres >= 8 )
          {
            rc.model._Bx._Ptr = v25->model._Bx._Ptr;
            v25->model._Bx._Ptr = 0;
          }
          else if ( v25->model._Mysize != -1 )
          {
            _memmove(&rc, v25, 2 * (v25->model._Mysize + 1));
          }
          rc.model._Mysize = v25->model._Mysize;
          rc.model._Myres = v25->model._Myres;
          v25->model._Myres = 7;
          v25->model._Mysize = 0;
          v25->model._Bx._Buf[0] = 0;
        }
        if ( v94._Myres >= 8 )
          operator delete(v94._Bx._Ptr);
        v94._Myres = 7;
        v94._Mysize = 0;
        v94._Bx._Buf[0] = 0;
        LOBYTE(v108) = 17;
        if ( result._Myres >= 0x10 )
          operator delete(result._Bx._Ptr);
        v26 = &rc;
        v27 = &rc;
        if ( rc.model._Myres >= 8 )
          v26 = (ClientRemoteCarDef *)rc.model._Bx._Ptr;
        if ( rc.model._Myres >= 8 )
          v27 = (ClientRemoteCarDef *)rc.model._Bx._Ptr;
        v28 = &v26->model._Bx._Buf[rc.model._Mysize];
        v29 = &rc;
        if ( rc.model._Myres >= 8 )
          v29 = (ClientRemoteCarDef *)rc.model._Bx._Ptr;
        if ( v29 == (ClientRemoteCarDef *)v28 )
          v87._Ptr = (const wchar_t *)v27;
        else
          std::_Transform<wchar_t *,std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,int (__cdecl *)(int)>(
            &v87,
            v29->model._Bx._Buf,
            v28,
            (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v27,
            _tolower);
        v30 = UDPPacket::readString((UDPPacket *)rpak, (std::string *)&result);
        LOBYTE(v108) = 19;
        v31 = (ClientRemoteCarDef *)string2wstring(&v94, v30);
        if ( &rc.skin != (std::wstring *)v31 )
        {
          if ( rc.skin._Myres >= 8 )
            operator delete(rc.skin._Bx._Ptr);
          rc.skin._Myres = 7;
          rc.skin._Mysize = 0;
          rc.skin._Bx._Buf[0] = 0;
          if ( v31->model._Myres >= 8 )
          {
            rc.skin._Bx._Ptr = v31->model._Bx._Ptr;
            v31->model._Bx._Ptr = 0;
          }
          else if ( v31->model._Mysize != -1 )
          {
            _memmove(&rc.skin, v31, 2 * (v31->model._Mysize + 1));
          }
          rc.skin._Mysize = v31->model._Mysize;
          rc.skin._Myres = v31->model._Myres;
          v31->model._Myres = 7;
          v31->model._Mysize = 0;
          v31->model._Bx._Buf[0] = 0;
        }
        if ( v94._Myres >= 8 )
          operator delete(v94._Bx._Ptr);
        v94._Myres = 7;
        v94._Mysize = 0;
        v94._Bx._Buf[0] = 0;
        LOBYTE(v108) = 17;
        if ( result._Myres >= 0x10 )
          operator delete(result._Bx._Ptr);
        v32 = UDPPacket::readString((UDPPacket *)rpak, (std::string *)&result);
        LOBYTE(v108) = 20;
        v33 = (ClientRemoteCarDef *)string2wstring(&v94, v32);
        if ( &rc.driverName != (std::wstring *)v33 )
        {
          if ( rc.driverName._Myres >= 8 )
            operator delete(rc.driverName._Bx._Ptr);
          rc.driverName._Myres = 7;
          rc.driverName._Mysize = 0;
          rc.driverName._Bx._Buf[0] = 0;
          if ( v33->model._Myres >= 8 )
          {
            rc.driverName._Bx._Ptr = v33->model._Bx._Ptr;
            v33->model._Bx._Ptr = 0;
          }
          else if ( v33->model._Mysize != -1 )
          {
            _memmove(&rc.driverName, v33, 2 * (v33->model._Mysize + 1));
          }
          rc.driverName._Mysize = v33->model._Mysize;
          rc.driverName._Myres = v33->model._Myres;
          v33->model._Myres = 7;
          v33->model._Mysize = 0;
          v33->model._Bx._Buf[0] = 0;
        }
        if ( v94._Myres >= 8 )
          operator delete(v94._Bx._Ptr);
        v94._Myres = 7;
        v94._Mysize = 0;
        v94._Bx._Buf[0] = 0;
        LOBYTE(v108) = 17;
        if ( result._Myres >= 0x10 )
          operator delete(result._Bx._Ptr);
        v34 = UDPPacket::readString((UDPPacket *)rpak, (std::string *)&result);
        LOBYTE(v108) = 21;
        v35 = (ClientRemoteCarDef *)string2wstring(&v94, v34);
        if ( &rc.team != (std::wstring *)v35 )
        {
          if ( rc.team._Myres >= 8 )
            operator delete(rc.team._Bx._Ptr);
          rc.team._Myres = 7;
          rc.team._Mysize = 0;
          rc.team._Bx._Buf[0] = 0;
          std::wstring::_Assign_rv(&rc.team, &v35->model);
        }
        if ( v94._Myres >= 8 )
          operator delete(v94._Bx._Ptr);
        v94._Myres = 7;
        v94._Mysize = 0;
        v94._Bx._Buf[0] = 0;
        LOBYTE(v108) = 17;
        if ( result._Myres >= 0x10 )
          operator delete(result._Bx._Ptr);
        v36 = UDPPacket::readString((UDPPacket *)rpak, (std::string *)&result);
        LOBYTE(v108) = 22;
        v37 = (ClientRemoteCarDef *)string2wstring(&v94, v36);
        if ( &rc.nationCode != (std::wstring *)v37 )
        {
          if ( rc.nationCode._Myres >= 8 )
            operator delete(rc.nationCode._Bx._Ptr);
          rc.nationCode._Myres = 7;
          rc.nationCode._Mysize = 0;
          rc.nationCode._Bx._Buf[0] = 0;
          std::wstring::_Assign_rv(&rc.nationCode, &v37->model);
        }
        if ( v94._Myres >= 8 )
          operator delete(v94._Bx._Ptr);
        v94._Myres = 7;
        v94._Mysize = 0;
        v94._Bx._Buf[0] = 0;
        LOBYTE(v108) = 17;
        if ( result._Myres >= 0x10 )
          operator delete(result._Bx._Ptr);
        v38 = UDPPacket::read<unsigned char>((UDPPacket *)rpak) != 0;
        for ( i = 0; i < 5; ++i )
        {
          v88 = UDPPacket::read<float>((UDPPacket *)rpak);
          v40 = v88;
          rc.damageZoneLevel[i] = v88;
          _printf("Damage zone %d: %f\n", i, v40);
        }
        v41 = &rc.nationCode;
        v42 = &rc.driverName;
        if ( rc.nationCode._Myres >= 8 )
          v41 = (std::wstring *)rc.nationCode._Bx._Ptr;
        if ( rc.driverName._Myres >= 8 )
          v42 = (std::wstring *)rc.driverName._Bx._Ptr;
        _printf("NAME: %S %S\n", v42->_Bx._Buf, v41->_Bx._Buf);
        v43 = std::to_wstring(&msg, rc.sessionID);
        LOBYTE(v108) = 23;
        v44 = std::to_wstring(&result, v83 + v82);
        LOBYTE(v108) = 24;
        v45 = std::operator+<wchar_t>(&v99, L"CAR", v44);
        LOBYTE(v108) = 25;
        v46 = std::operator+<wchar_t>(&v98, v45, L" SID:");
        LOBYTE(v108) = 26;
        v47 = std::operator+<wchar_t>(&v105, v46, v43);
        LOBYTE(v108) = 27;
        v48 = std::operator+<wchar_t>(&v106, v47, L" ");
        LOBYTE(v108) = 28;
        v49 = std::operator+<wchar_t>(&v104, v48, &rc.driverName);
        LOBYTE(v108) = 29;
        v50 = std::operator+<wchar_t>(&v102, v49, L" ");
        LOBYTE(v108) = 30;
        v51 = std::operator+<wchar_t>(&v100, v50, &rc.model);
        LOBYTE(v108) = 31;
        v52 = std::operator+<wchar_t>(&v103, v51, L"<");
        LOBYTE(v108) = 32;
        v53 = std::operator+<wchar_t>(&v101, v52, &rc.skin);
        LOBYTE(v108) = 33;
        v54 = std::operator+<wchar_t>(&v94, v53, L">");
        LOBYTE(v108) = 34;
        ACClient::logMessage(this, v54);
        if ( v94._Myres >= 8 )
          operator delete(v94._Bx._Ptr);
        v94._Myres = 7;
        v94._Mysize = 0;
        v94._Bx._Buf[0] = 0;
        if ( v101._Myres >= 8 )
          operator delete(v101._Bx._Ptr);
        v101._Myres = 7;
        v101._Mysize = 0;
        v101._Bx._Buf[0] = 0;
        if ( v103._Myres >= 8 )
          operator delete(v103._Bx._Ptr);
        v103._Myres = 7;
        v103._Mysize = 0;
        v103._Bx._Buf[0] = 0;
        if ( v100._Myres >= 8 )
          operator delete(v100._Bx._Ptr);
        v100._Myres = 7;
        v100._Mysize = 0;
        v100._Bx._Buf[0] = 0;
        if ( v102._Myres >= 8 )
          operator delete(v102._Bx._Ptr);
        v102._Myres = 7;
        v102._Mysize = 0;
        v102._Bx._Buf[0] = 0;
        if ( v104._Myres >= 8 )
          operator delete(v104._Bx._Ptr);
        v104._Myres = 7;
        v104._Mysize = 0;
        v104._Bx._Buf[0] = 0;
        if ( v106._Myres >= 8 )
          operator delete(v106._Bx._Ptr);
        v106._Myres = 7;
        v106._Mysize = 0;
        v106._Bx._Buf[0] = 0;
        if ( v105._Myres >= 8 )
          operator delete(v105._Bx._Ptr);
        v105._Myres = 7;
        v105._Mysize = 0;
        v105._Bx._Buf[0] = 0;
        if ( v98._Myres >= 8 )
          operator delete(v98._Bx._Ptr);
        v98._Myres = 7;
        v98._Mysize = 0;
        v98._Bx._Buf[0] = 0;
        if ( v99._Myres >= 8 )
          operator delete(v99._Bx._Ptr);
        v99._Myres = 7;
        v99._Mysize = 0;
        v99._Bx._Buf[0] = 0;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        LOBYTE(v108) = 17;
        if ( msg._Myres >= 8 )
          operator delete(msg._Bx._Ptr);
        if ( v38 )
        {
          if ( rc.sessionID == this->sessionID )
            this->playerIsSpectator = 1;
        }
        else if ( rc.sessionID == this->sessionID )
        {
          if ( &this->driverInfo != (DriverInfo *)&rc.driverName )
            std::wstring::assign(&this->driverInfo.name, &rc.driverName, 0, 0xFFFFFFFF);
          if ( &this->driverInfo.team != &rc.team )
            std::wstring::assign(&this->driverInfo.team, &rc.team, 0, 0xFFFFFFFF);
          if ( &this->driverInfo.nationCode != &rc.nationCode )
            std::wstring::assign(&this->driverInfo.nationCode, &rc.nationCode, 0, 0xFFFFFFFF);
          std::wstring::wstring(&result, L"THIS IS MY CAR!");
          LOBYTE(v108) = 35;
          ACClient::logMessage(this, &result);
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
        }
        else
        {
          std::vector<ClientRemoteCarDef>::push_back(v85, &rc);
        }
        LOBYTE(v108) = 9;
        ClientRemoteCarDef::~ClientRemoteCarDef(&rc);
        ++v82;
      }
      while ( v82 < v86 );
    }
    if ( v79 != 10 )
      break;
    std::wstring::wstring(&result, L"ASK FOR NEXT 10 CARS");
    LOBYTE(v108) = 37;
    ACClient::logMessage(this, &result);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v4 = v78 + 10;
    v78 += 10;
LABEL_148:
    LOBYTE(v108) = 8;
    UDPPacket::~UDPPacket((UDPPacket *)rpak);
    std::vector<LeaderboardEntry>::_Tidy((std::vector<vec3f> *)&ret);
    LOBYTE(v108) = 3;
    UDPPacket::~UDPPacket((UDPPacket *)&rpak[28]);
    v108 = -1;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v89);
    v3 = v84;
  }
  std::wstring::wstring(&result, L"COUNT != 10 EXITING");
  LOBYTE(v108) = 36;
  ACClient::logMessage(this, &result);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  LOBYTE(v108) = 8;
  UDPPacket::~UDPPacket((UDPPacket *)rpak);
  LOBYTE(v108) = 4;
  if ( ret._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&ret);
    operator delete(ret._Myfirst);
    ret._Myfirst = 0;
    ret._Mylast = 0;
    ret._Myend = 0;
  }
  LOBYTE(v108) = 3;
  UDPPacket::~UDPPacket((UDPPacket *)&rpak[28]);
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v89);
  return 1;
}
int ACClient::getSessionCount(ACClient *this)
{
  return this->sessions._Mylast - this->sessions._Myfirst;
}
int ACClient::getSessionIDFromCarAvatar(ACClient *this, CarAvatar *anAvatar)
{
  NetCarStateProvider **v3; // eax
  NetCarStateProvider **v4; // ecx

  if ( this->avatar == anAvatar )
    return this->sessionID;
  v3 = this->netCars._Myfirst;
  v4 = this->netCars._Mylast;
  if ( v3 == v4 )
    return -1;
  while ( (*v3)->avatar != anAvatar )
  {
    if ( ++v3 == v4 )
      return -1;
  }
  return (*v3)->sessionID;
}
unsigned __int8 ACClient::getSessionIdFromCarAvatarID(ACClient *this, int carAvatarID)
{
  NetCarStateProvider **v4; // esi
  NetCarStateProvider **v5; // edi

  if ( carAvatarID == CarAvatar::getGuid(this->avatar) )
    return this->sessionID;
  v4 = this->netCars._Myfirst;
  v5 = this->netCars._Mylast;
  if ( v4 == v5 )
    return -1;
  while ( CarAvatar::getGuid((*v4)->avatar) != carAvatarID )
  {
    if ( ++v4 == v5 )
      return -1;
  }
  return (*v4)->sessionID;
}
RemoteSession *ACClient::getSessionInfo(ACClient *this, RemoteSession *result, int index)
{
  RemoteSession *v3; // eax

  if ( index < 0 || index >= (unsigned int)(this->sessions._Mylast - this->sessions._Myfirst) )
  {
    result->name._Myres = 7;
    result->name._Mysize = 0;
    result->name._Bx._Buf[0] = 0;
    std::wstring::assign(&result->name, L"UNNAMED", 7u);
    result->index = 0;
    result->time = 0;
    v3 = result;
    result->laps = 0;
    result->startTime = 0.0;
    *(_WORD *)&result->isSpectator = 0;
    result->hasExtraLap = 0;
  }
  else
  {
    RemoteSession::RemoteSession(result, &this->sessions._Myfirst[index]);
    v3 = result;
  }
  return v3;
}
long double ACClient::getSessionTimeLeft(ACClient *this)
{
  return (double)this->currentSession.time * 60.0 * 1000.0
       - (this->sim->game->gameTime.now
        - this->currentSession.startTime);
}
unsigned int ACClient::getSplit(ACClient *this, CarAvatar *car, const int *sector)
{
  char v5; // al
  NetCarStateProvider **v6; // ecx
  NetCarStateProvider **v7; // edx
  NetCarStateProvider *v8; // esi

  if ( CarAvatar::getGuid(car) )
  {
    v5 = ACClient::getSessionIDFromCarAvatar(this, car);
    v6 = this->netCars._Myfirst;
    v7 = this->netCars._Mylast;
    if ( v6 == v7 )
    {
LABEL_7:
      v8 = 0;
    }
    else
    {
      while ( 1 )
      {
        v8 = *v6;
        if ( (*v6)->sessionID == v5 )
          break;
        if ( ++v6 == v7 )
          goto LABEL_7;
      }
    }
    if ( *sector < (unsigned int)(v8->currentSplits._Mylast - v8->currentSplits._Myfirst) )
      return v8->currentSplits._Myfirst[*sector];
  }
  else if ( *sector < (unsigned int)(this->localCarCurrentSplits._Mylast - this->localCarCurrentSplits._Myfirst) )
  {
    return this->localCarCurrentSplits._Myfirst[*sector];
  }
  return 0;
}
long double ACClient::getTimetoWait(ACClient *this)
{
  return this->raceClosingTime;
}
double ACClient::getVotingMaxTime(ACClient *this)
{
  return this->votingManager->currentVote.maxTime;
}
double ACClient::getVotingTimeLeft(ACClient *this)
{
  return this->votingManager->currentVote.timeLeftSeconds;
}
char ACClient::handleLocalAdminMessages(ACClient *this, std::wstring msg)
{
  std::wstring *v3; // eax
  std::wstring *v4; // eax
  const std::wstring *v5; // eax
  Event<OnChatMessageEvent> *v6; // edi
  int v7; // ebx
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  std::wstring *v12; // eax
  std::wstring *v13; // eax
  const std::wstring *v14; // eax
  std::pair<void *,std::function<void __cdecl(OnChatMessageEvent const &)> > *v15; // esi
  std::_Func_base<void,OnChatMessageEvent const &> **v16; // edi
  char v17; // bl
  int v19; // [esp-4h] [ebp-DCh]
  int v20; // [esp-4h] [ebp-DCh]
  NetCarStateProvider *v21; // [esp+14h] [ebp-C4h]
  std::wstring *v22; // [esp+14h] [ebp-C4h]
  std::wstring v23; // [esp+18h] [ebp-C0h] BYREF
  std::wstring v24; // [esp+30h] [ebp-A8h] BYREF
  std::wstring res_msg; // [esp+48h] [ebp-90h] BYREF
  std::wstring result; // [esp+60h] [ebp-78h] BYREF
  OnChatMessageEvent ev; // [esp+78h] [ebp-60h] BYREF
  OnChatMessageEvent event; // [esp+94h] [ebp-44h] BYREF
  std::wstring v29; // [esp+B0h] [ebp-28h] BYREF
  int v30; // [esp+D4h] [ebp-4h]

  v30 = 0;
  if ( std::wstring::compare(&msg, 0, msg._Mysize, L"/client_list", 0xCu) )
    goto $LN938;
  res_msg._Myres = 7;
  res_msg._Mysize = 0;
  res_msg._Bx._Buf[0] = 0;
  v19 = this->sessionID;
  LOBYTE(v30) = 1;
  v3 = std::to_wstring(&result, v19);
  LOBYTE(v30) = 2;
  v4 = std::operator+<wchar_t>(&v23, v3, L": ");
  LOBYTE(v30) = 3;
  v5 = std::operator+<wchar_t>(&v24, v4, &this->driverInfo.name);
  LOBYTE(v30) = 4;
  std::wstring::append(&res_msg, v5, 0, 0xFFFFFFFF);
  if ( v24._Myres >= 8 )
    operator delete(v24._Bx._Ptr);
  v24._Myres = 7;
  v24._Mysize = 0;
  v24._Bx._Buf[0] = 0;
  if ( v23._Myres >= 8 )
    operator delete(v23._Bx._Ptr);
  v23._Myres = 7;
  v23._Mysize = 0;
  v23._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  ev.sessionID = 0;
  ev.message._Myres = 7;
  ev.message._Mysize = 0;
  ev.message._Bx._Buf[0] = 0;
  LOBYTE(v30) = 5;
  std::wstring::assign(&ev.message, &res_msg, 0, 0xFFFFFFFF);
  ev.sessionID = 255;
  v6 = &this->evOnChatMessage;
  Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&this->evOnChatMessage, (const OnGearRequestEvent *)&ev);
  v7 = 0;
  if ( !(this->netCars._Mylast - this->netCars._Myfirst) )
  {
LABEL_38:
    if ( ev.message._Myres >= 8 )
      operator delete(ev.message._Bx._Ptr);
    ev.message._Myres = 7;
    ev.message._Mysize = 0;
    ev.message._Bx._Buf[0] = 0;
    if ( res_msg._Myres >= 8 )
      operator delete(res_msg._Bx._Ptr);
    v17 = 1;
    goto LABEL_45;
  }
  while ( 1 )
  {
    v21 = this->netCars._Myfirst[v7];
    v20 = v21->sessionID;
    if ( v7 % 2 )
    {
      v11 = std::to_wstring(&v29, v20);
      LOBYTE(v30) = 8;
      v12 = std::operator+<wchar_t>(&result, L"\t", v11);
      LOBYTE(v30) = 9;
      v13 = std::operator+<wchar_t>(&v24, v12, L": ");
      LOBYTE(v30) = 10;
      v14 = std::operator+<wchar_t>(&v23, v13, &v21->driverInfo.name);
      LOBYTE(v30) = 11;
      std::wstring::append(&res_msg, v14, 0, 0xFFFFFFFF);
      if ( v23._Myres >= 8 )
        operator delete(v23._Bx._Ptr);
      v23._Myres = 7;
      v23._Mysize = 0;
      v23._Bx._Buf[0] = 0;
      if ( v24._Myres >= 8 )
        operator delete(v24._Bx._Ptr);
      v24._Myres = 7;
      v24._Mysize = 0;
      v24._Bx._Buf[0] = 0;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      LOBYTE(v30) = 5;
      if ( v29._Myres >= 8 )
        operator delete(v29._Bx._Ptr);
    }
    else
    {
      v8 = std::to_wstring(&result, v20);
      LOBYTE(v30) = 6;
      v9 = std::operator+<wchar_t>(&v24, v8, L": ");
      LOBYTE(v30) = 7;
      v10 = std::operator+<wchar_t>(&v23, v9, &v21->driverInfo.name);
      v22 = v10;
      if ( &res_msg != v10 )
      {
        if ( res_msg._Myres >= 8 )
        {
          operator delete(res_msg._Bx._Ptr);
          v10 = v22;
        }
        res_msg._Myres = 7;
        res_msg._Bx._Buf[0] = 0;
        res_msg._Mysize = 0;
        std::wstring::_Assign_rv(&res_msg, v10);
      }
      if ( v23._Myres >= 8 )
        operator delete(v23._Bx._Ptr);
      v23._Myres = 7;
      v23._Mysize = 0;
      v23._Bx._Buf[0] = 0;
      if ( v24._Myres >= 8 )
        operator delete(v24._Bx._Ptr);
      v24._Myres = 7;
      v24._Mysize = 0;
      v24._Bx._Buf[0] = 0;
      LOBYTE(v30) = 5;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
    }
    if ( !(v7 % 2) && v7 != this->netCars._Mylast - this->netCars._Myfirst - 1 )
      goto LABEL_37;
    event.sessionID = 0;
    event.message._Myres = 7;
    event.message._Mysize = 0;
    event.message._Bx._Buf[0] = 0;
    LOBYTE(v30) = 12;
    std::wstring::assign(&event.message, &res_msg, 0, 0xFFFFFFFF);
    v15 = v6->handlers._Myfirst;
    event.sessionID = 255;
    if ( v15 != v6->handlers._Mylast )
      break;
LABEL_35:
    LOBYTE(v30) = 5;
    if ( event.message._Myres >= 8 )
      operator delete(event.message._Bx._Ptr);
LABEL_37:
    if ( ++v7 >= (unsigned int)(this->netCars._Mylast - this->netCars._Myfirst) )
      goto LABEL_38;
  }
  v16 = &v15->second._Impl;
  while ( *v16 )
  {
    (*v16)->_Do_call(*v16, &event);
    ++v15;
    v16 += 8;
    if ( v15 == this->evOnChatMessage.handlers._Mylast )
    {
      v6 = &this->evOnChatMessage;
      goto LABEL_35;
    }
  }
  std::_Xbad_function_call();
$LN938:
  v17 = 0;
LABEL_45:
  if ( msg._Myres >= 8 )
    operator delete(msg._Bx._Ptr);
  return v17;
}
ClientHandshakeResult *__userpurge ACClient::handshakeTCP@<eax>(ACClient *this@<ecx>, unsigned int a2@<ebx>, ClientHandshakeResult *result)
{
  ACClient *v4; // esi
  std::wstring *v5; // edi
  unsigned __int16 v6; // ax
  bool v7; // cf
  char v8; // bl
  unsigned __int16 v9; // ax
  char v10; // bl
  std::wstring *v11; // eax
  std::wstring *v12; // ecx
  std::wstring *v13; // esi
  std::wstring *v14; // eax
  std::wstring *v15; // eax
  std::wstring *v16; // eax
  const std::wstring *v17; // eax
  int v18; // eax
  std::wostream *v19; // eax
  std::wostream *v20; // eax
  std::wostream *v21; // eax
  std::wostream *v22; // eax
  const std::wstring *v23; // eax
  Sim *v24; // ecx
  const IPAddress *v25; // eax
  bool v26; // al
  bool v27; // bl
  const std::string *v29; // eax
  const std::string *v30; // eax
  const std::string *v31; // eax
  const std::string *v32; // eax
  const std::string *v33; // eax
  int v34; // esi
  std::wstring *v35; // eax
  const std::wstring *v36; // eax
  const std::wstring *v37; // eax
  Sim *v38; // ecx
  Sim *v39; // ecx
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v40; // ecx
  Sim *v41; // ecx
  Sim *v42; // ecx
  Sim *v43; // ecx
  Sim *v44; // ecx
  std::wstring *v45; // eax
  const __m128i *v46; // eax
  const std::string *v47; // eax
  std::wstring *v48; // eax
  std::wstring *v49; // eax
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *v50; // edi
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *v51; // esi
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *v52; // eax
  const std::string *v53; // eax
  std::wstring *v54; // eax
  std::wstring *v55; // eax
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *v56; // edi
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *v57; // esi
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *v58; // eax
  const std::string *v59; // eax
  std::wstring *v60; // eax
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *v61; // edi
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *v62; // esi
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *v63; // eax
  const std::string *v64; // eax
  std::wstring *v65; // eax
  __int16 v66; // ax
  int v67; // eax
  int v68; // eax
  unsigned __int8 v69; // al
  unsigned __int8 v70; // al
  int v71; // esi
  int v72; // eax
  int v73; // eax
  unsigned __int16 v74; // ax
  const std::wstring *v75; // eax
  const std::wstring *v76; // eax
  const std::wstring *v77; // eax
  std::wstring *v78; // eax
  const std::wstring *v79; // eax
  std::wstring *v80; // eax
  const std::wstring *v81; // eax
  int v82; // esi
  int v83; // edi
  int v84; // esi
  const std::string *v85; // eax
  std::vector<WingState> *v86; // eax
  std::vector<unsigned char> *v87; // ecx
  const std::string *v88; // eax
  std::wstring *v89; // edi
  std::wstring *i; // esi
  unsigned int v91; // esi
  double v92; // st7
  _QWORD *v93; // eax
  Sim *v94; // ecx
  int v95; // esi
  std::wstring *v96; // eax
  std::wostream *v97; // eax
  std::wostream *v98; // eax
  const std::wstring *v99; // eax
  Sim *v100; // ecx
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > *v101; // ecx
  const std::wstring *v102; // eax
  Sim *v103; // ecx
  bool v104; // zf
  std::wostream *v105; // eax
  std::wostream *v106; // eax
  const std::wstring *v107; // eax
  Sim *v108; // ecx
  ClientHandshakeResult *v109; // esi
  _BYTE _Val[28]; // [esp-4h] [ebp-904h] BYREF
  double v111; // [esp+2Ch] [ebp-8D4h]
  int v112; // [esp+34h] [ebp-8CCh]
  double v113; // [esp+38h] [ebp-8C8h] BYREF
  ClientHandshakeResult *v114; // [esp+40h] [ebp-8C0h]
  std::vector<unsigned char> pakdata; // [esp+44h] [ebp-8BCh] BYREF
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v116; // [esp+50h] [ebp-8B0h] BYREF
  ClientHandshakeResult *v117; // [esp+54h] [ebp-8ACh]
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v118; // [esp+58h] [ebp-8A8h] BYREF
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v119; // [esp+5Ch] [ebp-8A4h] BYREF
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v120; // [esp+60h] [ebp-8A0h] BYREF
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v121; // [esp+64h] [ebp-89Ch] BYREF
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v122; // [esp+68h] [ebp-898h] BYREF
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v123; // [esp+6Ch] [ebp-894h] BYREF
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v124; // [esp+70h] [ebp-890h] BYREF
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v125; // [esp+74h] [ebp-88Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v126; // [esp+78h] [ebp-888h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > ss2; // [esp+128h] [ebp-7D8h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v128; // [esp+1D8h] [ebp-728h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v129; // [esp+288h] [ebp-678h] BYREF
  ClientHandshakeResult res; // [esp+338h] [ebp-5C8h] BYREF
  std::wstring section; // [esp+3A4h] [ebp-55Ch] BYREF
  std::wstring key; // [esp+3BCh] [ebp-544h] BYREF
  UDPPacket recv_pak; // [esp+3D4h] [ebp-52Ch] BYREF
  std::wstring legal_tyres_string; // [esp+3F0h] [ebp-510h] BYREF
  std::wstring v135; // [esp+408h] [ebp-4F8h] BYREF
  std::vector<std::wstring> legal_tyres_list; // [esp+420h] [ebp-4E0h] BYREF
  int v137; // [esp+430h] [ebp-4D0h]
  unsigned int v138; // [esp+434h] [ebp-4CCh]
  std::wstring v139; // [esp+438h] [ebp-4C8h] BYREF
  UDPPacket pak; // [esp+450h] [ebp-4B0h] BYREF
  std::wstring v141; // [esp+46Ch] [ebp-494h] BYREF
  std::wstring myrequested_car; // [esp+484h] [ebp-47Ch] BYREF
  std::wstring myteam; // [esp+49Ch] [ebp-464h] BYREF
  std::wstring password; // [esp+4B4h] [ebp-44Ch] BYREF
  std::wstring myname; // [esp+4CCh] [ebp-434h] BYREF
  std::wstring mynation; // [esp+4E4h] [ebp-41Ch] BYREF
  RemoteSession session; // [esp+4FCh] [ebp-404h] BYREF
  std::string v148; // [esp+534h] [ebp-3CCh] BYREF
  INIReaderDocuments ini; // [esp+54Ch] [ebp-3B4h] BYREF
  std::wstring v150; // [esp+590h] [ebp-370h] BYREF
  std::wstring v151; // [esp+5A8h] [ebp-358h] BYREF
  std::wstring v152; // [esp+5C0h] [ebp-340h] BYREF
  std::wstring v153; // [esp+5D8h] [ebp-328h] BYREF
  std::wstring v154; // [esp+5F0h] [ebp-310h] BYREF
  std::wstring msg; // [esp+608h] [ebp-2F8h] BYREF
  std::wstring v156; // [esp+620h] [ebp-2E0h] BYREF
  std::wstring v157; // [esp+638h] [ebp-2C8h] BYREF
  std::wstring v158; // [esp+650h] [ebp-2B0h] BYREF
  std::wstring splitter; // [esp+668h] [ebp-298h] BYREF
  std::wstring message; // [esp+680h] [ebp-280h] BYREF
  std::wstring v161; // [esp+698h] [ebp-268h] BYREF
  std::wstring v162; // [esp+6B0h] [ebp-250h] BYREF
  std::wstring v163; // [esp+6C8h] [ebp-238h] BYREF
  std::wstring v164; // [esp+6E0h] [ebp-220h] BYREF
  std::wstring v165; // [esp+6F8h] [ebp-208h] BYREF
  std::wstring v166; // [esp+710h] [ebp-1F0h] BYREF
  std::wstring v167; // [esp+728h] [ebp-1D8h] BYREF
  std::wstring v168; // [esp+740h] [ebp-1C0h] BYREF
  std::wstring v169; // [esp+758h] [ebp-1A8h] BYREF
  std::wstring v170; // [esp+770h] [ebp-190h] BYREF
  std::wstring v171; // [esp+788h] [ebp-178h] BYREF
  std::wstring v172; // [esp+7A0h] [ebp-160h] BYREF
  std::string v173; // [esp+7B8h] [ebp-148h] BYREF
  std::wstring v174; // [esp+7D0h] [ebp-130h] BYREF
  std::wstring v175; // [esp+7E8h] [ebp-118h] BYREF
  std::wstring v176; // [esp+800h] [ebp-100h] BYREF
  std::string v177; // [esp+818h] [ebp-E8h] BYREF
  std::wstring v178; // [esp+830h] [ebp-D0h] BYREF
  std::wstring v179; // [esp+848h] [ebp-B8h] BYREF
  std::wstring v180; // [esp+860h] [ebp-A0h] BYREF
  std::string v181; // [esp+878h] [ebp-88h] BYREF
  std::wstring v182; // [esp+890h] [ebp-70h] BYREF
  std::wstring v183; // [esp+8A8h] [ebp-58h] BYREF
  std::wstring v184; // [esp+8C0h] [ebp-40h] BYREF
  std::string v185; // [esp+8D8h] [ebp-28h] BYREF
  int v186; // [esp+8F8h] [ebp-8h]
  int v187; // [esp+8FCh] [ebp-4h]
  void *retaddr; // [esp+900h] [ebp+0h]

  v112 = 0;
  v114 = result;
  v117 = result;
  res.model._Myres = 7;
  res.model._Mysize = 0;
  res.model._Bx._Buf[0] = 0;
  res.skin._Myres = 7;
  res.skin._Mysize = 0;
  res.skin._Bx._Buf[0] = 0;
  res.track._Myres = 7;
  res.track._Mysize = 0;
  res.track._Bx._Buf[0] = 0;
  res.track_config._Myres = 7;
  res.track_config._Mysize = 0;
  res.track_config._Bx._Buf[0] = 0;
  res.sunAngle = 0.0;
  res.sessionID = 0;
  *(_DWORD *)&_Val[24] = 0;
  res.success = 0;
  v187 = 1;
  *(_QWORD *)&_Val[16] = 0x700000000i64;
  *(_WORD *)_Val = 0;
  std::wstring::assign((std::wstring *)_Val, L"cfg/race.ini", 0xCu);
  INIReaderDocuments::INIReaderDocuments(&ini, a2, *(std::wstring *)_Val, _Val[24]);
  LOBYTE(v187) = 2;
  INIReader::setVerboseMode(&ini, 1);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"SERVER_IP", 9u);
  LOBYTE(v187) = 3;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"REMOTE", 6u);
  LOBYTE(v187) = 4;
  v4 = (ACClient *)INIReader::getString(&ini, &v139, &section, &key);
  v5 = &this->serverInfo.ip;
  if ( &this->serverInfo.ip != (std::wstring *)v4 )
  {
    if ( this->serverInfo.ip._Myres >= 8 )
      operator delete(v5->_Bx._Ptr);
    this->serverInfo.ip._Myres = 7;
    this->serverInfo.ip._Mysize = 0;
    *(_DWORD *)&_Val[24] = v4;
    v5->_Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&this->serverInfo.ip, *(std::wstring **)&_Val[24]);
  }
  if ( v139._Myres >= 8 )
    operator delete(v139._Bx._Ptr);
  v139._Myres = 7;
  v139._Mysize = 0;
  v139._Bx._Buf[0] = 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v187) = 2;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"SERVER_PORT", 0xBu);
  LOBYTE(v187) = 5;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"REMOTE", 6u);
  LOBYTE(v187) = 6;
  v6 = INIReader::getInt(&ini, &section, &key);
  v7 = section._Myres < 8;
  this->serverInfo.tcpPort = v6;
  if ( !v7 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v187) = 2;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"SERVER_HTTP_PORT", 0x10u);
  LOBYTE(v187) = 7;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"REMOTE", 6u);
  LOBYTE(v187) = 8;
  v8 = INIReader::hasKey(&ini, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v187) = 2;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v8 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SERVER_HTTP_PORT", 0x10u);
    LOBYTE(v187) = 9;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"REMOTE", 6u);
    LOBYTE(v187) = 10;
    v9 = INIReader::getInt(&ini, &section, &key);
    v7 = section._Myres < 8;
    this->serverInfo.httpPort = v9;
    if ( !v7 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v187) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"SERVER_NAME", 0xBu);
  LOBYTE(v187) = 11;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"REMOTE", 6u);
  LOBYTE(v187) = 12;
  v10 = INIReader::hasKey(&ini, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v187) = 2;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v10 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SERVER_NAME", 0xBu);
    LOBYTE(v187) = 13;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"REMOTE", 6u);
    LOBYTE(v187) = 14;
    v11 = INIReader::getString(&ini, &v139, &section, &key);
    std::wstring::operator=(&this->serverInfo.name, v11);
    if ( v139._Myres >= 8 )
      operator delete(v139._Bx._Ptr);
    v139._Myres = 7;
    v139._Mysize = 0;
    v139._Bx._Buf[0] = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v187) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  if ( this->serverInfo.ip._Myres < 8 )
    v12 = &this->serverInfo.ip;
  else
    v12 = (std::wstring *)v5->_Bx._Ptr;
  _printf("CONNECTING TO SERVER VIA TCP %S [%u]\n", v12->_Bx._Buf, this->serverInfo.tcpPort);
  v13 = std::to_wstring(&legal_tyres_string, this->serverInfo.tcpPort);
  LOBYTE(v187) = 15;
  v14 = std::operator+<wchar_t>(&section, L"Connecting to server(tcp):", &this->serverInfo.ip);
  LOBYTE(v187) = 16;
  v15 = std::operator+<wchar_t>(&v135, v14, L"<");
  LOBYTE(v187) = 17;
  v16 = std::operator+<wchar_t>(&v141, v15, v13);
  LOBYTE(v187) = 18;
  v17 = std::operator+<wchar_t>(&v139, v16, L"]");
  LOBYTE(v187) = 19;
  ACClient::logMessage(this, v17);
  if ( v139._Myres >= 8 )
    operator delete(v139._Bx._Ptr);
  v139._Myres = 7;
  v139._Mysize = 0;
  v139._Bx._Buf[0] = 0;
  if ( v141._Myres >= 8 )
    operator delete(v141._Bx._Ptr);
  v141._Myres = 7;
  v141._Mysize = 0;
  v141._Bx._Buf[0] = 0;
  if ( v135._Myres >= 8 )
    operator delete(v135._Bx._Ptr);
  v135._Myres = 7;
  v135._Mysize = 0;
  v135._Bx._Buf[0] = 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v187) = 2;
  if ( legal_tyres_string._Myres >= 8 )
    operator delete(legal_tyres_string._Bx._Ptr);
  *(_DWORD *)v126.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v126.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v126.gap68);
  LOBYTE(retaddr) = 20;
  LODWORD(v113) = 2;
  std::wiostream::basic_iostream<wchar_t>(&v126.gap0[4], &v126.gap10[12], 0);
  v186 = 21;
  *(const wchar_t **)((char *)&v125._Ptr + *((_DWORD *)v125._Ptr + 1)) = (const wchar_t *)&std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(const wchar_t **)((char *)&v124._Ptr + *((_DWORD *)v125._Ptr + 1)) = (const wchar_t *)(*((_DWORD *)v125._Ptr + 1)
                                                                                         - 104);
  std::wstreambuf::wstreambuf(&v126.gap10[4]);
  *(_DWORD *)&v126.gap10[4] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v126.gap10[60] = 0;
  *(_DWORD *)&v126.gap10[64] = 0;
  v18 = this->serverInfo.tcpPort;
  *(_DWORD *)&_Val[20] = " TCP";
  *(_DWORD *)&_Val[16] = v18;
  *(_DWORD *)&_Val[12] = &Manip;
  *(_DWORD *)&_Val[8] = &this->serverInfo.ip;
  LOBYTE(v186) = 23;
  v19 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(
          (std::wostream *)((char *)&v126._Chcount + 4),
          "connecting to ");
  v20 = std::operator<<<wchar_t>(v19, *(const std::wstring **)&_Val[8]);
  v21 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v20, *(const char **)&_Val[12]);
  v22 = (std::wostream *)std::wostream::operator<<(v21, *(_DWORD *)&_Val[16], *(_DWORD *)&_Val[20]);
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v22, *(const char **)&_Val[24]);
  v23 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
          &v126,
          &legal_tyres_string);
  v24 = this->sim;
  LOBYTE(v187) = 24;
  Sim::setSplashMessage(v24, v23);
  LOBYTE(v187) = 23;
  if ( legal_tyres_string._Myres >= 8 )
    operator delete(legal_tyres_string._Bx._Ptr);
  IPAddress::IPAddress((IPAddress *)&key, &this->serverInfo.ip, this->serverInfo.tcpPort);
  LOBYTE(v187) = 25;
  v26 = TCPSocket::connect(&this->tcpSock, v25);
  LOBYTE(v187) = 23;
  v27 = v26;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&key);
  if ( !v27 )
  {
    _printf("TCP connection failed\n");
    ClientHandshakeResult::ClientHandshakeResult(v114, &res);
    v112 = 3;
    goto LABEL_52;
  }
  UDPPacket::UDPPacket(&pak);
  *(_DWORD *)&_Val[24] = L"NAME";
  LOBYTE(v187) = 26;
  pak.data[pak.size] = 61;
  *(_WORD *)&pak.data[++pak.size] = 202;
  pak.size += 2;
  std::wstring::wstring(&key, *(const wchar_t **)&_Val[24]);
  LOBYTE(v187) = 27;
  std::wstring::wstring(&section, L"REMOTE");
  LOBYTE(v187) = 28;
  INIReader::getString(&ini, &myname, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v187) = 31;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::wstring(&v135, L"TEAM");
  LOBYTE(v187) = 32;
  std::wstring::wstring((std::wstring *)&legal_tyres_list, L"REMOTE");
  LOBYTE(v187) = 33;
  INIReader::getString(&ini, &myteam, (const std::wstring *)&legal_tyres_list, &v135);
  if ( v138 >= 8 )
    operator delete(legal_tyres_list._Myfirst);
  v138 = 7;
  v137 = 0;
  LOWORD(legal_tyres_list._Myfirst) = 0;
  LOBYTE(v187) = 36;
  if ( v135._Myres >= 8 )
    operator delete(v135._Bx._Ptr);
  v135._Myres = 7;
  v135._Mysize = 0;
  v135._Bx._Buf[0] = 0;
  std::wstring::wstring(&key, L"NATION_CODE");
  LOBYTE(v187) = 37;
  std::wstring::wstring(&section, L"CAR_0");
  LOBYTE(v187) = 38;
  INIReader::getString(&ini, &mynation, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v187) = 41;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::wstring((std::wstring *)&legal_tyres_list, L"REQUESTED_CAR");
  LOBYTE(v187) = 42;
  std::wstring::wstring(&v135, L"REMOTE");
  LOBYTE(v187) = 43;
  INIReader::getString(&ini, &myrequested_car, &v135, (const std::wstring *)&legal_tyres_list);
  if ( v135._Myres >= 8 )
    operator delete(v135._Bx._Ptr);
  v135._Myres = 7;
  v135._Mysize = 0;
  v135._Bx._Buf[0] = 0;
  LOBYTE(v187) = 46;
  if ( v138 >= 8 )
    operator delete(legal_tyres_list._Myfirst);
  v138 = 7;
  v137 = 0;
  LOWORD(legal_tyres_list._Myfirst) = 0;
  if ( &this->guid != &SteamInterface::playerGUID )
    std::wstring::assign(&this->guid, &SteamInterface::playerGUID, 0, 0xFFFFFFFF);
  v29 = wstring2string((std::string *)&legal_tyres_string, &this->guid);
  LOBYTE(v187) = 47;
  UDPPacket::writeString(&pak, v29);
  LOBYTE(v187) = 46;
  if ( legal_tyres_string._Myres >= 0x10 )
    operator delete(legal_tyres_string._Bx._Ptr);
  UDPPacket::writeString(&pak, &myname);
  v30 = wstring2string((std::string *)&legal_tyres_string, &myteam);
  LOBYTE(v187) = 48;
  UDPPacket::writeString(&pak, v30);
  LOBYTE(v187) = 46;
  if ( legal_tyres_string._Myres >= 0x10 )
    operator delete(legal_tyres_string._Bx._Ptr);
  v31 = wstring2string((std::string *)&legal_tyres_string, &mynation);
  LOBYTE(v187) = 49;
  UDPPacket::writeString(&pak, v31);
  LOBYTE(v187) = 46;
  if ( legal_tyres_string._Myres >= 0x10 )
    operator delete(legal_tyres_string._Bx._Ptr);
  v32 = wstring2string((std::string *)&legal_tyres_string, &myrequested_car);
  LOBYTE(v187) = 50;
  UDPPacket::writeString(&pak, v32);
  LOBYTE(v187) = 46;
  if ( legal_tyres_string._Myres >= 0x10 )
    operator delete(legal_tyres_string._Bx._Ptr);
  std::wstring::wstring(&v139, L"PASSWORD");
  LOBYTE(v187) = 51;
  std::wstring::wstring(&v141, L"REMOTE");
  LOBYTE(v187) = 52;
  INIReader::getString(&ini, &password, &v141, &v139);
  if ( v141._Myres >= 8 )
    operator delete(v141._Bx._Ptr);
  v141._Myres = 7;
  v141._Mysize = 0;
  v141._Bx._Buf[0] = 0;
  LOBYTE(v187) = 55;
  if ( v139._Myres >= 8 )
    operator delete(v139._Bx._Ptr);
  v139._Myres = 7;
  v139._Bx._Buf[0] = 0;
  v139._Mysize = 0;
  v33 = wstring2string((std::string *)&legal_tyres_string, &password);
  LOBYTE(v187) = 56;
  UDPPacket::writeString(&pak, v33);
  LOBYTE(v187) = 55;
  if ( legal_tyres_string._Myres >= 0x10 )
    operator delete(legal_tyres_string._Bx._Ptr);
  UDPPacket::send(&pak, &this->tcpSock);
  TCPSocket::receivePacket(&this->tcpSock, &pakdata);
  LOBYTE(v187) = 57;
  if ( pakdata._Myfirst == pakdata._Mylast )
    goto LABEL_143;
  UDPPacket::UDPPacket(&recv_pak, &pakdata);
  LOBYTE(v187) = 58;
  v34 = UDPPacket::read<unsigned char>(&recv_pak);
  _printf("RECV: %d\n", v34);
  v35 = std::to_wstring(&v151, v34);
  LOBYTE(v187) = 59;
  v36 = std::operator+<wchar_t>(&v150, L"Handshake answer:", v35);
  LOBYTE(v187) = 60;
  ACClient::logMessage(this, v36);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v150);
  LOBYTE(v187) = 58;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v151);
  switch ( v34 )
  {
    case ';':
      std::wstring::wstring(&v153, L"ACP_BLACKLISTED");
      LOBYTE(v187) = 67;
      ACClient::logMessage(this, &v153);
      LOBYTE(v187) = 58;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v153);
      _printf("ACClient:: ACP_BLACKLISTED\n");
      std::wstring::wstring(&v154, L"Cannot join the server : You have been blacklisted from this server");
      v42 = this->sim;
      LOBYTE(v187) = 68;
      Sim::setSplashMessage(v42, &v154);
      v40 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v154;
      goto LABEL_89;
    case '<':
      std::wstring::wstring(&v163, L"ACP_WRONG_PASSWORD");
      LOBYTE(v187) = 65;
      ACClient::logMessage(this, &v163);
      LOBYTE(v187) = 58;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v163);
      _printf("ACClient:: ACP_WRONG_PASSWORD\n");
      std::wstring::wstring(&v161, L"ERROR :: Password not accepted");
      v41 = this->sim;
      LOBYTE(v187) = 66;
      Sim::setSplashMessage(v41, &v161);
      v40 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v161;
      goto LABEL_89;
    case '>':
      _printf("ACClient:: server replied\n");
      std::wstring::wstring(&v152, L"connected");
      v44 = this->sim;
      LOBYTE(v187) = 71;
      Sim::setSplashMessage(v44, &v152);
      LOBYTE(v187) = 58;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v152);
      v45 = UDPPacket::readStringW(&recv_pak, &v169);
      std::wstring::operator=(&this->serverName, v45);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v169);
      *(_WORD *)&_Val[24] = UDPPacket::read<unsigned short>(&recv_pak);
      *(_DWORD *)&_Val[20] = &this->serverInfo.ip;
      this->serverInfo.udpPort = *(_WORD *)&_Val[24];
      IPAddress::IPAddress((IPAddress *)&section, *(const std::wstring **)&_Val[20], *(unsigned __int16 *)&_Val[24]);
      this->serverIP = (IPAddress)_mm_loadu_si128(v46);
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&section);
      _printf("UDP PORT:%u\n", this->serverInfo.udpPort);
      *(_DWORD *)&_Val[24] = UDPPacket::read<unsigned char>(&recv_pak);
      *(double *)&_Val[16] = (double)(3 * (1000 / *(_DWORD *)&_Val[24] / 3));
      *(_DWORD *)&_Val[12] = "SEND INTERVAL:%f (requested %dHz)\n";
      this->sendInterval = *(long double *)&_Val[16];
      _printf(*(const char *const *)&_Val[12], *(_QWORD *)&_Val[16], *(_DWORD *)&_Val[24]);
      res.success = 1;
      v47 = UDPPacket::readString(&recv_pak, &v173);
      LOBYTE(v187) = 72;
      v48 = string2wstring(&v171, v47);
      std::wstring::operator=(&res.track, v48);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v171);
      LOBYTE(v187) = 58;
      std::string::~string(&v173);
      v49 = &res.track;
      if ( res.track._Myres >= 8 )
        v49 = (std::wstring *)res.track._Bx._Ptr;
      _printf("TRACK:%S\n", v49->_Bx._Buf);
      v50 = std::wstring::begin(&res.track, &v120);
      v51 = std::wstring::end(&res.track, &v118);
      v52 = std::wstring::begin(&res.track, &v124);
      std::transform<std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,int (__cdecl *)(int)>(
        (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *)&v113,
        (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v52->_Ptr,
        (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v51->_Ptr,
        (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v50->_Ptr,
        _tolower);
      v53 = UDPPacket::readString(&recv_pak, &v177);
      LOBYTE(v187) = 73;
      v54 = string2wstring(&v175, v53);
      std::wstring::operator=(&res.track_config, v54);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v175);
      LOBYTE(v187) = 58;
      std::string::~string(&v177);
      v55 = &res.track_config;
      if ( res.track_config._Myres >= 8 )
        v55 = (std::wstring *)res.track_config._Bx._Ptr;
      _printf("TRACK_CONFIG=%S\n", v55->_Bx._Buf);
      v56 = std::wstring::begin(&res.track_config, &v123);
      v57 = std::wstring::end(&res.track_config, &v121);
      v58 = std::wstring::begin(&res.track_config, &v125);
      std::transform<std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,int (__cdecl *)(int)>(
        (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *)&v113,
        (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v58->_Ptr,
        (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v57->_Ptr,
        (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v56->_Ptr,
        _tolower);
      v59 = UDPPacket::readString(&recv_pak, &v181);
      LOBYTE(v187) = 74;
      v60 = string2wstring(&v179, v59);
      std::wstring::operator=(&res.model, v60);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v179);
      LOBYTE(v187) = 58;
      std::string::~string(&v181);
      v61 = std::wstring::begin(&res.model, &v119);
      v62 = std::wstring::end(&res.model, &v116);
      v63 = std::wstring::begin(&res.model, &v122);
      std::transform<std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,int (__cdecl *)(int)>(
        (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > *)&v113,
        (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v63->_Ptr,
        (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v62->_Ptr,
        (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v61->_Ptr,
        _tolower);
      v64 = UDPPacket::readString(&recv_pak, &v185);
      LOBYTE(v187) = 75;
      v65 = string2wstring(&v183, v64);
      std::wstring::operator=(&res.skin, v65);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v183);
      LOBYTE(v187) = 58;
      std::string::~string(&v185);
      res.sunAngle = UDPPacket::read<float>(&recv_pak);
      v66 = UDPPacket::read<short>(&recv_pak);
      PhysicsAvatar::setAllowedTyresOut(this->sim->physicsAvatar, v66);
      this->sim->physicsAvatar->engine.allowTyreBlankets = UDPPacket::read<unsigned char>(&recv_pak) != 0;
      this->serverDrivingAssists.tc = UDPPacket::read<unsigned char>(&recv_pak);
      this->serverDrivingAssists.abs = UDPPacket::read<unsigned char>(&recv_pak);
      this->serverDrivingAssists.stability = UDPPacket::read<unsigned char>(&recv_pak) != 0;
      this->serverDrivingAssists.autoClutch = UDPPacket::read<unsigned char>(&recv_pak) != 0;
      v67 = UDPPacket::read<unsigned char>(&recv_pak);
      if ( (_BYTE)v67 )
      {
        v68 = v67 - 1;
        if ( v68 )
        {
          if ( v68 == 1 )
            this->sim->physicsAvatar->engine.penaltyRules.jumpStartPenaltyMode = eDriveThroughMode;
        }
        else
        {
          this->sim->physicsAvatar->engine.penaltyRules.jumpStartPenaltyMode = eTeleportToPitMode;
        }
      }
      else
      {
        this->sim->physicsAvatar->engine.penaltyRules.jumpStartPenaltyMode = eLockOnGridMode;
      }
      this->sim->physicsAvatar->engine.mechanicalDamageRate = UDPPacket::read<float>(&recv_pak);
      this->sim->physicsAvatar->engine.fuelConsumptionRate = UDPPacket::read<float>(&recv_pak);
      this->sim->physicsAvatar->engine.tyreConsumptionRate = UDPPacket::read<float>(&recv_pak);
      this->sim->isVirtualMirrorForced = UDPPacket::read<unsigned char>(&recv_pak) != 0;
      this->wreckerProtection.maxContactsPerKM = (float)UDPPacket::read<unsigned char>(&recv_pak);
      this->raceOverTime = UDPPacket::read<unsigned int>(&recv_pak);
      this->resultScreenTime = UDPPacket::read<unsigned int>(&recv_pak);
      this->hasExtraLap = UDPPacket::read<unsigned char>(&recv_pak) != 0;
      this->isGasPenaltyDisabled = UDPPacket::read<unsigned char>(&recv_pak) != 0;
      this->pitWindowStart = (unsigned __int16)UDPPacket::read<unsigned short>(&recv_pak);
      this->pitWindowEnd = (unsigned __int16)UDPPacket::read<unsigned short>(&recv_pak);
      this->invertedGridPositions = (__int16)UDPPacket::read<short>(&recv_pak);
      v69 = UDPPacket::read<unsigned char>(&recv_pak);
      res.sessionID = v69;
      this->sessionID = v69;
      _printf("Server assigned sessionID: %d\n", v69);
      v70 = UDPPacket::read<unsigned char>(&recv_pak);
      v71 = v70;
      HIBYTE(v111) = 0;
      if ( !v70 )
        goto LABEL_117;
      break;
    case 'A':
      std::wstring::wstring(&v157, L"ACP_SERVER_STILL_BOOKING");
      LOBYTE(v187) = 96;
      ACClient::logMessage(this, &v157);
      LOBYTE(v187) = 58;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v157);
      v95 = UDPPacket::read<unsigned int>(&recv_pak);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v128,
        3,
        1);
      LOBYTE(v187) = 97;
      v96 = timeToSecsString(&v174, v95);
      *(_DWORD *)&_Val[24] = " ) seconds left, shutting down";
      *(_DWORD *)&_Val[20] = v96;
      LOBYTE(v187) = 98;
      v97 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(
              (std::wostream *)v128.gap10,
              "ERROR :: Server still booking ( ");
      v98 = std::operator<<<wchar_t>(v97, *(const std::wstring **)&_Val[20]);
      std::operator<<<wchar_t,std::char_traits<wchar_t>>(v98, *(const char **)&_Val[24]);
      LOBYTE(v187) = 97;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v174);
      v99 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v128, &v180);
      v100 = this->sim;
      LOBYTE(v187) = 99;
      Sim::setSplashMessage(v100, v99);
      LOBYTE(v187) = 97;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v180);
      res.success = 0;
      ksSleep(5000);
      v101 = &v128;
      goto LABEL_141;
    case 'B':
      std::wstring::wstring(&message, L"ACP_UNSUPPORTED_PROTOCOL");
      LOBYTE(v187) = 63;
      ACClient::logMessage(this, &message);
      LOBYTE(v187) = 58;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&message);
      _printf("ACClient:: ACP_UNSUPPORTED_PROTOCOL\n");
      std::wstring::wstring(&msg, L"ERROR :: Server is running a different protocol");
      v39 = this->sim;
      LOBYTE(v187) = 64;
      Sim::setSplashMessage(v39, &msg);
      v40 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&msg;
      goto LABEL_89;
    case 'E':
      std::wstring::wstring(&v156, L"ACP_NO_SLOTS_AVAILABLE");
      LOBYTE(v187) = 69;
      ACClient::logMessage(this, &v156);
      LOBYTE(v187) = 58;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v156);
      _printf("ACClient:: ACP_NO_SLOTS_AVAILABLE\n");
      std::wstring::wstring(&v158, L"Cannot join the server : no available slots");
      v43 = this->sim;
      LOBYTE(v187) = 70;
      Sim::setSplashMessage(v43, &v158);
      v40 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v158;
LABEL_89:
      LOBYTE(v187) = 58;
      std::wstring::~wstring(v40);
      res.success = 0;
      ksSleep(5000);
      goto LABEL_142;
    case 'n':
      std::wstring::wstring(&v151, L"ACP_SESSION_CLOSED");
      LOBYTE(v187) = 100;
      ACClient::logMessage(this, &v151);
      LOBYTE(v187) = 58;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v151);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &v129,
        3,
        1);
      LOBYTE(v187) = 101;
      std::operator<<<wchar_t,std::char_traits<wchar_t>>(
        (std::wostream *)v129.gap10,
        "ERROR :: Session is closed to new connections");
      v102 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v129, &v166);
      v103 = this->sim;
      LOBYTE(v187) = 102;
      Sim::setSplashMessage(v103, v102);
      LOBYTE(v187) = 101;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v166);
      res.success = 0;
      ksSleep(5000);
      v101 = &v129;
      goto LABEL_141;
    case 'o':
      _printf("ACClient:: ACP_AUTH_FAILED\n");
      UDPPacket::readStringW(&recv_pak, &legal_tyres_string);
      LOBYTE(v187) = 61;
      v37 = std::operator+<wchar_t>(&v170, L"SERVER AUTH FAILED:", &legal_tyres_string);
      v38 = this->sim;
      LOBYTE(v187) = 62;
      Sim::setSplashMessage(v38, v37);
      LOBYTE(v187) = 61;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v170);
      res.success = 0;
      ksSleep(5000);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&legal_tyres_string);
      goto LABEL_142;
    default:
      std::wstring::wstring(&v150, L"UNEXPECTED MESSAGE");
      LOBYTE(v187) = 103;
      ACClient::logMessage(this, &v150);
      LOBYTE(v187) = 58;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v150);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
        &ss2,
        3,
        1);
      LOBYTE(v187) = 104;
      v104 = UDPPacket::getSize(&recv_pak) == 0;
      v105 = (std::wostream *)ss2.gap10;
      if ( v104 )
      {
        *(_DWORD *)&_Val[24] = "Server error : No response from the server, shutting down";
      }
      else
      {
        *(_DWORD *)&_Val[24] = ", shutting down ";
        *(_DWORD *)&_Val[20] = v34;
        v106 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)ss2.gap10, "Server error code : ");
        v105 = (std::wostream *)std::wostream::operator<<(v106, *(_DWORD *)&_Val[20]);
      }
      std::operator<<<wchar_t,std::char_traits<wchar_t>>(v105, *(const char **)&_Val[24]);
      v107 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&ss2, &v167);
      v108 = this->sim;
      LOBYTE(v187) = 105;
      Sim::setSplashMessage(v108, v107);
      LOBYTE(v187) = 104;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v167);
      res.success = 0;
      ksSleep(5000);
      v101 = &ss2;
LABEL_141:
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(v101);
      goto LABEL_142;
  }
  do
  {
    RemoteSession::RemoteSession(&session);
    LOBYTE(v187) = 76;
    session.isTimedRace = 0;
    v72 = UDPPacket::read<unsigned char>(&recv_pak) - 1;
    if ( !v72 )
    {
LABEL_109:
      *(_DWORD *)&_Val[24] = L"Practice";
      session.type = Pratice;
      goto LABEL_110;
    }
    v73 = v72 - 1;
    if ( !v73 )
    {
      session.type = Qualify;
      *(_DWORD *)&_Val[24] = L"Qualify";
LABEL_110:
      std::wstring::assign(&session.name, *(const wchar_t **)&_Val[24]);
      goto LABEL_111;
    }
    if ( v73 != 1 )
      goto LABEL_109;
    session.type = Race;
    std::wstring::assign(&session.name, L"Race");
    HIBYTE(v111) = 1;
LABEL_111:
    session.laps = (unsigned __int16)UDPPacket::read<unsigned short>(&recv_pak);
    v74 = UDPPacket::read<unsigned short>(&recv_pak);
    session.time = v74;
    if ( session.type != Race || session.laps || (session.isTimedRace = 1, !v74) )
      session.isTimedRace = 0;
    std::vector<RemoteSession>::push_back(&this->sessions, &session);
    LOBYTE(v187) = 58;
    std::pair<std::wstring,jsonwriter::Node &>::~pair<std::wstring,jsonwriter::Node &>((MD5Result *)&session);
    --v71;
  }
  while ( v71 );
  if ( !HIBYTE(v111) )
  {
LABEL_117:
    this->pitWindowStart = 0;
    this->pitWindowEnd = 0;
  }
  v75 = std::operator+<wchar_t>(&v176, L"TRACK:", &res.track);
  LOBYTE(v187) = 77;
  ACClient::logMessage(this, v75);
  LOBYTE(v187) = 58;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v176);
  v76 = std::operator+<wchar_t>(&v168, L"MODEL:", &res.model);
  LOBYTE(v187) = 78;
  ACClient::logMessage(this, v76);
  LOBYTE(v187) = 58;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v168);
  v77 = std::operator+<wchar_t>(&v184, L"SKIN:", &res.skin);
  LOBYTE(v187) = 79;
  ACClient::logMessage(this, v77);
  LOBYTE(v187) = 58;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v184);
  v78 = std::to_wstring(&v178, res.sunAngle);
  LOBYTE(v187) = 80;
  v79 = std::operator+<wchar_t>(&v165, L"SUN ANGLE:", v78);
  LOBYTE(v187) = 81;
  ACClient::logMessage(this, v79);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v165);
  LOBYTE(v187) = 58;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v178);
  v80 = std::to_wstring(&v182, res.sessionID);
  LOBYTE(v187) = 82;
  v81 = std::operator+<wchar_t>(&v172, L"SESSION ID:", v80);
  LOBYTE(v187) = 83;
  ACClient::logMessage(this, v81);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v172);
  LOBYTE(v187) = 58;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v182);
  ACClient::onNewSession(this, &recv_pak, 1);
  v82 = UDPPacket::read<unsigned char>(&recv_pak);
  LODWORD(v113) = v82;
  std::vector<std::vector<LeaderboardEntry>>::resize(
    (std::vector<std::vector<WingState>> *)&this->checksumResults,
    v82 + 1);
  v83 = 0;
  if ( v82 <= 0 )
  {
LABEL_124:
    v88 = UDPPacket::readString(&recv_pak, &v148);
    LOBYTE(v187) = 90;
    string2wstring(&legal_tyres_string, v88);
    LOBYTE(v187) = 92;
    if ( v148._Myres >= 0x10 )
      operator delete(v148._Bx._Ptr);
    v148._Myres = 15;
    v148._Mysize = 0;
    v148._Bx._Buf[0] = 0;
    if ( legal_tyres_string._Mysize )
    {
      std::wstring::wstring(&splitter, L";");
      LOBYTE(v187) = 93;
      ksSplitString(&legal_tyres_list, &legal_tyres_string, &splitter);
      LOBYTE(v187) = 95;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&splitter);
      v89 = legal_tyres_list._Mylast;
      for ( i = legal_tyres_list._Myfirst; i != v89; ++i )
        PhysicsEngine::addLegalTyre(&this->sim->physicsAvatar->engine, i);
      LOBYTE(v187) = 92;
      std::vector<std::wstring>::_Tidy(&legal_tyres_list);
    }
    v91 = UDPPacket::read<unsigned int>(&recv_pak);
    _printf("Server send random seed:%u\n", v91);
    _srand(v91);
    v92 = ksGetTime();
    v93 = &v113;
    v113 = v92 - this->currentSession.startTime;
    *(_QWORD *)&legal_tyres_list._Myfirst = 0i64;
    if ( v113 <= 0.0 )
      v93 = &legal_tyres_list;
    *(_QWORD *)&_Val[20] = *v93;
    *(_DWORD *)&_Val[16] = "Server handshake time:%f\n";
    this->handshakeServerTimeS = *(long double *)&_Val[20];
    _printf(*(const char *const *)&_Val[16], *(_DWORD *)&_Val[20], *(_DWORD *)&_Val[24]);
    if ( legal_tyres_string._Myres >= 8 )
      operator delete(legal_tyres_string._Bx._Ptr);
LABEL_142:
    LOBYTE(v187) = 57;
    UDPPacket::~UDPPacket(&recv_pak);
LABEL_143:
    v109 = v114;
    ClientHandshakeResult::ClientHandshakeResult(v114, &res);
    v112 = 3;
    LOBYTE(v187) = 55;
    if ( pakdata._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&pakdata);
      operator delete(pakdata._Myfirst);
      pakdata._Myfirst = 0;
      pakdata._Mylast = 0;
      pakdata._Myend = 0;
    }
    if ( password._Myres >= 8 )
      operator delete(password._Bx._Ptr);
    password._Myres = 7;
    password._Mysize = 0;
    password._Bx._Buf[0] = 0;
    if ( myrequested_car._Myres >= 8 )
      operator delete(myrequested_car._Bx._Ptr);
    myrequested_car._Myres = 7;
    myrequested_car._Mysize = 0;
    myrequested_car._Bx._Buf[0] = 0;
    if ( mynation._Myres >= 8 )
      operator delete(mynation._Bx._Ptr);
    mynation._Myres = 7;
    mynation._Mysize = 0;
    mynation._Bx._Buf[0] = 0;
    if ( myteam._Myres >= 8 )
      operator delete(myteam._Bx._Ptr);
    myteam._Myres = 7;
    myteam._Mysize = 0;
    myteam._Bx._Buf[0] = 0;
    if ( myname._Myres >= 8 )
      operator delete(myname._Bx._Ptr);
    myname._Myres = 7;
    myname._Mysize = 0;
    myname._Bx._Buf[0] = 0;
    LOBYTE(v187) = 23;
    UDPPacket::~UDPPacket(&pak);
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v126);
    LOBYTE(v187) = 1;
    INIReaderDocuments::~INIReaderDocuments(&ini);
    ClientHandshakeResult::~ClientHandshakeResult(&res);
    return v109;
  }
  v84 = 0;
  while ( 1 )
  {
    v85 = UDPPacket::readString(&recv_pak, (std::string *)&v135);
    LOBYTE(v187) = 84;
    string2wstring((std::wstring *)&legal_tyres_list, v85);
    LOBYTE(v187) = 86;
    if ( v135._Myres >= 0x10 )
      operator delete(v135._Bx._Ptr);
    v135._Myres = 15;
    v135._Mysize = 0;
    v135._Bx._Alias[0] = 0;
    if ( !Path::fileExists((unsigned int)_printf, (const std::wstring *)&legal_tyres_list, 0) )
      break;
    v86 = (std::vector<WingState> *)md5((std::vector<unsigned char> *)&key, (const std::wstring *)&legal_tyres_list);
    v87 = this->checksumResults._Myfirst;
    LOBYTE(v187) = 89;
    std::vector<WingState>::operator=((std::vector<WingState> *)&v87[v84], v86);
    std::vector<LeaderboardEntry>::_Tidy((std::vector<vec3f> *)&key);
    LOBYTE(v187) = 58;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&legal_tyres_list);
    ++v83;
    ++v84;
    if ( v83 >= SLODWORD(v113) )
      goto LABEL_124;
  }
  std::wstring::wstring(&v162, L"PROBLEMS DURING CHECKSUM");
  v94 = this->sim;
  LOBYTE(v187) = 87;
  Sim::setSplashMessage(v94, &v162);
  LOBYTE(v187) = 86;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v162);
  std::wstring::wstring(&v164, L"Problems during checksum");
  LOBYTE(v187) = 88;
  ACClient::logMessage(this, &v164);
  LOBYTE(v187) = 86;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v164);
  res.success = 0;
  ksSleep(5000);
  ClientHandshakeResult::ClientHandshakeResult(v114, &res);
  v112 = 3;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&legal_tyres_list);
  LOBYTE(v187) = 57;
  UDPPacket::~UDPPacket(&recv_pak);
  std::vector<LeaderboardEntry>::_Tidy((std::vector<vec3f> *)&pakdata);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&password);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&myrequested_car);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&mynation);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&myteam);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&myname);
  LOBYTE(v187) = 23;
  UDPPacket::~UDPPacket(&pak);
LABEL_52:
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v126);
  LOBYTE(v187) = 1;
  INIReaderDocuments::~INIReaderDocuments(&ini);
  ClientHandshakeResult::~ClientHandshakeResult(&res);
  return v114;
}
bool ACClient::hasVoted(ACClient *this)
{
  return this->votingManager->currentVote.hasVoted;
}
bool ACClient::isAllowedToSendChatMessage(ACClient *this)
{
  return this->game->gameTime.now - this->lastChatMessage > 1000.0;
}
bool ACClient::isBestSplit(ACClient *this, const int *sector, const int *t, const bool *isGlobal, CarAvatar *car)
{
  char v7; // al
  NetCarStateProvider **v8; // ecx
  NetCarStateProvider **v9; // edx
  NetCarStateProvider *v10; // esi

  if ( !*t )
    return 0;
  if ( *isGlobal )
    return this->bestSplits._Myfirst[*sector] == *t;
  if ( !CarAvatar::getGuid(car) )
    return this->localCarBestSplits._Myfirst[*sector] == *t;
  v7 = ACClient::getSessionIDFromCarAvatar(this, car);
  v8 = this->netCars._Myfirst;
  v9 = this->netCars._Mylast;
  if ( v8 == v9 )
  {
LABEL_10:
    v10 = 0;
  }
  else
  {
    while ( 1 )
    {
      v10 = *v8;
      if ( (*v8)->sessionID == v7 )
        break;
      if ( ++v8 == v9 )
        goto LABEL_10;
    }
  }
  return v10->personalBestSplits._Myfirst[*sector] == *t;
}
void ACClient::logMessage(ACClient *this, const std::wstring *message)
{
  double v3; // st7
  std::wostream *v4; // eax
  std::wostream *v5; // eax
  std::wostream *v6; // eax
  std::wostream *v7; // eax
  const std::wstring *v8; // [esp-10h] [ebp-44h]
  std::wstring result; // [esp+Ch] [ebp-28h] BYREF
  int v10; // [esp+30h] [ebp-4h]

  if ( this->useLog )
  {
    v3 = ksGetTime();
    v8 = timeToString(&result, (int)v3, 3);
    v10 = 0;
    v4 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&this->log, "[");
    v5 = std::operator<<<wchar_t>(v4, v8);
    v6 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v5, "]:");
    v7 = std::operator<<<wchar_t>(v6, message);
    std::wostream::operator<<(v7);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
}
void ACClient::onCollisionEvent(ACClient *this, const OnCollisionEvent *ev)
{
  NetCarStateProvider **v2; // eax
  NetCarStateProvider **v3; // edx
  NetCarStateProvider *v4; // esi

  v2 = this->netCars._Myfirst;
  v3 = this->netCars._Mylast;
  if ( v2 == v3 )
  {
LABEL_4:
    v4 = 0;
  }
  else
  {
    while ( 1 )
    {
      v4 = *v2;
      if ( (*v2)->body == ev->body )
        break;
      if ( ++v2 == v3 )
        goto LABEL_4;
    }
  }
  ACClient::addCollisionEvent(this, v4, ev->relativeSpeed, &ev->worldPos, &ev->relPos);
  if ( v4 )
    v4->hasCollisionInThisStep = 1.0;
}
void ACClient::onCollisionWithCar(ACClient *this)
{
  long double v2; // st7
  int v3; // eax
  float v4; // xmm1_4
  int v5; // eax
  int v6; // eax
  Sim *v7; // ecx
  Sim *v8; // ecx
  std::function<void __cdecl(void)> v9; // [esp-4h] [ebp-5Ch] BYREF
  float v10; // [esp+24h] [ebp-34h]
  float current_km; // [esp+28h] [ebp-30h]
  UDPPacket pak; // [esp+2Ch] [ebp-2Ch] BYREF
  int v13; // [esp+54h] [ebp-4h]

  if ( this->wreckerProtection.maxContactsPerKM <= 0.0 )
    return;
  v2 = Car::getTotalKM(this->car);
  v3 = this->wreckerProtection.contacts + 1;
  current_km = v2;
  v4 = current_km;
  this->wreckerProtection.contacts = v3;
  v10 = (float)v3 / v4;
  _printf("Adding wrecking contact at km: %fm tot: %d, ratio: %f\n", v4, v3, v10);
  if ( current_km <= 1.0 || v10 <= this->wreckerProtection.maxContactsPerKM )
    return;
  v5 = this->wreckerProtection.warningCount;
  if ( !v5 )
  {
    v9._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_71deb67b0ca34dd63fec0c3a21e0c39f_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    v9._Space._Pfn[1] = (void (__cdecl *)())this;
    v9._Impl = (std::_Func_base<void> *)&v9;
    v8 = this->sim;
    v13 = -1;
    Sim::executeOnMainThread(v8, v9);
    this->wreckerProtection.warningCount = 1;
    goto LABEL_11;
  }
  v6 = v5 - 1;
  if ( !v6 )
  {
    v9._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_2bb6e88e9207602c4080d31c284a1a45_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    v9._Space._Pfn[1] = (void (__cdecl *)())this;
    v9._Impl = (std::_Func_base<void> *)&v9;
    v7 = this->sim;
    v13 = -1;
    Sim::executeOnMainThread(v7, v9);
    this->wreckerProtection.warningCount = 2;
LABEL_11:
    --this->wreckerProtection.contacts;
    return;
  }
  if ( v6 == 1 && !this->wreckerProtection.blackListRequested )
  {
    UDPPacket::UDPPacket(&pak);
    v13 = 2;
    pak.data[pak.size++] = 59;
    UDPPacket::send(&pak, &this->tcpSock);
    this->wreckerProtection.blackListRequested = 1;
    v13 = -1;
    UDPPacket::~UDPPacket(&pak);
  }
}
void ACClient::onDRSZoneReceived(ACClient *this, UDPPacket *pak)
{
  int v3; // ebx
  Track *v4; // eax
  int v5; // esi
  Track *v6; // [esp+38h] [ebp-5Ch]
  std::vector<DRSZone> zones; // [esp+3Ch] [ebp-58h] BYREF
  DRSZone zone; // [esp+48h] [ebp-4Ch] BYREF
  int v9; // [esp+90h] [ebp-4h]

  v3 = UDPPacket::read<unsigned char>(pak);
  _printf("RECEIVING %d DRS ZONES\n", v3);
  v4 = this->car->ksPhysics->track;
  v6 = v4;
  zones._Myfirst = 0;
  zones._Mylast = 0;
  zones._Myend = 0;
  v5 = 0;
  v9 = 0;
  if ( v3 > 0 )
  {
    do
    {
      zone.detection = 0.0;
      zone.start = UDPPacket::read<float>(pak);
      zone.end = UDPPacket::read<float>(pak);
      _printf("ADDING ZONE: %d (%f,%f)\n", v5, zone.start, zone.end);
      std::vector<DRSZone>::push_back((std::vector<vec3f> *)&zones, (const vec3f *)&zone);
      ++v5;
    }
    while ( v5 < v3 );
    v4 = v6;
  }
  DRSManager::setZones(v4->drsMamanger._Myptr, &zones);
  v9 = -1;
  if ( zones._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&zones);
    operator delete(zones._Myfirst);
  }
}
void ACClient::onLapCompleted(ACClient *this, const OnLapCompletedEvent *ev)
{
  unsigned int v3; // ecx
  unsigned int v4; // eax
  Car *v5; // eax
  int v6; // edi
  unsigned int v7; // ecx
  int v8; // ecx
  unsigned int *v9; // ecx
  unsigned int *v10; // eax
  unsigned int v11; // esi
  unsigned int v12; // ebx
  int *v13; // ecx
  Car *v14; // eax
  IPAddress v15; // xmm0
  int v16; // [esp+14h] [ebp-30h] BYREF
  UDPPacket pak; // [esp+18h] [ebp-2Ch] BYREF
  int v18; // [esp+40h] [ebp-4h]

  if ( !ev->carIndex )
  {
    v3 = this->instanceLocalCarBestLap;
    v4 = ev->lapTime;
    if ( v4 < v3 || !v3 )
      this->instanceLocalCarBestLap = v4;
    UDPPacket::UDPPacket(&pak);
    v18 = 0;
    pak.data[pak.size] = 73;
    v5 = this->car;
    ++pak.size;
    v6 = 0;
    *(_DWORD *)&pak.data[pak.size] = (unsigned int)v5->ksPhysics->physicsTime;
    v7 = ev->lapTime;
    pak.size += 4;
    *(_DWORD *)&pak.data[pak.size] = v7;
    v8 = ev->splits._Mylast - ev->splits._Myfirst;
    pak.size += 4;
    pak.data[pak.size] = v8;
    v9 = ev->splits._Myfirst;
    v10 = ev->splits._Mylast;
    v11 = pak.size + 1;
    v12 = (unsigned int)((char *)v10 - (char *)v9 + 3) >> 2;
    ++pak.size;
    if ( v9 > v10 )
      v12 = 0;
    if ( v12 )
    {
      do
      {
        ++v9;
        ++v6;
        *(_DWORD *)&pak.data[v11] = *(v9 - 1);
        v11 = pak.size + 4;
        pak.size += 4;
      }
      while ( v6 != v12 );
    }
    v13 = &v16;
    v16 = 255;
    if ( ev->cuts < 255 )
      v13 = &ev->cuts;
    pak.data[v11] = *(_BYTE *)v13;
    v14 = this->car;
    pak.data[++pak.size] = v14->transponder.lapCount;
    v15 = (IPAddress)_mm_loadu_si128((const __m128i *)&this->serverIP);
    ++pak.size;
    pak.targetIP = v15;
    UDPPacket::send(&pak, &this->tcpSock);
    v18 = -1;
    UDPPacket::~UDPPacket(&pak);
  }
}
void ACClient::onMessage(ACClient *this, const UDPMessage *msg)
{
  ACClient *v2; // edi
  int i; // esi
  int v4; // esi
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  std::wstring *v12; // eax
  std::wstring *v13; // edi
  std::wstring *v14; // esi
  std::wstring *v15; // eax
  std::wstring *v16; // eax
  std::wstring *v17; // eax
  std::wstring *v18; // eax
  std::wstring *v19; // eax
  const std::wstring *v20; // eax
  NetCarStateProvider *v21; // esi
  int v22; // esi
  int v23; // edi
  std::wstring *v24; // edi
  std::wstring *v25; // eax
  std::wstring *v26; // eax
  std::wstring *v27; // eax
  std::wstring *v28; // eax
  std::wstring *v29; // eax
  const std::wstring *v30; // eax
  int v31; // esi
  int v32; // ecx
  float v33; // xmm0_4
  float v34; // xmm1_4
  unsigned int v35; // eax
  std::wstring **v36; // ecx
  std::wstring **v37; // eax
  std::wstring *v38; // edi
  std::wstring *v39; // esi
  std::wstring *v40; // eax
  std::wstring *v41; // eax
  std::wstring *v42; // eax
  std::wstring *v43; // eax
  std::wstring *v44; // eax
  const std::wstring *v45; // eax
  std::wstring *v46; // esi
  std::function<void __cdecl(void)> v47; // [esp+Ch] [ebp-418h] BYREF
  vec3f v48; // [esp+30h] [ebp-3F4h] BYREF
  vec3f v49; // [esp+3Ch] [ebp-3E8h] BYREF
  vec3f v50; // [esp+48h] [ebp-3DCh] BYREF
  vec3f result; // [esp+54h] [ebp-3D0h] BYREF
  vec3f v52; // [esp+60h] [ebp-3C4h] BYREF
  vec3f v53; // [esp+6Ch] [ebp-3B8h] BYREF
  ACClient::onMessage::__l11::<lambda_89215cb97f19fb82d16432a1c1a52916> _Func; // [esp+78h] [ebp-3ACh] BYREF
  double v55; // [esp+88h] [ebp-39Ch]
  ACClient *v56; // [esp+90h] [ebp-394h]
  NetCarStateProvider *v57; // [esp+94h] [ebp-390h]
  int v58; // [esp+98h] [ebp-38Ch]
  std::wstring *_Right[2]; // [esp+9Ch] [ebp-388h]
  unsigned __int8 v60; // [esp+A6h] [ebp-37Eh]
  unsigned __int8 v61; // [esp+A7h] [ebp-37Dh]
  NetCarState v62; // [esp+A8h] [ebp-37Ch] BYREF
  NetCarState s; // [esp+130h] [ebp-2F4h] BYREF
  std::wstring v64; // [esp+1B8h] [ebp-26Ch] BYREF
  std::wstring v65; // [esp+1D0h] [ebp-254h] BYREF
  std::wstring v66; // [esp+1E8h] [ebp-23Ch] BYREF
  std::wstring v67; // [esp+200h] [ebp-224h] BYREF
  std::wstring v68; // [esp+218h] [ebp-20Ch] BYREF
  std::wstring v69; // [esp+230h] [ebp-1F4h] BYREF
  std::wstring v70; // [esp+248h] [ebp-1DCh] BYREF
  std::wstring v71; // [esp+260h] [ebp-1C4h] BYREF
  std::wstring v72; // [esp+278h] [ebp-1ACh] BYREF
  std::wstring v73; // [esp+290h] [ebp-194h] BYREF
  std::wstring v74; // [esp+2A8h] [ebp-17Ch] BYREF
  std::wstring v75; // [esp+2C0h] [ebp-164h] BYREF
  std::wstring v76; // [esp+2D8h] [ebp-14Ch] BYREF
  std::wstring v77; // [esp+2F0h] [ebp-134h] BYREF
  std::wstring v78; // [esp+308h] [ebp-11Ch] BYREF
  std::wstring v79; // [esp+320h] [ebp-104h] BYREF
  std::wstring v80; // [esp+338h] [ebp-ECh] BYREF
  std::wstring v81; // [esp+350h] [ebp-D4h] BYREF
  std::wstring v82; // [esp+368h] [ebp-BCh] BYREF
  std::wstring v83; // [esp+380h] [ebp-A4h] BYREF
  std::wstring v84; // [esp+398h] [ebp-8Ch] BYREF
  std::wstring v85; // [esp+3B0h] [ebp-74h] BYREF
  std::wstring v86; // [esp+3C8h] [ebp-5Ch] BYREF
  std::wstring v87; // [esp+3E0h] [ebp-44h] BYREF
  UDPPacket v88; // [esp+3F8h] [ebp-2Ch] BYREF
  int v89; // [esp+420h] [ebp-4h]

  v2 = this;
  v56 = this;
  UDPPacket::UDPPacket(&v88, msg);
  v89 = 0;
  v60 = UDPPacket::read<unsigned char>(&v88);
LABEL_3:
  for ( i = 0; !UDPPacket::isEOF(&v88) || UDPPacket::getSize(&v88) == 1 && !i; i = v58 )
  {
    v58 = ++i;
    switch ( v60 )
    {
      case 'F':
        v61 = UDPPacket::read<unsigned char>(&v88);
        NetCarState::NetCarState(&s);
        s.pakSequenceId = UDPPacket::read<unsigned char>(&v88);
        s.timeStamp = (double)UDPPacket::read<unsigned int>(&v88);
        s.ping = (unsigned __int16)UDPPacket::read<unsigned short>(&v88);
        s.pos = *UDPPacket::read<vec3f>(&v88, &result);
        s.rotation = *UDPPacket::read<vec3f>(&v88, &v53);
        v6 = 0;
        s.velocity = *UDPPacket::read<vec3f>(&v88, &v52);
        s.rcvTime = v2->sim->physicsAvatar->engine.physicsTime;
        do
        {
          *(float *)&_Right[1] = (float)UDPPacket::read<unsigned char>(&v88) - 100.0;
          LODWORD(v8) = __libm_sse2_powf(v7).m128_u32[0];
          if ( *(float *)&_Right[1] <= 0.0 )
          {
            if ( *(float *)&_Right[1] >= 0.0 )
              v10 = 0.0;
            else
              v10 = FLOAT_N1_0;
            v9 = FLOAT_1_0;
          }
          else
          {
            v9 = FLOAT_1_0;
            v10 = FLOAT_1_0;
          }
          s.tyreAngularSpeed[v6++] = (float)(v8 - v9) * v10;
        }
        while ( v6 < 4 );
        s.steerAngle = (float)UDPPacket::read<unsigned char>(&v88) - 127.0;
        s.wheelAngle = (float)((float)UDPPacket::read<unsigned char>(&v88) - 127.0) * 0.5;
        s.engineRPM = UDPPacket::read<unsigned short>(&v88);
        s.gearIndex = UDPPacket::read<unsigned char>(&v88);
        s.statusBytes = UDPPacket::read<unsigned int>(&v88);
        s.performanceDelta = (float)(__int16)UDPPacket::read<short>(&v88) * 0.001;
        v11 = (float)UDPPacket::read<unsigned char>(&v88) * 0.0039215689;
        if ( v11 <= 1.0 )
        {
          if ( v11 >= 0.0 )
            s.gas = v11;
          else
            s.gas = 0.0;
        }
        else
        {
          s.gas = 1.0;
        }
        v12 = (std::wstring *)v2->netCars._Myfirst;
        _Right[1] = (std::wstring *)v2->netCars._Mylast;
        if ( v12 == _Right[1] )
          goto LABEL_26;
        while ( 1 )
        {
          v57 = (NetCarStateProvider *)v12->_Bx._Ptr;
          if ( v57->sessionID == v61 )
            break;
          v12 = (std::wstring *)((char *)v12 + 4);
          if ( v12 == _Right[1] )
          {
LABEL_26:
            v57 = 0;
            break;
          }
        }
        v13 = std::to_wstring(&v86, s.pakSequenceId);
        LOBYTE(v89) = 1;
        v14 = timeToString(&v87, (int)s.timeStamp, 3);
        LOBYTE(v89) = 2;
        v15 = std::to_wstring(&v70, v61);
        LOBYTE(v89) = 3;
        v16 = std::operator+<wchar_t>(&v78, L"CSU|", v15);
        LOBYTE(v89) = 4;
        v17 = std::operator+<wchar_t>(&v68, v16, L"|");
        LOBYTE(v89) = 5;
        v18 = std::operator+<wchar_t>(&v80, v17, v14);
        LOBYTE(v89) = 6;
        v19 = std::operator+<wchar_t>(&v72, v18, L"|");
        LOBYTE(v89) = 7;
        v20 = std::operator+<wchar_t>(&v82, v19, v13);
        v2 = v56;
        LOBYTE(v89) = 8;
        ACClient::logMessage(v56, v20);
        if ( v82._Myres >= 8 )
          operator delete(v82._Bx._Ptr);
        v82._Myres = 7;
        v82._Mysize = 0;
        v82._Bx._Buf[0] = 0;
        if ( v72._Myres >= 8 )
          operator delete(v72._Bx._Ptr);
        v72._Myres = 7;
        v72._Mysize = 0;
        v72._Bx._Buf[0] = 0;
        if ( v80._Myres >= 8 )
          operator delete(v80._Bx._Ptr);
        v80._Myres = 7;
        v80._Mysize = 0;
        v80._Bx._Buf[0] = 0;
        if ( v68._Myres >= 8 )
          operator delete(v68._Bx._Ptr);
        v68._Myres = 7;
        v68._Mysize = 0;
        v68._Bx._Buf[0] = 0;
        if ( v78._Myres >= 8 )
          operator delete(v78._Bx._Ptr);
        v78._Myres = 7;
        v78._Mysize = 0;
        v78._Bx._Buf[0] = 0;
        if ( v70._Myres >= 8 )
          operator delete(v70._Bx._Ptr);
        v70._Myres = 7;
        v70._Mysize = 0;
        v70._Bx._Buf[0] = 0;
        if ( v87._Myres >= 8 )
          operator delete(v87._Bx._Ptr);
        v87._Myres = 7;
        v87._Mysize = 0;
        v87._Bx._Buf[0] = 0;
        LOBYTE(v89) = 0;
        if ( v86._Myres >= 8 )
          operator delete(v86._Bx._Ptr);
        v21 = v57;
        v86._Myres = 7;
        v86._Mysize = 0;
        v86._Bx._Buf[0] = 0;
        if ( v57 )
        {
          NetCarStateProvider::onRemoteStateReceived(v57, &s);
          v21->hasEverReceivedAPacket = 1;
        }
        continue;
      case 'H':
        ++v2->qos.counter;
        UDPPacket::read<unsigned int>(&v88);
        v22 = (unsigned __int16)UDPPacket::read<unsigned short>(&v88);
        v23 = UDPPacket::read<unsigned char>(&v88);
        v57 = (NetCarStateProvider *)v23;
        _Right[1] = std::to_wstring(&v79, v56->qos.lastQOS);
        LOBYTE(v89) = 9;
        v24 = std::to_wstring(&v81, v23);
        LOBYTE(v89) = 10;
        v25 = std::to_wstring(&v83, v22);
        LOBYTE(v89) = 11;
        v26 = std::operator+<wchar_t>(&v85, L"SU|", v25);
        LOBYTE(v89) = 12;
        v27 = std::operator+<wchar_t>(&v84, v26, L"|");
        LOBYTE(v89) = 13;
        v28 = std::operator+<wchar_t>(&v74, v27, v24);
        LOBYTE(v89) = 14;
        v29 = std::operator+<wchar_t>(&v65, v28, L"|");
        LOBYTE(v89) = 15;
        v30 = std::operator+<wchar_t>(&v76, v29, _Right[1]);
        v2 = v56;
        LOBYTE(v89) = 16;
        ACClient::logMessage(v56, v30);
        if ( v76._Myres >= 8 )
          operator delete(v76._Bx._Ptr);
        v76._Myres = 7;
        v76._Mysize = 0;
        v76._Bx._Buf[0] = 0;
        if ( v65._Myres >= 8 )
          operator delete(v65._Bx._Ptr);
        v65._Myres = 7;
        v65._Mysize = 0;
        v65._Bx._Buf[0] = 0;
        if ( v74._Myres >= 8 )
          operator delete(v74._Bx._Ptr);
        v74._Myres = 7;
        v74._Mysize = 0;
        v74._Bx._Buf[0] = 0;
        if ( v84._Myres >= 8 )
          operator delete(v84._Bx._Ptr);
        v84._Myres = 7;
        v84._Mysize = 0;
        v84._Bx._Buf[0] = 0;
        if ( v85._Myres >= 8 )
          operator delete(v85._Bx._Ptr);
        v85._Myres = 7;
        v85._Mysize = 0;
        v85._Bx._Buf[0] = 0;
        if ( v83._Myres >= 8 )
          operator delete(v83._Bx._Ptr);
        v83._Myres = 7;
        v83._Mysize = 0;
        v83._Bx._Buf[0] = 0;
        if ( v81._Myres >= 8 )
          operator delete(v81._Bx._Ptr);
        v81._Myres = 7;
        v81._Mysize = 0;
        v81._Bx._Buf[0] = 0;
        LOBYTE(v89) = 0;
        if ( v79._Myres >= 8 )
          operator delete(v79._Bx._Ptr);
        i = v58;
        v79._Myres = 7;
        v79._Mysize = 0;
        v79._Bx._Buf[0] = 0;
        if ( (int)v57 <= 0 )
          goto LABEL_3;
        break;
      case 'N':
        v2->isAssociated = 1;
        goto LABEL_3;
      case 'W':
        *(double *)_Right = (double)(int)UDPPacket::read<unsigned int>(&v88);
        v55 = (double)UDPPacket::read<unsigned int>(&v88);
        v4 = (unsigned __int16)UDPPacket::read<unsigned short>(&v88);
        *(long double *)&v47._Impl = v2->car->ksPhysics->physicsTime;
        *(double *)&v47._Space._Alias[8] = v55;
        _printf(
          "ACP_RACE_START_UPDATE: %f (%f) PING: %d, local guess:%.1f real:%.1f\n",
          *(double *)_Right,
          (double)v2->currentSession.startTime,
          v4,
          v55,
          *(double *)&v47._Impl);
        v5 = 2 * v4;
        i = v58;
        if ( (double)v5 <= COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v2->car->ksPhysics->physicsTime - v55) & _xmm) )
          goto LABEL_3;
        _Func.start_time = *(long double *)_Right;
        _Func.__this = v2;
        std::function<void __cdecl (void)>::function<void __cdecl (void)>(&v47, &_Func);
        Sim::executeOnMainThread(v2->sim, v47);
        PhysicsEngine::setCurrentSessionStartTime(v2->car->ksPhysics, *(const long double *)_Right);
        continue;
      default:
        _printf("ERROR: ACClient CRITICAL ERROR :: Unknown packet id: %d RETURNING\n", v60);
        goto LABEL_96;
    }
    do
    {
      v61 = UDPPacket::read<unsigned char>(&v88);
      NetCarState::NetCarState(&v62);
      v62.pakSequenceId = UDPPacket::read<unsigned char>(&v88);
      v62.timeStamp = (double)UDPPacket::read<unsigned int>(&v88);
      v62.ping = (unsigned __int16)UDPPacket::read<unsigned short>(&v88);
      v62.pos = *UDPPacket::read<vec3f>(&v88, &v50);
      v62.rotation = *UDPPacket::read<vec3f>(&v88, &v48);
      v31 = 0;
      v62.velocity = *UDPPacket::read<vec3f>(&v88, &v49);
      v62.rcvTime = v2->sim->physicsAvatar->engine.physicsTime;
      do
      {
        *(float *)&_Right[1] = (float)UDPPacket::read<unsigned char>(&v88) - 100.0;
        LODWORD(v33) = __libm_sse2_powf(v32).m128_u32[0];
        if ( *(float *)&_Right[1] <= 0.0 )
        {
          if ( *(float *)&_Right[1] >= 0.0 )
            v34 = 0.0;
          else
            v34 = FLOAT_N1_0;
        }
        else
        {
          v34 = FLOAT_1_0;
        }
        v62.tyreAngularSpeed[v31++] = (float)(v33 - 1.0) * v34;
      }
      while ( v31 < 4 );
      v62.steerAngle = (float)UDPPacket::read<unsigned char>(&v88) - 127.0;
      v62.wheelAngle = (float)((float)UDPPacket::read<unsigned char>(&v88) - 127.0) * 0.5;
      v62.engineRPM = UDPPacket::read<unsigned short>(&v88);
      v62.gearIndex = UDPPacket::read<unsigned char>(&v88);
      v35 = UDPPacket::read<unsigned int>(&v88);
      v36 = (std::wstring **)v2->netCars._Mylast;
      v62.statusBytes = v35;
      v37 = (std::wstring **)v2->netCars._Myfirst;
      HIDWORD(v55) = v36;
      if ( v37 == v36 )
      {
LABEL_72:
        _Right[1] = 0;
      }
      else
      {
        while ( 1 )
        {
          _Right[1] = *v37;
          if ( LOBYTE(_Right[1][2]._Myres) == v61 )
            break;
          if ( ++v37 == (std::wstring **)HIDWORD(v55) )
            goto LABEL_72;
        }
      }
      v38 = std::to_wstring(&v67, v62.pakSequenceId);
      LOBYTE(v89) = 17;
      v39 = timeToString(&v64, (int)v62.timeStamp, 3);
      LOBYTE(v89) = 18;
      v40 = std::to_wstring(&v66, v61);
      LOBYTE(v89) = 19;
      v41 = std::operator+<wchar_t>(&v69, L"CU|", v40);
      LOBYTE(v89) = 20;
      v42 = std::operator+<wchar_t>(&v71, v41, L"|");
      LOBYTE(v89) = 21;
      v43 = std::operator+<wchar_t>(&v73, v42, v39);
      LOBYTE(v89) = 22;
      v44 = std::operator+<wchar_t>(&v75, v43, L"|");
      LOBYTE(v89) = 23;
      v45 = std::operator+<wchar_t>(&v77, v44, v38);
      v2 = v56;
      LOBYTE(v89) = 24;
      ACClient::logMessage(v56, v45);
      if ( v77._Myres >= 8 )
        operator delete(v77._Bx._Ptr);
      v77._Myres = 7;
      v77._Mysize = 0;
      v77._Bx._Buf[0] = 0;
      if ( v75._Myres >= 8 )
        operator delete(v75._Bx._Ptr);
      v75._Myres = 7;
      v75._Mysize = 0;
      v75._Bx._Buf[0] = 0;
      if ( v73._Myres >= 8 )
        operator delete(v73._Bx._Ptr);
      v73._Myres = 7;
      v73._Mysize = 0;
      v73._Bx._Buf[0] = 0;
      if ( v71._Myres >= 8 )
        operator delete(v71._Bx._Ptr);
      v71._Myres = 7;
      v71._Mysize = 0;
      v71._Bx._Buf[0] = 0;
      if ( v69._Myres >= 8 )
        operator delete(v69._Bx._Ptr);
      v69._Myres = 7;
      v69._Mysize = 0;
      v69._Bx._Buf[0] = 0;
      if ( v66._Myres >= 8 )
        operator delete(v66._Bx._Ptr);
      v66._Myres = 7;
      v66._Mysize = 0;
      v66._Bx._Buf[0] = 0;
      if ( v64._Myres >= 8 )
        operator delete(v64._Bx._Ptr);
      v64._Myres = 7;
      v64._Mysize = 0;
      v64._Bx._Buf[0] = 0;
      LOBYTE(v89) = 0;
      if ( v67._Myres >= 8 )
        operator delete(v67._Bx._Ptr);
      v46 = _Right[1];
      v67._Myres = 7;
      v67._Mysize = 0;
      v67._Bx._Buf[0] = 0;
      if ( _Right[1] )
      {
        NetCarStateProvider::onRemoteStateReceived((NetCarStateProvider *)_Right[1], &v62);
        v46[11]._Bx._Alias[8] = 1;
      }
      v57 = (NetCarStateProvider *)((char *)v57 - 1);
    }
    while ( v57 );
  }
  if ( i != 1 )
    _printf("WARNING: client onMessage loops!=1 %d\n", i);
LABEL_96:
  v89 = -1;
  UDPPacket::~UDPPacket(&v88);
}
void ACClient::onMessageTCP(ACClient *this, const UDPMessage *msg)
{
  ACClient *v2; // ebx
  void (*v3)(const char *const, ...); // edi
  int v4; // esi
  DriverInfo *v5; // eax
  Car *v6; // eax
  int v7; // eax
  std::wstring *v8; // esi
  std::wstring *v9; // eax
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  std::wstring *v12; // eax
  std::wstring *v13; // eax
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v14; // ecx
  std::wstring *v15; // esi
  std::wstring *v16; // eax
  std::wstring *v17; // eax
  std::wstring *v18; // eax
  std::wstring *v19; // eax
  std::wstring *v20; // eax
  unsigned __int8 v21; // al
  float *v22; // ecx
  float *v23; // edx
  float v24; // eax
  int i; // esi
  unsigned __int8 v26; // bl
  float v27; // esi
  unsigned __int8 v28; // al
  NetCarStateProvider *v29; // eax
  NetCarStateProvider *v30; // esi
  CarAvatar *v31; // eax
  Sim *v32; // ecx
  CarAvatar *v33; // eax
  unsigned __int8 v34; // bh
  bool v35; // bl
  bool v36; // zf
  void (__cdecl *v37)(); // eax
  Sim *v38; // ecx
  unsigned __int8 v39; // al
  unsigned __int8 v40; // al
  CarAvatar *v41; // esi
  double v42; // st7
  unsigned __int8 v43; // dl
  Sim *v44; // ecx
  std::_Func_base<void> *v45; // ecx
  NetCarStateProvider **v46; // eax
  NetCarStateProvider **v47; // ecx
  NetCarStateProvider *v48; // esi
  Sim *v49; // ecx
  Sim *v50; // ecx
  std::_Func_base<void> *v51; // ecx
  NetCarStateProvider **v52; // eax
  NetCarStateProvider **v53; // ecx
  NetCarStateProvider *v54; // esi
  Sim *v55; // ecx
  const std::string *v56; // eax
  NetCarStateProvider **v57; // eax
  NetCarStateProvider **v58; // ecx
  float v59; // xmm1_4
  float v60; // xmm0_4
  int v61; // esi
  Speed *v62; // eax
  std::wstring *v63; // ecx
  Car *v64; // eax
  unsigned __int8 v65; // bl
  unsigned __int8 v66; // al
  NetCarStateProvider **v67; // ecx
  NetCarStateProvider **v68; // edx
  NetCarStateProvider *v69; // esi
  const wchar_t *v70; // eax
  unsigned __int8 v71; // al
  unsigned __int8 v72; // al
  NetCarStateProvider **v73; // ecx
  NetCarStateProvider **v74; // edx
  NetCarStateProvider *v75; // esi
  std::wstring *v76; // eax
  const std::string *v77; // eax
  const std::string *v78; // eax
  ACClient::onMessageTCP::__l119::<lambda_88b327a3fa7ea4738e9f6936855fc9a2> *v79; // eax
  NetCarStateProvider *v80; // eax
  float v81; // esi
  int v82; // eax
  int v83; // edi
  std::wstring *v84; // edi
  std::wstring *v85; // esi
  std::wstring *v86; // eax
  std::wstring *v87; // eax
  std::wstring *v88; // eax
  std::wstring *v89; // eax
  std::wstring *v90; // eax
  std::wstring *v91; // eax
  std::wstring *v92; // eax
  const std::wstring *v93; // eax
  int v94; // eax
  Sim *v95; // eax
  unsigned __int8 v96; // al
  bool v97; // cl
  unsigned __int8 v98; // al
  unsigned __int8 v99; // al
  unsigned __int8 v100; // dl
  bool v101; // cl
  unsigned __int8 v102; // bl
  unsigned __int8 v103; // al
  ACClient *v104; // esi
  unsigned __int8 v105; // bh
  CarAvatar *v106; // eax
  int v107; // eax
  ACClient::onMessageTCP::__l165::<lambda_d56d12ec4c2d04f70226b1d95868e0f3> *v108; // eax
  Sim *v109; // ecx
  std::_Func_class<void> v110[3]; // [esp-4h] [ebp-59Ch] BYREF
  unsigned __int8 v111; // [esp+5Fh] [ebp-539h]
  float restrictor; // [esp+60h] [ebp-538h]
  int v113; // [esp+64h] [ebp-534h]
  std::_Func_class<void> *v114; // [esp+68h] [ebp-530h]
  ACClient *_This; // [esp+6Ch] [ebp-52Ch]
  float ballastKG; // [esp+70h] [ebp-528h]
  CarAvatar *v117; // [esp+74h] [ebp-524h]
  OnGearRequestEvent v118; // [esp+7Ah] [ebp-51Eh] BYREF
  Speed v119; // [esp+84h] [ebp-514h] BYREF
  int kickedSessionID; // [esp+88h] [ebp-510h]
  int sid; // [esp+8Ch] [ebp-50Ch]
  unsigned __int8 id[4]; // [esp+90h] [ebp-508h]
  ACClient::onMessageTCP::__l110::<lambda_62015fcb806c2b758d752e087f67d5bf> v123; // [esp+94h] [ebp-504h] BYREF
  OnGearRequestEvent v124; // [esp+9Ch] [ebp-4FCh] BYREF
  float v125; // [esp+A8h] [ebp-4F0h]
  float v126; // [esp+ACh] [ebp-4ECh]
  float v127; // [esp+B8h] [ebp-4E0h]
  unsigned int v128; // [esp+BCh] [ebp-4DCh]
  float v129; // [esp+C4h] [ebp-4D4h]
  UDPPacket pak; // [esp+CCh] [ebp-4CCh] BYREF
  ReceivedVoteDef message; // [esp+E8h] [ebp-4B0h] BYREF
  std::wstring new_nation_code; // [esp+104h] [ebp-494h] BYREF
  std::wstring detail_msg; // [esp+11Ch] [ebp-47Ch] BYREF
  ACClient::onMessageTCP::__l103::<lambda_77fa972dbd724f64a8dd777ab67ae855> v134; // [esp+134h] [ebp-464h] BYREF
  std::wstring name; // [esp+150h] [ebp-448h] BYREF
  ACClient::onMessageTCP::__l117::<lambda_d9012094a323e946664e4993e5a2e310> v136; // [esp+168h] [ebp-430h] BYREF
  ACClient::onMessageTCP::__l105::<lambda_034d48754ea12fd9a7c51584058b5d75> v137; // [esp+188h] [ebp-410h] BYREF
  std::wstring v138; // [esp+1A8h] [ebp-3F0h] BYREF
  std::wstring v139; // [esp+1C0h] [ebp-3D8h] BYREF
  std::wstring v140; // [esp+1D8h] [ebp-3C0h] BYREF
  std::wstring v141; // [esp+1F0h] [ebp-3A8h] BYREF
  std::wstring v142; // [esp+208h] [ebp-390h] BYREF
  std::wstring v143; // [esp+220h] [ebp-378h] BYREF
  std::wstring v144; // [esp+238h] [ebp-360h] BYREF
  std::string v145; // [esp+250h] [ebp-348h] BYREF
  ACClient::onMessageTCP::__l18::<lambda_8ed240dda8b0abb382e2531a3d8b0b1c> v146; // [esp+268h] [ebp-330h] BYREF
  std::wstring v147; // [esp+284h] [ebp-314h] BYREF
  ACClient::onMessageTCP::__l99::<lambda_8edb651378e071f764f5bb6737b5a2e3> _Func; // [esp+29Ch] [ebp-2FCh] BYREF
  std::wstring v149; // [esp+2B8h] [ebp-2E0h] BYREF
  std::wstring v150; // [esp+2D0h] [ebp-2C8h] BYREF
  ACClient::onMessageTCP::__l127::<lambda_e537553689fc017a9af3740e06575ef5> _Val; // [esp+2E8h] [ebp-2B0h] BYREF
  std::wstring v152; // [esp+308h] [ebp-290h] BYREF
  std::wstring v153; // [esp+320h] [ebp-278h] BYREF
  std::wstring v154; // [esp+338h] [ebp-260h] BYREF
  std::wstring __message; // [esp+350h] [ebp-248h] BYREF
  std::wstring v156; // [esp+368h] [ebp-230h] BYREF
  std::wstring text; // [esp+380h] [ebp-218h] BYREF
  std::wstring result; // [esp+398h] [ebp-200h] BYREF
  std::wstring v159; // [esp+3B0h] [ebp-1E8h] BYREF
  std::wstring v160; // [esp+3C8h] [ebp-1D0h] BYREF
  std::wstring v161; // [esp+3E0h] [ebp-1B8h] BYREF
  std::wstring v162; // [esp+3F8h] [ebp-1A0h] BYREF
  std::wstring v163; // [esp+410h] [ebp-188h] BYREF
  std::string v164; // [esp+428h] [ebp-170h] BYREF
  std::wstring v165; // [esp+440h] [ebp-158h] BYREF
  std::wstring v166; // [esp+458h] [ebp-140h] BYREF
  std::wstring v167; // [esp+470h] [ebp-128h] BYREF
  std::wstring v168; // [esp+488h] [ebp-110h] BYREF
  std::wstring v169; // [esp+4A0h] [ebp-F8h] BYREF
  std::wstring v170; // [esp+4B8h] [ebp-E0h] BYREF
  std::string v171; // [esp+4D0h] [ebp-C8h] BYREF
  ACClient::onMessageTCP::__l165::<lambda_d56d12ec4c2d04f70226b1d95868e0f3> v172; // [esp+4E8h] [ebp-B0h] BYREF
  ACClient::onMessageTCP::__l119::<lambda_88b327a3fa7ea4738e9f6936855fc9a2> v173; // [esp+51Ch] [ebp-7Ch] BYREF
  int v174; // [esp+594h] [ebp-4h]

  v2 = this;
  _This = this;
  UDPPacket::UDPPacket(&pak, msg);
  v174 = 0;
  v3 = (void (*)(const char *const, ...))_printf;
  v4 = 0;
  BYTE1(v118.request) = UDPPacket::read<unsigned char>(&pak);
LABEL_4:
  while ( !UDPPacket::isEOF(&pak) || UDPPacket::getSize(&pak) == 1 && !v4 )
  {
    v113 = ++v4;
    switch ( BYTE1(v118.request) )
    {
      case 0xD:
        v26 = UDPPacket::read<unsigned char>(&pak);
        id[0] = v26;
        LODWORD(v27) = (unsigned __int16)UDPPacket::read<short>(&pak);
        ballastKG = v27;
        v28 = UDPPacket::read<unsigned char>(&pak);
        LODWORD(restrictor) = SLOWORD(v27);
        v111 = v28 != 0;
        v3("ACP_CE_P2P Car %i Count %i Activate %i \n", v26, SLOWORD(v27), v28 != 0);
        if ( v26 != _This->sessionID )
        {
          v2 = _This;
          v29 = ACClient::getNetCarFromSessionID(_This, id[0]);
          v30 = v29;
          if ( v29 )
          {
            if ( v111 )
              NetCarStateProvider::activateP2P(v29);
            *(float *)&v30->p2p.activations = restrictor;
          }
          goto LABEL_3;
        }
        if ( LOWORD(ballastKG) == 0xFFFF )
        {
          v2 = _This;
          v31 = Sim::getCar(_This->sim, 0);
          v32 = v2->sim;
          (&v110[0]._Impl)[1] = 0;
          v124.request = v31->physics->drivetrain.acEngine.p2p.activations;
          v124.nextGear = 0;
          v33 = Sim::getCar(v32, 0);
          Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&v33->physics->evOnPush2Pass, &v124);
          goto LABEL_3;
        }
        LOWORD(v128) = LOWORD(ballastKG);
        v2 = _This;
        v110[0]._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_7471ed95f74a5e68441cce0bf44db25a_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
        *(_QWORD *)&v110[0]._Space._Alias[4] = __PAIR64__((unsigned int)_This, v128);
        v110[0]._Impl = (std::_Func_base<void> *)v110;
        LOBYTE(v174) = 0;
        goto LABEL_2;
      case 0xE:
        v34 = UDPPacket::read<unsigned char>(&pak);
        BYTE2(v118.nextGear) = v34;
        v35 = UDPPacket::read<unsigned char>(&pak) != 0;
        v3("ACP_CE_MANDATORY_PIT Car %i Done %i \n", v34, v35);
        v36 = !v35;
        v2 = _This;
        if ( !v36 )
        {
          if ( BYTE2(v118.nextGear) == _This->sessionID )
          {
            Sim::getCar(_This->sim, 0)->mandatoryPitstopDone = 1;
          }
          else
          {
            v37 = (void (__cdecl *)())ACClient::getNetCarFromSessionID(_This, BYTE2(v118.nextGear));
            if ( v37 )
            {
              v110[0]._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_4a57095d2df20e6a1ecac27c5acee47f_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
              v110[0]._Space._Pfn[1] = v37;
              v110[0]._Impl = (std::_Func_base<void> *)v110;
              v38 = v2->sim;
              LOBYTE(v174) = 0;
              Sim::executeOnMainThread(v38, (std::function<void __cdecl(void)>)v110[0]);
            }
          }
        }
        goto LABEL_4;
      case 0x47:
        v65 = UDPPacket::read<unsigned char>(&pak);
        UDPPacket::readStringW(&pak, &new_nation_code);
        LOBYTE(v174) = 31;
        v137.chat_msg._Bx._Buf[0] = 0;
        v137.chat_msg._Myres = 7;
        v137.chat_msg._Mysize = 0;
        std::wstring::assign(&v137.chat_msg, &new_nation_code, 0, 0xFFFFFFFF);
        v137.car_id = v65;
        v2 = _This;
        v137.__this = _This;
        LOBYTE(v174) = 32;
        std::function<void __cdecl (void)>::function<void __cdecl (void)>(
          (std::function<void __cdecl(void)> *)v110,
          &v137);
        Sim::executeOnMainThread(v2->sim, (std::function<void __cdecl(void)>)v110[0]);
        if ( v137.chat_msg._Myres >= 8 )
          operator delete(v137.chat_msg._Bx._Ptr);
        v137.chat_msg._Myres = 7;
        v137.chat_msg._Mysize = 0;
        v137.chat_msg._Bx._Buf[0] = 0;
        LOBYTE(v174) = 0;
        goto LABEL_79;
      case 0x49:
        ACClient::onRemoteLapCompleted(v2, &pak);
        goto LABEL_4;
      case 0x4A:
        _Val.__this = v2;
        UDPPacket::UDPPacket(&_Val.pak, &pak);
        v114 = v110;
        v110[0]._Impl = 0;
        LOBYTE(v174) = 43;
        std::_Func_class<void,>::_Reset<_lambda_e537553689fc017a9af3740e06575ef5_>(v110, &_Val);
        v109 = v2->sim;
        LOBYTE(v174) = 42;
        Sim::executeOnMainThread(v109, (std::function<void __cdecl(void)>)v110[0]);
        LOBYTE(v174) = 0;
        UDPPacket::~UDPPacket(&_Val.pak);
        goto LABEL_179;
      case 0x4B:
        v3("ACP_RACE_OVER received\n");
        std::wstring::wstring(&v153, L"ACP_RACE_OVER");
        LOBYTE(v174) = 44;
        ACClient::logMessage(v2, &v153);
        LOBYTE(v174) = 0;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v153);
        v81 = 0.0;
        v82 = v2->netCars._Mylast - v2->netCars._Myfirst + 1;
        restrictor = 0.0;
        if ( v82 > 0 )
        {
          do
          {
            UDPPacket::read<unsigned char>(&pak);
            LODWORD(ballastKG) = UDPPacket::read<unsigned int>(&pak);
            v83 = (unsigned __int16)UDPPacket::read<unsigned short>(&pak);
            v117 = ACClient::getCarAvatarFromSessionID(v2, v2->sessionID);
            if ( v117 )
            {
              v84 = std::to_wstring(&v147, v83);
              LOBYTE(v174) = 45;
              v85 = timeToString(&v143, SLODWORD(ballastKG), 3);
              LOBYTE(v174) = 46;
              v86 = std::to_wstring(&v149, LODWORD(restrictor) + 1);
              LOBYTE(v174) = 47;
              v87 = std::operator+<wchar_t>(&v138, v86, L": ");
              LOBYTE(v174) = 48;
              v88 = std::operator+<wchar_t>(&v140, v87, &v117->driverInfo.name);
              LOBYTE(v174) = 49;
              v89 = std::operator+<wchar_t>(&v141, v88, L" ");
              LOBYTE(v174) = 50;
              v90 = std::operator+<wchar_t>(&v150, v89, v85);
              LOBYTE(v174) = 51;
              v91 = std::operator+<wchar_t>(&v144, v90, L" ");
              LOBYTE(v174) = 52;
              v92 = std::operator+<wchar_t>(&v142, v91, v84);
              LOBYTE(v174) = 53;
              v93 = std::operator+<wchar_t>(&v139, v92, L" laps");
              LOBYTE(v174) = 54;
              ACClient::logMessage(v2, v93);
              if ( v139._Myres >= 8 )
                operator delete(v139._Bx._Ptr);
              v139._Myres = 7;
              v139._Mysize = 0;
              v139._Bx._Buf[0] = 0;
              if ( v142._Myres >= 8 )
                operator delete(v142._Bx._Ptr);
              v142._Myres = 7;
              v142._Mysize = 0;
              v142._Bx._Buf[0] = 0;
              if ( v144._Myres >= 8 )
                operator delete(v144._Bx._Ptr);
              v144._Myres = 7;
              v144._Mysize = 0;
              v144._Bx._Buf[0] = 0;
              if ( v150._Myres >= 8 )
                operator delete(v150._Bx._Ptr);
              v150._Myres = 7;
              v150._Mysize = 0;
              v150._Bx._Buf[0] = 0;
              if ( v141._Myres >= 8 )
                operator delete(v141._Bx._Ptr);
              v141._Myres = 7;
              v141._Mysize = 0;
              v141._Bx._Buf[0] = 0;
              if ( v140._Myres >= 8 )
                operator delete(v140._Bx._Ptr);
              v140._Myres = 7;
              v140._Mysize = 0;
              v140._Bx._Buf[0] = 0;
              if ( v138._Myres >= 8 )
                operator delete(v138._Bx._Ptr);
              v138._Myres = 7;
              v138._Mysize = 0;
              v138._Bx._Buf[0] = 0;
              if ( v149._Myres >= 8 )
                operator delete(v149._Bx._Ptr);
              v149._Myres = 7;
              v149._Mysize = 0;
              v149._Bx._Buf[0] = 0;
              if ( v143._Myres >= 8 )
                operator delete(v143._Bx._Ptr);
              v143._Myres = 7;
              v143._Mysize = 0;
              v143._Bx._Buf[0] = 0;
              LOBYTE(v174) = 0;
              if ( v147._Myres >= 8 )
                operator delete(v147._Bx._Ptr);
              v81 = restrictor;
              v147._Myres = 7;
              v147._Mysize = 0;
              v147._Bx._Buf[0] = 0;
            }
            ++LODWORD(v81);
            v94 = v2->netCars._Mylast - v2->netCars._Myfirst + 1;
            restrictor = v81;
          }
          while ( SLODWORD(v81) < v94 );
          v3 = (void (*)(const char *const, ...))_printf;
        }
        v95 = v2->sim;
        v2->isResultScreenOn = 1;
        v2->raceClosingTime = (double)v2->resultScreenTime + v95->game->gameTime.now;
        v2->endSession.isConnectionFinished = UDPPacket::read<unsigned char>(&pak) == 0;
        goto LABEL_3;
      case 0x4D:
        v66 = UDPPacket::read<unsigned char>(&pak);
        v67 = v2->netCars._Myfirst;
        v68 = v2->netCars._Mylast;
        if ( v67 == v68 )
          goto LABEL_4;
        while ( 1 )
        {
          v69 = *v67;
          if ( (*v67)->sessionID == v66 )
            break;
          if ( ++v67 == v68 )
            goto LABEL_3;
        }
        if ( v69 )
        {
          v70 = v69->driverInfo.name._Bx._Buf;
          if ( v69->driverInfo.name._Myres >= 8 )
            v70 = *(const wchar_t **)v70;
          v3("Disconnecting %S for ACP_CLIENT_DISCONNECTED\n", v70);
          v69->isDisconnected = 1;
          v123.netcar = v69;
          v123.__this = v2;
          std::function<void __cdecl (void)>::function<void __cdecl (void)>(
            (std::function<void __cdecl(void)> *)v110,
            &v123);
LABEL_2:
          Sim::executeOnMainThread(v2->sim, (std::function<void __cdecl(void)>)v110[0]);
        }
        goto LABEL_3;
      case 0x50:
        v111 = UDPPacket::read<unsigned char>(&pak);
        v56 = UDPPacket::readString(&pak, &v145);
        LOBYTE(v174) = 24;
        string2wstring(&new_nation_code, v56);
        LOBYTE(v174) = 26;
        if ( v145._Myres >= 0x10 )
          operator delete(v145._Bx._Ptr);
        v57 = v2->netCars._Myfirst;
        v58 = v2->netCars._Mylast;
        v145._Myres = 15;
        v145._Mysize = 0;
        v145._Bx._Buf[0] = 0;
        if ( v57 == v58 )
          goto LABEL_77;
        while ( 1 )
        {
          v2 = _This;
          if ( (*v57)->sessionID == v111 )
            break;
          if ( ++v57 == v58 )
            goto LABEL_77;
        }
        if ( !*v57 )
        {
LABEL_77:
          v3("ERROR: ACP_TYRE_COMPOUND_CHANGED but cannot find netcar with id (%d)\n", v111);
          goto LABEL_78;
        }
        _Func.netcar = *v57;
        _Func.short_name._Bx._Buf[0] = 0;
        _Func.short_name._Myres = 7;
        _Func.short_name._Mysize = 0;
        std::wstring::assign(&_Func.short_name, &new_nation_code, 0, 0xFFFFFFFF);
        LOBYTE(v174) = 27;
        std::function<void __cdecl (void)>::function<void __cdecl (void)>(
          (std::function<void __cdecl(void)> *)v110,
          &_Func);
        Sim::executeOnMainThread(v2->sim, (std::function<void __cdecl(void)>)v110[0]);
        OnSetupAppCreated::~OnSetupAppCreated((Texture *)&_Func);
LABEL_78:
        LOBYTE(v174) = 0;
LABEL_79:
        if ( new_nation_code._Myres >= 8 )
          operator delete(new_nation_code._Bx._Ptr);
        goto LABEL_4;
      case 0x51:
        v39 = UDPPacket::read<unsigned char>(&pak);
        if ( v39 )
          v3("ERROR: ACP_TEXT_FILE type %d NOT RECOGNIZED\n", v39);
        else
          ACClient::onWelcomeMessageReceived(v2, &pak);
        goto LABEL_4;
      case 0x52:
        ACClient::onSetupReceived(v2, &pak);
        goto LABEL_4;
      case 0x53:
        ACClient::onDRSZoneReceived(v2, &pak);
        goto LABEL_4;
      case 0x54:
        restrictor = UDPPacket::read<float>(&pak);
        ACClient::onRemoteSunAngleReceived(v2, restrictor);
        goto LABEL_4;
      case 0x56:
        v21 = UDPPacket::read<unsigned char>(&pak);
        v22 = (float *)v2->netCars._Myfirst;
        v23 = (float *)v2->netCars._Mylast;
        v111 = v21;
        if ( v22 == v23 )
          goto LABEL_22;
        while ( 1 )
        {
          v24 = *v22;
          restrictor = v24;
          v2 = _This;
          if ( *(_BYTE *)(LODWORD(v24) + 68) == v111 )
            break;
          if ( ++v22 == v23 )
          {
LABEL_22:
            v24 = 0.0;
            restrictor = 0.0;
            break;
          }
        }
        if ( v24 == 0.0 )
          goto LABEL_4;
        for ( i = 0; i < 5; ++i )
          *(float *)&new_nation_code._Bx._Buf[2 * i] = UDPPacket::read<float>(&pak);
        NetCarStateProvider::setDamageZoneLevel(
          (NetCarStateProvider *)LODWORD(restrictor),
          (float *)&new_nation_code._Bx._Ptr);
        goto LABEL_3;
      case 0x58:
        ACClient::onRemoteSectorSplit(v2, &pak);
        goto LABEL_4;
      case 0x5A:
        BYTE2(v118.request) = UDPPacket::read<unsigned char>(&pak);
        v77 = UDPPacket::readString(&pak, &v164);
        LOBYTE(v174) = 35;
        string2wstring((std::wstring *)&message, v77);
        LOBYTE(v174) = 37;
        std::string::~string(&v164);
        v78 = UDPPacket::readString(&pak, &v171);
        LOBYTE(v174) = 38;
        string2wstring(&new_nation_code, v78);
        LOBYTE(v174) = 40;
        std::string::~string(&v171);
        lambda_88b327a3fa7ea4738e9f6936855fc9a2_::_lambda_88b327a3fa7ea4738e9f6936855fc9a2__0(
          &v173,
          v2,
          (const unsigned __int8 *)&v118.request + 2,
          (const std::wstring *)&message,
          &new_nation_code);
        LOBYTE(v174) = 41;
        std::function<void __cdecl (void)>::function<void __cdecl (void)>(
          (std::function<void __cdecl(void)> *)v110,
          v79);
        Sim::executeOnMainThread(v2->sim, (std::function<void __cdecl(void)>)v110[0]);
        LOBYTE(v174) = 40;
        OnTyreCompoundChanged::~OnTyreCompoundChanged(&v173);
        v80 = ACClient::getNetCarFromSessionID(v2, BYTE2(v118.request));
        if ( v80 )
          NetCarStateProvider::resetDamage(v80);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&new_nation_code);
        LOBYTE(v174) = 0;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&message);
        goto LABEL_4;
      case 0x5B:
        v71 = UDPPacket::read<unsigned char>(&pak);
        LODWORD(restrictor) = v71;
        if ( !v71 )
          goto LABEL_4;
        do
        {
          v72 = UDPPacket::read<unsigned char>(&pak);
          v73 = v2->netCars._Myfirst;
          v74 = v2->netCars._Mylast;
          v111 = v72;
          if ( v73 == v74 )
          {
LABEL_107:
            v75 = 0;
          }
          else
          {
            while ( 1 )
            {
              v75 = *v73;
              if ( (*v73)->sessionID == v72 )
                break;
              if ( ++v73 == v74 )
                goto LABEL_107;
            }
          }
          UDPPacket::readStringW(&pak, &new_nation_code);
          LOBYTE(v174) = 33;
          if ( v75 )
          {
            v76 = &new_nation_code;
            if ( new_nation_code._Myres >= 8 )
              v76 = (std::wstring *)new_nation_code._Bx._Ptr;
            v3("PhysicsThread: Car %d driver:%S\n", v111, v76->_Bx._Buf);
            v136.sid = v111;
            v136.__this = v2;
            v136.new_name._Bx._Buf[0] = 0;
            v136.new_name._Myres = 7;
            v136.new_name._Mysize = 0;
            std::wstring::assign(&v136.new_name, &new_nation_code, 0, 0xFFFFFFFF);
            LOBYTE(v174) = 34;
            std::function<void __cdecl (void)>::function<void __cdecl (void)>(
              (std::function<void __cdecl(void)> *)v110,
              &v136);
            Sim::executeOnMainThread(v2->sim, (std::function<void __cdecl(void)>)v110[0]);
            if ( v136.new_name._Myres >= 8 )
              operator delete(v136.new_name._Bx._Ptr);
            v136.new_name._Myres = 7;
            v136.new_name._Mysize = 0;
            v136.new_name._Bx._Buf[0] = 0;
          }
          LOBYTE(v174) = 0;
          if ( new_nation_code._Myres >= 8 )
            operator delete(new_nation_code._Bx._Ptr);
          --LODWORD(restrictor);
        }
        while ( LODWORD(restrictor) );
        goto LABEL_3;
      case 0x64:
        ReceivedVoteDef::ReceivedVoteDef(&message);
        message.voteType = eVoteNextSession;
        message.targetSessionID = UDPPacket::read<unsigned char>(&pak);
        message.quorum = UDPPacket::read<unsigned char>(&pak);
        message.votes = UDPPacket::read<unsigned char>(&pak);
        message.timeLeftMS = UDPPacket::read<unsigned int>(&pak);
        message.lastVoterSessionID = UDPPacket::read<unsigned char>(&pak);
        v96 = UDPPacket::read<unsigned char>(&pak);
        v97 = message.isMe;
        message.lastVoterVote = v96;
        if ( message.lastVoterSessionID == v2->sessionID )
          v97 = 1;
        goto LABEL_151;
      case 0x65:
        ReceivedVoteDef::ReceivedVoteDef(&message);
        message.voteType = eVoteRestartSession;
        message.targetSessionID = UDPPacket::read<unsigned char>(&pak);
        message.quorum = UDPPacket::read<unsigned char>(&pak);
        message.votes = UDPPacket::read<unsigned char>(&pak);
        message.timeLeftMS = UDPPacket::read<unsigned int>(&pak);
        message.lastVoterSessionID = UDPPacket::read<unsigned char>(&pak);
        v98 = UDPPacket::read<unsigned char>(&pak);
        v97 = message.isMe;
        message.lastVoterVote = v98;
        if ( message.lastVoterSessionID == v2->sessionID )
          v97 = 1;
LABEL_151:
        message.isMe = v97;
        Event<std::wstring>::trigger(
          (Event<OnGearRequestEvent> *)&v2->evOnVoteReceived,
          (const OnGearRequestEvent *)&message);
        goto LABEL_4;
      case 0x66:
        ReceivedVoteDef::ReceivedVoteDef(&message);
        message.voteType = eVoteKickUser;
        message.targetSessionID = UDPPacket::read<unsigned char>(&pak);
        message.quorum = UDPPacket::read<unsigned char>(&pak);
        message.votes = UDPPacket::read<unsigned char>(&pak);
        message.timeLeftMS = UDPPacket::read<unsigned int>(&pak);
        message.lastVoterSessionID = UDPPacket::read<unsigned char>(&pak);
        v99 = UDPPacket::read<unsigned char>(&pak);
        v100 = v2->sessionID;
        v101 = message.isMe;
        message.lastVoterVote = v99;
        if ( message.lastVoterSessionID == v100 )
          v101 = 1;
        message.isMe = v101;
        if ( message.targetSessionID != v100 )
          Event<std::wstring>::trigger(
            (Event<OnGearRequestEvent> *)&v2->evOnVoteReceived,
            (const OnGearRequestEvent *)&message);
        goto LABEL_4;
      case 0x67:
        UDPPacket::read<unsigned int>(&pak);
        LOBYTE(v118.request) = 1;
        Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&v2->evOnVoteNotPassed, &v118);
        goto LABEL_4;
      case 0x68:
        v102 = UDPPacket::read<unsigned char>(&pak);
        LOBYTE(kickedSessionID) = v102;
        v103 = UDPPacket::read<unsigned char>(&pak);
        v104 = _This;
        v105 = v103;
        v111 = v103;
        v106 = ACClient::getCarAvatarFromSessionID(_This, kickedSessionID);
        std::operator+<wchar_t>(&__message, L"Kicked Driver ", &v106->driverInfo.name);
        LOBYTE(v174) = 55;
        if ( v104->sessionID != v102 )
        {
          detail_msg._Myres = 7;
          detail_msg._Mysize = 0;
          detail_msg._Bx._Buf[0] = 0;
          LOBYTE(v174) = 56;
          switch ( v105 )
          {
            case 0u:
              (&v110[0]._Impl)[1] = (std::_Func_base<void> *)L"Kicked from the race";
              break;
            case 1u:
              (&v110[0]._Impl)[1] = (std::_Func_base<void> *)L"Kicked until the server restarts";
              break;
            case 2u:
              (&v110[0]._Impl)[1] = (std::_Func_base<void> *)L"Kicked and put on blacklist";
              break;
            case 3u:
              (&v110[0]._Impl)[1] = (std::_Func_base<void> *)L"Checksum failed";
              break;
            default:
              (&v110[0]._Impl)[1] = (std::_Func_base<void> *)L"Kicked from the server";
              break;
          }
          std::wstring::assign(&detail_msg, (const wchar_t *)(&v110[0]._Impl)[1]);
          v2 = _This;
          lambda_d56d12ec4c2d04f70226b1d95868e0f3_::_lambda_d56d12ec4c2d04f70226b1d95868e0f3_(
            &v172,
            _This,
            &__message,
            &detail_msg);
          LOBYTE(v174) = 57;
          std::function<void __cdecl (void)>::function<void __cdecl (void)>(
            (std::function<void __cdecl(void)> *)v110,
            v108);
          Sim::executeOnMainThread(v2->sim, (std::function<void __cdecl(void)>)v110[0]);
          lambda_d56d12ec4c2d04f70226b1d95868e0f3_::__lambda_d56d12ec4c2d04f70226b1d95868e0f3_(&v172);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&detail_msg);
LABEL_176:
          LOBYTE(v174) = 0;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&__message);
          goto LABEL_3;
        }
        v2 = v104;
        if ( v104->dcCountdown.isSignaled )
          goto LABEL_176;
        v107 = v111;
        v104->dcCountdown.timeToDisconnection = 10.0;
        switch ( v107 )
        {
          case 0:
            (&v110[0]._Impl)[1] = (std::_Func_base<void> *)L"You have been voted to be kicked from the race";
            break;
          case 1:
            (&v110[0]._Impl)[1] = (std::_Func_base<void> *)L"You have been voted to be banned from the server";
            break;
          case 2:
            (&v110[0]._Impl)[1] = (std::_Func_base<void> *)L"You have been voted to be blacklisted from the server";
            break;
          case 3:
            (&v110[0]._Impl)[1] = (std::_Func_base<void> *)L"Checksum failed. You have been kicked out of the race";
            break;
          default:
            (&v110[0]._Impl)[1] = (std::_Func_base<void> *)L"You have been kicked from the server";
            break;
        }
        std::wstring::assign(&v104->dcCountdown.message, (const wchar_t *)(&v110[0]._Impl)[1]);
        v104->dcCountdown.isSignaled = 1;
        LOBYTE(v174) = 0;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&__message);
LABEL_3:
        v4 = v113;
        break;
      case 0x70:
        v40 = UDPPacket::read<unsigned char>(&pak);
        v41 = (CarAvatar *)v40;
        v117 = (CarAvatar *)v40;
        if ( !v40 )
          goto LABEL_3;
        do
        {
          v111 = UDPPacket::read<unsigned char>(&pak);
          ballastKG = UDPPacket::read<float>(&pak);
          v42 = UDPPacket::read<float>(&pak);
          v43 = v111;
          restrictor = v42;
          if ( v111 == v2->sessionID )
          {
            v36 = ballastKG == v2->car->ballastKG;
            *(double *)&v110[0]._Impl = ballastKG;
            if ( v36 )
            {
              v3("WARNING: Received negative ballast (%f) ignoring\n", *(double *)&v110[0]._Impl);
            }
            else
            {
              v3("Setting Ballast to: %f\n", *(double *)&v110[0]._Impl);
              v129 = ballastKG;
              v110[0]._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_56ac8b8552a02ee0b57ccf93c5fbb10f_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
              *(_QWORD *)&v110[0]._Space._Alias[4] = __PAIR64__((unsigned int)v2, LODWORD(ballastKG));
              v110[0]._Impl = (std::_Func_base<void> *)v110;
              v44 = v2->sim;
              LOBYTE(v174) = 0;
              Sim::executeOnMainThread(v44, (std::function<void __cdecl(void)>)v110[0]);
              (&v110[0]._Impl)[1] = v45;
              Car::setBallastKG(v2->car, ballastKG);
            }
            v43 = v111;
          }
          else
          {
            v46 = v2->netCars._Myfirst;
            v47 = v2->netCars._Mylast;
            if ( v46 != v47 )
            {
              while ( 1 )
              {
                v48 = *v46;
                if ( (*v46)->sessionID == v111 )
                  break;
                if ( ++v46 == v47 )
                  goto LABEL_58;
              }
              if ( v48 )
              {
                v3("CAR: %i BALLAST SET TO:%f Kg\n", v111, ballastKG);
                v125 = ballastKG;
                v110[0]._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_a8c125a8ce066174ddc942f1d7f09e5a_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
                *(_QWORD *)&v110[0]._Space._Alias[4] = __PAIR64__(LODWORD(ballastKG), (unsigned int)v48);
                v110[0]._Impl = (std::_Func_base<void> *)v110;
                v49 = v2->sim;
                LOBYTE(v174) = 0;
                Sim::executeOnMainThread(v49, (std::function<void __cdecl(void)>)v110[0]);
                v43 = v111;
              }
LABEL_58:
              v41 = v117;
            }
          }
          if ( v43 == v2->sessionID )
          {
            ballastKG = Car::getRestrictor(v2->car);
            *(double *)&v110[0]._Impl = restrictor;
            if ( restrictor == ballastKG )
            {
              v3("WARNING: Received negative restrictor (%f) ignoring\n", *(double *)&v110[0]._Impl);
            }
            else
            {
              v3("Setting Restrictor to: %f\n", *(double *)&v110[0]._Impl);
              v126 = restrictor;
              v110[0]._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_1170cdf3bd71e1ebc5b6fd803b9745f1_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
              *(_QWORD *)&v110[0]._Space._Alias[4] = __PAIR64__((unsigned int)v2, LODWORD(restrictor));
              v110[0]._Impl = (std::_Func_base<void> *)v110;
              v50 = v2->sim;
              LOBYTE(v174) = 0;
              Sim::executeOnMainThread(v50, (std::function<void __cdecl(void)>)v110[0]);
              (&v110[0]._Impl)[1] = v51;
              Car::setRestrictor(v2->car, restrictor);
            }
          }
          else
          {
            v52 = v2->netCars._Myfirst;
            v53 = v2->netCars._Mylast;
            if ( v52 != v53 )
            {
              while ( 1 )
              {
                v54 = *v52;
                if ( (*v52)->sessionID == v43 )
                  break;
                if ( ++v52 == v53 )
                  goto LABEL_69;
              }
              if ( v54 )
              {
                v3("CAR: %i RESTRICTOR SET TO:%f \n", v43, restrictor);
                v127 = restrictor;
                v110[0]._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_70d6ec5fb0c5de134d3f177c95b099bb_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
                *(_QWORD *)&v110[0]._Space._Alias[4] = __PAIR64__(LODWORD(restrictor), (unsigned int)v54);
                v110[0]._Impl = (std::_Func_base<void> *)v110;
                v55 = v2->sim;
                LOBYTE(v174) = 0;
                Sim::executeOnMainThread(v55, (std::function<void __cdecl(void)>)v110[0]);
              }
LABEL_69:
              v41 = v117;
            }
          }
          v41 = (CarAvatar *)((char *)v41 - 1);
          v117 = v41;
        }
        while ( v41 );
        goto LABEL_3;
      case 0x78:
        v2->car->ksPhysics->ambientTemperature = (float)UDPPacket::read<unsigned char>(&pak);
        v2->car->ksPhysics->roadTemperature = (float)UDPPacket::read<unsigned char>(&pak);
        UDPPacket::readStringW(&pak, &new_nation_code);
        LOBYTE(v174) = 28;
        v59 = FLOAT_40_0;
        v60 = (float)(__int16)UDPPacket::read<short>(&pak);
        restrictor = v60;
        if ( v60 > 40.0 || (v59 = 0.0, v60 < 0.0) )
          restrictor = v59;
        v61 = (__int16)UDPPacket::read<short>(&pak);
        v62 = Speed::fromKMH(&v119, restrictor);
        LOBYTE(v174) = 29;
        PhysicsEngine::setWind(&v2->sim->physicsAvatar->engine, LODWORD(v62->value), (float)v61);
        LOBYTE(v174) = 28;
        dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v119);
        v134.graphics_name._Myres = 7;
        v134.graphics_name._Bx._Buf[0] = 0;
        v134.graphics_name._Mysize = 0;
        std::wstring::assign(&v134.graphics_name, &new_nation_code, 0, 0xFFFFFFFF);
        v134.__this = v2;
        LOBYTE(v174) = 30;
        std::function<void __cdecl (void)>::function<void __cdecl (void)>(
          (std::function<void __cdecl(void)> *)v110,
          &v134);
        Sim::executeOnMainThread(v2->sim, (std::function<void __cdecl(void)>)v110[0]);
        if ( v134.graphics_name._Myres >= 8 )
          operator delete(v134.graphics_name._Bx._Ptr);
        v134.graphics_name._Myres = 7;
        v63 = &new_nation_code;
        v134.graphics_name._Bx._Buf[0] = 0;
        v64 = v2->car;
        if ( new_nation_code._Myres >= 8 )
          v63 = (std::wstring *)new_nation_code._Bx._Ptr;
        v134.graphics_name._Mysize = 0;
        (&v110[0]._Impl)[1] = (std::_Func_base<void> *)v63;
        v3(
          "ACP_WEATHER_UPDATE: Ambient=%f Road=%f GRAPHICS=%S\n",
          v64->ksPhysics->ambientTemperature,
          v64->ksPhysics->roadTemperature,
          v63->_Bx._Buf);
        v4 = v113;
        LOBYTE(v174) = 0;
        if ( new_nation_code._Myres < 8 )
          goto LABEL_4;
        operator delete(new_nation_code._Bx._Ptr);
        goto LABEL_3;
      case 0x82:
        if ( UDPPacket::read<unsigned char>(&pak) != 12 )
          goto LABEL_4;
        LOBYTE(sid) = UDPPacket::read<unsigned char>(&pak);
        name._Myres = 7;
        name._Mysize = 0;
        name._Bx._Buf[0] = 0;
        LOBYTE(v174) = 1;
        if ( (_BYTE)sid == v2->sessionID )
        {
          LOBYTE(v174) = 0;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&name);
          goto LABEL_4;
        }
        v5 = &ACClient::getNetCarFromSessionID(v2, sid)->driverInfo;
        if ( &name != (std::wstring *)v5 )
          std::wstring::assign(&name, &v5->name, 0, 0xFFFFFFFF);
        new_nation_code._Myres = 7;
        new_nation_code._Mysize = 0;
        new_nation_code._Bx._Buf[0] = 0;
        v6 = v2->car;
        LOBYTE(v174) = 2;
        v7 = v6->ksPhysics->penaltyRules.jumpStartPenaltyMode - 1;
        if ( v7 )
        {
          if ( v7 != 1 )
            goto LABEL_18;
          std::wstring::wstring(&text, L"Drive through");
          LOBYTE(v174) = 3;
          std::wstring::wstring(&v152, L"Jumpstart detected for ");
          LOBYTE(v174) = 4;
          v8 = acTranslate(&result, &text);
          LOBYTE(v174) = 5;
          v9 = acTranslate(&v163, &v152);
          LOBYTE(v174) = 6;
          v10 = std::operator+<wchar_t>(&v161, L"[SERVER] ", v9);
          LOBYTE(v174) = 7;
          v11 = std::operator+<wchar_t>(&v159, v10, &name);
          LOBYTE(v174) = 8;
          v12 = std::operator+<wchar_t>(&v166, v11, L" ");
          LOBYTE(v174) = 9;
          v13 = std::operator+<wchar_t>(&v165, v12, v8);
          std::wstring::operator=(&new_nation_code, v13);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v165);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v166);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v159);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v161);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v163);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v152);
          v14 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text;
        }
        else
        {
          std::wstring::wstring(&v154, L"Starts from pits");
          LOBYTE(v174) = 10;
          std::wstring::wstring(&v156, L"Jumpstart detected for ");
          LOBYTE(v174) = 11;
          v15 = acTranslate(&v168, &v154);
          LOBYTE(v174) = 12;
          v16 = acTranslate(&v162, &v156);
          LOBYTE(v174) = 13;
          v17 = std::operator+<wchar_t>(&v170, L"[SERVER] ", v16);
          LOBYTE(v174) = 14;
          v18 = std::operator+<wchar_t>(&v160, v17, &name);
          LOBYTE(v174) = 15;
          v19 = std::operator+<wchar_t>(&v169, v18, L" ");
          LOBYTE(v174) = 16;
          v20 = std::operator+<wchar_t>(&v167, v19, v15);
          std::wstring::operator=(&new_nation_code, v20);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v167);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v169);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v160);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v170);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v162);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v168);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v156);
          v14 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v154;
        }
        LOBYTE(v174) = 2;
        std::wstring::~wstring(v14);
        v4 = v113;
LABEL_18:
        v146.msg._Myres = 7;
        v146.msg._Bx._Buf[0] = 0;
        v146.msg._Mysize = 0;
        std::wstring::assign(&v146.msg, &new_nation_code, 0, 0xFFFFFFFF);
        v146.__this = v2;
        LOBYTE(v174) = 17;
        std::function<void __cdecl (void)>::function<void __cdecl (void)>(
          (std::function<void __cdecl(void)> *)v110,
          &v146);
        Sim::executeOnMainThread(v2->sim, (std::function<void __cdecl(void)>)v110[0]);
        std::pair<std::wstring,jsonwriter::Node &>::~pair<std::wstring,jsonwriter::Node &>((MD5Result *)&v146);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&new_nation_code);
        LOBYTE(v174) = 0;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&name);
        goto LABEL_4;
      default:
        v3("ERROR: ACClient CRITICAL ERROR :: Unknown packet id: %d RETURNING\n", BYTE1(v118.request));
        goto LABEL_179;
    }
  }
LABEL_179:
  v174 = -1;
  UDPPacket::~UDPPacket(&pak);
}
void ACClient::onNewSession(ACClient *this, UDPPacket *pak, bool isHandShake)
{
  const std::string *v4; // eax
  RemoteSession *v5; // esi
  unsigned __int16 v6; // ax
  RemoteSession *v7; // eax
  Sim *v8; // esi
  SessionLeaderboard *v9; // ecx
  CarAvatar *v10; // ecx
  unsigned int v11; // ebx
  int v12; // eax
  NetCarStateProvider *v13; // esi
  NetCarStateProvider *v14; // esi
  NetCarStateProvider *v15; // esi
  NetCarStateProvider *v16; // ecx
  bool v17; // bl
  void (*v18)(const char *const, ...); // esi
  int v19; // eax
  unsigned __int8 v20; // bl
  CarAvatar *v21; // eax
  NetCarStateProvider **v22; // eax
  NetCarStateProvider **v23; // ecx
  DriverInfo *v24; // eax
  int v25; // ebx
  Sim *v26; // ecx
  CarAvatar *v27; // eax
  int *v28; // ecx
  int v29; // ebx
  int *v30; // esi
  int v31; // ebx
  int v32; // ecx
  unsigned int v33; // edx
  unsigned int v34; // edx
  int v35; // ecx
  unsigned int v36; // edx
  unsigned int v37; // edx
  int v38; // eax
  double v39; // st7
  double v40; // st7
  long double v41; // xmm0_8
  bool v42; // al
  const std::vector<unsigned int> *v43; // eax
  const std::vector<unsigned int> *v44; // esi
  UDPPacket *v45; // ecx
  unsigned __int8 v46; // bl
  CarAvatar *v47; // eax
  NetCarStateProvider **v48; // eax
  NetCarStateProvider **v49; // ecx
  NetCarStateProvider *v50; // edx
  int *v51; // esi
  int v52; // eax
  UDPPacket *v53; // ecx
  std::pair<void *,std::function<void __cdecl(RemoteSession const &)> > *v54; // esi
  int *v55; // ebx
  Sim *v56; // ecx
  std::function<void __cdecl(void)> v57; // [esp-Ch] [ebp-1A0h] BYREF
  unsigned int v58; // [esp+Ch] [ebp-188h]
  int *v59; // [esp+3Ch] [ebp-158h]
  UDPPacket *v60; // [esp+40h] [ebp-154h]
  int v61; // [esp+44h] [ebp-150h] BYREF
  std::vector<int> startingpositions; // [esp+48h] [ebp-14Ch] BYREF
  long double sess_start; // [esp+54h] [ebp-140h]
  int *v64; // [esp+60h] [ebp-134h] BYREF
  float grip; // [esp+64h] [ebp-130h]
  int index; // [esp+68h] [ebp-12Ch] BYREF
  RemoteSessionResult sessionResults; // [esp+6Ch] [ebp-128h] BYREF
  RemoteSession ses; // [esp+A4h] [ebp-F0h] BYREF
  std::wstring setName; // [esp+DCh] [ebp-B8h] BYREF
  RemoteSessionResult v70; // [esp+F4h] [ebp-A0h] BYREF
  std::string result; // [esp+138h] [ebp-5Ch] BYREF
  char v72; // [esp+18Ch] [ebp-8h]
  int v73; // [esp+190h] [ebp-4h]

  v58 = 7;
  v60 = pak;
  (&v57._Impl)[1] = (std::_Func_base<void> *)L"UNNAMED";
  this->transitionInfo.isTransitioning = 0;
  ses.name._Myres = 7;
  ses.name._Mysize = 0;
  ses.name._Bx._Buf[0] = 0;
  std::wstring::assign(&ses.name, (const wchar_t *)(&v57._Impl)[1], v58);
  ses.index = 0;
  ses.time = 0;
  ses.laps = 0;
  ses.startTime = 0.0;
  *(_WORD *)&ses.isTimedRace = 0;
  *(_WORD *)&ses.isSpectator = this->playerIsSpectator;
  v73 = 0;
  v4 = UDPPacket::readString(pak, &result);
  LOBYTE(v73) = 1;
  v5 = (RemoteSession *)string2wstring(&setName, v4);
  if ( &ses != v5 )
  {
    if ( ses.name._Myres >= 8 )
      operator delete(ses.name._Bx._Ptr);
    ses.name._Myres = 7;
    ses.name._Mysize = 0;
    ses.name._Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(&ses.name, &v5->name);
  }
  if ( setName._Myres >= 8 )
    operator delete(setName._Bx._Ptr);
  setName._Myres = 7;
  setName._Mysize = 0;
  setName._Bx._Buf[0] = 0;
  LOBYTE(v73) = 0;
  if ( result._Myres >= 0x10 )
    operator delete(result._Bx._Ptr);
  ses.index = UDPPacket::read<unsigned char>(pak);
  ses.type = UDPPacket::read<unsigned char>(pak);
  ses.time = (unsigned __int16)UDPPacket::read<unsigned short>(pak);
  v6 = UDPPacket::read<unsigned short>(pak);
  ses.laps = v6;
  if ( ses.type != Race || v6 || (ses.isTimedRace = 1, ses.time <= 0) )
    ses.isTimedRace = 0;
  this->debugStartingLights = 0;
  *(_WORD *)&this->hasLeaderFinished = 0;
  this->raceClosingTime = 0.0;
  grip = UDPPacket::read<float>(pak);
  _printf("\nSTART NEW REMOTE SESSION\n");
  v7 = &ses;
  if ( ses.name._Myres >= 8 )
    v7 = (RemoteSession *)ses.name._Bx._Ptr;
  _printf("NAME=%S\n", v7->name._Bx._Buf);
  _printf("TYPE=%d\n", ses.type);
  _printf("TIME=%d\n", ses.time);
  _printf("LAPS=%d\n", ses.laps);
  _printf("GRIP=%f", grip);
  v8 = this->sim;
  this->finishPosition = -1;
  this->isResultScreenOn = 0;
  this->isLastLap = 0;
  this->endSession.sendToPitsTimer = 0.0;
  v9 = v8->leaderboard;
  if ( v9 )
  {
    SessionLeaderboard::setVisible(v9, 0);
    v8->leaderboard->isActive = 0;
  }
  MicroSectors::initialize(this->sim->microSectors);
  v10 = this->avatar;
  if ( v10 )
    CarAvatar::setGentleStop(v10, 0);
  startingpositions._Myfirst = 0;
  startingpositions._Mylast = 0;
  startingpositions._Myend = 0;
  v11 = 0;
  v12 = this->netCars._Mylast - this->netCars._Myfirst;
  LOBYTE(v73) = 2;
  if ( v12 )
  {
    do
    {
      this->netCars._Myfirst[v11]->bestLap = 0;
      this->netCars._Myfirst[v11]->lastLap = 0;
      this->netCars._Myfirst[v11]->lastUpdateTime = 0.0;
      this->netCars._Myfirst[v11]->lastTime = 0.0;
      v13 = this->netCars._Myfirst[v11];
      std::_Container_base0::_Orphan_all(&v13->laps);
      v58 = LODWORD(sess_start);
      (&v57._Impl)[1] = (std::_Func_base<void> *)((char *)&v61 + 3);
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(v13->laps._Myfirst, v13->laps._Mylast);
      v13->laps._Mylast = v13->laps._Myfirst;
      v14 = this->netCars._Myfirst[v11];
      std::_Container_base0::_Orphan_all(&v14->currentSplits);
      v14->currentSplits._Mylast = v14->currentSplits._Myfirst;
      v15 = this->netCars._Myfirst[v11];
      std::_Container_base0::_Orphan_all(&v15->personalBestSplits);
      v15->personalBestSplits._Mylast = v15->personalBestSplits._Myfirst;
      this->netCars._Myfirst[v11]->p2p.active = 0;
      v16 = this->netCars._Myfirst[v11++];
      v16->p2p.timeAccum = v16->p2p.coolDownS;
    }
    while ( v11 < this->netCars._Mylast - this->netCars._Myfirst );
  }
  std::_Container_base0::_Orphan_all(&this->localCarCurrentSplits);
  this->localCarCurrentSplits._Mylast = this->localCarCurrentSplits._Myfirst;
  std::_Container_base0::_Orphan_all(&this->localCarBestSplits);
  this->localCarBestSplits._Mylast = this->localCarBestSplits._Myfirst;
  std::_Container_base0::_Orphan_all(&this->localCarLaps);
  v58 = LODWORD(sess_start);
  (&v57._Impl)[1] = (std::_Func_base<void> *)((char *)&v61 + 3);
  std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(this->localCarLaps._Myfirst, this->localCarLaps._Mylast);
  v17 = isHandShake;
  this->localCarLaps._Mylast = this->localCarLaps._Myfirst;
  this->localCarBestLap = 0;
  this->localCarLastLap.time = 0;
  if ( isHandShake )
  {
    v18 = (void (*)(const char *const, ...))_printf;
    v58 = UDPPacket::read<unsigned char>(v60);
    (&v57._Impl)[1] = (std::_Func_base<void> *)"HANDSHAKE POSITION:%d\n";
    this->handshakeCarPosition = v58;
    _printf((const char *const)(&v57._Impl)[1], v58);
    goto LABEL_65;
  }
  v18 = (void (*)(const char *const, ...))_printf;
  _printf("Grid positions:\n");
  v19 = this->netCars._Mylast - this->netCars._Myfirst;
  index = 0;
  if ( v19 != -1 )
  {
    while ( 1 )
    {
      v20 = UDPPacket::read<unsigned char>(v60);
      if ( v20 == this->sessionID )
      {
        v21 = Sim::getCar(this->sim, 0);
      }
      else
      {
        v22 = this->netCars._Myfirst;
        v23 = this->netCars._Mylast;
        if ( v22 == v23 )
        {
LABEL_29:
          v18("ERROR: Cannot find car with sessionID: %d\n", v20);
          v21 = 0;
        }
        else
        {
          while ( (*v22)->sessionID != v20 )
          {
            if ( ++v22 == v23 )
              goto LABEL_29;
          }
          v21 = (*v22)->avatar;
        }
      }
      v24 = &v21->driverInfo;
      if ( v24->name._Myres >= 8 )
        v24 = (DriverInfo *)v24->name._Bx._Ptr;
      LODWORD(sess_start) = v20;
      v18("CAR ID: %d : %S\n", v20, v24->name._Bx._Buf);
      if ( v20 == this->sessionID && ses.type == Race )
      {
        v25 = index;
        v18("Setting my grid position at: %u\n", index);
        setName._Myres = 7;
        setName._Mysize = 0;
        setName._Bx._Buf[0] = 0;
        std::wstring::assign(&setName, L"START", 5u);
        v26 = this->sim;
        LOBYTE(v73) = 3;
        v27 = Sim::getCar(v26, 0);
        CarAvatar::setSpawnPositionIndex(v27, &setName, v25);
        LOBYTE(v73) = 2;
        if ( setName._Myres >= 8 )
          operator delete(setName._Bx._Ptr);
        Sim::getCar(this->sim, 0)->mandatoryPitstopDone = 0;
      }
      v28 = startingpositions._Mylast;
      v29 = LODWORD(sess_start);
      v30 = startingpositions._Myfirst;
      v64 = (int *)LODWORD(sess_start);
      if ( (int *)&v64 >= startingpositions._Mylast || startingpositions._Myfirst > (int *)&v64 )
      {
        if ( startingpositions._Mylast == startingpositions._Myend
          && !(startingpositions._Myend - startingpositions._Mylast) )
        {
          v35 = startingpositions._Mylast - startingpositions._Myfirst;
          if ( v35 == 0x3FFFFFFF )
LABEL_67:
            std::_Xlength_error("vector<T> too long");
          v36 = startingpositions._Myend - startingpositions._Myfirst;
          LODWORD(sess_start) = v35 + 1;
          if ( 0x3FFFFFFF - (v36 >> 1) >= v36 )
            v37 = (v36 >> 1) + v36;
          else
            v37 = 0;
          if ( v37 < LODWORD(sess_start) )
            v37 = LODWORD(sess_start);
          std::vector<ksgui::CustomSpinner *>::_Reallocate(
            (std::vector<ksgui::CustomSpinner *> *)&startingpositions,
            v37);
          v28 = startingpositions._Mylast;
        }
        if ( !v28 )
          goto LABEL_63;
        *v28 = v29;
      }
      else
      {
        v31 = ((char *)&v64 - (char *)startingpositions._Myfirst) >> 2;
        if ( startingpositions._Mylast == startingpositions._Myend
          && !(startingpositions._Myend - startingpositions._Mylast) )
        {
          v32 = startingpositions._Mylast - startingpositions._Myfirst;
          if ( v32 == 0x3FFFFFFF )
            goto LABEL_67;
          v33 = startingpositions._Myend - startingpositions._Myfirst;
          LODWORD(sess_start) = v32 + 1;
          if ( 0x3FFFFFFF - (v33 >> 1) >= v33 )
            v34 = (v33 >> 1) + v33;
          else
            v34 = 0;
          if ( v34 < LODWORD(sess_start) )
            v34 = LODWORD(sess_start);
          std::vector<ksgui::CustomSpinner *>::_Reallocate(
            (std::vector<ksgui::CustomSpinner *> *)&startingpositions,
            v34);
          v28 = startingpositions._Mylast;
          v30 = startingpositions._Myfirst;
        }
        if ( !v28 )
          goto LABEL_63;
        *v28 = v30[v31];
      }
      v28 = startingpositions._Mylast;
LABEL_63:
      v38 = (char *)this->netCars._Mylast - (char *)this->netCars._Myfirst;
      v18 = (void (*)(const char *const, ...))_printf;
      startingpositions._Mylast = v28 + 1;
      if ( ++index >= (unsigned int)((v38 >> 2) + 1) )
      {
        v17 = 0;
        break;
      }
    }
  }
LABEL_65:
  sess_start = (double)UDPPacket::read<__int64>(v60);
  v18("RCV sess_start %d\n", LODWORD(sess_start));
  if ( v17 )
  {
    ses.startTime = ksGetTime() - sess_start;
    v39 = ksGetTime();
    v18("HANDSHAKE SESSION START=%f CURRENT TIME:%f\n", (double)ses.startTime, v39);
  }
  else
  {
    ses.startTime = sess_start;
    v40 = ksGetTime();
    v18("SESSION START AT: %f CURRENT TIME: %f\n", (double)sess_start, v40);
  }
  if ( &this->currentSession != &ses )
    std::wstring::assign(&this->currentSession.name, &ses.name, 0, 0xFFFFFFFF);
  v41 = ses.startTime;
  this->currentSession.type = ses.type;
  this->currentSession.index = ses.index;
  this->currentSession.time = ses.time;
  this->currentSession.laps = ses.laps;
  this->currentSession.isSpectator = ses.isSpectator;
  this->currentSession.isTimedRace = ses.isTimedRace;
  v42 = ses.hasExtraLap;
  this->currentSession.startTime = v41;
  this->currentSession.hasExtraLap = v42;
  RemoteSessionResult::RemoteSessionResult(&sessionResults);
  LOBYTE(v73) = 4;
  if ( v17 )
    goto LABEL_81;
  if ( this->currentSession.type != Race )
    goto LABEL_81;
  RemoteSessionResult::RemoteSessionResult(&v70, this->netCars._Mylast - this->netCars._Myfirst + 1);
  v44 = v43;
  LOBYTE(v73) = 5;
  std::vector<int>::operator=((std::vector<unsigned int> *)&sessionResults, v43);
  std::vector<int>::operator=((std::vector<unsigned int> *)&sessionResults.times, v44 + 1);
  std::vector<int>::operator=((std::vector<unsigned int> *)&sessionResults.lapCounter, v44 + 2);
  sessionResults.hasFinished._Mysize = (unsigned int)v44[4]._Myfirst;
  std::vector<float>::operator=(&sessionResults.hasFinished._Myvec, (const std::vector<unsigned int> *)&v44[3]);
  sessionResults.leaderLapCount = (unsigned int)v44[4]._Mylast;
  LOBYTE(v73) = 4;
  RemoteSessionResult::~RemoteSessionResult(&v70);
  v45 = 0;
  v60 = 0;
  if ( !(sessionResults.positions._Mylast - sessionResults.positions._Myfirst) )
    goto LABEL_81;
LABEL_74:
  v46 = startingpositions._Myfirst[(_DWORD)v45];
  if ( v46 == this->sessionID )
  {
    v47 = Sim::getCar(this->sim, 0);
    goto LABEL_80;
  }
  v48 = this->netCars._Myfirst;
  v49 = this->netCars._Mylast;
  if ( v48 == v49 )
  {
LABEL_79:
    _printf("ERROR: Cannot find car with sessionID: %d\n", v46);
    v47 = 0;
    goto LABEL_80;
  }
  while ( 1 )
  {
    v50 = *v48;
    if ( (*v48)->sessionID == v46 )
      break;
    if ( ++v48 == v49 )
      goto LABEL_79;
  }
  while ( 1 )
  {
    v47 = v50->avatar;
LABEL_80:
    v51 = sessionResults.positions._Myfirst;
    v52 = CarAvatar::getGuid(v47);
    v53 = v60;
    v51[(_DWORD)v60] = v52;
    v45 = (UDPPacket *)((char *)&v53->targetIP.sokaddr.sin_family + 1);
    v60 = v45;
    if ( (unsigned int)v45 < sessionResults.positions._Mylast - sessionResults.positions._Myfirst )
      goto LABEL_74;
LABEL_81:
    std::vector<int>::operator=(
      (std::vector<unsigned int> *)&this->sessionResultsGT,
      (const std::vector<unsigned int> *)&sessionResults);
    std::vector<int>::operator=(
      (std::vector<unsigned int> *)&this->sessionResultsGT.times,
      (const std::vector<unsigned int> *)&sessionResults.times);
    std::vector<int>::operator=(
      (std::vector<unsigned int> *)&this->sessionResultsGT.lapCounter,
      (const std::vector<unsigned int> *)&sessionResults.lapCounter);
    this->sessionResultsGT.hasFinished._Mysize = sessionResults.hasFinished._Mysize;
    std::vector<float>::operator=(&this->sessionResultsGT.hasFinished._Myvec, &sessionResults.hasFinished._Myvec);
    this->sessionResultsGT.leaderLapCount = sessionResults.leaderLapCount;
    v54 = this->evOnOnlineNewSession.handlers._Myfirst;
    if ( v54 != this->evOnOnlineNewSession.handlers._Mylast )
      break;
LABEL_85:
    if ( !isHandShake )
    {
      setName._Mysize = 7;
      *(_DWORD *)&setName._Bx._Alias[12] = 0;
      *((_WORD *)&ses.hasExtraLap + 1) = 0;
      std::wstring::assign((std::wstring *)(&ses.hasExtraLap + 2), L"New Session :", 0xDu);
      v56 = this->sim;
      v72 = 6;
      SystemMessage::addMessage(
        v56->systemMessage,
        (const std::wstring *)(&ses.hasExtraLap + 2),
        (const std::wstring *)&sessionResults.leaderLapCount,
        eDefault);
      v72 = 4;
      if ( setName._Mysize >= 8 )
        operator delete(*(_DWORD *)(&ses.hasExtraLap + 2));
    }
    setName._Myres = (unsigned int)this;
    LOWORD(v70.positions._Mylast) = 0;
    v70.positions._Myfirst = v64;
    v70.lapCounter._Myfirst = (int *)7;
    v70.times._Myend = 0;
    std::wstring::assign(
      (std::wstring *)&v70.positions._Mylast,
      (const std::wstring *)&sessionResults.leaderLapCount,
      0,
      0xFFFFFFFF);
    v70.lapCounter._Mylast = (int *)ses.name._Myres;
    v70.lapCounter._Myend = (int *)ses.type;
    v70.hasFinished = *(std::vector<bool> *)&ses.index;
    LOWORD(v70.leaderLapCount) = WORD2(ses.startTime);
    BYTE2(v70.leaderLapCount) = BYTE6(ses.startTime);
    startingpositions._Myend = (int *)&v57;
    v57._Impl = 0;
    v72 = 8;
    v55 = (int *)operator new(80);
    if ( v55 )
      goto $LN1208;
    std::_Xbad_alloc();
  }
  v55 = (int *)&v54->second._Impl;
  while ( *v55 )
  {
    (*(void (**)(int, RemoteSession *))(*(_DWORD *)*v55 + 8))(*v55, &ses);
    ++v54;
    v55 += 8;
    if ( v54 == this->evOnOnlineNewSession.handlers._Mylast )
      goto LABEL_85;
  }
  std::_Xbad_function_call();
$LN1208:
  v64 = v55;
  v59 = v55;
  *v55 = (int)&std::_Func_impl<std::_Callable_obj<_lambda_917dba4247aaddcdf1f957f212166217_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
  v55[2] = setName._Myres;
  v55[3] = (int)v70.positions._Myfirst;
  v55[9] = 7;
  v55[8] = 0;
  *((_WORD *)v55 + 8) = 0;
  v72 = 12;
  std::wstring::assign((std::wstring *)(v55 + 4), (const std::wstring *)&v70.positions._Mylast, 0, 0xFFFFFFFF);
  v55[10] = (int)v70.lapCounter._Mylast;
  v55[11] = (int)v70.lapCounter._Myend;
  *((std::vector<bool> *)v55 + 3) = v70.hasFinished;
  *((_WORD *)v55 + 32) = v70.leaderLapCount;
  *((_BYTE *)v55 + 66) = BYTE2(v70.leaderLapCount);
  v72 = 7;
  startingpositions._Myend[4] = (int)v55;
  PhysicsAvatar::executeOnPhysicsThread(this->sim->physicsAvatar, v57);
  if ( v70.lapCounter._Myfirst >= (int *)8 )
    operator delete(v70.positions._Mylast);
  RemoteSessionResult::~RemoteSessionResult((RemoteSessionResult *)&index);
  v72 = 0;
  if ( v61 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&v61);
    operator delete(v61);
    v61 = 0;
    startingpositions._Myfirst = 0;
    startingpositions._Mylast = 0;
  }
  if ( ses.name._Mysize >= 8 )
    operator delete(sessionResults.leaderLapCount);
}
void ACClient::onPhysicsStep(ACClient *this, long double pt)
{
  ICarControlsProvider *v3; // eax
  CarAvatar *v4; // eax
  TimeTransponder *v5; // eax
  __int16 v6; // cx
  ClientCollisionEvent *v7; // edi
  unsigned int v8; // ecx
  ClientCollisionEvent *v9; // esi
  unsigned int v10; // edx
  unsigned __int8 *v11; // ecx
  unsigned int v12; // edx
  vec3f *v13; // eax
  unsigned int v14; // edx
  unsigned __int8 *v15; // ecx
  vec3f *v16; // [esp+20h] [ebp-30h]
  UDPPacket pak; // [esp+24h] [ebp-2Ch] BYREF
  int v18; // [esp+4Ch] [ebp-4h]

  if ( (dword_186E860 & 1) == 0 )
  {
    perfCounter.name = "ACClient::onPhysicsStep";
    dword_186E860 |= 1u;
    perfCounter.group = Physics;
    perfCounter.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"ACClient::onPhysicsStep" | 0xFF000000;
  }
  v3 = Car::getControlsProvider(this->car);
  this->isFlashingCache |= ((int (*)(ICarControlsProvider *, int))v3->getAction)(v3, 10);
  ACClient::sendCarPosition(this);
  UDPSocket::receive(&this->sok, 10);
  TCPSocket::receive(&this->tcpSock, 10);
  if ( this->currentSession.type == Race && this->currentSession.startTime > pt )
  {
    v4 = Sim::getCar(this->sim, 0);
    v5 = CarAvatar::getTimeTransponder(v4);
    if ( v5 )
      v5->t = 0;
  }
  ACClient::updateQOS(this, pt);
  if ( pt - this->lastClientEventSendTime > 5000.0 )
  {
    if ( this->clientColissionEvents._Myfirst != this->clientColissionEvents._Mylast )
    {
      UDPPacket::UDPPacket(&pak);
      v18 = 0;
      pak.data[pak.size] = -126;
      v6 = this->clientColissionEvents._Mylast - this->clientColissionEvents._Myfirst;
      *(_WORD *)&pak.data[++pak.size] = v6;
      v7 = this->clientColissionEvents._Mylast;
      v8 = pak.size + 2;
      v9 = this->clientColissionEvents._Myfirst;
      pak.size += 2;
      if ( v9 != v7 )
      {
        v16 = &v9->worldPos;
        do
        {
          if ( v9->netCar )
          {
            pak.data[v8] = 10;
            pak.data[++pak.size] = v9->netCar->sessionID;
            ++pak.size;
            ACClient::onCollisionWithCar(this);
            v10 = pak.size;
          }
          else
          {
            pak.data[v8] = 11;
            v10 = ++pak.size;
          }
          ++v9;
          *(float *)&pak.data[v10] = v16[-1].z;
          v11 = pak.data;
          v12 = pak.size + 4;
          pak.size = v12;
          *(_QWORD *)&pak.data[v12] = *(_QWORD *)&v16->x;
          *(float *)&v11[v12 + 8] = v16->z;
          v13 = v16;
          v14 = pak.size + 12;
          v15 = pak.data;
          v16 = (vec3f *)((char *)v16 + 32);
          pak.size = v14;
          *(_QWORD *)&pak.data[v14] = *(_QWORD *)&v13[1].x;
          *(float *)&v15[v14 + 8] = v13[1].z;
          v8 = pak.size + 12;
          pak.size += 12;
        }
        while ( v9 != v7 );
      }
      UDPPacket::send(&pak, &this->tcpSock);
      std::_Container_base0::_Orphan_all(&this->clientColissionEvents);
      this->clientColissionEvents._Mylast = this->clientColissionEvents._Myfirst;
      v18 = -1;
      UDPPacket::~UDPPacket(&pak);
    }
    this->lastClientEventSendTime = pt;
  }
}
void ACClient::onRemoteLapCompleted(ACClient *this, UDPPacket *pak)
{
  unsigned __int8 v3; // bl
  NetCarStateProvider **v4; // eax
  NetCarStateProvider **v5; // ecx
  NetCarStateProvider *v6; // edi
  unsigned int v7; // ebx
  unsigned __int8 v8; // al
  CarAvatar *v9; // eax
  std::wstring *v10; // ebx
  unsigned int v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // eax
  CarAvatar *v14; // eax
  std::wstring *v15; // eax
  std::wstring *v16; // edi
  unsigned int v17; // eax
  unsigned int v18; // ecx
  unsigned int v19; // eax
  UDPPacket *v20; // edi
  TyreTester *v21; // ebx
  int v22; // ebx
  CarAvatar *v23; // eax
  NetCarStateProvider **v24; // eax
  NetCarStateProvider **v25; // ecx
  int v26; // edi
  bool v27; // zf
  unsigned int *v28; // eax
  unsigned int v29; // edx
  unsigned int v30; // edx
  char v31; // di
  unsigned int v32; // edx
  int v33; // edx
  char v34; // cl
  unsigned int v35; // edi
  Sim *v36; // ecx
  CarAvatar *v37; // edi
  NetCarStateProvider **v38; // eax
  NetCarStateProvider **v39; // ecx
  Track *v40; // esi
  int v41; // eax
  unsigned int v42; // ecx
  int v43; // edi
  Sim *v44; // ecx
  std::function<void __cdecl(void)> grip; // [esp-14h] [ebp-144h] BYREF
  unsigned __int8 v46; // [esp+1Bh] [ebp-115h]
  unsigned int rcv_lapCounter; // [esp+1Ch] [ebp-114h] BYREF
  bool v48; // [esp+23h] [ebp-10Dh]
  unsigned int v49; // [esp+24h] [ebp-10Ch]
  TyreTester *v50; // [esp+28h] [ebp-108h]
  unsigned int laptime; // [esp+2Ch] [ebp-104h] BYREF
  UDPPacket *v52; // [esp+30h] [ebp-100h]
  int ses_id; // [esp+34h] [ebp-FCh]
  int v54; // [esp+38h] [ebp-F8h]
  unsigned int v55; // [esp+3Ch] [ebp-F4h]
  OnLapCompletedEvent ev; // [esp+40h] [ebp-F0h] BYREF
  unsigned int v57; // [esp+70h] [ebp-C0h]
  unsigned int v58; // [esp+74h] [ebp-BCh]
  ACClient *v59; // [esp+78h] [ebp-B8h]
  RemoteSessionResult sessionResults; // [esp+80h] [ebp-B0h] BYREF
  std::wstring _Right; // [esp+B8h] [ebp-78h] BYREF
  long double v62; // [esp+D0h] [ebp-60h]
  bool v63; // [esp+D8h] [ebp-58h]
  int v64; // [esp+DCh] [ebp-54h]
  ACClient *v65; // [esp+E0h] [ebp-50h]
  Lap l; // [esp+ECh] [ebp-44h] BYREF
  int v67; // [esp+12Ch] [ebp-4h]

  v52 = pak;
  v3 = UDPPacket::read<unsigned char>(pak);
  LOBYTE(ses_id) = v3;
  v54 = v3;
  _printf("ON REMOTE LAP COMPLETED BY SES ID:%d\n", v3);
  v4 = this->netCars._Myfirst;
  v5 = this->netCars._Mylast;
  if ( v4 == v5 )
  {
LABEL_4:
    v6 = 0;
  }
  else
  {
    while ( 1 )
    {
      v6 = *v4;
      if ( (*v4)->sessionID == v3 )
        break;
      if ( ++v4 == v5 )
        goto LABEL_4;
    }
  }
  v7 = UDPPacket::read<unsigned int>(v52);
  laptime = v7;
  v8 = UDPPacket::read<unsigned char>(v52);
  v46 = v8;
  if ( v6 )
  {
    l.splits._Myfirst = 0;
    l.splits._Mylast = 0;
    l.splits._Myend = 0;
    l.compound._Myres = 7;
    l.compound._Mysize = 0;
    l.compound._Bx._Buf[0] = 0;
    v67 = 1;
    l.time = v7;
    l.isValid = v8 == 0;
    rcv_lapCounter = v8;
    l.cuts = v8;
    *(_QWORD *)_Right._Bx._Buf = 0i64;
    *(_DWORD *)&_Right._Bx._Alias[8] = 0;
    std::vector<WingState>::operator=((std::vector<WingState> *)&l.splits, (std::vector<WingState> *)&_Right);
    LOBYTE(v67) = 0;
    if ( _Right._Bx._Ptr )
    {
      std::_Container_base0::_Orphan_all(&_Right);
      operator delete(_Right._Bx._Ptr);
    }
    v9 = ACClient::getCarAvatarFromSessionID(this, ses_id);
    v10 = CarAvatar::getCurrentCompoundShortName(v9, &_Right);
    if ( &l.compound != v10 )
    {
      if ( l.compound._Myres >= 8 )
        operator delete(l.compound._Bx._Ptr);
      l.compound._Myres = 7;
      l.compound._Mysize = 0;
      l.compound._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&l.compound, v10);
    }
    if ( _Right._Myres >= 8 )
      operator delete(_Right._Bx._Ptr);
    std::vector<Lap>::push_back(&v6->laps, &l);
    v27 = v46 == 0;
    v11 = laptime;
    v6->lastTime = v6->lastUpdateTime;
    v6->lastLap = v11;
    if ( v27 )
    {
      v12 = v6->bestLap;
      if ( v11 < v12 || !v12 )
      {
        v6->bestLap = v11;
        v13 = this->globalBestlap;
        if ( !v13 || v13 > v11 )
          this->globalBestlap = v11;
      }
    }
    ACClient::storeSplitToLap(this, &v6->currentSplits, &v6->personalBestSplits, &v6->laps, &laptime, &rcv_lapCounter);
    v67 = -1;
    Lap::~Lap(&l);
  }
  if ( (_BYTE)ses_id == this->sessionID )
  {
    this->localCarLastLap.time = laptime;
    *(_QWORD *)_Right._Bx._Buf = 0i64;
    *(_DWORD *)&_Right._Bx._Alias[8] = 0;
    v67 = 2;
    std::vector<WingState>::operator=(
      (std::vector<WingState> *)&this->localCarLastLap.splits,
      (std::vector<WingState> *)&_Right);
    v67 = -1;
    if ( _Right._Bx._Ptr )
    {
      std::_Container_base0::_Orphan_all(&_Right);
      operator delete(_Right._Bx._Ptr);
    }
    v27 = v46 == 0;
    v49 = v46;
    this->localCarLastLap.cuts = v46;
    this->localCarLastLap.isValid = v27;
    v14 = ACClient::getCarAvatarFromSessionID(this, ses_id);
    v15 = CarAvatar::getCurrentCompoundShortName(v14, &_Right);
    v16 = &this->localCarLastLap.compound;
    rcv_lapCounter = (unsigned int)v15;
    if ( &this->localCarLastLap.compound != v15 )
    {
      if ( this->localCarLastLap.compound._Myres >= 8 )
      {
        operator delete(v16->_Bx._Ptr);
        v15 = (std::wstring *)rcv_lapCounter;
      }
      this->localCarLastLap.compound._Myres = 7;
      this->localCarLastLap.compound._Mysize = 0;
      v16->_Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&this->localCarLastLap.compound, v15);
    }
    if ( _Right._Myres >= 8 )
      operator delete(_Right._Bx._Ptr);
    std::vector<Lap>::push_back(&this->localCarLaps, &this->localCarLastLap);
    if ( !v46 )
    {
      v17 = this->localCarBestLap;
      v18 = laptime;
      if ( laptime < v17 || !v17 )
      {
        v19 = this->globalBestlap;
        this->localCarBestLap = laptime;
        if ( !v19 || v19 > v18 )
          this->globalBestlap = v18;
      }
    }
    rcv_lapCounter = v49;
    ACClient::storeSplitToLap(
      this,
      &this->localCarCurrentSplits,
      &this->localCarBestSplits,
      &this->localCarLaps,
      &laptime,
      &rcv_lapCounter);
  }
  v20 = v52;
  UDPPacket::read<unsigned char>(v52);
  v21 = (TyreTester *)(this->netCars._Mylast - this->netCars._Myfirst + 1);
  v50 = v21;
  RemoteSessionResult::RemoteSessionResult(&sessionResults, (int)v21);
  v67 = 3;
  v49 = 0;
  if ( v21 )
  {
    while ( 1 )
    {
      v22 = UDPPacket::read<unsigned char>(v20);
      v55 = UDPPacket::read<unsigned int>(v20);
      rcv_lapCounter = (unsigned __int16)UDPPacket::read<unsigned short>(v20);
      if ( (_BYTE)v22 == this->sessionID )
      {
        v23 = Sim::getCar(this->sim, 0);
      }
      else
      {
        v24 = this->netCars._Myfirst;
        v25 = this->netCars._Mylast;
        if ( v24 == v25 )
        {
LABEL_45:
          _printf("ERROR: Cannot find car with sessionID: %d\n", v22);
          v23 = 0;
        }
        else
        {
          while ( (*v24)->sessionID != (_BYTE)v22 )
          {
            if ( ++v24 == v25 )
              goto LABEL_45;
          }
          v23 = (*v24)->avatar;
        }
      }
      v26 = CarAvatar::getGuid(v23);
      v27 = UDPPacket::read<unsigned char>(v52) == 0;
      v28 = &rcv_lapCounter;
      v48 = !v27;
      if ( sessionResults.leaderLapCount >= rcv_lapCounter )
        v28 = &sessionResults.leaderLapCount;
      sessionResults.leaderLapCount = *v28;
      sessionResults.positions._Myfirst[v49] = v26;
      v29 = v55;
      sessionResults.times._Myfirst[v26] = v55;
      if ( v29 == 999999999 )
        sessionResults.times._Myfirst[v26] = 0;
      sessionResults.lapCounter._Myfirst[v26] = rcv_lapCounter;
      v30 = v26;
      v31 = v26 & 0x1F;
      v32 = v30 >> 5;
      if ( v27 )
        sessionResults.hasFinished._Myvec._Myfirst[v32] &= ~(1 << v31);
      else
        sessionResults.hasFinished._Myvec._Myfirst[v32] |= 1 << v31;
      v33 = this->sessionID;
      v34 = v48;
      if ( v22 == v33 )
        this->hasPlayerFinished = v48;
      if ( this->currentSession.type == Race )
      {
        if ( v54 == v22 && !v49 )
        {
          if ( this->currentSession.isTimedRace
            && (double)this->currentSession.time * 60.0 * 1000.0
             - (this->sim->game->gameTime.now
              - this->currentSession.startTime) < 0.0
            && this->hasExtraLap )
          {
            this->isLastLap = 1;
          }
          this->hasLeaderFinished = v34;
        }
        if ( v34 && this->raceClosingTime == 0.0 )
          this->raceClosingTime = (double)this->raceOverTime + this->sim->game->gameTime.now;
        if ( v22 == v33
          && !this->currentSession.isTimedRace
          && sessionResults.leaderLapCount == this->currentSession.laps - 1 )
        {
          this->isLastLap = 1;
        }
      }
      if ( ++v49 >= (unsigned int)v50 )
        break;
      v20 = v52;
    }
  }
  v50 = (TyreTester *)&ev;
  std::vector<Mesh *>::vector<Mesh *>(
    (std::vector<TyreThermalPatch *> *)&ev,
    (const std::vector<TyreThermalPatch *> *)&sessionResults);
  LOBYTE(v67) = 4;
  std::vector<Mesh *>::vector<Mesh *>(
    (std::vector<TyreThermalPatch *> *)&ev.splits,
    (const std::vector<TyreThermalPatch *> *)&sessionResults.times);
  LOBYTE(v67) = 5;
  std::vector<Mesh *>::vector<Mesh *>(
    (std::vector<TyreThermalPatch *> *)&ev.eventTime,
    (const std::vector<TyreThermalPatch *> *)&sessionResults.lapCounter);
  LOBYTE(v67) = 6;
  std::vector<unsigned int>::vector<unsigned int>(
    (std::vector<unsigned int> *)&ev.cuts,
    &sessionResults.hasFinished._Myvec);
  v57 = sessionResults.hasFinished._Mysize;
  v58 = sessionResults.leaderLapCount;
  v59 = this;
  v50 = (TyreTester *)&grip;
  grip._Impl = 0;
  LOBYTE(v67) = 8;
  v35 = operator new(68);
  if ( !v35 )
    std::_Xbad_alloc();
  v55 = v35;
  rcv_lapCounter = v35;
  LOBYTE(v67) = 12;
  *(_DWORD *)v35 = &std::_Func_impl<std::_Callable_obj<_lambda_a05cde93ad1ae34cde6819468c04a3fa_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
  lambda_a05cde93ad1ae34cde6819468c04a3fa_::_lambda_a05cde93ad1ae34cde6819468c04a3fa_(
    (ACClient::onRemoteLapCompleted::__l56::<lambda_a05cde93ad1ae34cde6819468c04a3fa> *)(v35 + 4),
    (const ACClient::onRemoteLapCompleted::__l56::<lambda_a05cde93ad1ae34cde6819468c04a3fa> *)&ev);
  grip._Impl = (std::_Func_base<void> *)v35;
  v36 = this->sim;
  LOBYTE(v67) = 7;
  Sim::executeOnMainThread(v36, grip);
  LOBYTE(v67) = 3;
  RemoteSessionResult::~RemoteSessionResult((RemoteSessionResult *)&ev);
  if ( (_BYTE)ses_id == this->sessionID )
  {
    v37 = Sim::getCar(this->sim, 0);
  }
  else
  {
    v38 = this->netCars._Myfirst;
    v39 = this->netCars._Mylast;
    if ( v38 == v39 )
    {
LABEL_79:
      _printf("ERROR: Cannot find car with sessionID: %d\n", v54);
      goto LABEL_80;
    }
    while ( (*v38)->sessionID != (_BYTE)ses_id )
    {
      if ( ++v38 == v39 )
        goto LABEL_79;
    }
    v37 = (*v38)->avatar;
  }
  if ( v37 )
  {
    ev.splits._Myfirst = 0;
    ev.splits._Mylast = 0;
    ev.splits._Myend = 0;
    ev.cuts = 0;
    ev.carIndex = 0;
    ev.lapTime = 0;
    ev.lapCount = 0;
    ev.eventTime = 0.0;
    ev.isValid = 0;
    LOBYTE(v67) = 13;
    ev.carIndex = CarAvatar::getGuid(v37);
    ev.eventTime = this->car->ksPhysics->physicsTime;
    v41 = CarAvatar::getGuid(v37);
    v42 = sessionResults.lapCounter._Myfirst[v41];
    ev.isValid = v46 == 0;
    ev.cuts = v46;
    *(_QWORD *)_Right._Bx._Buf = __PAIR64__(laptime, ev.carIndex);
    ev.lapCount = v42;
    *(_DWORD *)&_Right._Bx._Alias[8] = v42;
    ev.lapTime = laptime;
    std::vector<Mesh *>::vector<Mesh *>(
      (std::vector<TyreThermalPatch *> *)&_Right._Bx._Alias[12],
      (const std::vector<TyreThermalPatch *> *)&ev.splits);
    v63 = ev.isValid;
    v62 = ev.eventTime;
    v64 = ev.cuts;
    v65 = this;
    v50 = (TyreTester *)&grip;
    grip._Impl = 0;
    LOBYTE(v67) = 15;
    v43 = operator new(64);
    if ( !v43 )
      std::_Xbad_alloc();
    v55 = v43;
    v54 = v43;
    *(_DWORD *)v43 = &std::_Func_impl<std::_Callable_obj<_lambda_a8437c01ad429eb8483fb0d50f1b0bec_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)(v43 + 8) = *(_QWORD *)_Right._Bx._Buf;
    *(_DWORD *)(v43 + 16) = *(_DWORD *)&_Right._Bx._Alias[8];
    LOBYTE(v67) = 19;
    std::vector<Mesh *>::vector<Mesh *>(
      (std::vector<TyreThermalPatch *> *)(v43 + 20),
      (const std::vector<TyreThermalPatch *> *)&_Right._Bx._Alias[12]);
    *(long double *)(v43 + 32) = v62;
    *(_BYTE *)(v43 + 40) = v63;
    *(_DWORD *)(v43 + 44) = v64;
    *(_DWORD *)(v43 + 48) = v65;
    grip._Impl = (std::_Func_base<void> *)v43;
    v44 = this->sim;
    LOBYTE(v67) = 14;
    Sim::executeOnMainThread(v44, grip);
    LOBYTE(v67) = 13;
    if ( *(_DWORD *)&_Right._Bx._Alias[12] )
    {
      std::_Container_base0::_Orphan_all((std::_Container_base0 *)&_Right._Bx._Alias[12]);
      operator delete(*(_DWORD *)&_Right._Bx._Alias[12]);
    }
    LOBYTE(v67) = 3;
    if ( ev.splits._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&ev.splits);
      operator delete(ev.splits._Myfirst);
    }
  }
LABEL_80:
  v40 = this->sim->physicsAvatar->engine.track;
  *(float *)&(&grip._Impl)[1] = UDPPacket::read<float>(v52);
  Track::setGripLevelExternal(v40, *(float *)&(&grip._Impl)[1]);
  RemoteSessionResult::~RemoteSessionResult(&sessionResults);
}
void ACClient::onRemoteSectorSplit(ACClient *this, UDPPacket *pak)
{
  unsigned __int8 v3; // bl
  unsigned int v4; // edi
  unsigned __int8 v5; // al
  NetCarStateProvider **v6; // ecx
  unsigned int v7; // edx
  NetCarStateProvider **v8; // eax
  NetCarStateProvider *v9; // esi
  unsigned int sector_time; // [esp+10h] [ebp-20h] BYREF
  unsigned int cuts; // [esp+14h] [ebp-1Ch] BYREF
  unsigned int sector; // [esp+18h] [ebp-18h] BYREF
  OnSectorSplitEvent ev; // [esp+1Ch] [ebp-14h] BYREF

  v3 = UDPPacket::read<unsigned char>(pak);
  v4 = UDPPacket::read<unsigned char>(pak);
  sector_time = UDPPacket::read<unsigned int>(pak);
  v5 = UDPPacket::read<unsigned char>(pak);
  v6 = this->netCars._Myfirst;
  v7 = v5;
  v8 = this->netCars._Mylast;
  cuts = v7;
  if ( v6 != v8 )
  {
    while ( 1 )
    {
      v9 = *v6;
      if ( (*v6)->sessionID == v3 )
        break;
      if ( ++v6 == v8 )
        return;
    }
    ev.carIndex = v3;
    ev.sectorTime = sector_time;
    ev.sectorIndex = v4;
    ev.cuts = v7;
    Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&v9->evOnSectorSplit, (const OnGearRequestEvent *)&ev);
    sector = v4;
    ACClient::addSplitToBest(this, &v9->currentSplits, &v9->personalBestSplits, &sector, &sector_time, &cuts);
  }
}
void ACClient::onRemoteSunAngleReceived(ACClient *this, float angle)
{
  Sim *v2; // ecx
  std::function<void __cdecl(void)> v3; // [esp-18h] [ebp-34h] BYREF
  float v4; // [esp+Ch] [ebp-10h]
  int v5; // [esp+18h] [ebp-4h]

  v4 = angle;
  v3._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_3a3898a54f948dfae0db6ce4a4cf85d5_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
  *(_QWORD *)&v3._Space._Alias[4] = __PAIR64__(LODWORD(angle), (unsigned int)this);
  v3._Impl = (std::_Func_base<void> *)&v3;
  v2 = this->sim;
  v5 = -1;
  Sim::executeOnMainThread(v2, v3);
}
void ACClient::onSectorSplit(ACClient *this, const OnSectorSplitEvent *ev)
{
  unsigned __int8 v3; // cl
  unsigned int v4; // ecx
  unsigned int *v5; // eax
  unsigned int v6; // edx
  bool v7; // cf
  IPAddress v8; // xmm0
  int v9; // [esp+14h] [ebp-30h] BYREF
  UDPPacket pak; // [esp+18h] [ebp-2Ch] BYREF
  int v11; // [esp+40h] [ebp-4h]

  UDPPacket::UDPPacket(&pak);
  v9 = 255;
  v11 = 0;
  pak.data[pak.size] = 88;
  v3 = ev->sectorIndex;
  pak.data[++pak.size] = v3;
  v4 = ev->sectorTime;
  *(_DWORD *)&pak.data[++pak.size] = v4;
  v5 = (unsigned int *)&v9;
  v6 = pak.size + 4;
  v7 = ev->cuts < 0xFF;
  pak.size += 4;
  if ( v7 )
    v5 = &ev->cuts;
  pak.data[v6] = *(_BYTE *)v5;
  v8 = (IPAddress)_mm_loadu_si128((const __m128i *)&this->serverIP);
  ++pak.size;
  pak.targetIP = v8;
  UDPPacket::send(&pak, &this->tcpSock);
  ACClient::addSplitToBest(
    this,
    &this->localCarCurrentSplits,
    &this->localCarBestSplits,
    &ev->sectorIndex,
    &ev->sectorTime,
    &ev->cuts);
  v11 = -1;
  UDPPacket::~UDPPacket(&pak);
}
void ACClient::onSetupReceived(ACClient *this, UDPPacket *pak)
{
  UDPPacket *v2; // ebx
  int v3; // esi
  std::_Tree_node<std::pair<std::string const ,float>,void *> *v4; // eax
  std::_Tree_node<std::pair<std::string const ,float>,void *> *v5; // eax
  std::_Tree_node<std::pair<std::string const ,float>,void *> *v6; // esi
  const char *v7; // edx
  unsigned int v8; // edi
  std::string *v9; // ecx
  unsigned int v10; // ebx
  unsigned int v11; // eax
  int v12; // eax
  bool v13; // sf
  int v14; // eax
  std::_Tree_node<std::pair<std::string const ,float>,void *> *v15; // eax
  bool v16; // zf
  float v17; // ebx
  std::function<void __cdecl(void)> v18; // [esp-18h] [ebp-7Ch] BYREF
  std::tuple<> v19; // [esp+17h] [ebp-4Dh] BYREF
  std::map<std::string,float> setup_map; // [esp+18h] [ebp-4Ch] BYREF
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const ,float> > > > v21; // [esp+20h] [ebp-44h] BYREF
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const ,float> > > > result; // [esp+24h] [ebp-40h] BYREF
  ACClient *v23; // [esp+28h] [ebp-3Ch]
  int v24; // [esp+2Ch] [ebp-38h]
  float value; // [esp+30h] [ebp-34h]
  std::tuple<std::string const &> v26; // [esp+34h] [ebp-30h] BYREF
  std::string key; // [esp+38h] [ebp-2Ch] BYREF
  int v28; // [esp+60h] [ebp-4h]

  v23 = this;
  v2 = pak;
  v21._Ptr = (std::_Tree_node<std::pair<std::string const ,float>,void *> *)pak;
  UDPPacket::read<unsigned char>(pak);
  v3 = UDPPacket::read<unsigned char>(pak);
  v24 = v3;
  setup_map._Myhead = 0;
  setup_map._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const,int>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,TyreCompoundStrategy>> > *)&setup_map);
  setup_map._Myhead = v4;
  v28 = 0;
  if ( v3 > 0 )
  {
    do
    {
      UDPPacket::readString(v2, &key);
      LOBYTE(v28) = 1;
      value = UDPPacket::read<float>(v2);
      v5 = std::_Tree<std::_Tmap_traits<std::string,float,std::less<std::string>,std::allocator<std::pair<std::string const,float>>,0>>::_Lbound(
             &setup_map,
             &key);
      v6 = v5;
      if ( v5 == setup_map._Myhead )
        goto LABEL_15;
      v7 = v5->_Myval.first._Bx._Buf;
      v8 = v5->_Myval.first._Mysize;
      if ( v5->_Myval.first._Myres >= 0x10 )
        v7 = *(const char **)v7;
      v9 = &key;
      v10 = key._Mysize;
      v11 = v5->_Myval.first._Mysize;
      if ( key._Myres >= 0x10 )
        v9 = (std::string *)key._Bx._Ptr;
      if ( key._Mysize < v8 )
        v11 = key._Mysize;
      v12 = std::char_traits<char>::compare(v9->_Bx._Buf, v7, v11);
      v13 = v12 < 0;
      if ( !v12 )
      {
        if ( v10 >= v8 )
          v14 = v10 != v8;
        else
          v14 = -1;
        v13 = v14 < 0;
      }
      if ( v13 )
      {
LABEL_15:
        v26._Myfirst._Val = &key;
        v15 = (std::_Tree_node<std::pair<std::string const ,float>,void *> *)std::_Tree_buy<std::pair<std::string const,float>>::_Buynode<std::piecewise_construct_t const &,std::tuple<std::string const &>,std::tuple<>>(
                                                                               &setup_map,
                                                                               &piecewise_construct,
                                                                               &v26,
                                                                               &v19);
        std::_Tree<std::_Tmap_traits<std::string,float,std::less<std::string>,std::allocator<std::pair<std::string const,float>>,0>>::_Insert_hint<std::pair<std::string const,float> &,std::_Tree_node<std::pair<std::string const,float>,void *> *>(
          &setup_map,
          &result,
          (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const ,float> > > >)v6,
          &v15->_Myval,
          v15);
        v6 = result._Ptr;
      }
      v6->_Myval.second = value;
      LOBYTE(v28) = 0;
      if ( key._Myres >= 0x10 )
        operator delete(key._Bx._Ptr);
      v16 = v24-- == 1;
      v2 = (UDPPacket *)v21._Ptr;
    }
    while ( !v16 );
  }
  std::_Tree<std::_Tmap_traits<std::string,float,std::less<std::string>,std::allocator<std::pair<std::string const,float>>,0>>::_Tree<std::_Tmap_traits<std::string,float,std::less<std::string>,std::allocator<std::pair<std::string const,float>>,0>>(
    (std::_Tree<std::_Tmap_traits<std::string,float,std::less<std::string >,std::allocator<std::pair<std::string const ,float> >,0> > *)&key,
    &setup_map,
    (const std::allocator<std::pair<std::string const ,float> > *)&v19);
  *(_DWORD *)&key._Bx._Alias[8] = v23;
  v21._Ptr = (std::_Tree_node<std::pair<std::string const ,float>,void *> *)&v18;
  v18._Impl = 0;
  LOBYTE(v28) = 3;
  v17 = COERCE_FLOAT(operator new(20));
  if ( v17 == 0.0 )
    std::_Xbad_alloc();
  value = v17;
  result._Ptr = (std::_Tree_node<std::pair<std::string const ,float>,void *> *)LODWORD(v17);
  LOBYTE(v28) = 7;
  *(_DWORD *)LODWORD(v17) = &std::_Func_impl<std::_Callable_obj<_lambda_e21ada54cf8d695cebd35b33b8a9ff28_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
  std::_Tree<std::_Tmap_traits<std::string,float,std::less<std::string>,std::allocator<std::pair<std::string const,float>>,0>>::_Tree<std::_Tmap_traits<std::string,float,std::less<std::string>,std::allocator<std::pair<std::string const,float>>,0>>(
    (std::_Tree<std::_Tmap_traits<std::string,float,std::less<std::string >,std::allocator<std::pair<std::string const ,float> >,0> > *)(LODWORD(v17) + 4),
    (const std::_Tree<std::_Tmap_traits<std::string,float,std::less<std::string >,std::allocator<std::pair<std::string const ,float> >,0> > *)&key,
    (const std::allocator<std::pair<std::string const ,float> > *)&v19);
  *(_DWORD *)(LODWORD(v17) + 12) = *(_DWORD *)&key._Bx._Alias[8];
  *(float *)&v18._Impl = v17;
  LOBYTE(v28) = 2;
  Sim::executeOnMainThread(v23->sim, v18);
  LOBYTE(v28) = 0;
  std::_Tree<std::_Tmap_traits<std::string,float,std::less<std::string>,std::allocator<std::pair<std::string const,float>>,0>>::erase(
    (std::_Tree<std::_Tmap_traits<std::string,float,std::less<std::string >,std::allocator<std::pair<std::string const ,float> >,0> > *)&key,
    &v21,
    *(std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const ,float> > > > *)key._Bx._Ptr,
    *(std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const ,float> > > > *)key._Bx._Buf);
  operator delete(key._Bx._Ptr);
  v28 = -1;
  std::_Tree<std::_Tmap_traits<std::string,float,std::less<std::string>,std::allocator<std::pair<std::string const,float>>,0>>::erase(
    &setup_map,
    &v21,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const ,float> > > >)setup_map._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::string const ,float> > > >)setup_map._Myhead);
  operator delete(setup_map._Myhead);
}
void ACClient::onTyreCompoundChanged(ACClient *this, const std::wstring *shortName)
{
  UDPPacket pak; // [esp+Ch] [ebp-2Ch] BYREF
  int v4; // [esp+34h] [ebp-4h]

  UDPPacket::UDPPacket(&pak);
  v4 = 0;
  pak.data[pak.size++] = 80;
  UDPPacket::writeStringANSI(&pak, shortName);
  UDPPacket::send(&pak, &this->tcpSock);
  v4 = -1;
  UDPPacket::~UDPPacket(&pak);
}
void ACClient::onWelcomeMessageReceived(ACClient *this, UDPPacket *pak)
{
  std::wstring *v3; // edi
  std::wstring *v4; // esi
  std::wstring result; // [esp+8h] [ebp-1Ch] BYREF

  v3 = UDPPacket::readBigStringW(pak, &result);
  v4 = &this->welcomeMessage;
  if ( v4 != v3 )
  {
    if ( v4->_Myres >= 8 )
      operator delete(v4->_Bx._Ptr);
    v4->_Myres = 7;
    v4->_Mysize = 0;
    v4->_Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(v4, v3);
  }
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
}
void ACClient::renderHUD(ACClient *this, float dt)
{
  GLRenderer *v3; // esi
  Game *v4; // eax
  GLRenderer *v5; // esi
  Font *v6; // ecx
  std::wstring s; // [esp+24h] [ebp-28h] BYREF
  int v8; // [esp+48h] [ebp-4h]

  GhostCarRecorder::update((TyreTester *)this, dt);
  if ( this->welcomeMessage._Mysize )
  {
    v3 = this->game->graphics->gl;
    GLRenderer::color4f(v3, 0.0, 0.0, 0.0, 0.85000002);
    GLRenderer::quad(
      v3,
      100.0,
      100.0,
      (float)(this->game->graphics->videoSettings.width - 200),
      (float)(this->game->graphics->videoSettings.height - 150),
      0,
      0);
    Font::setColor(this->font, 1.0, 1.0, 1.0, 1.0);
    Font::blitString(this->font, 150.0, 150.0, &this->welcomeMessage, 0.80000001, eAlignLeft);
    s._Myres = 7;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
    std::wstring::assign(&s, L"click to close", 0xEu);
    v4 = this->game;
    v8 = 0;
    Font::blitString(
      this->font,
      (float)v4->graphics->videoSettings.width * 0.5,
      (float)(v4->graphics->videoSettings.height - 100),
      &s,
      0.5,
      eAlignCenter);
    v8 = -1;
    if ( s._Myres >= 8 )
      operator delete(s._Bx._Ptr);
    s._Myres = 7;
    s._Mysize = 0;
    s._Bx._Buf[0] = 0;
  }
  if ( this->dcCountdown.isSignaled )
  {
    v5 = this->game->graphics->gl;
    GLRenderer::color4f(v5, 0.5, 0.0, 0.0, 0.80000001);
    GLRenderer::quad(
      v5,
      0.0,
      0.0,
      (float)this->game->graphics->videoSettings.width,
      (float)this->game->graphics->videoSettings.height,
      0,
      0);
    v6 = this->font;
    if ( (int)(this->game->gameTime.now * 0.001) % 2 )
      Font::setColor(v6, 1.0, 1.0, 0.0, 1.0);
    else
      Font::setColor(v6, 1.0, 1.0, 1.0, 1.0);
    Font::blitString(
      this->font,
      (float)this->game->graphics->videoSettings.width * 0.5,
      (float)this->game->graphics->videoSettings.height * 0.5,
      &this->dcCountdown.message,
      1.0,
      eAlignCenter);
  }
}
void ACClient::resetCurrentLaps(ACClient *this)
{
  Sim *v2; // eax
  Sim *v3; // eax
  unsigned int *v4; // esi
  NetCarStateProvider **v5; // edi
  _DWORD *v6; // ebx
  std::_Container_base0 *v7; // ebx
  unsigned int *v8; // eax
  unsigned int v9; // ebx
  int v10; // [esp-8h] [ebp-40h]
  int v11; // [esp-8h] [ebp-40h]
  unsigned int v12; // [esp-8h] [ebp-40h]
  unsigned int _Pval; // [esp+18h] [ebp-20h] BYREF
  unsigned int v14; // [esp+1Ch] [ebp-1Ch] BYREF
  std::vector<unsigned int> v15; // [esp+20h] [ebp-18h] BYREF
  int v16; // [esp+34h] [ebp-4h]

  v2 = this->sim;
  _Pval = 0;
  v10 = v2->track->physicsTrack.sectorsNormalizedPositions._Mylast
      - v2->track->physicsTrack.sectorsNormalizedPositions._Myfirst;
  v15._Myfirst = 0;
  v15._Mylast = 0;
  v15._Myend = 0;
  std::vector<unsigned int>::_Construct_n(&v15, v10, &_Pval);
  v16 = 0;
  std::vector<WingState>::operator=((std::vector<WingState> *)&this->bestSplits, (std::vector<WingState> *)&v15);
  v16 = -1;
  if ( v15._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&v15);
    operator delete(v15._Myfirst);
  }
  this->globalBestlap = 0;
  std::_Container_base0::_Orphan_all(&this->localCarCurrentSplits);
  this->localCarCurrentSplits._Mylast = this->localCarCurrentSplits._Myfirst;
  v3 = this->sim;
  _Pval = 0;
  v11 = v3->track->physicsTrack.sectorsNormalizedPositions._Mylast
      - v3->track->physicsTrack.sectorsNormalizedPositions._Myfirst;
  v15._Myfirst = 0;
  v15._Mylast = 0;
  v15._Myend = 0;
  std::vector<unsigned int>::_Construct_n(&v15, v11, &_Pval);
  v16 = 1;
  std::vector<WingState>::operator=((std::vector<WingState> *)&this->localCarBestSplits, (std::vector<WingState> *)&v15);
  v16 = -1;
  if ( v15._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&v15);
    operator delete(v15._Myfirst);
  }
  std::_Container_base0::_Orphan_all(&this->localCarLaps);
  std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(this->localCarLaps._Myfirst, this->localCarLaps._Mylast);
  this->localCarLaps._Mylast = this->localCarLaps._Myfirst;
  v4 = (unsigned int *)this->netCars._Myfirst;
  v5 = this->netCars._Mylast;
  if ( v4 != (unsigned int *)v5 )
  {
    v14 = 0;
    do
    {
      _Pval = *v4;
      v6 = (_DWORD *)(_Pval + 196);
      std::_Container_base0::_Orphan_all((std::_Container_base0 *)(_Pval + 196));
      v6[1] = *v6;
      v12 = this->sim->track->physicsTrack.sectorsNormalizedPositions._Mylast
          - this->sim->track->physicsTrack.sectorsNormalizedPositions._Myfirst;
      v15._Myfirst = 0;
      v15._Mylast = 0;
      v15._Myend = 0;
      std::vector<unsigned int>::_Construct_n(&v15, v12, &v14);
      v7 = (std::_Container_base0 *)(_Pval + 208);
      v16 = 2;
      if ( (std::vector<unsigned int> *)(_Pval + 208) == &v15 )
      {
        v8 = v15._Myfirst;
      }
      else
      {
        if ( *(_DWORD *)v7 )
        {
          std::_Container_base0::_Orphan_all((std::_Container_base0 *)(_Pval + 208));
          operator delete(*(_DWORD *)v7);
          *(_DWORD *)v7 = 0;
          *(_DWORD *)&v7[4] = 0;
          *(_DWORD *)&v7[8] = 0;
        }
        std::_Container_base0::_Swap_all(v7, &v15);
        *(std::vector<unsigned int> *)v7 = v15;
        v8 = 0;
        v15._Myfirst = 0;
        v15._Mylast = 0;
        v15._Myend = 0;
      }
      v16 = -1;
      if ( v8 )
      {
        std::_Container_base0::_Orphan_all(&v15);
        operator delete(v15._Myfirst);
        v15._Myfirst = 0;
        v15._Mylast = 0;
        v15._Myend = 0;
      }
      v9 = _Pval;
      std::_Container_base0::_Orphan_all((std::_Container_base0 *)(_Pval + 240));
      std::_Destroy_range<std::_Wrap_alloc<std::allocator<Lap>>>(*(Lap **)(v9 + 240), *(Lap **)(v9 + 244));
      ++v4;
      *(_DWORD *)(v9 + 244) = *(_DWORD *)(v9 + 240);
    }
    while ( v4 != (unsigned int *)v5 );
  }
}
void ACClient::sendCarPosition(ACClient *this)
{
  Car *v2; // eax
  double v3; // xmm0_8
  unsigned __int8 v4; // cl
  Car *v5; // eax
  unsigned int v6; // ecx
  unsigned __int8 *v7; // edx
  float v8; // eax
  unsigned int v9; // esi
  vec3f *v10; // eax
  Car *v11; // eax
  unsigned __int8 *v12; // edx
  unsigned int v13; // ecx
  int v14; // xmm3_4
  float v15; // xmm2_4
  int v16; // edx
  float v17; // xmm0_4
  float v18; // xmm0_4
  float v19; // xmm1_4
  double v20; // st7
  Car *v21; // ecx
  Speed *v22; // eax
  int v23; // ecx
  int v24; // esi
  float v25; // xmm0_4
  Car *v26; // ecx
  double v27; // st7
  float v28; // xmm0_4
  float v29; // xmm0_4
  Car *v30; // ecx
  float v31; // xmm0_4
  Car *v32; // eax
  Car *v33; // ecx
  ICarControlsProvider *v34; // eax
  Car *v35; // eax
  Car *v36; // ecx
  double v37; // xmm1_8
  double v38; // xmm0_8
  int v39; // eax
  Car *v40; // eax
  Car *v41; // ecx
  IPAddress v42; // xmm0
  int v43; // eax
  std::wstring *v44; // edi
  std::wstring *v45; // esi
  std::wstring *v46; // eax
  std::wstring *v47; // eax
  std::wstring *v48; // eax
  std::wstring *v49; // eax
  std::wstring *v50; // eax
  const std::wstring *v51; // eax
  int v52; // [esp+10h] [ebp-178h]
  mat44f v53; // [esp+1Ch] [ebp-16Ch] BYREF
  __int64 v54; // [esp+5Ch] [ebp-12Ch] BYREF
  int v55; // [esp+64h] [ebp-124h]
  ACClient *v56; // [esp+68h] [ebp-120h]
  long double v57; // [esp+6Ch] [ebp-11Ch]
  double v58; // [esp+74h] [ebp-114h]
  PerformanceSplit result; // [esp+7Ch] [ebp-10Ch] BYREF
  unsigned int v60; // [esp+8Ch] [ebp-FCh]
  int v61; // [esp+90h] [ebp-F8h]
  float v62; // [esp+94h] [ebp-F4h]
  char v63; // [esp+9Bh] [ebp-EDh]
  std::wstring v64; // [esp+9Ch] [ebp-ECh] BYREF
  std::wstring v65; // [esp+B4h] [ebp-D4h] BYREF
  std::wstring v66; // [esp+CCh] [ebp-BCh] BYREF
  std::wstring v67; // [esp+E4h] [ebp-A4h] BYREF
  std::wstring v68; // [esp+FCh] [ebp-8Ch] BYREF
  std::wstring v69; // [esp+114h] [ebp-74h] BYREF
  std::wstring v70; // [esp+12Ch] [ebp-5Ch] BYREF
  std::wstring v71; // [esp+144h] [ebp-44h] BYREF
  UDPPacket v72; // [esp+15Ch] [ebp-2Ch] BYREF
  int v73; // [esp+184h] [ebp-4h]

  v56 = this;
  v2 = this->car;
  v60 = 0;
  v57 = v2->ksPhysics->physicsTime;
  if ( v57 - this->lastSendTime < this->sendInterval || this->endSession.isConnectionFinished )
    return;
  if ( !this->isAssociated )
  {
    ACClient::associate(this);
    this->lastSendTime = v57;
    return;
  }
  LODWORD(v58) = 0;
  UDPPacket::UDPPacket(&v72);
  v3 = v57;
  v73 = 0;
  v72.data[v72.size] = 70;
  v4 = this->pakSequenceIndex;
  v72.data[++v72.size] = v4;
  *(_DWORD *)&v72.data[++v72.size] = (unsigned int)v3;
  v5 = this->car;
  v72.size += 4;
  ++this->pakSequenceIndex;
  ((void (*)(IRigidBody *, mat44f *, _DWORD))v5->body->getWorldMatrix)(v5->body, &v53, 0);
  v6 = v72.size;
  v7 = v72.data;
  *((_DWORD *)&result.speedMS + 1) = LODWORD(v53.M43);
  v8 = v53.M43;
  *(_QWORD *)&v72.data[v72.size] = _mm_unpacklo_ps((__m128)LODWORD(v53.M41), (__m128)LODWORD(v53.M42)).m128_u64[0];
  *(float *)&v7[v6 + 8] = v8;
  v72.size += 12;
  v9 = v72.size;
  v10 = mat44f::toEuler(&v53, (vec3f *)((char *)&result.t + 4));
  *(vec3f *)&v72.data[v9] = *v10;
  v11 = this->car;
  v72.size += 12;
  v11->body->getVelocity(v11->body, (vec3f *)&v54);
  v12 = v72.data;
  v13 = v72.size;
  v14 = _xmm;
  v15 = FLOAT_154_0;
  *(_QWORD *)&v72.data[v72.size] = v54;
  *(_DWORD *)&v12[v13 + 8] = v55;
  v72.size += 12;
  v16 = 0;
  v61 = 1;
  HIDWORD(v58) = 0;
  do
  {
    v62 = *(float *)((char *)&this->car->tyres[0].status.angularVelocity + v16);
    v17 = v62;
    if ( COERCE_FLOAT(LODWORD(v62) & v14) > 0.1 )
    {
      LODWORD(v18) = __libm_sse2_log10f(v52).m128_u32[0];
      v19 = v62;
      if ( v62 <= 0.0 )
      {
        v62 = -1.0;
        if ( v19 >= 0.0 )
          v62 = 0.0;
      }
      else
      {
        v62 = 1.0;
      }
      v20 = _roundf(v18 * 20.0);
      v15 = FLOAT_154_0;
      v14 = _xmm;
      v62 = v20 * v62;
      v17 = v62;
    }
    if ( v17 <= v15 )
    {
      if ( v17 < -100.0 )
        v17 = FLOAT_N100_0;
    }
    else
    {
      v17 = v15;
    }
    v72.data[v72.size] = (int)(float)(v17 + 100.0);
    v21 = this->car;
    ++v72.size;
    if ( COERCE_FLOAT(*(_DWORD *)((_BYTE *)&v21->tyres[0].status.slipRatio + HIDWORD(v58)) & v14) <= 0.80000001 )
    {
      v23 = v60;
    }
    else
    {
      v22 = Car::getSpeed(v21, (Speed *)&result.speedMS + 1);
      v23 = v60 | 1;
      v60 |= 1u;
      if ( v22->value > 1.0 )
      {
        v63 = 1;
        goto LABEL_21;
      }
    }
    v63 = 0;
LABEL_21:
    if ( (v23 & 1) != 0 )
    {
      v60 = v23 & 0xFFFFFFFE;
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)(&result.speedMS + 1));
    }
    v24 = LODWORD(v58);
    if ( v63 )
    {
      v24 = v61 | LODWORD(v58);
      LODWORD(v58) |= v61;
    }
    v15 = FLOAT_154_0;
    v16 = HIDWORD(v58) + 1632;
    v14 = _xmm;
    HIDWORD(v58) = v16;
    v61 = __ROL4__(v61, 1);
  }
  while ( v16 < 6528 );
  v25 = this->car->steerLock * this->car->controls.steer;
  if ( v25 <= 127.0 )
  {
    if ( v25 < -127.0 )
      v25 = FLOAT_N127_0;
  }
  else
  {
    v25 = FLOAT_127_0;
  }
  v72.data[v72.size] = (int)(float)(v25 + 127.0);
  v26 = this->car;
  ++v72.size;
  v27 = Car::getFrontWheelAngle(v26);
  *(&result.speedMS + 1) = (v27 + v27) * 57.29578;
  if ( *(&result.speedMS + 1) <= 127.0 )
  {
    v28 = FLOAT_N127_0;
    if ( *(&result.speedMS + 1) >= -127.0 )
      v28 = *(&result.speedMS + 1);
  }
  else
  {
    v28 = FLOAT_127_0;
  }
  v29 = v28 + 127.0;
  v72.data[v72.size] = (int)v29;
  v30 = this->car;
  ++v72.size;
  v61 = (int)v29;
  v31 = FLOAT_65000_0;
  *(&result.speedMS + 1) = Drivetrain::getEngineRPM(&v30->drivetrain);
  if ( *(&result.speedMS + 1) <= 65000.0 )
  {
    v31 = FLOAT_1_0;
    if ( *(&result.speedMS + 1) >= 1.0 )
      v31 = *(&result.speedMS + 1);
  }
  *(_WORD *)&v72.data[v72.size] = (int)v31;
  v32 = this->car;
  v72.size += 2;
  v72.data[v72.size] = v32->drivetrain.currentGear;
  v33 = this->car;
  ++v72.size;
  if ( v33->controls.brake > 0.1 )
    v24 |= 0x10u;
  if ( v33->lightsOn )
    v24 |= 0x20u;
  v34 = Car::getControlsProvider(v33);
  if ( v34->getAction(v34, eHorn) )
    v24 |= 0x40u;
  *(double *)&result.speedMS = Car::getPenaltyTime(this->car);
  if ( *(double *)&result.speedMS > 0.0 )
    v24 |= 0x80u;
  if ( this->isFlashingCache )
  {
    v24 |= 0x100u;
    this->isFlashingCache = 0;
  }
  v35 = this->car;
  if ( v35->ers.isCharging )
    v24 |= 0x200u;
  if ( v35->drs.isPresent && v35->drs.isActive )
    v24 |= 0x400u;
  *(_DWORD *)&v72.data[v72.size] = v24;
  v36 = this->car;
  v72.size += 4;
  v37 = PerformanceMeter::getCurrentSplit(&v36->performanceMeter, &result)->t;
  if ( COERCE_DOUBLE(*(_QWORD *)&v37 & _xmm) <= 30.0 )
  {
    v39 = (int)(v37 * 1000.0);
  }
  else
  {
    v38 = 0.0;
    if ( v37 <= 0.0 )
    {
      if ( v37 < 0.0 )
        v38 = DOUBLE_N1_0;
      v39 = (int)(v38 * 30000.0);
    }
    else
    {
      v39 = (int)(1.0 * 30000.0);
    }
  }
  *(_WORD *)&v72.data[v72.size] = v39;
  v40 = this->car;
  v72.size += 2;
  v72.data[v72.size] = (int)(float)(v40->controls.gas * 255.0);
  v41 = this->car;
  *(float *)&v72.data[++v72.size] = v41->splineLocatorData.npos;
  v42 = (IPAddress)_mm_loadu_si128((const __m128i *)&this->serverIP);
  v72.size += 4;
  v72.targetIP = v42;
  UDPPacket::send(&v72, &this->sok);
  v43 = (unsigned __int8)v61 - 127;
  this->lastSendTime = v57;
  v44 = std::to_wstring(&v69, v43);
  HIDWORD(result.t) = LODWORD(v53.M41);
  result.speedMS = v53.M42;
  LOBYTE(v73) = 1;
  *((_DWORD *)&result.speedMS + 1) = LODWORD(v53.M43);
  v45 = vec3f::toString((vec3f *)((char *)&result.t + 4), &v67);
  LOBYTE(v73) = 2;
  v46 = timeToString(&v64, (int)v57, 3);
  LOBYTE(v73) = 3;
  v47 = std::operator+<wchar_t>(&v66, L"SCP|", v46);
  LOBYTE(v73) = 4;
  v48 = std::operator+<wchar_t>(&v68, v47, L"|");
  LOBYTE(v73) = 5;
  v49 = std::operator+<wchar_t>(&v70, v48, v45);
  LOBYTE(v73) = 6;
  v50 = std::operator+<wchar_t>(&v71, v49, L"|");
  LOBYTE(v73) = 7;
  v51 = std::operator+<wchar_t>(&v65, v50, v44);
  LOBYTE(v73) = 8;
  ACClient::logMessage(v56, v51);
  if ( v65._Myres >= 8 )
    operator delete(v65._Bx._Ptr);
  v65._Myres = 7;
  v65._Mysize = 0;
  v65._Bx._Buf[0] = 0;
  if ( v71._Myres >= 8 )
    operator delete(v71._Bx._Ptr);
  v71._Myres = 7;
  v71._Mysize = 0;
  v71._Bx._Buf[0] = 0;
  if ( v70._Myres >= 8 )
    operator delete(v70._Bx._Ptr);
  v70._Myres = 7;
  v70._Mysize = 0;
  v70._Bx._Buf[0] = 0;
  if ( v68._Myres >= 8 )
    operator delete(v68._Bx._Ptr);
  v68._Myres = 7;
  v68._Mysize = 0;
  v68._Bx._Buf[0] = 0;
  if ( v66._Myres >= 8 )
    operator delete(v66._Bx._Ptr);
  v66._Myres = 7;
  v66._Mysize = 0;
  v66._Bx._Buf[0] = 0;
  if ( v64._Myres >= 8 )
    operator delete(v64._Bx._Ptr);
  v64._Myres = 7;
  v64._Mysize = 0;
  v64._Bx._Buf[0] = 0;
  if ( v67._Myres >= 8 )
    operator delete(v67._Bx._Ptr);
  v67._Myres = 7;
  v67._Mysize = 0;
  v67._Bx._Buf[0] = 0;
  if ( v69._Myres >= 8 )
    operator delete(v69._Bx._Ptr);
  v69._Myres = 7;
  v69._Mysize = 0;
  v69._Bx._Buf[0] = 0;
  v73 = -1;
  UDPPacket::~UDPPacket(&v72);
}
void ACClient::sendChat(ACClient *this, const std::wstring *message)
{
  unsigned __int8 v3; // cl
  Game *v4; // eax
  std::wstring v5; // [esp-18h] [ebp-54h] BYREF
  UDPPacket pak; // [esp+10h] [ebp-2Ch] BYREF
  int v7; // [esp+38h] [ebp-4h]

  if ( this->game->gameTime.now - this->lastChatMessage > 1000.0 )
  {
    v5._Myres = 7;
    v5._Mysize = 0;
    v5._Bx._Buf[0] = 0;
    std::wstring::assign(&v5, message, 0, 0xFFFFFFFF);
    if ( !ACClient::handleLocalAdminMessages(this, v5) )
    {
      UDPPacket::UDPPacket(&pak);
      v5._Myres = (unsigned int)message;
      v7 = 0;
      pak.data[pak.size] = 71;
      v3 = this->sessionID;
      pak.data[++pak.size] = v3;
      ++pak.size;
      UDPPacket::writeString(&pak, (const std::wstring *)v5._Myres);
      UDPPacket::send(&pak, &this->tcpSock);
      v4 = this->game;
      v7 = -1;
      this->lastChatMessage = v4->gameTime.now;
      UDPPacket::~UDPPacket(&pak);
    }
  }
}
void ACClient::sendVote(ACClient *this, VoteType aVote, bool aVoteValue, int targetAvatarGUID)
{
  unsigned __int8 v5; // al
  IPAddress v6; // xmm0
  UDPPacket pak; // [esp+8h] [ebp-2Ch] BYREF
  int v8; // [esp+30h] [ebp-4h]

  UDPPacket::UDPPacket(&pak);
  v8 = 0;
  if ( aVote == eVoteNextSession )
  {
    pak.data[pak.size] = 100;
    goto LABEL_8;
  }
  if ( aVote == eVoteRestartSession )
  {
    pak.data[pak.size] = 101;
    goto LABEL_8;
  }
  if ( aVote != eVoteKickUser )
  {
LABEL_9:
    this->votingManager->currentVote.hasVoted = 1;
    goto LABEL_10;
  }
  if ( (unsigned __int8)targetAvatarGUID != -1 )
  {
    pak.data[pak.size++] = 102;
    v5 = ACClient::getSessionIdFromCarAvatarID(this, targetAvatarGUID);
    pak.data[pak.size] = v5;
LABEL_8:
    pak.data[++pak.size] = aVoteValue;
    v6 = (IPAddress)_mm_loadu_si128((const __m128i *)&this->serverIP);
    ++pak.size;
    pak.targetIP = v6;
    UDPPacket::send(&pak, &this->tcpSock);
    goto LABEL_9;
  }
LABEL_10:
  v8 = -1;
  UDPPacket::~UDPPacket(&pak);
}
void ACClient::shutdown(ACClient *this)
{
  IPAddress v2; // xmm0
  UDPPacket pak; // [esp+8h] [ebp-2Ch] BYREF
  int v4; // [esp+30h] [ebp-4h]

  UDPPacket::UDPPacket(&pak);
  v2 = (IPAddress)_mm_loadu_si128((const __m128i *)&this->serverIP);
  v4 = 0;
  pak.targetIP = v2;
  pak.data[pak.size++] = 67;
  UDPPacket::send(&pak, &this->tcpSock);
  v4 = -1;
  UDPPacket::~UDPPacket(&pak);
}
void ACClient::storeSplitToLap(ACClient *this, std::vector<unsigned int> *splits, std::vector<unsigned int> *personalSplits, std::vector<Lap> *laps, const unsigned int *laptime, const unsigned int *cuts)
{
  std::vector<ICollisionObject *> *v6; // esi
  unsigned int v8; // edx
  ICollisionObject *v9; // eax
  unsigned int *v10; // edi
  unsigned int v11; // edx
  unsigned int v12; // ecx
  unsigned int *v13; // eax
  unsigned int v14; // edx

  v6 = (std::vector<ICollisionObject *> *)splits;
  if ( this->bestSplits._Myfirst != this->bestSplits._Mylast )
  {
    splits = 0;
    std::vector<SpinnerData *>::push_back(v6, (ICollisionObject *const *)&splits);
    v8 = 0;
    if ( this->bestSplits._Mylast - this->bestSplits._Myfirst != 1 )
    {
      do
      {
        v9 = v6->_Myfirst[v8++];
        *((_DWORD *)v6->_Mylast - 1) += v9;
      }
      while ( v8 < this->bestSplits._Mylast - this->bestSplits._Myfirst - 1 );
    }
    *((_DWORD *)v6->_Mylast - 1) = *laptime - *((_DWORD *)v6->_Mylast - 1);
    if ( !*cuts )
    {
      v10 = this->bestSplits._Mylast;
      v11 = *(v10 - 1);
      if ( v11 && (v12 = *((_DWORD *)v6->_Mylast - 1), v11 <= v12) )
      {
        v13 = personalSplits->_Mylast;
        v14 = *(v13 - 1);
        if ( !v14 || v14 > v12 )
          *(v13 - 1) = v12;
      }
      else
      {
        *(v10 - 1) = *((_DWORD *)v6->_Mylast - 1);
        *(personalSplits->_Mylast - 1) = *((_DWORD *)v6->_Mylast - 1);
      }
    }
    std::vector<int>::operator=(&laps->_Mylast[-1].splits, (const std::vector<unsigned int> *)v6);
  }
  std::_Container_base0::_Orphan_all(v6);
  v6->_Mylast = v6->_Myfirst;
}
void ACClient::update(ACClient *this, float deltaT)
{
  ACClient *v2; // ebp
  Sim *v3; // ecx
  StartingLights *v4; // eax
  Game *v5; // eax
  std::vector<std::vector<unsigned char>> *v6; // ebx
  int v7; // edi
  const std::vector<unsigned char> *v8; // esi
  unsigned __int8 *v9; // eax
  int v10; // ebp
  int v11; // edx
  unsigned int v12; // ebx
  const std::vector<unsigned char> *v13; // eax
  double v14; // xmm1_8
  double v15; // xmm0_8
  unsigned __int8 v16; // cl
  IPAddress v17; // xmm0
  Game *v18; // eax
  Sim *v19; // edi
  GameObject **v20; // esi
  int v21; // eax
  Event<SessionInfo> *v22; // ecx
  Sim *v23; // ecx
  float v24; // xmm0_4
  Sim *v25; // ecx
  Sim *v26; // ecx
  ACCameraManager *v27; // ecx
  double *v28; // ecx
  float v29; // xmm0_4
  std::function<void __cdecl(bool const &)> v30; // [esp-1Ch] [ebp-90h] BYREF
  ACClient *v31; // [esp-4h] [ebp-78h]
  std::vector<std::vector<unsigned char>> *v32; // [esp+1Ch] [ebp-58h]
  char v33; // [esp+23h] [ebp-51h] BYREF
  ACClient *v34; // [esp+24h] [ebp-50h]
  int v35; // [esp+28h] [ebp-4Ch]
  UDPPacket pak; // [esp+30h] [ebp-44h] BYREF
  std::vector<unsigned char> checksum; // [esp+4Ch] [ebp-28h] BYREF
  ACClient *v38; // [esp+58h] [ebp-1Ch]
  int v39; // [esp+5Ch] [ebp-18h]
  unsigned int v40; // [esp+60h] [ebp-14h]
  int v41; // [esp+70h] [ebp-4h]

  v2 = this;
  v34 = this;
  if ( this->game->gameTime.now > this->game->gameTime.startTime - 2000.0 && !this->debugStartingLights )
  {
    v3 = this->sim;
    v2->debugStartingLights = 1;
    v4 = GameObject::getGameObject<StartingLights>(v3);
    if ( v4 )
      _printf("STARTING LIGHTS ACTIVE %i\n", v4->isActive);
  }
  v5 = v2->game;
  v6 = &v2->checksumResults;
  v32 = &v2->checksumResults;
  v5->graphics->lightingSettings.gameTime = v5->gameTime.now - v5->gameTime.startTime;
  if ( v2->checksumResults._Myfirst != v2->checksumResults._Mylast )
  {
    std::vector<unsigned char>::operator=(
      &v6->_Myfirst[v2->checksumResults._Mylast - v2->checksumResults._Myfirst - 1],
      &v2->playerCarMD5);
    UDPPacket::UDPPacket(&pak);
    v41 = 0;
    pak.data[pak.size] = 68;
    v7 = (int)v2->checksumResults._Mylast;
    ++pak.size;
    v8 = v6->_Myfirst;
    v35 = v7;
    if ( v8 != (const std::vector<unsigned char> *)v7 )
    {
      do
      {
        std::vector<unsigned char>::vector<unsigned char>(&checksum, v8);
        v9 = checksum._Myfirst;
        v10 = 0;
        v11 = checksum._Mylast - checksum._Myfirst;
        if ( checksum._Myfirst > checksum._Mylast )
          v11 = 0;
        if ( v11 )
        {
          v12 = pak.size;
          do
          {
            ++v9;
            ++v10;
            pak.data[v12] = *(v9 - 1);
            v12 = ++pak.size;
          }
          while ( v10 != v11 );
          v9 = checksum._Myfirst;
          v7 = v35;
        }
        if ( v9 )
        {
          std::_Container_base0::_Orphan_all(&checksum);
          operator delete(checksum._Myfirst);
          checksum._Myfirst = 0;
          checksum._Mylast = 0;
          checksum._Myend = 0;
        }
        ++v8;
      }
      while ( v8 != (const std::vector<unsigned char> *)v7 );
      v2 = v34;
      v6 = v32;
    }
    pak.targetIP = (IPAddress)_mm_loadu_si128((const __m128i *)&v2->serverIP);
    UDPPacket::send(&pak, &v2->tcpSock);
    v2->lastSpectatorPulse = v2->game->gameTime.now;
    std::_Container_base0::_Orphan_all(v6);
    v31 = (ACClient *)v32;
    (&v30._Impl)[1] = (std::_Func_base<void,bool const &> *)&v33;
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::vector<ReplayFrameWingStatus>>>>(v6->_Myfirst, v6->_Mylast);
    v13 = v6->_Myfirst;
    v30._Space._Pfn[2] = (void (__cdecl *)())"CHECKSUM SENT\n";
    v6->_Mylast = (std::vector<unsigned char> *)v13;
    _printf((const char *const)v30._Space._Pfn[2]);
    v41 = -1;
    UDPPacket::~UDPPacket(&pak);
  }
  v14 = v2->lastSessionCheckTime;
  v15 = v2->game->gameTime.now;
  if ( v14 <= 0.0 )
  {
    v2->lastSessionCheckTime = v15 + 5000.0;
  }
  else if ( v15 - v14 > 2000.0 )
  {
    UDPPacket::UDPPacket(&pak);
    v41 = 1;
    pak.data[pak.size] = 79;
    v16 = v2->currentSession.type;
    pak.data[++pak.size] = v16;
    v17 = (IPAddress)_mm_loadu_si128((const __m128i *)&v2->serverIP);
    ++pak.size;
    pak.targetIP = v17;
    UDPPacket::send(&pak, &v2->sok);
    v18 = v2->game;
    v41 = -1;
    v2->lastSessionCheckTime = v18->gameTime.now;
    UDPPacket::~UDPPacket(&pak);
  }
  if ( !v2->wrongWayIndicator )
  {
    v19 = v2->sim;
    v20 = v19->gameObjects._Myfirst;
    if ( v20 == v19->gameObjects._Mylast )
    {
LABEL_26:
      v21 = 0;
    }
    else
    {
      while ( 1 )
      {
        v21 = __RTDynamicCast(*v20, 0, &GameObject `RTTI Type Descriptor', &WrongWayIndicator `RTTI Type Descriptor', 0);
        if ( v21 )
          break;
        if ( ++v20 == v19->gameObjects._Mylast )
          goto LABEL_26;
      }
    }
    v31 = v2;
    v2->wrongWayIndicator = (WrongWayIndicator *)v21;
    v30._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_8ad06d8ae8716f36c50308fe2df7e47e_,0>,std::allocator<std::_Func_class<void,float const &>>,void,float const &>::`vftable';
    v30._Space._Pfn[1] = (void (__cdecl *)())v2;
    v30._Impl = (std::_Func_base<void,bool const &> *)&v30;
    v22 = (Event<SessionInfo> *)&v2->wrongWayIndicator->evOnDrivingWrongWay;
    v41 = -1;
    Event<float>::addHandler(v22, (std::function<void __cdecl(SessionInfo const &)>)v30, v31);
  }
  if ( v2->game->gameTime.now - v2->sok.lastPingTime > 20000.0 )
  {
    pak.currentDataPos = 7;
    pak.data = 0;
    pak.targetIP.sokaddr.sin_family = 0;
    std::wstring::assign((std::wstring *)&pak, L"The server seems to be unavailable.", 0x23u);
    v41 = 3;
    v40 = 7;
    v39 = 0;
    LOWORD(checksum._Myfirst) = 0;
    std::wstring::assign((std::wstring *)&checksum, L"Connection Issue", 0x10u);
    v23 = v2->sim;
    LOBYTE(v41) = 4;
    SystemMessage::addMessage(v23->systemMessage, (const std::wstring *)&checksum, (const std::wstring *)&pak, eDefault);
    if ( v40 >= 8 )
      operator delete(checksum._Myfirst);
    v40 = 7;
    v39 = 0;
    LOWORD(checksum._Myfirst) = 0;
    v41 = -1;
    if ( pak.currentDataPos >= 8 )
      operator delete(*(_DWORD *)&pak.targetIP.sokaddr.sin_family);
  }
  if ( v2->raceClosingTime > 0.0 && v2->isResultScreenOn )
  {
    if ( !v2->ignoreResultTeleport )
    {
      CarAvatar::setGentleStop(v2->avatar, 1);
      v24 = v2->endSession.sendToPitsTimer - deltaT;
      v2->endSession.sendToPitsTimer = v24;
      if ( v24 < 0.0 )
      {
        v31 = v2;
        v30._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_f5d5c0c4b8c5864531c2766d7b9b317a_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
        v30._Space._Pfn[1] = (void (__cdecl *)())v2;
        v30._Impl = (std::_Func_base<void,bool const &> *)&v30;
        v25 = v2->sim;
        v41 = -1;
        ACCameraManager::registerToFadeInEvent(v25->cameraManager, v30, v2);
        v26 = v2->sim;
        checksum._Myfirst = 0;
        v38 = v2;
        checksum._Myend = (unsigned __int8 *)1082130432;
        v27 = v26->cameraManager;
        checksum._Mylast = 0;
        ACCameraManager::fadeIn(v27, (FadeModeDef)_mm_loadu_si128((const __m128i *)&checksum));
        v2->endSession.sendToPitsTimer = 3.4028235e38;
      }
    }
    if ( v2->isResultScreenOn && v2->endSession.isConnectionFinished )
    {
      v28 = (double *)v2->sim->game;
      if ( v28[3] > v2->raceClosingTime )
        (*(void (**)(double *))(*(_DWORD *)v28 + 4))(v28);
    }
  }
  if ( v2->dcCountdown.isSignaled )
  {
    v29 = v2->dcCountdown.timeToDisconnection - deltaT;
    v2->dcCountdown.timeToDisconnection = v29;
    if ( v29 < 0.0 )
      v2->game->shutdown(v2->game);
  }
  ACClient::updateDamageReport(v2);
}
void ACClient::updateDamageReport(ACClient *this)
{
  CarAvatar *v2; // ebx
  float *v3; // esi
  int v4; // ecx
  float *v5; // edx
  float *i; // edi
  int v7; // edi
  unsigned int v8; // edx
  int v9; // ebx
  int v10; // xmm0_4
  UDPPacket pak; // [esp+18h] [ebp-2Ch] BYREF
  int v12; // [esp+40h] [ebp-4h]

  if ( this->game->gameTime.now - this->damageReport.lastSendTime > 2000.0 )
  {
    v2 = this->avatar;
    v3 = this->damageReport.damageZoneLevel;
    v4 = 0;
    v5 = this->damageReport.damageZoneLevel;
    for ( i = v2->physicsState.damageZoneLevel; *i == *v5; ++i )
    {
      ++v4;
      ++v5;
      if ( v4 >= 5 )
        return;
    }
    *(__m128i *)v3 = _mm_loadu_si128((const __m128i *)v2->physicsState.damageZoneLevel);
    this->damageReport.damageZoneLevel[4] = v2->physicsState.damageZoneLevel[4];
    this->damageReport.lastSendTime = this->game->gameTime.now;
    UDPPacket::UDPPacket(&pak);
    v7 = 0;
    v12 = 0;
    pak.data[pak.size] = 86;
    v8 = ++pak.size;
    v9 = 5;
    if ( this->damageReport.damageZoneLevel > &this->damageReport.damageZoneLevel[5] )
      v9 = 0;
    if ( v9 )
    {
      do
      {
        v10 = *(_DWORD *)v3++;
        ++v7;
        *(_DWORD *)&pak.data[v8] = v10;
        v8 = pak.size + 4;
        pak.size += 4;
      }
      while ( v7 != v9 );
    }
    _printf("Sending ACP_DAMAGE_UPDATE\n");
    UDPPacket::send(&pak, &this->tcpSock);
    v12 = -1;
    UDPPacket::~UDPPacket(&pak);
  }
}
void ACClient::updateQOS(ACClient *this, long double pt)
{
  long double v2; // xmm2_8
  float v4; // xmm0_4
  int *v5; // eax
  NetCarStateProvider **v6; // eax
  NetCarStateProvider **v7; // ecx
  int v8; // ebx
  unsigned int v9; // esi
  int v10; // ebp
  int v11; // edi
  int v12; // eax
  int v13; // [esp+0h] [ebp-4h] BYREF

  v13 = (int)this;
  v2 = pt;
  if ( pt - this->qos.startTime >= 3000.0 )
  {
    if ( this->qos.usingMegapackets )
    {
      v4 = (float)this->qos.counter;
      v5 = (int *)&pt;
      v13 = 100;
      this->qos.counter = 0;
      this->qos.startTime = v2;
      LODWORD(pt) = (int)(float)((float)(v4 * 0.016666668) * 100.0);
      if ( SLODWORD(pt) <= 100 )
        v5 = &v13;
      this->qos.lastQOS = *v5;
    }
    else
    {
      v6 = this->netCars._Mylast;
      v7 = this->netCars._Myfirst;
      v8 = 0;
      v9 = (unsigned int)((char *)this->netCars._Mylast - (char *)v7 + 3) >> 2;
      v10 = 0;
      v11 = 0;
      if ( v7 > v6 )
        v9 = 0;
      if ( v9 )
      {
        do
        {
          v12 = (int)*v7++;
          ++v8;
          v11 += *(_DWORD *)(v12 + 288);
          v10 += *(_DWORD *)(v12 + 292);
          *(_DWORD *)(v12 + 288) = 0;
          *(_DWORD *)(v12 + 292) = 0;
        }
        while ( v8 != v9 );
        if ( v11 )
          this->qos.lastQOS = (int)(float)((float)(1.0 - (float)((float)v10 / (float)v11)) * 100.0);
      }
      this->qos.startTime = v2;
    }
  }
}
