#pragma once

class AIDriverDrag
{
bool AIDriverDrag::isDeviceConnected(AIDriver *this);
void AIDriverDrag::AIDriverDrag(Car *icar);
void AIDriverDrag::acquireControls(CarControls *controls, float dt, CarControlsInput *input);
const char *AIDriverDrag::getName();
void AIDriverDrag::setStartTime(long double startTime);
void AIDriverDrag::stepGasBrake(float dt);
void AIDriverDrag::stepGasBrakeStart();
void AIDriverDrag::stepGears(float dt, CarControls *controls);
void AIDriverDrag::stepSteer(float dt);

};