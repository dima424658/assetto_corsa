#include "tyresmoke.h
void TyreSmoke::TyreSmoke(TyreSmoke *this, CarAvatar *a_car, int a_tyreIndex)
{
  int v4; // ebx
  Event<OnReplayStatusChanged> *v5; // ecx
  Event<OnNewSessionEvent> *v6; // ecx
  Event<bool> *v7; // ecx
  Game *v8; // eax
  int v9; // esi
  int v10; // ebp
  float v11; // xmm0_4
  int *v12; // eax
  ParticleSystem *v13; // ebp
  Game *v14; // eax
  ParticleSystem *v15; // eax
  ParticleGenerator *v16; // ebp
  __m128 v17; // xmm0
  ParticleGenerator *v18; // eax
  CarAvatar *v19; // eax
  ParticleSystem *v20; // ebp
  Game *v21; // eax
  ParticleSystem *v22; // eax
  ParticleGenerator *v23; // ebp
  __m128 v24; // xmm0
  ParticleGenerator *v25; // eax
  Game *v26; // eax
  ParticleSystem *v27; // ebp
  Game *v28; // eax
  ParticleSystem *v29; // eax
  ParticleGenerator *v30; // esi
  __m128 v31; // xmm0
  ParticleGenerator *v32; // eax
  ParticleSystem *v33; // eax
  double v34; // st7
  bool v35; // cf
  std::wstring v36; // [esp-14h] [ebp-164h] BYREF
  float aFrequency; // [esp+4h] [ebp-14Ch]
  int v38; // [esp+28h] [ebp-128h] BYREF
  int maxNumOfParticles; // [esp+2Ch] [ebp-124h] BYREF
  float v40; // [esp+30h] [ebp-120h]
  TyreSmoke *v41; // [esp+34h] [ebp-11Ch]
  std::wstring section; // [esp+38h] [ebp-118h] BYREF
  std::wstring a_name; // [esp+50h] [ebp-100h] BYREF
  Texture tex_grass; // [esp+68h] [ebp-E8h] BYREF
  std::wstring filename; // [esp+84h] [ebp-CCh] BYREF
  Texture tex; // [esp+9Ch] [ebp-B4h] BYREF
  INIReaderDocuments videoINI; // [esp+B8h] [ebp-98h] BYREF
  INIReader ini; // [esp+FCh] [ebp-54h] BYREF
  int v49; // [esp+14Ch] [ebp-4h]

  v4 = 0;
  maxNumOfParticles = 0;
  v41 = this;
  aFrequency = *(float *)&a_car->game;
  v36._Myres = 7;
  v36._Mysize = 0;
  v36._Bx._Buf[0] = 0;
  std::wstring::assign(&v36, L"TYRE_SMOKE", 0xAu);
  GameObject::GameObject(this, v36, (Game *)LODWORD(aFrequency));
  LODWORD(aFrequency) = this;
  v49 = 0;
  this->__vftable = (TyreSmoke_vtbl *)&TyreSmoke::`vftable';
  this->smokeEnabled = 1;
  this->pSystem = 0;
  this->pGenerator = 0;
  this->pSystemGrass = 0;
  this->pSystemGrassPieces = 0;
  this->pGeneratorGrass = 0;
  this->pGeneratorGrassPieces = 0;
  this->timeMult = 1.0;
  v36._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_de499c9c1ec8267d3760b58f8357dbd3_,0>,std::allocator<std::_Func_class<void,OnReplayStatusChanged const &>>,void,OnReplayStatusChanged const &>::`vftable';
  *(_DWORD *)&v36._Bx._Alias[4] = this;
  v36._Mysize = (unsigned int)&v36;
  v5 = &a_car->sim->evOnReplayStatusChanged;
  LOBYTE(v49) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v5,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v36,
    (void *)LODWORD(aFrequency));
  LODWORD(aFrequency) = this;
  v36._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_669f66797dc60e6795c0963c9e981de5_,0>,std::allocator<std::_Func_class<void,OnNewSessionEvent const &>>,void,OnNewSessionEvent const &>::`vftable';
  *(_DWORD *)&v36._Bx._Alias[4] = this;
  v36._Mysize = (unsigned int)&v36;
  v6 = &a_car->sim->evOnNewSession;
  LOBYTE(v49) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v6,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v36,
    this);
  LODWORD(aFrequency) = this;
  v36._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_cb4c3cfbb5db9f71e6d0829031977ee5_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
  *(_DWORD *)&v36._Bx._Alias[4] = this;
  v36._Mysize = (unsigned int)&v36;
  v7 = &a_car->sim->evOnPauseModeChanged;
  LOBYTE(v49) = 0;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v7,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v36,
    this);
  this->tyreIndex = a_tyreIndex;
  LODWORD(aFrequency) = 27;
  v36._Myres = (unsigned int)L"content/texture/smoke_0.png";
  this->car = a_car;
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, (const wchar_t *)v36._Myres, LODWORD(aFrequency));
  v8 = this->game;
  LOBYTE(v49) = 4;
  ResourceStore::getTexture(v8->graphics->resourceStore._Myptr, &tex, &filename, 0);
  LOBYTE(v49) = 6;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  aFrequency = 0.0;
  filename._Myres = 7;
  filename._Mysize = 0;
  v9 = 2000;
  filename._Bx._Buf[0] = 0;
  maxNumOfParticles = 2000;
  v36._Myres = 7;
  v36._Mysize = 0;
  v40 = FLOAT_60_0;
  v36._Bx._Buf[0] = 0;
  std::wstring::assign(&v36, L"cfg/video.ini", 0xDu);
  INIReaderDocuments::INIReaderDocuments(&videoINI, 0, v36, SLOBYTE(aFrequency));
  LOBYTE(v49) = 7;
  if ( videoINI.ready )
  {
    tex_grass.fileName._Mysize = 7;
    *(_DWORD *)&tex_grass.fileName._Bx._Alias[12] = 0;
    LOWORD(tex_grass.kid) = 0;
    std::wstring::assign((std::wstring *)&tex_grass, L"SMOKE", 5u);
    LOBYTE(v49) = 8;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"EFFECTS", 7u);
    LOBYTE(v49) = 9;
    v10 = INIReader::getInt(&videoINI, &section, (const std::wstring *)&tex_grass);
    v38 = v10;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v49) = 7;
    if ( tex_grass.fileName._Mysize >= 8 )
      operator delete(tex_grass.kid);
    _printf("SMOKE LEVEL AT %d:", v10);
    switch ( v38 )
    {
      case 0:
        _printf("eSmokeOff\n");
        this->smokeEnabled = 0;
        break;
      case 1:
        _printf("eSmokeVeryLow\n");
        v11 = FLOAT_0_050000001;
        v9 = 200;
        goto LABEL_15;
      case 2:
        _printf("eSmokeLow\n");
        v11 = FLOAT_0_1;
        v9 = 400;
        goto LABEL_15;
      case 3:
        _printf("eSmokeNormal\n");
        break;
      case 4:
        _printf("eSmokeHigh\n");
        v11 = FLOAT_120_0;
        v9 = 4000;
        goto LABEL_15;
      case 5:
        _printf("eSmokeUltra\n");
        v11 = FLOAT_240_0;
        v9 = 8000;
LABEL_15:
        v40 = v11;
        maxNumOfParticles = v9;
        break;
      default:
        break;
    }
  }
  if ( RaceManager::carsToBeLoaded > 25 )
  {
    v38 = 4000;
    v12 = &maxNumOfParticles;
    if ( v9 >= 4000 )
      v12 = &v38;
    v9 = *v12;
  }
  if ( this->smokeEnabled )
  {
    v13 = (ParticleSystem *)operator new(320);
    v38 = (int)v13;
    LOBYTE(v49) = 10;
    if ( v13 )
    {
      std::wstring::wstring(&a_name, L"TYRE_SMOKE_PARTICLE");
      LOBYTE(v49) = 11;
      LODWORD(aFrequency) = &tex;
      v14 = this->game;
      v4 = 1;
      maxNumOfParticles = 1;
      ParticleSystem::ParticleSystem(v13, &a_name, v14->graphics, v9, &tex);
    }
    else
    {
      v15 = 0;
    }
    this->pSystem = v15;
    v49 = 7;
    if ( (v4 & 1) != 0 )
    {
      v4 &= 0xFFFFFFFE;
      if ( a_name._Myres >= 8 )
        operator delete(a_name._Bx._Ptr);
    }
    v16 = (ParticleGenerator *)operator new(168);
    v38 = (int)v16;
    LOBYTE(v49) = 13;
    if ( v16 )
    {
      v17 = (__m128)LODWORD(v40);
      aFrequency = v40;
      std::wstring::wstring(&v36, L"system/cfg/tyre_smoke.ini");
      ParticleGenerator::ParticleGenerator(v16, v17, this->pSystem, v36, aFrequency);
    }
    else
    {
      v18 = 0;
    }
    aFrequency = *(float *)&this->pSystem;
    this->pGenerator = v18;
    v19 = this->car;
    LOBYTE(v49) = 7;
    v19->sim->particlesNode->addChild(v19->sim->particlesNode, (Node *)LODWORD(aFrequency));
    v20 = (ParticleSystem *)operator new(320);
    v38 = (int)v20;
    LOBYTE(v49) = 14;
    if ( v20 )
    {
      std::wstring::wstring(&a_name, L"TYRE_SMOKE_PARTICLE");
      LOBYTE(v49) = 15;
      LODWORD(aFrequency) = &tex;
      v21 = this->game;
      v4 |= 2u;
      maxNumOfParticles = v4;
      ParticleSystem::ParticleSystem(v20, &a_name, v21->graphics, v9, &tex);
    }
    else
    {
      v22 = 0;
    }
    this->pSystemGrass = v22;
    v49 = 7;
    if ( (v4 & 2) != 0 )
    {
      v4 &= 0xFFFFFFFD;
      if ( a_name._Myres >= 8 )
        operator delete(a_name._Bx._Ptr);
    }
    v23 = (ParticleGenerator *)operator new(168);
    v38 = (int)v23;
    LOBYTE(v49) = 17;
    if ( v23 )
    {
      v24 = (__m128)LODWORD(v40);
      aFrequency = v40;
      std::wstring::wstring(&v36, L"system/cfg/tyre_smoke_grass.ini");
      ParticleGenerator::ParticleGenerator(v23, v24, this->pSystemGrass, v36, aFrequency);
    }
    else
    {
      v25 = 0;
    }
    this->pGeneratorGrass = v25;
    LOBYTE(v49) = 7;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"content/texture/grass.png", 0x19u);
    v26 = this->game;
    LOBYTE(v49) = 18;
    ResourceStore::getTexture(v26->graphics->resourceStore._Myptr, &tex_grass, &section, 0);
    LOBYTE(v49) = 20;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    v27 = (ParticleSystem *)operator new(320);
    v38 = (int)v27;
    LOBYTE(v49) = 21;
    if ( v27 )
    {
      std::wstring::wstring(&a_name, L"TYRE_SMOKE_PARTICLE");
      LOBYTE(v49) = 22;
      LODWORD(aFrequency) = &tex_grass;
      v28 = this->game;
      v4 |= 4u;
      maxNumOfParticles = v4;
      ParticleSystem::ParticleSystem(v27, &a_name, v28->graphics, v9, &tex_grass);
    }
    else
    {
      v29 = 0;
    }
    this->pSystemGrassPieces = v29;
    v49 = 20;
    if ( (v4 & 4) != 0 && a_name._Myres >= 8 )
      operator delete(a_name._Bx._Ptr);
    v30 = (ParticleGenerator *)operator new(168);
    v38 = (int)v30;
    LOBYTE(v49) = 24;
    if ( v30 )
    {
      v31 = (__m128)LODWORD(v40);
      aFrequency = v40;
      std::wstring::wstring(&v36, L"system/cfg/tyre_pieces_grass.ini");
      ParticleGenerator::ParticleGenerator(v30, v31, this->pSystemGrassPieces, v36, aFrequency);
    }
    else
    {
      v32 = 0;
    }
    this->pGeneratorGrassPieces = v32;
    v33 = this->pSystemGrassPieces;
    LOBYTE(v49) = 20;
    v33->maxTimeAlive = 3.0;
    this->car->sim->particlesNode->addChild(this->car->sim->particlesNode, this->pSystemGrass);
    this->car->sim->particlesNode->addChild(this->car->sim->particlesNode, this->pSystemGrassPieces);
    LOBYTE(v49) = 7;
    OnSetupAppCreated::~OnSetupAppCreated(&tex_grass);
  }
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"system/cfg/tyre_smoke.ini", 0x19u);
  LOBYTE(v49) = 25;
  INIReader::INIReader(&ini, &section);
  LOBYTE(v49) = 27;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  a_name._Myres = 7;
  a_name._Mysize = 0;
  a_name._Bx._Buf[0] = 0;
  std::wstring::assign(&a_name, L"SLIP_LEVEL", 0xAu);
  LOBYTE(v49) = 28;
  tex_grass.fileName._Mysize = 7;
  *(_DWORD *)&tex_grass.fileName._Bx._Alias[12] = 0;
  LOWORD(tex_grass.kid) = 0;
  std::wstring::assign((std::wstring *)&tex_grass, L"TRIGGERS", 8u);
  LOBYTE(v49) = 29;
  v34 = INIReader::getFloat(&ini, (const std::wstring *)&tex_grass, &a_name);
  v35 = tex_grass.fileName._Mysize < 8;
  this->triggerSlipLevel = v34;
  if ( !v35 )
    operator delete(tex_grass.kid);
  tex_grass.fileName._Mysize = 7;
  *(_DWORD *)&tex_grass.fileName._Bx._Alias[12] = 0;
  LOWORD(tex_grass.kid) = 0;
  if ( a_name._Myres >= 8 )
    operator delete(a_name._Bx._Ptr);
  LOBYTE(v49) = 7;
  INIReader::~INIReader(&ini);
  LOBYTE(v49) = 6;
  INIReaderDocuments::~INIReaderDocuments(&videoINI);
  LOBYTE(v49) = 0;
  OnSetupAppCreated::~OnSetupAppCreated(&tex);
}
void TyreSmoke::~TyreSmoke(TyreSmoke *this)
{
  ParticleGenerator *v2; // edi
  ParticleGenerator *v3; // edi
  ParticleGenerator *v4; // edi

  this->__vftable = (TyreSmoke_vtbl *)&TyreSmoke::`vftable';
  v2 = this->pGenerator;
  if ( v2 )
  {
    ParticleGenerator::~ParticleGenerator(v2);
    operator delete(v2);
  }
  v3 = this->pGeneratorGrass;
  if ( v3 )
  {
    ParticleGenerator::~ParticleGenerator(this->pGeneratorGrass);
    operator delete(v3);
  }
  v4 = this->pGeneratorGrassPieces;
  if ( v4 )
  {
    ParticleGenerator::~ParticleGenerator(this->pGeneratorGrassPieces);
    operator delete(v4);
  }
  GameObject::~GameObject(this);
}
TyreSmoke *TyreSmoke::`scalar deleting destructor'(TyreSmoke *this, unsigned int a2)
{
  TyreSmoke::~TyreSmoke(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void TyreSmoke::onReplayStatusChanged(TyreSmoke *this, const OnReplayStatusChanged *message)
{
  eReplayStatus v3; // eax
  float v4; // xmm1_4
  eReplayStatus v5; // eax
  ParticleSystem *v6; // ecx
  ParticleSystem *v7; // ecx
  ParticleSystem *v8; // ecx

  this->isActive = message->status != eReplayPause && message->status != eReplayStop;
  v3 = message->status;
  if ( message->status == eReplaySlowMotion )
  {
    v4 = message->slowMotionLevel;
    if ( v4 > 0.0 )
      this->timeMult = 1.0 / v4;
  }
  else if ( v3 == eReplayFastForward || v3 == eReplayRewind )
  {
    this->timeMult = message->timeMult;
  }
  else
  {
    this->timeMult = 1.0;
  }
  v5 = message->status;
  if ( message->status == eReplayModeEnter
    || v5 == eReplayModeExit
    || v5 == eReplaySliderInteraction
    || v5 == eReplayStop
    || v5 == eReplayClearing )
  {
    v6 = this->pSystem;
    if ( v6 )
      ParticleSystem::clearParticles(v6);
    v7 = this->pSystemGrass;
    if ( v7 )
      ParticleSystem::clearParticles(v7);
    v8 = this->pSystemGrassPieces;
    if ( v8 )
      ParticleSystem::clearParticles(v8);
    this->timeMult = message->timeMult;
  }
}
void TyreSmoke::update(TyreSmoke *this, float deltaT)
{
  CarAvatar *v3; // ecx
  float v4; // xmm3_4
  float v5; // xmm4_4
  int v6; // xmm2_4
  float v7; // xmm1_4
  int v8; // eax
  CarAvatar *v9; // ecx
  Game *v10; // eax
  float v11; // xmm1_4
  float v12; // xmm2_4
  CarAvatar *v13; // ecx
  int v14; // edx
  CarAvatar *v15; // ecx
  Game *v16; // eax
  float v17; // xmm1_4
  float v18; // xmm2_4
  CarAvatar *v19; // ecx
  Game *v20; // eax
  float v21; // xmm1_4
  float v22; // xmm2_4
  long double v23; // [esp+8h] [ebp-18h]
  long double v24; // [esp+8h] [ebp-18h]
  long double v25; // [esp+8h] [ebp-18h]
  vec3f velocity; // [esp+14h] [ebp-Ch] BYREF
  float deltaTb; // [esp+24h] [ebp+4h]
  float deltaTa; // [esp+24h] [ebp+4h]

  if ( this->smokeEnabled )
  {
    if ( CarAvatar::isConnected(this->car) )
    {
      this->pSystem->isActive = 1;
      this->pSystemGrass->isActive = 1;
      this->pSystemGrassPieces->isActive = 1;
      deltaTb = this->timeMult * deltaT;
      ParticleSystem::step(this->pSystem, deltaTb);
      ParticleSystem::step(this->pSystemGrass, deltaTb);
      ParticleSystem::step(this->pSystemGrassPieces, deltaTb);
      v3 = this->car;
      v4 = FLOAT_1_0;
      v5 = FLOAT_8_0;
      v6 = _xmm;
      v7 = (float)((float)((float)(v3->physicsState.load[1] + v3->physicsState.load[0]) + v3->physicsState.load[2])
                 + v3->physicsState.load[3])
         * 0.125;
      deltaTa = v7;
      if ( this->timeMult > 0.0
        && (v3->physicsState.speed.value > 1.0
         || COERCE_FLOAT(LODWORD(v3->physicsState.wheelAngularSpeed[this->tyreIndex]) & _xmm) > 8.0) )
      {
        v8 = this->tyreIndex;
        if ( COERCE_FLOAT(LODWORD(v3->physicsState.slipRatio[v8]) & _xmm) > this->triggerSlipLevel
          && v3->physicsState.load[v8] > v7
          && v3->physicsState.tyreSurfaceDef[v8].gripMod >= 0.89999998 )
        {
          if ( CarAvatar::isConnected(v3) )
          {
            v9 = this->car;
            v10 = this->game;
            v11 = v9->physicsState.velocity.y;
            v12 = v9->physicsState.velocity.z;
            velocity.x = v9->physicsState.velocity.x * 0.0099999998;
            v23 = this->timeMult;
            velocity.y = (float)(v11 * 0.0099999998) + 1.0;
            velocity.z = v12 * 0.0099999998;
            ParticleGenerator::generateParticle(
              this->pGenerator,
              &v9->physicsState.tyreContactPoint[this->tyreIndex],
              &velocity,
              v10->gameTime.now,
              v23);
          }
          v5 = FLOAT_8_0;
          v4 = FLOAT_1_0;
          v6 = _xmm;
          v7 = deltaTa;
        }
      }
      if ( this->timeMult > 0.0 )
      {
        v13 = this->car;
        if ( v13->physicsState.speed.value > v4
          || COERCE_FLOAT(LODWORD(v13->physicsState.wheelAngularSpeed[this->tyreIndex]) & v6) > v5 )
        {
          v14 = this->tyreIndex;
          if ( COERCE_FLOAT(LODWORD(v13->physicsState.tyreSurfaceDef[v14].dirtAdditiveK) & v6) > 0.1
            && v13->physicsState.load[v14] > v7
            && CarAvatar::isConnected(v13) )
          {
            v15 = this->car;
            v16 = this->game;
            v17 = v15->physicsState.velocity.y;
            v18 = v15->physicsState.velocity.z;
            velocity.x = v15->physicsState.velocity.x * 0.0099999998;
            v24 = this->timeMult;
            velocity.y = (float)(v17 * 0.0099999998) + 1.0;
            velocity.z = v18 * 0.0099999998;
            ParticleGenerator::generateParticle(
              this->pGeneratorGrassPieces,
              &v15->physicsState.tyreContactPoint[this->tyreIndex],
              &velocity,
              v16->gameTime.now,
              v24);
            v19 = this->car;
            v20 = this->game;
            v21 = v19->physicsState.velocity.y;
            v22 = v19->physicsState.velocity.z;
            velocity.x = v19->physicsState.velocity.x * 0.0099999998;
            v25 = this->timeMult;
            velocity.y = (float)(v21 * 0.0099999998) + 1.0;
            velocity.z = v22 * 0.0099999998;
            ParticleGenerator::generateParticle(
              this->pGeneratorGrass,
              &v19->physicsState.tyreContactPoint[this->tyreIndex],
              &velocity,
              v20->gameTime.now,
              v25);
          }
        }
      }
    }
    else
    {
      ParticleSystem::disable(this->pSystem);
      ParticleSystem::disable(this->pSystemGrass);
      ParticleSystem::disable(this->pSystemGrassPieces);
    }
  }
}
