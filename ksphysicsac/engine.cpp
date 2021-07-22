#include "engine.h
void Engine::Engine(Engine *this)
{
  this->__vftable = (Engine_vtbl *)&Engine::`vftable';
  acEngineData::acEngineData(&this->data);
  this->status.turboBoost = 0.0;
  *(_OWORD *)&this->status.outTorque = 0i64;
  this->status.isLimiterOn = 0;
  this->coastTorqueMultiplier = 0.0;
  this->limiterMultiplier = 0.0;
  this->fuelPressure = 1.0;
  this->bov = 0.0;
  this->turbos._Myfirst = 0;
  this->turbos._Mylast = 0;
  this->turbos._Myend = 0;
  this->isEngineStallEnabled = 0;
  this->starterTorque = 20.0;
  this->rpmDamageThreshold = 0.0;
  this->restrictor = 0.0;
  *(_WORD *)&this->p2p.enabled = 0;
  this->p2p.overboost = 0.0;
  this->p2p.timeS = 0.0;
  this->p2p.coolDownS = 0.0;
  this->p2p.timeAccum = 0.0;
  this->p2p.activations = 0;
  this->p2p.baseWastegate = 0.0;
  this->p2p.baseActivations = 0;
  this->p2p.basePositionCoeff = 1;
  this->p2p.maxActivations = 0;
  this->torqueGenerators._Myfirst = 0;
  this->torqueGenerators._Mylast = 0;
  this->torqueGenerators._Myend = 0;
  this->coastGenerators._Myfirst = 0;
  this->coastGenerators._Mylast = 0;
  this->coastGenerators._Myend = 0;
  this->turboAdjustableFromCockpit = 0;
  this->lastInput.gasInput = 0.0;
  this->lastInput.carSpeed = 0.0;
  this->lastInput.altitude = 0.0;
  this->lastInput.rpm = 0.0;
  this->defaultEngineLimiter = 0;
  this->inertia = 1.0;
  this->limiterOn = 0;
  this->electronicOverride = 0.0;
  this->maxPowerW_Dynamic = -1.0;
  this->maxPowerW = 0.0;
  this->maxTorqueNM = 0.0;
  this->maxPowerRPM = 0.0;
  this->maxTorqueRPM = 0.0;
  this->physicsEngine = 0;
  Curve::Curve(&this->throttleResponseCurve);
  Curve::Curve(&this->throttleResponseCurveMax);
  this->throttleResponseCurveMaxRef = 6000.0;
  this->gasUsage = 0.0;
  this->lifeLeft = 0.0;
  this->turboBoostDamageThreshold = 0.0;
  this->turboBoostDamageK = 0.0;
  this->rpmDamageK = 0.0;
  this->bovThreshold = 0.2;
  this->car = 0;
  this->turboControllers._Myfirst = 0;
  this->turboControllers._Mylast = 0;
  this->turboControllers._Myend = 0;
  this->gasCoastOffset = 0.0;
  Curve::Curve(&this->gasCoastOffsetCurve);
  this->coastSettingsDefaultIndex = 0;
  this->coastEntryRpm = 0;
}
void Engine::~Engine(Engine *this)
{
  std::vector<ICoastGenerator *> *v2; // esi
  std::vector<ITorqueGenerator *> *v3; // esi

  this->__vftable = (Engine_vtbl *)&Engine::`vftable';
  Curve::~Curve(&this->gasCoastOffsetCurve);
  std::vector<TurboDynamicController>::_Tidy(&this->turboControllers);
  Curve::~Curve(&this->throttleResponseCurveMax);
  Curve::~Curve(&this->throttleResponseCurve);
  v2 = &this->coastGenerators;
  if ( this->coastGenerators._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->coastGenerators);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    this->coastGenerators._Mylast = 0;
    this->coastGenerators._Myend = 0;
  }
  v3 = &this->torqueGenerators;
  if ( this->torqueGenerators._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->torqueGenerators);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    this->torqueGenerators._Mylast = 0;
    this->torqueGenerators._Myend = 0;
  }
  std::vector<Turbo>::_Tidy(&this->turbos);
  Curve::~Curve(&this->data.coastCurve);
  Curve::~Curve(&this->data.powerCurve);
}
void Engine::addTorqueGenerator(Engine *this, ITorqueGenerator *generator)
{
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->torqueGenerators,
    (ICollisionObject *const *)&generator);
}
void Engine::blowUp(Engine *this)
{
  this->lifeLeft = DOUBLE_N100_0;
}
int Engine::getLimiterRPM(Engine *this)
{
  return (int)(float)((float)this->data.limiter * this->limiterMultiplier);
}
double Engine::getMaxPowerRPM(Engine *this)
{
  return this->maxPowerRPM;
}
double Engine::getMaxPowerW(Engine *this)
{
  float v2; // xmm1_4
  Turbo *v4; // ecx
  Turbo *v5; // eax
  float v6; // [esp+0h] [ebp-4h]

  v2 = 0.0;
  if ( this->maxPowerW_Dynamic > 0.0 )
    return this->maxPowerW_Dynamic;
  v4 = this->turbos._Mylast;
  v5 = this->turbos._Myfirst;
  v6 = 0.0;
  if ( v5 != v4 )
  {
    do
    {
      v2 = v2 + v5->data.maxBoost;
      ++v5;
    }
    while ( v5 != v4 );
    v6 = v2;
  }
  return (v6 + 1.0) * this->maxPowerW;
}
double Engine::getMaxTorqueNM(Engine *this)
{
  return this->maxTorqueNM;
}
double Engine::getMaxTorqueRPM(Engine *this)
{
  return this->maxTorqueRPM;
}
double Engine::getMaxTurboBoost(Engine *this, bool with_wastegate)
{
  Turbo *v2; // edx
  Turbo *v3; // ecx
  float v4; // xmm2_4
  float v5; // xmm0_4
  float b; // [esp+0h] [ebp-4h]

  v2 = this->turbos._Mylast;
  v3 = this->turbos._Myfirst;
  v4 = 0.0;
  b = 0.0;
  if ( v3 != v2 )
  {
    do
    {
      if ( !with_wastegate || (v5 = v3->data.wastegate, v5 == 0.0) )
      {
        v5 = v3->data.maxBoost;
      }
      else if ( v3->data.maxBoost <= v5 )
      {
        v5 = v3->data.maxBoost;
      }
      ++v3;
      v4 = v4 + v5;
    }
    while ( v3 != v2 );
    b = v4;
  }
  return b;
}
double Engine::getSafeTurboLevel(Engine *this)
{
  Turbo *v1; // edx
  float v2; // xmm1_4
  Turbo *v3; // eax
  float v5; // [esp+0h] [ebp-4h]

  v1 = this->turbos._Mylast;
  v2 = 0.0;
  v3 = this->turbos._Myfirst;
  v5 = 0.0;
  if ( v3 != v1 )
  {
    do
    {
      v2 = v2 + v3->data.maxBoost;
      ++v3;
    }
    while ( v3 != v1 );
    v5 = v2;
  }
  return this->turboBoostDamageThreshold / v5;
}
double Engine::getThrottleResponseGas(Engine *this, const float gas, const float rpm)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm3_4
  double result; // st7
  float ref; // [esp+10h] [ebp-4h]
  float v10; // [esp+10h] [ebp-4h]
  float gasa; // [esp+18h] [ebp+4h]

  if ( Curve::getCount(&this->throttleResponseCurve) && Curve::getCount(&this->throttleResponseCurveMax) )
  {
    ref = gas * 100.0;
    v4 = FLOAT_1_0;
    gasa = Curve::getValue(&this->throttleResponseCurve, gas * 100.0) * 0.0099999998;
    if ( gasa > 1.0 || (v4 = 0.0, gasa < 0.0) )
      gasa = v4;
    v5 = FLOAT_1_0;
    v10 = Curve::getValue(&this->throttleResponseCurveMax, ref) * 0.0099999998;
    v6 = v10;
    if ( v10 <= 1.0 )
    {
      if ( v10 < 0.0 )
        v6 = 0.0;
    }
    else
    {
      v6 = FLOAT_1_0;
    }
    v7 = rpm / this->throttleResponseCurveMaxRef;
    if ( v7 <= 1.0 )
    {
      if ( v7 >= 0.0 )
        v5 = rpm / this->throttleResponseCurveMaxRef;
      else
        v5 = 0.0;
    }
    result = (float)((float)((float)(v6 - gasa) * v5) + gasa);
  }
  else
  {
    if ( !Curve::getCount(&this->throttleResponseCurve) )
      goto LABEL_20;
    gas = Curve::getValue(&this->throttleResponseCurve, gas * 100.0) * 0.0099999998;
    if ( gas > 1.0 )
      return 1.0;
    if ( gas < 0.0 )
      result = 0.0;
    else
LABEL_20:
      result = gas;
  }
  return result;
}
double Engine::getTorqueAtRPM(Engine *this, float rpm, float gas)
{
  double v4; // st7
  float v5; // xmm1_4
  float v6; // xmm3_4
  float v7; // xmm2_4
  float v8; // xmm4_4
  float v9; // xmm0_4
  float torqueMax; // [esp+Ch] [ebp+4h]

  v4 = Curve::getValue(&this->data.powerCurve, rpm);
  v5 = this->data.coast1;
  v6 = 0.0;
  v7 = this->data.coast0;
  if ( v5 != 0.0 )
    v7 = (float)((float)(this->lastInput.rpm * v5) * this->coastTorqueMultiplier) + v7;
  v8 = this->data.coast2;
  if ( v8 != 0.0 )
  {
    v9 = this->lastInput.rpm;
    if ( v9 <= 0.0 )
    {
      if ( v9 < 0.0 )
        v6 = FLOAT_N1_0;
    }
    else
    {
      v6 = FLOAT_1_0;
    }
    v7 = v7 - (float)((float)((float)(this->coastTorqueMultiplier * v8) * (float)(v9 * v9)) * v6);
  }
  torqueMax = v4;
  return (float)((float)((float)(torqueMax - v7) * gas) + v7);
}
double Engine::getTurboBoostLevel(Engine *this)
{
  double result; // st7

  if ( this->turbos._Mylast - this->turbos._Myfirst )
    result = this->turbos._Myfirst->userSetting;
  else
    result = 0.0;
  return result;
}
void Engine::init(Engine *this, Car *car)
{
  Turbo *v3; // edi
  Turbo *i; // esi

  this->car = car;
  this->physicsEngine = car->ksPhysics;
  this->isEngineStallEnabled = 0;
  this->limiterMultiplier = 1.0;
  this->coastTorqueMultiplier = 1.0;
  this->limiterOn = 0;
  this->electronicOverride = 1.0;
  Engine::loadINI(this);
  v3 = this->turbos._Mylast;
  for ( i = this->turbos._Myfirst; i != v3; ++i )
    MaterialFilter::resetMaterialCache(i);
  this->lifeLeft = DOUBLE_1000_0;
  Engine::precalculatePowerAndTorque(this);
  this->restrictor = 0.0;
}
BOOL Engine::isLimiterOn(Engine *this)
{
  return this->limiterOn > 0;
}
INIReader *Engine::loadCoastSettings(Engine *this, INIReader *r, const std::wstring *section, std::wstring *a4)
{
  const wchar_t *v4; // eax
  float v5; // xmm1_4
  float v6; // xmm2_4
  int v7; // edi
  float v9; // [esp+14h] [ebp-50h]
  float v11; // [esp+1Ch] [ebp-48h]
  float v12; // [esp+20h] [ebp-44h]
  std::wstring v13; // [esp+24h] [ebp-40h] BYREF
  std::wstring key; // [esp+3Ch] [ebp-28h] BYREF
  int v15; // [esp+60h] [ebp-4h]

  if ( a4->_Myres < 8 )
    v4 = (const wchar_t *)a4;
  else
    v4 = a4->_Bx._Ptr;
  _printf("GENERATING COAST CURVE PARAMETERS for section %S\n", v4);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"RPM", 3u);
  v15 = 0;
  v11 = INIReader::getFloat((INIReader *)section, a4, &key);
  v15 = -1;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"TORQUE", 6u);
  v15 = 1;
  v9 = INIReader::getFloat((INIReader *)section, a4, &key);
  v15 = -1;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v13._Myres = 7;
  v13._Mysize = 0;
  v13._Bx._Buf[0] = 0;
  std::wstring::assign(&v13, L"NON_LINEARITY", 0xDu);
  v15 = 2;
  v12 = INIReader::getFloat((INIReader *)section, a4, &v13);
  if ( v13._Myres >= 8 )
    operator delete(v13._Bx._Ptr);
  v5 = v12 * v11;
  v6 = (float)((float)(1.0 - v12) * v11) - (float)this->data.minimum;
  if ( v6 == 0.0 )
    r->__vftable = 0;
  else
    r->__vftable = (INIReader_vtbl *)(COERCE_UNSIGNED_INT(v9 / v6) ^ _xmm);
  if ( v5 == 0.0 )
    *(_DWORD *)&r->ready = 0;
  else
    *(float *)&r->ready = v9 / (float)(v5 * v5);
  _printf("COAST CURVE EXAMPLE\n");
  v7 = 0;
  if ( v11 >= 0.0 )
  {
    do
    {
      _printf(
        "%d: %f\n",
        v7,
        (float)((float)((float)(v7 - this->data.minimum) * *(float *)&r->__vftable)
              - (float)((float)((v7 - this->data.minimum) * (v7 - this->data.minimum)) * *(float *)&r->ready)));
      v7 += 500;
    }
    while ( v11 >= (float)v7 );
  }
  return r;
}
void Engine::loadINI(Engine *this)
{
  Engine *v1; // edi
  const std::wstring *v2; // eax
  Car *v3; // ecx
  std::wstring *v4; // eax
  int v5; // eax
  Car *v6; // eax
  const std::wstring *v7; // eax
  Car *v8; // ecx
  std::wstring *v9; // edx
  unsigned int v10; // ecx
  int v11; // eax
  bool v12; // cf
  double v13; // st7
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // ecx
  bool v18; // al
  const Curve *v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // esi
  std::wostream *v23; // eax
  const std::wstring *v24; // eax
  bool v25; // al
  const std::wstring *v26; // eax
  const std::wstring *v27; // eax
  const std::wstring *v28; // eax
  const std::wstring *v29; // eax
  const std::wstring *v30; // eax
  const std::wstring *v31; // eax
  const std::wstring *v32; // eax
  Turbo *v33; // eax
  double v34; // st7
  Turbo *v35; // edi
  Turbo *i; // esi
  bool v37; // al
  double v38; // st7
  double v39; // st7
  double v40; // st7
  std::wstring *v41; // eax
  const std::wstring *v42; // eax
  Car *v43; // ecx
  int v44; // eax
  bool v45; // al
  bool v46; // bl
  bool v47; // al
  bool v48; // bl
  std::vector<Turbo> *v49; // esi
  unsigned int j; // ebx
  std::wstring *v51; // esi
  const std::wstring *v52; // ecx
  std::wstring *v53; // eax
  std::wstring *v54; // eax
  const DynamicController *v55; // eax
  std::wstring *v56; // esi
  const std::wstring *v57; // ecx
  std::wstring *v58; // eax
  std::wstring *v59; // eax
  std::wstring *v60; // eax
  const DynamicController *v61; // eax
  bool v62; // al
  bool v63; // bl
  Turbo *v64; // eax
  bool v65; // al
  bool v66; // bl
  const Curve *v67; // eax
  float v68; // xmm0_4
  int k; // esi
  std::wstring *value_4; // [esp+10h] [ebp-348h]
  bool v71; // [esp+4Bh] [ebp-30Dh]
  bool v72; // [esp+4Bh] [ebp-30Dh]
  bool v73; // [esp+4Bh] [ebp-30Dh]
  float tgas[2]; // [esp+4Ch] [ebp-30Ch] BYREF
  float gas; // [esp+54h] [ebp-304h]
  Engine *v76; // [esp+58h] [ebp-300h]
  int v77; // [esp+5Ch] [ebp-2FCh]
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t> > v78; // [esp+60h] [ebp-2F8h] BYREF
  std::wstring error; // [esp+114h] [ebp-244h] BYREF
  std::wstring key; // [esp+12Ch] [ebp-22Ch] BYREF
  std::wstring section; // [esp+144h] [ebp-214h] BYREF
  std::wstring fname; // [esp+15Ch] [ebp-1FCh] BYREF
  std::wstring v83; // [esp+174h] [ebp-1E4h] BYREF
  std::wstring v84; // [esp+18Ch] [ebp-1CCh] BYREF
  TurboDynamicController tc; // [esp+1A4h] [ebp-1B4h] BYREF
  INIReader r; // [esp+1C0h] [ebp-198h] BYREF
  std::wstring v87; // [esp+20Ch] [ebp-14Ch] BYREF
  std::wstring filename; // [esp+224h] [ebp-134h] BYREF
  std::wstring result; // [esp+23Ch] [ebp-11Ch] BYREF
  std::wstring powerCurveFile; // [esp+254h] [ebp-104h] BYREF
  std::wstring coastMode; // [esp+26Ch] [ebp-ECh] BYREF
  std::wstring lutfn; // [esp+284h] [ebp-D4h] BYREF
  Turbo v93; // [esp+29Ch] [ebp-BCh] BYREF
  Curve v94; // [esp+2C0h] [ebp-98h] BYREF
  int v95; // [esp+354h] [ebp-4h]

  v1 = this;
  v76 = this;
  v77 = 0;
  v2 = std::operator+<wchar_t>(&result, &this->car->carDataPath, L"engine.ini");
  v3 = v1->car;
  v95 = 0;
  Car::getConfigPath(v3, &filename, v2);
  LOBYTE(v95) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Bx._Buf[0] = 0;
  v4 = &filename;
  if ( filename._Myres >= 8 )
    v4 = (std::wstring *)filename._Bx._Ptr;
  result._Myres = 7;
  result._Mysize = 0;
  _printf("Loading engine file %S\n", v4->_Bx._Buf);
  INIReader::INIReader(&r, &filename);
  LOBYTE(v95) = 3;
  if ( r.ready )
  {
    fname._Myres = 7;
    fname._Mysize = 0;
    fname._Bx._Buf[0] = 0;
    std::wstring::assign(&fname, L"VERSION", 7u);
    LOBYTE(v95) = 4;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HEADER", 6u);
    LOBYTE(v95) = 5;
    v5 = INIReader::getInt(&r, &section, &fname);
    _printf("VERSION=%d\n", v5);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v95) = 3;
    if ( fname._Myres >= 8 )
      operator delete(fname._Bx._Ptr);
  }
  else
  {
    _printf("File not found\n");
  }
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"POWER_CURVE", 0xBu);
  LOBYTE(v95) = 6;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"HEADER", 6u);
  LOBYTE(v95) = 7;
  value_4 = INIReader::getString(&r, &error, &section, &key);
  v6 = v1->car;
  LOBYTE(v95) = 8;
  v7 = std::operator+<wchar_t>(&v83, &v6->carDataPath, value_4);
  v8 = v1->car;
  LOBYTE(v95) = 9;
  Car::getConfigPath(v8, &powerCurveFile, v7);
  if ( v83._Myres >= 8 )
    operator delete(v83._Bx._Ptr);
  v83._Myres = 7;
  v83._Mysize = 0;
  v83._Bx._Buf[0] = 0;
  if ( error._Myres >= 8 )
    operator delete(error._Bx._Ptr);
  error._Myres = 7;
  error._Mysize = 0;
  error._Bx._Buf[0] = 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v95) = 14;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  fname._Myres = 7;
  v9 = &powerCurveFile;
  fname._Mysize = 0;
  if ( powerCurveFile._Myres >= 8 )
    v9 = (std::wstring *)powerCurveFile._Bx._Ptr;
  fname._Bx._Buf[0] = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  if ( v9->_Bx._Buf[0] )
    v10 = wcslen(v9->_Bx._Buf);
  else
    v10 = 0;
  std::wstring::assign(&fname, v9->_Bx._Buf, v10);
  LOBYTE(v95) = 15;
  Curve::load(&v1->data.powerCurve, &fname);
  LOBYTE(v95) = 14;
  if ( fname._Myres >= 8 )
    operator delete(fname._Bx._Ptr);
  fname._Myres = 7;
  fname._Mysize = 0;
  fname._Bx._Buf[0] = 0;
  std::wstring::assign(&fname, L"MINIMUM", 7u);
  LOBYTE(v95) = 16;
  v84._Myres = 7;
  v84._Mysize = 0;
  v84._Bx._Buf[0] = 0;
  std::wstring::assign(&v84, L"ENGINE_DATA", 0xBu);
  LOBYTE(v95) = 17;
  v11 = INIReader::getInt(&r, &v84, &fname);
  v12 = v84._Myres < 8;
  v1->data.minimum = v11;
  if ( !v12 )
    operator delete(v84._Bx._Ptr);
  v84._Myres = 7;
  v84._Mysize = 0;
  v84._Bx._Buf[0] = 0;
  LOBYTE(v95) = 14;
  if ( fname._Myres >= 8 )
    operator delete(fname._Bx._Ptr);
  if ( !v1->data.minimum )
    v1->data.minimum = 1000;
  fname._Myres = 7;
  fname._Mysize = 0;
  fname._Bx._Buf[0] = 0;
  std::wstring::assign(&fname, L"COAST_CURVE", 0xBu);
  LOBYTE(v95) = 18;
  v84._Myres = 7;
  v84._Mysize = 0;
  v84._Bx._Buf[0] = 0;
  std::wstring::assign(&v84, L"HEADER", 6u);
  LOBYTE(v95) = 19;
  INIReader::getString(&r, &coastMode, &v84, &fname);
  if ( v84._Myres >= 8 )
    operator delete(v84._Bx._Ptr);
  v84._Myres = 7;
  v84._Mysize = 0;
  v84._Bx._Buf[0] = 0;
  LOBYTE(v95) = 22;
  if ( fname._Myres >= 8 )
    operator delete(fname._Bx._Ptr);
  fname._Myres = 7;
  fname._Mysize = 0;
  fname._Bx._Buf[0] = 0;
  if ( !std::wstring::compare(&coastMode, 0, coastMode._Mysize, L"FROM_COAST_REF", 0xEu) )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"COAST_REF", 9u);
    LOBYTE(v95) = 23;
    Engine::loadCoastSettings(v1, (INIReader *)tgas, (const std::wstring *)&r, &key);
    LOBYTE(v95) = 22;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v1->data.coast1 = tgas[0];
    v1->data.coast2 = tgas[1];
  }
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"INERTIA", 7u);
  LOBYTE(v95) = 24;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"ENGINE_DATA", 0xBu);
  LOBYTE(v95) = 25;
  v13 = INIReader::getFloat(&r, &key, &section);
  v12 = key._Myres < 8;
  v1->inertia = v13;
  if ( !v12 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  LOBYTE(v95) = 22;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"LIMITER", 7u);
  LOBYTE(v95) = 26;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"ENGINE_DATA", 0xBu);
  LOBYTE(v95) = 27;
  v14 = INIReader::getInt(&r, &key, &section);
  v12 = key._Myres < 8;
  v1->defaultEngineLimiter = v14;
  if ( !v12 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  LOBYTE(v95) = 22;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"LIMITER", 7u);
  LOBYTE(v95) = 28;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"ENGINE_DATA", 0xBu);
  LOBYTE(v95) = 29;
  v15 = INIReader::getInt(&r, &key, &section);
  v12 = key._Myres < 8;
  v1->data.limiter = v15;
  if ( !v12 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  LOBYTE(v95) = 22;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  std::wstring::wstring(&error, L"LIMITER_HZ");
  LOBYTE(v95) = 30;
  std::wstring::wstring(&key, L"ENGINE_DATA");
  LOBYTE(v95) = 31;
  v16 = INIReader::getInt(&r, &key, &error);
  v12 = key._Myres < 8;
  v1->data.limiterCycles = v16;
  if ( !v12 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  LOBYTE(v95) = 22;
  if ( error._Myres >= 8 )
    operator delete(error._Bx._Ptr);
  v17 = v1->data.limiterCycles;
  if ( v17 )
    v1->data.limiterCycles = 1000 / v17 / 3;
  else
    v1->data.limiterCycles = 50;
  std::wstring::wstring(&error, L"COAST_SETTINGS");
  LOBYTE(v95) = 32;
  v18 = INIReader::hasSection(&r, &error);
  v71 = v18;
  LOBYTE(v95) = 22;
  if ( error._Myres >= 8 )
  {
    operator delete(error._Bx._Ptr);
    v18 = v71;
  }
  if ( v18 )
  {
    _printf("COAST SETTINGS CURVE\n");
    std::wstring::wstring(&error, L"LUT");
    LOBYTE(v95) = 33;
    std::wstring::wstring(&key, L"COAST_SETTINGS");
    LOBYTE(v95) = 34;
    v19 = INIReader::getCurve(&r, &v94, &key, &error);
    LOBYTE(v95) = 35;
    Curve::operator=(&v1->gasCoastOffsetCurve, v19);
    LOBYTE(v95) = 34;
    Curve::~Curve(&v94);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v95) = 22;
    if ( error._Myres >= 8 )
      operator delete(error._Bx._Ptr);
    Curve::print(&v1->gasCoastOffsetCurve);
    std::wstring::wstring(&error, L"DEFAULT");
    LOBYTE(v95) = 36;
    std::wstring::wstring(&key, L"COAST_SETTINGS");
    LOBYTE(v95) = 37;
    v20 = INIReader::getInt(&r, &key, &error);
    v12 = key._Myres < 8;
    v1->coastSettingsDefaultIndex = v20;
    if ( !v12 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v95) = 22;
    if ( error._Myres >= 8 )
      operator delete(error._Bx._Ptr);
    Engine::setCoastSettings(v1, v1->coastSettingsDefaultIndex);
    std::wstring::wstring(&error, L"ACTIVATION_RPM");
    LOBYTE(v95) = 38;
    std::wstring::wstring(&key, L"COAST_SETTINGS");
    LOBYTE(v95) = 39;
    v21 = INIReader::getInt(&r, &key, &error);
    v12 = key._Myres < 8;
    v1->coastEntryRpm = v1->data.minimum + v21;
    if ( !v12 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v95) = 22;
    if ( error._Myres >= 8 )
      operator delete(error._Bx._Ptr);
  }
  v22 = 0;
  gas = 0.0;
  while ( 1 )
  {
    *(_DWORD *)v78.gap0 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wistream'};
    *(_DWORD *)v78.gap10 = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbtable'{for `std::wostream'};
    std::wios::wios(v78.gap68);
    v77 |= 1u;
    LOBYTE(v95) = 40;
    std::wiostream::basic_iostream<wchar_t>(&v78, &v78.gap10[8], 0);
    v95 = 41;
    *(_DWORD *)&v78.gap0[*(_DWORD *)(*(_DWORD *)v78.gap0 + 4)] = &std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vftable';
    *(int *)((char *)&v77 + *(_DWORD *)(*(_DWORD *)v78.gap0 + 4)) = *(_DWORD *)(*(_DWORD *)v78.gap0 + 4) - 104;
    std::wstreambuf::wstreambuf(&v78.gap10[8]);
    *(_DWORD *)&v78.gap10[8] = &std::wstringbuf::`vftable';
    *(_DWORD *)&v78.gap10[64] = 0;
    *(_DWORD *)&v78.gap10[68] = 0;
    LOBYTE(v95) = 43;
    v23 = std::operator<<<wchar_t,std::char_traits<wchar_t>>((std::wostream *)v78.gap10, "TURBO_");
    std::wostream::operator<<(v23, v22);
    v24 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v78, &error);
    LOBYTE(v95) = 44;
    v25 = INIReader::hasSection(&r, v24);
    v72 = v25;
    LOBYTE(v95) = 43;
    if ( error._Myres >= 8 )
    {
      operator delete(error._Bx._Ptr);
      v25 = v72;
    }
    if ( !v25 )
      break;
    tc.isWastegate = 0;
    *(_OWORD *)&tc.turbo = _xmm;
    tc.controller.stages._Myend = (DynamicControllerStage *)1065353216;
    *(_DWORD *)&tc.controller.ready = 0;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"LAG_DN", 6u);
    LOBYTE(v95) = 45;
    v26 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v78, &error);
    LOBYTE(v95) = 46;
    tgas[0] = INIReader::getFloat(&r, v26, &key);
    *(float *)&tc.controller.stages._Myfirst = (float)((float)(1.0 - tgas[0]) * 1.3333334) * 333.33334;
    if ( error._Myres >= 8 )
      operator delete(error._Bx._Ptr);
    error._Myres = 7;
    error._Mysize = 0;
    error._Bx._Buf[0] = 0;
    LOBYTE(v95) = 43;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"LAG_UP", 6u);
    LOBYTE(v95) = 47;
    v27 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v78, &error);
    LOBYTE(v95) = 48;
    tgas[0] = INIReader::getFloat(&r, v27, &key);
    *(float *)&tc.controller.car = (float)((float)(1.0 - tgas[0]) * 1.3333334) * 333.33334;
    if ( error._Myres >= 8 )
      operator delete(error._Bx._Ptr);
    error._Myres = 7;
    error._Mysize = 0;
    error._Bx._Buf[0] = 0;
    LOBYTE(v95) = 43;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MAX_BOOST", 9u);
    LOBYTE(v95) = 49;
    v28 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v78, &error);
    LOBYTE(v95) = 50;
    *(float *)&tc.turbo = INIReader::getFloat(&r, v28, &key);
    if ( error._Myres >= 8 )
      operator delete(error._Bx._Ptr);
    error._Myres = 7;
    error._Mysize = 0;
    error._Bx._Buf[0] = 0;
    LOBYTE(v95) = 43;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&v83, L"REFERENCE_RPM");
    LOBYTE(v95) = 51;
    v29 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v78, &error);
    LOBYTE(v95) = 52;
    *(float *)&tc.controller.stages._Mylast = INIReader::getFloat(&r, v29, &v83);
    if ( error._Myres >= 8 )
      operator delete(error._Bx._Ptr);
    error._Myres = 7;
    error._Mysize = 0;
    error._Bx._Buf[0] = 0;
    LOBYTE(v95) = 43;
    if ( v83._Myres >= 8 )
      operator delete(v83._Bx._Ptr);
    std::wstring::wstring(&v83, L"GAMMA");
    LOBYTE(v95) = 53;
    v30 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v78, &error);
    LOBYTE(v95) = 54;
    *(float *)&tc.controller.stages._Myend = INIReader::getFloat(&r, v30, &v83);
    if ( error._Myres >= 8 )
      operator delete(error._Bx._Ptr);
    error._Myres = 7;
    error._Mysize = 0;
    error._Bx._Buf[0] = 0;
    LOBYTE(v95) = 43;
    if ( v83._Myres >= 8 )
      operator delete(v83._Bx._Ptr);
    std::wstring::wstring(&v83, L"WASTEGATE");
    LOBYTE(v95) = 55;
    v31 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v78, &error);
    LOBYTE(v95) = 56;
    *(float *)&tc.controller.ready = INIReader::getFloat(&r, v31, &v83);
    if ( error._Myres >= 8 )
      operator delete(error._Bx._Ptr);
    error._Myres = 7;
    error._Mysize = 0;
    error._Bx._Buf[0] = 0;
    LOBYTE(v95) = 43;
    if ( v83._Myres >= 8 )
      operator delete(v83._Bx._Ptr);
    std::wstring::wstring(&v83, L"COCKPIT_ADJUSTABLE");
    LOBYTE(v95) = 57;
    v32 = std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::str(&v78, &error);
    LOBYTE(v95) = 58;
    tc.isWastegate = INIReader::getInt(&r, v32, &v83) != 0;
    if ( error._Myres >= 8 )
      operator delete(error._Bx._Ptr);
    error._Myres = 7;
    error._Mysize = 0;
    error._Bx._Buf[0] = 0;
    LOBYTE(v95) = 43;
    if ( v83._Myres >= 8 )
      operator delete(v83._Bx._Ptr);
    if ( tc.isWastegate )
      v1->turboAdjustableFromCockpit = 1;
    Turbo::Turbo(&v93, (TurboDef *)&tc);
    LOBYTE(v95) = 59;
    std::vector<Turbo>::push_back(&v1->turbos, v33);
    LOBYTE(v95) = 43;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v93);
    LOBYTE(v95) = 22;
    ++v22;
    std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v78);
  }
  LOBYTE(v95) = 22;
  std::basic_stringstream<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>::`vbase destructor(&v78);
  if ( v1->turboAdjustableFromCockpit )
  {
    std::wstring::wstring(&error, L"DEFAULT_TURBO_ADJUSTMENT");
    LOBYTE(v95) = 60;
    std::wstring::wstring(&key, L"ENGINE_DATA");
    LOBYTE(v95) = 61;
    v34 = INIReader::getFloat(&r, &key, &error);
    v35 = v1->turbos._Mylast;
    tgas[0] = v34;
    for ( i = v76->turbos._Myfirst; i != v35; ++i )
      Turbo::setTurboBoostLevel(i, tgas[0]);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v95) = 22;
    if ( error._Myres >= 8 )
      operator delete(error._Bx._Ptr);
    v1 = v76;
  }
  std::wstring::wstring(&error, L"OVERLAP");
  LOBYTE(v95) = 62;
  v37 = INIReader::hasSection(&r, &error);
  v73 = v37;
  LOBYTE(v95) = 22;
  if ( error._Myres >= 8 )
  {
    operator delete(error._Bx._Ptr);
    v37 = v73;
  }
  if ( v37 )
  {
    std::wstring::wstring(&error, L"FREQUENCY");
    LOBYTE(v95) = 63;
    std::wstring::wstring(&key, L"OVERLAP");
    LOBYTE(v95) = 64;
    v38 = INIReader::getFloat(&r, &key, &error);
    v12 = key._Myres < 8;
    v1->data.overlapFreq = v38;
    if ( !v12 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v95) = 22;
    if ( error._Myres >= 8 )
      operator delete(error._Bx._Ptr);
    std::wstring::wstring(&error, L"GAIN");
    LOBYTE(v95) = 65;
    std::wstring::wstring(&key, L"OVERLAP");
    LOBYTE(v95) = 66;
    v39 = INIReader::getFloat(&r, &key, &error);
    v12 = key._Myres < 8;
    v1->data.overlapGain = v39;
    if ( !v12 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v95) = 22;
    if ( error._Myres >= 8 )
      operator delete(error._Bx._Ptr);
    std::wstring::wstring(&section, L"IDEAL_RPM");
    LOBYTE(v95) = 67;
    std::wstring::wstring(&key, L"OVERLAP");
    LOBYTE(v95) = 68;
    v40 = INIReader::getFloat(&r, &key, &section);
    v12 = key._Myres < 8;
    v1->data.overlapIdealRPM = v40;
    if ( !v12 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v95) = 22;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    tgas[0] = 0.0;
    section._Mysize = 0;
    v41 = std::wstring::c_str(&section);
    std::char_traits<wchar_t>::assign(v41->_Bx._Buf, (const wchar_t *)tgas);
  }
  v42 = std::operator+<wchar_t>((std::wstring *)&v93, &v1->car->carDataPath, L"throttle.lut");
  v43 = v1->car;
  LOBYTE(v95) = 69;
  Car::getConfigPath(v43, &lutfn, v42);
  LOBYTE(v95) = 71;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v93);
  if ( Path::fileExists((unsigned int)_printf, &lutfn, 0) )
  {
    _printf("LOADING THROTTLE LUT\n");
    Curve::load(&v1->throttleResponseCurve, &lutfn);
  }
  v44 = v1->defaultEngineLimiter;
  if ( v44 )
  {
    v1->rpmDamageK = 10.0;
    v1->rpmDamageThreshold = (float)v44 * 1.05;
  }
  std::wstring::wstring(&error, L"DAMAGE");
  LOBYTE(v95) = 72;
  v45 = INIReader::hasSection(&r, &error);
  LOBYTE(v95) = 71;
  v46 = v45;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&error);
  if ( v46 )
  {
    if ( std::vector<Turbo>::size(&v1->turbos) )
    {
      std::wstring::wstring(&v83, L"TURBO_BOOST_THRESHOLD");
      LOBYTE(v95) = 73;
      std::wstring::wstring(&error, L"DAMAGE");
      LOBYTE(v95) = 74;
      v1->turboBoostDamageThreshold = INIReader::getFloat(&r, &error, &v83);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&error);
      LOBYTE(v95) = 71;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v83);
      std::wstring::wstring(&fname, L"TURBO_DAMAGE_K");
      LOBYTE(v95) = 75;
      std::wstring::wstring(&error, L"DAMAGE");
      LOBYTE(v95) = 76;
      v1->turboBoostDamageK = INIReader::getFloat(&r, &error, &fname);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&error);
      LOBYTE(v95) = 71;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&fname);
    }
    std::wstring::wstring(&v83, L"RPM_THRESHOLD");
    LOBYTE(v95) = 77;
    std::wstring::wstring(&error, L"DAMAGE");
    LOBYTE(v95) = 78;
    v1->rpmDamageThreshold = INIReader::getFloat(&r, &error, &v83);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&error);
    LOBYTE(v95) = 71;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v83);
    std::wstring::wstring(&fname, L"RPM_DAMAGE_K");
    LOBYTE(v95) = 79;
    std::wstring::wstring(&error, L"DAMAGE");
    LOBYTE(v95) = 80;
    v1->rpmDamageK = INIReader::getFloat(&r, &error, &fname);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&error);
    LOBYTE(v95) = 71;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&fname);
  }
  std::wstring::wstring(&error, L"BOV");
  LOBYTE(v95) = 81;
  v47 = INIReader::hasSection(&r, &error);
  LOBYTE(v95) = 71;
  v48 = v47;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&error);
  if ( v48 )
  {
    std::wstring::wstring(&v83, L"PRESSURE_THRESHOLD");
    LOBYTE(v95) = 82;
    std::wstring::wstring(&error, L"BOV");
    LOBYTE(v95) = 83;
    v1->bovThreshold = INIReader::getFloat(&r, &error, &v83);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&error);
    LOBYTE(v95) = 71;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v83);
  }
  v49 = &v1->turbos;
  for ( j = 0; j < std::vector<Turbo>::size(v49); ++j )
  {
    v51 = std::to_wstring(&v83, j);
    v52 = &v1->car->carDataPath;
    LOBYTE(v95) = 84;
    v53 = std::operator+<wchar_t>(&error, v52, L"ctrl_turbo");
    LOBYTE(v95) = 85;
    v54 = std::operator+<wchar_t>(&v87, v53, v51);
    LOBYTE(v95) = 86;
    std::operator+<wchar_t>(&fname, v54, L".ini");
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v87);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&error);
    LOBYTE(v95) = 90;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v83);
    if ( Path::fileExists(j, &fname, 0) )
    {
      _printf("Loading dynamic controller for Turbo: %d\n", j);
      TurboDynamicController::TurboDynamicController(&tc);
      LOBYTE(v95) = 91;
      tc.turbo = std::vector<Turbo>::operator[](&v1->turbos, j);
      DynamicController::DynamicController((DynamicController *)&section, v1->car, &fname);
      LOBYTE(v95) = 92;
      DynamicController::operator=(&tc.controller, v55);
      LOBYTE(v95) = 91;
      DynamicController::~DynamicController((DynamicController *)&section);
      std::vector<TurboDynamicController>::push_back(&v1->turboControllers, &tc);
      LOBYTE(v95) = 90;
      SteerBrake::~SteerBrake((SteerBrake *)&tc);
    }
    v56 = std::to_wstring((std::wstring *)&tc, j);
    v57 = &v1->car->carDataPath;
    LOBYTE(v95) = 93;
    v58 = std::operator+<wchar_t>(&section, v57, L"ctrl_wastegate");
    LOBYTE(v95) = 94;
    v59 = std::operator+<wchar_t>(&key, v58, v56);
    LOBYTE(v95) = 95;
    v60 = std::operator+<wchar_t>(&v84, v59, L".ini");
    std::wstring::operator=(&fname, v60);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v84);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
    LOBYTE(v95) = 90;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&tc);
    if ( Path::fileExists(j, &fname, 0) )
    {
      _printf("Loading dynamic controller for Turbo Wastegate: %d\n", j);
      TurboDynamicController::TurboDynamicController(&tc);
      v49 = &v1->turbos;
      LOBYTE(v95) = 96;
      tc.turbo = std::vector<Turbo>::operator[](&v1->turbos, j);
      DynamicController::DynamicController((DynamicController *)&section, v1->car, &fname);
      LOBYTE(v95) = 97;
      DynamicController::operator=(&tc.controller, v61);
      LOBYTE(v95) = 96;
      DynamicController::~DynamicController((DynamicController *)&section);
      tc.isWastegate = 1;
      std::vector<TurboDynamicController>::push_back(&v1->turboControllers, &tc);
      LOBYTE(v95) = 90;
      SteerBrake::~SteerBrake((SteerBrake *)&tc);
    }
    else
    {
      v49 = &v1->turbos;
    }
    LOBYTE(v95) = 71;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&fname);
  }
  std::wstring::wstring(&error, L"PUSH_TO_PASS");
  LOBYTE(v95) = 98;
  v62 = INIReader::hasSection(&r, &error);
  LOBYTE(v95) = 71;
  v63 = v62;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&error);
  if ( v63 )
  {
    if ( std::vector<Turbo>::empty((std::vector<TyreCompoundDef> *)v49) )
    {
      std::wstring::wstring(&error, L"ERROR: Cannot have PushToPass without turbos");
      LOBYTE(v95) = 99;
      ks_critical_error(&error);
      LOBYTE(v95) = 71;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&error);
    }
    v1->p2p.enabled = 1;
    v1->p2p.activations = 0;
    std::wstring::wstring(&v83, L"COOLDOWN_SECONDS");
    LOBYTE(v95) = 100;
    std::wstring::wstring(&error, L"PUSH_TO_PASS");
    LOBYTE(v95) = 101;
    v1->p2p.coolDownS = INIReader::getFloat(&r, &error, &v83);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&error);
    LOBYTE(v95) = 71;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v83);
    v1->p2p.timeAccum = v1->p2p.coolDownS;
    std::wstring::wstring(&fname, L"TIME_SECONDS");
    LOBYTE(v95) = 102;
    std::wstring::wstring(&error, L"PUSH_TO_PASS");
    LOBYTE(v95) = 103;
    v1->p2p.timeS = INIReader::getFloat(&r, &error, &fname);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&error);
    LOBYTE(v95) = 71;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&fname);
    std::wstring::wstring(&v84, L"OVERBOOST");
    LOBYTE(v95) = 104;
    std::wstring::wstring(&error, L"PUSH_TO_PASS");
    LOBYTE(v95) = 105;
    v1->p2p.overboost = INIReader::getFloat(&r, &error, &v84);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&error);
    LOBYTE(v95) = 71;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v84);
    v64 = std::vector<Turbo>::operator[](v49, 0);
    v1->p2p.baseWastegate = Turbo::getWastegate(v64);
    std::wstring::wstring(&key, L"ACTIVATION_BASE");
    LOBYTE(v95) = 106;
    std::wstring::wstring(&error, L"PUSH_TO_PASS");
    LOBYTE(v95) = 107;
    v1->p2p.baseActivations = INIReader::getInt(&r, &error, &key);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&error);
    LOBYTE(v95) = 71;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    std::wstring::wstring(&section, L"ACTIVATION_POS");
    LOBYTE(v95) = 108;
    std::wstring::wstring(&error, L"PUSH_TO_PASS");
    LOBYTE(v95) = 109;
    v1->p2p.basePositionCoeff = INIReader::getInt(&r, &error, &section);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&error);
    LOBYTE(v95) = 71;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&section);
    std::wstring::wstring(&v87, L"ACTIVATION_MAX");
    LOBYTE(v95) = 110;
    std::wstring::wstring(&error, L"PUSH_TO_PASS");
    LOBYTE(v95) = 111;
    v1->p2p.maxActivations = INIReader::getInt(&r, &error, &v87);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&error);
    LOBYTE(v95) = 71;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v87);
  }
  std::wstring::wstring(&v87, L"THROTTLE_RESPONSE");
  LOBYTE(v95) = 112;
  v65 = INIReader::hasSection(&r, &v87);
  LOBYTE(v95) = 71;
  v66 = v65;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v87);
  if ( v66 )
  {
    std::wstring::wstring(&error, L"RPM_REFERENCE");
    LOBYTE(v95) = 113;
    std::wstring::wstring(&v87, L"THROTTLE_RESPONSE");
    LOBYTE(v95) = 114;
    v1->throttleResponseCurveMaxRef = INIReader::getFloat(&r, &v87, &error);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v87);
    LOBYTE(v95) = 71;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&error);
    std::wstring::wstring(&v83, L"LUT");
    LOBYTE(v95) = 115;
    std::wstring::wstring(&v87, L"THROTTLE_RESPONSE");
    LOBYTE(v95) = 116;
    v67 = INIReader::getCurve(&r, &v94, &v87, &v83);
    LOBYTE(v95) = 117;
    Curve::operator=(&v1->throttleResponseCurveMax, v67);
    LOBYTE(v95) = 116;
    Curve::~Curve(&v94);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v87);
    LOBYTE(v95) = 71;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v83);
    _printf("THROTTLE RESPONSE TABLE\n");
    v68 = 0.0;
    do
    {
      _printf("G: %.1f ", v68);
      for ( k = 0; k < (int)v1->throttleResponseCurveMaxRef; k += 1000 )
      {
        tgas[0] = Engine::getThrottleResponseGas(v1, gas, (float)k);
        _printf("%03d\t", (int)(float)(tgas[0] * 100.0));
      }
      _printf("\n");
      v68 = gas + 0.1;
      gas = gas + 0.1;
    }
    while ( gas <= 1.09 );
  }
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&lutfn);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&coastMode);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&powerCurveFile);
  LOBYTE(v95) = 2;
  INIReader::~INIReader(&r);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&filename);
}
void Engine::precalculatePowerAndTorque(Engine *this)
{
  int v2; // edi
  float ref; // xmm1_4
  float v4; // xmm0_4
  float v5; // [esp+10h] [ebp-8h]
  float ta; // [esp+14h] [ebp-4h]
  float t; // [esp+14h] [ebp-4h]
  float tb; // [esp+14h] [ebp-4h]

  v5 = 0.0;
  v2 = 0;
  this->maxTorqueNM = 0.0;
  this->maxPowerW = 0.0;
  this->maxPowerRPM = 0.0;
  this->maxTorqueRPM = 0.0;
  ta = Curve::getMaxReference(&this->data.powerCurve);
  ref = 0.0;
  if ( ta > 0.0 )
  {
    do
    {
      t = Curve::getValue(&this->data.powerCurve, ref);
      if ( t > this->maxTorqueNM )
      {
        this->maxTorqueNM = t;
        this->maxTorqueRPM = v5;
      }
      v4 = (float)(v5 * t) * 0.1047;
      if ( v4 > this->maxPowerW )
      {
        this->maxPowerW = v4;
        this->maxPowerRPM = v5;
      }
      v2 += 50;
      v5 = (float)v2;
      ref = (float)v2;
      tb = Curve::getMaxReference(&this->data.powerCurve);
    }
    while ( tb > (float)v2 );
  }
}
void Engine::reset(Engine *this)
{
  Turbo *v2; // edi
  Turbo *i; // esi

  v2 = this->turbos._Mylast;
  for ( i = this->turbos._Myfirst; i != v2; ++i )
    MaterialFilter::resetMaterialCache(i);
  this->lifeLeft = DOUBLE_1000_0;
}
void Engine::setCoastSettings(Engine *this, int s)
{
  double v4; // st7
  Car *v5; // eax
  float sa; // [esp+18h] [ebp+4h]

  if ( s >= 0 && s <= Curve::getCount(&this->gasCoastOffsetCurve) )
  {
    v4 = Curve::getValue(&this->gasCoastOffsetCurve, (float)s);
    v5 = this->car;
    sa = v4;
    this->gasCoastOffset = sa;
    _printf("Car: %d , gasCoastOffset (%d): %f\n", v5->physicsGUID, s, sa);
  }
}
void Engine::setTurboBoostLevel(Engine *this, float value)
{
  Turbo *v2; // esi
  Turbo *i; // edi

  v2 = this->turbos._Myfirst;
  for ( i = this->turbos._Mylast; v2 != i; ++v2 )
    Turbo::setTurboBoostLevel(v2, value);
}
void Engine::step(Engine *this, SACEngineInput *input, float dt)
{
  SACEngineInput *v3; // esi
  double v5; // st7
  bool v6; // zf
  float v7; // xmm3_4
  float v8; // xmm2_4
  float v9; // xmm0_4
  int v10; // eax
  int v11; // eax
  float v12; // xmm0_4
  double v13; // st7
  float v14; // xmm2_4
  float v15; // xmm0_4
  float v16; // xmm3_4
  float v17; // xmm0_4
  float v18; // xmm4_4
  float v19; // xmm1_4
  float v20; // xmm0_4
  ICoastGenerator **v21; // esi
  unsigned int v22; // ecx
  long double v23; // st7
  int v24; // eax
  float v25; // xmm3_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm0_4
  double v29; // st7
  float v30; // xmm0_4
  float v31; // xmm2_4
  double v32; // xmm3_8
  float v33; // xmm0_4
  float v34; // xmm2_4
  double v35; // xmm0_8
  float v36; // xmm0_4
  float v37; // xmm3_4
  ITorqueGenerator **v38; // esi
  unsigned int v39; // ecx
  double v40; // st7
  bool v41; // al
  float v42; // xmm0_4
  double v43; // xmm1_8
  double Px; // [esp+10h] [ebp-14h] BYREF
  float v45; // [esp+18h] [ebp-Ch]
  float v46; // [esp+1Ch] [ebp-8h]
  float v47; // [esp+20h] [ebp-4h]
  float dta; // [esp+2Ch] [ebp+8h]
  int dtb; // [esp+2Ch] [ebp+8h]

  v3 = input;
  this->lastInput = (SACEngineInput)_mm_loadu_si128((const __m128i *)input);
  v5 = Engine::getThrottleResponseGas(this, this->lastInput.gasInput, input->rpm);
  v6 = !this->p2p.enabled;
  this->lastInput.gasInput = v5;
  if ( !v6 )
    Engine::stepP2P(this, dt);
  v7 = this->gasCoastOffset;
  if ( v7 > 0.0 )
  {
    v8 = (float)(input->rpm - (float)this->data.minimum) / (float)this->coastEntryRpm;
    if ( v8 <= 1.0 )
    {
      if ( v8 < 0.0 )
        v8 = 0.0;
    }
    else
    {
      v8 = FLOAT_1_0;
    }
    v9 = (float)((float)(1.0 - (float)(v7 * v8)) * this->lastInput.gasInput) + (float)(v7 * v8);
    if ( v9 <= 1.0 )
    {
      if ( v9 < 0.0 )
        v9 = 0.0;
    }
    else
    {
      v9 = FLOAT_1_0;
    }
    this->lastInput.gasInput = v9;
  }
  v10 = this->data.limiter;
  if ( v10 && this->lastInput.rpm > (float)((float)v10 * this->limiterMultiplier) )
    this->limiterOn = this->data.limiterCycles;
  v11 = this->limiterOn;
  if ( v11 > 0 )
  {
    this->lastInput.gasInput = 0.0;
    this->limiterOn = v11 - 1;
  }
  if ( this->lifeLeft <= 0.0 )
    this->fuelPressure = 0.0;
  v12 = this->electronicOverride * this->lastInput.gasInput;
  v46 = v12;
  this->lastInput.gasInput = v12;
  this->gasUsage = v12;
  v13 = Curve::getValue(&this->data.powerCurve, this->lastInput.rpm);
  v14 = this->data.coast1;
  v47 = v13;
  dta = 0.0;
  if ( v14 != 0.0 )
    dta = (float)(this->lastInput.rpm - (float)this->data.minimum) * v14;
  Engine::stepTurbos(this);
  v15 = this->status.turboBoost;
  v16 = FLOAT_1_0;
  if ( v15 == 0.0 )
    v17 = v47;
  else
    v17 = (float)(v15 + 1.0) * v47;
  v18 = this->data.coast2;
  v45 = v17;
  if ( v18 != 0.0 )
  {
    v20 = this->lastInput.rpm;
    if ( v20 <= 0.0 )
    {
      if ( v20 >= 0.0 )
        v16 = 0.0;
      else
        v16 = FLOAT_N1_0;
    }
    v19 = this->lastInput.rpm - (float)this->data.minimum;
    dta = dta - (float)((float)((float)(v19 * v19) * v18) * v16);
  }
  if ( this->coastGenerators._Myfirst != this->coastGenerators._Mylast )
  {
    v47 = 0.0;
    this->status.externalCoastTorque = 0.0;
    v21 = this->coastGenerators._Myfirst;
    v22 = (unsigned int)((char *)this->coastGenerators._Mylast - (char *)v21 + 3) >> 2;
    if ( v21 > this->coastGenerators._Mylast )
      v22 = 0;
    HIDWORD(Px) = v22;
    if ( v22 )
    {
      do
      {
        v23 = ((double (*)(ICoastGenerator *))(*v21)->getCoastTorque)(*v21)
            + this->status.externalCoastTorque;
        ++v21;
        v24 = ++LODWORD(v47);
        this->status.externalCoastTorque = v23;
      }
      while ( v24 != HIDWORD(Px) );
    }
    v3 = input;
    dta = dta + this->status.externalCoastTorque;
  }
  v25 = this->lastInput.rpm;
  if ( (float)this->data.minimum >= v25 )
  {
    dta = 0.0;
    this->status.externalCoastTorque = 0.0;
  }
  v26 = this->status.turboBoost;
  if ( (float)((float)(1.0 - this->lastInput.gasInput) * v26) <= this->bovThreshold )
    this->bov = 0.0;
  else
    this->bov = 1.0;
  v27 = this->turboBoostDamageThreshold;
  if ( v27 != 0.0 && v26 > v27 )
    this->lifeLeft = this->lifeLeft
                   - (float)((float)((float)((float)(v26 - v27) * this->turboBoostDamageK) * 0.003)
                           * this->physicsEngine->mechanicalDamageRate);
  v28 = this->rpmDamageThreshold;
  if ( v28 != 0.0 && v25 > v28 )
    this->lifeLeft = this->lifeLeft
                   - (float)((float)((float)((float)(v25 - v28) * this->rpmDamageK) * 0.003)
                           * this->physicsEngine->mechanicalDamageRate);
  v29 = PhysicsEngine::getAirDensity(this->car->ksPhysics);
  v30 = this->restrictor;
  v47 = v29 * 0.82630974;
  v31 = v47;
  if ( v30 > 0.0 )
  {
    v31 = v47 - (float)((float)((float)(v30 * v3->rpm) * 0.000099999997) * v46);
    if ( v31 < 0.0 )
      v31 = 0.0;
  }
  v32 = (float)((float)((float)((float)(v45 - dta) * v46) + dta) * v31);
  v33 = this->fuelPressure;
  Px = v32;
  this->status.outTorque = v32;
  if ( v33 > 0.0 )
  {
    v34 = this->lastInput.rpm;
    if ( (float)this->data.minimum <= v34 )
    {
      if ( this->data.overlapGain == 0.0 )
        goto LABEL_62;
      v36 = *(double *)__libm_sse2_sin().m128_u64 * 0.5 - 0.5;
      v35 = (float)(v36
                  * (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v34 - this->data.overlapIdealRPM) & _xmm)
                          * this->data.overlapGain))
          + Px;
    }
    else if ( this->isEngineStallEnabled )
    {
      if ( GetAsyncKeyState(8) )
        v35 = this->starterTorque;
      else
        v35 = (float)(v34 * -0.0099999998);
    }
    else
    {
      v35 = DOUBLE_15_0;
      if ( v32 >= 15.0 )
        v35 = v32;
    }
    this->status.outTorque = v35;
  }
