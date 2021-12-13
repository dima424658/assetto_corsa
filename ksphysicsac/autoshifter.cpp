#include "autoshifter.h"
void AutoShifter::init(AutoShifter *this, Car *car)
{
  this->car = car;
  this->changeUpRpm = 0;
  this->changeDnRpm = 4000;
  *(_WORD *)&this->butGearUp = 0;
  this->isActive = 0;
  this->slipThreshold = 0.80000001;
  this->gasCutoff = 0.0;
  this->gasCutoffTime = 0.5;
  AutoShifter::loadINI(this);
}
void AutoShifter::loadINI(AutoShifter *this)
{
  std::wstring *v2; // eax
  const std::wstring *v3; // eax
  Car *v4; // ecx
  bool v5; // bl
  int v6; // eax
  bool v7; // cf
  int v8; // eax
  double v9; // st7
  double v10; // st7
  std::wstring *v11; // eax
  std::wstring *v12; // edi
  int v13; // eax
  int v14; // eax
  double v15; // st7
  double v16; // st7
  char v17; // [esp+10h] [ebp-114h]
  std::wstring section; // [esp+14h] [ebp-110h] BYREF
  std::wstring key; // [esp+2Ch] [ebp-F8h] BYREF
  std::wstring fn; // [esp+44h] [ebp-E0h] BYREF
  std::wstring result; // [esp+5Ch] [ebp-C8h] BYREF
  std::wstring v22; // [esp+74h] [ebp-B0h] BYREF
  INIReader ini; // [esp+8Ch] [ebp-98h] BYREF
  INIReader ai_ini; // [esp+D0h] [ebp-54h] BYREF
  int v25; // [esp+120h] [ebp-4h]

  v17 = 0;
  v2 = std::operator+<wchar_t>(&result, L"content/cars/", &this->car->unixName);
  v25 = 0;
  v3 = std::operator+<wchar_t>(&v22, v2, L"/data/drivetrain.ini");
  v4 = this->car;
  LOBYTE(v25) = 1;
  Car::getConfigPath(v4, &fn, v3);
  if ( v22._Myres >= 8 )
    operator delete(v22._Bx._Ptr);
  v22._Myres = 7;
  v22._Mysize = 0;
  v22._Bx._Buf[0] = 0;
  LOBYTE(v25) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  INIReader::INIReader(&ini, &fn);
  LOBYTE(v25) = 5;
  v5 = 0;
  if ( ini.ready )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"AUTO_SHIFTER", 0xCu);
    LOBYTE(v25) = 6;
    v17 = 1;
    if ( INIReader::hasSection(&ini, &section) )
      v5 = 1;
  }
  v25 = 5;
  if ( (v17 & 1) != 0 && section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( v5 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"UP", 2u);
    LOBYTE(v25) = 7;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"AUTO_SHIFTER", 0xCu);
    LOBYTE(v25) = 8;
    v6 = INIReader::getInt(&ini, &section, &key);
    v7 = section._Myres < 8;
    this->changeUpRpm = v6;
    if ( !v7 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v25) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DOWN", 4u);
    LOBYTE(v25) = 9;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"AUTO_SHIFTER", 0xCu);
    LOBYTE(v25) = 10;
    v8 = INIReader::getInt(&ini, &section, &key);
    v7 = section._Myres < 8;
    this->changeDnRpm = v8;
    if ( !v7 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v25) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SLIP_THRESHOLD", 0xEu);
    LOBYTE(v25) = 11;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"AUTO_SHIFTER", 0xCu);
    LOBYTE(v25) = 12;
    v9 = INIReader::getFloat(&ini, &section, &key);
    v7 = section._Myres < 8;
    this->slipThreshold = v9;
    if ( !v7 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v25) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"GAS_CUTOFF_TIME", 0xFu);
    LOBYTE(v25) = 13;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"AUTO_SHIFTER", 0xCu);
    LOBYTE(v25) = 14;
    v10 = INIReader::getFloat(&ini, &section, &key);
    v7 = section._Myres < 8;
    this->gasCutoffTime = v10;
    if ( !v7 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  else
  {
    v11 = std::operator+<wchar_t>(&section, L"content/cars/", &this->car->unixName);
    LOBYTE(v25) = 15;
    v12 = std::operator+<wchar_t>(&key, v11, L"/data/ai.ini");
    if ( &fn != v12 )
    {
      if ( fn._Myres >= 8 )
        operator delete(fn._Bx._Ptr);
      fn._Myres = 7;
      fn._Mysize = 0;
      fn._Bx._Buf[0] = 0;
      std::wstring::_Assign_rv(&fn, v12);
    }
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v25) = 5;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    INIReader::INIReader(&ai_ini, &fn);
    LOBYTE(v25) = 16;
    if ( ai_ini.ready )
    {
      std::wstring::wstring(&section, L"UP");
      LOBYTE(v25) = 17;
      std::wstring::wstring(&key, L"GEARS");
      LOBYTE(v25) = 18;
      v13 = INIReader::getInt(&ai_ini, &key, &section);
      v7 = key._Myres < 8;
      this->changeUpRpm = v13;
      if ( !v7 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v25) = 16;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      std::wstring::wstring(&section, L"DOWN");
      LOBYTE(v25) = 19;
      std::wstring::wstring(&key, L"GEARS");
      LOBYTE(v25) = 20;
      v14 = INIReader::getInt(&ai_ini, &key, &section);
      v7 = key._Myres < 8;
      this->changeDnRpm = v14;
      if ( !v7 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v25) = 16;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      std::wstring::wstring(&section, L"SLIP_THRESHOLD");
      LOBYTE(v25) = 21;
      std::wstring::wstring(&key, L"GEARS");
      LOBYTE(v25) = 22;
      v15 = INIReader::getFloat(&ai_ini, &key, &section);
      v7 = key._Myres < 8;
      this->slipThreshold = v15;
      if ( !v7 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v25) = 16;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      std::wstring::wstring(&section, L"GAS_CUTOFF_TIME");
      LOBYTE(v25) = 23;
      std::wstring::wstring(&key, L"GEARS");
      LOBYTE(v25) = 24;
      v16 = INIReader::getFloat(&ai_ini, &key, &section);
      v7 = key._Myres < 8;
      this->gasCutoffTime = v16;
      if ( !v7 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
    LOBYTE(v25) = 5;
    INIReader::~INIReader(&ai_ini);
  }
  LOBYTE(v25) = 4;
  INIReader::~INIReader(&ini);
  if ( fn._Myres >= 8 )
    operator delete(fn._Bx._Ptr);
}
void AutoShifter::step(AutoShifter *this, float dt)
{
  Car *v3; // edi
  int v4; // eax
  Engine *v5; // ecx
  int v6; // eax
  Engine *v7; // ecx
  Car *v8; // eax
  Speed *v9; // eax
  char v10; // cl
  char v11; // bl
  Car *v12; // ecx
  double v13; // st7
  float v14; // xmm0_4
  float v15; // xmm2_4
  Car *v16; // ecx
  Car *v17; // eax
  int v18; // ecx
  int v19; // edx
  bool v20; // bl
  Car *v21; // eax
  float v22; // xmm0_4
  Car *v23; // eax
  int lag; // [esp+0h] [ebp-40h]
  float v25; // [esp+1Ch] [ebp-24h]
  float v26; // [esp+1Ch] [ebp-24h]
  float v27; // [esp+1Ch] [ebp-24h]
  float v28; // [esp+1Ch] [ebp-24h]
  float rpm; // [esp+24h] [ebp-1Ch] BYREF
  RaceEngineer eng; // [esp+28h] [ebp-18h] BYREF
  int v31; // [esp+3Ch] [ebp-4h]

  if ( PhysicsEngine::hasSessionStarted(this->car->ksPhysics, 300.0) )
  {
    if ( this->isActive )
    {
      v3 = this->car;
      if ( v3->drivetrain.currentGear )
      {
        if ( !this->changeUpRpm )
        {
          v25 = Engine::getMaxPowerRPM(&v3->drivetrain.acEngine);
          v4 = v3->drivetrain.acEngine.getLimiterRPM(&v3->drivetrain.acEngine);
          v5 = &this->car->drivetrain.acEngine;
          if ( v4 >= (int)v25 )
          {
            v26 = Engine::getMaxPowerRPM(v5);
            v6 = (int)v26;
          }
          else
          {
            v6 = v5->getLimiterRPM(v5);
          }
          v7 = &this->car->drivetrain.acEngine;
          this->changeUpRpm = (int)(float)((float)v6 * 0.98000002);
          v27 = Engine::getMaxTorqueRPM(v7) * 1.1;
          lag = this->changeUpRpm;
          this->changeDnRpm = (int)v27;
          _printf("CHANGE UP: %d  CHANGE DN: %d\n", lag, (int)v27);
        }
        v8 = this->car;
        if ( !v8->controls.gearUp && !v8->controls.gearDn )
        {
          v8->controls.gearDn = 0;
          this->car->controls.gearUp = 0;
          RaceEngineer::RaceEngineer(&eng, this->car);
          v31 = 0;
          v28 = RaceEngineer::getDrivingTyresSlip(&eng);
          if ( v28 <= this->slipThreshold )
          {
            v10 = 0;
          }
          else
          {
            v9 = Car::getSpeed(this->car, (Speed *)&rpm);
            v10 = 1;
            if ( v9->value > 5.0 )
            {
              v11 = 1;
LABEL_16:
              if ( (v10 & 1) != 0 )
                dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&rpm);
              if ( !Drivetrain::isChangingGear(&this->car->drivetrain) )
              {
                v12 = this->car;
                if ( (v12->controls.clutch > 0.99000001 || v12->drivetrain.currentGear == 1) && !v11 )
                {
                  v13 = Drivetrain::getEngineRPM(&v12->drivetrain);
                  v14 = (float)this->changeUpRpm;
                  rpm = v13;
                  v15 = rpm;
                  if ( rpm > v14 )
                  {
                    v16 = this->car;
                    if ( v16->drivetrain.currentGear < v16->drivetrain.gears._Mylast
                                                     - v16->drivetrain.gears._Myfirst
                                                     - 1
                      && v16->controls.gas > 0.2
                      && this->gasCutoff <= 0.0 )
                    {
                      v16->controls.gearUp = 1;
                      this->gasCutoff = this->gasCutoffTime;
                    }
                  }
                  v17 = this->car;
                  v18 = v17->drivetrain.currentGear;
                  if ( v18 == 3 )
                    v19 = (int)(float)((float)this->changeDnRpm * 0.64999998);
                  else
                    v19 = this->changeDnRpm;
                  if ( (float)v19 > v15 && v18 > 2 && v17->controls.clutch > 0.85000002 && this->gasCutoff <= 0.0 )
                    v17->controls.gearDn = 1;
                }
              }
              v20 = Car::getSpeed(this->car, (Speed *)&rpm)->value < 2.0;
              dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&rpm);
              if ( v20 && !Drivetrain::isChangingGear(&this->car->drivetrain) )
              {
                v21 = this->car;
                if ( v21->controls.gas < 0.1 && this->gasCutoff <= 0.0 && v21->drivetrain.currentGear > 2 )
                  v21->controls.gearDn = 1;
              }
              v22 = this->gasCutoff;
              if ( v22 > 0.0 )
              {
                v23 = this->car;
                this->gasCutoff = v22 - dt;
                v23->controls.gas = 0.0;
              }
              v31 = -1;
              RaceEngineer::~RaceEngineer(&eng);
              return;
            }
          }
          v11 = 0;
          goto LABEL_16;
        }
      }
    }
  }
}
