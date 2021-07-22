#pragma once

class CarRaceInfo
{
void CarRaceInfo();
void ~CarRaceInfo();
unsigned int getSpawnPositionIndex(const std::wstring *setName);
void init(CarAvatar *acar);
void setSpawnPositionIndex(const std::wstring *setName, int gp);

};