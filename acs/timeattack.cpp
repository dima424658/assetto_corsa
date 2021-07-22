#include "timeattack.h"
void __userpurge TimeAttack::TimeAttack(TimeAttack *this@<ecx>, char a2@<bl>, __m128 a3@<xmm3>, __m128 a4@<xmm4>, CarAvatar *aCar)
{
  CarAvatar *v6; // eax
  std::wstring *v7; // eax
  const std::wstring *v8; // eax
  bool v9; // bl
  bool v10; // bl
  double v11; // st7
  bool v12; // cf
  Game *v13; // eax
  Texture *v14; // eax
  Game *v15; // eax
  Texture *v16; // eax
  Game *v17; // eax
  Texture *v18; // eax
  Game *v19; // eax
  Texture *v20; // eax
  Game *v21; // eax
  Texture *v22; // eax
  Game *v23; // eax
  Texture *v24; // eax
  Game *v25; // eax
  Texture *v26; // eax
  CarAvatar *v27; // eax
  Texture *v28; // eax
  Font *v29; // eax
  Font *v30; // eax
  std::_Ref_count_base *v31; // esi
  Font *v32; // eax
  CarAvatar *v33; // eax
  CarAvatar *v34; // eax
  TimeEvaluation *v35; // eax
  float *v36; // edx
  float *i; // eax
  float v38; // xmm1_4
  TrackAvatar *v39; // edx
  CarAvatar *v40; // eax
  std::wstring v41; // [esp-10h] [ebp-120h] BYREF
  unsigned int v42; // [esp+8h] [ebp-108h]
  std::shared_ptr<Font> _Right; // [esp+2Ch] [ebp-E4h] BYREF
  std::vector<float> estimatedTimesPerSector; // [esp+34h] [ebp-DCh] BYREF
  TimeAttack *v45; // [esp+40h] [ebp-D0h]
  mat44f pos; // [esp+44h] [ebp-CCh] BYREF
  Texture result; // [esp+84h] [ebp-8Ch] BYREF
  Texture key; // [esp+A0h] [ebp-70h] BYREF
  INIReaderDocuments ini; // [esp+BCh] [ebp-54h] BYREF
  int v50; // [esp+10Ch] [ebp-4h]

  v45 = this;
  v42 = (unsigned int)aCar->game;
  v41._Myres = 7;
  v41._Mysize = 0;
  v41._Bx._Buf[0] = 0;
  std::wstring::assign(&v41, L"TIME_ATTACK", 0xBu);
  GameMode::GameMode(this, v41, (Game *)v42);
  this->__vftable = (TimeAttack_vtbl *)&TimeAttack::`vftable';
  v50 = 0;
  this->overlays._Myfirst = 0;
  this->overlays._Mylast = 0;
  this->overlays._Myend = 0;
  this->font._Ptr = 0;
  this->font._Rep = 0;
  this->guiStartTex.kid = 0;
  this->guiStartTex.fileName._Myres = 7;
  this->guiStartTex.fileName._Mysize = 0;
  this->guiStartTex.fileName._Bx._Buf[0] = 0;
  this->guiCheckpointTex.kid = 0;
  this->guiCheckpointTex.fileName._Myres = 7;
  this->guiCheckpointTex.fileName._Mysize = 0;
  this->guiCheckpointTex.fileName._Bx._Buf[0] = 0;
  this->guiWhiteClock.kid = 0;
  this->guiWhiteClock.fileName._Myres = 7;
  this->guiWhiteClock.fileName._Mysize = 0;
  this->guiWhiteClock.fileName._Bx._Buf[0] = 0;
  this->guiWhiteCup.kid = 0;
  this->guiWhiteCup.fileName._Myres = 7;
  this->guiWhiteCup.fileName._Mysize = 0;
  this->guiWhiteCup.fileName._Bx._Buf[0] = 0;
  this->guiBlackClock.kid = 0;
  this->guiBlackClock.fileName._Myres = 7;
  this->guiBlackClock.fileName._Mysize = 0;
  this->guiBlackClock.fileName._Bx._Buf[0] = 0;
  this->guiBlackCup.kid = 0;
  this->guiBlackCup.fileName._Myres = 7;
  this->guiBlackCup.fileName._Mysize = 0;
  this->guiBlackCup.fileName._Bx._Buf[0] = 0;
  this->guiPenalty.kid = 0;
  this->guiPenalty.fileName._Myres = 7;
  this->guiPenalty.fileName._Mysize = 0;
  this->guiPenalty.fileName._Bx._Buf[0] = 0;
  this->checkpointTexture.kid = 0;
  this->checkpointTexture.fileName._Myres = 7;
  this->checkpointTexture.fileName._Mysize = 0;
  this->checkpointTexture.fileName._Bx._Buf[0] = 0;
  *(_WORD *)&this->pause = 0;
  this->lastSectorIndex = 0;
  this->lastSectorUpdate = 0.0;
  this->car = aCar;
  this->target.sectors._Myfirst = 0;
  this->target.sectors._Mylast = 0;
  this->target.sectors._Myend = 0;
  this->target.sectorIncrements._Myfirst = 0;
  this->target.sectorIncrements._Mylast = 0;
  this->target.sectorIncrements._Myend = 0;
  TimeAttackGameStatus::TimeAttackGameStatus(&this->status);
  LOBYTE(v50) = 12;
  this->guiInfo.lastTimeLeft = 0;
  this->guiInfo.scoreLabelTimer = 1000.0;
  this->guiInfo.penaltyPointsAccumulated = 0.0;
  this->guiInfo.penaltyTimer = 0.0;
  this->guiInfo.lastGainedPoints = 0.0;
  this->guiInfo.lastGainedSeconds = 0.0;
  this->guiInfo.lastCarDamage = 0.0;
  v6 = this->car;
  this->timeMult = 1.0;
  PauseMenu::blankButton(v6->sim->pauseMenu, ePauseMenuPits, 1);
  v7 = TrackAvatar::getDataFolder(this->car->sim->track, (std::wstring *)&result);
  LOBYTE(v50) = 13;
  v8 = std::operator+<wchar_t>((std::wstring *)&key, v7, L"/data/overlays.ini");
  LOBYTE(v50) = 14;
  v9 = Path::fileExists(a2, v8, 0) == 0;
  if ( key.fileName._Mysize >= 8 )
    operator delete(key.kid);
  key.fileName._Mysize = 7;
  *(_DWORD *)&key.fileName._Bx._Alias[12] = 0;
  LOWORD(key.kid) = 0;
  LOBYTE(v50) = 12;
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  if ( v9 )
    TimeAttack::createAndSaveOverlays(this);
  v42 = 0;
  v41._Myres = 7;
  v41._Mysize = 0;
  v41._Bx._Buf[0] = 0;
  std::wstring::assign(&v41, L"cfg/gameplay.ini", 0x10u);
  INIReaderDocuments::INIReaderDocuments(&ini, v9, v41, v42);
  LOBYTE(v50) = 15;
  if ( ini.ready )
  {
    result.fileName._Mysize = 7;
    *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
    LOWORD(result.kid) = 0;
    std::wstring::assign((std::wstring *)&result, L"TIME_ATTACK", 0xBu);
    LOBYTE(v50) = 16;
    v10 = INIReader::hasSection(&ini, (const std::wstring *)&result);
    LOBYTE(v50) = 15;
    if ( result.fileName._Mysize >= 8 )
      operator delete(result.kid);
    if ( v10 )
    {
      std::wstring::wstring((std::wstring *)&key, L"BASE_TIME_MULT");
      LOBYTE(v50) = 17;
      std::wstring::wstring((std::wstring *)&result, L"TIME_ATTACK");
      LOBYTE(v50) = 18;
      v11 = INIReader::getFloat(&ini, (const std::wstring *)&result, (const std::wstring *)&key);
      v12 = result.fileName._Mysize < 8;
      this->timeMult = v11;
      if ( !v12 )
        operator delete(result.kid);
      result.fileName._Mysize = 7;
      *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
      LOWORD(result.kid) = 0;
      LOBYTE(v50) = 15;
      if ( key.fileName._Mysize >= 8 )
        operator delete(key.kid);
    }
  }
  TimeAttack::loadOverlaysAndSectors(this);
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  std::wstring::assign((std::wstring *)&result, L"content/gui/timeAttack/timeattack_start.png", 0x2Bu);
  v13 = this->game;
  LOBYTE(v50) = 19;
  v14 = ResourceStore::getTexture(v13->graphics->resourceStore._Myptr, &key, (const std::wstring *)&result, 0);
  this->guiStartTex.kid = v14->kid;
  LOBYTE(v50) = 20;
  if ( &this->guiStartTex.fileName != &v14->fileName )
    std::wstring::assign(&this->guiStartTex.fileName, &v14->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v50) = 19;
  OnSetupAppCreated::~OnSetupAppCreated(&key);
  LOBYTE(v50) = 15;
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  std::wstring::assign((std::wstring *)&result, L"content/gui/timeAttack/checkpoint.png", 0x25u);
  v15 = this->game;
  LOBYTE(v50) = 21;
  v16 = ResourceStore::getTexture(v15->graphics->resourceStore._Myptr, &key, (const std::wstring *)&result, 0);
  this->guiCheckpointTex.kid = v16->kid;
  LOBYTE(v50) = 22;
  if ( &this->guiCheckpointTex.fileName != &v16->fileName )
    std::wstring::assign(&this->guiCheckpointTex.fileName, &v16->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v50) = 21;
  OnSetupAppCreated::~OnSetupAppCreated(&key);
  LOBYTE(v50) = 15;
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  std::wstring::assign((std::wstring *)&result, L"content/gui/timeAttack/time_icon.png", 0x24u);
  v17 = this->game;
  LOBYTE(v50) = 23;
  v18 = ResourceStore::getTexture(v17->graphics->resourceStore._Myptr, &key, (const std::wstring *)&result, 0);
  this->guiWhiteClock.kid = v18->kid;
  LOBYTE(v50) = 24;
  if ( &this->guiWhiteClock.fileName != &v18->fileName )
    std::wstring::assign(&this->guiWhiteClock.fileName, &v18->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v50) = 23;
  OnSetupAppCreated::~OnSetupAppCreated(&key);
  LOBYTE(v50) = 15;
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  std::wstring::assign((std::wstring *)&result, L"content/gui/timeAttack/points_icon.png", 0x26u);
  v19 = this->game;
  LOBYTE(v50) = 25;
  v20 = ResourceStore::getTexture(v19->graphics->resourceStore._Myptr, &key, (const std::wstring *)&result, 0);
  this->guiWhiteCup.kid = v20->kid;
  LOBYTE(v50) = 26;
  if ( &this->guiWhiteCup.fileName != &v20->fileName )
    std::wstring::assign(&this->guiWhiteCup.fileName, &v20->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v50) = 25;
  OnSetupAppCreated::~OnSetupAppCreated(&key);
  LOBYTE(v50) = 15;
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  std::wstring::assign((std::wstring *)&result, L"content/gui/timeAttack/small_time_icon.png", 0x2Au);
  v21 = this->game;
  LOBYTE(v50) = 27;
  v22 = ResourceStore::getTexture(v21->graphics->resourceStore._Myptr, &key, (const std::wstring *)&result, 0);
  this->guiBlackClock.kid = v22->kid;
  LOBYTE(v50) = 28;
  if ( &this->guiBlackClock.fileName != &v22->fileName )
    std::wstring::assign(&this->guiBlackClock.fileName, &v22->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v50) = 27;
  OnSetupAppCreated::~OnSetupAppCreated(&key);
  LOBYTE(v50) = 15;
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  std::wstring::wstring((std::wstring *)&key, L"content/gui/timeAttack/small_points_icon.png");
  v23 = this->game;
  LOBYTE(v50) = 29;
  v24 = ResourceStore::getTexture(v23->graphics->resourceStore._Myptr, &result, (const std::wstring *)&key, 0);
  this->guiBlackCup.kid = v24->kid;
  LOBYTE(v50) = 30;
  if ( &this->guiBlackCup.fileName != &v24->fileName )
    std::wstring::assign(&this->guiBlackCup.fileName, &v24->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v50) = 29;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v50) = 15;
  if ( key.fileName._Mysize >= 8 )
    operator delete(key.kid);
  std::wstring::wstring((std::wstring *)&key, L"content/gui/timeAttack/penalty_icon.png");
  v25 = this->game;
  LOBYTE(v50) = 31;
  v26 = ResourceStore::getTexture(v25->graphics->resourceStore._Myptr, &result, (const std::wstring *)&key, 0);
  this->guiPenalty.kid = v26->kid;
  LOBYTE(v50) = 32;
  if ( &this->guiPenalty.fileName != &v26->fileName )
    std::wstring::assign(&this->guiPenalty.fileName, &v26->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v50) = 31;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v50) = 15;
  if ( key.fileName._Mysize >= 8 )
    operator delete(key.kid);
  std::wstring::wstring((std::wstring *)&key, L"content/texture/checkpoint.png");
  v27 = this->car;
  LOBYTE(v50) = 33;
  v28 = ResourceStore::getTexture(
          v27->sim->game->graphics->resourceStore._Myptr,
          &result,
          (const std::wstring *)&key,
          0);
  this->checkpointTexture.kid = v28->kid;
  LOBYTE(v50) = 34;
  if ( &this->checkpointTexture.fileName != &v28->fileName )
    std::wstring::assign(&this->checkpointTexture.fileName, &v28->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v50) = 33;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v50) = 15;
  if ( key.fileName._Mysize >= 8 )
    operator delete(key.kid);
  v29 = (Font *)operator new(24);
  _Right._Ptr = v29;
  LOBYTE(v50) = 35;
  if ( v29 )
    Font::Font(v29, eFontMonospaced, 45.0, 0, 0);
  else
    v30 = 0;
  LOBYTE(v50) = 15;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v30);
  std::shared_ptr<Font>::operator=(&this->font, &_Right);
  v31 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v31->_Destroy(v31);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v31->_Weaks) )
        v31->_Delete_this(v31);
    }
  }
  v32 = this->font._Ptr;
  v42 = (unsigned int)this;
  v32->shadowed = 1;
  this->car->sim->beforeCarsNode->isActive = 1;
  v41._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_2b8274081ecd2c8e7e86db8c7721e3d7_,0>,std::allocator<std::_Func_class<void,OnNodeRenderEvent const &>>,void,OnNodeRenderEvent const &>::`vftable';
  *(_DWORD *)&v41._Bx._Alias[4] = this;
  v41._Mysize = (unsigned int)&v41;
  v33 = this->car;
  LOBYTE(v50) = 15;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v33->sim->beforeCarsNode->evOnRender,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v41,
    (void *)v42);
  v42 = (unsigned int)this;
  v41._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_4cd83c8fc8d6f26534a91090005cf574_,0>,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>,void,OnNewSessionEvent const &>::`vftable';
  *(_DWORD *)&v41._Bx._Alias[4] = this;
  v41._Mysize = (unsigned int)&v41;
  v34 = this->car;
  LOBYTE(v50) = 15;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v34->sim->evOnNewSession,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v41,
    this);
  v35 = evaluateTimeFromTrackSpline(a3, a4, (TimeEvaluation *)&result, this->car);
  LOBYTE(v50) = 38;
  std::vector<float>::vector<float>(&estimatedTimesPerSector, &v35->estimatedTimePerSector_s);
  LOBYTE(v50) = 40;
  if ( result.fileName._Bx._Ptr )
  {
    std::_Container_base0::_Orphan_all(&result.fileName);
    operator delete(result.fileName._Bx._Ptr);
    *(_QWORD *)result.fileName._Bx._Buf = 0i64;
    *(_DWORD *)&result.fileName._Bx._Alias[8] = 0;
  }
  v36 = estimatedTimesPerSector._Mylast;
  for ( i = estimatedTimesPerSector._Myfirst; i != v36; ++i )
  {
    v38 = *i + 10.0;
    *i = v38;
    *i = this->timeMult * v38;
  }
  TimeAttackTarget::reset(&this->target, &estimatedTimesPerSector);
  PhysicsAvatar::setAllowedTyresOut(this->car->sim->physicsAvatar, 2);
  v39 = this->car->sim->track;
  TimeAttackGameStatus::reset(
    &this->status,
    v39->physicsTrack.sectorsNormalizedPositions._Mylast - v39->physicsTrack.sectorsNormalizedPositions._Myfirst);
  v42 = 11;
  this->guiInfo.lastTimeLeft = 0;
  v41._Myres = (unsigned int)L"TIME_ATTACK";
  this->guiInfo.scoreLabelTimer = 1000.0;
  this->guiInfo.penaltyPointsAccumulated = 0.0;
  this->guiInfo.penaltyTimer = 0.0;
  this->guiInfo.lastGainedPoints = 0.0;
  this->guiInfo.lastGainedSeconds = 0.0;
  this->guiInfo.lastCarDamage = 0.0;
  key.fileName._Mysize = 7;
  *(_DWORD *)&key.fileName._Bx._Alias[12] = 0;
  LOWORD(key.kid) = 0;
  std::wstring::assign((std::wstring *)&key, (const wchar_t *)v41._Myres, v42);
  LOBYTE(v50) = 41;
  TrackAvatar::getSpawnPosition(this->car->sim->track, &pos, (const std::wstring *)&key, 0);
  LOBYTE(v50) = 40;
  if ( key.fileName._Mysize >= 8 )
    operator delete(key.kid);
  if ( mat44f::isIdentity(&pos) )
  {
    std::wstring::wstring((std::wstring *)&key, L"START");
    LOBYTE(v50) = 43;
  }
  else
  {
    std::wstring::wstring((std::wstring *)&key, L"TIME_ATTACK");
    LOBYTE(v50) = 42;
  }
  CarAvatar::goToSpawnPosition(this->car, (const std::wstring *)&key);
  if ( key.fileName._Mysize >= 8 )
    operator delete(key.kid);
  v42 = (unsigned int)this;
  v41._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_580fb303675d98712da4536ec482cbb6_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
  *(_DWORD *)&v41._Bx._Alias[4] = this;
  v41._Mysize = (unsigned int)&v41;
  v40 = this->car;
  LOBYTE(v50) = 40;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v40->sim->evOnPauseModeChanged,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v41,
    this);
  LOBYTE(v50) = 15;
  if ( estimatedTimesPerSector._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&estimatedTimesPerSector);
    operator delete(estimatedTimesPerSector._Myfirst);
    estimatedTimesPerSector._Myfirst = 0;
    estimatedTimesPerSector._Mylast = 0;
    estimatedTimesPerSector._Myend = 0;
  }
  LOBYTE(v50) = 12;
  INIReaderDocuments::~INIReaderDocuments(&ini);
}
void TimeAttack::~TimeAttack(TimeAttack *this)
{
  std::vector<float> *v2; // edi
  std::_Ref_count_base *v3; // edi

  this->__vftable = (TimeAttack_vtbl *)&TimeAttack::`vftable';
  v2 = &this->status.sectorTimes;
  if ( this->status.sectorTimes._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->status.sectorTimes);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  TyreMaterials::~TyreMaterials(&this->target);
  OnSetupAppCreated::~OnSetupAppCreated(&this->checkpointTexture);
  OnSetupAppCreated::~OnSetupAppCreated(&this->guiPenalty);
  OnSetupAppCreated::~OnSetupAppCreated(&this->guiBlackCup);
  OnSetupAppCreated::~OnSetupAppCreated(&this->guiBlackClock);
  OnSetupAppCreated::~OnSetupAppCreated(&this->guiWhiteCup);
  OnSetupAppCreated::~OnSetupAppCreated(&this->guiWhiteClock);
  OnSetupAppCreated::~OnSetupAppCreated(&this->guiCheckpointTex);
  OnSetupAppCreated::~OnSetupAppCreated(&this->guiStartTex);
  v3 = this->font._Rep;
  if ( v3 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v3->_Uses, 0xFFFFFFFF) )
    {
      v3->_Destroy(v3);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v3->_Weaks) )
        v3->_Delete_this(v3);
    }
  }
  if ( this->overlays._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->overlays);
    operator delete(this->overlays._Myfirst);
    this->overlays._Myfirst = 0;
    this->overlays._Mylast = 0;
    this->overlays._Myend = 0;
  }
  GameMode::~GameMode(this);
}
TimeAttack *TimeAttack::`scalar deleting destructor'(TimeAttack *this, unsigned int a2)
{
  TimeAttack::~TimeAttack(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void TimeAttack::createAndSaveOverlays(TimeAttack *this)
{
  int v2; // esi
  std::wostream *v3; // eax
  std::wostream *v4; // eax
  std::wostream *v5; // eax
  std::wstring *v6; // eax
  CarAvatar *v7; // ecx
  float v8; // eax
  std::wstring *v9; // eax
  CarAvatar *v10; // ecx
  int v11; // eax
  std::wstring *v12; // ecx
  std::wostream *v13; // eax
  std::wostream *v14; // eax
  std::wostream *v15; // eax
  std::wstring *v16; // eax
  CarAvatar *v17; // ecx
  Node_vtbl *v18; // eax
  int v19; // eax
  float v20; // xmm1_4
  float v21; // xmm2_4
  vec3f *v22; // eax
  __int64 v23; // xmm0_8
  Node_vtbl *v24; // eax
  float v25; // xmm1_4
  float v26; // xmm1_4
  vec3f *v27; // eax
  __m128 v28; // xmm0
  float v29; // eax
  float v30; // xmm3_4
  __m128 v31; // xmm2
  float v32; // xmm0_4
  int v33; // eax
  std::wstring *v34; // ecx
  std::wostream *v35; // eax
  std::wostream *v36; // eax
  std::wostream *v37; // eax
  Overlay *v38; // eax
  std::wstring *v39; // eax
  std::wstring *v40; // eax
  bool v41; // cf
  bool v42; // zf
  int v43; // eax
  std::wostream *v44; // eax
  std::wostream *v45; // eax
  int v46; // eax
  int v47; // eax
  unsigned int v48; // edi
  int v49; // esi
  std::wostream *v50; // eax
  std::wostream *v51; // eax
  std::wostream *v52; // eax
  std::wostream *v53; // eax
  std::wostream *v54; // eax
  std::wostream *v55; // eax
  std::wostream *v56; // eax
  std::wostream *v57; // eax
  std::wostream *v58; // eax
  int v59; // eax
  std::wostream *v60; // eax
  int v61; // eax
  std::wostream *v62; // eax
  std::wostream *v63; // eax
  int v64; // eax
  _BYTE *v65; // esi
  int v66; // eax
  const char *v67; // [esp+48h] [ebp-3D8h]
  int v68; // [esp+48h] [ebp-3D8h]
  const std::wstring *v69; // [esp+48h] [ebp-3D8h]
  const char *v70; // [esp+4Ch] [ebp-3D4h]
  const std::wstring *v71; // [esp+4Ch] [ebp-3D4h]
  const std::wstring *v72; // [esp+4Ch] [ebp-3D4h]
  const std::wstring *v73; // [esp+4Ch] [ebp-3D4h]
  const char *v74; // [esp+50h] [ebp-3D0h]
  int v75; // [esp+50h] [ebp-3D0h]
  int v76; // [esp+50h] [ebp-3D0h]
  char v77[64]; // [esp+68h] [ebp-3B8h] BYREF
  mat44f v78; // [esp+A8h] [ebp-378h] BYREF
  vec3f v79; // [esp+E8h] [ebp-338h] BYREF
  vec3f v80; // [esp+F4h] [ebp-32Ch] BYREF
  int v81; // [esp+108h] [ebp-318h]
  float v82; // [esp+114h] [ebp-30Ch]
  std::wofstream v83; // [esp+118h] [ebp-308h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v84; // [esp+1C0h] [ebp-260h] BYREF
  vec3f pos; // [esp+270h] [ebp-1B0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v86; // [esp+27Ch] [ebp-1A4h] BYREF
  float v87; // [esp+32Ch] [ebp-F4h]
  int v88[2]; // [esp+330h] [ebp-F0h] BYREF
  Overlay _Val; // [esp+338h] [ebp-E8h] BYREF
  float v90; // [esp+368h] [ebp-B8h]
  Node *v91; // [esp+36Ch] [ebp-B4h]
  int v92; // [esp+370h] [ebp-B0h]
  float v93; // [esp+374h] [ebp-ACh]
  float v94; // [esp+378h] [ebp-A8h]
  AISpline *v95; // [esp+37Ch] [ebp-A4h]
  std::vector<Overlay> v96; // [esp+380h] [ebp-A0h] BYREF
  AISplinePayload v97; // [esp+38Ch] [ebp-94h] BYREF
  std::wstring result; // [esp+3E0h] [ebp-40h] BYREF
  std::wstring v99; // [esp+3F8h] [ebp-28h] BYREF
  int v100; // [esp+414h] [ebp-Ch]
  char v101; // [esp+418h] [ebp-8h]
  int v102; // [esp+41Ch] [ebp-4h]

  v92 = 0;
  v88[0] = 0;
  v88[1] = 0;
  *(_DWORD *)&_Val.isActive = 0;
  v102 = 0;
  v2 = 0;
  *(_DWORD *)v86.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v86.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v86.gap68);
  LOBYTE(v102) = 1;
  v92 = 1;
  std::wiostream::basic_iostream<wchar_t>(&v86, &v86.gap10[8], 0);
  v100 = 2;
  *(_DWORD *)((char *)&pos.y + *(_DWORD *)(LODWORD(pos.y) + 4)) = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&pos.x + *(_DWORD *)(LODWORD(pos.y) + 4)) = *(_DWORD *)(LODWORD(pos.y) + 4) - 104;
  std::wstreambuf::wstreambuf(v86.gap10);
  *(_DWORD *)v86.gap10 = &std::wstringbuf::`vftable';
  *(_DWORD *)&v86.gap10[56] = 0;
  *(_DWORD *)&v86.gap10[60] = 0;
  LOBYTE(v100) = 4;
  v3 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)&v86._Chcount, "AC_TIME_");
  v4 = (std::wostream *)std::wostream::operator<<(v3, 0);
  v5 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v4, v70);
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v5, v74);
  v95 = TrackAvatar::getAISpline(this->car->sim->track);
  v96._Myfirst = 0;
  v96._Mylast = 0;
  v96._Myend = 0;
  LOBYTE(v102) = 5;
  while ( 1 )
  {
    v6 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v86, &result);
    v7 = this->car;
    LOBYTE(v102) = 6;
    v8 = COERCE_FLOAT((int)v7->sim->trackNode->findChildByName(v7->sim->trackNode, v6, 1));
    v94 = v8;
    LOBYTE(v102) = 5;
    if ( result._Myres >= 8 )
    {
      operator delete(result._Bx._Ptr);
      v8 = v94;
    }
    if ( v8 == 0.0 )
      break;
    v81 = 0;
    _Val.height = 0.0;
    LOBYTE(_Val.worldPosition.x) = 0;
    _Val.width = 1.5;
    _Val.orientation.x = 15.0;
    *(_QWORD *)&_Val.offset.y = _mm_unpacklo_ps((__m128)0i64, (__m128)LODWORD(FLOAT_3_0)).m128_u64[0];
    v9 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v86, &result);
    v10 = this->car;
    LOBYTE(v102) = 7;
    v91 = v10->sim->trackNode->findChildByName(v10->sim->trackNode, v9, 1);
    LOBYTE(v102) = 5;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    v99._Myres = 7;
    v99._Mysize = 0;
    v99._Bx._Buf[0] = 0;
    std::wstring::assign(&v99, word_17BE9D8, 0);
    LOBYTE(v102) = 8;
    if ( (v86.gap10[68] & 1) != 0 )
    {
      if ( std::wstreambuf::pptr(&v86.gap10[8]) )
        std::wstreambuf::epptr(&v86.gap10[8]);
      else
        std::wstreambuf::egptr(&v86.gap10[8]);
      std::wstreambuf::eback(&v86.gap10[8]);
      v11 = std::wstreambuf::eback(&v86.gap10[8]);
      operator delete(v11);
    }
    std::wstreambuf::setg(&v86.gap10[8], 0, 0, 0);
    std::wstreambuf::setp(&v86.gap10[8], 0, 0);
    v12 = &v99;
    *(_DWORD *)&v86.gap10[64] = 0;
    v75 = *(_DWORD *)&v86.gap10[68] & 0xFFFFFFFE;
    if ( v99._Myres >= 8 )
      v12 = (std::wstring *)v99._Bx._Ptr;
    *(_DWORD *)&v86.gap10[68] &= 0xFFFFFFFE;
    std::wstringbuf::_Init((std::wstringbuf *)&v86.gap10[8], v12->_Bx._Buf, v99._Mysize, v75);
    LOBYTE(v102) = 5;
    if ( v99._Myres >= 8 )
      operator delete(v99._Bx._Ptr);
    v13 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v86.gap10, "AC_TIME_");
    v14 = (std::wostream *)std::wostream::operator<<(v13, v2);
    v15 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v14, v67);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v15, "_");
    v16 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
            (std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > *)&pos.z,
            (std::wstring *)&result._Myres);
    v17 = this->car;
    v101 = 9;
    v93 = COERCE_FLOAT(
            ((int (*)(Node *, std::wstring *, int, const char *))v17->sim->trackNode->findChildByName)(
              v17->sim->trackNode,
              v16,
              1,
              "R"));
    LOBYTE(v102) = 5;
    if ( v99._Myres >= 8 )
      operator delete(v99._Bx._Ptr);
    v99._Myres = 7;
    v99._Bx._Buf[0] = 0;
    v18 = v91->__vftable;
    v99._Mysize = 0;
    v19 = (int)v18->getWorldMatrix(v91, &v78);
    v20 = *(float *)(v19 + 52);
    v21 = *(float *)(v19 + 56);
    pos.x = *(float *)(v19 + 48);
    pos.y = v20;
    pos.z = v21;
    v94 = InterpolatingSpline::worldToSpline(&v95->spline, &pos, -1);
    v87 = v94;
    v22 = InterpolatingSpline::splineToWorld(&v95->spline, &v80, v94);
    v23 = *(_QWORD *)&v22->x;
    _Val.offset.x = v22->z;
    v24 = v91->__vftable;
    *(_QWORD *)&_Val.worldPosition.y = v23;
    v24->getWorldMatrix(v91, &v78);
    (*(void (**)(float, char *))(*(_DWORD *)LODWORD(v93) + 32))(COERCE_FLOAT(LODWORD(v93)), v77);
    AISpline::payloadAtPosition(v95, &v97, v94);
    v25 = (float)(COERCE_FLOAT(LODWORD(v97.sides[1]) & _xmm) + COERCE_FLOAT(LODWORD(v97.sides[0]) & _xmm)) * 0.5;
    if ( v97.sides[1] <= v97.sides[0] )
      v26 = v25 - v97.sides[1];
    else
      LODWORD(v26) = COERCE_UNSIGNED_INT(v25 - v97.sides[0]) ^ _xmm;
    _Val.offset.y = v26;
    v93 = Spline::length(&v95->spline);
    v27 = InterpolatingSpline::splineToWorld(&v95->spline, &v79, v87 - (float)(1.0 / v93));
    v28 = (__m128)_mm_loadl_epi64((const __m128i *)v27);
    v29 = v27->z;
    v31 = (__m128)v28.m128_u32[1];
    v31.m128_f32[0] = v28.m128_f32[1] - _Val.worldPosition.z;
    v28.m128_f32[0] = v28.m128_f32[0] - _Val.worldPosition.y;
    v30 = v28.m128_f32[0];
    *(_QWORD *)&_Val.orientation.y = _mm_unpacklo_ps(v28, v31).m128_u64[0];
    v82 = v29 - _Val.offset.x;
    v90 = v29 - _Val.offset.x;
    v32 = fsqrt((float)((float)(v30 * v30) + (float)(v31.m128_f32[0] * v31.m128_f32[0])) + (float)(v82 * v82));
    if ( v32 != 0.0 )
    {
      _Val.orientation.z = _Val.orientation.z * (float)(1.0 / v32);
      _Val.orientation.y = v30 * (float)(1.0 / v32);
      v90 = v90 * (float)(1.0 / v32);
    }
    std::vector<Overlay>::push_back(&v96, (const Overlay *)&_Val.worldPosition);
    v99._Myres = 7;
    v99._Mysize = 0;
    ++v2;
    v99._Bx._Buf[0] = 0;
    std::wstring::assign(&v99, word_17BE9D8, 0);
    LOBYTE(v102) = 10;
    if ( (v86.gap10[68] & 1) != 0 )
    {
      if ( std::wstreambuf::pptr(&v86.gap10[8]) )
        std::wstreambuf::epptr(&v86.gap10[8]);
      else
        std::wstreambuf::egptr(&v86.gap10[8]);
      std::wstreambuf::eback(&v86.gap10[8]);
      v33 = std::wstreambuf::eback(&v86.gap10[8]);
      operator delete(v33);
    }
    std::wstreambuf::setg(&v86.gap10[8], 0, 0, 0);
    std::wstreambuf::setp(&v86.gap10[8], 0, 0);
    v34 = &v99;
    *(_DWORD *)&v86.gap10[64] = 0;
    v76 = *(_DWORD *)&v86.gap10[68] & 0xFFFFFFFE;
    if ( v99._Myres >= 8 )
      v34 = (std::wstring *)v99._Bx._Ptr;
    *(_DWORD *)&v86.gap10[68] &= 0xFFFFFFFE;
    std::wstringbuf::_Init((std::wstringbuf *)&v86.gap10[8], v34->_Bx._Buf, v99._Mysize, v76);
    LOBYTE(v102) = 5;
    if ( v99._Myres >= 8 )
      operator delete(v99._Bx._Ptr);
    v35 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v86.gap10, "AC_TIME_");
    v36 = (std::wostream *)std::wostream::operator<<(v35, v2);
    v37 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v36, "_");
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v37, "L");
  }
  v38 = v96._Myfirst;
  if ( v96._Myfirst != v96._Mylast )
  {
    std::wofstream::wofstream(&v83, 1);
    LOBYTE(v102) = 11;
    v39 = TrackAvatar::getDataFolder(this->car->sim->track, &v99);
    LOBYTE(v102) = 12;
    v40 = std::operator+<wchar_t>(&result, v39, L"/data/overlays.ini");
    v41 = v40->_Myres < 8;
    LOBYTE(v102) = 13;
    if ( !v41 )
      v40 = (std::wstring *)v40->_Bx._Ptr;
    v42 = std::wfilebuf::open((std::wfilebuf *)&v83.gap0[4], v40->_Bx._Buf, 2, 64) == 0;
    v43 = *(_DWORD *)(*(_DWORD *)v83.gap0 + 4);
    if ( v42 )
      std::wios::setstate((char *)&v83 + v43, 2, 0);
    else
      std::wios::clear((char *)&v83 + v43, 0, 0);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    LOBYTE(v102) = 11;
    if ( v99._Myres >= 8 )
      operator delete(v99._Bx._Ptr);
    v44 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&v83, "[MAIN]");
    std::wostream::operator<<(v44);
    v68 = v96._Mylast - v96._Myfirst;
    v45 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&v83, "OVERLAYS_COUNT=");
    v46 = std::wostream::operator<<(v45, v68);
    v47 = std::wostream::operator<<(v46);
    std::wostream::operator<<(v47);
    v48 = 0;
    if ( v96._Mylast - v96._Myfirst )
    {
      v49 = 0;
      do
      {
        *(_DWORD *)v84.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
        *(_DWORD *)v84.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
        std::wios::wios(v84.gap68);
        v92 |= 2u;
        LOBYTE(v102) = 14;
        std::wiostream::basic_iostream<wchar_t>(&v84, &v84.gap10[8], 0);
        v102 = 15;
        *(_DWORD *)&v84.gap0[*(_DWORD *)(*(_DWORD *)v84.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
        *(_DWORD *)&v83.gap58[*(_DWORD *)(*(_DWORD *)v84.gap0 + 4) + 76] = *(_DWORD *)(*(_DWORD *)v84.gap0 + 4) - 104;
        std::wstreambuf::wstreambuf(&v84.gap10[8]);
        *(_DWORD *)&v84.gap10[8] = &std::wstringbuf::`vftable';
        *(_DWORD *)&v84.gap10[64] = 0;
        *(_DWORD *)&v84.gap10[68] = 0;
        LOBYTE(v102) = 17;
        v50 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v84.gap10, "CHECKPOINT_");
        std::wostream::operator<<(v50, v48);
        v69 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v84, &result);
        LOBYTE(v102) = 18;
        v51 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&v83, "[");
        v52 = std::operator<<<wchar_t>(v51, v69);
        v53 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v52, "]");
        std::wostream::operator<<(v53);
        LOBYTE(v102) = 17;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        v71 = vec3f::toString(&v96._Myfirst[v49].worldPosition, &result);
        LOBYTE(v102) = 19;
        v54 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&v83, "WORLD_POSITION=");
        v55 = std::operator<<<wchar_t>(v54, v71);
        std::wostream::operator<<(v55);
        LOBYTE(v102) = 17;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        v72 = vec3f::toString(&v96._Myfirst[v49].offset, &result);
        LOBYTE(v102) = 20;
        v56 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&v83, "OFFSET=");
        v57 = std::operator<<<wchar_t>(v56, v72);
        std::wostream::operator<<(v57);
        LOBYTE(v102) = 17;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        v58 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&v83, "WIDTH=");
        v59 = std::wostream::operator<<(v58);
        std::wostream::operator<<(v59);
        v60 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&v83, "HEIGHT=");
        v61 = std::wostream::operator<<(v60);
        std::wostream::operator<<(v61);
        v73 = vec3f::toString(&v96._Myfirst[v49].orientation, &result);
        LOBYTE(v102) = 21;
        v62 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(&v83, "ORIENTATION=");
        v63 = std::operator<<<wchar_t>(v62, v73);
        std::wostream::operator<<(v63);
        LOBYTE(v102) = 17;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        std::wostream::operator<<(&v83);
        LOBYTE(v102) = 11;
        *(_DWORD *)&v84.gap0[*(_DWORD *)(*(_DWORD *)v84.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
        *(_DWORD *)&v83.gap58[*(_DWORD *)(*(_DWORD *)v84.gap0 + 4) + 76] = *(_DWORD *)(*(_DWORD *)v84.gap0 + 4) - 104;
        *(_DWORD *)&v84.gap10[8] = &std::wstringbuf::`vftable';
        if ( (v84.gap10[68] & 1) != 0 )
        {
          if ( std::wstreambuf::pptr(&v84.gap10[8]) )
            std::wstreambuf::epptr(&v84.gap10[8]);
          else
            std::wstreambuf::egptr(&v84.gap10[8]);
          std::wstreambuf::eback(&v84.gap10[8]);
          v64 = std::wstreambuf::eback(&v84.gap10[8]);
          operator delete(v64);
        }
        std::wstreambuf::setg(&v84.gap10[8], 0, 0, 0);
        std::wstreambuf::setp(&v84.gap10[8], 0, 0);
        *(_DWORD *)&v84.gap10[68] &= 0xFFFFFFFE;
        *(_DWORD *)&v84.gap10[64] = 0;
        std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v84.gap10[8]);
        std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v84.gap10[16]);
        std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v84.gap68);
        ++v48;
        ++v49;
      }
      while ( v48 < v96._Mylast - v96._Myfirst );
    }
    v65 = &v83.gap0[4];
    if ( *(_DWORD *)&v83._Filebuffer[4] )
    {
      if ( !std::wfilebuf::_Endwrite((std::wfilebuf *)&v83.gap0[4]) )
        v65 = 0;
      if ( _fclose(*(FILE **)&v83._Filebuffer[4]) )
        v65 = 0;
    }
    else
    {
      v65 = 0;
    }
    v83._Filebuffer[0] = 0;
    v83.gap0[74] = 0;
    std::wstreambuf::_Init(&v83.gap0[4]);
    *(_DWORD *)&v83._Filebuffer[4] = 0;
    *(_DWORD *)&v83.gap0[76] = `std::wfilebuf::_Init'::`2'::_Stinit;
    *(_DWORD *)&v83.gap0[68] = 0;
    if ( !v65 )
      std::wios::setstate((char *)&v83 + *(_DWORD *)(*(_DWORD *)v83.gap0 + 4), 2, 0);
    std::wofstream::~wofstream<wchar_t,std::char_traits<wchar_t>>((std::wofstream *)&v83.gap58[8]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(&v83.gap58[8]);
    v38 = v96._Myfirst;
  }
  LOBYTE(v102) = 4;
  if ( v38 )
  {
    std::_Container_base0::_Orphan_all(&v96);
    operator delete(v96._Myfirst);
    v96._Myfirst = 0;
    v96._Mylast = 0;
    v96._Myend = 0;
  }
  LOBYTE(v102) = 0;
  *(_DWORD *)&v86.gap0[*(_DWORD *)(*(_DWORD *)v86.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&pos.z + *(_DWORD *)(*(_DWORD *)v86.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v86.gap0 + 4) - 104;
  *(_DWORD *)&v86.gap10[8] = &std::wstringbuf::`vftable';
  if ( (v86.gap10[68] & 1) != 0 )
  {
    if ( std::wstreambuf::pptr(&v86.gap10[8]) )
      std::wstreambuf::epptr(&v86.gap10[8]);
    else
      std::wstreambuf::egptr(&v86.gap10[8]);
    std::wstreambuf::eback(&v86.gap10[8]);
    v66 = std::wstreambuf::eback(&v86.gap10[8]);
    operator delete(v66);
  }
  std::wstreambuf::setg(&v86.gap10[8], 0, 0, 0);
  std::wstreambuf::setp(&v86.gap10[8], 0, 0);
  *(_DWORD *)&v86.gap10[68] &= 0xFFFFFFFE;
  *(_DWORD *)&v86.gap10[64] = 0;
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v86.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v86.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v86.gap68);
  v102 = -1;
  if ( v88[0] )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)v88);
    operator delete(v88[0]);
  }
}
void TimeAttack::loadOverlaysAndSectors(TimeAttack *this)
{
  std::wstring *v2; // eax
  const std::wstring *v3; // eax
  int v4; // esi
  TrackAvatar *v5; // ecx
  int v6; // eax
  std::wostream *v7; // eax
  const std::wstring *v8; // eax
  vec3f *v9; // eax
  __int64 v10; // xmm0_8
  float v11; // eax
  const std::wstring *v12; // eax
  vec3f *v13; // eax
  __int64 v14; // xmm0_8
  float v15; // eax
  const std::wstring *v16; // eax
  const std::wstring *v17; // eax
  const std::wstring *v18; // eax
  vec3f *v19; // eax
  __int64 v20; // xmm0_8
  float v21; // eax
  int v22; // eax
  TrackAvatar *v23; // ecx
  int v24; // [esp+18h] [ebp-1CCh]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v25; // [esp+1Ch] [ebp-1C8h] BYREF
  Overlay overlay; // [esp+D0h] [ebp-114h] BYREF
  vec3f v27; // [esp+100h] [ebp-E4h] BYREF
  vec3f v28; // [esp+10Ch] [ebp-D8h] BYREF
  vec3f v29; // [esp+118h] [ebp-CCh] BYREF
  std::wstring key; // [esp+124h] [ebp-C0h] BYREF
  std::wstring v31; // [esp+13Ch] [ebp-A8h] BYREF
  std::wstring v32; // [esp+154h] [ebp-90h] BYREF
  std::wstring result; // [esp+16Ch] [ebp-78h] BYREF
  INIReader overlayIni; // [esp+184h] [ebp-60h] BYREF
  int v35; // [esp+1E0h] [ebp-4h]

  v24 = 0;
  v2 = TrackAvatar::getDataFolder(this->car->sim->track, &result);
  v35 = 0;
  v3 = std::operator+<wchar_t>(&v32, v2, L"/data/overlays.ini");
  LOBYTE(v35) = 1;
  INIReader::INIReader(&overlayIni, v3);
  if ( v32._Myres >= 8 )
    operator delete(v32._Bx._Ptr);
  v32._Myres = 7;
  v32._Mysize = 0;
  v32._Bx._Buf[0] = 0;
  LOBYTE(v35) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( overlayIni.ready )
  {
    v4 = 0;
    v5 = this->car->sim->track;
    v6 = (char *)v5->physicsTrack.sectorsNormalizedPositions._Mylast
       - (char *)v5->physicsTrack.sectorsNormalizedPositions._Myfirst;
    if ( v6 >= 0 && (v6 & 0xFFFFFFFC) != 0 )
    {
      do
      {
        *(_DWORD *)v25.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
        *(_DWORD *)v25.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
        std::wios::wios(v25.gap68);
        v24 |= 1u;
        LOBYTE(v35) = 5;
        std::wiostream::basic_iostream<wchar_t>(&v25, &v25.gap10[8], 0);
        v35 = 6;
        *(_DWORD *)&v25.gap0[*(_DWORD *)(*(_DWORD *)v25.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
        *(int *)((char *)&v24 + *(_DWORD *)(*(_DWORD *)v25.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v25.gap0 + 4) - 104;
        std::wstreambuf::wstreambuf(&v25.gap10[8]);
        *(_DWORD *)&v25.gap10[8] = &std::wstringbuf::`vftable';
        *(_DWORD *)&v25.gap10[64] = 0;
        *(_DWORD *)&v25.gap10[68] = 0;
        LOBYTE(v35) = 8;
        v7 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v25.gap10, "CHECKPOINT_");
        std::wostream::operator<<(v7, v4);
        overlay.isActive = 0;
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"WORLD_POSITION", 0xEu);
        LOBYTE(v35) = 9;
        v8 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v25, &v31);
        LOBYTE(v35) = 10;
        v9 = INIReader::getFloat3(&overlayIni, &v29, v8, &key);
        v10 = *(_QWORD *)&v9->x;
        v11 = v9->z;
        *(_QWORD *)&overlay.worldPosition.x = v10;
        overlay.worldPosition.z = v11;
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        LOBYTE(v35) = 8;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"OFFSET", 6u);
        LOBYTE(v35) = 11;
        v12 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v25, &v31);
        LOBYTE(v35) = 12;
        v13 = INIReader::getFloat3(&overlayIni, &v28, v12, &key);
        v14 = *(_QWORD *)&v13->x;
        v15 = v13->z;
        *(_QWORD *)&overlay.offset.x = v14;
        overlay.offset.z = v15;
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        LOBYTE(v35) = 8;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"HEIGHT", 6u);
        LOBYTE(v35) = 13;
        v16 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v25, &v31);
        LOBYTE(v35) = 14;
        overlay.height = INIReader::getFloat(&overlayIni, v16, &key);
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        LOBYTE(v35) = 8;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"WIDTH", 5u);
        LOBYTE(v35) = 15;
        v17 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v25, &v31);
        LOBYTE(v35) = 16;
        overlay.width = INIReader::getFloat(&overlayIni, v17, &key);
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        LOBYTE(v35) = 8;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"ORIENTATION", 0xBu);
        LOBYTE(v35) = 17;
        v18 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v25, &v31);
        LOBYTE(v35) = 18;
        v19 = INIReader::getFloat3(&overlayIni, &v27, v18, &key);
        v20 = *(_QWORD *)&v19->x;
        v21 = v19->z;
        *(_QWORD *)&overlay.orientation.x = v20;
        overlay.orientation.z = v21;
        if ( v31._Myres >= 8 )
          operator delete(v31._Bx._Ptr);
        v31._Myres = 7;
        v31._Mysize = 0;
        v31._Bx._Buf[0] = 0;
        LOBYTE(v35) = 8;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Bx._Buf[0] = 0;
        key._Mysize = 0;
        std::vector<Overlay>::push_back(&this->overlays, &overlay);
        LOBYTE(v35) = 4;
        *(_DWORD *)&v25.gap0[*(_DWORD *)(*(_DWORD *)v25.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
        *(int *)((char *)&v24 + *(_DWORD *)(*(_DWORD *)v25.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v25.gap0 + 4) - 104;
        *(_DWORD *)&v25.gap10[8] = &std::wstringbuf::`vftable';
        if ( (v25.gap10[68] & 1) != 0 )
        {
          if ( std::wstreambuf::pptr(&v25.gap10[8]) )
            std::wstreambuf::epptr(&v25.gap10[8]);
          else
            std::wstreambuf::egptr(&v25.gap10[8]);
          std::wstreambuf::eback(&v25.gap10[8]);
          v22 = std::wstreambuf::eback(&v25.gap10[8]);
          operator delete(v22);
        }
        std::wstreambuf::setg(&v25.gap10[8], 0, 0, 0);
        std::wstreambuf::setp(&v25.gap10[8], 0, 0);
        *(_DWORD *)&v25.gap10[68] &= 0xFFFFFFFE;
        *(_DWORD *)&v25.gap10[64] = 0;
        std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v25.gap10[8]);
        std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v25.gap10[16]);
        std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v25.gap68);
        ++v4;
        v23 = this->car->sim->track;
      }
      while ( v4 < v23->physicsTrack.sectorsNormalizedPositions._Mylast
                 - v23->physicsTrack.sectorsNormalizedPositions._Myfirst );
    }
  }
  v35 = -1;
  INIReader::~INIReader(&overlayIni);
}
void TimeAttack::renderGameOver(TimeAttack *this, float dt)
{
  PauseMenu::blankButton(this->car->sim->pauseMenu, ePauseMenuPits, 1);
  PauseMenu::blankButton(this->car->sim->pauseMenu, ePauseMenuResume, 1);
}
void TimeAttack::renderGuiCheckpointBreak(TimeAttack *this, float dt, float newPoints, float newSeconds)
{
  float v5; // xmm0_4
  Game *v6; // ecx
  Texture *v7; // edi
  GLRenderer *v8; // ebx
  unsigned int v9; // eax
  unsigned int v10; // ebp
  unsigned int v11; // ecx
  float v12; // xmm0_4
  float v13; // xmm0_4
  unsigned int v14; // eax
  float v15; // xmm0_4
  unsigned int v16; // eax
  Texture *v17; // edi
  unsigned int v18; // ebp
  unsigned int v19; // eax
  float v20; // xmm0_4
  float v21; // xmm0_4
  Texture *v22; // ebp
  unsigned int v23; // edi
  unsigned int v24; // eax
  float v25; // xmm0_4
  float v26; // xmm0_4
  float v27; // xmm0_4
  Font *v28; // ecx
  std::wostream *v29; // eax
  std::wostream *v30; // eax
  Game *v31; // eax
  Font *v32; // ecx
  std::wstring *v33; // eax
  std::wostream *v34; // eax
  std::wostream *v35; // eax
  Game *v36; // eax
  Font *v37; // ecx
  float g; // [esp+14h] [ebp-104h]
  float ga; // [esp+14h] [ebp-104h]
  float gb; // [esp+14h] [ebp-104h]
  const std::wstring *gc; // [esp+14h] [ebp-104h]
  const std::wstring *gd; // [esp+14h] [ebp-104h]
  const std::wstring *b; // [esp+18h] [ebp-100h]
  int ba; // [esp+18h] [ebp-100h]
  unsigned int v45; // [esp+38h] [ebp-E0h]
  float y; // [esp+38h] [ebp-E0h]
  int v47; // [esp+3Ch] [ebp-DCh]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v48; // [esp+40h] [ebp-D8h] BYREF
  std::wstring result; // [esp+F0h] [ebp-28h] BYREF
  int v50; // [esp+114h] [ebp-4h]

  v47 = 0;
  if ( newPoints != 0.0 )
  {
    this->guiInfo.lastGainedPoints = newPoints;
    this->guiInfo.scoreLabelTimer = 0.0;
    this->guiInfo.lastGainedSeconds = newSeconds;
  }
  v5 = this->guiInfo.scoreLabelTimer;
  if ( v5 < 5.0 )
  {
    v6 = this->game;
    v7 = &this->guiCheckpointTex;
    this->guiInfo.scoreLabelTimer = v5 + dt;
    GraphicsManager::setTexture(v6->graphics, 0, &this->guiCheckpointTex);
    v8 = this->game->graphics->gl;
    GLRenderer::color4f(v8, 1.0, 1.0, 1.0, 1.0);
    if ( this->guiCheckpointTex.kid )
      v9 = kglTextureGetHeight(v7->kid);
    else
      v9 = 0;
    v45 = v9;
    if ( v7->kid )
      v10 = kglTextureGetWidth(v7->kid);
    else
      v10 = 0;
    if ( v7->kid )
      v11 = kglTextureGetWidth(v7->kid);
    else
      v11 = 0;
    v12 = (float)v45;
    g = v12;
    v13 = (float)v10;
    GLRenderer::quad(
      v8,
      (float)((float)this->game->graphics->videoSettings.width * 0.5) - (float)((float)v11 * 0.5),
      165.0,
      v13,
      g,
      1,
      0);
    GLRenderer::color4f(v8, 1.0, 1.0, 1.0, 0.5);
    if ( v7->kid )
      v14 = kglTextureGetHeight(v7->kid);
    else
      v14 = 0;
    v15 = (float)v14;
    GLRenderer::quad(
      v8,
      (float)((float)this->game->graphics->videoSettings.width * 0.5) - 270.0,
      (float)(v15 + 165.0) + 2.0,
      540.0,
      60.0,
      0,
      0);
    if ( v7->kid )
      v16 = kglTextureGetHeight(v7->kid);
    else
      v16 = 0;
    v17 = &this->guiBlackClock;
    y = (float)((float)v16 + 165.0) + 10.0;
    GraphicsManager::setTexture(this->game->graphics, 0, &this->guiBlackClock);
    GLRenderer::color4f(v8, 1.0, 1.0, 1.0, 1.0);
    if ( this->guiBlackClock.kid )
      v18 = kglTextureGetHeight(v17->kid);
    else
      v18 = 0;
    if ( v17->kid )
      v19 = kglTextureGetWidth(v17->kid);
    else
      v19 = 0;
    v20 = (float)v18;
    ga = v20;
    v21 = (float)v19;
    GLRenderer::quad(v8, (float)((float)this->game->graphics->videoSettings.width * 0.5) - 150.0, y, v21, ga, 1, 0);
    v22 = &this->guiBlackCup;
    GraphicsManager::setTexture(this->game->graphics, 0, &this->guiBlackCup);
    GLRenderer::color4f(v8, 1.0, 1.0, 1.0, 1.0);
    if ( this->guiBlackCup.kid )
      v23 = kglTextureGetHeight(v22->kid);
    else
      v23 = 0;
    if ( v22->kid )
      v24 = kglTextureGetWidth(v22->kid);
    else
      v24 = 0;
    v25 = (float)v23;
    gb = v25;
    v26 = (float)v24;
    GLRenderer::quad(v8, (float)((float)this->game->graphics->videoSettings.width * 0.5) + 60.0, y, v26, gb, 1, 0);
    *(_DWORD *)v48.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v48.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v48.gap68);
    v50 = 0;
    v47 = 1;
    std::wiostream::basic_iostream<wchar_t>(&v48, &v48.gap10[8], 0);
    v50 = 1;
    *(_DWORD *)&v48.gap0[*(_DWORD *)(*(_DWORD *)v48.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v47 + *(_DWORD *)(*(_DWORD *)v48.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v48.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v48.gap10[8]);
    *(_DWORD *)&v48.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v48.gap10[64] = 0;
    *(_DWORD *)&v48.gap10[68] = 0;
    v27 = this->guiInfo.lastGainedSeconds;
    v28 = this->font._Ptr;
    v50 = 3;
    if ( v27 <= 0.0 )
    {
      Font::setColor(v28, 1.0, 0.0, 0.0, 1.0);
      b = timeToTimeAttackDiffString(&result, this->guiInfo.lastGainedSeconds);
      LOBYTE(v50) = 5;
      v29 = (std::wostream *)v48.gap10;
    }
    else
    {
      Font::setColor(v28, 0.0, 1.0, 0.0, 1.0);
      b = timeToTimeAttackDiffString(&result, this->guiInfo.lastGainedSeconds);
      LOBYTE(v50) = 4;
      v29 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v48.gap10, "+");
    }
    v30 = std::operator<<<wchar_t>(v29, b);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v30, "\"");
    LOBYTE(v50) = 3;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    gc = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v48, &result);
    v31 = this->game;
    v32 = this->font._Ptr;
    LOBYTE(v50) = 6;
    Font::blitString(
      v32,
      (float)((float)v31->graphics->videoSettings.width * 0.5) - 20.0,
      y,
      gc,
      0.60000002,
      eAlignRight);
    LOBYTE(v50) = 3;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    std::wstring::assign(&result, word_17BE9D8, 0);
    LOBYTE(v50) = 7;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v48.gap10[8]);
    v33 = &result;
    if ( result._Myres >= 8 )
      v33 = (std::wstring *)result._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v48.gap10[8], v33->_Bx._Buf, result._Mysize, *(int *)&v48.gap10[68]);
    LOBYTE(v50) = 3;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    Font::setColor(this->font._Ptr, 0.0, 1.0, 0.0, 1.0);
    ba = (int)this->guiInfo.lastGainedPoints;
    v34 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v48.gap10, "+");
    v35 = (std::wostream *)std::wostream::operator<<(v34, ba);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v35, "pt");
    gd = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v48, &result);
    v36 = this->game;
    v37 = this->font._Ptr;
    LOBYTE(v50) = 8;
    Font::blitString(
      v37,
      (float)((float)v36->graphics->videoSettings.width * 0.5) + 200.0,
      y,
      gd,
      0.60000002,
      eAlignRight);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Bx._Buf[0] = 0;
    result._Mysize = 0;
    v50 = -1;
    *(_DWORD *)&v48.gap0[*(_DWORD *)(*(_DWORD *)v48.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v47 + *(_DWORD *)(*(_DWORD *)v48.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v48.gap0 + 4) - 104;
    *(_DWORD *)&v48.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&v48.gap10[8]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v48.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v48.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v48.gap68);
  }
}
void TimeAttack::renderGuiPenalties(TimeAttack *this, float dt)
{
  GLRenderer *v3; // ebp
  Texture *v4; // ebx
  unsigned int v5; // edi
  unsigned int v6; // eax
  float v7; // xmm0_4
  float v8; // xmm0_4
  int v9; // eax
  Game *v10; // eax
  float g; // [esp+14h] [ebp-100h]
  const std::wstring *ga; // [esp+14h] [ebp-100h]
  int v13; // [esp+38h] [ebp-DCh]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v14; // [esp+3Ch] [ebp-D8h] BYREF
  std::wstring result; // [esp+ECh] [ebp-28h] BYREF
  int v16; // [esp+110h] [ebp-4h]

  v13 = 0;
  if ( this->guiInfo.penaltyPointsAccumulated < 0.0 )
  {
    v3 = this->game->graphics->gl;
    GLRenderer::color4f(v3, 0.0, 0.0, 0.0, 0.5);
    GLRenderer::quad(
      v3,
      (float)((float)this->game->graphics->videoSettings.width * 0.5) + 275.0,
      80.0,
      250.0,
      85.0,
      0,
      0);
    GLRenderer::color4f(v3, 0.60000002, 0.60000002, 0.60000002, 0.5);
    GLRenderer::begin(v3, eLinesStrip, 0);
    GLRenderer::vertex3f(v3, (float)((float)this->game->graphics->videoSettings.width * 0.5) + 275.0, 80.0, 0.0);
    GLRenderer::vertex3f(v3, (float)((float)this->game->graphics->videoSettings.width * 0.5) + 525.0, 80.0, 0.0);
    GLRenderer::vertex3f(v3, (float)((float)this->game->graphics->videoSettings.width * 0.5) + 525.0, 165.0, 0.0);
    GLRenderer::vertex3f(v3, (float)((float)this->game->graphics->videoSettings.width * 0.5) + 275.0, 165.0, 0.0);
    GLRenderer::vertex3f(v3, (float)((float)this->game->graphics->videoSettings.width * 0.5) + 275.0, 80.0, 0.0);
    GLRenderer::end(v3);
    v4 = &this->guiPenalty;
    GraphicsManager::setTexture(this->game->graphics, 0, &this->guiPenalty);
    GLRenderer::color4f(v3, 1.0, 1.0, 1.0, 1.0);
    if ( this->guiPenalty.kid )
      v5 = kglTextureGetHeight(v4->kid);
    else
      v5 = 0;
    if ( v4->kid )
      v6 = kglTextureGetWidth(v4->kid);
    else
      v6 = 0;
    v7 = (float)v5;
    g = v7;
    v8 = (float)v6;
    GLRenderer::quad(v3, (float)((float)this->game->graphics->videoSettings.width * 0.5) + 280.0, 95.0, v8, g, 1, 0);
    *(_DWORD *)v14.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v14.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v14.gap68);
    v16 = 0;
    v13 = 1;
    std::wiostream::basic_iostream<wchar_t>(&v14, &v14.gap10[8], 0);
    v16 = 1;
    *(_DWORD *)&v14.gap0[*(_DWORD *)(*(_DWORD *)v14.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v13 + *(_DWORD *)(*(_DWORD *)v14.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v14.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v14.gap10[8]);
    *(_DWORD *)&v14.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v14.gap10[64] = 0;
    *(_DWORD *)&v14.gap10[68] = 0;
    v9 = (int)this->guiInfo.penaltyPointsAccumulated;
    v16 = 3;
    std::wostream::operator<<(v14.gap10, v9);
    Font::setColor(this->font._Ptr, 1.0, 0.0, 0.0, 1.0);
    ga = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v14, &result);
    v10 = this->game;
    LOBYTE(v16) = 4;
    Font::blitString(
      this->font._Ptr,
      (float)((float)v10->graphics->videoSettings.width * 0.5) + 500.0,
      95.0,
      ga,
      1.0,
      eAlignRight);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Bx._Buf[0] = 0;
    result._Mysize = 0;
    v16 = -1;
    *(_DWORD *)&v14.gap0[*(_DWORD *)(*(_DWORD *)v14.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v13 + *(_DWORD *)(*(_DWORD *)v14.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v14.gap0 + 4) - 104;
    *(_DWORD *)&v14.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&v14.gap10[8]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v14.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v14.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v14.gap68);
  }
}
void TimeAttack::renderGuiStart(TimeAttack *this, float dt)
{
  Texture *v3; // esi
  unsigned int v4; // ebp
  unsigned int v5; // ebx
  unsigned int v6; // ecx
  float v7; // xmm0_4
  float v8; // xmm0_4
  float g; // [esp+Ch] [ebp-20h]
  GLRenderer *v10; // [esp+28h] [ebp-4h]

  v3 = &this->guiStartTex;
  GraphicsManager::setTexture(this->game->graphics, 0, &this->guiStartTex);
  v10 = this->game->graphics->gl;
  GLRenderer::color4f(v10, 1.0, 1.0, 1.0, 1.0);
  if ( v3->kid )
    v4 = kglTextureGetHeight(v3->kid);
  else
    v4 = 0;
  if ( v3->kid )
    v5 = kglTextureGetWidth(v3->kid);
  else
    v5 = 0;
  if ( v3->kid )
    v6 = kglTextureGetWidth(v3->kid);
  else
    v6 = 0;
  v7 = (float)v4;
  g = v7;
  v8 = (float)v5;
  GLRenderer::quad(
    v10,
    (float)((float)this->game->graphics->videoSettings.width * 0.5) - (float)((float)v6 * 0.5),
    80.0,
    v8,
    g,
    1,
    0);
}
void TimeAttack::renderGuiStatus(TimeAttack *this, float dt)
{
  unsigned int v3; // ebx
  int v4; // edi
  TrackAvatar *v5; // eax
  float v6; // eax
  float v7; // xmm0_4
  float v8; // xmm0_4
  GLRenderer *v9; // ebp
  Texture *v10; // ebx
  unsigned int v11; // edi
  unsigned int v12; // eax
  float v13; // xmm0_4
  float v14; // xmm0_4
  Texture *v15; // ebx
  unsigned int v16; // edi
  unsigned int v17; // eax
  float v18; // xmm0_4
  float v19; // xmm0_4
  const std::wstring *v20; // eax
  std::wostream *v21; // eax
  Game *v22; // eax
  Font *v23; // ecx
  int v24; // eax
  std::wstring *v25; // ecx
  std::wostream *v26; // eax
  Font *v27; // ecx
  Game *v28; // eax
  Font *v29; // ecx
  int v30; // eax
  float g; // [esp+28h] [ebp-104h]
  float ga; // [esp+28h] [ebp-104h]
  const std::wstring *gb; // [esp+28h] [ebp-104h]
  const std::wstring *gc; // [esp+28h] [ebp-104h]
  float newSecondsa; // [esp+30h] [ebp-FCh]
  int newSeconds; // [esp+30h] [ebp-FCh]
  long double v37; // [esp+4Ch] [ebp-E0h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v38; // [esp+54h] [ebp-D8h] BYREF
  std::wstring result; // [esp+104h] [ebp-28h] BYREF
  int v40; // [esp+128h] [ebp-4h]

  v3 = 0;
  if ( this->overlays._Mylast - this->overlays._Myfirst )
  {
    v4 = 0;
    do
      this->overlays._Myfirst[v4++].isActive = this->status.mode == eTimeAttackOn
                                            && (v5 = this->car->sim->track,
                                                v3++ == (this->status.sectorIndex + 1)
                                                      % (v5->physicsTrack.sectorsNormalizedPositions._Mylast
                                                       - v5->physicsTrack.sectorsNormalizedPositions._Myfirst));
    while ( v3 < this->overlays._Mylast - this->overlays._Myfirst );
  }
  if ( this->status.carDamage != this->guiInfo.lastCarDamage || (v37 = CarAvatar::hasPenalty(this->car), v37 > 0.0) )
  {
    v6 = this->status.carDamage;
    this->guiInfo.penaltyTimer = 5.0;
    this->guiInfo.lastCarDamage = v6;
  }
  v7 = this->guiInfo.penaltyTimer;
  if ( v7 > 0.0 )
  {
    v8 = v7 - dt;
    this->guiInfo.penaltyTimer = v8;
    if ( v8 <= 0.0 )
    {
      this->guiInfo.penaltyPointsAccumulated = 0.0;
      this->guiInfo.penaltyTimer = 0.0;
    }
  }
  this->guiInfo.lastTimeLeft = (int)(float)(this->status.timeLeft * 0.001);
  TimeAttack::renderGuiCheckpointBreak(this, dt, 0.0, 0.0);
  TimeAttack::renderGuiPenalties(this, dt);
  v9 = this->game->graphics->gl;
  GLRenderer::color4f(v9, 0.0, 0.0, 0.0, 0.5);
  GLRenderer::quad(v9, (float)((float)this->game->graphics->videoSettings.width * 0.5) - 270.0, 80.0, 540.0, 85.0, 0, 0);
  GLRenderer::color4f(v9, 0.60000002, 0.60000002, 0.60000002, 0.5);
  GLRenderer::begin(v9, eLinesStrip, 0);
  GLRenderer::vertex3f(v9, (float)((float)this->game->graphics->videoSettings.width * 0.5) - 270.0, 80.0, 0.0);
  GLRenderer::vertex3f(v9, (float)((float)this->game->graphics->videoSettings.width * 0.5) + 270.0, 80.0, 0.0);
  GLRenderer::vertex3f(v9, (float)((float)this->game->graphics->videoSettings.width * 0.5) + 270.0, 165.0, 0.0);
  GLRenderer::vertex3f(v9, (float)((float)this->game->graphics->videoSettings.width * 0.5) - 270.0, 165.0, 0.0);
  GLRenderer::vertex3f(v9, (float)((float)this->game->graphics->videoSettings.width * 0.5) - 270.0, 80.0, 0.0);
  GLRenderer::end(v9);
  GLRenderer::begin(v9, eLinesStrip, 0);
  GLRenderer::vertex3f(v9, (float)this->game->graphics->videoSettings.width * 0.5, 95.0, 0.0);
  GLRenderer::vertex3f(v9, (float)this->game->graphics->videoSettings.width * 0.5, 150.0, 0.0);
  GLRenderer::end(v9);
  v10 = &this->guiWhiteClock;
  GraphicsManager::setTexture(this->game->graphics, 0, &this->guiWhiteClock);
  GLRenderer::color4f(v9, 1.0, 1.0, 1.0, 1.0);
  if ( this->guiWhiteClock.kid )
    v11 = kglTextureGetHeight(v10->kid);
  else
    v11 = 0;
  if ( v10->kid )
    v12 = kglTextureGetWidth(v10->kid);
  else
    v12 = 0;
  v13 = (float)v11;
  g = v13;
  v14 = (float)v12;
  GLRenderer::quad(v9, (float)((float)this->game->graphics->videoSettings.width * 0.5) - 240.0, 90.0, v14, g, 1, 0);
  v15 = &this->guiWhiteCup;
  GraphicsManager::setTexture(this->game->graphics, 0, &this->guiWhiteCup);
  GLRenderer::color4f(v9, 1.0, 1.0, 1.0, 1.0);
  if ( this->guiWhiteCup.kid )
    v16 = kglTextureGetHeight(v15->kid);
  else
    v16 = 0;
  if ( v15->kid )
    v17 = kglTextureGetWidth(v15->kid);
  else
    v17 = 0;
  v18 = (float)v16;
  ga = v18;
  v19 = (float)v17;
  GLRenderer::quad(v9, (float)((float)this->game->graphics->videoSettings.width * 0.5) + 30.0, 90.0, v19, ga, 1, 0);
  *(_DWORD *)v38.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v38.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v38.gap68);
  v40 = 0;
  std::wiostream::basic_iostream<wchar_t>(&v38, &v38.gap10[8], 0);
  v40 = 1;
  *(_DWORD *)&v38.gap0[*(_DWORD *)(*(_DWORD *)v38.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v37 + *(_DWORD *)(*(_DWORD *)v38.gap0 + 4) + 4) = *(_DWORD *)(*(_DWORD *)v38.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v38.gap10[8]);
  *(_DWORD *)&v38.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v38.gap10[64] = 0;
  *(_DWORD *)&v38.gap10[68] = 0;
  newSecondsa = this->status.timeLeft;
  v40 = 3;
  v20 = timeToTimeAttackString(&result, newSecondsa);
  LOBYTE(v40) = 4;
  v21 = std::operator<<<wchar_t>((std::wostream *)v38.gap10, v20);
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v21, "\"");
  LOBYTE(v40) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  Font::setColor(this->font._Ptr, 1.0, 1.0, 1.0, 1.0);
  gb = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v38, &result);
  v22 = this->game;
  v23 = this->font._Ptr;
  LOBYTE(v40) = 5;
  Font::blitString(
    v23,
    (float)((float)v22->graphics->videoSettings.width * 0.5) - 10.0,
    100.0,
    gb,
    0.80000001,
    eAlignRight);
  LOBYTE(v40) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  std::wstring::assign(&result, word_17BE9D8, 0);
  LOBYTE(v40) = 6;
  if ( (v38.gap10[68] & 1) != 0 )
  {
    if ( std::wstreambuf::pptr(&v38.gap10[8]) )
      std::wstreambuf::epptr(&v38.gap10[8]);
    else
      std::wstreambuf::egptr(&v38.gap10[8]);
    std::wstreambuf::eback(&v38.gap10[8]);
    v24 = std::wstreambuf::eback(&v38.gap10[8]);
    operator delete(v24);
  }
  std::wstreambuf::setg(&v38.gap10[8], 0, 0, 0);
  std::wstreambuf::setp(&v38.gap10[8], 0, 0);
  v25 = &result;
  *(_DWORD *)&v38.gap10[64] = 0;
  newSeconds = *(_DWORD *)&v38.gap10[68] & 0xFFFFFFFE;
  if ( result._Myres >= 8 )
    v25 = (std::wstring *)result._Bx._Ptr;
  *(_DWORD *)&v38.gap10[68] &= 0xFFFFFFFE;
  std::wstringbuf::_Init((std::wstringbuf *)&v38.gap10[8], v25->_Bx._Buf, result._Mysize, newSeconds);
  LOBYTE(v40) = 3;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v26 = (std::wostream *)std::wostream::operator<<(v38.gap10, (int)this->status.points);
  std::operator<<<wchar_t,std::char_traits<wchar_t>>(v26, " pt");
  v27 = this->font._Ptr;
  if ( this->status.points >= 0.0 )
    Font::setColor(v27, 1.0, 1.0, 1.0, 1.0);
  else
    Font::setColor(v27, 1.0, 0.0, 0.0, 1.0);
  gc = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v38, &result);
  v28 = this->game;
  v29 = this->font._Ptr;
  LOBYTE(v40) = 7;
  Font::blitString(
    v29,
    (float)((float)v28->graphics->videoSettings.width * 0.5) + 260.0,
    100.0,
    gc,
    0.80000001,
    eAlignRight);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  v40 = -1;
  *(_DWORD *)&v38.gap0[*(_DWORD *)(*(_DWORD *)v38.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&v37 + *(_DWORD *)(*(_DWORD *)v38.gap0 + 4) + 4) = *(_DWORD *)(*(_DWORD *)v38.gap0 + 4) - 104;
  *(_DWORD *)&v38.gap10[8] = &std::wstringbuf::`vftable';
  if ( (v38.gap10[68] & 1) != 0 )
  {
    if ( std::wstreambuf::pptr(&v38.gap10[8]) )
      std::wstreambuf::epptr(&v38.gap10[8]);
    else
      std::wstreambuf::egptr(&v38.gap10[8]);
    std::wstreambuf::eback(&v38.gap10[8]);
    v30 = std::wstreambuf::eback(&v38.gap10[8]);
    operator delete(v30);
  }
  std::wstreambuf::setg(&v38.gap10[8], 0, 0, 0);
  std::wstreambuf::setp(&v38.gap10[8], 0, 0);
  *(_DWORD *)&v38.gap10[68] &= 0xFFFFFFFE;
  *(_DWORD *)&v38.gap10[64] = 0;
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v38.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v38.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v38.gap68);
}
void TimeAttack::renderHUD(TimeAttack *this, float dt)
{
  Sim *v3; // edx
  eTimeAttackStatus v4; // eax
  __int32 v5; // eax
  std::wstring *v6; // eax
  Font *v7; // ecx
  Game *v8; // eax
  const std::wstring *g; // [esp+10h] [ebp-F4h]
  int v10; // [esp+28h] [ebp-DCh]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v11; // [esp+2Ch] [ebp-D8h] BYREF
  std::wstring result; // [esp+DCh] [ebp-28h] BYREF
  int v13; // [esp+100h] [ebp-4h]

  v10 = 0;
  v3 = this->car->sim;
  if ( (((char *)v3->track->physicsTrack.sectorsNormalizedPositions._Mylast
       - (char *)v3->track->physicsTrack.sectorsNormalizedPositions._Myfirst) & 0xFFFFFFFC) == 0
    || this->target.sectors._Myfirst == this->target.sectors._Mylast )
  {
    *(_DWORD *)v11.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v11.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v11.gap68);
    v13 = 0;
    v10 = 1;
    std::wiostream::basic_iostream<wchar_t>(&v11, &v11.gap10[8], 0);
    v13 = 1;
    *(_DWORD *)&v11.gap0[*(_DWORD *)(*(_DWORD *)v11.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v10 + *(_DWORD *)(*(_DWORD *)v11.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v11.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v11.gap10[8]);
    *(_DWORD *)&v11.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v11.gap10[64] = 0;
    *(_DWORD *)&v11.gap10[68] = 0;
    v13 = 3;
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(
      (std::wostream *)v11.gap10,
      "TIME ATTACK is not available for this track ");
    Font::setColor(this->font._Ptr, 1.0, 0.0, 0.0, 1.0);
    v6 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v11, &result);
    v7 = this->font._Ptr;
    g = v6;
    v8 = this->game;
    LOBYTE(v13) = 4;
    Font::blitString(v7, (float)v8->graphics->videoSettings.width * 0.5, 100.0, g, 0.80000001, eAlignCenter);
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Bx._Buf[0] = 0;
    result._Mysize = 0;
    v13 = -1;
    *(_DWORD *)&v11.gap0[*(_DWORD *)(*(_DWORD *)v11.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v10 + *(_DWORD *)(*(_DWORD *)v11.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v11.gap0 + 4) - 104;
    *(_DWORD *)&v11.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&v11.gap10[8]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v11.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v11.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v11.gap68);
  }
  else if ( !v3->escMenu->visible
         && !ReplayManager::isInReplaymode(v3->replayManager)
         && !this->car->sim->pauseMenu->visible )
  {
    v4 = this->status.mode;
    if ( v4 )
    {
      v5 = v4 - 1;
      if ( v5 )
      {
        if ( v5 == 1 )
          TimeAttack::renderGuiStart(this, dt);
      }
      else
      {
        TimeAttack::renderGuiStatus(this, dt);
      }
    }
    else
    {
      TimeAttack::renderGameOver(this, dt);
    }
  }
}
void TimeAttack::update(TimeAttack *this, float dt)
{
  Sim *v3; // ecx
  unsigned int v4; // edx
  eTimeAttackStatus v5; // eax
  __int32 v6; // eax
  CarAvatar *v7; // ecx
  __m128 v8; // xmm1
  float v9; // eax
  float v10; // xmm1_4
  float v11; // xmm2_4
  vec3f v12; // [esp+8h] [ebp-Ch] BYREF
  float dta; // [esp+18h] [ebp+4h]

  v3 = this->car->sim;
  if ( (((char *)v3->track->physicsTrack.sectorsNormalizedPositions._Mylast
       - (char *)v3->track->physicsTrack.sectorsNormalizedPositions._Myfirst) & 0xFFFFFFFC) != 0
    && !v3->pauseMenu->visible )
  {
    v4 = this->status.sectorIndex;
    if ( this->target.sectors._Mylast - this->target.sectors._Myfirst > v4
      && this->status.sectorTimes._Mylast - this->status.sectorTimes._Myfirst > v4
      && !ReplayManager::isInReplaymode(v3->replayManager) )
    {
      v5 = this->status.mode;
      if ( v5 )
      {
        v6 = v5 - 1;
        if ( v6 )
        {
          if ( v6 == 1 )
          {
            CarAvatar::setGentleStop(this->car, 0);
            v7 = this->car;
            v8 = (__m128)LODWORD(v7->bodyMatrix.M42);
            if ( v7->sim->escMenu->visible )
            {
              v9 = v7->bodyMatrix.M43;
              *(_QWORD *)&this->status.resetPosition.x = _mm_unpacklo_ps((__m128)LODWORD(v7->bodyMatrix.M41), v8).m128_u64[0];
              this->status.resetPosition.z = v9;
            }
            else
            {
              v10 = v8.m128_f32[0] - this->status.resetPosition.y;
              v11 = v7->bodyMatrix.M43 - this->status.resetPosition.z;
              v12.x = v7->bodyMatrix.M41 - this->status.resetPosition.x;
              v12.y = v10;
              v12.z = v11;
              dta = vec3f::length(&v12);
              if ( dta > 3.0 )
                this->status.mode = eTimeAttackOn;
            }
          }
        }
        else
        {
          TimeAttack::updateTimeAttack(this, dt);
        }
      }
      else
      {
        TimeAttack::updateGameOver(this, dt);
      }
    }
  }
}
void TimeAttack::updateGameOver(TimeAttack *this, float dt)
{
  TimeAttack_vtbl *v3; // eax

  v3 = this->__vftable;
  this->status.gameOverTime = dt + this->status.gameOverTime;
  ((void (*)(void))v3->verifyConditions)();
  CarAvatar::setGentleStop(this->car, 1);
}
void TimeAttack::updatePenalties(TimeAttack *this, float dt)
{
  CarAvatar *v3; // ecx
  float v4; // xmm2_4
  float v5; // xmm0_4
  int v6; // eax
  Speed *v7; // eax
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm1_4
  Speed result; // [esp+Ch] [ebp-44h] BYREF
  std::wstring imessage; // [esp+10h] [ebp-40h] BYREF
  std::wstring description; // [esp+28h] [ebp-28h] BYREF
  int v14; // [esp+4Ch] [ebp-4h]

  v3 = this->car;
  v4 = (float)((float)((float)(v3->physicsState.damageZoneLevel[0] + v3->physicsState.damageZoneLevel[1])
                     + v3->physicsState.damageZoneLevel[2])
             + v3->physicsState.damageZoneLevel[3])
     + v3->physicsState.damageZoneLevel[4];
  if ( v4 != this->status.carDamage )
  {
    v5 = this->guiInfo.penaltyPointsAccumulated;
    this->status.carDamage = v4;
    this->guiInfo.penaltyPointsAccumulated = v5 - (float)(v4 * 5.0);
    this->status.points = this->status.points - (float)(v4 * 5.0);
  }
  v6 = !v3->physicsState.tyreSurfaceDef[0].isValidTrack;
  if ( !v3->physicsState.tyreSurfaceDef[1].isValidTrack )
    ++v6;
  if ( !v3->physicsState.tyreSurfaceDef[2].isValidTrack )
    ++v6;
  if ( !v3->physicsState.tyreSurfaceDef[3].isValidTrack )
    ++v6;
  if ( v6 >= 3 )
  {
    this->guiInfo.penaltyPointsAccumulated = this->guiInfo.penaltyPointsAccumulated - (float)(dt * 100.0);
    this->status.points = this->status.points - (float)(dt * 100.0);
  }
  v7 = RaceEngineer::getMaxSpeedFromGear(v3->raceEngineer._Myptr, &result, 0);
  v8 = this->car->physicsState.speed.value * 3.5999999;
  v9 = (float)(v7->value * 3.5999999) * 0.66666669;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  if ( v9 <= v8 )
  {
    this->status.slowPenaltyTimer = 10.0;
  }
  else
  {
    v10 = this->status.slowPenaltyTimer - dt;
    this->status.slowPenaltyTimer = v10;
    if ( v10 <= 0.0 )
    {
      description._Myres = 7;
      description._Mysize = 0;
      description._Bx._Buf[0] = 0;
      std::wstring::assign(&description, L"You are too slow, gain some speed", 0x21u);
      v14 = 0;
      imessage._Myres = 7;
      imessage._Mysize = 0;
      imessage._Bx._Buf[0] = 0;
      std::wstring::assign(&imessage, L"Warning", 7u);
      LOBYTE(v14) = 1;
      SystemMessage::addMessage(this->car->sim->systemMessage, &imessage, &description, eDefault);
      if ( imessage._Myres >= 8 )
        operator delete(imessage._Bx._Ptr);
      imessage._Myres = 7;
      imessage._Mysize = 0;
      imessage._Bx._Buf[0] = 0;
      if ( description._Myres >= 8 )
        operator delete(description._Bx._Ptr);
      this->guiInfo.penaltyPointsAccumulated = this->guiInfo.penaltyPointsAccumulated - (float)(dt * 100.0);
      this->status.points = this->status.points - (float)(dt * 100.0);
    }
  }
}
void TimeAttack::updateTimeAttack(TimeAttack *this, float dt)
{
  Lap *v3; // eax
  int v4; // edi
  float v5; // xmm1_4
  int v6; // eax
  int v7; // edx
  float v8; // xmm0_4
  int v9; // ecx
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm3_4
  float *v13; // ecx
  float v14; // xmm1_4
  int v15; // edx
  float v16; // xmm0_4
  float v17; // xmm2_4
  float *v18; // eax
  int v19; // ecx
  float *v20; // eax
  Console *v21; // eax
  Console *v22; // eax
  Console *v23; // eax
  Console *v24; // eax
  Console *v25; // eax
  Console *v26; // eax
  Console *v27; // eax
  Console *v28; // eax
  Console *v29; // eax
  Console *v30; // eax
  Console *v31; // eax
  int v32; // ecx
  float *v33; // eax
  unsigned int v34; // ecx
  float v35; // xmm0_4
  CarAvatar *v36; // eax
  std::wstring v37; // [esp-98h] [ebp-128h] BYREF
  const float *v38; // [esp-80h] [ebp-110h]
  std::wstring v39; // [esp-7Ch] [ebp-10Ch] BYREF
  float *v40; // [esp-64h] [ebp-F4h]
  std::wstring v41; // [esp-60h] [ebp-F0h] BYREF
  float *v42; // [esp-48h] [ebp-D8h]
  std::wstring v43; // [esp-44h] [ebp-D4h] BYREF
  float *v44; // [esp-2Ch] [ebp-BCh]
  std::wstring v45; // [esp-28h] [ebp-B8h] BYREF
  _BYTE newPoints[28]; // [esp-10h] [ebp-A0h] BYREF
  float bonusSeconds; // [esp+1Ch] [ebp-74h] BYREF
  float additionalBonusPoints; // [esp+20h] [ebp-70h] BYREF
  float timeDifference[2]; // [esp+24h] [ebp-6Ch] BYREF
  __m128i v50; // [esp+2Ch] [ebp-64h] BYREF
  std::wstring *v51; // [esp+3Ch] [ebp-54h]
  std::wstring *v52; // [esp+40h] [ebp-50h]
  std::wstring *v53; // [esp+44h] [ebp-4Ch]
  _BYTE *v54; // [esp+48h] [ebp-48h]
  std::wstring *v55; // [esp+4Ch] [ebp-44h]
  Lap result; // [esp+50h] [ebp-40h] BYREF
  int v57; // [esp+8Ch] [ebp-4h]

  TimeAttack::updatePenalties(this, dt);
  v3 = RaceManager::getCurrentLap(this->car->sim->raceManager, &result, this->car);
  v4 = v3->splits._Mylast - v3->splits._Myfirst;
  if ( result.compound._Myres >= 8 )
    operator delete(result.compound._Bx._Ptr);
  result.compound._Myres = 7;
  result.compound._Mysize = 0;
  result.compound._Bx._Buf[0] = 0;
  if ( result.splits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&result.splits);
    operator delete(result.splits._Myfirst);
  }
  v5 = this->lastSectorUpdate;
  if ( v5 <= 0.08 )
  {
    this->lastSectorUpdate = v5 + dt;
  }
  else
  {
    v6 = this->status.sectorIndex;
    this->lastSectorUpdate = 0.0;
    this->lastSectorIndex = v6;
  }
  v7 = this->status.sectorIndex;
  if ( v7 != v4 )
  {
    v8 = this->target.sectors._Myfirst[v7] - this->status.sectorTimes._Myfirst[v7];
    timeDifference[0] = v8;
    if ( v8 < 0.0 )
    {
      this->status.mode = eTimeAttackOver;
LABEL_27:
      Event<std::wstring>::trigger(
        (Event<OnGearRequestEvent> *)&this->evOnLeaderboardScore,
        (const OnGearRequestEvent *)&this->status.points);
      return;
    }
    *(_DWORD *)&newPoints[24] = this->car;
    v9 = *(_DWORD *)(*(_DWORD *)&newPoints[24] + 172);
    bonusSeconds = v8 * 10.0;
    v10 = (float)((float)(unsigned int)RaceManager::getLapCount(
                                         *(RaceManager **)(v9 + 224),
                                         *(CarAvatar **)&newPoints[24])
                * 100.0)
        * timeDifference[0];
    if ( v10 <= 750.0 )
    {
      if ( v10 >= 0.0 )
        additionalBonusPoints = v10;
      else
        additionalBonusPoints = 0.0;
    }
    else
    {
      additionalBonusPoints = 750.0;
    }
    if ( RaceManager::getLapCount(this->car->sim->raceManager, this->car) != 1 || v4 )
    {
      v11 = additionalBonusPoints;
    }
    else
    {
      v11 = 0.0;
      additionalBonusPoints = 0.0;
    }
    v12 = v11 + bonusSeconds;
    v13 = &bonusSeconds;
    v14 = timeDifference[0] * 0.5;
    v15 = this->status.sectorIndex;
    v16 = v12 + this->status.points;
    bonusSeconds = timeDifference[0] * 0.5;
    this->status.points = v16;
    if ( v14 >= 5.0 )
      v13 = (float *)&maxMSecondsBonus;
    v17 = this->status.sectorTimes._Myfirst[v15];
    v18 = this->target.sectors._Myfirst;
    *(float *)&newPoints[24] = *v13 - (float)(this->target.sectorIncrements._Myfirst[v15] * v17);
    *(float *)&newPoints[20] = v12;
    *(float *)&newPoints[16] = dt;
    v18[v15] = v17 + *(float *)&newPoints[24];
    TimeAttack::renderGuiCheckpointBreak(
      this,
      *(float *)&newPoints[16],
      *(float *)&newPoints[20],
      *(float *)&newPoints[24]);
    bonusSeconds = COERCE_FLOAT(RaceManager::getLapCount(this->car->sim->raceManager, this->car));
    v54 = &newPoints[4];
    std::wstring::wstring((std::wstring *)&newPoints[4], L"\n");
    v19 = this->status.sectorIndex;
    v20 = this->target.sectors._Myfirst;
    v57 = 0;
    *(_DWORD *)newPoints = &v20[v19];
    v52 = &v45;
    std::wstring::wstring(&v45, L" NEW SECTOR OBJECTIVE ");
    LOBYTE(v57) = 1;
    v44 = &additionalBonusPoints;
    v51 = &v43;
    std::wstring::wstring(&v43, L" | ");
    LOBYTE(v57) = 2;
    v42 = timeDifference;
    v53 = &v41;
    std::wstring::wstring(&v41, L" | ");
    LOBYTE(v57) = 3;
    v40 = &bonusSeconds;
    v55 = &v39;
    std::wstring::wstring(&v39, L" | ");
    LOBYTE(v57) = 4;
    v38 = &this->status.sectorTimes._Myfirst[this->status.sectorIndex];
    LODWORD(timeDifference[1]) = &v37;
    std::wstring::wstring(&v37, L"CKP : ");
    LOBYTE(v57) = 5;
    v21 = Console::singleton();
    LOBYTE(v57) = 4;
    v22 = Console::operator<<(v21, v37);
    v23 = Console::operator<<(v22, v38);
    LOBYTE(v57) = 3;
    v24 = Console::operator<<(v23, v39);
    v25 = Console::operator<<(v24, (const int *)v40);
    LOBYTE(v57) = 2;
    v26 = Console::operator<<(v25, v41);
    v27 = Console::operator<<(v26, v42);
    LOBYTE(v57) = 1;
    v28 = Console::operator<<(v27, v43);
    v29 = Console::operator<<(v28, v44);
    LOBYTE(v57) = 0;
    v30 = Console::operator<<(v29, v45);
    v31 = Console::operator<<(v30, *(const float **)newPoints);
    v57 = -1;
    Console::operator<<(v31, *(std::wstring *)&newPoints[4]);
    v32 = this->status.sectorIndex;
    v33 = this->status.sectorTimes._Myfirst;
    this->lastSectorIndex = v32;
    v33[v32] = 0.0;
    this->status.sectorIndex = v4;
    this->lastSectorUpdate = 0.0;
  }
  v34 = this->status.sectorIndex;
  if ( v34 < this->status.sectorTimes._Mylast - this->status.sectorTimes._Myfirst )
    this->status.sectorTimes._Myfirst[v34] = this->status.sectorTimes._Myfirst[v34] + dt;
  v35 = this->target.sectors._Myfirst[this->status.sectorIndex]
      - this->status.sectorTimes._Myfirst[this->status.sectorIndex];
  this->status.timeLeft = v35;
  if ( v35 <= 0.0 )
  {
    *(_DWORD *)&newPoints[24] = this;
    this->status.mode = eTimeAttackOver;
    *(_DWORD *)newPoints = &std::_Func_impl<std::_Callable_obj<_lambda_ae2a90bb9214023e4a9249d4c26c1f22_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
    *(_DWORD *)&newPoints[4] = this;
    *(_DWORD *)&newPoints[16] = newPoints;
    v36 = this->car;
    v57 = -1;
    ACCameraManager::registerToFadeInEvent(
      v36->sim->cameraManager,
      *(std::function<void __cdecl(bool const &)> *)newPoints,
      *(void **)&newPoints[24]);
    v50.m128i_i32[0] = 0;
    v50.m128i_i32[3] = (int)this;
    *(__int64 *)((char *)v50.m128i_i64 + 4) = 0x4020000000000000i64;
    ACCameraManager::fadeIn(this->car->sim->cameraManager, (FadeModeDef)_mm_loadu_si128(&v50));
    goto LABEL_27;
  }
}
void TimeAttack::verifyConditions(TimeAttack *this)
{
  unsigned int v2; // ebx
  int v3; // esi
  std::wstring *v4; // eax
  const std::wstring *v5; // eax
  GameMode::ConditionDef *v6; // eax
  std::wstring imessage; // [esp+10h] [ebp-40h] BYREF
  std::wstring result; // [esp+28h] [ebp-28h] BYREF
  int v9; // [esp+4Ch] [ebp-4h]

  v2 = 0;
  if ( this->conditions._Mylast - this->conditions._Myfirst )
  {
    v3 = 0;
    do
    {
      if ( this->status.points >= (float)this->conditions._Myfirst[v3].objective
        && !this->conditions._Myfirst[v3].achieved )
      {
        imessage._Myres = 7;
        imessage._Mysize = 0;
        imessage._Bx._Buf[0] = 0;
        std::wstring::assign(&imessage, L"TimeAttack challenge", 0x14u);
        v4 = &this->conditions._Myfirst->name;
        v9 = 0;
        v5 = std::operator+<wchar_t>(&result, (std::wstring *)((char *)v4 + v3 * 56), L" Achieved");
        LOBYTE(v9) = 1;
        SystemMessage::addMessage(this->car->sim->systemMessage, &imessage, v5, eDefault);
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        v9 = -1;
        if ( imessage._Myres >= 8 )
          operator delete(imessage._Bx._Ptr);
        imessage._Myres = 7;
        imessage._Bx._Buf[0] = 0;
        v6 = this->conditions._Myfirst;
        imessage._Mysize = 0;
        v6[v3].achieved = 1;
        GameMode::setTier(this, v2);
      }
      ++v2;
      ++v3;
    }
    while ( v2 < this->conditions._Mylast - this->conditions._Myfirst );
  }
}
