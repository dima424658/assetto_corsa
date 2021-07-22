#include "physicsavatar.h
void PhysicsAvatar::PhysicsAvatar(PhysicsAvatar *this, Sim *isim)
{
  Event<OnNewSessionEvent> *v3; // ecx
  std::wstring v4; // [esp-1Ch] [ebp-50h] BYREF
  Game *v5; // [esp-4h] [ebp-38h]
  PhysicsAvatar *v6; // [esp+24h] [ebp-10h]
  int v7; // [esp+30h] [ebp-4h]

  v6 = this;
  v5 = isim->game;
  v4._Myres = 7;
  v4._Mysize = 0;
  v4._Bx._Buf[0] = 0;
  std::wstring::assign(&v4, L"PHYSICS_AVATAR", 0xEu);
  GameObject::GameObject(this, v4, v5);
  v7 = 0;
  this->__vftable = (PhysicsAvatar_vtbl *)&PhysicsAvatar::`vftable';
  PhysicsEngine::PhysicsEngine(&this->engine);
  this->evOnStepCompleted.handlers._Myfirst = 0;
  this->evOnStepCompleted.handlers._Mylast = 0;
  this->evOnStepCompleted.handlers._Myend = 0;
  this->evOnFlagEvent.handlers._Myfirst = 0;
  this->evOnFlagEvent.handlers._Mylast = 0;
  this->evOnFlagEvent.handlers._Myend = 0;
  LOBYTE(v7) = 3;
  this->occupancy = 0;
  this->cpuTimeMS = 1.0;
  this->useMatrixSmoothing = 1;
  this->physicsLateLoops = 0;
  std::unique_ptr<AudioEvent>::unique_ptr<AudioEvent>(&this->windData.speed);
  this->windData.directionDEG = 0.0;
  LOBYTE(v7) = 4;
  Concurrency::details::_Concurrent_queue_base_v4::_Concurrent_queue_base_v4(&this->commandQueue, 0x18u);
  this->commandQueue.__vftable = (Concurrency::concurrent_queue<std::function<void __cdecl(void)>,std::allocator<std::function<void __cdecl(void)> > >_vtbl *)&Concurrency::concurrent_queue<std::function<void __cdecl (void)>,std::allocator<std::function<void __cdecl (void)>>>::`vftable';
  v5 = isim->game;
  LOBYTE(v7) = 5;
  PhysicsDriveThread::PhysicsDriveThread(&this->driveThread, &this->engine, v5);
  this->timeMult = 1.0;
  this->isPaused = 1;
  this->sim = isim;
  this->temperatureInfo.ambientTemperature = 26.0;
  this->temperatureInfo.roadTemperature = 32.0;
  v5 = (Game *)&this->mutex;
  this->temperatureInfoPT.ambientTemperature = 26.0;
  this->temperatureInfoPT.roadTemperature = 32.0;
  InitializeCriticalSection((LPCRITICAL_SECTION)v5);
  this->currentStates._Myfirst = 0;
  this->currentStates._Mylast = 0;
  this->currentStates._Myend = 0;
  this->wingStates._Myfirst = 0;
  this->wingStates._Mylast = 0;
  this->wingStates._Myend = 0;
  this->dynamicTrackStatus.enabled = 0;
  this->dynamicTrackStatus.currentGripLevel = 1.0;
  this->dynamicTrackStatusPT.enabled = 0;
  this->dynamicTrackStatusPT.currentGripLevel = 1.0;
  this->penaltyRecords._Myfirst = 0;
  this->penaltyRecords._Mylast = 0;
  this->penaltyRecords._Myend = 0;
  v5 = (Game *)this;
  this->occupancy = 0;
  this->isPaused = 0;
  v4._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_650280e6ffaef14c009f2a60cf07fae3_,0>,std::allocator<std::_Func_class<void,double const &>>,void,double const &>::`vftable';
  *(_DWORD *)&v4._Bx._Alias[4] = this;
  v4._Mysize = (unsigned int)&v4;
  LOBYTE(v7) = 10;
  Event<float>::addHandler(
    (Event<SessionInfo> *)&this->engine.evOnPreStep,
    (std::function<void __cdecl(SessionInfo const &)>)v4,
    v5);
  v4._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_756de79827380d033d8c1c498213bb57_,0>,std::allocator<std::_Func_class<void,double const &>>,void,double const &>::`vftable';
  *(_DWORD *)&v4._Bx._Alias[4] = this;
  v4._Mysize = (unsigned int)&v4;
  LOBYTE(v7) = 10;
  Event<float>::addHandler(
    (Event<SessionInfo> *)&this->driveThread.evPhysicsStepCompleted,
    (std::function<void __cdecl(SessionInfo const &)>)v4,
    this);
  v4._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_ee7410b782c2824aac0ab2a2496d5d25_,0>,std::allocator<std::_Func_class<void,OnFlagEvent const &>>,void,OnFlagEvent const &>::`vftable';
  *(_DWORD *)&v4._Bx._Alias[4] = this;
  v4._Mysize = (unsigned int)&v4;
  LOBYTE(v7) = 10;
  Event<float>::addHandler(
    (Event<SessionInfo> *)&this->engine.evOnFlagEvent,
    (std::function<void __cdecl(SessionInfo const &)>)v4,
    this);
  v5 = (Game *)this;
  v4._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_6908e2633eea881755673b1f9e885fcb_,0>,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>,void,OnNewSessionEvent const &>::`vftable';
  *(_DWORD *)&v4._Bx._Alias[4] = this;
  v4._Mysize = (unsigned int)&v4;
  v3 = &this->sim->evOnNewSession;
  LOBYTE(v7) = 10;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v3,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v4,
    this);
  this->useMatrixSmoothing = 0;
}
void PhysicsAvatar::~PhysicsAvatar(PhysicsAvatar *this)
{
  std::vector<std::vector<PenaltyRecord>> *v2; // edi
  std::vector<unsigned char> **v3; // edi
  Task **v4; // edi
  Event<OnPhysicsStepCompleted> *v5; // edi

  this->__vftable = (PhysicsAvatar_vtbl *)&PhysicsAvatar::`vftable';
  v2 = &this->penaltyRecords;
  if ( this->penaltyRecords._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->penaltyRecords);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::vector<ReplayFrameWingStatus>>>>(
      (std::vector<unsigned char> *)v2->_Myfirst,
      (std::vector<unsigned char> *)v2->_Mylast);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  v3 = (std::vector<unsigned char> **)&this->wingStates;
  if ( this->wingStates._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->wingStates);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::vector<ReplayFrameWingStatus>>>>(
      *v3,
      (std::vector<unsigned char> *)this->wingStates._Mylast);
    operator delete(*v3);
    *v3 = 0;
    this->wingStates._Mylast = 0;
    this->wingStates._Myend = 0;
  }
  std::vector<CarPhysicsState>::_Tidy(&this->currentStates);
  DeleteCriticalSection(&this->mutex.criticalSection);
  PhysicsDriveThread::~PhysicsDriveThread(&this->driveThread);
  Concurrency::concurrent_queue<std::function<void __cdecl (void)>,std::allocator<std::function<void __cdecl (void)>>>::~concurrent_queue<std::function<void __cdecl (void)>,std::allocator<std::function<void __cdecl (void)>>>(&this->commandQueue);
  dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&this->windData);
  v4 = (Task **)&this->evOnFlagEvent;
  if ( this->evOnFlagEvent.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnFlagEvent);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evOnFlagEvent,
      *v4,
      (Task *)this->evOnFlagEvent.handlers._Mylast);
    operator delete(*v4);
    *v4 = 0;
    this->evOnFlagEvent.handlers._Mylast = 0;
    this->evOnFlagEvent.handlers._Myend = 0;
  }
  v5 = &this->evOnStepCompleted;
  if ( this->evOnStepCompleted.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnStepCompleted);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      &this->evOnStepCompleted.handlers,
      v5->handlers._Myfirst,
      this->evOnStepCompleted.handlers._Mylast);
    operator delete(v5->handlers._Myfirst);
    v5->handlers._Myfirst = 0;
    this->evOnStepCompleted.handlers._Mylast = 0;
    this->evOnStepCompleted.handlers._Myend = 0;
  }
  PhysicsEngine::~PhysicsEngine(&this->engine);
  GameObject::~GameObject(this);
}
PhysicsAvatar *PhysicsAvatar::`vector deleting destructor'(PhysicsAvatar *this, unsigned int a2)
{
  PhysicsAvatar::~PhysicsAvatar(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void PhysicsAvatar::executeOnPhysicsThread(PhysicsAvatar *this, std::function<void __cdecl(void)> f)
{
  Concurrency::details::_Concurrent_queue_base_v4::_Internal_push(&this->commandQueue, &f);
  if ( f._Impl )
    ((void (__stdcall *)(bool))f._Impl->_Delete_this)(f._Impl != (std::_Func_base<void> *)&f);
}
DynamicTrackStatus *PhysicsAvatar::getDynamicTrackStatus(PhysicsAvatar *this, DynamicTrackStatus *result)
{
  DynamicTrackStatus *v2; // eax
  int v3; // edx
  float v4; // ecx

  v2 = result;
  v3 = *(_DWORD *)&this->dynamicTrackStatus.enabled;
  v4 = this->dynamicTrackStatus.currentGripLevel;
  *(_DWORD *)&result->enabled = v3;
  result->currentGripLevel = v4;
  return v2;
}
TemperatureInfo *PhysicsAvatar::getTemperatureInfo(PhysicsAvatar *this, TemperatureInfo *result)
{
  TemperatureInfo *v2; // eax
  float v3; // edx
  float v4; // ecx

  v2 = result;
  v3 = this->temperatureInfo.ambientTemperature;
  v4 = this->temperatureInfo.roadTemperature;
  result->ambientTemperature = v3;
  result->roadTemperature = v4;
  return v2;
}
void PhysicsAvatar::onPhysicsStepCompleted(PhysicsAvatar *this, long double pt)
{
  Track *v3; // eax
  bool v4; // al
  Sim *v5; // ecx
  std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *v6; // esi
  std::_Func_base<void,OnPhysicsStepCompleted const &> **v7; // ebx
  std::function<void __cdecl(void)> v8; // [esp-18h] [ebp-4Ch] BYREF
  OnPhysicsStepCompleted ev; // [esp+18h] [ebp-1Ch] BYREF
  int v10; // [esp+30h] [ebp-4h]

  PhysicsAvatar::updateCrossThreadValues(this);
  if ( !TryEnterCriticalSection(&this->mutex.criticalSection) )
    EnterCriticalSection(&this->mutex.criticalSection);
  PhysicsEngine::getPhysicsStates(&this->engine, &this->currentStates, &this->wingStates);
  v3 = this->engine.track;
  this->dynamicTrackStatusPT.currentGripLevel = v3->dynamicGripLevel;
  v4 = v3->dynamicTrack.enabled || v3->dynamicTrack.isExternal;
  (&v8._Impl)[1] = (std::_Func_base<void> *)&this->mutex;
  this->dynamicTrackStatusPT.enabled = v4;
  LeaveCriticalSection((LPCRITICAL_SECTION)(&v8._Impl)[1]);
  if ( DRSManager::wasRaceSwitchedOn(this->engine.track->drsMamanger._Myptr, *(const Car **)this->engine.cars._Myfirst) )
  {
    v8._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_8165eff2958b95c6aad4cfdf700ba972_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    v8._Space._Pfn[1] = (void (__cdecl *)())this;
    v8._Impl = (std::_Func_base<void> *)&v8;
    v5 = this->sim;
    v10 = -1;
    Sim::executeOnMainThread(v5, v8);
  }
  v6 = this->evOnStepCompleted.handlers._Myfirst;
  ev.pt = pt;
  ev.states = &this->currentStates;
  if ( v6 != this->evOnStepCompleted.handlers._Mylast )
  {
    v7 = &v6->second._Impl;
    do
    {
      if ( !*v7 )
      {
        std::_Xbad_function_call();
        JUMPOUT(0x61AE79);
      }
      (*v7)->_Do_call(*v7, &ev);
      ++v6;
      v7 += 8;
    }
    while ( v6 != this->evOnStepCompleted.handlers._Mylast );
  }
}
void PhysicsAvatar::pausePhysics(PhysicsAvatar *this, bool mode)
{
  PhysicsDriveThread *v2; // ecx

  this->isPaused = mode;
  v2 = &this->driveThread;
  if ( mode )
    PhysicsDriveThread::pause(v2);
  else
    PhysicsDriveThread::start(v2);
}
void PhysicsAvatar::render(PhysicsAvatar *this, float dt)
{
  DirectInput *v2; // eax

  if ( this->isPaused && this->driveThread.useDirectInput )
  {
    DirectInput::singleton();
    DirectInput::forceFF(v2, 0.0);
  }
}
void PhysicsAvatar::setAllowedTyresOut(PhysicsAvatar *this, int v)
{
  this->engine.allowedTyresOut = v;
}
void PhysicsAvatar::shutdown(PhysicsAvatar *this)
{
  bool v2; // zf
  PhysicsDriveThread *v3; // ecx

  v2 = !this->driveThread.hasStarted;
  v3 = &this->driveThread;
  if ( !v2 )
    PhysicsDriveThread::stop(v3);
  if ( this->driveThread.useDirectInput )
    DirectInput::cleanup();
}
void PhysicsAvatar::startPhysics(PhysicsAvatar *this)
{
  _printf("STARTING PHYSICS ENGINE\n");
  if ( !this->driveThread.hasStarted )
    PhysicsDriveThread::start(&this->driveThread);
}
void PhysicsAvatar::stepCommandQueue(PhysicsAvatar *this)
{
  Concurrency::concurrent_queue<std::function<void __cdecl(void)>,std::allocator<std::function<void __cdecl(void)> > > *v1; // esi
  std::function<void __cdecl(void)> f; // [esp+Ch] [ebp-28h] BYREF
  int v3; // [esp+30h] [ebp-4h]

  f._Impl = 0;
  v1 = &this->commandQueue;
  v3 = 0;
  while ( Concurrency::details::_Concurrent_queue_base_v4::_Internal_pop_if_present(v1, &f) )
  {
    if ( !f._Impl )
    {
      std::_Xbad_function_call();
      JUMPOUT(0x61B00F);
    }
    f._Impl->_Do_call(f._Impl);
  }
  v3 = -1;
  if ( f._Impl )
    ((void (__stdcall *)(bool))f._Impl->_Delete_this)(f._Impl != (std::_Func_base<void> *)&f);
}
void PhysicsAvatar::update(PhysicsAvatar *this, float deltat)
{
  CarPhysicsState *v3; // edi
  CarPhysicsState *v4; // esi
  double v5; // xmm2_8
  vec3f *v6; // esi
  double v7; // xmm1_8
  vec3f *v8; // edi
  __m128i *v9; // esi
  const __m128i *v10; // eax
  mat44f *v11; // esi
  int v12; // esi
  const __m128i *v13; // eax
  __m128i *v14; // esi
  const __m128i *v15; // eax
  bool v16; // zf
  unsigned int v17; // eax
  CarPhysicsState *v18; // edi
  CarPhysicsState *v19; // esi
  float dt; // [esp+0h] [ebp-110h]
  mat44f v21; // [esp+10h] [ebp-100h] BYREF
  mat44f v22; // [esp+50h] [ebp-C0h] BYREF
  mat44f result; // [esp+90h] [ebp-80h] BYREF
  mat44f *src; // [esp+D0h] [ebp-40h]
  float v25; // [esp+D4h] [ebp-3Ch]
  PhysicsAvatar *v26; // [esp+D8h] [ebp-38h]
  std::vector<std::vector<WingState>> v27; // [esp+E0h] [ebp-30h] BYREF
  std::vector<CarPhysicsState> v28; // [esp+ECh] [ebp-24h] BYREF
  CarAvatar *v29; // [esp+F8h] [ebp-18h]
  vec3f *avel; // [esp+FCh] [ebp-14h]
  float v31; // [esp+100h] [ebp-10h]
  int v32; // [esp+10Ch] [ebp-4h]

  v26 = this;
  if ( this->isPaused )
    return;
  this->physicsLateLoops = this->driveThread.physicsLateLoops._My_val;
  this->occupancy = this->driveThread.occupancy._My_val;
  v31 = this->driveThread.cpuTimeAtomic._My_val;
  this->cpuTimeMS = v31;
  v28._Myfirst = 0;
  v28._Mylast = 0;
  v28._Myend = 0;
  v32 = 1;
  v27._Myfirst = 0;
  v27._Mylast = 0;
  v27._Myend = 0;
  if ( !TryEnterCriticalSection(&this->mutex.criticalSection) )
    EnterCriticalSection(&this->mutex.criticalSection);
  std::vector<CarPhysicsState>::operator=(&v28, &this->currentStates);
  std::vector<std::vector<WingState>>::operator=(&v27, &this->wingStates);
  *(_DWORD *)&this->dynamicTrackStatus.enabled = *(_DWORD *)&this->dynamicTrackStatusPT.enabled;
  this->dynamicTrackStatus.currentGripLevel = this->dynamicTrackStatusPT.currentGripLevel;
  LeaveCriticalSection(&this->mutex.criticalSection);
  if ( this->useMatrixSmoothing && this->driveThread.timeScale <= 1.0 )
  {
    v3 = v28._Mylast;
    v4 = v28._Myfirst;
    v29 = (CarAvatar *)v28._Mylast;
    if ( v28._Myfirst == v28._Mylast )
      goto LABEL_14;
    v5 = DOUBLE_0_009999999776482582;
    v6 = &v28._Myfirst->angularVelocity;
    avel = &v28._Myfirst->angularVelocity;
    do
    {
      v7 = (v26->game->gameTime.now - *(double *)&v6[100].z) * 0.001;
      if ( v5 > COERCE_DOUBLE(*(_QWORD *)&v7 & _xmm) )
      {
        v8 = avel;
        v9 = (__m128i *)&avel[-55];
        dt = v7;
        v25 = dt;
        v10 = (const __m128i *)getTimeCorrectedMatrix(
                                 (int)avel,
                                 (int)&avel[-55],
                                 &result,
                                 (const mat44f *)&avel[-55],
                                 avel - 3,
                                 avel,
                                 dt);
        LODWORD(v31) = 4;
        *v9 = _mm_loadu_si128(v10);
        v9[1] = _mm_loadu_si128(v10 + 1);
        v9[2] = _mm_loadu_si128(v10 + 2);
        v9[3] = _mm_loadu_si128(v10 + 3);
        v11 = (mat44f *)&v8[-29].z;
        src = (mat44f *)&v8[-29].z;
        do
        {
          v12 = (int)&v11[-4];
          v13 = (const __m128i *)getTimeCorrectedMatrix((int)v8, v12, &v22, (const mat44f *)v12, v8 - 3, v8, v25);
          *(__m128i *)v12 = _mm_loadu_si128(v13);
          *(__m128i *)(v12 + 16) = _mm_loadu_si128(v13 + 1);
          *(__m128i *)(v12 + 32) = _mm_loadu_si128(v13 + 2);
          *(__m128i *)(v12 + 48) = _mm_loadu_si128(v13 + 3);
          v14 = (__m128i *)src;
          v15 = (const __m128i *)getTimeCorrectedMatrix((int)v8, (int)src, &v21, src, v8 - 3, v8, v25);
          *v14 = _mm_loadu_si128(v15);
          v14[1] = _mm_loadu_si128(v15 + 1);
          v14[2] = _mm_loadu_si128(v15 + 2);
          v14[3] = _mm_loadu_si128(v15 + 3);
          v11 = (mat44f *)&v14[4];
          v16 = LODWORD(v31)-- == 1;
          src = v11;
        }
        while ( !v16 );
        v3 = (CarPhysicsState *)v29;
        v5 = DOUBLE_0_009999999776482582;
        v6 = avel;
      }
      v6 = (vec3f *)((char *)v6 + 2872);
      avel = v6;
    }
    while ( (CarPhysicsState *)&v6[-56].z != v3 );
  }
  v4 = v28._Myfirst;
  v3 = v28._Mylast;
LABEL_14:
  v31 = 0.0;
  v29 = (CarAvatar *)(v26->sim->cars._Mylast - v26->sim->cars._Myfirst);
  if ( (CarAvatar *)(v3 - v4) == v29 && v4 != v3 )
  {
    avel = 0;
    v17 = 0;
    do
    {
      v29 = Sim::getCar(v26->sim, v17);
      CarAvatar::setNewPhysicsState(v29, v4, deltat);
      std::vector<WingState>::operator=(
        &v29->wingsStatus,
        (const std::vector<WingState> *)((char *)avel + (unsigned int)v27._Myfirst));
      ++v4;
      ++avel;
      v17 = ++LODWORD(v31);
    }
    while ( v4 != v3 );
    v4 = v28._Myfirst;
  }
  LOBYTE(v32) = 0;
  if ( v27._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&v27);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::vector<ReplayFrameWingStatus>>>>(
      (std::vector<unsigned char> *)v27._Myfirst,
      (std::vector<unsigned char> *)v27._Mylast);
    operator delete(v27._Myfirst);
    v4 = v28._Myfirst;
    v27._Myfirst = 0;
    v27._Mylast = 0;
    v27._Myend = 0;
  }
  v32 = -1;
  if ( v4 )
  {
    std::_Container_base0::_Orphan_all(&v28);
    v18 = v28._Mylast;
    v19 = v28._Myfirst;
    if ( v28._Myfirst != v28._Mylast )
    {
      do
      {
        dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)&v19->speed);
        ++v19;
      }
      while ( v19 != v18 );
      v19 = v28._Myfirst;
    }
    operator delete(v19);
  }
}
void PhysicsAvatar::updateCrossThreadValues(PhysicsAvatar *this)
{
  float v2; // xmm1_4
  float v3; // xmm0_4
  int v4; // eax
  unsigned __int64 v5; // xmm0_8
  Sim *v6; // ecx
  float v7; // xmm0_4
  int v8; // eax
  unsigned __int64 v9; // xmm0_8
  Sim *v10; // ecx
  std::function<void __cdecl(void)> v11; // [esp-18h] [ebp-40h] BYREF
  std::function<void __cdecl(void)> *v12; // [esp+Ch] [ebp-1Ch]
  unsigned __int64 v13; // [esp+10h] [ebp-18h]
  int v14; // [esp+24h] [ebp-4h]

  v2 = this->engine.ambientTemperature;
  if ( this->temperatureInfoPT.ambientTemperature != v2
    || this->temperatureInfoPT.roadTemperature != this->engine.roadTemperature )
  {
    v3 = this->engine.roadTemperature;
    this->temperatureInfoPT.ambientTemperature = v2;
    this->temperatureInfoPT.roadTemperature = v3;
    v13 = __PAIR64__(LODWORD(v3), LODWORD(v2));
    v12 = &v11;
    v11._Impl = 0;
    v14 = 0;
    v4 = operator new(20);
    if ( !v4 )
      std::_Xbad_alloc();
    v5 = v13;
    *(_DWORD *)v4 = &std::_Func_impl<std::_Callable_obj<_lambda_86402815093bc779658fb3eae701d822_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)(v4 + 4) = v5;
    *(_DWORD *)(v4 + 12) = this;
    v11._Impl = (std::_Func_base<void> *)v4;
    v6 = this->sim;
    v14 = -1;
    Sim::executeOnMainThread(v6, v11);
  }
  if ( this->engine.wind.directionDeg != this->windData.directionDEG
    || this->engine.wind.speed.value != this->windData.speed.value )
  {
    v7 = this->engine.wind.speed.value;
    *(float *)&v13 = this->engine.wind.directionDeg;
    *((float *)&v13 + 1) = v7;
    v12 = &v11;
    v11._Impl = 0;
    v14 = 1;
    v8 = operator new(20);
    if ( !v8 )
      std::_Xbad_alloc();
    v9 = v13;
    *(_DWORD *)v8 = &std::_Func_impl<std::_Callable_obj<_lambda_fe26347f8f598f7d6c2b815ce9b7c4dc_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)(v8 + 4) = v9;
    *(_DWORD *)(v8 + 12) = this;
    v11._Impl = (std::_Func_base<void> *)v8;
    v10 = this->sim;
    v14 = -1;
    Sim::executeOnMainThread(v10, v11);
  }
}
__int16 PhysicsAvatar::getBasePitPenaltyLaps(PhysicsAvatar *this)
{
  return this->engine.penaltyRules.basePitPenaltyLaps;
}
void PhysicsAvatar::setJumpStartPenaltyMode(PhysicsAvatar *this, JumpStartPenaltyMode mode)
{
  this->engine.penaltyRules.jumpStartPenaltyMode = mode;
}
