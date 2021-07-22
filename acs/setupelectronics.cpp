#include "setupelectronics.h
void SetupElectronics::SetupElectronics(SetupElectronics *this, CarAvatar *aCar)
{
  CarAvatar *v3; // eax
  RaceEngineer *v4; // ecx
  CarAvatar *v5; // eax
  SpinnerData **v6; // esi
  int v7; // edx
  char *v8; // ebp
  Font *v9; // ebp
  float v10; // xmm2_4
  SpinnerData *v11; // edi
  ksgui::Spinner *v12; // ecx
  float v13; // xmm1_4
  Font *v14; // eax
  Font *v15; // eax
  std::_Ref_count_base *v16; // esi
  std::wstring v17; // [esp-14h] [ebp-6Ch] BYREF
  float x; // [esp+4h] [ebp-54h]
  float y; // [esp+8h] [ebp-50h]
  std::shared_ptr<Font> _Val; // [esp+20h] [ebp-38h] BYREF
  int v21; // [esp+28h] [ebp-30h]
  SetupElectronics *v22; // [esp+2Ch] [ebp-2Ch]
  std::wstring text; // [esp+30h] [ebp-28h] BYREF
  int v24; // [esp+54h] [ebp-4h]

  v22 = this;
  text._Myres = 7;
  text._Mysize = 0;
  text._Bx._Buf[0] = 0;
  std::wstring::assign(&text, L"ELECTRONICS", 0xBu);
  y = *(float *)&aCar->sim;
  v24 = 0;
  x = *(float *)(*(_DWORD *)(LODWORD(y) + 4) + 252);
  acTranslate(&v17, &text);
  SetupTab::SetupTab(this, v17, (ksgui::GUI *)LODWORD(x), (Sim *)LODWORD(y));
  if ( text._Myres >= 8 )
    operator delete(text._Bx._Ptr);
  this->__vftable = (SetupElectronics_vtbl *)&SetupElectronics::`vftable';
  this->absAssist = 0;
  this->tcAssist = 0;
  this->car = aCar;
  this->spinnerDatas._Myfirst = 0;
  this->spinnerDatas._Mylast = 0;
  this->spinnerDatas._Myend = 0;
  v3 = this->car;
  LOBYTE(v24) = 3;
  v4 = v3->raceEngineer._Myptr;
  if ( v4 && RaceEngineer::getCar(v4) )
  {
    SetupElectronics::checkDrivingAssist(this, (unsigned int)this);
    if ( (CarAvatar::isTcAvailable(this->car) || this->tcAssist == 2) && this->tcAssist )
    {
      _Val._Ptr = (Font *)SetupElectronics::addTC(this, this->gui);
      std::vector<SpinnerData *>::push_back(
        (std::vector<ICollisionObject *> *)&this->spinnerDatas,
        (ICollisionObject *const *)&_Val);
    }
    if ( (CarAvatar::isAbsAvailable(this->car) || this->absAssist == 2) && this->absAssist )
    {
      _Val._Ptr = (Font *)SetupElectronics::addABS(this, this->gui);
      std::vector<SpinnerData *>::push_back(
        (std::vector<ICollisionObject *> *)&this->spinnerDatas,
        (ICollisionObject *const *)&_Val);
    }
    if ( this->car->physicsInfo.hasAdjustableTurbo )
    {
      _Val._Ptr = (Font *)SetupElectronics::addTurbo(this, this->gui);
      std::vector<SpinnerData *>::push_back(
        (std::vector<ICollisionObject *> *)&this->spinnerDatas,
        (ICollisionObject *const *)&_Val);
    }
    v5 = this->car;
    if ( v5->physicsInfo.hasERS )
    {
      if ( v5->physicsInfo.ersPowerControllerCount > 0 )
      {
        if ( v5->physicsInfo.hasCockpitERSDeliveryProfile )
        {
          _Val._Ptr = (Font *)SetupElectronics::addErsPower(this, this->gui);
          std::vector<SpinnerData *>::push_back(
            (std::vector<ICollisionObject *> *)&this->spinnerDatas,
            (ICollisionObject *const *)&_Val);
        }
        if ( this->car->physicsInfo.hasCockpitERSRecovery )
        {
          _Val._Ptr = (Font *)SetupElectronics::addErsRecovery(this, this->gui);
          std::vector<SpinnerData *>::push_back(
            (std::vector<ICollisionObject *> *)&this->spinnerDatas,
            (ICollisionObject *const *)&_Val);
        }
      }
      if ( this->car->physicsInfo.hasCockpitERSMguHMode )
      {
        _Val._Ptr = (Font *)SetupElectronics::addHeatCharging(this, this->gui);
        std::vector<SpinnerData *>::push_back(
          (std::vector<ICollisionObject *> *)&this->spinnerDatas,
          (ICollisionObject *const *)&_Val);
      }
    }
    if ( this->car->physicsInfo.engineBrakeSettingsCount )
    {
      _Val._Ptr = (Font *)SetupElectronics::addEngineBrake(this, this->gui);
      std::vector<SpinnerData *>::push_back(
        (std::vector<ICollisionObject *> *)&this->spinnerDatas,
        (ICollisionObject *const *)&_Val);
    }
  }
  v6 = this->spinnerDatas._Myfirst;
  v7 = 80;
  v8 = (char *)((char *)this->spinnerDatas._Mylast - (char *)v6);
  v21 = 80;
  _Val._Ptr = 0;
  v9 = (Font *)((unsigned int)(v8 + 3) >> 2);
  if ( v6 > this->spinnerDatas._Mylast )
    v9 = 0;
  if ( v9 )
  {
    v10 = FLOAT_0_5;
    do
    {
      v11 = *v6;
      v12 = (*v6)->spinner;
      v13 = (float)(this->rect.right - this->rect.left) * v10;
      y = (float)v7;
      ksgui::Spinner::setPosition(v12, v13 - (float)((float)(v12->rect.right - v12->rect.left) * v10), (float)v7);
      ksgui::Control::addControl(this, v11->spinner);
      ++v6;
      v10 = FLOAT_0_5;
      v7 = v21 + 80;
      v21 += 80;
      ++_Val._Ptr;
    }
    while ( _Val._Ptr != v9 );
  }
  ksgui::Control::setSize(this, 450.0, (float)v7);
  v14 = (Font *)operator new(24);
  _Val._Ptr = v14;
  LOBYTE(v24) = 4;
  if ( v14 )
    Font::Font(v14, eFontProportional, 18.0, 0, 0);
  else
    v15 = 0;
  LOBYTE(v24) = 3;
  _Val = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&_Val, v15);
  v16 = this->font._Rep;
  this->font = _Val;
  if ( v16 && !_InterlockedExchangeAdd((volatile signed __int32 *)&v16->_Uses, 0xFFFFFFFF) )
  {
    v16->_Destroy(v16);
    if ( !_InterlockedDecrement((volatile signed __int32 *)&v16->_Weaks) )
      ((void (*)(void))v16->_Delete_this)();
  }
}
void SetupElectronics::~SetupElectronics(SetupElectronics *this)
{
  SetupElectronics *v1; // edi
  std::vector<SpinnerData *> *v2; // ebx
  int v3; // ebp
  SpinnerData **v4; // esi
  unsigned int v5; // ecx
  SpinnerData *v6; // edi
  std::_Func_base<float,CarAvatar *> *v7; // ecx
  std::function<float __cdecl(CarAvatar *)> *v8; // ebx
  std::_Func_base<float,CarAvatar *> *v9; // ecx
  unsigned int v10; // [esp+10h] [ebp-Ch]
  std::vector<SpinnerData *> *v11; // [esp+14h] [ebp-8h]

  v1 = this;
  v2 = &this->spinnerDatas;
  v3 = 0;
  v11 = &this->spinnerDatas;
  this->__vftable = (SetupElectronics_vtbl *)&SetupElectronics::`vftable';
  v4 = this->spinnerDatas._Myfirst;
  v5 = (unsigned int)((char *)this->spinnerDatas._Mylast - (char *)v4 + 3) >> 2;
  if ( v4 > v2->_Mylast )
    v5 = 0;
  v10 = v5;
  if ( v5 )
  {
    do
    {
      v6 = *v4;
      if ( *v4 )
      {
        v7 = v6->functionGetValue._Impl;
        v8 = &v6->functionGetValue;
        if ( v7 )
        {
          ((void (__stdcall *)(bool))v7->_Delete_this)(v7 != (std::_Func_base<float,CarAvatar *> *)v8);
          v6->functionGetValue._Impl = 0;
        }
        v9 = v6->functionGetValue._Impl;
        if ( v9 )
        {
          ((void (__stdcall *)(bool))v9->_Delete_this)(v9 != (std::_Func_base<float,CarAvatar *> *)v8);
          v6->functionGetValue._Impl = 0;
        }
        if ( v6->name._Myres >= 8 )
          operator delete(v6->name._Bx._Ptr);
        v6->name._Myres = 7;
        v6->name._Mysize = 0;
        v6->name._Bx._Buf[0] = 0;
        operator delete(v6);
        v5 = v10;
      }
      ++v3;
      ++v4;
    }
    while ( v3 != v5 );
    v2 = v11;
    v1 = this;
  }
  if ( v2->_Myfirst )
  {
    std::_Container_base0::_Orphan_all(v2);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  SetupTab::~SetupTab(v1);
}
SetupElectronics *SetupElectronics::`vector deleting destructor'(SetupElectronics *this, unsigned int a2)
{
  SetupElectronics::~SetupElectronics(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
SpinnerData *SetupElectronics::addABS(SetupElectronics *this, ksgui::GUI *gui)
{
  char v3; // bl
  ksgui::Spinner *v4; // esi
  const std::wstring *v5; // eax
  ksgui::Spinner *v6; // eax
  unsigned int v7; // edi
  unsigned int v8; // ebx
  std::pair<unsigned int,unsigned int> *v9; // eax
  SpinnerData *v10; // esi
  float v11; // xmm0_4
  SpinnerData *v12; // eax
  SpinnerData *v13; // ebx
  std::_Func_base<float,CarAvatar *> *v14; // ecx
  std::function<float __cdecl(CarAvatar *)> *v15; // esi
  std::_Func_base<float,CarAvatar *> *v16; // ecx
  int v17; // eax
  _BYTE _defaultValue[48]; // [esp-24h] [ebp-B4h] BYREF
  std::function<float __cdecl(CarAvatar *)> v20[2]; // [esp+Ch] [ebp-84h] BYREF
  ksgui::Spinner *_spinner; // [esp+40h] [ebp-50h]
  _BYTE *v22; // [esp+44h] [ebp-4Ch]
  std::pair<unsigned int,unsigned int> v23; // [esp+48h] [ebp-48h] BYREF
  std::wstring text; // [esp+50h] [ebp-40h] BYREF
  std::wstring result; // [esp+68h] [ebp-28h] BYREF
  int v26; // [esp+8Ch] [ebp-4h]

  v3 = 0;
  _spinner = 0;
  v4 = (ksgui::Spinner *)operator new(444);
  v22 = v4;
  v26 = 0;
  if ( v4 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"ABS", 3u);
    LOBYTE(v26) = 1;
    v5 = acTranslate(&result, &text);
    v3 = 3;
    v26 = 2;
    ksgui::Spinner::Spinner(v4, v5, gui, 1, 0);
    _spinner = v6;
  }
  else
  {
    _spinner = 0;
  }
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFDu;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v26 = -1;
  if ( (v3 & 1) != 0 )
  {
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  if ( CarAvatar::isAbsAvailable(this->car) )
  {
    v9 = CarAvatar::getABSMode(this->car, &v23);
    v7 = v9->first;
    v8 = v9->second;
  }
  else
  {
    v7 = 1;
    v8 = 1;
  }
  v10 = (SpinnerData *)operator new(64);
  v22 = v10;
  v26 = 5;
  if ( v10 )
  {
    v23.first = (unsigned int)v20;
    v20[0]._Impl = 0;
    LOBYTE(v26) = 6;
    v11 = (float)v8;
    *(float *)&_defaultValue[44] = v11;
    *(_DWORD *)&_defaultValue[40] = 0;
    *(float *)&_defaultValue[36] = (float)v7;
    *(_DWORD *)&_defaultValue[32] = _spinner;
    *(_DWORD *)&_defaultValue[28] = 7;
    *(_DWORD *)&_defaultValue[24] = 0;
    *(_WORD *)&_defaultValue[8] = 0;
    std::wstring::assign((std::wstring *)&_defaultValue[8], L"ABS", 3u);
    LOBYTE(v26) = 5;
    SpinnerData::SpinnerData(
      v10,
      *(std::wstring *)&_defaultValue[8],
      *(ksgui::Spinner **)&_defaultValue[32],
      *(float *)&_defaultValue[36],
      *(float *)&_defaultValue[40],
      *(float *)&_defaultValue[44],
      v20[0]);
    v13 = v12;
  }
  else
  {
    v13 = 0;
  }
  v14 = v13->functionGetValue._Impl;
  v15 = &v13->functionGetValue;
  v26 = -1;
  if ( v14 )
  {
    ((void (__stdcall *)(bool))v14->_Delete_this)(v14 != (std::_Func_base<float,CarAvatar *> *)v15);
    v13->functionGetValue._Impl = 0;
  }
  v15->_Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_c41af40ec1381acc51fb5a8c3bb8fab7_,0>,std::allocator<std::_Func_class<float,CarAvatar *>>,float,CarAvatar *>::`vftable';
  v13->functionGetValue._Impl = (std::_Func_base<float,CarAvatar *> *)&v13->functionGetValue;
  v23.first = (unsigned int)v20;
  v20[0]._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_caec48f8f26ff3e17fa123238713f1b8_,0>,std::allocator<std::_Func_class<std::wstring,CarAvatar *,int>>,std::wstring,CarAvatar *,int>::`vftable';
  v20[0]._Impl = (std::_Func_base<float,CarAvatar *> *)v20;
  v26 = 8;
  v22 = &_defaultValue[24];
  *(_DWORD *)&_defaultValue[24] = &std::_Func_impl<std::_Callable_obj<_lambda_a5180a937a511278fb4c9f7b86ce3f76_,0>,std::allocator<std::_Func_class<void,CarAvatar *,float>>,void,CarAvatar *,float>::`vftable';
  *(_DWORD *)&_defaultValue[40] = &_defaultValue[24];
  _spinner = (ksgui::Spinner *)_defaultValue;
  *(_DWORD *)&_defaultValue[16] = 0;
  v16 = v13->functionGetValue._Impl;
  LOBYTE(v26) = 11;
  if ( v16 )
  {
    if ( v16 == (std::_Func_base<float,CarAvatar *> *)v15 )
      v17 = v16->_Copy(v16, _defaultValue);
    else
      v17 = (int)v16->_Copy(v16, 0);
    *(_DWORD *)&_defaultValue[16] = v17;
  }
  else
  {
    *(_DWORD *)&_defaultValue[16] = 0;
  }
  v26 = -1;
  SetupElectronics::setSpinner(
    this,
    v13,
    *(std::function<float __cdecl(CarAvatar *)> *)_defaultValue,
    *(std::function<void __cdecl(CarAvatar *,float)> *)&_defaultValue[24],
    (std::function<std::wstring __cdecl(CarAvatar *,int)>)v20[0]);
  return v13;
}
SpinnerData *SetupElectronics::addEngineBrake(SetupElectronics *this, ksgui::GUI *gui)
{
  char v3; // bl
  ksgui::Spinner *v4; // esi
  const std::wstring *v5; // eax
  int v6; // eax
  int v7; // edi
  CarAvatar *v8; // eax
  int v9; // ebx
  SpinnerData *v10; // esi
  CarAvatar *v11; // eax
  SpinnerData *v12; // eax
  SpinnerData *v13; // ebx
  std::_Func_base<float,CarAvatar *> *v14; // ecx
  std::function<float __cdecl(CarAvatar *)> *v15; // esi
  std::_Func_base<float,CarAvatar *> *v16; // ecx
  int v17; // eax
  _BYTE _defaultValue[48]; // [esp-24h] [ebp-B0h] BYREF
  std::function<float __cdecl(CarAvatar *)> v20[2]; // [esp+Ch] [ebp-80h] BYREF
  int v21; // [esp+40h] [ebp-4Ch]
  _BYTE *v22; // [esp+44h] [ebp-48h]
  std::function<float __cdecl(CarAvatar *)> *v23; // [esp+48h] [ebp-44h]
  std::wstring text; // [esp+4Ch] [ebp-40h] BYREF
  std::wstring result; // [esp+64h] [ebp-28h] BYREF
  int v26; // [esp+88h] [ebp-4h]

  v3 = 0;
  v21 = 0;
  v4 = (ksgui::Spinner *)operator new(444);
  v22 = v4;
  v26 = 0;
  if ( v4 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Brake Engine", 0xCu);
    LOBYTE(v26) = 1;
    v5 = acTranslate(&result, &text);
    v3 = 3;
    v26 = 2;
    v21 = 3;
    ksgui::Spinner::Spinner(v4, v5, gui, 1, 0);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFDu;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v26 = -1;
  if ( (v3 & 1) != 0 )
  {
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v8 = this->car;
  (&v20[0]._Impl)[1] = (std::_Func_base<float,CarAvatar *> *)64;
  v9 = v8->currentEngineBrakeSetting;
  v10 = (SpinnerData *)operator new(64);
  v22 = v10;
  v26 = 5;
  if ( v10 )
  {
    v21 = (int)v20;
    v20[0]._Impl = 0;
    v11 = this->car;
    LOBYTE(v26) = 6;
    *(float *)&_defaultValue[44] = (float)v11->physicsInfo.engineBrakeSettingsCount;
    *(_DWORD *)&_defaultValue[40] = 1065353216;
    *(float *)&_defaultValue[36] = (float)v9;
    *(_DWORD *)&_defaultValue[32] = v7;
    *(_DWORD *)&_defaultValue[28] = 7;
    *(_DWORD *)&_defaultValue[24] = 0;
    *(_WORD *)&_defaultValue[8] = 0;
    std::wstring::assign((std::wstring *)&_defaultValue[8], L"BRAKE_ENGINE", 0xCu);
    LOBYTE(v26) = 5;
    SpinnerData::SpinnerData(
      v10,
      *(std::wstring *)&_defaultValue[8],
      *(ksgui::Spinner **)&_defaultValue[32],
      *(float *)&_defaultValue[36],
      *(float *)&_defaultValue[40],
      *(float *)&_defaultValue[44],
      v20[0]);
    v13 = v12;
  }
  else
  {
    v13 = 0;
  }
  v14 = v13->functionGetValue._Impl;
  v15 = &v13->functionGetValue;
  v26 = -1;
  if ( v14 )
  {
    ((void (__stdcall *)(bool))v14->_Delete_this)(v14 != (std::_Func_base<float,CarAvatar *> *)v15);
    v13->functionGetValue._Impl = 0;
  }
  v15->_Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_0e8b76b6a3bf6015a601ed552f351b8f_,0>,std::allocator<std::_Func_class<float,CarAvatar *>>,float,CarAvatar *>::`vftable';
  v13->functionGetValue._Impl = (std::_Func_base<float,CarAvatar *> *)&v13->functionGetValue;
  v23 = v20;
  v20[0]._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_cbdfebb6417da3228235f54e30dc6613_,0>,std::allocator<std::_Func_class<std::wstring,CarAvatar *,int>>,std::wstring,CarAvatar *,int>::`vftable';
  v20[0]._Space._Pfn[1] = (void (__cdecl *)())this;
  v20[0]._Impl = (std::_Func_base<float,CarAvatar *> *)v20;
  v26 = 8;
  v22 = &_defaultValue[24];
  *(_DWORD *)&_defaultValue[24] = &std::_Func_impl<std::_Callable_obj<_lambda_832e1775156345134d8d6d37d5a5389d_,0>,std::allocator<std::_Func_class<void,CarAvatar *,float>>,void,CarAvatar *,float>::`vftable';
  *(_DWORD *)&_defaultValue[40] = &_defaultValue[24];
  v21 = (int)_defaultValue;
  *(_DWORD *)&_defaultValue[16] = 0;
  v16 = v13->functionGetValue._Impl;
  LOBYTE(v26) = 11;
  if ( v16 )
  {
    if ( v16 == (std::_Func_base<float,CarAvatar *> *)v15 )
      v17 = v16->_Copy(v16, _defaultValue);
    else
      v17 = (int)v16->_Copy(v16, 0);
    *(_DWORD *)&_defaultValue[16] = v17;
  }
  else
  {
    *(_DWORD *)&_defaultValue[16] = 0;
  }
  v26 = -1;
  SetupElectronics::setSpinner(
    this,
    v13,
    *(std::function<float __cdecl(CarAvatar *)> *)_defaultValue,
    *(std::function<void __cdecl(CarAvatar *,float)> *)&_defaultValue[24],
    (std::function<std::wstring __cdecl(CarAvatar *,int)>)v20[0]);
  return v13;
}
SpinnerData *SetupElectronics::addErsPower(SetupElectronics *this, ksgui::GUI *gui)
{
  char v3; // bl
  ksgui::Spinner *v4; // esi
  const std::wstring *v5; // eax
  int v6; // eax
  int v7; // edi
  SpinnerData *v8; // esi
  CarAvatar *v9; // eax
  SpinnerData *v10; // eax
  SpinnerData *v11; // ebx
  std::_Func_base<float,CarAvatar *> *v12; // ecx
  std::function<float __cdecl(CarAvatar *)> *v13; // esi
  std::_Func_base<float,CarAvatar *> *v14; // ecx
  std::_Func_base<float,CarAvatar *>_vtbl *v15; // eax
  int v16; // eax
  _BYTE _defaultValue[48]; // [esp-24h] [ebp-CCh] BYREF
  std::function<float __cdecl(CarAvatar *)> v19[2]; // [esp+Ch] [ebp-9Ch] BYREF
  int v20; // [esp+40h] [ebp-68h]
  _BYTE *v21; // [esp+44h] [ebp-64h]
  std::function<float __cdecl(CarAvatar *)> *v22; // [esp+48h] [ebp-60h]
  std::pair<int,std::wstring > value; // [esp+4Ch] [ebp-5Ch] BYREF
  std::wstring text; // [esp+68h] [ebp-40h] BYREF
  std::wstring result; // [esp+80h] [ebp-28h] BYREF
  int v26; // [esp+A4h] [ebp-4h]

  v3 = 0;
  v20 = 0;
  v4 = (ksgui::Spinner *)operator new(444);
  v21 = v4;
  v26 = 0;
  if ( v4 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"MGUK-Delivery", 0xDu);
    LOBYTE(v26) = 1;
    v5 = acTranslate(&result, &text);
    v3 = 3;
    v26 = 2;
    v20 = 3;
    ksgui::Spinner::Spinner(v4, v5, gui, 1, 0);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFDu;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v26 = -1;
  if ( (v3 & 1) != 0 )
  {
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  CarAvatar::getERSPower(this->car, &value);
  v26 = 5;
  v8 = (SpinnerData *)operator new(64);
  v21 = v8;
  if ( v8 )
  {
    v20 = (int)v19;
    v19[0]._Impl = 0;
    v9 = this->car;
    LOBYTE(v26) = 7;
    *(float *)&_defaultValue[44] = (float)(v9->physicsInfo.ersPowerControllerCount - 1);
    *(_DWORD *)&_defaultValue[40] = 0;
    *(float *)&_defaultValue[36] = (float)value.first;
    *(_DWORD *)&_defaultValue[32] = v7;
    *(_DWORD *)&_defaultValue[28] = 7;
    *(_DWORD *)&_defaultValue[24] = 0;
    *(_WORD *)&_defaultValue[8] = 0;
    std::wstring::assign((std::wstring *)&_defaultValue[8], L"MGUK_DELIVERY", 0xDu);
    LOBYTE(v26) = 6;
    SpinnerData::SpinnerData(
      v8,
      *(std::wstring *)&_defaultValue[8],
      *(ksgui::Spinner **)&_defaultValue[32],
      *(float *)&_defaultValue[36],
      *(float *)&_defaultValue[40],
      *(float *)&_defaultValue[44],
      v19[0]);
    v11 = v10;
  }
  else
  {
    v11 = 0;
  }
  v12 = v11->functionGetValue._Impl;
  v13 = &v11->functionGetValue;
  LOBYTE(v26) = 5;
  if ( v12 )
  {
    ((void (__stdcall *)(bool))v12->_Delete_this)(v12 != (std::_Func_base<float,CarAvatar *> *)v13);
    v11->functionGetValue._Impl = 0;
  }
  v13->_Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_63b55491879d7052e2dff3bcd0a9b7cb_,0>,std::allocator<std::_Func_class<float,CarAvatar *>>,float,CarAvatar *>::`vftable';
  v11->functionGetValue._Impl = (std::_Func_base<float,CarAvatar *> *)&v11->functionGetValue;
  v22 = v19;
  v19[0]._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_bc78f13113546dcdd8613f18ac4ae0cf_,0>,std::allocator<std::_Func_class<std::wstring,CarAvatar *,int>>,std::wstring,CarAvatar *,int>::`vftable';
  v19[0]._Impl = (std::_Func_base<float,CarAvatar *> *)v19;
  v21 = &_defaultValue[24];
  *(_DWORD *)&_defaultValue[24] = &std::_Func_impl<std::_Callable_obj<_lambda_dd67fb5b3928a2eeb6ebcc3835e89d56_,0>,std::allocator<std::_Func_class<void,CarAvatar *,float>>,void,CarAvatar *,float>::`vftable';
  *(_DWORD *)&_defaultValue[40] = &_defaultValue[24];
  v20 = (int)_defaultValue;
  *(_DWORD *)&_defaultValue[16] = 0;
  v14 = v11->functionGetValue._Impl;
  LOBYTE(v26) = 12;
  if ( v14 )
  {
    v15 = v14->__vftable;
    if ( v14 == (std::_Func_base<float,CarAvatar *> *)v13 )
      v16 = ((int (__stdcall *)(_BYTE *))v15->_Copy)(_defaultValue);
    else
      v16 = ((int (__stdcall *)(_DWORD))v15->_Copy)(0);
    *(_DWORD *)&_defaultValue[16] = v16;
  }
  else
  {
    *(_DWORD *)&_defaultValue[16] = 0;
  }
  LOBYTE(v26) = 5;
  SetupElectronics::setSpinner(
    this,
    v11,
    *(std::function<float __cdecl(CarAvatar *)> *)_defaultValue,
    *(std::function<void __cdecl(CarAvatar *,float)> *)&_defaultValue[24],
    (std::function<std::wstring __cdecl(CarAvatar *,int)>)v19[0]);
  if ( value.second._Myres >= 8 )
    operator delete(value.second._Bx._Ptr);
  return v11;
}
SpinnerData *SetupElectronics::addErsRecovery(SetupElectronics *this, ksgui::GUI *gui)
{
  char v3; // bl
  ksgui::Spinner *v4; // esi
  const std::wstring *v5; // eax
  int v6; // eax
  int v7; // edi
  CarAvatar *v8; // eax
  int v9; // ebx
  SpinnerData *v10; // esi
  SpinnerData *v11; // eax
  SpinnerData *v12; // ebx
  std::_Func_base<float,CarAvatar *> *v13; // ecx
  std::function<float __cdecl(CarAvatar *)> *v14; // esi
  std::_Func_base<float,CarAvatar *> *v15; // ecx
  int v16; // eax
  _BYTE _defaultValue[48]; // [esp-24h] [ebp-B0h] BYREF
  std::function<float __cdecl(CarAvatar *)> v19[2]; // [esp+Ch] [ebp-80h] BYREF
  int v20; // [esp+40h] [ebp-4Ch]
  _BYTE *v21; // [esp+44h] [ebp-48h]
  std::function<float __cdecl(CarAvatar *)> *v22; // [esp+48h] [ebp-44h]
  std::wstring text; // [esp+4Ch] [ebp-40h] BYREF
  std::wstring result; // [esp+64h] [ebp-28h] BYREF
  int v25; // [esp+88h] [ebp-4h]

  v3 = 0;
  v20 = 0;
  v4 = (ksgui::Spinner *)operator new(444);
  v21 = v4;
  v25 = 0;
  if ( v4 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"MGUK-Recovery", 0xDu);
    LOBYTE(v25) = 1;
    v5 = acTranslate(&result, &text);
    v3 = 3;
    v25 = 2;
    v20 = 3;
    ksgui::Spinner::Spinner(v4, v5, gui, 1, 0);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFDu;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v25 = -1;
  if ( (v3 & 1) != 0 )
  {
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v8 = this->car;
  (&v19[0]._Impl)[1] = (std::_Func_base<float,CarAvatar *> *)64;
  v9 = v8->currentERSRecovery;
  v10 = (SpinnerData *)operator new(64);
  v21 = v10;
  v25 = 5;
  if ( v10 )
  {
    v20 = (int)v19;
    v19[0]._Impl = 0;
    LOBYTE(v25) = 6;
    *(_DWORD *)&_defaultValue[44] = 1092616192;
    *(_DWORD *)&_defaultValue[40] = 0;
    *(float *)&_defaultValue[36] = (float)v9;
    *(_DWORD *)&_defaultValue[32] = v7;
    *(_DWORD *)&_defaultValue[28] = 7;
    *(_DWORD *)&_defaultValue[24] = 0;
    *(_WORD *)&_defaultValue[8] = 0;
    std::wstring::assign((std::wstring *)&_defaultValue[8], L"MGUK_RECOVERY", 0xDu);
    LOBYTE(v25) = 5;
    SpinnerData::SpinnerData(
      v10,
      *(std::wstring *)&_defaultValue[8],
      *(ksgui::Spinner **)&_defaultValue[32],
      *(float *)&_defaultValue[36],
      *(float *)&_defaultValue[40],
      *(float *)&_defaultValue[44],
      v19[0]);
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  v13 = v12->functionGetValue._Impl;
  v14 = &v12->functionGetValue;
  v25 = -1;
  if ( v13 )
  {
    ((void (__stdcall *)(bool))v13->_Delete_this)(v13 != (std::_Func_base<float,CarAvatar *> *)v14);
    v12->functionGetValue._Impl = 0;
  }
  v14->_Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_801f1bc0da23acf585600afb34e3de3e_,0>,std::allocator<std::_Func_class<float,CarAvatar *>>,float,CarAvatar *>::`vftable';
  v12->functionGetValue._Impl = (std::_Func_base<float,CarAvatar *> *)&v12->functionGetValue;
  v22 = v19;
  v19[0]._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_f366ee7cf1b45b132e3eb8bf5587ac83_,0>,std::allocator<std::_Func_class<std::wstring,CarAvatar *,int>>,std::wstring,CarAvatar *,int>::`vftable';
  v19[0]._Impl = (std::_Func_base<float,CarAvatar *> *)v19;
  v25 = 8;
  v21 = &_defaultValue[24];
  *(_DWORD *)&_defaultValue[24] = &std::_Func_impl<std::_Callable_obj<_lambda_13d048c8a74cc9cf393e1d21df639e9e_,0>,std::allocator<std::_Func_class<void,CarAvatar *,float>>,void,CarAvatar *,float>::`vftable';
  *(_DWORD *)&_defaultValue[40] = &_defaultValue[24];
  v20 = (int)_defaultValue;
  *(_DWORD *)&_defaultValue[16] = 0;
  v15 = v12->functionGetValue._Impl;
  LOBYTE(v25) = 11;
  if ( v15 )
  {
    if ( v15 == (std::_Func_base<float,CarAvatar *> *)v14 )
      v16 = v15->_Copy(v15, _defaultValue);
    else
      v16 = (int)v15->_Copy(v15, 0);
    *(_DWORD *)&_defaultValue[16] = v16;
  }
  else
  {
    *(_DWORD *)&_defaultValue[16] = 0;
  }
  v25 = -1;
  SetupElectronics::setSpinner(
    this,
    v12,
    *(std::function<float __cdecl(CarAvatar *)> *)_defaultValue,
    *(std::function<void __cdecl(CarAvatar *,float)> *)&_defaultValue[24],
    (std::function<std::wstring __cdecl(CarAvatar *,int)>)v19[0]);
  return v12;
}
SpinnerData *SetupElectronics::addHeatCharging(SetupElectronics *this, ksgui::GUI *gui)
{
  char v3; // bl
  ksgui::Spinner *v4; // esi
  const std::wstring *v5; // eax
  int v6; // eax
  int v7; // edi
  CarAvatar *v8; // eax
  bool v9; // bl
  SpinnerData *v10; // esi
  SpinnerData *v11; // eax
  SpinnerData *v12; // ebx
  std::_Func_base<float,CarAvatar *> *v13; // ecx
  std::function<float __cdecl(CarAvatar *)> *v14; // esi
  std::_Func_base<float,CarAvatar *> *v15; // ecx
  int v16; // eax
  _BYTE _defaultValue[48]; // [esp-24h] [ebp-B0h] BYREF
  std::function<float __cdecl(CarAvatar *)> v19[2]; // [esp+Ch] [ebp-80h] BYREF
  int v20; // [esp+40h] [ebp-4Ch]
  _BYTE *v21; // [esp+44h] [ebp-48h]
  std::function<float __cdecl(CarAvatar *)> *v22; // [esp+48h] [ebp-44h]
  std::wstring text; // [esp+4Ch] [ebp-40h] BYREF
  std::wstring result; // [esp+64h] [ebp-28h] BYREF
  int v25; // [esp+88h] [ebp-4h]

  v3 = 0;
  v20 = 0;
  v4 = (ksgui::Spinner *)operator new(444);
  v21 = v4;
  v25 = 0;
  if ( v4 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"MGUH-Mode", 9u);
    LOBYTE(v25) = 1;
    v5 = acTranslate(&result, &text);
    v3 = 3;
    v25 = 2;
    v20 = 3;
    ksgui::Spinner::Spinner(v4, v5, gui, 1, 0);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFDu;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v25 = -1;
  if ( (v3 & 1) != 0 )
  {
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v8 = this->car;
  (&v19[0]._Impl)[1] = (std::_Func_base<float,CarAvatar *> *)64;
  v9 = v8->isHeatChargingBatteries;
  v10 = (SpinnerData *)operator new(64);
  v21 = v10;
  v25 = 5;
  if ( v10 )
  {
    v20 = (int)v19;
    v19[0]._Impl = 0;
    LOBYTE(v25) = 6;
    *(_DWORD *)&_defaultValue[44] = 1065353216;
    *(_DWORD *)&_defaultValue[40] = 0;
    *(float *)&_defaultValue[36] = (float)v9;
    *(_DWORD *)&_defaultValue[32] = v7;
    *(_DWORD *)&_defaultValue[28] = 7;
    *(_DWORD *)&_defaultValue[24] = 0;
    *(_WORD *)&_defaultValue[8] = 0;
    std::wstring::assign((std::wstring *)&_defaultValue[8], L"MGUH_MODE", 9u);
    LOBYTE(v25) = 5;
    SpinnerData::SpinnerData(
      v10,
      *(std::wstring *)&_defaultValue[8],
      *(ksgui::Spinner **)&_defaultValue[32],
      *(float *)&_defaultValue[36],
      *(float *)&_defaultValue[40],
      *(float *)&_defaultValue[44],
      v19[0]);
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  v13 = v12->functionGetValue._Impl;
  v14 = &v12->functionGetValue;
  v25 = -1;
  if ( v13 )
  {
    ((void (__stdcall *)(bool))v13->_Delete_this)(v13 != (std::_Func_base<float,CarAvatar *> *)v14);
    v12->functionGetValue._Impl = 0;
  }
  v14->_Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_d5f49b0957548bf0c3da4edd73e971fc_,0>,std::allocator<std::_Func_class<float,CarAvatar *>>,float,CarAvatar *>::`vftable';
  v12->functionGetValue._Impl = (std::_Func_base<float,CarAvatar *> *)&v12->functionGetValue;
  v22 = v19;
  v19[0]._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_e1157e21d6c7f495fa03d4dca1d457af_,0>,std::allocator<std::_Func_class<std::wstring,CarAvatar *,int>>,std::wstring,CarAvatar *,int>::`vftable';
  v19[0]._Impl = (std::_Func_base<float,CarAvatar *> *)v19;
  v25 = 8;
  v21 = &_defaultValue[24];
  *(_DWORD *)&_defaultValue[24] = &std::_Func_impl<std::_Callable_obj<_lambda_a994709b1def3b156b747245aaafb261_,0>,std::allocator<std::_Func_class<void,CarAvatar *,float>>,void,CarAvatar *,float>::`vftable';
  *(_DWORD *)&_defaultValue[40] = &_defaultValue[24];
  v20 = (int)_defaultValue;
  *(_DWORD *)&_defaultValue[16] = 0;
  v15 = v12->functionGetValue._Impl;
  LOBYTE(v25) = 11;
  if ( v15 )
  {
    if ( v15 == (std::_Func_base<float,CarAvatar *> *)v14 )
      v16 = v15->_Copy(v15, _defaultValue);
    else
      v16 = (int)v15->_Copy(v15, 0);
    *(_DWORD *)&_defaultValue[16] = v16;
  }
  else
  {
    *(_DWORD *)&_defaultValue[16] = 0;
  }
  v25 = -1;
  SetupElectronics::setSpinner(
    this,
    v12,
    *(std::function<float __cdecl(CarAvatar *)> *)_defaultValue,
    *(std::function<void __cdecl(CarAvatar *,float)> *)&_defaultValue[24],
    (std::function<std::wstring __cdecl(CarAvatar *,int)>)v19[0]);
  return v12;
}
SpinnerData *SetupElectronics::addTC(SetupElectronics *this, ksgui::GUI *gui)
{
  char v3; // bl
  ksgui::Spinner *v4; // edi
  const std::wstring *v5; // eax
  CarAvatar *v6; // ecx
  Sim *v7; // ecx
  ksgui::Spinner *v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // ebp
  std::pair<unsigned int,unsigned int> *v11; // eax
  SpinnerData *v12; // edi
  float v13; // xmm0_4
  SpinnerData *v14; // eax
  SpinnerData *v15; // edi
  _BYTE _defaultValue[48]; // [esp-24h] [ebp-BCh] BYREF
  std::function<float __cdecl(CarAvatar *)> v18[2]; // [esp+Ch] [ebp-8Ch] BYREF
  ksgui::Spinner *_spinner; // [esp+48h] [ebp-50h]
  std::pair<unsigned int,unsigned int> v20; // [esp+4Ch] [ebp-4Ch] BYREF
  void *v21; // [esp+54h] [ebp-44h]
  std::wstring text; // [esp+58h] [ebp-40h] BYREF
  std::wstring result; // [esp+70h] [ebp-28h] BYREF
  int v24; // [esp+94h] [ebp-4h]

  v3 = 0;
  _spinner = 0;
  v4 = (ksgui::Spinner *)operator new(444);
  v21 = v4;
  v24 = 0;
  if ( v4 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"Traction Control", 0x10u);
    LOBYTE(v24) = 1;
    _spinner = (ksgui::Spinner *)1;
    v5 = acTranslate(&result, &text);
    v6 = this->car;
    v3 = 3;
    (&v18[0]._Impl)[1] = 0;
    v18[0]._Impl = (std::_Func_base<float,CarAvatar *> *)1;
    v24 = 2;
    v7 = v6->sim;
    _spinner = (ksgui::Spinner *)3;
    ksgui::Spinner::Spinner(v4, v5, v7->game->gui, 1, 0);
    _spinner = v8;
  }
  else
  {
    _spinner = 0;
  }
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFDu;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v24 = -1;
  if ( (v3 & 1) != 0 )
  {
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  if ( CarAvatar::isTcAvailable(this->car) )
  {
    v11 = CarAvatar::getTCMode(this->car, &v20);
    v9 = v11->first;
    v10 = v11->second;
  }
  else
  {
    v9 = 1;
    v10 = 1;
  }
  v12 = (SpinnerData *)operator new(64);
  v21 = v12;
  v24 = 5;
  if ( v12 )
  {
    v20.first = (unsigned int)v18;
    v18[0]._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_4ad41c6d5f192cbd281f3c43d00c0142_,0>,std::allocator<std::_Func_class<float,CarAvatar *>>,float,CarAvatar *>::`vftable';
    v18[0]._Impl = (std::_Func_base<float,CarAvatar *> *)v18;
    LOBYTE(v24) = 7;
    v13 = (float)v10;
    *(float *)&_defaultValue[44] = v13;
    *(_DWORD *)&_defaultValue[40] = 0;
    *(float *)&_defaultValue[36] = (float)v9;
    *(_DWORD *)&_defaultValue[32] = _spinner;
    *(_DWORD *)&_defaultValue[28] = 7;
    *(_DWORD *)&_defaultValue[24] = 0;
    *(_WORD *)&_defaultValue[8] = 0;
    std::wstring::assign((std::wstring *)&_defaultValue[8], L"TRACTION_CONTROL", 0x10u);
    LOBYTE(v24) = 5;
    SpinnerData::SpinnerData(
      v12,
      *(std::wstring *)&_defaultValue[8],
      *(ksgui::Spinner **)&_defaultValue[32],
      *(float *)&_defaultValue[36],
      *(float *)&_defaultValue[40],
      *(float *)&_defaultValue[44],
      v18[0]);
    v15 = v14;
  }
  else
  {
    v15 = 0;
  }
  v18[0]._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_eea00b56d948751bd11b6c89b54c677a_,0>,std::allocator<std::_Func_class<std::wstring,CarAvatar *,int>>,std::wstring,CarAvatar *,int>::`vftable';
  v18[0]._Impl = (std::_Func_base<float,CarAvatar *> *)v18;
  v20.first = (unsigned int)&_defaultValue[24];
  *(_DWORD *)&_defaultValue[24] = &std::_Func_impl<std::_Callable_obj<_lambda_54671ad5569bd51105e0563464a207d7_,0>,std::allocator<std::_Func_class<void,CarAvatar *,float>>,void,CarAvatar *,float>::`vftable';
  *(_DWORD *)&_defaultValue[40] = &_defaultValue[24];
  *(_DWORD *)_defaultValue = &std::_Func_impl<std::_Callable_obj<_lambda_f449af80f2f5e225dd8bc0ab3a70a1d6_,0>,std::allocator<std::_Func_class<float,CarAvatar *>>,float,CarAvatar *>::`vftable';
  *(_DWORD *)&_defaultValue[16] = _defaultValue;
  v24 = -1;
  SetupElectronics::setSpinner(
    this,
    v15,
    *(std::function<float __cdecl(CarAvatar *)> *)_defaultValue,
    *(std::function<void __cdecl(CarAvatar *,float)> *)&_defaultValue[24],
    (std::function<std::wstring __cdecl(CarAvatar *,int)>)v18[0]);
  return v15;
}
SpinnerData *SetupElectronics::addTurbo(SetupElectronics *this, ksgui::GUI *gui)
{
  char v3; // bl
  ksgui::Spinner *v4; // esi
  const std::wstring *v5; // eax
  int v6; // eax
  int v7; // edi
  CarAvatar *v8; // eax
  CarAvatar *v9; // eax
  SpinnerData *v10; // esi
  SpinnerData *v11; // eax
  SpinnerData *v12; // edi
  std::_Func_base<float,CarAvatar *> *v13; // ecx
  std::function<float __cdecl(CarAvatar *)> *v14; // esi
  _BYTE _defaultValue[48]; // [esp-24h] [ebp-BE8h] BYREF
  std::function<float __cdecl(CarAvatar *)> v17[2]; // [esp+Ch] [ebp-BB8h] BYREF
  float v18; // [esp+40h] [ebp-B84h]
  std::function<float __cdecl(CarAvatar *)> *v19; // [esp+44h] [ebp-B80h]
  void *v20; // [esp+48h] [ebp-B7Ch]
  std::wstring text; // [esp+4Ch] [ebp-B78h] BYREF
  std::wstring result; // [esp+64h] [ebp-B60h] BYREF
  CarPhysicsState state; // [esp+7Ch] [ebp-B48h] BYREF
  int v24; // [esp+BC0h] [ebp-4h]

  v3 = 0;
  v18 = 0.0;
  v4 = (ksgui::Spinner *)operator new(444);
  v20 = v4;
  v24 = 0;
  if ( v4 )
  {
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
    std::wstring::assign(&text, L"TURBO", 5u);
    LOBYTE(v24) = 1;
    v5 = acTranslate(&result, &text);
    v3 = 3;
    v24 = 2;
    LODWORD(v18) = 3;
    ksgui::Spinner::Spinner(v4, v5, gui, 1, 0);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  if ( (v3 & 2) != 0 )
  {
    v3 &= 0xFDu;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Mysize = 0;
    result._Bx._Buf[0] = 0;
  }
  v24 = -1;
  if ( (v3 & 1) != 0 )
  {
    if ( text._Myres >= 8 )
      operator delete(text._Bx._Ptr);
    text._Myres = 7;
    text._Mysize = 0;
    text._Bx._Buf[0] = 0;
  }
  v8 = this->car;
  if ( v8->physicsStateProvider )
  {
    CarPhysicsState::CarPhysicsState(&state);
    v9 = this->car;
    v24 = 5;
    v9->physicsStateProvider->getPhysicsState(v9->physicsStateProvider, &state);
    v24 = -1;
    v18 = state.turboBoostLevel * 10.0;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&state.speed);
  }
  else
  {
    v18 = v8->physicsState.turboBoostLevel * 10.0;
  }
  v10 = (SpinnerData *)operator new(64);
  v20 = v10;
  v24 = 6;
  if ( v10 )
  {
    v19 = v17;
    v17[0]._Impl = 0;
    LOBYTE(v24) = 7;
    *(_DWORD *)&_defaultValue[44] = 1092616192;
    *(_DWORD *)&_defaultValue[40] = 0;
    *(float *)&_defaultValue[36] = v18;
    *(_DWORD *)&_defaultValue[32] = v7;
    *(_DWORD *)&_defaultValue[28] = 7;
    *(_DWORD *)&_defaultValue[24] = 0;
    *(_WORD *)&_defaultValue[8] = 0;
    std::wstring::assign((std::wstring *)&_defaultValue[8], L"TURBO", 5u);
    LOBYTE(v24) = 6;
    SpinnerData::SpinnerData(
      v10,
      *(std::wstring *)&_defaultValue[8],
      *(ksgui::Spinner **)&_defaultValue[32],
      *(float *)&_defaultValue[36],
      *(float *)&_defaultValue[40],
      *(float *)&_defaultValue[44],
      v17[0]);
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  v13 = v12->functionGetValue._Impl;
  v14 = &v12->functionGetValue;
  v24 = -1;
  if ( v13 )
  {
    ((void (__stdcall *)(bool))v13->_Delete_this)(v13 != (std::_Func_base<float,CarAvatar *> *)v14);
    v12->functionGetValue._Impl = 0;
  }
  v14->_Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_3fab2fe60eb1677c2f02144546c3547e_,0>,std::allocator<std::_Func_class<float,CarAvatar *>>,float,CarAvatar *>::`vftable';
  v12->functionGetValue._Space._Pfn[1] = (void (__cdecl *)())this;
  v12->functionGetValue._Impl = (std::_Func_base<float,CarAvatar *> *)&v12->functionGetValue;
  v19 = v17;
  v17[0]._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_a80cb031c74f3ba0d0162590a41abf65_,0>,std::allocator<std::_Func_class<std::wstring,CarAvatar *,int>>,std::wstring,CarAvatar *,int>::`vftable';
  v17[0]._Impl = (std::_Func_base<float,CarAvatar *> *)v17;
  *(_DWORD *)&_defaultValue[24] = &std::_Func_impl<std::_Callable_obj<_lambda_51e5eac4130511a33de71c5add75cfa0_,0>,std::allocator<std::_Func_class<void,CarAvatar *,float>>,void,CarAvatar *,float>::`vftable';
  *(_DWORD *)&_defaultValue[40] = &_defaultValue[24];
  *(_DWORD *)&_defaultValue[16] = 0;
  v24 = -1;
  SetupElectronics::setSpinner(
    this,
    v12,
    *(std::function<float __cdecl(CarAvatar *)> *)_defaultValue,
    *(std::function<void __cdecl(CarAvatar *,float)> *)&_defaultValue[24],
    (std::function<std::wstring __cdecl(CarAvatar *,int)>)v17[0]);
  return v12;
}
void __usercall SetupElectronics::checkDrivingAssist(SetupElectronics *this@<ecx>, unsigned int a2@<ebx>)
{
  int v3; // eax
  bool v4; // cf
  int v5; // eax
  CarAvatar *v6; // ecx
  ACClient *v7; // eax
  std::wstring v8; // [esp-1Ch] [ebp-ACh] BYREF
  BOOL v9; // [esp-4h] [ebp-94h]
  std::wstring section; // [esp+Ch] [ebp-84h] BYREF
  std::wstring key; // [esp+24h] [ebp-6Ch] BYREF
  INIReaderDocuments ini; // [esp+3Ch] [ebp-54h] BYREF
  int v13; // [esp+8Ch] [ebp-4h]

  v9 = 0;
  v8._Myres = 7;
  v8._Mysize = 0;
  v8._Bx._Buf[0] = 0;
  std::wstring::assign(&v8, L"cfg/assists.ini", 0xFu);
  INIReaderDocuments::INIReaderDocuments(&ini, a2, v8, v9);
  v13 = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"TRACTION_CONTROL", 0x10u);
  LOBYTE(v13) = 1;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"ASSISTS", 7u);
  LOBYTE(v13) = 2;
  v3 = INIReader::getInt(&ini, &section, &key);
  v4 = section._Myres < 8;
  this->tcAssist = v3;
  if ( !v4 )
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
  std::wstring::assign(&key, L"ABS", 3u);
  LOBYTE(v13) = 3;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"ASSISTS", 7u);
  LOBYTE(v13) = 4;
  v5 = INIReader::getInt(&ini, &section, &key);
  v4 = section._Myres < 8;
  this->absAssist = v5;
  if ( !v4 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v6 = this->car;
  key._Bx._Buf[0] = 0;
  key._Myres = 7;
  key._Mysize = 0;
  v7 = v6->sim->client;
  if ( v7 )
  {
    this->absAssist = v7->serverDrivingAssists.abs;
    this->tcAssist = v6->sim->client->serverDrivingAssists.tc;
  }
  v13 = -1;
  INIReaderDocuments::~INIReaderDocuments(&ini);
}
std::wstring *SetupElectronics::getStringToSave(SetupElectronics *this, std::wstring *result)
{
  SetupElectronics *v2; // ebx
  std::wstring *v3; // edi
  SpinnerData **v4; // eax
  const std::wstring **v5; // esi
  int v6; // ebx
  unsigned int v7; // ebp
  const std::wstring *v8; // edi
  std::wostream *v9; // eax
  std::wostream *v10; // eax
  std::wostream *v11; // eax
  std::wostream *v12; // eax
  int v13; // eax
  std::wstring *v14; // esi
  std::wstring *v15; // eax
  int v16; // eax
  const std::wstring *v18; // [esp-Ch] [ebp-120h]
  int v19; // [esp-8h] [ebp-11Ch]
  std::wstring *v21; // [esp+20h] [ebp-F4h]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v22; // [esp+24h] [ebp-F0h] BYREF
  std::wstring v23; // [esp+D4h] [ebp-40h] BYREF
  std::wstring v24; // [esp+ECh] [ebp-28h] BYREF
  int v25; // [esp+110h] [ebp-4h]

  v2 = this;
  v3 = result;
  v21 = result;
  *(_DWORD *)v22.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
  *(_DWORD *)v22.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
  std::wios::wios(v22.gap68);
  v25 = 0;
  std::wiostream::basic_iostream<wchar_t>(&v22, &v22.gap10[8], 0);
  v25 = 1;
  *(_DWORD *)&v22.gap0[*(_DWORD *)(*(_DWORD *)v22.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(std::wstring **)((char *)&v21 + *(_DWORD *)(*(_DWORD *)v22.gap0 + 4)) = (std::wstring *)(*(_DWORD *)(*(_DWORD *)v22.gap0 + 4)
                                                                                           - 104);
  std::wstreambuf::wstreambuf(&v22.gap10[8]);
  *(_DWORD *)&v22.gap10[8] = &std::wstringbuf::`vftable';
  *(_DWORD *)&v22.gap10[64] = 0;
  *(_DWORD *)&v22.gap10[68] = 0;
  v4 = v2->spinnerDatas._Mylast;
  v5 = (const std::wstring **)v2->spinnerDatas._Myfirst;
  v25 = 3;
  v6 = 0;
  v7 = (unsigned int)((char *)v4 - (char *)v5 + 3) >> 2;
  if ( v5 > (const std::wstring **)v4 )
    v7 = 0;
  if ( v7 )
  {
    do
    {
      v8 = *v5;
      v18 = *v5;
      v9 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v22.gap10, "[");
      v10 = std::operator<<<wchar_t>(v9, v18);
      v11 = std::operator<<<wchar_t,std::char_traits<wchar_t>>(v10, "]");
      std::wostream::operator<<(v11);
      v19 = ksgui::Spinner::getValue((ksgui::Spinner *)v8[1]._Bx._Ptr);
      v12 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v22.gap10, "VALUE=");
      v13 = std::wostream::operator<<(v12, v19);
      std::wostream::operator<<(v13);
      ++v6;
      ++v5;
    }
    while ( v6 != v7 );
    v3 = v21;
  }
  v14 = SetupTab::getStringToSave(this, &v24);
  LOBYTE(v25) = 4;
  v15 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v22, &v23);
  LOBYTE(v25) = 5;
  std::operator+<wchar_t>(v3, v15, v14);
  if ( v23._Myres >= 8 )
    operator delete(v23._Bx._Ptr);
  v23._Myres = 7;
  v23._Mysize = 0;
  v23._Bx._Buf[0] = 0;
  if ( v24._Myres >= 8 )
    operator delete(v24._Bx._Ptr);
  v24._Myres = 7;
  v24._Bx._Buf[0] = 0;
  v24._Mysize = 0;
  v25 = -1;
  *(_DWORD *)&v22.gap0[*(_DWORD *)(*(_DWORD *)v22.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
  *(std::wstring **)((char *)&v21 + *(_DWORD *)(*(_DWORD *)v22.gap0 + 4)) = (std::wstring *)(*(_DWORD *)(*(_DWORD *)v22.gap0 + 4)
                                                                                           - 104);
  *(_DWORD *)&v22.gap10[8] = &std::wstringbuf::`vftable';
  if ( (v22.gap10[68] & 1) != 0 )
  {
    if ( std::wstreambuf::pptr(&v22.gap10[8]) )
      std::wstreambuf::epptr(&v22.gap10[8]);
    else
      std::wstreambuf::egptr(&v22.gap10[8]);
    std::wstreambuf::eback(&v22.gap10[8]);
    v16 = std::wstreambuf::eback(&v22.gap10[8]);
    operator delete(v16);
  }
  std::wstreambuf::setg(&v22.gap10[8], 0, 0, 0);
  std::wstreambuf::setp(&v22.gap10[8], 0, 0);
  *(_DWORD *)&v22.gap10[68] &= 0xFFFFFFFE;
  *(_DWORD *)&v22.gap10[64] = 0;
  std::wstreambuf::~wstreambuf<wchar_t,std::char_traits<wchar_t>>(&v22.gap10[8]);
  std::wiostream::~basic_iostream<wchar_t,std::char_traits<wchar_t>>(&v22.gap10[16]);
  std::wios::~wios<wchar_t,std::char_traits<wchar_t>>(v22.gap68);
  return v3;
}
void SetupElectronics::loadFromINI(SetupElectronics *this, INIReader *ini, bool isFixed)
{
  SetupElectronics *v3; // eax
  const std::wstring **v4; // esi
  SpinnerData **v5; // edi
  const std::wstring *v6; // ebx
  int v7; // eax
  ksgui::Spinner *v8; // [esp-Ch] [ebp-50h]
  int v10; // [esp+18h] [ebp-2Ch]
  std::wstring key; // [esp+1Ch] [ebp-28h] BYREF
  int v12; // [esp+40h] [ebp-4h]

  v3 = this;
  v4 = (const std::wstring **)this->spinnerDatas._Myfirst;
  v5 = this->spinnerDatas._Mylast;
  if ( v4 != (const std::wstring **)v5 )
  {
    do
    {
      v6 = *v4;
      if ( INIReader::hasSection(ini, *v4) )
      {
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"VALUE", 5u);
        v12 = 0;
        v7 = INIReader::getInt(ini, v6, &key);
        v10 = v7;
        v12 = -1;
        if ( key._Myres >= 8 )
        {
          operator delete(key._Bx._Ptr);
          v7 = v10;
        }
        key._Myres = 7;
        v8 = (ksgui::Spinner *)v6[1]._Bx._Ptr;
        key._Bx._Buf[0] = 0;
        key._Mysize = 0;
        SetupTab::setValueToSpinner(this, v8, 0, v7);
      }
      else
      {
        *((_BYTE *)v6[1]._Bx._Ptr + 348) = 0;
      }
      ++v4;
    }
    while ( v4 != (const std::wstring **)v5 );
    v3 = this;
  }
  SetupTab::loadFromINI(v3, ini, isFixed);
}
void SetupElectronics::onVisibleChanged(SetupElectronics *this, float value)
{
  RaceEngineer *v3; // ecx
  SpinnerData **v4; // esi
  SpinnerData **i; // edi
  SpinnerData *v6; // ebx
  std::_Func_base<float,CarAvatar *> *v7; // ecx
  double v8; // st7
  ksgui::Spinner *v9; // ecx

  if ( LOBYTE(value) )
  {
    v3 = this->car->raceEngineer._Myptr;
    if ( v3 )
    {
      if ( RaceEngineer::getCar(v3) )
      {
        v4 = this->spinnerDatas._Myfirst;
        for ( i = this->spinnerDatas._Mylast; v4 != i; ++v4 )
        {
          v6 = *v4;
          value = *(float *)&this->car;
          v7 = v6->functionGetValue._Impl;
          if ( !v7 )
          {
            std::_Xbad_function_call();
            JUMPOUT(0x65DAF6);
          }
          v8 = ((double (*)(std::_Func_base<float,CarAvatar *> *, float *))v7->_Do_call)(v7, &value);
          v9 = v6->spinner;
          value = v8;
          ksgui::Spinner::setValue(v9, (int)value);
        }
      }
    }
  }
}
void __userpurge SetupElectronics::render(SetupElectronics *this@<ecx>, __int64 a2@<esi:edi>, float dt)
{
  unsigned int v3; // eax
  unsigned int v4; // esi
  int v5; // edi
  unsigned int v6; // ebx
  ksgui::PopOver *v7; // ecx

  LODWORD(a2) = this;
  SetupTab::render(this, a2, dt);
  v3 = *(_DWORD *)(a2 + 332);
  v4 = *(_DWORD *)(a2 + 328);
  v5 = 0;
  v6 = (v3 - v4 + 3) >> 2;
  if ( v4 > v3 )
    v6 = 0;
  if ( v6 )
  {
    do
    {
      v7 = *(ksgui::PopOver **)(*(_DWORD *)(*(_DWORD *)v4 + 24) + 312);
      if ( v7->visible )
        ksgui::PopOver::renderPopOver(v7, dt);
      ++v5;
      v4 += 4;
    }
    while ( v5 != v6 );
  }
}
void SetupElectronics::resetToDefaultValues(SetupElectronics *this)
{
  int v2; // edi
  SpinnerData **v3; // esi
  unsigned int v4; // ebx
  ksgui::Spinner *v5; // ecx

  v2 = 0;
  v3 = this->spinnerDatas._Myfirst;
  v4 = (unsigned int)((char *)this->spinnerDatas._Mylast - (char *)v3 + 3) >> 2;
  if ( v3 > this->spinnerDatas._Mylast )
    v4 = 0;
  if ( v4 )
  {
    do
    {
      v5 = (*v3)->spinner;
      if ( !v5->isReadOnly )
        ksgui::Spinner::setValue(v5, (int)(*v3)->defaultValue);
      ++v2;
      ++v3;
    }
    while ( v2 != v4 );
  }
  SetupTab::resetToDefaultValues(this);
}
void SetupElectronics::setSpinner(SetupElectronics *this, SpinnerData *customSpinner, std::function<float __cdecl(CarAvatar *)> functionGetValue, std::function<void __cdecl(CarAvatar *,float)> functionSetValue, std::function<std::wstring __cdecl(CarAvatar *,int)> functionGetName)
{
  int v6; // eax
  ksgui::Spinner *v7; // edi
  const std::wstring *v8; // eax
  int i; // esi
  std::_Func_base<float,CarAvatar *>_vtbl *v10; // eax
  std::_Func_base<void,CarAvatar *,float>_vtbl *v11; // eax
  int v12; // ebx
  Font *v13; // eax
  Font *v14; // eax
  volatile signed __int32 *v15; // esi
  int v16; // [esp+0h] [ebp-B8h] BYREF
  _BYTE v17[28]; // [esp+4h] [ebp-B4h] BYREF
  void *v18; // [esp+20h] [ebp-98h]
  SetupElectronics **v19; // [esp+30h] [ebp-88h]
  std::shared_ptr<Font> v20; // [esp+34h] [ebp-84h] BYREF
  int v21; // [esp+3Ch] [ebp-7Ch]
  std::wstring helpText; // [esp+40h] [ebp-78h] BYREF
  char v23[8]; // [esp+58h] [ebp-60h] BYREF
  SetupElectronics::setSpinner::__l22::<lambda_20b38918d1b98043ae37afe93d1c6ee9> __that; // [esp+60h] [ebp-58h] BYREF
  int v25; // [esp+A0h] [ebp-18h]
  unsigned int v26; // [esp+A4h] [ebp-14h]
  int v27; // [esp+B4h] [ebp-4h]

  v6 = (int)customSpinner->minValue;
  v7 = customSpinner->spinner;
  *(_DWORD *)&v17[20] = customSpinner;
  *(_DWORD *)&v17[16] = L"HELP_";
  v27 = 2;
  v7->step = 1;
  v7->minValue = v6;
  v8 = std::operator+<wchar_t>(
         (std::wstring *)&__that.functionSetValue._Impl,
         *(const wchar_t **)&v17[16],
         *(const std::wstring **)&v17[20]);
  LOBYTE(v27) = 3;
  acLocaleGetSetupHelpText(&helpText, v8);
  LOBYTE(v27) = 5;
  if ( v26 >= 8 )
    operator delete(__that.functionSetValue._Impl);
  v26 = 7;
  v25 = 0;
  LOWORD(__that.functionSetValue._Impl) = 0;
  if ( std::wstring::compare(&helpText, 0, helpText._Mysize, word_17BE9D8, 0) )
  {
    *(_DWORD *)&v17[20] = 7;
    *(_DWORD *)&v17[16] = 0;
    *(_WORD *)v17 = 0;
    std::wstring::assign((std::wstring *)v17, &helpText, 0, 0xFFFFFFFF);
    ksgui::PopOver::setText(v7->popOver, *(std::wstring *)v17);
    *(_DWORD *)&v17[20] = 7;
    *(_DWORD *)&v17[16] = 0;
    *(_WORD *)v17 = 0;
    std::wstring::assign((std::wstring *)v17, &v7->name, 0, 0xFFFFFFFF);
    ksgui::PopOver::setLabelTitle(v7->popOver, *(std::wstring *)v17);
    v7->displayPopover = 1;
  }
  else
  {
    v7->displayPopover = 0;
  }
  for ( i = (int)customSpinner->minValue; (float)(customSpinner->maxValue + 1.0) > (float)i; ++i )
  {
    v16 = i;
    if ( functionGetName._Impl )
      std::_Func_class<std::wstring,CarAvatar *,int>::operator()(&functionGetName, (std::wstring *)v17, this->car, v16);
    else
      std::to_wstring((std::wstring *)v17, v16);
    ksgui::Spinner::addItem(v7, *(std::wstring *)v17);
  }
  ksgui::Spinner::setValue(v7, (int)customSpinner->defaultValue);
  __that.functionGetValue._Space._Pfn[2] = 0;
  *(_DWORD *)&v17[20] = this;
  v19 = (SetupElectronics **)v23;
  LOBYTE(v27) = 6;
  if ( functionGetValue._Impl )
  {
    v10 = functionGetValue._Impl->__vftable;
    if ( (std::function<float __cdecl(CarAvatar *)> *)functionGetValue._Impl == &functionGetValue )
      *(_DWORD *)&v17[16] = v23;
    else
      *(_DWORD *)&v17[16] = 0;
    __that.functionGetValue._Space._Pfn[2] = (void (__cdecl *)())((int (__stdcall *)(_DWORD))v10->_Copy)(*(_DWORD *)&v17[16]);
  }
  else
  {
    __that.functionGetValue._Space._Pfn[2] = 0;
  }
  __that.functionGetValue._Impl = (std::_Func_base<float,CarAvatar *> *)this;
  v19 = &__that.__this;
  __that.functionSetValue._Space._Pfn[2] = 0;
  LOBYTE(v27) = 8;
  if ( functionSetValue._Impl )
  {
    v11 = functionSetValue._Impl->__vftable;
    if ( (std::function<void __cdecl(CarAvatar *,float)> *)functionSetValue._Impl == &functionSetValue )
      *(_DWORD *)&v17[16] = &__that.__this;
    else
      *(_DWORD *)&v17[16] = 0;
    __that.functionSetValue._Space._Pfn[2] = (void (__cdecl *)())((int (__stdcall *)(_DWORD))v11->_Copy)(*(_DWORD *)&v17[16]);
  }
  else
  {
    __that.functionSetValue._Space._Pfn[2] = 0;
  }
  v19 = (SetupElectronics **)&v16;
  *(_DWORD *)&v17[12] = 0;
  LOBYTE(v27) = 10;
  v12 = operator new(72);
  if ( !v12 )
    std::_Xbad_alloc();
  *(_DWORD *)&helpText._Bx._Alias[4] = v12;
  v21 = v12;
  *(_DWORD *)v12 = &std::_Func_impl<std::_Callable_obj<_lambda_20b38918d1b98043ae37afe93d1c6ee9_,0>,std::allocator<std::_Func_class<void,ksgui::OnSpinnerValueChanged const &>>,void,ksgui::OnSpinnerValueChanged const &>::`vftable';
  lambda_20b38918d1b98043ae37afe93d1c6ee9_::_lambda_20b38918d1b98043ae37afe93d1c6ee9_(
    (SetupElectronics::setSpinner::__l22::<lambda_20b38918d1b98043ae37afe93d1c6ee9> *)(v12 + 8),
    &__that);
  *(_DWORD *)&v17[12] = v12;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v7->evOnValueChanged,
    *(std::function<void __cdecl(OnPhysicsStepCompleted const &)> *)&v17[4],
    v18);
  lambda_20b38918d1b98043ae37afe93d1c6ee9_::__lambda_20b38918d1b98043ae37afe93d1c6ee9_(&__that);
  ksgui::Spinner::setDrawArrows(v7, 1);
  ((void (*)(ksgui::Spinner *, int, int))v7->setSize)(v7, 1127743488, 1101529088);
  v13 = (Font *)operator new(24);
  v20._Ptr = v13;
  LOBYTE(v27) = 15;
  if ( v13 )
    Font::Font(v13, eFontProportional, 12.0, 0, 0);
  else
    v14 = 0;
  LOBYTE(v27) = 5;
  v20 = 0i64;
  std::shared_ptr<Font>::_Resetp<Font>(&v20, v14);
  v15 = (volatile signed __int32 *)v7->font._Rep;
  v7->font = v20;
  if ( v15 )
  {
    if ( !_InterlockedExchangeAdd(v15 + 1, 0xFFFFFFFF) )
    {
      (**(void (***)(volatile signed __int32 *))v15)(v15);
      if ( !_InterlockedDecrement(v15 + 2) )
        (*(void (**)(volatile signed __int32 *))(*v15 + 4))(v15);
    }
  }
  if ( helpText._Myres >= 8 )
    operator delete(helpText._Bx._Ptr);
  helpText._Myres = 7;
  helpText._Mysize = 0;
  helpText._Bx._Buf[0] = 0;
  LOBYTE(v27) = 1;
  if ( functionGetValue._Impl )
  {
    ((void (__stdcall *)(bool))functionGetValue._Impl->_Delete_this)(functionGetValue._Impl != (std::_Func_base<float,CarAvatar *> *)&functionGetValue);
    functionGetValue._Impl = 0;
  }
  LOBYTE(v27) = 0;
  if ( functionSetValue._Impl )
  {
    ((void (__stdcall *)(bool))functionSetValue._Impl->_Delete_this)(functionSetValue._Impl != (std::_Func_base<void,CarAvatar *,float> *)&functionSetValue);
    functionSetValue._Impl = 0;
  }
  v27 = -1;
  if ( functionGetName._Impl )
    ((void (__stdcall *)(bool))functionGetName._Impl->_Delete_this)(functionGetName._Impl != (std::_Func_base<std::wstring,CarAvatar *,int> *)&functionGetName);
}
