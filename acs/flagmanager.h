#pragma once

class FlagManager
{
void FlagManager::FlagManager(Sim *aSim);
void FlagManager::~FlagManager();
void FlagManager::addFlagControl(ksgui::Control *flag, std::wstring flagname);
void FlagManager::checkForBlue();
void FlagManager::checkForYellow();
void FlagManager::checkforPenalty();
void FlagManager::clearFlag();
FlagType FlagManager::getCurrentFlag();
void FlagManager::setBlueFlag(int carIndex);
void FlagManager::setFlag(FlagType flag);
void FlagManager::update(float deltaT);

};