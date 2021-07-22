#pragma once

class SuspensionML
{
SuspensionStatus *SuspensionML::getStatus();
void SuspensionML::SuspensionML(Car *car, int index);
SuspensionML *SuspensionML::`vector deleting destructor'(unsigned int a2);
void SuspensionML::addForceAtPos(const vec3f *force, const vec3f *pos, bool driven, bool addToSteerTorque);
void SuspensionML::addLocalForceAndTorque(const vec3f *force, const vec3f *torque, const vec3f *driveTorque);
void SuspensionML::addTorque(const vec3f *torque);
vec3f *SuspensionML::getBasePosition(vec3f *result);
double SuspensionML::getDamage();
Damper *SuspensionML::getDamper();
std::vector<DebugLine> *SuspensionML::getDebugLines(std::vector<DebugLine> *result, const mat44f *bodyMatrix, const mat44f *hubMatrix);
vec3f *SuspensionML::getHubAngularVelocity(vec3f *result);
mat44f *SuspensionML::getHubWorldMatrix(mat44f *result);
void SuspensionML::getMass();
vec3f *SuspensionML::getPointVelocity(vec3f *result, const vec3f *p);
// void __userpurge SuspensionML::getSteerBasis(@<ecx>, __m128 a2@<xmm6>, vec3f *center, vec3f *axis);
double SuspensionML::getSteerTorque();
vec3f *SuspensionML::getVelocity(vec3f *result);
// void __userpurge SuspensionML::loadINI(@<ecx>, __m128 a2@<xmm0>, int index);
void SuspensionML::resetDamage();
void SuspensionML::setDamage(float amount);
void SuspensionML::attach();
void SuspensionML::setSteerLengthOffset(float o);
void SuspensionML::step(float dt);
void SuspensionML::stop();

};