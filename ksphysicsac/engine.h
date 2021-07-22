#pragma once

class Engine
{
void Engine::Engine();
void Engine::~Engine();
void Engine::addTorqueGenerator(ITorqueGenerator *generator);
void Engine::blowUp();
int Engine::getLimiterRPM();
double Engine::getMaxPowerRPM();
double Engine::getMaxPowerW();
double Engine::getMaxTorqueNM();
double Engine::getMaxTorqueRPM();
double Engine::getMaxTurboBoost(bool with_wastegate);
double Engine::getSafeTurboLevel();
double Engine::getThrottleResponseGas(const float gas, const float rpm);
double Engine::getTorqueAtRPM(float rpm, float gas);
double Engine::getTurboBoostLevel();
void Engine::init(Car *car);
BOOL Engine::isLimiterOn();
INIReader *Engine::loadCoastSettings(INIReader *r, const std::wstring *section, std::wstring *a4);
void Engine::loadINI();
void Engine::precalculatePowerAndTorque();
void Engine::reset();
void Engine::setCoastSettings(int s);
void Engine::setTurboBoostLevel(float value);
void Engine::step(SACEngineInput *input, float dt);
void Engine::stepP2P(float dt);
void Engine::stepTurbos();

};