#include "drivetrain.h
TractionType Drivetrain::getTractionType(Drivetrain *this)
{
  return this->tractionType;
}
void Drivetrain::~Drivetrain(Drivetrain *this)
{
  std::vector<ITorqueGenerator *> *v2; // esi
  Task **v3; // esi
  std::_Func_base<void> *v4; // ecx
  std::function<void __cdecl(void)> *v5; // esi
  std::_Func_base<void> *v6; // ecx
  std::vector<SGearRatio> *v7; // edi

  DrivetrainControllers::~DrivetrainControllers(&this->controllers);
  v2 = &this->wheelTorqueGenerators;
  if ( this->wheelTorqueGenerators._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->wheelTorqueGenerators);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    this->wheelTorqueGenerators._Mylast = 0;
    this->wheelTorqueGenerators._Myend = 0;
  }
  v3 = (Task **)&this->evOnGearRequest;
  if ( this->evOnGearRequest.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnGearRequest);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnGearRequest,
      *v3,
      (Task *)this->evOnGearRequest.handlers._Mylast);
    operator delete(*v3);
    *v3 = 0;
    this->evOnGearRequest.handlers._Mylast = 0;
    this->evOnGearRequest.handlers._Myend = 0;
  }
  v4 = this->downshiftProtectionFunction._Impl;
  v5 = &this->downshiftProtectionFunction;
  if ( v4 )
  {
    ((void (__stdcall *)(bool))v4->_Delete_this)(v4 != (std::_Func_base<void> *)v5);
    this->downshiftProtectionFunction._Impl = 0;
  }
  v6 = this->downshiftProtectionFunction._Impl;
  if ( v6 )
  {
    ((void (__stdcall *)(bool))v6->_Delete_this)(v6 != (std::_Func_base<void> *)v5);
    this->downshiftProtectionFunction._Impl = 0;
  }
  Engine::~Engine(&this->acEngine);
  v7 = &this->gears;
  if ( v7->_Myfirst )
  {
    std::_Container_base0::_Orphan_all(v7);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<TrackAvatar::SectorDescription>>>(v7->_Myfirst, v7->_Mylast);
    operator delete(v7->_Myfirst);
    v7->_Myfirst = 0;
    v7->_Mylast = 0;
    v7->_Myend = 0;
  }
}
void Drivetrain::addGear(Drivetrain *this, std::wstring name, long double ratio)
{
  std::wstring *v4; // eax
  std::wstring _Right; // [esp+8h] [ebp-48h] BYREF
  SGearRatio _Val; // [esp+20h] [ebp-30h] BYREF
  int v7; // [esp+4Ch] [ebp-4h]

  v4 = &name;
  v7 = 0;
  if ( name._Myres >= 8 )
    v4 = (std::wstring *)name._Bx._Ptr;
  _printf("ADDING GEAR:%S\n", v4->_Bx._Buf);
  _Right._Myres = 7;
  _Right._Mysize = 0;
  _Right._Bx._Buf[0] = 0;
  std::wstring::assign(&_Right, &name, 0, 0xFFFFFFFF);
  _Val.name._Myres = 7;
  _Val.name._Mysize = 0;
  _Val.name._Bx._Buf[0] = 0;
  LOBYTE(v7) = 2;
  std::wstring::assign(&_Val.name, &_Right, 0, 0xFFFFFFFF);
  _Val.ratio = ratio;
  if ( _Right._Myres >= 8 )
    operator delete(_Right._Bx._Ptr);
  _Right._Myres = 7;
  _Right._Mysize = 0;
  _Right._Bx._Buf[0] = 0;
  LOBYTE(v7) = 3;
  std::vector<SGearRatio>::push_back(&this->gears, &_Val);
  if ( _Val.name._Myres >= 8 )
    operator delete(_Val.name._Bx._Ptr);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
}
char Drivetrain::gearDown(Drivetrain *this)
{
  char v2; // bl
  int v3; // ecx
  SGearRatio *v4; // edx
  int v5; // ecx
  double v6; // xmm2_8
  double v7; // xmm5_8
  double v8; // xmm0_8
  double v9; // xmm3_8
  double v10; // xmm4_8
  double v11; // xmm5_8
  double v12; // xmm0_8
  Engine_vtbl *v13; // eax
  float v14; // xmm0_4
  Engine_vtbl *v15; // eax
  Car *v16; // esi
  int v17; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  double v22; // [esp+20h] [ebp-94h]
  double v23; // [esp+28h] [ebp-8Ch]
  char v24; // [esp+53h] [ebp-61h]
  Speed result; // [esp+58h] [ebp-5Ch] BYREF
  long double v26; // [esp+5Ch] [ebp-58h]
  OnGearRequestEvent ev; // [esp+64h] [ebp-50h] BYREF
  double v28; // [esp+6Ch] [ebp-48h]
  int v29; // [esp+B0h] [ebp-4h]

  v2 = 0;
  LODWORD(result.value) = 0;
  if ( Drivetrain::isGearboxLocked(this) )
    return 0;
  if ( this->downshiftProtection.isActive )
  {
    v3 = this->currentGear;
    if ( v3 > 0 )
    {
      v4 = this->gears._Myfirst;
      v5 = v3;
      v6 = v4[v5 - 1].ratio;
      if ( v6 == 0.0 || v4[v5].ratio == 0.0 )
      {
        if ( !this->downshiftProtection.lockN
          || v6 != 0.0
          || (v2 = 1, v24 = 1, (float)(Car::getSpeed(this->car, &result)->value * 3.5999999) <= 2.0) )
        {
          v24 = 0;
        }
        if ( (v2 & 1) != 0 )
          dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
        if ( v24 )
          return 0;
      }
      else
      {
        v7 = this->outShaftL.velocity;
        *(double *)&ev = (v7 - this->outShaftL.oldVelocity) * 333.3333304358853;
        v8 = *(double *)&ev;
        if ( *(double *)&ev > 0.0 )
        {
          v8 = 0.0;
          *(double *)&ev = 0.0;
        }
        v9 = this->gearDnTime;
        v10 = v9 * v8 + v7;
        v11 = this->outShaftR.velocity;
        v26 = (v11 - this->outShaftR.oldVelocity) * 333.3333304358853;
        v12 = v26;
        if ( v26 > 0.0 )
        {
          v12 = 0.0;
          v26 = 0.0;
        }
        v13 = this->acEngine.__vftable;
        v28 = v6 * ((v9 * v12 + v11 + v10) * 0.5) * this->finalRatio * 0.1591550715257987 * 60.0;
        if ( v28 > (double)(this->downshiftProtection.overrev + v13->getLimiterRPM(&this->acEngine)) )
        {
          if ( this->downshiftProtection.isDebug )
          {
            v14 = Car::getSpeed(this->car, &result)->value * 3.5999999;
            v15 = this->acEngine.__vftable;
            v16 = this->car;
            v29 = 0;
            v17 = ((int (*)(Engine *, GearChangeRequest, int, _DWORD, _DWORD))v15->getLimiterRPM)(
                    &this->acEngine,
                    ev.request,
                    ev.nextGear,
                    LODWORD(v26),
                    HIDWORD(v26));
            _printf(
              "DSP: Car%d sp:%.1f pos:%.3f G:%d RPM:%d pRPM: %d , limitRPM: %d dec: %.2f %.2f\n",
              v16->physicsGUID,
              v14,
              v16->splineLocatorData.npos,
              this->currentGear - 1,
              (int)(this->engine.velocity * 0.1591550715257987 * 60.0),
              (int)v28,
              this->downshiftProtection.overrev + v17,
              v22,
              v23);
            v29 = -1;
            dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
          }
          if ( this->downshiftProtectionFunction._Impl )
            std::_Func_class<void,>::operator()(&this->downshiftProtectionFunction);
          return 0;
        }
      }
    }
  }
  v19 = this->currentGear;
  if ( v19 <= 0 )
    return 0;
  v20 = v19 - 1;
  if ( this->gearRequest.request )
    return 0;
  this->gearRequest.timeout = this->gearDnTime;
  this->gearRequest.requestedGear = v20;
  this->gearRequest.request = eChangeDown;
  this->gearRequest.timeAccumulator = 0.0;
  v21 = this->currentGear - 1;
  ev.request = eChangeDown;
  ev.nextGear = v21;
  Event<std::wstring>::trigger(&this->evOnGearRequest, &ev);
  this->currentGear = 1;
  return 1;
}
char Drivetrain::gearUp(Drivetrain *this)
{
  unsigned int v2; // ecx
  int v3; // ecx
  int v4; // eax
  double v5; // xmm0_8
  OnGearRequestEvent ev; // [esp+4h] [ebp-8h] BYREF

  if ( Drivetrain::isGearboxLocked(this) )
    return 0;
  v2 = this->currentGear;
  if ( v2 >= this->gears._Mylast - this->gears._Myfirst - 1 )
    return 0;
  v3 = v2 + 1;
  if ( this->gearRequest.request )
    return 0;
  this->gearRequest.timeout = this->gearUpTime;
  this->gearRequest.requestedGear = v3;
  this->gearRequest.request = eChangeUp;
  this->gearRequest.timeAccumulator = 0.0;
  v4 = this->currentGear + 1;
  ev.request = eChangeUp;
  ev.nextGear = v4;
  Event<std::wstring>::trigger(&this->evOnGearRequest, &ev);
  v5 = this->autoCutOffTime;
  if ( v5 != 0.0 )
    this->cutOff = v5;
  this->currentGear = 1;
  return 1;
}
SGearRatio *Drivetrain::getCurrentGear(Drivetrain *this, SGearRatio *result)
{
  SGearRatio *v2; // edx

  v2 = &this->gears._Myfirst[this->currentGear];
  result->ratio = v2->ratio;
  result->name._Myres = 7;
  result->name._Mysize = 0;
  result->name._Bx._Buf[0] = 0;
  std::wstring::assign(&result->name, &v2->name, 0, 0xFFFFFFFF);
  return result;
}
long double Drivetrain::getDrivetrainSpeed(Drivetrain *this)
{
  return this->drive.velocity;
}
double Drivetrain::getEngineRPM(Drivetrain *this)
{
  return (float)((float)((float)this->engine.velocity * 0.15915507) * 60.0);
}
long double Drivetrain::getInertiaFromEngine(Drivetrain *this)
{
  double v1; // xmm0_8

  v1 = this->ratio;
  if ( this->tractionType == AWD )
  {
    if ( v1 != 0.0 )
      return (this->outShaftL.inertia
            + this->drive.inertia
            + this->outShaftR.inertia
            + this->outShaftLF.inertia
            + this->outShaftRF.inertia)
           / COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v1 * v1) & _xmm)
           + this->clutchInertia
           + this->engine.inertia;
  }
  else if ( v1 != 0.0 )
  {
    return (this->outShaftL.inertia + this->drive.inertia + this->outShaftR.inertia)
         / COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v1 * v1) & _xmm)
         + this->clutchInertia
         + this->engine.inertia;
  }
  return this->engine.inertia;
}
long double Drivetrain::getInertiaFromWheels(Drivetrain *this)
{
  double v1; // xmm1_8
  double v2; // xmm0_8
  double v3; // xmm1_8
  long double result; // st7
  double v5; // xmm1_8
  double v6; // xmm0_8
  double v7; // xmm1_8

  switch ( this->tractionType )
  {
    case RWD:
    case FWD:
    case AWD_NEW:
      v1 = this->ratio;
      if ( v1 == 0.0 )
      {
        result = this->outShaftL.inertia + this->drive.inertia + this->outShaftR.inertia;
      }
      else
      {
        v2 = this->clutchInertia;
        *(_QWORD *)&v3 = COERCE_UNSIGNED_INT64(v1 * v1) & _xmm;
        if ( !this->clutchOpenState )
          v2 = v2 + this->engine.inertia;
        result = v3 * v2 + this->drive.inertia + this->outShaftL.inertia + this->outShaftR.inertia;
      }
      break;
    case AWD:
      v5 = this->ratio;
      if ( v5 == 0.0 )
      {
        result = this->outShaftL.inertia
               + this->drive.inertia
               + this->outShaftR.inertia
               + this->outShaftLF.inertia
               + this->outShaftRF.inertia;
      }
      else
      {
        v6 = this->clutchInertia;
        *(_QWORD *)&v7 = COERCE_UNSIGNED_INT64(v5 * v5) & _xmm;
        if ( !this->clutchOpenState )
          v6 = v6 + this->engine.inertia;
        result = v7 * v6
               + this->drive.inertia
               + this->outShaftL.inertia
               + this->outShaftR.inertia
               + this->outShaftLF.inertia
               + this->outShaftRF.inertia;
      }
      break;
    default:
      result = 0.0;
      break;
  }
  return result;
}
long double Drivetrain::getRpmWindowStatus(Drivetrain *this)
{
  return this->validShiftRPMWindow / this->orgRpmWindow;
}
bool Drivetrain::hasDynamicControllers(Drivetrain *this)
{
  return this->controllers.awd2._Myptr
      || this->controllers.awdCenterLock._Myptr
      || this->controllers.awdFrontShare._Myptr
      || this->controllers.singleDiffLock._Myptr;
}
void Drivetrain::init(Drivetrain *this, Car *car)
{
  ICarPhysicsStateProvider *v3; // ebx
  std::wstring *v4; // eax
  long double v5; // xmm0_8
  KersAttachment v6; // eax
  ICollisionObject *_Val; // [esp+14h] [ebp-5Ch] BYREF
  std::wstring _Left; // [esp+18h] [ebp-58h] BYREF
  std::wstring result; // [esp+30h] [ebp-40h] BYREF
  std::wstring dataPath; // [esp+48h] [ebp-28h] BYREF
  int v11; // [esp+6Ch] [ebp-4h]

  v3 = (ICarPhysicsStateProvider *)car;
  this->car = car;
  Engine::init(&this->acEngine, car);
  this->lockCounter[0] = 0;
  this->lockCounter[1] = 0;
  this->lockCounter[2] = 0;
  this->lockCounter[3] = 0;
  this->rootVelocity = 0.0;
  this->ratio = DOUBLE_12_0;
  this->totalTorque = 0.0;
  this->isShifterSupported = 0;
  this->clutchOpenState = 0;
  this->diffPowerRamp = 0.69999999;
  this->diffCoastRamp = 0.2;
  this->diffPreLoad = 0.0;
  *(_OWORD *)&this->gearUpTime = _xmm;
  this->awdFrontShare = 0.30000001;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"content/cars/", 0xDu);
  v11 = 0;
  v4 = std::operator+<wchar_t>(&result, &_Left, &car->unixName);
  LOBYTE(v11) = 1;
  std::operator+<wchar_t>(&dataPath, v4, L"/data/");
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v11) = 4;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  this->engine.inertia = DOUBLE_0_009999999776482582;
  this->currentGear = 0;
  this->tractionType = RWD;
  this->drive.inertia = DOUBLE_0_009999999776482582;
  _Left._Bx._Buf[0] = 0;
  this->tyreLeft = &car->tyres[2];
  this->tyreRight = &car->tyres[3];
  this->finalRatio = 4.0;
  v5 = car->tyres[2].data.angularInertia;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  this->outShaftL.inertia = v5;
  this->outShaftR.inertia = car->tyres[3].data.angularInertia;
  this->cutOff = 0.0;
  this->lastRatio = DOUBLE_N1_0;
  Drivetrain::loadINI(this, &dataPath);
  if ( car->kers.present )
  {
    v6 = car->kers.attachment;
    if ( v6 )
    {
      if ( v6 == Wheels )
      {
        _Val = (ICollisionObject *)&car->kers;
        std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->wheelTorqueGenerators, &_Val);
      }
    }
    else
    {
      Engine::addTorqueGenerator(&this->acEngine, &car->kers);
    }
  }
  if ( car->ers.present )
  {
    Engine::addTorqueGenerator(&this->acEngine, &car->ers);
    if ( car == (Car *)-10432 )
      v3 = 0;
    else
      v3 = (ICarPhysicsStateProvider *)&car->ers.ICoastGenerator;
    PhysicsEngine::addAdditionalPhysicsProvider((PhysicsEngine *)&this->acEngine, v3);
  }
  Drivetrain::initControllers(this, (unsigned int)v3);
  if ( dataPath._Myres >= 8 )
    operator delete(dataPath._Bx._Ptr);
}
void __usercall Drivetrain::initControllers(Drivetrain *this@<ecx>, unsigned int a2@<ebx>)
{
  TractionType v3; // eax
  std::wstring *v4; // eax
  std::wstring *v5; // eax
  DynamicController *v6; // eax
  DynamicController *v7; // eax
  DynamicController *v8; // edi
  std::wstring *v9; // eax
  std::wstring *v10; // edi
  std::wstring *v11; // eax
  DynamicController *v12; // eax
  DynamicController *v13; // eax
  DynamicController *v14; // edi
  std::wstring *v15; // eax
  std::wstring *v16; // eax
  DynamicController *v17; // eax
  DynamicController *v18; // eax
  DynamicController *v19; // edi
  std::wstring path; // [esp+10h] [ebp-A0h] BYREF
  std::wstring filename; // [esp+28h] [ebp-88h] BYREF
  std::wstring result; // [esp+40h] [ebp-70h] BYREF
  std::wstring v23; // [esp+58h] [ebp-58h] BYREF
  std::wstring v24; // [esp+70h] [ebp-40h] BYREF
  std::wstring v25; // [esp+88h] [ebp-28h] BYREF
  int v26; // [esp+ACh] [ebp-4h]

  v3 = this->tractionType;
  if ( v3 )
  {
    if ( v3 == AWD )
    {
      v4 = std::operator+<wchar_t>(&result, L"content/cars/", &this->car->unixName);
      v26 = 4;
      std::operator+<wchar_t>(&path, v4, L"/data/ctrl_awd_front_share.ini");
      LOBYTE(v26) = 6;
      if ( result._Myres >= 8 )
        operator delete(result._Bx._Ptr);
      result._Myres = 7;
      result._Bx._Buf[0] = 0;
      result._Mysize = 0;
      if ( Path::fileExists(a2, &path, 0) )
      {
        v5 = &path;
        if ( path._Myres >= 8 )
          v5 = (std::wstring *)path._Bx._Ptr;
        _printf("INITIALIZING AWD FRONT SHARE CONTROLLER FROM: %S\n", v5->_Bx._Buf);
        v6 = (DynamicController *)operator new(20);
        LOBYTE(v26) = 7;
        if ( v6 )
          DynamicController::DynamicController(v6, this->car, &path);
        else
          v7 = 0;
        v8 = this->controllers.awdFrontShare._Myptr;
        LOBYTE(v26) = 6;
        this->controllers.awdFrontShare._Myptr = v7;
        if ( v8 )
        {
          DynamicController::~DynamicController(v8);
          operator delete(v8);
        }
      }
      v9 = std::operator+<wchar_t>(&v23, L"content/cars/", &this->car->unixName);
      LOBYTE(v26) = 8;
      v10 = std::operator+<wchar_t>(&v24, v9, L"/data/ctrl_awd_center_lock.ini");
      if ( &path != v10 )
      {
        if ( path._Myres >= 8 )
          operator delete(path._Bx._Ptr);
        path._Myres = 7;
        path._Mysize = 0;
        path._Bx._Buf[0] = 0;
        std::wstring::_Assign_rv(&path, v10);
      }
      if ( v24._Myres >= 8 )
        operator delete(v24._Bx._Ptr);
      v24._Myres = 7;
      v24._Mysize = 0;
      v24._Bx._Buf[0] = 0;
      LOBYTE(v26) = 6;
      if ( v23._Myres >= 8 )
        operator delete(v23._Bx._Ptr);
      v23._Myres = 7;
      v23._Bx._Buf[0] = 0;
      v23._Mysize = 0;
      if ( Path::fileExists(a2, &path, 0) )
      {
        v11 = &path;
        if ( path._Myres >= 8 )
          v11 = (std::wstring *)path._Bx._Ptr;
        _printf("INITIALIZING AWD CENTER LOCK CONTROLLER FROM: %S\n", v11->_Bx._Buf);
        v12 = (DynamicController *)operator new(20);
        LOBYTE(v26) = 9;
        if ( v12 )
          DynamicController::DynamicController(v12, this->car, &path);
        else
          v13 = 0;
        v14 = this->controllers.awdCenterLock._Myptr;
        LOBYTE(v26) = 6;
        this->controllers.awdCenterLock._Myptr = v13;
        if ( v14 )
        {
          DynamicController::~DynamicController(v14);
          operator delete(v14);
        }
      }
      if ( path._Myres >= 8 )
        operator delete(path._Bx._Ptr);
    }
  }
  else
  {
    v15 = std::operator+<wchar_t>(&v25, L"content/cars/", &this->car->unixName);
    v26 = 0;
    std::operator+<wchar_t>(&filename, v15, L"/data/ctrl_single_lock.ini");
    LOBYTE(v26) = 2;
    if ( v25._Myres >= 8 )
      operator delete(v25._Bx._Ptr);
    v25._Myres = 7;
    v25._Bx._Buf[0] = 0;
    v25._Mysize = 0;
    if ( Path::fileExists(a2, &filename, 0) )
    {
      v16 = &filename;
      if ( filename._Myres >= 8 )
        v16 = (std::wstring *)filename._Bx._Ptr;
      _printf("INITIALIZING SINGLE LOCK CONTROLLER FROM: %S\n", v16->_Bx._Buf);
      v17 = (DynamicController *)operator new(20);
      LOBYTE(v26) = 3;
      if ( v17 )
        DynamicController::DynamicController(v17, this->car, &filename);
      else
        v18 = 0;
      v19 = this->controllers.singleDiffLock._Myptr;
      LOBYTE(v26) = 2;
      this->controllers.singleDiffLock._Myptr = v18;
      if ( v19 )
      {
        DynamicController::~DynamicController(v19);
        operator delete(v19);
      }
    }
    if ( filename._Myres >= 8 )
      operator delete(filename._Bx._Ptr);
  }
}
BOOL Drivetrain::isChangingGear(Drivetrain *this)
{
  return this->gearRequest.request != eNoGearRequest;
}
bool Drivetrain::isGearboxLocked(Drivetrain *this)
{
  bool v2; // zf
  Car *v3; // eax
  PhysicsEngine *v4; // eax

  v2 = !PhysicsEngine::hasSessionStarted(this->car->ksPhysics, 0.0);
  v3 = this->car;
  if ( !v2 )
    return v3->isGearboxLocked;
  v4 = v3->ksPhysics;
  return v4->sessionInfo.startTimeMS - v4->lockGearboxAtStartTimeMS > v4->physicsTime
      || v4->penaltyRules.jumpStartPenaltyMode == eLockOnGridMode;
}
void Drivetrain::loadINI(Drivetrain *this, const std::wstring *dataPath)
{
  int v3; // ebx
  const std::wstring *v4; // eax
  Car *v5; // ecx
  const std::wstring *v6; // eax
  std::_Allocator_base<std::vector<LeaderboardEntry> > v7; // al
  int v8; // edi
  double v9; // st7
  bool v10; // cf
  signed int v11; // ebx
  int v12; // edi
  unsigned int v13; // ecx
  int v14; // ecx
  wchar_t *v15; // ecx
  double v17; // st7
  double v18; // st7
  double v19; // st7
  double v20; // st7
  Car *v21; // edx
  Car *v22; // eax
  Car *v23; // eax
  float v24; // xmm0_4
  float *v25; // eax
  double v26; // st7
  double v27; // st7
  double v28; // st7
  double v29; // st7
  double v30; // st7
  double v31; // st7
  double v32; // st7
  double v33; // st7
  double v34; // st7
  double v35; // st7
  Car *v36; // eax
  float *v37; // eax
  double v38; // st7
  double v39; // st7
  unsigned int v40; // eax
  std::allocator<wchar_t> *v41; // eax
  DynamicController *v42; // eax
  DynamicController *v43; // eax
  char v44; // bl
  bool v45; // zf
  Car *v46; // eax
  long double v47; // xmm0_8
  float v48; // xmm0_4
  std::wstring v49; // [esp-18h] [ebp-224h] BYREF
  long double ratio; // [esp+0h] [ebp-20Ch]
  std::_Wrap_alloc<std::allocator<std::vector<LeaderboardEntry> > > v51; // [esp+4Bh] [ebp-1C1h] BYREF
  long double v52; // [esp+4Ch] [ebp-1C0h]
  float ginertia; // [esp+54h] [ebp-1B8h]
  unsigned int v54; // [esp+58h] [ebp-1B4h]
  std::wstring v55; // [esp+5Ch] [ebp-1B0h] BYREF
  std::wstring key; // [esp+74h] [ebp-198h] BYREF
  std::wstring section; // [esp+8Ch] [ebp-180h] BYREF
  std::wstring result; // [esp+A4h] [ebp-168h] BYREF
  std::wstring v59; // [esp+BCh] [ebp-150h] BYREF
  INIReader r; // [esp+D4h] [ebp-138h] BYREF
  std::wstring v61; // [esp+120h] [ebp-ECh] BYREF
  std::wstring tr; // [esp+138h] [ebp-D4h] BYREF
  std::wstring filename; // [esp+150h] [ebp-BCh] BYREF
  wchar_t gname[24]; // [esp+168h] [ebp-A4h] BYREF
  wchar_t buffer[24]; // [esp+198h] [ebp-74h] BYREF
  int v66; // [esp+208h] [ebp-4h]

  v3 = 0;
  ginertia = *(float *)&dataPath;
  v54 = 0;
  LODWORD(v52) = 0;
  v4 = std::operator+<wchar_t>(&result, dataPath, L"drivetrain.ini");
  v5 = this->car;
  v66 = 0;
  v6 = Car::getConfigPath(v5, &key, v4);
  LOBYTE(v66) = 1;
  INIReader::INIReader(&r, v6);
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  LOBYTE(v66) = 4;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"HEADER", 6u);
  LOBYTE(v66) = 5;
  v7 = (std::_Allocator_base<std::vector<LeaderboardEntry> >)INIReader::hasSection(&r, &section);
  v51.std::_Allocator_base<std::vector<LeaderboardEntry> > = v7;
  LOBYTE(v66) = 4;
  if ( section._Myres >= 8 )
  {
    operator delete(section._Bx._Ptr);
    v7 = v51.std::_Allocator_base<std::vector<LeaderboardEntry> >;
  }
  if ( !*(_BYTE *)&v7 )
    goto LABEL_14;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"VERSION", 7u);
  LOBYTE(v66) = 6;
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  std::wstring::assign(&v55, L"HEADER", 6u);
  LOBYTE(v66) = 7;
  v8 = INIReader::getInt(&r, &v55, &section);
  if ( v55._Myres >= 8 )
    operator delete(v55._Bx._Ptr);
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  LOBYTE(v66) = 4;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( v8 < 2 )
    goto LABEL_14;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"DAMAGE", 6u);
  LOBYTE(v66) = 8;
  v3 = 1;
  v54 = 1;
  LODWORD(v52) = 1;
  v51.std::_Allocator_base<std::vector<LeaderboardEntry> > = (std::_Allocator_base<std::vector<LeaderboardEntry> >)1;
  if ( !INIReader::hasSection(&r, &section) )
