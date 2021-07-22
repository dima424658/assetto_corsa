#pragma once

class AIDriver
{
bool AIDriver::getAction(DriverActions anAction);
void AIDriver::AIDriver(Car *icar);
void AIDriver::~AIDriver();
void AIDriver::acquireControls(CarControls *controls, float dt, CarControlsInput *input);
void AIDriver::calcMinForwardSides(float forwardDistance);
int AIDriver::findTyreForQualify();
void AIDriver::generatePitStopStrategy(int laps);
void AIDriver::generatePitlaneWait();
double AIDriver::getBrakeTargetSpeed();
double AIDriver::getClosestFollowingCarTTI();
double AIDriver::getDistanceToApex(float offset, float resolution);
double AIDriver::getDistanceToNextCorner(float resolution);
double AIDriver::getEngagedDesiredOffset(float left, float right, float lateral, float *tti, float sideL, float sideR, float eng_speedL, float eng_speedR);
double AIDriver::getLABraking();
double AIDriver::getLateralPush();
double AIDriver::getLookAhead(const float factor, const float speed);
const char *AIDriver::getName();
double AIDriver::getOutsideOffset();
double AIDriver::getSteerAtDistance(float distance, AISpline *spline, AISplinePayload *payload, float dt);
double AIDriver::getUltraGrip();
void AIDriver::initTyreStrategies();
void AIDriver::onNewSession(SessionInfo si);
void AIDriver::selectTimeStartTime();
void AIDriver::setUltraGrip(float value);
void AIDriver::stepCarsAwareness2(float dt);
void AIDriver::stepDRS(CarControls *controls, float dt);
void AIDriver::stepGasBrake(float dt);
void AIDriver::stepGasBrakeStart();
void AIDriver::stepGears(float dt, CarControls *controls);
void AIDriver::stepHumanizer(float dt);
void AIDriver::stepP2P(float dt);
void AIDriver::stepPitLaneMode(float dt);
void AIDriver::stepPushVariations(float dt);
void AIDriver::stepSetup(float dt);
void AIDriver::stepSplineSelection(float dt);
void AIDriver::stepSteer(float dt);
void AIDriver::stepSuperhuman(CarControls *controls, float dt);
void AIDriver::stepTurbo(float dt);
void AIDriver::updateCurrentSplinePos();
void AIDriver::updateTyres();

};