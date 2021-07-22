#pragma once

class ACOperatingSystem
{
void ACOperatingSystem::ACOperatingSystem(Sim *isim);
void ACOperatingSystem::~ACOperatingSystem();
ACOperatingSystem *ACOperatingSystem::`vector deleting destructor'(char *this, unsigned int a2);
IACForm *ACOperatingSystem::createForm(const std::wstring *name);
IACTexture *ACOperatingSystem::createTexture(const std::wstring *filename);
void ACOperatingSystem::getCarData(int carIndex, ACCarData *data);
void ACOperatingSystem::getCarInfo(int carIndex, ACCarInfo *info);
ACINIReader *ACOperatingSystem::getINIReader(const std::wstring *filename);
void ACOperatingSystem::getRaceData(ACRaceData *data);
void ACOperatingSystem::getTrackData(ACTrackData *data);
void ACOperatingSystem::initApps();
void ACOperatingSystem::releaseTexture(IACTexture *texture);

};