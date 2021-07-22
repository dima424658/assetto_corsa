#include "tractioncontrol.h
void TractionControl::~TractionControl(TractionControl *this)
{
  Curve::~Curve(&this->valueCurve);
}
void TractionControl::cycleMode(TractionControl *this, int value)
{
  unsigned int v3; // et2
  unsigned int v4; // eax
  unsigned int v5; // eax

  if ( this->isPresent )
  {
    if ( !Curve::getCount(&this->valueCurve) )
    {
      this->isActive = !this->isActive;
      return;
    }
    if ( this->isActive )
    {
      if ( value > 0 )
      {
        v3 = (this->currentMode + 1) % Curve::getCount(&this->valueCurve);
        this->currentMode = v3;
        if ( !v3 )
        {
          this->isActive = 0;
          return;
        }
        goto LABEL_15;
      }
      v4 = this->currentMode;
      if ( !v4 )
      {
        this->isActive = 0;
        return;
      }
    }
    else
    {
      this->isActive = 1;
      if ( value > 0 )
      {
        v5 = 0;
LABEL_14:
        this->currentMode = v5;
LABEL_15:
        this->slipRatioLimit = Curve::getValue(&this->valueCurve, (float)this->currentMode);
        return;
      }
      v4 = Curve::getCount(&this->valueCurve);
    }
    v5 = v4 - 1;
    goto LABEL_14;
  }
}
std::pair<unsigned int,unsigned int> *TractionControl::getCurrentMode(TractionControl *this, std::pair<unsigned int,unsigned int> *result)
{
  std::pair<unsigned int,unsigned int> *v3; // eax
  unsigned int v4; // edx

  if ( this->isActive )
  {
    if ( Curve::getCount(&this->valueCurve) )
    {
      v4 = Curve::getCount(&this->valueCurve);
      v3 = result;
      result->first = this->currentMode + 1;
      result->second = v4;
    }
    else
    {
      v3 = result;
      result->first = 1;
      result->second = 1;
    }
  }
  else
  {
    v3 = result;
    result->first = 0;
    result->second = 0;
  }
  return v3;
}
void TractionControl::init(TractionControl *this, Car *acar)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  Car *v5; // ecx
  double v6; // st7
  bool v7; // cf
  std::wstring *v8; // eax
  bool v9; // bl
  std::wstring *v10; // esi
  std::wstring *v11; // ecx
  std::wstring *v12; // eax
  std::wstring *v13; // eax
  std::wstring *v14; // eax
  const std::wstring *v15; // eax
  signed int v16; // esi
  int v17; // eax
  int v18; // eax
  unsigned int v19; // [esp-8h] [ebp-164h]
  float ms; // [esp+0h] [ebp-15Ch]
  float lfr; // [esp+14h] [ebp-148h] BYREF
  std::wstring section; // [esp+18h] [ebp-144h] BYREF
  std::wstring key; // [esp+30h] [ebp-12Ch] BYREF
  std::wstring v24; // [esp+48h] [ebp-114h] BYREF
  std::wstring v25; // [esp+60h] [ebp-FCh] BYREF
  std::wstring v26; // [esp+78h] [ebp-E4h] BYREF
  std::wstring v27; // [esp+90h] [ebp-CCh] BYREF
  std::wstring result; // [esp+A8h] [ebp-B4h] BYREF
  std::wstring v29; // [esp+C0h] [ebp-9Ch] BYREF
  std::wstring v30; // [esp+D8h] [ebp-84h] BYREF
  std::wstring abs_filename; // [esp+F0h] [ebp-6Ch] BYREF
  INIReader r; // [esp+108h] [ebp-54h] BYREF
  int v33; // [esp+158h] [ebp-4h]

  this->car = acar;
  this->currentMode = 0;
  strcpy((char *)&this->slipRatioLimit, "��L>");
  *(_WORD *)&this->isPresent = 257;
  this->frequency = 0.050000001;
  this->timeAccumulator = 0.0;
  v3 = std::operator+<wchar_t>(&result, L"content/cars/", &acar->unixName);
  v33 = 0;
  v4 = std::operator+<wchar_t>(&v27, v3, L"/data/electronics.ini");
  v5 = this->car;
  LOBYTE(v33) = 1;
  Car::getConfigPath(v5, &abs_filename, v4);
  if ( v27._Myres >= 8 )
    operator delete(v27._Bx._Ptr);
  v27._Myres = 7;
  v27._Mysize = 0;
  v27._Bx._Buf[0] = 0;
  LOBYTE(v33) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  INIReader::INIReader(&r, &abs_filename);
  LOBYTE(v33) = 5;
  if ( r.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SLIP_RATIO_LIMIT", 0x10u);
    LOBYTE(v33) = 6;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"TRACTION_CONTROL", 0x10u);
    LOBYTE(v33) = 7;
    v6 = INIReader::getFloat(&r, &section, &key);
    v7 = section._Myres < 8;
    this->slipRatioLimit = v6;
    if ( !v7 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v33) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MIN_SPEED_KMH", 0xDu);
    LOBYTE(v33) = 8;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"TRACTION_CONTROL", 0x10u);
    LOBYTE(v33) = 9;
    ms = INIReader::getFloat(&r, &section, &key);
    this->minSpeedMS = Speed::fromKMH((Speed *)&lfr, ms)->value;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&lfr);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v33) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"CURVE", 5u);
    LOBYTE(v33) = 10;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"TRACTION_CONTROL", 0x10u);
    LOBYTE(v33) = 11;
    v8 = INIReader::getString(&r, &v24, &section, &key);
    v19 = v8->_Mysize;
    LOBYTE(v33) = 12;
    v9 = std::wstring::compare(v8, 0, v19, word_17BE9D8, 0) != 0;
    if ( v24._Myres >= 8 )
      operator delete(v24._Bx._Ptr);
    v24._Myres = 7;
    v24._Mysize = 0;
    v24._Bx._Buf[0] = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v33) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v9 )
    {
      std::wstring::wstring(&v30, L"CURVE");
      LOBYTE(v33) = 13;
      std::wstring::wstring(&key, L"TRACTION_CONTROL");
      LOBYTE(v33) = 14;
      v10 = INIReader::getString(&r, &v26, &key, &v30);
      LOBYTE(v33) = 15;
      std::wstring::wstring(&v25, L"content/cars/");
      v11 = &this->car->unixName;
      LOBYTE(v33) = 16;
      v13 = std::operator+<wchar_t>(&v29, v12, v11);
      LOBYTE(v33) = 17;
      v14 = std::operator+<wchar_t>(&section, v13, L"/data/");
      LOBYTE(v33) = 18;
      v15 = std::operator+<wchar_t>(&v24, v14, v10);
      LOBYTE(v33) = 19;
      Curve::load(&this->valueCurve, v15);
      if ( v24._Myres >= 8 )
        operator delete(v24._Bx._Ptr);
      v24._Myres = 7;
      v24._Mysize = 0;
      v24._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( v29._Myres >= 8 )
        operator delete(v29._Bx._Ptr);
      v29._Myres = 7;
      v29._Mysize = 0;
      v29._Bx._Buf[0] = 0;
      if ( v25._Myres >= 8 )
        operator delete(v25._Bx._Ptr);
      v25._Myres = 7;
      v25._Mysize = 0;
      v25._Bx._Buf[0] = 0;
      if ( v26._Myres >= 8 )
        operator delete(v26._Bx._Ptr);
      v26._Myres = 7;
      v26._Mysize = 0;
      v26._Bx._Buf[0] = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v33) = 5;
      if ( v30._Myres >= 8 )
        operator delete(v30._Bx._Ptr);
      v16 = 0;
      if ( Curve::getCount(&this->valueCurve) > 0 )
      {
        while ( 1 )
        {
          lfr = Curve::getValue(&this->valueCurve, (float)v16);
          if ( lfr == this->slipRatioLimit )
            break;
          if ( ++v16 >= Curve::getCount(&this->valueCurve) )
            goto LABEL_40;
        }
        this->currentMode = v16;
      }
    }
