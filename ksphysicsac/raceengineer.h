#pragma once

class RaceEngineer
{
Car *RaceEngineer::getCar();
void RaceEngineer::RaceEngineer(Car *icar);
void RaceEngineer::~RaceEngineer();
RaceEngineer *RaceEngineer::`vector deleting destructor'(unsigned int a2);
double RaceEngineer::evalAvailableBrake(float speed, float latg, float weight);
double RaceEngineer::evalFrontRideHeight();
double RaceEngineer::evalLateralGFromLoads(const float speed, const float aeroRatio, const float mass, const float *loads);
double RaceEngineer::evalLateralGrip(float speed, float mass, float aeroModifier, float *in_loads, float current_lift_kg);
double RaceEngineer::evalRearRideHeight();
double RaceEngineer::evalRideHeight(int index);
WheelValues *RaceEngineer::evalTyreLoad(WheelValues *result, float speedMS, float latg, float longg);
int RaceEngineer::findTyreCompound(FindTyreCompoundLogic logic);
float *RaceEngineer::getAccelerationProfile(float *a2);
double RaceEngineer::getAntiSquat();
double RaceEngineer::getBaseCarHeight();
double RaceEngineer::getBetaRAD();
double RaceEngineer::getCasterRAD(ISuspension *isus);
double RaceEngineer::getDrivingTyresSlip();
double RaceEngineer::getDynamicIndex();
double RaceEngineer::getFrontCasterRAD();
std::tuple<float,float> *RaceEngineer::getFrontDampingRatio(std::tuple<float,float> *result);
double RaceEngineer::getFrontNaturalFrequencyHZ();
double RaceEngineer::getFrontTrack();
KPI *RaceEngineer::getKPI_RAD(KPI *result, int index);
Car *RaceEngineer::getLeftDrivenTyre();
double RaceEngineer::getMaxBrakingForce();
Speed *RaceEngineer::getMaxSpeedFromGear(Speed *result, unsigned int relativeCarIndex);
double RaceEngineer::getOptimalBrake();
double RaceEngineer::getPointFrontShare(vec3f *p);
double RaceEngineer::getPointGroundHeight(const vec3f *p);
std::tuple<float,float> *RaceEngineer::getRearDampingRatio(std::tuple<float,float> *result);
double RaceEngineer::getRearNaturalFrequencyHZ();
double RaceEngineer::getRearTrack();
Car *RaceEngineer::getRightDrivenTyre();
double RaceEngineer::getTorqueToGripRatio();
double RaceEngineer::projectCarForwardForceAtGas(const float gas);
double RaceEngineer::projectWingsDrag(float speed);
double RaceEngineer::projectWingsLift(float speed);

};