LABEL_14:
    v51.std::_Allocator_base<std::vector<LeaderboardEntry> > = 0;
  v66 = 4;
  if ( (v3 & 1) != 0 )
  {
    v54 = v3 & 0xFFFFFFFE;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  if ( v51.std::_Allocator_base<std::vector<LeaderboardEntry> > )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"RPM_WINDOW_K", 0xCu);
    LOBYTE(v66) = 9;
    v55._Myres = 7;
    v55._Mysize = 0;
    v55._Bx._Buf[0] = 0;
    std::wstring::assign(&v55, L"DAMAGE", 6u);
    LOBYTE(v66) = 10;
    v9 = INIReader::getFloat(&r, &v55, &section);
    v10 = v55._Myres < 8;
    this->damageRpmWindow = v9;
    if ( !v10 )
      operator delete(v55._Bx._Ptr);
    v55._Myres = 7;
    v55._Mysize = 0;
    v55._Bx._Buf[0] = 0;
    LOBYTE(v66) = 4;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"COUNT", 5u);
  LOBYTE(v66) = 11;
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  std::wstring::assign(&v55, L"GEARS", 5u);
  LOBYTE(v66) = 12;
  v11 = INIReader::getInt(&r, &v55, &section);
  if ( v55._Myres >= 8 )
    operator delete(v55._Bx._Ptr);
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  LOBYTE(v66) = 4;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"GEAR_R", 6u);
  LOBYTE(v66) = 13;
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  std::wstring::assign(&v55, L"GEARS", 5u);
  LOBYTE(v66) = 14;
  v52 = INIReader::getFloat(&r, &v55, &section);
  ratio = v52;
  v49._Myres = 7;
  v49._Mysize = 0;
  v49._Bx._Buf[0] = 0;
  std::wstring::assign(&v49, L"R", 1u);
  Drivetrain::addGear(this, v49, ratio);
  if ( v55._Myres >= 8 )
    operator delete(v55._Bx._Ptr);
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  LOBYTE(v66) = 4;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  ratio = 0.0;
  v49._Myres = 7;
  v49._Mysize = 0;
  v49._Bx._Buf[0] = 0;
  std::wstring::assign(&v49, L"N", 1u);
  Drivetrain::addGear(this, v49, ratio);
  if ( v11 > 0 )
  {
    v12 = 1;
    do
    {
      _swprintf_s(buffer, 0x18u, L"%d", v12);
      _swprintf_s(gname, 0x18u, L"GEAR_%d", v12);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( gname[0] )
        v13 = wcslen(gname);
      else
        v13 = 0;
      std::wstring::assign(&section, gname, v13);
      LOBYTE(v66) = 15;
      v55._Myres = 7;
      v55._Mysize = 0;
      v55._Bx._Buf[0] = 0;
      std::wstring::assign(&v55, L"GEARS", 5u);
      LOBYTE(v66) = 16;
      v52 = INIReader::getFloat(&r, &v55, &section);
      ratio = v52;
      v49._Myres = 7;
      v49._Mysize = 0;
      v49._Bx._Buf[0] = 0;
      if ( buffer[0] )
      {
        v15 = buffer;
        LODWORD(v52) = &buffer[1];
        while ( *v15++ )
          ;
        v14 = ((int)v15 - LODWORD(v52)) >> 1;
      }
      else
      {
        v14 = 0;
      }
      std::wstring::assign(&v49, buffer, v14);
      Drivetrain::addGear(this, v49, ratio);
      if ( v55._Myres >= 8 )
        operator delete(v55._Bx._Ptr);
      v55._Myres = 7;
      v55._Mysize = 0;
      v55._Bx._Buf[0] = 0;
      LOBYTE(v66) = 4;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      ++v12;
      --v11;
    }
    while ( v11 );
  }
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"FINAL", 5u);
  LOBYTE(v66) = 17;
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  std::wstring::assign(&v55, L"GEARS", 5u);
  LOBYTE(v66) = 18;
  v17 = INIReader::getFloat(&r, &v55, &section);
  v10 = v55._Myres < 8;
  this->finalRatio = v17;
  if ( !v10 )
    operator delete(v55._Bx._Ptr);
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  LOBYTE(v66) = 4;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  this->isGearGrinding = 0;
  if ( (unsigned int)(this->gears._Mylast - this->gears._Myfirst) > 1 && this->currentGear != 1 )
    this->currentGear = 1;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"POWER", 5u);
  LOBYTE(v66) = 19;
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  std::wstring::assign(&v55, L"DIFFERENTIAL", 0xCu);
  LOBYTE(v66) = 20;
  v18 = INIReader::getFloat(&r, &v55, &section);
  v10 = v55._Myres < 8;
  this->diffPowerRamp = v18;
  if ( !v10 )
    operator delete(v55._Bx._Ptr);
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  LOBYTE(v66) = 4;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"COAST", 5u);
  LOBYTE(v66) = 21;
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  std::wstring::assign(&v55, L"DIFFERENTIAL", 0xCu);
  LOBYTE(v66) = 22;
  v19 = INIReader::getFloat(&r, &v55, &section);
  v10 = v55._Myres < 8;
  this->diffCoastRamp = v19;
  if ( !v10 )
    operator delete(v55._Bx._Ptr);
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  LOBYTE(v66) = 4;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( this->diffPowerRamp >= 1.0 && this->diffCoastRamp >= 1.0 )
  {
    HIDWORD(ratio) = "Activating differential spool code\n";
    this->diffType = Spool;
    _printf((const char *const)HIDWORD(ratio));
  }
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"PRELOAD", 7u);
  LOBYTE(v66) = 23;
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  std::wstring::assign(&v55, L"DIFFERENTIAL", 0xCu);
  LOBYTE(v66) = 24;
  v20 = INIReader::getFloat(&r, &v55, &section);
  v10 = v55._Myres < 8;
  this->diffPreLoad = v20;
  if ( !v10 )
    operator delete(v55._Bx._Ptr);
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  LOBYTE(v66) = 4;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"TYPE", 4u);
  LOBYTE(v66) = 25;
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  std::wstring::assign(&v55, L"TRACTION", 8u);
  LOBYTE(v66) = 26;
  INIReader::getString(&r, &tr, &v55, &section);
  if ( v55._Myres >= 8 )
    operator delete(v55._Bx._Ptr);
  v55._Myres = 7;
  v55._Mysize = 0;
  v55._Bx._Buf[0] = 0;
  LOBYTE(v66) = 29;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v11) = 0;
  if ( !std::wstring::compare(&tr, 0, tr._Mysize, L"FWD", 3u) )
  {
    v21 = this->car;
    LOBYTE(v11) = 1;
    this->tractionType = FWD;
    this->tyreLeft = v21->tyres;
    this->tyreRight = &v21->tyres[1];
    this->outShaftL.inertia = v21->tyres[0].data.angularInertia;
    this->outShaftR.inertia = v21->tyres[1].data.angularInertia;
    v21->tyres[0].driven = 1;
    this->car->tyres[1].driven = 1;
    this->car->tyres[2].driven = 0;
    this->car->tyres[3].driven = 0;
  }
  if ( !std::wstring::compare(&tr, 0, tr._Mysize, L"RWD", 3u) )
  {
    this->tractionType = RWD;
    LOBYTE(v11) = 1;
    this->car->tyres[0].driven = 0;
    this->car->tyres[1].driven = 0;
    this->car->tyres[2].driven = 1;
    this->car->tyres[3].driven = 1;
  }
  if ( !std::wstring::compare(&tr, 0, tr._Mysize, L"AWD", 3u) )
  {
    this->tractionType = AWD;
    v22 = this->car;
    LOBYTE(v11) = 1;
    HIDWORD(ratio) = L"FRONT_SHARE";
    v22->tyres[0].driven = 1;
    this->car->tyres[1].driven = 1;
    this->car->tyres[2].driven = 1;
    this->car->tyres[3].driven = 1;
    v23 = this->car;
    v24 = (float)(v23->tyres[2].data.angularInertia + v23->tyres[0].data.angularInertia) * 0.5;
    v23->tyres[0].data.angularInertia = v24;
    this->car->tyres[1].data.angularInertia = v24;
    this->car->tyres[2].data.angularInertia = v24;
    this->car->tyres[3].data.angularInertia = v24;
    v25 = (float *)this->car;
    this->outShaftLF.inertia = v25[517];
    this->outShaftRF.inertia = v25[925];
    this->outShaftL.inertia = v25[1333];
    this->outShaftR.inertia = v25[1741];
    std::wstring::wstring(&result, (const wchar_t *)HIDWORD(ratio));
    LOBYTE(v66) = 30;
    std::wstring::wstring(&key, L"AWD");
    LOBYTE(v66) = 31;
    v26 = INIReader::getFloat(&r, &key, &result);
    v10 = key._Myres < 8;
    this->awdFrontShare = v26 * 0.0099999998;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v66) = 29;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&result, L"FRONT_DIFF_POWER");
    LOBYTE(v66) = 32;
    std::wstring::wstring(&key, L"AWD");
    LOBYTE(v66) = 33;
    v27 = INIReader::getFloat(&r, &key, &result);
    v10 = key._Myres < 8;
    this->awdFrontDiff.power = v27;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v66) = 29;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&result, L"FRONT_DIFF_COAST");
    LOBYTE(v66) = 34;
    std::wstring::wstring(&key, L"AWD");
    LOBYTE(v66) = 35;
    v28 = INIReader::getFloat(&r, &key, &result);
    v10 = key._Myres < 8;
    this->awdFrontDiff.coast = v28;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v66) = 29;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&result, L"FRONT_DIFF_PRELOAD");
    LOBYTE(v66) = 36;
    std::wstring::wstring(&key, L"AWD");
    LOBYTE(v66) = 37;
    v29 = INIReader::getFloat(&r, &key, &result);
    v10 = key._Myres < 8;
    this->awdFrontDiff.preload = v29;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v66) = 29;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&result, L"REAR_DIFF_POWER");
    LOBYTE(v66) = 38;
    std::wstring::wstring(&key, L"AWD");
    LOBYTE(v66) = 39;
    v30 = INIReader::getFloat(&r, &key, &result);
    v10 = key._Myres < 8;
    this->awdRearDiff.power = v30;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v66) = 29;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&result, L"REAR_DIFF_COAST");
    LOBYTE(v66) = 40;
    std::wstring::wstring(&key, L"AWD");
    LOBYTE(v66) = 41;
    v31 = INIReader::getFloat(&r, &key, &result);
    v10 = key._Myres < 8;
    this->awdRearDiff.coast = v31;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v66) = 29;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&result, L"REAR_DIFF_PRELOAD");
    LOBYTE(v66) = 42;
    std::wstring::wstring(&key, L"AWD");
    LOBYTE(v66) = 43;
    v32 = INIReader::getFloat(&r, &key, &result);
    v10 = key._Myres < 8;
    this->awdRearDiff.preload = v32;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v66) = 29;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&result, L"CENTRE_DIFF_POWER");
    LOBYTE(v66) = 44;
    std::wstring::wstring(&key, L"AWD");
    LOBYTE(v66) = 45;
    v33 = INIReader::getFloat(&r, &key, &result);
    v10 = key._Myres < 8;
    this->awdCenterDiff.power = v33;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v66) = 29;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&result, L"CENTRE_DIFF_COAST");
    LOBYTE(v66) = 46;
    std::wstring::wstring(&key, L"AWD");
    LOBYTE(v66) = 47;
    v34 = INIReader::getFloat(&r, &key, &result);
    v10 = key._Myres < 8;
    this->awdCenterDiff.coast = v34;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v66) = 29;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&result, L"CENTRE_DIFF_PRELOAD");
    LOBYTE(v66) = 48;
    std::wstring::wstring(&key, L"AWD");
    LOBYTE(v66) = 49;
    v35 = INIReader::getFloat(&r, &key, &result);
    v10 = key._Myres < 8;
    this->awdCenterDiff.preload = v35;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v66) = 29;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
  }
  if ( std::wstring::compare(&tr, 0, tr._Mysize, L"AWD2", 4u) )
  {
    if ( !(_BYTE)v11 )
    {
      std::wstring::wstring((std::wstring *)&v49._Bx._Alias[8], L"TRACTION NOT FOUND");
      ((void (*)(IErrorHandler *, _DWORD, _DWORD, unsigned int, unsigned int, _DWORD, _DWORD))INIReader::errorHandler->writeWarning)(
        INIReader::errorHandler,
        *(_DWORD *)&v49._Bx._Alias[8],
        *(_DWORD *)&v49._Bx._Alias[12],
        v49._Mysize,
        v49._Myres,
        LODWORD(ratio),
        HIDWORD(ratio));
      _printf("ERROR: TRACTION TYPE NOT FOUND\n");
    }
  }
  else
  {
    this->tractionType = AWD_NEW;
    v36 = this->car;
    HIDWORD(ratio) = L"FRONT_DIFF_POWER";
    v36->tyres[0].driven = 1;
    this->car->tyres[1].driven = 1;
    this->car->tyres[2].driven = 1;
    this->car->tyres[3].driven = 1;
    v37 = (float *)this->car;
    this->outShaftLF.inertia = v37[517];
    this->outShaftRF.inertia = v37[925];
    this->outShaftL.inertia = v37[1333];
    this->outShaftR.inertia = v37[1741];
    std::wstring::wstring(&result, (const wchar_t *)HIDWORD(ratio));
    LOBYTE(v66) = 50;
    std::wstring::wstring(&key, L"AWD2");
    LOBYTE(v66) = 51;
    v38 = INIReader::getFloat(&r, &key, &result);
    v10 = key._Myres < 8;
    this->awdFrontDiff.power = v38;
    if ( !v10 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v66) = 29;
    if ( result._Myres >= 8 )
      operator delete(result._Bx._Ptr);
    std::wstring::wstring(&result, L"FRONT_DIFF_COAST");
    LOBYTE(v66) = 52;
    std::wstring::wstring(&key, L"AWD2");
    LOBYTE(v66) = 53;
    v39 = INIReader::getFloat(&r, &key, &result);
    v40 = key._Myres;
    this->awdFrontDiff.coast = v39;
    if ( v40 >= 8 )
    {
      HIDWORD(ratio) = v40 + 1;
      LODWORD(ratio) = key._Bx._Ptr;
      v41 = (std::allocator<wchar_t> *)std::_String_alloc<0,std::_String_base_types<wchar_t>>::_Getal(
                                         (std::_Vector_alloc<0,std::_Vec_base_types<std::vector<LeaderboardEntry>> > *)&key,
                                         &v51);
      std::allocator<wchar_t>::deallocate(v41, (wchar_t *)LODWORD(ratio), HIDWORD(ratio));
    }
    key._Myres = 7;
    std::wstring::_Eos(&key, 0);
    LOBYTE(v66) = 29;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    std::wstring::wstring(&key, L"FRONT_DIFF_PRELOAD");
    LOBYTE(v66) = 54;
    std::wstring::wstring(&result, L"AWD2");
    LOBYTE(v66) = 55;
    this->awdFrontDiff.preload = INIReader::getFloat(&r, &result, &key);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    LOBYTE(v66) = 29;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    std::wstring::wstring(&key, L"REAR_DIFF_POWER");
    LOBYTE(v66) = 56;
    std::wstring::wstring(&result, L"AWD2");
    LOBYTE(v66) = 57;
    this->diffPowerRamp = INIReader::getFloat(&r, &result, &key);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    LOBYTE(v66) = 29;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&key);
    std::wstring::wstring(&v61, L"REAR_DIFF_COAST");
    LOBYTE(v66) = 58;
    std::wstring::wstring(&result, L"AWD2");
    LOBYTE(v66) = 59;
    this->diffCoastRamp = INIReader::getFloat(&r, &result, &v61);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&result);
    LOBYTE(v66) = 29;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v61);
    std::wstring::wstring(&v59, L"REAR_DIFF_PRELOAD");
    LOBYTE(v66) = 60;
    std::wstring::wstring(&v61, L"AWD2");
    LOBYTE(v66) = 61;
    this->diffPreLoad = INIReader::getFloat(&r, &v61, &v59);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v61);
    LOBYTE(v66) = 29;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v59);
    std::wstring::wstring((std::wstring *)buffer, L"CENTRE_RAMP_TORQUE");
    LOBYTE(v66) = 62;
    std::wstring::wstring(&v59, L"AWD2");
    LOBYTE(v66) = 63;
    this->awd2.ramp = INIReader::getFloat(&r, &v59, (const std::wstring *)buffer);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v59);
    LOBYTE(v66) = 29;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)buffer);
    std::wstring::wstring((std::wstring *)gname, L"CENTRE_MAX_TORQUE");
    LOBYTE(v66) = 64;
    std::wstring::wstring((std::wstring *)buffer, L"AWD2");
    LOBYTE(v66) = 65;
    this->awd2.maxTorque = INIReader::getFloat(&r, (const std::wstring *)buffer, (const std::wstring *)gname);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)buffer);
    LOBYTE(v66) = 29;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)gname);
    std::operator+<wchar_t>(&filename, (const std::wstring *)LODWORD(ginertia), L"ctrl_awd2.ini");
    LOBYTE(v66) = 66;
    if ( Path::fileExists(v11, &filename, 0) )
    {
      _printf("Loading AWD2 controller\n");
      *(float *)&v42 = COERCE_FLOAT(operator new(20));
      ginertia = *(float *)&v42;
      LOBYTE(v66) = 67;
      if ( *(float *)&v42 == 0.0 )
        v43 = 0;
      else
        DynamicController::DynamicController(v42, this->car, &filename);
      std::unique_ptr<DynamicController>::reset(&this->controllers.awd2, v43);
    }
    LOBYTE(v66) = 29;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&filename);
  }
  std::wstring::wstring((std::wstring *)buffer, L"CHANGE_UP_TIME");
  LOBYTE(v66) = 68;
  std::wstring::wstring((std::wstring *)gname, L"GEARBOX");
  LOBYTE(v66) = 69;
  this->gearUpTime = INIReader::getFloat(&r, (const std::wstring *)gname, (const std::wstring *)buffer) * 0.001;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)gname);
  LOBYTE(v66) = 29;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)buffer);
  std::wstring::wstring(&v59, L"CHANGE_DN_TIME");
  LOBYTE(v66) = 70;
  std::wstring::wstring((std::wstring *)gname, L"GEARBOX");
  LOBYTE(v66) = 71;
  this->gearDnTime = INIReader::getFloat(&r, (const std::wstring *)gname, &v59) * 0.001;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)gname);
  LOBYTE(v66) = 29;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v59);
  if ( this->gearDnTime == 0.0 )
    this->gearDnTime = DOUBLE_0_15;
  if ( this->gearUpTime == 0.0 )
    this->gearUpTime = DOUBLE_0_1;
  std::wstring::wstring((std::wstring *)buffer, L"AUTO_CUTOFF_TIME");
  LOBYTE(v66) = 72;
  std::wstring::wstring((std::wstring *)gname, L"GEARBOX");
  LOBYTE(v66) = 73;
  this->autoCutOffTime = INIReader::getFloat(&r, (const std::wstring *)gname, (const std::wstring *)buffer) * 0.001;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)gname);
  LOBYTE(v66) = 29;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)buffer);
  std::wstring::wstring(&v59, L"SUPPORTS_SHIFTER");
  LOBYTE(v66) = 74;
  std::wstring::wstring((std::wstring *)gname, L"GEARBOX");
  LOBYTE(v66) = 75;
  this->isShifterSupported = INIReader::getInt(&r, (const std::wstring *)gname, &v59) != 0;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)gname);
  LOBYTE(v66) = 29;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v59);
  std::wstring::wstring(&v61, L"DOWNSHIFT_PROTECTION");
  v44 = v54 | 2;
  LOBYTE(v66) = 76;
  LODWORD(v52) = v54 | 2;
  if ( !INIReader::hasSection(&r, &v61)
    || (v45 = !this->isShifterSupported,
        v51.std::_Allocator_base<std::vector<LeaderboardEntry> > = (std::_Allocator_base<std::vector<LeaderboardEntry> >)1,
        !v45) )
  {
    v51.std::_Allocator_base<std::vector<LeaderboardEntry> > = 0;
  }
  v66 = 29;
  if ( (v44 & 2) != 0 )
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v61);
  if ( v51.std::_Allocator_base<std::vector<LeaderboardEntry> > )
  {
    std::wstring::wstring((std::wstring *)buffer, L"ACTIVE");
    LOBYTE(v66) = 77;
    std::wstring::wstring((std::wstring *)gname, L"DOWNSHIFT_PROTECTION");
    LOBYTE(v66) = 78;
    this->downshiftProtection.isActive = INIReader::getInt(
                                           &r,
                                           (const std::wstring *)gname,
                                           (const std::wstring *)buffer) != 0;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)gname);
    LOBYTE(v66) = 29;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)buffer);
    std::wstring::wstring(&v59, L"DEBUG");
    LOBYTE(v66) = 79;
    std::wstring::wstring((std::wstring *)gname, L"DOWNSHIFT_PROTECTION");
    LOBYTE(v66) = 80;
    this->downshiftProtection.isDebug = INIReader::getInt(&r, (const std::wstring *)gname, &v59) != 0;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)gname);
    LOBYTE(v66) = 29;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v59);
    std::wstring::wstring(&v61, L"OVERREV");
    LOBYTE(v66) = 81;
    std::wstring::wstring((std::wstring *)gname, L"DOWNSHIFT_PROTECTION");
    LOBYTE(v66) = 82;
    this->downshiftProtection.overrev = INIReader::getInt(&r, (const std::wstring *)gname, &v61);
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)gname);
    LOBYTE(v66) = 29;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v61);
    std::wstring::wstring(&filename, L"LOCK_N");
    LOBYTE(v66) = 83;
    std::wstring::wstring((std::wstring *)gname, L"DOWNSHIFT_PROTECTION");
    LOBYTE(v66) = 84;
    this->downshiftProtection.lockN = INIReader::getInt(&r, (const std::wstring *)gname, &filename) != 0;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)gname);
    LOBYTE(v66) = 29;
    std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&filename);
  }
  else
  {
    this->downshiftProtection.isActive = !this->isShifterSupported;
  }
  v46 = this->car;
  HIDWORD(ratio) = L"MAX_TORQUE";
  this->downshiftProtection.isDebug = v46->physicsGUID == 0;
  std::wstring::wstring((std::wstring *)buffer, (const wchar_t *)HIDWORD(ratio));
  LOBYTE(v66) = 85;
  std::wstring::wstring((std::wstring *)gname, L"CLUTCH");
  LOBYTE(v66) = 86;
  this->clutchMaxTorque = INIReader::getFloat(&r, (const std::wstring *)gname, (const std::wstring *)buffer);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)gname);
  LOBYTE(v66) = 29;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)buffer);
  if ( this->clutchMaxTorque == 0.0 )
    this->clutchMaxTorque = DOUBLE_450_0;
  std::wstring::wstring((std::wstring *)buffer, L"VALID_SHIFT_RPM_WINDOW");
  LOBYTE(v66) = 87;
  std::wstring::wstring((std::wstring *)gname, L"GEARBOX");
  LOBYTE(v66) = 88;
  this->validShiftRPMWindow = INIReader::getFloat(&r, (const std::wstring *)gname, (const std::wstring *)buffer);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)gname);
  LOBYTE(v66) = 29;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)buffer);
  v47 = this->validShiftRPMWindow;
  HIDWORD(ratio) = L"CONTROLS_WINDOW_GAIN";
  this->orgRpmWindow = v47;
  std::wstring::wstring(&v59, (const wchar_t *)HIDWORD(ratio));
  LOBYTE(v66) = 89;
  std::wstring::wstring((std::wstring *)gname, L"GEARBOX");
  LOBYTE(v66) = 90;
  this->controlsWindowGain = INIReader::getFloat(&r, (const std::wstring *)gname, &v59);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)gname);
  LOBYTE(v66) = 29;
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&v59);
  if ( this->validShiftRPMWindow == 0.0 )
    this->validShiftRPMWindow = DOUBLE_500_0;
  std::wstring::wstring((std::wstring *)buffer, L"INERTIA");
  LOBYTE(v66) = 91;
  std::wstring::wstring((std::wstring *)gname, L"GEARBOX");
  LOBYTE(v66) = 92;
  ginertia = INIReader::getFloat(&r, (const std::wstring *)gname, (const std::wstring *)buffer);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)gname);
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)buffer);
  v48 = ginertia;
  if ( ginertia != 0.0 )
  {
    this->clutchInertia = ginertia;
    this->drive.inertia = v48;
  }
  std::wstring::~wstring((FriendsLeaderboardDisplayer::FriendsLeaderboardElement *)&tr);
  v66 = -1;
  INIReader::~INIReader(&r);
}
double Drivetrain::projectRPMAtDownshift(Drivetrain *this)
{
  int v1; // edx
  double v2; // xmm2_8

  v1 = this->currentGear;
  if ( !v1 )
    return -1.0;
  v2 = this->gears._Myfirst[v1 - 1].ratio;
  if ( v2 == 0.0 )
    return -1.0;
  return (float)((float)((this->outShaftR.velocity + this->outShaftL.velocity) * 0.5)
               * v2
               * this->finalRatio
               * 0.1591550715257987
               * 60.0);
}
void Drivetrain::reallignSpeeds(Drivetrain *this, float dt)
{
  double v3; // xmm3_8
  __int64 v4; // xmm5_8
  double v5; // xmm4_8
  bool v6; // zf
  double v7; // xmm6_8
  double v8; // xmm2_8
  double v9; // xmm1_8
  double v10; // xmm3_8
  long double v11; // [esp+14h] [ebp-10h]
  double v12; // [esp+1Ch] [ebp-8h]

  v3 = this->ratio;
  if ( v3 == 0.0 )
    return;
  v4 = _xmm;
  if ( this->locClutch <= 0.89999998 )
  {
    v5 = this->drive.velocity;
    this->rootVelocity = v5 * v3;
  }
  else
  {
    v12 = this->rootVelocity;
    v11 = Drivetrain::getInertiaFromEngine(this);
    v3 = this->ratio;
    v5 = this->drive.velocity;
    v4 = _xmm;
    this->rootVelocity = v12
                       - (1.0 - this->engine.inertia / v11)
                       * (v12 / v3 - v5)
                       * COERCE_DOUBLE(*(_QWORD *)&this->ratio & _xmm);
  }
  v6 = this->tractionType == AWD;
  v7 = this->rootVelocity;
  v8 = v7 / v3;
  v9 = (float)(v7 / v3 - v5);
  v10 = this->drive.velocity + v9;
  this->drive.velocity = v10;
  if ( v6 )
  {
    v9 = v9 * 0.5 * 2.0;
    this->outShaftLF.velocity = this->outShaftLF.velocity + v9;
    this->outShaftRF.velocity = this->outShaftRF.velocity + v9;
LABEL_8:
    this->outShaftL.velocity = this->outShaftL.velocity + v9;
    this->outShaftR.velocity = this->outShaftR.velocity + v9;
    goto LABEL_9;
  }
  if ( this->diffType <= (unsigned int)Spool )
    goto LABEL_8;
LABEL_9:
  if ( !this->clutchOpenState )
    this->engine.velocity = v7;
  if ( COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v10 - v8) & v4) > 0.5 )
    _printf("NOT GOOD, WE ARE STUFFED %f expected %f\n", v10, v8);
}
void Drivetrain::reset(Drivetrain *this)
{
  long double v1; // xmm0_8

  this->clutchOpenState = 1;
  this->rootVelocity = 0.0;
  this->engine.velocity = 0.0;
  this->outShaftL.velocity = 0.0;
  this->outShaftR.velocity = 0.0;
  this->outShaftLF.velocity = 0.0;
  this->outShaftRF.velocity = 0.0;
  this->drive.velocity = 0.0;
  v1 = this->orgRpmWindow;
  this->gearRequest.request = eNoGearRequest;
  this->validShiftRPMWindow = v1;
  Engine::reset(&this->acEngine);
}
void Drivetrain::setCurrentGear(Drivetrain *this, int index, bool force)
{
  Car *v4; // eax
  double v5; // xmm4_8
  double v6; // xmm3_8
  float v7; // xmm0_4

  if ( index == 1 || !Drivetrain::isGearboxLocked(this) )
  {
    this->isGearGrinding = 0;
    if ( index >= 0 && index < (unsigned int)(this->gears._Mylast - this->gears._Myfirst) && index != this->currentGear )
    {
      if ( index == 1
        || force
        || (v4 = this->car,
            v5 = this->validShiftRPMWindow,
            *(_QWORD *)&v6 = COERCE_UNSIGNED_INT64(
                               this->engine.velocity
                             - this->gears._Myfirst[index].ratio * this->drive.velocity * this->finalRatio) & _xmm,
            v5 > ((v4->controls.gas * this->locClutch * v6 - this->locClutch * v6) * this->controlsWindowGain
                + this->locClutch * v6)
               * 0.1591550715257987
               * 60.0) )
      {
        this->currentGear = index;
      }
      else
      {
        this->isGearGrinding = 1;
        if ( v5 > 0.0 )
        {
          v7 = v4->ksPhysics->mechanicalDamageRate;
          if ( v7 > 0.0 )
            this->validShiftRPMWindow = v5 - this->damageRpmWindow * 0.003000000026077032 * v7;
        }
      }
    }
  }
  else
  {
    this->currentGear = 1;
  }
}
void Drivetrain::setGearRatio(Drivetrain *this, int index, float value)
{
  if ( index < 0 || index >= (unsigned int)(this->gears._Mylast - this->gears._Myfirst) )
    _printf("ERROR: Index out of bound for gear ratio request: %d\n", index);
  else
    this->gears._Myfirst[index].ratio = value;
}
void Drivetrain::step2WD(Drivetrain *this, float dt)
{
  int v3; // eax
  SGearRatio *v4; // eax
  bool v5; // cf
  long double v6; // xmm0_8
  ITorqueGenerator **v7; // esi
  unsigned int v8; // ecx
  double v9; // st7
  Tyre *v10; // eax
  float v11; // xmm0_4
  double v12; // xmm1_8
  float v13; // xmm0_4
  double v14; // xmm0_8
  TractionType v15; // esi
  double v16; // xmm2_8
  double v17; // xmm1_8
  long double v18; // st7
  bool v19; // zf
  double v20; // xmm3_8
  double v21; // xmm6_8
  double v22; // xmm6_8
  __int64 v23; // xmm5_8
  float v24; // xmm0_4
  double v25; // xmm0_8
  long double v26; // xmm5_8
  long double v27; // xmm0_8
  double v28; // xmm5_8
  float v29; // xmm2_4
  double v30; // xmm1_8
  float v31; // xmm0_4
  double v32; // xmm2_8
  double v33; // xmm1_8
  long double v34; // xmm0_8
  long double v35; // xmm5_8
  Tyre *v36; // ecx
  Tyre *v37; // edx
  double v38; // xmm1_8
  double v39; // xmm0_8
  double v40; // xmm1_8
  long double v41; // xmm1_8
  double v42; // xmm0_8
  long double v43; // xmm5_8
  long double v44; // xmm0_8
  double v45; // xmm5_8
  float v46; // xmm2_4
  double v47; // xmm1_8
  float v48; // xmm0_4
  double v49; // xmm1_8
  long double v50; // xmm0_8
  long double v51; // xmm5_8
  long double v52; // xmm0_8
  long double v53; // xmm1_8
  long double v54; // xmm0_8
  DifferentialType v55; // eax
  double v56; // xmm0_8
  double v57; // xmm2_8
  long double v58; // xmm0_8
  double v59; // xmm1_8
  double v60; // xmm1_8
  double v61; // xmm6_8
  double v62; // xmm0_8
  long double v63; // xmm1_8
  long double v64; // xmm0_8
  long double v65; // xmm0_8
  long double v66; // xmm6_8
  long double v67; // xmm2_8
  long double v68; // xmm1_8
  Speed *v69; // eax
  char v70; // cl
  double v71; // xmm0_8
  double v72; // xmm1_8
  double v73; // xmm2_8
  float v74; // xmm0_4
  float v75; // xmm0_4
  double v76; // xmm1_8
  float v77; // xmm0_4
  float v78; // xmm0_4
  float v79; // xmm1_4
  Car *v80; // eax
  unsigned int v81; // xmm0_4
  Car *v82; // ecx
  float v83; // xmm0_4
  Car *v84; // ecx
  float v85; // xmm0_4
  int v86; // esi
  ISuspension *v87; // ecx
  float *v88; // eax
  float v89; // xmm1_4
  float v90; // xmm2_4
  float v91; // xmm3_4
  Car *v92; // eax
  mat44f v93; // [esp+18h] [ebp-88h] BYREF
  int v94; // [esp+58h] [ebp-48h]
  Speed v95; // [esp+5Ch] [ebp-44h] BYREF
  long double v96; // [esp+60h] [ebp-40h]
  long double v97; // [esp+68h] [ebp-38h]
  long double v98; // [esp+70h] [ebp-30h]
  char v99; // [esp+7Bh] [ebp-25h]
  SGearRatio result; // [esp+7Ch] [ebp-24h] BYREF

  LODWORD(v95.value) = 0;
  if ( (dword_186F0F4 & 1) == 0 )
  {
    perfCounter_25.name = "Drivetrain::step2WD";
    dword_186F0F4 |= 1u;
    perfCounter_25.group = Physics;
    perfCounter_25.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Drivetrain::step2WD" | 0xFF000000;
  }
  if ( (this->gearRequest.request == eChangeUp || this->gearRequest.request == eChangeDown)
    && this->gearRequest.timeAccumulator > this->gearRequest.timeout )
  {
    v3 = this->gearRequest.requestedGear;
    this->gearRequest.request = eNoGearRequest;
    this->currentGear = v3;
  }
  if ( this->gearRequest.request )
    this->gearRequest.timeAccumulator = dt + this->gearRequest.timeAccumulator;
  v4 = Drivetrain::getCurrentGear(this, &result);
  v5 = result.name._Myres < 8;
  this->ratio = this->finalRatio * v4->ratio;
  if ( !v5 )
    operator delete(result.name._Bx._Ptr);
  v6 = this->acEngine.inertia;
  HIDWORD(v98) = 0;
  this->engine.inertia = v6;
  v7 = this->wheelTorqueGenerators._Myfirst;
  v8 = (unsigned int)((char *)this->wheelTorqueGenerators._Mylast - (char *)v7 + 3) >> 2;
  if ( v7 > this->wheelTorqueGenerators._Mylast )
    v8 = 0;
  HIDWORD(v96) = v8;
  if ( v8 )
  {
    do
    {
      v9 = ((double (*)(ITorqueGenerator *))(*v7)->getOutputTorque)(*v7);
      v10 = this->tyreRight;
      ++v7;
      v11 = v10->status.feedbackTorque;
      *((float *)&v97 + 1) = v9 * 0.5;
      v10->status.feedbackTorque = v11 + *((float *)&v97 + 1);
      this->tyreLeft->status.feedbackTorque = this->tyreLeft->status.feedbackTorque + *((float *)&v97 + 1);
      ++HIDWORD(v98);
    }
    while ( HIDWORD(v98) != HIDWORD(v96) );
  }
  if ( this->ratio != this->lastRatio )
  {
    Drivetrain::reallignSpeeds(this, dt);
    this->lastRatio = this->ratio;
  }
  v12 = this->cutOff;
  *(_QWORD *)&result.name._Bx._Alias[8] = 0i64;
  result.name._Myres = 0;
  result.name._Mysize = 0;
  if ( v12 > 0.0 )
  {
    *(_DWORD *)&result.name._Bx._Alias[8] = 0;
    this->cutOff = v12 - dt;
  }
  else
  {
    *(float *)&result.name._Bx._Alias[8] = this->car->controls.gas;
  }
  v13 = this->engine.velocity;
  *(float *)&result.name._Myres = (float)(v13 * 0.15915507) * 60.0;
  Engine::step(&this->acEngine, (SACEngineInput *)&result.name._Bx._Alias[8], dt);
  if ( this->locClutch < 1.0 )
  {
LABEL_27:
    this->clutchOpenState = 1;
    goto LABEL_28;
  }
  v14 = this->engine.velocity;
  if ( v14 != 0.0 )
  {
    if ( COERCE_DOUBLE(COERCE_UNSIGNED_INT64(this->rootVelocity / v14 - 1.0) & _xmm) < 0.1 )
    {
      this->clutchOpenState = 0;
      goto LABEL_28;
    }
    goto LABEL_27;
  }
  this->clutchOpenState = this->rootVelocity != 0.0;
LABEL_28:
  v15 = this->tractionType;
  v16 = this->ratio;
  if ( v15 == AWD )
  {
    if ( v16 != 0.0 )
    {
      v17 = this->outShaftL.inertia
          + this->drive.inertia
          + this->outShaftR.inertia
          + this->outShaftLF.inertia
          + this->outShaftRF.inertia;
      goto LABEL_33;
    }
  }
  else if ( v16 != 0.0 )
  {
    v17 = this->outShaftL.inertia + this->drive.inertia + this->outShaftR.inertia;
LABEL_33:
    v97 = v17 / COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v16 * v16) & _xmm) + this->clutchInertia + this->engine.inertia;
    goto LABEL_35;
  }
  v97 = this->engine.inertia;
