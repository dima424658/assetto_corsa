#pragma once

class SuspensionStrut
{
mat44f *SuspensionStrut::getHubWorldMatrix(mat44f *result);
double SuspensionStrut::getPackerRange();
vec3f *SuspensionStrut::getVelocity(vec3f *result);
// void __userpurge SuspensionStrut::SuspensionStrut(@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>, Car *car, int index);
void SuspensionStrut::addForceAtPos(const vec3f *force, const vec3f *pos, bool driven, bool addToSteerTorque);
void SuspensionStrut::addLocalForceAndTorque(const vec3f *force, const vec3f *torque, const vec3f *driveTorque);
void SuspensionStrut::addTorque(const vec3f *torque);
vec3f *SuspensionStrut::getBasePosition(vec3f *result);
double SuspensionStrut::getDamage();
Damper *SuspensionStrut::getDamper();
std::vector<DebugLine> *SuspensionStrut::getDebugLines(std::vector<DebugLine> *result, const mat44f *bodyMatrix, const mat44f *hubMatrix);
void SuspensionStrut::getMass();
SuspensionStatus *SuspensionStrut::getStatus();
// void __userpurge SuspensionStrut::getSteerBasis(@<ecx>, __m128 a2@<xmm6>, vec3f *center, vec3f *axis);
double SuspensionStrut::getSteerTorque();
// void __userpurge SuspensionStrut::loadINI(@<ecx>, __m128 a2@<xmm0>, int index);
void SuspensionStrut::resetDamage();
void SuspensionStrut::setDamage(float amount);
void SuspensionStrut::setERPCFM(float erp, float cfm);
void SuspensionStrut::setPositions();
void SuspensionStrut::setSteerLengthOffset(float o);
void SuspensionStrut::step(float dt);

};