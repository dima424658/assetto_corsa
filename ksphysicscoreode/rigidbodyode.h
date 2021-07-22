#pragma once

class RigidBodyODE
{
void RigidBodyODE::RigidBodyODE(PhysicsCore *core);
RigidBodyODE *RigidBodyODE::`vector deleting destructor'(unsigned int a2);
void RigidBodyODE::~RigidBodyODE();
double RigidBodyODE::getMass();
void RigidBodyODE::release();
void RigidBodyODE::setMassExplicitInertia(float totalMass, float x, float y, float z);
void RigidBodyODE::setMassBox(float m, float x, float y, float z);
vec3f *RigidBodyODE::getLocalInertia(vec3f *result);
mat44f *RigidBodyODE::getWorldMatrix(mat44f *result, float interpolationT);
vec3f *RigidBodyODE::localToWorld(vec3f *result, const vec3f *p);
vec3f *RigidBodyODE::worldToLocal(vec3f *result, const vec3f *p);
vec3f *RigidBodyODE::localToWorldNormal(vec3f *result, const vec3f *p);
vec3f *RigidBodyODE::worldToLocalNormal(vec3f *result, const vec3f *p);
void RigidBodyODE::stop(float amount);
vec3f *RigidBodyODE::getVelocity(vec3f *result);
void RigidBodyODE::setVelocity(const vec3f *vel);
void RigidBodyODE::setPosition(const vec3f *pos);
// void __userpurge RigidBodyODE::setRotation(@<ecx>, char a2@<efl>, const mat44f *mat);
vec3f *RigidBodyODE::getPosition(vec3f *result, float interpolationT);
vec3f *RigidBodyODE::getAngularVelocity(vec3f *result);
vec3f *RigidBodyODE::getLocalAngularVelocity(vec3f *result);
vec3f *RigidBodyODE::getLocalVelocity(vec3f *result);
void RigidBodyODE::addMeshCollider(float *vertices, unsigned int verticesCount, unsigned __int16 *indices, unsigned int indicesCount, mat44f mat, unsigned int category, unsigned int collideMask, unsigned int spaceId);
void RigidBodyODE::setMeshCollideMask(unsigned int meshIndex, unsigned int mask);
void RigidBodyODE::setMeshCollideCategory(unsigned int meshIndex, unsigned int category);
unsigned int RigidBodyODE::getMeshCollideCategory(unsigned int meshIndex);
unsigned int RigidBodyODE::getMeshCollideMask(unsigned int meshIndex);
void RigidBodyODE::setBoxColliderMask(unsigned int box, unsigned int mask);
unsigned int RigidBodyODE::addBoxCollider(const vec3f *pos, const vec3f *size, unsigned int category, unsigned int mask, unsigned int spaceId);
void RigidBodyODE::addLocalForce(const vec3f *f);
void RigidBodyODE::addLocalTorque(const vec3f *t);
void RigidBodyODE::addLocalForceAtPos(const vec3f *f, const vec3f *p);
void RigidBodyODE::addLocalForceAtLocalPos(const vec3f *f, const vec3f *p);
void RigidBodyODE::addForceAtLocalPos(const vec3f *f, const vec3f *p);
vec3f *RigidBodyODE::getLocalPointVelocity(vec3f *result, const vec3f *p);
vec3f *RigidBodyODE::getPointVelocity(vec3f *result, const vec3f *p);
void RigidBodyODE::addForceAtPos(const vec3f *f, const vec3f *p);
void RigidBodyODE::addTorque(const vec3f *t);
void RigidBodyODE::setAngularVelocity(const vec3f *vel);
void RigidBodyODE::setAutoDisable(bool mode);
BOOL RigidBodyODE::isEnabled();
void RigidBodyODE::setEnabled(bool value);

};