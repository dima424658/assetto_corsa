#include "sim.h"
int Sim::getCarsCount(Sim *this)
{
  return this->cars._Mylast - this->cars._Myfirst;
}
void Sim::displayLeaderboard(Sim *this, BOOL value)
{
  SessionLeaderboard *v3; // ecx

  v3 = this->leaderboard;
  if ( v3 )
  {
    SessionLeaderboard::setVisible(v3, value);
    this->leaderboard->isActive = value;
  }
}
bool Sim::isDisplayingResults(Sim *this)
{
  EndSessionDisplayer *v1; // eax
  bool result; // al

  v1 = this->endSessionDisplayer;
  if ( v1 )
    result = v1->isActive;
  else
    result = 0;
  return result;
}
bool Sim::isVrRoom(Sim *this)
{
  return this->isRoomVR;
}
void __userpurge Sim::Sim(Sim *this@<ecx>, unsigned int a2@<ebx>, __m128 a3@<xmm3>, __m128 a4@<xmm4>, Game *igame)
{
  std::map<std::wstring,Texture> *v6; // ebx
  std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *v7; // eax
  double v8; // st7
  bool v9; // cf
  double v10; // st7
  StereoCameraForward *v11; // eax
  __m128 v12; // xmm0
  Console *v13; // eax
  Console *v14; // eax
  Console *v15; // esi
  ACErrorHandler *v16; // eax
  ACErrorHandler *v17; // eax
  SharedFileOut *v18; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > > v19; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > > v20; // esi
  PhysicsAvatar *v21; // eax
  PhysicsAvatar *v22; // eax
  PhysicsAvatar *v23; // esi
  SharedMemoryWriter *v24; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > > v25; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > > v26; // esi
  ksgui::GameScreen *v27; // esi
  ksgui::GameScreen *v28; // eax
  Game *v29; // ecx
  ksgui::FormRenderStats *v30; // eax
  ksgui::FormRenderStats *v31; // eax
  SkyBox *v32; // eax
  SkyBox *v33; // eax
  SkyBox *v34; // ecx
  CameraForward *v35; // eax
  WarningReporter *v36; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > > v37; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > > v38; // esi
  unsigned int v39; // eax
  MirrorTextureRenderer *v40; // eax
  MirrorTextureRenderer *v41; // eax
  ScreenCapturer *v42; // esi
  ScreenCapturer *v43; // eax
  ScreenCapturer *v44; // esi
  SystemMessage *v45; // eax
  SystemMessage *v46; // eax
  SystemMessage *v47; // esi
  SystemNotification *v48; // eax
  SystemNotification *v49; // eax
  SystemNotification *v50; // esi
  WeatherManager *v51; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > > v52; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > > v53; // esi
  MicroSectors *v54; // eax
  MicroSectors *v55; // eax
  MicroSectors *v56; // esi
  RaceManager *v57; // eax
  RaceManager *v58; // eax
  RaceManager *v59; // esi
  CarAvatar *v60; // ebx
  std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *v61; // eax
  Game *v62; // eax
  Texture *v63; // esi
  Texture *v64; // eax
  void *v65; // ecx
  const std::wstring *v66; // esi
  CarAvatar **v67; // esi
  std::vector<CarAvatar *> *v68; // ecx
  CarAvatar **v69; // edi
  std::wstring *v70; // eax
  const std::wstring *v71; // eax
  Game *v72; // ecx
  Texture *v73; // eax
  CarAvatar_vtbl *v74; // ecx
  CarAvatar **v75; // eax
  CarAvatar **v76; // ecx
  Car *v77; // edx
  PushToPassManager *v78; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > > v79; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > > v80; // esi
  std::vector<GameObject *> *v81; // edi
  ReplayManager *v82; // eax
  ReplayManager *v83; // eax
  ReplayManager *v84; // esi
  CameraForward *v85; // eax
  ACHideAll *v86; // eax
  ksgui::Control *v87; // eax
  ksgui::Control *v88; // edx
  ksgui::GameScreen *v89; // ecx
  PauseMenu *v90; // eax
  PauseMenu *v91; // eax
  int v92; // eax
  unsigned int v93; // eax
  int v94; // eax
  std::vector<CarAvatar *> *v95; // edi
  CarAvatar *v96; // ecx
  CarAvatar *v97; // ecx
  ICarControlsProvider *v98; // eax
  int v99; // eax
  ACEssentials *v100; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > > v101; // eax
  ksgui::Control *v102; // esi
  FormChat *v103; // eax
  ksgui::Control *v104; // eax
  ksgui::Control *v105; // esi
  TyresApp *v106; // eax
  ksgui::Form *v107; // eax
  char v108; // di
  LeaderboardApp *v109; // eax
  ksgui::Form *v110; // eax
  PlayerCurrentTime *v111; // eax
  ksgui::Form *v112; // eax
  CameraForwardYebis *v113; // ebx
  FormHDR *v114; // eax
  ksgui::Form *v115; // eax
  FormVolumes *v116; // eax
  ksgui::Form *v117; // eax
  RaceFuelMonitor *v118; // eax
  ksgui::Form *v119; // eax
  PhotoMode *v120; // eax
  ksgui::Form *v121; // eax
  FormDRSZones *v122; // esi
  CarAvatar **v123; // eax
  ksgui::Form *v124; // eax
  SetupDebug *v125; // eax
  ksgui::Form *v126; // eax
  TyreWearingDebug *v127; // eax
  ksgui::Form *v128; // eax
  FormTelemetry *v129; // esi
  CarAvatar **v130; // eax
  ksgui::Form *v131; // eax
  ACHelp *v132; // eax
  ksgui::Form *v133; // eax
  ACTimeFlow *v134; // eax
  ksgui::Form *v135; // eax
  FormOpenVR *v136; // eax
  ksgui::Form *v137; // eax
  PostProcessFilterSelector *v138; // eax
  ksgui::Form *v139; // eax
  DriverEyesPositioner *v140; // esi
  CarAvatar **v141; // eax
  ksgui::Form *v142; // eax
  FFBForm *v143; // esi
  CarAvatar **v144; // eax
  ksgui::Form *v145; // eax
  CarPedalsForm *v146; // esi
  CarAvatar **v147; // eax
  ksgui::Form *v148; // eax
  NetMonitorForm *v149; // eax
  ksgui::Form *v150; // eax
  FormRealTimeTiming *v151; // eax
  ksgui::Form *v152; // eax
  PerformanceMeterApp *v153; // esi
  CarAvatar **v154; // eax
  ksgui::Form *v155; // eax
  FormGear *v156; // esi
  CarAvatar **v157; // eax
  ksgui::Form *v158; // eax
  TrackMap *v159; // eax
  ksgui::Form *v160; // eax
  ElectronicAidsForm *v161; // esi
  CarAvatar **v162; // eax
  ksgui::Form *v163; // eax
  FormMGU *v164; // esi
  CarAvatar **v165; // eax
  ksgui::Form *v166; // eax
  FormBallast *v167; // esi
  CarAvatar **v168; // eax
  ksgui::Form *v169; // eax
  TripleScreenManager *v170; // eax
  ksgui::Form *v171; // eax
  FormAI *v172; // eax
  ksgui::Form *v173; // eax
  CarPhysicsForm *v174; // esi
  CarAvatar **v175; // eax
  ksgui::Form *v176; // eax
  TelemetryApp *v177; // esi
  CarAvatar **v178; // eax
  ksgui::Form *v179; // eax
  FormGameStats *v180; // eax
  ksgui::Form *v181; // eax
  RacePosition *v182; // eax
  ksgui::Form *v183; // eax
  KeyboardControlsDebug *v184; // esi
  CarAvatar **v185; // eax
  ksgui::Form *v186; // eax
  FormDriverModel *v187; // esi
  CarAvatar **v188; // eax
  ksgui::Form *v189; // eax
  TyreTesterForm *v190; // esi
  CarAvatar **v191; // eax
  ksgui::Form *v192; // eax
  FormLogoAC *v193; // eax
  ksgui::Form *v194; // eax
  FormWings *v195; // esi
  CarAvatar **v196; // eax
  ksgui::Form *v197; // eax
  ACSuspension *v198; // esi
  CarAvatar **v199; // eax
  ksgui::Form *v200; // eax
  ACDriverPerformance *v201; // esi
  CarAvatar **v202; // eax
  ksgui::Form *v203; // eax
  ACDCarEngineer *v204; // eax
  ksgui::Form *v205; // eax
  GPUProfilerApp *v206; // eax
  ksgui::Form *v207; // eax
  FormCamera *v208; // eax
  ksgui::Form *v209; // eax
  TrackDescription *v210; // eax
  ksgui::Form *v211; // eax
  X360ControllerDebug *v212; // eax
  ksgui::Form *v213; // eax
  TimeLimitedTest *v214; // eax
  PitCrew *v215; // eax
  TimeLimitedTest *v216; // eax
  FormRunningTime *v217; // eax
  ksgui::Form *v218; // eax
  int v219; // ebx
  float v220; // ebx
  char v221; // bl
  int v222; // eax
  PythonInterface *v223; // eax
  PitCrew *v224; // eax
  char *v225; // ebx
  std::unique_ptr<RaceEngineer> **v226; // eax
  ComparativeTelemetryRecorder *v227; // esi
  CarAvatar **v228; // eax
  PitCrew *v229; // eax
  ESCMenu *v230; // eax
  ESCMenu *v231; // eax
  bool v232; // zf
  Sim::{ctor}::__l100::<lambda_a8934cdcb6f363d258fa7e835d4ed7a1> *v233; // eax
  DriftMode *v234; // esi
  CarAvatar **v235; // eax
  PitCrew *v236; // eax
  TimeAttack *v237; // esi
  CarAvatar **v238; // eax
  PitCrew *v239; // eax
  DragMode *v240; // eax
  PitCrew *v241; // eax
  HotlapMode *v242; // eax
  PitCrew *v243; // eax
  RaceEvent *v244; // eax
  PitCrew *v245; // eax
  Sim::{ctor}::__l106::<lambda_fbd0a65f3eb1aa7aebf79671d2661532> *v246; // eax
  PluginManager *v247; // eax
  PitCrew *v248; // eax
  SimScreen *v249; // eax
  PitCrew *v250; // eax
  RemoteTelemetryUDP *v251; // esi
  CarAvatar **v252; // eax
  PitCrew *v253; // eax
  MouseHider *v254; // eax
  PitCrew *v255; // eax
  WrongWayIndicator *v256; // esi
  CarAvatar **v257; // eax
  PitCrew *v258; // eax
  ACOperatingSystem *v259; // eax
  ACOperatingSystem *v260; // eax
  ACCameraManager *v261; // eax
  PitCrew *v262; // eax
  ACCameraManager *v263; // eax
  ChaseCamEditor *v264; // eax
  ksgui::Form *v265; // eax
  StartingLights *v266; // eax
  PitCrew *v267; // eax
  StartingTrackSemaphore *v268; // eax
  PitCrew *v269; // eax
  UDPCommandListener *v270; // eax
  PitCrew *v271; // eax
  JsonOutputFile *v272; // eax
  PitCrew *v273; // eax
  LapInvalidatorAvatar *v274; // eax
  PitCrew *v275; // eax
  DriveThroughPenaltyAvatar *v276; // eax
  PitCrew *v277; // eax
  LockControlsTimeAvatar *v278; // eax
  PitCrew *v279; // eax
  ProximityIndicator *v280; // eax
  PitCrew *v281; // eax
  PitStop *v282; // eax
  PitCrew *v283; // eax
  PitStop *v284; // eax
  DriverNameDisplayer *v285; // eax
  PitCrew *v286; // eax
  DriverNameDisplayer *v287; // eax
  DamageDisplayer *v288; // eax
  PitCrew *v289; // eax
  FanatecUpdater *v290; // esi
  CarAvatar **v291; // eax
  PitCrew *v292; // eax
  PitCrew *v293; // esi
  DebugVisualizer *v294; // eax
  PitCrew *v295; // eax
  DebugVisualizer *v296; // eax
  DrivingAssistManager *v297; // eax
  PitCrew *v298; // eax
  CameraForward *v299; // eax
  int v300; // ecx
  DigitalItem **v301; // eax
  std::wstring *v302; // eax
  const std::wstring *v303; // eax
  const vec3f *v304; // eax
  const vec3f *v305; // eax
  Sim::{ctor}::__l135::<lambda_af39a7517139f6a5869e118678b0f708> *v306; // eax
  Sim::{ctor}::__l136::<lambda_e49627c2b163b572ea864b95e6e5ab27> *v307; // eax
  Sim::{ctor}::__l137::<lambda_25d14ad2eade83d5779db6381d690ff1> *v308; // eax
  Sim::{ctor}::__l138::<lambda_6547d3c58cfc0f47944b490e8ced7c94> *v309; // eax
  int v310; // esi
  Sim::{ctor}::__l148::<lambda_47b3546a3185b0ddbb338bc74e0bb1a1> *v311; // eax
  std::wstring *v312; // eax
  Sim::{ctor}::__l156::<lambda_16aa69a2b949a21e27f913bb05684dfe> *v313; // eax
  EndSessionDisplayer *v314; // eax
  PitCrew *v315; // eax
  OverlayLeaderboard *v316; // eax
  PitCrew *v317; // eax
  SteamInterface *v318; // eax
  PitCrew *v319; // eax
  FriendsLeaderboardDisplayer *v320; // eax
  ksgui::Form *v321; // eax
  Sim::{ctor}::__l163::<lambda_0126d507b0e75f5f24e1413b5e200ee5> *v322; // eax
  unsigned int j; // esi
  const std::wstring *v324; // eax
  Console *v325; // eax
  Console *v326; // eax
  std::wstring *v327; // eax
  const std::wstring *v328; // eax
  GraphicsManager *v329; // esi
  double v330; // st7
  float v331; // xmm0_4
  int v332; // esi
  SessionLeaderboard *v333; // eax
  PitCrew *v334; // eax
  SessionLeaderboard *v335; // eax
  VirtualMirrorRenderer *v336; // eax
  PitCrew *v337; // eax
  VirtualMirrorRenderer *v338; // eax
  std::wstring *v339; // eax
  const std::wstring *v340; // eax
  bool v341; // bl
  FlagManager *v342; // eax
  PitCrew *v343; // eax
  FuelLight *v344; // eax
  PitCrew *v345; // eax
  std::wstring *v346; // eax
  const std::wstring *v347; // eax
  BenchmarkMode *v348; // eax
  PitCrew *v349; // eax
  DigitalItem **v350; // esi
  DigitalItem **v351; // eax
  Game *v352; // ebx
  DigitalItem **v353; // edx
  DigitalItem *v354; // eax
  GraphicsManager *v355; // edi
  __int64 v356; // xmm0_8
  float v357; // eax
  NodeEvent *v358; // esi
  NodeEvent *v359; // eax
  NodeEvent *v360; // edx
  Node *v361; // ecx
  Sim::{ctor}::__l204::<lambda_9365af50048c57821365e8ba72a394e3> *v362; // eax
  _BYTE useBlur[56]; // [esp-Ch] [ebp-3D8h] BYREF
  int i; // [esp+48h] [ebp-384h] BYREF
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > > result; // [esp+4Ch] [ebp-380h] BYREF
  float v366; // [esp+50h] [ebp-37Ch]
  float v367; // [esp+54h] [ebp-378h]
  std::vector<std::wstring> dxErrorStrings; // [esp+58h] [ebp-374h] BYREF
  Sim *v369; // [esp+64h] [ebp-368h]
  std::wstring nationCode; // [esp+68h] [ebp-364h] BYREF
  std::wstring section; // [esp+80h] [ebp-34Ch] BYREF
  std::wstring key; // [esp+98h] [ebp-334h] BYREF
  std::wstring _Keyval; // [esp+B0h] [ebp-31Ch] BYREF
  std::wstring v374; // [esp+C8h] [ebp-304h] BYREF
  Texture v375; // [esp+E0h] [ebp-2ECh] BYREF
  std::wstring v376; // [esp+FCh] [ebp-2D0h] BYREF
  std::wstring ifilename; // [esp+114h] [ebp-2B8h] BYREF
  std::wstring iname; // [esp+12Ch] [ebp-2A0h] BYREF
  std::wstring s; // [esp+144h] [ebp-288h] BYREF
  std::wstring v380; // [esp+15Ch] [ebp-270h] BYREF
  INIReaderDocuments videoini; // [esp+174h] [ebp-258h] BYREF
  INIReaderDocuments gameplayINI; // [esp+1B8h] [ebp-214h] BYREF
  INIReader acIni; // [esp+1FCh] [ebp-1D0h] BYREF
  DebugTimer dtt; // [esp+240h] [ebp-18Ch] BYREF
  INIReader acPitstop; // [esp+268h] [ebp-164h] BYREF
  INIReader fadesINI; // [esp+2ACh] [ebp-120h] BYREF
  INIReader ini; // [esp+2F0h] [ebp-DCh] BYREF
  INIReader exp_ini; // [esp+334h] [ebp-98h] BYREF
  INIReader audioIni; // [esp+378h] [ebp-54h] BYREF
  int v390; // [esp+3C8h] [ebp-4h]

  *(_DWORD *)&useBlur[52] = igame;
  v367 = 0.0;
  v366 = 0.0;
  i = (int)igame;
  v369 = this;
  *(_DWORD *)&useBlur[48] = 7;
  *(_DWORD *)&useBlur[44] = 0;
  *(_WORD *)&useBlur[28] = 0;
  std::wstring::assign((std::wstring *)&useBlur[28], L"ACS_SIM", 7u);
  GameObject::GameObject(this, *(std::wstring *)&useBlur[28], *(Game **)&useBlur[52]);
  this->IKeyEventListener::__vftable = (IKeyEventListener_vtbl *)&IKeyEventListener::`vftable';
  this->GameObject::__vftable = (Sim_vtbl *)&Sim::`vftable'{for `GameObject'};
  this->IKeyEventListener::__vftable = (IKeyEventListener_vtbl *)&Sim::`vftable'{for `IKeyEventListener'};
  v390 = 0;
  this->evNewCarLoaded.handlers._Myfirst = 0;
  this->evNewCarLoaded.handlers._Mylast = 0;
  this->evNewCarLoaded.handlers._Myend = 0;
  this->evOnReplayStatusChanged.handlers._Myfirst = 0;
  this->evOnReplayStatusChanged.handlers._Mylast = 0;
  this->evOnReplayStatusChanged.handlers._Myend = 0;
  this->evOnPauseModeChanged.handlers._Myfirst = 0;
  this->evOnPauseModeChanged.handlers._Mylast = 0;
  this->evOnPauseModeChanged.handlers._Myend = 0;
  this->evOnCollisionEvent.handlers._Myfirst = 0;
  this->evOnCollisionEvent.handlers._Mylast = 0;
  this->evOnCollisionEvent.handlers._Myend = 0;
  this->evOnNewSession.handlers._Myfirst = 0;
  this->evOnNewSession.handlers._Mylast = 0;
  this->evOnNewSession.handlers._Myend = 0;
  LOBYTE(v390) = 5;
  this->hdrLevels.minExposure = 0.0;
  this->hdrLevels.maxExposure = 10000.0;
  CommandManager::CommandManager(&this->commandManager, a2);
  LOBYTE(v390) = 6;
  OptionsManager::OptionsManager(&this->optionsManager);
  this->gameScreen = 0;
  this->pauseMenu = 0;
  this->escMenu = 0;
  this->rootNode = 0;
  this->trackNode = 0;
  this->carsNode = 0;
  this->skidMarkNode = 0;
  this->particlesNode = 0;
  this->carFakeShadowsNode = 0;
  this->track = 0;
  this->blurredNode = 0;
  this->unblurredNode = 0;
  this->drivingAidsManager = 0;
  this->renderFinishedNodeEvent = 0;
  this->beforeCarsNode = 0;
  this->mirrorTextureRenderer = 0;
  this->cameraManager = 0;
  this->cameraDirtNode = 0;
  this->systemMessage = 0;
  this->systemNotification = 0;
  this->raceManager = 0;
  this->replayManager = 0;
  this->physicsAvatar = 0;
  this->screenCapturer = 0;
  this->client = 0;
  this->pitStop = 0;
  this->timeLimitedTest = 0;
  *(_DWORD *)&this->useProView = 0;
  this->useMousePitstop = 0;
  this->microSectors = 0;
  this->serializeForms = 0;
  this->connectedCarsCount = 0;
  *(_WORD *)&this->allowFreeCamera = 0;
  this->audioPerformanceSpew = 0;
  this->cars._Myfirst = 0;
  this->cars._Mylast = 0;
  this->cars._Myend = 0;
  LOBYTE(v390) = 8;
  this->focusedCarIndex = 0;
  this->cameraFadeTime = 0.0;
  this->console = 0;
  this->simScreen = 0;
  this->sceneCamera = 0;
  this->skyBox = 0;
  this->errorHandler = 0;
  this->debugVisualizer = 0;
  this->formRenderStats = 0;
  this->endSessionDisplayer = 0;
  this->leaderboard = 0;
  Trigger::Trigger(&this->changingCameraTrigger);
  *(_DWORD *)&useBlur[52] = 24;
  LOBYTE(v390) = 9;
  this->virtualMirrorRenderer = 0;
  Concurrency::details::_Concurrent_queue_base_v4::_Concurrent_queue_base_v4(
    &this->chFunctions.queue,
    *(unsigned int *)&useBlur[52]);
  this->chFunctions.queue.__vftable = (Concurrency::concurrent_queue<std::function<void __cdecl(void)>,std::allocator<std::function<void __cdecl(void)> > >_vtbl *)&Concurrency::concurrent_queue<std::function<void __cdecl (void)>,std::allocator<std::function<void __cdecl (void)>>>::`vftable';
  v6 = &this->flagMapCache;
  this->lastDT = 0.0;
  this->node3DGUI = 0;
  LOBYTE(v390) = 10;
  this->flagMapCache._Myhead = 0;
  this->flagMapCache._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<CarAvatar * const,Lap>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,TagDocumentText>> > *)&this->flagMapCache);
  this->flagMapCache._Myhead = v7;
  LOBYTE(v390) = 11;
  INIReader::clearCache();
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"Sim::Sim", 8u);
  LOBYTE(v390) = 12;
  DebugTimer::DebugTimer(&dtt, &iname);
  LOBYTE(v390) = 14;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  *(double *)section._Bx._Buf = ksGetSystemTime();
  _srand((unsigned int)*(double *)section._Bx._Buf);
  this->cameraManager = 0;
  this->tripleScreenMode = 0;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/fades.ini", 0x14u);
  LOBYTE(v390) = 15;
  INIReader::INIReader(&fadesINI, &ifilename);
  LOBYTE(v390) = 17;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( fadesINI.ready )
  {
    nationCode._Myres = 7;
    nationCode._Mysize = 0;
    nationCode._Bx._Buf[0] = 0;
    std::wstring::assign(&nationCode, L"MS", 2u);
    LOBYTE(v390) = 18;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CHANGE_CAMERA_FADE", 0x12u);
    LOBYTE(v390) = 19;
    v8 = INIReader::getFloat(&fadesINI, &section, &nationCode);
    v9 = section._Myres < 8;
    this->cameraFadeTime = v8 * 0.001;
    if ( !v9 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v390) = 17;
    if ( nationCode._Myres >= 8 )
      operator delete(nationCode._Bx._Ptr);
  }
  else
  {
    this->cameraFadeTime = 0.0;
  }
  *(_DWORD *)&useBlur[52] = 0;
  this->focusedCarIndex = 0;
  this->client = 0;
  *(_DWORD *)&useBlur[48] = 7;
  *(_DWORD *)&useBlur[44] = 0;
  *(_WORD *)&useBlur[28] = 0;
  std::wstring::assign((std::wstring *)&useBlur[28], L"cfg/video.ini", 0xDu);
  INIReaderDocuments::INIReaderDocuments(&videoini, (unsigned int)v6, *(std::wstring *)&useBlur[28], useBlur[52]);
  LOBYTE(v390) = 20;
  nationCode._Myres = 7;
  nationCode._Mysize = 0;
  nationCode._Bx._Buf[0] = 0;
  std::wstring::assign(&nationCode, L"MOTION_BLUR", 0xBu);
  LOBYTE(v390) = 21;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"EFFECTS", 7u);
  LOBYTE(v390) = 22;
  v10 = INIReader::getFloat(&videoini, &section, &nationCode);
  *(float *)&result._Ptr = v10;
  v367 = FLOAT_12_0;
  if ( *(float *)&result._Ptr <= 12.0 )
  {
    if ( *(float *)&result._Ptr >= 0.0 )
      v367 = *(float *)&result._Ptr;
    else
      v367 = 0.0;
  }
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v390) = 20;
  if ( nationCode._Myres >= 8 )
    operator delete(nationCode._Bx._Ptr);
  *(float *)&useBlur[52] = v367;
  *(_DWORD *)&useBlur[48] = &videoini;
  this->replayManager = 0;
  v11 = Sim::createCamera(this, *(INIReaderDocuments **)&useBlur[48], *(float *)&useBlur[52]);
  this->sceneCamera = v11;
  v11->clearColor = (vec4f)_xmm;
  this->sceneCamera->renderAudio = 1;
  if ( !this->isVrConnected )
    this->sceneCamera->blurQuality = v367 * 2.0;
  nationCode._Myres = 7;
  nationCode._Mysize = 0;
  nationCode._Bx._Buf[0] = 0;
  std::wstring::assign(&nationCode, L"WORLD_DETAIL", 0xCu);
  LOBYTE(v390) = 23;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"ASSETTOCORSA", 0xCu);
  LOBYTE(v390) = 24;
  v12 = (__m128)COERCE_UNSIGNED_INT((float)INIReader::getInt(&videoini, &section, &nationCode));
  LODWORD(this->sceneCamera->maxLayer) = v12.m128_i32[0];
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v390) = 20;
  if ( nationCode._Myres >= 8 )
    operator delete(nationCode._Bx._Ptr);
  nationCode._Myres = 7;
  nationCode._Mysize = 0;
  nationCode._Bx._Buf[0] = 0;
  std::wstring::assign(&nationCode, L"SATURATION", 0xAu);
  LOBYTE(v390) = 25;
  LOBYTE(v6) = INIReader::hasSection(&videoini, &nationCode);
  LOBYTE(v390) = 20;
  if ( nationCode._Myres >= 8 )
    operator delete(nationCode._Bx._Ptr);
  if ( (_BYTE)v6 )
  {
    std::wstring::wstring(&key, L"LEVEL");
    LOBYTE(v390) = 26;
    std::wstring::wstring(&nationCode, L"SATURATION");
    LOBYTE(v390) = 27;
    v10 = INIReader::getFloat(&videoini, &nationCode, &key) * 0.0099999998;
    this->game->graphics->lightingSettings.saturation = v10;
    if ( nationCode._Myres >= 8 )
      operator delete(nationCode._Bx._Ptr);
    nationCode._Myres = 7;
    nationCode._Mysize = 0;
    nationCode._Bx._Buf[0] = 0;
    LOBYTE(v390) = 20;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  *(float *)&v13 = COERCE_FLOAT(operator new(172));
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v13;
  LOBYTE(v390) = 28;
  if ( *(float *)&v13 == 0.0 )
  {
    *(float *)&v15 = 0.0;
  }
  else
  {
    Console::Console(v13, (unsigned int)v6, this);
    v15 = v14;
  }
  LOBYTE(v390) = 20;
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v15;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&result);
  v15->parent = this;
  *(_DWORD *)&useBlur[52] = 20;
  this->console = v15;
  *(float *)&v16 = COERCE_FLOAT(operator new(*(_DWORD *)&useBlur[52]));
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v16;
  LOBYTE(v390) = 29;
  if ( *(float *)&v16 == 0.0 )
    v17 = 0;
  else
    ACErrorHandler::ACErrorHandler(v16, this->console);
  *(_DWORD *)&useBlur[52] = 1065353216;
  *(_DWORD *)&useBlur[48] = 0;
  this->errorHandler = v17;
  INIReader::errorHandler = v17;
  *(float *)&result._Ptr = COERCE_FLOAT(&useBlur[24]);
  *(_DWORD *)&useBlur[24] = &std::_Func_impl<std::_Callable_obj<_lambda_b02171bdbb0a58cfca78de503084e9c0_,0>,std::allocator<std::_Func_class<void,SVar *,float>>,void,SVar *,float>::`vftable';
  *(_DWORD *)&useBlur[28] = this;
  *(_DWORD *)&useBlur[40] = &useBlur[24];
  LOBYTE(v390) = 31;
  std::wstring::wstring((std::wstring *)useBlur, L"axisMode");
  LOBYTE(v390) = 20;
  Console::addVarLambda(
    this->console,
    *(std::wstring *)useBlur,
    *(std::function<void __cdecl(SVar *,float)> *)&useBlur[24],
    useBlur[48],
    *(float *)&useBlur[52]);
  *(float *)&v18 = COERCE_FLOAT(operator new(92));
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v18;
  LOBYTE(v390) = 32;
  if ( *(float *)&v18 == 0.0 )
  {
    *(float *)&v20._Ptr = 0.0;
  }
  else
  {
    SharedFileOut::SharedFileOut(v18, this);
    v20._Ptr = v19._Ptr;
  }
  LOBYTE(v390) = 20;
  result._Ptr = v20._Ptr;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&result);
  *(_DWORD *)&useBlur[52] = 808;
  v20._Ptr->_Myval.first._Myres = (unsigned int)this;
  *(float *)&v21 = COERCE_FLOAT(operator new(*(_DWORD *)&useBlur[52]));
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v21;
  LOBYTE(v390) = 33;
  if ( *(float *)&v21 == 0.0 )
  {
    *(float *)&v23 = 0.0;
  }
  else
  {
    PhysicsAvatar::PhysicsAvatar(v21, this);
    v23 = v22;
  }
  LOBYTE(v390) = 20;
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v23;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&result);
  *(_DWORD *)&useBlur[52] = 0;
  v23->parent = this;
  this->physicsAvatar = v23;
  std::wstring::wstring((std::wstring *)&useBlur[28], L"cfg/gameplay.ini");
  INIReaderDocuments::INIReaderDocuments(&gameplayINI, (unsigned int)v6, *(std::wstring *)&useBlur[28], useBlur[52]);
  LOBYTE(v390) = 34;
  *(float *)&v24 = COERCE_FLOAT(operator new(432));
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v24;
  LOBYTE(v390) = 35;
  if ( *(float *)&v24 == 0.0 )
  {
    *(float *)&v26._Ptr = 0.0;
  }
  else
  {
    SharedMemoryWriter::SharedMemoryWriter(v24, (unsigned int)v6, this);
    v26._Ptr = v25._Ptr;
  }
  LOBYTE(v390) = 34;
  result._Ptr = v26._Ptr;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&result);
  *(_DWORD *)&useBlur[52] = 308;
  v26._Ptr->_Myval.first._Myres = (unsigned int)this;
  *(float *)&v27 = COERCE_FLOAT(operator new(*(_DWORD *)&useBlur[52]));
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v27;
  LOBYTE(v390) = 36;
  if ( *(float *)&v27 == 0.0 )
  {
    v28 = 0;
  }
  else
  {
    *(_DWORD *)&useBlur[52] = this->game->gui;
    std::wstring::wstring((std::wstring *)&useBlur[28], L"SIM_GAME_SCREEN");
    ksgui::GameScreen::GameScreen(v27, *(std::wstring *)&useBlur[28], *(ksgui::GUI **)&useBlur[52]);
  }
  v29 = this->game;
  this->gameScreen = v28;
  LOBYTE(v390) = 34;
  ksgui::GUI::addControl(v29->gui, v28);
  if ( gameplayINI.ready )
  {
    std::wstring::wstring(&key, L"USE_MPH");
    LOBYTE(v390) = 37;
    std::wstring::wstring(&nationCode, L"OPTIONS");
    LOBYTE(v390) = 38;
    Speed::useMPH = INIReader::getInt(&gameplayINI, &nationCode, &key) != 0;
    if ( nationCode._Myres >= 8 )
      operator delete(nationCode._Bx._Ptr);
    nationCode._Myres = 7;
    nationCode._Mysize = 0;
    nationCode._Bx._Buf[0] = 0;
    LOBYTE(v390) = 34;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  *(float *)&v30 = COERCE_FLOAT(operator new(360));
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v30;
  LOBYTE(v390) = 39;
  if ( *(float *)&v30 == 0.0 )
    v31 = 0;
  else
    ksgui::FormRenderStats::FormRenderStats(v30, this->game->gui, (GameTime *)(i + 16));
  *(_DWORD *)&useBlur[52] = 84;
  LOBYTE(v390) = 34;
  this->formRenderStats = v31;
  *(float *)&v32 = COERCE_FLOAT(operator new(*(_DWORD *)&useBlur[52]));
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v32;
  LOBYTE(v390) = 40;
  if ( *(float *)&v32 == 0.0 )
  {
    v34 = 0;
  }
  else
  {
    SkyBox::SkyBox(v32, (unsigned int)v6, this->game->graphics);
    v34 = v33;
  }
  v35 = this->sceneCamera;
  this->skyBox = v34;
  LOBYTE(v390) = 34;
  v35->skyBox = v34;
  Sim::initSceneGraph(this);
  *(float *)&v36 = COERCE_FLOAT(operator new(220));
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v36;
  LOBYTE(v390) = 41;
  if ( *(float *)&v36 == 0.0 )
  {
    *(float *)&v38._Ptr = 0.0;
  }
  else
  {
    WarningReporter::WarningReporter(v36, (unsigned int)v6, this);
    v38._Ptr = v37._Ptr;
  }
  LOBYTE(v390) = 34;
  result._Ptr = v38._Ptr;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&result);
  v38._Ptr->_Myval.first._Myres = (unsigned int)this;
  LOBYTE(v6) = videoini.ready
            && (std::wstring::wstring(&key, L"SIZE"),
                LOBYTE(v390) = 42,
                LODWORD(v367) = 1,
                std::wstring::wstring(&nationCode, L"MIRROR"),
                v390 = 43,
                LODWORD(v366) = 3,
                LODWORD(v367) = 3,
                INIReader::getInt(&videoini, &nationCode, &key));
  v39 = LODWORD(v366);
  if ( (LOBYTE(v366) & 2) != 0 )
  {
    v39 = LODWORD(v366) & 0xFFFFFFFD;
    LODWORD(v366) &= 0xFFFFFFFD;
    if ( nationCode._Myres >= 8 )
    {
      operator delete(nationCode._Bx._Ptr);
      v39 = LODWORD(v366);
    }
    nationCode._Myres = 7;
    nationCode._Mysize = 0;
    nationCode._Bx._Buf[0] = 0;
  }
  v390 = 34;
  if ( (v39 & 1) != 0 )
  {
    LODWORD(v366) = v39 & 0xFFFFFFFE;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  if ( (_BYTE)v6 )
  {
    *(float *)&v40 = COERCE_FLOAT(operator new(60));
    result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v40;
    LOBYTE(v390) = 44;
    if ( *(float *)&v40 == 0.0 )
      v41 = 0;
    else
      MirrorTextureRenderer::MirrorTextureRenderer(v40, (unsigned int)v6, this);
    LOBYTE(v390) = 34;
    this->mirrorTextureRenderer = v41;
  }
  *(float *)&v42 = COERCE_FLOAT(operator new(124));
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v42;
  LOBYTE(v390) = 45;
  if ( *(float *)&v42 == 0.0 )
  {
    *(float *)&v44 = 0.0;
  }
  else
  {
    *(_DWORD *)&useBlur[52] = this;
    std::wstring::wstring((std::wstring *)&useBlur[28], L"SCREEN CAPTURER");
    ScreenCapturer::ScreenCapturer(v42, *(std::wstring *)&useBlur[28], *(Sim **)&useBlur[52]);
    v44 = v43;
  }
  LOBYTE(v390) = 34;
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v44;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&result);
  v44->parent = this;
  *(_DWORD *)&useBlur[52] = 88;
  this->screenCapturer = v44;
  *(float *)&v45 = COERCE_FLOAT(operator new(*(_DWORD *)&useBlur[52]));
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v45;
  LOBYTE(v390) = 46;
  if ( *(float *)&v45 == 0.0 )
  {
    *(float *)&v47 = 0.0;
  }
  else
  {
    SystemMessage::SystemMessage(v45, this);
    v47 = v46;
  }
  LOBYTE(v390) = 34;
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v47;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&result);
  v47->parent = this;
  *(_DWORD *)&useBlur[52] = 108;
  this->systemMessage = v47;
  *(float *)&v48 = COERCE_FLOAT(operator new(*(_DWORD *)&useBlur[52]));
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v48;
  LOBYTE(v390) = 47;
  if ( *(float *)&v48 == 0.0 )
  {
    *(float *)&v50 = 0.0;
  }
  else
  {
    SystemNotification::SystemNotification(v48, this);
    v50 = v49;
  }
  LOBYTE(v390) = 34;
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v50;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&result);
  v50->parent = this;
  *(_DWORD *)&useBlur[52] = 80;
  this->systemNotification = v50;
  *(float *)&v51 = COERCE_FLOAT(operator new(*(_DWORD *)&useBlur[52]));
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v51;
  LOBYTE(v390) = 48;
  if ( *(float *)&v51 == 0.0 )
  {
    *(float *)&v53._Ptr = 0.0;
  }
  else
  {
    WeatherManager::WeatherManager(v51, this);
    v53._Ptr = v52._Ptr;
  }
  LOBYTE(v390) = 34;
  result._Ptr = v53._Ptr;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&result);
  *(_DWORD *)&useBlur[52] = 80;
  v53._Ptr->_Myval.first._Myres = (unsigned int)this;
  *(float *)&v54 = COERCE_FLOAT(operator new(*(_DWORD *)&useBlur[52]));
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v54;
  LOBYTE(v390) = 49;
  if ( *(float *)&v54 == 0.0 )
  {
    *(float *)&v56 = 0.0;
  }
  else
  {
    MicroSectors::MicroSectors(v54, (unsigned int)v6, this);
    v56 = v55;
  }
  LOBYTE(v390) = 34;
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v56;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&result);
  v56->parent = this;
  *(_DWORD *)&useBlur[52] = 344;
  this->microSectors = v56;
  *(float *)&v57 = COERCE_FLOAT(operator new(*(_DWORD *)&useBlur[52]));
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v57;
  LOBYTE(v390) = 50;
  if ( *(float *)&v57 == 0.0 )
  {
    *(float *)&v59 = 0.0;
  }
  else
  {
    RaceManager::RaceManager(v57, this);
    v59 = v58;
  }
  LOBYTE(v390) = 34;
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v59;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&result);
  v59->parent = this;
  this->raceManager = v59;
  if ( RaceManager::loadSessions(v59, (unsigned int)v6, v12, a3, a4) )
  {
    v60 = (CarAvatar *)&this->flagMapCache;
    std::_Tree<std::_Tmap_traits<std::wstring,Texture,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,Texture>>,0>>::_Erase(
      &this->flagMapCache,
      this->flagMapCache._Myhead->_Parent);
    v61 = this->flagMapCache._Myhead;
    *(_DWORD *)&useBlur[52] = L"content/gui/NationFlags/AC.png";
    v61->_Parent = v61;
    v60->~GameObject = (void (*)(GameObject *))v60->__vftable;
    v60->render = (void (*)(GameObject *, float))v60->__vftable;
    this->flagMapCache._Mysize = 0;
    std::wstring::wstring(&key, *(const wchar_t **)&useBlur[52]);
    LOBYTE(v390) = 51;
    std::wstring::wstring(&nationCode, L"AC");
    v62 = this->game;
    LOBYTE(v390) = 52;
    v63 = ResourceStore::getTexture(v62->graphics->resourceStore._Myptr, &v375, &key, 0);
    LOBYTE(v390) = 53;
    v64 = std::map<std::wstring,Texture>::operator[](&this->flagMapCache, &nationCode);
    v65 = v63->kid;
    v66 = &v63->fileName;
    v64->kid = v65;
    if ( &v64->fileName != v66 )
      std::wstring::assign(&v64->fileName, v66, 0, 0xFFFFFFFF);
    LOBYTE(v390) = 52;
    OnSetupAppCreated::~OnSetupAppCreated(&v375);
    if ( nationCode._Myres >= 8 )
      operator delete(nationCode._Bx._Ptr);
    nationCode._Myres = 7;
    nationCode._Mysize = 0;
    nationCode._Bx._Buf[0] = 0;
    LOBYTE(v390) = 34;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v67 = this->cars._Myfirst;
    v68 = &this->cars;
    v69 = this->cars._Mylast;
    if ( v67 != v69 )
    {
      do
      {
        v60 = *v67;
        if ( CarAvatar::isConnected(*v67) )
        {
          nationCode._Myres = 7;
          nationCode._Bx._Buf[0] = 0;
          nationCode._Mysize = 0;
          std::wstring::assign(&nationCode, &v60->driverInfo.nationCode, 0, 0xFFFFFFFF);
          LOBYTE(v390) = 54;
          v60 = (CarAvatar *)&this->flagMapCache;
          std::_Tree<std::_Tmap_traits<std::wstring,CBuffer *,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,CBuffer *>>,0>>::find(
            (std::_Tree<std::_Tmap_traits<std::wstring,enum DynamicControllerInput,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,enum DynamicControllerInput> >,0> > *)&this->flagMapCache,
            (std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,enum DynamicControllerInput> > > > *)&result,
            &nationCode);
          if ( result._Ptr == this->flagMapCache._Myhead )
          {
            v70 = std::operator+<wchar_t>(&v374, L"content/gui/NationFlags/", &nationCode);
            LOBYTE(v390) = 55;
            v71 = std::operator+<wchar_t>(&key, v70, L".png");
            v72 = this->game;
            LOBYTE(v390) = 56;
            v60 = (CarAvatar *)ResourceStore::getTexture(v72->graphics->resourceStore._Myptr, &v375, v71, 0);
            OnSetupAppCreated::~OnSetupAppCreated(&v375);
            if ( key._Myres >= 8 )
              operator delete(key._Bx._Ptr);
            key._Myres = 7;
            key._Mysize = 0;
            key._Bx._Buf[0] = 0;
            LOBYTE(v390) = 54;
            if ( v374._Myres >= 8 )
              operator delete(v374._Bx._Ptr);
            v374._Myres = 7;
            v374._Mysize = 0;
            v374._Bx._Buf[0] = 0;
            if ( v60->__vftable )
            {
              v73 = std::map<std::wstring,Texture>::operator[](&this->flagMapCache, &nationCode);
              v74 = v60->__vftable;
              v60 = (CarAvatar *)((char *)v60 + 4);
              v73->kid = v74;
              if ( &v73->fileName != (std::wstring *)v60 )
                std::wstring::assign(&v73->fileName, (const std::wstring *)v60, 0, 0xFFFFFFFF);
            }
          }
          LOBYTE(v390) = 34;
          if ( nationCode._Myres >= 8 )
            operator delete(nationCode._Bx._Ptr);
        }
        ++v67;
      }
      while ( v67 != v69 );
      v68 = &this->cars;
    }
    v75 = v68->_Myfirst;
    v76 = v68->_Mylast;
    if ( v75 == v76 )
    {
LABEL_124:
      *(float *)&v78 = COERCE_FLOAT(operator new(64));
      result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v78;
      LOBYTE(v390) = 57;
      if ( *(float *)&v78 == 0.0 )
      {
        *(float *)&v80._Ptr = 0.0;
      }
      else
      {
        PushToPassManager::PushToPassManager(v78, this);
        v80._Ptr = v79._Ptr;
      }
      LOBYTE(v390) = 34;
      v81 = &this->gameObjects;
      result._Ptr = v80._Ptr;
      std::vector<SpinnerData *>::push_back(
        (std::vector<ICollisionObject *> *)&this->gameObjects,
        (ICollisionObject *const *)&result);
      v80._Ptr->_Myval.first._Myres = (unsigned int)this;
    }
    else
    {
      while ( 1 )
      {
        v77 = (*v75)->physics;
        if ( v77 )
        {
          if ( !v77->drivetrain.acEngine.p2p.enabled )
            break;
        }
        if ( ++v75 == v76 )
          goto LABEL_124;
      }
      v81 = &this->gameObjects;
    }
    if ( !this->replayManager )
    {
      *(float *)&v82 = COERCE_FLOAT(operator new(264));
      result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v82;
      LOBYTE(v390) = 58;
      if ( *(float *)&v82 == 0.0 )
      {
        *(float *)&v84 = 0.0;
      }
      else
      {
        ReplayManager::ReplayManager(v82, this, this->physicsAvatar);
        v84 = v83;
      }
      LOBYTE(v390) = 34;
      result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v84;
      std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)v81, (ICollisionObject *const *)&result);
      v84->parent = this;
      this->replayManager = v84;
    }
    *(_DWORD *)&useBlur[28] = &std::_Func_impl<std::_Callable_obj<_lambda_1d4466c7ff4df7aa72f6d191899c6b8f_,0>,std::allocator<std::_Func_class<void,OnReplayStatusChanged const &>>,void,OnReplayStatusChanged const &>::`vftable';
    *(_DWORD *)&useBlur[32] = this;
    *(_DWORD *)&useBlur[44] = &useBlur[28];
    LOBYTE(v390) = 34;
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)&this->evOnReplayStatusChanged,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&useBlur[28],
      this);
    v85 = this->sceneCamera;
    *(_DWORD *)&useBlur[52] = 332;
    v85->nearPlane = 0.050000001;
    this->sceneCamera->farPlane = 40000.0;
    *(float *)&v86 = COERCE_FLOAT(operator new(*(_DWORD *)&useBlur[52]));
    result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v86;
    LOBYTE(v390) = 60;
    if ( *(float *)&v86 == 0.0 )
    {
      v88 = 0;
    }
    else
    {
      ACHideAll::ACHideAll(v86, this);
      v88 = v87;
    }
    v89 = this->gameScreen;
    LOBYTE(v390) = 34;
    v89->addControl(v89, v88, 1);
    *(float *)&v90 = COERCE_FLOAT(operator new(376));
    result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v90;
    LOBYTE(v390) = 61;
    if ( *(float *)&v90 == 0.0 )
      v91 = 0;
    else
      PauseMenu::PauseMenu(v90, this, this->game->gui);
    *(_DWORD *)&useBlur[52] = 0;
    LOBYTE(v390) = 34;
    this->pauseMenu = v91;
    ksgui::Control::setVisible(v91, *(BOOL *)&useBlur[52]);
    ksgui::GUI::addControl(this->game->gui, this->pauseMenu);
    nationCode._Myres = 7;
    BYTE1(v60) = 1;
    nationCode._Mysize = 0;
    LOBYTE(i) = 1;
    nationCode._Bx._Buf[0] = 0;
    std::wstring::assign(&nationCode, L"system/cfg/assetto_corsa.ini", 0x1Cu);
    LOBYTE(v390) = 62;
    INIReader::INIReader(&acIni, &nationCode);
    LOBYTE(v390) = 64;
    if ( nationCode._Myres >= 8 )
      operator delete(nationCode._Bx._Ptr);
    nationCode._Myres = 7;
    nationCode._Mysize = 0;
    nationCode._Bx._Buf[0] = 0;
    LOBYTE(v60) = acIni.ready
               && (std::wstring::wstring(&key, L"AC_APPS"),
                   LOBYTE(v390) = 65,
                   LODWORD(v366) |= 4u,
                   v367 = v366,
                   INIReader::hasSection(&acIni, &key));
    v390 = 64;
    if ( (LOBYTE(v366) & 4) != 0 )
    {
      LODWORD(v366) &= 0xFFFFFFFB;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
    if ( (_BYTE)v60 )
    {
      std::wstring::wstring(&key, L"ENABLE_DEV_APPS");
      LOBYTE(v390) = 66;
      std::wstring::wstring(&section, L"AC_APPS");
      LOBYTE(v390) = 67;
      BYTE1(v60) = INIReader::getInt(&acIni, &section, &key) > 0;
      LOBYTE(i) = BYTE1(v60);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v390) = 64;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"ALLOW_FREE_CAMERA");
      LOBYTE(v390) = 68;
      std::wstring::wstring(&section, L"CAMERA");
      LOBYTE(v390) = 69;
      v92 = INIReader::getInt(&acIni, &section, &key);
      v9 = section._Myres < 8;
      this->allowFreeCamera = v92 > 0;
      if ( !v9 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v390) = 64;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
    *(_DWORD *)&useBlur[52] = L"system/cfg/pitstop.ini";
    this->useMousePitstop = 0;
    std::wstring::wstring(&v374, *(const wchar_t **)&useBlur[52]);
    LOBYTE(v390) = 70;
    INIReader::INIReader(&acPitstop, &v374);
    LOBYTE(v390) = 72;
    if ( v374._Myres >= 8 )
      operator delete(v374._Bx._Ptr);
    v374._Myres = 7;
    v374._Mysize = 0;
    v374._Bx._Buf[0] = 0;
    if ( acPitstop.ready )
    {
      std::wstring::wstring(&key, L"USE_MOUSE_PITSTOP");
      LOBYTE(v390) = 73;
      LODWORD(v366) |= 8u;
      v367 = v366;
      std::wstring::wstring(&section, L"SETTINGS");
      v390 = 74;
      LODWORD(v366) |= 0x10u;
      v367 = v366;
      INIReader::hasKey(&acPitstop, &section, &key);
    }
    v93 = LODWORD(v366);
    if ( (LOBYTE(v366) & 0x10) != 0 )
    {
      v93 = LODWORD(v366) & 0xFFFFFFEF;
      LODWORD(v366) &= 0xFFFFFFEF;
      if ( section._Myres >= 8 )
      {
        operator delete(section._Bx._Ptr);
        v93 = LODWORD(v366);
      }
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
    }
    v390 = 72;
    if ( (v93 & 8) != 0 )
    {
      LODWORD(v366) = v93 & 0xFFFFFFF7;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
    std::wstring::wstring(&key, L"USE_MOUSE_PITSTOP");
    LOBYTE(v390) = 75;
    std::wstring::wstring(&section, L"SETTINGS");
    LOBYTE(v390) = 76;
    v94 = INIReader::getInt(&acPitstop, &section, &key);
    v9 = section._Myres < 8;
    this->useMousePitstop = v94 != 0;
    if ( !v9 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v390) = 72;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v95 = &this->cars;
    if ( !this->useMousePitstop )
    {
      v96 = this->cars._Mylast - this->cars._Myfirst ? *v95->_Myfirst : 0;
      if ( CarAvatar::getControlsProvider(v96) )
      {
        if ( this->cars._Mylast - this->cars._Myfirst )
          v97 = *v95->_Myfirst;
        else
          v97 = 0;
        v98 = CarAvatar::getControlsProvider(v97);
        this->useMousePitstop = v98->IsKeyboardControl(v98);
      }
    }
    std::wstring::wstring(&key, L"system/cfg/audio_engine.ini");
    LOBYTE(v390) = 77;
    INIReader::INIReader(&audioIni, &key);
    LOBYTE(v390) = 79;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( audioIni.ready )
    {
      std::wstring::wstring(&v376, L"ENABLE_PERFORMANCE_SPEW");
      LOBYTE(v390) = 80;
      std::wstring::wstring(&section, L"SETTINGS");
      LOBYTE(v390) = 81;
      v99 = INIReader::getInt(&audioIni, &section, &v376);
      v9 = section._Myres < 8;
      this->audioPerformanceSpew = v99 != 0;
      if ( !v9 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v390) = 79;
      if ( v376._Myres >= 8 )
        operator delete(v376._Bx._Ptr);
    }
    *(float *)&v100 = COERCE_FLOAT(operator new(452));
    result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v100;
    LOBYTE(v390) = 82;
    if ( *(float *)&v100 == 0.0 )
    {
      v102 = 0;
      *(float *)&result._Ptr = 0.0;
    }
    else
    {
      ACEssentials::ACEssentials(v100, (unsigned int)v60, this);
      v102 = (ksgui::Control *)v101._Ptr;
      result._Ptr = v101._Ptr;
    }
    LOBYTE(v390) = 79;
    if ( BYTE1(v60) || !v102[1].name._Bx._Alias[0] )
    {
      this->gameScreen->addControl(this->gameScreen, v102, 1);
    }
    else
    {
      this->gameScreen->addControl(this->gameScreen, v102, 0);
      ksgui::Control::setVisible(v102, 0);
    }
    *(float *)&v103 = COERCE_FLOAT(operator new(708));
    v367 = *(float *)&v103;
    LOBYTE(v390) = 83;
    if ( *(float *)&v103 == 0.0 )
    {
      v105 = 0;
    }
    else
    {
      FormChat::FormChat(v103, this);
      v105 = v104;
    }
    LOBYTE(v390) = 79;
    if ( BYTE1(v60) || !v105[1].name._Bx._Alias[0] )
    {
      this->gameScreen->addControl(this->gameScreen, v105, 1);
    }
    else
    {
      this->gameScreen->addControl(this->gameScreen, v105, 0);
      ksgui::Control::setVisible(v105, 0);
    }
    *(float *)&v106 = COERCE_FLOAT(operator new(952));
    v367 = *(float *)&v106;
    LOBYTE(v390) = 84;
    if ( *(float *)&v106 == 0.0 )
    {
      v107 = 0;
    }
    else if ( this->cars._Mylast - this->cars._Myfirst )
    {
      TyresApp::TyresApp(v106, (unsigned int)v60, *v95->_Myfirst);
    }
    else
    {
      TyresApp::TyresApp(v106, (unsigned int)v60, 0);
    }
    v108 = i;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v107, i);
    v109 = (LeaderboardApp *)operator new(320);
    i = (int)v109;
    LOBYTE(v390) = 85;
    if ( v109 )
      LeaderboardApp::LeaderboardApp(v109, this);
    else
      v110 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v110, v108);
    v111 = (PlayerCurrentTime *)operator new(536);
    i = (int)v111;
    LOBYTE(v390) = 86;
    if ( v111 )
      PlayerCurrentTime::PlayerCurrentTime(v111, (unsigned int)v60, this);
    else
      v112 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v112, v108);
    v113 = (CameraForwardYebis *)__RTDynamicCast(
                                   this->sceneCamera,
                                   0,
                                   &CameraForward `RTTI Type Descriptor',
                                   &CameraForwardYebis `RTTI Type Descriptor',
                                   0);
    if ( v113 )
    {
      v114 = (FormHDR *)operator new(376);
      i = (int)v114;
      LOBYTE(v390) = 87;
      if ( v114 )
        FormHDR::FormHDR(v114, this->game->gui, v113, this);
      else
        v115 = 0;
      LOBYTE(v390) = 79;
      Sim::addForm(this, v115, v108);
    }
    v116 = (FormVolumes *)operator new(408);
    i = (int)v116;
    LOBYTE(v390) = 88;
    if ( v116 )
      FormVolumes::FormVolumes(v116, this);
    else
      v117 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v117, v108);
    v118 = (RaceFuelMonitor *)operator new(324);
    i = (int)v118;
    LOBYTE(v390) = 89;
    if ( v118 )
      RaceFuelMonitor::RaceFuelMonitor(v118, (unsigned int)v113, this);
    else
      v119 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v119, v108);
    v120 = (PhotoMode *)operator new(412);
    i = (int)v120;
    LOBYTE(v390) = 90;
    if ( v120 )
      PhotoMode::PhotoMode(v120, this);
    else
      v121 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v121, v108);
    v122 = (FormDRSZones *)operator new(368);
    i = (int)v122;
    LOBYTE(v390) = 91;
    if ( v122 )
    {
      v123 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      FormDRSZones::FormDRSZones(v122, *v123);
    }
    else
    {
      v124 = 0;
    }
    LOBYTE(v390) = 79;
    Sim::addForm(this, v124, v108);
    v125 = (SetupDebug *)operator new(328);
    i = (int)v125;
    LOBYTE(v390) = 92;
    if ( v125 )
      SetupDebug::SetupDebug(v125, (unsigned int)v113, this);
    else
      v126 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v126, v108);
    v127 = (TyreWearingDebug *)operator new(324);
    i = (int)v127;
    LOBYTE(v390) = 93;
    if ( v127 )
      TyreWearingDebug::TyreWearingDebug(v127, this);
    else
      v128 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v128, v108);
    v129 = (FormTelemetry *)operator new(456);
    i = (int)v129;
    LOBYTE(v390) = 94;
    if ( v129 )
    {
      v130 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      FormTelemetry::FormTelemetry(v129, *v130);
    }
    else
    {
      v131 = 0;
    }
    LOBYTE(v390) = 79;
    Sim::addForm(this, v131, v108);
    v132 = (ACHelp *)operator new(328);
    i = (int)v132;
    LOBYTE(v390) = 95;
    if ( v132 )
      ACHelp::ACHelp(v132, (unsigned int)v113, this->game->gui);
    else
      v133 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v133, v108);
    v134 = (ACTimeFlow *)operator new(468);
    i = (int)v134;
    LOBYTE(v390) = 96;
    if ( v134 )
      ACTimeFlow::ACTimeFlow(v134, (unsigned int)v113, this);
    else
      v135 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v135, v108);
    if ( __RTDynamicCast(
           this->sceneCamera,
           0,
           &CameraForward `RTTI Type Descriptor',
           &StereoCameraVive `RTTI Type Descriptor',
           0) )
    {
      v136 = (FormOpenVR *)operator new(344);
      i = (int)v136;
      LOBYTE(v390) = 97;
      if ( v136 )
        FormOpenVR::FormOpenVR(v136, v10, this);
      else
        v137 = 0;
      LOBYTE(v390) = 79;
      Sim::addForm(this, v137, 0);
    }
    if ( GameObject::getGameObject<PostProcessEffectsUpdater>(this) )
    {
      v138 = (PostProcessFilterSelector *)operator new(328);
      i = (int)v138;
      LOBYTE(v390) = 98;
      if ( v138 )
        PostProcessFilterSelector::PostProcessFilterSelector(v138, (unsigned int)v113, this);
      else
        v139 = 0;
      LOBYTE(v390) = 79;
      Sim::addForm(this, v139, v108);
    }
    v140 = (DriverEyesPositioner *)operator new(460);
    i = (int)v140;
    LOBYTE(v390) = 99;
    if ( v140 )
    {
      v141 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      DriverEyesPositioner::DriverEyesPositioner(v140, (unsigned int)v113, *v141);
    }
    else
    {
      v142 = 0;
    }
    LOBYTE(v390) = 79;
    Sim::addForm(this, v142, v108);
    v143 = (FFBForm *)operator new(440);
    i = (int)v143;
    LOBYTE(v390) = 100;
    if ( v143 )
    {
      v144 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      FFBForm::FFBForm(v143, (unsigned int)v113, *v144);
    }
    else
    {
      v145 = 0;
    }
    LOBYTE(v390) = 79;
    Sim::addForm(this, v145, v108);
    Sim::addForm(this, this->formRenderStats, v108);
    v146 = (CarPedalsForm *)operator new(352);
    i = (int)v146;
    LOBYTE(v390) = 101;
    if ( v146 )
    {
      v147 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      CarPedalsForm::CarPedalsForm(v146, (unsigned int)v113, *v147);
    }
    else
    {
      v148 = 0;
    }
    LOBYTE(v390) = 79;
    Sim::addForm(this, v148, v108);
    if ( GameObject::getGameObject<ACClient>(this) )
    {
      v149 = (NetMonitorForm *)operator new(340);
      i = (int)v149;
      LOBYTE(v390) = 102;
      if ( v149 )
        NetMonitorForm::NetMonitorForm(v149, (unsigned int)v113, this);
      else
        v150 = 0;
      LOBYTE(v390) = 79;
      Sim::addForm(this, v150, v108);
    }
    v151 = (FormRealTimeTiming *)operator new(544);
    i = (int)v151;
    LOBYTE(v390) = 103;
    if ( v151 )
      FormRealTimeTiming::FormRealTimeTiming(v151, this);
    else
      v152 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v152, v108);
    v153 = (PerformanceMeterApp *)operator new(360);
    i = (int)v153;
    LOBYTE(v390) = 104;
    if ( v153 )
    {
      v154 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      PerformanceMeterApp::PerformanceMeterApp(v153, (unsigned int)v113, *v154);
    }
    else
    {
      v155 = 0;
    }
    LOBYTE(v390) = 79;
    Sim::addForm(this, v155, v108);
    v156 = (FormGear *)operator new(672);
    i = (int)v156;
    LOBYTE(v390) = 105;
    if ( v156 )
    {
      v157 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      FormGear::FormGear(v156, (unsigned int)v113, *v157);
    }
    else
    {
      v158 = 0;
    }
    LOBYTE(v390) = 79;
    Sim::addForm(this, v158, v108);
    v159 = (TrackMap *)operator new(652);
    i = (int)v159;
    LOBYTE(v390) = 106;
    if ( v159 )
      TrackMap::TrackMap(v159, this->game->gui, this, 0);
    else
      v160 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v160, v108);
    v161 = (ElectronicAidsForm *)operator new(340);
    i = (int)v161;
    LOBYTE(v390) = 107;
    if ( v161 )
    {
      v162 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      ElectronicAidsForm::ElectronicAidsForm(v161, *v162);
    }
    else
    {
      v163 = 0;
    }
    LOBYTE(v390) = 79;
    Sim::addForm(this, v163, v108);
    v164 = (FormMGU *)operator new(340);
    i = (int)v164;
    LOBYTE(v390) = 108;
    if ( v164 )
    {
      v165 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      FormMGU::FormMGU(v164, (unsigned int)v113, *v165);
    }
    else
    {
      v166 = 0;
    }
    LOBYTE(v390) = 79;
    Sim::addForm(this, v166, v108);
    if ( !GameObject::getGameObject<ACClient>(this) )
    {
      v167 = (FormBallast *)operator new(324);
      i = (int)v167;
      LOBYTE(v390) = 109;
      if ( v167 )
      {
        v168 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
        FormBallast::FormBallast(v167, *v168);
      }
      else
      {
        v169 = 0;
      }
      LOBYTE(v390) = 79;
      Sim::addForm(this, v169, v108);
    }
    if ( this->tripleScreenMode )
    {
      v170 = (TripleScreenManager *)operator new(648);
      i = (int)v170;
      LOBYTE(v390) = 110;
      if ( v170 )
        TripleScreenManager::TripleScreenManager(v170, this);
      else
        v171 = 0;
      LOBYTE(v390) = 79;
      Sim::addForm(this, v171, v108);
    }
    v172 = (FormAI *)operator new(468);
    i = (int)v172;
    LOBYTE(v390) = 111;
    if ( v172 )
      FormAI::FormAI(v172, this);
    else
      v173 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v173, v108);
    v174 = (CarPhysicsForm *)operator new(360);
    i = (int)v174;
    LOBYTE(v390) = 112;
    if ( v174 )
    {
      v175 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      CarPhysicsForm::CarPhysicsForm(v174, *v175);
    }
    else
    {
      v176 = 0;
    }
    LOBYTE(v390) = 79;
    Sim::addForm(this, v176, v108);
    v177 = (TelemetryApp *)operator new(340);
    i = (int)v177;
    LOBYTE(v390) = 113;
    if ( v177 )
    {
      v178 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      TelemetryApp::TelemetryApp(v177, (unsigned int)v113, *v178);
    }
    else
    {
      v179 = 0;
    }
    LOBYTE(v390) = 79;
    Sim::addForm(this, v179, v108);
    v180 = (FormGameStats *)operator new(356);
    i = (int)v180;
    LOBYTE(v390) = 114;
    if ( v180 )
      FormGameStats::FormGameStats(v180, this->game);
    else
      v181 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v181, v108);
    v182 = (RacePosition *)operator new(356);
    i = (int)v182;
    LOBYTE(v390) = 115;
    if ( v182 )
      RacePosition::RacePosition(v182, (unsigned int)v113, this);
    else
      v183 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v183, v108);
    v184 = (KeyboardControlsDebug *)operator new(352);
    i = (int)v184;
    LOBYTE(v390) = 116;
    if ( v184 )
    {
      v185 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      KeyboardControlsDebug::KeyboardControlsDebug(v184, *v185);
    }
    else
    {
      v186 = 0;
    }
    LOBYTE(v390) = 79;
    Sim::addForm(this, v186, v108);
    v187 = (FormDriverModel *)operator new(380);
    i = (int)v187;
    LOBYTE(v390) = 117;
    if ( v187 )
    {
      v188 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      FormDriverModel::FormDriverModel(v187, *v188);
    }
    else
    {
      v189 = 0;
    }
    LOBYTE(v390) = 79;
    Sim::addForm(this, v189, v108);
    v190 = (TyreTesterForm *)operator new(352);
    i = (int)v190;
    LOBYTE(v390) = 118;
    if ( v190 )
    {
      v191 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      TyreTesterForm::TyreTesterForm(v190, *v191, this->game->gui);
    }
    else
    {
      v192 = 0;
    }
    LOBYTE(v390) = 79;
    Sim::addForm(this, v192, v108);
    v193 = (FormLogoAC *)operator new(320);
    i = (int)v193;
    LOBYTE(v390) = 119;
    if ( v193 )
      FormLogoAC::FormLogoAC(v193, (unsigned int)v113, this->game->gui);
    else
      v194 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v194, v108);
    v195 = (FormWings *)operator new(324);
    i = (int)v195;
    LOBYTE(v390) = 120;
    if ( v195 )
    {
      v196 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      FormWings::FormWings(v195, *v196);
    }
    else
    {
      v197 = 0;
    }
    LOBYTE(v390) = 79;
    Sim::addForm(this, v197, v108);
    v198 = (ACSuspension *)operator new(468);
    i = (int)v198;
    LOBYTE(v390) = 121;
    if ( v198 )
    {
      v199 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      ACSuspension::ACSuspension(v198, *v199);
    }
    else
    {
      v200 = 0;
    }
    LOBYTE(v390) = 79;
    Sim::addForm(this, v200, v108);
    v201 = (ACDriverPerformance *)operator new(500);
    i = (int)v201;
    LOBYTE(v390) = 122;
    if ( v201 )
    {
      v202 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      ACDriverPerformance::ACDriverPerformance(v201, (unsigned int)v113, *v202);
    }
    else
    {
      v203 = 0;
    }
    LOBYTE(v390) = 79;
    Sim::addForm(this, v203, v108);
    v204 = (ACDCarEngineer *)operator new(348);
    i = (int)v204;
    LOBYTE(v390) = 123;
    if ( v204 )
      ACDCarEngineer::ACDCarEngineer(v204, this);
    else
      v205 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v205, v108);
    v206 = (GPUProfilerApp *)operator new(324);
    i = (int)v206;
    LOBYTE(v390) = 124;
    if ( v206 )
      GPUProfilerApp::GPUProfilerApp(v206, (unsigned int)v113, this->game->graphics, this->game->gui);
    else
      v207 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v207, v108);
    if ( v113 )
    {
      v208 = (FormCamera *)operator new(492);
      i = (int)v208;
      LOBYTE(v390) = 125;
      if ( v208 )
        FormCamera::FormCamera(v208, (unsigned int)v113, this, v113);
      else
        v209 = 0;
      LOBYTE(v390) = 79;
      Sim::addForm(this, v209, v108);
    }
    v210 = (TrackDescription *)operator new(328);
    i = (int)v210;
    LOBYTE(v390) = 126;
    if ( v210 )
      TrackDescription::TrackDescription(v210, (unsigned int)v113, this);
    else
      v211 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v211, v108);
    v212 = (X360ControllerDebug *)operator new(336);
    i = (int)v212;
    LOBYTE(v390) = 127;
    if ( v212 )
      X360ControllerDebug::X360ControllerDebug(v212, this);
    else
      v213 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v213, v108);
    v214 = (TimeLimitedTest *)operator new(76);
    i = (int)v214;
    LOBYTE(v390) = 0x80;
    if ( v214 )
      TimeLimitedTest::TimeLimitedTest(v214, (unsigned int)v113, this);
    else
      v215 = 0;
    LOBYTE(v390) = 79;
    v216 = (TimeLimitedTest *)GameObject::addGameObject<ProximityIndicator>(this, v215);
    this->timeLimitedTest = v216;
    if ( v216->isActive )
    {
      v217 = (FormRunningTime *)operator new(332);
      i = (int)v217;
      LOBYTE(v390) = -127;
      if ( v217 )
        FormRunningTime::FormRunningTime(v217, (unsigned int)v113, this);
      else
        v218 = 0;
      LOBYTE(v390) = 79;
      Sim::addForm(this, v218, v108);
    }
    if ( !gameplayINI.ready )
      goto LABEL_363;
    std::wstring::wstring(&_Keyval, L"PYTHON");
    v219 = LODWORD(v366) | 0x20;
    LOBYTE(v390) = -126;
    v366 = *(float *)&v219;
    v367 = *(float *)&v219;
    if ( !INIReader::hasSection(&gameplayINI, &_Keyval) )
      goto LABEL_363;
    std::wstring::wstring(&section, L"ENABLE_PYTHON");
    LODWORD(v220) = v219 | 0x40;
    v390 = 131;
    v367 = v220;
    std::wstring::wstring(&v376, L"PYTHON");
    v390 = 132;
    LODWORD(v366) = LODWORD(v220) | 0x80;
    LODWORD(v367) = LODWORD(v220) | 0x80;
    if ( INIReader::getInt(&gameplayINI, &v376, &section) > 0 )
      v221 = 1;
    else
LABEL_363:
      v221 = 0;
    v222 = LODWORD(v366);
    if ( SLOBYTE(v366) < 0 )
    {
      LODWORD(v366) &= 0xFFFFFF7F;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v376);
      v222 = LODWORD(v366);
    }
    if ( (v222 & 0x40) != 0 )
    {
      LODWORD(v366) = v222 & 0xFFFFFFBF;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
      v222 = LODWORD(v366);
    }
    v390 = 79;
    if ( (v222 & 0x20) != 0 )
    {
      LODWORD(v366) = v222 & 0xFFFFFFDF;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
    }
    if ( v221 )
    {
      v223 = (PythonInterface *)operator new(280);
      i = (int)v223;
      LOBYTE(v390) = -123;
      if ( v223 )
        PythonInterface::PythonInterface(v223, this);
      else
        v224 = 0;
      LOBYTE(v390) = 79;
      GameObject::addGameObject<ProximityIndicator>(this, v224);
    }
    v225 = (char *)&this->cars;
    v226 = (std::unique_ptr<RaceEngineer> **)std::vector<DigitalItem *>::operator[](
                                               (std::vector<DigitalItem *> *)&this->cars,
                                               0);
    if ( std::unique_ptr<RaceEngineer>::operator bool(*v226 + 918) )
    {
      v227 = (ComparativeTelemetryRecorder *)operator new(236);
      i = (int)v227;
      LOBYTE(v390) = -122;
      if ( v227 )
      {
        v228 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
        ComparativeTelemetryRecorder::ComparativeTelemetryRecorder(v227, *v228);
      }
      else
      {
        v229 = 0;
      }
      LOBYTE(v390) = 79;
      GameObject::addGameObject<ProximityIndicator>(this, v229);
    }
    v230 = (ESCMenu *)operator new(408);
    i = (int)v230;
    LOBYTE(v390) = -121;
    if ( v230 )
      ESCMenu::ESCMenu(v230, (unsigned int)v225, this, this->game->gui);
    else
      v231 = 0;
    v232 = this->client == 0;
    LOBYTE(v390) = 79;
    this->escMenu = v231;
    if ( !v232 )
    {
      *(_DWORD *)&useBlur[52] = this;
      CommandItem::CommandItem(
        (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&i,
        (CarAudioFMOD *)this);
      std::function<void __cdecl (RemoteSession const &)>::function<void __cdecl (RemoteSession const &)>(
        (std::function<void __cdecl(RemoteSession const &)> *)&useBlur[28],
        v233);
      Event<float>::addHandler(
        (Event<SessionInfo> *)&this->client->evOnOnlineNewSession,
        *(std::function<void __cdecl(SessionInfo const &)> *)&useBlur[28],
        *(void **)&useBlur[52]);
    }
    switch ( RaceManager::getCurrentSessionType(this->raceManager) )
    {
      case Race:
        if ( RaceManager::isOfficialSpecialEvent(this->raceManager) )
        {
          v244 = (RaceEvent *)operator new(132);
          i = (int)v244;
          LOBYTE(v390) = -116;
          if ( v244 )
            RaceEvent::RaceEvent(v244, (unsigned int)v225, this);
          else
            v245 = 0;
          LOBYTE(v390) = 79;
          GameObject::addGameObject<ProximityIndicator>(this, v245);
        }
        break;
      case Hotlap:
        v242 = (HotlapMode *)operator new(128);
        i = (int)v242;
        LOBYTE(v390) = -117;
        if ( !v242 )
          goto LABEL_397;
        HotlapMode::HotlapMode(v242, this);
        LOBYTE(v390) = 79;
        GameObject::addGameObject<ProximityIndicator>(this, v243);
        break;
      case TimeAttack:
        v237 = (TimeAttack *)operator new(492);
        i = (int)v237;
        LOBYTE(v390) = -119;
        if ( !v237 )
          goto LABEL_397;
        v238 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
        TimeAttack::TimeAttack(v237, (char)v225, a3, a4, *v238);
        LOBYTE(v390) = 79;
        GameObject::addGameObject<ProximityIndicator>(this, v239);
        break;
      case Drift:
        v234 = (DriftMode *)operator new(4468);
        i = (int)v234;
        LOBYTE(v390) = -120;
        if ( !v234 )
          goto LABEL_397;
        v235 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
        DriftMode::DriftMode(v234, *v235);
        LOBYTE(v390) = 79;
        GameObject::addGameObject<ProximityIndicator>(this, v236);
        break;
      case Drag:
        v240 = (DragMode *)operator new(480);
        i = (int)v240;
        LOBYTE(v390) = -118;
        if ( v240 )
        {
          DragMode::DragMode(v240, this);
          LOBYTE(v390) = 79;
          GameObject::addGameObject<ProximityIndicator>(this, v241);
        }
        else
        {
LABEL_397:
          LOBYTE(v390) = 79;
          GameObject::addGameObject<ProximityIndicator>(this, 0);
        }
        break;
      default:
        break;
    }
    TrackAvatar::initPitCrew(this->track);
    ksgui::GUI::addControl(this->game->gui, this->escMenu);
    *(_DWORD *)&useBlur[52] = this;
    CommandItem::CommandItem(
      (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&i,
      (CarAudioFMOD *)this);
    std::function<void __cdecl (OnESCMenuTriggered const &)>::function<void __cdecl (OnESCMenuTriggered const &)>(
      (std::function<void __cdecl(OnESCMenuTriggered const &)> *)&useBlur[28],
      v246);
    Event<float>::addHandler(
      (Event<SessionInfo> *)&this->escMenu->evOnESCMenuTriggered,
      *(std::function<void __cdecl(SessionInfo const &)> *)&useBlur[28],
      *(void **)&useBlur[52]);
    v247 = (PluginManager *)operator new(76);
    i = (int)v247;
    LOBYTE(v390) = -115;
    if ( v247 )
      PluginManager::PluginManager(v247, this);
    else
      v248 = 0;
    LOBYTE(v390) = 79;
    GameObject::addGameObject<ProximityIndicator>(this, v248);
    AppForm::addEventListener(&this->game->keyboardManager, &this->IKeyEventListener);
    v249 = (SimScreen *)operator new(56);
    i = (int)v249;
    LOBYTE(v390) = -114;
    if ( v249 )
      SimScreen::SimScreen(v249, this);
    else
      v250 = 0;
    LOBYTE(v390) = 79;
    this->simScreen = (SimScreen *)GameObject::addGameObject<ProximityIndicator>(this, v250);
    Sim::initCubemaps(this);
    v251 = (RemoteTelemetryUDP *)operator new(404);
    i = (int)v251;
    LOBYTE(v390) = -113;
    if ( v251 )
    {
      v252 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      RemoteTelemetryUDP::RemoteTelemetryUDP(v251, this, *v252);
    }
    else
    {
      v253 = 0;
    }
    LOBYTE(v390) = 79;
    GameObject::addGameObject<ProximityIndicator>(this, v253);
    v254 = (MouseHider *)operator new(84);
    i = (int)v254;
    LOBYTE(v390) = -112;
    if ( v254 )
      MouseHider::MouseHider(v254, this);
    else
      v255 = 0;
    LOBYTE(v390) = 79;
    GameObject::addGameObject<ProximityIndicator>(this, v255);
    if ( RaceManager::getCurrentSessionType(this->raceManager) != Drift )
    {
      v256 = (WrongWayIndicator *)operator new(112);
      i = (int)v256;
      LOBYTE(v390) = -111;
      if ( v256 )
      {
        v257 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
        WrongWayIndicator::WrongWayIndicator(v256, (unsigned int)v225, *v257);
      }
      else
      {
        v258 = 0;
      }
      LOBYTE(v390) = 79;
      GameObject::addGameObject<ProximityIndicator>(this, v258);
    }
    v259 = (ACOperatingSystem *)operator new(116);
    i = (int)v259;
    LOBYTE(v390) = -110;
    if ( v259 )
      ACOperatingSystem::ACOperatingSystem(v259, this);
    else
      v260 = 0;
    LOBYTE(v390) = 79;
    GameObject::addGameObject<ACOperatingSystem>(this, v260);
    v261 = (ACCameraManager *)operator new(252);
    i = (int)v261;
    LOBYTE(v390) = -109;
    if ( v261 )
      ACCameraManager::ACCameraManager(v261, this, this->sceneCamera);
    else
      v262 = 0;
    LOBYTE(v390) = 79;
    v263 = (ACCameraManager *)GameObject::addGameObject<ProximityIndicator>(this, v262);
    *(_DWORD *)&useBlur[52] = 348;
    this->cameraManager = v263;
    v264 = (ChaseCamEditor *)operator new(*(_DWORD *)&useBlur[52]);
    i = (int)v264;
    LOBYTE(v390) = -108;
    if ( v264 )
      ChaseCamEditor::ChaseCamEditor(v264, this);
    else
      v265 = 0;
    LOBYTE(v390) = 79;
    Sim::addForm(this, v265, v108);
    v266 = (StartingLights *)operator new(156);
    i = (int)v266;
    LOBYTE(v390) = -107;
    if ( v266 )
      StartingLights::StartingLights(v266, this);
    else
      v267 = 0;
    LOBYTE(v390) = 79;
    GameObject::addGameObject<ProximityIndicator>(this, v267);
    v268 = (StartingTrackSemaphore *)operator new(88);
    i = (int)v268;
    LOBYTE(v390) = -106;
    if ( v268 )
      StartingTrackSemaphore::StartingTrackSemaphore(v268, this);
    else
      v269 = 0;
    LOBYTE(v390) = 79;
    GameObject::addGameObject<ProximityIndicator>(this, v269);
    v270 = (UDPCommandListener *)operator new(60);
    i = (int)v270;
    LOBYTE(v390) = -105;
    if ( v270 )
      UDPCommandListener::UDPCommandListener(v270, this);
    else
      v271 = 0;
    LOBYTE(v390) = 79;
    GameObject::addGameObject<ProximityIndicator>(this, v271);
    v272 = (JsonOutputFile *)operator new(104);
    i = (int)v272;
    LOBYTE(v390) = -104;
    if ( v272 )
      JsonOutputFile::JsonOutputFile(v272, this);
    else
      v273 = 0;
    LOBYTE(v390) = 79;
    GameObject::addGameObject<ProximityIndicator>(this, v273);
    v274 = (LapInvalidatorAvatar *)operator new(128);
    i = (int)v274;
    LOBYTE(v390) = -103;
    if ( v274 )
      LapInvalidatorAvatar::LapInvalidatorAvatar(v274, this);
    else
      v275 = 0;
    LOBYTE(v390) = 79;
    GameObject::addGameObject<ProximityIndicator>(this, v275);
    v276 = (DriveThroughPenaltyAvatar *)operator new(68);
    i = (int)v276;
    LOBYTE(v390) = -102;
    if ( v276 )
      DriveThroughPenaltyAvatar::DriveThroughPenaltyAvatar(v276, this);
    else
      v277 = 0;
    LOBYTE(v390) = 79;
    GameObject::addGameObject<ProximityIndicator>(this, v277);
    v278 = (LockControlsTimeAvatar *)operator new(96);
    i = (int)v278;
    LOBYTE(v390) = -101;
    if ( v278 )
      LockControlsTimeAvatar::LockControlsTimeAvatar(v278, this);
    else
      v279 = 0;
    LOBYTE(v390) = 79;
    GameObject::addGameObject<ProximityIndicator>(this, v279);
    if ( !this->isVrConnected )
    {
      v280 = (ProximityIndicator *)operator new(56);
      i = (int)v280;
      LOBYTE(v390) = -100;
      if ( v280 )
        ProximityIndicator::ProximityIndicator(v280, this);
      else
        v281 = 0;
      LOBYTE(v390) = 79;
      GameObject::addGameObject<ProximityIndicator>(this, v281);
    }
    v282 = (PitStop *)operator new(352);
    i = (int)v282;
    LOBYTE(v390) = -99;
    if ( v282 )
      PitStop::PitStop(v282, this);
    else
      v283 = 0;
    LOBYTE(v390) = 79;
    v284 = (PitStop *)GameObject::addGameObject<ProximityIndicator>(this, v283);
    *(_DWORD *)&useBlur[52] = 240;
    this->pitStop = v284;
    v285 = (DriverNameDisplayer *)operator new(*(_DWORD *)&useBlur[52]);
    i = (int)v285;
    LOBYTE(v390) = -98;
    if ( v285 )
      DriverNameDisplayer::DriverNameDisplayer(v285, (unsigned int)v225, this);
    else
      v286 = 0;
    LOBYTE(v390) = 79;
    v287 = (DriverNameDisplayer *)GameObject::addGameObject<ProximityIndicator>(this, v286);
    if ( this->isVrConnected )
      DriverNameDisplayer::setActive(v287, 0);
    v288 = (DamageDisplayer *)operator new(108);
    i = (int)v288;
    LOBYTE(v390) = -97;
    if ( v288 )
      DamageDisplayer::DamageDisplayer(v288, (Font *)v225, this);
    else
      v289 = 0;
    LOBYTE(v390) = 79;
    GameObject::addGameObject<ProximityIndicator>(this, v289);
    v290 = (FanatecUpdater *)operator new(120);
    i = (int)v290;
    LOBYTE(v390) = -96;
    if ( v290 )
    {
      v291 = (CarAvatar **)std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      FanatecUpdater::FanatecUpdater(v290, *v291);
      v293 = v292;
    }
    else
    {
      v293 = 0;
    }
    LOBYTE(v390) = 79;
    if ( FanatecUpdater::IsConnected((FanatecUpdater *)v293) )
    {
      GameObject::addGameObject<ProximityIndicator>(this, v293);
    }
    else if ( v293 )
    {
      ((void (*)(PitCrew *, int))v293->~GameObject)(v293, 1);
    }
    v294 = (DebugVisualizer *)operator new(220);
    i = (int)v294;
    LOBYTE(v390) = -95;
    if ( v294 )
      DebugVisualizer::DebugVisualizer(v294, this);
    else
      v295 = 0;
    LOBYTE(v390) = 79;
    v296 = (DebugVisualizer *)GameObject::addGameObject<ProximityIndicator>(this, v295);
    this->debugVisualizer = v296;
    *(_DWORD *)&useBlur[52] = 60;
    v296->isActive = 0;
    v297 = (DrivingAssistManager *)operator new(*(_DWORD *)&useBlur[52]);
    i = (int)v297;
    LOBYTE(v390) = -94;
    if ( v297 )
      DrivingAssistManager::DrivingAssistManager(v297, this);
    else
      v298 = 0;
    LOBYTE(v390) = 79;
    this->drivingAidsManager = (DrivingAssistManager *)GameObject::addGameObject<ProximityIndicator>(this, v298);
    Sim::initHDRLevels(this);
    *(_DWORD *)&useBlur[52] = 1065353216;
    *(_DWORD *)&useBlur[48] = 0;
    *(_DWORD *)&useBlur[44] = 0;
    *(_DWORD *)&useBlur[40] = &(*std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0))->timeToIgnore;
    std::wstring::wstring((std::wstring *)&useBlur[16], L"mirrorpos.x");
    Console::addVar(
      this->console,
      *(std::wstring *)&useBlur[16],
      *(float **)&useBlur[40],
      *(IVarCallback **)&useBlur[44],
      useBlur[48],
      *(float *)&useBlur[52]);
    *(_DWORD *)&useBlur[52] = 1065353216;
    *(_DWORD *)&useBlur[48] = 0;
    *(_DWORD *)&useBlur[44] = 0;
    *(_DWORD *)&useBlur[40] = &(*std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0))->timeToIgnoreBase;
    std::wstring::wstring((std::wstring *)&useBlur[16], L"mirrorpos.y");
    Console::addVar(
      this->console,
      *(std::wstring *)&useBlur[16],
      *(float **)&useBlur[40],
      *(IVarCallback **)&useBlur[44],
      useBlur[48],
      *(float *)&useBlur[52]);
    *(_DWORD *)&useBlur[52] = 1065353216;
    *(_DWORD *)&useBlur[48] = 0;
    *(_DWORD *)&useBlur[44] = 0;
    *(_DWORD *)&useBlur[40] = *std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0) + 1;
    std::wstring::wstring((std::wstring *)&useBlur[16], L"mirrorpos.z");
    Console::addVar(
      this->console,
      *(std::wstring *)&useBlur[16],
      *(float **)&useBlur[40],
      *(IVarCallback **)&useBlur[44],
      useBlur[48],
      *(float *)&useBlur[52]);
    v299 = this->sceneCamera;
    *(_DWORD *)&useBlur[52] = 1065353216;
    *(_DWORD *)&useBlur[48] = 0;
    *(_DWORD *)&useBlur[44] = 0;
    *(_DWORD *)&useBlur[40] = &v299->shadowBias;
    std::wstring::wstring((std::wstring *)&useBlur[16], L"shadowBias");
    Console::addVar(
      this->console,
      *(std::wstring *)&useBlur[16],
      *(float **)&useBlur[40],
      *(IVarCallback **)&useBlur[44],
      useBlur[48],
      *(float *)&useBlur[52]);
    std::wstring::wstring(&_Keyval, L"PROVIEW_MODE");
    LOBYTE(v390) = -93;
    this->useProView = *std::map<std::wstring,float>::operator[](&this->optionsManager.options, &_Keyval) != 0.0;
    LOBYTE(v390) = 79;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
    LOBYTE(v225) = !this->replayManager->hasLoadedReplay
                && (std::wstring::wstring(&_Keyval, L"DISABLE_SHOW_MODE"),
                    LOBYTE(v390) = -92,
                    LODWORD(v366) |= 0x100u,
                    v367 = v366,
                    *std::map<std::wstring,float>::operator[](&this->optionsManager.options, &_Keyval) == 0.0);
    v390 = 79;
    if ( (LOWORD(v366) & 0x100) != 0 )
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
    *(_DWORD *)&useBlur[52] = 0;
    if ( (_BYTE)v225 )
    {
      ACCameraManager::setMode(this->cameraManager, eStart, 0, useBlur[52]);
      ksgui::Control::setVisible(this->escMenu, 1);
    }
    else
    {
      ksgui::Control::setVisible(this->escMenu, *(BOOL *)&useBlur[52]);
      *(_DWORD *)&useBlur[52] = v300;
      RaceManager::startRace(this->raceManager, 20000.0);
      CameraOnBoardFree::setIntroMode(this->cameraManager->cameraOnBoardFree, 0);
    }
    v301 = std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
    v302 = std::operator+<wchar_t>((std::wstring *)&v375, L"content/cars/", (const std::wstring *)&(*v301)[1].color.y);
    LOBYTE(v390) = -91;
    v303 = std::operator+<wchar_t>(&s, v302, L"/data/escmode.ini");
    LOBYTE(v390) = -90;
    INIReader::INIReader(&ini, v303);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
    LOBYTE(v390) = -87;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v375);
    vec3f::vec3f((vec3f *)&section, 0.0, 1.4, 3.2);
    CameraOnBoardFree::setPosition(this->cameraManager->cameraOnBoardFree, v304);
    if ( ini.ready )
    {
      std::wstring::wstring(&v376, L"POSITION");
      LOBYTE(v390) = -86;
      std::wstring::wstring(&_Keyval, L"SETTINGS");
      LOBYTE(v390) = -85;
      v305 = INIReader::getFloat3(&ini, (vec3f *)&section, &_Keyval, &v376);
      CameraOnBoardFree::setPosition(this->cameraManager->cameraOnBoardFree, v305);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
      LOBYTE(v390) = -87;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v376);
      std::wstring::wstring(&v380, L"FOV");
      LOBYTE(v390) = -84;
      std::wstring::wstring(&_Keyval, L"SETTINGS");
      LOBYTE(v390) = -83;
      this->cameraManager->cameraOnBoardFree->fov = INIReader::getFloat(&ini, &_Keyval, &v380);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
      LOBYTE(v390) = -87;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v380);
    }
    *(_DWORD *)&useBlur[52] = this;
    CommandItem::CommandItem(
      (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&i,
      (CarAudioFMOD *)this);
    std::function<void __cdecl (OnNewSessionEvent const &)>::function<void __cdecl (OnNewSessionEvent const &)>(
      (std::function<void __cdecl(OnNewSessionEvent const &)> *)&useBlur[28],
      v306);
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)&this->evOnNewSession,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&useBlur[28],
      *(void **)&useBlur[52]);
    *(_DWORD *)&useBlur[52] = 1065353216;
    *(_DWORD *)&useBlur[48] = 0;
    CommandItem::CommandItem(
      (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&i,
      (CarAudioFMOD *)this);
    v367 = COERCE_FLOAT(&useBlur[24]);
    std::function<void __cdecl (SVar *,float)>::function<void __cdecl (SVar *,float)>(
      (std::function<void __cdecl(SVar *,float)> *)&useBlur[24],
      v307);
    LOBYTE(v390) = -82;
    std::wstring::wstring((std::wstring *)useBlur, L"hdrHPLevel");
    LOBYTE(v390) = -87;
    Console::addVarLambda(
      this->console,
      *(std::wstring *)useBlur,
      *(std::function<void __cdecl(SVar *,float)> *)&useBlur[24],
      useBlur[48],
      *(float *)&useBlur[52]);
    *(_DWORD *)&useBlur[52] = 1065353216;
    *(_DWORD *)&useBlur[48] = 0;
    CommandItem::CommandItem(
      (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&i,
      (CarAudioFMOD *)this);
    v367 = COERCE_FLOAT(&useBlur[24]);
    std::function<void __cdecl (SVar *,float)>::function<void __cdecl (SVar *,float)>(
      (std::function<void __cdecl(SVar *,float)> *)&useBlur[24],
      v308);
    LOBYTE(v390) = -81;
    std::wstring::wstring((std::wstring *)useBlur, L"hdrBloomLevel");
    LOBYTE(v390) = -87;
    Console::addVarLambda(
      this->console,
      *(std::wstring *)useBlur,
      *(std::function<void __cdecl(SVar *,float)> *)&useBlur[24],
      useBlur[48],
      *(float *)&useBlur[52]);
    *(_DWORD *)&useBlur[52] = 1065353216;
    *(_DWORD *)&useBlur[48] = 0;
    CommandItem::CommandItem(
      (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&i,
      (CarAudioFMOD *)this);
    v367 = COERCE_FLOAT(&useBlur[24]);
    std::function<void __cdecl (SVar *,float)>::function<void __cdecl (SVar *,float)>(
      (std::function<void __cdecl(SVar *,float)> *)&useBlur[24],
      v309);
    LOBYTE(v390) = -80;
    std::wstring::wstring((std::wstring *)useBlur, L"hdrBloomBaseLevel");
    LOBYTE(v390) = -87;
    Console::addVarLambda(
      this->console,
      *(std::wstring *)useBlur,
      *(std::function<void __cdecl(SVar *,float)> *)&useBlur[24],
      useBlur[48],
      *(float *)&useBlur[52]);
    v310 = 0;
    i = 0;
    do
    {
      *(_DWORD *)&useBlur[52] = 1065353216;
      *(_DWORD *)&useBlur[48] = 0;
      lambda_47b3546a3185b0ddbb338bc74e0bb1a1_::_lambda_47b3546a3185b0ddbb338bc74e0bb1a1_(
        (Sim::{ctor}::__l148::<lambda_47b3546a3185b0ddbb338bc74e0bb1a1> *)&section,
        this,
        &i);
      i = (int)&useBlur[24];
      std::function<void __cdecl (SVar *,float)>::function<void __cdecl (SVar *,float)>(
        (std::function<void __cdecl(SVar *,float)> *)&useBlur[24],
        v311);
      LOBYTE(v390) = -79;
      v312 = std::to_wstring(&v380, v310);
      LOBYTE(v390) = -78;
      std::operator+<wchar_t>((std::wstring *)useBlur, L"bodyDamageLevel", v312);
      LOBYTE(v390) = -77;
      Console::addVarLambda(
        this->console,
        *(std::wstring *)useBlur,
        *(std::function<void __cdecl(SVar *,float)> *)&useBlur[24],
        useBlur[48],
        *(float *)&useBlur[52]);
      LOBYTE(v390) = -87;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v380);
      i = ++v310;
    }
    while ( v310 < 5 );
    *(_DWORD *)&useBlur[52] = 1065353216;
    *(_DWORD *)&useBlur[48] = 0;
    CommandItem::CommandItem(
      (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&i,
      (CarAudioFMOD *)this);
    v367 = COERCE_FLOAT(&useBlur[24]);
    std::function<void __cdecl (SVar *,float)>::function<void __cdecl (SVar *,float)>(
      (std::function<void __cdecl(SVar *,float)> *)&useBlur[24],
      v313);
    LOBYTE(v390) = -76;
    std::wstring::wstring((std::wstring *)useBlur, L"engineDamageLevel");
    LOBYTE(v390) = -87;
    Console::addVarLambda(
      this->console,
      *(std::wstring *)useBlur,
      *(std::function<void __cdecl(SVar *,float)> *)&useBlur[24],
      useBlur[48],
      *(float *)&useBlur[52]);
    v314 = (EndSessionDisplayer *)operator new(192);
    i = (int)v314;
    LOBYTE(v390) = -75;
    if ( v314 )
      EndSessionDisplayer::EndSessionDisplayer(v314, (unsigned int)v225, this);
    else
      v315 = 0;
    LOBYTE(v390) = -87;
    this->endSessionDisplayer = (EndSessionDisplayer *)GameObject::addGameObject<ProximityIndicator>(this, v315);
    if ( (unsigned int)std::vector<CarAvatar *>::size(&this->cars) > 1
      && RaceManager::getCurrentSessionType(this->raceManager) != Drag )
    {
      v316 = (OverlayLeaderboard *)operator new(152);
      i = (int)v316;
      LOBYTE(v390) = -74;
      if ( v316 )
        OverlayLeaderboard::OverlayLeaderboard(v316, this);
      else
        v317 = 0;
      LOBYTE(v390) = -87;
      GameObject::addGameObject<ProximityIndicator>(this, v317);
    }
    v318 = (SteamInterface *)operator new(360);
    i = (int)v318;
    LOBYTE(v390) = -73;
    if ( v318 )
      SteamInterface::SteamInterface(v318, this);
    else
      v319 = 0;
    LOBYTE(v390) = -87;
    GameObject::addGameObject<ProximityIndicator>(this, v319);
    v320 = (FriendsLeaderboardDisplayer *)operator new(436);
    i = (int)v320;
    LOBYTE(v390) = -72;
    if ( v320 )
      FriendsLeaderboardDisplayer::FriendsLeaderboardDisplayer(v320, (unsigned int)v225, this);
    else
      v321 = 0;
    LOBYTE(v390) = -87;
    Sim::addForm(this, v321, v108);
    SystemMessage::loadDriversInfo(this->systemMessage);
    if ( this->replayManager->hasLoadedReplay )
    {
      CommandItem::CommandItem(
        (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&i,
        (CarAudioFMOD *)this);
      std::function<void __cdecl (void)>::function<void __cdecl (void)>(
        (std::function<void __cdecl(void)> *)&useBlur[32],
        v322);
      Sim::executeOnMainThread(this, *(std::function<void __cdecl(void)> *)&useBlur[32]);
    }
    GraphicsManager::getErrorStrings(this->game->graphics, &dxErrorStrings);
    LOBYTE(v390) = -71;
    if ( !std::vector<Turbo>::empty((std::vector<TyreCompoundDef> *)&dxErrorStrings) )
    {
      for ( j = 0; j < std::vector<std::wstring>::size(&dxErrorStrings); ++j )
      {
        i = (int)&useBlur[32];
        std::wstring::wstring((std::wstring *)&useBlur[32], L"\n");
        LOBYTE(v390) = -70;
        v324 = (const std::wstring *)std::vector<VisualDamageManager::GlassBreakablePart>::operator[](
                                       (std::vector<VisualDamageManager::GlassBreakablePart> *)&dxErrorStrings,
                                       j);
        v367 = COERCE_FLOAT(&useBlur[8]);
        std::wstring::wstring((std::wstring *)&useBlur[8], v324);
        LOBYTE(v390) = -69;
        v325 = Console::singleton();
        LOBYTE(v390) = -70;
        v326 = Console::operator<<(v325, *(std::wstring *)&useBlur[8]);
        LOBYTE(v390) = -71;
        Console::operator<<(v326, *(std::wstring *)&useBlur[32]);
      }
    }
    v327 = Path::getDocumentPath(&s);
    LOBYTE(v390) = -68;
    v328 = std::operator+<wchar_t>((std::wstring *)&v375, v327, L"/Assetto Corsa/cfg/acos.ini");
    LOBYTE(v390) = -67;
    LOBYTE(v225) = Path::fileExists((unsigned int)v225, v328, 0) == 0;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v375);
    LOBYTE(v390) = -71;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
    if ( (_BYTE)v225 )
    {
      v225 = (char *)result._Ptr;
      ksgui::Control::setVisible((ksgui::Control *)result._Ptr, 1);
      v329 = this->game->graphics;
      v330 = ksgui::ksRect::getHeight((ksgui::ksRect *)(v225 + 28));
      v331 = (float)v329->videoSettings.height;
      v332 = v329->videoSettings.width / 2;
      *(float *)&result._Ptr = v331;
      *(float *)&useBlur[52] = v331 - v330;
      *(float *)&result._Ptr = ksgui::ksRect::getWidth((ksgui::ksRect *)(v225 + 28));
      ksgui::Form::setPosition(
        (ksgui::Form *)v225,
        (float)v332 - (float)(*(float *)&result._Ptr * 0.5),
        *(float *)&useBlur[52]);
    }
    if ( (unsigned int)Sim::getCarsCount(this) > 1 || this->client )
    {
      *(float *)&v333 = COERCE_FLOAT(operator new(56));
      result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v333;
      LOBYTE(v390) = -66;
      if ( *(float *)&v333 == 0.0 )
        v334 = 0;
      else
        SessionLeaderboard::SessionLeaderboard(v333, this);
      LOBYTE(v390) = -71;
      v335 = (SessionLeaderboard *)GameObject::addGameObject<ProximityIndicator>(this, v334);
      *(_DWORD *)&useBlur[52] = 0;
      this->leaderboard = v335;
      Sim::displayLeaderboard(this, *(BOOL *)&useBlur[52]);
    }
    if ( this->mirrorTextureRenderer )
    {
      *(float *)&v336 = COERCE_FLOAT(operator new(76));
      result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v336;
      LOBYTE(v390) = -65;
      if ( *(float *)&v336 == 0.0 )
        v337 = 0;
      else
        VirtualMirrorRenderer::VirtualMirrorRenderer(v336, this);
      LOBYTE(v390) = -71;
      v338 = (VirtualMirrorRenderer *)GameObject::addGameObject<ProximityIndicator>(this, v337);
      v232 = !this->isVrConnected;
      this->virtualMirrorRenderer = v338;
      if ( !v232 )
        Node::setActive(v338->nodeVirtualMirror, 0);
    }
    PhysicsAvatar::startPhysics(this->physicsAvatar);
    this->serializeForms = 1;
    v339 = Path::getDocumentPath(&s);
    LOBYTE(v390) = -64;
    v340 = std::operator+<wchar_t>((std::wstring *)&v375, v339, L"/Assetto Corsa/cfg/video_editing.ini");
    LOBYTE(v390) = -63;
    v341 = Path::fileExists((unsigned int)v225, v340, 0) == 0;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v375);
    LOBYTE(v390) = -71;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
    if ( v341 )
    {
      _printf("UNLOADING MESH RESOURCES\n");
      Sim::unloadMeshResources(this, this->rootNode);
    }
    else
    {
      _printf("KEEPING MESH RESOURCES\n");
    }
    RenderWindow::setFocus(&this->game->window);
    *(float *)&v342 = COERCE_FLOAT(operator new(144));
    result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v342;
    LOBYTE(v390) = -62;
    if ( *(float *)&v342 == 0.0 )
      v343 = 0;
    else
      FlagManager::FlagManager(v342, this);
    LOBYTE(v390) = -71;
    GameObject::addGameObject<ProximityIndicator>(this, v343);
    *(float *)&v344 = COERCE_FLOAT(operator new(132));
    result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v344;
    LOBYTE(v390) = -61;
    if ( *(float *)&v344 == 0.0 )
      v345 = 0;
    else
      FuelLight::FuelLight(v344, this);
    LOBYTE(v390) = -71;
    GameObject::addGameObject<ProximityIndicator>(this, v345);
    v346 = Path::getDocumentPath(&s);
    LOBYTE(v390) = -60;
    v347 = std::operator+<wchar_t>((std::wstring *)&v375, v346, L"/Assetto Corsa/cfg/exposure.ini");
    LOBYTE(v390) = -59;
    INIReader::INIReader(&exp_ini, v347);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v375);
    LOBYTE(v390) = -56;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&s);
    if ( exp_ini.ready )
    {
      std::wstring::wstring(&_Keyval, L"VALUE");
      LOBYTE(v390) = -55;
      std::wstring::wstring(&v380, L"EXPOSURE");
      LOBYTE(v390) = -54;
      this->game->graphics->exposureMultiplier = INIReader::getFloat(&exp_ini, &v380, &_Keyval);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v380);
      LOBYTE(v390) = -56;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&_Keyval);
    }
    if ( PhysicsEngine::isTestMode )
      Sim::startGame(this);
    if ( Sim::benchmarkMode )
    {
      *(float *)&v348 = COERCE_FLOAT(operator new(136));
      result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v348;
      LOBYTE(v390) = -53;
      if ( *(float *)&v348 == 0.0 )
        v349 = 0;
      else
        BenchmarkMode::BenchmarkMode(v348, this);
      LOBYTE(v390) = -56;
      GameObject::addGameObject<ProximityIndicator>(this, v349);
    }
    if ( this->isVrConnected )
    {
      v350 = std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      v351 = std::vector<DigitalItem *>::operator[]((std::vector<DigitalItem *> *)&this->cars, 0);
      v352 = this->game;
      v353 = v351;
      v354 = *v350;
      *(_DWORD *)&useBlur[40] = this->sceneCamera;
      v355 = v352->graphics;
      v356 = *(_QWORD *)&v354[2].color.w;
      v357 = v354[2].color2.y;
      *(_QWORD *)&useBlur[44] = v356;
      *(float *)&useBlur[52] = v357;
      ksgui::GUI::init3DMode(
        v352->gui,
        v355->videoSettings.width,
        v355->videoSettings.height,
        (Node *)(*v353)[1].preFix._Mysize,
        *(Camera **)&useBlur[40],
        *(vec3f *)&useBlur[44]);
      *(float *)&v358 = COERCE_FLOAT(operator new(200));
      result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,Texture>,void *> *)v358;
      LOBYTE(v390) = -52;
      if ( *(float *)&v358 == 0.0 )
      {
        v360 = 0;
      }
      else
      {
        std::wstring::wstring((std::wstring *)&useBlur[32], L"3D_GUI_NODE");
        NodeEvent::NodeEvent(v358, *(std::wstring *)&useBlur[32]);
        v360 = v359;
      }
      v361 = this->unblurredNode;
      this->node3DGUI = v360;
      LOBYTE(v390) = -56;
      v361->addChild(v361, v360);
      *(_DWORD *)&useBlur[52] = this;
      CommandItem::CommandItem(
        (CarAudioFMOD::{ctor}::__l51::<lambda_d8094ee7e2dbdd4a9a921b54d17e0eee> *)&section,
        (CarAudioFMOD *)this);
      std::function<void __cdecl (OnNodeRenderEvent const &)>::function<void __cdecl (OnNodeRenderEvent const &)>(
        (std::function<void __cdecl(OnNodeRenderEvent const &)> *)&useBlur[28],
        v362);
      Event<std::wstring>::addHandler(
        (Event<OnPhysicsStepCompleted> *)&this->node3DGUI->evOnRender,
        *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&useBlur[28],
        *(void **)&useBlur[52]);
    }
    if ( PhysicsEngine::autoDrive || this->isRoomVR )
    {
      Sim::startGame(this);
      if ( this->isRoomVR )
        ksgui::GameScreen::showDesktop(this->gameScreen);
    }
    LOBYTE(v390) = -71;
    INIReader::~INIReader(&exp_ini);
    std::vector<std::wstring>::_Tidy(&dxErrorStrings);
    LOBYTE(v390) = 79;
    INIReader::~INIReader(&ini);
    LOBYTE(v390) = 72;
    INIReader::~INIReader(&audioIni);
    LOBYTE(v390) = 64;
    INIReader::~INIReader(&acPitstop);
    LOBYTE(v390) = 34;
    INIReader::~INIReader(&acIni);
  }
  else
  {
    this->game->shutdown(this->game);
  }
  LOBYTE(v390) = 20;
  INIReaderDocuments::~INIReaderDocuments(&gameplayINI);
  LOBYTE(v390) = 17;
  INIReaderDocuments::~INIReaderDocuments(&videoini);
  LOBYTE(v390) = 14;
  INIReader::~INIReader(&fadesINI);
  LOBYTE(v390) = 11;
  DebugTimer::~DebugTimer(&dtt);
}
void Sim::~Sim(Sim *this)
{
  bool v2; // zf
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  std::wostream *v5; // eax
  Game *v6; // eax
  unsigned int v7; // ecx
  std::wostream *v8; // eax
  int v9; // eax
  SkyBox *v10; // ecx
  Node *v11; // ecx
  CameraForward *v12; // ecx
  MirrorTextureRenderer *v13; // esi
  ACErrorHandler *v14; // ecx
  std::vector<CarAvatar *> *v15; // esi
  std::wstring v16; // [esp+0h] [ebp-114h] BYREF
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > > v17; // [esp+24h] [ebp-F0h] BYREF
  Sim *v18; // [esp+28h] [ebp-ECh]
  std::wofstream file; // [esp+2Ch] [ebp-E8h] BYREF
  std::wstring v20; // [esp+D4h] [ebp-40h] BYREF
  std::wstring result; // [esp+ECh] [ebp-28h] BYREF
  int v22; // [esp+110h] [ebp-4h]

  v18 = this;
  this->GameObject::__vftable = (Sim_vtbl *)&Sim::`vftable'{for `GameObject'};
  this->IKeyEventListener::__vftable = (IKeyEventListener_vtbl *)&Sim::`vftable'{for `IKeyEventListener'};
  v2 = !this->serializeForms;
  v22 = 11;
  if ( !v2 )
  {
    v16._Myres = 7;
    v16._Mysize = 0;
    v16._Bx._Buf[0] = 0;
    std::wstring::assign(&v16, L"Assetto Corsa", 0xDu);
    ksgui::GUI::serializeForms(this->game->gui, v16);
  }
  v3 = Path::getDocumentPath(&result);
  LOBYTE(v22) = 12;
  v4 = std::operator+<wchar_t>(&v20, v3, L"/Assetto Corsa/cfg/exposure.ini");
  LOBYTE(v22) = 13;
  std::wofstream::wofstream(&file, v4, 2, 64, 1);
  if ( v20._Myres >= 8 )
    operator delete(v20._Bx._Ptr);
  v20._Myres = 7;
  v20._Mysize = 0;
  v20._Bx._Buf[0] = 0;
  LOBYTE(v22) = 16;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  v16._Myres = (unsigned int)std::endl<wchar_t,std::char_traits<wchar_t>>;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  v5 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&file, "[EXPOSURE]");
  std::wostream::operator<<(v5);
  v6 = this->game;
  v16._Myres = (unsigned int)std::endl<wchar_t,std::char_traits<wchar_t>>;
  v16._Mysize = v7;
  v16._Mysize = LODWORD(v6->graphics->exposureMultiplier);
  v8 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&file, "VALUE=");
  v9 = std::wostream::operator<<(v8);
  std::wostream::operator<<(v9);
  if ( !std::wfilebuf::close((std::wfilebuf *)&file.gap0[4]) )
    std::wios::setstate((char *)&file + *(_DWORD *)(*(_DWORD *)file.gap0 + 4), 2, 0);
  v10 = this->skyBox;
  if ( v10 )
    ((void (*)(SkyBox *, int))v10->~SkyBox)(v10, 1);
  v11 = this->rootNode;
  if ( v11 )
    ((void (*)(Node *, int))v11->~Node)(v11, 1);
  v12 = this->sceneCamera;
  if ( v12 )
    ((void (*)(CameraForward *, int))v12->~Camera)(v12, 1);
  v13 = this->mirrorTextureRenderer;
  if ( v13 )
  {
    MirrorTextureRenderer::~MirrorTextureRenderer(this->mirrorTextureRenderer);
    operator delete(v13);
  }
  v14 = this->errorHandler;
  if ( v14 )
    ((void (*)(ACErrorHandler *, int))v14->~ACErrorHandler)(v14, 1);
  std::wofstream::~wofstream<wchar_t,std::char_traits<wchar_t>>((std::wofstream *)&file.gap58[8]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&file.gap58[8]);
  v16._Myres = (unsigned int)this->flagMapCache._Myhead;
  LOBYTE(v22) = 10;
  std::_Tree<std::_Tmap_traits<std::wstring,Texture,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,Texture>>,0>>::erase(
    &this->flagMapCache,
    &v17,
    *(std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > > *)v16._Myres,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > >)v16._Myres);
  operator delete(this->flagMapCache._Myhead);
  LOBYTE(v22) = 9;
  Concurrency::concurrent_queue<std::function<void __cdecl (void)>,std::allocator<std::function<void __cdecl (void)>>>::~concurrent_queue<std::function<void __cdecl (void)>,std::allocator<std::function<void __cdecl (void)>>>(&this->chFunctions.queue);
  LOBYTE(v22) = 8;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->changingCameraTrigger);
  v2 = this->cars._Myfirst == 0;
  v15 = &this->cars;
  LOBYTE(v22) = 7;
  if ( !v2 )
  {
    std::_Container_base0::_Orphan_all(&this->cars);
    operator delete(v15->_Myfirst);
    v15->_Myfirst = 0;
    this->cars._Mylast = 0;
    this->cars._Myend = 0;
  }
  LOBYTE(v22) = 6;
  OptionsManager::~OptionsManager(&this->optionsManager);
  LOBYTE(v22) = 5;
  std::map<std::wstring,AudioEngine::GUID>::~map<std::wstring,AudioEngine::GUID>((std::map<std::wstring,TyreCompoundStrategy> *)&this->commandManager);
  v2 = this->evOnNewSession.handlers._Myfirst == 0;
  LOBYTE(v22) = 4;
  if ( !v2 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnNewSession);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnNewSession,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnNewSession.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnNewSession.handlers._Mylast);
    operator delete(this->evOnNewSession.handlers._Myfirst);
    this->evOnNewSession.handlers._Myfirst = 0;
    this->evOnNewSession.handlers._Mylast = 0;
    this->evOnNewSession.handlers._Myend = 0;
  }
  v2 = this->evOnCollisionEvent.handlers._Myfirst == 0;
  LOBYTE(v22) = 3;
  if ( !v2 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnCollisionEvent);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnCollisionEvent,
      (Task *)this->evOnCollisionEvent.handlers._Myfirst,
      (Task *)this->evOnCollisionEvent.handlers._Mylast);
    operator delete(this->evOnCollisionEvent.handlers._Myfirst);
    this->evOnCollisionEvent.handlers._Myfirst = 0;
    this->evOnCollisionEvent.handlers._Mylast = 0;
    this->evOnCollisionEvent.handlers._Myend = 0;
  }
  v2 = this->evOnPauseModeChanged.handlers._Myfirst == 0;
  LOBYTE(v22) = 2;
  if ( !v2 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnPauseModeChanged);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnPauseModeChanged,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnPauseModeChanged.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnPauseModeChanged.handlers._Mylast);
    operator delete(this->evOnPauseModeChanged.handlers._Myfirst);
    this->evOnPauseModeChanged.handlers._Myfirst = 0;
    this->evOnPauseModeChanged.handlers._Mylast = 0;
    this->evOnPauseModeChanged.handlers._Myend = 0;
  }
  v2 = this->evOnReplayStatusChanged.handlers._Myfirst == 0;
  LOBYTE(v22) = 1;
  if ( !v2 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnReplayStatusChanged);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnReplayStatusChanged,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnReplayStatusChanged.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnReplayStatusChanged.handlers._Mylast);
    operator delete(this->evOnReplayStatusChanged.handlers._Myfirst);
    this->evOnReplayStatusChanged.handlers._Myfirst = 0;
    this->evOnReplayStatusChanged.handlers._Mylast = 0;
    this->evOnReplayStatusChanged.handlers._Myend = 0;
  }
  v2 = this->evNewCarLoaded.handlers._Myfirst == 0;
  LOBYTE(v22) = 0;
  if ( !v2 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evNewCarLoaded);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evNewCarLoaded,
      (Task *)this->evNewCarLoaded.handlers._Myfirst,
      (Task *)this->evNewCarLoaded.handlers._Mylast);
    operator delete(this->evNewCarLoaded.handlers._Myfirst);
    this->evNewCarLoaded.handlers._Myfirst = 0;
    this->evNewCarLoaded.handlers._Mylast = 0;
    this->evNewCarLoaded.handlers._Myend = 0;
  }
  v22 = -1;
  GameObject::~GameObject(this);
}
Sim *Sim::`scalar deleting destructor'(Sim *this, unsigned int a2)
{
  Sim::~Sim(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void Sim::activateEscMenu(Sim *this)
{
  ksgui::Control::setVisible(this->escMenu, 1);
  ksgui::Control::setVisible(this->pauseMenu, 0);
  ksgui::Control::setVisible(this->gameScreen, 0);
  ksgui::Control::setVisible(this->game->gui->taskbar, 0);
}
void Sim::activateGameGui(Sim *this)
{
  ksgui::Control::setVisible(this->escMenu, 0);
  ksgui::Control::setVisible(this->pauseMenu, 0);
  ksgui::Control::setVisible(this->gameScreen, 1);
  ksgui::Control::setVisible(this->game->gui->taskbar, 1);
}
void Sim::activatePauseMenu(Sim *this)
{
  ksgui::Control::setVisible(this->escMenu, 0);
  ksgui::Control::setVisible(this->pauseMenu, 1);
  ksgui::Control::setVisible(this->gameScreen, 0);
  ksgui::Control::setVisible(this->game->gui->taskbar, 0);
}
CarAvatar *__userpurge Sim::addCar@<eax>(Sim *this@<ecx>, __m128 a2@<xmm3>, __m128 a3@<xmm4>, const std::wstring *model, const std::wstring *config, const std::wstring *skin)
{
  CarAvatar *v7; // eax
  CarAvatar *v8; // eax
  CarAvatar *v9; // ebp
  int v10; // eax
  int v11; // eax
  std::pair<void *,std::function<void __cdecl(OnNewCarLoadedEvent const &)> > *v12; // esi
  std::_Func_base<void,OnNewCarLoadedEvent const &> **v13; // edi
  CarAvatar *ca; // [esp+14h] [ebp-30h] BYREF
  OnNewCarLoadedEvent message; // [esp+18h] [ebp-2Ch] BYREF
  std::wstring setName; // [esp+1Ch] [ebp-28h] BYREF
  int v18; // [esp+40h] [ebp-4h]

  v7 = (CarAvatar *)operator new(4232);
  ca = v7;
  v18 = 0;
  if ( v7 )
    CarAvatar::CarAvatar(v7, a2, a3, this, model, config, skin);
  else
    v8 = 0;
  ca = v8;
  v18 = -1;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->cars, (int *)&ca);
  setName._Myres = 7;
  setName._Mysize = 0;
  setName._Bx._Buf[0] = 0;
  std::wstring::assign(&setName, L"PIT", 3u);
  v9 = ca;
  v10 = this->cars._Mylast - this->cars._Myfirst - 1;
  v18 = 1;
  CarAvatar::setSpawnPositionIndex(ca, &setName, v10);
  v18 = -1;
  if ( setName._Myres >= 8 )
    operator delete(setName._Bx._Ptr);
  setName._Myres = 7;
  setName._Mysize = 0;
  setName._Bx._Buf[0] = 0;
  std::wstring::assign(&setName, L"START", 5u);
  v11 = this->cars._Mylast - this->cars._Myfirst - 1;
  v18 = 2;
  CarAvatar::setSpawnPositionIndex(v9, &setName, v11);
  v18 = -1;
  if ( setName._Myres >= 8 )
    operator delete(setName._Bx._Ptr);
  setName._Myres = 7;
  setName._Mysize = 0;
  setName._Bx._Buf[0] = 0;
  std::wstring::assign(&setName, L"PIT", 3u);
  v18 = 3;
  CarAvatar::goToSpawnPosition(v9, &setName);
  v18 = -1;
  if ( setName._Myres >= 8 )
    operator delete(setName._Bx._Ptr);
  ca = v9;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&ca);
  v9->parent = this;
  v12 = this->evNewCarLoaded.handlers._Myfirst;
  message.car = v9;
  if ( v12 != this->evNewCarLoaded.handlers._Mylast )
  {
    v13 = &v12->second._Impl;
    do
    {
      if ( !*v13 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x685A17);
      }
      (*v13)->_Do_call(*v13, &message);
      ++v12;
      v13 += 8;
    }
    while ( v12 != this->evNewCarLoaded.handlers._Mylast );
  }
  return v9;
}
void Sim::addForm(Sim *this, ksgui::Form *aForm, bool isInDevMode)
{
  if ( isInDevMode || !aForm->devApp )
  {
    this->gameScreen->addControl(this->gameScreen, aForm, 1);
  }
  else
  {
    this->gameScreen->addControl(this->gameScreen, aForm, 0);
    ksgui::Control::setVisible(aForm, 0);
  }
}
CarAvatar *Sim::addNetCar(Sim *this, ClientRemoteCarDef *desc, ACClient *client)
{
  Track *v4; // eax
  TrackAvatar *v5; // ecx
  const __m128i *v6; // eax
  CarAvatar *v7; // eax
  int v8; // eax
  int v9; // edi
  CarAvatar *v10; // eax
  CarAvatar *v11; // eax
  CarAvatar *v12; // ebp
  std::pair<void *,std::function<void __cdecl(OnNewCarLoadedEvent const &)> > *v13; // esi
  std::_Func_base<void,OnNewCarLoadedEvent const &> **v14; // edi
  unsigned int v16; // [esp-4h] [ebp-138h]
  CarAvatar *ca; // [esp+14h] [ebp-120h] BYREF
  OnNewCarLoadedEvent message; // [esp+18h] [ebp-11Ch] BYREF
  mat44f result; // [esp+1Ch] [ebp-118h] BYREF
  NetCarStateProviderDef def; // [esp+5Ch] [ebp-D8h] BYREF
  std::wstring setName; // [esp+10Ch] [ebp-28h] BYREF
  int v22; // [esp+130h] [ebp-4h]

  def.guid = 0;
  def.driverName._Myres = 7;
  def.driverName._Mysize = 0;
  def.driverName._Bx._Buf[0] = 0;
  def.team._Myres = 7;
  def.team._Mysize = 0;
  def.team._Bx._Buf[0] = 0;
  def.nationCode._Myres = 7;
  def.nationCode._Mysize = 0;
  def.nationCode._Bx._Buf[0] = 0;
  def.model._Myres = 7;
  def.model._Mysize = 0;
  def.model._Bx._Buf[0] = 0;
  mat44f::mat44f(&def.pitPosition);
  def.sessionID = desc->sessionID;
  v22 = 0;
  def.client = client;
  if ( &def.driverName != &desc->driverName )
    std::wstring::assign(&def.driverName, &desc->driverName, 0, 0xFFFFFFFF);
  if ( &def.team != &desc->team )
    std::wstring::assign(&def.team, &desc->team, 0, 0xFFFFFFFF);
  if ( &def.nationCode != &desc->nationCode )
    std::wstring::assign(&def.nationCode, &desc->nationCode, 0, 0xFFFFFFFF);
  if ( &def.model != (std::wstring *)desc )
    std::wstring::assign(&def.model, &desc->model, 0, 0xFFFFFFFF);
  v4 = &this->track->physicsTrack;
  setName._Myres = 7;
  def.rayCastProvider = v4;
  def.physicsAvatar = this->physicsAvatar;
  def.guid = this->cars._Mylast - this->cars._Myfirst;
  setName._Mysize = 0;
  setName._Bx._Buf[0] = 0;
  std::wstring::assign(&setName, L"PIT", 3u);
  v5 = this->track;
  v16 = desc->sessionID;
  LOBYTE(v22) = 1;
  v6 = (const __m128i *)TrackAvatar::getSpawnPosition(v5, &result, &setName, v16);
  LOBYTE(v22) = 0;
  *(__m128i *)&def.pitPosition.M11 = _mm_loadu_si128(v6);
  *(__m128i *)&def.pitPosition.M21 = _mm_loadu_si128(v6 + 1);
  *(__m128i *)&def.pitPosition.M31 = _mm_loadu_si128(v6 + 2);
  *(__m128i *)&def.pitPosition.M41 = _mm_loadu_si128(v6 + 3);
  if ( setName._Myres >= 8 )
    operator delete(setName._Bx._Ptr);
  v7 = (CarAvatar *)operator new(5224);
  ca = v7;
  LOBYTE(v22) = 2;
  if ( v7 )
  {
    NetCarStateProvider::NetCarStateProvider((NetCarStateProvider *)v7, &def);
    v9 = v8;
  }
  else
  {
    v9 = 0;
  }
  LOBYTE(v22) = 0;
  ca = (CarAvatar *)v9;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&ca);
  *(_DWORD *)(v9 + 36) = this;
  v10 = (CarAvatar *)operator new(4232);
  ca = v10;
  LOBYTE(v22) = 3;
  if ( v10 )
    CarAvatar::CarAvatar(v10, this, &desc->model, &desc->config, &desc->skin, (ICarPhysicsStateProvider *)(v9 + 52));
  else
    v11 = 0;
  LOBYTE(v22) = 0;
  ca = v11;
  NetCarStateProvider::setCarAvatar((NetCarStateProvider *)v9, v11);
  ACClient::addNetCar(client, (NetCarStateProvider *)v9);
  NetCarStateProvider::setDamageZoneLevel((NetCarStateProvider *)v9, desc->damageZoneLevel);
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->cars, (int *)&ca);
  v12 = ca;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&ca);
  v12->parent = this;
  v13 = this->evNewCarLoaded.handlers._Myfirst;
  message.car = v12;
  if ( v13 != this->evNewCarLoaded.handlers._Mylast )
  {
    v14 = &v13->second._Impl;
    do
    {
      if ( !*v14 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x685DC6);
      }
      (*v14)->_Do_call(*v14, &message);
      ++v13;
      v14 += 8;
    }
    while ( v13 != this->evNewCarLoaded.handlers._Mylast );
  }
  NetCarStateProviderDef::~NetCarStateProviderDef(&def);
  return v12;
}
void Sim::applyCustomWeather(Sim *this, const std::wstring *name)
{
  GameObject **v3; // esi
  WeatherManager *v4; // eax
  std::wstring *v5; // eax
  bool v6; // bl
  CarAvatar **v7; // eax
  CarAvatar **v8; // esi
  int v9; // edi
  unsigned int v10; // ebx
  char lights_on; // [esp+14h] [ebp-B8h]
  bool lights_ona; // [esp+14h] [ebp-B8h]
  std::wstring section; // [esp+18h] [ebp-B4h] BYREF
  std::wstring key; // [esp+30h] [ebp-9Ch] BYREF
  std::wstring result; // [esp+48h] [ebp-84h] BYREF
  std::wstring filename; // [esp+60h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+78h] [ebp-54h] BYREF
  int v18; // [esp+C8h] [ebp-4h]

  lights_on = 0;
  SkyBox::updateCloudsGeneration(this->sceneCamera->skyBox, name);
  v3 = this->gameObjects._Myfirst;
  if ( v3 == this->gameObjects._Mylast )
  {
LABEL_4:
    v4 = 0;
  }
  else
  {
    while ( 1 )
    {
      v4 = (WeatherManager *)__RTDynamicCast(
                               *v3,
                               0,
                               &GameObject `RTTI Type Descriptor',
                               &WeatherManager `RTTI Type Descriptor',
                               0);
      if ( v4 )
        break;
      if ( ++v3 == this->gameObjects._Mylast )
        goto LABEL_4;
    }
  }
  WeatherManager::applyCustomWeather(v4, name);
  v5 = std::operator+<wchar_t>(&result, L"content/weather/", name);
  v18 = 0;
  std::operator+<wchar_t>(&filename, v5, L"/weather.ini");
  LOBYTE(v18) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  INIReader::INIReader(&ini, &filename);
  LOBYTE(v18) = 3;
  v6 = 0;
  if ( ini.ready )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CAR_LIGHTS", 0xAu);
    LOBYTE(v18) = 4;
    lights_on = 1;
    if ( INIReader::hasSection(&ini, &section) )
      v6 = 1;
  }
  v18 = 3;
  if ( (lights_on & 1) != 0 && section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( v6 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"FORCE_ON", 8u);
    LOBYTE(v18) = 5;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CAR_LIGHTS", 0xAu);
    LOBYTE(v18) = 6;
    lights_ona = INIReader::getInt(&ini, &section, &key) != 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v18) = 3;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v7 = this->cars._Mylast;
    v8 = this->cars._Myfirst;
    v9 = 0;
    v10 = (unsigned int)((char *)v7 - (char *)v8 + 3) >> 2;
    if ( v8 > v7 )
      v10 = 0;
    if ( v10 )
    {
      do
      {
        CarAvatar::setHeadlights(*v8, lights_ona);
        ++v9;
        ++v8;
      }
      while ( v9 != v10 );
    }
  }
  LOBYTE(v18) = 2;
  INIReader::~INIReader(&ini);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
StereoCameraForward *Sim::createCamera(Sim *this, INIReaderDocuments *videoIni, float useBlur)
{
  unsigned int v4; // ebx
  int v5; // ebp
  ICollisionObject *v6; // edi
  Game *v7; // eax
  StereoCameraForward *v8; // eax
  StereoCameraForward *v9; // edi
  ICollisionObject *v10; // eax
  ICollisionObject *v11; // eax
  ICollisionObject *v12; // ebx
  Event<float> *v13; // ecx
  ICollisionObject *v14; // edi
  Game *v15; // eax
  StereoCameraForward *v16; // eax
  ICollisionObject *v17; // eax
  ICollisionObject *v18; // eax
  ICollisionObject *v19; // ebx
  Event<float> *v20; // ecx
  CameraForwardYebis *v21; // edi
  Game *v22; // eax
  Game *v23; // eax
  StereoCameraForward *v24; // eax
  PostProcessEffectsUpdater *v25; // eax
  PostProcessEffectsUpdater *v26; // eax
  PostProcessEffectsUpdater *v27; // ebx
  CameraForward *v28; // edi
  Game *v29; // eax
  Game *v30; // eax
  StereoCameraForward *v31; // eax
  bool v32; // zf
  CameraTripleScreen *v33; // edi
  Game *v34; // eax
  StereoCameraForward *v35; // eax
  PostProcessEffectsUpdater *v36; // eax
  PostProcessEffectsUpdater *v37; // eax
  CameraForward *v38; // edi
  Game *v39; // eax
  Game *v40; // eax
  StereoCameraForward *v41; // eax
  _BYTE v43[56]; // [esp-1Ch] [ebp-114h] BYREF
  ICollisionObject *_Val; // [esp+1Ch] [ebp-DCh] BYREF
  bool v45; // [esp+23h] [ebp-D5h]
  void *v46; // [esp+24h] [ebp-D4h]
  int v47; // [esp+28h] [ebp-D0h]
  std::wstring iname; // [esp+2Ch] [ebp-CCh] BYREF
  std::wstring v49; // [esp+44h] [ebp-B4h] BYREF
  std::wstring cameraMode; // [esp+5Ch] [ebp-9Ch] BYREF
  std::wstring key; // [esp+74h] [ebp-84h] BYREF
  std::wstring section; // [esp+8Ch] [ebp-6Ch] BYREF
  INIReaderDocuments raceIni; // [esp+A4h] [ebp-54h] BYREF
  int v54; // [esp+F4h] [ebp-4h]

  v4 = 0;
  v47 = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"MODE", 4u);
  v54 = 0;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"CAMERA", 6u);
  LOBYTE(v54) = 1;
  INIReader::getString(videoIni, &cameraMode, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v54) = 4;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  *(_DWORD *)&v43[24] = 0;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  *(_DWORD *)&v43[20] = 7;
  *(_DWORD *)&v43[16] = 0;
  *(_WORD *)v43 = 0;
  std::wstring::assign((std::wstring *)v43, L"cfg/race.ini", 0xCu);
  INIReaderDocuments::INIReaderDocuments(&raceIni, 0, *(std::wstring *)v43, v43[24]);
  LOBYTE(v54) = 5;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"CARS", 4u);
  LOBYTE(v54) = 6;
  v49._Myres = 7;
  v49._Mysize = 0;
  v49._Bx._Buf[0] = 0;
  std::wstring::assign(&v49, L"RACE", 4u);
  LOBYTE(v54) = 7;
  v5 = INIReader::getInt(&raceIni, &v49, &iname);
  if ( v49._Myres >= 8 )
    operator delete(v49._Bx._Ptr);
  v49._Myres = 7;
  v49._Mysize = 0;
  v49._Bx._Buf[0] = 0;
  LOBYTE(v54) = 5;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"ENABLED", 7u);
  LOBYTE(v54) = 8;
  v49._Myres = 7;
  v49._Mysize = 0;
  v49._Bx._Buf[0] = 0;
  std::wstring::assign(&v49, L"POST_PROCESS", 0xCu);
  LOBYTE(v54) = 9;
  v45 = INIReader::getInt(videoIni, &v49, &iname) != 0;
  if ( v49._Myres >= 8 )
    operator delete(v49._Bx._Ptr);
  v49._Myres = 7;
  v49._Mysize = 0;
  v49._Bx._Buf[0] = 0;
  LOBYTE(v54) = 5;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  if ( !std::wstring::compare(&cameraMode, 0, cameraMode._Mysize, L"OCULUS", 6u) )
  {
    if ( StereoCameraForward::initOculus(v5) )
    {
      v6 = (ICollisionObject *)operator new(2272);
      _Val = v6;
      LOBYTE(v54) = 10;
      if ( v6 )
      {
        std::wstring::wstring(&iname, L"MAIN_CAMERA");
        v7 = this->game;
        v4 = 1;
        *(_DWORD *)&v43[24] = 1;
        *(_DWORD *)&v43[20] = 0;
        LOBYTE(v54) = 11;
        *(_DWORD *)&v43[16] = v7->graphics;
        v47 = 1;
        StereoCameraForward::StereoCameraForward(
          (StereoCameraForward *)v6,
          1u,
          v5,
          &iname,
          *(GraphicsManager **)&v43[16],
          0,
          1);
        v9 = v8;
      }
      else
      {
        v9 = 0;
      }
      v54 = 5;
      if ( (v4 & 1) != 0 )
      {
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        iname._Myres = 7;
        iname._Mysize = 0;
        iname._Bx._Buf[0] = 0;
      }
      v10 = (ICollisionObject *)operator new(96);
      _Val = v10;
      LOBYTE(v54) = 13;
      if ( v10 )
      {
        OculusManager::OculusManager((OculusManager *)v10, v4, this, v9);
        v12 = v11;
      }
      else
      {
        v12 = 0;
      }
      LOBYTE(v54) = 5;
      _Val = v12;
      std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &_Val);
      *(_DWORD *)&v43[24] = this;
      v12[9].__vftable = (ICollisionObject_vtbl *)this;
      *(_DWORD *)v43 = &std::_Func_impl<std::_Callable_obj<_lambda_bc6fa735863c7edf25f2f5af6cfe4c4c_,0>,std::allocator<std::_Func_class<void,float const &>>,void,float const &>::`vftable';
      *(_DWORD *)&v43[4] = v9;
      *(_DWORD *)&v43[16] = v43;
      v13 = &this->game->evOnRenderFinished;
      LOBYTE(v54) = 5;
      Event<float>::addHandler(
        (Event<SessionInfo> *)v13,
        *(std::function<void __cdecl(SessionInfo const &)> *)v43,
        *(void **)&v43[24]);
      this->isVrConnected = 1;
      goto LABEL_83;
    }
    std::wstring::assign(&cameraMode, L"DEFAULT", 7u);
  }
  if ( !std::wstring::compare(&cameraMode, 0, cameraMode._Mysize, L"OPENVR", 6u) )
  {
    if ( StereoCameraVive::initOpenVR() )
    {
      v14 = (ICollisionObject *)operator new(4808);
      _Val = v14;
      LOBYTE(v54) = 15;
      if ( v14 )
      {
        std::wstring::wstring(&iname, L"MAIN_CAMERA");
        LOBYTE(v4) = 2;
        *(_DWORD *)&v43[24] = this->isRoomVR;
        v15 = this->game;
        LOBYTE(v54) = 16;
        v47 = 2;
        StereoCameraVive::StereoCameraVive((StereoCameraVive *)v14, 2u, &iname, v15->graphics, 0, v43[24]);
        v9 = v16;
      }
      else
      {
        v9 = 0;
      }
      v54 = 5;
      if ( (v4 & 2) != 0 )
      {
        if ( iname._Myres >= 8 )
          operator delete(iname._Bx._Ptr);
        iname._Myres = 7;
        iname._Mysize = 0;
        iname._Bx._Buf[0] = 0;
      }
      v17 = (ICollisionObject *)operator new(96);
      _Val = v17;
      LOBYTE(v54) = 18;
      if ( v17 )
      {
        ViveManager::ViveManager((ViveManager *)v17, this, (StereoCameraVive *)v9);
        v19 = v18;
      }
      else
      {
        v19 = 0;
      }
      LOBYTE(v54) = 5;
      _Val = v19;
      std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &_Val);
      *(_DWORD *)&v43[24] = this;
      v19[9].__vftable = (ICollisionObject_vtbl *)this;
      *(_DWORD *)v43 = &std::_Func_impl<std::_Callable_obj<_lambda_52ee50730b424552787d4133d4b7f69c_,0>,std::allocator<std::_Func_class<void,float const &>>,void,float const &>::`vftable';
      *(_DWORD *)&v43[4] = v9;
      *(_DWORD *)&v43[16] = v43;
      v20 = &this->game->evOnRenderFinished;
      LOBYTE(v54) = 5;
      Event<float>::addHandler(
        (Event<SessionInfo> *)v20,
        *(std::function<void __cdecl(SessionInfo const &)> *)v43,
        *(void **)&v43[24]);
      this->isVrConnected = 1;
      goto LABEL_83;
    }
    std::wstring::assign(&cameraMode, L"DEFAULT", 7u);
  }
  if ( !std::wstring::compare(&cameraMode, 0, cameraMode._Mysize, L"DEFAULT", 7u) )
  {
    if ( v45 )
    {
      _printf("CREATING YEBIS CAMERA\n");
      v21 = (CameraForwardYebis *)operator new(3384);
      v46 = v21;
      LOBYTE(v54) = 20;
      if ( v21 )
      {
        if ( useBlur <= 0.0 || (v22 = this->game, LOBYTE(_Val) = 1, !v22->graphics->videoSettings.ppHDREnabled) )
          LOBYTE(_Val) = 0;
        std::wstring::wstring(&iname, L"MAIN_CAMERA_YEBIS");
        v23 = this->game;
        LOBYTE(v4) = 4;
        *(_DWORD *)&v43[24] = v5;
        *(_DWORD *)&v43[20] = 0;
        *(_DWORD *)&v43[16] = _Val;
        LOBYTE(v54) = 21;
        *(_DWORD *)&v43[12] = v23->graphics;
        v47 = 4;
        CameraForwardYebis::CameraForwardYebis(v21, 4u, &iname, *(GraphicsManager **)&v43[12], (bool)_Val, 0, v5);
        v9 = v24;
      }
      else
      {
        v9 = 0;
      }
      v54 = 5;
      if ( (v4 & 4) != 0 )
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
      v25 = (PostProcessEffectsUpdater *)operator new(84);
      v46 = v25;
      LOBYTE(v54) = 23;
      if ( v25 )
      {
        PostProcessEffectsUpdater::PostProcessEffectsUpdater(v25, this, (CameraForwardYebis *)v9);
        v27 = v26;
      }
      else
      {
        v27 = 0;
      }
      LOBYTE(v54) = 5;
      *(_DWORD *)&v43[24] = 7;
      *(_DWORD *)&v43[20] = 0;
      *(_WORD *)&v43[4] = 0;
      std::wstring::assign((std::wstring *)&v43[4], &v27->defaultFilter, 0, 0xFFFFFFFF);
      PostProcessEffectsUpdater::loadConfigurationFile(v27, *(std::wstring *)&v43[4]);
      goto LABEL_73;
    }
    _printf("CREATING CAMERA FORWARD\n");
    v28 = (CameraForward *)operator new(1672);
    v46 = v28;
    LOBYTE(v54) = 24;
    if ( v28 )
    {
      if ( useBlur <= 0.0 || (v29 = this->game, LOBYTE(_Val) = 1, !v29->graphics->videoSettings.ppHDREnabled) )
        LOBYTE(_Val) = 0;
      std::wstring::wstring(&iname, L"MAIN_CAMERA");
      v30 = this->game;
      LOBYTE(v4) = 8;
      LOBYTE(v54) = 25;
      v47 = 8;
      CameraForward::CameraForward(v28, &iname, v30->graphics, (bool)_Val);
      v9 = v31;
    }
    else
    {
      v9 = 0;
    }
    v32 = (v4 & 8) == 0;
    goto LABEL_81;
  }
  if ( std::wstring::compare(&cameraMode, 0, cameraMode._Mysize, L"TRIPLE", 6u) )
  {
    _printf("RETURING A NORMAL CAMERA BY DEFAULT\n");
    v38 = (CameraForward *)operator new(1672);
    v46 = v38;
    LOBYTE(v54) = 31;
    if ( v38 )
    {
      if ( useBlur <= 0.0 || (v39 = this->game, LOBYTE(_Val) = 1, !v39->graphics->videoSettings.ppHDREnabled) )
        LOBYTE(_Val) = 0;
      std::wstring::wstring(&iname, L"MAIN_CAMERA");
      v40 = this->game;
      LOBYTE(v4) = 32;
      LOBYTE(v54) = 32;
      v47 = 32;
      CameraForward::CameraForward(v38, &iname, v40->graphics, (bool)_Val);
      v9 = v41;
    }
    else
    {
      v9 = 0;
    }
    v32 = (v4 & 0x20) == 0;
LABEL_81:
    v54 = 5;
    if ( !v32 )
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
    goto LABEL_83;
  }
  *(_DWORD *)&v43[24] = 3956;
  this->tripleScreenMode = 1;
  v33 = (CameraTripleScreen *)operator new(*(_DWORD *)&v43[24]);
  v46 = v33;
  LOBYTE(v54) = 27;
  if ( v33 )
  {
    std::wstring::wstring(&iname, L"MAIN_CAMERA_YEBIS");
    v34 = this->game;
    LOBYTE(v4) = 16;
    LOBYTE(v54) = 28;
    v47 = 16;
    CameraTripleScreen::CameraTripleScreen(v33, &iname, v34->graphics, v5);
    v9 = v35;
  }
  else
  {
    v9 = 0;
  }
  v54 = 5;
  if ( (v4 & 0x10) != 0 )
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&iname);
  if ( v45 )
  {
    v36 = (PostProcessEffectsUpdater *)operator new(84);
    v46 = v36;
    LOBYTE(v54) = 30;
    if ( v36 )
    {
      PostProcessEffectsUpdater::PostProcessEffectsUpdater(v36, this, (CameraForwardYebis *)v9);
      v27 = v37;
    }
    else
    {
      v27 = 0;
    }
    LOBYTE(v54) = 5;
    PostProcessEffectsUpdater::loadDefaultConfiguration(v27);
LABEL_73:
    _Val = (ICollisionObject *)v27;
    std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &_Val);
    v27->parent = this;
  }
LABEL_83:
  LOBYTE(v54) = 4;
  INIReaderDocuments::~INIReaderDocuments(&raceIni);
  if ( cameraMode._Myres >= 8 )
    operator delete(cameraMode._Bx._Ptr);
  return v9;
}
void Sim::executeOnMainThread(Sim *this, std::function<void __cdecl(void)> f)
{
  Concurrency::details::_Concurrent_queue_base_v4::_Internal_push(&this->chFunctions.queue, &f);
  if ( f._Impl )
    ((void (__stdcall *)(bool))f._Impl->_Delete_this)(f._Impl != (std::_Func_base<void> *)&f);
}
CarAvatar *Sim::getCar(Sim *this, unsigned int index)
{
  CarAvatar *result; // eax

  if ( index >= this->cars._Mylast - this->cars._Myfirst )
    result = 0;
  else
    result = this->cars._Myfirst[index];
  return result;
}
Console *Sim::getConsole(Sim *this)
{
  return this->console;
}
unsigned int Sim::getFocusedCarIndex(Sim *this)
{
  return this->focusedCarIndex;
}
Texture *Sim::getNationFlag(Sim *this, const std::wstring *nationCode)
{
  Texture *v3; // esi
  std::map<std::wstring,Texture> *v4; // esi
  std::wstring *v6; // eax
  const std::wstring *v7; // eax
  Game *v8; // ecx
  Texture *v9; // ebx
  Texture *v10; // eax
  void *v11; // ecx
  const std::wstring *v12; // ebx
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,Texture> > > > result; // [esp+10h] [ebp-78h] BYREF
  std::wstring _Keyval; // [esp+14h] [ebp-74h] BYREF
  std::wstring v15; // [esp+2Ch] [ebp-5Ch] BYREF
  std::wstring v16; // [esp+44h] [ebp-44h] BYREF
  Texture v17; // [esp+5Ch] [ebp-2Ch] BYREF
  int v18; // [esp+84h] [ebp-4h]

  if ( !nationCode->_Mysize )
  {
    _Keyval._Myres = 7;
    _Keyval._Mysize = 0;
    _Keyval._Bx._Buf[0] = 0;
    std::wstring::assign(&_Keyval, L"AC", 2u);
    v18 = 0;
    v3 = std::map<std::wstring,Texture>::operator[](&this->flagMapCache, &_Keyval);
    if ( _Keyval._Myres >= 8 )
      operator delete(_Keyval._Bx._Ptr);
    return v3;
  }
  v4 = &this->flagMapCache;
  std::_Tree<std::_Tmap_traits<std::wstring,CBuffer *,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,CBuffer *>>,0>>::find(
    (std::_Tree<std::_Tmap_traits<std::wstring,enum DynamicControllerInput,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,enum DynamicControllerInput> >,0> > *)&this->flagMapCache,
    (std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,enum DynamicControllerInput> > > > *)&result,
    nationCode);
  if ( result._Ptr != v4->_Myhead )
    return &result._Ptr->_Myval.second;
  v6 = std::operator+<wchar_t>(&v15, L"content/gui/NationFlags/", nationCode);
  v18 = 1;
  v7 = std::operator+<wchar_t>(&_Keyval, v6, L".png");
  v8 = this->game;
  LOBYTE(v18) = 2;
  v9 = ResourceStore::getTexture(v8->graphics->resourceStore._Myptr, &v17, v7, 0);
  OnSetupAppCreated::~OnSetupAppCreated(&v17);
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  v18 = -1;
  if ( v15._Myres >= 8 )
    operator delete(v15._Bx._Ptr);
  v15._Myres = 7;
  v15._Mysize = 0;
  v15._Bx._Buf[0] = 0;
  if ( !v9->kid )
  {
    std::wstring::wstring(&v16, L"AC");
    v18 = 3;
    v3 = std::map<std::wstring,Texture>::operator[](v4, &v16);
    if ( v16._Myres >= 8 )
      operator delete(v16._Bx._Ptr);
    return v3;
  }
  v10 = std::map<std::wstring,Texture>::operator[](v4, nationCode);
  v11 = v9->kid;
  v12 = &v9->fileName;
  v10->kid = v11;
  if ( &v10->fileName != v12 )
    std::wstring::assign(&v10->fileName, v12, 0, 0xFFFFFFFF);
  return std::map<std::wstring,Texture>::operator[](v4, nationCode);
}
CameraForward *Sim::getSceneCamera(Sim *this)
{
  return this->sceneCamera;
}
TrackData *Sim::getTrackData(Sim *this, TrackData *result)
{
  std::wstring *v3; // esi
  TrackData *v4; // eax
  std::wstring *v5; // ebx
  TrackAvatar *v6; // ecx
  int v7; // eax
  bool v8; // cf
  std::wstring setName; // [esp+1Ch] [ebp-28h] BYREF
  int v11; // [esp+40h] [ebp-4h]

  v3 = &result->configuration;
  result->name._Myres = 7;
  result->name._Mysize = 0;
  result->name._Bx._Buf[0] = 0;
  result->configuration._Myres = 7;
  result->configuration._Mysize = 0;
  result->configuration._Bx._Buf[0] = 0;
  v11 = 0;
  v4 = (TrackData *)&this->track->name;
  if ( result != v4 )
    std::wstring::assign(&result->name, &v4->name, 0, 0xFFFFFFFF);
  v5 = TrackAvatar::getConfig(this->track, &setName);
  if ( v3 != v5 )
  {
    if ( result->configuration._Myres >= 8 )
      operator delete(v3->_Bx._Ptr);
    result->configuration._Myres = 7;
    result->configuration._Mysize = 0;
    v3->_Bx._Buf[0] = 0;
    std::wstring::_Assign_rv(v3, v5);
  }
  if ( setName._Myres >= 8 )
    operator delete(setName._Bx._Ptr);
  setName._Myres = 7;
  setName._Mysize = 0;
  setName._Bx._Buf[0] = 0;
  std::wstring::assign(&setName, L"START", 5u);
  v6 = this->track;
  v11 = 1;
  v7 = TrackAvatar::getMaxSlotsAvailable(v6, &setName);
  v8 = setName._Myres < 8;
  result->gridPlaces = v7;
  if ( !v8 )
    operator delete(setName._Bx._Ptr);
  return result;
}
void Sim::initCubemaps(Sim *this)
{
  unsigned int v2; // ebx
  int v3; // esi
  CameraForward *v4; // eax
  Event<int> *v5; // ecx
  Event<int> *v6; // ecx
  std::wstring v7; // [esp-14h] [ebp-BCh] BYREF
  float v8; // [esp+4h] [ebp-A4h]
  float farp; // [esp+20h] [ebp-88h]
  std::wstring section; // [esp+24h] [ebp-84h] BYREF
  std::wstring key; // [esp+3Ch] [ebp-6Ch] BYREF
  INIReaderDocuments r; // [esp+54h] [ebp-54h] BYREF
  int v13; // [esp+A4h] [ebp-4h]

  v8 = 0.0;
  v2 = 512;
  v7._Myres = 7;
  v7._Mysize = 0;
  v7._Bx._Buf[0] = 0;
  std::wstring::assign(&v7, L"cfg/video.ini", 0xDu);
  INIReaderDocuments::INIReaderDocuments(&r, 0x200u, v7, SLOBYTE(v8));
  v13 = 0;
  if ( r.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SIZE", 4u);
    LOBYTE(v13) = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CUBEMAP", 7u);
    LOBYTE(v13) = 2;
    v2 = INIReader::getInt(&r, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v13) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"FACES_PER_FRAME", 0xFu);
    LOBYTE(v13) = 3;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CUBEMAP", 7u);
    LOBYTE(v13) = 4;
    v3 = INIReader::getInt(&r, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v13) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v3 <= 6 )
    {
      if ( v3 < 0 )
        v3 = 0;
    }
    else
    {
      v3 = 6;
    }
    v4 = this->sceneCamera;
    LODWORD(v8) = 8;
    v7._Myres = (unsigned int)L"FARPLANE";
    key._Myres = 7;
    v4->cubeMapRenderer.facesPerFrame = v3;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, (const wchar_t *)v7._Myres, LODWORD(v8));
    LOBYTE(v13) = 5;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CUBEMAP", 7u);
    LOBYTE(v13) = 6;
    farp = INIReader::getFloat(&r, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v13) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( farp != 0.0 )
      CubeMapRenderer::setCameraNearFarPlanes(&this->sceneCamera->cubeMapRenderer, 0.0099999998, farp);
    LODWORD(v8) = this;
    v7._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_3cd36707c912741a6dd403569aa5ef51_,0>,std::allocator<std::_Func_class<void,int const &>>,void,int const &>::`vftable';
    *(_DWORD *)&v7._Bx._Alias[4] = this;
    v7._Mysize = (unsigned int)&v7;
    v5 = &this->sceneCamera->cubeMapRenderer.evOnRenderBegin;
    LOBYTE(v13) = 0;
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)v5,
      (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v7,
      this);
    LODWORD(v8) = this;
    v7._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_f8b9d0f8b0fe612572c0d95c92a874de_,0>,std::allocator<std::_Func_class<void,int const &>>,void,int const &>::`vftable';
    *(_DWORD *)&v7._Bx._Alias[4] = this;
    v7._Mysize = (unsigned int)&v7;
    v6 = &this->sceneCamera->cubeMapRenderer.evOnRenderEnd;
    LOBYTE(v13) = 0;
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)v6,
      (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v7,
      this);
  }
  CameraForward::setCubemapSize(this->sceneCamera, v2);
  v13 = -1;
  INIReaderDocuments::~INIReaderDocuments(&r);
}
void Sim::initHDRLevels(Sim *this)
{
  double v2; // st7
  bool v3; // cf
  double v4; // st7
  std::wstring v5; // [esp-24h] [ebp-D0h] BYREF
  HDRLevels *v6; // [esp-Ch] [ebp-B8h]
  IVarCallback *v7; // [esp-8h] [ebp-B4h]
  BOOL v8; // [esp-4h] [ebp-B0h]
  float multiplier; // [esp+0h] [ebp-ACh]
  std::wstring section; // [esp+10h] [ebp-9Ch] BYREF
  std::wstring key; // [esp+28h] [ebp-84h] BYREF
  std::wstring ifilename; // [esp+40h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+58h] [ebp-54h] BYREF
  int v14; // [esp+A8h] [ebp-4h]

  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/lighting.ini", 0x17u);
  v14 = 0;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v14) = 2;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MIN_EXPOSURE", 0xCu);
    LOBYTE(v14) = 3;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HDR", 3u);
    LOBYTE(v14) = 4;
    v2 = INIReader::getFloat(&ini, &section, &key);
    v3 = section._Myres < 8;
    this->hdrLevels.minExposure = v2;
    if ( !v3 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v14) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MAX_EXPOSURE", 0xCu);
    LOBYTE(v14) = 5;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HDR", 3u);
    LOBYTE(v14) = 6;
    v4 = INIReader::getFloat(&ini, &section, &key);
    v3 = section._Myres < 8;
    this->hdrLevels.maxExposure = v4;
    if ( !v3 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v14) = 2;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  multiplier = 1.0;
  v8 = 0;
  v7 = 0;
  v6 = &this->hdrLevels;
  v5._Myres = 7;
  v5._Mysize = 0;
  v5._Bx._Buf[0] = 0;
  std::wstring::assign(&v5, L"minExposure", 0xBu);
  Console::addVar(this->console, v5, &v6->minExposure, v7, v8, multiplier);
  v14 = -1;
  INIReader::~INIReader(&ini);
}
void Sim::initSceneGraph(Sim *this)
{
  int v2; // ebx
  Node *v3; // edi
  Node *v4; // eax
  Node *v5; // edi
  Node *v6; // eax
  Node *v7; // edi
  Node *v8; // eax
  Node *v9; // edi
  Node *v10; // eax
  Node *v11; // edi
  Node *v12; // eax
  NodeEvent *v13; // edi
  NodeEvent *v14; // eax
  NodeEvent *v15; // edx
  Node *v16; // ecx
  CarNodeSorter *v17; // edi
  CarNodeSorter *v18; // eax
  NodeEvent *v19; // edi
  NodeEvent *v20; // eax
  Node *v21; // ecx
  Node *v22; // edi
  Node *v23; // eax
  NodeEvent *v24; // edi
  NodeEvent *v25; // eax
  NodeEvent *v26; // edx
  Node *v27; // ecx
  std::wstring v28; // [esp-Ch] [ebp-58h] BYREF
  int v29; // [esp+1Ch] [ebp-30h]
  void *v30; // [esp+20h] [ebp-2Ch]
  std::wstring n; // [esp+24h] [ebp-28h] BYREF
  int v32; // [esp+48h] [ebp-4h]

  v2 = 0;
  v29 = 0;
  v3 = (Node *)operator new(188);
  v4 = 0;
  v32 = 0;
  if ( v3 )
  {
    n._Myres = 7;
    n._Mysize = 0;
    n._Bx._Buf[0] = 0;
    std::wstring::assign(&n, L"ROOT", 4u);
    LOBYTE(v32) = 1;
    v2 = 1;
    v29 = 1;
    Node::Node(v3, &n);
  }
  this->rootNode = v4;
  v32 = -1;
  if ( (v2 & 1) != 0 )
  {
    v2 &= 0xFFFFFFFE;
    if ( n._Myres >= 8 )
      operator delete(n._Bx._Ptr);
  }
  v5 = (Node *)operator new(188);
  v6 = 0;
  v32 = 3;
  if ( v5 )
  {
    n._Myres = 7;
    n._Mysize = 0;
    n._Bx._Buf[0] = 0;
    std::wstring::assign(&n, L"BLURRED", 7u);
    LOBYTE(v32) = 4;
    v2 |= 2u;
    v29 = v2;
    Node::Node(v5, &n);
  }
  this->blurredNode = v6;
  v32 = -1;
  if ( (v2 & 2) != 0 )
  {
    v2 &= 0xFFFFFFFD;
    if ( n._Myres >= 8 )
      operator delete(n._Bx._Ptr);
  }
  v7 = (Node *)operator new(188);
  v30 = v7;
  v8 = 0;
  v32 = 6;
  if ( v7 )
  {
    n._Myres = 7;
    n._Mysize = 0;
    n._Bx._Buf[0] = 0;
    std::wstring::assign(&n, L"UNBLURRED", 9u);
    LOBYTE(v32) = 7;
    v2 |= 4u;
    v29 = v2;
    Node::Node(v7, &n);
  }
  this->unblurredNode = v8;
  v32 = -1;
  if ( (v2 & 4) != 0 )
  {
    v2 &= 0xFFFFFFFB;
    if ( n._Myres >= 8 )
      operator delete(n._Bx._Ptr);
  }
  this->rootNode->addChild(this->rootNode, this->blurredNode);
  this->rootNode->addChild(this->rootNode, this->unblurredNode);
  v9 = (Node *)operator new(188);
  v30 = v9;
  v10 = 0;
  v32 = 9;
  if ( v9 )
  {
    n._Myres = 7;
    n._Mysize = 0;
    n._Bx._Buf[0] = 0;
    std::wstring::assign(&n, L"TRACK", 5u);
    LOBYTE(v32) = 10;
    v2 |= 8u;
    v29 = v2;
    Node::Node(v9, &n);
  }
  this->trackNode = v10;
  v32 = -1;
  if ( (v2 & 8) != 0 )
  {
    v2 &= 0xFFFFFFF7;
    if ( n._Myres >= 8 )
      operator delete(n._Bx._Ptr);
  }
  this->blurredNode->addChild(this->blurredNode, this->trackNode);
  v11 = (Node *)operator new(188);
  v30 = v11;
  v12 = 0;
  v32 = 12;
  if ( v11 )
  {
    n._Myres = 7;
    n._Mysize = 0;
    n._Bx._Buf[0] = 0;
    std::wstring::assign(&n, L"SKIDMARKS", 9u);
    LOBYTE(v32) = 13;
    v2 |= 0x10u;
    v29 = v2;
    Node::Node(v11, &n);
  }
  this->skidMarkNode = v12;
  v32 = -1;
  if ( (v2 & 0x10) != 0 )
  {
    v2 &= 0xFFFFFFEF;
    if ( n._Myres >= 8 )
      operator delete(n._Bx._Ptr);
  }
  this->blurredNode->addChild(this->blurredNode, this->skidMarkNode);
  v13 = (NodeEvent *)operator new(200);
  v30 = v13;
  v32 = 15;
  if ( v13 )
  {
    v28._Myres = 7;
    v28._Mysize = 0;
    v28._Bx._Buf[0] = 0;
    std::wstring::assign(&v28, L"CAR_SHADOWS", 0xBu);
    NodeEvent::NodeEvent(v13, v28);
    v15 = v14;
  }
  else
  {
    v15 = 0;
  }
  v16 = this->blurredNode;
  this->carFakeShadowsNode = v15;
  v32 = -1;
  v16->addChild(v16, v15);
  v17 = (CarNodeSorter *)operator new(200);
  v30 = v17;
  v18 = 0;
  v32 = 16;
  if ( v17 )
  {
    n._Myres = 7;
    n._Mysize = 0;
    n._Bx._Buf[0] = 0;
    std::wstring::assign(&n, L"CARS", 4u);
    LOBYTE(v32) = 17;
    v2 |= 0x20u;
    v29 = v2;
    CarNodeSorter::CarNodeSorter(v17, &n, this);
  }
  this->carsNode = v18;
  v32 = -1;
  if ( (v2 & 0x20) != 0 )
  {
    v2 &= 0xFFFFFFDF;
    if ( n._Myres >= 8 )
      operator delete(n._Bx._Ptr);
  }
  v19 = (NodeEvent *)operator new(200);
  v30 = v19;
  v20 = 0;
  v32 = 19;
  if ( v19 )
  {
    v28._Myres = 7;
    v28._Mysize = 0;
    v28._Bx._Buf[0] = 0;
    std::wstring::assign(&v28, L"BEFORE_CARS_NODE", 0x10u);
    NodeEvent::NodeEvent(v19, v28);
  }
  this->beforeCarsNode = v20;
  v20->isActive = 0;
  v21 = this->unblurredNode;
  v28._Myres = (unsigned int)this->beforeCarsNode;
  v32 = -1;
  v21->addChild(v21, (Node *)v28._Myres);
  this->unblurredNode->addChild(this->unblurredNode, this->carsNode);
  v22 = (Node *)operator new(188);
  v30 = v22;
  v23 = 0;
  v32 = 20;
  if ( v22 )
  {
    n._Myres = 7;
    n._Mysize = 0;
    n._Bx._Buf[0] = 0;
    std::wstring::assign(&n, L"PARTICLES_NODE", 0xEu);
    LOBYTE(v32) = 21;
    v2 |= 0x40u;
    v29 = v2;
    Node::Node(v22, &n);
  }
  this->particlesNode = v23;
  v32 = -1;
  if ( (v2 & 0x40) != 0 && n._Myres >= 8 )
    operator delete(n._Bx._Ptr);
  this->unblurredNode->addChild(this->unblurredNode, this->particlesNode);
  v24 = (NodeEvent *)operator new(200);
  v30 = v24;
  v32 = 23;
  if ( v24 )
  {
    v28._Myres = 7;
    v28._Mysize = 0;
    v28._Bx._Buf[0] = 0;
    std::wstring::assign(&v28, L"RENDER FINISHED", 0xFu);
    NodeEvent::NodeEvent(v24, v28);
    v26 = v25;
  }
  else
  {
    v26 = 0;
  }
  v27 = this->unblurredNode;
  this->renderFinishedNodeEvent = v26;
  v32 = -1;
  v27->addChild(v27, v26);
}
void Sim::initStaticCubemap(Sim *this)
{
  TrackAvatar *v2; // eax
  std::wstring *v3; // eax
  Node *v4; // edi
  CameraForward *v5; // ecx
  int v6; // esi
  std::wstring filename; // [esp+10h] [ebp-ACh] BYREF
  std::wstring result; // [esp+28h] [ebp-94h] BYREF
  KN5IO kn5; // [esp+40h] [ebp-7Ch] BYREF
  int v10; // [esp+B8h] [ebp-4h]

  KN5IO::KN5IO(&kn5, this->game->graphics);
  v2 = this->track;
  v10 = 0;
  v3 = std::operator+<wchar_t>(&result, L"content/tracks/", &v2->name);
  LOBYTE(v10) = 1;
  std::operator+<wchar_t>(&filename, v3, L"/cubemap_model.kn5");
  LOBYTE(v10) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  if ( !Path::fileExists((unsigned int)this, &filename, 0) )
    std::wstring::assign(&filename, L"content/objects3D/cubemap_model.kn5", 0x23u);
  v4 = KN5IO::load(&kn5, &filename);
  GraphicsManager::compile(this->game->graphics, v4);
  v5 = this->sceneCamera;
  v6 = v5->cubeMapRenderer.facesPerFrame;
  v5->cubeMapRenderer.facesPerFrame = 6;
  CubeMapRenderer::render(&this->sceneCamera->cubeMapRenderer, this->sceneCamera->cubeMap, v4, this->sceneCamera);
  this->sceneCamera->cubeMapRenderer.facesPerFrame = v6;
  if ( v4 )
    ((void (*)(Node *, int))v4->~Node)(v4, 1);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  v10 = -1;
  KN5IO::~KN5IO(&kn5);
}
bool Sim::isInTripleScreenMode(Sim *this)
{
  return this->tripleScreenMode;
}
void __userpurge Sim::loadTrack(Sim *this@<ecx>, __m128 a2@<xmm0>, __m128 a3@<xmm3>, __m128 a4@<xmm4>, const std::wstring *tname, const std::wstring *config, int playerPitPosition)
{
  ICollisionObject *v8; // eax
  ICollisionObject *v9; // eax
  ICollisionObject *v10; // esi
  ICollisionObject_vtbl *v11; // ebx
  unsigned int v12; // ecx
  std::wstring *v13; // eax
  unsigned int v14; // eax
  std::wstring *v15; // esi
  void *(*v16)(ICollisionObject *); // eax
  ICollisionObject_vtbl *j; // eax
  void (*i)(ICollisionObject *, void *); // eax
  ICollisionObject *_Val; // [esp+14h] [ebp-140h] BYREF
  Sim *v20; // [esp+18h] [ebp-13Ch]
  std::wstring surfaceWav; // [esp+1Ch] [ebp-138h] BYREF
  std::wstring surfaceType; // [esp+34h] [ebp-120h] BYREF
  std::wstring eventPath; // [esp+4Ch] [ebp-108h] BYREF
  std::pair<std::wstring const ,SurfaceDef> s; // [esp+64h] [ebp-F0h] BYREF
  int v25; // [esp+150h] [ebp-4h]

  v20 = this;
  v8 = (ICollisionObject *)operator new(512);
  _Val = v8;
  v25 = 0;
  if ( v8 )
  {
    TrackAvatar::TrackAvatar((TrackAvatar *)v8, a2, a3, a4, this, tname, config);
    v10 = v9;
  }
  else
  {
    v10 = 0;
  }
  v25 = -1;
  _Val = v10;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->gameObjects, &_Val);
  v10[9].__vftable = (ICollisionObject_vtbl *)this;
  this->track = (TrackAvatar *)v10;
  v10[30].__vftable = (ICollisionObject_vtbl *)playerPitPosition;
  if ( this->game->audioEngine )
  {
    _Val = (ICollisionObject *)this->track->surfacesManager.surfaces._Myhead;
    v11 = _Val->__vftable;
    while ( v11 != (ICollisionObject_vtbl *)_Val )
    {
      s.first._Myres = 7;
      s.first._Mysize = 0;
      s.first._Bx._Buf[0] = 0;
      std::wstring::assign((std::wstring *)&s.first, (const std::wstring *)&v11->getMask, 0, 0xFFFFFFFF);
      qmemcpy(&s.second, &v11[1].getMask, sizeof(s.second));
      v25 = 1;
      surfaceWav._Myres = 7;
      surfaceWav._Mysize = 0;
      surfaceWav._Bx._Buf[0] = 0;
      if ( s.second.wavString[0] )
        v12 = wcslen(s.second.wavString);
      else
        v12 = 0;
      std::wstring::assign(&surfaceWav, s.second.wavString, v12);
      LOBYTE(v25) = 2;
      if ( surfaceWav._Mysize )
      {
        v13 = &surfaceWav;
        surfaceType._Myres = 7;
        if ( surfaceWav._Myres >= 8 )
          v13 = (std::wstring *)surfaceWav._Bx._Ptr;
        surfaceType._Mysize = 0;
        v14 = (unsigned int)v13 + 2 * surfaceWav._Mysize - 8;
        v15 = &surfaceWav;
        if ( surfaceWav._Myres >= 8 )
          v15 = (std::wstring *)surfaceWav._Bx._Ptr;
        surfaceType._Bx._Buf[0] = 0;
        if ( v15 != (std::wstring *)v14 )
          std::wstring::assign(&surfaceType, v15->_Bx._Buf, (int)(v14 - (_DWORD)v15) >> 1);
        LOBYTE(v25) = 3;
        std::operator+<wchar_t>(&eventPath, L"event:/surfaces/", &surfaceType);
        LOBYTE(v25) = 4;
        AudioEngine::addCache(v20->game->audioEngine, &eventPath);
        if ( eventPath._Myres >= 8 )
          operator delete(eventPath._Bx._Ptr);
        eventPath._Myres = 7;
        eventPath._Mysize = 0;
        eventPath._Bx._Buf[0] = 0;
        if ( surfaceType._Myres >= 8 )
          operator delete(surfaceType._Bx._Ptr);
      }
      if ( surfaceWav._Myres >= 8 )
        operator delete(surfaceWav._Bx._Ptr);
      v25 = -1;
      if ( s.first._Myres >= 8 )
        operator delete(s.first._Bx._Ptr);
      if ( !BYTE1(v11->getGroup) )
      {
        v16 = v11->getUserPointer;
        if ( *((_BYTE *)v16 + 13) )
        {
          for ( i = v11->setUserPointer;
                !*((_BYTE *)i + 13);
                i = (void (*)(ICollisionObject *, void *))*((_DWORD *)i + 1) )
          {
            if ( v11 != *((ICollisionObject_vtbl **)i + 2) )
              break;
            v11 = (ICollisionObject_vtbl *)i;
          }
          v11 = (ICollisionObject_vtbl *)i;
        }
        else
        {
          v11 = (ICollisionObject_vtbl *)v11->getUserPointer;
          for ( j = *(ICollisionObject_vtbl **)v16; !BYTE1(j->getGroup); j = (ICollisionObject_vtbl *)j->release )
            v11 = j;
        }
      }
    }
  }
}
unsigned int Sim::nextCar(Sim *this, const unsigned int anIndex)
{
  CarAvatar *v5; // eax
  unsigned int v6; // ebp
  unsigned int v7; // edi
  CarAvatar *v8; // ecx
  CarAvatar *v9; // eax
  float v10; // xmm0_4
  CarAvatar *v11; // eax
  float v12; // [esp+4h] [ebp-4h]
  float anIndexa; // [esp+Ch] [ebp+4h]

  if ( (unsigned int)(this->cars._Mylast - this->cars._Myfirst) <= 1 )
    return anIndex;
  if ( anIndex >= this->cars._Mylast - this->cars._Myfirst )
    v5 = 0;
  else
    v5 = this->cars._Myfirst[anIndex];
  v6 = 0;
  v7 = 0;
  v12 = v5->physicsState.normalizedSplinePosition;
  for ( anIndexa = FLOAT_1_0; v7 < this->cars._Mylast - this->cars._Myfirst; ++v7 )
  {
    if ( v7 != anIndex )
    {
      v8 = v7 >= this->cars._Mylast - this->cars._Myfirst ? 0 : this->cars._Myfirst[v7];
      if ( CarAvatar::isConnected(v8) )
      {
        if ( v7 >= this->cars._Mylast - this->cars._Myfirst )
          v9 = 0;
        else
          v9 = this->cars._Myfirst[v7];
        v10 = v9->physicsState.normalizedSplinePosition - v12;
        if ( v10 < 0.0 )
        {
          if ( v7 >= this->cars._Mylast - this->cars._Myfirst )
            v11 = 0;
          else
            v11 = this->cars._Myfirst[v7];
          v10 = (float)(1.0 - v12) + v11->physicsState.normalizedSplinePosition;
        }
        if ( anIndexa > v10 )
        {
          anIndexa = v10;
          v6 = v7;
        }
      }
    }
  }
  return v6;
}
void Sim::onKeyDown(Sim *this, const OnKeyEvent *message)
{
  int v3; // eax
  Sim *v4; // ecx
  float v5; // eax
  int v6; // ecx
  float *v7; // eax
  float v8; // eax
  std::wostream *v9; // eax
  std::wostream *v10; // eax
  const std::wstring *v11; // eax
  float v12; // eax
  int v13; // ecx
  float *v14; // eax
  float v15; // eax
  std::wostream *v16; // eax
  std::wostream *v17; // eax
  const std::wstring *v18; // eax
  bool v19; // zf
  char v20; // al
  const std::wstring *v21; // eax
  CarNodeSorter *v22; // ecx
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v23; // ecx
  const std::wstring *v24; // eax
  CarNodeSorter *v25; // ecx
  char v26; // al
  const std::wstring *v27; // eax
  char v28; // al
  CarAvatar **v29; // eax
  const std::wstring *v30; // eax
  CarAvatar **v31; // eax
  char v32; // al
  CarAvatar **v33; // ecx
  const std::wstring *v34; // eax
  char v35; // al
  CarAvatar **v36; // eax
  const std::wstring *v37; // eax
  CarAvatar **v38; // eax
  bool v39; // bl
  CarAvatar **v40; // eax
  ReplayManager *v41; // eax
  std::wstring *v42; // eax
  std::wstring *v43; // eax
  _DWORD *v44; // ecx
  Node *v45; // ecx
  int v46; // eax
  float v47; // eax
  float v48; // xmm1_4
  float v49; // xmm1_4
  std::wostream *v50; // eax
  std::wostream *v51; // eax
  int v52; // eax
  const std::wstring *v53; // eax
  Node *v54; // ecx
  int v55; // eax
  float v56; // eax
  float v57; // xmm0_4
  float v58; // xmm0_4
  std::wostream *v59; // eax
  std::wostream *v60; // eax
  int v61; // eax
  const std::wstring *v62; // eax
  int v63; // eax
  std::wstring *v64; // eax
  const std::wstring *v65; // eax
  int v66; // ecx
  int v67; // eax
  std::wstring *v68; // eax
  const std::wstring *v69; // eax
  std::pair<void *,std::function<void __cdecl(OnReplayStatusChanged const &)> > **v70; // esi
  bool v71; // bl
  ReplayManager *v72; // ecx
  RaceManager *v73; // eax
  char v74; // bl
  CarAvatar **v75; // ecx
  ICarControlsProvider *v76; // eax
  CarNodeSorter *v77; // ecx
  bool v78; // bl
  bool v79; // bl
  bool v80; // bl
  bool v81; // al
  const std::wstring *v82; // esi
  const std::wstring *v83; // eax
  CarNodeSorter *v84; // ecx
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement *v85; // ecx
  const std::wstring *v86; // esi
  const std::wstring *v87; // eax
  CarNodeSorter *v88; // ecx
  bool v89; // bl
  JoypadCarControl *v90; // ebx
  ReplayManager *v91; // ecx
  Car *v92; // eax
  ICarControlsProvider *v93; // eax
  CarAvatar **v94; // ecx
  bool v95; // bl
  DamageDisplayer *v96; // eax
  bool v97; // bl
  MouseHider *v98; // eax
  const std::wstring *v99; // esi
  const std::wstring *v100; // eax
  bool v101; // bl
  DamageDisplayer *v102; // eax
  bool v103; // cl
  bool v104; // bl
  ReplayManager *v105; // ecx
  bool v106; // bl
  ReplayManager *v107; // ecx
  bool v108; // bl
  ReplayManager *v109; // ecx
  bool v110; // bl
  ICarControlsProvider *v111; // eax
  ICarControlsProvider *v112; // eax
  KeyboardCarControl *v113; // eax
  KeyboardCarControl *v114; // ebx
  bool v115; // bl
  ReplayManager *v116; // ecx
  ReplayManager *v117; // ecx
  bool v118; // bl
  ReplayManager *v119; // ecx
  NodeEvent *v120; // ecx
  bool v121; // bl
  NodeEvent *v122; // ecx
  bool v123; // bl
  DriverNameDisplayer *v124; // esi
  const std::wstring *v125; // esi
  const std::wstring *v126; // eax
  bool v127; // bl
  Node *v128; // ecx
  bool v129; // bl
  Node *v130; // ecx
  bool v131; // bl
  Node *v132; // ecx
  bool v133; // bl
  CarNodeSorter *v134; // ecx
  Node *v135; // ecx
  ReplayManager *v136; // ecx
  CarNodeSorter *v137; // ecx
  Trigger *v138; // esi
  Node *v139; // ecx
  Node *v140; // ecx
  ACCameraManager *v141; // eax
  Node *v142; // ecx
  QuickMenuPitstop *v143; // eax
  std::wstring *v144; // esi
  CarAvatar **v145; // ecx
  std::wstring *v146; // eax
  std::wstring *v147; // eax
  std::wstring *v148; // eax
  std::wstring *v149; // eax
  const std::wstring *v150; // eax
  std::wstring *v151; // esi
  CarAvatar **v152; // ecx
  std::wstring *v153; // eax
  std::wstring *v154; // eax
  std::wstring *v155; // eax
  std::wstring *v156; // eax
  const std::wstring *v157; // eax
  float v158; // eax
  float v159; // eax
  std::wostream *v160; // eax
  std::wostream *v161; // eax
  const std::wstring *v162; // esi
  const std::wstring *v163; // eax
  CarNodeSorter *v164; // ecx
  float v165; // eax
  float v166; // eax
  std::wostream *v167; // eax
  std::wostream *v168; // eax
  const std::wstring *v169; // esi
  const std::wstring *v170; // eax
  CarNodeSorter *v171; // ecx
  _BYTE value[64]; // [esp-8h] [ebp-7BCh] BYREF
  int v173; // [esp+3Ch] [ebp-778h]
  float cff; // [esp+40h] [ebp-774h] BYREF
  int v175; // [esp+44h] [ebp-770h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v176; // [esp+48h] [ebp-76Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v177; // [esp+F8h] [ebp-6BCh] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v178; // [esp+1A8h] [ebp-60Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v179; // [esp+258h] [ebp-55Ch] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > ws; // [esp+308h] [ebp-4ACh] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v181; // [esp+3B8h] [ebp-3FCh] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v182; // [esp+468h] [ebp-34Ch] BYREF
  std::wstring description; // [esp+518h] [ebp-29Ch] BYREF
  std::wstring text; // [esp+530h] [ebp-284h] BYREF
  std::wstring v185; // [esp+548h] [ebp-26Ch] BYREF
  std::pair<int,std::wstring > v186; // [esp+560h] [ebp-254h] BYREF
  std::wstring result; // [esp+57Ch] [ebp-238h] BYREF
  std::wstring v188; // [esp+594h] [ebp-220h] BYREF
  std::wstring v189; // [esp+5ACh] [ebp-208h] BYREF
  std::wstring v190; // [esp+5C4h] [ebp-1F0h] BYREF
  std::wstring v191; // [esp+5DCh] [ebp-1D8h] BYREF
  std::wstring path; // [esp+5F4h] [ebp-1C0h] BYREF
  std::wstring imessage; // [esp+60Ch] [ebp-1A8h] BYREF
  std::wstring v194; // [esp+624h] [ebp-190h] BYREF
  std::wstring v195; // [esp+63Ch] [ebp-178h] BYREF
  std::wstring v196; // [esp+654h] [ebp-160h] BYREF
  std::wstring v197; // [esp+66Ch] [ebp-148h] BYREF
  std::wstring v198; // [esp+684h] [ebp-130h] BYREF
  std::wstring v199; // [esp+69Ch] [ebp-118h] BYREF
  std::wstring v200; // [esp+6B4h] [ebp-100h] BYREF
  std::wstring v201; // [esp+6CCh] [ebp-E8h] BYREF
  std::wstring v202; // [esp+6E4h] [ebp-D0h] BYREF
  std::wstring v203; // [esp+6FCh] [ebp-B8h] BYREF
  std::wstring v204; // [esp+714h] [ebp-A0h] BYREF
  std::wstring v205; // [esp+72Ch] [ebp-88h] BYREF
  std::wstring v206; // [esp+744h] [ebp-70h] BYREF
  std::wstring v207; // [esp+75Ch] [ebp-58h] BYREF
  std::wstring v208; // [esp+774h] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v209; // [esp+78Ch] [ebp-28h] BYREF
  int v210; // [esp+7ACh] [ebp-8h]
  int v211; // [esp+7B0h] [ebp-4h]
  int retaddr; // [esp+7B4h] [ebp+0h]

  *(float *)&v175 = 0.0;
  if ( message->keyCode == 9 )
  {
    if ( this->cars._Myfirst )
    {
      if ( !this->evOnCollisionEvent.handlers._Myend[7].second._Space._Alias[12]
        && !this->evOnCollisionEvent.handlers._Mylast[7].second._Space._Alias[12] )
      {
        v3 = *(_DWORD *)&this->allowFreeCamera;
        v4 = (Sim *)((char *)this - 52);
        if ( !v3 || !*(_BYTE *)(v3 + 32) )
          Sim::displayLeaderboard(v4, 1);
      }
    }
  }
  if ( GetAsyncKeyState(16) && GetAsyncKeyState(17) )
  {
    if ( message->keyCode == 107 && !Console::singleton()->isActive )
    {
      v5 = this[-1].changingCameraTrigger.accumulator;
      cff = 2.0;
      v6 = *(_DWORD *)(LODWORD(v5) + 192);
      v7 = (float *)&v175;
      *(float *)&v175 = *(float *)(v6 + 276) + 0.0099999998;
      if ( *(float *)&v175 >= 2.0 )
        v7 = &cff;
      *(float *)(v6 + 276) = *v7;
      *(_DWORD *)v177.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v177.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v177.gap68);
      retaddr = 0;
      *(_DWORD *)v176.gap0 = 2;
      std::wiostream::basic_iostream<wchar_t>(&v177.gap0[4], &v177.gap10[12], 0);
      v210 = 1;
      *(_DWORD *)&v176.gap68[*(_DWORD *)(*(_DWORD *)&v176.gap68[68] + 4) + 68] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v176.gap68[*(_DWORD *)(*(_DWORD *)&v176.gap68[68] + 4) + 64] = *(_DWORD *)(*(_DWORD *)&v176.gap68[68]
                                                                                           + 4)
                                                                               - 104;
      std::wstreambuf::wstreambuf(&v177.gap10[4]);
      *(_DWORD *)&v177.gap10[4] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v177.gap10[60] = 0;
      *(_DWORD *)&v177.gap10[64] = 0;
      v8 = this[-1].changingCameraTrigger.accumulator;
      *(_DWORD *)&value[20] = L"%";
      v210 = 3;
      *(_DWORD *)&value[16] = (int)(float)(*(float *)(*(_DWORD *)(LODWORD(v8) + 192) + 276) * 100.0);
      v9 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(
             (std::wostream *)((char *)&v177._Chcount + 4),
             L"Saturation: ");
      v10 = (std::wostream *)std::wostream::operator<<(v9, *(_DWORD *)&value[16]);
      std::operator<<<wchar_t,std::char_traits<wchar_t>>(v10, *(const wchar_t **)&value[24]);
      std::wstring::wstring(&description, word_17BE9D8);
      LOBYTE(v211) = 4;
      v11 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v177, &result);
      LOBYTE(v211) = 5;
      SystemMessage::addMessage((SystemMessage *)this->carsNode, v11, &description, eDefault);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
      std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v177);
      return;
    }
    if ( message->keyCode == 109 )
    {
      if ( !Console::singleton()->isActive )
      {
        v12 = this[-1].changingCameraTrigger.accumulator;
        *(float *)&v175 = 0.0;
        v13 = *(_DWORD *)(LODWORD(v12) + 192);
        v14 = &cff;
        cff = *(float *)(v13 + 276) - 0.0099999998;
        if ( cff <= 0.0 )
          v14 = (float *)&v175;
        *(float *)(v13 + 276) = *v14;
        *(_DWORD *)v178.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
        *(_DWORD *)v178.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
        std::wios::wios(v178.gap68);
        retaddr = 6;
        *(_DWORD *)v176.gap0 = 4;
        std::wiostream::basic_iostream<wchar_t>(&v178.gap0[4], &v178.gap10[12], 0);
        v210 = 7;
        *(_DWORD *)&v177.gap68[*(_DWORD *)(*(_DWORD *)&v177.gap68[68] + 4) + 68] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
        *(_DWORD *)&v177.gap68[*(_DWORD *)(*(_DWORD *)&v177.gap68[68] + 4) + 64] = *(_DWORD *)(*(_DWORD *)&v177.gap68[68]
                                                                                             + 4)
                                                                                 - 104;
        std::wstreambuf::wstreambuf(&v178.gap10[4]);
        *(_DWORD *)&v178.gap10[4] = &std::wstringbuf::`vftable';
        *(_DWORD *)&v178.gap10[60] = 0;
        *(_DWORD *)&v178.gap10[64] = 0;
        v15 = this[-1].changingCameraTrigger.accumulator;
        *(_DWORD *)&value[20] = L"%";
        v210 = 9;
        *(_DWORD *)&value[16] = (int)(float)(*(float *)(*(_DWORD *)(LODWORD(v15) + 192) + 276) * 100.0);
        v16 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(
                (std::wostream *)((char *)&v178._Chcount + 4),
                L"Saturation: ");
        v17 = (std::wostream *)std::wostream::operator<<(v16, *(_DWORD *)&value[16]);
        std::operator<<<wchar_t,std::char_traits<wchar_t>>(v17, *(const wchar_t **)&value[24]);
        std::wstring::wstring(&description, word_17BE9D8);
        LOBYTE(v211) = 10;
        v18 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v178, &result);
        LOBYTE(v211) = 11;
        SystemMessage::addMessage((SystemMessage *)this->carsNode, v18, &description, eDefault);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v178);
      }
      return;
    }
  }
  if ( !this->evOnCollisionEvent.handlers._Mylast[7].second._Space._Alias[12] )
  {
    description._Myres = 7;
    description._Mysize = 0;
    description._Bx._Buf[0] = 0;
    std::wstring::assign(&description, L"ABS", 3u);
    v211 = 12;
    v19 = message->keyCode == CommandManager::getCommand(
                                (CommandManager *)&this->evOnReplayStatusChanged.handlers._Mylast,
                                &description);
    v211 = -1;
    v20 = v19;
    HIBYTE(v173) = v19;
    if ( description._Myres >= 8 )
    {
      operator delete(description._Bx._Ptr);
      v20 = HIBYTE(v173);
    }
    if ( v20 )
    {
      if ( GetAsyncKeyState(17) && GetAsyncKeyState(16) )
      {
        if ( CarAvatar::isAbsAvailable((CarAvatar *)this->replayManager->__vftable) )
        {
          CarAvatar::cycleAbsMode((CarAvatar *)this->replayManager->__vftable, -1);
          goto LABEL_34;
        }
        std::wstring::wstring(&text, L"Not available");
        v211 = 13;
        std::wstring::wstring(&description, L"ABS");
        LOBYTE(v211) = 14;
        v21 = acTranslate(&v185, &text);
        v22 = this->carsNode;
        LOBYTE(v211) = 15;
        SystemMessage::addMessage((SystemMessage *)v22, &description, v21, eABS);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v185);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
        v23 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text;
      }
      else
      {
        if ( !GetAsyncKeyState(17) )
          goto LABEL_34;
        if ( CarAvatar::isAbsAvailable((CarAvatar *)this->replayManager->__vftable) )
        {
          CarAvatar::cycleAbsMode((CarAvatar *)this->replayManager->__vftable, 1);
          goto LABEL_34;
        }
        std::wstring::wstring(&description, L"Not available");
        v211 = 16;
        std::wstring::wstring(&text, L"ABS");
        LOBYTE(v211) = 17;
        v24 = acTranslate(&v185, &description);
        v25 = this->carsNode;
        LOBYTE(v211) = 18;
        SystemMessage::addMessage((SystemMessage *)v25, &text, v24, eABS);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v185);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
        v23 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description;
      }
      v211 = -1;
      std::wstring::~wstring(v23);
    }
