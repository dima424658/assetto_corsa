#include "ers.h"
void ERS::ERS(ERS *this)
{
  this->ICoastGenerator::__vftable = (ICoastGenerator_vtbl *)&ICoastGenerator::`vftable';
  this->ITorqueGenerator::__vftable = (ERS_vtbl *)&ERS::`vftable'{for `ITorqueGenerator'};
  this->ICoastGenerator::__vftable = (ICoastGenerator_vtbl *)&ERS::`vftable'{for `ICoastGenerator'};
  this->present = 0;
  this->kineticRecovery = 1.0;
  this->status.kineticRecovery = 0.0;
  this->status.heatRecovery = 0.0;
  this->isHeatCharginBattery = 1;
  this->ersPowerControllers._Myfirst = 0;
  this->ersPowerControllers._Mylast = 0;
  this->ersPowerControllers._Myend = 0;
  this->ersPowerControllersFront._Myfirst = 0;
  this->ersPowerControllersFront._Mylast = 0;
  this->ersPowerControllersFront._Myend = 0;
  this->defaultPowerControllerIndex = 0;
  *(_DWORD *)&this->isCharging = &unk_1010100;
  this->car = 0;
  *(_OWORD *)&this->chargeK = 0i64;
  this->hasButtonOverride = 0;
  this->dischargeKFront = 0.0;
  Curve::Curve(&this->torqueLUT);
  Curve::Curve(&this->coastLUT);
  DynamicController::DynamicController(&this->controller);
  DynamicController::DynamicController(&this->controllerFront);
  this->charge = DOUBLE_1_0;
  this->maxJ = 0.0;
  this->currentJ = 0.0;
  this->input = 0.0;
  this->heatChargeK = 0.0;
  this->heatTorque = 0.30000001;
  this->rearCorrectionTorque = 0.0;
  DynamicController::DynamicController(&this->frontController);
  Curve::Curve(&this->frontTorqueLUT);
  this->frontTorqueVectoringBias = 1.0;
}
void ERS::~ERS(ERS *this)
{
  this->ITorqueGenerator::__vftable = (ERS_vtbl *)&ERS::`vftable'{for `ITorqueGenerator'};
  this->ICoastGenerator::__vftable = (ICoastGenerator_vtbl *)&ERS::`vftable'{for `ICoastGenerator'};
  Curve::~Curve(&this->frontTorqueLUT);
  DynamicController::~DynamicController(&this->frontController);
  DynamicController::~DynamicController(&this->controllerFront);
  DynamicController::~DynamicController(&this->controller);
  Curve::~Curve(&this->coastLUT);
  Curve::~Curve(&this->torqueLUT);
  if ( this->ersPowerControllersFront._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->ersPowerControllersFront);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<ERSPowerController>>>(
      this->ersPowerControllersFront._Myfirst,
      this->ersPowerControllersFront._Mylast);
    operator delete(this->ersPowerControllersFront._Myfirst);
    this->ersPowerControllersFront._Myfirst = 0;
    this->ersPowerControllersFront._Mylast = 0;
    this->ersPowerControllersFront._Myend = 0;
  }
  if ( this->ersPowerControllers._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->ersPowerControllers);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<ERSPowerController>>>(
      this->ersPowerControllers._Myfirst,
      this->ersPowerControllers._Mylast);
    operator delete(this->ersPowerControllers._Myfirst);
    this->ersPowerControllers._Myfirst = 0;
    this->ersPowerControllers._Mylast = 0;
    this->ersPowerControllers._Myend = 0;
  }
  this->ITorqueGenerator::__vftable = (ERS_vtbl *)&ITorqueGenerator::`vftable';
  this->ICoastGenerator::__vftable = (ICoastGenerator_vtbl *)&ICoastGenerator::`vftable';
}
ERS *ERS::`vector deleting destructor'(char *this, unsigned int a2)
{
  return ERS::`scalar deleting destructor'((ERS *)(this - 4), a2);
}
ERS *ERS::`scalar deleting destructor'(ERS *this, unsigned int a2)
{
  ERS::~ERS(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
double ERS::getCoastTorque(ERS *this)
{
  int v2; // ecx
  float v4; // [esp+8h] [ebp-4h]
  float v5; // [esp+8h] [ebp-4h]

  if ( !LOBYTE(this->ICoastGenerator::__vftable) )
    return 0.0;
  if ( *(double *)(&this->controllerFront + 1) >= 1.0 )
    return 0.0;
  v2 = *(_DWORD *)&this->isCharging;
  if ( *(double *)(v2 + 688) == 0.0 )
    return 0.0;
  v4 = *(float *)(v2 + 220);
  v5 = Curve::getValue((Curve *)&this->torqueLUT.filename._Myres, *(double *)(v2 + 512) * 0.1591550715257987 * 60.0)
     * v4
     * *(float *)&this->present;
  return COERCE_FLOAT(LODWORD(v5) ^ _xmm);
}
double ERS::getOutputTorque(ERS *this)
{
  double result; // st7

  if ( this->present )
    result = Curve::getValue(&this->torqueLUT, this->car->drivetrain.engine.velocity * 0.1591550715257987 * 60.0)
           * this->input;
  else
    result = 0.0;
  return result;
}
void ERS::init(ERS *this, Car *car)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  int v5; // esi
  double v6; // st7
  bool v7; // cf
  Curve *v8; // esi
  const std::wstring *v9; // esi
  Curve *v10; // esi
  const std::wstring *v11; // esi
  double v12; // st7
  int v13; // eax
  int v14; // esi
  int v15; // eax
  double v16; // st7
  double v17; // st7
  double v18; // st7
  int v19; // eax
  unsigned int i; // ebx
  std::wstring *v21; // esi
  std::wstring *v22; // eax
  std::wstring *v23; // eax
  std::wstring *v24; // eax
  const std::wstring *v25; // eax
  int v26; // eax
  int v27; // esi
  ERSPowerController *v28; // esi
  std::wstring *v29; // esi
  std::wstring *v30; // eax
  std::wstring *v31; // eax
  std::wstring *v32; // eax
  const std::wstring *v33; // eax
  int v34; // eax
  int v35; // esi
  ERSPowerController *v36; // esi
  std::wstring *v37; // eax
  void (*v38)(const char *const, ...); // esi
  bool v39; // al
  bool v40; // bl
  bool v41; // al
  bool v42; // bl
  int v43; // esi
  const Curve *v44; // eax
  std::function<void __cdecl(OnPhysicsStepCompleted const &)> v45; // [esp-18h] [ebp-264h] BYREF
  float v; // [esp+0h] [ebp-24Ch]
  std::wstring section; // [esp+20h] [ebp-22Ch] BYREF
  std::wstring fn_front; // [esp+38h] [ebp-214h] BYREF
  std::wstring key; // [esp+50h] [ebp-1FCh] BYREF
  std::wstring v50; // [esp+68h] [ebp-1E4h] BYREF
  std::wstring v51; // [esp+80h] [ebp-1CCh] BYREF
  std::wstring v52; // [esp+98h] [ebp-1B4h] BYREF
  std::wstring path; // [esp+B0h] [ebp-19Ch] BYREF
  ERSPowerController v54; // [esp+C8h] [ebp-184h] BYREF
  ERSPowerController c; // [esp+F4h] [ebp-158h] BYREF
  INIReader ini; // [esp+120h] [ebp-12Ch] BYREF
  std::wstring result; // [esp+164h] [ebp-E8h] BYREF
  std::wstring v58; // [esp+17Ch] [ebp-D0h] BYREF
  std::wstring fn; // [esp+194h] [ebp-B8h] BYREF
  Curve v60; // [esp+1ACh] [ebp-A0h] BYREF
  INIReader v61; // [esp+1F8h] [ebp-54h] BYREF
  int v62; // [esp+248h] [ebp-4h]

  this->car = car;
  v3 = std::operator+<wchar_t>(&result, L"content/cars/", &car->unixName);
  v62 = 0;
  v4 = std::operator+<wchar_t>(&v58, v3, L"/data/ers.ini");
  LOBYTE(v62) = 1;
  Car::getConfigPath(car, &fn, v4);
  if ( v58._Myres >= 8 )
    operator delete(v58._Bx._Ptr);
  v58._Myres = 7;
  v58._Mysize = 0;
  v58._Bx._Buf[0] = 0;
  LOBYTE(v62) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  INIReader::INIReader(&ini, &fn);
  LOBYTE(v62) = 5;
  if ( ini.ready )
  {
    fn_front._Myres = 7;
    fn_front._Mysize = 0;
    fn_front._Bx._Buf[0] = 0;
    std::wstring::assign(&fn_front, L"VERSION", 7u);
    LOBYTE(v62) = 6;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HEADER", 6u);
    LOBYTE(v62) = 7;
    v5 = INIReader::getInt(&ini, &section, &fn_front);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v62) = 5;
    if ( fn_front._Myres >= 8 )
      operator delete(fn_front._Bx._Ptr);
    _printf("Loading ERS VERSION %d\n", v5);
    this->present = 1;
    fn_front._Myres = 7;
    fn_front._Mysize = 0;
    fn_front._Bx._Buf[0] = 0;
    std::wstring::assign(&fn_front, L"CHARGE_K", 8u);
    LOBYTE(v62) = 8;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"KINETIC", 7u);
    LOBYTE(v62) = 9;
    v6 = INIReader::getFloat(&ini, &section, &fn_front);
    v7 = section._Myres < 8;
    this->chargeK = v6 * 0.001;
    if ( !v7 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v62) = 5;
    if ( fn_front._Myres >= 8 )
      operator delete(fn_front._Bx._Ptr);
    fn_front._Myres = 7;
    fn_front._Mysize = 0;
    fn_front._Bx._Buf[0] = 0;
    std::wstring::assign(&fn_front, L"TORQUE_CURVE", 0xCu);
    LOBYTE(v62) = 10;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"KINETIC", 7u);
    LOBYTE(v62) = 11;
    v8 = INIReader::getCurve(&ini, &v60, &section, &fn_front);
    LOBYTE(v62) = 12;
    std::vector<float>::operator=(
      (std::vector<unsigned int> *)&this->torqueLUT.references,
      (const std::vector<unsigned int> *)&v8->references);
    std::vector<float>::operator=(
      (std::vector<unsigned int> *)&this->torqueLUT.values,
      (const std::vector<unsigned int> *)&v8->values);
    this->torqueLUT.fastStep = v8->fastStep;
    this->torqueLUT.cubicSplineReady = v8->cubicSplineReady;
    std::vector<CTData>::operator=(&this->torqueLUT.cSpline.mElements, &v8->cSpline.mElements);
    v9 = &v8->filename;
    if ( &this->torqueLUT.filename != v9 )
      std::wstring::assign(&this->torqueLUT.filename, v9, 0, 0xFFFFFFFF);
    LOBYTE(v62) = 11;
    Curve::~Curve(&v60);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v62) = 5;
    if ( fn_front._Myres >= 8 )
      operator delete(fn_front._Bx._Ptr);
    fn_front._Myres = 7;
    fn_front._Mysize = 0;
    fn_front._Bx._Buf[0] = 0;
    std::wstring::assign(&fn_front, L"COAST_CURVE", 0xBu);
    LOBYTE(v62) = 13;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"KINETIC", 7u);
    LOBYTE(v62) = 14;
    v10 = INIReader::getCurve(&ini, &v60, &section, &fn_front);
    LOBYTE(v62) = 15;
    std::vector<float>::operator=(
      (std::vector<unsigned int> *)&this->coastLUT.references,
      (const std::vector<unsigned int> *)&v10->references);
    std::vector<float>::operator=(
      (std::vector<unsigned int> *)&this->coastLUT.values,
      (const std::vector<unsigned int> *)&v10->values);
    this->coastLUT.fastStep = v10->fastStep;
    this->coastLUT.cubicSplineReady = v10->cubicSplineReady;
    std::vector<CTData>::operator=(&this->coastLUT.cSpline.mElements, &v10->cSpline.mElements);
    v11 = &v10->filename;
    if ( &this->coastLUT.filename != v11 )
      std::wstring::assign(&this->coastLUT.filename, v11, 0, 0xFFFFFFFF);
    LOBYTE(v62) = 14;
    Curve::~Curve(&v60);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v62) = 5;
    if ( fn_front._Myres >= 8 )
      operator delete(fn_front._Bx._Ptr);
    fn_front._Myres = 7;
    fn_front._Mysize = 0;
    fn_front._Bx._Buf[0] = 0;
    std::wstring::assign(&fn_front, L"DISCHARGE_TIME", 0xEu);
    LOBYTE(v62) = 16;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"KINETIC", 7u);
    LOBYTE(v62) = 17;
    v12 = INIReader::getFloat(&ini, &section, &fn_front);
    v7 = section._Myres < 8;
    this->dischargeK = 1000.0 / v12;
    if ( !v7 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v62) = 5;
    if ( fn_front._Myres >= 8 )
      operator delete(fn_front._Bx._Ptr);
    DynamicController::DynamicController((DynamicController *)&section, car, &fn);
    v14 = v13;
    this->controller.car = *(Car **)v13;
    LOBYTE(v62) = 18;
    std::vector<DynamicControllerStage>::operator=(
      &this->controller.stages,
      (const std::vector<DynamicControllerStage> *)(v13 + 4));
    this->controller.ready = *(_BYTE *)(v14 + 16);
    LOBYTE(v62) = 5;
    DynamicController::~DynamicController((DynamicController *)&section);
    LODWORD(v) = 19;
    this->charge = DOUBLE_1_0;
    fn_front._Myres = 7;
    fn_front._Mysize = 0;
    fn_front._Bx._Buf[0] = 0;
    std::wstring::assign(&fn_front, L"HAS_BUTTON_OVERRIDE", LODWORD(v));
    LOBYTE(v62) = 19;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"KINETIC", 7u);
    LOBYTE(v62) = 20;
    v15 = INIReader::getInt(&ini, &section, &fn_front);
    v7 = section._Myres < 8;
    this->hasButtonOverride = v15 != 0;
    if ( !v7 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v62) = 5;
    if ( fn_front._Myres >= 8 )
      operator delete(fn_front._Bx._Ptr);
    fn_front._Myres = 7;
    fn_front._Mysize = 0;
    fn_front._Bx._Buf[0] = 0;
    std::wstring::assign(&fn_front, L"MAX_KJ_PER_LAP", 0xEu);
    LOBYTE(v62) = 21;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"KINETIC", 7u);
    LOBYTE(v62) = 22;
    v16 = INIReader::getFloat(&ini, &section, &fn_front);
    v7 = section._Myres < 8;
    this->maxJ = v16 * 1000.0;
    if ( !v7 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v62) = 5;
    if ( fn_front._Myres >= 8 )
      operator delete(fn_front._Bx._Ptr);
    fn_front._Myres = 7;
    fn_front._Mysize = 0;
    fn_front._Bx._Buf[0] = 0;
    std::wstring::assign(&fn_front, L"CHARGE_K", 8u);
    LOBYTE(v62) = 23;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HEAT", 4u);
    LOBYTE(v62) = 24;
    v17 = INIReader::getFloat(&ini, &section, &fn_front);
    v7 = section._Myres < 8;
    this->heatChargeK = v17;
    if ( !v7 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v62) = 5;
    if ( fn_front._Myres >= 8 )
      operator delete(fn_front._Bx._Ptr);
    std::wstring::wstring(&key, L"TORQUE_PERC");
    LOBYTE(v62) = 25;
    std::wstring::wstring(&fn_front, L"HEAT");
    LOBYTE(v62) = 26;
    v18 = INIReader::getFloat(&ini, &fn_front, &key);
    v7 = fn_front._Myres < 8;
    this->heatTorque = v18 * 0.0099999998;
    if ( !v7 )
      operator delete(fn_front._Bx._Ptr);
    fn_front._Myres = 7;
    fn_front._Mysize = 0;
    fn_front._Bx._Buf[0] = 0;
    LOBYTE(v62) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    std::wstring::wstring(&key, L"DEFAULT_CONTROLLER");
    LOBYTE(v62) = 27;
    std::wstring::wstring(&fn_front, L"KINETIC");
    LOBYTE(v62) = 28;
    v19 = INIReader::getInt(&ini, &fn_front, &key);
    v7 = fn_front._Myres < 8;
    this->defaultPowerControllerIndex = v19;
    if ( !v7 )
      operator delete(fn_front._Bx._Ptr);
    fn_front._Myres = 7;
    fn_front._Mysize = 0;
    fn_front._Bx._Buf[0] = 0;
    LOBYTE(v62) = 5;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    this->kineticRecovery = 0.5;
    for ( i = 0; ; ++i )
    {
      v21 = std::to_wstring(&key, i);
      LOBYTE(v62) = 29;
      v22 = std::operator+<wchar_t>(&v51, L"content/cars/", &car->unixName);
      LOBYTE(v62) = 30;
      v23 = std::operator+<wchar_t>(&v52, v22, L"/data/ctrl_ers_");
      LOBYTE(v62) = 31;
      v24 = std::operator+<wchar_t>(&section, v23, v21);
      LOBYTE(v62) = 32;
      v25 = std::operator+<wchar_t>(&v50, v24, L".ini");
      LOBYTE(v62) = 33;
      Car::getConfigPath(car, &path, v25);
      if ( v50._Myres >= 8 )
        operator delete(v50._Bx._Ptr);
      v50._Myres = 7;
      v50._Mysize = 0;
      v50._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( v52._Myres >= 8 )
        operator delete(v52._Bx._Ptr);
      v52._Myres = 7;
      v52._Mysize = 0;
      v52._Bx._Buf[0] = 0;
      if ( v51._Myres >= 8 )
        operator delete(v51._Bx._Ptr);
      v51._Myres = 7;
      v51._Mysize = 0;
      v51._Bx._Buf[0] = 0;
      LOBYTE(v62) = 39;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Bx._Buf[0] = 0;
      key._Mysize = 0;
      if ( !Path::fileExists(i, &path, 0) )
        break;
      c.name._Myres = 7;
      c.name._Mysize = 0;
      c.name._Bx._Buf[0] = 0;
      LOBYTE(v62) = 40;
      DynamicController::DynamicController(&c.ctrl);
      LOBYTE(v62) = 41;
      DynamicController::DynamicController((DynamicController *)&section, car, &path);
      v27 = v26;
      c.ctrl.car = *(Car **)v26;
      LOBYTE(v62) = 42;
      std::vector<DynamicControllerStage>::operator=(
        &c.ctrl.stages,
        (const std::vector<DynamicControllerStage> *)(v26 + 4));
      c.ctrl.ready = *(_BYTE *)(v27 + 16);
      LOBYTE(v62) = 41;
      DynamicController::~DynamicController((DynamicController *)&section);
      INIReader::INIReader((INIReader *)&v60, &path);
      LOBYTE(v62) = 43;
      v50._Myres = 7;
      v50._Mysize = 0;
      v50._Bx._Buf[0] = 0;
      std::wstring::assign(&v50, L"NAME", 4u);
      LOBYTE(v62) = 44;
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      std::wstring::assign(&section, L"HEADER", 6u);
      LOBYTE(v62) = 45;
      v28 = (ERSPowerController *)INIReader::getString((INIReader *)&v60, &key, &section, &v50);
      if ( &c != v28 )
      {
        if ( c.name._Myres >= 8 )
          operator delete(c.name._Bx._Ptr);
        c.name._Myres = 7;
        c.name._Mysize = 0;
        c.name._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&c.name, &v28->name);
      }
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v62) = 43;
      if ( v50._Myres >= 8 )
        operator delete(v50._Bx._Ptr);
      std::vector<ERSPowerController>::push_back(&this->ersPowerControllers, &c);
      v29 = std::to_wstring(&section, i);
      LOBYTE(v62) = 46;
      v30 = std::operator+<wchar_t>(&v50, L"content/cars/", &car->unixName);
      LOBYTE(v62) = 47;
      v31 = std::operator+<wchar_t>(&v52, v30, L"/data/ctrl_ers_front_");
      LOBYTE(v62) = 48;
      v32 = std::operator+<wchar_t>(&v51, v31, v29);
      LOBYTE(v62) = 49;
      v33 = std::operator+<wchar_t>(&key, v32, L".ini");
      LOBYTE(v62) = 50;
      Car::getConfigPath(car, &fn_front, v33);
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      if ( v51._Myres >= 8 )
        operator delete(v51._Bx._Ptr);
      v51._Myres = 7;
      v51._Mysize = 0;
      v51._Bx._Buf[0] = 0;
      if ( v52._Myres >= 8 )
        operator delete(v52._Bx._Ptr);
      v52._Myres = 7;
      v52._Mysize = 0;
      v52._Bx._Buf[0] = 0;
      if ( v50._Myres >= 8 )
        operator delete(v50._Bx._Ptr);
      v50._Myres = 7;
      v50._Mysize = 0;
      v50._Bx._Buf[0] = 0;
      LOBYTE(v62) = 56;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Bx._Buf[0] = 0;
      section._Mysize = 0;
      if ( Path::fileExists(i, &fn_front, 0) )
      {
        v54.name._Myres = 7;
        v54.name._Mysize = 0;
        v54.name._Bx._Buf[0] = 0;
        LOBYTE(v62) = 57;
        DynamicController::DynamicController(&v54.ctrl);
        LOBYTE(v62) = 58;
        DynamicController::DynamicController((DynamicController *)&section, car, &fn_front);
        v35 = v34;
        v54.ctrl.car = *(Car **)v34;
        LOBYTE(v62) = 59;
        std::vector<DynamicControllerStage>::operator=(
          &v54.ctrl.stages,
          (const std::vector<DynamicControllerStage> *)(v34 + 4));
        v54.ctrl.ready = *(_BYTE *)(v35 + 16);
        LOBYTE(v62) = 58;
        DynamicController::~DynamicController((DynamicController *)&section);
        INIReader::INIReader(&v61, &fn_front);
        LOBYTE(v62) = 60;
        std::wstring::wstring(&v51, L"NAME");
        LOBYTE(v62) = 61;
        std::wstring::wstring(&v50, L"HEADER");
        LOBYTE(v62) = 62;
        v36 = (ERSPowerController *)INIReader::getString(&v61, &key, &v50, &v51);
        if ( &v54 != v36 )
        {
          if ( v54.name._Myres >= 8 )
            operator delete(v54.name._Bx._Ptr);
          v54.name._Myres = 7;
          v54.name._Mysize = 0;
          v54.name._Bx._Buf[0] = 0;
          std::wstring::_Assign_rv(&v54.name, &v36->name);
        }
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        if ( v50._Myres >= 8 )
          operator delete(v50._Bx._Ptr);
        v50._Myres = 7;
        v50._Mysize = 0;
        v50._Bx._Buf[0] = 0;
        LOBYTE(v62) = 60;
        if ( v51._Myres >= 8 )
          operator delete(v51._Bx._Ptr);
        std::vector<ERSPowerController>::push_back(&this->ersPowerControllersFront, &v54);
        LOBYTE(v62) = 58;
        INIReader::~INIReader(&v61);
        LOBYTE(v62) = 63;
        DynamicController::~DynamicController(&v54.ctrl);
        if ( v54.name._Myres >= 8 )
          operator delete(v54.name._Bx._Ptr);
      }
      if ( fn_front._Myres >= 8 )
        operator delete(fn_front._Bx._Ptr);
      fn_front._Myres = 7;
      fn_front._Mysize = 0;
      fn_front._Bx._Buf[0] = 0;
      LOBYTE(v62) = 41;
      INIReader::~INIReader((INIReader *)&v60);
      LOBYTE(v62) = 64;
      DynamicController::~DynamicController(&c.ctrl);
      if ( c.name._Myres >= 8 )
        operator delete(c.name._Bx._Ptr);
      LOBYTE(v62) = 5;
      if ( path._Myres >= 8 )
        operator delete(path._Bx._Ptr);
    }
    LOBYTE(v62) = 5;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&path);
    if ( this->ersPowerControllers._Myfirst == this->ersPowerControllers._Mylast )
    {
      std::wstring::wstring(&key, L"Error, no ctrl_ers_*.ini controllers found\n");
      v37 = &key;
      v38 = (void (*)(const char *const, ...))_printf;
      if ( key._Myres >= 8 )
        v37 = (std::wstring *)key._Bx._Ptr;
      LOBYTE(v62) = 65;
      _printf("Kunos Simulazioni: CRITICAL ERROR\n%S\n", v37->_Bx._Buf);
      ksGenerateCrash();
      LOBYTE(v62) = 5;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    }
    else
    {
      v38 = (void (*)(const char *const, ...))_printf;
    }
    ERS::setPowerController(this, this->defaultPowerControllerIndex);
    v45._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_fb4451d7c810bd09b68377dd26c19dcb_,0>,std::allocator<std::_Func_class<void,OnLapCompletedEvent const &>>,void,OnLapCompletedEvent const &>::`vftable';
    v45._Space._Pfn[1] = (void (__cdecl *)())this;
    v45._Impl = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)&v45;
    LOBYTE(v62) = 5;
    Event<std::wstring>::addHandler((Event<OnPhysicsStepCompleted> *)&car->evOnLapCompleted, v45, this);
    std::wstring::wstring(&v51, L"BRAKE_REAR_CORRECTION");
    LOBYTE(v62) = 67;
    std::wstring::wstring(&key, L"KINETIC");
    LOBYTE(v62) = 68;
    this->rearCorrectionTorque = INIReader::getFloat(&ini, &key, &v51);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    LOBYTE(v62) = 5;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v51);
    std::wstring::wstring(&key, L"COCKPIT_CONTROLS");
    LOBYTE(v62) = 69;
    v39 = INIReader::hasSection(&ini, &key);
    LOBYTE(v62) = 5;
    v40 = v39;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    if ( v40 )
    {
      std::wstring::wstring(&v51, L"DELIVERY_PROFILE");
      LOBYTE(v62) = 70;
      std::wstring::wstring(&key, L"COCKPIT_CONTROLS");
      LOBYTE(v62) = 71;
      this->cockpitControls.deliveryProfile = INIReader::getInt(&ini, &key, &v51) != 0;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      LOBYTE(v62) = 5;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v51);
      std::wstring::wstring(&v52, L"MGU_H_MODE");
      LOBYTE(v62) = 72;
      std::wstring::wstring(&key, L"COCKPIT_CONTROLS");
      LOBYTE(v62) = 73;
      this->cockpitControls.mguHMode = INIReader::getInt(&ini, &key, &v52) != 0;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      LOBYTE(v62) = 5;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v52);
      std::wstring::wstring(&path, L"RECOVERY");
      LOBYTE(v62) = 74;
      std::wstring::wstring(&key, L"COCKPIT_CONTROLS");
      LOBYTE(v62) = 75;
      this->cockpitControls.recovery = INIReader::getInt(&ini, &key, &path) != 0;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      LOBYTE(v62) = 5;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&path);
    }
    std::wstring::wstring(&key, L"FRONT_MOTORS");
    LOBYTE(v62) = 76;
    v41 = INIReader::hasSection(&ini, &key);
    LOBYTE(v62) = 5;
    v42 = v41;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    if ( v42 )
    {
      v38("Loading FRONT_MOTORS\n");
      v43 = std::vector<ERSPowerController>::size(&this->ersPowerControllersFront);
      if ( std::vector<ERSPowerController>::size(&this->ersPowerControllers) != v43 )
      {
        std::wstring::wstring(
          &key,
          L"ERROR: For ERS with front motors, there needs to be the same amount of controllers present for front and rear");
        LOBYTE(v62) = 77;
        ks_critical_error(&key);
        LOBYTE(v62) = 5;
        std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      }
      std::wstring::wstring(&v51, L"TORQUE_CURVE");
      LOBYTE(v62) = 78;
      std::wstring::wstring(&key, L"FRONT_MOTORS");
      LOBYTE(v62) = 79;
      v44 = INIReader::getCurve(&ini, &v60, &key, &v51);
      LOBYTE(v62) = 80;
      Curve::operator=(&this->frontTorqueLUT, v44);
      LOBYTE(v62) = 79;
      Curve::~Curve(&v60);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      LOBYTE(v62) = 5;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v51);
      std::wstring::wstring(&v52, L"DISCHARGE_TIME");
      LOBYTE(v62) = 81;
      std::wstring::wstring(&key, L"FRONT_MOTORS");
      LOBYTE(v62) = 82;
      this->dischargeKFront = 1000.0 / INIReader::getFloat(&ini, &key, &v52);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      LOBYTE(v62) = 5;
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v52);
      std::wstring::wstring(&path, L"FRONT_TORQUE_VECTORING_BIAS");
      LOBYTE(v62) = 83;
      std::wstring::wstring(&key, L"FRONT_MOTORS");
      LOBYTE(v62) = 84;
      v = INIReader::getFloat(&ini, &key, &path);
      this->frontTorqueVectoringBias = saturate(v);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
      std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&path);
    }
  }
  LOBYTE(v62) = 4;
  INIReader::~INIReader(&ini);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&fn);
}
void ERS::reset(ERS *this)
{
  this->charge = DOUBLE_1_0;
  this->currentJ = 0.0;
}
void ERS::setPowerController(ERS *this, int index)
{
  int v3; // ebp
  ERSPowerController *v4; // eax
  ERSPowerController *v5; // esi
  ERSPowerController *v6; // esi

  if ( index >= 0 && index < (unsigned int)(this->ersPowerControllers._Mylast - this->ersPowerControllers._Myfirst) )
  {
    v3 = index;
    v4 = &this->ersPowerControllers._Myfirst[index];
    if ( v4->name._Myres >= 8 )
      v4 = (ERSPowerController *)v4->name._Bx._Ptr;
    _printf("ERS, setting Kinetic power controller index: %d (%S)\n", index, v4->name._Bx._Buf);
    v5 = this->ersPowerControllers._Myfirst;
    this->controller.car = v5[v3].ctrl.car;
    std::vector<DynamicControllerStage>::operator=(&this->controller.stages, &v5[v3].ctrl.stages);
    this->controller.ready = v5[v3].ctrl.ready;
    if ( index < (unsigned int)(this->ersPowerControllersFront._Mylast - this->ersPowerControllersFront._Myfirst) )
    {
      v6 = this->ersPowerControllersFront._Myfirst;
      this->controllerFront.car = v6[v3].ctrl.car;
      std::vector<DynamicControllerStage>::operator=(&this->controllerFront.stages, &v6[v3].ctrl.stages);
      this->controllerFront.ready = v6[v3].ctrl.ready;
    }
  }
}
void ERS::step(ERS *this, float dt)
{
  Car *v3; // ecx
  float v4; // xmm3_4
  double v5; // xmm4_8
  float v6; // xmm1_4
  float v7; // xmm3_4
  double v8; // xmm5_8
  float v9; // xmm1_4
  float v10; // xmm1_4
  double v11; // xmm1_8
  float v12; // xmm1_4
  float v13; // xmm0_4
  Car *v14; // eax
  Engine *v15; // esi
  float v16; // xmm6_4
  float v17; // xmm1_4
  double v18; // xmm4_8
  double v19; // xmm5_8
  double v20; // xmm4_8
  float v21; // xmm0_4
  float v22; // xmm0_4
  long double v23; // xmm0_8
  double v24; // xmm4_8
  float v25; // xmm1_4
  float v26; // xmm1_4
  float v27; // xmm4_4
  Car *v28; // ecx
  double v29; // xmm1_8
  Car *v30; // eax
  float v31; // xmm1_4
  float v32; // xmm2_4
  float v33; // xmm1_4
  double v34; // st7
  Car *v35; // eax
  float v36; // [esp+Ch] [ebp-1Ch]
  float v37; // [esp+10h] [ebp-18h]
  float v38; // [esp+10h] [ebp-18h]
  float v39; // [esp+10h] [ebp-18h]
  float v40; // [esp+10h] [ebp-18h]
  float v41; // [esp+14h] [ebp-14h]
  float v42; // [esp+14h] [ebp-14h]
  float v43; // [esp+14h] [ebp-14h]
  float v44; // [esp+14h] [ebp-14h]
  float v45; // [esp+14h] [ebp-14h]
  float v46; // [esp+14h] [ebp-14h]
  double v47; // [esp+18h] [ebp-10h]
  float v48; // [esp+1Ch] [ebp-Ch]
  float v49; // [esp+20h] [ebp-8h]
  bool v50; // [esp+27h] [ebp-1h]

  if ( this->present )
  {
    if ( Car::isInPits(this->car) )
      this->charge = DOUBLE_1_0;
    v3 = this->car;
    v47 = v3->drivetrain.rootVelocity;
    v4 = COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v3->drivetrain.acEngine.status.outTorque - v3->drivetrain.acEngine.status.externalCoastTorque) ^ _xmm);
    v36 = 0.0;
    if ( v4 < 0.0 )
      v4 = 0.0;
    v5 = v3->drivetrain.ratio;
    if ( v5 == 0.0 )
    {
      v6 = 0.0;
      v4 = 0.0;
    }
    else
    {
      v6 = (float)((float)(COERCE_FLOAT(LODWORD(v3->tyres[2].inputs.brakeTorque) & _xmm) * v3->tyres[2].absOverride)
                 + (float)(COERCE_FLOAT(LODWORD(v3->tyres[1].inputs.brakeTorque) & _xmm) * v3->tyres[1].absOverride))
         / v5;
    }
    v50 = this->isHeatCharginBattery && (!this->hasButtonOverride || !v3->controls.kers);
    v41 = v6 + v4;
    v37 = Engine::getMaxTurboBoost(&v3->drivetrain.acEngine, 0);
    if ( v37 <= 0.0 )
      v7 = 0.0;
    else
      v7 = this->car->drivetrain.acEngine.status.turboBoost / v37;
    v8 = this->charge;
    if ( v8 >= 1.0 )
    {
      this->status.kineticRecovery = 0.0;
      this->status.heatRecovery = 0.0;
    }
    else
    {
      v9 = v41 * this->chargeK * v47 * this->kineticRecovery;
      this->status.kineticRecovery = v9;
      if ( v50 )
        this->status.heatRecovery = v7 * this->heatChargeK;
      else
        this->status.heatRecovery = 0.0;
      v10 = v9 + this->status.heatRecovery;
      if ( v10 < 0.0 )
        v10 = 0.0;
      v11 = v10 * dt + v8;
      if ( v11 <= 1.0 )
      {
        if ( v11 < 0.0 )
          v11 = 0.0;
        this->charge = v11;
      }
      else
      {
        this->charge = DOUBLE_1_0;
      }
    }
    this->isCharging = this->status.kineticRecovery > 0.0;
    v42 = DynamicController::eval(&this->controller);
    v12 = v42;
    if ( v42 <= 1.0 )
    {
      if ( v42 < 0.0 )
        v12 = 0.0;
    }
    else
    {
      v12 = FLOAT_1_0;
    }
    this->input = v12;
    v43 = DynamicController::eval(&this->controllerFront);
    v13 = v43;
    v48 = v43;
    if ( v43 <= 1.0 )
    {
      if ( v43 < 0.0 )
      {
        v13 = 0.0;
        v48 = 0.0;
      }
    }
    else
    {
      v13 = FLOAT_1_0;
      v48 = FLOAT_1_0;
    }
    v49 = v13;
    v44 = 0.0;
    if ( !v50 )
      v44 = (float)(this->heatTorque * this->car->controls.gas) * v7;
    if ( this->hasButtonOverride && this->car->controls.kers )
    {
      this->input = 1.0;
      v48 = FLOAT_1_0;
      v49 = FLOAT_1_0;
      v44 = this->heatTorque * v7;
    }
    if ( this->charge <= 0.0 || this->car->speedLimiter.isLimiting || this->currentJ > this->maxJ )
    {
      this->input = 0.0;
      v48 = 0.0;
      v49 = 0.0;
    }
    v14 = this->car;
    v15 = &v14->drivetrain.acEngine;
    v38 = Drivetrain::getEngineRPM(&v14->drivetrain);
    if ( v38 >= (float)v15->getLimiterRPM(v15) || this->car->drivetrain.currentGear <= 1 )
      this->input = 0.0;
    v16 = this->input;
    if ( v16 >= 0.0 )
    {
      v17 = v16 - v44;
      if ( (float)(v16 - v44) <= 1.0 )
      {
        if ( v17 < 0.0 )
          v17 = 0.0;
      }
      else
      {
        v17 = FLOAT_1_0;
      }
      v18 = this->charge;
      v19 = (v17 * this->dischargeK + v48 * this->dischargeKFront) * dt;
      if ( v19 <= v18 )
      {
        v23 = DOUBLE_1_0;
        v24 = v18 - v19;
        if ( v24 <= 1.0 )
        {
          v23 = 0.0;
          if ( v24 >= 0.0 )
            v23 = v24;
        }
        this->charge = v23;
      }
      else
      {
        v20 = v18 / v19;
        v21 = v16 * v20;
        this->input = v21;
        v22 = v48 * v20;
        v49 = v22;
        this->charge = 0.0;
      }
    }
    v25 = this->input + v44;
    if ( v25 <= 1.0 )
    {
      if ( v25 < 0.0 )
        v25 = 0.0;
    }
    else
    {
      v25 = FLOAT_1_0;
    }
    this->input = v25;
    if ( v25 > 0.0 )
    {
      v26 = v25 - v44;
      v27 = this->car->drivetrain.engine.velocity;
      v39 = v26;
      if ( v26 <= 1.0 )
      {
        if ( v26 < 0.0 )
          v39 = 0.0;
      }
      else
      {
        v39 = FLOAT_1_0;
      }
      v45 = Curve::getValue(&this->torqueLUT, (float)(v27 * 0.15915507) * 60.0);
      this->currentJ = (float)((float)((float)(v45 * v39) * v27) * dt) + this->currentJ;
    }
    v28 = this->car;
    v29 = v28->drivetrain.ratio;
    if ( v29 != 0.0 )
      v28->brakeSystem.rearCorrectionTorque = (float)(this->rearCorrectionTorque * this->kineticRecovery) * v29;
    if ( Curve::getCount(&this->frontTorqueLUT) > 0 )
    {
      v30 = this->car;
      v31 = v30->tyres[0].status.load;
      v32 = v30->tyres[1].status.load + v31;
      v46 = (float)(v30->tyres[1].status.angularVelocity + v30->tyres[0].status.angularVelocity) * 0.5;
      if ( v32 <= 0.0 )
      {
        v30->tyres[0].inputs.electricTorque = 0.0;
        this->car->tyres[1].inputs.electricTorque = 0.0;
      }
      else
      {
        v33 = (float)((float)((float)(v31 / v32) - 0.5) * this->frontTorqueVectoringBias) + 0.5;
        if ( v33 <= 1.0 )
        {
          if ( v33 >= 0.0 )
            v36 = v33;
        }
        else
        {
          v36 = FLOAT_1_0;
        }
        v34 = Curve::getValue(&this->frontTorqueLUT, (float)(v46 * 0.15915507) * 60.0);
        v35 = this->car;
        v40 = v34 * v49;
        this->currentJ = (float)((float)(v40 * v46) * dt) + this->currentJ;
        v35->tyres[0].inputs.electricTorque = v40 * v36;
        this->car->tyres[1].inputs.electricTorque = (float)(1.0 - v36) * v40;
      }
    }
  }
}
