#include "driftmodecomponent.h"
BOOL DriftModeComponent::checkExtremeDrifting(DriftModeComponent *this)
{
  Car *v1; // eax
  int v2; // edx
  SurfaceDef *v3; // ecx
  SurfaceDef *v4; // ecx
  SurfaceDef *v5; // ecx
  SurfaceDef *v6; // ecx

  v1 = this->car;
  v2 = 0;
  v3 = this->car->tyres[0].surfaceDef;
  if ( v3
    && COERCE_FLOAT(LODWORD(v1->tyres[0].status.angularVelocity) & _xmm) > 4.0
    && COERCE_FLOAT(LODWORD(v1->tyres[0].status.slipRatio) & _xmm) > triggerSlipLevel
    && v1->tyres[0].status.load > 10.0
    && v3->gripMod >= 0.89999998 )
  {
    v2 = 1;
  }
  v4 = v1->tyres[1].surfaceDef;
  if ( v4
    && COERCE_FLOAT(LODWORD(v1->tyres[1].status.angularVelocity) & _xmm) > 4.0
    && COERCE_FLOAT(LODWORD(v1->tyres[1].status.slipRatio) & _xmm) > triggerSlipLevel
    && v1->tyres[1].status.load > 10.0
    && v4->gripMod >= 0.89999998 )
  {
    ++v2;
  }
  v5 = v1->tyres[2].surfaceDef;
  if ( v5
    && COERCE_FLOAT(LODWORD(v1->tyres[2].status.angularVelocity) & _xmm) > 4.0
    && COERCE_FLOAT(LODWORD(v1->tyres[2].status.slipRatio) & _xmm) > triggerSlipLevel
    && v1->tyres[2].status.load > 10.0
    && v5->gripMod >= 0.89999998 )
  {
    ++v2;
  }
  v6 = v1->tyres[3].surfaceDef;
  if ( v6
    && COERCE_FLOAT(LODWORD(v1->tyres[3].status.angularVelocity) & _xmm) > 4.0
    && COERCE_FLOAT(LODWORD(v1->tyres[3].status.slipRatio) & _xmm) > triggerSlipLevel
    && v1->tyres[3].status.load > 10.0
    && v6->gripMod >= 0.89999998 )
  {
    ++v2;
  }
  return v2 > 1;
}
void DriftModeComponent::init(DriftModeComponent *this, Car *car)
{
  std::wstring section; // [esp+Ch] [ebp-9Ch] BYREF
  std::wstring key; // [esp+24h] [ebp-84h] BYREF
  std::wstring ifilename; // [esp+3Ch] [ebp-6Ch] BYREF
  INIReader ini; // [esp+54h] [ebp-54h] BYREF
  int v7; // [esp+A4h] [ebp-4h]

  this->car = car;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/tyre_smoke.ini", 0x19u);
  v7 = 0;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v7) = 2;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"SLIP_LEVEL", 0xAu);
  LOBYTE(v7) = 3;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"TRIGGERS", 8u);
  LOBYTE(v7) = 4;
  triggerSlipLevel = INIReader::getFloat(&ini, &section, &key);
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  this->car = car;
  this->oldDamageZones[0] = 0.0;
  this->oldDamageZones[1] = 0.0;
  this->oldDamageZones[2] = 0.0;
  this->oldDamageZones[3] = 0.0;
  this->oldDamageZones[4] = 0.0;
  v7 = -1;
  INIReader::~INIReader(&ini);
}
void DriftModeComponent::step(DriftModeComponent *this, float dt)
{
  double v3; // st7
  Car *v4; // ecx
  float v5; // xmm0_4
  float v6; // xmm1_4
  Car *v7; // ecx
  double v8; // xmm0_8
  long double v9; // xmm1_8
  bool v10; // al
  double v11; // xmm0_8
  Car *v12; // ecx
  float v13; // xmm1_4
  float v14; // xmm1_4
  long double v15; // xmm0_8
  Car *v16; // ecx
  float v17; // xmm0_4
  float v18; // xmm1_4
  long double v19; // xmm0_8
  __m128d v20; // xmm0
  __m128d v21; // xmm0
  RaceEngineer v22; // [esp+8h] [ebp-30h] BYREF
  vec3f v23; // [esp+14h] [ebp-24h] BYREF
  Speed result; // [esp+20h] [ebp-18h] BYREF
  float v25; // [esp+24h] [ebp-14h]
  char v26; // [esp+2Bh] [ebp-Dh]
  int v27; // [esp+34h] [ebp-4h]

  v25 = 0.0;
  DriftModeComponent::validateDrift(this);
  RaceEngineer::RaceEngineer(&v22, this->car);
  v27 = 0;
  v3 = RaceEngineer::getBetaRAD(&v22);
  v4 = this->car;
  v25 = v3;
  LODWORD(v25) &= _xmm;
  if ( (float)(Car::getSpeed(v4, &result)->value * 3.5999999) <= 20.0 || (v26 = 1, v25 <= 0.13089749) )
    v26 = 0;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  if ( v26 )
  {
    if ( !this->drifting )
    {
      v5 = 0.0;
      v6 = Car::getLocalVelocity(this->car, &v23)->x;
      if ( v6 <= 0.0 )
      {
        if ( v6 < 0.0 )
          v5 = FLOAT_N1_0;
      }
      else
      {
        v5 = FLOAT_1_0;
      }
      this->comboCounter = 1;
      this->invalid = 0;
      this->lastDriftDirection = (int)v5;
      this->instantDrift = 0.0;
    }
    v7 = this->car;
    this->currentDriftAngle = (float)(v25 - 0.13089749);
    *(double *)&v23.y = (float)((float)((float)(Car::getSpeed(v7, &result)->value * 3.5999999) - 20.0) * 0.015384615);
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
    v8 = DOUBLE_2_0;
    v9 = *(double *)&v23.y;
    if ( *(double *)&v23.y > 2.0 || (v8 = 0.0, *(double *)&v23.y < 0.0) )
    {
      v9 = v8;
      *(double *)&v23.y = v8;
    }
    this->currentSpeedMultiplier = v9;
    v10 = DriftModeComponent::checkExtremeDrifting(this);
    v11 = this->currentDriftAngle * *(double *)&v23.y;
    this->extremeDrifting = v10;
    if ( v10 )
      v11 = v11 * 2.0;
    v12 = this->car;
    this->instantDrift = v11 + this->instantDrift;
    if ( COERCE_FLOAT(LODWORD(Car::getLocalVelocity(v12, &v23)->x) & _xmm) > 4.0 )
    {
      v13 = Car::getLocalVelocity(this->car, &v23)->x;
      if ( v13 <= 0.0 )
        v14 = v13 >= 0.0 ? 0.0 : FLOAT_N1_0;
      else
        v14 = FLOAT_1_0;
      if ( (float)this->lastDriftDirection != v14 && v25 > 0.26179498 )
      {
        v15 = this->instantDrift + 50.0;
        v16 = this->car;
        ++this->comboCounter;
        this->instantDrift = v15;
        v17 = 0.0;
        v18 = Car::getLocalVelocity(v16, &v23)->x;
        if ( v18 <= 0.0 )
        {
          if ( v18 < 0.0 )
            v17 = FLOAT_N1_0;
        }
        else
        {
          v17 = FLOAT_1_0;
        }
        this->lastDriftDirection = (int)v17;
      }
    }
    this->drifting = 1;
    this->driftStraightTimer = 0.0;
  }
  if ( !this->drifting )
    goto LABEL_41;
  if ( (float)(Car::getSpeed(this->car, &result)->value * 3.5999999) <= 20.0 || (v26 = 1, v25 >= 0.065448746) )
    v26 = 0;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  if ( v26 )
    this->driftStraightTimer = this->driftStraightTimer + dt;
  else
    this->driftStraightTimer = 0.0;
  if ( this->drifting && !this->invalid && this->driftStraightTimer > 1.0 )
  {
    v19 = this->instantDrift + this->points;
    this->comboCounter = 0;
    this->drifting = 0;
    this->points = v19;
    v20 = 0i64;
    this->instantDrift = 0.0;
  }
  else
  {
LABEL_41:
    v20 = 0i64;
  }
  v21 = _mm_unpacklo_pd(v20, v20);
  if ( this->invalid )
  {
    *(__m128d *)&this->currentSpeedMultiplier = v21;
    *(_WORD *)&this->extremeDrifting = 0;
    this->instantDrift = v21.m128d_f64[0];
    this->comboCounter = 0;
  }
  v27 = -1;
  RaceEngineer::~RaceEngineer(&v22);
}
void DriftModeComponent::validateDrift(DriftModeComponent *this)
{
  int v1; // eax
  Car *v3; // ecx
  SurfaceDef *v4; // edx
  SurfaceDef *v5; // edx
  SurfaceDef *v6; // edx
  SurfaceDef *v7; // edx
  char v8; // cl
  float v9; // xmm1_4
  float v10; // xmm1_4
  float v11; // xmm1_4
  float v12; // xmm1_4
  float v13; // xmm1_4
  char v14; // bl
  char v15; // [esp+0h] [ebp-8h]
  Speed result; // [esp+4h] [ebp-4h] BYREF

  v1 = 0;
  v15 = 0;
  v3 = this->car;
  v4 = v3->tyres[0].surfaceDef;
  if ( v4 && v4->dirtAdditiveK > 0.001 )
    v1 = 1;
  v5 = v3->tyres[1].surfaceDef;
  if ( v5 && v5->dirtAdditiveK > 0.001 )
    ++v1;
  v6 = v3->tyres[2].surfaceDef;
  if ( v6 && v6->dirtAdditiveK > 0.001 )
    ++v1;
  v7 = v3->tyres[3].surfaceDef;
  if ( v7 && v7->dirtAdditiveK > 0.001 )
    ++v1;
  if ( v1 > 2 )
    goto LABEL_25;
  v15 = 1;
  if ( (float)(Car::getSpeed(v3, &result)->value * 3.5999999) < 20.0 )
    goto LABEL_25;
  v8 = 0;
  v9 = this->car->damageZoneLevel[0];
  if ( this->oldDamageZones[0] != v9 )
  {
    v8 = 1;
    this->oldDamageZones[0] = v9;
  }
  v10 = this->car->damageZoneLevel[1];
  if ( this->oldDamageZones[1] != v10 )
  {
    v8 = 1;
    this->oldDamageZones[1] = v10;
  }
  v11 = this->car->damageZoneLevel[2];
  if ( this->oldDamageZones[2] != v11 )
  {
    v8 = 1;
    this->oldDamageZones[2] = v11;
  }
  v12 = this->car->damageZoneLevel[3];
  if ( this->oldDamageZones[3] != v12 )
  {
    v8 = 1;
    this->oldDamageZones[3] = v12;
  }
  v13 = this->car->damageZoneLevel[4];
  if ( this->oldDamageZones[4] != v13 )
  {
    this->oldDamageZones[4] = v13;
LABEL_25:
    v14 = 1;
    goto LABEL_26;
  }
  if ( v8 || !this->car->drivetrain.currentGear )
    goto LABEL_25;
  v14 = 0;
LABEL_26:
  if ( (v15 & 1) != 0 )
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  if ( v14 )
    this->invalid = 1;
}
