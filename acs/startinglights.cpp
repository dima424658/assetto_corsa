#include "startinglights.h
void StartingLights::StartingLights(StartingLights *this, Sim *sim)
{
  Sim *v3; // edi
  Game *v4; // eax
  Texture *v5; // eax
  __m128 v6; // xmm1
  int v7; // eax
  std::wstring *v8; // eax
  const std::wstring *v9; // eax
  vec3f *v10; // eax
  float v11; // xmm2_4
  float v12; // xmm1_4
  ICollisionObject *v13; // eax
  std::wstring *v14; // eax
  Mesh *v15; // edi
  Material *v16; // eax
  Material *v17; // eax
  std::_Ref_count_base *v18; // edx
  Material *v19; // ebx
  volatile signed __int32 *v20; // esi
  MaterialVar *v21; // eax
  MaterialVar *v22; // eax
  MaterialVar *v23; // eax
  std::_Ref_count_base *v24; // esi
  std::wstring v25; // [esp-1Ch] [ebp-160h] BYREF
  int v26; // [esp-4h] [ebp-148h]
  ICollisionObject *_Val; // [esp+18h] [ebp-12Ch] BYREF
  float v28; // [esp+1Ch] [ebp-128h]
  vec3f emissive; // [esp+20h] [ebp-124h]
  __m128i v30; // [esp+2Ch] [ebp-118h] BYREF
  StartingLights *v31; // [esp+40h] [ebp-104h]
  std::vector<TrackStartingLight> *v32; // [esp+44h] [ebp-100h]
  Sim *v33; // [esp+48h] [ebp-FCh]
  StartingLights *v34; // [esp+4Ch] [ebp-F8h]
  std::wstring filename; // [esp+50h] [ebp-F4h] BYREF
  std::wstring result; // [esp+68h] [ebp-DCh] BYREF
  TrackStartingLight tsl; // [esp+80h] [ebp-C4h] BYREF
  std::wstring section; // [esp+9Ch] [ebp-A8h] BYREF
  std::wstring meshname; // [esp+B4h] [ebp-90h] BYREF
  std::wstring v40; // [esp+CCh] [ebp-78h] BYREF
  INIReader ini; // [esp+E4h] [ebp-60h] BYREF
  int v42; // [esp+140h] [ebp-4h]

  v31 = this;
  v3 = sim;
  v34 = this;
  v33 = sim;
  v26 = (int)sim->game;
  v25._Myres = 7;
  v25._Mysize = 0;
  v25._Bx._Buf[0] = 0;
  std::wstring::assign(&v25, L"STARTING_LIGHTS", 0xFu);
  GameObject::GameObject(this, v25, (Game *)v26);
  this->__vftable = (StartingLights_vtbl *)&StartingLights::`vftable';
  this->texOFF.kid = 0;
  this->texOFF.fileName._Myres = 7;
  this->texOFF.fileName._Mysize = 0;
  v42 = 0;
  this->texOFF.fileName._Bx._Buf[0] = 0;
  this->sim = sim;
  this->lights._Myfirst = 0;
  this->lights._Mylast = 0;
  this->lights._Myend = 0;
  this->colours[0].x = 0.0;
  this->colours[0].y = 0.0;
  this->colours[0].z = 0.0;
  this->colours[1].x = 0.0;
  this->colours[1].y = 0.0;
  this->colours[1].z = 0.0;
  this->colours[2].x = 0.0;
  this->colours[2].y = 0.0;
  this->colours[2].z = 0.0;
  this->randomTimeOffsetStart = 0.0;
  this->randomTimeOffsetRedWait = 0.0;
  v30.m128i_i64[0] = 0i64;
  v32 = &this->trackLights;
  this->trackLights._Myfirst = 0;
  this->trackLights._Mylast = 0;
  this->trackLights._Myend = 0;
  v26 = (int)this;
  this->lightsON = 0;
  v25._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_7b20f34712fe391a229c201c78115743_,0>,std::allocator<std::_Func_class<void,OnReplayStatusChanged const &>>,void,OnReplayStatusChanged const &>::`vftable';
  *(_DWORD *)&v25._Bx._Alias[4] = this;
  v25._Mysize = (unsigned int)&v25;
  LOBYTE(v42) = 3;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&sim->evOnReplayStatusChanged,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v25,
    (void *)v26);
  v25._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_d10444b5017a0be549ef3857e79b6e96_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
  *(_DWORD *)&v25._Bx._Alias[4] = this;
  v25._Mysize = (unsigned int)&v25;
  LOBYTE(v42) = 3;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)&sim->evOnPauseModeChanged,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v25,
    this);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"content/texture/off.png", 0x17u);
  v4 = this->game;
  LOBYTE(v42) = 6;
  v5 = ResourceStore::getTexture(v4->graphics->resourceStore._Myptr, (Texture *)&tsl, &filename, 0);
  this->texOFF.kid = v5->kid;
  LOBYTE(v42) = 7;
  if ( &this->texOFF.fileName != &v5->fileName )
    std::wstring::assign(&this->texOFF.fileName, &v5->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v42) = 6;
  OnSetupAppCreated::~OnSetupAppCreated((Texture *)&tsl);
  LOBYTE(v42) = 3;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  *(float *)&_Val = 0.0;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->lights, &_Val);
  *(float *)&_Val = 0.0;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->lights, &_Val);
  *(float *)&_Val = 0.0;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->lights, &_Val);
  *(float *)&_Val = 0.0;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->lights, &_Val);
  *(float *)&_Val = 0.0;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->lights, &_Val);
  *(float *)&_Val = 0.0;
  std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&this->lights, &_Val);
  v6 = (__m128)_mm_loadl_epi64(&v30);
  *(_QWORD *)&this->colours[0].x = _mm_unpacklo_ps((__m128)LODWORD(FLOAT_0_5), (__m128)LODWORD(FLOAT_0_5)).m128_u64[0];
  *(_QWORD *)&this->colours[1].x = _mm_unpacklo_ps((__m128)LODWORD(FLOAT_3_0), v6).m128_u64[0];
  this->colours[0].z = 0.5;
  this->colours[1].z = 0.0;
  emissive.z = 0.0;
  *(_QWORD *)&this->colours[2].x = _mm_unpacklo_ps(v6, (__m128)LODWORD(FLOAT_1_0)).m128_u64[0];
  this->colours[2].z = 0.0;
  this->randomTimeOffsetStart = (float)((float)((float)_rand() * 0.000030518509) * 1000.0) - 500.0;
  v7 = _rand();
  v26 = (int)&filename;
  this->randomTimeOffsetRedWait = (float)((float)((float)v7 * 0.000030518509) * 1000.0) - 500.0;
  v8 = TrackAvatar::getDataFolder(sim->track, (std::wstring *)v26);
  LOBYTE(v42) = 8;
  v9 = std::operator+<wchar_t>(&result, v8, L"/data/startinglights.ini");
  LOBYTE(v42) = 9;
  INIReader::INIReader(&ini, v9);
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  LOBYTE(v42) = 12;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"SETTINGS", 8u);
    LOBYTE(v42) = 13;
    if ( INIReader::hasSection(&ini, &section) )
    {
      std::wstring::wstring(&meshname, L"INTENSITY");
      LOBYTE(v42) = 14;
      std::wstring::wstring(&filename, L"EMISSIVE");
      LOBYTE(v42) = 15;
      *(float *)&_Val = INIReader::getFloat(&ini, &section, &meshname);
      v10 = INIReader::getFloat3(&ini, (vec3f *)&v30, &section, &filename);
      v11 = v10->y * *(float *)&_Val;
      v12 = v10->z * *(float *)&_Val;
      emissive.x = *(float *)&_Val * v10->x;
      emissive.y = v11;
      emissive.z = v12;
      if ( filename._Myres >= 8 )
        operator delete(filename._Bx._Ptr);
      filename._Myres = 7;
      filename._Mysize = 0;
      filename._Bx._Buf[0] = 0;
      LOBYTE(v42) = 13;
      if ( meshname._Myres >= 8 )
        operator delete(meshname._Bx._Ptr);
      v13 = 0;
      *(float *)&_Val = 0.0;
      while ( 1 )
      {
        v14 = std::to_wstring(&v40, (int)v13);
        LOBYTE(v42) = 16;
        std::operator+<wchar_t>(&meshname, L"KS_START_LIGHT_", v14);
        LOBYTE(v42) = 18;
        if ( v40._Myres >= 8 )
          operator delete(v40._Bx._Ptr);
        v26 = 1;
        v40._Myres = 7;
        v40._Mysize = 0;
        v40._Bx._Buf[0] = 0;
        v25._Mysize = 0;
        v25._Myres = 7;
        v25._Bx._Buf[0] = 0;
        std::wstring::assign(&v25, &meshname, 0, 0xFFFFFFFF);
        v15 = Node::getNodeChild<Mesh>(v3->trackNode, v25, v26);
        if ( !v15 )
          break;
        tsl.material._Ptr = 0;
        tsl.material._Rep = 0;
        tsl.materialVar = 0;
        LOBYTE(v42) = 19;
        tsl.emissive = emissive;
        tsl.targetMesh = v15;
        v16 = (Material *)operator new(104);
        v28 = *(float *)&v16;
        LOBYTE(v42) = 20;
        if ( v16 )
          Material::Material(v16, v15->material._Ptr);
        else
          v17 = 0;
        LOBYTE(v42) = 19;
        v30.m128i_i64[0] = 0i64;
        std::shared_ptr<Material>::_Resetp<Material>((std::shared_ptr<Material> *)&v30, v17);
        v18 = (std::_Ref_count_base *)v30.m128i_i32[1];
        v19 = (Material *)v30.m128i_i32[0];
        v30.m128i_i64[0] = 0i64;
        tsl.material._Rep = v18;
        tsl.material._Ptr = v19;
        if ( v18 )
          _InterlockedExchangeAdd((volatile signed __int32 *)&v18->_Uses, 1u);
        v20 = (volatile signed __int32 *)v15->material._Rep;
        v15->material._Rep = v18;
        v15->material._Ptr = v19;
        if ( v20 )
        {
          if ( !_InterlockedExchangeAdd(v20 + 1, 0xFFFFFFFF) )
          {
            (**(void (***)(volatile signed __int32 *))v20)(v20);
            if ( !_InterlockedExchangeAdd(v20 + 2, 0xFFFFFFFF) )
              (*(void (**)(volatile signed __int32 *))(*v20 + 4))(v20);
          }
        }
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        std::wstring::assign(&result, L"DIFFUSE", 7u);
        LOBYTE(v42) = 21;
        filename._Myres = 7;
        filename._Mysize = 0;
        filename._Bx._Buf[0] = 0;
        std::wstring::assign(&filename, L"ksDiffuse", 9u);
        LOBYTE(v42) = 22;
        v28 = INIReader::getFloat(&ini, &section, &result);
        v21 = Material::getVar(v19, &filename);
        v21->fValue = v28;
        MaterialVar::set(v21);
        if ( filename._Myres >= 8 )
          operator delete(filename._Bx._Ptr);
        filename._Myres = 7;
        filename._Mysize = 0;
        filename._Bx._Buf[0] = 0;
        LOBYTE(v42) = 19;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        std::wstring::assign(&result, L"DIFFUSE", 7u);
        LOBYTE(v42) = 23;
        filename._Myres = 7;
        filename._Mysize = 0;
        filename._Bx._Buf[0] = 0;
        std::wstring::assign(&filename, L"ksAmbient", 9u);
        LOBYTE(v42) = 24;
        v28 = INIReader::getFloat(&ini, &section, &result);
        v22 = Material::getVar(v19, &filename);
        v22->fValue = v28;
        MaterialVar::set(v22);
        if ( filename._Myres >= 8 )
          operator delete(filename._Bx._Ptr);
        filename._Myres = 7;
        filename._Mysize = 0;
        filename._Bx._Buf[0] = 0;
        LOBYTE(v42) = 19;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        std::wstring::assign(&result, L"ksSpecular", 0xAu);
        LOBYTE(v42) = 25;
        v23 = Material::getVar(v19, &result);
        v23->fValue = 0.0;
        MaterialVar::set(v23);
        LOBYTE(v42) = 19;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        result._Myres = 7;
        result._Mysize = 0;
        result._Bx._Buf[0] = 0;
        std::wstring::assign(&result, L"ksEmissive", 0xAu);
        LOBYTE(v42) = 26;
        tsl.materialVar = Material::getVar(v19, &result);
        LOBYTE(v42) = 19;
        if ( result._Myres >= 8 )
          operator delete(result._Bx._Ptr);
        std::vector<TrackStartingLight>::push_back(v32, &tsl);
        v24 = tsl.material._Rep;
        v13 = (ICollisionObject *)((char *)&_Val->__vftable + 1);
        _Val = (ICollisionObject *)((char *)_Val + 1);
        LOBYTE(v42) = 18;
        if ( tsl.material._Rep )
        {
          if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&tsl.material._Rep->_Uses, 0xFFFFFFFF) )
          {
            v24->_Destroy(v24);
            if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&v24->_Weaks, 0xFFFFFFFF) )
              v24->_Delete_this(v24);
          }
          v13 = _Val;
        }
        v3 = v33;
        LOBYTE(v42) = 13;
        if ( meshname._Myres >= 8 )
        {
          operator delete(meshname._Bx._Ptr);
          v13 = _Val;
        }
      }
      if ( meshname._Myres >= 8 )
        operator delete(meshname._Bx._Ptr);
    }
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
  }
  LOBYTE(v42) = 3;
  INIReader::~INIReader(&ini);
}
void StartingLights::~StartingLights(StartingLights *this)
{
  std::vector<TrackStartingLight> *v2; // esi

  this->__vftable = (StartingLights_vtbl *)&StartingLights::`vftable';
  v2 = &this->trackLights;
  if ( this->trackLights._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->trackLights);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<TrackStartingLight>>>(v2->_Myfirst, v2->_Mylast);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  if ( this->lights._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->lights);
    operator delete(this->lights._Myfirst);
    this->lights._Myfirst = 0;
    this->lights._Mylast = 0;
    this->lights._Myend = 0;
  }
  OnSetupAppCreated::~OnSetupAppCreated(&this->texOFF);
  GameObject::~GameObject(this);
}
StartingLights *StartingLights::`vector deleting destructor'(StartingLights *this, unsigned int a2)
{
  StartingLights::~StartingLights(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void StartingLights::renderHUD(StartingLights *this, float deltaT)
{
  Sim *v3; // ecx
  char v4; // bl
  ACClient *v5; // eax
  double v6; // xmm1_8
  Session *v7; // eax
  char v8; // cl
  float v9; // xmm1_4
  float v10; // xmm2_4
  float v11; // xmm0_4
  int v12; // eax
  float v13; // xmm1_4
  __m128i v14; // xmm0
  int v15; // edi
  unsigned int v16; // ecx
  GraphicsManager *v17; // eax
  float v18; // xmm3_4
  float v19; // xmm1_4
  __m128 v20; // xmm4
  float v21; // xmm2_4
  int v22; // ecx
  TrackStartingLight *v23; // edi
  TrackStartingLight *v24; // esi
  __m128 v25; // xmm3
  __m128 v26; // xmm0
  MaterialVar *v27; // ecx
  float v28; // eax
  TrackStartingLight *v29; // edi
  TrackStartingLight *v30; // esi
  MaterialVar *v31; // ecx
  eStartLightColour *v32; // [esp-4h] [ebp-A8h]
  eStartLightColour *v33; // [esp-4h] [ebp-A8h]
  eStartLightColour *v34; // [esp+0h] [ebp-A4h]
  eStartLightColour *v35; // [esp+0h] [ebp-A4h]
  float timeToStart; // [esp+14h] [ebp-90h] BYREF
  float all_red_time; // [esp+18h] [ebp-8Ch] BYREF
  float cc; // [esp+1Ch] [ebp-88h] BYREF
  float i; // [esp+20h] [ebp-84h]
  StartingLights::renderHUD::__l30::<lambda_fa340b727ec482ed946200e5cd0eacda> _Func; // [esp+24h] [ebp-80h] BYREF
  float step; // [esp+38h] [ebp-6Ch] BYREF
  float px; // [esp+3Ch] [ebp-68h] BYREF
  RemoteSession ses; // [esp+40h] [ebp-64h] BYREF

  all_red_time = 0.0;
  v3 = this->sim;
  if ( v3->pauseMenu->visible )
    return;
  timeToStart = 0.0;
  v4 = 0;
  v5 = v3->client;
  if ( !v5 )
  {
    if ( RaceManager::hasSessionStarted(v3->raceManager) )
    {
      v8 = LOBYTE(all_red_time);
    }
    else
    {
      v7 = RaceManager::getCurrentSession(this->sim->raceManager, (Session *)&ses);
      v8 = 1;
      if ( v7->sessionType == Race )
      {
        v4 = 1;
LABEL_13:
        if ( (v8 & 1) != 0 )
          Session::~Session((Session *)&ses);
        timeToStart = RaceManager::getTimeToSessionStart(this->sim->raceManager);
        goto LABEL_16;
      }
    }
    v4 = 0;
    goto LABEL_13;
  }
  ACClient::getCurrentSession(v5, &ses);
  if ( ses.type == Race )
  {
    v6 = this->game->gameTime.now;
    if ( ses.startTime > v6 )
    {
      v4 = 1;
      timeToStart = ses.startTime - v6;
    }
  }
  if ( ses.name._Myres >= 8 )
    operator delete(ses.name._Bx._Ptr);
LABEL_16:
  if ( v4 )
  {
    if ( debug_counter <= 10 )
    {
      ++debug_counter;
    }
    else
    {
      debug_counter = 0;
      _printf("Starting light should show. TTS: %f\n", timeToStart);
    }
    v9 = this->randomTimeOffsetStart;
    v10 = v9 + 4000.0;
    v11 = (float)(v9 + 3000.0) + this->randomTimeOffsetRedWait;
    i = v9 + 4000.0;
    all_red_time = v11;
    if ( (float)(v9 + 15000.0) > timeToStart )
    {
      v12 = this->lights._Mylast - this->lights._Myfirst;
      _Func.__this = this;
      _Func.timeToStart = &timeToStart;
      _Func.all_red_time = &all_red_time;
      _Func.step = &step;
      v13 = (float)(unsigned int)v12;
      _Func.cc = &cc;
      v34 = this->lights._Mylast;
      step = v10 / v13;
      v14 = _mm_loadu_si128((const __m128i *)&_Func);
      v32 = this->lights._Myfirst;
      cc = v13;
      *(__m128i *)&_Func.timeToStart = v14;
      std::_For_each<enum eStartLightColour *,_lambda_fa340b727ec482ed946200e5cd0eacda_>(v32, v34, &_Func);
      v15 = this->lights._Mylast - this->lights._Myfirst;
      v16 = this->texOFF.kid ? kglTextureGetWidth(this->texOFF.kid) : 0;
      v17 = this->game->graphics;
      _Func.timeToStart = (float *)this;
      v18 = (float)v17->videoSettings.width;
      _Func.all_red_time = &px;
      v19 = (float)v16;
      v35 = this->lights._Mylast;
      v33 = this->lights._Myfirst;
      px = (float)(v18 * 0.5) - (float)((float)(v19 * (float)(unsigned int)v15) * 0.5);
      std::_For_each<enum eStartLightColour *,_lambda_c0c2aa218c2af9472482a9d96df5d332_>(
        v33,
        v35,
        (StartingLights::renderHUD::__l31::<lambda_c0c2aa218c2af9472482a9d96df5d332> *)&_Func);
      v20 = 0i64;
      v21 = (float)(unsigned int)(this->trackLights._Mylast - this->trackLights._Myfirst);
      cc = v21;
      if ( v21 > 0.0 )
      {
        v22 = (char *)this->trackLights._Mylast - (char *)this->trackLights._Myfirst;
        v25 = (__m128)LODWORD(i);
        v23 = this->trackLights._Mylast;
        v24 = this->trackLights._Myfirst;
        v25.m128_f32[0] = i / (float)(unsigned int)(v22 / 28);
        for ( i = v25.m128_f32[0]; v24 != v23; cc = cc - 1.0 )
        {
          v26 = v25;
          v27 = v24->materialVar;
          if ( (float)(timeToStart - all_red_time) <= (float)(v25.m128_f32[0] * v21) )
          {
            *(_QWORD *)&v27->fValue3.x = *(_QWORD *)&v24->emissive.x;
            v28 = v24->emissive.z;
          }
          else
          {
            v26.m128_f32[0] = v20.m128_f32[0];
            _Func.step = 0;
            v28 = 0.0;
            *(_QWORD *)&v27->fValue3.x = _mm_unpacklo_ps(v26, v20).m128_u64[0];
          }
          v27->fValue3.z = v28;
          MaterialVar::set(v27);
          ++v24;
          v25 = (__m128)LODWORD(i);
          v20 = 0i64;
          v21 = cc - 1.0;
        }
      }
    }
  }
  else if ( this->lightsON )
  {
    this->lightsON = 0;
    v29 = this->trackLights._Mylast;
    v30 = this->trackLights._Myfirst;
    if ( v30 != v29 )
    {
      _Func.step = 0;
      _Func.timeToStart = 0;
      _Func.all_red_time = 0;
      do
      {
        v31 = v30->materialVar;
        *(_QWORD *)&v31->fValue3.x = *(_QWORD *)&_Func.timeToStart;
        v31->fValue3.z = 0.0;
        MaterialVar::set(v31);
        ++v30;
      }
      while ( v30 != v29 );
    }
  }
}
void StartingLights::renderLight(StartingLights *this, float x, float y, vec3f colour)
{
  GLRenderer *v5; // ebx
  Texture *v6; // edi
  unsigned int v7; // esi
  unsigned int v8; // eax
  float v9; // xmm0_4
  float width; // xmm0_4
  float r; // [esp+Ch] [ebp-18h]

  v5 = this->game->graphics->gl;
  GLRenderer::color3f(v5, colour.x, colour.y, colour.z);
  v6 = &this->texOFF;
  GraphicsManager::setTexture(this->game->graphics, 0, &this->texOFF);
  GLRenderer::begin(v5, eQuads, 0);
  if ( this->texOFF.kid )
    v7 = kglTextureGetHeight(v6->kid);
  else
    v7 = 0;
  if ( v6->kid )
    v8 = kglTextureGetWidth(v6->kid);
  else
    v8 = 0;
  v9 = (float)v7;
  r = v9;
  width = (float)v8;
  GLRenderer::quad(v5, x, y, width, r, 1, 0);
  GLRenderer::end(v5);
}
