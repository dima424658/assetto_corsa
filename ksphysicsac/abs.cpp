#include "abs.h"
void ABS::~ABS(ABS *this)
{
  Curve::~Curve(&this->valueCurve);
}
void ABS::cycleMode(ABS *this, int value)
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
std::pair<unsigned int,unsigned int> *ABS::getCurrentMode(ABS *this, std::pair<unsigned int,unsigned int> *result)
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
void ABS::init(ABS *this, Car *acar)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  Car *v5; // ecx
  const unsigned __int16 *v6; // edi
  bool v7; // al
  unsigned int v8; // ecx
  double v9; // st7
  bool v10; // cf
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // ecx
  int v14; // eax
  unsigned int v15; // ecx
  std::wstring *v16; // eax
  std::wstring *v17; // esi
  std::wstring *v18; // ecx
  std::wstring *v19; // eax
  std::wstring *v20; // eax
  std::wstring *v21; // eax
  const std::wstring *v22; // eax
  signed int v23; // esi
  unsigned int v24; // ecx
  unsigned int v25; // ecx
  int v26; // eax
  int v27; // eax
  std::wstring *v28; // eax
  std::wstring *v29; // eax
  std::wstring *v30; // eax
  unsigned int v31; // [esp-8h] [ebp-170h]
  bool v32; // [esp+1Bh] [ebp-14Dh]
  bool v33; // [esp+1Bh] [ebp-14Dh]
  float lfra; // [esp+1Ch] [ebp-14Ch]
  float lfr; // [esp+1Ch] [ebp-14Ch]
  int v36; // [esp+20h] [ebp-148h]
  std::wstring section; // [esp+24h] [ebp-144h] BYREF
  std::wstring key; // [esp+3Ch] [ebp-12Ch] BYREF
  std::wstring v39; // [esp+54h] [ebp-114h] BYREF
  std::wstring v40; // [esp+6Ch] [ebp-FCh] BYREF
  std::wstring v41; // [esp+84h] [ebp-E4h] BYREF
  std::wstring v42; // [esp+9Ch] [ebp-CCh] BYREF
  std::wstring result; // [esp+B4h] [ebp-B4h] BYREF
  std::wstring v44; // [esp+CCh] [ebp-9Ch] BYREF
  std::wstring v45; // [esp+E4h] [ebp-84h] BYREF
  std::wstring abs_filename; // [esp+FCh] [ebp-6Ch] BYREF
  INIReader r; // [esp+114h] [ebp-54h] BYREF
  int v48; // [esp+164h] [ebp-4h]

  this->car = acar;
  this->currentMode = 0;
  this->slipRatioLimit = 0.2;
  *(_WORD *)&this->isPresent = 257;
  this->timeAccumulator = 0.0;
  this->frequency = 0.050000001;
  v3 = std::operator+<wchar_t>(&result, L"content/cars/", &acar->unixName);
  v48 = 0;
  v4 = std::operator+<wchar_t>(&v44, v3, L"/data/electronics.ini");
  v5 = this->car;
  LOBYTE(v48) = 1;
  Car::getConfigPath(v5, &abs_filename, v4);
  if ( v44._Myres >= 8 )
    operator delete(v44._Bx._Ptr);
  v44._Myres = 7;
  v44._Mysize = 0;
  v44._Bx._Buf[0] = 0;
  LOBYTE(v48) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  INIReader::INIReader(&r, &abs_filename);
  LOBYTE(v48) = 5;
  if ( r.ready )
  {
    v36 = 1;
    section._Myres = 7;
    v6 = L"ABS";
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"ABS_V2", 6u);
    LOBYTE(v48) = 6;
    v7 = INIReader::hasSection(&r, &section);
    v32 = v7;
    LOBYTE(v48) = 5;
    if ( section._Myres >= 8 )
    {
      operator delete(section._Bx._Ptr);
      v7 = v32;
    }
    if ( v7 )
    {
      v36 = 2;
      v6 = L"ABS_V2";
    }
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SLIP_RATIO_LIMIT", 0x10u);
    LOBYTE(v48) = 7;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( *v6 )
      v8 = wcslen(v6);
    else
      v8 = 0;
    std::wstring::assign(&section, v6, v8);
    LOBYTE(v48) = 8;
    v9 = INIReader::getFloat(&r, &section, &key);
    v10 = section._Myres < 8;
    this->slipRatioLimit = v9;
    if ( !v10 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v48) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"PRESENT", 7u);
    LOBYTE(v48) = 9;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( *v6 )
      v11 = wcslen(v6);
    else
      v11 = 0;
    std::wstring::assign(&section, v6, v11);
    LOBYTE(v48) = 10;
    v12 = INIReader::getInt(&r, &section, &key);
    v10 = section._Myres < 8;
    this->isPresent = v12 != 0;
    if ( !v10 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v48) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ACTIVE", 6u);
    LOBYTE(v48) = 11;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( *v6 )
      v13 = wcslen(v6);
    else
      v13 = 0;
    std::wstring::assign(&section, v6, v13);
    LOBYTE(v48) = 12;
    v14 = INIReader::getInt(&r, &section, &key);
    v10 = section._Myres < 8;
    this->isActive = v14 != 0;
    if ( !v10 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v48) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"CURVE", 5u);
    LOBYTE(v48) = 13;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( *v6 )
      v15 = wcslen(v6);
    else
      v15 = 0;
    std::wstring::assign(&section, v6, v15);
    LOBYTE(v48) = 14;
    v16 = INIReader::getString(&r, &v39, &section, &key);
    v31 = v16->_Mysize;
    LOBYTE(v48) = 15;
    v33 = std::wstring::compare(v16, 0, v31, word_17BE9D8, 0) != 0;
    if ( v39._Myres >= 8 )
      operator delete(v39._Bx._Ptr);
    v39._Myres = 7;
    v39._Mysize = 0;
    v39._Bx._Buf[0] = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v48) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v33 )
    {
      std::wstring::wstring(&v42, L"CURVE");
      LOBYTE(v48) = 16;
      std::wstring::wstring(&key, L"ABS");
      LOBYTE(v48) = 17;
      v17 = INIReader::getString(&r, &v41, &key, &v42);
      LOBYTE(v48) = 18;
      std::wstring::wstring(&v40, L"content/cars/");
      v18 = &this->car->unixName;
      LOBYTE(v48) = 19;
      v20 = std::operator+<wchar_t>(&v45, v19, v18);
      LOBYTE(v48) = 20;
      v21 = std::operator+<wchar_t>(&section, v20, L"/data/");
      LOBYTE(v48) = 21;
      v22 = std::operator+<wchar_t>(&v39, v21, v17);
      LOBYTE(v48) = 22;
      Curve::load(&this->valueCurve, v22);
      if ( v39._Myres >= 8 )
        operator delete(v39._Bx._Ptr);
      v39._Myres = 7;
      v39._Mysize = 0;
      v39._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( v45._Myres >= 8 )
        operator delete(v45._Bx._Ptr);
      v45._Myres = 7;
      v45._Mysize = 0;
      v45._Bx._Buf[0] = 0;
      if ( v40._Myres >= 8 )
        operator delete(v40._Bx._Ptr);
      v40._Myres = 7;
      v40._Mysize = 0;
      v40._Bx._Buf[0] = 0;
      if ( v41._Myres >= 8 )
        operator delete(v41._Bx._Ptr);
      v41._Myres = 7;
      v41._Mysize = 0;
      v41._Bx._Buf[0] = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v48) = 5;
      if ( v42._Myres >= 8 )
        operator delete(v42._Bx._Ptr);
      v23 = 0;
      if ( Curve::getCount(&this->valueCurve) > 0 )
      {
        while ( 1 )
        {
          lfra = Curve::getValue(&this->valueCurve, (float)v23);
          if ( lfra == this->slipRatioLimit )
            break;
          if ( ++v23 >= Curve::getCount(&this->valueCurve) )
            goto LABEL_60;
        }
        this->currentMode = v23;
      }
    }
