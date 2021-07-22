#include "enginesmoke.h
void EngineSmoke::EngineSmoke(EngineSmoke *this, CarAvatar *a_car)
{
  Event<OnReplayStatusChanged> *v3; // ecx
  CarAvatar *v4; // eax
  Event<OnNewSessionEvent> *v5; // ecx
  Game *v6; // eax
  int v7; // ebx
  int v8; // ebp
  float v9; // xmm0_4
  ParticleSystem *v10; // esi
  Game *v11; // eax
  ParticleSystem *v12; // eax
  bool v13; // zf
  ParticleGenerator *v14; // esi
  __m128 v15; // xmm0
  ParticleGenerator *v16; // eax
  CarAvatar *v17; // eax
  bool v18; // bl
  double v19; // st7
  bool v20; // cf
  std::wstring v21; // [esp-18h] [ebp-160h] BYREF
  float aFrequency; // [esp+0h] [ebp-148h]
  float v23; // [esp+24h] [ebp-124h]
  int v24; // [esp+28h] [ebp-120h]
  void *v25; // [esp+2Ch] [ebp-11Ch]
  EngineSmoke *v26; // [esp+30h] [ebp-118h]
  std::wstring key; // [esp+34h] [ebp-114h] BYREF
  std::wstring section; // [esp+4Ch] [ebp-FCh] BYREF
  std::wstring a_name; // [esp+64h] [ebp-E4h] BYREF
  std::wstring filename; // [esp+7Ch] [ebp-CCh] BYREF
  Texture tex; // [esp+94h] [ebp-B4h] BYREF
  INIReader ini; // [esp+B0h] [ebp-98h] BYREF
  INIReaderDocuments videoINI; // [esp+F4h] [ebp-54h] BYREF
  int v34; // [esp+144h] [ebp-4h]

  v24 = 0;
  v26 = this;
  aFrequency = *(float *)&a_car->game;
  v21._Myres = 7;
  v21._Mysize = 0;
  v21._Bx._Buf[0] = 0;
  std::wstring::assign(&v21, L"ENGINE_SMOKE", 0xCu);
  GameObject::GameObject(this, v21, (Game *)LODWORD(aFrequency));
  this->__vftable = (EngineSmoke_vtbl *)&EngineSmoke::`vftable';
  this->car = a_car;
  this->smokeEnabled = 1;
  this->pSystem = 0;
  this->pGenerator = 0;
  this->live.oldValue = 1000.0;
  this->live.smokeTimer = 0.0;
  LODWORD(aFrequency) = this;
  this->replay.oldValue = 1000.0;
  this->replay.smokeTimer = 0.0;
  v34 = 0;
  this->triggerEngineLife = 25.0;
  this->maxSmokeTimer = 20.0;
  v21._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_968a01676f34487887e6c6aaf03b1c42_,0>,std::allocator<std::_Func_class<void,OnReplayStatusChanged const &>>,void,OnReplayStatusChanged const &>::`vftable';
  *(_DWORD *)&v21._Bx._Alias[4] = this;
  v21._Mysize = (unsigned int)&v21;
  v3 = &a_car->sim->evOnReplayStatusChanged;
  LOBYTE(v34) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v3,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v21,
    (void *)LODWORD(aFrequency));
  LODWORD(aFrequency) = this;
  v21._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_d38bf75ea0405e2c42703fbedbda8fcb_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
  *(_DWORD *)&v21._Bx._Alias[4] = this;
  v21._Mysize = (unsigned int)&v21;
  v4 = this->car;
  LOBYTE(v34) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&v4->sim->evOnPauseModeChanged,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v21,
    this);
  LODWORD(aFrequency) = this;
  v21._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_479d35c1751e51c08c83b0914617b355_,0>,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>,void,OnNewSessionEvent const &>::`vftable';
  *(_DWORD *)&v21._Bx._Alias[4] = this;
  v21._Mysize = (unsigned int)&v21;
  v5 = &a_car->sim->evOnNewSession;
  LOBYTE(v34) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v5,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v21,
    this);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"content/texture/smoke_0.png", 0x1Bu);
  v6 = this->game;
  LOBYTE(v34) = 4;
  ResourceStore::getTexture(v6->graphics->resourceStore._Myptr, &tex, &filename, 0);
  LOBYTE(v34) = 6;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  v7 = 2000;
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  v23 = FLOAT_60_0;
  _printf("ENGINE SMOKE LEVEL SELECTED : ");
  aFrequency = 0.0;
  v21._Myres = 7;
  v21._Mysize = 0;
  v21._Bx._Buf[0] = 0;
  std::wstring::assign(&v21, L"cfg/video.ini", 0xDu);
  INIReaderDocuments::INIReaderDocuments(&videoINI, 0x7D0u, v21, SLOBYTE(aFrequency));
  LOBYTE(v34) = 7;
  if ( videoINI.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"SMOKE", 5u);
    LOBYTE(v34) = 8;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"EFFECTS", 7u);
    LOBYTE(v34) = 9;
    v8 = INIReader::getInt(&videoINI, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v34) = 7;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    switch ( v8 )
    {
      case 0:
        _printf("eSmokeOff\n");
        this->smokeEnabled = 0;
        break;
      case 1:
        _printf("eSmokeVeryLow\n");
        v9 = FLOAT_15_0;
        v7 = 500;
        goto LABEL_15;
      case 2:
        _printf("eSmokeLow\n");
        v9 = FLOAT_30_0;
        v7 = 1000;
        goto LABEL_15;
      case 3:
        _printf("eSmokeNormal\n");
        break;
      case 4:
        _printf("eSmokeHigh\n");
        v9 = FLOAT_120_0;
        v7 = 4000;
        goto LABEL_15;
      case 5:
        _printf("eSmokeUltra\n");
        v9 = FLOAT_240_0;
        v7 = 8000;
LABEL_15:
        v23 = v9;
        break;
      default:
        break;
    }
  }
  if ( this->smokeEnabled )
  {
    v10 = (ParticleSystem *)operator new(320);
    v25 = v10;
    LOBYTE(v34) = 10;
    if ( v10 )
    {
      std::wstring::wstring(&a_name, L"ENGINE_SMOKE_PARTICLE");
      v24 = 1;
      LODWORD(aFrequency) = &tex;
      v11 = this->game;
      LOBYTE(v34) = 11;
      ParticleSystem::ParticleSystem(v10, &a_name, v11->graphics, v7, &tex);
    }
    else
    {
      v12 = 0;
    }
    v13 = (v24 & 1) == 0;
    this->pSystem = v12;
    v34 = 7;
    if ( !v13 && a_name._Myres >= 8 )
      operator delete(a_name._Bx._Ptr);
    v14 = (ParticleGenerator *)operator new(168);
    v25 = v14;
    LOBYTE(v34) = 13;
    if ( v14 )
    {
      v15 = (__m128)LODWORD(v23);
      aFrequency = v23;
      std::wstring::wstring(&v21, L"system/cfg/engine_smoke.ini");
      ParticleGenerator::ParticleGenerator(v14, v15, this->pSystem, v21, aFrequency);
    }
    else
    {
      v16 = 0;
    }
    aFrequency = *(float *)&this->pSystem;
    this->pGenerator = v16;
    v17 = this->car;
    LOBYTE(v34) = 7;
    v17->sim->particlesNode->addChild(v17->sim->particlesNode, (Node *)LODWORD(aFrequency));
  }
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"system/cfg/engine_smoke.ini", 0x1Bu);
  LOBYTE(v34) = 14;
  INIReader::INIReader(&ini, &section);
  LOBYTE(v34) = 16;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"LIFE_TIME", 9u);
  LOBYTE(v34) = 17;
  v18 = INIReader::hasSection(&ini, &key);
  LOBYTE(v34) = 16;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( v18 )
  {
    a_name._Myres = 7;
    a_name._Mysize = 0;
    a_name._Bx._Buf[0] = 0;
    std::wstring::assign(&a_name, L"SECONDS", 7u);
    LOBYTE(v34) = 18;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"LIFE_TIME", 9u);
    LOBYTE(v34) = 19;
    v19 = INIReader::getFloat(&ini, &key, &a_name);
    v20 = key._Myres < 8;
    this->maxSmokeTimer = v19;
    if ( !v20 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( a_name._Myres >= 8 )
      operator delete(a_name._Bx._Ptr);
  }
  LOBYTE(v34) = 7;
  INIReader::~INIReader(&ini);
  LOBYTE(v34) = 6;
  INIReaderDocuments::~INIReaderDocuments(&videoINI);
  LOBYTE(v34) = 0;
  OnSetupAppCreated::~OnSetupAppCreated(&tex);
}
EngineSmoke *EngineSmoke::`vector deleting destructor'(EngineSmoke *this, unsigned int a2)
{
  ParticleGenerator *v3; // edi

  this->__vftable = (EngineSmoke_vtbl *)&EngineSmoke::`vftable';
  v3 = this->pGenerator;
  if ( v3 )
  {
    ParticleGenerator::~ParticleGenerator(v3);
    operator delete(v3);
  }
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void EngineSmoke::update(EngineSmoke *this, float dt)
{
  float v3; // xmm0_4
  CarAvatar *v4; // ecx
  EngineSmoke::EngineSmokeStatus *v5; // edi
  float v6; // xmm1_4
  float *v7; // eax
  ParticleGenerator *v8; // ecx
  float v9; // xmm1_4
  float v10; // xmm3_4
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  Game *v14; // eax
  float v15; // [esp+18h] [ebp-1Ch]
  vec3f velocity; // [esp+1Ch] [ebp-18h] BYREF
  vec3f pointOfGeneration; // [esp+28h] [ebp-Ch] BYREF

  if ( this->smokeEnabled && CarAvatar::isConnected(this->car) )
  {
    v15 = FLOAT_1_0;
    if ( ReplayManager::isInReplaymode(this->car->sim->replayManager) )
    {
      v15 = this->car->sim->replayManager->timeMult;
      v3 = v15 * dt;
    }
    else
    {
      v3 = dt;
    }
    ParticleSystem::step(this->pSystem, v3);
    v4 = this->car;
    v5 = &this->replay;
    if ( !v4->sim->replayManager->isActive )
      v5 = &this->live;
    v6 = v4->physicsState.engineLifeLeft;
    if ( v6 < 0.0 )
      v6 = 0.0;
    if ( this->triggerEngineLife >= v6 )
    {
      if ( v5->oldValue != v6 )
      {
        v5->oldValue = v6;
        v5->smokeTimer = this->maxSmokeTimer;
      }
      if ( v5->smokeTimer > 0.0 )
      {
        v7 = (float *)this->car;
        v8 = this->pGenerator;
        v9 = (float)(v7[233] + v7[249]) * 0.5;
        v10 = (float)(v7[235] + v7[251]) * 0.5;
        pointOfGeneration.y = (float)(v7[234] + v7[250]) * 0.5;
        pointOfGeneration.x = v9;
        pointOfGeneration.z = v10;
        v11 = v7[265];
        v12 = v7[266];
        v13 = v7[267];
        v14 = this->game;
        velocity.x = v11 * 0.0099999998;
        velocity.y = (float)(v12 * 0.0099999998) + 1.0;
        velocity.z = v13 * 0.0099999998;
        ParticleGenerator::generateParticle(v8, &pointOfGeneration, &velocity, v14->gameTime.now, v15);
        v5->smokeTimer = v5->smokeTimer - v3;
      }
    }
  }
}