LABEL_34:
    description._Myres = 7;
    description._Mysize = 0;
    description._Bx._Buf[0] = 0;
    std::wstring::assign(&description, L"Traction Control", 0x10u);
    v211 = 19;
    v19 = message->keyCode == CommandManager::getCommand(
                                (CommandManager *)&this->evOnReplayStatusChanged.handlers._Mylast,
                                &description);
    v211 = -1;
    v26 = v19;
    HIBYTE(v173) = v19;
    if ( description._Myres >= 8 )
    {
      operator delete(description._Bx._Ptr);
      v26 = HIBYTE(v173);
    }
    if ( v26 )
    {
      if ( GetAsyncKeyState(17) && GetAsyncKeyState(16) )
      {
        if ( CarAvatar::isTcAvailable((CarAvatar *)this->replayManager->__vftable) )
        {
          CarAvatar::cycleTcMode((CarAvatar *)this->replayManager->__vftable, -1);
          goto LABEL_47;
        }
        std::wstring::wstring(&description, L"Not available");
        v211 = 20;
        std::wstring::wstring(&text, L"TC");
        LOBYTE(v211) = 21;
        v27 = acTranslate(&v185, &description);
        LOBYTE(v211) = 22;
      }
      else
      {
        if ( !GetAsyncKeyState(17) )
          goto LABEL_47;
        if ( CarAvatar::isTcAvailable((CarAvatar *)this->replayManager->__vftable) )
        {
          CarAvatar::cycleTcMode((CarAvatar *)this->replayManager->__vftable, 1);
          goto LABEL_47;
        }
        std::wstring::wstring(&description, L"Not available");
        v211 = 23;
        std::wstring::wstring(&text, L"TC");
        LOBYTE(v211) = 24;
        v27 = acTranslate(&v185, &description);
        LOBYTE(v211) = 25;
      }
      SystemMessage::addMessage((SystemMessage *)this->carsNode, &text, v27, eTC);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v185);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
      v211 = -1;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
    }
