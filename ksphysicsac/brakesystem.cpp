#include "brakesystem.h
void BrakeSystem::BrakeSystem(BrakeSystem *this)
{
  this->frontBias = 0.69999999;
  this->brakePowerMultiplier = 1.0;
  this->electronicOverride = 1.0;
  this->handBrakeTorque = 0.0;
  this->ebbInstant = 0.5;
  `eh vector constructor iterator'(
    this->discs,
    0x5Cu,
    4,
    (void (*)(void *))BrakeDisc::BrakeDisc,
    (void (*)(void *))BrakeDisc::~BrakeDisc);
  this->limitDown = 0.0;
  this->limitUp = 1.0;
  this->rearCorrectionTorque = 0.0;
  this->biasOverride = -1.0;
  this->hasCockpitBias = 1;
  this->biasStep = 0.0049999999;
  this->ebbMode = Disabled;
  strcpy((char *)&this->ebbFrontMultiplier, "�̌?");
  DynamicController::DynamicController(&this->steerBrake.controller);
  this->hasBrakeTempsData = 0;
  std::ofstream::ofstream(&this->tempRunFile, 1);
  DynamicController::DynamicController(&this->ebbController);
}
void BrakeSystem::~BrakeSystem(BrakeSystem *this)
{
  DynamicController::~DynamicController(&this->ebbController);
  std::ofstream::~ofstream<char,std::char_traits<char>>((std::ofstream *)&this->tempRunFile.gap58[8]);
  std::ios::~ios<char,std::char_traits<char>>(&this->tempRunFile.gap58[8]);
  DynamicController::~DynamicController(&this->steerBrake.controller);
  `eh vector destructor iterator'(this->discs, 0x5Cu, 4, (void (*)(void *))BrakeDisc::~BrakeDisc);
}
void BrakeSystem::activateTempRunFile(BrakeSystem *this, bool mode)
{
  std::wstring *v3; // esi
  std::wstring *v4; // ecx
  std::wstring *v5; // eax
  std::wstring *v6; // eax
  std::wstring *v7; // eax
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  std::ofstream *v10; // esi
  std::filebuf *v11; // eax
  int v12; // ecx
  std::ofstream *v13; // esi
  int version; // [esp+10h] [ebp-8Ch] BYREF
  std::wstring filename; // [esp+14h] [ebp-88h] BYREF
  std::wstring v16; // [esp+2Ch] [ebp-70h] BYREF
  std::wstring v17; // [esp+44h] [ebp-58h] BYREF
  std::wstring v18; // [esp+5Ch] [ebp-40h] BYREF
  std::wstring result; // [esp+74h] [ebp-28h] BYREF
  int v20; // [esp+98h] [ebp-4h]

  if ( mode )
  {
    v3 = Track::getName(this->car->ksPhysics->track, &result);
    v4 = &this->car->unixName;
    v20 = 0;
    v5 = std::operator+<wchar_t>(&v17, L"TempRuns/", v4);
    LOBYTE(v20) = 1;
    v6 = std::operator+<wchar_t>(&v18, v5, L"@");
    LOBYTE(v20) = 2;
    v7 = std::operator+<wchar_t>(&v16, v6, v3);
    LOBYTE(v20) = 3;
    std::operator+<wchar_t>(&filename, v7, L".trun");
    if ( v16._Myres >= 8 )
      operator delete(v16._Bx._Ptr);
    v16._Myres = 7;
    v16._Mysize = 0;
    v16._Bx._Buf[0] = 0;
    if ( v18._Myres >= 8 )
      operator delete(v18._Bx._Ptr);
    v18._Myres = 7;
    v18._Mysize = 0;
    v18._Bx._Buf[0] = 0;
    if ( v17._Myres >= 8 )
      operator delete(v17._Bx._Ptr);
    v17._Myres = 7;
    v17._Mysize = 0;
    v17._Bx._Buf[0] = 0;
    LOBYTE(v20) = 8;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    result._Myres = 7;
    result._Bx._Buf[0] = 0;
    v8 = &filename;
    if ( filename._Myres >= 8 )
      v8 = (std::wstring *)filename._Bx._Ptr;
    result._Mysize = 0;
    _printf("Opening temps run at %S\n", v8->_Bx._Buf);
    v9 = &filename;
    v10 = &this->tempRunFile;
    if ( filename._Myres >= 8 )
      v9 = (std::wstring *)filename._Bx._Ptr;
    v11 = std::filebuf::open((std::filebuf *)&this->tempRunFile.gap0[4], v9->_Bx._Buf, 34, 64);
    v12 = *(_DWORD *)(*(_DWORD *)v10->gap0 + 4);
    if ( v11 )
      std::ios::clear((char *)v10 + v12, 0, 0);
    else
      std::ios::setstate((char *)v10 + v12, 2, 0);
    this->hasBrakeTempsData = 0;
    version = 1;
    std::ostream::write(&this->tempRunFile, &version, 4, 0);
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
  }
  else
  {
    v13 = &this->tempRunFile;
    if ( !std::filebuf::close((std::filebuf *)&this->tempRunFile.gap0[4]) )
      std::ios::setstate((char *)v13 + *(_DWORD *)(*(_DWORD *)v13->gap0 + 4), 2, 0);
  }
}
double BrakeSystem::getBrakePower(BrakeSystem *this)
{
  return this->brakePower;
}
double BrakeSystem::getFrontBias(BrakeSystem *this)
{
  double result; // st7

  if ( this->biasOverride == -1.0 )
    result = this->frontBias;
  else
    result = this->biasOverride;
  return result;
}
void __userpurge BrakeSystem::init(BrakeSystem *this@<ecx>, unsigned int a2@<ebx>, Car *car)
{
  std::wstring *v4; // eax
  int v5; // eax
  int v6; // esi
  std::wstring v7; // [esp-18h] [ebp-98h] BYREF
  std::wstring _Left; // [esp+10h] [ebp-70h] BYREF
  std::wstring filename; // [esp+28h] [ebp-58h] BYREF
  std::wstring result; // [esp+40h] [ebp-40h] BYREF
  std::wstring dataPath; // [esp+58h] [ebp-28h] BYREF
  int v12; // [esp+7Ch] [ebp-4h]

  v7._Myres = 13;
  this->car = car;
  v7._Mysize = (unsigned int)L"content/cars/";
  this->brakePower = 2000.0;
  this->frontBias = 0.69999999;
  this->brakePowerMultiplier = 1.0;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, (const wchar_t *)v7._Mysize, v7._Myres);
  v12 = 0;
  v4 = std::operator+<wchar_t>(&result, &_Left, &car->unixName);
  LOBYTE(v12) = 1;
  std::operator+<wchar_t>(&dataPath, v4, L"/data/");
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v12) = 4;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  _Left._Myres = 7;
  _Left._Mysize = 0;
  this->electronicOverride = 0.0;
  v7._Mysize = 0;
  v7._Myres = 7;
  _Left._Bx._Buf[0] = 0;
  v7._Bx._Buf[0] = 0;
  std::wstring::assign(&v7, &dataPath, 0, 0xFFFFFFFF);
  BrakeSystem::loadINI(this, v7);
  std::operator+<wchar_t>(&filename, &dataPath, L"ctrl_ebb.ini");
  LOBYTE(v12) = 5;
  if ( Path::fileExists(a2, &filename, 0) )
  {
    DynamicController::DynamicController((DynamicController *)&_Left, car, &filename);
    v6 = v5;
    this->ebbController.car = *(Car **)v5;
    LOBYTE(v12) = 6;
    std::vector<DynamicControllerStage>::operator=(
      &this->ebbController.stages,
      (const std::vector<DynamicControllerStage> *)(v5 + 4));
    this->ebbController.ready = *(_BYTE *)(v6 + 16);
    LOBYTE(v12) = 5;
    DynamicController::~DynamicController((DynamicController *)&_Left);
    this->ebbMode = DynamicController;
  }
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  if ( dataPath._Myres >= 8 )
    operator delete(dataPath._Bx._Ptr);
}
void BrakeSystem::loadINI(BrakeSystem *this, std::wstring dataPath)
{
  BrakeSystem *v2; // ebp
  const std::wstring *v3; // eax
  Car *v4; // ecx
  const std::wstring *v5; // eax
  double v6; // st7
  bool v7; // cf
  double v8; // st7
  double v9; // st7
  int v10; // eax
  double v11; // st7
  char v12; // bl
  float v13; // xmm0_4
  const std::wstring *v14; // eax
  char v15; // al
  char v16; // bl
  const std::wstring *v17; // eax
  int v18; // eax
  int v19; // esi
  std::vector<float> *v20; // esi
  int v21; // edi
  std::wstring *v22; // ebx
  std::vector<float> *v23; // edi
  int v24; // ebp
  double v25; // st7
  Curve *v26; // esi
  const std::wstring *v27; // esi
  double v28; // st7
  double v29; // st7
  const std::wstring *v30; // eax
  Car *v31; // ecx
  const std::wstring *v32; // eax
  bool v33; // bl
  double v34; // st7
  double v35; // st7
  Car *v36; // [esp+8h] [ebp-1D0h]
  char v37; // [esp+24h] [ebp-1B4h]
  std::vector<float> *v38; // [esp+28h] [ebp-1B0h]
  float v39; // [esp+2Ch] [ebp-1ACh]
  float v40; // [esp+2Ch] [ebp-1ACh]
  int v41; // [esp+2Ch] [ebp-1ACh]
  std::wstring section; // [esp+34h] [ebp-1A4h] BYREF
  std::wstring v44; // [esp+4Ch] [ebp-18Ch] BYREF
  std::wstring key; // [esp+64h] [ebp-174h] BYREF
  std::wstring v46; // [esp+7Ch] [ebp-15Ch] BYREF
  std::wstring v47; // [esp+94h] [ebp-144h] BYREF
  std::wstring result; // [esp+ACh] [ebp-12Ch] BYREF
  INIReader r; // [esp+C4h] [ebp-114h] BYREF
  INIReader ini; // [esp+108h] [ebp-D0h] BYREF
  Curve v51; // [esp+14Ch] [ebp-8Ch] BYREF
  std::wstring sections[2]; // [esp+198h] [ebp-40h] BYREF
  int v53; // [esp+1D4h] [ebp-4h]

  v2 = this;
  v37 = 0;
  v53 = 0;
  v3 = std::operator+<wchar_t>(&result, &dataPath, L"brakes.ini");
  v4 = v2->car;
  LOBYTE(v53) = 1;
  v5 = Car::getConfigPath(v4, &v47, v3);
  LOBYTE(v53) = 2;
  INIReader::INIReader(&r, v5);
  if ( v47._Myres >= 8 )
    operator delete(v47._Bx._Ptr);
  v47._Myres = 7;
  v47._Mysize = 0;
  v47._Bx._Buf[0] = 0;
  LOBYTE(v53) = 5;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"MAX_TORQUE", 0xAu);
  LOBYTE(v53) = 6;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"DATA", 4u);
  LOBYTE(v53) = 7;
  v6 = INIReader::getFloat(&r, &section, &key);
  v7 = section._Myres < 8;
  v2->brakePower = v6;
  if ( !v7 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v53) = 5;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"FRONT_SHARE", 0xBu);
  LOBYTE(v53) = 8;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"DATA", 4u);
  LOBYTE(v53) = 9;
  v8 = INIReader::getFloat(&r, &section, &key);
  v7 = section._Myres < 8;
  v2->frontBias = v8;
  if ( !v7 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v53) = 5;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"HANDBRAKE_TORQUE", 0x10u);
  LOBYTE(v53) = 10;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"DATA", 4u);
  LOBYTE(v53) = 11;
  v9 = INIReader::getFloat(&r, &section, &key);
  v7 = section._Myres < 8;
  v2->handBrakeTorque = v9;
  if ( !v7 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v53) = 5;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"COCKPIT_ADJUSTABLE", 0x12u);
  LOBYTE(v53) = 12;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"DATA", 4u);
  LOBYTE(v53) = 13;
  v10 = INIReader::getInt(&r, &section, &key);
  v7 = section._Myres < 8;
  v2->hasCockpitBias = v10 != 0;
  if ( !v7 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v53) = 5;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"ADJUST_STEP", 0xBu);
  LOBYTE(v53) = 14;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"DATA", 4u);
  LOBYTE(v53) = 15;
  v11 = INIReader::getFloat(&r, &section, &key);
  v7 = section._Myres < 8;
  v2->biasStep = v11 * 0.0099999998;
  if ( !v7 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v53) = 5;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"EBB", 3u);
  LOBYTE(v53) = 16;
  v12 = INIReader::hasSection(&r, &key);
  LOBYTE(v53) = 5;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v12 )
  {
    v2->ebbMode = Internal;
    v44._Myres = 7;
    v44._Mysize = 0;
    v44._Bx._Buf[0] = 0;
    std::wstring::assign(&v44, L"FRONT_SHARE_MULTIPLIER", 0x16u);
    LOBYTE(v53) = 17;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"EBB", 3u);
    LOBYTE(v53) = 18;
    v13 = FLOAT_1_1;
    v39 = INIReader::getFloat(&r, &section, &v44);
    if ( v39 >= 1.1 )
    {
      std::wstring::wstring(&v46, L"FRONT_SHARE_MULTIPLIER");
      LOBYTE(v53) = 19;
      std::wstring::wstring(&key, L"EBB");
      v53 = 20;
      v12 = 3;
      v37 = 3;
      v40 = INIReader::getFloat(&r, &key, &v46);
      v13 = v40;
    }
    else
    {
      v12 = 0;
    }
    v2->ebbFrontMultiplier = v13;
    if ( (v12 & 2) != 0 )
    {
      v12 &= 0xFDu;
      v37 = v12;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
    }
    v53 = 18;
    if ( (v12 & 1) != 0 )
    {
      v12 &= 0xFEu;
      v37 = v12;
      if ( v46._Myres >= 8 )
        operator delete(v46._Bx._Ptr);
      v46._Myres = 7;
      v46._Mysize = 0;
      v46._Bx._Buf[0] = 0;
    }
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v53) = 5;
    if ( v44._Myres >= 8 )
      operator delete(v44._Bx._Ptr);
  }
  v14 = std::operator+<wchar_t>(&v44, &dataPath, L"steer_brake_controller.ini");
  LOBYTE(v53) = 21;
  v15 = Path::fileExists(v12, v14, 0);
  LOBYTE(v53) = 5;
  v16 = v15;
  if ( v44._Myres >= 8 )
    operator delete(v44._Bx._Ptr);
  if ( v16 )
  {
    _printf("INITIALIZING STEER BRAKE\n");
    v2->steerBrake.isActive = 1;
    v17 = std::operator+<wchar_t>(&v44, &dataPath, L"steer_brake_controller.ini");
    v36 = v2->car;
    LOBYTE(v53) = 22;
    DynamicController::DynamicController((DynamicController *)&section, v36, v17);
    v19 = v18;
    v2->steerBrake.controller.car = *(Car **)v18;
    LOBYTE(v53) = 23;
    std::vector<DynamicControllerStage>::operator=(
      &v2->steerBrake.controller.stages,
      (const std::vector<DynamicControllerStage> *)(v18 + 4));
    v2->steerBrake.controller.ready = *(_BYTE *)(v19 + 16);
    LOBYTE(v53) = 22;
    DynamicController::~DynamicController((DynamicController *)&section);
    LOBYTE(v53) = 5;
    if ( v44._Myres >= 8 )
      operator delete(v44._Bx._Ptr);
  }
  sections[0]._Myres = 7;
  sections[0]._Mysize = 0;
  sections[0]._Bx._Buf[0] = 0;
  std::wstring::assign(sections, L"TEMPS_FRONT", 0xBu);
  LOBYTE(v53) = 24;
  sections[1]._Myres = 7;
  sections[1]._Mysize = 0;
  sections[1]._Bx._Buf[0] = 0;
  std::wstring::assign(&sections[1], L"TEMPS_REAR", 0xAu);
  v20 = &v2->discs[0].perfCurve.references;
  LOBYTE(v53) = 25;
  v21 = 2;
  v38 = &v2->discs[0].perfCurve.references;
  v22 = sections;
  v41 = 2;
  do
  {
    if ( INIReader::hasSection(&r, v22) )
    {
      v23 = v20;
      v24 = 2;
      do
      {
        v44._Myres = 7;
        v44._Mysize = 0;
        v44._Bx._Buf[0] = 0;
        std::wstring::assign(&v44, L"TORQUE_K", 8u);
        LOBYTE(v53) = 26;
        v25 = INIReader::getFloat(&r, v22, &v44);
        v7 = v44._Myres < 8;
        *(float *)&v23[-1]._Myfirst = v25;
        LOBYTE(v53) = 25;
        if ( !v7 )
          operator delete(v44._Bx._Ptr);
        v44._Myres = 7;
        v44._Mysize = 0;
        v44._Bx._Buf[0] = 0;
        std::wstring::assign(&v44, L"PERF_CURVE", 0xAu);
        LOBYTE(v53) = 27;
        v26 = INIReader::getCurve(&r, &v51, v22, &v44);
        LOBYTE(v53) = 28;
        std::vector<float>::operator=(
          (std::vector<unsigned int> *)v23,
          (const std::vector<unsigned int> *)&v26->references);
        std::vector<float>::operator=(
          (std::vector<unsigned int> *)&v23[1],
          (const std::vector<unsigned int> *)&v26->values);
        v23[2]._Myfirst = (float *)LODWORD(v26->fastStep);
        LOBYTE(v23[2]._Mylast) = v26->cubicSplineReady;
        std::vector<CTData>::operator=(
          (std::vector<CubicSpline<float,float>::Element,std::allocator<CubicSpline<float,float>::Element> > *)&v23[3],
          &v26->cSpline.mElements);
        v27 = &v26->filename;
        if ( &v23[4] != (std::vector<float> *)v27 )
          std::wstring::assign((std::wstring *)&v23[4], v27, 0, 0xFFFFFFFF);
        LOBYTE(v53) = 27;
        Curve::~Curve(&v51);
        LOBYTE(v53) = 25;
        if ( v44._Myres >= 8 )
          operator delete(v44._Bx._Ptr);
        v44._Myres = 7;
        v44._Mysize = 0;
        v44._Bx._Buf[0] = 0;
        std::wstring::assign(&v44, L"COOL_TRANSFER", 0xDu);
        LOBYTE(v53) = 29;
        v28 = INIReader::getFloat(&r, v22, &v44);
        v7 = v44._Myres < 8;
        *(float *)&v23[-2]._Myend = v28;
        LOBYTE(v53) = 25;
        if ( !v7 )
          operator delete(v44._Bx._Ptr);
        v44._Myres = 7;
        v44._Mysize = 0;
        v44._Bx._Buf[0] = 0;
        std::wstring::assign(&v44, L"COOL_SPEED_FACTOR", 0x11u);
        LOBYTE(v53) = 30;
        v29 = INIReader::getFloat(&r, v22, &v44);
        v7 = v44._Myres < 8;
        *(float *)&v23[-1]._Mylast = v29;
        LOBYTE(v53) = 25;
        if ( !v7 )
          operator delete(v44._Bx._Ptr);
        v23 = (std::vector<float> *)((char *)v23 + 92);
        --v24;
      }
      while ( v24 );
      v2 = this;
      v20 = v38;
      v21 = v41;
      this->hasBrakeTempsData = 1;
    }
    else
    {
      v2->hasBrakeTempsData = 0;
    }
    v20 = (std::vector<float> *)((char *)v20 + 184);
    ++v22;
    --v21;
    v38 = v20;
    v41 = v21;
  }
  while ( v21 );
  v30 = std::operator+<wchar_t>(&key, &dataPath, L"setup.ini");
  v31 = v2->car;
  LOBYTE(v53) = 31;
  v32 = Car::getConfigPath(v31, &v46, v30);
  LOBYTE(v53) = 32;
  INIReader::INIReader(&ini, v32);
  if ( v46._Myres >= 8 )
    operator delete(v46._Bx._Ptr);
  v46._Myres = 7;
  v46._Mysize = 0;
  v46._Bx._Buf[0] = 0;
  LOBYTE(v53) = 35;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  v33 = 0;
  if ( ini.ready )
  {
    std::wstring::wstring(&v44, L"FRONT_BIAS");
    LOBYTE(v53) = 36;
    v37 |= 4u;
    if ( INIReader::hasSection(&ini, &v44) )
      v33 = 1;
  }
  v53 = 35;
  if ( (v37 & 4) != 0 && v44._Myres >= 8 )
    operator delete(v44._Bx._Ptr);
  if ( v33 )
  {
    std::wstring::wstring(&section, L"MIN");
    LOBYTE(v53) = 37;
    std::wstring::wstring(&v44, L"FRONT_BIAS");
    LOBYTE(v53) = 38;
    v34 = INIReader::getFloat(&ini, &v44, &section);
    v7 = v44._Myres < 8;
    v2->limitDown = v34 * 0.0099999998;
    if ( !v7 )
      operator delete(v44._Bx._Ptr);
    v44._Myres = 7;
    v44._Mysize = 0;
    v44._Bx._Buf[0] = 0;
    LOBYTE(v53) = 35;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    std::wstring::wstring(&section, L"MAX");
    LOBYTE(v53) = 39;
    std::wstring::wstring(&v44, L"FRONT_BIAS");
    LOBYTE(v53) = 40;
    v35 = INIReader::getFloat(&ini, &v44, &section);
    v7 = v44._Myres < 8;
    v2->limitUp = v35 * 0.0099999998;
    if ( !v7 )
      operator delete(v44._Bx._Ptr);
    v44._Myres = 7;
    v44._Mysize = 0;
    v44._Bx._Buf[0] = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    _printf("Brake bias limits set to (%f , %f)\n", v2->limitDown, v2->limitUp);
  }
  LOBYTE(v53) = 25;
  INIReader::~INIReader(&ini);
  LOBYTE(v53) = 5;
  `eh vector destructor iterator'(sections, 0x18u, 2, (void (*)(void *))std::wstring::~wstring);
  LOBYTE(v53) = 0;
  INIReader::~INIReader(&r);
  if ( dataPath._Myres >= 8 )
    operator delete(dataPath._Bx._Ptr);
}
void BrakeSystem::reset(BrakeSystem *this)
{
  BrakeSystem *v1; // edx

  v1 = (BrakeSystem *)this->discs;
  for ( this->biasOverride = -1.0; v1 != (BrakeSystem *)&this->limitDown; v1 = (BrakeSystem *)((char *)v1 + 92) )
    v1->frontBias = this->car->ksPhysics->ambientTemperature;
}
void BrakeSystem::saveTempsRunFame(BrakeSystem *this)
{
  int i; // esi
  int j; // esi
  Speed result; // [esp+Ch] [ebp-8h] BYREF
  float vel; // [esp+10h] [ebp-4h] BYREF

  vel = Car::getSpeed(this->car, &result)->value;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  std::ostream::write(&this->tempRunFile, &vel, 4, 0);
  for ( i = 0; i < 4; ++i )
    std::ostream::write(&this->tempRunFile, &this->car->tyres[i].status.angularVelocity, 4, 0);
  for ( j = 0; j < 4; ++j )
    std::ostream::write(&this->tempRunFile, &this->car->tyres[j], 4, 0);
}
void BrakeSystem::setManualFrontBias(BrakeSystem *this, int value)
{
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm0_4

  if ( this->hasCockpitBias )
  {
    if ( this->biasOverride == -1.0 )
      this->biasOverride = this->frontBias;
    v2 = this->limitUp;
    v3 = this->limitDown;
    v4 = (float)((float)value * this->biasStep) + this->biasOverride;
    if ( v4 <= v2 )
    {
      if ( v3 > v4 )
      {
        this->biasOverride = v3;
        return;
      }
      v2 = (float)((float)value * this->biasStep) + this->biasOverride;
    }
    this->biasOverride = v2;
  }
}
void BrakeSystem::step(BrakeSystem *this, float dt)
{
  char v3; // dl
  float v4; // xmm2_4
  Car *v5; // ecx
  float v6; // xmm1_4
  Speed *v7; // eax
  bool v8; // bl
  float v9; // xmm1_4
  float v10; // xmm0_4
  Car *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm4_4
  float v14; // xmm1_4
  float v15; // xmm3_4
  double v16; // st7
  Car *v17; // eax
  float loc_bias; // [esp+8h] [ebp-Ch] BYREF
  float v19; // [esp+Ch] [ebp-8h]
  float bs; // [esp+10h] [ebp-4h]

  v3 = 0;
  bs = 0.0;
  v4 = this->frontBias;
  if ( this->biasOverride != -1.0 )
    v4 = this->biasOverride;
  if ( this->ebbMode == Internal )
  {
    v5 = this->car;
    v6 = v5->tyres[3].status.load + v5->tyres[2].status.load;
    v19 = v5->tyres[1].status.load + v5->tyres[0].status.load;
    bs = v6 + v19;
    v8 = 0;
    if ( (float)(v6 + v19) != 0.0 )
    {
      v7 = Car::getSpeed(v5, (Speed *)&loc_bias);
      v3 = 1;
      if ( (float)(v7->value * 3.5999999) > 10.0 )
        v8 = 1;
    }
    if ( (v3 & 1) != 0 )
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&loc_bias);
    if ( v8 )
    {
      v9 = FLOAT_1_0;
      v10 = (float)(v19 / bs) * this->ebbFrontMultiplier;
      if ( v10 > 1.0 || (v9 = 0.0, v10 < 0.0) )
        v10 = v9;
      this->ebbInstant = v10;
    }
    else
    {
      this->ebbInstant = this->frontBias;
    }
    v4 = this->ebbInstant;
  }
  else if ( this->ebbMode == DynamicController )
  {
    loc_bias = DynamicController::eval(&this->ebbController);
    v4 = loc_bias;
  }
  if ( v4 <= this->limitUp )
  {
    if ( this->limitDown > v4 )
      v4 = this->limitDown;
  }
  else
  {
    v4 = this->limitUp;
  }
  v11 = this->car;
  v12 = this->electronicOverride;
  if ( v12 <= v11->controls.brake )
    v12 = v11->controls.brake;
  v13 = FLOAT_1_0;
  v14 = (float)(this->brakePower * this->brakePowerMultiplier) * v12;
  v11->tyres[0].inputs.brakeTorque = v14 * v4;
  this->car->tyres[1].inputs.brakeTorque = v14 * v4;
  v15 = (float)((float)(1.0 - v4) * v14) - this->rearCorrectionTorque;
  if ( v15 < 0.0 )
    v15 = 0.0;
  this->car->tyres[2].inputs.brakeTorque = v15;
  this->car->tyres[3].inputs.brakeTorque = v15;
  this->car->tyres[2].inputs.handBrakeTorque = this->car->controls.handBrake * this->handBrakeTorque;
  this->car->tyres[3].inputs.handBrakeTorque = this->car->controls.handBrake * this->handBrakeTorque;
  if ( this->steerBrake.isActive )
  {
    v16 = DynamicController::eval(&this->steerBrake.controller);
    v17 = this->car;
    v13 = FLOAT_1_0;
    bs = v16;
    if ( bs >= 0.0 )
      v17->tyres[3].inputs.brakeTorque = v17->tyres[3].inputs.brakeTorque + bs;
    else
      v17->tyres[2].inputs.brakeTorque = v17->tyres[2].inputs.brakeTorque - bs;
  }
  if ( this->hasBrakeTempsData && v13 >= this->car->tyres[0].aiMult )
    BrakeSystem::stepTemps(this, dt);
  if ( (unsigned __int8)std::ios_base::operator bool((char *)&this->tempRunFile + *(_DWORD *)(*(_DWORD *)this->tempRunFile.gap0
                                                                                            + 4)) )
    BrakeSystem::saveTempsRunFame(this);
  this->electronicOverride = 0.0;
}
void BrakeSystem::stepTemps(BrakeSystem *this, float dt)
{
  BrakeSystem *v2; // esi
  BrakeDisc *v3; // edi
  Car *v4; // esi
  double v5; // st7
  Car *v6; // ecx
  int v7; // eax
  float v8; // xmm2_4
  int v9; // xmm1_4
  float v10; // xmm0_4
  float *v11; // [esp+Ch] [ebp-14h]
  float v12; // [esp+10h] [ebp-10h]
  Speed result; // [esp+14h] [ebp-Ch] BYREF
  BrakeSystem *v14; // [esp+18h] [ebp-8h]
  int v15; // [esp+1Ch] [ebp-4h]

  v2 = this;
  v14 = this;
  v3 = this->discs;
  v11 = &this->limitDown;
  if ( this->discs != (BrakeDisc *)&this->limitDown )
  {
    v15 = 0;
    do
    {
      v4 = v2->car;
      v5 = Curve::getValue(&v3->perfCurve, v3->t);
      *(float *)((char *)&v4->tyres[0].inputs.brakeTorque + v15) = v5
                                                                 * *(float *)((char *)&v4->tyres[0].inputs.brakeTorque
                                                                            + v15);
      v2 = v14;
      v12 = (float)((float)((float)(Car::getSpeed(v14->car, &result)->value * 3.5999999) * v3->coolSpeedFactor) + 1.0)
          * v3->coolTransfer;
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
      v6 = v2->car;
      v7 = v15;
      v8 = (float)((float)((float)(v6->ksPhysics->ambientTemperature - v3->t) * v12) * dt) + v3->t;
      v3->t = v8;
      v9 = *(_DWORD *)((char *)&v6->tyres[0].status.angularVelocity + v7);
      v10 = *(float *)((char *)&v6->tyres[0].inputs.brakeTorque + v7) * v3->torqueK;
      v15 = v7 + 1632;
      v3->t = (float)((float)((float)(COERCE_FLOAT(v9 & _xmm) * v10) * 0.001) * dt) + v8;
      ++v3;
    }
    while ( v3 != (BrakeDisc *)v11 );
  }
}
BOOL BrakeSystem::isUsingEBB(BrakeSystem *this)
{
  return this->ebbMode != Disabled;
}