LABEL_60:
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"RATE_HZ", 7u);
    LOBYTE(v48) = 23;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( *v6 )
      v24 = wcslen(v6);
    else
      v24 = 0;
    std::wstring::assign(&section, v6, v24);
    LOBYTE(v48) = 24;
    lfr = INIReader::getFloat(&r, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v48) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( lfr != 0.0 )
      this->frequency = 1.0 / lfr;
    if ( v36 >= 2 )
    {
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, L"CHANNELS", 8u);
      LOBYTE(v48) = 25;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( *v6 )
        v25 = wcslen(v6);
      else
        v25 = 0;
      std::wstring::assign(&section, v6, v25);
      LOBYTE(v48) = 26;
      v26 = INIReader::getInt(&r, &section, &key);
      v10 = section._Myres < 8;
      this->channels = v26;
      if ( !v10 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v48) = 5;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      v27 = this->channels;
      if ( v27 != 1 && v27 != 2 && v27 != 4 )
      {
        v28 = std::to_wstring(&v42, this->channels);
        LOBYTE(v48) = 27;
        v29 = std::operator+<wchar_t>(&v40, L"ERROR: [ABS_V2] CHANNELS value ", v28);
        LOBYTE(v48) = 28;
        v30 = std::operator+<wchar_t>(&v41, v29, L" is not valid, only 1, 2 and 4 supported");
        v10 = v30->_Myres < 8;
        LOBYTE(v48) = 29;
        if ( !v10 )
          v30 = (std::wstring *)v30->_Bx._Ptr;
        _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v30->_Bx._Buf);
        ksGenerateCrash();
        if ( v41._Myres >= 8 )
          operator delete(v41._Bx._Ptr);
        v41._Myres = 7;
        v41._Mysize = 0;
        v41._Bx._Buf[0] = 0;
        if ( v40._Myres >= 8 )
          operator delete(v40._Bx._Ptr);
        v40._Myres = 7;
        v40._Mysize = 0;
        v40._Bx._Buf[0] = 0;
        if ( v42._Myres >= 8 )
          operator delete(v42._Bx._Ptr);
      }
    }
  }
  LOBYTE(v48) = 4;
  INIReader::~INIReader(&r);
  if ( abs_filename._Myres >= 8 )
    operator delete(abs_filename._Bx._Ptr);
}
bool ABS::isInAction(ABS *this)
{
  float *v1; // ecx

  v1 = (float *)this->car;
  return v1[716] != 1.0 || v1[1124] != 1.0 || v1[1532] != 1.0 || v1[1940] != 1.0;
}
void ABS::step(ABS *this, float td)
{
  char v3; // cl
  float v4; // xmm1_4
  float v5; // xmm0_4
  bool v6; // al
  Speed *v7; // eax
  Car *v8; // eax
  Car *v9; // eax
  Car *v10; // eax
  Car *v11; // eax
  Car *v12; // eax
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float *v16; // eax
  float v17; // xmm1_4
  float v18; // xmm2_4
  float v19; // xmm0_4
  Speed result; // [esp+0h] [ebp-4h] BYREF
  char td_3; // [esp+Bh] [ebp+7h]

  v3 = 0;
  LODWORD(result.value) = 0;
  v4 = td + this->timeAccumulator;
  v5 = this->frequency;
  this->timeAccumulator = v4;
  if ( v5 <= v4 )
  {
    this->timeAccumulator = 0.0;
    v6 = this->isActive && this->isPresent;
    this->isActive = v6;
    if ( !v6 || (v7 = Car::getSpeed(this->car, &result), v3 = 1, td_3 = 1, (float)(v7->value * 3.5999999) <= 20.0) )
      td_3 = 0;
    if ( (v3 & 1) != 0 )
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
    if ( td_3 )
    {
      switch ( this->channels )
      {
        case 1:
          v16 = (float *)this->car;
          LODWORD(v17) = LODWORD(this->slipRatioLimit) ^ _xmm;
          v18 = FLOAT_1_0;
          if ( v17 > v16[646] || v17 > v16[1054] )
            v19 = 0.0;
          else
            v19 = FLOAT_1_0;
          if ( v17 > v16[1462] || v17 > v16[1870] )
            v18 = 0.0;
          if ( v18 <= v19 )
            v19 = v18;
          v16[716] = v19;
          this->car->tyres[1].absOverride = v19;
          this->car->tyres[2].absOverride = v19;
          this->car->tyres[3].absOverride = v19;
          break;
        case 2:
          v12 = this->car;
          LODWORD(v13) = LODWORD(this->slipRatioLimit) ^ _xmm;
          v14 = FLOAT_1_0;
          if ( v13 > v12->tyres[0].status.slipRatio || v13 > v12->tyres[1].status.slipRatio )
            v15 = 0.0;
          else
            v15 = FLOAT_1_0;
          if ( v13 > v12->tyres[2].status.slipRatio || v13 > v12->tyres[3].status.slipRatio )
            v14 = 0.0;
          v12->tyres[0].absOverride = v15;
          this->car->tyres[1].absOverride = v15;
          this->car->tyres[2].absOverride = v14;
          this->car->tyres[3].absOverride = v14;
          break;
        case 4:
          v8 = this->car;
          if ( COERCE_FLOAT(LODWORD(this->slipRatioLimit) ^ _xmm) <= v8->tyres[0].status.slipRatio )
            v8->tyres[0].absOverride = 1.0;
          else
            v8->tyres[0].absOverride = 0.0;
          v9 = this->car;
          if ( COERCE_FLOAT(LODWORD(this->slipRatioLimit) ^ _xmm) <= v9->tyres[1].status.slipRatio )
            v9->tyres[1].absOverride = 1.0;
          else
            v9->tyres[1].absOverride = 0.0;
          v10 = this->car;
          if ( COERCE_FLOAT(LODWORD(this->slipRatioLimit) ^ _xmm) <= v10->tyres[2].status.slipRatio )
            v10->tyres[2].absOverride = 1.0;
          else
            v10->tyres[2].absOverride = 0.0;
          v11 = this->car;
          if ( COERCE_FLOAT(LODWORD(this->slipRatioLimit) ^ _xmm) <= v11->tyres[3].status.slipRatio )
            v11->tyres[3].absOverride = 1.0;
          else
            v11->tyres[3].absOverride = 0.0;
          break;
      }
    }
    else
    {
      this->car->tyres[0].absOverride = 1.0;
      this->car->tyres[1].absOverride = 1.0;
      this->car->tyres[2].absOverride = 1.0;
      this->car->tyres[3].absOverride = 1.0;
      this->currentValue = 1.0;
    }
  }
}
