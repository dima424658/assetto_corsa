#pragma once

class DRSManager
{
void DRSManager(PhysicsEngine *engine);
void ~DRSManager();
char isDRSAvailable(const Car *car);
void setZones(std::vector<DRSZone> *zv);
char wasRaceSwitchedOn(const Car *car);

};