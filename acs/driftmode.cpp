#include "driftmode.h"
void DriftMode::DriftMode(DriftMode *this, CarAvatar *car)
{
  CarAvatar *v3; // ebx
  Font *v4; // eax
  Font *v5; // eax
  std::_Ref_count_base *v6; // edi
  Font *v7; // eax
  Game *v8; // eax
  Texture *v9; // eax
  Game *v10; // eax
  Texture *v11; // eax
  Game *v12; // eax
  Texture *v13; // eax
  Game *v14; // eax
  Texture *v15; // eax
  Game *v16; // eax
  Texture *v17; // eax
  Game *v18; // eax
  Texture *v19; // eax
  Game *v20; // eax
  Texture *v21; // eax
  Game *v22; // eax
  Texture *v23; // eax
  Event<OnPhysicsStepCompleted> *v24; // ecx
  unsigned int v25; // ecx
  float *v26; // edx
  double v27; // xmm0_8
  unsigned int v28; // eax
  std::wstring v29; // [esp-10h] [ebp-88h] BYREF
  unsigned int v30; // [esp+8h] [ebp-70h]
  std::shared_ptr<Font> _Right; // [esp+24h] [ebp-54h] BYREF
  CarAvatar *v32; // [esp+2Ch] [ebp-4Ch]
  DriftMode *v33; // [esp+30h] [ebp-48h]
  std::wstring filename; // [esp+34h] [ebp-44h] BYREF
  Texture result; // [esp+4Ch] [ebp-2Ch] BYREF
  int v36; // [esp+74h] [ebp-4h]

  v3 = car;
  v33 = this;
  v32 = car;
  v30 = (unsigned int)car->game;
  v29._Myres = 7;
  v29._Mysize = 0;
  v29._Bx._Buf[0] = 0;
  std::wstring::assign(&v29, L"DRIFT_MODE", 0xAu);
  GameMode::GameMode(this, v29, (Game *)v30);
  this->__vftable = (DriftMode_vtbl *)&DriftMode::`vftable';
  v36 = 0;
  this->font._Ptr = 0;
  this->font._Rep = 0;
  this->mode = eDriftingStill;
  this->guiStar.kid = 0;
  this->guiStar.fileName._Myres = 7;
  this->guiStar.fileName._Mysize = 0;
  this->guiStar.fileName._Bx._Buf[0] = 0;
  this->guiWhiteClock.kid = 0;
  this->guiWhiteClock.fileName._Myres = 7;
  this->guiWhiteClock.fileName._Mysize = 0;
  this->guiWhiteClock.fileName._Bx._Buf[0] = 0;
  this->guiWhiteCup.kid = 0;
  this->guiWhiteCup.fileName._Myres = 7;
  this->guiWhiteCup.fileName._Mysize = 0;
  this->guiWhiteCup.fileName._Bx._Buf[0] = 0;
  this->guiInstantDrift.kid = 0;
  this->guiInstantDrift.fileName._Myres = 7;
  this->guiInstantDrift.fileName._Mysize = 0;
  this->guiInstantDrift.fileName._Bx._Buf[0] = 0;
  this->guiInstantDriftExtreme.kid = 0;
  this->guiInstantDriftExtreme.fileName._Myres = 7;
  this->guiInstantDriftExtreme.fileName._Mysize = 0;
  this->guiInstantDriftExtreme.fileName._Bx._Buf[0] = 0;
  this->guiLevelUp.kid = 0;
  this->guiLevelUp.fileName._Myres = 7;
  this->guiLevelUp.fileName._Mysize = 0;
  this->guiLevelUp.fileName._Bx._Buf[0] = 0;
  this->guiCombo.kid = 0;
  this->guiCombo.fileName._Myres = 7;
  this->guiCombo.fileName._Mysize = 0;
  this->guiCombo.fileName._Bx._Buf[0] = 0;
  this->guiStartTex.kid = 0;
  this->guiStartTex.fileName._Myres = 7;
  this->guiStartTex.fileName._Mysize = 0;
  this->guiStartTex.fileName._Bx._Buf[0] = 0;
  this->bonusTime.y = 0.0;
  this->bonusTime.x = 0.0;
  this->bonusTime.bonus._Myres = 7;
  this->bonusTime.bonus._Mysize = 0;
  this->bonusTime.bonus._Bx._Buf[0] = 0;
  this->bonusPoints.y = 0.0;
  this->bonusPoints.x = 0.0;
  this->bonusPoints.bonus._Myres = 7;
  this->bonusPoints.bonus._Mysize = 0;
  this->bonusPoints.bonus._Bx._Buf[0] = 0;
  LOBYTE(v36) = 11;
  this->lastTimeLeft = 0;
  this->maxSessionComboCount = 0.0;
  this->levelUpTime = 0.0;
  this->oldPoints = 0.0;
  this->secondsLeft = 60.0;
  this->currentLevel = 0;
  this->sessionPoints = 0.0;
  this->maxPoints = 0;
  this->currentPointsPerLevel = 0.0;
  this->lastPointsAchieved = 0;
  this->lastSecondsAchieved = 0;
  PhysicsAvatar::setAllowedTyresOut(car->sim->physicsAvatar, 2);
  v30 = 24;
  this->car = car;
  v4 = (Font *)operator new(v30);
  _Right._Ptr = v4;
  LOBYTE(v36) = 12;
  if ( v4 )
    Font::Font(v4, eFontMonospaced, 35.0, 0, 0);
  else
    v5 = 0;
  LOBYTE(v36) = 11;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v5);
  std::shared_ptr<Font>::operator=(&this->font, &_Right);
  v6 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v6->_Destroy(v6);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v6->_Weaks) )
        v6->_Delete_this(v6);
    }
    v3 = v32;
  }
  v7 = this->font._Ptr;
  v30 = 26;
  v29._Myres = (unsigned int)L"content/gui/drift/star.png";
  filename._Myres = 7;
  v7->shadowed = 1;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, (const wchar_t *)v29._Myres, v30);
  v8 = this->game;
  LOBYTE(v36) = 13;
  v9 = ResourceStore::getTexture(v8->graphics->resourceStore._Myptr, &result, &filename, 0);
  this->guiStar.kid = v9->kid;
  LOBYTE(v36) = 14;
  if ( &this->guiStar.fileName != &v9->fileName )
    std::wstring::assign(&this->guiStar.fileName, &v9->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v36) = 13;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v36) = 11;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"content/gui/drift/time_icon.png", 0x1Fu);
  v10 = this->game;
  LOBYTE(v36) = 15;
  v11 = ResourceStore::getTexture(v10->graphics->resourceStore._Myptr, &result, &filename, 0);
  this->guiWhiteClock.kid = v11->kid;
  LOBYTE(v36) = 16;
  if ( &this->guiWhiteClock.fileName != &v11->fileName )
    std::wstring::assign(&this->guiWhiteClock.fileName, &v11->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v36) = 15;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v36) = 11;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"content/gui/drift/points_icon.png", 0x21u);
  v12 = this->game;
  LOBYTE(v36) = 17;
  v13 = ResourceStore::getTexture(v12->graphics->resourceStore._Myptr, &result, &filename, 0);
  this->guiWhiteCup.kid = v13->kid;
  LOBYTE(v36) = 18;
  if ( &this->guiWhiteCup.fileName != &v13->fileName )
    std::wstring::assign(&this->guiWhiteCup.fileName, &v13->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v36) = 17;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v36) = 11;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"content/gui/drift/instantDrift.png", 0x22u);
  v14 = this->game;
  LOBYTE(v36) = 19;
  v15 = ResourceStore::getTexture(v14->graphics->resourceStore._Myptr, &result, &filename, 0);
  this->guiInstantDrift.kid = v15->kid;
  LOBYTE(v36) = 20;
  if ( &this->guiInstantDrift.fileName != &v15->fileName )
    std::wstring::assign(&this->guiInstantDrift.fileName, &v15->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v36) = 19;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v36) = 11;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"content/gui/drift/instantDriftExtreme.png", 0x29u);
  v16 = this->game;
  LOBYTE(v36) = 21;
  v17 = ResourceStore::getTexture(v16->graphics->resourceStore._Myptr, &result, &filename, 0);
  this->guiInstantDriftExtreme.kid = v17->kid;
  LOBYTE(v36) = 22;
  if ( &this->guiInstantDriftExtreme.fileName != &v17->fileName )
    std::wstring::assign(&this->guiInstantDriftExtreme.fileName, &v17->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v36) = 21;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v36) = 11;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"content/gui/drift/levelup.png", 0x1Du);
  v18 = this->game;
  LOBYTE(v36) = 23;
  v19 = ResourceStore::getTexture(v18->graphics->resourceStore._Myptr, &result, &filename, 0);
  this->guiLevelUp.kid = v19->kid;
  LOBYTE(v36) = 24;
  if ( &this->guiLevelUp.fileName != &v19->fileName )
    std::wstring::assign(&this->guiLevelUp.fileName, &v19->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v36) = 23;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v36) = 11;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"content/gui/drift/combo.png", 0x1Bu);
  v20 = this->game;
  LOBYTE(v36) = 25;
  v21 = ResourceStore::getTexture(v20->graphics->resourceStore._Myptr, &result, &filename, 0);
  this->guiCombo.kid = v21->kid;
  LOBYTE(v36) = 26;
  if ( &this->guiCombo.fileName != &v21->fileName )
    std::wstring::assign(&this->guiCombo.fileName, &v21->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v36) = 25;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v36) = 11;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  std::wstring::wstring(&filename, L"content/gui/drift/drift_start.png");
  v22 = this->game;
  LOBYTE(v36) = 27;
  v23 = ResourceStore::getTexture(v22->graphics->resourceStore._Myptr, &result, &filename, 0);
  this->guiStartTex.kid = v23->kid;
  LOBYTE(v36) = 28;
  if ( &this->guiStartTex.fileName != &v23->fileName )
    std::wstring::assign(&this->guiStartTex.fileName, &v23->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v36) = 27;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  v30 = (unsigned int)this;
  v29._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_ec3fa2fb99b2535ddeeab2096f7a03f9_,0>,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>,void,OnNewSessionEvent const &>::`vftable';
  *(_DWORD *)&v29._Bx._Alias[4] = this;
  v29._Mysize = (unsigned int)&v29;
  v24 = (Event<OnPhysicsStepCompleted> *)&v3->sim->evOnNewSession;
  LOBYTE(v36) = 11;
  Event<std::wstring>::addHandler(v24, (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v29, this);
  v25 = 200;
  v26 = this->pointsPerLevel;
  do
  {
    v27 = (double)(int)v25;
    v28 = v25 >> 31;
    v25 += 100;
    *v26++ = v27 + _xmm[v28];
  }
  while ( v25 < 0x18768 );
}
void DriftMode::~DriftMode(DriftMode *this)
{
  std::_Ref_count_base *v2; // edi
  std::_Ref_count_base *v3; // edi

  this->__vftable = (DriftMode_vtbl *)&DriftMode::`vftable';
  v2 = this->font._Rep;
  this->font._Rep = 0;
  this->font._Ptr = 0;
  if ( v2 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v2->_Uses, 0xFFFFFFFF) )
    {
      v2->_Destroy(v2);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v2->_Weaks, 0xFFFFFFFF) )
        v2->_Delete_this(v2);
    }
  }
  if ( this->bonusPoints.bonus._Myres >= 8 )
    operator delete(this->bonusPoints.bonus._Bx._Ptr);
  this->bonusPoints.bonus._Myres = 7;
  this->bonusPoints.bonus._Mysize = 0;
  this->bonusPoints.bonus._Bx._Buf[0] = 0;
  if ( this->bonusTime.bonus._Myres >= 8 )
    operator delete(this->bonusTime.bonus._Bx._Ptr);
  this->bonusTime.bonus._Myres = 7;
  this->bonusTime.bonus._Mysize = 0;
  this->bonusTime.bonus._Bx._Buf[0] = 0;
  OnSetupAppCreated::~OnSetupAppCreated(&this->guiStartTex);
  OnSetupAppCreated::~OnSetupAppCreated(&this->guiCombo);
  OnSetupAppCreated::~OnSetupAppCreated(&this->guiLevelUp);
  OnSetupAppCreated::~OnSetupAppCreated(&this->guiInstantDriftExtreme);
  OnSetupAppCreated::~OnSetupAppCreated(&this->guiInstantDrift);
  OnSetupAppCreated::~OnSetupAppCreated(&this->guiWhiteCup);
  OnSetupAppCreated::~OnSetupAppCreated(&this->guiWhiteClock);
  OnSetupAppCreated::~OnSetupAppCreated(&this->guiStar);
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
  GameMode::~GameMode(this);
}
DriftMode *DriftMode::`scalar deleting destructor'(DriftMode *this, unsigned int a2)
{
  DriftMode::~DriftMode(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void DriftMode::animateBonuses(DriftMode *this, float dt)
{
  float v3; // xmm1_4
  float v4; // xmm0_4

  Font::setColor(this->font._Ptr, 0.0, 1.0, 0.0, 1.0);
  v3 = this->bonusTime.y;
  if ( v3 > 0.0 )
  {
    Font::blitString(this->font._Ptr, this->bonusTime.x, v3, &this->bonusTime.bonus, 1.0, eAlignRight);
    this->bonusTime.y = this->bonusTime.y - (float)(dt * 100.0);
  }
  v4 = this->bonusPoints.y;
  if ( v4 > 0.0 )
  {
    Font::blitString(this->font._Ptr, this->bonusPoints.x, v4, &this->bonusPoints.bonus, 1.0, eAlignRight);
    this->bonusPoints.y = this->bonusPoints.y - (float)(dt * 100.0);
  }
}
void DriftMode::modeDrifting(DriftMode *this, float dt)
{
  int v3; // ebp
  CarAvatar *v4; // edx
  float v5; // xmm0_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm1_4
  int v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  CarAvatar *v17; // eax
  Game *v18; // eax
  GraphicsManager *v19; // eax
  GLRenderer *v20; // edi
  int v21; // ebx
  float v22; // eax
  std::wostream *v23; // eax
  float v24; // xmm2_4
  float v25; // xmm0_4
  float v26; // xmm3_4
  float v27; // xmm2_4
  float v28; // xmm0_4
  std::_Func_base<void,bool const &> *v29; // eax
  Game *v30; // eax
  Font *v31; // ecx
  int v32; // eax
  unsigned int v33; // eax
  float v34; // xmm0_4
  float v35; // xmm0_4
  int v36; // eax
  unsigned int v37; // eax
  float v38; // xmm0_4
  float v39; // xmm0_4
  std::wstring *v40; // eax
  std::wostream *v41; // eax
  int v42; // eax
  Font *v43; // ecx
  const std::wstring *v44; // eax
  std::_Func_base<void,bool const &> *v45; // ecx
  Font *v46; // ecx
  GearChangeRequest v47; // edi
  std::wostream *v48; // eax
  std::wostream *v49; // eax
  std::wstring *v50; // eax
  std::wstring *v51; // edi
  std::wstring *v52; // eax
  std::wostream *v53; // eax
  const std::wstring *v54; // eax
  std::_Func_base<void,bool const &> *v55; // ecx
  Font *v56; // ecx
  std::wostream *v57; // eax
  std::wostream *v58; // eax
  DriftMode *v59; // ebp
  std::wstring *v60; // edi
  GraphicsManager *v61; // eax
  GLRenderer *v62; // edi
  unsigned int v63; // ebp
  unsigned int v64; // eax
  float v65; // xmm0_4
  float v66; // xmm0_4
  CarAvatar *v67; // eax
  std::wostream *v68; // eax
  const std::wstring *v69; // eax
  std::_Func_base<void,bool const &> *v70; // ecx
  Font *v71; // ecx
  GraphicsManager *v72; // eax
  GLRenderer *v73; // edi
  unsigned int v74; // ebp
  unsigned int v75; // eax
  float v76; // xmm0_4
  float v77; // xmm0_4
  CarAvatar *v78; // eax
  std::wostream *v79; // eax
  const std::wstring *v80; // eax
  float v81; // xmm2_4
  int v82; // eax
  std::function<void __cdecl(bool const &)> g; // [esp+3Ch] [ebp-40Ch] BYREF
  float a; // [esp+54h] [ebp-3F4h]
  float v85; // [esp+84h] [ebp-3C4h]
  float v86; // [esp+88h] [ebp-3C0h]
  OnGearRequestEvent message; // [esp+8Ch] [ebp-3BCh] BYREF
  float x; // [esp+94h] [ebp-3B4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v89; // [esp+98h] [ebp-3B0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > bonus; // [esp+148h] [ebp-300h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v91; // [esp+1F8h] [ebp-250h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v92; // [esp+2A8h] [ebp-1A0h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v93; // [esp+358h] [ebp-F0h] BYREF
  std::wstring v94; // [esp+408h] [ebp-40h] BYREF
  std::wstring result; // [esp+420h] [ebp-28h] BYREF
  int v96; // [esp+440h] [ebp-8h]
  int v97; // [esp+444h] [ebp-4h]
  void *retaddr; // [esp+448h] [ebp+0h]

  v85 = 0.0;
  v3 = 0;
  v4 = this->car;
  message.request = eNoGearRequest;
  v5 = (float)v4->physicsState.driftComboCounter;
  if ( v5 > this->maxSessionComboCount )
    this->maxSessionComboCount = v5;
  v6 = v4->physicsState.driftPoints;
  v7 = this->oldPoints;
  LODWORD(v8) = (int)v7;
  if ( SLODWORD(v7) != SLODWORD(v6) )
  {
    v3 = (int)(float)(v6 - v7);
    this->currentPointsPerLevel = (float)v3 + this->currentPointsPerLevel;
    this->oldPoints = v4->physicsState.driftPoints;
    this->lastPointsAchieved = v3;
  }
  v9 = (float)this->maxPoints;
  v10 = (float)v3 + this->sessionPoints;
  this->sessionPoints = v10;
  if ( v10 > v9 )
    this->maxPoints = (int)v10;
  v11 = this->currentLevel;
  v12 = this->currentPointsPerLevel;
  v13 = this->pointsPerLevel[v11];
  if ( v12 > v13 )
  {
    v14 = v12 - v13;
    v15 = FLOAT_30_0;
    this->currentPointsPerLevel = v14;
    v16 = 30.0 - (float)v11;
    if ( v16 <= 30.0 )
    {
      if ( v16 >= 10.0 )
        v15 = 30.0 - (float)v11;
      else
        v15 = FLOAT_10_0;
    }
    message.request = (int)v15;
    this->lastSecondsAchieved = (int)v15;
    if ( v11 < 999 )
      this->currentLevel = v11 + 1;
    this->levelUpTime = 3.0;
    this->secondsLeft = (float)(int)v15 + this->secondsLeft;
  }
  if ( this->secondsLeft <= 0.0 && v4->physicsState.instantDrift == 0.0 )
  {
    LODWORD(a) = this;
    this->mode = eDriftingOver;
    g._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_3aaa896e5da70f3d531f10bf2d0a9d46_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
    g._Space._Pfn[1] = (void (__cdecl *)())this;
    g._Impl = (std::_Func_base<void,bool const &> *)&g;
    v17 = this->car;
    v97 = -1;
    ACCameraManager::registerToFadeInEvent(v17->sim->cameraManager, g, (void *)LODWORD(a));
    v94._Bx._Ptr = 0;
    *(_DWORD *)&v94._Bx._Alias[12] = this;
    *(_QWORD *)&v94._Bx._Alias[4] = 0x4020000000000000i64;
    ACCameraManager::fadeIn(this->car->sim->cameraManager, (FadeModeDef)_mm_loadu_si128((const __m128i *)&v94));
    *(float *)&message.request = (float)this->maxPoints;
    Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&this->evOnLeaderboardScore, &message);
  }
  else
  {
    v18 = this->game;
    a = v8;
    v86 = (float)v18->graphics->videoSettings.width * 0.5;
    DriftMode::animateBonuses(this, dt);
    v19 = this->game->graphics;
    a = 0.5;
    (&g._Impl)[1] = 0;
    g._Impl = 0;
    v20 = v19->gl;
    GLRenderer::color4f(v20, 0.0, 0.0, 0.0, 0.5);
    x = v86 - 270.0;
    GLRenderer::quad(v20, v86 - 270.0, 80.0, 540.0, 85.0, 0, 0);
    GLRenderer::color4f(v20, 0.60000002, 0.60000002, 0.60000002, 0.5);
    GLRenderer::begin(v20, eLinesStrip, 0);
    GLRenderer::vertex3f(v20, v86 - 270.0, 80.0, 0.0);
    *(float *)&message.nextGear = v86 + 270.0;
    GLRenderer::vertex3f(v20, v86 + 270.0, 80.0, 0.0);
    GLRenderer::vertex3f(v20, v86 + 270.0, 165.0, 0.0);
    GLRenderer::vertex3f(v20, v86 - 270.0, 165.0, 0.0);
    GLRenderer::vertex3f(v20, v86 - 270.0, 80.0, 0.0);
    GLRenderer::end(v20);
    GLRenderer::color4f(v20, 0.0, 0.0, 0.0, 0.5);
    GLRenderer::quad(v20, v86 - 270.0, 167.0, 539.0, 20.0, 0, 0);
    *(_DWORD *)v89.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v89.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v89.gap68);
    v97 = 1;
    v21 = 1;
    LODWORD(v85) = 1;
    std::wiostream::basic_iostream<wchar_t>(&v89, &v89.gap10[8], 0);
    v97 = 2;
    *(_DWORD *)&v89.gap0[*(_DWORD *)(*(_DWORD *)v89.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)((char *)&x + *(_DWORD *)(*(_DWORD *)v89.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v89.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v89.gap10[8]);
    *(_DWORD *)&v89.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v89.gap10[64] = 0;
    *(_DWORD *)&v89.gap10[68] = 0;
    LODWORD(v22) = this->currentLevel + 1;
    v97 = 4;
    a = v22;
    v23 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v89.gap10, "Level ");
    std::wostream::operator<<(v23, LODWORD(a));
    GLRenderer::color4f(v20, 0.2, 0.69999999, 0.2, 0.60000002);
    v24 = this->currentPointsPerLevel / this->pointsPerLevel[this->currentLevel];
    x = x + 1.0;
    *(float *)&message.nextGear = v24 * 538.0;
    GLRenderer::quad(v20, x, 168.0, v24 * 538.0, 18.0, 0, 0);
    GLRenderer::color4f(v20, 0.69999999, 0.69999999, 0.2, 0.60000002);
    v25 = FLOAT_1_0;
    v26 = this->car->physicsState.instantDrift / this->pointsPerLevel[this->currentLevel];
    v27 = 538.0 - (float)(v24 * 538.0);
    if ( v26 <= 1.0 )
    {
      if ( v26 >= 0.0 )
        v25 = this->car->physicsState.instantDrift / this->pointsPerLevel[this->currentLevel];
      else
        v25 = 0.0;
    }
    v28 = v25 * 537.0;
    v85 = v28;
    if ( v28 <= v27 )
    {
      if ( v28 < 0.0 )
      {
        v28 = 0.0;
        v85 = 0.0;
      }
    }
    else
    {
      v28 = 538.0 - *(float *)&message.nextGear;
      v85 = 538.0 - *(float *)&message.nextGear;
    }
    if ( v28 == v27 )
    {
      GLRenderer::color4f(v20, 1.0, 1.0, 0.2, 0.60000002);
      v28 = v85;
    }
    GLRenderer::quad(v20, x + *(float *)&message.nextGear, 168.0, v28, 18.0, 0, 0);
    Font::setColor(this->font._Ptr, 1.0, 1.0, 1.0, 0.69999999);
    v29 = (std::_Func_base<void,bool const &> *)std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                                                  &v89,
                                                  &result);
    LODWORD(a) = 2;
    (&g._Impl)[1] = (std::_Func_base<void,bool const &> *)1056964608;
    g._Impl = v29;
    v30 = this->game;
    v31 = this->font._Ptr;
    LOBYTE(v97) = 5;
    Font::blitString(
      v31,
      (float)(v30->graphics->videoSettings.width / 2),
      167.0,
      (const std::wstring *)g._Impl,
      0.5,
      eAlignCenter);
    LOBYTE(v97) = 4;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    DriftMode::updateLevelUp(this, dt);
    GLRenderer::color4f(v20, 0.60000002, 0.60000002, 0.60000002, 0.5);
    GLRenderer::begin(v20, eLinesStrip, 0);
    GLRenderer::vertex3f(v20, v86, 95.0, 0.0);
    GLRenderer::vertex3f(v20, v86, 150.0, 0.0);
    GLRenderer::end(v20);
    GraphicsManager::setTexture(this->game->graphics, 0, &this->guiWhiteClock);
    GLRenderer::color4f(v20, 1.0, 1.0, 1.0, 1.0);
    if ( this->guiWhiteClock.kid )
      v32 = kglTextureGetHeight(this->guiWhiteClock.kid);
    else
      v32 = 0;
    message.nextGear = v32;
    if ( this->guiWhiteClock.kid )
      v33 = kglTextureGetWidth(this->guiWhiteClock.kid);
    else
      v33 = 0;
    v34 = (float)(unsigned int)message.nextGear;
    *(float *)&g._Impl = v34;
    v35 = (float)v33;
    GLRenderer::quad(v20, v86 - 240.0, 90.0, v35, *(float *)&g._Impl, 1, 0);
    GraphicsManager::setTexture(this->game->graphics, 0, &this->guiWhiteCup);
    GLRenderer::color4f(v20, 1.0, 1.0, 1.0, 1.0);
    if ( this->guiWhiteCup.kid )
      v36 = kglTextureGetHeight(this->guiWhiteCup.kid);
    else
      v36 = 0;
    message.nextGear = v36;
    if ( this->guiWhiteCup.kid )
      v37 = kglTextureGetWidth(this->guiWhiteCup.kid);
    else
      v37 = 0;
    v38 = (float)(unsigned int)message.nextGear;
    *(float *)&g._Impl = v38;
    v39 = (float)v37;
    GLRenderer::quad(v20, v86 + 30.0, 90.0, v39, *(float *)&g._Impl, 1, 0);
    v94._Myres = 7;
    v94._Mysize = 0;
    v94._Bx._Buf[0] = 0;
    std::wstring::assign(&v94, word_17BE9D8, 0);
    LOBYTE(v97) = 6;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v89.gap10[8]);
    a = *(float *)&v89.gap10[68];
    v40 = &v94;
    (&g._Impl)[1] = (std::_Func_base<void,bool const &> *)v94._Mysize;
    if ( v94._Myres >= 8 )
      v40 = (std::wstring *)v94._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v89.gap10[8], v40->_Bx._Buf, (unsigned int)(&g._Impl)[1], SLODWORD(a));
    LOBYTE(v97) = 4;
    if ( v94._Myres >= 8 )
      operator delete(v94._Bx._Ptr);
    v41 = (std::wostream *)std::wostream::operator<<(v89.gap10, (int)this->secondsLeft);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v41, "\"");
    v42 = (int)this->secondsLeft;
    v43 = this->font._Ptr;
    a = 1.0;
    if ( v42 >= 6 )
    {
      (&g._Impl)[1] = (std::_Func_base<void,bool const &> *)1065353216;
      g._Impl = (std::_Func_base<void,bool const &> *)1065353216;
    }
    else
    {
      (&g._Impl)[1] = 0;
      g._Impl = 0;
    }
    Font::setColor(v43, 1.0, *(float *)&g._Impl, *(float *)&(&g._Impl)[1], a);
    v44 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v89, &result);
    LODWORD(a) = 1;
    (&g._Impl)[1] = v45;
    v46 = this->font._Ptr;
    LOBYTE(v97) = 7;
    *(float *)&message.nextGear = v86 - 10.0;
    Font::blitString(v46, v86 - 10.0, 100.0, v44, 1.0, eAlignRight);
    LOBYTE(v97) = 4;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    Font::setColor(this->font._Ptr, 1.0, 1.0, 1.0, 1.0);
    v47 = message.request;
    if ( message.request )
    {
      LODWORD(this->bonusTime.x) = message.nextGear;
      this->bonusTime.y = 100.0;
      *(_DWORD *)bonus.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)bonus.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(bonus.gap68);
      LOBYTE(retaddr) = 8;
      v21 = 3;
      LODWORD(v86) = 3;
      std::wiostream::basic_iostream<wchar_t>(&bonus.gap0[4], &bonus.gap10[12], 0);
      v96 = 9;
      *(_DWORD *)&v89.gap68[*(_DWORD *)(*(_DWORD *)&v89.gap68[68] + 4) + 68] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v89.gap68[*(_DWORD *)(*(_DWORD *)&v89.gap68[68] + 4) + 64] = *(_DWORD *)(*(_DWORD *)&v89.gap68[68] + 4)
                                                                             - 104;
      std::wstreambuf::wstreambuf(&bonus.gap10[4]);
      *(_DWORD *)&bonus.gap10[4] = &std::wstringbuf::`vftable';
      *(_DWORD *)&bonus.gap10[60] = 0;
      *(_DWORD *)&bonus.gap10[64] = 0;
      LOBYTE(v96) = 11;
      v48 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)((char *)&bonus._Chcount + 4), "+");
      v49 = (std::wostream *)std::wostream::operator<<(v48, v47);
      std::operator<<<wchar_t,std::char_traits<wchar_t>>(v49, (const char *)LODWORD(a));
      v50 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&bonus, &result);
      v51 = &this->bonusTime.bonus;
      message.request = (GearChangeRequest)v50;
      if ( &this->bonusTime.bonus != v50 )
      {
        if ( this->bonusTime.bonus._Myres >= 8 )
        {
          operator delete(v51->_Bx._Ptr);
          v50 = (std::wstring *)message.request;
        }
        this->bonusTime.bonus._Myres = 7;
        this->bonusTime.bonus._Mysize = 0;
        v51->_Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&this->bonusTime.bonus, v50);
      }
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      LOBYTE(v97) = 4;
      *(_DWORD *)&bonus.gap0[*(_DWORD *)(*(_DWORD *)bonus.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v89.gap68[*(_DWORD *)(*(_DWORD *)bonus.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)bonus.gap0 + 4) - 104;
      *(_DWORD *)&bonus.gap10[8] = &std::wstringbuf::`vftable';
      std::wstringbuf::_Tidy((std::wstringbuf *)&bonus.gap10[8]);
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&bonus.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&bonus.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(bonus.gap68);
    }
    v94._Myres = 7;
    v94._Mysize = 0;
    v94._Bx._Buf[0] = 0;
    std::wstring::assign(&v94, word_17BE9D8, 0);
    LOBYTE(v97) = 12;
    std::wstringbuf::_Tidy((std::wstringbuf *)&v89.gap10[8]);
    a = *(float *)&v89.gap10[68];
    v52 = &v94;
    (&g._Impl)[1] = (std::_Func_base<void,bool const &> *)v94._Mysize;
    if ( v94._Myres >= 8 )
      v52 = (std::wstring *)v94._Bx._Ptr;
    std::wstringbuf::_Init((std::wstringbuf *)&v89.gap10[8], v52->_Bx._Buf, (unsigned int)(&g._Impl)[1], SLODWORD(a));
    LOBYTE(v97) = 4;
    if ( v94._Myres >= 8 )
      operator delete(v94._Bx._Ptr);
    v53 = (std::wostream *)std::wostream::operator<<(v89.gap10, (int)this->sessionPoints);
    std::operator<<<wchar_t,std::char_traits<wchar_t>>(v53, " pt");
    v54 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v89, &result);
    LODWORD(a) = 1;
    (&g._Impl)[1] = v55;
    v56 = this->font._Ptr;
    LOBYTE(v97) = 13;
    *(float *)&message.request = v86 + 260.0;
    Font::blitString(v56, v86 + 260.0, 100.0, v54, 1.0, eAlignRight);
    LOBYTE(v97) = 4;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    if ( v3 )
    {
      LODWORD(this->bonusPoints.x) = message.request;
      this->bonusPoints.y = 100.0;
      *(_DWORD *)v91.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v91.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v91.gap68);
      LOBYTE(retaddr) = 14;
      v21 |= 4u;
      v86 = *(float *)&v21;
      std::wiostream::basic_iostream<wchar_t>(&v91.gap0[4], &v91.gap10[12], 0);
      v96 = 15;
      *(_DWORD *)&bonus.gap68[*(_DWORD *)(*(_DWORD *)&bonus.gap68[68] + 4) + 68] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&bonus.gap68[*(_DWORD *)(*(_DWORD *)&bonus.gap68[68] + 4) + 64] = *(_DWORD *)(*(_DWORD *)&bonus.gap68[68]
                                                                                             + 4)
                                                                                 - 104;
      std::wstreambuf::wstreambuf(&v91.gap10[4]);
      *(_DWORD *)&v91.gap10[4] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v91.gap10[60] = 0;
      *(_DWORD *)&v91.gap10[64] = 0;
      LOBYTE(v96) = 17;
      v57 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)((char *)&v91._Chcount + 4), "+");
      v58 = (std::wostream *)std::wostream::operator<<(v57, v3);
      std::operator<<<wchar_t,std::char_traits<wchar_t>>(v58, (const char *)LODWORD(a));
      v59 = (DriftMode *)std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(
                           &v91,
                           &result);
      v60 = &this->bonusPoints.bonus;
      if ( &this->bonusPoints.bonus != (std::wstring *)v59 )
      {
        if ( this->bonusPoints.bonus._Myres >= 8 )
          operator delete(v60->_Bx._Ptr);
        this->bonusPoints.bonus._Myres = 7;
        this->bonusPoints.bonus._Mysize = 0;
        LODWORD(a) = v59;
        v60->_Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&this->bonusPoints.bonus, (std::wstring *)LODWORD(a));
      }
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      LOBYTE(v97) = 4;
      *(_DWORD *)&v91.gap0[*(_DWORD *)(*(_DWORD *)v91.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&bonus.gap68[*(_DWORD *)(*(_DWORD *)v91.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v91.gap0 + 4) - 104;
      *(_DWORD *)&v91.gap10[8] = &std::wstringbuf::`vftable';
      std::wstringbuf::_Tidy((std::wstringbuf *)&v91.gap10[8]);
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v91.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v91.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v91.gap68);
    }
    if ( (int)this->car->physicsState.instantDrift )
    {
      v61 = this->game->graphics;
      a = 0.5;
      (&g._Impl)[1] = 0;
      g._Impl = 0;
      v62 = v61->gl;
      GLRenderer::color4f(v62, 0.0, 0.0, 0.0, 0.5);
      v85 = v86 + 275.0;
      GLRenderer::quad(v62, v86 + 275.0, 80.0, 250.0, 85.0, 0, 0);
      GLRenderer::color4f(v62, 0.60000002, 0.60000002, 0.60000002, 0.5);
      GLRenderer::begin(v62, eLinesStrip, 0);
      GLRenderer::vertex3f(v62, v86 + 275.0, 80.0, 0.0);
      *(float *)&message.request = v86 + 525.0;
      GLRenderer::vertex3f(v62, v86 + 525.0, 80.0, 0.0);
      GLRenderer::vertex3f(v62, v86 + 525.0, 165.0, 0.0);
      GLRenderer::vertex3f(v62, v86 + 275.0, 165.0, 0.0);
      GLRenderer::vertex3f(v62, v86 + 275.0, 80.0, 0.0);
      GLRenderer::end(v62);
      if ( this->car->physicsState.driftBonusOn )
      {
        GraphicsManager::setTexture(this->game->graphics, 0, &this->guiInstantDriftExtreme);
        GLRenderer::color4f(v62, 1.0, 1.0, 1.0, 1.0);
        if ( this->guiInstantDrift.kid )
          v63 = kglTextureGetHeight(this->guiInstantDrift.kid);
        else
          v63 = 0;
        if ( this->guiInstantDrift.kid )
          v64 = kglTextureGetWidth(this->guiInstantDrift.kid);
        else
          v64 = 0;
        v65 = (float)v63;
        *(float *)&g._Impl = v65;
        v66 = (float)v64;
        GLRenderer::quad(v62, v86 + 420.0, 90.0, v66, *(float *)&g._Impl, 1, 0);
      }
      *(_DWORD *)v93.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v93.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v93.gap68);
      LOBYTE(v97) = 18;
      v21 |= 8u;
      v85 = *(float *)&v21;
      std::wiostream::basic_iostream<wchar_t>(&v93, &v93.gap10[8], 0);
      v97 = 19;
      *(_DWORD *)&v93.gap0[*(_DWORD *)(*(_DWORD *)v93.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v92.gap68[*(_DWORD *)(*(_DWORD *)v93.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v93.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&v93.gap10[8]);
      *(_DWORD *)&v93.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v93.gap10[64] = 0;
      *(_DWORD *)&v93.gap10[68] = 0;
      v67 = this->car;
      LOBYTE(v97) = 21;
      LODWORD(a) = (int)v67->physicsState.instantDrift;
      v68 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v93.gap10, "+ ");
      std::wostream::operator<<(v68, LODWORD(a));
      Font::setColor(this->font._Ptr, 1.0, 1.0, 0.0, 1.0);
      v69 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v93, &result);
      a = 0.0;
      (&g._Impl)[1] = v70;
      v71 = this->font._Ptr;
      LOBYTE(v97) = 22;
      Font::blitString(v71, v86 + 280.0, 100.0, v69, 1.0, eAlignLeft);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      LOBYTE(v97) = 4;
      *(_DWORD *)&v93.gap0[*(_DWORD *)(*(_DWORD *)v93.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v92.gap68[*(_DWORD *)(*(_DWORD *)v93.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v93.gap0 + 4) - 104;
      *(_DWORD *)&v93.gap10[8] = &std::wstringbuf::`vftable';
      std::wstringbuf::_Tidy((std::wstringbuf *)&v93.gap10[8]);
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v93.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v93.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v93.gap68);
    }
    if ( this->car->physicsState.driftComboCounter > 1 )
    {
      v72 = this->game->graphics;
      a = 0.5;
      (&g._Impl)[1] = 0;
      g._Impl = 0;
      v73 = v72->gl;
      GLRenderer::color4f(v73, 0.0, 0.0, 0.0, 0.5);
      v85 = v86 - 275.0;
      GLRenderer::quad(v73, (float)(v86 - 275.0) - 250.0, 80.0, 250.0, 85.0, 0, 0);
      GLRenderer::color4f(v73, 0.60000002, 0.60000002, 0.60000002, 0.5);
      GLRenderer::begin(v73, eLinesStrip, 0);
      GLRenderer::vertex3f(v73, v86 - 275.0, 80.0, 0.0);
      *(float *)&message.request = v86 - 525.0;
      GLRenderer::vertex3f(v73, v86 - 525.0, 80.0, 0.0);
      GLRenderer::vertex3f(v73, v86 - 525.0, 165.0, 0.0);
      GLRenderer::vertex3f(v73, v86 - 275.0, 165.0, 0.0);
      GLRenderer::vertex3f(v73, v86 - 275.0, 80.0, 0.0);
      GLRenderer::end(v73);
      GraphicsManager::setTexture(this->game->graphics, 0, &this->guiCombo);
      GLRenderer::color4f(v73, 1.0, 1.0, 1.0, 1.0);
      if ( this->guiInstantDrift.kid )
        v74 = kglTextureGetHeight(this->guiInstantDrift.kid);
      else
        v74 = 0;
      if ( this->guiInstantDrift.kid )
        v75 = kglTextureGetWidth(this->guiInstantDrift.kid);
      else
        v75 = 0;
      v76 = (float)v74;
      *(float *)&g._Impl = v76;
      v77 = (float)v75;
      GLRenderer::quad(v73, v86 - 515.0, 90.0, v77, *(float *)&g._Impl, 1, 0);
      *(_DWORD *)v92.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
      *(_DWORD *)v92.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
      std::wios::wios(v92.gap68);
      LOBYTE(v97) = 23;
      LODWORD(v85) = v21 | 0x10;
      std::wiostream::basic_iostream<wchar_t>(&v92, &v92.gap10[8], 0);
      v97 = 24;
      *(_DWORD *)&v92.gap0[*(_DWORD *)(*(_DWORD *)v92.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v91.gap68[*(_DWORD *)(*(_DWORD *)v92.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v92.gap0 + 4) - 104;
      std::wstreambuf::wstreambuf(&v92.gap10[8]);
      *(_DWORD *)&v92.gap10[8] = &std::wstringbuf::`vftable';
      *(_DWORD *)&v92.gap10[64] = 0;
      *(_DWORD *)&v92.gap10[68] = 0;
      v78 = this->car;
      LOBYTE(v97) = 26;
      a = *(float *)&v78->physicsState.driftComboCounter;
      v79 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v92.gap10, " x ");
      std::wostream::operator<<(v79, LODWORD(a));
      Font::setColor(this->font._Ptr, 1.0, 1.0, 1.0, 1.0);
      v80 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v92, &result);
      LOBYTE(v97) = 27;
      Font::blitString(this->font._Ptr, v86 - 430.0, 95.0, v80, 1.15, eAlignLeft);
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Bx._Buf[0] = 0;
      result._Mysize = 0;
      LOBYTE(v97) = 4;
      *(_DWORD *)&v92.gap0[*(_DWORD *)(*(_DWORD *)v92.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
      *(_DWORD *)&v91.gap68[*(_DWORD *)(*(_DWORD *)v92.gap0 + 4) + 68] = *(_DWORD *)(*(_DWORD *)v92.gap0 + 4) - 104;
      *(_DWORD *)&v92.gap10[8] = &std::wstringbuf::`vftable';
      std::wstringbuf::_Tidy((std::wstringbuf *)&v92.gap10[8]);
      std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v92.gap10[8]);
      std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v92.gap10[16]);
      std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v92.gap68);
    }
    Font::setColor(this->font._Ptr, 1.0, 1.0, 1.0, 1.0);
    v81 = this->secondsLeft;
    if ( v81 > 0.0 || this->car->physicsState.instantDrift <= 0.0 )
      this->secondsLeft = v81 - dt;
    else
      this->secondsLeft = 0.0;
    v82 = (int)this->secondsLeft;
    v97 = -1;
    this->lastTimeLeft = v82;
    *(_DWORD *)&v89.gap0[*(_DWORD *)(*(_DWORD *)v89.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(_DWORD *)((char *)&x + *(_DWORD *)(*(_DWORD *)v89.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v89.gap0 + 4) - 104;
    *(_DWORD *)&v89.gap10[8] = &std::wstringbuf::`vftable';
    std::wstringbuf::_Tidy((std::wstringbuf *)&v89.gap10[8]);
    std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v89.gap10[8]);
    std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v89.gap10[16]);
    std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v89.gap68);
  }
}
void DriftMode::modeGameOver(DriftMode *this, float dt)
{
  this->verifyConditions(this);
  CarAvatar::setGentleStop(this->car, 1);
  PauseMenu::blankButton(this->car->sim->pauseMenu, ePauseMenuPits, 1);
  PauseMenu::blankButton(this->car->sim->pauseMenu, ePauseMenuResume, 1);
}
void DriftMode::renderHUD(DriftMode *this, float dt)
{
  Sim *v3; // ecx
  PauseMenu *v4; // ecx
  eDriftModeStatus v5; // eax
  __int32 v6; // eax
  Texture *v7; // edi
  unsigned int v8; // ebp
  unsigned int v9; // ebx
  unsigned int v10; // ecx
  float v11; // xmm0_4
  float v12; // xmm0_4
  float g; // [esp+Ch] [ebp-1Ch]
  GLRenderer *dta; // [esp+2Ch] [ebp+4h]

  this->verifyConditions(this);
  v3 = this->car->sim;
  if ( !v3->escMenu->visible && !ReplayManager::isInReplaymode(v3->replayManager) )
  {
    v4 = this->car->sim->pauseMenu;
    if ( !v4->visible )
    {
      v5 = this->mode;
      if ( v5 )
      {
        v6 = v5 - 1;
        if ( v6 )
        {
          if ( v6 == 1 )
          {
            PauseMenu::blankButton(v4, ePauseMenuPits, 1);
            PauseMenu::blankButton(this->car->sim->pauseMenu, ePauseMenuResume, 0);
            CarAvatar::setGentleStop(this->car, 0);
            v7 = &this->guiStartTex;
            GraphicsManager::setTexture(this->game->graphics, 0, &this->guiStartTex);
            dta = this->game->graphics->gl;
            GLRenderer::color4f(dta, 1.0, 1.0, 1.0, 1.0);
            if ( this->guiStartTex.kid )
              v8 = kglTextureGetHeight(v7->kid);
            else
              v8 = 0;
            if ( v7->kid )
              v9 = kglTextureGetWidth(v7->kid);
            else
              v9 = 0;
            if ( v7->kid )
              v10 = kglTextureGetWidth(v7->kid);
            else
              v10 = 0;
            v11 = (float)v8;
            g = v11;
            v12 = (float)v9;
            GLRenderer::quad(
              dta,
              (float)((float)this->game->graphics->videoSettings.width * 0.5) - (float)((float)v10 * 0.5),
              80.0,
              v12,
              g,
              1,
              0);
            if ( (float)(this->car->physicsState.speed.value * 3.5999999) > 15.0 )
            {
              this->mode = eDrifting;
              this->secondsLeft = 60.0;
            }
          }
        }
        else
        {
          DriftMode::modeDrifting(this, dt);
        }
      }
      else
      {
        DriftMode::modeGameOver(this, dt);
      }
    }
  }
}
void DriftMode::updateLevelUp(DriftMode *this, float dt)
{
  GraphicsManager *v3; // ecx
  Texture *v4; // esi
  GLRenderer *v5; // ebx
  unsigned int v6; // ebp
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  float v9; // xmm0_4
  float v10; // xmm0_4
  float g; // [esp+Ch] [ebp-20h]
  GLRenderer *v12; // [esp+28h] [ebp-4h]

  if ( this->levelUpTime > 0.0 )
  {
    v3 = this->game->graphics;
    v4 = &this->guiLevelUp;
    v5 = v3->gl;
    v12 = v5;
    GraphicsManager::setTexture(v3, 0, &this->guiLevelUp);
    GLRenderer::color4f(v5, 1.0, 1.0, 1.0, 1.0);
    if ( this->guiLevelUp.kid )
      v6 = kglTextureGetHeight(v4->kid);
    else
      v6 = 0;
    if ( v4->kid )
      v7 = kglTextureGetWidth(v4->kid);
    else
      v7 = 0;
    if ( v4->kid )
      v8 = kglTextureGetWidth(v4->kid);
    else
      v8 = 0;
    v9 = (float)v6;
    g = v9;
    v10 = (float)v7;
    GLRenderer::quad(
      v12,
      (float)((float)this->game->graphics->videoSettings.width * 0.5) - (float)((double)(v8 >> 1) + 0.0),
      167.0,
      v10,
      g,
      1,
      0);
    this->levelUpTime = this->levelUpTime - dt;
  }
}
void DriftMode::verifyConditions(DriftMode *this)
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
      if ( this->sessionPoints >= (float)this->conditions._Myfirst[v3].objective
        && !this->conditions._Myfirst[v3].achieved )
      {
        imessage._Myres = 7;
        imessage._Mysize = 0;
        imessage._Bx._Buf[0] = 0;
        std::wstring::assign(&imessage, L"Drift challenge", 0xFu);
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
