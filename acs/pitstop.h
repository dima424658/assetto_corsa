#pragma once

class PitStop
{
double PitStop::getPitStopTyrePercentage();
void PitStop::PitStop(Sim *aSim);
void PitStop::~PitStop();
void PitStop::commitChanges();
void PitStop::commitQuickMenuChanges();
double PitStop::getEstimatedTime();
double PitStop::getPitStopFuelingPercentage();
double PitStop::getPitStopRepairingPercentage();
double PitStop::getRealMaxFuel();
bool PitStop::isCarInPitLane();
char PitStop::isCarOutOfPitArea();
BOOL PitStop::isChangingTyres();
bool PitStop::isInPitPosition();
BOOL PitStop::isPitStopDone(float dt);
// void __userpurge PitStop::renderHUD(@<ecx>, float dt, int a3);
void PitStop::update(float dt);

};