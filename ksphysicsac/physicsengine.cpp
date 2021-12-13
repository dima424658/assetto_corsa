#include "physicsengine.h"
void PhysicsEngine::setDynamicTempData(PhysicsEngine *this, DynamicTempData *data)
{
  DynamicTempData *v2; // esi
  float v3; // xmm0_4
  float *v4; // ebx
  DynamicTempData **v6; // eax
  float *v7; // ecx
  DynamicTempData **v8; // eax
  float v9; // xmm0_4

  v2 = data;
  v3 = data->baseAir;
  v4 = &data->baseAir;
  if ( v3 == 0.0 )
  {
    v6 = &data;
    data = (DynamicTempData *)1065353216;
    v7 = &v2->baseRoad;
    if ( v3 > 1.0 )
      v6 = (DynamicTempData **)v4;
    *(_DWORD *)v4 = *v6;
    v8 = &data;
    v9 = *v7;
    data = (DynamicTempData *)1065353216;
    if ( v9 > 1.0 )
      v8 = (DynamicTempData **)&v2->baseRoad;
    *(_DWORD *)v7 = *v8;
  }
  std::vector<float>::operator=(
    (std::vector<unsigned int> *)&this->dynamicTemp.temperatureCurve.references,
    (const std::vector<unsigned int> *)&v2->temperatureCurve.references);
  std::vector<float>::operator=(
    (std::vector<unsigned int> *)&this->dynamicTemp.temperatureCurve.values,
    (const std::vector<unsigned int> *)&v2->temperatureCurve.values);
  this->dynamicTemp.temperatureCurve.fastStep = v2->temperatureCurve.fastStep;
  this->dynamicTemp.temperatureCurve.cubicSplineReady = v2->temperatureCurve.cubicSplineReady;
  std::vector<CTData>::operator=(
    &this->dynamicTemp.temperatureCurve.cSpline.mElements,
    &v2->temperatureCurve.cSpline.mElements);
  if ( &this->dynamicTemp.temperatureCurve.filename != &v2->temperatureCurve.filename )
    std::wstring::assign(&this->dynamicTemp.temperatureCurve.filename, &v2->temperatureCurve.filename, 0, 0xFFFFFFFF);
  this->dynamicTemp.temperatureStartTime = v2->temperatureStartTime;
  this->dynamicTemp.baseRoad = v2->baseRoad;
  this->dynamicTemp.baseAir = *v4;
}
void PhysicsEngine::PhysicsEngine(PhysicsEngine *this)
{
  int v2; // esi
  bool v3; // bl
  bool v4; // bl
  double v5; // st7
  bool v6; // cf
  double v7; // st7
  bool v8; // bl
  IPhysicsCore *v9; // eax
  double v10; // st7
  IPhysicsCore *v11; // ecx
  signed int v12; // ebp
  ThreadPool *v13; // edx
  ThreadPool *v14; // eax
  ThreadPool *v15; // ecx
  std::function<void __cdecl(int)> v16; // [esp-18h] [ebp-E4h] BYREF
  int v17; // [esp+18h] [ebp-B4h]
  int v18; // [esp+1Ch] [ebp-B0h]
  unsigned int v19; // [esp+20h] [ebp-ACh]
  PhysicsEngine *v20; // [esp+28h] [ebp-A4h]
  std::wstring section; // [esp+30h] [ebp-9Ch] BYREF
  std::wstring key; // [esp+48h] [ebp-84h] BYREF
  std::wstring ifilename; // [esp+60h] [ebp-6Ch] BYREF
  INIReader ini; // [esp+78h] [ebp-54h] BYREF
  int v25; // [esp+C8h] [ebp-4h]

  v20 = this;
  v18 = 0;
  this->__vftable = (PhysicsEngine_vtbl *)&PhysicsEngine::`vftable';
  v25 = 0;
  this->cars._Myfirst = 0;
  this->cars._Mylast = 0;
  this->cars._Myend = 0;
  Concurrency::details::_Concurrent_queue_base_v4::_Concurrent_queue_base_v4(&this->eventQueue, 0x38u);
  this->eventQueue.__vftable = (Concurrency::concurrent_queue<ACPhysicsEvent,std::allocator<ACPhysicsEvent> >_vtbl *)&Concurrency::concurrent_queue<ACPhysicsEvent,std::allocator<ACPhysicsEvent>>::`vftable';
  this->evOnFlagEvent.handlers._Myfirst = 0;
  this->evOnFlagEvent.handlers._Mylast = 0;
  this->evOnFlagEvent.handlers._Myend = 0;
  this->evOnStepCompleted.handlers._Myfirst = 0;
  this->evOnStepCompleted.handlers._Mylast = 0;
  this->evOnStepCompleted.handlers._Myend = 0;
  this->evOnPreStep.handlers._Myfirst = 0;
  this->evOnPreStep.handlers._Mylast = 0;
  this->evOnPreStep.handlers._Myend = 0;
  this->evOnNewSessionPhysics.handlers._Myfirst = 0;
  this->evOnNewSessionPhysics.handlers._Mylast = 0;
  this->evOnNewSessionPhysics.handlers._Myend = 0;
  this->allowTyreBlankets = 1;
  this->fuelConsumptionRate = 1.0;
  this->tyreConsumptionRate = 1.0;
  this->penaltyMode = Nothing;
  this->penaltyRules.jumpStartPenaltyMode = eTeleportToPitMode;
  this->penaltyRules.basePitPenaltyLaps = 3;
  this->slipStreams._Myfirst = 0;
  this->slipStreams._Mylast = 0;
  this->slipStreams._Myend = 0;
  this->ambientTemperature = 26.0;
  this->roadTemperature = 32.0;
  this->mechanicalDamageRate = 1.0;
  *(_OWORD *)&this->physicsCPUTimes.carStep = 0i64;
  this->physicsCPUTimes.coreCPUTimes.contactPoints = 0;
  this->physicsCPUTimes.coreCPUTimes.collisionTime = 0.0;
  this->physicsCPUTimes.coreCPUTimes.narrowPhaseTests = 0;
  this->physicsCPUTimes.currentCPU = 0;
  this->flatSpotFFGain = 0.050000001;
  this->mzLowSpeedReduction.speedKMH = 3.0;
  this->mzLowSpeedReduction.minValue = 0.5;
  this->isEngineStallEnabled = 0;
  this->gyroWheelGain = 0.050000001;
  this->spinTorqueGain = 0.0099999998;
  this->damperMinValue = 0.0;
  this->damperGain = 1.0;
  this->wind.vector.x = 0.0;
  this->wind.vector.y = 0.0;
  this->wind.vector.z = 0.0;
  std::unique_ptr<AudioEvent>::unique_ptr<AudioEvent>(&this->wind.speed);
  this->wind.directionDeg = 0.0;
  this->sessionInfo.index = 0;
  this->sessionInfo.type = Undefined;
  *(_OWORD *)&this->sessionInfo.startTimeMS = 0i64;
  this->sessionInfo.laps = 0;
  this->stepCounter = 0;
  this->additionalPhysicsProviders._Myfirst = 0;
  this->additionalPhysicsProviders._Mylast = 0;
  this->additionalPhysicsProviders._Myend = 0;
  this->legalTyreList._Myfirst = 0;
  this->legalTyreList._Mylast = 0;
  this->legalTyreList._Myend = 0;
  this->pool._Myptr = 0;
  Curve::Curve(&this->dynamicTemp.temperatureCurve);
  this->dynamicTemp.baseRoad = 26.0;
  this->dynamicTemp.temperatureStartTime = 0.0;
  this->dynamicTemp.baseAir = 26.0;
  (&v16._Impl)[1] = (std::_Func_base<void,int> *)28;
  LOBYTE(v25) = 12;
  v16._Impl = (std::_Func_base<void,int> *)L"system/cfg/assetto_corsa.ini";
  this->isEngineStallEnabled = 1;
  this->lockGearboxAtStartTimeMS = 0.0;
  this->debugVisualizer = 0;
  this->allowedTyresOut = -1;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, (const wchar_t *)v16._Impl, (unsigned int)(&v16._Impl)[1]);
  LOBYTE(v25) = 13;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v25) = 15;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  v2 = -1;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  this->gyroWheelGain = 0.0;
  this->spinTorqueGain = 0.0;
  if ( ini.ready )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"FF_EXPERIMENTAL", 0xFu);
    LOBYTE(v25) = 16;
    v3 = INIReader::hasSection(&ini, &section);
    LOBYTE(v25) = 15;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v3 )
    {
      std::wstring::wstring(&key, L"ENABLE_GYRO");
      LOBYTE(v25) = 17;
      std::wstring::wstring(&section, L"FF_EXPERIMENTAL");
      LOBYTE(v25) = 18;
      v4 = INIReader::getInt(&ini, &section, &key) != 0;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v25) = 15;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      if ( v4 )
        this->gyroWheelGain = 0.0040000002;
    }
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DAMPER_MIN_LEVEL", 0x10u);
    LOBYTE(v25) = 19;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"FF_EXPERIMENTAL", 0xFu);
    LOBYTE(v25) = 20;
    v5 = INIReader::getFloat(&ini, &section, &key);
    v6 = section._Myres < 8;
    this->damperMinValue = v5;
    if ( !v6 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v25) = 15;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"DAMPER_GAIN", 0xBu);
    LOBYTE(v25) = 21;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"FF_EXPERIMENTAL", 0xFu);
    LOBYTE(v25) = 22;
    v7 = INIReader::getFloat(&ini, &section, &key);
    v6 = section._Myres < 8;
    this->damperGain = v7;
    if ( !v6 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v25) = 15;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"PHYSICS_THREADING", 0x11u);
    LOBYTE(v25) = 23;
    v8 = INIReader::hasSection(&ini, &key);
    LOBYTE(v25) = 15;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    if ( v8 )
    {
      std::wstring::wstring(&section, L"THREADS");
      LOBYTE(v25) = 24;
      std::wstring::wstring(&key, L"PHYSICS_THREADING");
      LOBYTE(v25) = 25;
      v2 = INIReader::getInt(&ini, &key, &section);
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      LOBYTE(v25) = 15;
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
    }
  }
  (&v16._Impl)[1] = (std::_Func_base<void,int> *)"******** Kunos Simulazioni Physics Engine ********\n";
  this->ambientTemperature = 26.0;
  this->roadTemperature = 30.0;
  this->validated = 0;
  _printf((const char *const)(&v16._Impl)[1]);
  ksPhysicsCoreODEFactory::create();
  this->core = v9;
  this->track = 0;
  v10 = ksGetTime();
  v11 = this->core;
  this->physicsTime = v10;
  v11->setCollisionCallback(v11, this);
  PhysicsEngine::initLowSpeedFF(this);
  v12 = ksGetNumberOfProcessors();
  _printf("LOGICAL CPU DETECTED: %d\n", v12);
  if ( v12 < 4 )
  {
    _printf("Multithreading disabled because <4 cores detected\n");
LABEL_30:
    _printf("INITIALISING PHYSICS SINGLE THREADED\n");
    goto LABEL_31;
  }
  if ( !v2 )
    goto LABEL_30;
  if ( v2 == -1 )
    v2 = v12 / 2;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"SET_THREAD_AFFINITY_MASK", 0x18u);
  LOBYTE(v25) = 26;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"THREADING", 9u);
  v25 = 27;
  v18 = 3;
  if ( !INIReader::getInt(&ini, &section, &key) || (HIBYTE(v17) = 1, (int)ksGetNumberOfProcessors() <= 4) )
    HIBYTE(v17) = 0;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  v25 = 15;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  _printf("INITIALISING PHYSICS THREAD POOL WITH %d THREADS\n", v2);
  v13 = (ThreadPool *)operator new(52);
  v18 = (int)v13;
  if ( v13 )
  {
    LOBYTE(v19) = HIBYTE(v17);
    v16._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_2e324f348e95b5616652a80a52abd18d_,0>,std::allocator<std::_Func_class<void,int>>,void,int>::`vftable';
    *(_QWORD *)&v16._Space._Alias[4] = __PAIR64__((unsigned int)this, v19);
    v16._Impl = (std::_Func_base<void,int> *)&v16;
    LOBYTE(v25) = 28;
    ThreadPool::ThreadPool(v13, v2, v16);
  }
  else
  {
    v14 = 0;
  }
  v15 = this->pool._Myptr;
  LOBYTE(v25) = 15;
  this->pool._Myptr = v14;
  if ( v15 )
    ((void (*)(ThreadPool *, int))v15->~ThreadPool)(v15, 1);
LABEL_31:
  LOBYTE(v25) = 12;
  INIReader::~INIReader(&ini);
}
void PhysicsEngine::~PhysicsEngine(PhysicsEngine *this)
{
  ThreadPool *v2; // ecx
  std::vector<std::wstring> *v3; // edi
  std::vector<ICarPhysicsStateProvider *> *v4; // edi
  std::vector<SlipStream *> *v5; // edi

  this->__vftable = (PhysicsEngine_vtbl *)&PhysicsEngine::`vftable';
  _printf("Destroying PhysicsEngine\n");
  this->core->release(this->core);
  Curve::~Curve(&this->dynamicTemp.temperatureCurve);
  v2 = this->pool._Myptr;
  if ( v2 )
    ((void (*)(ThreadPool *, int))v2->~ThreadPool)(v2, 1);
  v3 = &this->legalTyreList;
  if ( this->legalTyreList._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->legalTyreList);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(v3->_Myfirst, this->legalTyreList._Mylast);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    this->legalTyreList._Mylast = 0;
    this->legalTyreList._Myend = 0;
  }
  v4 = &this->additionalPhysicsProviders;
  if ( this->additionalPhysicsProviders._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->additionalPhysicsProviders);
    operator delete(v4->_Myfirst);
    v4->_Myfirst = 0;
    this->additionalPhysicsProviders._Mylast = 0;
    this->additionalPhysicsProviders._Myend = 0;
  }
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->wind.speed);
  v5 = &this->slipStreams;
  if ( this->slipStreams._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->slipStreams);
    operator delete(v5->_Myfirst);
    v5->_Myfirst = 0;
    this->slipStreams._Mylast = 0;
    this->slipStreams._Myend = 0;
  }
  if ( this->evOnNewSessionPhysics.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnNewSessionPhysics);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnNewSessionPhysics,
      (Task *)this->evOnNewSessionPhysics.handlers._Myfirst,
      (Task *)this->evOnNewSessionPhysics.handlers._Mylast);
    operator delete(this->evOnNewSessionPhysics.handlers._Myfirst);
    this->evOnNewSessionPhysics.handlers._Myfirst = 0;
    this->evOnNewSessionPhysics.handlers._Mylast = 0;
    this->evOnNewSessionPhysics.handlers._Myend = 0;
  }
  if ( this->evOnPreStep.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnPreStep);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnPreStep,
      (Task *)this->evOnPreStep.handlers._Myfirst,
      (Task *)this->evOnPreStep.handlers._Mylast);
    operator delete(this->evOnPreStep.handlers._Myfirst);
    this->evOnPreStep.handlers._Myfirst = 0;
    this->evOnPreStep.handlers._Mylast = 0;
    this->evOnPreStep.handlers._Myend = 0;
  }
  if ( this->evOnStepCompleted.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnStepCompleted);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnStepCompleted,
      (Task *)this->evOnStepCompleted.handlers._Myfirst,
      (Task *)this->evOnStepCompleted.handlers._Mylast);
    operator delete(this->evOnStepCompleted.handlers._Myfirst);
    this->evOnStepCompleted.handlers._Myfirst = 0;
    this->evOnStepCompleted.handlers._Mylast = 0;
    this->evOnStepCompleted.handlers._Myend = 0;
  }
  if ( this->evOnFlagEvent.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnFlagEvent);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnFlagEvent,
      (Task *)this->evOnFlagEvent.handlers._Myfirst,
      (Task *)this->evOnFlagEvent.handlers._Mylast);
    operator delete(this->evOnFlagEvent.handlers._Myfirst);
    this->evOnFlagEvent.handlers._Myfirst = 0;
    this->evOnFlagEvent.handlers._Mylast = 0;
    this->evOnFlagEvent.handlers._Myend = 0;
  }
  Concurrency::concurrent_queue<ACPhysicsEvent,std::allocator<ACPhysicsEvent>>::~concurrent_queue<ACPhysicsEvent,std::allocator<ACPhysicsEvent>>(&this->eventQueue);
  if ( this->cars._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->cars);
    operator delete(this->cars._Myfirst);
    this->cars._Myfirst = 0;
    this->cars._Mylast = 0;
    this->cars._Myend = 0;
  }
  this->__vftable = (PhysicsEngine_vtbl *)&ICollisionCallback::`vftable';
}
PhysicsEngine *PhysicsEngine::`scalar deleting destructor'(PhysicsEngine *this, unsigned int a2)
{
  PhysicsEngine::~PhysicsEngine(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void PhysicsEngine::addAdditionalPhysicsProvider(PhysicsEngine *this, ICarPhysicsStateProvider *p)
{
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->additionalPhysicsProviders,
    (ICollisionObject *const *)&p);
}
void PhysicsEngine::addLegalTyre(PhysicsEngine *this, const std::wstring *short_name)
{
  const std::wstring *v3; // eax

  if ( short_name->_Myres < 8 )
    v3 = short_name;
  else
    v3 = (const std::wstring *)short_name->_Bx._Ptr;
  _printf("Adding legal tyre:%S\n", v3->_Bx._Buf);
  std::vector<std::wstring>::push_back(&this->legalTyreList, short_name);
}
double PhysicsEngine::getAirDensity(PhysicsEngine *this)
{
  return 1.2922 - this->ambientTemperature * 0.0041;
}
IPhysicsCore *PhysicsEngine::getCore(PhysicsEngine *this)
{
  return this->core;
}
double PhysicsEngine::getOddTimeOffset(PhysicsEngine *this)
{
  return (double)(this->stepCounter % 3) + 0.0;
}
void PhysicsEngine::getPhysicsStates(PhysicsEngine *this, std::vector<CarPhysicsState> *states, std::vector<std::vector<WingState>> *wingStates)
{
  PhysicsEngine *v3; // edi
  unsigned int v4; // esi
  Car **v5; // esi
  int v6; // ecx
  int v7; // ebx
  unsigned int v8; // ebp
  Car *v9; // edi
  char *v10; // esi
  unsigned int v11; // ebp
  int v12; // ecx
  int v13; // ebx
  int v14; // edi
  int v15; // [esp+10h] [ebp-Ch]
  int v16; // [esp+10h] [ebp-Ch]
  int v17; // [esp+14h] [ebp-8h]
  int v18; // [esp+14h] [ebp-8h]

  v3 = this;
  v4 = this->cars._Mylast
     - this->cars._Myfirst
     + this->additionalPhysicsProviders._Mylast
     - this->additionalPhysicsProviders._Myfirst;
  if ( states->_Mylast - states->_Myfirst != v4 )
    std::vector<CarPhysicsState>::resize(
      states,
      this->cars._Mylast
    - this->cars._Myfirst
    + this->additionalPhysicsProviders._Mylast
    - this->additionalPhysicsProviders._Myfirst);
  if ( wingStates->_Mylast - wingStates->_Myfirst != v4 )
    std::vector<std::vector<LeaderboardEntry>>::resize(wingStates, v4);
  v5 = v3->cars._Myfirst;
  v6 = 0;
  v7 = 0;
  v8 = (unsigned int)((char *)v3->cars._Mylast - (char *)v5 + 3) >> 2;
  if ( v5 > v3->cars._Mylast )
    v8 = 0;
  if ( v8 )
  {
    v15 = 0;
    v17 = 0;
    do
    {
      v9 = *v5;
      Car::getPhysicsState(*v5, (CarPhysicsState *)((char *)states->_Myfirst + v6));
      Car::getWingState(v9, &wingStates->_Myfirst[v15]);
      ++v5;
      ++v15;
      ++v7;
      v6 = v17 + 2872;
      v17 += 2872;
    }
    while ( v7 != v8 );
    v3 = this;
  }
  v10 = (char *)v3->additionalPhysicsProviders._Myfirst;
  v16 = 0;
  v11 = (unsigned int)((char *)v3->additionalPhysicsProviders._Mylast - v10 + 3) >> 2;
  if ( (ICarPhysicsStateProvider **)v10 > v3->additionalPhysicsProviders._Mylast )
    v11 = 0;
  if ( v11 )
  {
    v12 = 2872 * v7;
    v13 = v7;
    v18 = v12;
    do
    {
      v14 = *(_DWORD *)v10;
      (*(void (**)(_DWORD, char *))(**(_DWORD **)v10 + 4))(
        *(_DWORD *)v10,
        (char *)&states->_Myfirst->physicsGUID + v12);
      (*(void (**)(int, std::vector<WingState> *))(*(_DWORD *)v14 + 8))(v14, &wingStates->_Myfirst[v13]);
      v10 += 4;
      v12 = v18 + 2872;
      ++v16;
      ++v13;
      v18 += 2872;
    }
    while ( v16 != v11 );
  }
}
BOOL PhysicsEngine::hasSessionStarted(PhysicsEngine *this, long double lag)
{
  return this->physicsTime > this->sessionInfo.startTimeMS + lag;
}
void PhysicsEngine::initLowSpeedFF(PhysicsEngine *this)
{
  bool v2; // bl
  double v3; // st7
  bool v4; // cf
  double v5; // st7
  double v6; // xmm0_8
  std::wstring section; // [esp+1Ch] [ebp-9Ch] BYREF
  std::wstring key; // [esp+34h] [ebp-84h] BYREF
  std::wstring ifilename; // [esp+4Ch] [ebp-6Ch] BYREF
  INIReader ini; // [esp+64h] [ebp-54h] BYREF
  int v11; // [esp+B4h] [ebp-4h]

  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/assetto_corsa.ini", 0x1Cu);
  v11 = 0;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v11) = 2;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"LOW_SPEED_FF", 0xCu);
    LOBYTE(v11) = 3;
    v2 = INIReader::hasSection(&ini, &section);
    LOBYTE(v11) = 2;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v2 )
    {
      std::wstring::wstring(&key, L"SPEED_KMH");
      LOBYTE(v11) = 4;
      std::wstring::wstring(&section, L"LOW_SPEED_FF");
      LOBYTE(v11) = 5;
      v3 = INIReader::getFloat(&ini, &section, &key);
      v4 = section._Myres < 8;
      this->mzLowSpeedReduction.speedKMH = v3;
      if ( !v4 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v11) = 2;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"MIN_VALUE");
      LOBYTE(v11) = 6;
      std::wstring::wstring(&section, L"LOW_SPEED_FF");
      LOBYTE(v11) = 7;
      v5 = INIReader::getFloat(&ini, &section, &key);
      v4 = section._Myres < 8;
      this->mzLowSpeedReduction.minValue = v5;
      if ( !v4 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      v6 = this->mzLowSpeedReduction.minValue;
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      _printf("USING FF LOW SPEED VALUES: %f kmh MIN_VALUE:%f\n", this->mzLowSpeedReduction.speedKMH, v6);
    }
  }
  v11 = -1;
  INIReader::~INIReader(&ini);
}
char PhysicsEngine::isTyreLegal(PhysicsEngine *this, const std::wstring *short_name)
{
  std::wstring *v2; // eax
  std::wstring *v4; // edi
  std::wstring *v5; // esi
  const std::wstring *v6; // eax

  v2 = this->legalTyreList._Myfirst;
  if ( v2 == this->legalTyreList._Mylast )
    return 1;
  v4 = this->legalTyreList._Mylast;
  v5 = this->legalTyreList._Myfirst;
  if ( v2 == v4 )
    return 0;
  while ( 1 )
  {
    v6 = short_name->_Myres < 8 ? short_name : short_name->_Bx._Ptr;
    if ( !std::wstring::compare(v5, 0, v5->_Mysize, v6->_Bx._Buf, short_name->_Mysize) )
      break;
    if ( ++v5 == v4 )
      return 0;
  }
  return 1;
}
void PhysicsEngine::onCollisionCallBack(PhysicsEngine *this, void *userData0, void *shape0, void *userData1, void *shape1, vec3f normal, vec3f pos, float depth)
{
  char v10; // bl
  Car **v11; // edx
  char v12; // cl
  Car **v13; // eax
  unsigned int v14; // esi
  int v15; // eax
  void *v16; // eax
  void *v17; // ebx
  void *v18; // edx
  Car **v19; // esi
  int v20; // edi
  __int128 v21; // [esp-Ch] [ebp-2Ch]
  int v22; // [esp+4h] [ebp-1Ch]
  char *v23; // [esp+14h] [ebp-Ch]
  void *v24; // [esp+14h] [ebp-Ch]
  PhysicsEngine *v25; // [esp+1Ch] [ebp-4h]
  void *userData1a; // [esp+2Ch] [ebp+Ch]
  char *shape1a; // [esp+30h] [ebp+10h]

  v23 = 0;
  v10 = 0;
  v11 = this->cars._Myfirst;
  v12 = 0;
  v25 = this;
  v13 = this->cars._Mylast;
  v14 = (unsigned int)((char *)v13 - (char *)v11 + 3) >> 2;
  if ( v11 > v13 )
    v14 = 0;
  if ( v14 )
  {
    userData1a = userData0;
    do
    {
      v15 = (int)*v11++;
      v16 = *(void **)(v15 + 152);
      if ( v16 == userData0 )
        v10 = 1;
      if ( v16 == userData1 )
        v12 = 1;
      ++v23;
    }
    while ( v23 != (char *)v14 );
    if ( v10 || !v12 )
    {
      v18 = userData0;
      v17 = shape0;
      v24 = shape1;
      goto LABEL_16;
    }
    v17 = shape1;
    v18 = userData1;
    userData1 = userData0;
    v24 = shape0;
  }
  else
  {
    v17 = shape0;
    v18 = userData0;
    v24 = shape1;
  }
  userData1a = v18;
LABEL_16:
  shape1a = 0;
  v19 = v25->cars._Myfirst;
  v20 = (unsigned int)((char *)v25->cars._Mylast - (char *)v19 + 3) >> 2;
  if ( v19 > v25->cars._Mylast )
    v20 = 0;
  if ( v20 )
  {
    do
    {
      *(_QWORD *)&v21 = *(_QWORD *)&pos.x;
      *((_QWORD *)&v21 + 1) = __PAIR64__(LODWORD(depth), LODWORD(pos.z));
      Car::onCollisionCallBack(*v19++, v20, v18, v17, userData1, v24, normal, v21, v22);
      v18 = userData1a;
      ++shape1a;
    }
    while ( shape1a != (char *)v20 );
  }
}
void PhysicsEngine::removeCar(PhysicsEngine *this, Car *c)
{
  Car **v3; // eax
  Car **v4; // edx

  v3 = this->cars._Myfirst;
  v4 = this->cars._Mylast;
  if ( v3 != v4 )
  {
    while ( *v3 != c )
    {
      if ( ++v3 == v4 )
        return;
    }
    _memmove(v3, v3 + 1, ((char *)this->cars._Mylast - (char *)(v3 + 1)) & 0xFFFFFFFC);
    --this->cars._Mylast;
  }
}
void PhysicsEngine::setCurrentSessionStartTime(PhysicsEngine *this, const long double new_start_time)
{
  this->sessionInfo.startTimeMS = new_start_time;
}
void PhysicsEngine::setSessionInfo(PhysicsEngine *this, const SessionInfo *info)
{
  *(__m128i *)&this->sessionInfo.type = _mm_loadu_si128((const __m128i *)info);
  *(__m128i *)&this->sessionInfo.timeSecs = _mm_loadu_si128((const __m128i *)&info->timeSecs);
  this->core->resetCollisions(this->core);
}
void PhysicsEngine::setWind(PhysicsEngine *this, Speed speed, float directionDEG)
{
  float v4; // xmm4_4
  float v5; // xmm6_4
  float v6; // xmm5_4
  float v7; // xmm0_4
  __int64 v8; // xmm2_8
  float v9; // xmm3_4
  __int64 v10; // xmm0_8
  float v11; // xmm4_4
  float v12; // xmm6_4
  float v13; // [esp+24h] [ebp-14h]
  __m128i v14; // [esp+28h] [ebp-10h] BYREF

  *(float *)&v14.m128i_i32[2] = __libm_sse2_cosf().m128_f32[0];
  v4 = __libm_sse2_sinf().m128_f32[0];
  v5 = (float)(1.0 - *(float *)&v14.m128i_i32[2]) * 0.0;
  v6 = (float)((float)(1.0 - *(float *)&v14.m128i_i32[2]) + *(float *)&v14.m128i_i32[2]) * 0.0;
  v7 = v4 * 0.0;
  *(float *)&v14.m128i_i32[2] = v5 + *(float *)&v14.m128i_i32[2];
  *(float *)&v14.m128i_i32[3] = (float)(v4 * 0.0) + v5;
  HIDWORD(v8) = 0;
  *(float *)&v8 = v5 - (float)(v4 * 0.0);
  v9 = *(float *)&v14.m128i_i32[3] * 0.0;
  v14.m128i_i64[0] = v8;
  *(float *)&v8 = (float)(v5 - v4) * 0.0;
  HIDWORD(v10) = v14.m128i_i32[1];
  v11 = (float)(v4 + v5) * speed.value;
  v12 = (float)(v5 - v7) * speed.value;
  *(float *)&v10 = (float)((float)(*(float *)v14.m128i_i32 * 0.0) + (float)(*(float *)&v14.m128i_i32[2] * 0.0)) + v11;
  v14.m128i_i64[0] = v10;
  *(float *)&v14.m128i_i32[3] = (float)((float)(*(float *)&v14.m128i_i32[3] * 0.0) + v6) + v12;
  *(float *)&v14.m128i_i32[2] = (float)(v9 + *(float *)&v8) + (float)(*(float *)&v14.m128i_i32[2] * speed.value);
  v13 = *(float *)&v14.m128i_i32[2];
  _printf("Setting wind %f kmh direction: %f deg\n", (float)(speed.value * 3.5999999), directionDEG);
  _printf(
    "%s: (%f , %f , %f)\n",
    "wind vector",
    *(float *)_mm_loadl_epi64(&v14).m128i_i32,
    *(float *)&v14.m128i_i32[3],
    *(float *)&v14.m128i_i32[2]);
  *(float *)&v10 = directionDEG;
  *(_QWORD *)&this->wind.vector.x = _mm_unpacklo_ps((__m128)_mm_loadl_epi64(&v14), (__m128)v14.m128i_u32[3]).m128_u64[0];
  this->wind.vector.z = v13;
  this->wind.speed.value = speed.value;
  LODWORD(this->wind.directionDeg) = v10;
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&speed);
}
void PhysicsEngine::step(PhysicsEngine *this, float dt, long double currentTime, long double gt)
{
  long double v5; // xmm0_8
  std::pair<void *,std::function<void __cdecl(double const &)> > *v6; // esi
  std::_Func_base<void,double const &> **v7; // edi
  double v8; // st7
  Car **v9; // esi
  int v10; // edi
  unsigned int v11; // ebp
  bool v12; // cc
  ThreadPool *v13; // edx
  Car **v14; // esi
  int v15; // ebp
  unsigned int v16; // edi
  unsigned int v17; // eax
  int v18; // ecx
  unsigned int v19; // edi
  unsigned int v20; // ebp
  int v21; // edi
  int v22; // ecx
  Car **v23; // eax
  int v24; // eax
  char *v25; // ecx
  __int64 v26; // xmm0_8
  int (__stdcall **v27)(int *); // eax
  int v28; // eax
  std::function<void __cdecl(void)> *v29; // esi
  int *v30; // esi
  int *v31; // ecx
  int (__stdcall **v32)(int *); // eax
  int v33; // eax
  unsigned int v34; // eax
  unsigned int i; // esi
  Task *v36; // eax
  Task *v37; // edi
  Task *v38; // eax
  std::_Func_base<void> **v39; // esi
  double v40; // st7
  IPhysicsCore *v41; // ecx
  float v42; // xmm0_4
  const __m128i *v43; // eax
  std::pair<void *,std::function<void __cdecl(double const &)> > *v44; // esi
  std::_Func_base<void,double const &> **v45; // edi
  int v46; // edi
  Car **v47; // ecx
  std::wstring *v48; // edi
  Car **v49; // ecx
  std::wstring *v50; // esi
  Car **v51; // ecx
  std::wstring *v52; // eax
  std::wstring *v53; // eax
  std::wstring *v54; // eax
  std::wstring *v55; // eax
  const std::wstring *v56; // eax
  Car **v57; // ecx
  std::wstring *v58; // esi
  Car **v59; // ecx
  std::wstring *v60; // eax
  std::wstring *v61; // eax
  const std::wstring *v62; // eax
  int j; // esi
  Car **v64; // ecx
  SurfaceDef *v65; // eax
  Speed *v66; // eax
  int v67; // ecx
  int v68; // eax
  Car *v69; // esi
  float *v70; // ecx
  std::wstring *v71; // eax
  const std::wstring *v72; // eax
  const std::wstring *v73; // eax
  std::wstring *v74; // eax
  const std::wstring *v75; // eax
  std::wstring *v76; // eax
  const std::wstring *v77; // eax
  char v78; // [esp+3Fh] [ebp-249h]
  std::vector<Task> tasks; // [esp+40h] [ebp-248h] BYREF
  unsigned int v80; // [esp+4Ch] [ebp-23Ch]
  unsigned int v81; // [esp+50h] [ebp-238h]
  unsigned int v82; // [esp+54h] [ebp-234h]
  Speed v83; // [esp+58h] [ebp-230h] BYREF
  char v84[16]; // [esp+5Ch] [ebp-22Ch] BYREF
  char *v85; // [esp+6Ch] [ebp-21Ch]
  int *v86; // [esp+74h] [ebp-214h]
  __int64 v87; // [esp+78h] [ebp-210h]
  char *v88; // [esp+84h] [ebp-204h]
  double v89; // [esp+88h] [ebp-200h]
  char v90[24]; // [esp+90h] [ebp-1F8h] BYREF
  volatile bool v91; // [esp+A8h] [ebp-1E0h]
  int v92[4]; // [esp+B0h] [ebp-1D8h] BYREF
  int *v93; // [esp+C0h] [ebp-1C8h]
  std::wstring v94; // [esp+C8h] [ebp-1C0h] BYREF
  std::wstring v95; // [esp+E0h] [ebp-1A8h] BYREF
  std::wstring v96; // [esp+F8h] [ebp-190h] BYREF
  std::wstring v97; // [esp+110h] [ebp-178h] BYREF
  std::wstring v98; // [esp+128h] [ebp-160h] BYREF
  std::wstring v99; // [esp+140h] [ebp-148h] BYREF
  std::wstring v100; // [esp+158h] [ebp-130h] BYREF
  std::wstring v101; // [esp+170h] [ebp-118h] BYREF
  std::wstring v102; // [esp+188h] [ebp-100h] BYREF
  std::wstring v103; // [esp+1A0h] [ebp-E8h] BYREF
  std::wstring v104; // [esp+1B8h] [ebp-D0h] BYREF
  std::wstring v105; // [esp+1D0h] [ebp-B8h] BYREF
  std::wstring v106; // [esp+1E8h] [ebp-A0h] BYREF
  std::wstring v107; // [esp+200h] [ebp-88h] BYREF
  std::wstring result; // [esp+218h] [ebp-70h] BYREF
  std::wstring v109; // [esp+230h] [ebp-58h] BYREF
  std::wstring v110; // [esp+248h] [ebp-40h] BYREF
  std::wstring v111; // [esp+260h] [ebp-28h] BYREF
  int v112; // [esp+284h] [ebp-4h]

  v81 = 0;
  if ( (dword_186F0D0 & 1) == 0 )
  {
    perfCounter_23.name = "PhysicsEngine::step";
    dword_186F0D0 |= 1u;
    perfCounter_23.group = Physics;
    perfCounter_23.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"PhysicsEngine::step" | 0xFF000000;
  }
  v5 = gt;
  ++this->stepCounter;
  this->gameTime = v5;
  this->physicsTime = currentTime;
  v6 = this->evOnPreStep.handlers._Myfirst;
  if ( v6 != this->evOnPreStep.handlers._Mylast )
  {
    v7 = &v6->second._Impl;
    do
    {
      if ( !*v7 )
        goto LABEL_17;
      (*v7)->_Do_call(*v7, &currentTime);
      ++v6;
      v7 += 8;
    }
    while ( v6 != this->evOnPreStep.handlers._Mylast );
  }
  Track::step(this->track, dt);
  PhysicsEngine::stepWind(this, dt);
  v8 = ksGetQPTTime();
  v9 = this->cars._Myfirst;
  v10 = 0;
  v11 = (unsigned int)((char *)this->cars._Mylast - (char *)v9 + 3) >> 2;
  v12 = v9 <= this->cars._Mylast;
  v89 = v8;
  if ( !v12 )
    v11 = 0;
  if ( v11 )
  {
    do
    {
      Car::stepPreCacheValues(*v9, dt);
      ++v10;
      ++v9;
    }
    while ( v10 != v11 );
  }
  v13 = this->pool._Myptr;
  if ( v13 )
    goto $LN1223;
  v14 = this->cars._Myfirst;
  v15 = 0;
  v16 = (unsigned int)((char *)this->cars._Mylast - (char *)v14 + 3) >> 2;
  if ( v14 > this->cars._Mylast )
    v16 = 0;
  if ( v16 )
  {
    do
    {
      Car::step(*v14, (int)v14, dt);
      ++v15;
      ++v14;
    }
    while ( v15 != v16 );
  }
  while ( 1 )
  {
    v40 = ksGetQPTTime();
    v41 = this->core;
    v42 = dt;
    this->physicsCPUTimes.carStep = v40 - v89;
    v41->step(v41, COERCE_FLOAT(LODWORD(v42)));
    v43 = (const __m128i *)this->core->getCoreCPUTimes(this->core, v90);
    *(__m128i *)&this->physicsCPUTimes.coreCPUTimes.solverTime = _mm_loadu_si128(v43);
    *(_QWORD *)&this->physicsCPUTimes.coreCPUTimes.contactPoints = v43[1].m128i_i64[0];
    v44 = this->evOnStepCompleted.handlers._Myfirst;
    if ( v44 == this->evOnStepCompleted.handlers._Mylast )
      break;
    v45 = &v44->second._Impl;
    while ( *v45 )
    {
      (*v45)->_Do_call(*v45, &this->physicsTime);
      ++v44;
      v45 += 8;
      if ( v44 == this->evOnStepCompleted.handlers._Mylast )
        goto LABEL_57;
    }
LABEL_17:
    std::_Xbad_function_call();
$LN1223:
    tasks._Myfirst = 0;
    tasks._Mylast = 0;
    tasks._Myend = 0;
    v17 = (this->cars._Mylast - this->cars._Myfirst) / (unsigned int)(v13->workers._Mylast - v13->workers._Myfirst);
    v18 = this->cars._Mylast - this->cars._Myfirst;
    v112 = 0;
    v19 = v17 + 1;
    v80 = v17 + 1;
    std::vector<Task>::resize(&tasks, v18 - (v17 + 1));
    v20 = 0;
    if ( this->cars._Mylast - this->cars._Myfirst != v19 )
    {
      v21 = 0;
      v88 = v84;
      v22 = 4 * v80;
      v82 = 4 * v80;
      while ( 1 )
      {
        v23 = this->cars._Myfirst;
        LODWORD(v87) = v20;
        v85 = 0;
        HIDWORD(v87) = *(Car **)((char *)v23 + v22);
        LOBYTE(v112) = 1;
        v24 = operator new(20);
        v25 = (char *)v24;
        if ( !v24 )
          break;
        v26 = v87;
        *(_DWORD *)v24 = &std::_Func_impl<std::_Callable_obj<_lambda_044fc942b21b790926a874e6db5381f1_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
        *(_QWORD *)(v24 + 4) = v26;
        *(_DWORD *)(v24 + 12) = &dt;
        v85 = (char *)v24;
        v93 = 0;
        v86 = v92;
        LOBYTE(v112) = 3;
        v27 = *(int (__stdcall ***)(int *))v24;
        if ( v25 == v84 )
          v28 = (*v27)(v92);
        else
          v28 = (*v27)(0);
        v93 = (int *)v28;
        v91 = 0;
        LOBYTE(v112) = 0;
        if ( v85 )
        {
          (*(void (__stdcall **)(bool))(*(_DWORD *)v85 + 16))(v85 != v84);
          v85 = 0;
        }
        LOBYTE(v112) = 4;
        v29 = &tasks._Myfirst->function;
        tasks._Myfirst[v21].isDone = v91;
        v30 = (int *)((char *)v29 + v21 * 32);
        if ( v30 != v92 )
        {
          v31 = (int *)v30[4];
          if ( v31 )
          {
            (*(void (__stdcall **)(bool))(*v31 + 16))(v31 != v30);
            v30[4] = 0;
          }
          if ( v93 )
          {
            v32 = (int (__stdcall **)(int *))*v93;
            if ( v93 == v92 )
              v33 = (*v32)(v30);
            else
              v33 = (*v32)(0);
            v30[4] = v33;
          }
          else
          {
            v30[4] = 0;
          }
        }
        LOBYTE(v112) = 0;
        if ( v93 )
          (*(void (__stdcall **)(bool))(*v93 + 16))(v93 != v92);
        ThreadPool::addTask(this->pool._Myptr, &tasks._Myfirst[v21]);
        ++v20;
        ++v21;
        v22 = v82 + 4;
        v34 = this->cars._Mylast - this->cars._Myfirst - v80;
        v82 += 4;
        if ( v20 >= v34 )
        {
          v19 = v80;
          goto LABEL_39;
        }
      }
      std::_Xbad_alloc();
$LN1225:
      v57 = this->cars._Myfirst;
      if ( (*v57)->transponder.lapCount > 3 )
      {
        v58 = std::to_wstring(
                &v110,
                (float)((*v57)->fuelLapEvaluator.totalM * 0.001 / (*v57)->fuelLapEvaluator.totalLiters)
              * (*v57)->maxFuel);
        v59 = this->cars._Myfirst;
        v112 = 12;
        v60 = std::operator+<wchar_t>(&v102, L"\n", &(*v59)->unixName);
        LOBYTE(v112) = 13;
        v61 = std::operator+<wchar_t>(&v106, v60, L"|");
        LOBYTE(v112) = 14;
        v62 = std::operator+<wchar_t>(&v100, v61, v58);
        LOBYTE(v112) = 15;
        PhysicsEngine::writeTestResult(this, v62);
        if ( v100._Myres >= 8 )
          operator delete(v100._Bx._Ptr);
        v100._Myres = 7;
        v100._Mysize = 0;
        v100._Bx._Buf[0] = 0;
        if ( v106._Myres >= 8 )
          operator delete(v106._Bx._Ptr);
        v106._Myres = 7;
        v106._Mysize = 0;
        v106._Bx._Buf[0] = 0;
        if ( v102._Myres >= 8 )
          operator delete(v102._Bx._Ptr);
        v102._Myres = 7;
        v102._Mysize = 0;
        v102._Bx._Buf[0] = 0;
        if ( v110._Myres >= 8 )
          operator delete(v110._Bx._Ptr);
        v110._Myres = 7;
        v110._Mysize = 0;
        v110._Bx._Buf[0] = 0;
        _exit(0);
      }
      return;
    }
LABEL_39:
    for ( i = 0; i < v19; ++i )
      Car::step(this->cars._Myfirst[i], i, dt);
    v36 = tasks._Myfirst;
    if ( tasks._Myfirst != tasks._Mylast )
    {
      do
      {
        while ( !v36->isDone )
          ;
        ++v36;
      }
      while ( v36 != tasks._Mylast );
      v36 = tasks._Myfirst;
    }
    v112 = -1;
    if ( v36 )
    {
      std::_Container_base0::_Orphan_all(&tasks);
      v37 = tasks._Mylast;
      v38 = tasks._Myfirst;
      if ( tasks._Myfirst != tasks._Mylast )
      {
        v39 = &tasks._Myfirst->function._Impl;
        do
        {
          if ( *v39 )
          {
            ((void (__stdcall *)(bool))(*v39)->_Delete_this)(*v39 != (std::_Func_base<void> *)(v39 - 4));
            *v39 = 0;
          }
          v39 += 8;
        }
        while ( v39 - 6 != (std::_Func_base<void> **)v37 );
        v38 = tasks._Myfirst;
      }
      operator delete(v38);
    }
  }
LABEL_57:
  this->physicsCPUTimes.currentCPU = 0;
  if ( !PhysicsEngine::isTestMode )
    return;
  v46 = 0;
  if ( PhysicsEngine::testMode )
  {
    if ( PhysicsEngine::testMode != CarRange )
    {
      if ( PhysicsEngine::testMode == BestLap )
      {
        v47 = this->cars._Myfirst;
        if ( (*v47)->transponder.lapCount > 1 )
        {
          v48 = std::to_wstring(&result, (*v47)->transponder.bestLap);
          v49 = this->cars._Myfirst;
          v112 = 16;
          v50 = timeToString(&v98, (*v49)->transponder.bestLap, 3);
          v51 = this->cars._Myfirst;
          LOBYTE(v112) = 17;
          v52 = std::operator+<wchar_t>(&v94, L"\n", &(*v51)->unixName);
          LOBYTE(v112) = 18;
          v53 = std::operator+<wchar_t>(&v96, v52, L"|");
          LOBYTE(v112) = 19;
          v54 = std::operator+<wchar_t>(&v111, v53, v50);
          LOBYTE(v112) = 20;
          v55 = std::operator+<wchar_t>(&v109, v54, L"|");
          LOBYTE(v112) = 21;
          v56 = std::operator+<wchar_t>(&v104, v55, v48);
          LOBYTE(v112) = 22;
          PhysicsEngine::writeTestResult(this, v56);
          if ( v104._Myres >= 8 )
            operator delete(v104._Bx._Ptr);
          v104._Myres = 7;
          v104._Mysize = 0;
          v104._Bx._Buf[0] = 0;
          if ( v109._Myres >= 8 )
            operator delete(v109._Bx._Ptr);
          v109._Myres = 7;
          v109._Mysize = 0;
          v109._Bx._Buf[0] = 0;
          if ( v111._Myres >= 8 )
            operator delete(v111._Bx._Ptr);
          v111._Myres = 7;
          v111._Mysize = 0;
          v111._Bx._Buf[0] = 0;
          if ( v96._Myres >= 8 )
            operator delete(v96._Bx._Ptr);
          v96._Myres = 7;
          v96._Mysize = 0;
          v96._Bx._Buf[0] = 0;
          if ( v94._Myres >= 8 )
            operator delete(v94._Bx._Ptr);
          v94._Myres = 7;
          v94._Mysize = 0;
          v94._Bx._Buf[0] = 0;
          if ( v98._Myres >= 8 )
            operator delete(v98._Bx._Ptr);
          v98._Myres = 7;
          v98._Mysize = 0;
          v98._Bx._Buf[0] = 0;
          if ( result._Myres >= 8 )
            operator delete(result._Bx._Ptr);
          result._Myres = 7;
          result._Mysize = 0;
          result._Bx._Buf[0] = 0;
          _exit(0);
        }
      }
      return;
    }
    goto $LN1225;
  }
  for ( j = 0; j < 4; ++j )
  {
    v64 = this->cars._Myfirst;
    v65 = (*v64)->tyres[j].surfaceDef;
    if ( v65 && !v65->isValidTrack )
      ++v46;
    v66 = Car::getSpeed(*v64, &v83);
    v67 = v81 | 1;
    v81 |= 1u;
    if ( (float)(v66->value * 3.5999999) <= 20.0
      || (v78 = 1, (*this->cars._Myfirst)->tyres[j].status.slipAngleRAD <= 0.78538501) )
    {
      v78 = 0;
    }
    if ( (v67 & 1) != 0 )
    {
      v81 = v67 & 0xFFFFFFFE;
      dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v83);
    }
    if ( v78 )
    {
      v76 = std::to_wstring(&v107, (*this->cars._Myfirst)->splineLocatorData.npos);
      v112 = 5;
      v77 = std::operator+<wchar_t>(&v105, L"FAIL|HIGH SLIP|", v76);
      LOBYTE(v112) = 6;
      PhysicsEngine::writeTestResult(this, v77);
      if ( v105._Myres >= 8 )
        operator delete(v105._Bx._Ptr);
      v105._Myres = 7;
      v105._Mysize = 0;
      v105._Bx._Buf[0] = 0;
      if ( v107._Myres >= 8 )
        operator delete(v107._Bx._Ptr);
      v107._Myres = 7;
      v107._Mysize = 0;
      v107._Bx._Buf[0] = 0;
      _exit(0);
    }
  }
  v68 = 0;
  v69 = *this->cars._Myfirst;
  v70 = v69->damageZoneLevel;
  do
  {
    if ( *v70 > 0.0 )
    {
      v74 = std::to_wstring(&v103, v69->splineLocatorData.npos);
      v112 = 7;
      v75 = std::operator+<wchar_t>(&v101, L"FAIL|DAMAGE|", v74);
      LOBYTE(v112) = 8;
      PhysicsEngine::writeTestResult(this, v75);
      if ( v101._Myres >= 8 )
        operator delete(v101._Bx._Ptr);
      v101._Myres = 7;
      v101._Mysize = 0;
      v101._Bx._Buf[0] = 0;
      if ( v103._Myres >= 8 )
        operator delete(v103._Bx._Ptr);
      v103._Myres = 7;
      v103._Mysize = 0;
      v103._Bx._Buf[0] = 0;
      _exit(0);
    }
    ++v68;
    ++v70;
  }
  while ( v68 < 5 );
  if ( v46 > 3 )
  {
    v71 = std::to_wstring(&v97, v69->splineLocatorData.npos);
    v112 = 9;
    v72 = std::operator+<wchar_t>(&v95, L"FAIL|TYRES OUT|", v71);
    LOBYTE(v112) = 10;
    PhysicsEngine::writeTestResult(this, v72);
    if ( v95._Myres >= 8 )
      operator delete(v95._Bx._Ptr);
    v95._Myres = 7;
    v95._Mysize = 0;
    v95._Bx._Buf[0] = 0;
    if ( v97._Myres >= 8 )
      operator delete(v97._Bx._Ptr);
    v97._Myres = 7;
    v97._Mysize = 0;
    v97._Bx._Buf[0] = 0;
    _exit(0);
  }
  if ( v69->transponder.lapCount > 1 )
  {
    v73 = timeToString(&v99, v69->transponder.bestLap, 3);
    v112 = 11;
    PhysicsEngine::writeTestResult(this, v73);
    if ( v99._Myres >= 8 )
      operator delete(v99._Bx._Ptr);
    v99._Myres = 7;
    v99._Mysize = 0;
    v99._Bx._Buf[0] = 0;
    _exit(0);
  }
}
void PhysicsEngine::stepPaused(PhysicsEngine *this)
{
  ICarControlsProvider *v1; // eax
  ICarControlsProvider *v2; // esi
  ICarControlsProvider_vtbl *v3; // edx
  __int128 v4; // [esp+14h] [ebp-14h] BYREF
  int v5; // [esp+24h] [ebp-4h]

  v1 = Car::getControlsProvider(*this->cars._Myfirst);
  v2 = v1;
  if ( v1 )
  {
    v3 = v1->__vftable;
    v5 = 0;
    v4 = 0i64;
    v3->setVibrations(v1, (const VibrationDef *)&v4);
    ((void (*)(ICarControlsProvider *, _DWORD, _DWORD, _DWORD))v2->sendFF)(v2, 0, 0, 0);
  }
}
void PhysicsEngine::stepWind(PhysicsEngine *this, float dt)
{
  float v3; // xmm0_4
  float v4; // eax
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm0_4
  float v9; // eax
  Speed new_speed; // [esp+Ch] [ebp-1Ch] BYREF
  float Px; // [esp+10h] [ebp-18h] BYREF
  float v12; // [esp+14h] [ebp-14h] BYREF
  float v13; // [esp+18h] [ebp-10h] BYREF
  vec3f nv; // [esp+1Ch] [ebp-Ch]

  if ( this->wind.speed.value >= 0.0099999998 )
  {
    v3 = *(double *)__libm_sse2_sin().m128_u64;
    Speed::operator*(&this->wind.speed, &new_speed, (float)(v3 * 0.1) + 1.0);
    v4 = this->wind.vector.z;
    *(_QWORD *)&nv.x = *(_QWORD *)&this->wind.vector.x;
    v5 = nv.x;
    v6 = nv.y;
    nv.z = v4;
    v7 = v4;
    v8 = fsqrt((float)((float)(v5 * v5) + (float)(v6 * v6)) + (float)(v7 * v7));
    if ( v8 != 0.0 )
    {
      v5 = (float)(1.0 / v8) * nv.x;
      v6 = (float)(1.0 / v8) * nv.y;
      v7 = (float)(1.0 / v8) * v4;
    }
    nv.x = new_speed.value * v5;
    v12 = new_speed.value * v6;
    nv.y = new_speed.value * v6;
    v13 = new_speed.value * v7;
    nv.z = new_speed.value * v7;
    Px = new_speed.value * v5;
    if ( __fdtest(&Px) <= 0 && __fdtest(&v12) <= 0 && __fdtest(&v13) <= 0 )
    {
      v9 = nv.z;
      *(_QWORD *)&this->wind.vector.x = *(_QWORD *)&nv.x;
      this->wind.vector.z = v9;
    }
    dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&new_speed);
  }
}
void PhysicsEngine::writeTestResult(PhysicsEngine *this, const std::wstring *result)
{
  std::wstring *v2; // eax
  std::wstring *v3; // eax
  bool v4; // cf
  bool v5; // zf
  int v6; // eax
  const std::string *v7; // eax
  std::wstring *v8; // eax
  std::wstring *v9; // eax
  int v10; // eax
  const std::string *v11; // eax
  std::ofstream file; // [esp+8h] [ebp-148h] BYREF
  std::wstring v13; // [esp+B0h] [ebp-A0h] BYREF
  std::wstring v14; // [esp+C8h] [ebp-88h] BYREF
  std::wstring v15; // [esp+E0h] [ebp-70h] BYREF
  std::wstring v16; // [esp+F8h] [ebp-58h] BYREF
  std::string v17; // [esp+110h] [ebp-40h] BYREF
  std::string v18; // [esp+128h] [ebp-28h] BYREF
  int v19; // [esp+14Ch] [ebp-4h]

  std::ofstream::ofstream(&file, 1);
  v19 = 0;
  if ( PhysicsEngine::testMode )
  {
    v2 = Path::getDocumentPath(&v15);
    LOBYTE(v19) = 4;
    v3 = std::operator+<wchar_t>(&v14, v2, L"/Assetto Corsa/out/test_result.txt");
    v4 = v3->_Myres < 8;
    LOBYTE(v19) = 5;
    if ( !v4 )
      v3 = (std::wstring *)v3->_Bx._Ptr;
    v5 = std::filebuf::open((std::filebuf *)&file.gap0[4], v3->_Bx._Buf, 10, 64) == 0;
    v6 = *(_DWORD *)(*(_DWORD *)file.gap0 + 4);
    if ( v5 )
      std::ios::setstate((char *)&file + v6, 2, 0);
    else
      std::ios::clear((char *)&file + v6, 0, 0);
    if ( v14._Myres >= 8 )
      operator delete(v14._Bx._Ptr);
    v14._Myres = 7;
    v14._Mysize = 0;
    v14._Bx._Buf[0] = 0;
    LOBYTE(v19) = 0;
    if ( v15._Myres >= 8 )
      operator delete(v15._Bx._Ptr);
    v15._Myres = 7;
    v15._Bx._Buf[0] = 0;
    v15._Mysize = 0;
    v7 = wstring2string(&v17, result);
    LOBYTE(v19) = 6;
    std::operator<<<char>(&file, v7);
    if ( v17._Myres >= 0x10 )
      operator delete(v17._Bx._Ptr);
  }
  else
  {
    v8 = Path::getDocumentPath(&v13);
    LOBYTE(v19) = 1;
    v9 = std::operator+<wchar_t>(&v16, v8, L"/Assetto Corsa/out/test_result.txt");
    v4 = v9->_Myres < 8;
    LOBYTE(v19) = 2;
    if ( !v4 )
      v9 = (std::wstring *)v9->_Bx._Ptr;
    v5 = std::filebuf::open((std::filebuf *)&file.gap0[4], v9->_Bx._Buf, 2, 64) == 0;
    v10 = *(_DWORD *)(*(_DWORD *)file.gap0 + 4);
    if ( v5 )
      std::ios::setstate((char *)&file + v10, 2, 0);
    else
      std::ios::clear((char *)&file + v10, 0, 0);
    if ( v16._Myres >= 8 )
      operator delete(v16._Bx._Ptr);
    v16._Myres = 7;
    v16._Mysize = 0;
    v16._Bx._Buf[0] = 0;
    LOBYTE(v19) = 0;
    if ( v13._Myres >= 8 )
      operator delete(v13._Bx._Ptr);
    v13._Myres = 7;
    v13._Bx._Buf[0] = 0;
    v13._Mysize = 0;
    v11 = wstring2string(&v18, result);
    LOBYTE(v19) = 3;
    std::operator<<<char>(&file, v11);
    if ( v18._Myres >= 0x10 )
      operator delete(v18._Bx._Ptr);
  }
  std::ofstream::~ofstream<char,std::char_traits<char>>((std::ofstream *)&file.gap58[8]);
  std::ios::~ios<char,std::char_traits<char>>(&file.gap58[8]);
}
