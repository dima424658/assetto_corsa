#include "edl.h"
void EDL::init(EDL *this, Car *a_car)
{
  TractionType v3; // eax
  std::wstring *v4; // eax
  const std::wstring *v5; // eax
  Car *v6; // ecx
  bool v7; // bl
  int v8; // eax
  bool v9; // cf
  int v10; // eax
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  double v16; // st7
  std::wstring *v17; // eax
  std::wstring *v18; // eax
  float Px; // [esp+10h] [ebp-D0h] BYREF
  std::wstring section; // [esp+14h] [ebp-CCh] BYREF
  std::wstring key; // [esp+2Ch] [ebp-B4h] BYREF
  std::wstring v22; // [esp+44h] [ebp-9Ch] BYREF
  std::wstring result; // [esp+5Ch] [ebp-84h] BYREF
  INIReader r; // [esp+74h] [ebp-6Ch] BYREF
  std::wstring abs_filename; // [esp+B8h] [ebp-28h] BYREF
  int v26; // [esp+DCh] [ebp-4h]

  Px = 0.0;
  this->car = a_car;
  this->wheelSpeedGainPower = 0.0099999998;
  this->wheelSpeedGainCoast = 0.0099999998;
  *(_WORD *)&this->isPresent = 0;
  this->brakeTorquePower = 2000.0;
  this->brakeTorqueCoast = 2000.0;
  this->deadZoneCoast = 0.0;
  this->deadZonePower = 0.0;
  this->outBrakeTorque = 0.0;
  this->speedDiff = 0.0;
  this->leftTyreIndex = 2;
  this->rightTyreIndex = 3;
  this->outLevel = 0.0;
  v3 = a_car->drivetrain.tractionType;
  if ( v3 == FWD || v3 == AWD )
  {
    this->leftTyreIndex = 0;
    this->rightTyreIndex = 1;
  }
  v4 = std::operator+<wchar_t>(&result, L"content/cars/", &a_car->unixName);
  v26 = 0;
  v5 = std::operator+<wchar_t>(&v22, v4, L"/data/electronics.ini");
  v6 = this->car;
  LOBYTE(v26) = 1;
  Car::getConfigPath(v6, &abs_filename, v5);
  if ( v22._Myres >= 8 )
    operator delete(v22._Bx._Ptr);
  v22._Myres = 7;
  v22._Mysize = 0;
  v22._Bx._Buf[0] = 0;
  LOBYTE(v26) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  INIReader::INIReader(&r, &abs_filename);
  LOBYTE(v26) = 5;
  v7 = 0;
  if ( r.ready )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"EDL", 3u);
    LOBYTE(v26) = 6;
    LODWORD(Px) = 1;
    if ( INIReader::hasSection(&r, &section) )
      v7 = 1;
  }
  v26 = 5;
  if ( (LOBYTE(Px) & 1) != 0 && section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( v7 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"PRESENT", 7u);
    LOBYTE(v26) = 7;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"EDL", 3u);
    LOBYTE(v26) = 8;
    v8 = INIReader::getInt(&r, &section, &key);
    v9 = section._Myres < 8;
    this->isPresent = v8 != 0;
    if ( !v9 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v26) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"ACTIVE", 6u);
    LOBYTE(v26) = 9;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"EDL", 3u);
    LOBYTE(v26) = 10;
    v10 = INIReader::getInt(&r, &section, &key);
    v9 = section._Myres < 8;
    this->isActive = v10 != 0;
    if ( !v9 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v26) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"BRAKE_TORQUE_POWER", 0x12u);
    LOBYTE(v26) = 11;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"EDL", 3u);
    LOBYTE(v26) = 12;
    v11 = INIReader::getFloat(&r, &section, &key);
    v9 = section._Myres < 8;
    this->brakeTorquePower = v11;
    if ( !v9 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v26) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"BRAKE_TORQUE_COAST", 0x12u);
    LOBYTE(v26) = 13;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"EDL", 3u);
    LOBYTE(v26) = 14;
    v12 = INIReader::getFloat(&r, &section, &key);
    v9 = section._Myres < 8;
    this->brakeTorqueCoast = v12;
    if ( !v9 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v26) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DEAD_ZONE_COAST", 0xFu);
    LOBYTE(v26) = 15;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"EDL", 3u);
    LOBYTE(v26) = 16;
    v13 = INIReader::getFloat(&r, &section, &key);
    v9 = section._Myres < 8;
    this->deadZoneCoast = v13;
    if ( !v9 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v26) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DEAD_ZONE_POWER", 0xFu);
    LOBYTE(v26) = 17;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"EDL", 3u);
    LOBYTE(v26) = 18;
    v14 = INIReader::getFloat(&r, &section, &key);
    v9 = section._Myres < 8;
    this->deadZonePower = v14;
    if ( !v9 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v26) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MAX_SPIN_POWER", 0xEu);
    LOBYTE(v26) = 19;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"EDL", 3u);
    LOBYTE(v26) = 20;
    v15 = INIReader::getFloat(&r, &section, &key);
    v9 = section._Myres < 8;
    this->wheelSpeedGainPower = 1.0 / (v15 - this->deadZonePower);
    if ( !v9 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v26) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MAX_SPIN_COAST", 0xEu);
    LOBYTE(v26) = 21;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"EDL", 3u);
    LOBYTE(v26) = 22;
    v16 = INIReader::getFloat(&r, &section, &key);
    v9 = section._Myres < 8;
    this->wheelSpeedGainCoast = 1.0 / (v16 - this->deadZoneCoast);
    if ( !v9 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v26) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    Px = this->wheelSpeedGainCoast;
    if ( __fdtest(&Px) > 0 )
    {
      _printf("ERROR: wheelSpeedGainCoast is Nan, set to 0\n");
      std::wstring::wstring(&key, L"MAX_SPIN_COAST has same value as DEAD_ZONE_COAST, it should be bigger");
      v17 = &key;
      LOBYTE(v26) = 23;
      if ( key._Myres >= 8 )
        v17 = (std::wstring *)key._Bx._Ptr;
      _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v17->_Bx._Buf);
      ksGenerateCrash();
      LOBYTE(v26) = 5;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      this->wheelSpeedGainCoast = 0.0;
    }
    Px = this->wheelSpeedGainPower;
    if ( __fdtest(&Px) > 0 )
    {
      _printf("ERROR: wheelSpeedGainPower is Nan, set to 0\n");
      std::wstring::wstring(&key, L"MAX_SPIN_POWER has same value as DEAD_ZONE_POWER, it should be bigger");
      v18 = &key;
      LOBYTE(v26) = 24;
      if ( key._Myres >= 8 )
        v18 = (std::wstring *)key._Bx._Ptr;
      _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v18->_Bx._Buf);
      ksGenerateCrash();
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      this->wheelSpeedGainPower = 0.0;
    }
  }
  LOBYTE(v26) = 4;
  INIReader::~INIReader(&r);
  if ( abs_filename._Myres >= 8 )
    operator delete(abs_filename._Bx._Ptr);
}
void EDL::step(EDL *this, float td)
{
  int v3; // ebx
  Car *v4; // edi
  float v5; // xmm1_4
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm4_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  float *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm0_4
  float *v14; // eax
  double v15; // st7
  int v16; // eax
  float v17; // xmm0_4
  float v18; // [esp+10h] [ebp-10h]
  float v19; // [esp+14h] [ebp-Ch] BYREF
  float v20; // [esp+18h] [ebp-8h] BYREF
  unsigned int v21; // [esp+1Ch] [ebp-4h]

  if ( this->isActive && this->isPresent )
  {
    v3 = this->leftTyreIndex;
    v4 = this->car;
    v21 = 1632 * this->rightTyreIndex;
    LODWORD(v5) = LODWORD(v4->tyres[v21 / 0x660].status.angularVelocity) & _xmm;
    LODWORD(v6) = LODWORD(v4->tyres[v3].status.angularVelocity) & _xmm;
    if ( v6 != 0.0 && v5 != 0.0 )
    {
      if ( v6 <= v5 )
        LODWORD(v7) = LODWORD(v4->tyres[v21 / 0x660].status.angularVelocity) & _xmm;
      else
        LODWORD(v7) = LODWORD(v4->tyres[v3].status.angularVelocity) & _xmm;
      if ( v6 <= v5 )
        LODWORD(v8) = LODWORD(v4->tyres[v3].status.angularVelocity) & _xmm;
      else
        LODWORD(v8) = LODWORD(v4->tyres[v21 / 0x660].status.angularVelocity) & _xmm;
      this->speedDiff = (float)(v7 / v8) - 1.0;
      if ( v4->accG.z <= 0.0 )
      {
        v9 = this->wheelSpeedGainCoast;
        v18 = this->brakeTorqueCoast;
        v10 = this->deadZoneCoast;
      }
      else
      {
        v9 = this->wheelSpeedGainPower;
        v18 = this->brakeTorquePower;
        v10 = this->deadZonePower;
      }
      if ( v6 <= v5 )
      {
        v19 = 0.0;
        v14 = &v20;
        v20 = (float)((float)(v5 / v6) - 1.0) - v10;
        if ( v20 <= 0.0 )
          v14 = &v19;
        v15 = saturate(*v14 * v9);
        v12 = v18;
        v16 = v21;
        v20 = v15;
        v17 = v20;
        this->outLevel = v20;
        *(float *)((char *)&v4->tyres[0].inputs.brakeTorque + v16) = (float)(v17 * v18)
                                                                   + *(float *)((char *)&v4->tyres[0].inputs.brakeTorque
                                                                              + v16);
      }
      else
      {
        v20 = 0.0;
        v11 = &v19;
        v19 = (float)((float)(v6 / v5) - 1.0) - v10;
        if ( v19 <= 0.0 )
          v11 = &v20;
        v12 = v18;
        v20 = saturate(*v11 * v9);
        v13 = v20;
        this->outLevel = v20;
        v4->tyres[v3].inputs.brakeTorque = (float)(v13 * v18) + v4->tyres[v3].inputs.brakeTorque;
      }
      this->outBrakeTorque = v12 * this->outLevel;
    }
  }
}