LABEL_35:
  v18 = Drivetrain::getInertiaFromWheels(this);
  v19 = !this->clutchOpenState;
  v20 = this->ratio;
  v21 = 0.0;
  v98 = v18;
  if ( !v19 )
  {
    v22 = this->engine.velocity;
    v23 = _xmm;
    *(long double *)&result.name._Mysize = this->rootVelocity;
    v21 = -((v22 - *(double *)&result.name._Mysize)
          / (COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v22 - *(double *)&result.name._Mysize) & _xmm) + 4.0)
          * (this->locClutch
           * this->clutchMaxTorque));
    v24 = v21;
    this->currentClutchTorque = v24;
    v96 = this->acEngine.status.outTorque;
    v25 = dt;
    if ( v20 == 0.0 )
    {
      v36 = this->tyreRight;
      v37 = this->tyreLeft;
      v41 = v96 / this->engine.inertia * v25 + this->engine.velocity;
      this->engine.velocity = v41;
      this->rootVelocity = v41;
      v38 = (float)(v36->status.feedbackTorque + v37->status.feedbackTorque) / v98 * dt;
      this->drive.velocity = v38 + this->drive.velocity;
      if ( v15 == AWD )
      {
        v38 = v38 * 0.5 * 2.0;
        this->outShaftLF.velocity = v38 + this->outShaftLF.velocity;
        this->outShaftRF.velocity = v38 + this->outShaftRF.velocity;
LABEL_55:
        v52 = v38 + this->outShaftL.velocity;
        v53 = v38 + this->outShaftR.velocity;
        this->outShaftL.velocity = v52;
        this->outShaftR.velocity = v53;
        goto LABEL_61;
      }
LABEL_54:
      if ( this->diffType > (unsigned int)Spool )
        goto LABEL_61;
      goto LABEL_55;
    }
    this->engine.velocity = (v96 + v21) / this->engine.inertia * v25 + this->engine.velocity;
    v26 = dt * (COERCE_DOUBLE(*(_QWORD *)&v21 ^ _xmm) / (v97 - this->engine.inertia));
    v27 = *(double *)&result.name._Mysize + v26;
    v28 = v26 / v20;
    this->rootVelocity = v27;
    *(double *)&result.name._Mysize = v28 + this->drive.velocity;
    this->drive.velocity = *(long double *)&result.name._Mysize;
    if ( v15 == AWD )
    {
      v29 = this->awdFrontShare;
      v30 = v29 * v28 * 2.0;
      this->outShaftLF.velocity = this->outShaftLF.velocity + v30;
      this->outShaftRF.velocity = this->outShaftRF.velocity + v30;
      v31 = 1.0 - v29;
      v32 = DOUBLE_2_0;
      v33 = v31 * v28 * 2.0;
      this->outShaftL.velocity = this->outShaftL.velocity + v33;
      this->outShaftR.velocity = this->outShaftR.velocity + v33;
    }
    else
    {
      v32 = DOUBLE_2_0;
      if ( this->diffType <= (unsigned int)Spool )
      {
        v34 = v28 + this->outShaftL.velocity;
        v35 = v28 + this->outShaftR.velocity;
        this->outShaftL.velocity = v34;
        this->outShaftR.velocity = v35;
      }
    }
    v36 = this->tyreRight;
    v37 = this->tyreLeft;
    v38 = dt * ((float)(v36->status.feedbackTorque + v37->status.feedbackTorque) / v98);
    this->rootVelocity = v20 * v38 + this->rootVelocity;
    v39 = v38 + *(double *)&result.name._Mysize;
