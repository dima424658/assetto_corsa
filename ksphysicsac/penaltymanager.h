#pragma once

class PenaltyManager
{
void PenaltyManager::~PenaltyManager();
void PenaltyManager::addJumpStartPenalty();
bool PenaltyManager::checkBlackFlag();
void PenaltyManager::decreasePitPenaltyLaps(bool isValidLap);
void PenaltyManager::init(Car *car);
void PenaltyManager::reset();
void PenaltyManager::resetPenalty();
void PenaltyManager::step(float dt);

};