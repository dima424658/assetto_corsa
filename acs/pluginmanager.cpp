#include "pluginmanager.h
void PluginManager::PluginManager(PluginManager *this, Sim *isim)
{
  std::wstring v3; // [esp-1Ch] [ebp-38h] BYREF
  Game *v4; // [esp-4h] [ebp-20h]
  PluginManager *v5; // [esp+Ch] [ebp-10h]
  int v6; // [esp+18h] [ebp-4h]

  v5 = this;
  v4 = isim->game;
  v3._Myres = 7;
  v3._Mysize = 0;
  v3._Bx._Buf[0] = 0;
  std::wstring::assign(&v3, L"PLUGIN MANAGER", 0xEu);
  GameObject::GameObject(this, v3, v4);
  this->__vftable = (PluginManager_vtbl *)&PluginManager::`vftable';
  v6 = 0;
  this->plugins._Myfirst = 0;
  this->plugins._Mylast = 0;
  this->plugins._Myend = 0;
  v4 = 0;
  LOBYTE(v6) = 1;
  this->closing = 0;
  this->sim = isim;
  this->car = Sim::getCar(isim, (unsigned int)v4);
  PluginManager::loadPlugins(this);
}
PluginManager *PluginManager::`vector deleting destructor'(PluginManager *this, unsigned int a2)
{
  this->__vftable = (PluginManager_vtbl *)&PluginManager::`vftable';
  if ( this->plugins._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->plugins);
    operator delete(this->plugins._Myfirst);
    this->plugins._Myfirst = 0;
    this->plugins._Mylast = 0;
    this->plugins._Myend = 0;
  }
  GameObject::~GameObject(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void PluginManager::loadPlugins(PluginManager *this)
{
  std::wstring *v1; // esi
  std::wstring *v2; // edi
  int v3; // ebx
  const wchar_t *v4; // eax
  std::wstring *v5; // eax
  HMODULE v6; // ebx
  DWORD v7; // eax
  FARPROC acpGetName; // eax
  ICollisionObject *v9; // eax
  ICollisionObject *v10; // eax
  const wchar_t *v11; // eax
  std::wstring *v12; // eax
  std::wstring *v13; // edi
  std::wstring *v14; // esi
  std::vector<std::wstring> files; // [esp+14h] [ebp-2B0h] BYREF
  ICollisionObject *_Val; // [esp+20h] [ebp-2A4h] BYREF
  PluginManager *v17; // [esp+24h] [ebp-2A0h]
  std::wstring section; // [esp+28h] [ebp-29Ch] BYREF
  std::wstring ifilename; // [esp+40h] [ebp-284h] BYREF
  std::wstring filter; // [esp+58h] [ebp-26Ch] BYREF
  INIReader r; // [esp+70h] [ebp-254h] BYREF
  wchar_t buffer[256]; // [esp+B4h] [ebp-210h] BYREF
  int v23; // [esp+2C0h] [ebp-4h]

  v17 = this;
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"plugins/plugins.ini", 0x13u);
  v23 = 0;
  INIReader::INIReader(&r, &ifilename);
  LOBYTE(v23) = 2;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  _printf("\n_________________________________________________________\n");
  _printf("INITIALISING PLUGINS\n");
  _printf("_________________________________________________________\n");
  filter._Myres = 7;
  filter._Mysize = 0;
  filter._Bx._Buf[0] = 0;
  std::wstring::assign(&filter, L"plugins/*.dll", 0xDu);
  LOBYTE(v23) = 3;
  Path::getFiles(&files, &filter);
  LOBYTE(v23) = 5;
  if ( filter._Myres >= 8 )
    operator delete(filter._Bx._Ptr);
  v1 = files._Myfirst;
  v2 = files._Mylast;
  filter._Myres = 7;
  filter._Mysize = 0;
  for ( filter._Bx._Buf[0] = 0; v1 != v2; ++v1 )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"PLUGINS", 7u);
    LOBYTE(v23) = 6;
    v3 = INIReader::getInt(&r, &section, v1);
    LOBYTE(v23) = 5;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    if ( v3 )
    {
      if ( v1->_Myres < 8 )
        v4 = (const wchar_t *)v1;
      else
        v4 = v1->_Bx._Ptr;
      _printf("Checking plugin: %S\n", v4);
      v5 = std::operator+<wchar_t>(&section, L"plugins/", v1);
      if ( v5->_Myres >= 8 )
        v5 = (std::wstring *)v5->_Bx._Ptr;
      v6 = LoadLibraryW(v5->_Bx._Buf);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      v7 = GetLastError();
      if ( v6 )
      {
        acpGetName = GetProcAddress(v6, "acpGetName");
        if ( acpGetName )
        {
          ((void (__cdecl *)(wchar_t *))acpGetName)(buffer);
          _printf("ACP PLUGIN: %S\n", buffer);
          v9 = (ICollisionObject *)operator new(68);
          _Val = v9;
          LOBYTE(v23) = 7;
          if ( v9 )
            ACPlugin::ACPlugin((ACPlugin *)v9, v17->sim, v6);
          else
            v10 = 0;
          _Val = v10;
          LOBYTE(v23) = 5;
          std::vector<SpinnerData *>::push_back((std::vector<ICollisionObject *> *)&v17->plugins, &_Val);
        }
        else
        {
          if ( v1->_Myres < 8 )
            v11 = (const wchar_t *)v1;
          else
            v11 = v1->_Bx._Ptr;
          _printf("Loading ACP plugin error: %S\n", v11);
          FreeLibrary(v6);
        }
      }
      else
      {
        _printf("LOAD PLUGIN ERROR %u\n", v7);
      }
    }
    else
    {
      if ( v1->_Myres < 8 )
        v12 = v1;
      else
        v12 = (std::wstring *)v1->_Bx._Ptr;
      _printf("Ignoring plugin: %S\n", v12);
    }
  }
  _printf("\n");
  LOBYTE(v23) = 2;
  if ( files._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&files);
    v13 = files._Mylast;
    v14 = files._Myfirst;
    if ( files._Myfirst != files._Mylast )
    {
      do
      {
        if ( v14->_Myres >= 8 )
          operator delete(v14->_Bx._Ptr);
        v14->_Myres = 7;
        v14->_Mysize = 0;
        v14->_Bx._Buf[0] = 0;
        ++v14;
      }
      while ( v14 != v13 );
      v14 = files._Myfirst;
    }
    operator delete(v14);
    files._Myfirst = 0;
    files._Mylast = 0;
    files._Myend = 0;
  }
  v23 = -1;
  INIReader::~INIReader(&r);
}
void PluginManager::renderHUD(PluginManager *this, float dt)
{
  ACPlugin **v2; // eax
  ACPlugin **v3; // esi
  unsigned int v4; // ebx
  int v5; // edi
  ACPluginContext v6; // [esp+1h] [ebp-1h] BYREF

  v6 = (ACPluginContext)HIBYTE(this);
  if ( !this->closing )
  {
    v2 = this->plugins._Mylast;
    v3 = this->plugins._Myfirst;
    v4 = (unsigned int)((char *)v2 - (char *)v3 + 3) >> 2;
    v5 = 0;
    if ( v3 > v2 )
      v4 = 0;
    if ( v4 )
    {
      do
      {
        ACPlugin::onGui(*v3, &v6);
        ++v5;
        ++v3;
      }
      while ( v5 != v4 );
    }
  }
}
void PluginManager::shutdown(PluginManager *this)
{
  FILE *v2; // eax
  ACPlugin **v3; // ebx
  std::vector<ACPlugin *> *v4; // ebp
  ACPlugin **v5; // esi
  int v6; // edi
  unsigned int v7; // ebx

  this->closing = 1;
  _printf("closing pluginManager\n");
  v2 = ___iob_func();
  _fflush(v2 + 1);
  v3 = this->plugins._Mylast;
  v4 = &this->plugins;
  v5 = this->plugins._Myfirst;
  v6 = 0;
  v7 = (unsigned int)((char *)v3 - (char *)v5 + 3) >> 2;
  if ( v5 > v4->_Mylast )
    v7 = 0;
  if ( v7 )
  {
    do
    {
      if ( *v5 )
        ((void (*)(ACPlugin *, int))(*v5)->~ACPlugin)(*v5, 1);
      ++v6;
      ++v5;
    }
    while ( v6 != v7 );
  }
  std::_Container_base0::_Orphan_all(v4);
  v4->_Mylast = v4->_Myfirst;
}
void PluginManager::update(PluginManager *this, float deltaT)
{
  CarAvatar *v3; // ecx
  int v4; // eax
  int v5; // eax
  CarAvatar *v6; // ecx
  float v7; // xmm1_4
  float v8; // xmm2_4
  Node *v9; // eax
  int v10; // eax
  CarAvatar *v11; // ecx
  float v12; // xmm1_4
  float v13; // xmm2_4
  Node *v14; // eax
  int v15; // eax
  CarAvatar *v16; // ecx
  float v17; // xmm1_4
  float v18; // xmm2_4
  Node *v19; // eax
  int v20; // eax
  CarAvatar *v21; // ecx
  float v22; // xmm1_4
  float v23; // xmm2_4
  vec3f *v24; // eax
  CarAvatar *v25; // ecx
  Node *v26; // eax
  ACPlugin **v27; // eax
  ACPlugin **v28; // esi
  int v29; // edi
  unsigned int v30; // ebx
  vec3f pos; // [esp+30h] [ebp-1A4h] BYREF
  vec3f result; // [esp+3Ch] [ebp-198h] BYREF
  mat44f v33; // [esp+48h] [ebp-18Ch] BYREF
  ACCarState state; // [esp+88h] [ebp-14Ch] BYREF

  if ( !this->closing )
  {
    if ( !this->car )
      this->car = Sim::getCar(this->sim, 0);
    v3 = this->car;
    *(_QWORD *)state.accG = *(_QWORD *)&v3->physicsState.accG.x;
    state.accG[2] = v3->physicsState.accG.z;
    *(_QWORD *)state.localAngularVelocity = *(_QWORD *)&v3->physicsState.localAngularVelocity.x;
    state.localAngularVelocity[2] = v3->physicsState.localAngularVelocity.z;
    *(_QWORD *)state.worldVelocity = *(_QWORD *)&v3->physicsState.velocity.x;
    state.worldVelocity[2] = v3->physicsState.velocity.z;
    *(_QWORD *)state.localVelocity = *(_QWORD *)&v3->physicsState.localVelocity.x;
    state.localVelocity[2] = v3->physicsState.localVelocity.z;
    v4 = (int)v3->suspensionAvatar->getWheelTransform(v3->suspensionAvatar, 0);
    v5 = (*(int (**)(int, mat44f *))(*(_DWORD *)v4 + 32))(v4, &v33);
    v6 = this->car;
    v7 = *(float *)(v5 + 52);
    v8 = *(float *)(v5 + 56);
    pos.x = *(float *)(v5 + 48);
    pos.y = v7;
    pos.z = v8;
    *(vec3f *)state.wheelLF_localPos = *Node::worldToLocal(v6->bodyTransform, &result, &pos);
    v9 = this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, 1);
    v10 = (int)v9->getWorldMatrix(v9, &v33);
    v11 = this->car;
    v12 = *(float *)(v10 + 52);
    v13 = *(float *)(v10 + 56);
    pos.x = *(float *)(v10 + 48);
    pos.y = v12;
    pos.z = v13;
    *(vec3f *)state.wheelRF_localPos = *Node::worldToLocal(v11->bodyTransform, &result, &pos);
    v14 = this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, 2);
    v15 = (int)v14->getWorldMatrix(v14, &v33);
    v16 = this->car;
    v17 = *(float *)(v15 + 52);
    v18 = *(float *)(v15 + 56);
    pos.x = *(float *)(v15 + 48);
    pos.y = v17;
    pos.z = v18;
    *(vec3f *)state.wheelLR_localPos = *Node::worldToLocal(v16->bodyTransform, &result, &pos);
    v19 = this->car->suspensionAvatar->getWheelTransform(this->car->suspensionAvatar, 3);
    v20 = (int)v19->getWorldMatrix(v19, &v33);
    v21 = this->car;
    v22 = *(float *)(v20 + 52);
    v23 = *(float *)(v20 + 56);
    pos.x = *(float *)(v20 + 48);
    pos.y = v22;
    pos.z = v23;
    v24 = Node::worldToLocal(v21->bodyTransform, &result, &pos);
    v25 = this->car;
    *(vec3f *)state.wheelRR_localPos = *v24;
    v26 = v25->bodyTransform;
    *(__m128i *)state.bodyMatrix = _mm_loadu_si128((const __m128i *)&v26->matrix);
    *(__m128i *)&state.bodyMatrix[4] = _mm_loadu_si128((const __m128i *)&v26->matrix.M21);
    *(__m128i *)&state.bodyMatrix[8] = _mm_loadu_si128((const __m128i *)&v26->matrix.M31);
    *(__m128i *)&state.bodyMatrix[12] = _mm_loadu_si128((const __m128i *)&v26->matrix.M41);
    state.brake = v25->physicsState.brake;
    state.gas = v25->physicsState.gas;
    state.clutch = v25->physicsState.clutch;
    state.drivetrainSpeed = v25->physicsState.drivetrainSpeed;
    state.engineRPMS = v25->physicsState.engineRPM;
    state.gear = v25->physicsState.gear;
    state.isEngineLimiterOn = v25->physicsState.isEngineLimiterOn;
    state.isGearGrinding = v25->physicsState.isGearGrinding;
    state.lastFF = v25->physicsState.lastFF_Pure;
    state.limiterRPM = v25->physicsState.limiterRPM;
    state.performanceMeter = v25->physicsState.performanceMeter;
    state.speedMS = v25->physicsState.speed.value;
    state.load[0] = v25->physicsState.load[0];
    v27 = this->plugins._Mylast;
    v28 = this->plugins._Myfirst;
    v29 = 0;
    state.ndSlip[0] = v25->physicsState.ndSlip[0];
    state.wheelAngularSpeed[0] = v25->physicsState.wheelAngularSpeed[0];
    state.load[1] = v25->physicsState.load[1];
    state.ndSlip[1] = v25->physicsState.ndSlip[1];
    state.wheelAngularSpeed[1] = v25->physicsState.wheelAngularSpeed[1];
    state.load[2] = v25->physicsState.load[2];
    state.ndSlip[2] = v25->physicsState.ndSlip[2];
    state.wheelAngularSpeed[2] = v25->physicsState.wheelAngularSpeed[2];
    state.load[3] = v25->physicsState.load[3];
    state.ndSlip[3] = v25->physicsState.ndSlip[3];
    v30 = (unsigned int)((char *)v27 - (char *)v28 + 3) >> 2;
    state.wheelAngularSpeed[3] = v25->physicsState.wheelAngularSpeed[3];
    if ( v28 > v27 )
      v30 = 0;
    if ( v30 )
    {
      do
      {
        ACPlugin::update(*v28, &state, deltaT);
        ++v29;
        ++v28;
      }
      while ( v29 != v30 );
    }
  }
}
