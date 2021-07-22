#include "physicsdrivethread.h
void PhysicsDriveThread::PhysicsDriveThread(PhysicsDriveThread *this, PhysicsEngine *aphysicsEngine, Game *agame)
{
  std::atomic<unsigned int> *v4; // ebx
  std::atomic<int> *v5; // esi
  std::atomic<float> *v6; // edi
  unsigned int v7; // ebx
  bool v8; // al
  int v9; // edi
  bool v10; // al
  std::wstring v11; // [esp-1Ch] [ebp-138h] BYREF
  Game *v12; // [esp-4h] [ebp-120h]
  char v13; // [esp+17h] [ebp-105h]
  unsigned int v14; // [esp+18h] [ebp-104h]
  int v15; // [esp+1Ch] [ebp-100h]
  PhysicsDriveThread *v16; // [esp+20h] [ebp-FCh]
  std::wstring section; // [esp+24h] [ebp-F8h] BYREF
  std::wstring v18; // [esp+3Ch] [ebp-E0h] BYREF
  std::wstring ifilename; // [esp+54h] [ebp-C8h] BYREF
  std::wstring ct; // [esp+6Ch] [ebp-B0h] BYREF
  INIReader ini; // [esp+84h] [ebp-98h] BYREF
  INIReaderDocuments iniDoc; // [esp+C8h] [ebp-54h] BYREF
  int v23; // [esp+118h] [ebp-4h]

  v4 = &this->physicsLateLoops;
  v16 = this;
  v15 = 0;
  _InterlockedExchange((volatile __int32 *)&this->physicsLateLoops, 0);
  v5 = &this->occupancy;
  _InterlockedExchange((volatile __int32 *)&this->occupancy, 0);
  v6 = &this->cpuTimeAtomic;
  this->evPhysicsStepCompleted.handlers._Myfirst = 0;
  this->cpuTimeAtomic._My_val = 0.0;
  this->evPhysicsStepCompleted.handlers._Mylast = 0;
  this->evPhysicsStepCompleted.handlers._Myend = 0;
  this->timeScale = DOUBLE_1_0;
  this->useDirectInput = 1;
  this->cpuTimeLocal = 0.0;
  this->engine = aphysicsEngine;
  v23 = 0;
  this->thread._Thr._Id = 0;
  v12 = agame;
  *(_WORD *)&this->useTimerProcess = 1;
  this->isPhysicsInitialized = 0;
  this->lastStepTimestamp = 0.0;
  this->directInput = 0;
  DICommandManager::DICommandManager(&this->diCommandManager, v12);
  LOBYTE(v23) = 2;
  this->hasStarted = 0;
  this->shuttingDown = 0;
  this->currentTime = 0.0;
  this->startTime = ksGetTime();
  this->isPaused = 0;
  _InterlockedExchange((volatile __int32 *)v5, 0);
  v14 = 0;
  this->tProcess = 0;
  this->cpuTimeLocal = 0.0;
  _InterlockedExchange((volatile __int32 *)v6, 0);
  _InterlockedExchange((volatile __int32 *)v4, 0);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/assetto_corsa.ini", 0x1Cu);
  LOBYTE(v23) = 3;
  INIReader::INIReader(&ini, &ifilename);
  LOBYTE(v23) = 5;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( !ini.ready )
  {
    v7 = v15;
    goto LABEL_7;
  }
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"THREADING", 9u);
  LOBYTE(v23) = 6;
  v7 = 1;
  v14 = 1;
  if ( !INIReader::hasSection(&ini, &section) )
  {
LABEL_7:
    v13 = 0;
    goto LABEL_8;
  }
  v13 = 1;
