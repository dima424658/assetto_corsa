#pragma once

class SetupGearManager
{
void SetupGearManager::SetupGearManager(CarAvatar *aCar);
void SetupGearManager::~SetupGearManager();
void SetupGearManager::addGearSet(std::wstring name, GearSetDef gs);
void SetupGearManager::addSetupItem(int absoluteGearIndex, const SetupItemText *item);
std::wstring *SetupGearManager::getStringMaxSpeed(std::wstring *result, unsigned int gear);
std::wstring *SetupGearManager::getStringToSave(std::wstring *result);
void SetupGearManager::loadFromINI(INIReader *ini, bool isFixed);
// void __userpurge SetupGearManager::populateSpinner(@<ecx>, unsigned int a2@<ebx>, int absoluteGearIndex, ksgui::Spinner *spinner, const SetupItemText *item);
// void __userpurge SetupGearManager::render(@<ecx>, __int64 a2@<esi:edi>, float dt);
void SetupGearManager::resetToDefaultValues();

};