LABEL_42:
    this->drive.velocity = v39;
    if ( v15 == AWD )
    {
      v40 = v38 * 0.5 * v32;
LABEL_44:
      this->outShaftLF.velocity = v40 + this->outShaftLF.velocity;
      this->outShaftRF.velocity = v40 + this->outShaftRF.velocity;
LABEL_59:
      v54 = v40 + this->outShaftL.velocity;
      this->outShaftR.velocity = v40 + this->outShaftR.velocity;
      this->outShaftL.velocity = v54;
      goto LABEL_60;
    }
    v23 = _xmm;
    goto LABEL_54;
  }
  v42 = this->acEngine.status.outTorque;
  v96 = v42;
  if ( v20 != 0.0 )
  {
    v43 = dt * (v42 / v97);
    v44 = this->rootVelocity + v43;
    v45 = v43 / v20;
    this->rootVelocity = v44;
    *(double *)&result.name._Mysize = v45 + this->drive.velocity;
    this->drive.velocity = *(long double *)&result.name._Mysize;
    if ( v15 == AWD )
    {
      v46 = this->awdFrontShare;
      v47 = v46 * v45 * 2.0;
      this->outShaftLF.velocity = this->outShaftLF.velocity + v47;
      this->outShaftRF.velocity = this->outShaftRF.velocity + v47;
      v48 = 1.0 - v46;
      v32 = DOUBLE_2_0;
      v49 = v48 * v45 * 2.0;
      this->outShaftL.velocity = this->outShaftL.velocity + v49;
      this->outShaftR.velocity = this->outShaftR.velocity + v49;
    }
    else
    {
      v32 = DOUBLE_2_0;
      if ( this->diffType <= (unsigned int)Spool )
      {
        v50 = v45 + this->outShaftL.velocity;
        v51 = v45 + this->outShaftR.velocity;
        this->outShaftL.velocity = v50;
        this->outShaftR.velocity = v51;
      }
    }
    v36 = this->tyreRight;
    v37 = this->tyreLeft;
    v38 = dt * ((float)(v36->status.feedbackTorque + v37->status.feedbackTorque) / v98);
    this->rootVelocity = v20 * v38 + this->rootVelocity;
    v39 = v38 + *(double *)&result.name._Mysize;
    goto LABEL_42;
  }
  v36 = this->tyreRight;
  v37 = this->tyreLeft;
  this->rootVelocity = v42 / v97 * dt + this->rootVelocity;
  v40 = (float)(v36->status.feedbackTorque + v37->status.feedbackTorque) / v98 * dt;
  this->drive.velocity = v40 + this->drive.velocity;
  if ( v15 == AWD )
  {
    v40 = v40 * 0.5 * 2.0;
    goto LABEL_44;
  }
  if ( this->diffType <= (unsigned int)Spool )
    goto LABEL_59;
