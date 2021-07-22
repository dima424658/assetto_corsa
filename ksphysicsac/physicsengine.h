#pragma once

class PhysicsEngine
{
void PhysicsEngine::setDynamicTempData(DynamicTempData *data);
void PhysicsEngine::PhysicsEngine();
void PhysicsEngine::~PhysicsEngine();
void PhysicsEngine::addAdditionalPhysicsProvider(ICarPhysicsStateProvider *p);
void PhysicsEngine::addLegalTyre(const std::wstring *short_name);
double PhysicsEngine::getAirDensity();
IPhysicsCore *PhysicsEngine::getCore();
double PhysicsEngine::getOddTimeOffset();
void PhysicsEngine::getPhysicsStates(std::vector<CarPhysicsState> *states, std::vector<std::vector<WingState>> *wingStates);
BOOL PhysicsEngine::hasSessionStarted(long double lag);
void PhysicsEngine::initLowSpeedFF();
char PhysicsEngine::isTyreLegal(const std::wstring *short_name);
void PhysicsEngine::onCollisionCallBack(void *userData0, void *shape0, void *userData1, void *shape1, vec3f normal, vec3f pos, float depth);
void PhysicsEngine::removeCar(Car *c);
void PhysicsEngine::setCurrentSessionStartTime(const long double new_start_time);
void PhysicsEngine::setSessionInfo(const SessionInfo *info);
void PhysicsEngine::setWind(Speed speed, float directionDEG);
void PhysicsEngine::step(float dt, long double currentTime, long double gt);
void PhysicsEngine::stepPaused();
void PhysicsEngine::stepWind(float dt);
void PhysicsEngine::writeTestResult(const std::wstring *result);

};