#include "autoclutch.h
void Autoclutch::Autoclutch(Autoclutch *this)
{
  this->rpmMin = 0.0;
  this->rpmMax = 0.0;
  this->clutchSpeed = 0.0;
  *(_WORD *)&this->useAutoOnStart = 257;
  this->isForced = 0;
  this->car = 0;
  Curve::Curve(&this->clutchSequence.clutchCurve);
  this->clutchSequence.currentTime = 0.0;
  this->clutchSequence.isDone = 1;
  Curve::Curve(&this->upshiftProfile);
  Curve::Curve(&this->downshiftProfile);
  this->clutchValueSignal = 0.0;
}
double Autoclutch::getDownshiftSequenceDuration(Autoclutch *this)
{
  Curve *v1; // esi
  double v2; // st7
  std::pair<float,float> result; // [esp+4h] [ebp-8h] BYREF

  v1 = &this->downshiftProfile;
  if ( Curve::getCount(&this->downshiftProfile) )
    v2 = Curve::getPairAtIndex(v1, &result, 3)->first;
  else
    v2 = 0.0;
  return v2;
}
void Autoclutch::setDownshiftProfile(Autoclutch *this, Curve *dp)
{
  std::vector<float>::operator=(
    (std::vector<unsigned int> *)&this->downshiftProfile.references,
    (const std::vector<unsigned int> *)&dp->references);
  std::vector<float>::operator=(
    (std::vector<unsigned int> *)&this->downshiftProfile.values,
    (const std::vector<unsigned int> *)&dp->values);
  this->downshiftProfile.fastStep = dp->fastStep;
  this->downshiftProfile.cubicSplineReady = dp->cubicSplineReady;
  std::vector<CTData>::operator=(&this->downshiftProfile.cSpline.mElements, &dp->cSpline.mElements);
  if ( &this->downshiftProfile.filename != &dp->filename )
    std::wstring::assign(&this->downshiftProfile.filename, &dp->filename, 0, 0xFFFFFFFF);
}
void Autoclutch::~Autoclutch(Autoclutch *this)
{
  Curve::~Curve(&this->downshiftProfile);
  Curve::~Curve(&this->upshiftProfile);
  Curve::~Curve(&this->clutchSequence.clutchCurve);
}
void Autoclutch::init(Autoclutch *this, Car *car)
{
  _BYTE v3[28]; // [esp-1Ch] [ebp-38h] BYREF
  int v4; // [esp+18h] [ebp-4h]

  this->car = car;
  this->clutchSpeed = 1.0;
  this->rpmMin = 1500.0;
  this->rpmMax = 2500.0;
  this->clutchValueSignal = 0.0;
  *(_WORD *)&this->useAutoOnStart = 257;
  *(_DWORD *)&v3[24] = 7;
  *(_DWORD *)&v3[20] = 0;
  *(_WORD *)&v3[4] = 0;
  std::wstring::assign((std::wstring *)&v3[4], &car->unixName, 0, 0xFFFFFFFF);
  Autoclutch::loadINI(this, *(std::wstring *)&v3[4]);
  *(_DWORD *)v3 = &std::_Func_impl<std::_Callable_obj<_lambda_e1bed8e0568154e3fae5d19ba4df8d87_,0>,std::allocator<std::_Func_class<void,OnGearRequestEvent const &>>,void,OnGearRequestEvent const &>::`vftable';
  *(_DWORD *)&v3[4] = this;
  *(_DWORD *)&v3[16] = v3;
  v4 = -1;
  Event<float>::addHandler(
    (Event<SessionInfo> *)&car->drivetrain.evOnGearRequest,
    *(std::function<void __cdecl(SessionInfo const &)> *)v3,
    this);
}
void Autoclutch::loadINI(Autoclutch *this, std::wstring carModel)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  Car *v5; // ecx
  bool v6; // bl
  int v7; // edi
  int v8; // eax
  bool v9; // cf
  int v10; // eax
  int v11; // eax
  int v12; // eax
  float ref; // [esp+0h] [ebp-15Ch]
  float refa; // [esp+0h] [ebp-15Ch]
  float refb; // [esp+0h] [ebp-15Ch]
  float refc; // [esp+0h] [ebp-15Ch]
  float refd; // [esp+0h] [ebp-15Ch]
  float refe; // [esp+0h] [ebp-15Ch]
  std::wstring key; // [esp+18h] [ebp-144h] BYREF
  std::wstring v20; // [esp+30h] [ebp-12Ch] BYREF
  std::wstring section; // [esp+48h] [ebp-114h] BYREF
  std::wstring upprofile; // [esp+60h] [ebp-FCh] BYREF
  std::wstring dnprofile; // [esp+78h] [ebp-E4h] BYREF
  std::wstring v24; // [esp+90h] [ebp-CCh] BYREF
  std::wstring _Left; // [esp+A8h] [ebp-B4h] BYREF
  std::wstring filename; // [esp+C0h] [ebp-9Ch] BYREF
  std::wstring v27; // [esp+D8h] [ebp-84h] BYREF
  std::wstring result; // [esp+F0h] [ebp-6Ch] BYREF
  INIReader r; // [esp+108h] [ebp-54h] BYREF
  int v30; // [esp+158h] [ebp-4h]

  v30 = 0;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  LOBYTE(v30) = 1;
  v3 = std::operator+<wchar_t>(&result, &_Left, &carModel);
  LOBYTE(v30) = 2;
  v4 = std::operator+<wchar_t>(&v27, v3, L"/data/drivetrain.ini");
  v5 = this->car;
  LOBYTE(v30) = 3;
  Car::getConfigPath(v5, &filename, v4);
  if ( v27._Myres >= 8 )
    operator delete(v27._Bx._Ptr);
  v27._Myres = 7;
  v27._Mysize = 0;
  v27._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v30) = 7;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Bx._Buf[0] = 0;
  _Left._Mysize = 0;
  INIReader::INIReader(&r, &filename);
  LOBYTE(v30) = 8;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"HEADER", 6u);
  LOBYTE(v30) = 9;
  v6 = INIReader::hasSection(&r, &section);
  LOBYTE(v30) = 8;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( v6 )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"VERSION", 7u);
    LOBYTE(v30) = 10;
    v20._Myres = 7;
    v20._Mysize = 0;
    v20._Bx._Buf[0] = 0;
    std::wstring::assign(&v20, L"HEADER", 6u);
    LOBYTE(v30) = 11;
    v7 = INIReader::getInt(&r, &v20, &section);
    if ( v20._Myres >= 8 )
      operator delete(v20._Bx._Ptr);
    v20._Myres = 7;
    v20._Mysize = 0;
    v20._Bx._Buf[0] = 0;
    LOBYTE(v30) = 8;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v7 >= 3 )
    {
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"FORCED_ON", 9u);
      LOBYTE(v30) = 12;
      v20._Myres = 7;
      v20._Mysize = 0;
      v20._Bx._Buf[0] = 0;
      std::wstring::assign(&v20, L"AUTOCLUTCH", 0xAu);
      LOBYTE(v30) = 13;
      v8 = INIReader::getInt(&r, &v20, &section);
      v9 = v20._Myres < 8;
      this->isForced = v8 != 0;
      if ( !v9 )
        operator delete(v20._Bx._Ptr);
      v20._Myres = 7;
      v20._Mysize = 0;
      v20._Bx._Buf[0] = 0;
      LOBYTE(v30) = 8;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
  }
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"UPSHIFT_PROFILE", 0xFu);
  LOBYTE(v30) = 14;
  v20._Myres = 7;
  v20._Mysize = 0;
  v20._Bx._Buf[0] = 0;
  std::wstring::assign(&v20, L"AUTOCLUTCH", 0xAu);
  LOBYTE(v30) = 15;
  INIReader::getString(&r, &upprofile, &v20, &key);
  if ( v20._Myres >= 8 )
    operator delete(v20._Bx._Ptr);
  v20._Myres = 7;
  v20._Mysize = 0;
  v20._Bx._Buf[0] = 0;
  LOBYTE(v30) = 18;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"DOWNSHIFT_PROFILE", 0x11u);
  LOBYTE(v30) = 19;
  v24._Myres = 7;
  v24._Mysize = 0;
  v24._Bx._Buf[0] = 0;
  std::wstring::assign(&v24, L"AUTOCLUTCH", 0xAu);
  LOBYTE(v30) = 20;
  INIReader::getString(&r, &dnprofile, &v24, &section);
  if ( v24._Myres >= 8 )
    operator delete(v24._Bx._Ptr);
  v24._Myres = 7;
  v24._Mysize = 0;
  v24._Bx._Buf[0] = 0;
  LOBYTE(v30) = 23;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  v20._Myres = 7;
  v20._Mysize = 0;
  v20._Bx._Buf[0] = 0;
  std::wstring::assign(&v20, L"USE_ON_CHANGES", 0xEu);
  LOBYTE(v30) = 24;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"AUTOCLUTCH", 0xAu);
  LOBYTE(v30) = 25;
  v10 = INIReader::getInt(&r, &key, &v20);
  v9 = key._Myres < 8;
  this->useAutoOnChange = v10 != 0;
  if ( !v9 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  LOBYTE(v30) = 23;
  if ( v20._Myres >= 8 )
    operator delete(v20._Bx._Ptr);
  if ( std::wstring::compare(&upprofile, 0, upprofile._Mysize, L"NONE", 4u) )
  {
    Curve::addValue(&this->upshiftProfile, 0.0, 1.0);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"POINT_0", 7u);
    LOBYTE(v30) = 26;
    ref = INIReader::getFloat(&r, &upprofile, &key) * 0.001;
    Curve::addValue(&this->upshiftProfile, ref, 0.0);
    LOBYTE(v30) = 23;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"POINT_1", 7u);
    LOBYTE(v30) = 27;
    refa = INIReader::getFloat(&r, &upprofile, &key) * 0.001;
    Curve::addValue(&this->upshiftProfile, refa, 0.0);
    LOBYTE(v30) = 23;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"POINT_2", 7u);
    LOBYTE(v30) = 28;
    refb = INIReader::getFloat(&r, &upprofile, &key) * 0.001;
    Curve::addValue(&this->upshiftProfile, refb, 1.0);
    LOBYTE(v30) = 23;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  if ( std::wstring::compare(&dnprofile, 0, dnprofile._Mysize, L"NONE", 4u) )
  {
    Curve::addValue(&this->downshiftProfile, 0.0, 1.0);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"POINT_0", 7u);
    LOBYTE(v30) = 29;
    refc = INIReader::getFloat(&r, &dnprofile, &key) * 0.001;
    Curve::addValue(&this->downshiftProfile, refc, 0.0);
    LOBYTE(v30) = 23;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"POINT_1", 7u);
    LOBYTE(v30) = 30;
    refd = INIReader::getFloat(&r, &dnprofile, &key) * 0.001;
    Curve::addValue(&this->downshiftProfile, refd, 0.0);
    LOBYTE(v30) = 23;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"POINT_2", 7u);
    LOBYTE(v30) = 31;
    refe = INIReader::getFloat(&r, &dnprofile, &key) * 0.001;
    Curve::addValue(&this->downshiftProfile, refe, 1.0);
    LOBYTE(v30) = 23;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
  }
  std::wstring::wstring(&v20, L"MIN_RPM");
  LOBYTE(v30) = 32;
  std::wstring::wstring(&key, L"AUTOCLUTCH");
  LOBYTE(v30) = 33;
  v11 = INIReader::getInt(&r, &key, &v20);
  v9 = key._Myres < 8;
  this->rpmMin = (float)v11;
  if ( !v9 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  LOBYTE(v30) = 23;
  if ( v20._Myres >= 8 )
    operator delete(v20._Bx._Ptr);
  std::wstring::wstring(&v20, L"MAX_RPM");
  LOBYTE(v30) = 34;
  std::wstring::wstring(&key, L"AUTOCLUTCH");
  LOBYTE(v30) = 35;
  v12 = INIReader::getInt(&r, &key, &v20);
  v9 = key._Myres < 8;
  this->rpmMax = (float)v12;
  if ( !v9 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  if ( v20._Myres >= 8 )
    operator delete(v20._Bx._Ptr);
  if ( this->rpmMin == 0.0 || this->rpmMax == 0.0 )
  {
    this->rpmMin = 1500.0;
    this->rpmMax = 2500.0;
  }
  if ( dnprofile._Myres >= 8 )
    operator delete(dnprofile._Bx._Ptr);
  dnprofile._Myres = 7;
  dnprofile._Mysize = 0;
  dnprofile._Bx._Buf[0] = 0;
  if ( upprofile._Myres >= 8 )
    operator delete(upprofile._Bx._Ptr);
  upprofile._Myres = 7;
  upprofile._Mysize = 0;
  upprofile._Bx._Buf[0] = 0;
  LOBYTE(v30) = 7;
  INIReader::~INIReader(&r);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  if ( carModel._Myres >= 8 )
    operator delete(carModel._Bx._Ptr);
}
void Autoclutch::onGearRequest(Autoclutch *this, const OnGearRequestEvent *ev)
{
  double v3; // xmm1_8
  const ClutchSequence *v4; // eax
  const ClutchSequence *v5; // eax
  ClutchSequence v6; // [esp+10h] [ebp-B8h] BYREF
  ClutchSequence v7; // [esp+64h] [ebp-64h] BYREF
  int v8; // [esp+C4h] [ebp-4h]

  if ( this->useAutoOnChange )
  {
    v3 = DOUBLE_0_01;
    if ( ev->request == eChangeDown && this->clutchValueSignal > 0.01 )
    {
      if ( Curve::getCount(&this->downshiftProfile) == 4 )
      {
        ClutchSequence::ClutchSequence(&v6, &this->downshiftProfile);
        v8 = 0;
        ClutchSequence::operator=(&this->clutchSequence, v4);
        v8 = -1;
        Curve::~Curve(&v6.clutchCurve);
      }
      v3 = DOUBLE_0_01;
    }
    if ( ev->request == eChangeUp && this->clutchValueSignal > v3 && Curve::getCount(&this->upshiftProfile) == 4 )
    {
      ClutchSequence::ClutchSequence(&v7, &this->upshiftProfile);
      v8 = 1;
      ClutchSequence::operator=(&this->clutchSequence, v5);
      v8 = -1;
      Curve::~Curve(&v7.clutchCurve);
    }
  }
}
void Autoclutch::step(Autoclutch *this, float dt)
{
  Car *v3; // ecx
  float v4; // xmm2_4
  float v5; // xmm1_4
  int v6; // eax
  float v7; // xmm3_4
  float v8; // xmm0_4
  float v9; // xmm4_4
  float v10; // xmm4_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  Car *v13; // eax
  Speed result; // [esp+Ch] [ebp-8h] BYREF
  bool v15; // [esp+13h] [ebp-1h]

  if ( !this->clutchSequence.isDone )
  {
    v15 = (float)(Car::getSpeed(this->car, &result)->value * 3.5999999) > 5.0;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
    if ( v15 )
    {
      Autoclutch::stepSequence(this, dt);
      return;
    }
    this->clutchSequence.isDone = 1;
  }
  if ( !this->useAutoOnStart && !this->isForced )
    return;
  v3 = this->car;
  v4 = FLOAT_1_0;
  v5 = FLOAT_1_0;
  v6 = v3->drivetrain.currentGear;
  v7 = v3->drivetrain.engine.velocity * 0.1591550715257987 * 60.0;
  if ( v6 == 2 || !v6 )
  {
    v8 = this->rpmMin;
    if ( v7 >= this->rpmMin )
    {
      v9 = this->rpmMax;
      if ( v9 >= v7 )
      {
        v5 = (float)(v7 - v8) / (float)(v9 - v8);
        this->clutchValueSignal = v5;
      }
    }
    if ( v7 > this->rpmMax )
      v5 = FLOAT_1_0;
LABEL_14:
    if ( v8 <= v7 )
      goto LABEL_22;
LABEL_15:
    v5 = 0.0;
    this->clutchValueSignal = 0.0;
    goto LABEL_22;
  }
  if ( v6 != 1 )
  {
    v8 = this->rpmMin;
    goto LABEL_14;
  }
  v15 = (float)(Car::getSpeed(v3, &result)->value * 3.5999999) < 5.0;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  v4 = FLOAT_1_0;
  if ( !v15 )
  {
    v5 = FLOAT_1_0;
    goto LABEL_22;
  }
  if ( this->car->controls.gas <= 0.2 )
    goto LABEL_15;
  v5 = FLOAT_1_0;
  this->clutchValueSignal = 1.0;
LABEL_22:
  v10 = this->clutchValueSignal;
  v11 = this->clutchSpeed * dt;
  if ( v11 <= COERCE_FLOAT(COERCE_UNSIGNED_INT(v5 - v10) & _xmm) )
  {
    if ( v5 <= v10 )
      this->clutchValueSignal = v10 - v11;
    else
      this->clutchValueSignal = v11 + v10;
  }
  else
  {
    this->clutchValueSignal = v5;
  }
  v12 = this->clutchValueSignal;
  v13 = this->car;
  if ( v12 <= v4 )
  {
    if ( v12 < 0.0 )
    {
      v13->controls.clutch = 0.0;
      return;
    }
    v4 = this->clutchValueSignal;
  }
  v13->controls.clutch = v4;
}
void Autoclutch::stepSequence(Autoclutch *this, float dt)
{
  double v3; // st7
  float v4; // xmm0_4
  float v5; // xmm0_4
  Car *v6; // eax
  float v7; // xmm1_4
  float dta; // [esp+10h] [ebp+4h]

  v3 = Curve::getValue(&this->clutchSequence.clutchCurve, this->clutchSequence.currentTime);
  v4 = dt + this->clutchSequence.currentTime;
  this->clutchValueSignal = v3;
  this->clutchSequence.currentTime = v4;
  dta = Curve::getMaxReference(&this->clutchSequence.clutchCurve);
  if ( this->clutchSequence.currentTime > dta )
    this->clutchSequence.isDone = 1;
  v5 = this->clutchValueSignal;
  v6 = this->car;
  v7 = FLOAT_1_0;
  if ( v5 > 1.0 || (v7 = 0.0, v5 < 0.0) )
    v6->controls.clutch = v7;
  else
    v6->controls.clutch = v5;
}