LABEL_60:
  v23 = _xmm;
LABEL_61:
  v55 = this->diffType;
  v56 = this->acEngine.status.outTorque;
  v57 = this->locClutch * v56;
  if ( v55 == LSD )
  {
    if ( v21 != 0.0 )
      v57 = -v21;
    *(_QWORD *)&v59 = *(_QWORD *)&v20 & v23;
    if ( v57 <= 0.0 )
      *(_QWORD *)&v60 = COERCE_UNSIGNED_INT64(v59 * (this->diffCoastRamp * v57)) & v23;
    else
      v60 = v59 * (this->diffPowerRamp * v57);
    v61 = this->outShaftL.velocity;
    v62 = this->diffPreLoad + v60;
    v63 = v61 - this->drive.velocity;
    v97 = v62;
    v98 = this->outShaftR.velocity;
    if ( COERCE_DOUBLE(*(_QWORD *)&v63 & v23) >= 0.1000000014901161
      || COERCE_DOUBLE(COERCE_UNSIGNED_INT64((float)(v36->status.feedbackTorque - v37->status.feedbackTorque)) & v23) > v97 )
    {
      v65 = dt
          * (-((v61 - v98) / (COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v61 - v98) & v23) + 0.009999999776482582) * v62)
           / this->outShaftL.inertia
           * 0.5);
      v66 = v61 + v65;
      v67 = v98 - v65;
      this->outShaftL.velocity = v66;
      this->outShaftR.velocity = v67;
      v68 = dt * ((float)(v36->status.feedbackTorque - v37->status.feedbackTorque) / this->outShaftR.inertia * 0.5);
      this->outShaftL.velocity = v66 - v68;
      this->outShaftR.velocity = v67 + v68;
    }
    else
    {
      v64 = this->drive.velocity;
      this->outShaftR.velocity = v64;
      this->outShaftL.velocity = v64;
    }
    goto LABEL_73;
  }
  if ( v55 == Spool )
  {
    v58 = this->drive.velocity;
    this->outShaftR.velocity = v58;
    this->outShaftL.velocity = v58;
LABEL_73:
    v56 = v96;
  }
  if ( !v37->status.isLocked || !v36->status.isLocked )
    goto LABEL_85;
  if ( COERCE_DOUBLE(COERCE_UNSIGNED_INT64(COERCE_DOUBLE(*(_QWORD *)&v20 & v23) * v56) & v23) > (float)((float)((float)((float)(v37->absOverride * v37->inputs.brakeTorque) + v37->inputs.handBrakeTorque) + (float)(v36->absOverride * v36->inputs.brakeTorque)) + v36->inputs.handBrakeTorque) )
  {
    v70 = LOBYTE(v95.value);
    goto LABEL_80;
  }
  v69 = Car::getSpeed(this->car, &v95);
  v70 = 1;
  if ( v69->value > 1.0 )
  {
LABEL_80:
    v99 = 1;
    goto LABEL_81;
  }
  v99 = 0;
