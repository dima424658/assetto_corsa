#include "autoblip.h"
void AutoBlip::init(AutoBlip *this, Car *acar)
{
  Event<SessionInfo> *v3; // ecx
  _BYTE v4[28]; // [esp-1Ch] [ebp-34h] BYREF
  int v5; // [esp+14h] [ebp-4h]

  this->car = acar;
  this->isActive = 1;
  *(_DWORD *)v4 = -1;
  this->blipStartTime = 0.0;
  *(_DWORD *)&v4[24] = 7;
  *(_DWORD *)&v4[20] = 0;
  *(_WORD *)&v4[4] = 0;
  std::wstring::assign((std::wstring *)&v4[4], &acar->unixName, 0, *(unsigned int *)v4);
  AutoBlip::loadINI(this, *(std::wstring *)&v4[4]);
  *(_DWORD *)&v4[24] = this;
  *(_DWORD *)v4 = &std::_Func_impl<std::_Callable_obj<_lambda_459db49854199dd1a98d3500d7edae84_,0>,std::allocator<std::_Func_class<void,OnGearRequestEvent const &>>,void,OnGearRequestEvent const &>::`vftable';
  *(_DWORD *)&v4[4] = this;
  *(_DWORD *)&v4[16] = v4;
  v3 = (Event<SessionInfo> *)&this->car->drivetrain.evOnGearRequest;
  v5 = -1;
  Event<float>::addHandler(v3, *(std::function<void __cdecl(SessionInfo const &)> *)v4, this);
}
void AutoBlip::loadINI(AutoBlip *this, std::wstring carModel)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  Car *v5; // ecx
  double v6; // st7
  bool v7; // cf
  float ref; // [esp+0h] [ebp-FCh]
  float refa; // [esp+0h] [ebp-FCh]
  float refb; // [esp+0h] [ebp-FCh]
  float level; // [esp+14h] [ebp-E8h]
  float levela; // [esp+14h] [ebp-E8h]
  std::wstring section; // [esp+18h] [ebp-E4h] BYREF
  std::wstring key; // [esp+30h] [ebp-CCh] BYREF
  std::wstring _Left; // [esp+48h] [ebp-B4h] BYREF
  std::wstring filename; // [esp+60h] [ebp-9Ch] BYREF
  std::wstring v17; // [esp+78h] [ebp-84h] BYREF
  std::wstring result; // [esp+90h] [ebp-6Ch] BYREF
  INIReader r; // [esp+A8h] [ebp-54h] BYREF
  int v20; // [esp+F8h] [ebp-4h]

  v20 = 0;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  LOBYTE(v20) = 1;
  v3 = std::operator+<wchar_t>(&result, &_Left, &carModel);
  LOBYTE(v20) = 2;
  v4 = std::operator+<wchar_t>(&v17, v3, L"/data/drivetrain.ini");
  v5 = this->car;
  LOBYTE(v20) = 3;
  Car::getConfigPath(v5, &filename, v4);
  if ( v17._Myres >= 8 )
    operator delete(v17._Bx._Ptr);
  v17._Myres = 7;
  v17._Mysize = 0;
  v17._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v20) = 7;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Bx._Buf[0] = 0;
  _Left._Mysize = 0;
  INIReader::INIReader(&r, &filename);
  LOBYTE(v20) = 8;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"LEVEL", 5u);
  LOBYTE(v20) = 9;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"AUTOBLIP", 8u);
  LOBYTE(v20) = 10;
  level = INIReader::getFloat(&r, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v20) = 8;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  Curve::addValue(&this->blipProfile, 0.0, 0.0);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"POINT_0", 7u);
  LOBYTE(v20) = 11;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"AUTOBLIP", 8u);
  LOBYTE(v20) = 12;
  ref = INIReader::getFloat(&r, &section, &key);
  Curve::addValue(&this->blipProfile, ref, level);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v20) = 8;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"POINT_1", 7u);
  LOBYTE(v20) = 13;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"AUTOBLIP", 8u);
  LOBYTE(v20) = 14;
  refa = INIReader::getFloat(&r, &section, &key);
  Curve::addValue(&this->blipProfile, refa, level);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v20) = 8;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"POINT_2", 7u);
  LOBYTE(v20) = 15;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"AUTOBLIP", 8u);
  LOBYTE(v20) = 16;
  refb = INIReader::getFloat(&r, &section, &key);
  Curve::addValue(&this->blipProfile, refb, 0.0);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v20) = 8;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v6 = Curve::getMaxReference(&this->blipProfile);
  key._Myres = 7;
  key._Mysize = 0;
  this->blipPerformTime = v6;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"ELECTRONIC", 0xAu);
  LOBYTE(v20) = 17;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"AUTOBLIP", 8u);
  LOBYTE(v20) = 18;
  levela = INIReader::getFloat(&r, &section, &key);
  v7 = section._Myres < 8;
  this->isElectronic = levela != 0.0;
  if ( !v7 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  LOBYTE(v20) = 7;
  INIReader::~INIReader(&r);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  if ( carModel._Myres >= 8 )
    operator delete(carModel._Bx._Ptr);
}
void AutoBlip::step(AutoBlip *this, float dt)
{
  char v3; // dl
  Car *v4; // ecx
  Speed *v5; // eax
  bool v6; // bl
  float v7; // xmm1_4
  float v8; // xmm0_4
  float ref; // [esp+0h] [ebp-20h]
  float refa; // [esp+0h] [ebp-20h]
  Speed result; // [esp+10h] [ebp-10h] BYREF
  float v12; // [esp+14h] [ebp-Ch]
  long double v13; // [esp+18h] [ebp-8h]

  v3 = 0;
  v12 = 0.0;
  v4 = this->car;
  v6 = 1;
  if ( !v4->isControlsLocked )
  {
    v5 = Car::getSpeed(v4, &result);
    v3 = 1;
    if ( (float)(v5->value * 3.5999999) >= 5.0 )
      v6 = 0;
  }
  if ( (v3 & 1) != 0 )
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  if ( !v6 && (this->isElectronic || this->isActive) )
  {
    v13 = this->car->ksPhysics->physicsTime - this->blipStartTime;
    if ( v13 >= 0.0 && this->blipPerformTime > v13 && Curve::getCount(&this->blipProfile) == 4 )
    {
      result.value = this->car->controls.gas;
      ref = v13;
      v12 = Curve::getValue(&this->blipProfile, ref);
      if ( result.value <= v12 )
      {
        refa = v13;
        v12 = Curve::getValue(&this->blipProfile, refa);
        v7 = v12;
      }
      else
      {
        v7 = this->car->controls.gas;
      }
      v8 = FLOAT_1_0;
      if ( v7 <= 1.0 )
      {
        v8 = 0.0;
        if ( v7 >= 0.0 )
          v8 = v7;
      }
      this->car->controls.gas = v8;
    }
  }
}
