#pragma once

class SetupTyresManager
{
void resetToDefaultValues(SetupFuelManager *this);
void SetupTyresManager(CarAvatar *aCar);
std::wstring *getStringToSave(std::wstring *result);
void loadFromINI(INIReader *ini, bool isFixed);

};