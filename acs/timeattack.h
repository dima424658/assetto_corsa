#pragma once

class TimeAttack
{
// void __userpurge TimeAttack::TimeAttack(@<ecx>, char a2@<bl>, __m128 a3@<xmm3>, __m128 a4@<xmm4>, CarAvatar *aCar);
void TimeAttack::~TimeAttack();
void TimeAttack::createAndSaveOverlays();
void TimeAttack::loadOverlaysAndSectors();
void TimeAttack::renderGameOver(float dt);
void TimeAttack::renderGuiCheckpointBreak(float dt, float newPoints, float newSeconds);
void TimeAttack::renderGuiPenalties(float dt);
void TimeAttack::renderGuiStart(float dt);
void TimeAttack::renderGuiStatus(float dt);
void TimeAttack::renderHUD(float dt);
void TimeAttack::update(float dt);
void TimeAttack::updateGameOver(float dt);
void TimeAttack::updatePenalties(float dt);
void TimeAttack::updateTimeAttack(float dt);
void TimeAttack::verifyConditions();

};