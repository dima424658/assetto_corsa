#pragma once

class PitCrew
{
void PitCrew::PitCrew(CarAvatar *aCar, std::wstring skin);
void PitCrew::~PitCrew();
PitCrew *PitCrew::`vector deleting destructor'(unsigned int a2);
void PitCrew::loadCrewSkin(KN5IO *kn, INIReader *iniS, const std::wstring *section, const std::wstring *key);
void PitCrew::onPitStopBegin(const PitStopStart *message);
void PitCrew::onPitStopFinished();
void PitCrew::onPitStopIdle();
void PitCrew::pitCrewUpdate(float dt);
void PitCrew::reset();
void PitCrew::updateCurrentPosition(float dt);

};