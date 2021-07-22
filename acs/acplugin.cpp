#include "acplugin.h
void ACPlugin::ACPlugin(ACPlugin *this, Sim *aSim, HINSTANCE__ *module)
{
  CarAvatar *v4; // eax
  Car *v5; // eax
  bool (__cdecl *v6)(wchar_t *); // eax
  bool (__cdecl *acpInit)(IACPPluginHost *); // eax
  bool (__cdecl *acpShutdown)(); // eax
  bool (__cdecl *acpUpdate)(ACCarState *, float); // eax
  bool (__cdecl *acpOnGui)(ACPluginContext *); // eax
  bool (__cdecl *acpGetControls)(ICarControlsProvider **); // eax
  bool (__cdecl *v12)(IACPPluginHost *); // eax
  bool (__cdecl *v13)(ICarControlsProvider **); // eax
  const char *v14; // eax
  Sim *v15; // ecx
  CarAvatar *v16; // eax
  bool (__cdecl *v17)(wchar_t *); // eax
  unsigned int v18; // ecx
  std::wstring v19; // [esp-18h] [ebp-244h] BYREF
  ICarControlsProvider *np[2]; // [esp+14h] [ebp-218h] BYREF
  wchar_t buffer[256]; // [esp+1Ch] [ebp-210h] BYREF
  int v22; // [esp+228h] [ebp-4h]

  this->__vftable = (ACPlugin_vtbl *)&ACPlugin::`vftable';
  this->name._Myres = 7;
  this->name._Mysize = 0;
  np[1] = (ICarControlsProvider *)this;
  this->name._Bx._Buf[0] = 0;
  v19._Myres = 0;
  v22 = 0;
  this->car = 0;
  this->sim = aSim;
  v4 = Sim::getCar(aSim, v19._Myres);
  this->carAvatar = v4;
  v5 = RaceEngineer::getCar(v4->raceEngineer._Myptr);
  this->car = v5;
  if ( !v5 )
  {
    v19._Myres = 7;
    v19._Mysize = 0;
    v19._Bx._Buf[0] = 0;
    std::wstring::assign(&v19, L"NO CAR IN PLUGIN", 0x10u);
    ksGenerateCrash(v19);
  }
  v19._Myres = (unsigned int)"acpGetName";
  v19._Mysize = (unsigned int)module;
  this->hModule = module;
  this->getName = 0;
  this->init = 0;
  this->shutdown = 0;
  this->p_update = 0;
  this->p_onGui = 0;
  this->getControls = 0;
  v6 = (bool (__cdecl *)(wchar_t *))GetProcAddress((HMODULE)v19._Mysize, (LPCSTR)v19._Myres);
  this->getName = v6;
  if ( !v6 )
    _printf("Error binding api: %s\n", "acpGetName");
  acpInit = (bool (__cdecl *)(IACPPluginHost *))GetProcAddress(this->hModule, "acpInit");
  this->init = acpInit;
  if ( !acpInit )
    _printf("Error binding api: %s\n", "acpInit");
  acpShutdown = (bool (__cdecl *)())GetProcAddress(this->hModule, "acpShutdown");
  this->shutdown = acpShutdown;
  if ( !acpShutdown )
    _printf("Error binding api: %s\n", "acpShutdown");
  acpUpdate = (bool (__cdecl *)(ACCarState *, float))GetProcAddress(this->hModule, "acpUpdate");
  this->p_update = acpUpdate;
  if ( !acpUpdate )
    _printf("Error binding api: %s\n", "acpUpdate");
  acpOnGui = (bool (__cdecl *)(ACPluginContext *))GetProcAddress(this->hModule, "acpOnGui");
  this->p_onGui = acpOnGui;
  if ( !acpOnGui )
    _printf("Error binding api: %s\n", "acpOnGui");
  acpGetControls = (bool (__cdecl *)(ICarControlsProvider **))GetProcAddress(this->hModule, "acpGetControls");
  this->getControls = acpGetControls;
  if ( !acpGetControls )
    _printf("Error binding api: %s\n", "acpGetControls");
  v12 = this->init;
  if ( v12 )
    v12(this);
  v13 = this->getControls;
  if ( v13 )
  {
    np[0] = 0;
    if ( v13(np) )
    {
      v14 = np[0]->getName(np[0]);
      _printf("Ovverriding controls provider: %s\n", v14);
      v15 = this->sim;
      v19._Myres = (unsigned int)np[0];
      v16 = GameObject::getGameObject<CarAvatar>(v15);
      CarAvatar::setControlsProvider(v16, (ICarControlsProvider *)v19._Myres);
    }
  }
  v17 = this->getName;
  if ( v17 )
  {
    v17(buffer);
    if ( buffer[0] )
      v18 = wcslen(buffer);
    else
      v18 = 0;
    std::wstring::assign(&this->name, buffer, v18);
  }
}
void ACPlugin::~ACPlugin(ACPlugin *this)
{
  std::wstring *v2; // eax
  void (*v3)(void); // eax

  this->__vftable = (ACPlugin_vtbl *)&ACPlugin::`vftable';
  if ( this->name._Myres < 8 )
    v2 = &this->name;
  else
    v2 = (std::wstring *)this->name._Bx._Ptr;
  _printf("Releasing plugin: %S\n", v2->_Bx._Buf);
  v3 = (void (*)(void))this->shutdown;
  if ( v3 )
    v3();
  FreeLibrary(this->hModule);
  if ( this->name._Myres >= 8 )
    operator delete(this->name._Bx._Ptr);
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
}
ACPlugin *ACPlugin::`vector deleting destructor'(ACPlugin *this, unsigned int a2)
{
  ACPlugin::~ACPlugin(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
HINSTANCE ACPlugin::getHInstance(ACPlugin *this)
{
  return DirectInput::hInstance;
}
HWND__ *ACPlugin::getHwnd(ACPlugin *this)
{
  return DirectInput::hWnd;
}
void ACPlugin::onGui(ACPlugin *this, ACPluginContext *cc)
{
  bool (__cdecl *v2)(ACPluginContext *); // eax

  v2 = this->p_onGui;
  if ( v2 )
    v2(cc);
}
void ACPlugin::setABS(ACPlugin *this, float value)
{
  Car *v2; // eax

  this->car->abs.slipRatioLimit = value;
  v2 = this->car;
  if ( value <= 0.0 )
  {
    v2->abs.isActive = 0;
    this->car->abs.isPresent = 0;
  }
  else
  {
    v2->abs.isActive = 1;
    this->car->abs.isPresent = 1;
  }
}
void ACPlugin::setAutoShift(ACPlugin *this, bool value)
{
  this->car->autoShift.isActive = value;
}
void ACPlugin::setBrakeBias(ACPlugin *this, float value)
{
  this->car->brakeSystem.frontBias = value;
}
void ACPlugin::setIdealLine(ACPlugin *this, bool value, bool isFromPhysicsThread)
{
  Sim *v3; // ecx
  std::function<void __cdecl(void)> v4; // [esp-18h] [ebp-34h] BYREF
  unsigned int v5; // [esp+8h] [ebp-14h]
  int v6; // [esp+18h] [ebp-4h]

  if ( isFromPhysicsThread )
  {
    LOBYTE(v5) = value;
    v4._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_9f5d139ac3da50f79c44adf8fbf8cdd4_,0>,std::allocator<std::_Func_class<void,>>,void,>::`vftable';
    *(_QWORD *)&v4._Space._Alias[4] = __PAIR64__((unsigned int)this, v5);
    v4._Impl = (std::_Func_base<void> *)&v4;
    v3 = this->sim;
    v6 = -1;
    Sim::executeOnMainThread(v3, v4);
  }
  else
  {
    DrivingAssistManager::setIdealLine(this->sim->drivingAidsManager, value);
  }
}
void ACPlugin::setStabilityControl(ACPlugin *this, float value)
{
  this->car->stabilityControl.gain = value;
}
void ACPlugin::setSystemMessage(ACPlugin *this, const wchar_t *message, const wchar_t *description, bool isFromPhysicsThread)
{
  Sim *v5; // eax
  Sim *v6; // ecx
  std::function<void __cdecl(void)> v7; // [esp-18h] [ebp-74h] BYREF
  ACPlugin::setSystemMessage::__l9::<lambda_0638175e8dfc45e8ab90c6bccc126276> _Func; // [esp+Ch] [ebp-50h] BYREF
  std::wstring imessage; // [esp+1Ch] [ebp-40h] BYREF
  std::wstring v10; // [esp+34h] [ebp-28h] BYREF
  int v11; // [esp+58h] [ebp-4h]

  v5 = this->sim;
  if ( v5 && v5->systemMessage )
  {
    if ( isFromPhysicsThread )
    {
      _Func.description = description;
      _Func.message = message;
      _Func.__this = this;
      std::function<void __cdecl (void)>::function<void __cdecl (void)>(&v7, &_Func);
      Sim::executeOnMainThread(this->sim, v7);
    }
    else
    {
      std::wstring::wstring(&v10, description);
      v11 = 0;
      std::wstring::wstring(&imessage, message);
      v6 = this->sim;
      LOBYTE(v11) = 1;
      SystemMessage::addMessage(v6->systemMessage, &imessage, &v10, eDefault);
      if ( imessage._Myres >= 8 )
        operator delete(imessage._Bx._Ptr);
      imessage._Myres = 7;
      imessage._Mysize = 0;
      imessage._Bx._Buf[0] = 0;
      if ( v10._Myres >= 8 )
        operator delete(v10._Bx._Ptr);
    }
  }
}
void ACPlugin::setTC(ACPlugin *this, float value)
{
  Car *v2; // eax

  this->car->tractionControl.slipRatioLimit = value;
  v2 = this->car;
  if ( value <= 0.0 )
  {
    v2->tractionControl.isActive = 0;
    this->car->tractionControl.isPresent = 0;
  }
  else
  {
    v2->tractionControl.isActive = 1;
    this->car->tractionControl.isPresent = 1;
  }
}
void ACPlugin::update(ACPlugin *this, ACCarState *state, float dt)
{
  bool (__cdecl *v3)(ACCarState *, float); // eax

  v3 = this->p_update;
  if ( v3 )
    ((void (__cdecl *)(ACCarState *, _DWORD))v3)(state, LODWORD(dt));
}
