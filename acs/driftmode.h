#pragma once

class DriftMode
{
void DriftMode::DriftMode(CarAvatar *car);
void DriftMode::~DriftMode();
void DriftMode::animateBonuses(float dt);
void DriftMode::modeDrifting(float dt);
void DriftMode::modeGameOver(float dt);
void DriftMode::renderHUD(float dt);
void DriftMode::updateLevelUp(float dt);
void DriftMode::verifyConditions();

};