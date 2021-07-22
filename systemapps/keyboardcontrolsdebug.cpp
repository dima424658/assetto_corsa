#include "keyboardcontrolsdebug.h
void KeyboardControlsDebug::KeyboardControlsDebug(KeyboardControlsDebug *this, CarAvatar *aCar)
{
  int v3; // ebx
  Sim *v4; // eax
  const std::wstring *v5; // eax
  Font *v6; // eax
  Font *v7; // eax
  std::_Ref_count_base *v8; // ebp
  Font *v9; // eax
  CarAvatar *v10; // ecx
  ICarControlsProvider *v11; // eax
  KeyboardCarControl *v12; // eax
  const std::wstring *v13; // eax
  int v14; // ebp
  ksgui::Spinner *v15; // eax
  ksgui::Spinner *v16; // eax
  int v17; // ebx
  const std::wstring *v18; // ecx
  int v19; // eax
  ksgui::Spinner *v20; // eax
  ksgui::Spinner *v21; // eax
  int v22; // ebx
  const std::wstring *v23; // ecx
  int v24; // eax
  ksgui::Spinner *v25; // eax
  ksgui::Spinner *v26; // eax
  int v27; // ebx
  const std::wstring *v28; // ecx
  int v29; // eax
  ksgui::Spinner *v30; // eax
  ksgui::Spinner *v31; // eax
  int v32; // ebx
  const std::wstring *v33; // ecx
  int v34; // eax
  ksgui::Spinner *v35; // eax
  ksgui::Spinner *v36; // eax
  _BYTE v37[28]; // [esp+Ch] [ebp-9Ch] BYREF
  float h; // [esp+28h] [ebp-80h]
  int _Val; // [esp+54h] [ebp-54h] BYREF
  std::shared_ptr<Font> v40; // [esp+58h] [ebp-50h] BYREF
  int v41; // [esp+60h] [ebp-48h]
  KeyboardControlsDebug *v42; // [esp+64h] [ebp-44h]
  std::wstring result; // [esp+68h] [ebp-40h] BYREF
  std::wstring text; // [esp+80h] [ebp-28h] BYREF
  int v45; // [esp+A4h] [ebp-4h]

  v3 = 0;
  v41 = 0;
  h = 0.0;
  v42 = this;
  v4 = aCar->sim;
  _Val = (int)aCar;
  *(_DWORD *)&v37[24] = v4->game->gui;
  *(_DWORD *)&v37[20] = 7;
  *(_DWORD *)&v37[16] = 0;
  *(_WORD *)v37 = 0;
  std::wstring::assign((std::wstring *)v37, L"KEY_DEBUG", 9u);
  ksgui::Form::Form(this, 0, *(std::wstring *)v37, *(ksgui::GUI **)&v37[24], SLOBYTE(h));
  v45 = 0;
  LODWORD(h) = 14;
  this->__vftable = (KeyboardControlsDebug_vtbl *)&KeyboardControlsDebug::`vftable';
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Keyboard debug", LODWORD(h));
  LOBYTE(v45) = 1;
  v5 = acTranslate(&result, &text);
  LOBYTE(v45) = 2;
  this->formTitle->setText(this->formTitle, v5);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  LOBYTE(v45) = 0;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->car = aCar;
  ksgui::Form::setSize(this, 600.0, 600.0);
  v6 = (Font *)operator new(0x18u);
  v40._Ptr = v6;
  LOBYTE(v45) = 3;
  if ( v6 )
    Font::Font(v6, eFontMonospaced, 10.0, 0, 0);
  else
    v7 = 0;
  LOBYTE(v45) = 0;
  v40 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v40, v7);
  v8 = this->font._Rep;
  this->font = v40;
  if ( v8 )
  {
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v8->_Uses, 0xFFFFFFFF) )
    {
      v8->_Destroy(v8);
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v8->_Weaks, 0xFFFFFFFF) )
        v8->_Delete_this(v8);
    }
  }
  Font::setColor(this->font._Ptr, 1.0, 0.0, 0.0, 1.0);
  v9 = this->font._Ptr;
  h = 0.0;
  *(_DWORD *)&v37[24] = &KeyboardCarControl `RTTI Type Descriptor';
  *(_DWORD *)&v37[20] = &ICarControlsProvider `RTTI Type Descriptor';
  v9->scale = 20.0;
  v10 = this->car;
  *(_DWORD *)&v37[16] = 0;
  v11 = CarAvatar::getControlsProvider(v10);
  v12 = (KeyboardCarControl *)__RTDynamicCast(
                                v11,
                                *(_DWORD *)&v37[16],
                                *(_DWORD *)&v37[20],
                                *(_DWORD *)&v37[24],
                                LODWORD(h));
  this->key = v12;
  this->y = 15.0;
  if ( v12 )
  {
    v40._Ptr = (Font *)operator new(0x1BCu);
    LOBYTE(v45) = 4;
    if ( v40._Ptr )
    {
      std::wstring::wstring(&text, L"Steering Speed");
      LOBYTE(v45) = 5;
      v41 = 1;
      v13 = acTranslate(&result, &text);
      v45 = 6;
      v3 = 3;
      v14 = _Val;
      v41 = 3;
      ksgui::Spinner::Spinner(
        (ksgui::Spinner *)v40._Ptr,
        v13,
        *(ksgui::GUI **)(*(_DWORD *)(*(_DWORD *)(_Val + 172) + 4) + 252),
        0,
        0);
    }
    else
    {
      v14 = _Val;
      v15 = 0;
    }
    this->steerSpeedSP = v15;
    if ( (v3 & 2) != 0 )
    {
      v3 &= 0xFFFFFFFD;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
    }
    v45 = 0;
    if ( (v3 & 1) != 0 )
    {
      v3 &= 0xFFFFFFFE;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
    }
    this->steerSpeedSP->backColor = (vec4f)_xmm;
    v16 = this->steerSpeedSP;
    h = 175.0;
    *(_DWORD *)&v37[24] = 1137180672;
    v16->minValue = 0;
    this->steerSpeedSP->maxValue = 100;
    ksgui::Spinner::setPosition(this->steerSpeedSP, *(float *)&v37[24], h);
    ((void (*)(ksgui::Spinner *, int, int))this->steerSpeedSP->setSize)(
      this->steerSpeedSP,
      1125515264,
      1108082688);
    ksgui::Spinner::setValue(this->steerSpeedSP, (int)(float)((float)(this->key->steerSpeed * 0.2) * 100.0));
    _Val = (int)this->steerSpeedSP;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
    LODWORD(h) = 444;
    *(_DWORD *)(_Val + 148) = this;
    v40._Ptr = (Font *)operator new(LODWORD(h));
    LOBYTE(v45) = 9;
    if ( v40._Ptr )
    {
      std::wstring::wstring(&text, L"SteerChangeDirectionSpeed");
      LOBYTE(v45) = 10;
      v17 = v3 | 4;
      v41 = v17;
      v18 = acTranslate(&result, &text);
      v45 = 11;
      v3 = v17 | 8;
      v19 = *(_DWORD *)(v14 + 172);
      v41 = v3;
      ksgui::Spinner::Spinner((ksgui::Spinner *)v40._Ptr, v18, *(ksgui::GUI **)(*(_DWORD *)(v19 + 4) + 252), 0, 0);
    }
    else
    {
      v20 = 0;
    }
    this->steerReturnSP = v20;
    if ( (v3 & 8) != 0 )
    {
      v3 &= 0xFFFFFFF7;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
    }
    v45 = 0;
    if ( (v3 & 4) != 0 )
    {
      v3 &= 0xFFFFFFFB;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
    }
    this->steerReturnSP->backColor = (vec4f)_xmm;
    v21 = this->steerReturnSP;
    h = 250.0;
    *(_DWORD *)&v37[24] = 1137180672;
    v21->minValue = 0;
    this->steerReturnSP->maxValue = 100;
    ksgui::Spinner::setPosition(this->steerReturnSP, *(float *)&v37[24], h);
    ((void (*)(ksgui::Spinner *, int, int))this->steerReturnSP->setSize)(
      this->steerReturnSP,
      1125515264,
      1108082688);
    ksgui::Spinner::setValue(this->steerReturnSP, (int)(float)(this->key->steerOppositeDirectionFactor * 10.0));
    _Val = (int)this->steerReturnSP;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
    LODWORD(h) = 444;
    *(_DWORD *)(_Val + 148) = this;
    v40._Ptr = (Font *)operator new(LODWORD(h));
    LOBYTE(v45) = 14;
    if ( v40._Ptr )
    {
      std::wstring::wstring(&text, L"SteerGain from spline");
      LOBYTE(v45) = 15;
      v22 = v3 | 0x10;
      v41 = v22;
      v23 = acTranslate(&result, &text);
      v45 = 16;
      v3 = v22 | 0x20;
      v24 = *(_DWORD *)(v14 + 172);
      v41 = v3;
      ksgui::Spinner::Spinner((ksgui::Spinner *)v40._Ptr, v23, *(ksgui::GUI **)(*(_DWORD *)(v24 + 4) + 252), 0, 0);
    }
    else
    {
      v25 = 0;
    }
    this->steerGainSpinner = v25;
    if ( (v3 & 0x20) != 0 )
    {
      v3 &= 0xFFFFFFDF;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
    }
    v45 = 0;
    if ( (v3 & 0x10) != 0 )
    {
      v3 &= 0xFFFFFFEF;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
    }
    this->steerGainSpinner->backColor = (vec4f)_xmm;
    v26 = this->steerGainSpinner;
    h = 325.0;
    *(_DWORD *)&v37[24] = 1137180672;
    v26->minValue = 0;
    this->steerGainSpinner->maxValue = 100;
    ksgui::Spinner::setPosition(this->steerGainSpinner, *(float *)&v37[24], h);
    ((void (*)(ksgui::Spinner *, int, int))this->steerGainSpinner->setSize)(
      this->steerGainSpinner,
      1125515264,
      1108082688);
    ksgui::Spinner::setValue(this->steerGainSpinner, (int)(float)(this->key->steerGain * 100.0));
    _Val = (int)this->steerGainSpinner;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
    LODWORD(h) = 444;
    *(_DWORD *)(_Val + 148) = this;
    v40._Ptr = (Font *)operator new(LODWORD(h));
    LOBYTE(v45) = 19;
    if ( v40._Ptr )
    {
      std::wstring::wstring(&text, L"SteerReset Speed");
      LOBYTE(v45) = 20;
      v27 = v3 | 0x40;
      v41 = v27;
      v28 = acTranslate(&result, &text);
      v45 = 21;
      v3 = v27 | 0x80;
      v29 = *(_DWORD *)(v14 + 172);
      v41 = v3;
      ksgui::Spinner::Spinner((ksgui::Spinner *)v40._Ptr, v28, *(ksgui::GUI **)(*(_DWORD *)(v29 + 4) + 252), 0, 0);
    }
    else
    {
      v30 = 0;
    }
    this->steerResetSP = v30;
    if ( (v3 & 0x80u) != 0 )
    {
      v3 &= 0xFFFFFF7F;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
    }
    v45 = 0;
    if ( (v3 & 0x40) != 0 )
    {
      v3 &= 0xFFFFFFBF;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
    }
    this->steerResetSP->backColor = (vec4f)_xmm;
    v31 = this->steerResetSP;
    h = 400.0;
    *(_DWORD *)&v37[24] = 1137180672;
    v31->minValue = 0;
    this->steerResetSP->maxValue = 100;
    ksgui::Spinner::setPosition(this->steerResetSP, *(float *)&v37[24], h);
    ((void (*)(ksgui::Spinner *, int, int))this->steerResetSP->setSize)(
      this->steerResetSP,
      1125515264,
      1108082688);
    ksgui::Spinner::setValue(this->steerResetSP, (int)(float)(this->key->steerResetFactor * 10.0));
    _Val = (int)this->steerResetSP;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
    LODWORD(h) = 444;
    *(_DWORD *)(_Val + 148) = this;
    v40._Ptr = (Font *)operator new(LODWORD(h));
    LOBYTE(v45) = 24;
    if ( v40._Ptr )
    {
      std::wstring::wstring(&text, L"LookAhead Points");
      LOBYTE(v45) = 25;
      v32 = v3 | 0x100;
      v41 = v32;
      v33 = acTranslate(&result, &text);
      v45 = 26;
      v3 = v32 | 0x200;
      v34 = *(_DWORD *)(v14 + 172);
      v41 = v3;
      ksgui::Spinner::Spinner((ksgui::Spinner *)v40._Ptr, v33, *(ksgui::GUI **)(*(_DWORD *)(v34 + 4) + 252), 0, 0);
    }
    else
    {
      v35 = 0;
    }
    this->lookAheadSP = v35;
    if ( (v3 & 0x200) != 0 )
    {
      LOWORD(v3) = v3 & 0xFDFF;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
    }
    v45 = 0;
    if ( (v3 & 0x100) != 0 && text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    this->lookAheadSP->backColor = (vec4f)_xmm;
    v36 = this->lookAheadSP;
    h = 475.0;
    *(_DWORD *)&v37[24] = 1137180672;
    v36->minValue = 0;
    this->lookAheadSP->maxValue = 100;
    ksgui::Spinner::setPosition(this->lookAheadSP, *(float *)&v37[24], h);
    ((void (*)(ksgui::Spinner *, int, int))this->lookAheadSP->setSize)(
      this->lookAheadSP,
      1125515264,
      1108082688);
    ksgui::Spinner::setValue(this->lookAheadSP, (int)this->key->lookAhead);
    _Val = (int)this->lookAheadSP;
    std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->controls, &_Val);
    LODWORD(h) = this;
    *(_DWORD *)(_Val + 148) = this;
    *(_DWORD *)&v37[4] = &std::_Func_impl<std::_Callable_obj<_lambda_3988abd2b5764002050306796e1ce6fd_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
    *(_DWORD *)&v37[8] = this;
    *(_DWORD *)&v37[20] = &v37[4];
    LOBYTE(v45) = 0;
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)&this->steerSpeedSP->evOnValueChanged,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v37[4],
      (void *)LODWORD(h));
    *(_DWORD *)&v37[4] = &std::_Func_impl<std::_Callable_obj<_lambda_46f9e066a53870e8c46e3a386a6c5623_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
    *(_DWORD *)&v37[8] = this;
    *(_DWORD *)&v37[20] = &v37[4];
    LOBYTE(v45) = 0;
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)&this->steerReturnSP->evOnValueChanged,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v37[4],
      this);
    *(_DWORD *)&v37[4] = &std::_Func_impl<std::_Callable_obj<_lambda_04c6a3f2d3c08b43de0a4d9149dae0ea_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
    *(_DWORD *)&v37[8] = this;
    *(_DWORD *)&v37[20] = &v37[4];
    LOBYTE(v45) = 0;
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)&this->steerGainSpinner->evOnValueChanged,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v37[4],
      this);
    *(_DWORD *)&v37[4] = &std::_Func_impl<std::_Callable_obj<_lambda_47bf9ed23480d86d564fc1b243f4fd71_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
    *(_DWORD *)&v37[8] = this;
    *(_DWORD *)&v37[20] = &v37[4];
    LOBYTE(v45) = 0;
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)&this->steerResetSP->evOnValueChanged,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v37[4],
      this);
    *(_DWORD *)&v37[4] = &std::_Func_impl<std::_Callable_obj<_lambda_704b8563bcd33ea08723c70bdf81e25c_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
    *(_DWORD *)&v37[8] = this;
    *(_DWORD *)&v37[20] = &v37[4];
    LOBYTE(v45) = 0;
    Event<std::wstring>::addHandler(
      (Event<OnPhysicsStepCompleted> *)&this->lookAheadSP->evOnValueChanged,
      *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v37[4],
      this);
  }
}
void KeyboardControlsDebug::onSpinnerValueChanged(KeyboardControlsDebug *this, const ksgui::OnSpinnerValueChanged *ev)
{
  KeyboardControlsDebug *v2; // ebx
  std::wstring *v3; // eax
  unsigned int v4; // edx
  std::wstring *v5; // eax
  unsigned int v6; // edx
  std::wstring *v7; // eax
  unsigned int v8; // edx
  std::wstring *v9; // eax
  unsigned int v10; // edx
  const std::wstring *v11; // eax
  bool v12; // bl
  bool v13; // [esp+13h] [ebp-79h]
  bool v14; // [esp+13h] [ebp-79h]
  bool v15; // [esp+13h] [ebp-79h]
  bool v16; // [esp+13h] [ebp-79h]
  std::wstring result; // [esp+18h] [ebp-74h] BYREF
  std::wstring text; // [esp+30h] [ebp-5Ch] BYREF
  std::wstring v20; // [esp+48h] [ebp-44h] BYREF
  FriendsLeaderboardDisplayer::FriendsLeaderboardElement v21; // [esp+60h] [ebp-2Ch] BYREF
  int v22; // [esp+88h] [ebp-4h]

  v2 = this;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"Steering Speed", 0xEu);
  v22 = 0;
  v3 = acTranslate(&result, &text);
  LOBYTE(v22) = 1;
  v4 = v3->_Mysize;
  if ( v3->_Myres >= 8 )
    v3 = (std::wstring *)v3->_Bx._Ptr;
  v13 = std::wstring::compare(&ev->spinner->name, 0, ev->spinner->name._Mysize, v3->_Bx._Buf, v4) == 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v22 = -1;
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  if ( v13 )
  {
    v2->key->steerSpeed = (float)((float)ev->value * 0.0099999998) * 5.0;
  }
  else
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"SteerChangeDirectionSpeed", 0x19u);
    v22 = 2;
    v5 = acTranslate(&result, &text);
    LOBYTE(v22) = 3;
    v6 = v5->_Mysize;
    if ( v5->_Myres >= 8 )
      v5 = (std::wstring *)v5->_Bx._Ptr;
    v14 = std::wstring::compare(&ev->spinner->name, 0, ev->spinner->name._Mysize, v5->_Bx._Buf, v6) == 0;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    v22 = -1;
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    if ( v14 )
    {
      v2->key->steerOppositeDirectionFactor = (float)ev->value * 0.1;
    }
    else
    {
      std::wstring::wstring(&text, L"SteerGain from spline");
      v22 = 4;
      v7 = acTranslate(&result, &text);
      LOBYTE(v22) = 5;
      v8 = v7->_Mysize;
      if ( v7->_Myres >= 8 )
        v7 = (std::wstring *)v7->_Bx._Ptr;
      v15 = std::wstring::compare(&ev->spinner->name, 0, ev->spinner->name._Mysize, v7->_Bx._Buf, v8) == 0;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      v22 = -1;
      result._Myres = 7;
      result._Mysize = 0;
      result._Bx._Buf[0] = 0;
      if ( text._Myres >= 8 )
        operator delete(text._Bx._Ptr);
      if ( v15 )
      {
        v2->key->steerGain = (float)ev->value * 0.0099999998;
      }
      else
      {
        std::wstring::wstring(&text, L"SteerReset Speed");
        v22 = 6;
        v9 = acTranslate(&result, &text);
        LOBYTE(v22) = 7;
        v10 = v9->_Mysize;
        if ( v9->_Myres >= 8 )
          v9 = (std::wstring *)v9->_Bx._Ptr;
        v16 = std::wstring::compare(&ev->spinner->name, 0, ev->spinner->name._Mysize, v9->_Bx._Buf, v10) == 0;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        v22 = -1;
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        if ( text._Myres >= 8 )
          operator delete(text._Bx._Ptr);
        if ( v16 )
        {
          v2->key->steerResetFactor = (float)ev->value * 0.1;
        }
        else
        {
          std::wstring::wstring(&v20, L"LookAhead Points");
          v22 = 8;
          v11 = acTranslate(&v21.name, &v20);
          v12 = std::operator==<wchar_t>(&ev->spinner->name, v11);
          std::wstring::~wstring(&v21);
          std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v20);
          if ( v12 )
            this->key->lookAhead = (float)ev->value;
        }
      }
    }
  }
}
void __userpurge KeyboardControlsDebug::render(KeyboardControlsDebug *this@<ecx>, int a2@<edi>, float dt)
{
  std::wstring v4; // [esp-14h] [ebp-6Ch] BYREF
  __int64 v5; // [esp+4h] [ebp-54h]
  float v6; // [esp+Ch] [ebp-4Ch]
  std::wstring text; // [esp+14h] [ebp-44h] BYREF
  std::wstring v8; // [esp+2Ch] [ebp-2Ch] BYREF
  int v9; // [esp+54h] [ebp-4h]

  ksgui::Control::render(this, a2, (int)this, dt, v5, v6);
  this->y = 15.0;
  if ( this->key )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Steering Speed", 0xEu);
    v9 = 0;
    acTranslate(&v4, &text);
    KeyboardControlsDebug::printStringList(this, LODWORD(this->key->steerSpeed), SLODWORD(FLOAT_4_0), v4);
    v9 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Opposite Direction Speed", 0x18u);
    v9 = 1;
    acTranslate(&v4, &text);
    KeyboardControlsDebug::printStringList(
      this,
      LODWORD(this->key->steerOppositeDirectionFactor),
      SLODWORD(FLOAT_4_0),
      v4);
    v9 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Steering Gain", 0xDu);
    v9 = 2;
    acTranslate(&v4, &text);
    KeyboardControlsDebug::printStringList(this, LODWORD(this->key->steerGain), SLODWORD(FLOAT_4_0), v4);
    v9 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Steering Reset", 0xEu);
    v9 = 3;
    acTranslate(&v4, &text);
    KeyboardControlsDebug::printStringList(this, LODWORD(this->key->steerResetFactor), SLODWORD(FLOAT_4_0), v4);
    v9 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"LookAhead Points", 0x10u);
    v9 = 4;
    acTranslate(&v4, &text);
    KeyboardControlsDebug::printStringList(this, LODWORD(this->key->lookAhead), SLODWORD(FLOAT_4_0), v4);
    v9 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Speed Decelering Factor", 0x17u);
    v9 = 5;
    acTranslate(&v4, &text);
    KeyboardControlsDebug::printStringList(this, LODWORD(this->key->speedDeceleringFactor), SLODWORD(FLOAT_4_0), v4);
    v9 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Turn Decelering Factor", 0x16u);
    v9 = 6;
    acTranslate(&v4, &text);
    KeyboardControlsDebug::printStringList(this, LODWORD(this->key->turnDeceleringFactor), SLODWORD(FLOAT_4_0), v4);
    v9 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Steer Decelerator Factor", 0x18u);
    v9 = 7;
    acTranslate(&v4, &text);
    KeyboardControlsDebug::printStringList(this, LODWORD(this->key->steerDecelerator), SLODWORD(FLOAT_4_0), v4);
    v9 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Int Gas", 7u);
    v9 = 8;
    acTranslate(&v4, &text);
    KeyboardControlsDebug::printStringList(this, LODWORD(this->key->intGas), SLODWORD(FLOAT_4_0), v4);
    v9 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Int Steer", 9u);
    v9 = 9;
    acTranslate(&v4, &text);
    KeyboardControlsDebug::printStringList(this, LODWORD(this->key->intSteer), SLODWORD(FLOAT_4_0), v4);
    v9 = -1;
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Min Steer", 9u);
    v9 = 10;
    acTranslate(&v4, &text);
    KeyboardControlsDebug::printStringList(this, LODWORD(this->key->minSteering), SLODWORD(FLOAT_4_0), v4);
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
  }
  else
  {
    v8._Myres = 7;
    v8._Mysize = 0;
    v8._Bx._Buf[0] = 0;
    std::wstring::assign(&v8, L"KEYBOARD CONTROL NOT SELECTED", 0x1Du);
    v9 = 11;
    acTranslate(&v4, &v8);
    KeyboardControlsDebug::printStringList(this, 0, SLODWORD(FLOAT_4_0), v4);
    if ( v8._Myres >= 8 )
      operator delete(v8._Bx._Ptr);
  }
}
void __userpurge KeyboardControlsDebug::printStringList(KeyboardControlsDebug *this@<ecx>, int a2@<xmm1>, int a3@<xmm2>, std::wstring name)
{
  int v7; // ecx
  float v8; // xmm4_4
  __m128 v9; // xmm5
  __m128 v10; // xmm0
  float v11; // xmm2_4
  KeyboardControlsDebug_vtbl *v12; // eax
  std::wstring *v13; // esi
  std::wstring *v14; // eax
  const std::wstring *v15; // eax
  int v16; // eax
  int v17[4]; // [esp+3Ch] [ebp-120h] BYREF
  vec2f pos; // [esp+4Ch] [ebp-110h] BYREF
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v19; // [esp+54h] [ebp-108h] BYREF
  std::wstring v20; // [esp+104h] [ebp-58h] BYREF
  std::wstring v21; // [esp+11Ch] [ebp-40h] BYREF
  std::wstring result; // [esp+134h] [ebp-28h] BYREF
  int v23; // [esp+158h] [ebp-4h]

  v17[2] = a3;
  v17[0] = a2;
  v23 = 0;
  *(_DWORD *)v19.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v19.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v19.gap68);
  LOBYTE(v23) = 1;
  v17[3] = 1;
  std::wiostream::basic_iostream<wchar_t>(&v19, &v19.gap10[8], 0);
  v23 = 2;
  *(_DWORD *)&v19.gap0[*(_DWORD *)(*(_DWORD *)v19.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&pos.y + *(_DWORD *)(*(_DWORD *)v19.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v19.gap0 + 4) - 104;
  std::wstreambuf::wstreambuf(&v19.gap10[8]);
  *(_DWORD *)&v19.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v19.gap10[64] = 0;
  *(_DWORD *)&v19.gap10[68] = 0;
  LOBYTE(v23) = 4;
  v8 = __libm_sse2_powf(v7).m128_f32[0];
  v9.m128_i32[0] = LODWORD(FLOAT_N0_0) & COERCE_UNSIGNED_INT(v8 * *(float *)v17);
  v10.m128_i32[0] = COERCE_UNSIGNED_INT(v8 * *(float *)v17) ^ v9.m128_i32[0];
  LODWORD(v11) = LODWORD(FLOAT_8388608_0) & _mm_cmplt_ss(v10, (__m128)LODWORD(FLOAT_8388608_0)).m128_u32[0] | v9.m128_i32[0];
  v10.m128_f32[0] = (float)((float)((float)(v8 * *(float *)v17) + v11) - v11) - (float)(v8 * *(float *)v17);
  std::wostream::operator<<(
    v19.gap10,
    (float)((float)((float)((float)(v8 * *(float *)v17) + v11) - v11)
          - COERCE_FLOAT(_mm_cmpgt_ss(v10, v9).m128_u32[0] & LODWORD(FLOAT_1_0)))
  / v8);
  v12 = this->__vftable;
  v10.m128_i32[0] = LODWORD(this->y);
  v17[0] = 0;
  v17[1] = v10.m128_i32[0];
  v12->localToWorld(this, &pos, (const vec2f *)v17);
  v13 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v19, &result);
  LOBYTE(v23) = 5;
  v14 = std::operator+<wchar_t>(&v20, &name, L" : ");
  LOBYTE(v23) = 6;
  v15 = std::operator+<wchar_t>(&v21, v14, v13);
  LOBYTE(v23) = 7;
  Font::blitString(this->font._Ptr, pos.x, pos.y, v15, 1.0, eAlignLeft);
  if ( v21._Myres >= 8 )
    operator delete(v21._Bx._Ptr);
  v21._Myres = 7;
  v21._Mysize = 0;
  v21._Bx._Buf[0] = 0;
  if ( v20._Myres >= 8 )
    operator delete(v20._Bx._Ptr);
  v20._Myres = 7;
  v20._Mysize = 0;
  v20._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  v16 = *(_DWORD *)v19.gap0;
  this->y = this->y + 20.0;
  *(_DWORD *)&v19.gap0[*(_DWORD *)(v16 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(_DWORD *)((char *)&pos.y + *(_DWORD *)(*(_DWORD *)v19.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v19.gap0 + 4) - 104;
  *(_DWORD *)&v19.gap10[8] = &std::wstringbuf::`vftable';
  std::wstringbuf::_Tidy((std::wstringbuf *)&v19.gap10[8]);
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v19.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v19.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v19.gap68);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
