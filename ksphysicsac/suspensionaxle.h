#pragma once

class SuspensionAxle
{
void SuspensionAxle::SuspensionAxle(Car *car, RigidAxleSide side, const std::wstring *carDataPath);
void SuspensionAxle::addForceAtPos(const vec3f *force, const vec3f *pos, bool driven, bool addToSteerTorque);
void SuspensionAxle::addLocalForceAndTorque(const vec3f *force, const vec3f *torque, const vec3f *driveTorque);
void SuspensionAxle::addTorque(const vec3f *torque);
vec3f *SuspensionAxle::getBasePosition(vec3f *result);
std::vector<DebugLine> *SuspensionAxle::getDebugLines(std::vector<DebugLine> *result, const mat44f *bodyMatrix, const mat44f *hubMatrix);
vec3f *SuspensionAxle::getHubAngularVelocity(vec3f *result);
mat44f *SuspensionAxle::getHubWorldMatrix(mat44f *result);
double SuspensionAxle::getMass();
vec3f *SuspensionAxle::getPointVelocity(vec3f *result, const vec3f *p);
SuspensionStatus *SuspensionAxle::getStatus();
void SuspensionAxle::getSteerBasis(vec3f *center, vec3f *axis);
vec3f *SuspensionAxle::getVelocity(vec3f *result);
void SuspensionAxle::printRollCenter(float tyreRadius);
void SuspensionAxle::setERPCFM(float erp, float cfm);
void SuspensionAxle::setPositions();
void SuspensionAxle::step(float dt);
void SuspensionAxle::stop();

};