LABEL_47:
    description._Myres = 7;
    description._Mysize = 0;
    description._Bx._Buf[0] = 0;
    std::wstring::assign(&description, L"Engine Brake", 0xCu);
    v211 = 26;
    v19 = message->keyCode == CommandManager::getCommand(
                                (CommandManager *)&this->evOnReplayStatusChanged.handlers._Mylast,
                                &description);
    v211 = -1;
    v28 = v19;
    HIBYTE(v173) = v19;
    if ( description._Myres >= 8 )
    {
      operator delete(description._Bx._Ptr);
      v28 = HIBYTE(v173);
    }
    if ( v28 )
    {
      if ( GetAsyncKeyState(17) && GetAsyncKeyState(16) )
      {
        v29 = (CarAvatar **)this->replayManager;
        if ( (*v29)->physicsInfo.engineBrakeSettingsCount > 1 )
        {
          CarAvatar::cycleEngineBrake(*v29, -1);
          goto LABEL_60;
        }
        std::wstring::wstring(&description, L"Not available");
        v211 = 27;
        std::wstring::wstring(&text, L"Engine Brake");
        LOBYTE(v211) = 28;
        v30 = acTranslate(&v185, &description);
        LOBYTE(v211) = 29;
      }
      else
      {
        if ( !GetAsyncKeyState(17) )
          goto LABEL_60;
        v31 = (CarAvatar **)this->replayManager;
        if ( (*v31)->physicsInfo.engineBrakeSettingsCount > 1 )
        {
          CarAvatar::cycleEngineBrake(*v31, 1);
          goto LABEL_60;
        }
        std::wstring::wstring(&description, L"Not available");
        v211 = 30;
        std::wstring::wstring(&text, L"Engine Brake");
        LOBYTE(v211) = 31;
        v30 = acTranslate(&v185, &description);
        LOBYTE(v211) = 32;
      }
      SystemMessage::addMessage((SystemMessage *)this->carsNode, &text, v30, eBrakeEngine);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v185);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
      v211 = -1;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
    }