LABEL_81:
  if ( (v70 & 1) != 0 )
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v95);
  if ( v99 )
  {
    this->tyreLeft->status.isLocked = 0;
    this->tyreRight->status.isLocked = 0;
  }
  else if ( this->clutchOpenState )
  {
    this->rootVelocity = 0.0;
    this->drive.velocity = 0.0;
    this->outShaftL.velocity = 0.0;
    this->outShaftR.velocity = 0.0;
  }
LABEL_85:
  if ( this->tyreLeft && this->tyreRight && this->tractionType != AWD_NEW )
  {
    if ( !this->clutchOpenState )
      this->engine.velocity = this->rootVelocity;
    v71 = this->ratio;
    if ( v71 != 0.0 )
    {
      v72 = this->rootVelocity / v71;
      v73 = this->drive.velocity;
      if ( COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v73 - v72) & _xmm) > 0.5 )
        _printf("NOT GOOD, WE ARE STUFFED %f expected %f\n", v73, v72);
    }
    v74 = this->outShaftL.velocity;
    this->tyreLeft->status.angularVelocity = v74;
    v75 = this->outShaftR.velocity;
    this->tyreRight->status.angularVelocity = v75;
    Tyre::stepRotationMatrix(this->tyreLeft, dt);
    Tyre::stepRotationMatrix(this->tyreRight, dt);
  }
  v76 = this->ratio;
  v77 = this->acEngine.status.outTorque;
  v78 = v77 * this->locClutch;
  if ( v76 == 0.0 )
    LODWORD(this->totalTorque) = LODWORD(v78) & _xmm;
  else
    LODWORD(this->totalTorque) = COERCE_UNSIGNED_INT(
                                   (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v76) & _xmm) * v78)
                                 - (float)(this->tyreLeft->status.feedbackTorque + this->tyreRight->status.feedbackTorque)) & _xmm;
  v79 = this->locClutch * this->acEngine.status.outTorque * Drivetrain::getCurrentGear(this, &result)->ratio;
  *((float *)&v98 + 1) = v79;
  if ( result.name._Myres >= 8 )
  {
    operator delete(result.name._Bx._Ptr);
    v79 = *((float *)&v98 + 1);
  }
  v80 = this->car;
  if ( v80->suspensionTypeR == Axle )
  {
    *(float *)&v81 = v80->axleTorqueReaction * v79;
    *(_DWORD *)&result.name._Bx._Alias[12] = 0;
    result.name._Mysize = 0;
    result.name._Myres = v81;
    v80->body->addLocalTorque(v80->body, (const vec3f *)&result.name._Bx._Alias[12]);
    v82 = this->car;
    v83 = v82->axleTorqueReaction;
    *(_DWORD *)&result.name._Bx._Alias[12] = 0;
    result.name._Mysize = 0;
    result.name._Myres = COERCE_UNSIGNED_INT(v83 * *((float *)&v98 + 1)) ^ _xmm;
    v82->rigidAxle->addLocalTorque(v82->rigidAxle, (const vec3f *)&result.name._Bx._Alias[12]);
    v84 = this->car;
    if ( v84->torqueModeEx == reactionTorques )
    {
      v85 = v84->axleTorqueReaction;
      result.name._Mysize = 0;
      result.name._Myres = 0;
      *(_DWORD *)&result.name._Bx._Alias[12] = HIDWORD(v98) ^ _xmm;
      if ( v85 == 0.0 )
        v84->body->addLocalTorque(v84->body, (const vec3f *)&result.name._Bx._Alias[12]);
      else
        v84->rigidAxle->addLocalTorque(v84->rigidAxle, (const vec3f *)&result.name._Bx._Alias[12]);
    }
  }
  else if ( v80->torqueModeEx == reactionTorques
         && !this->tyreLeft->status.isLocked
         && !this->tyreRight->status.isLocked )
  {
    if ( this->tractionType == FWD )
    {
      v94 = 0;
      LODWORD(v95.value) = (Speed)1;
    }
    else
    {
      v94 = 2;
      LODWORD(v95.value) = (Speed)3;
    }
    v86 = 0;
    HIDWORD(v98) = LODWORD(v79) ^ _xmm;
    do
    {
      v87 = this->car->suspensions._Myfirst[*(&v94 + v86)];
      v88 = (float *)v87->getHubWorldMatrix(v87, &v93);
      v89 = *v88;
      v90 = v88[1];
      v91 = v88[2];
      v92 = this->car;
      *(float *)&result.name._Bx._Alias[12] = (float)(v89 * *((float *)&v98 + 1)) * 0.5;
      *(float *)&result.name._Mysize = (float)(v90 * *((float *)&v98 + 1)) * 0.5;
      *(float *)&result.name._Myres = (float)(v91 * *((float *)&v98 + 1)) * 0.5;
      v92->body->addTorque(v92->body, (const vec3f *)&result.name._Bx._Alias[12]);
      ++v86;
    }
    while ( v86 < 2 );
  }
}
void Drivetrain::step4WD(Drivetrain *this, float dt)
{
  int v3; // eax
  SGearRatio *v4; // eax
  bool v5; // cf
  ITorqueGenerator **v6; // esi
  unsigned int v7; // ecx
  double v8; // st7
  double v9; // xmm1_8
  float v10; // xmm0_4
  double v11; // xmm0_8
  TractionType v12; // esi
  double v13; // xmm2_8
  double v14; // xmm1_8
  long double v15; // st7
  double v16; // xmm2_8
  double v17; // xmm4_8
  double v18; // xmm5_8
  float v19; // xmm6_4
  __int64 v20; // xmm3_8
  float v21; // xmm0_4
  double v22; // xmm0_8
  long double v23; // xmm3_8
  long double v24; // xmm0_8
  double v25; // xmm3_8
  float v26; // xmm2_4
  double v27; // xmm1_8
  float v28; // xmm0_4
  double v29; // xmm2_8
  double v30; // xmm1_8
  double v31; // xmm0_8
  bool v32; // zf
  float *v33; // eax
  float *v34; // ecx
  float *v35; // edx
  double v36; // xmm1_8
  double v37; // xmm1_8
  float *v38; // eax
  long double v39; // xmm1_8
  double v40; // xmm0_8
  double v41; // xmm3_8
  long double v42; // xmm0_8
  double v43; // xmm3_8
  float v44; // xmm2_4
  double v45; // xmm1_8
  float v46; // xmm0_4
  double v47; // xmm1_8
  double v48; // xmm3_8
  double v49; // xmm1_8
  float *v50; // eax
  float *v51; // eax
  float v52; // xmm0_4
  double v53; // xmm1_8
  double v54; // xmm2_8
  double v55; // xmm0_8
  double v56; // xmm3_8
  long double v57; // xmm0_8
  long double v58; // xmm2_8
  long double v59; // xmm3_8
  long double v60; // xmm1_8
  long double v61; // xmm0_8
  float v62; // xmm1_4
  double v63; // xmm0_8
  double v64; // xmm3_8
  double v65; // xmm1_8
  long double v66; // xmm1_8
  long double v67; // xmm1_8
  double v68; // xmm0_8
  double v69; // xmm1_8
  double v70; // xmm3_8
  long double v71; // xmm2_8
  long double v72; // xmm7_8
  long double v73; // xmm1_8
  long double v74; // xmm3_8
  long double v75; // xmm4_8
  long double v76; // xmm0_8
  long double v77; // xmm1_8
  double v78; // xmm1_8
  double v79; // xmm2_8
  float *v80; // eax
  float v81; // xmm0_4
  int v82; // esi
  float v83; // xmm0_4
  unsigned int v84; // xmm0_4
  double v85; // xmm1_8
  float v86; // xmm0_4
  double v87; // [esp+18h] [ebp-44h]
  double v88; // [esp+18h] [ebp-44h]
  double v89; // [esp+20h] [ebp-3Ch]
  int v90; // [esp+24h] [ebp-38h]
  float *v91; // [esp+24h] [ebp-38h]
  char *v92; // [esp+24h] [ebp-38h]
  bool v93; // [esp+2Bh] [ebp-31h]
  double v94; // [esp+2Ch] [ebp-30h]
  double v95; // [esp+2Ch] [ebp-30h]
  double v96; // [esp+2Ch] [ebp-30h]
  double v97; // [esp+2Ch] [ebp-30h]
  unsigned int v98; // [esp+30h] [ebp-2Ch]
  float v99; // [esp+34h] [ebp-28h]
  float *v100; // [esp+34h] [ebp-28h]
  SGearRatio result; // [esp+38h] [ebp-24h] BYREF

  if ( (dword_186F0E4 & 1) == 0 )
  {
    perfCounter_24.name = "Drivetrain::step4WD";
    dword_186F0E4 |= 1u;
    perfCounter_24.group = Physics;
    perfCounter_24.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"Drivetrain::step4WD" | 0xFF000000;
  }
  if ( (this->gearRequest.request == eChangeUp || this->gearRequest.request == eChangeDown)
    && this->gearRequest.timeAccumulator > this->gearRequest.timeout )
  {
    v3 = this->gearRequest.requestedGear;
    this->gearRequest.request = eNoGearRequest;
    this->currentGear = v3;
  }
  if ( this->gearRequest.request )
    this->gearRequest.timeAccumulator = dt + this->gearRequest.timeAccumulator;
  v4 = Drivetrain::getCurrentGear(this, &result);
  v5 = result.name._Myres < 8;
  this->ratio = this->finalRatio * v4->ratio;
  if ( !v5 )
    operator delete(result.name._Bx._Ptr);
  v90 = 0;
  this->engine.inertia = this->acEngine.inertia;
  v6 = this->wheelTorqueGenerators._Myfirst;
  v7 = (unsigned int)((char *)this->wheelTorqueGenerators._Mylast - (char *)v6 + 3) >> 2;
  if ( v6 > this->wheelTorqueGenerators._Mylast )
    v7 = 0;
  v98 = v7;
  if ( v7 )
  {
    do
    {
      v8 = ((double (*)(ITorqueGenerator *))(*v6)->getOutputTorque)(*v6);
      ++v6;
      v99 = v8 * 0.25;
      this->car->tyres[0].status.feedbackTorque = this->car->tyres[0].status.feedbackTorque + v99;
      this->car->tyres[1].status.feedbackTorque = this->car->tyres[1].status.feedbackTorque + v99;
      this->car->tyres[2].status.feedbackTorque = this->car->tyres[2].status.feedbackTorque + v99;
      this->car->tyres[3].status.feedbackTorque = this->car->tyres[3].status.feedbackTorque + v99;
      ++v90;
    }
    while ( v90 != v98 );
  }
  if ( this->ratio != this->lastRatio )
  {
    Drivetrain::reallignSpeeds(this, dt);
    this->lastRatio = this->ratio;
  }
  v9 = this->cutOff;
  *(_QWORD *)&result.name._Bx._Alias[8] = 0i64;
  result.name._Myres = 0;
  result.name._Mysize = 0;
  if ( v9 > 0.0 )
  {
    *(_DWORD *)&result.name._Bx._Alias[8] = 0;
    this->cutOff = v9 - dt;
  }
  else
  {
    *(float *)&result.name._Bx._Alias[8] = this->car->controls.gas;
  }
  v10 = this->engine.velocity;
  *(float *)&result.name._Myres = (float)(v10 * 0.15915507) * 60.0;
  Engine::step(&this->acEngine, (SACEngineInput *)&result.name._Bx._Alias[8], dt);
  if ( this->locClutch < 1.0 )
  {
LABEL_27:
    this->clutchOpenState = 1;
    goto LABEL_28;
  }
  v11 = this->engine.velocity;
  if ( v11 != 0.0 )
  {
    if ( COERCE_DOUBLE(COERCE_UNSIGNED_INT64(this->rootVelocity / v11 - 1.0) & _xmm) < 0.1 )
    {
      this->clutchOpenState = 0;
      goto LABEL_28;
    }
    goto LABEL_27;
  }
  this->clutchOpenState = this->rootVelocity != 0.0;
LABEL_28:
  v12 = this->tractionType;
  v13 = this->ratio;
  if ( v12 == AWD )
  {
    if ( v13 != 0.0 )
    {
      v14 = this->outShaftL.inertia
          + this->drive.inertia
          + this->outShaftR.inertia
          + this->outShaftLF.inertia
          + this->outShaftRF.inertia;
      goto LABEL_33;
    }
  }
  else if ( v13 != 0.0 )
  {
    v14 = this->outShaftL.inertia + this->drive.inertia + this->outShaftR.inertia;
LABEL_33:
    v94 = v14 / COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v13 * v13) & _xmm) + this->clutchInertia + this->engine.inertia;
    goto LABEL_35;
  }
  v94 = this->engine.inertia;