LABEL_8:
  v23 = 5;
  if ( (v7 & 1) != 0 )
  {
    v7 &= 0xFFFFFFFE;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  if ( v13 )
  {
    v15 = ksGetNumberOfProcessors();
    _printf("Initialising threading with: %d cores\n", v15);
    INIReader::setVerboseMode(&ini, 1);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SET_THREAD_AFFINITY_MASK", 0x18u);
    LOBYTE(v23) = 7;
    v18._Myres = 7;
    v18._Mysize = 0;
    v18._Bx._Buf[0] = 0;
    std::wstring::assign(&v18, L"THREADING", 9u);
    v23 = 8;
    v7 |= 6u;
    v14 = v7;
    v8 = INIReader::getInt(&ini, &v18, &section) && (int)ksGetNumberOfProcessors() > 4;
    this->setAffinityMask = v8;
    if ( (v7 & 4) != 0 )
    {
      v7 &= 0xFFFFFFFB;
      if ( v18._Myres >= 8 )
        operator delete(v18._Bx._Ptr);
      v18._Myres = 7;
      v18._Mysize = 0;
      v18._Bx._Buf[0] = 0;
    }
    v23 = 5;
    if ( (v7 & 2) != 0 && section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"USE_TIMER_PROCESS", 0x11u);
    LOBYTE(v23) = 9;
    v18._Myres = 7;
    v18._Mysize = 0;
    v18._Bx._Buf[0] = 0;
    std::wstring::assign(&v18, L"THREADING", 9u);
    LOBYTE(v23) = 10;
    v9 = INIReader::getInt(&ini, &v18, &section);
    if ( v18._Myres >= 8 )
      operator delete(v18._Bx._Ptr);
    v18._Myres = 7;
    v18._Mysize = 0;
    v18._Bx._Buf[0] = 0;
    LOBYTE(v23) = 5;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v9 == -1 )
      v10 = v15 <= 2;
    else
      v10 = v9 != 0;
    this->useTimerProcess = v10;
    if ( v10 )
      _printf("TimerProcess: ON\n");
    else
      _printf("TimerProcess: OFF\n");
  }
  if ( this->setAffinityMask )
    ksSetCurrentThreadAffinityMask(2ui64);
  v12 = 0;
  this->useDirectInput = 1;
  v11._Myres = 7;
  v11._Mysize = 0;
  v11._Bx._Buf[0] = 0;
  std::wstring::assign(&v11, L"cfg/controls.ini", 0x10u);
  INIReaderDocuments::INIReaderDocuments(&iniDoc, v7, v11, (bool)v12);
  LOBYTE(v23) = 11;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"INPUT_METHOD", 0xCu);
  LOBYTE(v23) = 12;
  v18._Myres = 7;
  v18._Mysize = 0;
  v18._Bx._Buf[0] = 0;
  std::wstring::assign(&v18, L"HEADER", 6u);
  LOBYTE(v23) = 13;
  INIReader::getString(&iniDoc, &ct, &v18, &section);
  if ( v18._Myres >= 8 )
    operator delete(v18._Bx._Ptr);
  v18._Myres = 7;
  v18._Mysize = 0;
  v18._Bx._Buf[0] = 0;
  LOBYTE(v23) = 16;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  if ( !std::wstring::compare(&ct, 0, ct._Mysize, L"EXTERNAL", 8u) )
    this->useDirectInput = 0;
  if ( ct._Myres >= 8 )
    operator delete(ct._Bx._Ptr);
  ct._Myres = 7;
  ct._Mysize = 0;
  ct._Bx._Buf[0] = 0;
  LOBYTE(v23) = 5;
  INIReaderDocuments::~INIReaderDocuments(&iniDoc);
  LOBYTE(v23) = 2;
  INIReader::~INIReader(&ini);
}
void PhysicsDriveThread::~PhysicsDriveThread(PhysicsDriveThread *this)
{
  this->shuttingDown = 1;
  TimeEvaluation::~TimeEvaluation((DRS *)&this->diCommandManager);
  if ( this->thread._Thr._Id )
    terminate();
  if ( this->evPhysicsStepCompleted.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evPhysicsStepCompleted);
    std::vector<std::pair<void *,std::function<void __cdecl (double const &)>>>::_Destroy(
      (std::vector<Task> *)&this->evPhysicsStepCompleted,
      (Task *)this->evPhysicsStepCompleted.handlers._Myfirst,
      (Task *)this->evPhysicsStepCompleted.handlers._Mylast);
    operator delete(this->evPhysicsStepCompleted.handlers._Myfirst);
    this->evPhysicsStepCompleted.handlers._Myfirst = 0;
    this->evPhysicsStepCompleted.handlers._Mylast = 0;
    this->evPhysicsStepCompleted.handlers._Myend = 0;
  }
}
void PhysicsDriveThread::pause(PhysicsDriveThread *this)
{
  this->isPaused = 1;
}
void PhysicsDriveThread::run(PhysicsDriveThread *this)
{
  void (*v2)(const char *const, ...); // ebp
  IPhysicsCore *v3; // eax
  DirectInput *v4; // eax
  int v5; // ebx
  double v6; // xmm0_8
  std::atomic<int> *v7; // ebp
  DirectInput *v8; // ecx
  double v9; // st7
  long double currentTime; // xmm0_8
  PhysicsEngine *v11; // ecx
  double v12; // st7
  __int32 *v13; // ecx
  std::pair<void *,std::function<void __cdecl(double const &)> > *v14; // esi
  long double *v15; // ebp
  std::_Func_base<void,double const &> **v16; // ebx
  DirectInput *v17; // ecx
  PhysicsEngine *v18; // ecx
  long double gt; // [esp+Ch] [ebp-88h]
  double v20; // [esp+5Ch] [ebp-38h] BYREF
  int v21; // [esp+64h] [ebp-30h] BYREF
  float v22; // [esp+68h] [ebp-2Ch]
  double v23; // [esp+6Ch] [ebp-28h]
  long double v24; // [esp+74h] [ebp-20h]
  long double v25; // [esp+7Ch] [ebp-18h]
  double v26; // [esp+84h] [ebp-10h]
  double v27; // [esp+8Ch] [ebp-8h]

  if ( !this->shuttingDown )
  {
    v2 = (void (*)(const char *const, ...))_printf;
    v24 = DOUBLE_20_0;
    v25 = DOUBLE_1000_0;
    v26 = DOUBLE_100_0;
    v27 = DOUBLE_30000_0;
    do
    {
      if ( !this->isPhysicsInitialized )
      {
        v23 = ksGetSystemTime();
        _srand((unsigned int)v23);
        if ( this->setAffinityMask )
          ksSetCurrentThreadAffinityMask(4ui64);
        v3 = PhysicsEngine::getCore(this->engine);
        v3->initMultithreading(v3);
        this->isPhysicsInitialized = 1;
      }
      if ( !this->directInput && this->useDirectInput )
      {
        DirectInput::singleton();
        this->directInput = v4;
      }
      if ( this->isPaused )
      {
        v17 = this->directInput;
        if ( v17 && this->useDirectInput )
        {
          DirectInput::poll(v17);
          DICommandManager::step(&this->diCommandManager);
        }
        _InterlockedExchange((volatile __int32 *)&this->occupancy, 0);
        v18 = this->engine;
        this->cpuTimeLocal = 0.0;
        PhysicsEngine::stepPaused(v18);
        ksSleep(10);
      }
      else
      {
        if ( PhysicsEngine::isTestMode )
          this->timeScale = v24;
        v5 = 0;
        v23 = ksGetTime() * this->timeScale;
        if ( v23 - this->currentTime <= v25 )
        {
          v6 = v23;
        }
        else
        {
          v2("RESET PHYSICS TIMER\n");
          v6 = v23;
          this->currentTime = v23;
        }
        if ( v6 > this->currentTime )
        {
          v21 = 300;
          v7 = &this->occupancy;
          do
          {
            v8 = this->directInput;
            if ( v8 && this->useDirectInput )
            {
              DirectInput::poll(v8);
              DICommandManager::step(&this->diCommandManager);
            }
            v9 = ksGetQPTTime();
            currentTime = this->currentTime + 3.0;
            ++v5;
            v11 = this->engine;
            gt = v23;
            v20 = v9;
            v22 = *(float *)&v5;
            this->currentTime = currentTime;
            PhysicsEngine::step(v11, 0.003, currentTime, gt);
            v12 = ksGetQPTTime();
            v13 = (__int32 *)&v20;
            *(float *)&v20 = v12 - v20;
            LODWORD(currentTime) = LODWORD(v20);
            this->cpuTimeLocal = *(float *)&v20;
            LODWORD(v20) = (int)((float)(*(float *)&currentTime * 0.33333334) * v26);
            if ( SLODWORD(v20) >= 300 )
              v13 = &v21;
            _InterlockedExchange((volatile __int32 *)v7, *v13);
            v14 = this->evPhysicsStepCompleted.handlers._Myfirst;
            v15 = &this->engine->physicsTime;
            if ( v14 != this->evPhysicsStepCompleted.handlers._Mylast )
            {
              v16 = &v14->second._Impl;
              do
              {
                if ( !*v16 )
                {
                  std::_Xbad_function_call();
                  JUMPOUT(0x61C0A8);
                }
                (*v16)->_Do_call(*v16, v15);
                ++v14;
                v16 += 8;
              }
              while ( v14 != this->evPhysicsStepCompleted.handlers._Mylast );
              v5 = LODWORD(v22);
            }
            v7 = &this->occupancy;
          }
          while ( v23 > this->currentTime );
          if ( v5 > 0 )
          {
            this->lastStepTimestamp = v23;
            dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v13);
          }
          v2 = (void (*)(const char *const, ...))_printf;
          if ( v5 > 1 )
          {
            _printf("WAS LATE, HAD TO LOOP %d times\n", v5);
            if ( v23 > v27 )
              _InterlockedExchangeAdd((volatile signed __int32 *)&this->physicsLateLoops, 1u);
          }
        }
      }
      v22 = this->cpuTimeLocal;
      _InterlockedExchange((volatile __int32 *)&this->cpuTimeAtomic, SLODWORD(v22));
      ksSleep(0);
    }
    while ( !this->shuttingDown );
  }
}
void PhysicsDriveThread::start(PhysicsDriveThread *this)
{
  TimerProcess *v2; // eax
  TimerProcess *v3; // eax
  std::function<void __cdecl(void)> v4; // [esp-18h] [ebp-54h] BYREF
  TimerProcess *v5; // [esp+Ch] [ebp-30h]
  struct _Thrd_imp_t v6; // [esp+10h] [ebp-2Ch] BYREF
  std::_Pad v7; // [esp+18h] [ebp-24h] BYREF
  PhysicsDriveThread *v8; // [esp+28h] [ebp-14h]
  int v9; // [esp+38h] [ebp-4h]

  if ( this->hasStarted )
  {
    this->isPaused = 0;
    return;
  }
  if ( !this->useTimerProcess )
  {
    std::_Pad::_Pad(&v7);
    v7.__vftable = (std::_Pad_vtbl *)&std::_LaunchPad<std::_Bind<0,void,_lambda_50e63f57fef20886d046ed60550835f6_,>>::`vftable';
    v8 = this;
    v9 = 2;
    std::_Pad::_Launch(&v7, &v6);
    v9 = -1;
    std::_Pad::~_Pad(&v7);
    if ( this->thread._Thr._Id )
      terminate();
    this->thread._Thr = v6;
    goto LABEL_11;
  }
  if ( this->tProcess )
  {
LABEL_11:
    this->hasStarted = 1;
    return;
  }
  v2 = (TimerProcess *)operator new(48);
  v5 = v2;
  v9 = 0;
  if ( v2 )
  {
    v4._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_29c2637f94c4da9ecd28a46d4bd8728b_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    v4._Space._Pfn[1] = (void (__cdecl *)())this;
    v4._Impl = (std::_Func_base<void> *)&v4;
    LOBYTE(v9) = 0;
    TimerProcess::TimerProcess(v2, 3, v4);
    this->tProcess = v3;
    this->hasStarted = 1;
  }
  else
  {
    this->hasStarted = 1;
    this->tProcess = 0;
  }
}
void PhysicsDriveThread::step(PhysicsDriveThread *this)
{
  IPhysicsCore *v2; // eax
  DirectInput *v3; // eax
  int v4; // ebx
  double v5; // xmm0_8
  DirectInput *v6; // ecx
  double v7; // st7
  long double currentTime; // xmm0_8
  PhysicsEngine *v9; // ecx
  double v10; // st7
  __int32 *v11; // ecx
  std::pair<void *,std::function<void __cdecl(double const &)> > *v12; // esi
  long double *v13; // ebp
  std::_Func_base<void,double const &> **v14; // ebx
  DirectInput *v15; // ecx
  PhysicsEngine *v16; // ecx
  long double gt; // [esp+Ch] [ebp-48h]
  double v18; // [esp+34h] [ebp-20h] BYREF
  int v19; // [esp+3Ch] [ebp-18h] BYREF
  int v20; // [esp+40h] [ebp-14h]
  double v21; // [esp+44h] [ebp-10h]
  double v22; // [esp+4Ch] [ebp-8h]

  if ( !this->isPhysicsInitialized )
  {
    v21 = ksGetSystemTime();
    _srand((unsigned int)v21);
    if ( this->setAffinityMask )
      ksSetCurrentThreadAffinityMask(4ui64);
    v2 = PhysicsEngine::getCore(this->engine);
    v2->initMultithreading(v2);
    this->isPhysicsInitialized = 1;
  }
  if ( !this->directInput && this->useDirectInput )
  {
    DirectInput::singleton();
    this->directInput = v3;
  }
  if ( this->isPaused )
  {
$LN176_1:
    v15 = this->directInput;
    if ( v15 && this->useDirectInput )
    {
      DirectInput::poll(v15);
      DICommandManager::step(&this->diCommandManager);
    }
    _InterlockedExchange((volatile __int32 *)&this->occupancy, 0);
    v16 = this->engine;
    this->cpuTimeLocal = 0.0;
    PhysicsEngine::stepPaused(v16);
    ksSleep(10);
    goto LABEL_37;
  }
  if ( PhysicsEngine::isTestMode )
    this->timeScale = DOUBLE_20_0;
  v4 = 0;
  v21 = ksGetTime() * this->timeScale;
  if ( v21 - this->currentTime <= 1000.0 )
  {
    v5 = v21;
  }
  else
  {
    _printf("RESET PHYSICS TIMER\n");
    v5 = v21;
    this->currentTime = v21;
  }
  if ( v5 > this->currentTime )
  {
    v19 = 300;
    v22 = DOUBLE_100_0;
    while ( 1 )
    {
      v6 = this->directInput;
      if ( v6 && this->useDirectInput )
      {
        DirectInput::poll(v6);
        DICommandManager::step(&this->diCommandManager);
      }
      v7 = ksGetQPTTime();
      currentTime = this->currentTime + 3.0;
      ++v4;
      v9 = this->engine;
      gt = v21;
      v18 = v7;
      v20 = v4;
      this->currentTime = currentTime;
      PhysicsEngine::step(v9, 0.003, currentTime, gt);
      v10 = ksGetQPTTime();
      v11 = (__int32 *)&v18;
      *(float *)&v18 = v10 - v18;
      LODWORD(currentTime) = LODWORD(v18);
      this->cpuTimeLocal = *(float *)&v18;
      LODWORD(v18) = (int)((float)(*(float *)&currentTime * 0.33333334) * v22);
      if ( SLODWORD(v18) >= 300 )
        v11 = &v19;
      _InterlockedExchange((volatile __int32 *)&this->occupancy, *v11);
      v12 = this->evPhysicsStepCompleted.handlers._Myfirst;
      v13 = &this->engine->physicsTime;
      if ( v12 != this->evPhysicsStepCompleted.handlers._Mylast )
        break;
LABEL_26:
      if ( v21 <= this->currentTime )
      {
        if ( v4 > 0 )
        {
          this->lastStepTimestamp = v21;
          dxtemplateThreadingImplementation<dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>,dxtemplateJobListSelfHandler<dxSelfWakeup,dxtemplateJobListContainer<dxFakeLull,dxFakeMutex,dxFakeAtomicsProvider>>>::CleanupForRestart((TyreTester *)v11);
        }
        if ( v4 > 1 )
        {
          _printf("WAS LATE, HAD TO LOOP %d times\n", v4);
          if ( v21 > 30000.0 )
            _InterlockedExchangeAdd((volatile signed __int32 *)&this->physicsLateLoops, 1u);
        }
        goto LABEL_37;
      }
    }
    v14 = &v12->second._Impl;
    while ( *v14 )
    {
      (*v14)->_Do_call(*v14, v13);
      ++v12;
      v14 += 8;
      if ( v12 == this->evPhysicsStepCompleted.handlers._Mylast )
      {
        v4 = v20;
        goto LABEL_26;
      }
    }
    std::_Xbad_function_call();
    goto $LN176_1;
  }
LABEL_37:
  _InterlockedExchange((volatile __int32 *)&this->cpuTimeAtomic, LODWORD(this->cpuTimeLocal));
}
void PhysicsDriveThread::stop(PhysicsDriveThread *this)
{
  bool v2; // zf
  TimerProcess *v3; // edi

  v2 = !this->useTimerProcess;
  this->shuttingDown = 1;
  if ( v2 )
  {
    std::thread::join(&this->thread);
  }
  else
  {
    v3 = this->tProcess;
    if ( v3 )
    {
      TimerProcess::~TimerProcess(this->tProcess);
      operator delete(v3);
      this->tProcess = 0;
    }
    ksSleep(500);
  }
}