LABEL_60:
    description._Myres = 7;
    description._Mysize = 0;
    description._Bx._Buf[0] = 0;
    std::wstring::assign(&description, L"MGU-K Delivery", 0xEu);
    v211 = 33;
    v19 = message->keyCode == CommandManager::getCommand(
                                (CommandManager *)&this->evOnReplayStatusChanged.handlers._Mylast,
                                &description);
    v211 = -1;
    v32 = v19;
    HIBYTE(v173) = v19;
    if ( description._Myres >= 8 )
    {
      operator delete(description._Bx._Ptr);
      v32 = HIBYTE(v173);
    }
    if ( v32 )
    {
      if ( GetAsyncKeyState(17) && GetAsyncKeyState(16) )
      {
        v33 = (CarAvatar **)this->replayManager;
        if ( (*v33)->physicsInfo.hasCockpitERSDeliveryProfile )
        {
          *(_DWORD *)&value[24] = -1;
LABEL_71:
          CarAvatar::cycleERSPower(*v33, &v186, *(int *)&value[24]);
          std::pair<int,std::wstring>::~pair<int,std::wstring>(&v186);
          goto LABEL_74;
        }
        std::wstring::wstring(&description, L"Not available");
        v211 = 34;
        std::wstring::wstring(&text, L"MGU-K Delivery");
        LOBYTE(v211) = 35;
        v34 = acTranslate(&v185, &description);
        LOBYTE(v211) = 36;
      }
      else
      {
        if ( !GetAsyncKeyState(17) )
          goto LABEL_74;
        v33 = (CarAvatar **)this->replayManager;
        if ( (*v33)->physicsInfo.hasCockpitERSDeliveryProfile )
        {
          *(_DWORD *)&value[24] = 1;
          goto LABEL_71;
        }
        std::wstring::wstring(&description, L"Not available");
        v211 = 37;
        std::wstring::wstring(&text, L"MGU-K Delivery");
        LOBYTE(v211) = 38;
        v34 = acTranslate(&v185, &description);
        LOBYTE(v211) = 39;
      }
      SystemMessage::addMessage((SystemMessage *)this->carsNode, &text, v34, eMGU);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v185);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
      v211 = -1;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
    }
