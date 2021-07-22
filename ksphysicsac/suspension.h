#pragma once

class Suspension
{
// void __userpurge Suspension::Suspension(@<ecx>, int a2@<ebx>, int a3@<ebp>, Car *car, int index);
void Suspension::addForceAtPos(const vec3f *force, const vec3f *pos, bool driven, bool addToSteerTorque);
void Suspension::addLocalForceAndTorque(const vec3f *force, const vec3f *torque, const vec3f *driveTorque);
void Suspension::addTorque(const vec3f *torque);
double Suspension::getDamage();
Damper *Suspension::getDamper();
std::vector<DebugLine> *Suspension::getDebugLines(std::vector<DebugLine> *result, const mat44f *bodyMatrix, const mat44f *hubMatrix);
vec3f *Suspension::getHubAngularVelocity(SuspensionStrut *this, vec3f *result);
vec3f *Suspension::getPointVelocity(SuspensionStrut *this, vec3f *result, const vec3f *p);
SuspensionStatus *Suspension::getStatus();
// void __userpurge Suspension::getSteerBasis(@<ecx>, __m128 a2@<xmm6>, vec3f *centre, vec3f *axis);
double Suspension::getSteerTorque();
// void __userpurge Suspension::loadINI(@<ecx>, __m128 a2@<xmm0>, int index);
void Suspension::resetDamage();
void Suspension::setDamage(float amount);
void Suspension::setERPCFM(float erp, float cfm);
void Suspension::setSteerLengthOffset(float o);
void Suspension::step(float dt);
double Suspension::getK(SuspensionStrut *this);
void Suspension::stop(SuspensionStrut *this);

};