LABEL_62:
  v37 = this->fuelPressure;
  if ( v37 < 1.0 )
    this->status.outTorque = (this->status.outTorque - this->lastInput.rpm * -0.01) * v37 + this->lastInput.rpm * -0.01;
  v38 = this->torqueGenerators._Myfirst;
  dtb = 0;
  v39 = (unsigned int)((char *)this->torqueGenerators._Mylast - (char *)v38 + 3) >> 2;
  if ( v38 > this->torqueGenerators._Mylast )
    v39 = 0;
  HIDWORD(Px) = v39;
  if ( v39 )
  {
    do
    {
      v40 = ((double (*)(ITorqueGenerator *))(*v38)->getOutputTorque)(*v38);
      ++v38;
      ++dtb;
      this->status.outTorque = v40 + this->status.outTorque;
    }
    while ( dtb != HIDWORD(Px) );
  }
  v41 = this->limiterOn != 0;
  Px = this->status.outTorque;
  this->status.isLimiterOn = v41;
  if ( __dtest(&Px) > 0 )
    _printf("!_finite(output->outTorque) : %f\n", this->lastInput.rpm);
  v42 = this->maxPowerW_Dynamic;
  this->electronicOverride = 1.0;
  v43 = input->rpm * this->status.outTorque * 0.1046999990940094;
  if ( v43 > v42 )
    this->maxPowerW_Dynamic = v43;
}
void Engine::stepP2P(Engine *this, float dt)
{
  float v2; // xmm0_4
  bool v4; // zf
  Turbo *v5; // ecx
  Turbo *i; // eax
  Car *v7; // ecx
  Turbo *v8; // ecx
  Turbo *j; // eax
  OnGearRequestEvent message; // [esp+0h] [ebp-8h] BYREF

  v2 = FLOAT_1000_0;
  if ( (float)(dt + this->p2p.timeAccum) <= 1000.0 )
    v2 = dt + this->p2p.timeAccum;
  v4 = !this->p2p.active;
  this->p2p.timeAccum = v2;
  if ( v4 )
  {
    if ( this->p2p.activations > 0 && this->car->controls.kers && v2 > this->p2p.coolDownS )
    {
      _printf("PUSH TO PASS ACTIVATED\n");
      --this->p2p.activations;
      this->p2p.timeAccum = 0.0;
      this->p2p.active = 1;
      v5 = this->turbos._Mylast;
      for ( i = this->turbos._Myfirst; i != v5; ++i )
        i->data.wastegate = this->p2p.overboost + this->p2p.baseWastegate;
      v7 = this->car;
      message.request = this->p2p.activations;
      message.nextGear = 1;
      Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&v7->evOnPush2Pass, &message);
    }
  }
  else if ( v2 > this->p2p.timeS )
  {
    _printf("PUSH TO PASS DEACTIVATED\n");
    this->p2p.timeAccum = 0.0;
    this->p2p.active = 0;
    v8 = this->turbos._Mylast;
    for ( j = this->turbos._Myfirst; j != v8; ++j )
      j->data.wastegate = this->p2p.baseWastegate;
  }
}
void Engine::stepTurbos(Engine *this)
{
  TurboDynamicController *v2; // edi
  TurboDynamicController *v3; // esi
  DynamicController *v4; // ebx
  double v5; // st7
  Turbo *v6; // eax
  double v7; // st7
  Turbo *v8; // eax
  Turbo *v9; // edi
  Turbo *v10; // esi
  float *v11; // eax
  double v12; // st7
  float v13; // [esp+1Ch] [ebp-4h] BYREF

  v2 = this->turboControllers._Mylast;
  v3 = this->turboControllers._Myfirst;
  if ( v3 != v2 )
  {
    v4 = &v3->controller;
    do
    {
      if ( LOBYTE(v4[1].car) )
      {
        v5 = DynamicController::eval(v4);
        v6 = v3->turbo;
        v13 = v5;
        v6->data.wastegate = v13;
      }
      else
      {
        v7 = DynamicController::eval(v4);
        v8 = v3->turbo;
        v13 = v7;
        v8->data.maxBoost = v13;
      }
      ++v3;
      v4 = (DynamicController *)((char *)v4 + 28);
    }
    while ( v3 != v2 );
  }
  this->status.turboBoost = 0.0;
  v9 = this->turbos._Mylast;
  v10 = this->turbos._Myfirst;
  if ( v10 != v9 )
  {
    v13 = 0.0;
    do
    {
      v11 = &v13;
      if ( this->lastInput.rpm > 0.0 )
        v11 = &this->lastInput.rpm;
      Turbo::step(v10, this->lastInput.gasInput, *v11, 0.003);
      v12 = Turbo::getBoost(v10++);
      this->status.turboBoost = v12 * this->fuelPressure + this->status.turboBoost;
    }
    while ( v10 != v9 );
  }
}