LABEL_74:
    description._Myres = 7;
    description._Mysize = 0;
    description._Bx._Buf[0] = 0;
    std::wstring::assign(&description, L"MGU-K Recovery", 0xEu);
    v211 = 40;
    v19 = message->keyCode == CommandManager::getCommand(
                                (CommandManager *)&this->evOnReplayStatusChanged.handlers._Mylast,
                                &description);
    v211 = -1;
    v35 = v19;
    HIBYTE(v173) = v19;
    if ( description._Myres >= 8 )
    {
      operator delete(description._Bx._Ptr);
      v35 = HIBYTE(v173);
    }
    if ( !v35 )
      goto LABEL_87;
    if ( GetAsyncKeyState(17) && GetAsyncKeyState(16) )
    {
      v36 = (CarAvatar **)this->replayManager;
      if ( (*v36)->physicsInfo.hasCockpitERSRecovery )
      {
        CarAvatar::cycleERSRecovery(*v36, -1);
LABEL_87:
        description._Myres = 7;
        description._Mysize = 0;
        description._Bx._Buf[0] = 0;
        std::wstring::assign(&description, L"MGU-H Mode", 0xAu);
        v211 = 47;
        v19 = message->keyCode == CommandManager::getCommand(
                                    (CommandManager *)&this->evOnReplayStatusChanged.handlers._Mylast,
                                    &description);
        v211 = -1;
        v39 = v19;
        if ( description._Myres >= 8 )
          operator delete(description._Bx._Ptr);
        if ( v39 && GetAsyncKeyState(17) )
        {
          v40 = (CarAvatar **)this->replayManager;
          if ( (*v40)->physicsInfo.hasCockpitERSMguHMode )
          {
            CarAvatar::cycleERSHeatCharging(*v40);
            v41 = this->replayManager;
            *(_DWORD *)&value[24] = word_17BE9D8;
            if ( LOBYTE(v41->__vftable[174].renderAudio) )
            {
              std::wstring::wstring(&description, *(const wchar_t **)&value[24]);
              v211 = 48;
              std::wstring::wstring(&text, L"MGU-H Mode: Battery");
              LOBYTE(v211) = 49;
              v42 = acTranslate(&v185, &text);
              *(_DWORD *)&value[24] = 13;
              LOBYTE(v211) = 50;
            }
            else
            {
              std::wstring::wstring(&description, *(const wchar_t **)&value[24]);
              v211 = 51;
              std::wstring::wstring(&text, L"MGU-H Mode: Motor");
              LOBYTE(v211) = 52;
              v42 = acTranslate(&v185, &text);
              *(_DWORD *)&value[24] = 13;
              LOBYTE(v211) = 53;
            }
            *(_DWORD *)&value[20] = &description;
          }
          else
          {
            std::wstring::wstring(&description, L"Not available");
            v211 = 54;
            std::wstring::wstring(&text, L"MGU-H Mode");
            LOBYTE(v211) = 55;
            v43 = acTranslate(&v185, &description);
            *(_DWORD *)&value[24] = 13;
            *(_DWORD *)&value[20] = v43;
            LOBYTE(v211) = 56;
            v42 = &text;
          }
          SystemMessage::addMessage(
            (SystemMessage *)this->carsNode,
            v42,
            *(const std::wstring **)&value[20],
            *(const SystemMessageType *)&value[24]);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v185);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
          v211 = -1;
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
        }
        goto LABEL_98;
      }
      std::wstring::wstring(&description, L"Not available");
      v211 = 41;
      std::wstring::wstring(&text, L"MGU-K Recovery");
      LOBYTE(v211) = 42;
      v37 = acTranslate(&v185, &description);
      LOBYTE(v211) = 43;
    }
    else
    {
      if ( !GetAsyncKeyState(17) )
        goto LABEL_87;
      v38 = (CarAvatar **)this->replayManager;
      if ( (*v38)->physicsInfo.hasCockpitERSRecovery )
      {
        CarAvatar::cycleERSRecovery(*v38, 1);
        goto LABEL_87;
      }
      std::wstring::wstring(&description, L"Not available");
      v211 = 44;
      std::wstring::wstring(&text, L"MGU-K Recovery");
      LOBYTE(v211) = 45;
      v37 = acTranslate(&v185, &description);
      LOBYTE(v211) = 46;
    }
    SystemMessage::addMessage((SystemMessage *)this->carsNode, &text, v37, eMGU);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v185);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    v211 = -1;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
    goto LABEL_87;
  }
