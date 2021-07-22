#pragma once

class GameObject
{
TimeLimitedTest *GameObject::getGameObject<TimeLimitedTest>();
TrackAvatar *GameObject::getGameObject<TrackAvatar>();
std::vector<CarAvatar *> *GameObject::getGameObjects<CarAvatar>(std::vector<CarAvatar *> *result);
Sim *GameObject::getGameObject<Sim>();
PhysicsAvatar *GameObject::getGameObject<PhysicsAvatar>();
PushToPassManager *GameObject::getGameObject<PushToPassManager>();
ACClient *GameObject::getGameObject<ACClient>();
GameObject *GameObject::getGameObject(std::wstring name);
SunAnimator *GameObject::getGameObject<SunAnimator>();
SteamInterface *GameObject::getGameObject<SteamInterface>();
GameMode *GameObject::getGameObject<GameMode>();
PostProcessEffectsUpdater *GameObject::getGameObject<PostProcessEffectsUpdater>();
StartingLights *GameObject::getGameObject<StartingLights>();
ACCameraManager *GameObject::getGameObject<ACCameraManager>();
StartingTrackSemaphore *GameObject::getGameObject<StartingTrackSemaphore>();
PitStop *GameObject::getGameObject<PitStop>();
PitCrew *GameObject::addGameObject<ProximityIndicator>(PitCrew *object);
QuickMenuPitstop *GameObject::getGameObject<QuickMenuPitstop>();
FlagManager *GameObject::getGameObject<FlagManager>();
CarAvatar *GameObject::getGameObject<CarAvatar>();
GhostCar *GameObject::getGameObject<GhostCar>();
RaceManager *GameObject::getGameObject<RaceManager>();
DragMode *GameObject::getGameObject<DragMode>();
DriftMode *GameObject::getGameObject<DriftMode>();
TimeAttack *GameObject::getGameObject<TimeAttack>();
SplashScreen *GameObject::getGameObject<SplashScreen>();
WeatherManager *GameObject::getGameObject<WeatherManager>();
CarBrakeLights *GameObject::getGameObject<CarBrakeLights>();
DynamicCarEffects *GameObject::getGameObject<DynamicCarEffects>();
ACOperatingSystem *GameObject::addGameObject<ACOperatingSystem>(ACOperatingSystem *object);
DamageDisplayer *GameObject::getGameObject<DamageDisplayer>();
DriverNameDisplayer *GameObject::getGameObject<DriverNameDisplayer>();
MouseHider *GameObject::getGameObject<MouseHider>();
void GameObject::GameObject(std::wstring iname, Game *igame);
void GameObject::~GameObject();
GameObject *GameObject::getParent();

};