LABEL_35:
  v15 = Drivetrain::getInertiaFromWheels(this);
  v16 = DOUBLE_0_5;
  v17 = 0.0;
  v18 = this->ratio;
  v19 = dt;
  v93 = this->clutchOpenState;
  if ( v93 )
  {
    v20 = _xmm;
    v89 = this->rootVelocity;
    v17 = -((this->engine.velocity - v89)
          / (COERCE_DOUBLE(COERCE_UNSIGNED_INT64(this->engine.velocity - v89) & _xmm) + 4.0)
          * (this->locClutch
           * this->clutchMaxTorque));
    v21 = v17;
    this->currentClutchTorque = v21;
    *(long double *)&result.name._Mysize = this->acEngine.status.outTorque;
    v22 = dt;
    if ( v18 == 0.0 )
    {
      v32 = this->tractionType == AWD;
      v38 = (float *)this->car;
      v34 = v38 + 1885;
      v35 = v38 + 1477;
      v100 = v38 + 1069;
      v91 = v38 + 661;
      v39 = *(double *)&result.name._Mysize / this->engine.inertia * v22 + this->engine.velocity;
      this->engine.velocity = v39;
      this->rootVelocity = v39;
      v36 = (float)((float)(v38[1885] + v38[1477]) + (float)(v38[1069] + v38[661])) / v15 * dt;
      this->drive.velocity = this->drive.velocity + v36;
      if ( v32 )
      {
        v36 = v36 * 0.5 * 2.0;
        this->outShaftLF.velocity = v36 + this->outShaftLF.velocity;
        this->outShaftRF.velocity = v36 + this->outShaftRF.velocity;
LABEL_57:
        this->outShaftL.velocity = this->outShaftL.velocity + v36;
        this->outShaftR.velocity = this->outShaftR.velocity + v36;
        goto LABEL_63;
      }
LABEL_56:
      if ( this->diffType > (unsigned int)Spool )
        goto LABEL_63;
      goto LABEL_57;
    }
    this->engine.velocity = (*(double *)&result.name._Mysize + v17) / this->engine.inertia * v22 + this->engine.velocity;
    v23 = dt * (COERCE_DOUBLE(*(_QWORD *)&v17 ^ _xmm) / (v94 - this->engine.inertia));
    v24 = v89 + v23;
    v25 = v23 / v18;
    this->rootVelocity = v24;
    v95 = this->drive.velocity + v25;
    this->drive.velocity = v95;
    if ( v12 == AWD )
    {
      v26 = this->awdFrontShare;
      v27 = v26 * v25 * 2.0;
      this->outShaftLF.velocity = this->outShaftLF.velocity + v27;
      this->outShaftRF.velocity = this->outShaftRF.velocity + v27;
      v28 = 1.0 - v26;
      v29 = DOUBLE_2_0;
      v30 = v28 * v25 * 2.0;
      this->outShaftL.velocity = this->outShaftL.velocity + v30;
      v31 = this->outShaftR.velocity + v30;
    }
    else
    {
      v29 = DOUBLE_2_0;
      if ( this->diffType > (unsigned int)Spool )
        goto LABEL_42;
      this->outShaftL.velocity = this->outShaftL.velocity + v25;
      v31 = this->outShaftR.velocity + v25;
    }
    this->outShaftR.velocity = v31;
LABEL_42:
    v32 = this->tractionType == AWD;
    v33 = (float *)this->car;
    v34 = v33 + 1885;
    v35 = v33 + 1477;
    v100 = v33 + 1069;
    v91 = v33 + 661;
    v36 = dt * ((float)((float)(v33[1885] + v33[1477]) + (float)(v33[1069] + v33[661])) / v15);
    this->rootVelocity = v18 * v36 + this->rootVelocity;
    this->drive.velocity = v36 + v95;
    if ( v32 )
    {
      v37 = v36 * 0.5 * v29;
LABEL_44:
      this->outShaftLF.velocity = v37 + this->outShaftLF.velocity;
      this->outShaftRF.velocity = v37 + this->outShaftRF.velocity;
LABEL_61:
      this->outShaftL.velocity = this->outShaftL.velocity + v37;
      this->outShaftR.velocity = this->outShaftR.velocity + v37;
      goto LABEL_62;
    }
LABEL_55:
    v20 = _xmm;
    goto LABEL_56;
  }
  v40 = this->acEngine.status.outTorque;
  *(double *)&result.name._Mysize = v40;
  if ( v18 != 0.0 )
  {
    v41 = dt * (v40 / v94);
    v42 = this->rootVelocity + v41;
    v43 = v41 / v18;
    this->rootVelocity = v42;
    v96 = this->drive.velocity + v43;
    this->drive.velocity = v96;
    if ( v12 == AWD )
    {
      v44 = this->awdFrontShare;
      v45 = v44 * v43 * 2.0;
      this->outShaftLF.velocity = this->outShaftLF.velocity + v45;
      this->outShaftRF.velocity = this->outShaftRF.velocity + v45;
      v46 = 1.0 - v44;
      v16 = DOUBLE_0_5;
      v47 = v46 * v43;
      v48 = DOUBLE_2_0;
      v49 = v47 * 2.0;
      this->outShaftL.velocity = this->outShaftL.velocity + v49;
      this->outShaftR.velocity = this->outShaftR.velocity + v49;
    }
    else
    {
      if ( this->diffType <= (unsigned int)Spool )
      {
        this->outShaftL.velocity = this->outShaftL.velocity + v43;
        this->outShaftR.velocity = this->outShaftR.velocity + v43;
      }
      v48 = DOUBLE_2_0;
    }
    v32 = this->tractionType == AWD;
    v50 = (float *)this->car;
    v34 = v50 + 1885;
    v35 = v50 + 1477;
    v100 = v50 + 1069;
    v91 = v50 + 661;
    v36 = dt * ((float)((float)(v50[1885] + v50[1477]) + (float)(v50[1069] + v50[661])) / v15);
    this->rootVelocity = v18 * v36 + this->rootVelocity;
    this->drive.velocity = v36 + v96;
    if ( v32 )
    {
      v37 = v36 * v16 * v48;
      goto LABEL_44;
    }
    goto LABEL_55;
  }
  v32 = this->tractionType == AWD;
  v51 = (float *)this->car;
  v34 = v51 + 1885;
  v35 = v51 + 1477;
  v100 = v51 + 1069;
  v91 = v51 + 661;
  this->rootVelocity = v40 / v94 * dt + this->rootVelocity;
  v37 = (float)((float)(v51[1885] + v51[1477]) + (float)(v51[1069] + v51[661])) / v15 * dt;
  this->drive.velocity = this->drive.velocity + v37;
  if ( v32 )
  {
    v37 = v37 * 0.5 * 2.0;
    goto LABEL_44;
  }
  if ( this->diffType <= (unsigned int)Spool )
    goto LABEL_61;
LABEL_62:
  v20 = _xmm;