LABEL_98:
  if ( !GetAsyncKeyState(17) || this->evOnCollisionEvent.handlers._Mylast[7].second._Space._Alias[12] )
  {
    switch ( message->keyCode )
    {
      case 0x1Bu:
        v136 = (ReplayManager *)this->carFakeShadowsNode;
        if ( v136->hasLoadedReplay )
        {
          (*(void (**)(_DWORD))(*(_DWORD *)LODWORD(this[-1].changingCameraTrigger.accumulator) + 4))(LODWORD(this[-1].changingCameraTrigger.accumulator));
          return;
        }
        if ( ReplayManager::isInReplaymode(v136) )
        {
          LODWORD(cff) = &this[-1].changingCameraTrigger;
          std::function<void __cdecl (void)>::function<void __cdecl (void)>(
            (std::function<void __cdecl(void)> *)&value[4],
            (Sim::onKeyDown::__l370::<lambda_f88ce723f09c46af68702020f748c345> *)&cff);
          Sim::executeOnMainThread((Sim *)((char *)this - 52), *(std::function<void __cdecl(void)> *)&value[4]);
          return;
        }
        if ( Sim::isDisplayingResults((Sim *)((char *)this - 52)) )
          return;
        if ( this->unblurredNode && (float)(*(float *)&this->replayManager->__vftable[44].~GameObject * 3.5999999) > 1.0 )
        {
          std::wstring::wstring(&v190, L"Stop your car to enter the pause menu");
          v211 = 142;
          std::wstring::wstring(&imessage, L"Stop for Esc Menu");
          v137 = this->carsNode;
          LOBYTE(v211) = -113;
          SystemMessage::addMessage((SystemMessage *)v137, &imessage, &v190, eDefault);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&imessage);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v190);
          return;
        }
        if ( !this->evOnCollisionEvent.handlers._Myend[7].second._Space._Alias[12]
          && ((LODWORD(this->rootNode[1].matrix.M34) - LODWORD(this->rootNode[1].matrix.M33)) & 0xFFFFFFE0) == 0 )
        {
          Sim::activatePauseMenu((Sim *)((char *)this - 52));
          Sim::setPauseMode((Sim *)((char *)this - 52), 1);
        }
        GameObject::getGameObject<MouseHider>((Sim *)((char *)this - 52))->forceHide = 0;
        break;
      case 0x21u:
        v165 = this[-1].changingCameraTrigger.accumulator;
        *(_DWORD *)&value[24] = 1;
        *(_DWORD *)&value[20] = 3;
        *(float *)(*(_DWORD *)(LODWORD(v165) + 192) + 12) = *(float *)(*(_DWORD *)(LODWORD(v165) + 192) + 12)
                                                          + 0.0099999998;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
          &v181,
          *(int *)&value[20],
          *(int *)&value[24]);
        v166 = this[-1].changingCameraTrigger.accumulator;
        *(_DWORD *)&value[24] = L"%";
        v211 = 163;
        *(_DWORD *)&value[20] = (int)(float)(*(float *)(*(_DWORD *)(LODWORD(v166) + 192) + 12) * 100.0);
        v167 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v181.gap10, L"EXPOSURE: ");
        v168 = (std::wostream *)std::wostream::operator<<(v167, *(_DWORD *)&value[20]);
        std::operator<<<wchar_t,std::char_traits<wchar_t>>(v168, L"%");
        std::wstring::wstring(&result, L"Camera Exposure Multiplier");
        LOBYTE(v211) = -92;
        v169 = acTranslate(&v195, &result);
        LOBYTE(v211) = -91;
        v170 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v181, &v202);
        v171 = this->carsNode;
        LOBYTE(v211) = -90;
        SystemMessage::addMessage((SystemMessage *)v171, v170, v169, eDefault);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v202);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v195);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v181);
        return;
      case 0x22u:
        v158 = this[-1].changingCameraTrigger.accumulator;
        *(_DWORD *)&value[24] = 1;
        *(_DWORD *)&value[20] = 3;
        *(float *)(*(_DWORD *)(LODWORD(v158) + 192) + 12) = *(float *)(*(_DWORD *)(LODWORD(v158) + 192) + 12)
                                                          - 0.0099999998;
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
          &v182,
          *(int *)&value[20],
          *(int *)&value[24]);
        v159 = this[-1].changingCameraTrigger.accumulator;
        *(_DWORD *)&value[24] = L"%";
        v211 = 159;
        *(_DWORD *)&value[20] = (int)(float)(*(float *)(*(_DWORD *)(LODWORD(v159) + 192) + 12) * 100.0);
        v160 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v182.gap10, L"EXPOSURE: ");
        v161 = (std::wostream *)std::wostream::operator<<(v160, *(_DWORD *)&value[20]);
        std::operator<<<wchar_t,std::char_traits<wchar_t>>(v161, L"%");
        std::wstring::wstring(&v188, L"Camera Exposure Multiplier");
        LOBYTE(v211) = -96;
        v162 = acTranslate(&v208, &v188);
        LOBYTE(v211) = -95;
        v163 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v182, &v200);
        v164 = this->carsNode;
        LOBYTE(v211) = -94;
        SystemMessage::addMessage((SystemMessage *)v164, v163, v162, eDefault);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v200);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v208);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v188);
        std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v182);
        return;
      case 0x24u:
        Console::show((Console *)this->timeLimitedTest, !this->timeLimitedTest->isActive);
        return;
      case 0x25u:
      case 0x26u:
      case 0x27u:
      case 0x28u:
        v143 = GameObject::getGameObject<QuickMenuPitstop>((Sim *)((char *)this - 52));
        if ( v143 )
          QuickMenuPitstop::sendInput(v143, message->keyCode);
        return;
      case 0x6Bu:
        if ( Console::singleton()->isActive || ReplayManager::isInReplaymode((ReplayManager *)this->carFakeShadowsNode) )
          goto $LN17_8;
        cff = CarAvatar::modifyUserFFGain((CarAvatar *)this->replayManager->__vftable, 0.0099999998);
        std::wstring::wstring(&v189, L"Force Feedback");
        v211 = 145;
        v144 = std::to_wstring(&v205, (int)(float)(cff * 100.0));
        v145 = (CarAvatar **)this->replayManager;
        LOBYTE(v211) = -110;
        v146 = CarAvatar::getScreenName(*v145, &v194);
        LOBYTE(v211) = -109;
        v147 = std::operator+<wchar_t>(&v201, L"User level for ", v146);
        LOBYTE(v211) = -108;
        v148 = std::operator+<wchar_t>(&v199, v147, L": ");
        LOBYTE(v211) = -107;
        v149 = std::operator+<wchar_t>(&v197, v148, v144);
        LOBYTE(v211) = -106;
        v150 = std::operator+<wchar_t>(&v203, v149, L"%");
        LOBYTE(v211) = -105;
        SystemMessage::addMessage((SystemMessage *)this->carsNode, v150, &v189, eDefault);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v203);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v197);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v199);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v201);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v194);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v205);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v189);
        return;
      case 0x6Du:
