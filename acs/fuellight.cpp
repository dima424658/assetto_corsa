#include "fuellight.h"
void FuelLight::FuelLight(FuelLight *this, Sim *aSim)
{
  Game *v3; // eax
  Texture *v4; // eax
  Game *v5; // eax
  Texture *v6; // eax
  CarAvatar *v7; // esi
  std::wstring *v8; // eax
  const std::wstring *v9; // eax
  Event<OnReplayStatusChanged> *v10; // ecx
  Sim *v11; // ebx
  GameObject **v12; // esi
  FlagManager *v13; // eax
  Event<SessionInfo> *v14; // ecx
  std::wstring v15; // [esp-1Ch] [ebp-F4h] BYREF
  unsigned int v16; // [esp-4h] [ebp-DCh]
  float minFuel[2]; // [esp+18h] [ebp-C0h] BYREF
  std::wstring filename; // [esp+20h] [ebp-B8h] BYREF
  Texture result; // [esp+38h] [ebp-A0h] BYREF
  std::wstring key; // [esp+54h] [ebp-84h] BYREF
  std::wstring v21; // [esp+6Ch] [ebp-6Ch] BYREF
  INIReader carIni; // [esp+84h] [ebp-54h] BYREF
  int v23; // [esp+D4h] [ebp-4h]

  LODWORD(minFuel[1]) = this;
  v16 = (unsigned int)aSim->game;
  v15._Myres = 7;
  v15._Mysize = 0;
  v15._Bx._Buf[0] = 0;
  std::wstring::assign(&v15, L"FUEL_LIGHT", 0xAu);
  GameObject::GameObject(this, v15, (Game *)v16);
  this->__vftable = (FuelLight_vtbl *)&FuelLight::`vftable';
  this->sim = aSim;
  this->fuelTexture.kid = 0;
  this->fuelTexture.fileName._Myres = 7;
  this->fuelTexture.fileName._Mysize = 0;
  v23 = 0;
  this->fuelTexture.fileName._Bx._Buf[0] = 0;
  this->outOfFuelTexture.kid = 0;
  this->outOfFuelTexture.fileName._Myres = 7;
  this->outOfFuelTexture.fileName._Mysize = 0;
  this->outOfFuelTexture.fileName._Bx._Buf[0] = 0;
  this->fuelLimits._Myfirst = 0;
  this->fuelLimits._Mylast = 0;
  this->fuelLimits._Myend = 0;
  v16 = 46;
  v15._Myres = (unsigned int)L"content//gui//fuelIndicator//fuelIndicator.png";
  LOBYTE(v23) = 3;
  this->xPos = 25.0;
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, (const wchar_t *)v15._Myres, v16);
  v3 = this->game;
  LOBYTE(v23) = 4;
  v4 = ResourceStore::getTexture(v3->graphics->resourceStore._Myptr, &result, &filename, 0);
  this->fuelTexture.kid = v4->kid;
  LOBYTE(v23) = 5;
  if ( &this->fuelTexture.fileName != &v4->fileName )
    std::wstring::assign(&this->fuelTexture.fileName, &v4->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v23) = 4;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v23) = 3;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"content//gui//fuelIndicator//outOfFuel.png", 0x2Au);
  v5 = this->game;
  LOBYTE(v23) = 6;
  v6 = ResourceStore::getTexture(v5->graphics->resourceStore._Myptr, &result, &filename, 0);
  this->outOfFuelTexture.kid = v6->kid;
  LOBYTE(v23) = 7;
  if ( &this->outOfFuelTexture.fileName != &v6->fileName )
    std::wstring::assign(&this->outOfFuelTexture.fileName, &v6->fileName, 0, 0xFFFFFFFF);
  LOBYTE(v23) = 6;
  OnSetupAppCreated::~OnSetupAppCreated(&result);
  LOBYTE(v23) = 3;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  v7 = Sim::getCar(this->sim, 0);
  v8 = std::operator+<wchar_t>((std::wstring *)&result, L"content/cars/", &v7->unixName);
  LOBYTE(v23) = 8;
  v9 = std::operator+<wchar_t>(&v21, v8, L"/data/car.ini");
  LOBYTE(v23) = 9;
  CarAvatar::openINI(v7, &carIni, v9);
  if ( v21._Myres >= 8 )
    operator delete(v21._Bx._Ptr);
  v21._Myres = 7;
  v21._Mysize = 0;
  v21._Bx._Buf[0] = 0;
  LOBYTE(v23) = 12;
  if ( result.fileName._Mysize >= 8 )
    operator delete(result.kid);
  result.fileName._Mysize = 7;
  *(_DWORD *)&result.fileName._Bx._Alias[12] = 0;
  LOWORD(result.kid) = 0;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"FUEL_LIGHT_MIN_LITERS", 0x15u);
  LOBYTE(v23) = 13;
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"GRAPHICS", 8u);
  LOBYTE(v23) = 14;
  minFuel[0] = INIReader::getFloat(&carIni, &filename, &key);
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  LOBYTE(v23) = 12;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  if ( minFuel[0] == 0.0 )
    minFuel[0] = 3.0;
  std::vector<CarAvatar *>::push_back((std::vector<int> *)&this->fuelLimits, (int *)minFuel);
  v16 = (unsigned int)this;
  v15._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_3997bb45dffea64fb02ff2feca9c1a05_,0>,std::allocator<std::_Func_class<void,OnReplayStatusChanged const &>>,void,OnReplayStatusChanged const &>::`vftable';
  *(_DWORD *)&v15._Bx._Alias[4] = this;
  v15._Mysize = (unsigned int)&v15;
  v10 = &this->sim->evOnReplayStatusChanged;
  LOBYTE(v23) = 12;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)v10,
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v15,
    this);
  v11 = this->sim;
  v12 = v11->gameObjects._Myfirst;
  if ( v12 == v11->gameObjects._Mylast )
  {
LABEL_22:
    v13 = 0;
  }
  else
  {
    while ( 1 )
    {
      v13 = (FlagManager *)__RTDynamicCast(
                             *v12,
                             0,
                             &GameObject `RTTI Type Descriptor',
                             &FlagManager `RTTI Type Descriptor',
                             0);
      if ( v13 )
        break;
      if ( ++v12 == v11->gameObjects._Mylast )
        goto LABEL_22;
    }
  }
  v16 = (unsigned int)this;
  this->flagManager = v13;
  v15._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_312aceeaa8eb0ff2f6f798ebad983322_,0>,std::allocator<std::_Func_class<void,FlagTriggered const &>>,void,FlagTriggered const &>::`vftable';
  *(_DWORD *)&v15._Bx._Alias[4] = this;
  v15._Mysize = (unsigned int)&v15;
  v14 = (Event<SessionInfo> *)&this->flagManager->evOnFlagChange;
  LOBYTE(v23) = 12;
  Event<float>::addHandler(v14, (std::function<void __cdecl(SessionInfo const &)>)v15, (void *)v16);
  LOBYTE(v23) = 3;
  INIReader::~INIReader(&carIni);
}
void FuelLight::~FuelLight(FuelLight *this)
{
  this->__vftable = (FuelLight_vtbl *)&FuelLight::`vftable';
  if ( this->fuelLimits._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->fuelLimits);
    operator delete(this->fuelLimits._Myfirst);
    this->fuelLimits._Myfirst = 0;
    this->fuelLimits._Mylast = 0;
    this->fuelLimits._Myend = 0;
  }
  OnSetupAppCreated::~OnSetupAppCreated(&this->outOfFuelTexture);
  OnSetupAppCreated::~OnSetupAppCreated(&this->fuelTexture);
  GameObject::~GameObject(this);
}
FuelLight *FuelLight::`scalar deleting destructor'(FuelLight *this, unsigned int a2)
{
  FuelLight::~FuelLight(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void FuelLight::renderHUD(FuelLight *this, float dt)
{
  unsigned int v3; // edi
  float *v4; // esi
  unsigned int v5; // eax
  Sim *v6; // ecx
  Sim *v7; // ecx
  EndSessionDisplayer *v8; // eax
  GLRenderer *v9; // ebp
  unsigned int v10; // edi
  float *v11; // esi
  unsigned int v12; // eax
  CarAvatar *v13; // eax
  unsigned int v14; // eax
  float v15; // xmm0_4
  Texture *v16; // eax

  if ( !Sim::getFocusedCarIndex(this->sim) )
  {
    v3 = Sim::getFocusedCarIndex(this->sim);
    v4 = this->fuelLimits._Myfirst;
    v5 = Sim::getFocusedCarIndex(this->sim);
    if ( v4[v3] >= Sim::getCar(this->sim, v5)->physicsState.fuel )
    {
      v6 = this->sim;
      if ( !v6->escMenu->visible && !RaceManager::isRaceOver(v6->raceManager, 0) )
      {
        v7 = this->sim;
        v8 = v7->endSessionDisplayer;
        if ( !v8 || !v8->isActive )
        {
          v9 = v7->game->graphics->gl;
          v10 = Sim::getFocusedCarIndex(v7);
          v11 = this->fuelLimits._Myfirst;
          v12 = Sim::getFocusedCarIndex(this->sim);
          v13 = Sim::getCar(this->sim, v12);
          GLRenderer::color4f(v9, 1.0, 1.0 - (float)(1.0 - (float)(v13->physicsState.fuel / v11[v10])), 0.0, 1.0);
          GraphicsManager::setBlendMode(this->game->graphics, eAlphaBlend);
          v14 = Sim::getFocusedCarIndex(this->sim);
          v15 = Sim::getCar(this->sim, v14)->physicsState.fuel;
          v16 = &this->fuelTexture;
          if ( v15 <= 0.0 )
            v16 = &this->outOfFuelTexture;
          GraphicsManager::setTexture(this->game->graphics, 0, v16);
          if ( Sim::isInTripleScreenMode(this->sim) )
            GLRenderer::quad(
              v9,
              (float)(this->game->graphics->videoSettings.width / 3) + this->xPos,
              25.0,
              50.0,
              50.0,
              1,
              0);
          else
            GLRenderer::quad(v9, this->xPos, 25.0, 50.0, 50.0, 1, 0);
        }
      }
    }
  }
}
