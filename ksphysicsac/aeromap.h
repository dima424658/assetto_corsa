#pragma once

class AeroMap
{
void AeroMap::AeroMap();
void AeroMap::~AeroMap();
void AeroMap::addDrag(const vec3f *lv);
void AeroMap::addLift(const vec3f *localVelocity);
double AeroMap::getCurrentDragKG();
double AeroMap::getCurrentLiftKG();
std::vector<WingState> *AeroMap::getWingStatus(std::vector<WingState> *result);
void AeroMap::init(Car *a_car, const vec3f *frontAP, const vec3f *rearAP, std::wstring dataPath);
void AeroMap::loadINI(const std::wstring *dataPath);
void AeroMap::step(float dt);

};