LABEL_40:
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"PRESENT", 7u);
    LOBYTE(v33) = 20;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"TRACTION_CONTROL", 0x10u);
    LOBYTE(v33) = 21;
    v17 = INIReader::getInt(&r, &section, &key);
    v7 = section._Myres < 8;
    this->isPresent = v17 != 0;
    if ( !v7 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v33) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ACTIVE", 6u);
    LOBYTE(v33) = 22;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"TRACTION_CONTROL", 0x10u);
    LOBYTE(v33) = 23;
    v18 = INIReader::getInt(&r, &section, &key);
    v7 = section._Myres < 8;
    this->isActive = v18 != 0;
    if ( !v7 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v33) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"RATE_HZ", 7u);
    LOBYTE(v33) = 24;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"TRACTION_CONTROL", 0x10u);
    LOBYTE(v33) = 25;
    lfr = INIReader::getFloat(&r, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( lfr != 0.0 )
      this->frequency = 1.0 / lfr;
  }
  LOBYTE(v33) = 4;
  INIReader::~INIReader(&r);
  if ( abs_filename._Myres >= 8 )
    operator delete(abs_filename._Bx._Ptr);
}
void TractionControl::step(TractionControl *this, float dt)
{
  char v2; // bl
  vec3f *v4; // eax
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  Car *v9; // eax
  float v10; // xmm0_4
  Speed v11; // [esp+8h] [ebp-10h] BYREF
  vec3f result; // [esp+Ch] [ebp-Ch] BYREF
  char dta; // [esp+1Ch] [ebp+4h]

  v2 = 0;
  LODWORD(v11.value) = 0;
  if ( (dword_186F1FC & 1) == 0 )
  {
    perfCounter_39.name = "TractionControl::step";
    dword_186F1FC |= 1u;
    perfCounter_39.group = Physics;
    perfCounter_39.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"TractionControl::step" | 0xFF000000;
  }
  if ( this->isPresent )
  {
    v4 = Car::getVelocity(this->car, &result);
    v5 = (float)((float)(v4->x * v4->x) + (float)(v4->y * v4->y)) + (float)(v4->z * v4->z);
    if ( v5 == 0.0 )
      v6 = 0.0;
    else
      v6 = fsqrt(v5);
    if ( this->minSpeedMS <= v6 )
    {
      v7 = this->timeAccumulator + dt;
      v8 = this->frequency;
      this->timeAccumulator = v7;
      if ( v8 <= v7 )
      {
        this->timeAccumulator = 0.0;
        if ( !this->isActive || (v2 = 1, dta = 1, Car::getSpeed(this->car, &v11)->value <= 1.0) )
          dta = 0;
        if ( (v2 & 1) != 0 )
          dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v11);
        if ( dta )
        {
          v9 = this->car;
          v10 = 0.0;
          if ( v9->tyres[0].driven && v9->tyres[0].status.slipRatio > 0.0 )
            v10 = v9->tyres[0].status.slipRatio;
          if ( v9->tyres[1].driven && v9->tyres[1].status.slipRatio > v10 )
            v10 = v9->tyres[1].status.slipRatio;
          if ( v9->tyres[2].driven && v9->tyres[2].status.slipRatio > v10 )
            v10 = v9->tyres[2].status.slipRatio;
          if ( v9->tyres[3].driven && v9->tyres[3].status.slipRatio > v10 )
            v10 = v9->tyres[3].status.slipRatio;
          if ( v10 > this->slipRatioLimit )
            v9->drivetrain.acEngine.electronicOverride = 0.0;
        }
        this->isInAction = this->car->drivetrain.acEngine.electronicOverride != 1.0;
      }
      else if ( this->isInAction )
      {
        this->car->drivetrain.acEngine.electronicOverride = 0.0;
      }
    }
    else
    {
      this->isInAction = 0;
      this->timeAccumulator = 0.0;
    }
  }
  else
  {
    this->isInAction = 0;
    this->isActive = 0;
  }
}
