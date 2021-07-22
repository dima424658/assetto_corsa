#pragma once

class DragMode
{
void DragMode::DragMode(Sim *aSim);
void DragMode::~DragMode();
void DragMode::computeCarTimes();
long double DragMode::generateStartTime();
bool DragMode::isGameOver();
void DragMode::newMatch(float secondsFade);
void DragMode::onFinishLanePassed(const unsigned int *carIndex);
void DragMode::renderDragGUI(float dt);
void DragMode::renderDragPenalty(float dt);
void DragMode::renderHUD(float dt);
void DragMode::resetMatch();
void DragMode::update(float dt);
void DragMode::updateDragRace(float dt);
void DragMode::verifyConditions();
unsigned int DragMode::getNumberOfPlayerWins();
unsigned int DragMode::getNumberOfRuns();

};