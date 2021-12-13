#include "kers.h"
bool Kers::isPresent(Kers *this)
{
  return this->present;
}
void Kers::Kers(Kers *this)
{
  this->__vftable = (Kers_vtbl *)&Kers::`vftable';
  this->attachment = Engine;
  this->car = 0;
  this->present = 0;
  this->input = 0.0;
  this->charge = 0.0;
  this->angularVelocity = 0.0;
  this->negativeInputChargeK = 0.0;
  this->hasButtonOverride = 0;
  this->currentJ = 0.0;
  this->maxJ = 0.0;
  Curve::Curve(&this->torqueLUT);
  DynamicController::DynamicController(&this->controller);
  this->hasController = 0;
}
Kers *Kers::`vector deleting destructor'(Kers *this, unsigned int a2)
{
  Kers::~Kers(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void Kers::~Kers(Kers *this)
{
  this->__vftable = (Kers_vtbl *)&Kers::`vftable';
  DynamicController::~DynamicController(&this->controller);
  Curve::~Curve(&this->torqueLUT);
  this->__vftable = (Kers_vtbl *)&ITorqueGenerator::`vftable';
}
double Kers::getDischargeTimeS(Kers *this)
{
  return 1000.0 / this->dischargeK * 0.001;
}
double Kers::getOutputTorque(Kers *this)
{
  float ref; // xmm1_4
  KersAttachment v2; // eax

  if ( !this->present )
    return 0.0;
  ref = 0.0;
  if ( this->charge <= 0.0 )
    return 0.0;
  v2 = this->attachment;
  if ( v2 )
  {
    if ( v2 == Wheels )
      ref = (COERCE_DOUBLE(*(_QWORD *)&this->car->drivetrain.outShaftR.velocity & _xmm)
           + COERCE_DOUBLE(*(_QWORD *)&this->car->drivetrain.outShaftL.velocity & _xmm))
          * 0.5
          * 0.1591550715257987
          * 60.0;
  }
  else
  {
    ref = this->car->drivetrain.engine.velocity * 0.1591550715257987 * 60.0;
  }
  return Curve::getValue(&this->torqueLUT, ref) * this->input;
}
void Kers::init(Kers *this, Car *car)
{
  std::wstring *v3; // eax
  const std::wstring *v4; // eax
  const std::wstring *v5; // eax
  int v6; // ebp
  double v7; // st7
  bool v8; // cf
  double v9; // st7
  std::wstring *v10; // eax
  std::wstring *v11; // eax
  const std::wstring *v12; // eax
  double v13; // st7
  double v14; // st7
  std::wstring *v15; // eax
  std::wstring *v16; // eax
  std::wstring *v17; // eax
  const std::wstring *v18; // eax
  int v19; // eax
  int v20; // esi
  int v21; // eax
  double v22; // st7
  std::function<void __cdecl(OnPhysicsStepCompleted const &)> v23; // [esp-1Ch] [ebp-1ACh] BYREF
  float v24; // [esp+18h] [ebp-178h]
  std::wstring key; // [esp+1Ch] [ebp-174h] BYREF
  std::wstring section; // [esp+34h] [ebp-15Ch] BYREF
  std::wstring v27; // [esp+4Ch] [ebp-144h] BYREF
  std::wstring v28; // [esp+64h] [ebp-12Ch] BYREF
  std::wstring v29; // [esp+7Ch] [ebp-114h] BYREF
  std::wstring controller_filename; // [esp+94h] [ebp-FCh] BYREF
  std::wstring attach; // [esp+ACh] [ebp-E4h] BYREF
  std::wstring v32; // [esp+C4h] [ebp-CCh] BYREF
  std::wstring v33; // [esp+DCh] [ebp-B4h] BYREF
  std::wstring result; // [esp+F4h] [ebp-9Ch] BYREF
  INIReader ini; // [esp+10Ch] [ebp-84h] BYREF
  std::wstring torque_lut; // [esp+150h] [ebp-40h] BYREF
  std::wstring v37; // [esp+168h] [ebp-28h] BYREF
  int v38; // [esp+18Ch] [ebp-4h]

  this->car = car;
  v3 = std::operator+<wchar_t>(&result, L"content/cars/", &car->unixName);
  v38 = 0;
  v4 = std::operator+<wchar_t>(&v33, v3, L"/data/kers.ini");
  LOBYTE(v38) = 1;
  v5 = Car::getConfigPath(car, &v32, v4);
  LOBYTE(v38) = 2;
  INIReader::INIReader(&ini, v5);
  if ( v32._Myres >= 8 )
    operator delete(v32._Bx._Ptr);
  v32._Myres = 7;
  v32._Mysize = 0;
  v32._Bx._Buf[0] = 0;
  if ( v33._Myres >= 8 )
    operator delete(v33._Bx._Ptr);
  v33._Myres = 7;
  v33._Mysize = 0;
  v33._Bx._Buf[0] = 0;
  LOBYTE(v38) = 6;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"VERSION", 7u);
    LOBYTE(v38) = 7;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HEADER", 6u);
    LOBYTE(v38) = 8;
    v6 = INIReader::getInt(&ini, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v38) = 6;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    _printf("Loading KERS VERSION %d\n", v6);
    this->present = 1;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"BRAKE_LEVEL", 0xBu);
    LOBYTE(v38) = 9;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"KERS", 4u);
    LOBYTE(v38) = 10;
    v24 = BrakeSystem::getBrakePower(&car->brakeSystem);
    v7 = INIReader::getFloat(&ini, &section, &key);
    v8 = section._Myres < 8;
    this->brakeForMaxCharge = v7 * v24 + v7 * v24;
    if ( !v8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v38) = 6;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"CHARGE_K", 8u);
    LOBYTE(v38) = 11;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"KERS", 4u);
    LOBYTE(v38) = 12;
    v9 = INIReader::getFloat(&ini, &section, &key);
    v8 = section._Myres < 8;
    this->chargeK = v9;
    if ( !v8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v38) = 6;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    v27._Myres = 7;
    v27._Mysize = 0;
    v27._Bx._Buf[0] = 0;
    std::wstring::assign(&v27, L"TORQUE_CURVE", 0xCu);
    LOBYTE(v38) = 13;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"KERS", 4u);
    LOBYTE(v38) = 14;
    INIReader::getString(&ini, &torque_lut, &section, &v27);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v38) = 17;
    if ( v27._Myres >= 8 )
      operator delete(v27._Bx._Ptr);
    v27._Myres = 7;
    v27._Bx._Buf[0] = 0;
    v27._Mysize = 0;
    v10 = std::operator+<wchar_t>(&v29, L"content/cars/", &car->unixName);
    LOBYTE(v38) = 18;
    v11 = std::operator+<wchar_t>(&v28, v10, L"/data/");
    LOBYTE(v38) = 19;
    v12 = std::operator+<wchar_t>(&key, v11, &torque_lut);
    LOBYTE(v38) = 20;
    Curve::load(&this->torqueLUT, v12);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( v28._Myres >= 8 )
      operator delete(v28._Bx._Ptr);
    v28._Myres = 7;
    v28._Mysize = 0;
    v28._Bx._Buf[0] = 0;
    LOBYTE(v38) = 17;
    if ( v29._Myres >= 8 )
      operator delete(v29._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DISCHARGE_TIME", 0xEu);
    LOBYTE(v38) = 21;
    v28._Myres = 7;
    v28._Mysize = 0;
    v28._Bx._Buf[0] = 0;
    std::wstring::assign(&v28, L"KERS", 4u);
    LOBYTE(v38) = 22;
    v13 = INIReader::getFloat(&ini, &v28, &key);
    v8 = v28._Myres < 8;
    this->dischargeK = 1000.0 / v13;
    if ( !v8 )
      operator delete(v28._Bx._Ptr);
    v28._Myres = 7;
    v28._Mysize = 0;
    v28._Bx._Buf[0] = 0;
    LOBYTE(v38) = 17;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v6 >= 2 )
    {
      std::wstring::wstring(&v29, L"NEGATIVE_INPUT_CHARGE_K");
      LOBYTE(v38) = 23;
      std::wstring::wstring(&key, L"KERS");
      LOBYTE(v38) = 24;
      v14 = INIReader::getFloat(&ini, &key, &v29);
      v8 = key._Myres < 8;
      this->negativeInputChargeK = v14;
      if ( !v8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v38) = 17;
      if ( v29._Myres >= 8 )
        operator delete(v29._Bx._Ptr);
    }
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"CONTROLLER", 0xAu);
    LOBYTE(v38) = 25;
    v28._Myres = 7;
    v28._Mysize = 0;
    v28._Bx._Buf[0] = 0;
    std::wstring::assign(&v28, L"KERS", 4u);
    LOBYTE(v38) = 26;
    INIReader::getString(&ini, &controller_filename, &v28, &key);
    if ( v28._Myres >= 8 )
      operator delete(v28._Bx._Ptr);
    v28._Myres = 7;
    v28._Mysize = 0;
    v28._Bx._Buf[0] = 0;
    LOBYTE(v38) = 29;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( controller_filename._Mysize )
    {
      v15 = &controller_filename;
      if ( controller_filename._Myres >= 8 )
        v15 = (std::wstring *)controller_filename._Bx._Ptr;
      _printf("Loading KERS controller file:%S\n", v15->_Bx._Buf);
      v16 = std::operator+<wchar_t>(&v37, L"content/cars/", &car->unixName);
      LOBYTE(v38) = 30;
      v17 = std::operator+<wchar_t>(&v29, v16, L"/data/");
      LOBYTE(v38) = 31;
      v18 = std::operator+<wchar_t>(&v27, v17, &controller_filename);
      LOBYTE(v38) = 32;
      DynamicController::DynamicController((DynamicController *)&section, car, v18);
      v20 = v19;
      this->controller.car = *(Car **)v19;
      LOBYTE(v38) = 33;
      std::vector<DynamicControllerStage>::operator=(
        &this->controller.stages,
        (const std::vector<DynamicControllerStage> *)(v19 + 4));
      this->controller.ready = *(_BYTE *)(v20 + 16);
      LOBYTE(v38) = 32;
      DynamicController::~DynamicController((DynamicController *)&section);
      if ( v27._Myres >= 8 )
        operator delete(v27._Bx._Ptr);
      v27._Myres = 7;
      v27._Mysize = 0;
      v27._Bx._Buf[0] = 0;
      if ( v29._Myres >= 8 )
        operator delete(v29._Bx._Ptr);
      v29._Myres = 7;
      v29._Mysize = 0;
      v29._Bx._Buf[0] = 0;
      LOBYTE(v38) = 29;
      if ( v37._Myres >= 8 )
        operator delete(v37._Bx._Ptr);
      this->hasController = 1;
    }
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"ATTACH", 6u);
    LOBYTE(v38) = 34;
    v27._Myres = 7;
    v27._Mysize = 0;
    v27._Bx._Buf[0] = 0;
    std::wstring::assign(&v27, L"KERS", 4u);
    LOBYTE(v38) = 35;
    INIReader::getString(&ini, &attach, &v27, &section);
    if ( v27._Myres >= 8 )
      operator delete(v27._Bx._Ptr);
    v27._Myres = 7;
    v27._Mysize = 0;
    v27._Bx._Buf[0] = 0;
    LOBYTE(v38) = 38;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Bx._Buf[0] = 0;
    section._Mysize = 0;
    if ( std::operator==<wchar_t>(&attach, L"ENGINE") )
      this->attachment = Engine;
    if ( std::operator==<wchar_t>(&attach, L"WHEELS") )
      this->attachment = Wheels;
    this->charge = 1.0;
    if ( v6 >= 3 )
    {
      std::wstring::wstring(&v29, L"HAS_BUTTON_OVERRIDE");
      LOBYTE(v38) = 39;
      std::wstring::wstring(&key, L"KERS");
      LOBYTE(v38) = 40;
      v21 = INIReader::getInt(&ini, &key, &v29);
      v8 = key._Myres < 8;
      this->hasButtonOverride = v21 != 0;
      if ( !v8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v38) = 38;
      if ( v29._Myres >= 8 )
        operator delete(v29._Bx._Ptr);
      std::wstring::wstring(&v29, L"MAX_KJ_PER_LAP");
      LOBYTE(v38) = 41;
      std::wstring::wstring(&key, L"KERS");
      LOBYTE(v38) = 42;
      v22 = INIReader::getFloat(&ini, &key, &v29);
      v8 = key._Myres < 8;
      this->maxJ = v22 * 1000.0;
      if ( !v8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      if ( v29._Myres >= 8 )
        operator delete(v29._Bx._Ptr);
    }
    if ( attach._Myres >= 8 )
      operator delete(attach._Bx._Ptr);
    attach._Myres = 7;
    attach._Mysize = 0;
    attach._Bx._Buf[0] = 0;
    if ( controller_filename._Myres >= 8 )
      operator delete(controller_filename._Bx._Ptr);
    controller_filename._Myres = 7;
    controller_filename._Mysize = 0;
    controller_filename._Bx._Buf[0] = 0;
    if ( torque_lut._Myres >= 8 )
      operator delete(torque_lut._Bx._Ptr);
  }
  v23._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_d361f6b318de1ab2f7ed810b0ea4e32b_,0>,std::allocator<std::_Func_class<void,OnLapCompletedEvent const &>>,void,OnLapCompletedEvent const &>::`vftable';
  v23._Space._Pfn[1] = (void (__cdecl *)())this;
  v23._Impl = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)&v23;
  LOBYTE(v38) = 6;
  Event<std::wstring>::addHandler((Event<OnPhysicsStepCompleted> *)&car->evOnLapCompleted, v23, this);
  v38 = -1;
  INIReader::~INIReader(&ini);
}
void Kers::reset(Kers *this)
{
  this->charge = 1.0;
  this->currentJ = 0.0;
}
void Kers::step(Kers *this, float dt)
{
  float v3; // xmm3_4
  Car *v4; // edx
  float v5; // xmm5_4
  float *v6; // eax
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm6_4
  float v10; // xmm1_4
  bool v11; // zf
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm4_4
  float v15; // xmm4_4
  float v16; // xmm0_4
  float v17; // xmm1_4
  Car *v18; // esi
  KersAttachment v19; // eax
  float v20; // xmm0_4
  float v21; // [esp+8h] [ebp-Ch]
  float v22; // [esp+8h] [ebp-Ch]
  float v23; // [esp+8h] [ebp-Ch]
  float v24; // [esp+Ch] [ebp-8h]
  float v25; // [esp+10h] [ebp-4h]

  v3 = FLOAT_1_0;
  if ( Car::isInPits(this->car) )
    this->charge = 1.0;
  v4 = this->car;
  v24 = 0.0;
  v5 = COERCE_DOUBLE(*(_QWORD *)&v4->drivetrain.outShaftL.velocity & _xmm) * 2.0;
  v25 = v5;
  if ( v5 < 6.0 )
  {
    v5 = 0.0;
    v25 = 0.0;
  }
  v6 = (float *)v4->tyres;
  v7 = 0.0;
  if ( v4->tyres != (Tyre *)&v4->suspensions )
  {
    do
    {
      v8 = v6[206] * *v6;
      v6 += 408;
      v7 = v7 + v8;
    }
    while ( v6 != (float *)&v4->suspensions );
  }
  v9 = dt;
  v10 = (float)((float)((float)((float)((float)(v7 / this->brakeForMaxCharge) * v5) * 0.5) * this->chargeK) * dt)
      + this->charge;
  if ( v10 <= 1.0 )
  {
    if ( v10 < 0.0 )
      v10 = 0.0;
  }
  else
  {
    v10 = FLOAT_1_0;
  }
  v11 = !this->hasController;
  this->charge = v10;
  if ( v11 )
  {
    if ( v4->controls.kers )
    {
      this->input = 1.0;
      goto LABEL_18;
    }
    goto LABEL_17;
  }
  v3 = FLOAT_1_0;
  v21 = DynamicController::eval(&this->controller);
  v12 = v21;
  if ( v21 <= 1.0 )
  {
    if ( v21 < 0.0 )
      v12 = 0.0;
  }
  else
  {
    v12 = FLOAT_1_0;
  }
  v4 = this->car;
  v5 = v25;
  v9 = dt;
  this->input = v12;
  if ( v4->controls.brake > 0.0099999998 )
LABEL_17:
    this->input = 0.0;
LABEL_18:
  if ( this->hasButtonOverride && v4->controls.kers )
    this->input = 1.0;
  v13 = this->charge;
  if ( v13 <= 0.0 || v4->speedLimiter.isLimiting || (v14 = this->maxJ, v14 != 0.0) && this->currentJ > v14 )
    this->input = 0.0;
  v15 = this->input;
  if ( v15 < 0.0 )
  {
    if ( v5 <= 0.0 )
      goto LABEL_37;
    v16 = this->negativeInputChargeK;
  }
  else
  {
    v16 = this->dischargeK;
  }
  v17 = v13 - (float)((float)(v16 * v15) * v9);
  if ( v17 <= v3 )
  {
    if ( v17 >= 0.0 )
      v3 = v17;
    else
      v3 = 0.0;
  }
  this->charge = v3;
LABEL_37:
  v18 = this->car;
  v22 = Drivetrain::getEngineRPM(&v4->drivetrain);
  if ( v22 >= (float)v18->drivetrain.acEngine.getLimiterRPM(&v18->drivetrain.acEngine)
    || this->car->drivetrain.currentGear <= 1 )
  {
    this->input = 0.0;
  }
  if ( this->input > 0.0 )
  {
    v19 = this->attachment;
    if ( v19 )
    {
      if ( v19 == Wheels )
      {
        v20 = (COERCE_DOUBLE(*(_QWORD *)&this->car->drivetrain.outShaftR.velocity & _xmm)
             + COERCE_DOUBLE(*(_QWORD *)&this->car->drivetrain.outShaftL.velocity & _xmm))
            * 0.5;
        v24 = v20;
      }
      else
      {
        v20 = 0.0;
      }
    }
    else
    {
      v20 = this->car->drivetrain.engine.velocity;
      v24 = v20;
    }
    v23 = Curve::getValue(&this->torqueLUT, (float)(v20 * 0.15915507) * 60.0);
    this->currentJ = (float)((float)((float)(v23 * this->input) * v24) * dt) + this->currentJ;
  }
}
