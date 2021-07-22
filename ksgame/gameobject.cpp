#include "gameobject.h
TimeLimitedTest *GameObject::getGameObject<TimeLimitedTest>(GameObject *this)
{
  GameObject **v2; // esi
  TimeLimitedTest *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (TimeLimitedTest *)__RTDynamicCast(
                                  *v2,
                                  0,
                                  &GameObject `RTTI Type Descriptor',
                                  &TimeLimitedTest `RTTI Type Descriptor',
                                  0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
TrackAvatar *GameObject::getGameObject<TrackAvatar>(GameObject *this)
{
  GameObject **v2; // esi
  TrackAvatar *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (TrackAvatar *)__RTDynamicCast(
                              *v2,
                              0,
                              &GameObject `RTTI Type Descriptor',
                              &TrackAvatar `RTTI Type Descriptor',
                              0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
std::vector<CarAvatar *> *GameObject::getGameObjects<CarAvatar>(GameObject *this, std::vector<CarAvatar *> *result)
{
  GameObject **v3; // esi
  CarAvatar *v4; // ebx
  CarAvatar **v5; // eax
  int v6; // ebx
  CarAvatar **v7; // ecx
  CarAvatar **v8; // eax
  CarAvatar *res; // [esp+14h] [ebp-14h] BYREF
  int i; // [esp+18h] [ebp-10h]
  int v12; // [esp+24h] [ebp-4h]

  i = 0;
  result->_Myfirst = 0;
  result->_Mylast = 0;
  result->_Myend = 0;
  v12 = 0;
  v3 = this->gameObjects._Myfirst;
  for ( i = 1; v3 != this->gameObjects._Mylast; ++v3 )
  {
    v4 = (CarAvatar *)__RTDynamicCast(*v3, 0, &GameObject `RTTI Type Descriptor', &CarAvatar `RTTI Type Descriptor', 0);
    res = v4;
    if ( v4 )
    {
      v5 = result->_Mylast;
      if ( &res >= v5 || result->_Myfirst > &res )
      {
        if ( v5 == result->_Myend )
          std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)result, 1u);
        v8 = result->_Mylast;
        if ( v8 )
          *v8 = v4;
      }
      else
      {
        v6 = &res - result->_Myfirst;
        if ( v5 == result->_Myend )
          std::vector<unsigned int>::_Reserve((std::vector<unsigned int> *)result, 1u);
        v7 = result->_Mylast;
        if ( v7 )
          *v7 = result->_Myfirst[v6];
      }
      ++result->_Mylast;
    }
  }
  return result;
}
Sim *GameObject::getGameObject<Sim>(GameObject *this)
{
  GameObject **v2; // esi
  Sim *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (Sim *)__RTDynamicCast(*v2, 0, &GameObject `RTTI Type Descriptor', &Sim `RTTI Type Descriptor', 0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
PhysicsAvatar *GameObject::getGameObject<PhysicsAvatar>(GameObject *this)
{
  GameObject **v2; // esi
  PhysicsAvatar *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (PhysicsAvatar *)__RTDynamicCast(
                                *v2,
                                0,
                                &GameObject `RTTI Type Descriptor',
                                &PhysicsAvatar `RTTI Type Descriptor',
                                0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
PushToPassManager *GameObject::getGameObject<PushToPassManager>(GameObject *this)
{
  GameObject **v2; // esi
  PushToPassManager *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (PushToPassManager *)__RTDynamicCast(
                                    *v2,
                                    0,
                                    &GameObject `RTTI Type Descriptor',
                                    &PushToPassManager `RTTI Type Descriptor',
                                    0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
ACClient *GameObject::getGameObject<ACClient>(GameObject *this)
{
  GameObject **v2; // esi
  ACClient *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (ACClient *)__RTDynamicCast(
                           *v2,
                           0,
                           &GameObject `RTTI Type Descriptor',
                           &ACClient `RTTI Type Descriptor',
                           0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
GameObject *GameObject::getGameObject(GameObject *this, std::wstring name)
{
  GameObject **v3; // esi
  std::wstring *v4; // eax
  GameObject *v5; // esi

  v3 = this->gameObjects._Myfirst;
  if ( v3 == this->gameObjects._Mylast )
  {
LABEL_6:
    v5 = 0;
  }
  else
  {
    while ( 1 )
    {
      v4 = &name;
      if ( name._Myres >= 8 )
        v4 = (std::wstring *)name._Bx._Ptr;
      if ( !std::wstring::compare(&(*v3)->name, 0, (*v3)->name._Mysize, v4->_Bx._Buf, name._Mysize) )
        break;
      if ( ++v3 == this->gameObjects._Mylast )
        goto LABEL_6;
    }
    v5 = *v3;
  }
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  return v5;
}
SunAnimator *GameObject::getGameObject<SunAnimator>(GameObject *this)
{
  GameObject **v2; // esi
  SunAnimator *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (SunAnimator *)__RTDynamicCast(
                              *v2,
                              0,
                              &GameObject `RTTI Type Descriptor',
                              &SunAnimator `RTTI Type Descriptor',
                              0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
SteamInterface *GameObject::getGameObject<SteamInterface>(GameObject *this)
{
  GameObject **v2; // esi
  SteamInterface *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (SteamInterface *)__RTDynamicCast(
                                 *v2,
                                 0,
                                 &GameObject `RTTI Type Descriptor',
                                 &SteamInterface `RTTI Type Descriptor',
                                 0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
GameMode *GameObject::getGameObject<GameMode>(GameObject *this)
{
  GameObject **v2; // esi
  GameMode *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (GameMode *)__RTDynamicCast(
                           *v2,
                           0,
                           &GameObject `RTTI Type Descriptor',
                           &GameMode `RTTI Type Descriptor',
                           0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
PostProcessEffectsUpdater *GameObject::getGameObject<PostProcessEffectsUpdater>(GameObject *this)
{
  GameObject **v2; // esi
  PostProcessEffectsUpdater *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (PostProcessEffectsUpdater *)__RTDynamicCast(
                                            *v2,
                                            0,
                                            &GameObject `RTTI Type Descriptor',
                                            &PostProcessEffectsUpdater `RTTI Type Descriptor',
                                            0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
StartingLights *GameObject::getGameObject<StartingLights>(GameObject *this)
{
  GameObject **v2; // esi
  StartingLights *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (StartingLights *)__RTDynamicCast(
                                 *v2,
                                 0,
                                 &GameObject `RTTI Type Descriptor',
                                 &StartingLights `RTTI Type Descriptor',
                                 0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
ACCameraManager *GameObject::getGameObject<ACCameraManager>(GameObject *this)
{
  GameObject **v2; // esi
  ACCameraManager *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (ACCameraManager *)__RTDynamicCast(
                                  *v2,
                                  0,
                                  &GameObject `RTTI Type Descriptor',
                                  &ACCameraManager `RTTI Type Descriptor',
                                  0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
StartingTrackSemaphore *GameObject::getGameObject<StartingTrackSemaphore>(GameObject *this)
{
  GameObject **v2; // esi
  StartingTrackSemaphore *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (StartingTrackSemaphore *)__RTDynamicCast(
                                         *v2,
                                         0,
                                         &GameObject `RTTI Type Descriptor',
                                         &StartingTrackSemaphore `RTTI Type Descriptor',
                                         0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
PitStop *GameObject::getGameObject<PitStop>(GameObject *this)
{
  GameObject **v2; // esi
  PitStop *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (PitStop *)__RTDynamicCast(*v2, 0, &GameObject `RTTI Type Descriptor', &PitStop `RTTI Type Descriptor', 0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
PitCrew *GameObject::addGameObject<ProximityIndicator>(GameObject *this, PitCrew *object)
{
  PitCrew *v2; // esi

  v2 = object;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&object);
  v2->parent = this;
  return v2;
}
QuickMenuPitstop *GameObject::getGameObject<QuickMenuPitstop>(GameObject *this)
{
  GameObject **v2; // esi
  QuickMenuPitstop *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (QuickMenuPitstop *)__RTDynamicCast(
                                   *v2,
                                   0,
                                   &GameObject `RTTI Type Descriptor',
                                   &QuickMenuPitstop `RTTI Type Descriptor',
                                   0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
FlagManager *GameObject::getGameObject<FlagManager>(GameObject *this)
{
  GameObject **v2; // esi
  FlagManager *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (FlagManager *)__RTDynamicCast(
                              *v2,
                              0,
                              &GameObject `RTTI Type Descriptor',
                              &FlagManager `RTTI Type Descriptor',
                              0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
CarAvatar *GameObject::getGameObject<CarAvatar>(GameObject *this)
{
  GameObject **v2; // esi
  CarAvatar *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (CarAvatar *)__RTDynamicCast(
                            *v2,
                            0,
                            &GameObject `RTTI Type Descriptor',
                            &CarAvatar `RTTI Type Descriptor',
                            0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
GhostCar *GameObject::getGameObject<GhostCar>(GameObject *this)
{
  GameObject **v2; // esi
  GhostCar *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (GhostCar *)__RTDynamicCast(
                           *v2,
                           0,
                           &GameObject `RTTI Type Descriptor',
                           &GhostCar `RTTI Type Descriptor',
                           0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
RaceManager *GameObject::getGameObject<RaceManager>(GameObject *this)
{
  GameObject **v2; // esi
  RaceManager *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (RaceManager *)__RTDynamicCast(
                              *v2,
                              0,
                              &GameObject `RTTI Type Descriptor',
                              &RaceManager `RTTI Type Descriptor',
                              0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
DragMode *GameObject::getGameObject<DragMode>(GameObject *this)
{
  GameObject **v2; // esi
  DragMode *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (DragMode *)__RTDynamicCast(
                           *v2,
                           0,
                           &GameObject `RTTI Type Descriptor',
                           &DragMode `RTTI Type Descriptor',
                           0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
DriftMode *GameObject::getGameObject<DriftMode>(GameObject *this)
{
  GameObject **v2; // esi
  DriftMode *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (DriftMode *)__RTDynamicCast(
                            *v2,
                            0,
                            &GameObject `RTTI Type Descriptor',
                            &DriftMode `RTTI Type Descriptor',
                            0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
TimeAttack *GameObject::getGameObject<TimeAttack>(GameObject *this)
{
  GameObject **v2; // esi
  TimeAttack *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (TimeAttack *)__RTDynamicCast(
                             *v2,
                             0,
                             &GameObject `RTTI Type Descriptor',
                             &TimeAttack `RTTI Type Descriptor',
                             0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
SplashScreen *GameObject::getGameObject<SplashScreen>(GameObject *this)
{
  GameObject **v2; // esi
  SplashScreen *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (SplashScreen *)__RTDynamicCast(
                               *v2,
                               0,
                               &GameObject `RTTI Type Descriptor',
                               &SplashScreen `RTTI Type Descriptor',
                               0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
WeatherManager *GameObject::getGameObject<WeatherManager>(GameObject *this)
{
  GameObject **v2; // esi
  WeatherManager *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (WeatherManager *)__RTDynamicCast(
                                 *v2,
                                 0,
                                 &GameObject `RTTI Type Descriptor',
                                 &WeatherManager `RTTI Type Descriptor',
                                 0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
CarBrakeLights *GameObject::getGameObject<CarBrakeLights>(GameObject *this)
{
  GameObject **v2; // esi
  CarBrakeLights *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (CarBrakeLights *)__RTDynamicCast(
                                 *v2,
                                 0,
                                 &GameObject `RTTI Type Descriptor',
                                 &CarBrakeLights `RTTI Type Descriptor',
                                 0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
DynamicCarEffects *GameObject::getGameObject<DynamicCarEffects>(GameObject *this)
{
  GameObject **v2; // esi
  DynamicCarEffects *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (DynamicCarEffects *)__RTDynamicCast(
                                    *v2,
                                    0,
                                    &GameObject `RTTI Type Descriptor',
                                    &DynamicCarEffects `RTTI Type Descriptor',
                                    0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
ACOperatingSystem *GameObject::addGameObject<ACOperatingSystem>(GameObject *this, ACOperatingSystem *object)
{
  ACOperatingSystem *v2; // esi

  v2 = object;
  if ( object )
    object = (ACOperatingSystem *)((char *)object + 4);
  else
    object = 0;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->gameObjects,
    (ICollisionObject *const *)&object);
  v2->parent = this;
  return v2;
}
DamageDisplayer *GameObject::getGameObject<DamageDisplayer>(GameObject *this)
{
  GameObject **v2; // esi
  DamageDisplayer *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (DamageDisplayer *)__RTDynamicCast(
                                  *v2,
                                  0,
                                  &GameObject `RTTI Type Descriptor',
                                  &DamageDisplayer `RTTI Type Descriptor',
                                  0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
DriverNameDisplayer *GameObject::getGameObject<DriverNameDisplayer>(GameObject *this)
{
  GameObject **v2; // esi
  DriverNameDisplayer *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (DriverNameDisplayer *)__RTDynamicCast(
                                      *v2,
                                      0,
                                      &GameObject `RTTI Type Descriptor',
                                      &DriverNameDisplayer `RTTI Type Descriptor',
                                      0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
MouseHider *GameObject::getGameObject<MouseHider>(GameObject *this)
{
  GameObject **v2; // esi
  MouseHider *result; // eax

  v2 = this->gameObjects._Myfirst;
  if ( v2 == this->gameObjects._Mylast )
    return 0;
  while ( 1 )
  {
    result = (MouseHider *)__RTDynamicCast(
                             *v2,
                             0,
                             &GameObject `RTTI Type Descriptor',
                             &MouseHider `RTTI Type Descriptor',
                             0);
    if ( result )
      break;
    if ( ++v2 == this->gameObjects._Mylast )
      return 0;
  }
  return result;
}
void GameObject::GameObject(GameObject *this, std::wstring iname, Game *igame)
{
  GameObject *v3; // esi
  std::wstring *v4; // ecx
  bool v5; // cf

  v3 = this;
  v4 = &this->name;
  this->game = igame;
  v3->__vftable = (GameObject_vtbl *)&GameObject::`vftable';
  v4->_Myres = 7;
  v4->_Mysize = 0;
  v4->_Bx._Buf[0] = 0;
  v3->gameObjects._Myfirst = 0;
  v3->gameObjects._Mylast = 0;
  v3->gameObjects._Myend = 0;
  if ( v4 != &iname )
    std::wstring::assign(v4, &iname, 0, 0xFFFFFFFF);
  v5 = iname._Myres < 8;
  v3->isActive = 1;
  v3->parent = 0;
  if ( !v5 )
    operator delete(iname._Bx._Ptr);
}
void GameObject::~GameObject(GameObject *this)
{
  GameObject **i; // esi
  void (***v3)(_DWORD, int); // ecx

  this->__vftable = (GameObject_vtbl *)&GameObject::`vftable';
  for ( i = this->gameObjects._Mylast; i != this->gameObjects._Myfirst; --i )
  {
    v3 = (void (***)(_DWORD, int))*(i - 1);
    if ( v3 )
      (**v3)(v3, 1);
  }
  if ( this->gameObjects._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->gameObjects);
    operator delete(this->gameObjects._Myfirst);
    this->gameObjects._Myfirst = 0;
    this->gameObjects._Mylast = 0;
    this->gameObjects._Myend = 0;
  }
  if ( this->name._Myres >= 8 )
    operator delete(this->name._Bx._Ptr);
  this->name._Myres = 7;
  this->name._Mysize = 0;
  this->name._Bx._Buf[0] = 0;
}
GameObject *GameObject::getParent(GameObject *this)
{
  return this->parent;
}
