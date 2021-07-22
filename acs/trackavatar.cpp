#include "trackavatar.h"
void __userpurge TrackAvatar::TrackAvatar(TrackAvatar *this@<ecx>, __m128 a2@<xmm0>, __m128 a3@<xmm3>, __m128 a4@<xmm4>, Sim *isim, const std::wstring *iunixName, const std::wstring *config)
{
  TrackAvatar *v7; // ebx
  GameObject **v8; // esi
  int v9; // eax
  std::wstring *v10; // edi
  std::_Tree_node<std::pair<std::wstring const ,std::vector<Node *> >,void *> *v11; // eax
  std::_Tree_node<std::pair<int const ,int>,void *> *v12; // eax
  bool v13; // zf
  const std::wstring *v14; // eax
  Sim *v15; // ecx
  std::wstring *v16; // eax
  std::wstring *v17; // eax
  std::wstring *v18; // eax
  const std::wstring *v19; // eax
  const std::wstring *v20; // eax
  Sim *v21; // ecx
  std::wstring *v22; // eax
  std::wstring *v23; // eax
  IdealLine *v24; // ecx
  IdealLine *v25; // eax
  IdealLine *v26; // esi
  AISpline *v27; // eax
  IdealLine *v28; // eax
  std::wstring *v29; // eax
  const std::wstring *v30; // eax
  Console *v31; // eax
  Console *v32; // eax
  DynamicTrackManager *v33; // esi
  const std::wstring *v34; // eax
  int v35; // eax
  int v36; // esi
  unsigned int v37; // eax
  TrackAudio *v38; // eax
  int v39; // eax
  int v40; // esi
  CameraFacing *v41; // eax
  int v42; // eax
  int v43; // esi
  std::wstring *v44; // eax
  const std::wstring *v45; // eax
  bool v46; // al
  double v47; // st7
  bool v48; // cf
  double v49; // st7
  int v50; // eax
  double v51; // st7
  std::wstring *v52; // eax
  const std::wstring *v53; // eax
  float v54; // edi
  std::wostream *v55; // eax
  const std::wstring *v56; // eax
  char v57; // al
  const std::wstring *v58; // eax
  const std::wstring *v59; // eax
  const std::wstring *v60; // eax
  std::wstring *v61; // esi
  std::wstring *v62; // eax
  std::wostream *v63; // eax
  Sim *v64; // eax
  int v65; // ecx
  float *v66; // esi
  Node **i; // edi
  TrackObject *v68; // ebp
  TrackObject *v69; // eax
  Game *v70; // eax
  TrackObject *v71; // ebx
  GameObject *v72; // ebp
  float v73; // eax
  TrackAvatar::{ctor}::__l41::<lambda_164f52c735376574f9762bc4ed55c4eb> *v74; // eax
  Event<OnPhysicsStepCompleted> *v75; // ecx
  AISplineRecorder *v76; // eax
  AISpline *v77; // eax
  InterpolatingSpline *v78; // eax
  AIDriver *v79; // xmm0_4
  std::wstring v80; // [esp-20h] [ebp-3BCh] BYREF
  _BYTE v81[28]; // [esp-8h] [ebp-3A4h] BYREF
  float multiplier; // [esp+14h] [ebp-388h]
  int v83; // [esp+34h] [ebp-368h] BYREF
  _BYTE *v84; // [esp+38h] [ebp-364h]
  std::wstring *_Right; // [esp+3Ch] [ebp-360h] BYREF
  unsigned int v86; // [esp+40h] [ebp-35Ch]
  AIDriver::{ctor}::__l57::<lambda_b1b5a2018750bb2261f39e860a2780a3> _Arg; // [esp+44h] [ebp-358h] BYREF
  TrackObject *to; // [esp+48h] [ebp-354h] BYREF
  TrackAvatar *v89; // [esp+4Ch] [ebp-350h]
  std::vector<Node *> ksObjs; // [esp+50h] [ebp-34Ch] BYREF
  TrackAvatar *v91; // [esp+5Ch] [ebp-340h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v92; // [esp+60h] [ebp-33Ch] BYREF
  std::wstring setName; // [esp+110h] [ebp-28Ch] BYREF
  std::wstring iname; // [esp+128h] [ebp-274h] BYREF
  std::wstring section; // [esp+140h] [ebp-25Ch] BYREF
  DebugTimer dtIdealLine; // [esp+158h] [ebp-244h] BYREF
  TrackAvatar::SectorDescription sd; // [esp+180h] [ebp-21Ch] BYREF
  std::wstring v98; // [esp+1A0h] [ebp-1FCh] BYREF
  std::wstring v99; // [esp+1B8h] [ebp-1E4h] BYREF
  std::wstring result; // [esp+1D0h] [ebp-1CCh] BYREF
  std::wstring ideal_file; // [esp+1E8h] [ebp-1B4h] BYREF
  std::wstring v102; // [esp+200h] [ebp-19Ch] BYREF
  INIReader dataIni; // [esp+218h] [ebp-184h] BYREF
  INIReader sectionsIni; // [esp+25Ch] [ebp-140h] BYREF
  INIReader ini; // [esp+2A0h] [ebp-FCh] BYREF
  DebugTimer timer; // [esp+2E4h] [ebp-B8h] BYREF
  AISpline spline; // [esp+30Ch] [ebp-90h] BYREF
  int v108; // [esp+398h] [ebp-4h]

  v7 = this;
  v89 = this;
  to = 0;
  multiplier = *(float *)&isim->game;
  v86 = 0;
  v91 = this;
  _Right = (std::wstring *)config;
  *(_DWORD *)&v81[24] = 7;
  *(_DWORD *)&v81[20] = 0;
  *(_WORD *)&v81[4] = 0;
  std::wstring::assign((std::wstring *)&v81[4], iunixName, 0, 0xFFFFFFFF);
  GameObject::GameObject(v7, *(std::wstring *)&v81[4], (Game *)LODWORD(multiplier));
  v7->__vftable = (TrackAvatar_vtbl *)&TrackAvatar::`vftable';
  v108 = 0;
  v7->trackObjects._Myfirst = 0;
  v7->trackObjects._Mylast = 0;
  v7->trackObjects._Myend = 0;
  v7->info.length = 0.0;
  multiplier = NAN;
  LOBYTE(v108) = 1;
  v7->unixName._Myres = 7;
  *(_DWORD *)&v81[24] = 0;
  v7->unixName._Mysize = 0;
  *(_DWORD *)&v81[20] = iunixName;
  v7->unixName._Bx._Buf[0] = 0;
  std::wstring::assign(&v7->unixName, *(const std::wstring **)&v81[20], *(unsigned int *)&v81[24], LODWORD(multiplier));
  v7->config._Myres = 7;
  multiplier = NAN;
  LOBYTE(v108) = 2;
  v7->config._Mysize = 0;
  *(_DWORD *)&v81[24] = 0;
  *(_DWORD *)&v81[20] = config;
  v7->config._Bx._Buf[0] = 0;
  std::wstring::assign(&v7->config, *(const std::wstring **)&v81[20], *(unsigned int *)&v81[24], LODWORD(multiplier));
  v7->playerPitPosition = 0;
  v7->sim = isim;
  v8 = isim->gameObjects._Myfirst;
  LOBYTE(v108) = 3;
  if ( v8 == isim->gameObjects._Mylast )
  {
LABEL_4:
    v9 = 0;
  }
  else
  {
    while ( 1 )
    {
      v9 = __RTDynamicCast(*v8, 0, &GameObject `RTTI Type Descriptor', &PhysicsAvatar `RTTI Type Descriptor', 0);
      if ( v9 )
        break;
      if ( ++v8 == isim->gameObjects._Mylast )
        goto LABEL_4;
    }
  }
  v10 = _Right;
  Track::Track(&v7->physicsTrack, (PhysicsEngine *)(v9 + 56), iunixName, _Right);
  LOBYTE(v108) = 4;
  v7->spawnPositions._Myhead = 0;
  v7->spawnPositions._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const,GearSetDef>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,std::vector<AudioEvent *> >> > *)&v7->spawnPositions);
  v7->spawnPositions._Myhead = v11;
  LOBYTE(v108) = 5;
  SurfacesManager::SurfacesManager(&v7->surfacesManager, v7);
  v7->igPhysicalizePrefix._Myres = 7;
  v7->igPhysicalizePrefix._Mysize = 0;
  v7->igPhysicalizePrefix._Bx._Buf[0] = 0;
  v7->spacePartitioner = 0;
  v7->lollipopCrews._Myfirst = 0;
  v7->lollipopCrews._Mylast = 0;
  v7->lollipopCrews._Myend = 0;
  v7->physicsStats.objects = 0;
  v7->physicsStats.tris = 0;
  LOBYTE(v108) = 8;
  v7->physicsStats.groups._Myhead = 0;
  v7->physicsStats.groups._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<ID3D11View * const,PPFX::IGPUSurface *>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<unsigned int const ,bool>> > *)&v7->physicsStats.groups);
  v7->physicsStats.groups._Myhead = v12;
  v7->dynamicObjects._Myfirst = 0;
  v7->dynamicObjects._Mylast = 0;
  v7->dynamicObjects._Myend = 0;
  v7->sectorDescriptions._Myfirst = 0;
  v7->sectorDescriptions._Mylast = 0;
  v7->sectorDescriptions._Myend = 0;
  LOBYTE(v108) = 11;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"TrackAvatar::TrackAvatar", 0x18u);
  LOBYTE(v108) = 12;
  DebugTimer::DebugTimer(&timer, &iname);
  LOBYTE(v108) = 14;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  v13 = v10->_Mysize == 0;
  LODWORD(multiplier) = iunixName;
  iname._Bx._Buf[0] = 0;
  *(_DWORD *)&v81[24] = L"loading track ";
  iname._Mysize = 0;
  *(_DWORD *)&v81[20] = &dtIdealLine;
  if ( v13 )
  {
    v14 = std::operator+<wchar_t>(
            *(std::wstring **)&v81[20],
            *(const wchar_t **)&v81[24],
            (const std::wstring *)LODWORD(multiplier));
    v15 = v7->sim;
    LOBYTE(v108) = 15;
    Sim::setSplashMessage(v15, v14);
  }
  else
  {
    v16 = std::operator+<wchar_t>(
            *(std::wstring **)&v81[20],
            *(const wchar_t **)&v81[24],
            (const std::wstring *)LODWORD(multiplier));
    LOBYTE(v108) = 16;
    v17 = std::operator+<wchar_t>(&result, v16, L" [");
    LOBYTE(v108) = 17;
    v18 = std::operator+<wchar_t>(&v99, v17, v10);
    LOBYTE(v108) = 18;
    v19 = std::operator+<wchar_t>(&v98, v18, L"]");
    LOBYTE(v108) = 19;
    v20 = acTranslate(&setName, v19);
    v21 = v7->sim;
    LOBYTE(v108) = 20;
    Sim::setSplashMessage(v21, v20);
    if ( setName._Myres >= 8 )
      operator delete(setName._Bx._Ptr);
    setName._Myres = 7;
    setName._Mysize = 0;
    setName._Bx._Buf[0] = 0;
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
  }
  LOBYTE(v108) = 14;
  if ( *(_DWORD *)&dtIdealLine.name._Bx._Alias[4] >= 8u )
    operator delete(dtIdealLine.__vftable);
  v7->displayList = 0;
  TrackAvatar::init3D(v7);
  TrackAvatar::initPhysics(v7, a2, a3, a4);
  TrackAvatar::initDynamicObjects(v7);
  setName._Myres = 7;
  setName._Mysize = 0;
  setName._Bx._Buf[0] = 0;
  std::wstring::assign(&setName, L"PIT", 3u);
  LOBYTE(v108) = 21;
  TrackAvatar::initRespawnPositionSet(v7, &setName);
  LOBYTE(v108) = 14;
  if ( setName._Myres >= 8 )
    operator delete(setName._Bx._Ptr);
  setName._Myres = 7;
  setName._Mysize = 0;
  setName._Bx._Buf[0] = 0;
  std::wstring::assign(&setName, L"START", 5u);
  LOBYTE(v108) = 22;
  TrackAvatar::initRespawnPositionSet(v7, &setName);
  LOBYTE(v108) = 14;
  if ( setName._Myres >= 8 )
    operator delete(setName._Bx._Ptr);
  setName._Myres = 7;
  setName._Mysize = 0;
  setName._Bx._Buf[0] = 0;
  std::wstring::assign(&setName, L"TIME_ATTACK", 0xBu);
  LOBYTE(v108) = 23;
  TrackAvatar::initRespawnPositionSet(v7, &setName);
  LOBYTE(v108) = 14;
  if ( setName._Myres >= 8 )
    operator delete(setName._Bx._Ptr);
  TrackAvatar::initTimeLines(v7);
  v22 = TrackAvatar::getDataFolder(v7, &result);
  LOBYTE(v108) = 24;
  std::operator+<wchar_t>(&ideal_file, v22, L"/data/ideal_line.ai");
  LOBYTE(v108) = 26;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  if ( Path::fileExists((unsigned int)v7, &ideal_file, 0) )
  {
    v23 = &ideal_file;
    if ( ideal_file._Myres >= 8 )
      v23 = (std::wstring *)ideal_file._Bx._Ptr;
    _printf("IDEAL LINE FROM FILE: %S\n", v23->_Bx._Buf);
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"IDEALLINE", 9u);
    LOBYTE(v108) = 27;
    DebugTimer::DebugTimer(&dtIdealLine, &iname);
    LOBYTE(v108) = 29;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    AISpline::AISpline(&spline);
    LOBYTE(v108) = 30;
    AISpline::loadFast(&spline, a3, a4, &ideal_file);
    v24 = (IdealLine *)operator new(192);
    v84 = v24;
    LOBYTE(v108) = 31;
    if ( v24 )
      IdealLine::IdealLine(v24, &spline, v7->game->graphics, &v7->physicsTrack);
    else
      v25 = 0;
    v7->idealLine = v25;
    LOBYTE(v108) = 29;
    AISpline::~AISpline(&spline);
    LOBYTE(v108) = 26;
    DebugTimer::~DebugTimer(&dtIdealLine);
  }
  else
  {
    _printf("IDEAL LINE FROM AI LINE\n");
    v26 = (IdealLine *)operator new(192);
    v84 = v26;
    LOBYTE(v108) = 32;
    if ( v26 )
    {
      v27 = AISplineRecorder::getBestLapSpline(v7->physicsTrack.aiSplineRecorder._Myptr);
      IdealLine::IdealLine(v26, v27, v7->game->graphics, &v7->physicsTrack);
    }
    else
    {
      v28 = 0;
    }
    LOBYTE(v108) = 26;
    v7->idealLine = v28;
  }
  GraphicsManager::compile(v7->game->graphics, v7->idealLine);
  v7->sim->trackNode->addChild(v7->sim->trackNode, v7->idealLine);
  v29 = TrackAvatar::getDataFolder(v7, &v98);
  LOBYTE(v108) = 33;
  v30 = std::operator+<wchar_t>(&v99, v29, L"/data/lighting.ini");
  LOBYTE(v108) = 34;
  INIReader::INIReader(&ini, v30);
  if ( v99._Myres >= 8 )
    operator delete(v99._Bx._Ptr);
  v99._Myres = 7;
  v99._Mysize = 0;
  v99._Bx._Buf[0] = 0;
  LOBYTE(v108) = 37;
  if ( v98._Myres >= 8 )
    operator delete(v98._Bx._Ptr);
  v98._Myres = 7;
  v98._Mysize = 0;
  v98._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    setName._Myres = 7;
    setName._Mysize = 0;
    setName._Bx._Buf[0] = 0;
    std::wstring::assign(&setName, L"SUN_PITCH_ANGLE", 0xFu);
    LOBYTE(v108) = 38;
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"LIGHTING", 8u);
    LOBYTE(v108) = 39;
    v7->game->graphics->lightingSettings.pitchAngle = INIReader::getFloat(&ini, &iname, &setName);
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    LOBYTE(v108) = 37;
    if ( setName._Myres >= 8 )
      operator delete(setName._Bx._Ptr);
    setName._Myres = 7;
    setName._Mysize = 0;
    setName._Bx._Buf[0] = 0;
    std::wstring::assign(&setName, L"SUN_HEADING_ANGLE", 0x11u);
    LOBYTE(v108) = 40;
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"LIGHTING", 8u);
    LOBYTE(v108) = 41;
    v7->game->graphics->lightingSettings.headingAngle = INIReader::getFloat(&ini, &iname, &setName);
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    LOBYTE(v108) = 37;
    if ( setName._Myres >= 8 )
      operator delete(setName._Bx._Ptr);
    GraphicsManager::updateLightingSetttings(v7->game->graphics);
  }
  multiplier = 1.0;
  *(_DWORD *)&v81[24] = 0;
  v84 = v81;
  *(_DWORD *)v81 = &std::_Func_impl<std::_Callable_obj<_lambda_2259c22871515b6b451fb08af0faad6d_,0>,std::allocator<std::_Func_class<void,SVar *,float>>,void,SVar *,float>::`vftable';
  *(_DWORD *)&v81[4] = v7;
  *(_DWORD *)&v81[16] = v81;
  LOBYTE(v108) = 43;
  *(float *)&_Arg.__this = COERCE_FLOAT(&v80);
  v80._Myres = 7;
  v80._Mysize = 0;
  v80._Bx._Buf[0] = 0;
  std::wstring::assign(&v80, L"sunHeading", 0xAu);
  LOBYTE(v108) = 44;
  v31 = Console::singleton();
  LOBYTE(v108) = 37;
  Console::addVarLambda(v31, v80, *(std::function<void __cdecl(SVar *,float)> *)v81, v81[24], multiplier);
  multiplier = 1.0;
  *(_DWORD *)&v81[24] = 0;
  v84 = v81;
  *(_DWORD *)v81 = &std::_Func_impl<std::_Callable_obj<_lambda_d35ceb4ae4a47dbde23c91dd18924e8d_,0>,std::allocator<std::_Func_class<void,SVar *,float>>,void,SVar *,float>::`vftable';
  *(_DWORD *)&v81[4] = v7;
  *(_DWORD *)&v81[16] = v81;
  LOBYTE(v108) = 46;
  *(float *)&_Arg.__this = COERCE_FLOAT(&v80);
  std::wstring::wstring(&v80, L"sunPitch");
  LOBYTE(v108) = 47;
  v32 = Console::singleton();
  LOBYTE(v108) = 37;
  Console::addVarLambda(v32, v80, *(std::function<void __cdecl(SVar *,float)> *)v81, v81[24], multiplier);
  v33 = (DynamicTrackManager *)operator new(84);
  v84 = v33;
  LOBYTE(v108) = 48;
  if ( v33 )
  {
    v34 = TrackAvatar::getDataFolder(v7, (std::wstring *)&dtIdealLine);
    LOBYTE(v108) = 49;
    LODWORD(multiplier) = v34;
    *(_DWORD *)&v81[24] = v7->sim;
    v86 = 1;
    to = (TrackObject *)1;
    DynamicTrackManager::DynamicTrackManager(v33, *(Sim **)&v81[24], v34);
    v36 = v35;
  }
  else
  {
    v36 = 0;
  }
  v108 = 50;
  _Right = (std::wstring *)v36;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&v7->gameObjects,
    (ICollisionObject *const *)&_Right);
  v37 = v86;
  *(float *)(v36 + 36) = *(float *)&v7;
  v7->dynamicTrackManager = (DynamicTrackManager *)v36;
  v108 = 37;
  if ( (v37 & 1) != 0 )
  {
    v86 = v37 & 0xFFFFFFFE;
    if ( *(_DWORD *)&dtIdealLine.name._Bx._Alias[4] >= 8u )
      operator delete(dtIdealLine.__vftable);
  }
  v38 = (TrackAudio *)operator new(96);
  v84 = v38;
  LOBYTE(v108) = 51;
  if ( v38 )
  {
    TrackAudio::TrackAudio(v38, v7, v7->sim);
    v40 = v39;
  }
  else
  {
    v40 = 0;
  }
  LOBYTE(v108) = 37;
  _Right = (std::wstring *)v40;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&v7->gameObjects,
    (ICollisionObject *const *)&_Right);
  LODWORD(multiplier) = 52;
  *(float *)(v40 + 36) = *(float *)&v7;
  v41 = (CameraFacing *)operator new(LODWORD(multiplier));
  v84 = v41;
  LOBYTE(v108) = 52;
  if ( v41 )
  {
    CameraFacing::CameraFacing(v41, v7, v7->sim);
    v43 = v42;
  }
  else
  {
    v43 = 0;
  }
  LOBYTE(v108) = 37;
  _Right = (std::wstring *)v43;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&v7->gameObjects,
    (ICollisionObject *const *)&_Right);
  *(float *)(v43 + 36) = *(float *)&v7;
  v44 = TrackAvatar::getDataFolder(v7, &v102);
  LOBYTE(v108) = 53;
  v45 = std::operator+<wchar_t>(&iname, v44, L"/data/data.ini");
  LOBYTE(v108) = 54;
  INIReader::INIReader(&dataIni, v45);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  LOBYTE(v108) = 57;
  if ( v102._Myres >= 8 )
    operator delete(v102._Bx._Ptr);
  v102._Myres = 7;
  v102._Mysize = 0;
  v102._Bx._Buf[0] = 0;
  if ( !dataIni.ready
    || (std::wstring::wstring(&section, L"POSITION"),
        LOBYTE(v108) = 58,
        v86 |= 2u,
        to = (TrackObject *)v86,
        v46 = INIReader::hasSection(&dataIni, &section),
        HIBYTE(v83) = 1,
        !v46) )
  {
    HIBYTE(v83) = 0;
  }
  v108 = 57;
  if ( (v86 & 2) != 0 && section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( HIBYTE(v83) )
  {
    std::wstring::wstring(&section, L"LATITUDE");
    LOBYTE(v108) = 59;
    std::wstring::wstring(&setName, L"POSITION");
    LOBYTE(v108) = 60;
    v47 = INIReader::getFloat(&dataIni, &setName, &section);
    v48 = setName._Myres < 8;
    v7->trackLocation.latitude = v47;
    if ( !v48 )
      operator delete(setName._Bx._Ptr);
    setName._Myres = 7;
    setName._Mysize = 0;
    setName._Bx._Buf[0] = 0;
    LOBYTE(v108) = 57;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    std::wstring::wstring(&section, L"LONGITUDE");
    LOBYTE(v108) = 61;
    std::wstring::wstring(&setName, L"POSITION");
    LOBYTE(v108) = 62;
    v49 = INIReader::getFloat(&dataIni, &setName, &section);
    v48 = setName._Myres < 8;
    v7->trackLocation.longitude = v49;
    if ( !v48 )
      operator delete(setName._Bx._Ptr);
    setName._Myres = 7;
    setName._Mysize = 0;
    setName._Bx._Buf[0] = 0;
    LOBYTE(v108) = 57;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    std::wstring::wstring(&section, L"GMT");
    LOBYTE(v108) = 63;
    std::wstring::wstring(&setName, L"POSITION");
    LOBYTE(v108) = 64;
    v50 = INIReader::getInt(&dataIni, &setName, &section);
    v48 = setName._Myres < 8;
    v7->trackLocation.gmt = v50;
    if ( !v48 )
      operator delete(setName._Bx._Ptr);
    setName._Myres = 7;
    setName._Mysize = 0;
    setName._Bx._Buf[0] = 0;
    LOBYTE(v108) = 57;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    std::wstring::wstring(&section, L"NORD_OFFSET");
    LOBYTE(v108) = 65;
    std::wstring::wstring(&setName, L"POSITION");
    LOBYTE(v108) = 66;
    v51 = INIReader::getFloat(&dataIni, &setName, &section);
    v48 = setName._Myres < 8;
    v7->trackLocation.nordOffset = v51;
    if ( !v48 )
      operator delete(setName._Bx._Ptr);
    setName._Myres = 7;
    setName._Mysize = 0;
    setName._Bx._Buf[0] = 0;
    LOBYTE(v108) = 57;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  else
  {
    _printf("WARNING: TRACK :: NO POSITION DATA FOUND\n");
    v7->trackLocation.gmt = 0;
    *(_OWORD *)&v7->trackLocation.longitude = 0i64;
    v7->trackLocation.nordOffset = 0.0;
  }
  v52 = TrackAvatar::getDataFolder(v7, &section);
  LOBYTE(v108) = 67;
  v53 = std::operator+<wchar_t>(&setName, v52, L"/data/sections.ini");
  LOBYTE(v108) = 68;
  INIReader::INIReader(&sectionsIni, v53);
  if ( setName._Myres >= 8 )
    operator delete(setName._Bx._Ptr);
  setName._Myres = 7;
  setName._Mysize = 0;
  setName._Bx._Buf[0] = 0;
  LOBYTE(v108) = 71;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  if ( sectionsIni.ready )
  {
    v54 = 0.0;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>(
      &v92,
      3,
      1);
    multiplier = 0.0;
    LOBYTE(v108) = 72;
    v55 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v92.gap10, "SECTION_");
    std::wostream::operator<<(v55, LODWORD(multiplier));
    while ( 1 )
    {
      v56 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
              &v92,
              (std::wstring *)&dtIdealLine);
      LOBYTE(v108) = 73;
      v57 = INIReader::hasSection(&sectionsIni, v56);
      HIBYTE(v83) = v57;
      if ( *(_DWORD *)&dtIdealLine.name._Bx._Alias[4] >= 8u )
      {
        operator delete(dtIdealLine.__vftable);
        v57 = HIBYTE(v83);
      }
      if ( !v57 )
        break;
      sd.in = 0.0;
      sd.out = 0.0;
      sd.text._Myres = 7;
      sd.text._Mysize = 0;
      sd.text._Bx._Buf[0] = 0;
      LOBYTE(v108) = 74;
      std::wstring::wstring(&setName, L"IN");
      LOBYTE(v108) = 75;
      v58 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v92, &section);
      LOBYTE(v108) = 76;
      sd.in = INIReader::getFloat(&sectionsIni, v58, &setName);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v108) = 74;
      if ( setName._Myres >= 8 )
        operator delete(setName._Bx._Ptr);
      std::wstring::wstring(&setName, L"OUT");
      LOBYTE(v108) = 77;
      v59 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v92, &section);
      LOBYTE(v108) = 78;
      sd.out = INIReader::getFloat(&sectionsIni, v59, &setName);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v108) = 74;
      if ( setName._Myres >= 8 )
        operator delete(setName._Bx._Ptr);
      std::wstring::wstring((std::wstring *)&dtIdealLine, L"TEXT");
      LOBYTE(v108) = 79;
      v60 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v92, &setName);
      LOBYTE(v108) = 80;
      v61 = INIReader::getString(&sectionsIni, &section, v60, (const std::wstring *)&dtIdealLine);
      if ( &sd.text != v61 )
      {
        if ( sd.text._Myres >= 8 )
          operator delete(sd.text._Bx._Ptr);
        sd.text._Myres = 7;
        sd.text._Mysize = 0;
        sd.text._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&sd.text, v61);
      }
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( setName._Myres >= 8 )
        operator delete(setName._Bx._Ptr);
      setName._Myres = 7;
      setName._Mysize = 0;
      setName._Bx._Buf[0] = 0;
      LOBYTE(v108) = 74;
      if ( *(_DWORD *)&dtIdealLine.name._Bx._Alias[4] >= 8u )
        operator delete(dtIdealLine.__vftable);
      std::vector<TrackAvatar::SectorDescription>::push_back(&v7->sectorDescriptions, &sd);
      ++LODWORD(v54);
      std::wstring::wstring(&setName, word_17BE9D8);
      LOBYTE(v108) = 81;
      std::wstringbuf::_Tidy((std::wstringbuf *)&v92.gap10[8]);
      multiplier = *(float *)&v92.gap10[68];
      v62 = &setName;
      *(_DWORD *)&v81[24] = setName._Mysize;
      if ( setName._Myres >= 8 )
        v62 = (std::wstring *)setName._Bx._Ptr;
      std::wstringbuf::_Init(
        (std::wstringbuf *)&v92.gap10[8],
        v62->_Bx._Buf,
        *(unsigned int *)&v81[24],
        SLODWORD(multiplier));
      LOBYTE(v108) = 74;
      if ( setName._Myres >= 8 )
        operator delete(setName._Bx._Ptr);
      multiplier = v54;
      v63 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v92.gap10, "SECTION_");
      std::wostream::operator<<(v63, LODWORD(multiplier));
      LOBYTE(v108) = 72;
      if ( sd.text._Myres >= 8 )
        operator delete(sd.text._Bx._Ptr);
    }
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v92);
  }
  ksObjs._Myfirst = 0;
  ksObjs._Mylast = 0;
  ksObjs._Myend = 0;
  LOBYTE(v108) = 82;
  std::wstring::wstring((std::wstring *)&dtIdealLine, L"AC_POBJECT");
  v64 = v7->sim;
  LOBYTE(v108) = 83;
  v64->trackNode->findChildrenByPrefix(v64->trackNode, (const std::wstring *)&dtIdealLine, &ksObjs);
  LOBYTE(v108) = 82;
  if ( *(_DWORD *)&dtIdealLine.name._Bx._Alias[4] >= 8u )
    operator delete(dtIdealLine.__vftable);
  v66 = (float *)ksObjs._Myfirst;
  for ( i = ksObjs._Mylast; v66 != (float *)i; *(_BYTE *)(LODWORD(v73) + 184) = 1 )
  {
    v68 = (TrackObject *)operator new(148);
    v84 = v68;
    LOBYTE(v108) = 84;
    if ( v68 )
    {
      multiplier = *v66;
      *(_DWORD *)&v81[24] = v7->sim;
      *(_DWORD *)&v81[20] = 7;
      *(_DWORD *)&v81[16] = 0;
      *(_WORD *)v81 = 0;
      std::wstring::assign((std::wstring *)v81, (const std::wstring *)(LODWORD(multiplier) + 160), 0, 0xFFFFFFFF);
      TrackObject::TrackObject(v68, *(std::wstring *)v81, *(Sim **)&v81[24], (Node *)LODWORD(multiplier));
    }
    else
    {
      v69 = 0;
    }
    to = v69;
    LOBYTE(v108) = 82;
    std::vector<SpinnerData *>::push_back(
      (std::vector<ICollisionObject *> *)&v7->trackObjects,
      (ICollisionObject *const *)&to);
    v70 = v7->game;
    v71 = to;
    _Right = (std::wstring *)to;
    v72 = v70->root;
    std::vector<SpinnerData *>::push_back(
      (std::vector<ICollisionObject *> *)&v72->gameObjects,
      (ICollisionObject *const *)&_Right);
    v71->parent = v72;
    v73 = *v66++;
    v7 = v89;
  }
  LODWORD(multiplier) = v7;
  _Arg.__this = (AIDriver *)v7;
  v84 = &v81[4];
  *(_DWORD *)&v81[20] = 0;
  *(_DWORD *)v81 = v65;
  LOBYTE(v108) = 85;
  std::allocator<std::_Func_class<void,SessionInfo const &>>::allocator<std::_Func_class<void,SessionInfo const &>>(
    (std::allocator<std::_Func_class<void,SessionInfo const &> > *)v81,
    (const std::allocator<std::_Func_class<void,SessionInfo const &> > *)&v83 + 3);
  v74 = (TrackAvatar::{ctor}::__l41::<lambda_164f52c735376574f9762bc4ed55c4eb> *)std::forward<_lambda_b1b5a2018750bb2261f39e860a2780a3_>(&_Arg);
  std::_Func_class<void,OnNewSessionEvent const &>::_Do_alloc<std::_Func_impl<std::_Callable_obj<_lambda_164f52c735376574f9762bc4ed55c4eb_,0>,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>,void,OnNewSessionEvent const &>,_lambda_164f52c735376574f9762bc4ed55c4eb_,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>>(
    (std::_Func_class<void,OnNewSessionEvent const &> *)&v81[4],
    v74,
    (std::allocator<std::_Func_class<void,OnNewSessionEvent const &> >)v81[0]);
  v75 = (Event<OnPhysicsStepCompleted> *)&v7->sim->evOnNewSession;
  LOBYTE(v108) = 82;
  Event<std::wstring>::addHandler(
    v75,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v81[4],
    (void *)LODWORD(multiplier));
  v76 = (AISplineRecorder *)std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef>>>::operator*((std::_Vector_iterator<std::_Vector_val<std::_Simple_types<TyreCompoundDef> > > *)&v7->physicsTrack.aiSplineRecorder);
  v77 = AISplineRecorder::getBestLapSpline(v76);
  if ( v77 )
  {
    v78 = AISpline::getBaseSpline(v77);
    *(float *)&_Arg.__this = Spline::length(v78);
    v79 = _Arg.__this;
    v7->info.length = *(float *)&_Arg.__this;
    _printf("TRACK LENGTH: %f\n", *(float *)&v79);
  }
  Sim::unloadMeshResources(v7->sim, v7->sim->trackNode);
  std::vector<std::pair<int,float>>::~vector<std::pair<int,float>>((std::vector<SplineIndexBound> *)&ksObjs);
  LOBYTE(v108) = 57;
  INIReader::~INIReader(&sectionsIni);
  LOBYTE(v108) = 37;
  INIReader::~INIReader(&dataIni);
  LOBYTE(v108) = 26;
  INIReader::~INIReader(&ini);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&ideal_file);
  LOBYTE(v108) = 11;
  DebugTimer::~DebugTimer(&timer);
}
void TrackAvatar::~TrackAvatar(TrackAvatar *this)
{
  bool v2; // zf
  std::vector<TrackAvatar::SectorDescription> *v3; // esi
  std::vector<DynamicTrackObject> *v4; // esi
  std::vector<LollipopCrew *> *v5; // esi
  std::_Tree_node<std::pair<std::wstring const ,std::vector<Node *> >,void *> *v6; // [esp-4h] [ebp-28h]
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,bool> > > > result; // [esp+14h] [ebp-10h] BYREF
  int v8; // [esp+20h] [ebp-4h]

  this->__vftable = (TrackAvatar_vtbl *)&TrackAvatar::`vftable';
  v2 = this->sectorDescriptions._Myfirst == 0;
  v3 = &this->sectorDescriptions;
  v8 = 5;
  if ( !v2 )
  {
    std::_Container_base0::_Orphan_all(&this->sectorDescriptions);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<TrackAvatar::SectorDescription>>>(
      (SGearRatio *)v3->_Myfirst,
      (SGearRatio *)v3->_Mylast);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    v3->_Mylast = 0;
    v3->_Myend = 0;
  }
  v4 = &this->dynamicObjects;
  if ( this->dynamicObjects._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->dynamicObjects);
    operator delete(v4->_Myfirst);
    v4->_Myfirst = 0;
    this->dynamicObjects._Mylast = 0;
    this->dynamicObjects._Myend = 0;
  }
  std::_Tree<std::_Tmap_traits<unsigned int,bool,std::less<unsigned int>,std::allocator<std::pair<unsigned int const,bool>>,0>>::erase(
    (std::_Tree<std::_Tmap_traits<unsigned int,bool,std::less<unsigned int>,std::allocator<std::pair<unsigned int const ,bool> >,0> > *)&this->physicsStats.groups,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,bool> > > >)this->physicsStats.groups._Myhead->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<unsigned int const ,bool> > > >)this->physicsStats.groups._Myhead);
  operator delete(this->physicsStats.groups._Myhead);
  v5 = &this->lollipopCrews;
  if ( this->lollipopCrews._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->lollipopCrews);
    operator delete(v5->_Myfirst);
    v5->_Myfirst = 0;
    this->lollipopCrews._Mylast = 0;
    this->lollipopCrews._Myend = 0;
  }
  if ( this->igPhysicalizePrefix._Myres >= 8 )
    operator delete(this->igPhysicalizePrefix._Bx._Ptr);
  this->igPhysicalizePrefix._Myres = 7;
  this->igPhysicalizePrefix._Mysize = 0;
  this->igPhysicalizePrefix._Bx._Buf[0] = 0;
  SurfacesManager::~SurfacesManager(&this->surfacesManager);
  v6 = this->spawnPositions._Myhead;
  LOBYTE(v8) = 4;
  std::_Tree<std::_Tmap_traits<std::wstring,std::vector<Node *>,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,std::vector<Node *>>>,0>>::erase(
    &this->spawnPositions,
    (std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,std::vector<Node *> > > > > *)&result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,std::vector<Node *> > > > >)v6->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,std::vector<Node *> > > > >)v6);
  operator delete(this->spawnPositions._Myhead);
  LOBYTE(v8) = 3;
  Track::~Track(&this->physicsTrack);
  if ( this->config._Myres >= 8 )
    operator delete(this->config._Bx._Ptr);
  this->config._Myres = 7;
  this->config._Mysize = 0;
  this->config._Bx._Buf[0] = 0;
  if ( this->unixName._Myres >= 8 )
    operator delete(this->unixName._Bx._Ptr);
  this->unixName._Myres = 7;
  this->unixName._Mysize = 0;
  this->unixName._Bx._Buf[0] = 0;
  LOBYTE(v8) = 0;
  if ( this->trackObjects._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->trackObjects);
    operator delete(this->trackObjects._Myfirst);
    this->trackObjects._Myfirst = 0;
    this->trackObjects._Mylast = 0;
    this->trackObjects._Myend = 0;
  }
  v8 = -1;
  GameObject::~GameObject(this);
}
TrackAvatar *TrackAvatar::`scalar deleting destructor'(TrackAvatar *this, unsigned int a2)
{
  TrackAvatar::~TrackAvatar(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void TrackAvatar::addPhysicsMesh(TrackAvatar *this, Mesh *mesh, unsigned int sector_id)
{
  TrackAvatar *v3; // ebx
  signed int v4; // esi
  int v5; // edi
  int v6; // ebx
  MeshVertex *v7; // edx
  vec3f *v8; // ecx
  std::wstring *v9; // esi
  unsigned int v10; // edi
  unsigned int v11; // ecx
  std::wstring v12; // [esp-18h] [ebp-124h] BYREF
  TrackAvatar *v13; // [esp+14h] [ebp-F8h]
  std::vector<vec3f> vertices; // [esp+18h] [ebp-F4h] BYREF
  NKUtils nku; // [esp+24h] [ebp-E8h] BYREF
  SurfaceDef sd; // [esp+28h] [ebp-E4h] BYREF
  std::wstring iname; // [esp+E4h] [ebp-28h] BYREF
  int v18; // [esp+108h] [ebp-4h]

  v3 = this;
  v13 = this;
  v4 = mesh->vertices._Mylast - mesh->vertices._Myfirst;
  std::vector<vec3f>::vector<vec3f>(&vertices, v4);
  v18 = 0;
  NKUtils::NKUtils(&nku);
  LOBYTE(v18) = 1;
  if ( v4 )
  {
    mesh->isStatic = 1;
    if ( v4 > 0 )
    {
      v5 = 0;
      v6 = 0;
      do
      {
        v7 = mesh->vertices._Myfirst;
        ++v6;
        v8 = vertices._Myfirst;
        *(_QWORD *)&vertices._Myfirst[v5++].x = *(_QWORD *)&v7[v6 - 1].pos.x;
        v8[v5 - 1].z = v7[v6 - 1].pos.z;
        --v4;
      }
      while ( v4 );
      v3 = v13;
    }
    v9 = &mesh->name;
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, &mesh->name, 0, 0xFFFFFFFF);
    TrackAvatar::getSurfaceDescFromMeshName(v3, &sd, v12);
    v10 = sector_id;
    sd.userPointer = mesh;
    if ( sd.collisionCategory == 2 )
      v10 = sector_id + 10000;
    if ( mesh->name._Myres >= 8 )
      v9 = (std::wstring *)v9->_Bx._Ptr;
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    if ( v9->_Bx._Buf[0] )
      v11 = wcslen(v9->_Bx._Buf);
    else
      v11 = 0;
    std::wstring::assign(&iname, v9->_Bx._Buf, v11);
    v12._Myres = v10;
    v12._Mysize = (unsigned int)&sd;
    *(_DWORD *)&v12._Bx._Alias[12] = mesh->indices._Mylast - mesh->indices._Myfirst;
    *(_DWORD *)&v12._Bx._Alias[8] = mesh->indices._Myfirst;
    LOBYTE(v18) = 2;
    Track::addSurface(
      &v3->physicsTrack,
      &iname,
      &vertices._Myfirst->x,
      vertices._Mylast - vertices._Myfirst,
      *(unsigned __int16 **)&v12._Bx._Alias[8],
      *(int *)&v12._Bx._Alias[12],
      &sd,
      v10);
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  LOBYTE(v18) = 0;
  NKUtils::~NKUtils(&nku);
  v18 = -1;
  if ( vertices._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&vertices);
    operator delete(vertices._Myfirst);
  }
}
AISpline *TrackAvatar::getAISpline(TrackAvatar *this)
{
  return AISplineRecorder::getBestLapSpline(this->physicsTrack.aiSplineRecorder._Myptr);
}
std::wstring *TrackAvatar::getConfig(TrackAvatar *this, std::wstring *result)
{
  result->_Myres = 7;
  result->_Mysize = 0;
  result->_Bx._Buf[0] = 0;
  std::wstring::assign(result, &this->config, 0, 0xFFFFFFFF);
  return result;
}
std::wstring *TrackAvatar::getDataFolder(TrackAvatar *this, std::wstring *result)
{
  Track::getDataFolder(&this->physicsTrack, result);
  return result;
}
int TrackAvatar::getMaxSlotsAvailable(TrackAvatar *this, const std::wstring *setName)
{
  std::vector<Node *> *v2; // eax

  v2 = std::map<std::wstring,std::vector<Node *>>::operator[](&this->spawnPositions, setName);
  return v2->_Mylast - v2->_Myfirst;
}
std::wstring *TrackAvatar::getSectorDescription(TrackAvatar *this, std::wstring *result, float normalizedPosition)
{
  TrackAvatar::SectorDescription *v3; // esi
  TrackAvatar::SectorDescription *v4; // edi
  float v5; // xmm0_4
  TrackAvatar::SectorDescription sd; // [esp+14h] [ebp-30h] BYREF
  int v8; // [esp+40h] [ebp-4h]

  v3 = this->sectorDescriptions._Myfirst;
  v4 = this->sectorDescriptions._Mylast;
  if ( v3 == v4 )
  {
LABEL_7:
    result->_Myres = 7;
    result->_Mysize = 0;
    result->_Bx._Buf[0] = 0;
    std::wstring::assign(result, word_17BE9D8, 0);
  }
  else
  {
    while ( 1 )
    {
      sd.in = v3->in;
      v5 = v3->out;
      sd.text._Bx._Buf[0] = 0;
      sd.text._Myres = 7;
      sd.text._Mysize = 0;
      std::wstring::assign(&sd.text, &v3->text, 0, 0xFFFFFFFF);
      v8 = 0;
      if ( normalizedPosition > sd.in && v5 > normalizedPosition )
        break;
      v8 = -1;
      if ( sd.text._Myres >= 8 )
        operator delete(sd.text._Bx._Ptr);
      if ( ++v3 == v4 )
        goto LABEL_7;
    }
    result->_Myres = 7;
    result->_Mysize = 0;
    result->_Bx._Buf[0] = 0;
    std::wstring::assign(result, &sd.text, 0, 0xFFFFFFFF);
    if ( sd.text._Myres >= 8 )
      operator delete(sd.text._Bx._Ptr);
  }
  return result;
}
mat44f *TrackAvatar::getSpawnPosition(TrackAvatar *this, mat44f *result, const std::wstring *setName, unsigned int index)
{
  const std::wstring *v4; // esi
  std::map<std::wstring,std::vector<Node *>> *v5; // edi
  std::vector<Node *> *v6; // eax
  Node *v7; // ecx
  mat44f *v8; // eax
  std::vector<Node *> *v9; // eax
  mat44f mat; // [esp+Ch] [ebp-40h] BYREF

  v4 = setName;
  v5 = &this->spawnPositions;
  v6 = std::map<std::wstring,std::vector<Node *>>::operator[](&this->spawnPositions, setName);
  if ( index >= v6->_Mylast - v6->_Myfirst )
  {
    v9 = std::map<std::wstring,std::vector<Node *>>::operator[](v5, setName);
    if ( setName->_Myres >= 8 )
      v4 = (const std::wstring *)setName->_Bx._Ptr;
    _printf(
      "ERROR: REQUESTING SPAWN SET %S POSITION:%u  BUT ONLY %d\n",
      v4->_Bx._Buf,
      index,
      v9->_Mylast - v9->_Myfirst);
    mat44f::mat44f(&mat);
    mat44f::loadIdentity(&mat);
    v8 = result;
    *(__m128i *)&result->M11 = _mm_loadu_si128((const __m128i *)&mat);
    *(__m128i *)&result->M21 = _mm_loadu_si128((const __m128i *)&mat.M21);
    *(__m128i *)&result->M31 = _mm_loadu_si128((const __m128i *)&mat.M31);
    *(__m128i *)&result->M41 = _mm_loadu_si128((const __m128i *)&mat.M41);
  }
  else
  {
    v7 = std::map<std::wstring,std::vector<Node *>>::operator[](v5, setName)->_Myfirst[index];
    v8 = result;
    *(__m128i *)&result->M11 = _mm_loadu_si128((const __m128i *)&v7->matrix);
    *(__m128i *)&result->M21 = _mm_loadu_si128((const __m128i *)&v7->matrix.M21);
    *(__m128i *)&result->M31 = _mm_loadu_si128((const __m128i *)&v7->matrix.M31);
    *(__m128i *)&result->M41 = _mm_loadu_si128((const __m128i *)&v7->matrix.M41);
  }
  return v8;
}
AISplineRecorder *TrackAvatar::getSplineRecorder(TrackAvatar *this)
{
  return this->physicsTrack.aiSplineRecorder._Myptr;
}
SurfaceDef *TrackAvatar::getSurfaceDescFromMeshName(TrackAvatar *this, SurfaceDef *result, std::wstring meshname)
{
  std::wstring *v3; // ecx
  std::wstring *v4; // edi
  wchar_t *v5; // eax
  std::wstring *v6; // ecx
  std::wstring *v7; // esi
  int *v8; // eax
  int v9; // edi
  bool v10; // cf
  SurfaceDef *v11; // eax
  Console *v12; // eax
  Console *v13; // eax
  std::wstring v14; // [esp-18h] [ebp-1CCh] BYREF
  int v15; // [esp+0h] [ebp-1B4h] BYREF
  SurfaceDef sd; // [esp+10h] [ebp-1A4h] BYREF
  std::wstring *failMessage; // [esp+D0h] [ebp-E4h]
  TrackAvatar *v18; // [esp+D4h] [ebp-E0h]
  SurfaceDef *v19; // [esp+D8h] [ebp-DCh]
  std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > > v20; // [esp+DCh] [ebp-D8h] BYREF
  wchar_t *EndPtr; // [esp+E0h] [ebp-D4h] BYREF
  SurfaceDef v22; // [esp+E4h] [ebp-D0h] BYREF
  std::wstring v23; // [esp+184h] [ebp-30h] BYREF
  std::wstring v24; // [esp+19Ch] [ebp-18h] BYREF

  *(_DWORD *)&v24._Bx._Alias[8] = &v15;
  EndPtr = (wchar_t *)this;
  v18 = this;
  v19 = result;
  v24._Myres = 0;
  SurfaceDef::SurfaceDef(&sd);
  v3 = &meshname;
  v4 = &meshname;
  if ( meshname._Myres >= 8 )
    v3 = (std::wstring *)meshname._Bx._Ptr;
  if ( meshname._Myres >= 8 )
    v4 = (std::wstring *)meshname._Bx._Ptr;
  v5 = &v3->_Bx._Buf[meshname._Mysize];
  v6 = &meshname;
  if ( meshname._Myres >= 8 )
    v6 = (std::wstring *)meshname._Bx._Ptr;
  if ( v6 != (std::wstring *)v5 )
    std::_Transform<wchar_t *,std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t>>>,int (__cdecl *)(int)>(
      &v20,
      v6->_Bx._Buf,
      v5,
      (std::_String_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v4,
      _toupper);
  LOBYTE(v24._Myres) = 1;
  v14._Myres = 7;
  v14._Mysize = 0;
  v14._Bx._Buf[0] = 0;
  std::wstring::assign(&v14, &meshname, 0, 0xFFFFFFFF);
  qmemcpy(&sd, SurfacesManager::getSurface((SurfacesManager *)(EndPtr + 204), &v22, v14), sizeof(sd));
  v7 = &meshname;
  if ( meshname._Myres >= 8 )
    v7 = (std::wstring *)meshname._Bx._Ptr;
  v8 = __errno();
  v14._Myres = 10;
  *v8 = 0;
  v9 = _wcstol(v7->_Bx._Buf, &EndPtr, v14._Myres);
  if ( v7 == (std::wstring *)EndPtr )
    std::_Xinvalid_argument((const char *)&stru_17C4688);
  if ( *__errno() == 34 )
  {
    std::_Xout_of_range((const char *)&stru_17C4688.name._Myres);
    v20._Ptr = (const wchar_t *)&v24;
    std::wstring::wstring(&v24, L"\n");
    LOBYTE(v24._Myres) = 3;
    EndPtr = (wchar_t *)&v23;
    std::wstring::wstring(&v23, failMessage);
    LOBYTE(v24._Myres) = 4;
    v12 = Sim::getConsole(v18->sim);
    LOBYTE(v24._Myres) = 3;
    v13 = Console::operator<<(v12, v23);
    LOBYTE(v24._Myres) = 2;
    Console::operator<<(v13, v24);
    v24._Myres = 0;
    sd.gripMod = 1.0;
    sd.sectorID = std::stoi(&meshname, 0, 10);
    SurfaceDef::SurfaceDef(v19, &sd);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&meshname);
    v11 = v19;
  }
  else
  {
    v10 = meshname._Myres < 8;
    sd.sectorID = v9;
    result->collisionCategory = 0;
    result->damping = 0.0;
    result->granularity = 0.0;
    result->vibrationGain = 0.0;
    result->vibrationLength = 1.5;
    qmemcpy(result, &sd, sizeof(SurfaceDef));
    if ( !v10 )
      operator delete(meshname._Bx._Ptr);
    v11 = result;
  }
  return v11;
}
void TrackAvatar::init3D(TrackAvatar *this)
{
  TrackAvatar *v1; // ebp
  int v2; // ebx
  Model *v3; // esi
  Model *v4; // eax
  const std::wstring *v5; // esi
  std::wstring *v6; // eax
  std::wstring *v7; // eax
  std::wstring *v8; // eax
  Game *v9; // eax
  unsigned int v10; // ebp
  std::wostream *v11; // eax
  const std::wstring *v12; // eax
  bool v13; // bl
  const std::wstring *v14; // eax
  std::wstring *v15; // eax
  std::wstring *v16; // eax
  std::wstring *v17; // eax
  std::wstring *v18; // edi
  std::wstring *v19; // esi
  std::wstring *v20; // ecx
  int v21; // edi
  std::wstring *v22; // eax
  int v23; // eax
  bool v24; // zf
  std::wstring *v25; // eax
  std::wstring *v26; // esi
  std::wstring *v27; // eax
  std::wstring *v28; // eax
  std::wstring *v29; // eax
  std::wstring *v30; // eax
  int v31; // edi
  std::wstring *v32; // eax
  std::wstring *v33; // esi
  std::wstring *v34; // eax
  std::wstring *v35; // eax
  std::wstring *v36; // esi
  __m128 v37; // xmm1
  __m128 v38; // xmm2
  float v39; // xmm3_4
  Model *v41; // eax
  const mat44f *v42; // eax
  int v43; // eax
  Model *v44; // eax
  std::wstring *v45; // eax
  bool v46; // cf
  std::wstring v47; // [esp-10h] [ebp-430h] BYREF
  int v48; // [esp+20h] [ebp-400h]
  const std::wstring *v49; // [esp+24h] [ebp-3FCh]
  TrackAvatar *v50; // [esp+28h] [ebp-3F8h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v51; // [esp+2Ch] [ebp-3F4h] BYREF
  mat44f mat; // [esp+DCh] [ebp-344h] BYREF
  mat44f v53; // [esp+11Ch] [ebp-304h] BYREF
  std::wstring key; // [esp+15Ch] [ebp-2C4h] BYREF
  std::wstring v55; // [esp+174h] [ebp-2ACh] BYREF
  std::wstring iname; // [esp+18Ch] [ebp-294h] BYREF
  std::wstring v57; // [esp+1A4h] [ebp-27Ch] BYREF
  std::wstring v58; // [esp+1BCh] [ebp-264h] BYREF
  std::wstring models_filename; // [esp+1D4h] [ebp-24Ch] BYREF
  std::wstring section; // [esp+1ECh] [ebp-234h] BYREF
  std::wstring filename; // [esp+204h] [ebp-21Ch] BYREF
  vec3f pos; // [esp+21Ch] [ebp-204h] BYREF
  __int64 v63; // [esp+228h] [ebp-1F8h]
  unsigned int v64; // [esp+230h] [ebp-1F0h]
  vec3f rot; // [esp+234h] [ebp-1ECh] BYREF
  int v66; // [esp+244h] [ebp-1DCh]
  unsigned int v67; // [esp+248h] [ebp-1D8h]
  std::wstring ovr; // [esp+24Ch] [ebp-1D4h] BYREF
  std::wstring _Left; // [esp+264h] [ebp-1BCh] BYREF
  std::wstring v70; // [esp+27Ch] [ebp-1A4h] BYREF
  std::wstring v71; // [esp+294h] [ebp-18Ch] BYREF
  std::wstring result; // [esp+2ACh] [ebp-174h] BYREF
  std::wstring v73; // [esp+2C4h] [ebp-15Ch] BYREF
  std::wstring v74; // [esp+2DCh] [ebp-144h] BYREF
  KN5IO kn5; // [esp+2F4h] [ebp-12Ch] BYREF
  INIReader mini; // [esp+360h] [ebp-C0h] BYREF
  INIReader ini; // [esp+3A4h] [ebp-7Ch] BYREF
  DebugTimer timer; // [esp+3E8h] [ebp-38h] BYREF
  int v79; // [esp+41Ch] [ebp-4h]

  v1 = this;
  v50 = this;
  v2 = 0;
  v48 = 0;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"TrackAvatar::init3D()", 0x15u);
  v79 = 0;
  DebugTimer::DebugTimer(&timer, &iname);
  LOBYTE(v79) = 2;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  v3 = (Model *)operator new(212);
  v49 = (const std::wstring *)v3;
  LOBYTE(v79) = 3;
  if ( v3 )
  {
    std::operator+<wchar_t>(&v47, L"TRACK ", &v1->name);
    Model::Model(v3, v47);
  }
  else
  {
    v4 = 0;
  }
  v1->model = v4;
  LOBYTE(v79) = 2;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/tracks/", 0xFu);
  v5 = &v1->name;
  LOBYTE(v79) = 4;
  v49 = &v1->name;
  v6 = std::operator+<wchar_t>(&result, &_Left, &v1->name);
  LOBYTE(v79) = 5;
  v7 = std::operator+<wchar_t>(&v70, v6, L"/");
  LOBYTE(v79) = 6;
  v8 = std::operator+<wchar_t>(&v73, v7, &v1->name);
  LOBYTE(v79) = 7;
  std::operator+<wchar_t>(&filename, v8, L".kn5");
  if ( v73._Myres >= 8 )
    operator delete(v73._Bx._Ptr);
  v73._Myres = 7;
  v73._Mysize = 0;
  v73._Bx._Buf[0] = 0;
  if ( v70._Myres >= 8 )
    operator delete(v70._Bx._Ptr);
  v70._Myres = 7;
  v70._Mysize = 0;
  v70._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v79) = 12;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Bx._Buf[0] = 0;
  v9 = v1->game;
  _Left._Mysize = 0;
  KN5IO::KN5IO(&kn5, v9->graphics);
  LOBYTE(v79) = 13;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"system/cfg/track_skins.ini", 0x1Au);
  LOBYTE(v79) = 14;
  INIReader::INIReader(&ini, &iname);
  LOBYTE(v79) = 16;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    v10 = 0;
    while ( 1 )
    {
      *(_DWORD *)v51.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v51.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v51.gap68);
      LOBYTE(v79) = 17;
      v48 = v2 | 1;
      std::wiostream::basic_iostream<wchar_t>(&v51, &v51.gap10[8], 0);
      v79 = 18;
      *(_DWORD *)&v51.gap0[*(_DWORD *)(*(_DWORD *)v51.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(TrackAvatar **)((char *)&v50 + *(_DWORD *)(*(_DWORD *)v51.gap0 + 4)) = (TrackAvatar *)(*(_DWORD *)(*(_DWORD *)v51.gap0 + 4)
                                                                                             - 104);
      std::wstreambuf::wstreambuf(&v51.gap10[8]);
      *(_DWORD *)&v51.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v51.gap10[64] = 0;
      *(_DWORD *)&v51.gap10[68] = 0;
      v47._Myres = v10;
      LOBYTE(v79) = 20;
      v11 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v51.gap10, "FOLDER_");
      std::wostream::operator<<(v11, v47._Myres);
      v12 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v51, &v57);
      LOBYTE(v79) = 21;
      v13 = INIReader::hasSection(&ini, v12);
      LOBYTE(v79) = 20;
      if ( v57._Myres >= 8 )
        operator delete(v57._Bx._Ptr);
      if ( !v13 )
        break;
      v64 = 7;
      HIDWORD(v63) = 0;
      LOWORD(pos.x) = 0;
      std::wstring::assign((std::wstring *)&pos, L"NAME", 4u);
      LOBYTE(v79) = 22;
      v14 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v51, &key);
      LOBYTE(v79) = 23;
      INIReader::getString(&ini, &ovr, v14, (const std::wstring *)&pos);
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v79) = 26;
      if ( v64 >= 8 )
        operator delete(LODWORD(pos.x));
      v64 = 7;
      HIDWORD(v63) = 0;
      LOWORD(pos.x) = 0;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"content/tracks/", 0xFu);
      LOBYTE(v79) = 27;
      v15 = std::operator+<wchar_t>(&v55, &section, v5);
      LOBYTE(v79) = 28;
      v16 = std::operator+<wchar_t>(&v58, v15, L"/skins/");
      LOBYTE(v79) = 29;
      v17 = std::operator+<wchar_t>((std::wstring *)&rot, v16, &ovr);
      v18 = v17;
      v19 = kn5.skinOverridePath._Mylast;
      LOBYTE(v79) = 30;
      if ( v17 >= kn5.skinOverridePath._Mylast
        || (v20 = kn5.skinOverridePath._Myfirst, kn5.skinOverridePath._Myfirst > v17) )
      {
        if ( kn5.skinOverridePath._Mylast == kn5.skinOverridePath._Myend )
        {
          std::vector<std::wstring>::_Reserve(&kn5.skinOverridePath, 1u);
          v19 = kn5.skinOverridePath._Mylast;
        }
      }
      else
      {
        v21 = v17 - kn5.skinOverridePath._Myfirst;
        if ( kn5.skinOverridePath._Mylast == kn5.skinOverridePath._Myend )
        {
          std::vector<std::wstring>::_Reserve(&kn5.skinOverridePath, 1u);
          v19 = kn5.skinOverridePath._Mylast;
          v20 = kn5.skinOverridePath._Myfirst;
        }
        v18 = &v20[v21];
      }
      if ( v19 )
      {
        v19->_Mysize = 0;
        v19->_Myres = 7;
        v19->_Mysize = 0;
        v19->_Bx._Buf[0] = 0;
        if ( v18->_Myres >= 8 )
        {
          v19->_Bx._Ptr = v18->_Bx._Ptr;
          v18->_Bx._Ptr = 0;
        }
        else if ( v18->_Mysize != -1 )
        {
          _memmove(v19, v18, 2 * (v18->_Mysize + 1));
        }
        v19->_Mysize = v18->_Mysize;
        v19->_Myres = v18->_Myres;
        v18->_Myres = 7;
        v18->_Mysize = 0;
        v18->_Bx._Buf[0] = 0;
        v19 = kn5.skinOverridePath._Mylast;
      }
      kn5.skinOverridePath._Mylast = v19 + 1;
      if ( v67 >= 8 )
        operator delete(LODWORD(rot.x));
      v67 = 7;
      v66 = 0;
      LOWORD(rot.x) = 0;
      if ( v58._Myres >= 8 )
        operator delete(v58._Bx._Ptr);
      v58._Myres = 7;
      v58._Mysize = 0;
      v58._Bx._Buf[0] = 0;
      if ( v55._Myres >= 8 )
        operator delete(v55._Bx._Ptr);
      v55._Myres = 7;
      v55._Mysize = 0;
      v55._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      v22 = &ovr;
      if ( ovr._Myres >= 8 )
        v22 = (std::wstring *)ovr._Bx._Ptr;
      _printf("ADDED TRACK SKIN OVERRIDE: %S\n", v22->_Bx._Buf);
      if ( ovr._Myres >= 8 )
        operator delete(ovr._Bx._Ptr);
      ++v10;
      LOBYTE(v79) = 16;
      *(_DWORD *)&v51.gap0[*(_DWORD *)(*(_DWORD *)v51.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(TrackAvatar **)((char *)&v50 + *(_DWORD *)(*(_DWORD *)v51.gap0 + 4)) = (TrackAvatar *)(*(_DWORD *)(*(_DWORD *)v51.gap0 + 4)
                                                                                             - 104);
      *(_DWORD *)&v51.gap10[8] = &std::wstringbuf::`vftable';
      if ( (v51.gap10[68] & 1) != 0 )
      {
        if ( std::wstreambuf::pptr(&v51.gap10[8]) )
          std::wstreambuf::epptr(&v51.gap10[8]);
        else
          std::wstreambuf::egptr(&v51.gap10[8]);
        std::wstreambuf::eback(&v51.gap10[8]);
        v23 = std::wstreambuf::eback(&v51.gap10[8]);
        operator delete(v23);
      }
      std::wstreambuf::setg(&v51.gap10[8], 0, 0, 0);
      std::wstreambuf::setp(&v51.gap10[8], 0, 0);
      *(_DWORD *)&v51.gap10[68] &= 0xFFFFFFFE;
      *(_DWORD *)&v51.gap10[64] = 0;
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v51.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v51.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v51.gap68);
      v2 = v48;
      v5 = v49;
    }
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v51);
    v1 = v50;
  }
  models_filename._Myres = 7;
  models_filename._Mysize = 0;
  models_filename._Bx._Buf[0] = 0;
  v24 = v1->config._Mysize == 0;
  v47._Myres = (unsigned int)v5;
  v47._Mysize = (unsigned int)L"content/tracks/";
  LOBYTE(v79) = 31;
  *(_DWORD *)&v47._Bx._Alias[12] = &v57;
  if ( v24 )
  {
    v25 = std::operator+<wchar_t>(
            *(std::wstring **)&v47._Bx._Alias[12],
            (const wchar_t *)v47._Mysize,
            (const std::wstring *)v47._Myres);
    LOBYTE(v79) = 32;
    v26 = std::operator+<wchar_t>(&v55, v25, L"/models.ini");
    if ( &models_filename != v26 )
    {
      if ( models_filename._Myres >= 8 )
        operator delete(models_filename._Bx._Ptr);
      models_filename._Myres = 7;
      models_filename._Mysize = 0;
      models_filename._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&models_filename, v26);
    }
    if ( v55._Myres >= 8 )
      operator delete(v55._Bx._Ptr);
    v55._Myres = 7;
    v55._Mysize = 0;
    v55._Bx._Buf[0] = 0;
  }
  else
  {
    v27 = std::operator+<wchar_t>(
            *(std::wstring **)&v47._Bx._Alias[12],
            (const wchar_t *)v47._Mysize,
            (const std::wstring *)v47._Myres);
    LOBYTE(v79) = 33;
    v28 = std::operator+<wchar_t>(&key, v27, L"/models_");
    LOBYTE(v79) = 34;
    v29 = std::operator+<wchar_t>(&v58, v28, &v1->config);
    LOBYTE(v79) = 35;
    v30 = std::operator+<wchar_t>(&v55, v29, L".ini");
    std::wstring::operator=(&models_filename, v30);
    if ( v55._Myres >= 8 )
      operator delete(v55._Bx._Ptr);
    v55._Myres = 7;
    v55._Mysize = 0;
    v55._Bx._Buf[0] = 0;
    if ( v58._Myres >= 8 )
      operator delete(v58._Bx._Ptr);
    v58._Myres = 7;
    v58._Mysize = 0;
    v58._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
  }
  LOBYTE(v79) = 31;
  if ( v57._Myres >= 8 )
    operator delete(v57._Bx._Ptr);
  INIReader::INIReader(&mini, &models_filename);
  LOBYTE(v79) = 36;
  if ( mini.ready )
  {
    v31 = 0;
    while ( 1 )
    {
      v32 = std::to_wstring(&v55, v31);
      LOBYTE(v79) = 37;
      std::operator+<wchar_t>(&section, L"MODEL_", v32);
      LOBYTE(v79) = 39;
      if ( v55._Myres >= 8 )
        operator delete(v55._Bx._Ptr);
      v55._Myres = 7;
      v55._Bx._Buf[0] = 0;
      v55._Mysize = 0;
      if ( !INIReader::hasSection(&mini, &section) )
        break;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"FILE", 4u);
      LOBYTE(v79) = 40;
      v33 = INIReader::getString(&mini, &v57, &section, &key);
      LOBYTE(v79) = 41;
      v34 = std::operator+<wchar_t>(&v74, L"content/tracks/", &v1->name);
      LOBYTE(v79) = 42;
      v35 = std::operator+<wchar_t>(&v71, v34, L"/");
      LOBYTE(v79) = 43;
      v36 = std::operator+<wchar_t>(&v58, v35, v33);
      if ( &filename != v36 )
      {
        if ( filename._Myres >= 8 )
          operator delete(filename._Bx._Ptr);
        filename._Myres = 7;
        filename._Mysize = 0;
        filename._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&filename, v36);
      }
      if ( v58._Myres >= 8 )
        operator delete(v58._Bx._Ptr);
      v58._Myres = 7;
      v58._Mysize = 0;
      v58._Bx._Buf[0] = 0;
      if ( v71._Myres >= 8 )
        operator delete(v71._Bx._Ptr);
      v71._Myres = 7;
      v71._Mysize = 0;
      v71._Bx._Buf[0] = 0;
      if ( v74._Myres >= 8 )
        operator delete(v74._Bx._Ptr);
      v74._Myres = 7;
      v74._Mysize = 0;
      v74._Bx._Buf[0] = 0;
      if ( v57._Myres >= 8 )
        operator delete(v57._Bx._Ptr);
      v57._Myres = 7;
      v57._Mysize = 0;
      v57._Bx._Buf[0] = 0;
      LOBYTE(v79) = 39;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      Model::load(v1->model, &filename, v1->game->graphics, &kn5);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"POSITION", 8u);
      LOBYTE(v79) = 44;
      INIReader::getFloat3(&mini, &pos, &section, &key);
      LOBYTE(v79) = 39;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&v57, L"ROTATION");
      LOBYTE(v79) = 45;
      INIReader::getFloat3(&mini, &rot, &section, &v57);
      if ( v57._Myres >= 8 )
        operator delete(v57._Bx._Ptr);
      v37 = (__m128)LODWORD(rot.x);
      v38 = (__m128)LODWORD(rot.y);
      v37.m128_f32[0] = rot.x * 0.017453;
      v38.m128_f32[0] = rot.y * 0.017453;
      v39 = rot.z * 0.017453;
      *(_QWORD *)&rot.x = _mm_unpacklo_ps(v37, v38).m128_u64[0];
      *(float *)&iname._Bx._Alias[8] = rot.z * 0.017453;
      rot.z = rot.z * 0.017453;
      if ( v37.m128_f32[0] != 0.0 || v38.m128_f32[0] != 0.0 || v39 != 0.0 )
      {
        mat44f::mat44f(&mat);
        v41 = v1->model;
        *(_QWORD *)ovr._Bx._Buf = 0i64;
        *(_DWORD *)&ovr._Bx._Alias[8] = 0;
        v47._Myres = *((_DWORD *)v41->nodes._Mylast - 1) + 4;
        v42 = mat44f::createFromEuler(&v53, &rot, (const vec3f *)&ovr);
        mul(&mat, v42, (const mat44f *)v47._Myres);
        v43 = *((_DWORD *)v1->model->nodes._Mylast - 1);
        *(__m128i *)(v43 + 4) = _mm_loadu_si128((const __m128i *)&mat);
        *(__m128i *)(v43 + 20) = _mm_loadu_si128((const __m128i *)&mat.M21);
        *(__m128i *)(v43 + 36) = _mm_loadu_si128((const __m128i *)&mat.M31);
        *(__m128i *)(v43 + 52) = _mm_loadu_si128((const __m128i *)&mat.M41);
      }
      v44 = v1->model;
      ++v31;
      LOBYTE(v79) = 36;
      *(vec3f *)(*((_DWORD *)v44->nodes._Mylast - 1) + 52) = pos;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
    LOBYTE(v79) = 36;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  else
  {
    if ( v1->config._Mysize )
    {
      v45 = std::operator+<wchar_t>(
              &v57,
              L"ERROR, models_[config].ini file is required and not found in:",
              &models_filename);
      v46 = v45->_Myres < 8;
      LOBYTE(v79) = 46;
      if ( !v46 )
        v45 = (std::wstring *)v45->_Bx._Ptr;
      _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v45->_Bx._Buf);
      ksGenerateCrash();
      LOBYTE(v79) = 36;
      if ( v57._Myres >= 8 )
        operator delete(v57._Bx._Ptr);
    }
    Model::load(v1->model, &filename, v1->game->graphics, &kn5);
  }
  GraphicsManager::compile(v1->game->graphics, v1->model);
  v1->sim->trackNode->addChild(v1->sim->trackNode, v1->model);
  LOBYTE(v79) = 31;
  INIReader::~INIReader(&mini);
  if ( models_filename._Myres >= 8 )
    operator delete(models_filename._Bx._Ptr);
  models_filename._Myres = 7;
  models_filename._Mysize = 0;
  models_filename._Bx._Buf[0] = 0;
  LOBYTE(v79) = 13;
  INIReader::~INIReader(&ini);
  LOBYTE(v79) = 12;
  KN5IO::~KN5IO(&kn5);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  v79 = -1;
  DebugTimer::~DebugTimer(&timer);
}
void TrackAvatar::initDynamicObjects(TrackAvatar *this)
{
  bool v2; // zf
  std::wstring *v3; // eax
  std::wstring *v4; // esi
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  std::wstring *v7; // eax
  std::wstring *v8; // esi
  int v9; // ecx
  std::wstring *v10; // eax
  int v11; // esi
  std::wstring *v12; // esi
  std::wstring *v13; // eax
  std::wstring *v14; // eax
  Node *v15; // esi
  vec3f *v16; // eax
  __int64 v17; // xmm0_8
  float v18; // eax
  float v19; // xmm2_4
  float v20; // xmm2_4
  int v21; // eax
  __m128 v22; // xmm2
  float v23; // edi
  __m128 v24; // xmm0
  int v25; // eax
  float v26; // xmm1_4
  float v27; // xmm2_4
  int v28; // eax
  float v29; // xmm1_4
  float v30; // xmm2_4
  int v31; // eax
  __m128 v32; // xmm1
  __m128 v33; // xmm0
  TrackAvatar *v34; // edi
  ACClient *v35; // eax
  __m128 v36; // xmm1
  __m128 v37; // xmm2
  __m128 v38; // xmm0
  std::wstring *v39; // [esp-4h] [ebp-290h]
  vec3f v40; // [esp+Ch] [ebp-280h] BYREF
  float v41; // [esp+20h] [ebp-26Ch]
  float v42; // [esp+2Ch] [ebp-260h]
  float v43; // [esp+38h] [ebp-254h]
  vec3f v44; // [esp+3Ch] [ebp-250h] BYREF
  vec3f v45; // [esp+48h] [ebp-244h] BYREF
  vec3f v46; // [esp+54h] [ebp-238h] BYREF
  unsigned __int64 v47; // [esp+60h] [ebp-22Ch]
  vec2f v48; // [esp+68h] [ebp-224h] BYREF
  TrackAvatar *v49; // [esp+70h] [ebp-21Ch]
  float v50; // [esp+74h] [ebp-218h]
  MLJoint _Val; // [esp+78h] [ebp-214h] BYREF
  std::wstring *_Right; // [esp+ACh] [ebp-1E0h]
  int v53; // [esp+B0h] [ebp-1DCh]
  float v54; // [esp+B4h] [ebp-1D8h]
  float v55; // [esp+B8h] [ebp-1D4h]
  float v56; // [esp+BCh] [ebp-1D0h]
  float v57; // [esp+C0h] [ebp-1CCh]
  KN5IO v58; // [esp+C4h] [ebp-1C8h] BYREF
  INIReader v59; // [esp+130h] [ebp-15Ch] BYREF
  std::wstring v60; // [esp+174h] [ebp-118h] BYREF
  std::wstring v61; // [esp+18Ch] [ebp-100h] BYREF
  std::wstring v62; // [esp+1A4h] [ebp-E8h] BYREF
  std::wstring v63; // [esp+1BCh] [ebp-D0h] BYREF
  std::wstring result; // [esp+1D4h] [ebp-B8h] BYREF
  std::wstring v65; // [esp+1ECh] [ebp-A0h] BYREF
  std::wstring section; // [esp+204h] [ebp-88h] BYREF
  std::wstring ifilename; // [esp+21Ch] [ebp-70h] BYREF
  std::wstring v68; // [esp+234h] [ebp-58h] BYREF
  std::wstring key; // [esp+24Ch] [ebp-40h] BYREF
  std::wstring v70; // [esp+264h] [ebp-28h] BYREF
  int v71; // [esp+288h] [ebp-4h]

  v49 = this;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  v2 = this->config._Mysize == 0;
  v71 = 0;
  v39 = &this->name;
  _Right = &this->name;
  if ( v2 )
  {
    v3 = std::operator+<wchar_t>(&result, L"content/tracks/", v39);
    LOBYTE(v71) = 1;
    v4 = std::operator+<wchar_t>(&key, v3, L"/models.ini");
    if ( &ifilename != v4 )
    {
      if ( ifilename._Myres >= 8 )
        operator delete(ifilename._Bx._Ptr);
      ifilename._Myres = 7;
      ifilename._Mysize = 0;
      ifilename._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&ifilename, v4);
    }
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
  }
  else
  {
    v5 = std::operator+<wchar_t>(&result, L"content/tracks/", v39);
    LOBYTE(v71) = 2;
    v6 = std::operator+<wchar_t>(&v68, v5, L"/models_");
    LOBYTE(v71) = 3;
    v7 = std::operator+<wchar_t>(&v65, v6, &this->config);
    LOBYTE(v71) = 4;
    v8 = std::operator+<wchar_t>(&key, v7, L".ini");
    if ( &ifilename != v8 )
    {
      if ( ifilename._Myres >= 8 )
        operator delete(ifilename._Bx._Ptr);
      ifilename._Myres = 7;
      ifilename._Mysize = 0;
      ifilename._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&ifilename, v8);
    }
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( v65._Myres >= 8 )
      operator delete(v65._Bx._Ptr);
    v65._Myres = 7;
    v65._Mysize = 0;
    v65._Bx._Buf[0] = 0;
    if ( v68._Myres >= 8 )
      operator delete(v68._Bx._Ptr);
    v68._Myres = 7;
    v68._Mysize = 0;
    v68._Bx._Buf[0] = 0;
  }
  LOBYTE(v71) = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  INIReader::INIReader(&v59, &ifilename);
  LOBYTE(v71) = 5;
  if ( v59.ready )
  {
    KN5IO::KN5IO(&v58, this->game->graphics);
    v9 = 0;
    LOBYTE(v71) = 6;
    v53 = 0;
    while ( 1 )
    {
      v10 = std::to_wstring(&v61, v9);
      LOBYTE(v71) = 7;
      std::operator+<wchar_t>(&section, L"DYNAMIC_OBJECT_", v10);
      LOBYTE(v71) = 9;
      if ( v61._Myres >= 8 )
        operator delete(v61._Bx._Ptr);
      v61._Myres = 7;
      v61._Bx._Buf[0] = 0;
      v61._Mysize = 0;
      if ( !INIReader::hasSection(&v59, &section) )
        break;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"PROBABILITY", 0xBu);
      LOBYTE(v71) = 10;
      v11 = INIReader::getInt(&v59, &section, &key);
      LOBYTE(v71) = 9;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      if ( (float)v11 > (float)((float)((float)_rand() * 0.000030518509) * 100.0) )
      {
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"MULT", 4u);
        LOBYTE(v71) = 11;
        INIReader::getFloat2(&v59, &v48, &section, &key);
        LOBYTE(v71) = 9;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        v57 = v48.x;
        v54 = v48.y + 1.0;
        LODWORD(v54) = (int)(float)((float)((float)((float)_rand() * 0.000030518509) * (float)(v54 - v57)) + v57);
        if ( SLODWORD(v54) > 0 )
        {
          do
          {
            v70._Myres = 7;
            _Val.ballTyre.relToCar.x = 0.0;
            v70._Mysize = 0;
            *(_OWORD *)&_Val.ballCar.relToTyre.y = 0i64;
            v70._Bx._Buf[0] = 0;
            *(_OWORD *)&_Val.ballCar.relToCar.z = 0i64;
            std::wstring::assign(&v70, L"FILE", 4u);
            LOBYTE(v71) = 12;
            v12 = INIReader::getString(&v59, &v60, &section, &v70);
            LOBYTE(v71) = 13;
            v13 = std::operator+<wchar_t>(&v62, L"content/tracks/", _Right);
            LOBYTE(v71) = 14;
            v14 = std::operator+<wchar_t>(&v63, v13, L"/");
            LOBYTE(v71) = 15;
            std::operator+<wchar_t>(&result, v14, v12);
            if ( v63._Myres >= 8 )
              operator delete(v63._Bx._Ptr);
            v63._Myres = 7;
            v63._Mysize = 0;
            v63._Bx._Buf[0] = 0;
            if ( v62._Myres >= 8 )
              operator delete(v62._Bx._Ptr);
            v62._Myres = 7;
            v62._Mysize = 0;
            v62._Bx._Buf[0] = 0;
            if ( v60._Myres >= 8 )
              operator delete(v60._Bx._Ptr);
            v60._Myres = 7;
            v60._Mysize = 0;
            v60._Bx._Buf[0] = 0;
            LOBYTE(v71) = 20;
            if ( v70._Myres >= 8 )
              operator delete(v70._Bx._Ptr);
            v70._Myres = 7;
            v70._Bx._Buf[0] = 0;
            v70._Mysize = 0;
            v15 = KN5IO::load(&v58, &result);
            v68._Myres = 7;
            LODWORD(_Val.ballCar.relToTyre.x) = v15;
            v68._Mysize = 0;
            v68._Bx._Buf[0] = 0;
            std::wstring::assign(&v68, L"POS_MODE", 8u);
            LOBYTE(v71) = 21;
            INIReader::getString(&v59, &key, &section, &v68);
            LOBYTE(v71) = 23;
            if ( v68._Myres >= 8 )
              operator delete(v68._Bx._Ptr);
            v68._Myres = 7;
            v68._Mysize = 0;
            v68._Bx._Buf[0] = 0;
            if ( std::wstring::compare(&key, 0, key._Mysize, L"RANDOM", 6u) )
            {
              v23 = _Val.ballCar.relToCar.x;
              v47 = *(_QWORD *)&_Val.ballCar.relToTyre.y;
            }
            else
            {
              v70._Myres = 7;
              v70._Mysize = 0;
              v70._Bx._Buf[0] = 0;
              std::wstring::assign(&v70, L"RND_POS_CENTER", 0xEu);
              LOBYTE(v71) = 24;
              INIReader::getFloat3(&v59, &v46, &section, &v70);
              LOBYTE(v71) = 23;
              if ( v70._Myres >= 8 )
                operator delete(v70._Bx._Ptr);
              v70._Myres = 7;
              v70._Mysize = 0;
              v70._Bx._Buf[0] = 0;
              std::wstring::assign(&v70, L"RND_POS_RANGE", 0xDu);
              LOBYTE(v71) = 25;
              v16 = INIReader::getFloat3(&v59, &v40, &section, &v70);
              LOBYTE(v71) = 23;
              v17 = *(_QWORD *)&v16->x;
              v18 = v16->z;
              *(_QWORD *)&_Val.ballCar.relToCar.y = v17;
              _Val.ballTyre.relToTyre.x = v18;
              if ( v70._Myres >= 8 )
                operator delete(v70._Bx._Ptr);
              LODWORD(v57) = LODWORD(_Val.ballTyre.relToTyre.x) ^ _xmm;
              v19 = (float)((float)((float)_rand() * 0.000030518509) * (float)(_Val.ballTyre.relToTyre.x - v57)) + v57;
              LODWORD(v57) = LODWORD(_Val.ballCar.relToCar.z) ^ _xmm;
              v56 = v19;
              v20 = (float)((float)((float)_rand() * 0.000030518509) * (float)(_Val.ballCar.relToCar.z - v57)) + v57;
              LODWORD(v57) = LODWORD(_Val.ballCar.relToCar.y) ^ _xmm;
              v55 = v20;
              v21 = _rand();
              v22 = (__m128)LODWORD(v46.x);
              v41 = v56 + v46.z;
              v23 = v56 + v46.z;
              v22.m128_f32[0] = v46.x
                              + (float)((float)((float)((float)v21 * 0.000030518509)
                                              * (float)(_Val.ballCar.relToCar.y - v57))
                                      + v57);
              v24 = (__m128)LODWORD(v55);
              v24.m128_f32[0] = v55 + v46.y;
              _Val.ballCar.relToCar.x = v56 + v46.z;
              v47 = _mm_unpacklo_ps(v22, v24).m128_u64[0];
              *(_QWORD *)&_Val.ballCar.relToTyre.y = v47;
            }
            v70._Myres = 7;
            v70._Mysize = 0;
            v70._Bx._Buf[0] = 0;
            std::wstring::assign(&v70, L"VEL_MODE", 8u);
            LOBYTE(v71) = 26;
            INIReader::getString(&v59, &v65, &section, &v70);
            LOBYTE(v71) = 28;
            if ( v70._Myres >= 8 )
              operator delete(v70._Bx._Ptr);
            v70._Myres = 7;
            v70._Mysize = 0;
            v70._Bx._Buf[0] = 0;
            if ( !std::wstring::compare(&v65, 0, v65._Mysize, L"RANDOM", 6u) )
            {
              v68._Myres = 7;
              v68._Mysize = 0;
              v68._Bx._Buf[0] = 0;
              std::wstring::assign(&v68, L"RND_VEL_BASE", 0xCu);
              LOBYTE(v71) = 29;
              INIReader::getFloat3(&v59, &v45, &section, &v68);
              LOBYTE(v71) = 28;
              if ( v68._Myres >= 8 )
                operator delete(v68._Bx._Ptr);
              v68._Myres = 7;
              v68._Mysize = 0;
              v68._Bx._Buf[0] = 0;
              std::wstring::assign(&v68, L"RND_VEL_RANGE", 0xDu);
              LOBYTE(v71) = 30;
              INIReader::getFloat3(&v59, &v44, &section, &v68);
              LOBYTE(v71) = 28;
              if ( v68._Myres >= 8 )
                operator delete(v68._Bx._Ptr);
              v55 = v44.z;
              LODWORD(v56) = LODWORD(v44.z) ^ _xmm;
              v25 = _rand();
              v26 = v55 - v56;
              v55 = v44.y;
              v27 = (float)((float)((float)v25 * 0.000030518509) * v26) + v56;
              LODWORD(v56) = LODWORD(v44.y) ^ _xmm;
              v50 = v27;
              v28 = _rand();
              v29 = v55 - v56;
              v55 = v44.x;
              v30 = (float)((float)((float)v28 * 0.000030518509) * v29) + v56;
              LODWORD(v56) = LODWORD(v44.x) ^ _xmm;
              v57 = v30;
              v31 = _rand();
              v32 = (__m128)LODWORD(v45.x);
              v42 = v50 + v45.z;
              v32.m128_f32[0] = v45.x
                              + (float)((float)((float)((float)v31 * 0.000030518509) * (float)(v55 - v56)) + v56);
              v33 = (__m128)LODWORD(v57);
              v33.m128_f32[0] = v57 + v45.y;
              _Val.ballTyre.relToCar.x = v50 + v45.z;
              *(_QWORD *)&_Val.ballTyre.relToTyre.y = _mm_unpacklo_ps(v32, v33).m128_u64[0];
            }
            *(float *)&_Val.joint = v23;
            v34 = v49;
            *(_QWORD *)&_Val.ballTyre.relToCar.y = v47;
            v35 = v49->sim->client;
            if ( v35 )
            {
              v36 = _mm_cvtpd_ps((__m128d)*(unsigned __int64 *)&v35->handshakeServerTimeS);
              v37 = v36;
              v38 = v36;
              v37.m128_f32[0] = (float)(v36.m128_f32[0] * _Val.ballTyre.relToTyre.y) + _Val.ballCar.relToTyre.y;
              v38.m128_f32[0] = (float)(v36.m128_f32[0] * _Val.ballTyre.relToTyre.z) + _Val.ballCar.relToTyre.z;
              v43 = (float)(v36.m128_f32[0] * _Val.ballTyre.relToCar.x) + _Val.ballCar.relToCar.x;
              *(_QWORD *)&_Val.ballCar.relToTyre.y = _mm_unpacklo_ps(v37, v38).m128_u64[0];
              _Val.ballCar.relToCar.x = v43;
            }
            GraphicsManager::compile(v49->game->graphics, v15);
            v34->model->addChild(v34->model, v15);
            std::vector<MLJoint>::push_back((std::vector<MLJoint> *)&v34->dynamicObjects, &_Val);
            if ( v65._Myres >= 8 )
              operator delete(v65._Bx._Ptr);
            v65._Myres = 7;
            v65._Mysize = 0;
            v65._Bx._Buf[0] = 0;
            if ( key._Myres >= 8 )
              operator delete(key._Bx._Ptr);
            key._Myres = 7;
            key._Mysize = 0;
            key._Bx._Buf[0] = 0;
            LOBYTE(v71) = 9;
            if ( result._Myres >= 8 )
              operator delete(result._Bx._Ptr);
            --LODWORD(v54);
          }
          while ( v54 != 0.0 );
        }
      }
      v9 = v53 + 1;
      LOBYTE(v71) = 6;
      ++v53;
      if ( section._Myres >= 8 )
      {
        operator delete(section._Bx._Ptr);
        v9 = v53;
      }
    }
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    LOBYTE(v71) = 5;
    KN5IO::~KN5IO(&v58);
  }
  LOBYTE(v71) = 0;
  INIReader::~INIReader(&v59);
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
}
void __usercall TrackAvatar::initPhysics(TrackAvatar *this@<ecx>, __m128 a2@<xmm0>, __m128 a3@<xmm3>, __m128 a4@<xmm4>)
{
  bool v5; // cf
  std::wstring *v6; // eax
  std::wstring *v7; // edx
  std::wstring *v8; // eax
  const std::wstring *v9; // eax
  std::wstring iname; // [esp+8h] [ebp-A8h] BYREF
  std::wstring wname; // [esp+20h] [ebp-90h] BYREF
  std::wstring result; // [esp+38h] [ebp-78h] BYREF
  DebugTimer dt; // [esp+50h] [ebp-60h] BYREF
  DebugTimer timer; // [esp+78h] [ebp-38h] BYREF
  int v15; // [esp+ACh] [ebp-4h]

  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"TrackAvatar::initPhysics()", 0x1Au);
  v15 = 0;
  DebugTimer::DebugTimer(&timer, &iname);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  wname._Myres = 7;
  wname._Mysize = 0;
  wname._Bx._Buf[0] = 0;
  v5 = this->name._Myres < 8;
  v6 = &this->name;
  LOBYTE(v15) = 3;
  if ( v5 )
    v7 = &this->name;
  else
    v7 = (std::wstring *)v6->_Bx._Ptr;
  if ( this->name._Myres >= 8 )
    v6 = (std::wstring *)v6->_Bx._Ptr;
  std::wstring::replace(
    &wname,
    (std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)&wname,
    (std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)&wname,
    (std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)v6,
    (std::_String_const_iterator<std::_String_val<std::_Simple_types<wchar_t> > >)((char *)v7 + 2 * this->name._Mysize));
  v8 = TrackAvatar::getDataFolder(this, &result);
  LOBYTE(v15) = 4;
  v9 = std::operator+<wchar_t>(&iname, v8, L"/ai");
  LOBYTE(v15) = 5;
  Path::createFolder(v9);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  LOBYTE(v15) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  TrackAvatar::processPhysicsNode(this, this->model);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"INIT TRACK SPLINES", 0x12u);
  LOBYTE(v15) = 6;
  DebugTimer::DebugTimer(&dt, &iname);
  LOBYTE(v15) = 8;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  Track::initAISpline(&this->physicsTrack, a2, a3, a4);
  LOBYTE(v15) = 3;
  DebugTimer::~DebugTimer(&dt);
  if ( wname._Myres >= 8 )
    operator delete(wname._Bx._Ptr);
  wname._Myres = 7;
  wname._Mysize = 0;
  wname._Bx._Buf[0] = 0;
  v15 = -1;
  DebugTimer::~DebugTimer(&timer);
}
void TrackAvatar::initPitCrew(TrackAvatar *this)
{
  TrackAvatar *v1; // ebx
  std::wstring *v2; // eax
  const std::wstring *v3; // eax
  const std::vector<TyreThermalPatch *> *v4; // eax
  Node **v5; // esi
  Node **v6; // edi
  float v7; // edx
  Sim *v8; // ecx
  ACClient *v9; // eax
  CarAvatar *v10; // eax
  CarAvatar *v11; // ebp
  std::wstring *v12; // ebx
  std::wstring *v13; // eax
  std::wstring *v14; // eax
  unsigned int v15; // edx
  LollipopCrew *v16; // ebx
  LollipopCrew *v17; // eax
  LollipopCrew *v18; // ebp
  unsigned int *v19; // ebx
  LollipopCrew **v20; // ecx
  wchar_t *v21; // eax
  _DWORD *v22; // ecx
  LollipopCrew **v23; // eax
  GameObject **v24; // ecx
  wchar_t *v25; // eax
  GameObject **v26; // ecx
  _DWORD *v27; // eax
  Sim *v28; // eax
  Model *v29; // ecx
  float *v30; // esi
  Node **v31; // edi
  std::wstring *v32; // eax
  const wchar_t *v33; // ebx
  bool v34; // cf
  int *v35; // eax
  unsigned int v36; // ebp
  TrackAvatar *v37; // edx
  float v38; // ebx
  Sim *v39; // ecx
  CarAvatar *v40; // eax
  std::shared_ptr<Material> *v41; // eax
  Material *v42; // ecx
  MaterialResource *v43; // eax
  std::wstring *v44; // ebx
  int v45; // eax
  unsigned int v46; // ebp
  std::wstring *v47; // eax
  std::wstring *v48; // ebp
  float v49; // ebp
  std::wstring *v50; // ebx
  std::wstring *v51; // eax
  std::wstring *v52; // eax
  std::wstring *v53; // eax
  std::wstring *v54; // eax
  std::wstring *v55; // eax
  std::wstring *v56; // eax
  const std::wstring *v57; // eax
  char v58; // bl
  std::wstring *v59; // eax
  std::wstring *v60; // eax
  std::wstring *v61; // ebx
  std::wstring *v62; // eax
  std::wstring *v63; // eax
  std::wstring *v64; // eax
  std::wstring *v65; // eax
  std::shared_ptr<Material> *v66; // ebx
  Texture *v67; // eax
  MaterialResource *v68; // edx
  void *v69; // ecx
  const std::wstring *v70; // eax
  std::_Ref_count_base *v71; // ebx
  mat44f v72; // [esp-40h] [ebp-284h]
  float v73[13]; // [esp+0h] [ebp-244h] BYREF
  float side; // [esp+34h] [ebp-210h] BYREF
  wchar_t *EndPtr; // [esp+38h] [ebp-20Ch] BYREF
  std::shared_ptr<Material> *v76; // [esp+3Ch] [ebp-208h]
  TrackAvatar *v77; // [esp+40h] [ebp-204h]
  LollipopCrew *v78; // [esp+44h] [ebp-200h] BYREF
  std::vector<Node *> crews; // [esp+48h] [ebp-1FCh] BYREF
  LollipopCrew *lp; // [esp+54h] [ebp-1F0h] BYREF
  std::shared_ptr<Material> clone; // [esp+58h] [ebp-1ECh] BYREF
  std::vector<Node *> pits; // [esp+60h] [ebp-1E4h] BYREF
  LollipopCrew *v83; // [esp+6Ch] [ebp-1D8h]
  std::wstring key; // [esp+70h] [ebp-1D4h] BYREF
  std::wstring section; // [esp+88h] [ebp-1BCh] BYREF
  std::wstring _Left; // [esp+A0h] [ebp-1A4h] BYREF
  std::wstring skin; // [esp+B8h] [ebp-18Ch] BYREF
  std::wstring iniSkin; // [esp+D0h] [ebp-174h] BYREF
  std::wstring v89; // [esp+E8h] [ebp-15Ch] BYREF
  std::wstring override_tex; // [esp+100h] [ebp-144h] BYREF
  std::wstring crewskin; // [esp+118h] [ebp-12Ch] BYREF
  Texture v92; // [esp+130h] [ebp-114h] BYREF
  std::wstring _Keyval; // [esp+14Ch] [ebp-F8h] BYREF
  std::wstring texname; // [esp+164h] [ebp-E0h] BYREF
  std::wstring result; // [esp+17Ch] [ebp-C8h] BYREF
  std::wstring v96; // [esp+194h] [ebp-B0h] BYREF
  INIReader iniS; // [esp+1ACh] [ebp-98h] BYREF
  INIReader ini; // [esp+1F0h] [ebp-54h] BYREF
  int v99; // [esp+240h] [ebp-4h]

  v1 = this;
  v77 = this;
  v76 = (std::shared_ptr<Material> *)LODWORD(FLOAT_N1_0);
  v2 = TrackAvatar::getDataFolder(this, &result);
  v99 = 0;
  v3 = std::operator+<wchar_t>(&v96, v2, L"/data/crew.ini");
  LOBYTE(v99) = 1;
  INIReader::INIReader(&ini, v3);
  if ( v96._Myres >= 8 )
    operator delete(v96._Bx._Ptr);
  v96._Myres = 7;
  v96._Mysize = 0;
  v96._Bx._Buf[0] = 0;
  LOBYTE(v99) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    _Left._Myres = 7;
    _Left._Mysize = 0;
    _Left._Bx._Buf[0] = 0;
    std::wstring::assign(&_Left, L"SIDE", 4u);
    LOBYTE(v99) = 5;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"HEADER", 6u);
    LOBYTE(v99) = 6;
    side = INIReader::getFloat(&ini, &key, &_Left);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v99) = 4;
    if ( _Left._Myres >= 8 )
      operator delete(_Left._Bx._Ptr);
    v76 = (std::shared_ptr<Material> *)LODWORD(side);
  }
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::wstring::assign(&_Keyval, L"PIT", 3u);
  LOBYTE(v99) = 7;
  v4 = (const std::vector<TyreThermalPatch *> *)std::map<std::wstring,std::vector<Node *>>::operator[](
                                                  &v1->spawnPositions,
                                                  &_Keyval);
  std::vector<Mesh *>::vector<Mesh *>((std::vector<TyreThermalPatch *> *)&pits, v4);
  LOBYTE(v99) = 9;
  if ( _Keyval._Myres >= 8 )
    operator delete(_Keyval._Bx._Ptr);
  v5 = pits._Myfirst;
  v6 = pits._Mylast;
  v7 = 0.0;
  _Keyval._Myres = 7;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  for ( side = 0.0; v5 != v6; side = v7 )
  {
    v8 = v1->sim;
    EndPtr = (wchar_t *)*v5;
    if ( LODWORD(v7) < v8->cars._Mylast - v8->cars._Myfirst )
    {
      v9 = v8->client;
      v73[6] = v7;
      if ( v9 )
        v10 = ACClient::getCarAvatarFromSessionID(v9, LOBYTE(v73[6]));
      else
        v10 = Sim::getCar(v8, LODWORD(v73[6]));
      v11 = v10;
      v12 = CarAvatar::getCurrentSkin(v10, &section);
      LOBYTE(v99) = 10;
      v13 = std::operator+<wchar_t>(&crewskin, L"content/cars/", &v11->unixName);
      LOBYTE(v99) = 11;
      v14 = std::operator+<wchar_t>(&_Left, v13, L"/skins/");
      LOBYTE(v99) = 12;
      std::operator+<wchar_t>(&skin, v14, v12);
      if ( _Left._Myres >= 8 )
        operator delete(_Left._Bx._Ptr);
      _Left._Myres = 7;
      _Left._Mysize = 0;
      _Left._Bx._Buf[0] = 0;
      if ( crewskin._Myres >= 8 )
        operator delete(crewskin._Bx._Ptr);
      crewskin._Myres = 7;
      crewskin._Mysize = 0;
      crewskin._Bx._Buf[0] = 0;
      LOBYTE(v99) = 16;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      v16 = (LollipopCrew *)operator new(120);
      v83 = v16;
      LOBYTE(v99) = 17;
      if ( v16 )
      {
        LODWORD(v73[6]) = 7;
        v73[5] = 0.0;
        LOWORD(v73[1]) = 0;
        std::wstring::assign((std::wstring *)&v73[1], &skin, 0, 0xFFFFFFFF);
        *(__m128i *)&v72.M11 = _mm_loadu_si128((const __m128i *)(EndPtr + 2));
        *(__m128i *)&v72.M21 = _mm_loadu_si128((const __m128i *)(EndPtr + 10));
        *(__m128i *)&v72.M31 = _mm_loadu_si128((const __m128i *)(EndPtr + 18));
        *(__m128i *)&v72.M41 = _mm_loadu_si128((const __m128i *)(EndPtr + 26));
        LollipopCrew::LollipopCrew(v16, (int)v11, (int)v6, (int)v5, v11, v72, *(float *)&v76, *(std::wstring *)&v73[1]);
        v18 = v17;
      }
      else
      {
        v18 = 0;
      }
      v19 = (unsigned int *)&v77->lollipopCrews;
      LOBYTE(v99) = 16;
      lp = v18;
      v20 = v77->lollipopCrews._Mylast;
      if ( &lp >= v20 || (v15 = *v19, *v19 > (unsigned int)&lp) )
      {
        if ( v20 == v77->lollipopCrews._Myend )
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&v77->lollipopCrews, 1u);
        v23 = (LollipopCrew **)v19[1];
        if ( v23 )
          *v23 = v18;
      }
      else
      {
        v21 = (wchar_t *)((int)((int)&lp - v15) >> 2);
        EndPtr = v21;
        if ( v20 == v77->lollipopCrews._Myend )
        {
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&v77->lollipopCrews, 1u);
          v21 = EndPtr;
        }
        v22 = (_DWORD *)v19[1];
        v15 = *v19;
        if ( v22 )
          *v22 = *(_DWORD *)(v15 + 4 * (_DWORD)v21);
      }
      v19[1] += 4;
      v1 = v77;
      v78 = v18;
      v24 = v77->gameObjects._Mylast;
      if ( &v78 >= v24 || (v15 = (unsigned int)v77->gameObjects._Myfirst, v15 > (unsigned int)&v78) )
      {
        if ( v24 == v77->gameObjects._Myend )
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&v77->gameObjects, 1u);
        v27 = v1->gameObjects._Mylast;
        if ( v27 )
          *v27 = v18;
      }
      else
      {
        v25 = (wchar_t *)((int)((int)&v78 - v15) >> 2);
        EndPtr = v25;
        if ( v24 == v77->gameObjects._Myend )
        {
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&v77->gameObjects, 1u);
          v25 = EndPtr;
        }
        v26 = v1->gameObjects._Mylast;
        v15 = (unsigned int)v1->gameObjects._Myfirst;
        if ( v26 )
          *v26 = *(GameObject **)(v15 + 4 * (_DWORD)v25);
      }
      ++v1->gameObjects._Mylast;
      v18->parent = v1;
      ((void (__fastcall *)(Model *, unsigned int, Node *))v1->model->addChild)(v1->model, v15, v18->node);
      LOBYTE(v99) = 9;
      if ( skin._Myres >= 8 )
        operator delete(skin._Bx._Ptr);
      v7 = side;
    }
    ++LODWORD(v7);
    ++v5;
  }
  if ( v1->sim->escMenu && v1->lollipopCrews._Mylast - v1->lollipopCrews._Myfirst )
  {
    LODWORD(v73[6]) = v1;
    LODWORD(v73[0]) = &std::_Func_impl<std::_Callable_obj<_lambda_c4fad89696ecb7c4f1a2aabe83c56fb7_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
    LODWORD(v73[1]) = v1;
    LODWORD(v73[4]) = v73;
    v28 = v1->sim;
    LOBYTE(v99) = 9;
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)&v28->escMenu->evOnDriveMenuPressed,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)v73,
      v1);
  }
  crews._Myfirst = 0;
  crews._Mylast = 0;
  crews._Myend = 0;
  LOBYTE(v99) = 19;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"AC_CREW_", 8u);
  v29 = v1->model;
  LOBYTE(v99) = 20;
  v29->findChildrenByPrefix(v29, &_Left, &crews);
  LOBYTE(v99) = 19;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  v30 = (float *)crews._Myfirst;
  v31 = crews._Mylast;
  if ( crews._Myfirst != crews._Mylast )
  {
    do
    {
      side = *v30;
      v32 = std::wstring::substr((std::wstring *)(LODWORD(side) + 160), &skin, 8u, 0xFFFFFFFF);
      v33 = (const wchar_t *)v32;
      v34 = v32->_Myres < 8;
      LOBYTE(v99) = 21;
      if ( !v34 )
        v33 = v32->_Bx._Ptr;
      v35 = __errno();
      LODWORD(v73[6]) = 10;
      *v35 = 0;
      v36 = _wcstol(v33, &EndPtr, SLODWORD(v73[6]));
      if ( v33 == EndPtr )
        goto $LN2221;
      if ( *__errno() == 34 )
      {
        std::_Xout_of_range((const char *)&stru_17C4688.name._Myres);
$LN2221:
        std::_Xinvalid_argument((const char *)&stru_17C4688);
        JUMPOUT(0x6B7130);
      }
      LOBYTE(v99) = 19;
      if ( skin._Myres >= 8 )
        operator delete(skin._Bx._Ptr);
      v37 = v77;
      v38 = side;
      if ( v77->sim->cars._Mylast - v77->sim->cars._Myfirst <= v36 )
      {
        *(_BYTE *)(LODWORD(side) + 184) = 0;
      }
      else
      {
        *(_BYTE *)(LODWORD(side) + 184) = 1;
        v39 = v37->sim;
        LODWORD(v73[6]) = v36;
        if ( v39->client )
          *(float *)&v40 = COERCE_FLOAT(ACClient::getCarAvatarFromSessionID(v39->client, LOBYTE(v73[6])));
        else
          *(float *)&v40 = COERCE_FLOAT(Sim::getCar(v39, LODWORD(v73[6])));
        side = *(float *)&v40;
        v41 = (std::shared_ptr<Material> *)__RTDynamicCast(
                                             LODWORD(v38),
                                             0,
                                             &Node `RTTI Type Descriptor',
                                             &Mesh `RTTI Type Descriptor',
                                             0);
        if ( v41 )
        {
          v42 = v41[31]._Ptr;
          v76 = v41 + 31;
          v43 = v42->resources._Myfirst;
          if ( v43 != v42->resources._Mylast )
          {
            v44 = &v43->texture.fileName;
            v45 = std::wstring::find_first_of(&v43->texture.fileName, L"::", 0, 2u);
            v46 = v45;
            if ( v45 != -1 )
            {
              std::wstring::substr(v44, &texname, v45 + 2, 0xFFFFFFFF);
              LOBYTE(v99) = 22;
              if ( !std::wstring::compare(&texname, 0, texname._Mysize, L"DRIVER_Suit.dds", 0xFu) )
              {
                v47 = std::wstring::substr(v44, &skin, 0, v46);
                LOBYTE(v99) = 23;
                v48 = std::operator+<wchar_t>(&section, v47, L"::DRIVER_Suit2.dds");
                if ( v44 != v48 )
                {
                  if ( v44->_Myres >= 8 )
                    operator delete(v44->_Bx._Ptr);
                  v44->_Myres = 7;
                  v44->_Mysize = 0;
                  LODWORD(v73[6]) = v48;
                  v44->_Bx._Buf[0] = 0;
                  std::wstring::_Assign_rv(v44, (std::wstring *)LODWORD(v73[6]));
                }
                if ( section._Myres >= 8 )
                  operator delete(section._Bx._Ptr);
                section._Myres = 7;
                section._Mysize = 0;
                section._Bx._Buf[0] = 0;
                LOBYTE(v99) = 22;
                if ( skin._Myres >= 8 )
                  operator delete(skin._Bx._Ptr);
                std::wstring::assign(&texname, L"DRIVER_Suit2.dds", 0x10u);
              }
              v49 = side;
              v50 = CarAvatar::getCurrentSkin((CarAvatar *)LODWORD(side), &key);
              LOBYTE(v99) = 24;
              v51 = std::operator+<wchar_t>(&iniSkin, L"content/cars/", (const std::wstring *)(LODWORD(v49) + 176));
              LOBYTE(v99) = 25;
              v52 = std::operator+<wchar_t>(&section, v51, L"/skins/");
              LOBYTE(v99) = 26;
              std::operator+<wchar_t>(&_Left, v52, v50);
              if ( section._Myres >= 8 )
                operator delete(section._Bx._Ptr);
              section._Myres = 7;
              section._Mysize = 0;
              section._Bx._Buf[0] = 0;
              if ( iniSkin._Myres >= 8 )
                operator delete(iniSkin._Bx._Ptr);
              iniSkin._Myres = 7;
              iniSkin._Mysize = 0;
              iniSkin._Bx._Buf[0] = 0;
              LOBYTE(v99) = 30;
              if ( key._Myres >= 8 )
                operator delete(key._Bx._Ptr);
              key._Myres = 7;
              key._Bx._Buf[0] = 0;
              key._Mysize = 0;
              v53 = std::operator+<wchar_t>(&v89, &_Left, L"/");
              LOBYTE(v99) = 31;
              std::operator+<wchar_t>(&override_tex, v53, &texname);
              LOBYTE(v99) = 33;
              if ( v89._Myres >= 8 )
                operator delete(v89._Bx._Ptr);
              v89._Myres = 7;
              v89._Bx._Buf[0] = 0;
              v89._Mysize = 0;
              std::operator+<wchar_t>(&crewskin, &_Left, L"/skin.ini");
              LOBYTE(v99) = 34;
              LOBYTE(v50) = 1;
              if ( Path::fileExists((unsigned int)v50, &crewskin, 0) )
              {
                CarAvatar::openINI((CarAvatar *)LODWORD(v49), &iniS, &crewskin);
                LOBYTE(v99) = 35;
                if ( iniS.ready )
                {
                  section._Myres = 7;
                  section._Mysize = 0;
                  section._Bx._Buf[0] = 0;
                  std::wstring::assign(&section, L"CREW", 4u);
                  LOBYTE(v99) = 36;
                  key._Myres = 7;
                  key._Mysize = 0;
                  key._Bx._Buf[0] = 0;
                  std::wstring::assign(&key, L"SUIT", 4u);
                  LOBYTE(v99) = 37;
                  if ( INIReader::hasSection(&iniS, &section) )
                  {
                    iniSkin._Myres = 7;
                    iniSkin._Mysize = 0;
                    iniSkin._Bx._Buf[0] = 0;
                    LOBYTE(v99) = 38;
                    if ( INIReader::hasKey(&iniS, &section, &key) )
                    {
                      v50 = INIReader::getString(&iniS, (std::wstring *)&v92, &section, &key);
                      LOBYTE(v99) = 39;
                      v54 = std::operator+<wchar_t>(&skin, L"content/texture/crew_", &key);
                      LOBYTE(v99) = 40;
                      v55 = std::operator+<wchar_t>(&v89, v54, v50);
                      std::wstring::operator=(&iniSkin, v55);
                      if ( v89._Myres >= 8 )
                        operator delete(v89._Bx._Ptr);
                      v89._Myres = 7;
                      v89._Mysize = 0;
                      v89._Bx._Buf[0] = 0;
                      if ( skin._Myres >= 8 )
                        operator delete(skin._Bx._Ptr);
                      skin._Myres = 7;
                      skin._Mysize = 0;
                      skin._Bx._Buf[0] = 0;
                      LOBYTE(v99) = 38;
                      if ( v92.fileName._Mysize >= 8 )
                        operator delete(v92.kid);
                      if ( Path::folderExists(&iniSkin) )
                      {
                        v56 = std::operator+<wchar_t>(&skin, &iniSkin, L"/");
                        LOBYTE(v99) = 41;
                        v57 = std::operator+<wchar_t>((std::wstring *)&v92, v56, &texname);
                        LOBYTE(v99) = 42;
                        v58 = Path::fileExists((unsigned int)v50, v57, 0);
                        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v92);
                        LOBYTE(v99) = 38;
                        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&skin);
                        if ( v58 )
                        {
                          v59 = std::operator+<wchar_t>(&skin, &iniSkin, L"/");
                          LOBYTE(v99) = 43;
                          v60 = std::operator+<wchar_t>((std::wstring *)&v92, v59, &texname);
                          std::wstring::operator=(&override_tex, v60);
                          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v92);
                          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&skin);
                        }
                      }
                    }
                    LOBYTE(v50) = 0;
                    if ( iniSkin._Myres >= 8 )
                      operator delete(iniSkin._Bx._Ptr);
                  }
                  if ( key._Myres >= 8 )
                    operator delete(key._Bx._Ptr);
                  key._Myres = 7;
                  key._Mysize = 0;
                  key._Bx._Buf[0] = 0;
                  if ( section._Myres >= 8 )
                    operator delete(section._Bx._Ptr);
                }
                LOBYTE(v99) = 34;
                INIReader::~INIReader(&iniS);
              }
              if ( (_BYTE)v50 )
              {
                v61 = CarAvatar::getCurrentSkin((CarAvatar *)LODWORD(v49), (std::wstring *)&v92);
                LOBYTE(v99) = 44;
                v62 = std::operator+<wchar_t>(&key, L"content/cars/", (const std::wstring *)(LODWORD(v49) + 176));
                LOBYTE(v99) = 45;
                v63 = std::operator+<wchar_t>(&iniSkin, v62, L"/skins/");
                LOBYTE(v99) = 46;
                v64 = std::operator+<wchar_t>(&section, v63, v61);
                LOBYTE(v99) = 47;
                v65 = std::operator+<wchar_t>(&v89, v64, L"/");
                LOBYTE(v99) = 48;
                v50 = std::operator+<wchar_t>(&skin, v65, &texname);
                if ( &override_tex != v50 )
                {
                  if ( override_tex._Myres >= 8 )
                    operator delete(override_tex._Bx._Ptr);
                  override_tex._Myres = 7;
                  override_tex._Mysize = 0;
                  override_tex._Bx._Buf[0] = 0;
                  std::wstring::_Assign_rv(&override_tex, v50);
                }
                if ( skin._Myres >= 8 )
                  operator delete(skin._Bx._Ptr);
                skin._Myres = 7;
                skin._Mysize = 0;
                skin._Bx._Buf[0] = 0;
                if ( v89._Myres >= 8 )
                  operator delete(v89._Bx._Ptr);
                v89._Myres = 7;
                v89._Mysize = 0;
                v89._Bx._Buf[0] = 0;
                if ( section._Myres >= 8 )
                  operator delete(section._Bx._Ptr);
                section._Myres = 7;
                section._Mysize = 0;
                section._Bx._Buf[0] = 0;
                if ( iniSkin._Myres >= 8 )
                  operator delete(iniSkin._Bx._Ptr);
                iniSkin._Myres = 7;
                iniSkin._Mysize = 0;
                iniSkin._Bx._Buf[0] = 0;
                if ( key._Myres >= 8 )
                  operator delete(key._Bx._Ptr);
                key._Myres = 7;
                key._Mysize = 0;
                key._Bx._Buf[0] = 0;
                LOBYTE(v99) = 34;
                if ( v92.fileName._Mysize >= 8 )
                  operator delete(v92.kid);
              }
              if ( Path::fileExists((unsigned int)v50, &override_tex, 0) )
              {
                v66 = v76;
                side = *(float *)&v76->_Ptr;
                std::make_shared<Material,Material *>(&clone, (Material **)&side);
                LOBYTE(v99) = 49;
                v67 = ResourceStore::getTexture(v77->game->graphics->resourceStore._Myptr, &v92, &override_tex, 0);
                LOBYTE(v99) = 50;
                v68 = clone._Ptr->resources._Myfirst;
                v69 = v67->kid;
                v70 = &v67->fileName;
                v68->texture.kid = v69;
                if ( &v68->texture.fileName != v70 )
                  std::wstring::assign(&v68->texture.fileName, v70, 0, 0xFFFFFFFF);
                LOBYTE(v99) = 49;
                OnSetupAppCreated::~OnSetupAppCreated(&v92);
                std::shared_ptr<Material>::operator=(v66, &clone);
                v71 = clone._Rep;
                LOBYTE(v99) = 34;
                if ( clone._Rep )
                {
                  if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&clone._Rep->_Uses, 0xFFFFFFFF) )
                  {
                    v71->_Destroy(v71);
                    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v71->_Weaks, 0xFFFFFFFF) )
                      v71->_Delete_this(v71);
                  }
                }
              }
              if ( crewskin._Myres >= 8 )
                operator delete(crewskin._Bx._Ptr);
              crewskin._Myres = 7;
              crewskin._Mysize = 0;
              crewskin._Bx._Buf[0] = 0;
              if ( override_tex._Myres >= 8 )
                operator delete(override_tex._Bx._Ptr);
              override_tex._Myres = 7;
              override_tex._Mysize = 0;
              override_tex._Bx._Buf[0] = 0;
              if ( _Left._Myres >= 8 )
                operator delete(_Left._Bx._Ptr);
              _Left._Myres = 7;
              _Left._Mysize = 0;
              _Left._Bx._Buf[0] = 0;
              LOBYTE(v99) = 19;
              if ( texname._Myres >= 8 )
                operator delete(texname._Bx._Ptr);
            }
          }
        }
      }
      ++v30;
    }
    while ( v30 != (float *)v31 );
    v30 = (float *)crews._Myfirst;
  }
  LOBYTE(v99) = 9;
  if ( v30 )
  {
    std::_Container_base0::_Orphan_all(&crews);
    operator delete(crews._Myfirst);
    crews._Myfirst = 0;
    crews._Mylast = 0;
    crews._Myend = 0;
  }
  LOBYTE(v99) = 4;
  if ( pits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&pits);
    operator delete(pits._Myfirst);
    pits._Myfirst = 0;
    pits._Mylast = 0;
    pits._Myend = 0;
  }
  v99 = -1;
  INIReader::~INIReader(&ini);
}
void TrackAvatar::initRespawnPositionSet(TrackAvatar *this, const std::wstring *setName)
{
  std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *v2; // esi
  int v3; // edi
  int v4; // ebx
  std::wostream *v5; // eax
  std::wostream *v6; // eax
  std::wostream *v7; // eax
  std::wstring *v8; // eax
  unsigned int v9; // ecx
  int v10; // edi
  std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *v11; // eax
  int v12; // xmm1_4
  int v13; // xmm2_4
  std::_Tree_buy<std::pair<std::wstring const ,std::vector<AudioEvent *> >> *v14; // ebx
  std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *v15; // eax
  std::_Tree_node<std::pair<std::wstring const ,std::vector<Node *> >,void *> *v16; // esi
  const wchar_t *v17; // eax
  std::_Tree_node<std::pair<std::wstring const ,std::vector<Node *> >,void *> *v18; // eax
  Node **v19; // eax
  Node **v20; // ecx
  int v21; // ebx
  Node **v22; // ecx
  _DWORD *v23; // eax
  int v24; // eax
  char v25; // [esp+33h] [ebp-119h]
  Node *tr; // [esp+34h] [ebp-118h] BYREF
  std::tuple<> v27; // [esp+3Bh] [ebp-111h] BYREF
  int v28; // [esp+3Ch] [ebp-110h]
  int v29; // [esp+40h] [ebp-10Ch]
  std::tuple<std::wstring const &> v30; // [esp+44h] [ebp-108h] BYREF
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,std::vector<Node *> > > > > result; // [esp+48h] [ebp-104h] BYREF
  TrackAvatar *v32; // [esp+4Ch] [ebp-100h]
  int v33[3]; // [esp+50h] [ebp-FCh] BYREF
  int v34[2]; // [esp+5Ch] [ebp-F0h] BYREF
  int v35; // [esp+64h] [ebp-E8h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v36; // [esp+68h] [ebp-E4h] BYREF
  RayCastResult res; // [esp+118h] [ebp-34h] BYREF
  int v38; // [esp+148h] [ebp-4h]

  v2 = (std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *)this;
  v32 = this;
  v3 = 0;
  v4 = 0;
  v29 = 0;
  v25 = 0;
  v28 = 0;
  do
  {
    *(_DWORD *)v36.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v36.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v36.gap68);
    v38 = 0;
    v29 = v3 | 1;
    std::wiostream::basic_iostream<wchar_t>(&v36, &v36.gap10[8], 0);
    v38 = 1;
    *(_DWORD *)&v36.gap0[*(_DWORD *)(*(_DWORD *)v36.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v35 + *(_DWORD *)(*(_DWORD *)v36.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v36.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v36.gap10[8]);
    *(_DWORD *)&v36.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v36.gap10[64] = 0;
    *(_DWORD *)&v36.gap10[68] = 0;
    v38 = 3;
    v5 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v36.gap10, "AC_");
    v6 = std::operator<<<wchar_t>(v5, setName);
    v7 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v6, "_");
    std::wostream::operator<<(v7, v4);
    v8 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
           &v36,
           (std::wstring *)&res);
    v9 = v2[20]._Mysize;
    LOBYTE(v38) = 4;
    v10 = (*(int (**)(unsigned int, std::wstring *, int))(*(_DWORD *)v9 + 20))(v9, v8, 1);
    tr = (Node *)v10;
    LOBYTE(v38) = 3;
    if ( LODWORD(res.normal.y) >= 8 )
      operator delete(res.surfaceDef);
    if ( v10 )
    {
      v11 = v2[21]._Myhead;
      res.normal.y = 0.0;
      *(_OWORD *)&res.pos.x = 0i64;
      res.normal.z = 0.0;
      res.surfaceDef = 0;
      res.hasHit = 0;
      res.collisionObject = 0;
      v33[0] = 0;
      v33[1] = -1082130432;
      v33[2] = 0;
      *(float *)&v12 = *(float *)(v10 + 56) + 10.0;
      v13 = *(_DWORD *)(v10 + 60);
      v34[0] = *(_DWORD *)(v10 + 52);
      v34[1] = v12;
      v35 = v13;
      ((void (__stdcall *)(int *, int *, RayCastResult *, int))v11->_Parent)(v34, v33, &res, 1120403456);
      if ( res.hasHit )
        *(vec3f *)(v10 + 52) = res.pos;
      v14 = (std::_Tree_buy<std::pair<std::wstring const ,std::vector<AudioEvent *> >> *)&v2[50];
      v15 = std::_Tree<std::_Tmap_traits<std::wstring,CBuffer *,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,CBuffer *>>,0>>::_Lbound(
              v2 + 50,
              setName);
      v16 = (std::_Tree_node<std::pair<std::wstring const ,std::vector<Node *> >,void *> *)v15;
      if ( v15 == (std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *)v14->_Myhead )
        goto LABEL_11;
      v17 = v15->_Myval.first._Bx._Buf;
      if ( v16->_Myval.first._Myres >= 8 )
        v17 = *(const wchar_t **)v17;
      if ( std::wstring::compare((std::wstring *)setName, 0, setName->_Mysize, v17, v16->_Myval.first._Mysize) < 0 )
      {
LABEL_11:
        v30._Myfirst._Val = setName;
        v18 = (std::_Tree_node<std::pair<std::wstring const ,std::vector<Node *> >,void *> *)std::_Tree_buy<std::pair<std::wstring const,std::vector<AudioEvent *>>>::_Buynode<std::piecewise_construct_t const &,std::tuple<std::wstring const &>,std::tuple<>>(
                                                                                               v14,
                                                                                               &piecewise_construct_20,
                                                                                               &v30,
                                                                                               &v27);
        std::_Tree<std::_Tmap_traits<std::wstring,std::vector<Node *>,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,std::vector<Node *>>>,0>>::_Insert_hint<std::pair<std::wstring const,std::vector<Node *>> &,std::_Tree_node<std::pair<std::wstring const,std::vector<Node *>>,void *> *>(
          (std::_Tree<std::_Tmap_traits<std::wstring,std::vector<Node *>,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,std::vector<Node *> > >,0> > *)v14,
          &result,
          (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,std::vector<Node *> > > > >)v16,
          &v18->_Myval,
          v18);
        v16 = result._Ptr;
      }
      v19 = v16->_Myval.second._Mylast;
      if ( &tr >= v19 || (v20 = v16->_Myval.second._Myfirst, v20 > &tr) )
      {
        if ( v19 == v16->_Myval.second._Myend )
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&v16->_Myval.second, 1u);
        v23 = v16->_Myval.second._Mylast;
        if ( v23 )
          *v23 = v10;
      }
      else
      {
        v21 = &tr - v20;
        if ( v19 == v16->_Myval.second._Myend )
          std::vector<SVar *>::_Reserve((std::vector<ICollisionObject *> *)&v16->_Myval.second, 1u);
        v22 = v16->_Myval.second._Mylast;
        if ( v22 )
          *v22 = v16->_Myval.second._Myfirst[v21];
      }
      ++v16->_Myval.second._Mylast;
      v4 = v28;
      v2 = (std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *)v32;
      *(_BYTE *)(v10 + 184) = 0;
    }
    else
    {
      v25 = 1;
    }
    v28 = ++v4;
    v38 = -1;
    *(_DWORD *)&v36.gap0[*(_DWORD *)(*(_DWORD *)v36.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v35 + *(_DWORD *)(*(_DWORD *)v36.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v36.gap0 + 4) - 104;
    *(_DWORD *)&v36.gap10[8] = &std::wstringbuf::`vftable';
    if ( (v36.gap10[68] & 1) != 0 )
    {
      if ( std::wstreambuf::pptr(&v36.gap10[8]) )
        std::wstreambuf::epptr(&v36.gap10[8]);
      else
        std::wstreambuf::egptr(&v36.gap10[8]);
      std::wstreambuf::eback(&v36.gap10[8]);
      v24 = std::wstreambuf::eback(&v36.gap10[8]);
      operator delete(v24);
    }
    std::wstreambuf::setg(&v36.gap10[8], 0, 0, 0);
    std::wstreambuf::setp(&v36.gap10[8], 0, 0);
    *(_DWORD *)&v36.gap10[68] &= 0xFFFFFFFE;
    *(_DWORD *)&v36.gap10[64] = 0;
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v36.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v36.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v36.gap68);
    v3 = v29;
  }
  while ( !v25 );
}
void TrackAvatar::initTimeLines(TrackAvatar *this)
{
  int v2; // ebp
  int v3; // ebx
  std::wostream *v4; // eax
  std::wostream *v5; // eax
  std::wstring *v6; // eax
  _DWORD *v7; // ebp
  int v8; // eax
  std::wstring *v9; // ecx
  std::wostream *v10; // eax
  std::wostream *v11; // eax
  std::wstring *v12; // eax
  Sim *v13; // ecx
  int v14; // esi
  unsigned int v15; // xmm1_4
  unsigned int v16; // xmm2_4
  unsigned int v17; // xmm0_4
  int v18; // xmm2_4
  int v19; // eax
  Sim *v20; // eax
  Sim *v21; // eax
  int v22; // esi
  Sim *v23; // eax
  Node *v24; // ebp
  Sim *v25; // eax
  int v26; // ebx
  unsigned int v27; // xmm1_4
  unsigned int v28; // xmm2_4
  float v29; // xmm0_4
  float v30; // xmm2_4
  unsigned int v31; // xmm1_4
  unsigned int v32; // xmm2_4
  float v33; // xmm0_4
  float v34; // xmm2_4
  Sim *v35; // eax
  int v36; // ebx
  Sim *v37; // eax
  int v38; // esi
  const char *v39; // [esp+50h] [ebp-16Ch]
  int v40; // [esp+54h] [ebp-168h]
  int v41; // [esp+58h] [ebp-164h]
  char v42; // [esp+73h] [ebp-149h]
  int v43; // [esp+74h] [ebp-148h]
  Node *v44; // [esp+74h] [ebp-148h]
  vec3f v45; // [esp+78h] [ebp-144h] BYREF
  _DWORD *v46; // [esp+84h] [ebp-138h] BYREF
  int v47; // [esp+88h] [ebp-134h] BYREF
  std::wostream v48; // [esp+94h] [ebp-128h] BYREF
  _BYTE v49[72]; // [esp+ECh] [ebp-D0h] BYREF
  std::wstring v50; // [esp+134h] [ebp-88h] BYREF
  std::wstring v51; // [esp+14Ch] [ebp-70h] BYREF
  std::wstring p1; // [esp+164h] [ebp-58h] BYREF
  std::wstring p2; // [esp+17Ch] [ebp-40h] BYREF
  std::wstring v54; // [esp+194h] [ebp-28h] BYREF
  char v55; // [esp+1B4h] [ebp-8h]
  int v56; // [esp+1B8h] [ebp-4h]
  void *retaddr; // [esp+1BCh] [ebp+0h]

  v2 = 0;
  v42 = 1;
  v3 = 0;
  do
  {
    v46 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v48.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v49);
    v56 = 0;
    v43 = v2 | 1;
    std::wiostream::basic_iostream<wchar_t>(&v46, &v48.gap0[8], 0);
    v56 = 1;
    *(_DWORD **)((char *)&v46 + v46[1]) = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)((char *)&v45.z + v46[1]) = v46[1] - 104;
    std::wstreambuf::wstreambuf(&v48.gap0[8]);
    *(_DWORD *)&v48.gap0[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v48.gap0[64] = 0;
    *(_DWORD *)&v48.gap0[68] = 0;
    v56 = 3;
    v4 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&v48, "AC_TIME_");
    v5 = (std::wostream *)std::wostream::operator<<(v4, v3);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v5, (const char *)v41);
    v6 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
           (std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > *)&v47,
           (std::wstring *)&v50._Bx._Alias[4]);
    v41 = 1;
    LOBYTE(retaddr) = 4;
    v7 = (_DWORD *)((int (*)(Node *, std::wstring *))this->sim->trackNode->findChildByName)(
                     this->sim->trackNode,
                     v6);
    LOBYTE(v56) = 3;
    if ( v50._Myres >= 8 )
      operator delete(v50._Bx._Ptr);
    v50._Myres = 7;
    v50._Mysize = 0;
    v50._Bx._Buf[0] = 0;
    v54._Myres = 7;
    v54._Mysize = 0;
    v54._Bx._Buf[0] = 0;
    std::wstring::assign(&v54, word_17BE9D8, 0);
    LOBYTE(v56) = 5;
    if ( (v48.gap0[68] & 1) != 0 )
    {
      if ( std::wstreambuf::pptr(&v48.gap0[8]) )
        std::wstreambuf::epptr(&v48.gap0[8]);
      else
        std::wstreambuf::egptr(&v48.gap0[8]);
      std::wstreambuf::eback(&v48.gap0[8]);
      v8 = std::wstreambuf::eback(&v48.gap0[8]);
      operator delete(v8);
    }
    std::wstreambuf::setg(&v48.gap0[8], 0, 0, 0);
    std::wstreambuf::setp(&v48.gap0[8], 0, 0);
    v9 = &v54;
    *(_DWORD *)&v48.gap0[64] = 0;
    v40 = *(_DWORD *)&v48.gap0[68] & 0xFFFFFFFE;
    if ( v54._Myres >= 8 )
      v9 = (std::wstring *)v54._Bx._Ptr;
    *(_DWORD *)&v48.gap0[68] &= 0xFFFFFFFE;
    std::wstringbuf::_Init((std::wstringbuf *)&v48.gap0[8], v9->_Bx._Buf, v54._Mysize, v40);
    LOBYTE(v56) = 3;
    if ( v54._Myres >= 8 )
      operator delete(v54._Bx._Ptr);
    v10 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&v48, "AC_TIME_");
    v11 = (std::wostream *)std::wostream::operator<<(v10, v3);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v11, v39);
    v12 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
            (std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > *)&v45.z,
            (std::wstring *)&v50._Myres);
    v13 = this->sim;
    v55 = 6;
    v14 = ((int (*)(Node *, std::wstring *, int, const char *))v13->trackNode->findChildByName)(
            v13->trackNode,
            v12,
            1,
            "_R");
    LOBYTE(v56) = 3;
    if ( v51._Myres >= 8 )
      operator delete(v51._Bx._Ptr);
    v51._Myres = 7;
    v51._Mysize = 0;
    v51._Bx._Buf[0] = 0;
    if ( v7 && v14 )
    {
      v15 = *(_DWORD *)(v14 + 56);
      v16 = *(_DWORD *)(v14 + 60);
      p2._Bx._Ptr = *(wchar_t **)(v14 + 52);
      v17 = v7[13];
      *(_QWORD *)&p2._Bx._Alias[4] = __PAIR64__(v16, v15);
      v18 = v7[15];
      *(_QWORD *)p1._Bx._Buf = __PAIR64__(v7[14], v17);
      *(_DWORD *)&p1._Bx._Alias[8] = v18;
      Track::addTimeLine(&this->physicsTrack, (const vec3f *)&p1, (const vec3f *)&p2, Default);
    }
    else
    {
      v42 = 0;
    }
    ++v3;
    v56 = -1;
    *(_DWORD **)((char *)&v46 + v46[1]) = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)((char *)&v45.z + v46[1]) = v46[1] - 104;
    *(_DWORD *)&v48.gap0[8] = &std::wstringbuf::`vftable';
    if ( (v48.gap0[68] & 1) != 0 )
    {
      if ( std::wstreambuf::pptr(&v48.gap0[8]) )
        std::wstreambuf::epptr(&v48.gap0[8]);
      else
        std::wstreambuf::egptr(&v48.gap0[8]);
      std::wstreambuf::eback(&v48.gap0[8]);
      v19 = std::wstreambuf::eback(&v48.gap0[8]);
      operator delete(v19);
    }
    std::wstreambuf::setg(&v48.gap0[8], 0, 0, 0);
    std::wstreambuf::setp(&v48.gap0[8], 0, 0);
    *(_DWORD *)&v48.gap0[68] &= 0xFFFFFFFE;
    *(_DWORD *)&v48.gap0[64] = 0;
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v48.gap0[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v48.gap0[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v49);
    v2 = v43;
  }
  while ( v42 );
  p2._Myres = 7;
  p2._Mysize = 0;
  p2._Bx._Buf[0] = 0;
  std::wstring::assign(&p2, L"AC_AB_START_L", 0xDu);
  v20 = this->sim;
  v56 = 7;
  v44 = v20->trackNode->findChildByName(v20->trackNode, &p2, 1);
  v56 = -1;
  if ( p2._Myres >= 8 )
    operator delete(p2._Bx._Ptr);
  p2._Myres = 7;
  p2._Mysize = 0;
  p2._Bx._Buf[0] = 0;
  p1._Myres = 7;
  p1._Mysize = 0;
  p1._Bx._Buf[0] = 0;
  std::wstring::assign(&p1, L"AC_AB_START_R", 0xDu);
  v21 = this->sim;
  v56 = 8;
  v22 = (int)v21->trackNode->findChildByName(v21->trackNode, &p1, 1);
  v56 = -1;
  if ( p1._Myres >= 8 )
    operator delete(p1._Bx._Ptr);
  p1._Myres = 7;
  p1._Mysize = 0;
  p1._Bx._Buf[0] = 0;
  v51._Myres = 7;
  v51._Mysize = 0;
  v51._Bx._Buf[0] = 0;
  std::wstring::assign(&v51, L"AC_AB_FINISH_L", 0xEu);
  v23 = this->sim;
  v56 = 9;
  v24 = v23->trackNode->findChildByName(v23->trackNode, &v51, 1);
  v56 = -1;
  if ( v51._Myres >= 8 )
    operator delete(v51._Bx._Ptr);
  v51._Myres = 7;
  v51._Mysize = 0;
  v51._Bx._Buf[0] = 0;
  v50._Myres = 7;
  v50._Mysize = 0;
  v50._Bx._Buf[0] = 0;
  std::wstring::assign(&v50, L"AC_AB_FINISH_R", 0xEu);
  v25 = this->sim;
  v56 = 10;
  v26 = (int)v25->trackNode->findChildByName(v25->trackNode, &v50, 1);
  v56 = -1;
  if ( v50._Myres >= 8 )
    operator delete(v50._Bx._Ptr);
  v50._Myres = 7;
  v50._Mysize = 0;
  v50._Bx._Buf[0] = 0;
  if ( v44 && v22 && v24 && v26 )
  {
    _printf("TRACK IS AN OPENTRACK\n");
    v27 = *(_DWORD *)(v22 + 56);
    v28 = *(_DWORD *)(v22 + 60);
    p1._Bx._Ptr = *(wchar_t **)(v22 + 52);
    v29 = v44->matrix.M41;
    *(_QWORD *)&p1._Bx._Alias[4] = __PAIR64__(v28, v27);
    v30 = v44->matrix.M43;
    *(_QWORD *)p2._Bx._Buf = __PAIR64__(LODWORD(v44->matrix.M42), LODWORD(v29));
    *(float *)&p2._Bx._Alias[8] = v30;
    Track::addTimeLine(&this->physicsTrack, (const vec3f *)&p2, (const vec3f *)&p1, Skinned);
    v31 = *(_DWORD *)(v26 + 56);
    v32 = *(_DWORD *)(v26 + 60);
    p1._Bx._Ptr = *(wchar_t **)(v26 + 52);
    v33 = v24->matrix.M41;
    *(_QWORD *)&p1._Bx._Alias[4] = __PAIR64__(v32, v31);
    v34 = v24->matrix.M43;
    *(_QWORD *)p2._Bx._Buf = __PAIR64__(LODWORD(v24->matrix.M42), LODWORD(v33));
    *(float *)&p2._Bx._Alias[8] = v34;
    Track::addTimeLine(&this->physicsTrack, (const vec3f *)&p2, (const vec3f *)&p1, Particle);
  }
  v50._Myres = 7;
  v50._Mysize = 0;
  v50._Bx._Buf[0] = 0;
  std::wstring::assign(&v50, L"AC_OPEN_FINISH_L", 0x10u);
  v35 = this->sim;
  v56 = 11;
  v36 = (int)v35->trackNode->findChildByName(v35->trackNode, &v50, 1);
  v56 = -1;
  if ( v50._Myres >= 8 )
    operator delete(v50._Bx._Ptr);
  v50._Myres = 7;
  v50._Mysize = 0;
  v50._Bx._Buf[0] = 0;
  v51._Myres = 7;
  v51._Mysize = 0;
  v51._Bx._Buf[0] = 0;
  std::wstring::assign(&v51, L"AC_OPEN_FINISH_R", 0x10u);
  v37 = this->sim;
  v56 = 12;
  v38 = (int)v37->trackNode->findChildByName(v37->trackNode, &v51, 1);
  v56 = -1;
  if ( v51._Myres >= 8 )
    operator delete(v51._Bx._Ptr);
  v51._Myres = 7;
  v51._Mysize = 0;
  v51._Bx._Buf[0] = 0;
  if ( v36 )
  {
    if ( v38 )
    {
      v45 = *(vec3f *)(v38 + 52);
      *(_QWORD *)v54._Bx._Buf = *(_QWORD *)(v36 + 52);
      *(_DWORD *)&v54._Bx._Alias[8] = *(_DWORD *)(v36 + 60);
      Track::addTimeLine(&this->physicsTrack, (const vec3f *)&v54, &v45, Default);
    }
  }
}
void TrackAvatar::processPhysicsNode(TrackAvatar *this, Node *node)
{
  Node *v3; // esi
  unsigned int v4; // edi
  int *v5; // eax
  int v6; // ecx
  Node **v7; // eax
  Node **v8; // esi
  int v9; // edi
  unsigned int v10; // ebx
  std::wstring v11; // [esp-18h] [ebp-3Ch] BYREF
  NKUtils nku; // [esp+14h] [ebp-10h] BYREF
  int v13; // [esp+20h] [ebp-4h]

  v3 = node;
  v4 = __RTDynamicCast(node, 0, &Node `RTTI Type Descriptor', &Mesh `RTTI Type Descriptor', 0);
  NKUtils::NKUtils(&nku);
  v13 = 0;
  if ( v4 )
  {
    v11._Myres = 7;
    v11._Mysize = 0;
    v11._Bx._Buf[0] = 0;
    std::wstring::assign(&v11, (const std::wstring *)(v4 + 160), 0, 0xFFFFFFFF);
    node = (Node *)NKUtils::getSectorID(&nku, v11);
    if ( node )
    {
      ++this->physicsStats.objects;
      v5 = std::map<int,int>::operator[](&this->physicsStats.groups, (const int *)&node);
      ++*v5;
      v6 = *(_DWORD *)(v4 + 240) - *(_DWORD *)(v4 + 236);
      v11._Myres = (unsigned int)node;
      v11._Mysize = v4;
      this->physicsStats.tris += (v6 >> 1) / 3u;
      TrackAvatar::addPhysicsMesh(this, (Mesh *)v11._Mysize, v11._Myres);
    }
  }
  if ( !std::wstring::find(&v3->name, L"AC_", 0, 3u) )
    v3->isActive = 0;
  v7 = v3->nodes._Mylast;
  v8 = v3->nodes._Myfirst;
  v9 = 0;
  v10 = (unsigned int)((char *)v7 - (char *)v8 + 3) >> 2;
  if ( v8 > v7 )
    v10 = 0;
  if ( v10 )
  {
    do
    {
      TrackAvatar::processPhysicsNode(this, *v8);
      ++v9;
      ++v8;
    }
    while ( v9 != v10 );
  }
  v13 = -1;
  NKUtils::~NKUtils(&nku);
}
void TrackAvatar::setDynamicGrooveVisibility(TrackAvatar *this, bool visibility)
{
  DynamicTrackManager::setGrooveMeshVisibility(this->dynamicTrackManager, visibility);
}
void TrackAvatar::update(TrackAvatar *this, float dt)
{
  Sim *v3; // ecx
  unsigned int i; // edi
  CarAvatar *v5; // eax
  int v6; // eax
  int v7; // ebx
  Sim *v8; // ecx
  CarAvatar *v9; // eax
  bool v10; // zf
  Node *v11; // eax

  v3 = this->sim;
  if ( v3->client )
  {
    for ( i = 0; i < v3->cars._Mylast - v3->cars._Myfirst; ++i )
    {
      v5 = Sim::getCar(v3, i);
      v6 = ACClient::getSessionIDFromCarAvatar(this->sim->client, v5);
      v7 = v6;
      if ( v6 >= 0 )
      {
        v8 = this->sim;
        if ( v6 < (unsigned int)(v8->cars._Mylast - v8->cars._Myfirst) )
        {
          v9 = Sim::getCar(v8, i);
          v10 = ACClient::getPing(this->sim->client, v9) == 0;
          v11 = this->lollipopCrews._Myfirst[v7]->node;
          v11->isActive = !v10;
        }
      }
      v3 = this->sim;
    }
  }
  TrackAvatar::updateDynamicObjects(this, dt);
}
void TrackAvatar::updateDynamicObjects(TrackAvatar *this, float dt)
{
  DynamicTrackObject *v2; // edx
  DynamicTrackObject *v3; // eax
  float *v4; // edi
  __m128 v5; // xmm3
  Node *v6; // esi
  __m128 v7; // xmm1
  float v8; // xmm0_4
  unsigned int v9; // ecx

  v2 = this->dynamicObjects._Mylast;
  v3 = this->dynamicObjects._Myfirst;
  if ( v3 != v2 )
  {
    v4 = &v3->pos.y;
    do
    {
      v5 = (__m128)*((unsigned int *)v4 - 1);
      v6 = v3->node;
      ++v3;
      v5.m128_f32[0] = v5.m128_f32[0] + (float)(v4[5] * dt);
      v7 = (__m128)*(unsigned int *)v4;
      v7.m128_f32[0] = v7.m128_f32[0] + (float)(v4[6] * dt);
      v8 = v4[1] + (float)(v4[7] * dt);
      *(_QWORD *)(v4 - 1) = _mm_unpacklo_ps(v5, v7).m128_u64[0];
      v4[1] = v8;
      v6->matrix.M41 = *(v4 - 1);
      v6->matrix.M42 = *v4;
      v9 = *((_DWORD *)v4 + 1);
      v4 += 13;
      LODWORD(v6->matrix.M43) = v9;
    }
    while ( v3 != v2 );
  }
}
