#pragma once

class StartingTrackSemaphore
{
void StartingTrackSemaphore::StartingTrackSemaphore(Sim *aSim);
void StartingTrackSemaphore::~StartingTrackSemaphore();
double StartingTrackSemaphore::getTimeToSessionStart();
void StartingTrackSemaphore::resetLights();
void StartingTrackSemaphore::setCustomStartTime(long double startTime);
void StartingTrackSemaphore::update(float dt);

};