LABEL_63:
  v52 = 1.0 - this->awdFrontShare;
  v53 = v52 * this->acEngine.status.outTorque;
  if ( v17 != 0.0 )
    v53 = -(v52 * v17);
  *(_QWORD *)&v54 = *(_QWORD *)&v18 & v20;
  *(_QWORD *)&v87 = *(_QWORD *)&v18 & v20;
  if ( v53 <= 0.0 )
    *(_QWORD *)&v55 = COERCE_UNSIGNED_INT64(this->awdRearDiff.coast * v53 * v54) & v20;
  else
    v55 = this->awdRearDiff.power * v53 * v54;
  v56 = this->outShaftR.velocity;
  v57 = dt
      * (COERCE_DOUBLE(COERCE_UNSIGNED_INT64(
                         (this->outShaftL.velocity - v56)
                       / (COERCE_DOUBLE(COERCE_UNSIGNED_INT64(this->outShaftL.velocity - v56) & _xmm)
                        + 0.1000000014901161)
                       * (this->awdRearDiff.preload + v55)) ^ _xmm)
       / this->outShaftL.inertia
       * 0.5);
  v58 = this->outShaftL.velocity + v57;
  v59 = v56 - v57;
  this->outShaftL.velocity = v58;
  this->outShaftR.velocity = v59;
  v60 = dt * ((float)(*v34 - *v35) / this->outShaftR.inertia * 0.5);
  this->outShaftR.velocity = v59 + v60;
  v61 = v58 - v60;
  v62 = this->awdFrontShare;
  this->outShaftL.velocity = v61;
  v63 = v62 * this->acEngine.status.outTorque;
  if ( v17 != 0.0 )
    v63 = -(v62 * v17);
  v64 = v87;
  if ( v63 <= 0.0 )
    *(_QWORD *)&v65 = COERCE_UNSIGNED_INT64(this->awdFrontDiff.coast * v63 * v87) & _xmm;
  else
    v65 = this->awdFrontDiff.power * v63 * v87;
  v66 = dt
      * (-((this->outShaftLF.velocity - this->outShaftRF.velocity)
         / (COERCE_DOUBLE(COERCE_UNSIGNED_INT64(this->outShaftLF.velocity - this->outShaftRF.velocity) & _xmm)
          + 0.1000000014901161)
         * (this->awdFrontDiff.preload + v65))
       / this->outShaftLF.inertia
       * 0.5);
  this->outShaftLF.velocity = this->outShaftLF.velocity + v66;
  this->outShaftRF.velocity = this->outShaftRF.velocity - v66;
  v67 = dt * ((float)(*v100 - *v91) / this->outShaftRF.inertia * 0.5);
  v97 = this->outShaftRF.velocity + v67;
  this->outShaftRF.velocity = v97;
  v88 = this->outShaftLF.velocity - v67;
  this->outShaftLF.velocity = v88;
  if ( v17 == 0.0 )
    v68 = *(double *)&result.name._Mysize;
  else
    v68 = -v17;
  if ( v68 <= 0.0 )
    *(_QWORD *)&v69 = COERCE_UNSIGNED_INT64(this->awdCenterDiff.coast * v68 * v64) & _xmm;
  else
    v69 = this->awdCenterDiff.power * v68 * v64;
  v70 = this->outShaftL.velocity;
  v71 = (this->outShaftR.velocity + v70) * 0.5 - (v88 + v97) * 0.5;
  v72 = 1.0 / (this->outShaftR.inertia + this->outShaftL.inertia + this->outShaftLF.inertia + this->outShaftR.inertia);
  v73 = dt
      * (-(v71 / (COERCE_DOUBLE(*(_QWORD *)&v71 & _xmm) + 0.1000000014901161) * (this->awdCenterDiff.preload + v69))
       * v72);
  v74 = v70 + v73;
  v75 = this->outShaftR.velocity + v73;
  this->outShaftLF.velocity = this->outShaftLF.velocity - v73;
  v76 = this->outShaftRF.velocity - v73;
  this->outShaftL.velocity = v74;
  this->outShaftR.velocity = v75;
  this->outShaftRF.velocity = v76;
  v77 = dt * ((float)((float)(*v34 + *v35) - (float)(*v100 + *v91)) * v72);
  this->outShaftL.velocity = v74 + v77;
  this->outShaftR.velocity = v75 + v77;
  this->outShaftLF.velocity = this->outShaftLF.velocity - v77;
  this->outShaftRF.velocity = this->outShaftRF.velocity - v77;
  if ( !v93 )
    this->engine.velocity = this->rootVelocity;
  if ( v18 != 0.0 )
  {
    v78 = this->rootVelocity / v18;
    v79 = this->drive.velocity;
    if ( COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v79 - v78) & _xmm) > 0.5 )
    {
      _printf("NOT GOOD, WE ARE STUFFED %f expected %f\n", v79, v78);
      v19 = dt;
    }
  }
  v80 = (float *)&result.name._Bx._Alias[8];
  v81 = this->outShaftLF.velocity;
  v82 = 0;
  v92 = &result.name._Bx._Alias[8];
  *(float *)&result.name._Bx._Alias[8] = v81;
  v83 = this->outShaftRF.velocity;
  *(float *)&result.name._Bx._Alias[12] = v83;
  *(float *)&v84 = this->outShaftL.velocity;
  result.name._Mysize = v84;
  *(float *)&result.name._Myres = this->outShaftR.velocity;
  do
  {
    this->car->tyres[v82].status.angularVelocity = *v80;
    Tyre::stepRotationMatrix(&this->car->tyres[v82], v19);
    v19 = dt;
    this->car->tyres[v82++].status.isLocked = 0;
    v80 = (float *)(v92 + 4);
    v92 += 4;
  }
  while ( v82 < 4 );
  v85 = this->ratio;
  v86 = (float)this->acEngine.status.outTorque * this->locClutch;
  if ( v85 == 0.0 )
    LODWORD(this->totalTorque) = LODWORD(v86) & _xmm;
  else
    LODWORD(this->totalTorque) = COERCE_UNSIGNED_INT(
                                   (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT(v85) & _xmm) * v86)
                                 - (float)((float)((float)(this->car->tyres[1].status.feedbackTorque
                                                         + this->car->tyres[0].status.feedbackTorque)
                                                 + this->car->tyres[2].status.feedbackTorque)
                                         + this->car->tyres[3].status.feedbackTorque)) & _xmm;
}
void Drivetrain::step4WD_new(Drivetrain *this, float dt)
{
  DynamicController *v3; // ecx
  double v4; // xmm2_8
  float v5; // xmm0_4
  Car *v6; // eax
  long double v7; // xmm4_8
  long double v8; // xmm1_8
  long double v9; // xmm3_8
  long double v10; // xmm2_8
  long double v11; // xmm1_8
  long double v12; // xmm3_8
  long double v13; // xmm2_8
  long double v14; // xmm1_8
  long double v15; // st7
  float v16; // xmm2_4
  double v17; // xmm5_8
  long double v18; // st7
  double v19; // xmm1_8
  bool v20; // zf
  double v21; // xmm3_8
  double v22; // xmm0_8
  long double v23; // xmm1_8
  double v24; // xmm1_8
  float *v25; // eax
  float v26; // xmm0_4
  int v27; // edi
  int v28; // xmm0_4
  float v29; // xmm0_4
  double v30; // xmm0_8
  float v31; // xmm2_4
  float v32; // xmm0_4
  double v33; // [esp+14h] [ebp-2Ch]
  double v34; // [esp+24h] [ebp-1Ch]
  int *v35; // [esp+28h] [ebp-18h]
  int v36[2]; // [esp+2Ch] [ebp-14h] BYREF
  long double v37; // [esp+34h] [ebp-Ch]

  Drivetrain::step2WD(this, dt);
  v3 = this->controllers.awd2._Myptr;
  v4 = ((this->outShaftL.velocity + this->outShaftR.velocity) * 0.5
      - (this->outShaftLF.velocity + this->outShaftRF.velocity) * 0.5)
     * this->awd2.ramp;
  v34 = v4;
  if ( v3 )
  {
    v4 = ((this->outShaftL.velocity + this->outShaftR.velocity) * 0.5
        - (this->outShaftLF.velocity + this->outShaftRF.velocity) * 0.5)
       * this->awd2.ramp;
    this->awd2.maxTorque = DynamicController::eval(v3);
  }
  if ( v4 <= this->awd2.maxTorque )
  {
    if ( -this->awd2.maxTorque <= v4 )
      goto LABEL_8;
    v4 = -this->awd2.maxTorque;
  }
  else
  {
    v4 = this->awd2.maxTorque;
  }
  v34 = v4;
LABEL_8:
  v5 = v4;
  v6 = this->car;
  this->awd2.currentLockTorque = v5;
  v7 = 1.0 / (this->outShaftRF.inertia + this->outShaftLF.inertia);
  v8 = v7 * v4 * dt;
  v9 = this->outShaftLF.velocity + v8;
  v10 = this->outShaftRF.velocity + v8;
  this->outShaftLF.velocity = v9;
  this->outShaftRF.velocity = v10;
  v11 = v6->tyres[0].status.feedbackTorque * v7 * dt;
  v12 = v9 + v11 + v11;
  v13 = v10 + v11 - v11;
  this->outShaftLF.velocity = v12;
  this->outShaftRF.velocity = v13;
  v14 = v6->tyres[1].status.feedbackTorque * v7 * dt;
  v33 = v12 + v14 - v14;
  this->outShaftLF.velocity = v33;
  v37 = v13 + v14 + v14;
  this->outShaftRF.velocity = v37;
  v15 = Drivetrain::getInertiaFromWheels(this);
  v16 = dt;
  v17 = this->ratio;
  v18 = v34 / v15 * dt;
  v19 = -v18;
  if ( v17 != 0.0 )
    this->rootVelocity = v17 * v19 + this->rootVelocity;
  v20 = this->tractionType == AWD;
  v21 = this->drive.velocity - v18;
  this->drive.velocity = v21;
  if ( v20 )
  {
    v19 = v19 * 0.5 * 2.0;
    this->outShaftLF.velocity = v19 + v33;
    this->outShaftRF.velocity = v19 + v37;
    v22 = v19 + this->outShaftL.velocity;
  }
  else
  {
    if ( this->diffType > (unsigned int)Spool )
      goto LABEL_15;
    v22 = this->outShaftL.velocity - v18;
  }
  v23 = v19 + this->outShaftR.velocity;
  this->outShaftL.velocity = v22;
  this->outShaftR.velocity = v23;
LABEL_15:
  if ( !this->clutchOpenState )
    this->engine.velocity = this->rootVelocity;
  if ( v17 != 0.0 )
  {
    v24 = this->rootVelocity / v17;
    if ( COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v21 - v24) & _xmm) > 0.5 )
    {
      _printf("NOT GOOD, WE ARE STUFFED %f expected %f\n", v21, v24);
      v16 = dt;
    }
  }
  v25 = (float *)v36;
  v26 = this->outShaftLF.velocity;
  v27 = 0;
  v35 = v36;
  *(float *)v36 = v26;
  *(float *)&v28 = this->outShaftRF.velocity;
  v36[1] = v28;
  v29 = this->outShaftL.velocity;
  *(float *)&v37 = v29;
  *((float *)&v37 + 1) = this->outShaftR.velocity;
  do
  {
    this->car->tyres[v27].status.angularVelocity = *v25;
    Tyre::stepRotationMatrix(&this->car->tyres[v27], v16);
    v16 = dt;
    this->car->tyres[v27++].status.isLocked = 0;
    v25 = (float *)++v35;
  }
  while ( v27 < 4 );
  v30 = this->ratio;
  if ( v30 == 0.0 )
  {
    LODWORD(this->totalTorque) = COERCE_UNSIGNED_INT((float)this->acEngine.status.outTorque * this->locClutch) & _xmm;
  }
  else
  {
    LODWORD(v31) = COERCE_UNSIGNED_INT(v30) & _xmm;
    v32 = this->acEngine.status.outTorque;
    LODWORD(this->totalTorque) = COERCE_UNSIGNED_INT(
                                   (float)(v31 * (float)(v32 * this->locClutch))
                                 - (float)((float)((float)(this->car->tyres[1].status.feedbackTorque
                                                         + this->car->tyres[0].status.feedbackTorque)
                                                 + this->car->tyres[2].status.feedbackTorque)
                                         + this->car->tyres[3].status.feedbackTorque)) & _xmm;
  }
}
void Drivetrain::step(Drivetrain *this, float dt)
{
  this->outShaftLF.oldVelocity = this->outShaftLF.velocity;
  this->outShaftRF.oldVelocity = this->outShaftRF.velocity;
  this->outShaftL.oldVelocity = this->outShaftL.velocity;
  this->outShaftR.oldVelocity = this->outShaftR.velocity;
  LODWORD(this->locClutch) = __libm_sse2_powf(this).m128_u32[0];
  this->currentClutchTorque = 0.0;
  Drivetrain::stepControllers(this, dt);
  switch ( this->tractionType )
  {
    case RWD:
    case FWD:
      Drivetrain::step2WD(this, dt);
      break;
    case AWD:
      Drivetrain::step4WD(this, dt);
      break;
    case AWD_NEW:
      Drivetrain::step4WD_new(this, dt);
      break;
    default:
      return;
  }
}
void Drivetrain::stepControllers(Drivetrain *this, float dt)
{
  DynamicController *v3; // ecx
  Car *v4; // ecx
  float v5; // xmm0_4
  float v6; // xmm0_4
  DynamicController *v7; // ecx
  float v8; // [esp+8h] [ebp-18h]
  float v9; // [esp+Ch] [ebp-14h]
  Speed result; // [esp+10h] [ebp-10h] BYREF
  int v11; // [esp+1Ch] [ebp-4h]

  v3 = this->controllers.awdFrontShare._Myptr;
  if ( v3 )
    this->awdFrontShare = DynamicController::eval(v3);
  if ( this->controllers.awdCenterLock._Myptr )
  {
    v4 = this->car;
    this->awdCenterDiff.power = 0.0;
    this->awdCenterDiff.coast = 0.0;
    v5 = Car::getSpeed(v4, &result)->value;
    v11 = 0;
    v8 = FLOAT_1_0;
    v6 = (float)((float)(v5 * 3.5999999) - 5.0) * 0.050000001;
    if ( v6 <= 1.0 )
    {
      if ( v6 >= 0.0 )
        v8 = v6;
      else
        v8 = 0.0;
    }
    v9 = DynamicController::eval(this->controllers.awdCenterLock._Myptr);
    v11 = -1;
    this->awdCenterDiff.preload = (float)((float)(v9 - 20.0) * v8) + 20.0;
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&result);
  }
  v7 = this->controllers.singleDiffLock._Myptr;
  if ( v7 )
  {
    this->diffCoastRamp = 0.0;
    this->diffPowerRamp = 0.0;
    this->diffPreLoad = DynamicController::eval(v7);
  }
}
void Drivetrain::Drivetrain(Drivetrain *this)
{
  this->isGearGrinding = 0;
  this->finalRatio = 1.0;
  this->engine.oldVelocity = 0.0;
  *(_OWORD *)&this->engine.velocity = 0i64;
  this->gears._Myfirst = 0;
  this->drive.oldVelocity = 0.0;
  *(_OWORD *)&this->drive.velocity = 0i64;
  this->gears._Mylast = 0;
  this->outShaftL.oldVelocity = 0.0;
  *(_OWORD *)&this->outShaftL.velocity = 0i64;
  this->gears._Myend = 0;
  this->outShaftR.oldVelocity = 0.0;
  *(_OWORD *)&this->outShaftR.velocity = 0i64;
  this->outShaftLF.oldVelocity = 0.0;
  *(_OWORD *)&this->outShaftLF.velocity = 0i64;
  this->outShaftRF.oldVelocity = 0.0;
  *(_OWORD *)&this->outShaftRF.velocity = 0i64;
  this->clutchOpenState = 0;
  this->ratio = 0.0;
  this->diffPowerRamp = 0.0;
  this->diffCoastRamp = 0.0;
  this->diffPreLoad = 0.0;
  this->diffType = LSD;
  this->cutOff = 0.0;
  Engine::Engine(&this->acEngine);
  this->isShifterSupported = 0;
  this->clutchMaxTorque = 0.0;
  this->totalTorque = 0.0;
  this->awdFrontShare = 0.1;
  this->awdFrontDiff.power = 0.0;
  this->awdFrontDiff.coast = 0.0;
  this->awdFrontDiff.preload = 0.0;
  this->awdFrontDiff.type = LSD;
  this->awdRearDiff.power = 0.0;
  this->awdRearDiff.coast = 0.0;
  this->awdRearDiff.preload = 0.0;
  this->awdRearDiff.type = LSD;
  this->awdCenterDiff.power = 0.0;
  this->awdCenterDiff.coast = 0.0;
  this->awdCenterDiff.preload = 0.0;
  this->awdCenterDiff.type = LSD;
  *(_WORD *)&this->downshiftProtection.isActive = 0;
  this->downshiftProtection.overrev = 0;
  this->downshiftProtection.lockN = 1;
  *(_OWORD *)&this->awd2.ramp = _xmm;
  this->awd2.currentLockTorque = 0.0;
  this->currentClutchTorque = 0.0;
  this->downshiftProtectionFunction._Impl = 0;
  this->evOnGearRequest.handlers._Myfirst = 0;
  this->evOnGearRequest.handlers._Mylast = 0;
  this->evOnGearRequest.handlers._Myend = 0;
  this->tyreLeft = 0;
  this->tyreRight = 0;
  this->gearRequest.request = eNoGearRequest;
  this->gearRequest.timeAccumulator = 0.0;
  this->gearRequest.timeout = DOUBLE_200_0;
  this->gearRequest.requestedGear = -1;
  this->wheelTorqueGenerators._Myfirst = 0;
  this->wheelTorqueGenerators._Mylast = 0;
  this->wheelTorqueGenerators._Myend = 0;
  *(_OWORD *)&this->damageRpmWindow = 0i64;
  this->controllers.awdFrontShare._Myptr = 0;
  this->controllers.awdCenterLock._Myptr = 0;
  this->controllers.singleDiffLock._Myptr = 0;
  this->controllers.awd2._Myptr = 0;
  this->clutchInertia = 1.0;
  this->locClutch = 1.0;
}
long double Drivetrain::getGearDnTime(Drivetrain *this)
{
  return this->gearDnTime;
}
