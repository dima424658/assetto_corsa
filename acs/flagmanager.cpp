#include "flagmanager.h
void FlagManager::FlagManager(FlagManager *this, Sim *aSim)
{
  int v3; // ebx
  Font *v4; // eax
  Font *v5; // eax
  std::_Ref_count_base *v6; // esi
  Font *v7; // eax
  Font *v8; // esi
  ksgui::Control *v9; // eax
  Sim *v10; // eax
  Font *v11; // esi
  ksgui::Control *v12; // eax
  Sim *v13; // eax
  Font *v14; // esi
  ksgui::Control *v15; // eax
  Sim *v16; // eax
  Font *v17; // esi
  ksgui::Control *v18; // eax
  Sim *v19; // eax
  Font *v20; // esi
  ksgui::Control *v21; // eax
  Sim *v22; // eax
  Sim *v23; // ebx
  GameObject **v24; // esi
  TrackAvatar *v25; // eax
  std::wstring *v26; // esi
  TrackAvatar *v27; // eax
  std::wstring *v28; // eax
  std::wstring *v29; // eax
  std::wstring *v30; // eax
  const std::wstring *v31; // eax
  bool v32; // bl
  double v33; // st7
  bool v34; // cf
  Font *v35; // esi
  ksgui::Label *v36; // eax
  ksgui::Label *v37; // ecx
  ksgui::Label_vtbl *v38; // eax
  bool v39; // al
  ksgui::Form *v40; // esi
  bool v41; // zf
  Game *v42; // eax
  float v43; // xmm0_4
  GraphicsManager *v44; // eax
  int v45; // ecx
  float v46; // xmm1_4
  float v47; // xmm0_4
  float left; // xmm1_4
  float v49; // xmm1_4
  int v50; // eax
  float v51; // xmm1_4
  float v52; // xmm0_4
  std::_Ref_count_base *v53; // ebx
  Font *v54; // eax
  ksgui::Label *v55; // edx
  volatile signed __int32 *v56; // esi
  ksgui::Label *v57; // ecx
  Sim *v58; // edx
  Sim *v59; // edx
  Sim *v60; // eax
  Event<OnNewSessionEvent> *v61; // ecx
  _BYTE top[56]; // [esp-Ch] [ebp-144h] BYREF
  int _Val; // [esp+2Ch] [ebp-10Ch] BYREF
  std::shared_ptr<Font> _Right; // [esp+30h] [ebp-108h] BYREF
  FlagManager *v65; // [esp+38h] [ebp-100h]
  std::wstring iname; // [esp+3Ch] [ebp-FCh] BYREF
  std::wstring v67; // [esp+54h] [ebp-E4h] BYREF
  std::wstring v68; // [esp+6Ch] [ebp-CCh] BYREF
  std::wstring result; // [esp+84h] [ebp-B4h] BYREF
  std::wstring v70; // [esp+9Ch] [ebp-9Ch] BYREF
  std::wstring v71; // [esp+B4h] [ebp-84h] BYREF
  std::wstring key; // [esp+CCh] [ebp-6Ch] BYREF
  INIReader ini; // [esp+E4h] [ebp-54h] BYREF
  int v74; // [esp+134h] [ebp-4h]

  v3 = 0;
  _Val = 0;
  v65 = this;
  *(_DWORD *)&top[24] = aSim->game;
  *(_DWORD *)&top[20] = 7;
  *(_DWORD *)&top[16] = 0;
  *(_WORD *)top = 0;
  std::wstring::assign((std::wstring *)top, L"FLAG_MANAGER", 0xCu);
  GameObject::GameObject(this, *(std::wstring *)top, *(Game **)&top[24]);
  this->__vftable = (FlagManager_vtbl *)&FlagManager::`vftable';
  v74 = 0;
  this->evOnFlagChange.handlers._Myfirst = 0;
  this->evOnFlagChange.handlers._Mylast = 0;
  this->evOnFlagChange.handlers._Myend = 0;
  this->lastPositionOnSpline._Myfirst = 0;
  this->lastPositionOnSpline._Mylast = 0;
  this->lastPositionOnSpline._Myend = 0;
  this->blueFlagTimers._Myfirst = 0;
  this->blueFlagTimers._Mylast = 0;
  this->blueFlagTimers._Myend = 0;
  this->sim = aSim;
  this->currentFlag = eNoFlag;
  this->font._Ptr = 0;
  this->font._Rep = 0;
  *(_DWORD *)&top[24] = 24;
  LOBYTE(v74) = 4;
  this->yellowFlagDistance = 700.0;
  this->drawWhiteFlag = 1;
  this->timer = 0.0;
  v4 = (Font *)operator new(*(_DWORD *)&top[24]);
  _Val = (int)v4;
  LOBYTE(v74) = 5;
  if ( v4 )
    Font::Font(v4, eFontProportional, 25.0, 0, 1);
  else
    v5 = 0;
  LOBYTE(v74) = 4;
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
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v6->_Weaks, 0xFFFFFFFF) )
        v6->_Delete_this(v6);
    }
  }
  v7 = this->font._Ptr;
  *(_DWORD *)&top[24] = 280;
  v7->shadowed = 1;
  v8 = (Font *)operator new(*(_DWORD *)&top[24]);
  _Right._Ptr = v8;
  v9 = 0;
  LOBYTE(v74) = 6;
  if ( v8 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"FLAG_BLUE", 9u);
    v10 = this->sim;
    v3 = 1;
    LOBYTE(v74) = 7;
    _Val = 1;
    ksgui::Control::Control((ksgui::Control *)v8, &iname, v10->game->gui);
  }
  this->controlBlue = v9;
  v74 = 4;
  if ( (v3 & 1) != 0 )
  {
    v3 &= 0xFFFFFFFE;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  v11 = (Font *)operator new(280);
  _Right._Ptr = v11;
  v12 = 0;
  LOBYTE(v74) = 9;
  if ( v11 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"FLAG_BLACK", 0xAu);
    v13 = this->sim;
    v3 |= 2u;
    LOBYTE(v74) = 10;
    _Val = v3;
    ksgui::Control::Control((ksgui::Control *)v11, &iname, v13->game->gui);
  }
  this->controlBlack = v12;
  v74 = 4;
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFFFFFFFD;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  v14 = (Font *)operator new(280);
  _Right._Ptr = v14;
  v15 = 0;
  LOBYTE(v74) = 12;
  if ( v14 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"FLAG_CHEQUERED", 0xEu);
    v16 = this->sim;
    v3 |= 4u;
    LOBYTE(v74) = 13;
    _Val = v3;
    ksgui::Control::Control((ksgui::Control *)v14, &iname, v16->game->gui);
  }
  this->controlChequered = v15;
  v74 = 4;
  if ( (v3 & 4) != 0 )
  {
    v3 &= 0xFFFFFFFB;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  v17 = (Font *)operator new(280);
  _Right._Ptr = v17;
  v18 = 0;
  LOBYTE(v74) = 15;
  if ( v17 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"FLAG_YELLOW", 0xBu);
    v19 = this->sim;
    v3 |= 8u;
    LOBYTE(v74) = 16;
    _Val = v3;
    ksgui::Control::Control((ksgui::Control *)v17, &iname, v19->game->gui);
  }
  this->controlYellow = v18;
  v74 = 4;
  if ( (v3 & 8) != 0 )
  {
    v3 &= 0xFFFFFFF7;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
  }
  v20 = (Font *)operator new(280);
  _Right._Ptr = v20;
  v21 = 0;
  LOBYTE(v74) = 18;
  if ( v20 )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"FLAG_PENALTY", 0xCu);
    v22 = this->sim;
    v3 |= 0x10u;
    LOBYTE(v74) = 19;
    _Val = v3;
    ksgui::Control::Control((ksgui::Control *)v20, &iname, v22->game->gui);
  }
  this->controlPenalty = v21;
  v74 = 4;
  if ( (v3 & 0x10) != 0 && iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  *(_DWORD *)&top[24] = 7;
  *(_DWORD *)&top[20] = 0;
  *(_WORD *)&top[4] = 0;
  std::wstring::assign((std::wstring *)&top[4], L"blueFlag", 8u);
  FlagManager::addFlagControl(this, this->controlBlue, *(std::wstring *)&top[4]);
  *(_DWORD *)&top[24] = 7;
  *(_DWORD *)&top[20] = 0;
  *(_WORD *)&top[4] = 0;
  std::wstring::assign((std::wstring *)&top[4], L"blackFlag", 9u);
  FlagManager::addFlagControl(this, this->controlBlack, *(std::wstring *)&top[4]);
  *(_DWORD *)&top[24] = 7;
  *(_DWORD *)&top[20] = 0;
  *(_WORD *)&top[4] = 0;
  std::wstring::assign((std::wstring *)&top[4], L"finish", 6u);
  FlagManager::addFlagControl(this, this->controlChequered, *(std::wstring *)&top[4]);
  *(_DWORD *)&top[24] = 7;
  *(_DWORD *)&top[20] = 0;
  *(_WORD *)&top[4] = 0;
  std::wstring::assign((std::wstring *)&top[4], L"yellowFlag", 0xAu);
  FlagManager::addFlagControl(this, this->controlYellow, *(std::wstring *)&top[4]);
  *(_DWORD *)&top[24] = 7;
  *(_DWORD *)&top[20] = 0;
  *(_WORD *)&top[4] = 0;
  std::wstring::assign((std::wstring *)&top[4], L"penalty", 7u);
  FlagManager::addFlagControl(this, this->controlPenalty, *(std::wstring *)&top[4]);
  v23 = this->sim;
  v24 = v23->gameObjects._Myfirst;
  if ( v24 == v23->gameObjects._Mylast )
  {
LABEL_36:
    v25 = 0;
  }
  else
  {
    while ( 1 )
    {
      v25 = (TrackAvatar *)__RTDynamicCast(
                             *v24,
                             0,
                             &GameObject `RTTI Type Descriptor',
                             &TrackAvatar `RTTI Type Descriptor',
                             0);
      if ( v25 )
        break;
      if ( ++v24 == v23->gameObjects._Mylast )
        goto LABEL_36;
    }
  }
  this->track = v25;
  v26 = TrackAvatar::getConfig(v25, &result);
  v27 = this->track;
  LOBYTE(v74) = 21;
  v28 = std::operator+<wchar_t>(&v68, L"content/tracks/", &v27->name);
  LOBYTE(v74) = 22;
  v29 = std::operator+<wchar_t>(&v70, v28, L"/");
  LOBYTE(v74) = 23;
  v30 = std::operator+<wchar_t>(&v67, v29, v26);
  LOBYTE(v74) = 24;
  v31 = std::operator+<wchar_t>(&v71, v30, L"/data/overlays.ini");
  LOBYTE(v74) = 25;
  INIReader::INIReader(&ini, v31);
  if ( v71._Myres >= 8 )
    operator delete(v71._Bx._Ptr);
  v71._Myres = 7;
  v71._Mysize = 0;
  v71._Bx._Buf[0] = 0;
  if ( v67._Myres >= 8 )
    operator delete(v67._Bx._Ptr);
  v67._Myres = 7;
  v67._Mysize = 0;
  v67._Bx._Buf[0] = 0;
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
  LOBYTE(v74) = 31;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    iname._Myres = 7;
    iname._Mysize = 0;
    iname._Bx._Buf[0] = 0;
    std::wstring::assign(&iname, L"YELLOW_FLAG", 0xBu);
    LOBYTE(v74) = 32;
    v32 = INIReader::hasSection(&ini, &iname);
    LOBYTE(v74) = 31;
    if ( iname._Myres >= 8 )
      operator delete(iname._Bx._Ptr);
    if ( v32 )
    {
      std::wstring::wstring(&key, L"DISTANCE");
      LOBYTE(v74) = 33;
      std::wstring::wstring(&iname, L"YELLOW_FLAG");
      LOBYTE(v74) = 34;
      v33 = INIReader::getFloat(&ini, &iname, &key);
      v34 = iname._Myres < 8;
      this->yellowFlagDistance = v33;
      if ( !v34 )
        operator delete(iname._Bx._Ptr);
      iname._Myres = 7;
      iname._Mysize = 0;
      iname._Bx._Buf[0] = 0;
      LOBYTE(v74) = 31;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
  }
  v35 = (Font *)operator new(284);
  _Right._Ptr = v35;
  LOBYTE(v74) = 35;
  if ( v35 )
  {
    *(_DWORD *)&top[24] = this->sim->game->gui;
    *(_DWORD *)&top[20] = 7;
    *(_DWORD *)&top[16] = 0;
    *(_WORD *)top = 0;
    std::wstring::assign((std::wstring *)top, L"BLACK_FLAG_CAPTION", 0x12u);
    ksgui::Label::Label((ksgui::Label *)v35, *(std::wstring *)top, *(ksgui::GUI **)&top[24]);
    v37 = v36;
  }
  else
  {
    v37 = 0;
  }
  this->blackFlagCaption = v37;
  v38 = v37->__vftable;
  LOBYTE(v74) = 31;
  ((void (*)(ksgui::Label *, int, int))v38->setSize)(v37, 1137180672, 1101529088);
  v39 = Sim::isInTripleScreenMode(this->sim);
  v40 = (ksgui::Form *)this->blackFlagCaption;
  v41 = !v39;
  v42 = this->game;
  v43 = (float)(v40->rect.bottom - v40->rect.top) * 0.5;
  if ( v41 )
  {
    v49 = (float)(v42->graphics->videoSettings.height / 2);
    v50 = v42->graphics->videoSettings.width / 2;
    v51 = v49 - v43;
    v52 = v40->rect.right - v40->rect.left;
    *(float *)&top[24] = v51;
    left = (float)v50 - (float)(v52 * 0.5);
  }
  else
  {
    v44 = v42->graphics;
    v45 = v44->videoSettings.width;
    v46 = (float)(v44->videoSettings.height / 2) - v43;
    v47 = v40->rect.right - v40->rect.left;
    *(float *)&top[24] = v46;
    left = (float)((float)(v45 / 2) - (float)(v47 * 0.5)) + (float)(v45 / 3);
  }
  ksgui::Form::setPosition(v40, left, *(float *)&top[24]);
  this->blackFlagCaption->fontAlign = eAlignCenter;
  this->blackFlagCaption->foreColor = (vec4f)_xmm;
  v53 = this->font._Rep;
  v54 = this->font._Ptr;
  v55 = this->blackFlagCaption;
  _Val = (int)v54;
  if ( v53 )
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)&v53->_Uses, 1u);
    v54 = (Font *)_Val;
  }
  v56 = (volatile signed __int32 *)v55->font._Rep;
  v55->font._Rep = v53;
  v55->font._Ptr = v54;
  if ( v56 )
  {
    if ( !_InterlockedExchangeAdd(v56 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v56)(v56);
      if ( !_InterlockedDecrement(v56 + 2) )
        (*(void (**)(volatile signed __int32 *))(*v56 + 4))(v56);
    }
  }
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, word_17BE9D8, 0);
  v57 = this->blackFlagCaption;
  LOBYTE(v74) = 36;
  v57->setText(v57, &iname);
  LOBYTE(v74) = 31;
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->sim->gameScreen->addControl(this->sim->gameScreen, this->blackFlagCaption, 0);
  v58 = this->sim;
  _Val = 0;
  std::vector<int>::resize(
    (std::vector<int> *)&this->lastPositionOnSpline,
    v58->cars._Mylast - v58->cars._Myfirst,
    &_Val);
  v59 = this->sim;
  _Val = -1082130432;
  std::vector<int>::resize((std::vector<int> *)&this->blueFlagTimers, v59->cars._Mylast - v59->cars._Myfirst, &_Val);
  *(_DWORD *)&top[24] = this;
  *(_DWORD *)top = &std::_Func_impl<std::_Callable_obj<_lambda_7facda78dd6f961defee5e81b24a5156_,0>,std::allocator<std::_Func_class<void,OnFlagEvent const &>>,void,OnFlagEvent const &>::`vftable';
  *(_DWORD *)&top[4] = this;
  *(_DWORD *)&top[16] = top;
  v60 = this->sim;
  LOBYTE(v74) = 31;
  Event<float>::addHandler(
    (Event<SessionInfo> *)&v60->physicsAvatar->evOnFlagEvent,
    *(std::function<void __cdecl(SessionInfo const &)> *)top,
    this);
  *(_DWORD *)&top[24] = this;
  *(_DWORD *)top = &std::_Func_impl<std::_Callable_obj<_lambda_78e9c1906d4139f63604d90100919266_,0>,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>,void,OnNewSessionEvent const &>::`vftable';
  *(_DWORD *)&top[4] = this;
  *(_DWORD *)&top[16] = top;
  v61 = &this->sim->evOnNewSession;
  LOBYTE(v74) = 31;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v61,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)top,
    this);
  LOBYTE(v74) = 4;
  INIReader::~INIReader(&ini);
}
void FlagManager::~FlagManager(FlagManager *this)
{
  std::_Ref_count_base *v2; // esi

  this->__vftable = (FlagManager_vtbl *)&FlagManager::`vftable';
  v2 = this->font._Rep;
  if ( v2 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v2->_Uses, 0xFFFFFFFF) )
    {
      v2->_Destroy(v2);
      if ( !_InterlockedDecrement((volatile signed __int32 *)&v2->_Weaks) )
        v2->_Delete_this(v2);
    }
  }
  if ( this->blueFlagTimers._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->blueFlagTimers);
    operator delete(this->blueFlagTimers._Myfirst);
    this->blueFlagTimers._Myfirst = 0;
    this->blueFlagTimers._Mylast = 0;
    this->blueFlagTimers._Myend = 0;
  }
  if ( this->lastPositionOnSpline._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->lastPositionOnSpline);
    operator delete(this->lastPositionOnSpline._Myfirst);
    this->lastPositionOnSpline._Myfirst = 0;
    this->lastPositionOnSpline._Mylast = 0;
    this->lastPositionOnSpline._Myend = 0;
  }
  if ( this->evOnFlagChange.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnFlagChange);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnFlagChange,
      (Task *)this->evOnFlagChange.handlers._Myfirst,
      (Task *)this->evOnFlagChange.handlers._Mylast);
    operator delete(this->evOnFlagChange.handlers._Myfirst);
    this->evOnFlagChange.handlers._Myfirst = 0;
    this->evOnFlagChange.handlers._Mylast = 0;
    this->evOnFlagChange.handlers._Myend = 0;
  }
  GameObject::~GameObject(this);
}
FlagManager *FlagManager::`scalar deleting destructor'(FlagManager *this, unsigned int a2)
{
  FlagManager::~FlagManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void FlagManager::addFlagControl(FlagManager *this, ksgui::Control *flag, std::wstring flagname)
{
  std::wstring *v4; // eax
  const std::wstring *v5; // eax
  Game *v6; // ecx
  void *v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // ecx
  float v10; // xmm0_4
  GraphicsManager *v11; // eax
  int v12; // ecx
  float left; // xmm0_4
  float v14; // [esp+8h] [ebp-74h]
  float top; // [esp+14h] [ebp-68h]
  std::wstring result; // [esp+20h] [ebp-5Ch] BYREF
  std::wstring v17; // [esp+38h] [ebp-44h] BYREF
  Texture t; // [esp+50h] [ebp-2Ch] BYREF
  int v19; // [esp+78h] [ebp-4h]

  v19 = 0;
  v4 = std::operator+<wchar_t>(&result, L"content/gui/flags/", &flagname);
  LOBYTE(v19) = 1;
  v5 = std::operator+<wchar_t>(&v17, v4, L".png");
  v6 = this->game;
  LOBYTE(v19) = 2;
  ResourceStore::getTexture(v6->graphics->resourceStore._Myptr, &t, v5, 0);
  if ( v17._Myres >= 8 )
    operator delete(v17._Bx._Ptr);
  v17._Myres = 7;
  v17._Mysize = 0;
  v17._Bx._Buf[0] = 0;
  LOBYTE(v19) = 5;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  v7 = t.kid;
  result._Mysize = 0;
  flag->backTexture.kid = t.kid;
  if ( &flag->backTexture.fileName != &t.fileName )
  {
    std::wstring::assign(&flag->backTexture.fileName, &t.fileName, 0, 0xFFFFFFFF);
    v7 = t.kid;
  }
  if ( v7 )
  {
    v8 = kglTextureGetHeight(v7);
    if ( t.kid )
    {
      v9 = kglTextureGetWidth(t.kid);
      goto LABEL_12;
    }
  }
  else
  {
    v8 = 0;
  }
  v9 = 0;
LABEL_12:
  v10 = (float)v8;
  v14 = (float)v9;
  ((void (*)(ksgui::Control *, _DWORD, _DWORD))flag->setSize)(flag, LODWORD(v14), LODWORD(v10));
  *(_WORD *)&flag->drawBorder = 0;
  ksgui::Control::setVisible(flag, 0);
  if ( Sim::isInTripleScreenMode(this->sim) )
  {
    v11 = this->game->graphics;
    v12 = v11->videoSettings.width;
    if ( flag == this->controlBlack )
    {
      ksgui::Form::setPosition(
        (ksgui::Form *)flag,
        (float)((float)(v12 / 2) - (float)((float)(flag->rect.right - flag->rect.left) * 0.5)) + (float)(v12 / 3),
        (float)(v11->videoSettings.height / 2) - (float)((float)(flag->rect.bottom - flag->rect.top) * 0.5));
      goto LABEL_20;
    }
    top = flagPosition.y;
    left = (float)(v12 / 3) + flagPosition.x;
  }
  else
  {
    if ( flag == this->controlBlack )
    {
      ksgui::Form::setPosition(
        (ksgui::Form *)flag,
        (float)(this->game->graphics->videoSettings.width / 2)
      - (float)((float)(flag->rect.right - flag->rect.left) * 0.5),
        (float)(this->game->graphics->videoSettings.height / 2)
      - (float)((float)(flag->rect.bottom - flag->rect.top) * 0.5));
      goto LABEL_20;
    }
    top = flagPosition.y;
    left = flagPosition.x;
  }
  ksgui::Form::setPosition((ksgui::Form *)flag, left, top);
LABEL_20:
  this->sim->gameScreen->addControl(this->sim->gameScreen, flag, 0);
  LOBYTE(v19) = 0;
  OnSetupAppCreated::~OnSetupAppCreated(&t);
  if ( flagname._Myres >= 8 )
    operator delete(flagname._Bx._Ptr);
}
void FlagManager::checkForBlue(FlagManager *this)
{
  CarAvatar *v2; // eax
  unsigned int v3; // ebp
  CarAvatar *v4; // eax
  Sim *v5; // ecx
  unsigned int v6; // ebx
  CarAvatar *v7; // eax
  CarAvatar *v8; // eax
  CarAvatar *v9; // eax
  float *v10; // esi
  float v11; // xmm0_4
  char v12; // dl
  char v13; // [esp+Bh] [ebp-1h]

  v2 = Sim::getCar(this->sim, 0);
  v3 = RaceManager::getLapCount(this->sim->raceManager, v2);
  v13 = 0;
  v4 = Sim::getCar(this->sim, 0);
  if ( !CarAvatar::isInPitlane(v4) )
  {
    v5 = this->sim;
    v6 = 1;
    if ( (unsigned int)(v5->cars._Mylast - v5->cars._Myfirst) <= 1 )
      goto LABEL_13;
    do
    {
      v7 = Sim::getCar(v5, v6);
      if ( !CarAvatar::isConnected(v7) )
        goto LABEL_10;
      v8 = Sim::getCar(this->sim, v6);
      if ( RaceManager::getLapCount(this->sim->raceManager, v8) <= v3 )
        goto LABEL_10;
      v9 = Sim::getCar(this->sim, v6);
      if ( CarAvatar::isInPitlane(v9) )
        goto LABEL_10;
      v10 = &Sim::getCar(this->sim, 0)->physicsState.normalizedSplinePosition;
      v11 = *v10 - Sim::getCar(this->sim, v6)->physicsState.normalizedSplinePosition;
      if ( v11 < 0.0 )
        v11 = v11 + 1.0;
      if ( (float)(this->track->info.length * v11) > 100.0 )
      {
LABEL_10:
        v12 = v13;
      }
      else
      {
        FlagManager::setBlueFlag(this, v6);
        v12 = 1;
        v13 = 1;
      }
      v5 = this->sim;
      ++v6;
    }
    while ( v6 < v5->cars._Mylast - v5->cars._Myfirst );
    if ( !v12 )
    {
LABEL_13:
      if ( this->currentFlag == eBlueFlag )
        FlagManager::clearFlag(this);
    }
  }
}
void FlagManager::checkForYellow(FlagManager *this)
{
  unsigned int v2; // esi
  CarAvatar *v3; // eax
  float *v4; // esi
  CarAvatar *v5; // eax
  float v6; // xmm0_4
  int v7; // esi
  CarAvatar *v8; // eax
  int v9; // ecx
  int v10; // eax
  Sim *v11; // ecx
  CarAvatar *v12; // eax
  int v13; // ecx
  CarAvatar *v14; // eax
  char v15; // al
  CarAvatar *v16; // eax
  CarAvatar *v17; // eax
  float *v18; // esi
  CarAvatar *v19; // eax
  char v20; // cl
  float *v21; // esi
  CarAvatar *v22; // eax
  Sim *v23; // ecx
  FlagType v24; // eax
  OnGearRequestEvent message; // [esp+8h] [ebp-90h] BYREF
  char v26; // [esp+10h] [ebp-88h]
  vec3f v27; // [esp+14h] [ebp-84h] BYREF
  int v28; // [esp+20h] [ebp-78h]
  long double v29; // [esp+24h] [ebp-74h]
  int v30; // [esp+2Ch] [ebp-6Ch]
  unsigned int index; // [esp+30h] [ebp-68h]
  Session result; // [esp+34h] [ebp-64h] BYREF

  LOBYTE(v30) = 0;
  v2 = 1;
  index = 1;
  if ( (unsigned int)(this->sim->cars._Mylast - this->sim->cars._Myfirst) <= 1 )
    goto LABEL_34;
  do
  {
    v3 = Sim::getCar(this->sim, v2);
    if ( !CarAvatar::isConnected(v3) )
      goto LABEL_29;
    v4 = &Sim::getCar(this->sim, v2)->physicsState.normalizedSplinePosition;
    v5 = Sim::getCar(this->sim, 0);
    v6 = *v4;
    v7 = 0;
    v28 = 0;
    *((float *)&v29 + 1) = this->track->info.length * (float)(v6 - v5->physicsState.normalizedSplinePosition);
    do
    {
      v8 = Sim::getCar(this->sim, index);
      v9 = v28;
      if ( !v8->physicsState.tyreSurfaceDef[v7].isValidTrack )
        v9 = ++v28;
      ++v7;
    }
    while ( v7 < 4 );
    if ( this->yellowFlagDistance > *((float *)&v29 + 1) )
    {
      v2 = index;
      if ( *((float *)&v29 + 1) <= 0.0 )
        goto LABEL_29;
      v10 = (unsigned __int8)v30;
      if ( v9 == 4 )
        v10 = 1;
      v11 = this->sim;
      HIDWORD(v29) = v10;
      v12 = Sim::getCar(v11, index);
      v13 = BYTE4(v29);
      if ( !v12->physicsState.gear )
        v13 = 1;
      v30 = v13;
      v29 = this->sim->game->gameTime.now - RaceManager::getCurrentSession(this->sim->raceManager, &result)->startTime;
      if ( result.name._Myres >= 8 )
        operator delete(result.name._Bx._Ptr);
      result.name._Myres = 7;
      result.name._Mysize = 0;
      result.name._Bx._Buf[0] = 0;
      if ( result.spawSet._Myres >= 8 )
        operator delete(result.spawSet._Bx._Ptr);
      if ( (float)(Sim::getCar(this->sim, v2)->physicsState.speed.value * 3.5999999) < 15.0 )
      {
        v14 = Sim::getCar(this->sim, v2);
        if ( !CarAvatar::isInPitlane(v14) && RaceManager::hasSessionStarted(this->sim->raceManager) )
        {
          v15 = v30;
          if ( v29 > 5000.0 )
            v15 = 1;
          LOBYTE(v30) = v15;
        }
      }
      v16 = Sim::getCar(this->sim, v2);
      CarAvatar::getRoadDirection(v16, &v27);
      v17 = Sim::getCar(this->sim, v2);
      if ( (float)((float)((float)(v27.y * COERCE_FLOAT(LODWORD(v17->physicsState.worldMatrix.M32) ^ _xmm))
                         + (float)(v27.x * COERCE_FLOAT(LODWORD(v17->physicsState.worldMatrix.M31) ^ _xmm)))
                 + (float)(v27.z * COERCE_FLOAT(LODWORD(v17->physicsState.worldMatrix.M33) ^ _xmm))) > 0.40000001 )
      {
        v18 = this->lastPositionOnSpline._Myfirst;
        v19 = Sim::getCar(this->sim, index);
        v20 = v30;
        if ( v18[index] > v19->physicsState.normalizedSplinePosition )
          v20 = 1;
        LOBYTE(v30) = v20;
      }
      v21 = this->lastPositionOnSpline._Myfirst;
      v22 = Sim::getCar(this->sim, index);
      v21[index] = v22->physicsState.normalizedSplinePosition;
    }
    v2 = index;
LABEL_29:
    v23 = this->sim;
    index = ++v2;
  }
  while ( v2 < v23->cars._Mylast - v23->cars._Myfirst );
  if ( (_BYTE)v30 )
  {
    v29 = 16777220.08984375;
    v27.x = 15.0;
    message.request = eNoGearRequest;
    v26 = 0;
    v27.y = 15.0;
    v27.z = 0.0;
    message.nextGear = (int)Sim::getCar(v23, 0);
    v24 = this->currentFlag;
    message.request = 4;
    v26 = 1;
    if ( v24 != eBlackFlag && v24 != eCheckeredFlag )
    {
      this->currentFlag = eYellowFlag;
      this->timer = 5.0;
      Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&this->evOnFlagChange, &message);
    }
    return;
  }
LABEL_34:
  if ( this->currentFlag == eYellowFlag )
    FlagManager::clearFlag(this);
}
void FlagManager::checkforPenalty(FlagManager *this)
{
  CarAvatar *v2; // eax
  long double v3; // st7
  Sim *v4; // ecx
  OnGearRequestEvent message; // [esp+Ch] [ebp-18h] BYREF
  char v6; // [esp+14h] [ebp-10h]
  int v7; // [esp+18h] [ebp-Ch]
  int v8; // [esp+1Ch] [ebp-8h]
  int v9; // [esp+20h] [ebp-4h]

  if ( this->currentFlag != eBlackFlag )
  {
    v2 = Sim::getCar(this->sim, 0);
    v3 = CarAvatar::hasPenalty(v2);
    v4 = this->sim;
    if ( v3 > 0.0 )
    {
LABEL_3:
      v7 = 1097859072;
      v9 = 0;
      v8 = 1097859072;
      message.nextGear = (int)Sim::getCar(v4, 0);
      message.request = 6;
      v6 = 1;
      this->currentFlag = ePenaltyFlag;
      Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&this->evOnFlagChange, &message);
      return;
    }
    if ( Sim::getCar(v4, 0)->physics->penaltyManager.pitPenaltyLaps > 0 )
    {
      v4 = this->sim;
      goto LABEL_3;
    }
    if ( this->currentFlag == ePenaltyFlag )
      FlagManager::setFlag(this, eNoFlag);
  }
}
void FlagManager::clearFlag(FlagManager *this)
{
  Sim *v2; // ecx
  CarAvatar *v3; // eax
  std::pair<void *,std::function<void __cdecl(FlagTriggered const &)> > *v4; // esi
  std::_Func_base<void,FlagTriggered const &> **v5; // edi
  FlagTriggered ev; // [esp+14h] [ebp-18h] BYREF

  ev.flagPosition.x = 15.0;
  v2 = this->sim;
  ev.flag = eNoFlag;
  ev.carAvatar = 0;
  ev.isActive = 0;
  ev.flagPosition.y = 15.0;
  ev.flagWidth = 0.0;
  v3 = Sim::getCar(v2, 0);
  v4 = this->evOnFlagChange.handlers._Myfirst;
  ev.carAvatar = v3;
  ev.flag = eNoFlag;
  ev.isActive = 0;
  if ( v4 != this->evOnFlagChange.handlers._Mylast )
  {
    v5 = &v4->second._Impl;
    do
    {
      if ( !*v5 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x595B76);
      }
      (*v5)->_Do_call(*v5, &ev);
      ++v4;
      v5 += 8;
    }
    while ( v4 != this->evOnFlagChange.handlers._Mylast );
  }
  this->timer = -1.0;
  this->currentFlag = eNoFlag;
}
FlagType FlagManager::getCurrentFlag(FlagManager *this)
{
  return this->currentFlag;
}
void FlagManager::setBlueFlag(FlagManager *this, int carIndex)
{
  Sim *v3; // ecx
  FlagType v4; // eax
  FlagTriggered ev; // [esp+Ch] [ebp-18h] BYREF

  ev.flagPosition.x = 15.0;
  v3 = this->sim;
  ev.flag = eNoFlag;
  ev.isActive = 0;
  ev.flagPosition.y = 15.0;
  ev.flagWidth = 0.0;
  ev.carAvatar = Sim::getCar(v3, 0);
  v4 = this->currentFlag;
  ev.flag = eBlueFlag;
  ev.isActive = 1;
  if ( v4 != eBlueFlag && v4 != eYellowFlag && v4 != eBlackFlag )
  {
    this->currentFlag = eBlueFlag;
    Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&this->evOnFlagChange, (const OnGearRequestEvent *)&ev);
  }
}
void FlagManager::setFlag(FlagManager *this, FlagType flag)
{
  Sim *v3; // ecx
  FlagType v4; // eax
  FlagTriggered ev; // [esp+Ch] [ebp-18h] BYREF

  ev.flagPosition.x = 15.0;
  v3 = this->sim;
  ev.flagPosition.y = 15.0;
  ev.flagWidth = 0.0;
  ev.carAvatar = Sim::getCar(v3, 0);
  ev.flag = flag;
  ev.isActive = 1;
  switch ( flag )
  {
    case eNoFlag:
      this->currentFlag = eNoFlag;
      ev.isActive = 0;
      Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&this->evOnFlagChange, (const OnGearRequestEvent *)&ev);
      break;
    case eBlackFlag:
      if ( this->timer <= 0.0 || this->currentFlag != eBlackFlag )
      {
        this->currentFlag = eBlackFlag;
        Event<std::wstring>::trigger(
          (Event<OnGearRequestEvent> *)&this->evOnFlagChange,
          (const OnGearRequestEvent *)&ev);
      }
      break;
    case eCheckeredFlag:
      this->currentFlag = eCheckeredFlag;
      this->timer = -1.0;
      Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&this->evOnFlagChange, (const OnGearRequestEvent *)&ev);
      break;
    case eYellowFlag:
      v4 = this->currentFlag;
      if ( v4 != eBlackFlag && v4 != eCheckeredFlag )
      {
        this->currentFlag = eYellowFlag;
        this->timer = 5.0;
        Event<std::wstring>::trigger(
          (Event<OnGearRequestEvent> *)&this->evOnFlagChange,
          (const OnGearRequestEvent *)&ev);
      }
      break;
    case ePenaltyFlag:
      this->currentFlag = ePenaltyFlag;
      Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&this->evOnFlagChange, (const OnGearRequestEvent *)&ev);
      break;
    default:
      return;
  }
}
void FlagManager::update(FlagManager *this, float deltaT)
{
  Sim *v3; // ecx
  CarAvatar *v4; // eax
  int v5; // esi
  EndSessionDisplayer *v6; // eax
  ksgui::Label *v7; // ecx
  Sim *v8; // ecx
  EndSessionDisplayer *v9; // eax
  CarAvatar *v10; // eax
  int v11; // esi
  EndSessionDisplayer *v12; // eax
  EndSessionDisplayer *v13; // eax
  __int32 v14; // eax
  Sim *v15; // ecx
  EndSessionDisplayer *v16; // eax
  OnGearRequestEvent message; // [esp+Ch] [ebp-18h] BYREF
  char v18; // [esp+14h] [ebp-10h]
  int v19; // [esp+18h] [ebp-Ch]
  int v20; // [esp+1Ch] [ebp-8h]
  int v21; // [esp+20h] [ebp-4h]

  ksgui::Control::setVisible(this->controlBlue, 0);
  ksgui::Control::setVisible(this->controlBlack, 0);
  ksgui::Control::setVisible(this->controlYellow, 0);
  ksgui::Control::setVisible(this->controlPenalty, 0);
  ksgui::Control::setVisible(this->controlChequered, 0);
  ksgui::Control::setVisible(this->blackFlagCaption, 0);
  if ( !ReplayManager::isInReplaymode(this->sim->replayManager) )
  {
    v3 = this->sim;
    if ( !v3->pauseMenu->visible && !v3->escMenu->visible )
    {
      v4 = Sim::getCar(v3, 0);
      v5 = CarAvatar::getGuid(v4);
      if ( Sim::getFocusedCarIndex(this->sim) == v5 )
      {
        if ( RaceManager::getCurrentSessionType(this->sim->raceManager) == Race )
          FlagManager::checkForBlue(this);
        if ( this->yellowFlagDistance != 0.0 && RaceManager::getCurrentSessionType(this->sim->raceManager) != Drag )
          FlagManager::checkForYellow(this);
        FlagManager::checkforPenalty(this);
        switch ( this->currentFlag )
        {
          case eBlueFlag:
            if ( !RaceManager::isRaceOver(this->sim->raceManager, 0) )
            {
              v6 = this->sim->endSessionDisplayer;
              if ( !v6 || !v6->isActive )
              {
                v7 = (ksgui::Label *)this->controlBlue;
                goto LABEL_29;
              }
            }
            break;
          case eBlackFlag:
            if ( !RaceManager::isRaceOver(this->sim->raceManager, 0) )
            {
              v8 = this->sim;
              v9 = v8->endSessionDisplayer;
              if ( !v9 || !v9->isActive )
              {
                v10 = Sim::getCar(v8, 0);
                v11 = CarAvatar::getGuid(v10);
                if ( Sim::getFocusedCarIndex(this->sim) == v11 )
                {
                  ksgui::Control::setVisible(this->controlBlack, 1);
                  v7 = this->blackFlagCaption;
                  goto LABEL_29;
                }
              }
            }
            break;
          case eYellowFlag:
            if ( !RaceManager::isRaceOver(this->sim->raceManager, 0) )
            {
              v12 = this->sim->endSessionDisplayer;
              if ( (!v12 || !v12->isActive) && this->timer > 0.0 )
              {
                v7 = (ksgui::Label *)this->controlYellow;
                goto LABEL_29;
              }
            }
            break;
          case ePenaltyFlag:
            if ( !RaceManager::isRaceOver(this->sim->raceManager, 0) )
            {
              v13 = this->sim->endSessionDisplayer;
              if ( !v13 || !v13->isActive )
              {
                v7 = (ksgui::Label *)this->controlPenalty;
LABEL_29:
                ksgui::Control::setVisible(v7, 1);
              }
            }
            break;
          default:
            break;
        }
        v14 = RaceManager::getCurrentSessionType(this->sim->raceManager) - 2;
        if ( v14 )
        {
          if ( v14 != 1 )
            goto LABEL_39;
          if ( !RaceManager::isRaceOver(this->sim->raceManager, 0) )
            goto LABEL_39;
          v15 = this->sim;
          v16 = v15->endSessionDisplayer;
          if ( v16 )
          {
            if ( v16->isActive )
              goto LABEL_39;
          }
        }
        else
        {
          if ( RaceManager::getSessionTimeLeft(this->sim->raceManager) >= 0.0 )
          {
LABEL_39:
            this->timer = this->timer - deltaT;
            return;
          }
          v15 = this->sim;
        }
        v19 = 1097859072;
        v20 = 1097859072;
        v21 = 0;
        message.nextGear = (int)Sim::getCar(v15, 0);
        message.request = eChangeToGear;
        v18 = 1;
        this->currentFlag = eCheckeredFlag;
        this->timer = -1.0;
        Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&this->evOnFlagChange, &message);
        ksgui::Control::setVisible(this->controlChequered, 1);
        goto LABEL_39;
      }
    }
  }
}
