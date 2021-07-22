#include "acoperatingsystem.h
void ACOperatingSystem::ACOperatingSystem(ACOperatingSystem *this, Sim *isim)
{
  Game *v3; // eax
  std::wstring v4; // [esp-1Ch] [ebp-3Ch] BYREF
  Game *v5; // [esp-4h] [ebp-24h]
  ACOperatingSystem *v6; // [esp+10h] [ebp-10h]
  int v7; // [esp+1Ch] [ebp-4h]

  v6 = this;
  this->IACOperatingSystem::__vftable = (ACOperatingSystem_vtbl *)&IACOperatingSystem::`vftable';
  v5 = isim->game;
  v4._Myres = 7;
  v4._Mysize = 0;
  v4._Bx._Buf[0] = 0;
  std::wstring::assign(&v4, L"ACOS", 4u);
  GameObject::GameObject(&this->GameObject, v4, v5);
  this->IACOperatingSystem::__vftable = (ACOperatingSystem_vtbl *)&ACOperatingSystem::`vftable'{for `IACOperatingSystem'};
  this->GameObject::__vftable = (GameObject_vtbl *)&ACOperatingSystem::`vftable'{for `GameObject'};
  v3 = isim->game;
  v7 = 0;
  this->gui = v3->gui;
  ACGL::ACGL(&this->gl, this->game->graphics->gl);
  this->sim = isim;
  this->modules._Myfirst = 0;
  this->modules._Mylast = 0;
  this->modules._Myend = 0;
  this->textures._Myfirst = 0;
  this->textures._Mylast = 0;
  this->textures._Myend = 0;
  LOBYTE(v7) = 3;
  ACINIReader::ACINIReader(&this->iniReader);
  LOBYTE(v7) = 4;
  ACOperatingSystem::initApps(this);
}
void ACOperatingSystem::~ACOperatingSystem(ACOperatingSystem *this)
{
  ACOperatingSystem *v1; // ebx
  HINSTANCE__ **v2; // esi
  std::vector<HINSTANCE__ *> *v3; // ebp
  unsigned int v4; // ecx
  int v5; // edi
  unsigned int v6; // ebp
  HMODULE v7; // ebx
  void (*acAppShutdown)(void); // eax
  std::vector<HINSTANCE__ *> *v9; // [esp+18h] [ebp-14h]

  v1 = this;
  this->IACOperatingSystem::__vftable = (ACOperatingSystem_vtbl *)&ACOperatingSystem::`vftable'{for `IACOperatingSystem'};
  this->GameObject::__vftable = (GameObject_vtbl *)&ACOperatingSystem::`vftable'{for `GameObject'};
  v2 = this->modules._Myfirst;
  v3 = &this->modules;
  v9 = &this->modules;
  v4 = (unsigned int)((char *)this->modules._Mylast - (char *)v2 + 3) >> 2;
  v5 = 0;
  if ( v2 > v1->modules._Mylast )
    v4 = 0;
  if ( v4 )
  {
    v6 = v4;
    do
    {
      v7 = *v2;
      acAppShutdown = (void (*)(void))GetProcAddress(*v2, "acAppShutdown");
      if ( acAppShutdown )
        acAppShutdown();
      FreeLibrary(v7);
      ++v5;
      ++v2;
    }
    while ( v5 != v6 );
    v3 = v9;
    v1 = this;
  }
  ACINIReader::~ACINIReader(&v1->iniReader);
  if ( v1->textures._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&v1->textures);
    operator delete(v1->textures._Myfirst);
    v1->textures._Myfirst = 0;
    v1->textures._Mylast = 0;
    v1->textures._Myend = 0;
  }
  if ( v3->_Myfirst )
  {
    std::_Container_base0::_Orphan_all(v3);
    operator delete(v3->_Myfirst);
    v3->_Myfirst = 0;
    v3->_Mylast = 0;
    v3->_Myend = 0;
  }
  ACGL::~ACGL(&v1->gl);
  GameObject::~GameObject(&v1->GameObject);
}
ACOperatingSystem *ACOperatingSystem::`vector deleting destructor'(char *this, unsigned int a2)
{
  return ACOperatingSystem::`scalar deleting destructor'((ACOperatingSystem *)(this - 4), a2);
}
ACOperatingSystem *ACOperatingSystem::`scalar deleting destructor'(ACOperatingSystem *this, unsigned int a2)
{
  ACOperatingSystem::~ACOperatingSystem(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
IACForm *ACOperatingSystem::createForm(ACOperatingSystem *this, const std::wstring *name)
{
  AppForm *v3; // esi
  unsigned int v4; // eax
  unsigned int v5; // esi
  std::wstring *v6; // eax
  std::wstring *v7; // eax
  int v8; // edx
  Sim *v9; // ecx
  ksgui::GameScreen *v10; // ecx
  std::wstring v12; // [esp-18h] [ebp-88h] BYREF
  AppForm *v13; // [esp+10h] [ebp-60h]
  std::wstring _Left; // [esp+18h] [ebp-58h] BYREF
  std::wstring v15; // [esp+30h] [ebp-40h] BYREF
  std::wstring result; // [esp+48h] [ebp-28h] BYREF
  int v17; // [esp+6Ch] [ebp-4h]

  v3 = (AppForm *)operator new(340);
  v13 = v3;
  v17 = 0;
  if ( v3 )
  {
    v12._Myres = 7;
    v12._Mysize = 0;
    v12._Bx._Buf[0] = 0;
    std::wstring::assign(&v12, name, 0, 0xFFFFFFFF);
    AppForm::AppForm(v3, (unsigned int)name, this, v12);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  v17 = -1;
  _Left._Myres = 7;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  std::wstring::assign(&_Left, L"apps/", 5u);
  v17 = 1;
  v6 = std::operator+<wchar_t>(&result, &_Left, name);
  LOBYTE(v17) = 2;
  v7 = std::operator+<wchar_t>(&v15, v6, L"/icon.png");
  v8 = *(_DWORD *)(v5 + 320);
  LOBYTE(v17) = 3;
  (*(void (**)(unsigned int, std::wstring *))(v8 + 8))(v5 + 320, v7);
  if ( v15._Myres >= 8 )
    operator delete(v15._Bx._Ptr);
  v15._Myres = 7;
  v15._Mysize = 0;
  v15._Bx._Buf[0] = 0;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Mysize = 0;
  result._Bx._Buf[0] = 0;
  v17 = -1;
  if ( _Left._Myres >= 8 )
    operator delete(_Left._Bx._Ptr);
  v9 = this->sim;
  v12._Myres = 1;
  v12._Mysize = v5;
  _Left._Myres = 7;
  v10 = v9->gameScreen;
  _Left._Mysize = 0;
  _Left._Bx._Buf[0] = 0;
  v10->addControl(v10, (ksgui::Control *)v5, 1);
  return (IACForm *)(v5 + 320);
}
IACTexture *ACOperatingSystem::createTexture(ACOperatingSystem *this, const std::wstring *filename)
{
  ACTexture *v3; // eax
  const std::wstring *v4; // eax

  v3 = (ACTexture *)operator new(36);
  if ( v3 )
    ACTexture::ACTexture(v3, filename, this->game->graphics);
  else
    v4 = 0;
  filename = v4;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->textures,
    (ICollisionObject *const *)&filename);
  return (IACTexture *)*((_DWORD *)this->textures._Mylast - 1);
}
void ACOperatingSystem::getCarData(ACOperatingSystem *this, int carIndex, ACCarData *data)
{
  CarAvatar *v3; // eax

  v3 = Sim::getCar(this->sim, carIndex);
  if ( v3 )
  {
    data->limiterRPM = v3->physicsState.limiterRPM;
    data->maxGear = v3->physicsInfo.maxGear;
    data->steerLock = v3->physicsInfo.steerLock;
  }
}
void ACOperatingSystem::getCarInfo(ACOperatingSystem *this, int carIndex, ACCarInfo *info)
{
  CarAvatar *v3; // eax
  CarAvatar *v4; // esi
  wchar_t **v5; // ecx
  ACCarInfo *v6; // edx
  wchar_t v7; // ax
  float v8; // xmm0_4

  v3 = Sim::getCar(this->sim, carIndex);
  v4 = v3;
  if ( v3 )
  {
    v5 = (wchar_t **)&v3->unixName;
    if ( v3->unixName._Myres >= 8 )
      v5 = (wchar_t **)*v5;
    v6 = info;
    do
    {
      v7 = *(_WORD *)v5;
      v5 = (wchar_t **)((char *)v5 + 2);
      v6->model[0] = v7;
      v6 = (ACCarInfo *)((char *)v6 + 2);
    }
    while ( v7 );
    info->isEngineLimiterOn = v4->physicsState.isEngineLimiterOn;
    info->engineRPM = (int)v4->physicsState.engineRPM;
    info->speedMS = v4->physicsState.speed.value;
    info->gear = v4->physicsState.gear;
    info->lateralG = v4->physicsState.accG.x;
    info->longitudinalG = v4->physicsState.accG.z;
    info->gas = v4->physicsState.gas;
    info->brake = v4->physicsState.brake;
    info->steerDEG = v4->physicsState.steer;
    v8 = v4->physicsState.worldMatrix.M43;
    *(_QWORD *)info->worldPosition = _mm_unpacklo_ps(
                                       (__m128)LODWORD(v4->physicsState.worldMatrix.M41),
                                       (__m128)LODWORD(v4->physicsState.worldMatrix.M42)).m128_u64[0];
    info->worldPosition[2] = v8;
    info->wheelAngularSpeed[0] = v4->physicsState.wheelAngularSpeed[0];
    info->wheelAngularSpeed[1] = v4->physicsState.wheelAngularSpeed[1];
    info->wheelAngularSpeed[2] = v4->physicsState.wheelAngularSpeed[2];
    info->wheelAngularSpeed[3] = v4->physicsState.wheelAngularSpeed[3];
  }
}
ACINIReader *ACOperatingSystem::getINIReader(ACOperatingSystem *this, const std::wstring *filename)
{
  ACINIReader *v3; // esi
  bool v4; // al
  ACINIReader *v5; // ecx
  std::wstring v7; // [esp-18h] [ebp-20h] BYREF

  v7._Myres = 7;
  v7._Mysize = 0;
  v7._Bx._Buf[0] = 0;
  std::wstring::assign(&v7, filename, 0, 0xFFFFFFFF);
  v3 = &this->iniReader;
  v4 = ACINIReader::open(v3, v7);
  v5 = 0;
  if ( v4 )
    v5 = v3;
  return v5;
}
void ACOperatingSystem::getRaceData(ACOperatingSystem *this, ACRaceData *data)
{
  data->carsCount = this->sim->cars._Mylast - this->sim->cars._Myfirst;
}
void ACOperatingSystem::getTrackData(ACOperatingSystem *this, ACTrackData *data)
{
  TrackData *v2; // eax
  TrackData td; // [esp+4h] [ebp-38h] BYREF

  Sim::getTrackData(this->sim, &td);
  v2 = &td;
  if ( td.name._Myres >= 8 )
    v2 = (TrackData *)td.name._Bx._Ptr;
  _wcscpy_s(data->name, 0x100u, v2->name._Bx._Buf);
  _wcscpy_s(data->configuration, 0x100u, word_17BE9D8);
  if ( td.configuration._Myres >= 8 )
    operator delete(td.configuration._Bx._Ptr);
  td.configuration._Myres = 7;
  td.configuration._Mysize = 0;
  td.configuration._Bx._Buf[0] = 0;
  if ( td.name._Myres >= 8 )
    operator delete(td.name._Bx._Ptr);
}
void ACOperatingSystem::initApps(ACOperatingSystem *this)
{
  ACOperatingSystem::initApps::__l11::<lambda_de6c9c19f47e4d115a985c1f5e5078c7> _Func; // [esp+Ch] [ebp-38h] BYREF
  std::vector<std::wstring> files; // [esp+10h] [ebp-34h] BYREF
  std::wstring filter; // [esp+1Ch] [ebp-28h] BYREF
  int v5; // [esp+40h] [ebp-4h]

  filter._Myres = 7;
  filter._Mysize = 0;
  filter._Bx._Buf[0] = 0;
  std::wstring::assign(&filter, L"apps/*.dll", 0xAu);
  v5 = 0;
  Path::getFiles(&files, &filter);
  LOBYTE(v5) = 2;
  if ( filter._Myres >= 8 )
    operator delete(filter._Bx._Ptr);
  filter._Myres = 7;
  filter._Bx._Buf[0] = 0;
  filter._Mysize = 0;
  _Func.__this = this;
  std::_For_each<std::wstring *,_lambda_de6c9c19f47e4d115a985c1f5e5078c7_>(files._Myfirst, files._Mylast, &_Func);
  v5 = -1;
  if ( files._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&files);
    std::_Destroy_range<std::_Wrap_alloc<std::allocator<std::wstring>>>(files._Myfirst, files._Mylast);
    operator delete(files._Myfirst);
  }
}
void ACOperatingSystem::releaseTexture(ACOperatingSystem *this, IACTexture *texture)
{
  ACTexture **v3; // edx
  ACTexture **i; // eax

  v3 = this->textures._Mylast;
  for ( i = this->textures._Myfirst; i != v3; ++i )
  {
    if ( *i == texture )
      break;
  }
  _memmove(i, i + 1, ((char *)this->textures._Mylast - (char *)(i + 1)) & 0xFFFFFFFC);
  --this->textures._Mylast;
}