$LN17_8:
        if ( !Console::singleton()->isActive
          && !ReplayManager::isInReplaymode((ReplayManager *)this->carFakeShadowsNode) )
        {
          cff = CarAvatar::modifyUserFFGain((CarAvatar *)this->replayManager->__vftable, -0.0099999998);
          std::wstring::wstring(&v191, L"Force Feedback");
          v211 = 152;
          v151 = std::to_wstring(&v204, (int)(float)(cff * 100.0));
          v152 = (CarAvatar **)this->replayManager;
          LOBYTE(v211) = -103;
          v153 = CarAvatar::getScreenName(*v152, &v198);
          LOBYTE(v211) = -102;
          v154 = std::operator+<wchar_t>(&v206, L"User level for ", v153);
          LOBYTE(v211) = -101;
          v155 = std::operator+<wchar_t>(&v196, v154, L": ");
          LOBYTE(v211) = -100;
          v156 = std::operator+<wchar_t>(&v209.name, v155, v151);
          LOBYTE(v211) = -99;
          v157 = std::operator+<wchar_t>(&v207, v156, L"%");
          LOBYTE(v211) = -98;
          SystemMessage::addMessage((SystemMessage *)this->carsNode, v157, &v191, eDefault);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v207);
          std::wstring::~wstring(&v209);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v196);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v206);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v198);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v204);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v191);
        }
        return;
      case 0x70u:
        SystemMessage::clearMessage((SystemMessage *)this->carsNode);
        ACCameraManager::setMode((ACCameraManager *)this->rootNode, eCockpit, 0, 0);
        return;
      case 0x71u:
        v138 = &this[-1].changingCameraTrigger;
        *(_DWORD *)&value[24] = (char *)this - 52;
        LODWORD(cff) = &this[-1].changingCameraTrigger;
        std::function<void __cdecl (bool const &)>::function<void __cdecl (bool const &)>(
          (std::function<void __cdecl(bool const &)> *)value,
          (Sim::onKeyDown::__l383::<lambda_13cf479f16c93369468a6946710b9319> *)&cff);
        goto LABEL_268;
      case 0x72u:
        v138 = &this[-1].changingCameraTrigger;
        *(_DWORD *)&value[24] = (char *)this - 52;
        LODWORD(cff) = &this[-1].changingCameraTrigger;
        std::function<void __cdecl (bool const &)>::function<void __cdecl (bool const &)>(
          (std::function<void __cdecl(bool const &)> *)value,
          (Sim::onKeyDown::__l385::<lambda_0727a0eb368ea446cf4b19c771fd53c9> *)&cff);
        goto LABEL_268;
      case 0x73u:
        if ( (unsigned int)(((char *)this->physicsAvatar - (char *)this->replayManager) >> 2) <= 1 )
          return;
        v138 = &this[-1].changingCameraTrigger;
        *(_DWORD *)&value[24] = (char *)this - 52;
        LODWORD(cff) = &this[-1].changingCameraTrigger;
        std::function<void __cdecl (bool const &)>::function<void __cdecl (bool const &)>(
          (std::function<void __cdecl(bool const &)> *)value,
          (Sim::onKeyDown::__l395::<lambda_e29c70e447da9a3030f56bf152de03d2> *)&cff);
        goto LABEL_268;
      case 0x74u:
        if ( *(_DWORD *)&this->rootNode->name._Bx._Alias[8] == 5 )
          return;
        v138 = &this[-1].changingCameraTrigger;
        *(_DWORD *)&value[24] = (char *)this - 52;
        LODWORD(cff) = &this[-1].changingCameraTrigger;
        std::function<void __cdecl (bool const &)>::function<void __cdecl (bool const &)>(
          (std::function<void __cdecl(bool const &)> *)value,
          (Sim::onKeyDown::__l390::<lambda_1c4d450c8d498e06cbe083ef9a95b6d4> *)&cff);
        goto LABEL_268;
      case 0x75u:
        v140 = this->rootNode;
        if ( *(_DWORD *)&v140->name._Bx._Alias[8] == 1 )
        {
          CameraCarManager::nextCamera((CameraCarManager *)LODWORD(v140->matrixWS.M31));
        }
        else
        {
          v138 = &this[-1].changingCameraTrigger;
          *(_DWORD *)&value[24] = (char *)this - 52;
          LODWORD(cff) = &this[-1].changingCameraTrigger;
          std::function<void __cdecl (bool const &)>::function<void __cdecl (bool const &)>(
            (std::function<void __cdecl(bool const &)> *)value,
            (Sim::onKeyDown::__l400::<lambda_3038a154952c7952585d6e09cf386330> *)&cff);
LABEL_268:
          ACCameraManager::registerToFadeInEvent(
            (ACCameraManager *)this->rootNode,
            *(std::function<void __cdecl(bool const &)> *)value,
            *(void **)&value[24]);
          v139 = this->rootNode;
          *(_DWORD *)&description._Bx._Alias[8] = this->pitStop;
          *(_QWORD *)description._Bx._Buf = 0i64;
          *(_DWORD *)&description._Bx._Alias[12] = v138;
          ACCameraManager::fadeIn((ACCameraManager *)v139, (FadeModeDef)_mm_loadu_si128((const __m128i *)&description));
        }
        return;
      case 0x76u:
        if ( LOBYTE(this->raceManager) )
        {
          v141 = GameObject::getGameObject<ACCameraManager>((Sim *)((char *)this - 52));
          ACCameraManager::setMode(v141, eFree, 0, 0);
        }
        return;
      case 0x77u:
        std::wstring::wstring(&path, word_17BE9D8);
        v142 = this->blurredNode;
        v211 = 144;
        ScreenCapturer::takeScreen((ScreenCapturer *)v142, &path);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&path);
        return;
      case 0x7Bu:
        return;
      default:
        break;
    }
  }
  else
  {
    if ( message->keyCode == 107 )
    {
      v45 = this->rootNode;
      v46 = *(_DWORD *)&v45->name._Bx._Alias[8];
      if ( !v46 || v46 == 2 && *(_DWORD *)(LODWORD(v45->matrixWS.M32) + 52) == 4 )
      {
        v47 = v45->matrixWS.M13;
        v48 = *(float *)(LODWORD(v47) + 92);
        if ( v48 < 125.0 )
        {
          v49 = v48 + 0.5;
          *(float *)(LODWORD(v47) + 92) = v49;
          cff = v49;
          *(_DWORD *)ws.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)ws.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(ws.gap68);
          v211 = 57;
          v175 = 8;
          std::wiostream::basic_iostream<wchar_t>(&ws, &ws.gap10[8], 0);
          v211 = 58;
          *(_DWORD *)&ws.gap0[*(_DWORD *)(*(_DWORD *)ws.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(_DWORD *)&v179.gap68[*(_DWORD *)(*(_DWORD *)ws.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)ws.gap0 + 4) - 104;
          std::wstreambuf::wstreambuf(&ws.gap10[8]);
          *(_DWORD *)&ws.gap10[8] = &std::wstringbuf::`vftable';
          *(_DWORD *)&ws.gap10[64] = 0;
          *(_DWORD *)&ws.gap10[68] = 0;
          v211 = 60;
          *(_DWORD *)&value[16] = std::setprecision(&description, 1, 0);
          v50 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)ws.gap10, L"FOV: ");
          v51 = std::operator<<<wchar_t,std::char_traits<wchar_t>,__int64>(
                  v50,
                  *(const std::_Smanip<__int64> **)&value[16]);
          v52 = std::wostream::operator<<(v51, std::fixed);
          std::wostream::operator<<(v52);
          std::wstring::wstring(&text, L"On Board Camera");
          LOBYTE(v211) = 61;
          v53 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&ws, &v185);
          LOBYTE(v211) = 62;
          SystemMessage::addMessage((SystemMessage *)this->carsNode, v53, &text, eDefault);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v185);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&ws);
        }
        return;
      }
    }
    if ( message->keyCode == 109 )
    {
      v54 = this->rootNode;
      v55 = *(_DWORD *)&v54->name._Bx._Alias[8];
      if ( !v55 || v55 == 2 && *(_DWORD *)(LODWORD(v54->matrixWS.M32) + 52) == 4 )
      {
        v56 = v54->matrixWS.M13;
        v57 = *(float *)(LODWORD(v56) + 92);
        if ( v57 > 1.0 )
        {
          v58 = v57 - 0.5;
          *(float *)(LODWORD(v56) + 92) = v58;
          cff = v58;
          *(_DWORD *)v179.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v179.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v179.gap68);
          v211 = 63;
          v175 = 16;
          std::wiostream::basic_iostream<wchar_t>(&v179, &v179.gap10[8], 0);
          v211 = 64;
          *(_DWORD *)&v179.gap0[*(_DWORD *)(*(_DWORD *)v179.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(_DWORD *)&v178.gap68[*(_DWORD *)(*(_DWORD *)v179.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v179.gap0 + 4)
                                                                             - 104;
          std::wstreambuf::wstreambuf(&v179.gap10[8]);
          *(_DWORD *)&v179.gap10[8] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v179.gap10[64] = 0;
          *(_DWORD *)&v179.gap10[68] = 0;
          v211 = 66;
          *(_DWORD *)&value[16] = std::setprecision(&description, 1, 0);
          v59 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v179.gap10, L"FOV: ");
          v60 = std::operator<<<wchar_t,std::char_traits<wchar_t>,__int64>(
                  v59,
                  *(const std::_Smanip<__int64> **)&value[16]);
          v61 = std::wostream::operator<<(v60, std::fixed);
          std::wostream::operator<<(v61);
          std::wstring::wstring(&text, L"On Board Camera");
          LOBYTE(v211) = 67;
          v62 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v179, &v185);
          LOBYTE(v211) = 68;
          SystemMessage::addMessage((SystemMessage *)this->carsNode, v62, &text, eDefault);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v185);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v179);
        }
        return;
      }
    }
    if ( GetAsyncKeyState(16) )
    {
      if ( GetAsyncKeyState(45) )
      {
        *(_BYTE *)(*(_DWORD *)&this->serializeForms + 32) = *(_BYTE *)(*(_DWORD *)&this->serializeForms + 32) == 0;
        if ( *(_BYTE *)(*(_DWORD *)&this->serializeForms + 32) )
        {
          std::wstring::wstring(&description, L"Active");
          v211 = 69;
          std::wstring::wstring(&text, L"Visual Debug");
          LOBYTE(v211) = 70;
        }
        else
        {
          std::wstring::wstring(&description, L"Deactivated");
          v211 = 71;
          std::wstring::wstring(&text, L"Visual Debug");
          LOBYTE(v211) = 72;
        }
        SystemMessage::addMessage((SystemMessage *)this->carsNode, &text, &description, eDefault);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
        v211 = -1;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
      }
      if ( *(_BYTE *)(*(_DWORD *)&this->serializeForms + 32) )
      {
        if ( GetAsyncKeyState(37) )
        {
          DebugVisualizer::previousLayer(*(DebugVisualizer **)&this->serializeForms);
          *(_DWORD *)v176.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
          *(_DWORD *)v176.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
          std::wios::wios(v176.gap68);
          v211 = 73;
          v175 = 32;
          std::wiostream::basic_iostream<wchar_t>(&v176, &v176.gap10[8], 0);
          v211 = 74;
          *(_DWORD *)&v176.gap0[*(_DWORD *)(*(_DWORD *)v176.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
          *(int *)((char *)&v175 + *(_DWORD *)(*(_DWORD *)v176.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v176.gap0 + 4) - 104;
          std::wstreambuf::wstreambuf(&v176.gap10[8]);
          *(_DWORD *)&v176.gap10[8] = &std::wstringbuf::`vftable';
          *(_DWORD *)&v176.gap10[64] = 0;
          *(_DWORD *)&v176.gap10[68] = 0;
          v63 = *(_DWORD *)&this->serializeForms;
          v211 = 76;
          std::wostream::operator<<(v176.gap10, *(_DWORD *)(v63 + 184));
          std::wstring::wstring(&text, word_17BE9D8);
          LOBYTE(v211) = 77;
          v64 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v176, &result);
          LOBYTE(v211) = 78;
          v65 = std::operator+<wchar_t>(&v185, L"Current Debug Layer: ", v64);
          LOBYTE(v211) = 79;
          SystemMessage::addMessage((SystemMessage *)this->carsNode, v65, &text, eDefault);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v185);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
          v211 = -1;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v176);
        }
        if ( GetAsyncKeyState(39) )
        {
          v66 = *(_DWORD *)&this->serializeForms;
          *(_DWORD *)&value[24] = 1;
          *(_DWORD *)&value[20] = 3;
          *(_DWORD *)(v66 + 184) = (*(_DWORD *)(v66 + 184) + 1) % 0x14u;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
            &v176,
            *(int *)&value[20],
            *(int *)&value[24]);
          v67 = *(_DWORD *)&this->serializeForms;
          v211 = 80;
          std::wostream::operator<<(v176.gap10, *(_DWORD *)(v67 + 184));
          std::wstring::wstring(&text, word_17BE9D8);
          LOBYTE(v211) = 81;
          v68 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v176, &result);
          LOBYTE(v211) = 82;
          v69 = std::operator+<wchar_t>(&v185, L"Current Debug Layer: ", v68);
          LOBYTE(v211) = 83;
          SystemMessage::addMessage((SystemMessage *)this->carsNode, v69, &text, eDefault);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v185);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
          v211 = -1;
          std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v176);
        }
      }
    }
    std::wstring::wstring(&text, L"Reset Race");
    v211 = 84;
    v70 = &this->evOnReplayStatusChanged.handlers._Mylast;
    v19 = message->keyCode == CommandManager::getCommand(
                                (CommandManager *)&this->evOnReplayStatusChanged.handlers._Mylast,
                                &text);
    v211 = -1;
    v71 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v71 )
    {
      v72 = (ReplayManager *)this->carFakeShadowsNode;
      if ( !v72->hasLoadedReplay
        && !ReplayManager::isInReplaymode(v72)
        && !this->evOnCollisionEvent.handlers._Mylast[7].second._Space._Alias[12]
        && !this->evOnCollisionEvent.handlers._Myend[7].second._Space._Alias[12] )
      {
        v73 = GameObject::getGameObject<RaceManager>((Sim *)((char *)this - 52));
        RaceManager::restartCurrentSession(v73);
      }
    }
    std::wstring::wstring(&text, L"Activate AI");
    v74 = v175 | 1;
    v211 = 85;
    v175 |= 1u;
    if ( message->keyCode != CommandManager::getCommand(
                               (CommandManager *)&this->evOnReplayStatusChanged.handlers._Mylast,
                               &text)
      || (v19 = this->unblurredNode == 0, HIBYTE(v173) = 1, !v19) )
    {
      HIBYTE(v173) = 0;
    }
    v211 = -1;
    if ( (v74 & 1) != 0 )
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( HIBYTE(v173) )
    {
      v75 = (CarAvatar **)this->replayManager;
      *(_DWORD *)&value[24] = 0;
      *(_DWORD *)&value[20] = &AIDriver `RTTI Type Descriptor';
      *(_DWORD *)&value[16] = &ICarControlsProvider `RTTI Type Descriptor';
      v76 = CarAvatar::getControlsProvider(*v75);
      if ( !__RTDynamicCast(v76, 0, &ICarControlsProvider `RTTI Type Descriptor', &AIDriver `RTTI Type Descriptor', 0) )
      {
        LODWORD(cff) = &this[-1].changingCameraTrigger;
        std::function<void __cdecl (void)>::function<void __cdecl (void)>(
          (std::function<void __cdecl(void)> *)&value[4],
          (Sim::onKeyDown::__l189::<lambda_19d5872d209bba5d002c5accf43621b8> *)&cff);
        PhysicsAvatar::executeOnPhysicsThread(
          (PhysicsAvatar *)this->track,
          *(std::function<void __cdecl(void)> *)&value[4]);
        std::wstring::wstring(&description, L"ON");
        v211 = 86;
        std::wstring::wstring(&text, L"AI DRIVER");
        v77 = this->carsNode;
        LOBYTE(v211) = 87;
        SystemMessage::addMessage((SystemMessage *)v77, &text, &description, eDefault);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
        v211 = -1;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
      }
    }
    std::wstring::wstring(&text, L"Hide Show Apps");
    v211 = 88;
    v19 = message->keyCode == CommandManager::getCommand(
                                (CommandManager *)&this->evOnReplayStatusChanged.handlers._Mylast,
                                &text);
    v211 = -1;
    v78 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v78
      && !this->evOnCollisionEvent.handlers._Mylast[7].second._Space._Alias[12]
      && !this->evOnCollisionEvent.handlers._Myend[7].second._Space._Alias[12] )
    {
      ksgui::GameScreen::showDesktop((ksgui::GameScreen *)this->evOnCollisionEvent.handlers._Myfirst);
    }
    std::wstring::wstring(&text, L"Cycle Virtual Desktop");
    v211 = 89;
    v19 = message->keyCode == CommandManager::getCommand(
                                (CommandManager *)&this->evOnReplayStatusChanged.handlers._Mylast,
                                &text);
    v211 = -1;
    v79 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v79
      && !this->evOnCollisionEvent.handlers._Mylast[7].second._Space._Alias[12]
      && !this->evOnCollisionEvent.handlers._Myend[7].second._Space._Alias[12] )
    {
      ksgui::Taskbar::cycleDekstop(*(ksgui::Taskbar **)(*(_DWORD *)(LODWORD(this[-1].changingCameraTrigger.accumulator)
                                                                  + 252)
                                                      + 92));
    }
    std::wstring::wstring(&text, L"Auto Shifter");
    v211 = 90;
    v19 = message->keyCode == CommandManager::getCommand(
                                (CommandManager *)&this->evOnReplayStatusChanged.handlers._Mylast,
                                &text);
    v211 = -1;
    v80 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v80 )
    {
      v81 = CarAvatar::getAutoShifter((CarAvatar *)this->replayManager->__vftable);
      LOBYTE(cff) = !v81;
      if ( v81 )
      {
        std::wstring::wstring(&description, L"OFF");
        v211 = 95;
        std::wstring::wstring(&text, L"Auto Shifter");
        LOBYTE(v211) = 96;
        v86 = acTranslate(&v185, &description);
        LOBYTE(v211) = 97;
        v87 = acTranslate((std::wstring *)&v186, &text);
        v88 = this->carsNode;
        LOBYTE(v211) = 98;
        SystemMessage::addMessage((SystemMessage *)v88, v87, v86, eDefault);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v186);
        v85 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v185;
      }
      else
      {
        std::wstring::wstring(&description, L"ON");
        v211 = 91;
        std::wstring::wstring(&text, L"Auto Shifter");
        LOBYTE(v211) = 92;
        v82 = acTranslate((std::wstring *)&v186, &description);
        LOBYTE(v211) = 93;
        v83 = acTranslate(&v185, &text);
        v84 = this->carsNode;
        LOBYTE(v211) = 94;
        SystemMessage::addMessage((SystemMessage *)v84, v83, v82, eDefault);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v185);
        v85 = (FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v186;
      }
      std::wstring::~wstring(v85);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
      v211 = -1;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
      CarAvatar::setAutoShifter((CarAvatar *)this->replayManager->__vftable, SLOBYTE(cff));
      v70 = &this->evOnReplayStatusChanged.handlers._Mylast;
    }
    std::wstring::wstring(&text, L"Ideal Line");
    v211 = 99;
    v19 = message->keyCode == CommandManager::getCommand((CommandManager *)v70, &text);
    v211 = -1;
    v89 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v89 )
      DrivingAssistManager::setIdealLine(
        (DrivingAssistManager *)this->optionsManager.options._Mysize,
        *(_BYTE *)(this->optionsManager.options._Mysize + 56) == 0);
    if ( message->keyCode == 80 && !this->timeLimitedTest->isActive )
    {
      *(float *)&v90 = COERCE_FLOAT(operator new(400));
      cff = *(float *)&v90;
      v211 = 100;
      if ( *(float *)&v90 == 0.0 )
      {
        v93 = 0;
      }
      else
      {
        v91 = this->replayManager;
        *(_DWORD *)&value[24] = *(_DWORD *)(LODWORD(this[-1].changingCameraTrigger.accumulator) + 280);
        v92 = RaceEngineer::getCar((RaceEngineer *)v91->__vftable[153].~GameObject);
        JoypadCarControl::JoypadCarControl(v90, v92, *(Joypad **)&value[24]);
      }
      v94 = (CarAvatar **)this->replayManager;
      v211 = -1;
      CarAvatar::setControlsProvider(*v94, v93);
    }
    std::wstring::wstring(&text, L"Show Damage");
    v211 = 101;
    v19 = message->keyCode == CommandManager::getCommand((CommandManager *)v70, &text);
    v211 = -1;
    v95 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v95 )
    {
      v96 = GameObject::getGameObject<DamageDisplayer>((Sim *)((char *)this - 52));
      if ( v96 )
        DamageDisplayer::show(v96);
    }
    std::wstring::wstring(&text, L"Mouse Force Hide");
    v211 = 102;
    v19 = message->keyCode == CommandManager::getCommand((CommandManager *)v70, &text);
    v211 = -1;
    v97 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v97 )
    {
      v98 = GameObject::getGameObject<MouseHider>((Sim *)((char *)this - 52));
      if ( v98->forceHide )
      {
        *(_DWORD *)&value[24] = L"Press CTRL + F8 to hide cursor";
        v98->forceHide = 0;
        std::wstring::wstring(&description, *(const wchar_t **)&value[24]);
        v211 = 107;
        std::wstring::wstring(&text, L"Mouse Cursor visible");
        LOBYTE(v211) = 108;
        v99 = acTranslate(&v185, &description);
        LOBYTE(v211) = 109;
        v100 = acTranslate((std::wstring *)&v186, &text);
        LOBYTE(v211) = 110;
      }
      else
      {
        *(_DWORD *)&value[24] = L"Press CTRL + F8 to reset";
        v98->forceHide = 1;
        std::wstring::wstring(&description, *(const wchar_t **)&value[24]);
        v211 = 103;
        std::wstring::wstring(&text, L"Mouse Cursor not visible");
        LOBYTE(v211) = 104;
        v99 = acTranslate(&v185, &description);
        LOBYTE(v211) = 105;
        v100 = acTranslate((std::wstring *)&v186, &text);
        LOBYTE(v211) = 106;
      }
      SystemMessage::addMessage((SystemMessage *)this->carsNode, v100, v99, eDefault);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v186);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v185);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
      v211 = -1;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
      v70 = &this->evOnReplayStatusChanged.handlers._Mylast;
    }
    std::wstring::wstring(&text, L"Hide Damage");
    v211 = 111;
    v19 = message->keyCode == CommandManager::getCommand((CommandManager *)v70, &text);
    v211 = -1;
    v101 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v101 )
    {
      v102 = GameObject::getGameObject<DamageDisplayer>((Sim *)((char *)this - 52));
      if ( v102 )
      {
        v103 = !v102->enabled;
        v102->enabled = v103;
        if ( v103 )
        {
          std::wstring::wstring(&description, L"Enabled");
          v211 = 112;
          std::wstring::wstring(&text, L"Damage Displayer");
          LOBYTE(v211) = 113;
        }
        else
        {
          std::wstring::wstring(&description, L"Disabled");
          v211 = 114;
          std::wstring::wstring(&text, L"Damage Displayer");
          LOBYTE(v211) = 115;
        }
        SystemMessage::addMessage((SystemMessage *)this->carsNode, &text, &description, eDefault);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
        v211 = -1;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
      }
    }
    std::wstring::wstring(&text, L"Previous Lap");
    v211 = 116;
    v19 = message->keyCode == CommandManager::getCommand((CommandManager *)v70, &text);
    v211 = -1;
    v104 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v104 )
    {
      v105 = (ReplayManager *)this->carFakeShadowsNode;
      if ( v105 )
      {
        if ( ReplayManager::isInReplaymode(v105) )
          ReplayManager::previousLap((ReplayManager *)this->carFakeShadowsNode);
      }
    }
    std::wstring::wstring(&text, L"Next Lap");
    v211 = 117;
    v19 = message->keyCode == CommandManager::getCommand((CommandManager *)v70, &text);
    v211 = -1;
    v106 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v106 )
    {
      v107 = (ReplayManager *)this->carFakeShadowsNode;
      if ( v107 )
      {
        if ( ReplayManager::isInReplaymode(v107) )
          ReplayManager::nextLap((ReplayManager *)this->carFakeShadowsNode);
      }
    }
    std::wstring::wstring(&text, L"FFWD");
    v211 = 118;
    v19 = message->keyCode == CommandManager::getCommand((CommandManager *)v70, &text);
    v211 = -1;
    v108 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v108 )
    {
      v109 = (ReplayManager *)this->carFakeShadowsNode;
      if ( v109 )
      {
        if ( ReplayManager::isInReplaymode(v109) )
          ReplayManager::fastForward((ReplayManager *)this->carFakeShadowsNode, 1, 0);
      }
    }
    std::wstring::wstring(&text, L"Mouse Steering");
    v211 = 119;
    v19 = message->keyCode == CommandManager::getCommand((CommandManager *)v70, &text);
    v211 = -1;
    v110 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v110 )
    {
      v111 = CarAvatar::getControlsProvider((CarAvatar *)this->replayManager->__vftable);
      if ( __RTDynamicCast(
             v111,
             0,
             &ICarControlsProvider `RTTI Type Descriptor',
             &KeyboardCarControl `RTTI Type Descriptor',
             0) )
      {
        v112 = CarAvatar::getControlsProvider((CarAvatar *)this->replayManager->__vftable);
        v113 = (KeyboardCarControl *)__RTDynamicCast(
                                       v112,
                                       0,
                                       &ICarControlsProvider `RTTI Type Descriptor',
                                       &KeyboardCarControl `RTTI Type Descriptor',
                                       0);
        v114 = v113;
        if ( v113 )
          KeyboardCarControl::setMouseSteering(v113, !v113->mouseSteering);
        if ( v114->mouseSteering )
        {
          std::wstring::wstring(&description, L"Activated");
          v211 = 120;
          std::wstring::wstring(&text, L"Mouse Steering");
          LOBYTE(v211) = 121;
        }
        else
        {
          std::wstring::wstring(&description, L"Deactivated");
          v211 = 122;
          std::wstring::wstring(&text, L"Mouse Steering");
          LOBYTE(v211) = 123;
        }
        SystemMessage::addMessage((SystemMessage *)this->carsNode, &text, &description, eDefault);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
        v211 = -1;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
      }
    }
    std::wstring::wstring(&text, L"REV");
    v211 = 124;
    v19 = message->keyCode == CommandManager::getCommand((CommandManager *)v70, &text);
    v211 = -1;
    v115 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v115 )
    {
      v116 = (ReplayManager *)this->carFakeShadowsNode;
      if ( v116 )
      {
        if ( ReplayManager::isInReplaymode(v116) )
        {
          v117 = (ReplayManager *)this->carFakeShadowsNode;
          *(_DWORD *)&value[24] = 0;
          ReplayManager::rewind(v117, 1, *(__int64 *)&value[24]);
        }
      }
    }
    std::wstring::wstring(&text, L"SLOWMO");
    v211 = 125;
    v19 = message->keyCode == CommandManager::getCommand((CommandManager *)v70, &text);
    v211 = -1;
    v118 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v118 )
    {
      v119 = (ReplayManager *)this->carFakeShadowsNode;
      if ( v119 )
      {
        if ( ReplayManager::isInReplaymode(v119) )
        {
          v120 = this->carFakeShadowsNode;
          if ( LODWORD(v120->matrixWS.M32) == 5 )
            ReplayManager::play((ReplayManager *)v120);
          else
            ReplayManager::slowMotion((ReplayManager *)v120, *(float *)&v120->evOnRender.handlers._Myfirst);
        }
      }
    }
    std::wstring::wstring(&text, L"Pause Replay");
    v211 = 126;
    v19 = message->keyCode == CommandManager::getCommand((CommandManager *)v70, &text);
    v211 = -1;
    v121 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v121
      && !this->timeLimitedTest->isActive
      && ReplayManager::isInReplaymode((ReplayManager *)this->carFakeShadowsNode) )
    {
      v122 = this->carFakeShadowsNode;
      if ( LODWORD(v122->matrixWS.M32) )
        ReplayManager::play((ReplayManager *)v122);
      else
        ReplayManager::pause((ReplayManager *)v122);
    }
    std::wstring::wstring(&text, L"Driver Names");
    v211 = 127;
    v19 = message->keyCode == CommandManager::getCommand((CommandManager *)v70, &text);
    v211 = -1;
    v123 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v123 && !BYTE1(this->beforeCarsNode) )
    {
      v124 = GameObject::getGameObject<DriverNameDisplayer>((Sim *)((char *)this - 52));
      DriverNameDisplayer::setActive(v124, !v124->isActive);
      if ( v124->isActive )
      {
        std::wstring::wstring(&description, L"ON");
        v211 = 128;
        std::wstring::wstring(&text, L"Driver Names");
        LOBYTE(v211) = -127;
        v125 = acTranslate(&v185, &description);
        LOBYTE(v211) = -126;
        v126 = acTranslate((std::wstring *)&v186, &text);
        LOBYTE(v211) = -125;
      }
      else
      {
        std::wstring::wstring(&description, L"OFF");
        v211 = 132;
        std::wstring::wstring(&text, L"Driver Names");
        LOBYTE(v211) = -123;
        v125 = acTranslate(&v185, &description);
        LOBYTE(v211) = -122;
        v126 = acTranslate((std::wstring *)&v186, &text);
        LOBYTE(v211) = -121;
      }
      SystemMessage::addMessage((SystemMessage *)this->carsNode, v126, v125, eDefault);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v186);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v185);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
      v211 = -1;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
      v70 = &this->evOnReplayStatusChanged.handlers._Mylast;
    }
    std::wstring::wstring(&text, L"Previous Car");
    v211 = 136;
    v19 = message->keyCode == CommandManager::getCommand((CommandManager *)v70, &text);
    v211 = -1;
    v127 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v127 && (unsigned int)(((char *)this->physicsAvatar - (char *)this->replayManager) >> 2) > 1 )
    {
      *(_DWORD *)&value[24] = (char *)this - 52;
      LODWORD(cff) = &this[-1].changingCameraTrigger;
      std::function<void __cdecl (bool const &)>::function<void __cdecl (bool const &)>(
        (std::function<void __cdecl(bool const &)> *)value,
        (Sim::onKeyDown::__l324::<lambda_fece7355d7de510eb2229a3de6f131b2> *)&cff);
      ACCameraManager::registerToFadeInEvent(
        (ACCameraManager *)this->rootNode,
        *(std::function<void __cdecl(bool const &)> *)value,
        *(void **)&value[24]);
      v128 = this->rootNode;
      *(_DWORD *)&description._Bx._Alias[8] = this->pitStop;
      *(_QWORD *)description._Bx._Buf = 0i64;
      *(_DWORD *)&description._Bx._Alias[12] = (char *)this - 52;
      ACCameraManager::fadeIn((ACCameraManager *)v128, (FadeModeDef)_mm_loadu_si128((const __m128i *)&description));
      v70 = &this->evOnReplayStatusChanged.handlers._Mylast;
    }
    std::wstring::wstring(&text, L"Player Car");
    v211 = 137;
    v19 = message->keyCode == CommandManager::getCommand((CommandManager *)v70, &text);
    v211 = -1;
    v129 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v129 && (unsigned int)(((char *)this->physicsAvatar - (char *)this->replayManager) >> 2) > 1 )
    {
      *(_DWORD *)&value[24] = (char *)this - 52;
      LODWORD(cff) = &this[-1].changingCameraTrigger;
      std::function<void __cdecl (bool const &)>::function<void __cdecl (bool const &)>(
        (std::function<void __cdecl(bool const &)> *)value,
        (Sim::onKeyDown::__l331::<lambda_effbbc30b6ffed4f18f6a17916eea29e> *)&cff);
      ACCameraManager::registerToFadeInEvent(
        (ACCameraManager *)this->rootNode,
        *(std::function<void __cdecl(bool const &)> *)value,
        *(void **)&value[24]);
      v130 = this->rootNode;
      *(_DWORD *)&description._Bx._Alias[8] = this->pitStop;
      *(_QWORD *)description._Bx._Buf = 0i64;
      *(_DWORD *)&description._Bx._Alias[12] = (char *)this - 52;
      ACCameraManager::fadeIn((ACCameraManager *)v130, (FadeModeDef)_mm_loadu_si128((const __m128i *)&description));
      v70 = &this->evOnReplayStatusChanged.handlers._Mylast;
    }
    std::wstring::wstring(&text, L"Next Car");
    v211 = 138;
    v19 = message->keyCode == CommandManager::getCommand((CommandManager *)v70, &text);
    v211 = -1;
    v131 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v131 && (unsigned int)(((char *)this->physicsAvatar - (char *)this->replayManager) >> 2) > 1 )
    {
      *(_DWORD *)&value[24] = (char *)this - 52;
      LODWORD(cff) = &this[-1].changingCameraTrigger;
      std::function<void __cdecl (bool const &)>::function<void __cdecl (bool const &)>(
        (std::function<void __cdecl(bool const &)> *)value,
        (Sim::onKeyDown::__l338::<lambda_80870c9d530af70726001765d3e328c5> *)&cff);
      ACCameraManager::registerToFadeInEvent(
        (ACCameraManager *)this->rootNode,
        *(std::function<void __cdecl(bool const &)> *)value,
        *(void **)&value[24]);
      v132 = this->rootNode;
      *(_DWORD *)&description._Bx._Alias[8] = this->pitStop;
      *(_QWORD *)description._Bx._Buf = 0i64;
      *(_DWORD *)&description._Bx._Alias[12] = (char *)this - 52;
      ACCameraManager::fadeIn((ACCameraManager *)v132, (FadeModeDef)_mm_loadu_si128((const __m128i *)&description));
      v70 = &this->evOnReplayStatusChanged.handlers._Mylast;
    }
    std::wstring::wstring(&text, L"Start Replay");
    v211 = 139;
    v19 = message->keyCode == CommandManager::getCommand((CommandManager *)v70, &text);
    v211 = -1;
    v133 = v19;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
    if ( v133 )
    {
      if ( this->unblurredNode )
      {
        std::wstring::wstring(&description, L"Not available for multiplayer races");
        v211 = 140;
        std::wstring::wstring(&text, L"Instant Replay");
        v134 = this->carsNode;
        LOBYTE(v211) = -115;
        SystemMessage::addMessage((SystemMessage *)v134, &text, &description, eDefault);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&text);
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&description);
        return;
      }
      if ( !this->timeLimitedTest->isActive && !LOBYTE(this->carFakeShadowsNode->matrixWS.M31) )
      {
        v44 = (_DWORD *)&this->rootNode[1].matrix.M33;
        if ( ((LODWORD(this->rootNode[1].matrix.M34) - *v44) & 0xFFFFFFE0) == 0 )
        {
          *(_DWORD *)&value[24] = (char *)this - 52;
          LODWORD(cff) = &this[-1].changingCameraTrigger;
          std::function<void __cdecl (bool const &)>::function<void __cdecl (bool const &)>(
            (std::function<void __cdecl(bool const &)> *)value,
            (Sim::onKeyDown::__l356::<lambda_999f2b28c30e2af003ac064c3a501ea1> *)&cff);
          ACCameraManager::registerToFadeInEvent(
            (ACCameraManager *)this->rootNode,
            *(std::function<void __cdecl(bool const &)> *)value,
            *(void **)&value[24]);
          v135 = this->rootNode;
          *(_DWORD *)&description._Bx._Alias[8] = this->pitStop;
          *(_QWORD *)description._Bx._Buf = 0i64;
          *(_DWORD *)&description._Bx._Alias[12] = (char *)this - 52;
          ACCameraManager::fadeIn((ACCameraManager *)v135, (FadeModeDef)_mm_loadu_si128((const __m128i *)&description));
        }
      }
    }
  }
  if ( !this->timeLimitedTest->isActive && !this->evOnCollisionEvent.handlers._Myend[7].second._Space._Alias[12] )
  {
    if ( message->keyCode == 49 )
    {
      *(_DWORD *)&value[24] = v44;
      CarAvatar::setTurboBoost((CarAvatar *)this->replayManager->__vftable, 0.1);
    }
    if ( message->keyCode == 50 )
    {
      *(_DWORD *)&value[24] = v44;
      CarAvatar::setTurboBoost((CarAvatar *)this->replayManager->__vftable, 0.2);
    }
    if ( message->keyCode == 51 )
    {
      *(_DWORD *)&value[24] = v44;
      CarAvatar::setTurboBoost((CarAvatar *)this->replayManager->__vftable, 0.30000001);
    }
    if ( message->keyCode == 52 )
    {
      *(_DWORD *)&value[24] = v44;
      CarAvatar::setTurboBoost((CarAvatar *)this->replayManager->__vftable, 0.40000001);
    }
    if ( message->keyCode == 53 )
    {
      *(_DWORD *)&value[24] = v44;
      CarAvatar::setTurboBoost((CarAvatar *)this->replayManager->__vftable, 0.5);
    }
    if ( message->keyCode == 54 )
    {
      *(_DWORD *)&value[24] = v44;
      CarAvatar::setTurboBoost((CarAvatar *)this->replayManager->__vftable, 0.60000002);
    }
    if ( message->keyCode == 55 )
    {
      *(_DWORD *)&value[24] = v44;
      CarAvatar::setTurboBoost((CarAvatar *)this->replayManager->__vftable, 0.69999999);
    }
    if ( message->keyCode == 56 )
    {
      *(_DWORD *)&value[24] = v44;
      CarAvatar::setTurboBoost((CarAvatar *)this->replayManager->__vftable, 0.80000001);
    }
    if ( message->keyCode == 57 )
    {
      *(_DWORD *)&value[24] = v44;
      CarAvatar::setTurboBoost((CarAvatar *)this->replayManager->__vftable, 0.89999998);
    }
    if ( message->keyCode == 48 )
    {
      *(_DWORD *)&value[24] = v44;
      CarAvatar::setTurboBoost((CarAvatar *)this->replayManager->__vftable, 1.0);
    }
  }
}
void Sim::onPostLoad(Sim *this)
{
  CarAvatar **v2; // esi
  int v3; // edi
  unsigned int v4; // ebx
  ReplayManager *v5; // ecx

  if ( !this->game->isClosing )
    Sim::initStaticCubemap(this);
  v2 = this->cars._Myfirst;
  v3 = 0;
  v4 = (unsigned int)((char *)this->cars._Mylast - (char *)v2 + 3) >> 2;
  if ( v2 > this->cars._Mylast )
    v4 = 0;
  if ( v4 )
  {
    do
    {
      CarAvatar::onPostLoad(*v2, v4);
      ++v3;
      ++v2;
    }
    while ( v3 != v4 );
  }
  v5 = this->replayManager;
  if ( v5 )
  {
    if ( v5->hasLoadedReplay )
      ReplayManager::startReplayMode(v5, (int)this, 0);
  }
}
void Sim::onReplayModeChanged(Sim *this, const OnReplayStatusChanged *message)
{
  PhysicsAvatar *v4; // ecx
  bool value; // [esp+Ch] [ebp+4h]

  _printf("ON REPLAY MODE CHANGED %d\n", message->status);
  if ( message->status == eReplayModeEnter )
  {
    value = this->client == 0;
    PhysicsAvatar::pausePhysics(this->physicsAvatar, value);
    this->raceManager->pauseMode = value;
    ksSleep(500);
  }
  if ( message->status == eReplayModeExit && !this->replayManager->hasLoadedReplay )
  {
    AudioEngine::start(this->game->audioEngine);
    v4 = this->physicsAvatar;
    this->focusedCarIndex = 0;
    PhysicsAvatar::pausePhysics(v4, 0);
    this->raceManager->pauseMode = 0;
  }
}
unsigned int Sim::previousCar(Sim *this, const unsigned int anIndex)
{
  CarAvatar *v5; // eax
  unsigned int v6; // ebp
  unsigned int v7; // edi
  CarAvatar *v8; // ecx
  CarAvatar *v9; // eax
  float v10; // xmm0_4
  CarAvatar *v11; // eax
  float v12; // [esp+4h] [ebp-4h]
  float anIndexa; // [esp+Ch] [ebp+4h]

  if ( (unsigned int)(this->cars._Mylast - this->cars._Myfirst) <= 1 )
    return anIndex;
  if ( anIndex >= this->cars._Mylast - this->cars._Myfirst )
    v5 = 0;
  else
    v5 = this->cars._Myfirst[anIndex];
  v6 = 0;
  v7 = 0;
  v12 = v5->physicsState.normalizedSplinePosition;
  for ( anIndexa = FLOAT_1_0; v7 < this->cars._Mylast - this->cars._Myfirst; ++v7 )
  {
    if ( v7 != anIndex )
    {
      v8 = v7 >= this->cars._Mylast - this->cars._Myfirst ? 0 : this->cars._Myfirst[v7];
      if ( CarAvatar::isConnected(v8) )
      {
        if ( v7 >= this->cars._Mylast - this->cars._Myfirst )
          v9 = 0;
        else
          v9 = this->cars._Myfirst[v7];
        v10 = v12 - v9->physicsState.normalizedSplinePosition;
        if ( v10 < 0.0 )
        {
          if ( v7 >= this->cars._Mylast - this->cars._Myfirst )
            v11 = 0;
          else
            v11 = this->cars._Myfirst[v7];
          v10 = (float)(1.0 - v11->physicsState.normalizedSplinePosition) + v12;
        }
        if ( anIndexa > v10 )
        {
          anIndexa = v10;
          v6 = v7;
        }
      }
    }
  }
  return v6;
}
void Sim::render(Sim *this, float deltaT)
{
  this->lastDT = deltaT;
  if ( PhysicsEngine::isTestMode )
  {
    this->blurredNode->isActive = 0;
    this->unblurredNode->isActive = 0;
    Sleep(0x3Cu);
  }
}
void Sim::renderHUD(Sim *this, float deltaT)
{
  SessionLeaderboard *v3; // eax
  EndSessionDisplayer *v4; // eax
  SessionLeaderboard *v5; // ecx

  v3 = this->leaderboard;
  if ( v3 )
  {
    if ( v3->parentControl->visible
      && (!GetAsyncKeyState(9) || this->escMenu->visible || (v4 = this->endSessionDisplayer) != 0 && v4->isActive) )
    {
      v5 = this->leaderboard;
      if ( v5 )
      {
        SessionLeaderboard::setVisible(v5, 0);
        this->leaderboard->isActive = 0;
      }
    }
  }
}
void __userpurge Sim::renderScene(Sim *this@<ecx>, __int64 a2@<esi:edi>, float deltaT)
{
  int v3; // eax
  int v4; // eax
  __int128 dt; // [esp+2h] [ebp-1Ch] BYREF
  int v6; // [esp+1Ah] [ebp-4h]

  HIDWORD(a2) = this;
  if ( this->node3DGUI )
  {
    *(float *)&dt = deltaT;
    ksgui::GUI::preRender3D(this->game->gui, a2, dt);
    Game::renderHUDOnDemand(*(Game **)(HIDWORD(a2) + 4), deltaT);
    ksgui::GUI::renderVPointer(*(ksgui::GUI **)(*(_DWORD *)(HIDWORD(a2) + 4) + 252));
  }
  FolderEncrypter::FolderEncrypter(
    (std::_Wrap_alloc<std::allocator<std::_Tree_node<std::pair<std::wstring const ,std::map<std::wstring,INISection> >,void *> > > *)&dt
  + 15);
  LODWORD(dt) = *(_DWORD *)(HIDWORD(a2) + 156);
  v6 = 0;
  WorldMatrixTraverser::traverse((WorldMatrixTraverser *)&dt + 15, (Node *)dt);
  if ( *(_DWORD *)(HIDWORD(a2) + 204)
    && (ACCameraManager::isCameraOnBoard(
          *(ACCameraManager **)(HIDWORD(a2) + 208),
          *(CarAvatar **)(*(_DWORD *)(HIDWORD(a2) + 280) + 4 * *(_DWORD *)(HIDWORD(a2) + 292)))
     || !*(_BYTE *)(*(_DWORD *)(HIDWORD(a2) + 204) + 29)
     || *(_BYTE *)(*(_DWORD *)(*(_DWORD *)(HIDWORD(a2) + 348) + 52) + 184)
     && ACCameraManager::isVirtualMirrorOn(*(ACCameraManager **)(HIDWORD(a2) + 208))) )
  {
    v3 = *(_DWORD *)(HIDWORD(a2) + 376);
    if ( v3 )
      *(_BYTE *)(v3 + 184) = 0;
    MirrorTextureRenderer::render(*(MirrorTextureRenderer **)(HIDWORD(a2) + 204), deltaT);
    v4 = *(_DWORD *)(HIDWORD(a2) + 376);
    if ( v4 )
      *(_BYTE *)(v4 + 184) = 1;
  }
  (*(void (**)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(HIDWORD(a2) + 308) + 28))(
    *(_DWORD *)(HIDWORD(a2) + 308),
    *(_DWORD *)(HIDWORD(a2) + 184),
    *(_DWORD *)(HIDWORD(a2) + 188),
    *(_DWORD *)(HIDWORD(a2) + 156),
    LODWORD(deltaT));
  v6 = -1;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)((char *)&dt + 15));
}
void Sim::setFocusedCarIndex(Sim *this, unsigned int aCarIndex)
{
  if ( aCarIndex < this->cars._Mylast - this->cars._Myfirst )
    this->focusedCarIndex = aCarIndex;
}
void Sim::setPauseMode(Sim *this, bool mode)
{
  std::pair<void *,std::function<void __cdecl(bool const &)> > *v3; // esi
  std::_Func_base<void,bool const &> **v4; // ebx
  bool v5; // al

  _printf("SETTING PAUSE MODE: %d\n", mode);
  v3 = this->evOnPauseModeChanged.handlers._Myfirst;
  if ( v3 != this->evOnPauseModeChanged.handlers._Mylast )
  {
    v4 = &v3->second._Impl;
    while ( *v4 )
    {
      (*v4)->_Do_call(*v4, &mode);
      ++v3;
      v4 += 8;
      if ( v3 == this->evOnPauseModeChanged.handlers._Mylast )
        goto LABEL_5;
    }
    std::_Xbad_function_call();
    goto $LN61_11;
  }
LABEL_5:
  if ( !this->replayManager->hasLoadedReplay )
  {
    if ( mode && !this->client )
    {
      v5 = 1;
LABEL_11:
      PhysicsAvatar::pausePhysics(this->physicsAvatar, v5);
      CarAvatar::setControlsLock(*this->cars._Myfirst, mode);
      goto LABEL_12;
    }
$LN61_11:
    v5 = 0;
    goto LABEL_11;
  }
LABEL_12:
  this->raceManager->pauseMode = mode;
}
void Sim::setSplashLoadingCar(Sim *this, const std::wstring *carUnixName)
{
  GameObject *v2; // edi
  GameObject **v3; // esi
  SplashScreen *v4; // eax

  v2 = this->game->root;
  v3 = v2->gameObjects._Myfirst;
  if ( v3 != v2->gameObjects._Mylast )
  {
    while ( 1 )
    {
      v4 = (SplashScreen *)__RTDynamicCast(
                             *v3,
                             0,
                             &GameObject `RTTI Type Descriptor',
                             &SplashScreen `RTTI Type Descriptor',
                             0);
      if ( v4 )
        break;
      if ( ++v3 == v2->gameObjects._Mylast )
        return;
    }
    SplashScreen::addLoadingCar(v4, carUnixName);
  }
}
void Sim::setSplashMessage(Sim *this, const std::wstring *msg)
{
  GameObject *v2; // edi
  GameObject **v3; // esi
  SplashScreen *v4; // eax

  v2 = this->game->root;
  v3 = v2->gameObjects._Myfirst;
  if ( v3 != v2->gameObjects._Mylast )
  {
    while ( 1 )
    {
      v4 = (SplashScreen *)__RTDynamicCast(
                             *v3,
                             0,
                             &GameObject `RTTI Type Descriptor',
                             &SplashScreen `RTTI Type Descriptor',
                             0);
      if ( v4 )
        break;
      if ( ++v3 == v2->gameObjects._Mylast )
        return;
    }
    SplashScreen::setCurrentMessage(v4, msg);
  }
}
void Sim::shutdown(Sim *this)
{
  ksgui::GameScreen *v2; // ecx
  ESCMenu *v3; // ecx
  double v4; // st7
  std::wstring *v5; // eax
  std::wstring *v6; // ecx
  std::wstring *v7; // eax
  std::wstring filename; // [esp+10h] [ebp-A4h] BYREF
  std::wstring result; // [esp+28h] [ebp-8Ch] BYREF
  wchar_t buffer[50]; // [esp+40h] [ebp-74h] BYREF
  int v11; // [esp+B0h] [ebp-4h]

  v2 = this->gameScreen;
  if ( v2 )
    ksgui::GameScreen::shutdown(v2);
  v3 = this->escMenu;
  if ( v3 )
    ESCMenu::onShutdown(v3);
  Sim::writeOutputJson(this);
  v4 = CarAvatar::getUserFFGain(*this->cars._Myfirst);
  _swprintf_s(buffer, 0x32u, L"%0.3f", v4);
  v5 = Path::getDocumentPath(&result);
  v11 = 0;
  std::operator+<wchar_t>(&filename, v5, L"/Assetto Corsa/cfg/user_ff.ini");
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v6 = &filename;
  if ( filename._Myres >= 8 )
    v6 = (std::wstring *)filename._Bx._Ptr;
  v7 = &(*this->cars._Myfirst)->unixName;
  if ( (*this->cars._Myfirst)->unixName._Myres >= 8 )
    v7 = (std::wstring *)v7->_Bx._Ptr;
  WritePrivateProfileStringW(v7->_Bx._Buf, L"VALUE", buffer, v6->_Bx._Buf);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
}
void Sim::startGame(Sim *this)
{
  CarAvatar *v2; // eax
  ACCameraManager *v3; // ecx
  ESCMenu *v4; // eax
  ACCameraManager *v5; // ecx
  std::function<void __cdecl(bool const &)> v6; // [esp-1Ch] [ebp-48h] BYREF
  Sim *v7; // [esp-4h] [ebp-30h]
  __m128i v8; // [esp+10h] [ebp-1Ch] BYREF
  int v9; // [esp+28h] [ebp-4h]

  if ( this->cars._Mylast - this->cars._Myfirst )
    v2 = *this->cars._Myfirst;
  else
    v2 = 0;
  if ( v2->physicsState.setupState == Legal )
  {
    v7 = this;
    v6._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_b284e6a412ac28e54d823b1721065045_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
    v6._Space._Pfn[1] = (void (__cdecl *)())this;
    v6._Impl = (std::_Func_base<void,bool const &> *)&v6;
    v3 = this->cameraManager;
    v9 = -1;
    ACCameraManager::registerToFadeInEvent(v3, v6, v7);
    v4 = this->escMenu;
    v5 = this->cameraManager;
    v8.m128i_i64[0] = 0i64;
    v8.m128i_i32[3] = (int)this;
    v8.m128i_i32[2] = LODWORD(v4->fadeTime);
    ACCameraManager::fadeIn(v5, (FadeModeDef)_mm_loadu_si128(&v8));
  }
}
void __cdecl Sim::stepPhysicsEvent(int a1, float colliderCategory)
{
  Sim *this; // ecx
  Sim *v3; // ebx
  bool (*v4)(Concurrency::details::_Concurrent_queue_base_v4 *, void *); // edi
  PhysicsAvatar *v5; // ecx
  int v6; // ebp
  std::pair<void *,std::function<void __cdecl(CollisionEvent const &)> > *v7; // esi
  unsigned int v8; // edx
  float normalForce; // xmm1_4
  float impactAngle; // xmm2_4
  float relativeSpeed; // xmm0_4
  std::_Func_base<void,CollisionEvent const &> **v12; // edi
  CarAudioFMOD *v13; // ecx
  CollisionEvent cev; // [esp+34h] [ebp-64h] BYREF
  ACPhysicsEvent ev; // [esp+60h] [ebp-38h] BYREF
  eACEventType vars0; // [esp+98h] [ebp+0h]

  v3 = this;
  ev.vParam2.y = 0.0;
  v4 = Concurrency::details::_Concurrent_queue_base_v4::_Internal_pop_if_present;
  v5 = this->physicsAvatar;
  *(_OWORD *)&ev.param1 = _xmm_bf800000bf800000bf800000bf800000;
  ev.vParam2.z = 0.0;
  ev.voidParam0 = 0;
  *(_OWORD *)&ev.vParam1.x = 0i64;
  ev.voidParam1 = 0;
  ev.ulParam0 = 0;
  if ( Concurrency::details::_Concurrent_queue_base_v4::_Internal_pop_if_present(&v5->engine.eventQueue, &ev) )
  {
    do
    {
      if ( !LODWORD(ev.param4) )
      {
        v6 = (int)ev.vParam1.x;
        v7 = v3->evOnCollisionEvent.handlers._Myfirst;
        v8 = LODWORD(colliderCategory);
        LODWORD(cev.impactAngle) = ev.voidParam0;
        ev.type = vars0;
        ev.param3 = colliderCategory;
        normalForce = ev.vParam1.y;
        impactAngle = ev.vParam1.z;
        *(_QWORD *)&cev.normal.y = *(_QWORD *)&ev.vParam2.y;
        *(_QWORD *)&cev.relativeSpeed = *(_QWORD *)&ev.voidParam1;
        relativeSpeed = ev.vParam2.x;
        LODWORD(cev.pos.z) = (int)ev.vParam1.x;
        cev.normal.x = ev.vParam1.y;
        *(_QWORD *)&ev.param1 = *(_QWORD *)&ev.vParam1.z;
        if ( v7 != v3->evOnCollisionEvent.handlers._Mylast )
        {
          v12 = &v7->second._Impl;
          do
          {
            if ( !*v12 )
            {
              std::_Xbad_function_call();
              JUMPOUT(0x68C244);
            }
            (*v12)->_Do_call(*v12, (CollisionEvent *)&cev.pos.z);
            ++v7;
            v12 += 8;
          }
          while ( v7 != v3->evOnCollisionEvent.handlers._Mylast );
          v8 = LODWORD(colliderCategory);
          relativeSpeed = ev.vParam2.x;
          impactAngle = ev.vParam1.z;
          normalForce = ev.vParam1.y;
          v4 = Concurrency::details::_Concurrent_queue_base_v4::_Internal_pop_if_present;
        }
        if ( v6 < 0 || v6 >= (unsigned int)(v3->cars._Mylast - v3->cars._Myfirst) )
        {
          _printf(
            "ERROR: Trying to send a collision to car out of bounds: %d cars: %u\n",
            v6,
            v3->cars._Mylast - v3->cars._Myfirst);
        }
        else
        {
          v13 = v3->cars._Myfirst[v6]->carAudioFMOD;
          if ( v13 )
            CarAudioFMOD::onCarHit(
              v13,
              normalForce,
              (const vec3f *)&ev.vParam2.y,
              (const vec3f *)&ev.voidParam1,
              impactAngle,
              relativeSpeed,
              v8);
        }
      }
    }
    while ( v4(&v3->physicsAvatar->engine.eventQueue, &ev.param4) );
  }
}
void Sim::unloadMeshResources(Sim *this, Node *node)
{
  std::_Container_base0 *v3; // eax
  std::_Container_base0 *v4; // edi
  std::vector<MeshVertex> *v5; // esi
  std::vector<unsigned short> *v6; // edi
  unsigned __int16 *v7; // eax
  unsigned __int16 *v8; // ecx
  std::_Container_base0 *v9; // eax
  std::_Container_base0 *v10; // edi
  std::_Container_base0 *v11; // esi
  int v12; // eax
  Node **v13; // esi
  int v14; // edi
  unsigned int v15; // ebx

  v3 = (std::_Container_base0 *)__RTDynamicCast(node, 0, &Node `RTTI Type Descriptor', &Mesh `RTTI Type Descriptor', 0);
  v4 = v3;
  if ( v3 )
  {
    v5 = (std::vector<MeshVertex> *)&v3[224];
    std::_Container_base0::_Orphan_all(v3 + 224);
    v6 = (std::vector<unsigned short> *)&v4[236];
    v5->_Mylast = v5->_Myfirst;
    std::_Container_base0::_Orphan_all(v6);
    v6->_Mylast = v6->_Myfirst;
    std::vector<MeshVertex>::shrink_to_fit(v5);
    v7 = v6->_Mylast;
    if ( v6->_Myend != v7 )
    {
      v8 = v6->_Myfirst;
      if ( v6->_Myfirst == v7 )
      {
        if ( v8 )
        {
          std::_Container_base0::_Orphan_all(v6);
          operator delete(v6->_Myfirst);
          v6->_Myfirst = 0;
          v6->_Mylast = 0;
          v6->_Myend = 0;
        }
      }
      else
      {
        std::vector<unsigned short>::_Reallocate(v6, v7 - v8);
      }
    }
  }
  v9 = (std::_Container_base0 *)__RTDynamicCast(
                                  node,
                                  0,
                                  &Node `RTTI Type Descriptor',
                                  &SkinnedMesh `RTTI Type Descriptor',
                                  0);
  v10 = v9;
  if ( v9 )
  {
    std::_Container_base0::_Orphan_all(v9 + 224);
    *(_DWORD *)&v10[228] = *(_DWORD *)&v10[224];
    std::vector<SkinnedMeshVertex>::shrink_to_fit((std::vector<SkinnedMeshVertex> *)&v10[224]);
    v11 = v10 + 236;
    std::_Container_base0::_Orphan_all(v10 + 236);
    v12 = *(_DWORD *)&v10[236];
    *(_DWORD *)&v10[240] = v12;
    if ( *(_DWORD *)&v10[244] != v12 )
    {
      if ( v12 )
      {
        std::_Container_base0::_Orphan_all(v10 + 236);
        operator delete(*(_DWORD *)v11);
        *(_DWORD *)v11 = 0;
        *(_DWORD *)&v10[240] = 0;
        *(_DWORD *)&v10[244] = 0;
      }
    }
  }
  v13 = node->nodes._Myfirst;
  v14 = 0;
  v15 = (unsigned int)((char *)node->nodes._Mylast - (char *)v13 + 3) >> 2;
  if ( v13 > node->nodes._Mylast )
    v15 = 0;
  if ( v15 )
  {
    do
    {
      Sim::unloadMeshResources(this, *v13);
      ++v14;
      ++v13;
    }
    while ( v14 != v15 );
  }
}
void Sim::update(Sim *this, float deltaT)
{
  int v3; // ebp
  CarAvatar **v4; // esi
  unsigned int v5; // edi
  CarAvatar **v6; // eax
  CarAvatar *v7; // ecx
  CarAvatar *v8; // ecx
  CarAvatar *v9; // ecx
  CarAvatar *v10; // ecx
  CarAvatar *v11; // ecx
  ksgui::FormRenderStats *v12; // ecx
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  SystemMessage *v18; // ecx
  Game *v19; // eax
  unsigned int *v20; // ecx
  Sim::CarItemCmp *v21; // ecx
  ComparablePoint *v22; // ebp
  CarAvatar **v23; // esi
  CarAvatar **v24; // edi
  double v25; // st7
  CarAvatar *v26; // eax
  Sim::CarItemCmp *v27; // ecx
  int v28; // eax
  int v29; // ecx
  unsigned int v30; // edx
  unsigned int v31; // edx
  float v32; // eax
  int v33; // ecx
  unsigned int v34; // edx
  unsigned int v35; // edx
  Sim::CarItemCmp *v36; // edi
  Sim::CarItemCmp *v37; // esi
  int i; // ebp
  CarAvatar *v39; // ecx
  Game *v40; // eax
  CarAvatar *v41; // eax
  GameObject **v42; // esi
  ACCameraManager *v43; // eax
  ReplayManager *v44; // ecx
  vec3f v45; // [esp+34h] [ebp-618h]
  int v46; // [esp+40h] [ebp-60Ch]
  float v47; // [esp+44h] [ebp-608h]
  float distance; // [esp+54h] [ebp-5F8h]
  int v49; // [esp+58h] [ebp-5F4h] BYREF
  Sim::CarItemCmp carItem; // [esp+5Ch] [ebp-5F0h] BYREF
  float v51; // [esp+64h] [ebp-5E8h]
  std::vector<Sim::CarItemCmp> cars_distance; // [esp+68h] [ebp-5E4h] BYREF
  int v53; // [esp+78h] [ebp-5D4h]
  unsigned int v54; // [esp+7Ch] [ebp-5D0h]
  AudioStats stats; // [esp+80h] [ebp-5CCh] BYREF
  std::wstring imessage; // [esp+9Ch] [ebp-5B0h] BYREF
  std::function<void __cdecl(void)> f; // [esp+B4h] [ebp-598h] BYREF
  wchar_t shortFormat[48]; // [esp+CCh] [ebp-580h] BYREF
  wchar_t longFormat[135]; // [esp+12Ch] [ebp-520h] BYREF
  wchar_t line[512]; // [esp+23Ch] [ebp-410h] BYREF
  int v61; // [esp+648h] [ebp-4h]

  if ( Sim::benchmarkMode )
    this->game->gui->isActive = 0;
  this->connectedCarsCount = 0;
  v3 = 0;
  v4 = this->cars._Myfirst;
  v5 = (unsigned int)((char *)this->cars._Mylast - (char *)v4 + 3) >> 2;
  if ( v4 > this->cars._Mylast )
    v5 = 0;
  if ( v5 )
  {
    do
    {
      if ( CarAvatar::isConnected(*v4) )
        ++this->connectedCarsCount;
      ++v3;
      ++v4;
    }
    while ( v3 != v5 );
  }
  f._Impl = 0;
  v61 = 0;
  if ( Concurrency::details::_Concurrent_queue_base_v4::_Internal_pop_if_present(&this->chFunctions.queue, &f) )
  {
    while ( f._Impl )
    {
      f._Impl->_Do_call(f._Impl);
      if ( !Concurrency::details::_Concurrent_queue_base_v4::_Internal_pop_if_present(&this->chFunctions.queue, &f) )
        goto LABEL_12;
    }
    std::_Xbad_function_call();
  }
  else
  {
LABEL_12:
    CarNodeSorter::sort(this->carsNode);
    v6 = this->cars._Mylast;
    if ( !this->console->isActive )
    {
      if ( v6 - this->cars._Myfirst )
        v9 = *this->cars._Myfirst;
      else
        v9 = 0;
      if ( CarAvatar::getControlsProvider(v9) )
      {
        v10 = this->cars._Mylast - this->cars._Myfirst ? *this->cars._Myfirst : 0;
        if ( !CarAvatar::getControlsProvider(v10)->keyboardEnabled )
        {
          if ( this->cars._Mylast - this->cars._Myfirst )
            v11 = *this->cars._Myfirst;
          else
            v11 = 0;
          CarAvatar::getControlsProvider(v11)->keyboardEnabled = 1;
        }
      }
      ACCameraManager::setKeyboardInputEnabled(this->cameraManager, 1);
      goto LABEL_39;
    }
    if ( v6 - this->cars._Myfirst )
    {
      v7 = *this->cars._Myfirst;
      goto LABEL_17;
    }
  }
  v7 = 0;
LABEL_17:
  if ( CarAvatar::getControlsProvider(v7) )
  {
    v8 = this->cars._Mylast - this->cars._Myfirst ? *this->cars._Myfirst : 0;
    if ( CarAvatar::getControlsProvider(v8)->keyboardEnabled )
    {
      if ( this->cars._Mylast - this->cars._Myfirst )
      {
        CarAvatar::getControlsProvider(*this->cars._Myfirst)->keyboardEnabled = 0;
        ACCameraManager::setKeyboardInputEnabled(this->cameraManager, 0);
        goto LABEL_39;
      }
      CarAvatar::getControlsProvider(0)->keyboardEnabled = 0;
    }
  }
  ACCameraManager::setKeyboardInputEnabled(this->cameraManager, 0);
LABEL_39:
  Sim::stepPhysicsEvent(v46, v47);
  v12 = this->formRenderStats;
  v13 = FLOAT_1_0;
  v14 = v12->simulationOccupancy;
  v51 = 0.0;
  if ( deltaT <= 1.0 )
  {
    if ( deltaT >= 0.0 )
      v15 = deltaT;
    else
      v15 = 0.0;
  }
  else
  {
    v15 = FLOAT_1_0;
  }
  v16 = (float)((float)((float)this->physicsAvatar->occupancy - v14) * v15) + v14;
  v12->simulationOccupancy = v16;
  if ( deltaT <= 1.0 )
  {
    if ( deltaT >= 0.0 )
      v13 = deltaT;
    else
      v13 = 0.0;
  }
  v17 = this->game->stats.cpuTime / (deltaT * 1000.0) * 100.0;
  this->formRenderStats->cpuTime = (float)((float)(v17 - this->formRenderStats->cpuTime) * v13)
                                 + this->formRenderStats->cpuTime;
  if ( v16 >= 99.0 )
  {
    v54 = 7;
    v53 = 0;
    LOWORD(cars_distance._Myfirst) = 0;
    std::wstring::assign((std::wstring *)&cars_distance, L"CPU OCCUPANCY > 99% ", 0x14u);
    LOBYTE(v61) = 1;
    imessage._Myres = 7;
    imessage._Mysize = 0;
    imessage._Bx._Buf[0] = 0;
    std::wstring::assign(&imessage, L"WARNING", 7u);
    v18 = this->systemMessage;
    LOBYTE(v61) = 2;
    SystemMessage::addMessage(v18, &imessage, (const std::wstring *)&cars_distance, eDefault);
    if ( imessage._Myres >= 8 )
      operator delete(imessage._Bx._Ptr);
    imessage._Myres = 7;
    imessage._Mysize = 0;
    imessage._Bx._Buf[0] = 0;
    LOBYTE(v61) = 0;
    if ( v54 >= 8 )
      operator delete(cars_distance._Myfirst);
  }
  v19 = this->game;
  v20 = (unsigned int *)&v49;
  v49 = 10000;
  this->formRenderStats->renderAudioTime = v19->stats.renderAudioTime;
  if ( this->physicsAvatar->physicsLateLoops < 0x2710 )
    v20 = &this->physicsAvatar->physicsLateLoops;
  this->formRenderStats->physicsLate = (float)*v20;
  if ( this->game->audioEngine )
  {
    v21 = 0;
    v22 = 0;
    cars_distance._Myfirst = 0;
    cars_distance._Mylast = 0;
    cars_distance._Myend = 0;
    v23 = this->cars._Myfirst;
    v24 = this->cars._Mylast;
    for ( LOBYTE(v61) = 3; v23 != v24; ++v23 )
    {
      if ( !CarAvatar::isConnected(*v23) )
      {
        v21 = cars_distance._Mylast;
        v22 = (ComparablePoint *)cars_distance._Myfirst;
        continue;
      }
      *(_QWORD *)&v45.x = _mm_unpacklo_ps(
                            (__m128)LODWORD((*v23)->bodyMatrix.M41),
                            (__m128)LODWORD((*v23)->bodyMatrix.M42)).m128_u64[0];
      *(float *)&imessage._Bx._Alias[8] = (*v23)->bodyMatrix.M43;
      v45.z = *(float *)&imessage._Bx._Alias[8];
      v25 = AudioEngine::listenerDistance(this->game->audioEngine, v45);
      v26 = *v23;
      v27 = cars_distance._Mylast;
      v22 = (ComparablePoint *)cars_distance._Myfirst;
      v49 = (int)v26;
      carItem.car = v26;
      distance = v25;
      carItem.dist = distance;
      if ( &carItem >= cars_distance._Mylast || cars_distance._Myfirst > &carItem )
      {
        if ( cars_distance._Mylast == cars_distance._Myend )
        {
          if ( !(cars_distance._Myend - cars_distance._Mylast) )
          {
            v33 = cars_distance._Mylast - cars_distance._Myfirst;
            if ( v33 == 0x1FFFFFFF )
LABEL_98:
              std::_Xlength_error("vector<T> too long");
            v34 = cars_distance._Myend - cars_distance._Myfirst;
            LODWORD(distance) = v33 + 1;
            if ( 0x1FFFFFFF - (v34 >> 1) >= v34 )
              v35 = (v34 >> 1) + v34;
            else
              v35 = 0;
            if ( v35 < LODWORD(distance) )
              v35 = v33 + 1;
            std::vector<ReplayLap>::_Reallocate((std::vector<SplineIndexBound> *)&cars_distance, v35);
            v27 = cars_distance._Mylast;
            v22 = (ComparablePoint *)cars_distance._Myfirst;
          }
          v26 = (CarAvatar *)v49;
        }
        if ( !v27 )
          goto LABEL_73;
        v27->car = v26;
        v32 = carItem.dist;
      }
      else
      {
        v28 = &carItem - cars_distance._Myfirst;
        v49 = v28;
        if ( cars_distance._Mylast == cars_distance._Myend )
        {
          if ( !(cars_distance._Myend - cars_distance._Mylast) )
          {
            v29 = cars_distance._Mylast - cars_distance._Myfirst;
            if ( v29 == 0x1FFFFFFF )
              goto LABEL_98;
            v30 = cars_distance._Myend - cars_distance._Myfirst;
            LODWORD(distance) = v29 + 1;
            if ( 0x1FFFFFFF - (v30 >> 1) >= v30 )
              v31 = (v30 >> 1) + v30;
            else
              v31 = 0;
            if ( v31 < LODWORD(distance) )
              v31 = v29 + 1;
            std::vector<ReplayLap>::_Reallocate((std::vector<SplineIndexBound> *)&cars_distance, v31);
            v27 = cars_distance._Mylast;
            v22 = (ComparablePoint *)cars_distance._Myfirst;
          }
          v28 = v49;
        }
        if ( !v27 )
          goto LABEL_73;
        v27->car = (CarAvatar *)v22[v28].index;
        v32 = v22[v49].distance;
      }
      v27->dist = v32;
      v27 = cars_distance._Mylast;
      v22 = (ComparablePoint *)cars_distance._Myfirst;
LABEL_73:
      v21 = v27 + 1;
      cars_distance._Mylast = v21;
    }
    std::_Sort<ComparablePoint *,int,std::less<void>>(
      v22,
      (ComparablePoint *)v21,
      ((char *)v21 - (char *)v22) >> 3,
      LOBYTE(distance));
    v36 = cars_distance._Mylast;
    v37 = cars_distance._Myfirst;
    for ( i = 0; v37 != v36; ++v37 )
    {
      v37->car->carAudioFMOD->listenerPriority = i;
      v37->car->carAudioFMOD->listenerDistance = v37->dist - v51;
      v39 = v37->car;
      v51 = v37->dist;
      if ( !CarAvatar::isInPit(v39) )
        ++i;
    }
    AudioEngine::getPerformanceStats(this->game->audioEngine, &stats);
    this->formRenderStats->fmodUpdateUsage = stats.updateCpuUsage;
    if ( this->audioPerformanceSpew )
    {
      v40 = this->game;
      *(__m128i *)shortFormat = _mm_loadu_si128((const __m128i *)aAudioPe);
      wcscpy(
        (char *)longFormat,
        L"CHANNELS: %d; CMD BUF: %4.1f%% (%5.1fms stall); HANDLE BUF: %4.1f%% (%5.1fms stall); CPU: render %5.1fms, dsp %4"
         ".1f%%, update %4.1f%%\n");
      *(__m128i *)&shortFormat[8] = _mm_loadu_si128((const __m128i *)&xmmword_8A02B8);
      *(__m128i *)&shortFormat[16] = _mm_loadu_si128((const __m128i *)&xmmword_8A02C8);
      *(__m128i *)&shortFormat[24] = _mm_loadu_si128((const __m128i *)&xmmword_8A02D8);
      *(__m128i *)&shortFormat[32] = _mm_loadu_si128((const __m128i *)&xmmword_8A02E8);
      *(__m128i *)&shortFormat[40] = _mm_loadu_si128((const __m128i *)&xmmword_8A02F8);
      swprintf_1(
        line,
        0x200u,
        longFormat,
        stats.numChannels,
        stats.commandQueueUsage,
        stats.commandQueueStallTime,
        stats.handleUsage,
        stats.handleStallTime,
        LODWORD(v40->stats.renderAudioTime),
        HIDWORD(v40->stats.renderAudioTime),
        stats.dspCpuUsage,
        stats.updateCpuUsage);
      OutputDebugStringW(line);
      swprintf_1(
        line,
        0x200u,
        shortFormat,
        stats.numChannels,
        stats.commandQueueUsage,
        stats.commandQueueStallTime,
        stats.handleUsage,
        stats.handleStallTime,
        LODWORD(this->game->stats.renderAudioTime),
        HIDWORD(this->game->stats.renderAudioTime),
        stats.dspCpuUsage,
        stats.updateCpuUsage);
      _printf("%S\n", line);
    }
    LOBYTE(v61) = 0;
    if ( cars_distance._Myfirst )
    {
      std::_Container_base0::_Orphan_all(&cars_distance);
      operator delete(cars_distance._Myfirst);
      cars_distance._Myfirst = 0;
      cars_distance._Mylast = 0;
      cars_distance._Myend = 0;
    }
  }
  if ( this->cars._Mylast - this->cars._Myfirst )
    v41 = *this->cars._Myfirst;
  else
    v41 = 0;
  if ( Trigger::ignoreSubsequentTrue(&this->changingCameraTrigger, (v41->physicsState.actionsState.state & 0x20) != 0) )
  {
    v42 = this->gameObjects._Myfirst;
    if ( v42 == this->gameObjects._Mylast )
    {
LABEL_104:
      v43 = 0;
    }
    else
    {
      while ( 1 )
      {
        v43 = (ACCameraManager *)__RTDynamicCast(
                                   *v42,
                                   0,
                                   &GameObject `RTTI Type Descriptor',
                                   &ACCameraManager `RTTI Type Descriptor',
                                   0);
        if ( v43 )
          break;
        if ( ++v42 == this->gameObjects._Mylast )
          goto LABEL_104;
      }
    }
    ACCameraManager::setMode(v43, eCockpit, 0, 0);
  }
  v44 = this->replayManager;
  if ( v44->isActive )
    ReplayManager::updatePlayState(v44, deltaT);
  v61 = -1;
  if ( f._Impl )
    ((void (__stdcall *)(bool))f._Impl->_Delete_this)(f._Impl != (std::_Func_base<void> *)&f);
}
void Sim::writeOutputJson(Sim *this)
{
  GameObject **v2; // esi
  JsonOutputFile *v3; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 != this->gameObjects._Mylast )
  {
    while ( 1 )
    {
      v3 = (JsonOutputFile *)__RTDynamicCast(
                               *v2,
                               0,
                               &GameObject `RTTI Type Descriptor',
                               &JsonOutputFile `RTTI Type Descriptor',
                               0);
      if ( v3 )
        break;
      if ( ++v2 == this->gameObjects._Mylast )
        return;
    }
    JsonOutputFile::writeOutputFile(v3);
  }
}
