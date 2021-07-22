#pragma once

class ACPlugin
{
void ACPlugin::ACPlugin(Sim *aSim, HINSTANCE__ *module);
void ACPlugin::~ACPlugin();
ACPlugin *ACPlugin::`vector deleting destructor'(unsigned int a2);
HINSTANCE ACPlugin::getHInstance();
HWND__ *ACPlugin::getHwnd();
void ACPlugin::onGui(ACPluginContext *cc);
void ACPlugin::setABS(float value);
void ACPlugin::setAutoShift(bool value);
void ACPlugin::setBrakeBias(float value);
void ACPlugin::setIdealLine(bool value, bool isFromPhysicsThread);
void ACPlugin::setStabilityControl(float value);
void ACPlugin::setSystemMessage(const wchar_t *message, const wchar_t *description, bool isFromPhysicsThread);
void ACPlugin::setTC(float value);
void ACPlugin::update(ACCarState *state, float dt);

};