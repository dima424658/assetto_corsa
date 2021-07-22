#pragma once

class SetupFuelManager
{
void SetupFuelManager::SetupFuelManager(CarAvatar *aCar);
SetupFuelManager *SetupFuelManager::`vector deleting destructor'(unsigned int a2);
double SetupFuelManager::getSetupFuel();
std::wstring *SetupFuelManager::getStringToSave(std::wstring *result);
bool SetupFuelManager::isFixedFuel();
void SetupFuelManager::loadFromINI(INIReader *ini, bool isFixed);
void SetupFuelManager::onVisibleChanged(bool value);
// void __userpurge SetupFuelManager::render(@<ecx>, __int64 a2@<esi:edi>, float dt);

};