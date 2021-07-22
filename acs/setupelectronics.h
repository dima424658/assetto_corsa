#pragma once

class SetupElectronics
{
void SetupElectronics::SetupElectronics(CarAvatar *aCar);
void SetupElectronics::~SetupElectronics();
SetupElectronics *SetupElectronics::`vector deleting destructor'(unsigned int a2);
SpinnerData *SetupElectronics::addABS(ksgui::GUI *gui);
SpinnerData *SetupElectronics::addEngineBrake(ksgui::GUI *gui);
SpinnerData *SetupElectronics::addErsPower(ksgui::GUI *gui);
SpinnerData *SetupElectronics::addErsRecovery(ksgui::GUI *gui);
SpinnerData *SetupElectronics::addHeatCharging(ksgui::GUI *gui);
SpinnerData *SetupElectronics::addTC(ksgui::GUI *gui);
SpinnerData *SetupElectronics::addTurbo(ksgui::GUI *gui);
std::wstring *SetupElectronics::getStringToSave(std::wstring *result);
void SetupElectronics::loadFromINI(INIReader *ini, bool isFixed);
void SetupElectronics::onVisibleChanged(float value);
// void __userpurge SetupElectronics::render(@<ecx>, __int64 a2@<esi:edi>, float dt);
void SetupElectronics::resetToDefaultValues();
void SetupElectronics::setSpinner(SpinnerData *customSpinner, std::function<float __cdecl(CarAvatar *)> functionGetValue, std::function<void __cdecl(CarAvatar *,float)> functionSetValue, std::function<std::wstring __cdecl(CarAvatar *,int)> functionGetName);

};