#include "pausemenu.h"
void PauseMenu::PauseMenu(PauseMenu *this, Sim *isim, ksgui::GUI *gui)
{
  double v4; // st7
  bool v5; // cf
  std::_Ref_count_base *v6; // eax
  Font *v7; // eax
  std::_Ref_count_base *v8; // edx
  std::_Ref_count_base *v9; // ecx
  ksgui::GUI *v10; // edi
  Texture *v11; // eax
  unsigned int v12; // eax
  float v13; // xmm0_4
  int *v14; // eax
  int *v15; // edi
  std::_Ref_count_base *v16; // ecx
  std::_Ref_count_base *v17; // eax
  std::_Ref_count_base *v18; // edx
  std::_Ref_count_base *v19; // ecx
  float v20; // xmm0_4
  int v21; // eax
  std::_Ref_count_base *v22; // edi
  int *v23; // eax
  int *v24; // edi
  std::_Ref_count_base *v25; // ecx
  Font *v26; // eax
  std::_Ref_count_base *v27; // edx
  std::_Ref_count_base *v28; // ecx
  float v29; // xmm0_4
  int v30; // eax
  RaceManager *v31; // ecx
  std::_Ref_count_base *v32; // edi
  int *v33; // eax
  int *v34; // edi
  float v35; // xmm0_4
  int v36; // eax
  float v37; // xmm1_4
  float v38; // xmm0_4
  std::_Ref_count_base *v39; // edi
  int *v40; // eax
  int *v41; // edi
  std::_Ref_count_base *v42; // ecx
  Font *v43; // eax
  std::_Ref_count_base *v44; // edx
  std::_Ref_count_base *v45; // edx
  float v46; // xmm0_4
  int v47; // eax
  std::_Ref_count_base *v48; // edi
  int *v49; // eax
  int *v50; // edi
  float v51; // xmm0_4
  int v52; // eax
  ReplayManager *v53; // eax
  std::_Ref_count_base *v54; // edi
  int *v55; // eax
  int *v56; // edi
  float v57; // xmm0_4
  int v58; // eax
  _BYTE v59[56]; // [esp+28h] [ebp-FCh] BYREF
  PauseMenu *v60; // [esp+68h] [ebp-BCh]
  ksgui::GUI *v61; // [esp+6Ch] [ebp-B8h]
  std::_Ref_count_base *v62; // [esp+70h] [ebp-B4h]
  ksgui::ActiveButton *v63; // [esp+74h] [ebp-B0h] BYREF
  float top; // [esp+78h] [ebp-ACh]
  std::shared_ptr<Font> _Right; // [esp+7Ch] [ebp-A8h] BYREF
  INIReader v66; // [esp+84h] [ebp-A0h] BYREF
  std::wstring ifilename; // [esp+C8h] [ebp-5Ch] BYREF
  Texture result; // [esp+E0h] [ebp-44h] BYREF
  std::wstring key; // [esp+FCh] [ebp-28h] BYREF
  int v70; // [esp+120h] [ebp-4h]

  v60 = this;
  v61 = gui;
  result.fileName._Myres = 7;
  result.fileName._Mysize = 0;
  result.fileName._Bx._Buf[0] = 0;
  std::wstring::assign(&result.fileName, L"PAUSE_MENU", 0xAu);
  v70 = 0;
  ksgui::Control::Control(this, &result.fileName, gui);
  if ( result.fileName._Myres >= 8 )
    operator delete(result.fileName._Bx._Ptr);
  this->sim = isim;
  this->__vftable = (PauseMenu_vtbl *)&PauseMenu::`vftable';
  this->acLogo.kid = 0;
  this->acLogo.fileName._Myres = 7;
  this->acLogo.fileName._Mysize = 0;
  this->acLogo.fileName._Bx._Buf[0] = 0;
  LOBYTE(v70) = 3;
  Trigger::Trigger(&this->upKey);
  LOBYTE(v70) = 4;
  Trigger::Trigger(&this->dwKey);
  LOBYTE(v70) = 5;
  Trigger::Trigger(&this->enterKey);
  this->buttons._Myfirst = 0;
  this->buttons._Mylast = 0;
  this->buttons._Myend = 0;
  *(_DWORD *)&v59[24] = 20;
  LOBYTE(v70) = 7;
  *(_DWORD *)&v59[20] = L"system/cfg/fades.ini";
  this->fadeSeconds = 0.0;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, *(const wchar_t **)&v59[20], *(unsigned int *)&v59[24]);
  LOBYTE(v70) = 8;
  INIReader::INIReader(&v66, &ifilename);
  LOBYTE(v70) = 10;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( v66.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MS", 2u);
    LOBYTE(v70) = 11;
    result.fileName._Myres = 7;
    result.fileName._Mysize = 0;
    result.fileName._Bx._Buf[0] = 0;
    std::wstring::assign(&result.fileName, L"FADE", 4u);
    LOBYTE(v70) = 12;
    v4 = INIReader::getFloat(&v66, &result.fileName, &key);
    v5 = result.fileName._Myres < 8;
    this->fadeSeconds = v4 * 0.001;
    if ( !v5 )
      operator delete(result.fileName._Bx._Ptr);
    result.fileName._Myres = 7;
    result.fileName._Mysize = 0;
    result.fileName._Bx._Buf[0] = 0;
    LOBYTE(v70) = 10;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  *(_DWORD *)&v59[24] = 24;
  this->currentlySelectedButton = 0;
  v6 = (std::_Ref_count_base *)operator new(*(_DWORD *)&v59[24]);
  _Right._Rep = v6;
  LOBYTE(v70) = 13;
  if ( v6 )
    Font::Font((Font *)v6, eFontProportional, 22.0, 0, 0);
  else
    v7 = 0;
  LOBYTE(v70) = 10;
  _Right._Ptr = 0;
  _Right._Rep = 0;
  std::shared_ptr<Font>::_Resetp<Font>(&_Right, v7);
  std::shared_ptr<Font>::operator=(&this->font, &_Right);
  v8 = _Right._Rep;
  if ( _Right._Rep )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Uses, 0xFFFFFFFF) )
    {
      v8->_Destroy(v8);
      v9 = _Right._Rep;
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Weaks, 0xFFFFFFFF) )
        v9->_Delete_this(v9);
    }
  }
  ksgui::Control::setSize(this, 400.0, 400.0);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"content/gui/pauseMenuLogo.png", 0x1Du);
  v10 = v61;
  LOBYTE(v70) = 14;
  v11 = ResourceStore::getTexture(v61->graphics->resourceStore._Myptr, &result, &key, 0);
  this->acLogo.kid = v11->kid;
  LOBYTE(v70) = 15;
  if ( &this->acLogo.fileName != &v11->fileName )
    std::wstring::assign(&this->acLogo.fileName, &v11->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v70) = 14;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v70) = 10;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( this->acLogo.kid )
    v12 = kglTextureGetHeight(this->acLogo.kid);
  else
    v12 = 0;
  *(_DWORD *)&v59[24] = 448;
  v13 = (float)v12;
  top = (float)(v13 * 0.5) + 2.0;
  this->backColor = (vec4f)_xmm;
  this->borderColor = (vec4f)_xmm;
  v63 = (ksgui::ActiveButton *)operator new(*(_DWORD *)&v59[24]);
  LOBYTE(v70) = 16;
  if ( v63 )
  {
    *(_DWORD *)&v59[24] = v10;
    *(_DWORD *)&v59[20] = 7;
    *(_DWORD *)&v59[16] = 0;
    *(_WORD *)v59 = 0;
    std::wstring::assign((std::wstring *)v59, L"RESUME", 6u);
    ksgui::ActiveButton::ActiveButton(v63, *(std::wstring *)v59, *(ksgui::GUI **)&v59[24]);
    v15 = v14;
  }
  else
  {
    v15 = 0;
  }
  LOBYTE(v70) = 10;
  v63 = (ksgui::ActiveButton *)v15;
  ksgui::Control::addControl(this, (ksgui::Control *)v15);
  *((_WORD *)v15 + 100) = 0;
  v16 = this->font._Rep;
  v17 = (std::_Ref_count_base *)this->font._Ptr;
  v62 = v16;
  _Right._Rep = v17;
  if ( v16 )
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)&v16->_Uses, 1u);
    v16 = v62;
    v17 = _Right._Rep;
  }
  v18 = (std::_Ref_count_base *)v15[33];
  v15[33] = (int)v16;
  _Right._Rep = v18;
  v15[32] = (int)v17;
  if ( v18 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v18->_Uses, 0xFFFFFFFF) )
    {
      v18->_Destroy(v18);
      v19 = _Right._Rep;
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Weaks, 0xFFFFFFFF) )
        v19->_Delete_this(v19);
    }
  }
  *((_OWORD *)v15 + 18) = 0i64;
  *((_OWORD *)v15 + 20) = _xmm;
  *(_DWORD *)&v59[24] = 1110704128;
  *((_OWORD *)v15 + 19) = _xmm;
  (*(void (**)(int *, int, _DWORD))(*v15 + 28))(v15, 1137180672, *(_DWORD *)&v59[24]);
  _Right._Ptr = (Font *)v15[70];
  v20 = top;
  v15[70] = (int)_Right._Ptr;
  _Right._Rep = (std::_Ref_count_base *)1088421888;
  *(float *)&v59[24] = v20;
  v15[71] = 1088421888;
  ksgui::Form::setPosition((ksgui::Form *)v15, 0.0, *(float *)&v59[24]);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"Resume", 6u);
  LOBYTE(v70) = 17;
  *(_DWORD *)&v59[24] = acTranslate(&result.fileName, &key);
  v21 = *v15;
  LOBYTE(v70) = 18;
  (*(void (**)(int *, _DWORD))(v21 + 68))(v15, *(_DWORD *)&v59[24]);
  if ( result.fileName._Myres >= 8 )
    operator delete(result.fileName._Bx._Ptr);
  result.fileName._Myres = 7;
  result.fileName._Mysize = 0;
  result.fileName._Bx._Buf[0] = 0;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  *(_DWORD *)v59 = &std::_Func_impl<std::_Callable_obj<_lambda_511ee02b74ce79c4088195d898f4f668_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v59[4] = this;
  *(_DWORD *)&v59[16] = v59;
  LOBYTE(v70) = 10;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)v15 + 13,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)v59,
    this);
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->buttons, (int *)&v63);
  top = top + 45.0;
  v22 = (std::_Ref_count_base *)operator new(448);
  _Right._Rep = v22;
  LOBYTE(v70) = 20;
  if ( v22 )
  {
    *(_DWORD *)&v59[24] = v61;
    *(_DWORD *)&v59[20] = 7;
    *(_DWORD *)&v59[16] = 0;
    *(_WORD *)v59 = 0;
    std::wstring::assign((std::wstring *)v59, L"PITS", 4u);
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v22, *(std::wstring *)v59, *(ksgui::GUI **)&v59[24]);
    v24 = v23;
  }
  else
  {
    v24 = 0;
  }
  LOBYTE(v70) = 10;
  v63 = (ksgui::ActiveButton *)v24;
  ksgui::Control::addControl(this, (ksgui::Control *)v24);
  *((_WORD *)v24 + 100) = 0;
  v25 = this->font._Rep;
  v26 = this->font._Ptr;
  _Right._Rep = v25;
  v62 = (std::_Ref_count_base *)v26;
  if ( v25 )
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)&v25->_Uses, 1u);
    v25 = _Right._Rep;
    v26 = (Font *)v62;
  }
  v27 = (std::_Ref_count_base *)v24[33];
  v24[33] = (int)v25;
  _Right._Rep = v27;
  v24[32] = (int)v26;
  if ( v27 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v27->_Uses, 0xFFFFFFFF) )
    {
      v27->_Destroy(v27);
      v28 = _Right._Rep;
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&_Right._Rep->_Weaks, 0xFFFFFFFF) )
        v28->_Delete_this(v28);
    }
  }
  *((_OWORD *)v24 + 18) = 0i64;
  *((_OWORD *)v24 + 20) = _xmm;
  *(_DWORD *)&v59[24] = 1110704128;
  *((_OWORD *)v24 + 19) = _xmm;
  (*(void (**)(int *, int, _DWORD))(*v24 + 28))(v24, 1137180672, *(_DWORD *)&v59[24]);
  _Right._Ptr = (Font *)v24[70];
  v29 = top;
  v24[70] = (int)_Right._Ptr;
  _Right._Rep = (std::_Ref_count_base *)1088421888;
  *(float *)&v59[24] = v29;
  v24[71] = 1088421888;
  ksgui::Form::setPosition((ksgui::Form *)v24, 0.0, *(float *)&v59[24]);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"Back to pits", 0xCu);
  LOBYTE(v70) = 21;
  *(_DWORD *)&v59[24] = acTranslate(&result.fileName, &key);
  v30 = *v24;
  LOBYTE(v70) = 22;
  (*(void (**)(int *, _DWORD))(v30 + 68))(v24, *(_DWORD *)&v59[24]);
  if ( result.fileName._Myres >= 8 )
    operator delete(result.fileName._Bx._Ptr);
  result.fileName._Myres = 7;
  result.fileName._Mysize = 0;
  result.fileName._Bx._Buf[0] = 0;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  *(_DWORD *)v59 = &std::_Func_impl<std::_Callable_obj<_lambda_b11faf5d0607572a20e6fb0f5cdb1513_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v59[4] = this;
  *(_DWORD *)&v59[16] = v59;
  LOBYTE(v70) = 10;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)v24 + 13,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)v59,
    this);
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->buttons, (int *)&v63);
  v31 = this->sim->raceManager;
  top = top + 45.0;
  if ( (unsigned int)RaceManager::getSessionCount(v31) <= 1
    || RaceManager::getCurrentSessionType(this->sim->raceManager) == Race
    || this->sim->client )
  {
    v38 = top;
    v37 = FLOAT_45_0;
  }
  else
  {
    v32 = (std::_Ref_count_base *)operator new(448);
    _Right._Rep = v32;
    LOBYTE(v70) = 24;
    if ( v32 )
    {
      *(_DWORD *)&v59[24] = v61;
      std::wstring::wstring((std::wstring *)v59, L"SKIP");
      ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v32, *(std::wstring *)v59, *(ksgui::GUI **)&v59[24]);
      v34 = v33;
    }
    else
    {
      v34 = 0;
    }
    LOBYTE(v70) = 10;
    v63 = (ksgui::ActiveButton *)v34;
    ksgui::Control::addControl(this, (ksgui::Control *)v34);
    *((_WORD *)v34 + 100) = 0;
    std::shared_ptr<Font>::operator=((std::shared_ptr<Font> *)v34 + 16, &this->font);
    *((_OWORD *)v34 + 18) = 0i64;
    *((_OWORD *)v34 + 20) = _xmm;
    *(_DWORD *)&v59[24] = 1110704128;
    *((_OWORD *)v34 + 19) = _xmm;
    (*(void (**)(int *, int, _DWORD))(*v34 + 28))(v34, 1137180672, *(_DWORD *)&v59[24]);
    _Right._Ptr = (Font *)v34[70];
    v35 = top;
    v34[70] = (int)_Right._Ptr;
    _Right._Rep = (std::_Ref_count_base *)1088421888;
    *(float *)&v59[24] = v35;
    v34[71] = 1088421888;
    ksgui::Form::setPosition((ksgui::Form *)v34, 0.0, *(float *)&v59[24]);
    std::wstring::wstring(&result.fileName, L"Skip session");
    LOBYTE(v70) = 25;
    *(_DWORD *)&v59[24] = acTranslate(&key, &result.fileName);
    v36 = *v34;
    LOBYTE(v70) = 26;
    (*(void (**)(int *, _DWORD))(v36 + 68))(v34, *(_DWORD *)&v59[24]);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( result.fileName._Myres >= 8 )
      operator delete(result.fileName._Bx._Ptr);
    *(_DWORD *)v59 = &std::_Func_impl<std::_Callable_obj<_lambda_48727aab0716447e29a81130a76093da_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
    *(_DWORD *)&v59[4] = this;
    *(_DWORD *)&v59[16] = v59;
    LOBYTE(v70) = 10;
    Event<ksgui::OnControlClicked>::addHandler(
      (Event<OnMouseWheelMovedEvent> *)v34 + 13,
      *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)v59,
      this);
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->buttons, (int *)&v63);
    v37 = FLOAT_45_0;
    v38 = top + 45.0;
    top = top + 45.0;
  }
  if ( !this->sim->client )
  {
    v39 = (std::_Ref_count_base *)operator new(448);
    _Right._Rep = v39;
    LOBYTE(v70) = 28;
    if ( v39 )
    {
      *(_DWORD *)&v59[24] = v61;
      std::wstring::wstring((std::wstring *)v59, L"RESTART");
      ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v39, *(std::wstring *)v59, *(ksgui::GUI **)&v59[24]);
      v41 = v40;
    }
    else
    {
      v41 = 0;
    }
    LOBYTE(v70) = 10;
    v63 = (ksgui::ActiveButton *)v41;
    ksgui::Control::addControl(this, (ksgui::Control *)v41);
    *((_WORD *)v41 + 100) = 0;
    v42 = this->font._Rep;
    v43 = this->font._Ptr;
    _Right._Rep = v42;
    v62 = (std::_Ref_count_base *)v43;
    if ( v42 )
    {
      _InterlockedExchangeAdd((volatile signed __int32 *)&v42->_Uses, 1u);
      v42 = _Right._Rep;
      v43 = (Font *)v62;
    }
    v44 = (std::_Ref_count_base *)v41[33];
    v41[33] = (int)v42;
    _Right._Rep = v44;
    v41[32] = (int)v43;
    if ( v44 )
    {
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v44->_Uses, 0xFFFFFFFF) )
      {
        v44->_Destroy(v44);
        v45 = _Right._Rep;
        if ( !_InterlockedDecrement((volatile signed __int32 *)&_Right._Rep->_Weaks) )
          v45->_Delete_this(v45);
      }
    }
    *((_OWORD *)v41 + 18) = 0i64;
    *((_OWORD *)v41 + 20) = _xmm;
    *(_DWORD *)&v59[24] = 1110704128;
    *((_OWORD *)v41 + 19) = _xmm;
    (*(void (**)(int *, int, _DWORD))(*v41 + 28))(v41, 1137180672, *(_DWORD *)&v59[24]);
    _Right._Ptr = (Font *)v41[70];
    v46 = top;
    v41[70] = (int)_Right._Ptr;
    _Right._Rep = (std::_Ref_count_base *)1088421888;
    *(float *)&v59[24] = v46;
    v41[71] = 1088421888;
    ksgui::Form::setPosition((ksgui::Form *)v41, 0.0, *(float *)&v59[24]);
    std::wstring::wstring(&result.fileName, L"Restart Session");
    LOBYTE(v70) = 29;
    *(_DWORD *)&v59[24] = acTranslate(&key, &result.fileName);
    v47 = *v41;
    LOBYTE(v70) = 30;
    (*(void (**)(int *, _DWORD))(v47 + 68))(v41, *(_DWORD *)&v59[24]);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( result.fileName._Myres >= 8 )
      operator delete(result.fileName._Bx._Ptr);
    *(_DWORD *)v59 = &std::_Func_impl<std::_Callable_obj<_lambda_6693c32658a69fae21ad9f626de8784b_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
    *(_DWORD *)&v59[4] = this;
    *(_DWORD *)&v59[16] = v59;
    LOBYTE(v70) = 10;
    Event<ksgui::OnControlClicked>::addHandler(
      (Event<OnMouseWheelMovedEvent> *)v41 + 13,
      *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)v59,
      this);
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->buttons, (int *)&v63);
    top = top + 45.0;
    v48 = (std::_Ref_count_base *)operator new(448);
    _Right._Rep = v48;
    LOBYTE(v70) = 32;
    if ( v48 )
    {
      *(_DWORD *)&v59[24] = v61;
      std::wstring::wstring((std::wstring *)v59, L"REPLAY");
      ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v48, *(std::wstring *)v59, *(ksgui::GUI **)&v59[24]);
      v50 = v49;
    }
    else
    {
      v50 = 0;
    }
    LOBYTE(v70) = 10;
    v63 = (ksgui::ActiveButton *)v50;
    ksgui::Control::addControl(this, (ksgui::Control *)v50);
    *((_WORD *)v50 + 100) = 0;
    std::shared_ptr<Font>::operator=((std::shared_ptr<Font> *)v50 + 16, &this->font);
    *((_OWORD *)v50 + 18) = 0i64;
    *((_OWORD *)v50 + 20) = _xmm;
    *(_DWORD *)&v59[24] = 1110704128;
    *((_OWORD *)v50 + 19) = _xmm;
    (*(void (**)(int *, int, _DWORD))(*v50 + 28))(v50, 1137180672, *(_DWORD *)&v59[24]);
    _Right._Ptr = (Font *)v50[70];
    v51 = top;
    v50[70] = (int)_Right._Ptr;
    _Right._Rep = (std::_Ref_count_base *)1088421888;
    *(float *)&v59[24] = v51;
    v50[71] = 1088421888;
    ksgui::Form::setPosition((ksgui::Form *)v50, 0.0, *(float *)&v59[24]);
    std::wstring::wstring(&result.fileName, L"Replay");
    LOBYTE(v70) = 33;
    *(_DWORD *)&v59[24] = acTranslate(&key, &result.fileName);
    v52 = *v50;
    LOBYTE(v70) = 34;
    (*(void (**)(int *, _DWORD))(v52 + 68))(v50, *(_DWORD *)&v59[24]);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v70) = 10;
    if ( result.fileName._Myres >= 8 )
      operator delete(result.fileName._Bx._Ptr);
    std::wstring::wstring((std::wstring *)&v59[4], L"REPLAY_MANAGER");
    v53 = (ReplayManager *)GameObject::getGameObject(this->sim, *(std::wstring *)&v59[4]);
    *(_DWORD *)&v59[24] = this;
    this->rpMng = v53;
    *(_DWORD *)v59 = &std::_Func_impl<std::_Callable_obj<_lambda_6ae1d60a7d9f21e65a828edce0fd6489_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
    *(_DWORD *)&v59[4] = this;
    *(_DWORD *)&v59[16] = v59;
    LOBYTE(v70) = 10;
    Event<ksgui::OnControlClicked>::addHandler(
      (Event<OnMouseWheelMovedEvent> *)v50 + 13,
      *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)v59,
      *(void **)&v59[24]);
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->buttons, (int *)&v63);
    v37 = FLOAT_45_0;
    v38 = top + 45.0;
  }
  top = v38 + v37;
  v54 = (std::_Ref_count_base *)operator new(448);
  _Right._Rep = v54;
  LOBYTE(v70) = 36;
  if ( v54 )
  {
    *(_DWORD *)&v59[24] = v61;
    std::wstring::wstring((std::wstring *)v59, L"EXIT");
    ksgui::ActiveButton::ActiveButton((ksgui::ActiveButton *)v54, *(std::wstring *)v59, *(ksgui::GUI **)&v59[24]);
    v56 = v55;
  }
  else
  {
    v56 = 0;
  }
  LOBYTE(v70) = 10;
  v63 = (ksgui::ActiveButton *)v56;
  ksgui::Control::addControl(this, (ksgui::Control *)v56);
  *((_WORD *)v56 + 100) = 0;
  std::shared_ptr<Font>::operator=((std::shared_ptr<Font> *)v56 + 16, &this->font);
  *((_OWORD *)v56 + 18) = 0i64;
  *((_OWORD *)v56 + 20) = _xmm;
  *(_DWORD *)&v59[24] = 1110704128;
  *((_OWORD *)v56 + 19) = _xmm;
  (*(void (**)(int *, int, _DWORD))(*v56 + 28))(v56, 1137180672, *(_DWORD *)&v59[24]);
  _Right._Ptr = (Font *)v56[70];
  v57 = top;
  v56[70] = (int)_Right._Ptr;
  _Right._Rep = (std::_Ref_count_base *)1088421888;
  *(float *)&v59[24] = v57;
  v56[71] = 1088421888;
  ksgui::Form::setPosition((ksgui::Form *)v56, 0.0, *(float *)&v59[24]);
  std::wstring::wstring(&result.fileName, L"Exit");
  LOBYTE(v70) = 37;
  *(_DWORD *)&v59[24] = acTranslate(&key, &result.fileName);
  v58 = *v56;
  LOBYTE(v70) = 38;
  (*(void (**)(int *, _DWORD))(v58 + 68))(v56, *(_DWORD *)&v59[24]);
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  if ( result.fileName._Myres >= 8 )
    operator delete(result.fileName._Bx._Ptr);
  *(_DWORD *)v59 = &std::_Func_impl<std::_Callable_obj<_lambda_09032053a37acb039941ba2555f4c984_,0>,std::allocator<std::_Func_class<void,ksgui::OnControlClicked const &>>,void,ksgui::OnControlClicked const &>::`vftable';
  *(_DWORD *)&v59[4] = this;
  *(_DWORD *)&v59[16] = v59;
  LOBYTE(v70) = 10;
  Event<ksgui::OnControlClicked>::addHandler(
    (Event<OnMouseWheelMovedEvent> *)v56 + 13,
    *(std::function<void __cdecl(OnMouseWheelMovedEvent const &)> *)v59,
    this);
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->buttons, (int *)&v63);
  ksgui::Control::setSize(this, 400.0, (float)(top + 45.0) + 50.0);
  LOBYTE(v70) = 7;
  INIReader::~INIReader(&v66);
}
void PauseMenu::~PauseMenu(PauseMenu *this)
{
  std::vector<ksgui::ActiveButton *> *v2; // esi

  this->__vftable = (PauseMenu_vtbl *)&PauseMenu::`vftable';
  v2 = &this->buttons;
  if ( this->buttons._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->buttons);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->enterKey);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->dwKey);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->upKey);
  OnSetupAppCreated::~OnSetupAppCreated(&this->acLogo);
  ksgui::Control::~Control(this);
}
PauseMenu *PauseMenu::`vector deleting destructor'(PauseMenu *this, unsigned int a2)
{
  PauseMenu::~PauseMenu(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void PauseMenu::blankButton(PauseMenu *this, ePauseMenuButtons button, bool value)
{
  ksgui::ActiveButton *v4; // esi
  std::wstring v5; // [esp+8h] [ebp-A0h] BYREF
  std::wstring v6; // [esp+20h] [ebp-88h] BYREF
  std::wstring v7; // [esp+38h] [ebp-70h] BYREF
  std::wstring v8; // [esp+50h] [ebp-58h] BYREF
  std::wstring name; // [esp+68h] [ebp-40h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v10; // [esp+80h] [ebp-28h] BYREF
  int v11; // [esp+A4h] [ebp-4h]

  switch ( button )
  {
    case ePauseMenuResume:
      std::wstring::wstring(&name, L"RESUME");
      v11 = 0;
      PauseMenu::getButtonByName(this, &name)->blanked = value;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&name);
      break;
    case ePauseMenuPits:
      std::wstring::wstring(&v7, L"PITS");
      v11 = 1;
      PauseMenu::getButtonByName(this, &v7)->blanked = value;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v7);
      break;
    case ePauseMenuRestart:
      std::wstring::wstring(&v5, L"RESTART");
      v11 = 2;
      PauseMenu::getButtonByName(this, &v5)->blanked = value;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v5);
      break;
    case ePauseMenuReplay:
      std::wstring::wstring(&v8, L"REPLAY");
      v11 = 4;
      PauseMenu::getButtonByName(this, &v8)->blanked = value;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v8);
      break;
    case ePauseMenuExit:
      std::wstring::wstring(&v6, L"EXIT");
      v11 = 3;
      PauseMenu::getButtonByName(this, &v6)->blanked = value;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v6);
      break;
    case ePauseMenuSkip:
      std::wstring::wstring(&v10.name, L"SKIP");
      v11 = 5;
      v4 = PauseMenu::getButtonByName(this, &v10.name);
      std::wstring::~wstring(&v10);
      if ( v4 )
        v4->blanked = value;
      break;
    default:
      return;
  }
}
ksgui::ActiveButton *PauseMenu::getButtonByName(PauseMenu *this, const std::wstring *name)
{
  int v3; // esi
  std::wstring *v4; // ecx
  const std::wstring *v5; // eax

  v3 = 0;
  if ( !(this->buttons._Mylast - this->buttons._Myfirst) )
    return 0;
  while ( 1 )
  {
    v5 = name->_Myres < 8 ? name : name->_Bx._Ptr;
    v4 = &this->buttons._Myfirst[v3]->name;
    if ( !std::wstring::compare(v4, 0, v4->_Mysize, v5->_Bx._Buf, name->_Mysize) )
      break;
    if ( ++v3 >= (unsigned int)(this->buttons._Mylast - this->buttons._Myfirst) )
      return 0;
  }
  return this->buttons._Myfirst[v3];
}
void PauseMenu::onVisibleChanged(PauseMenu *this, bool newValue)
{
  ksgui::ActiveButton *v3; // eax
  ksgui::ActiveButton *v4; // edi
  AudioEngine *v5; // ecx
  int v6; // ecx
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement name; // [esp+Ch] [ebp-28h] BYREF
  int v8; // [esp+30h] [ebp-4h]

  if ( RaceManager::getCurrentSessionType(this->sim->raceManager) == Race )
  {
    std::wstring::wstring(&name.name, L"SKIP");
    v8 = 5;
    v3 = PauseMenu::getButtonByName(this, &name.name);
    v8 = -1;
    v4 = v3;
    std::wstring::~wstring(&name);
    if ( v4 )
      v4->blanked = 1;
  }
  SystemMessage::clearMessage(this->sim->systemMessage);
  v5 = this->sim->game->audioEngine;
  if ( newValue )
    AudioEngine::stop(v5);
  else
    AudioEngine::start(v5);
  v6 = this->currentlySelectedButton;
  if ( v6 != -1 )
  {
    this->buttons._Myfirst[v6]->selected = 0;
    this->currentlySelectedButton = -1;
  }
}
void __userpurge PauseMenu::render(PauseMenu *this@<ecx>, float a2@<ebp>, int a3@<edi>, int a4@<esi>, float dt)
{
  PauseMenu_vtbl *v6; // eax
  Texture *v7; // edi
  unsigned int v8; // ebp
  unsigned int v9; // ebx
  unsigned int v10; // esi
  float v11; // xmm3_4
  float v12; // xmm2_4
  unsigned int v13; // eax
  float v14; // xmm0_4
  float v15; // xmm0_4
  float v16; // xmm0_4
  float r; // [esp+Ch] [ebp-34h]
  float g; // [esp+10h] [ebp-30h]
  __int64 v19; // [esp+1Ch] [ebp-24h]
  GLRenderer *v20; // [esp+2Ch] [ebp-14h]
  ksgui::ksRect wrect; // [esp+30h] [ebp-10h] BYREF
  float dta; // [esp+44h] [ebp+4h]

  HIDWORD(v19) = a4;
  LODWORD(v19) = a3;
  ksgui::Form::setPosition(
    (ksgui::Form *)this,
    (float)((float)this->gui->graphics->videoSettings.width * 0.5)
  - (float)((float)(this->rect.right - this->rect.left) * 0.5),
    (float)((float)this->gui->graphics->videoSettings.height * 0.5)
  - (float)((float)(this->rect.bottom - this->rect.top) * 0.5));
  ksgui::Control::render(this, a3, (int)this, dt, v19, a2);
  v6 = this->__vftable;
  wrect = (ksgui::ksRect)_mm_loadu_si128((const __m128i *)&this->rect);
  v6->getWorldRect(this, &wrect);
  v20 = this->gui->graphics->gl;
  GLRenderer::color4f(v20, 1.0, 1.0, 1.0, 1.0);
  v7 = &this->acLogo;
  GraphicsManager::setTexture(this->gui->graphics, 0, &this->acLogo);
  if ( this->acLogo.kid )
    v8 = kglTextureGetHeight(v7->kid);
  else
    v8 = 0;
  if ( v7->kid )
    v9 = kglTextureGetWidth(v7->kid);
  else
    v9 = 0;
  if ( v7->kid )
    v10 = kglTextureGetHeight(v7->kid);
  else
    v10 = 0;
  v11 = wrect.left;
  v12 = wrect.right - wrect.left;
  dta = wrect.right - wrect.left;
  if ( v7->kid )
  {
    v13 = kglTextureGetWidth(v7->kid);
    v11 = wrect.left;
    v12 = dta;
  }
  else
  {
    v13 = 0;
  }
  v14 = (float)v8;
  g = v14;
  v15 = (float)v9;
  r = v15;
  v16 = (float)v10;
  GLRenderer::quad(
    v20,
    (float)((float)(v12 * 0.5) + v11) - (float)((float)v13 * 0.5),
    wrect.top - (float)(v16 * 0.5),
    r,
    g,
    1,
    0);
}
