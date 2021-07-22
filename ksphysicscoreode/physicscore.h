#pragma once

class PhysicsCore
{
CoreCPUTimes *PhysicsCore::getCoreCPUTimes(CoreCPUTimes *result);
void PhysicsCore::PhysicsCore();
void PhysicsCore::~PhysicsCore();
void PhysicsCore::step(float dt);
void PhysicsCore::createRigidBody();
void PhysicsCore::release();
IJoint *PhysicsCore::createDistanceJoint(IRigidBody *rb1, IRigidBody *rb2, const vec3f *p1, const vec3f *p2);
void PhysicsCore::reseatDistanceJointLocal(IJoint *joint, const vec3f *p1, const vec3f *p2);
IJoint *PhysicsCore::createBumpJoint(IRigidBody *rb1, IRigidBody *rb2, const vec3f *p1, float rangeUp, float rangeDn);
IJoint *PhysicsCore::createFixedJoint(IRigidBody *rb1, IRigidBody *rb2);
IJoint *PhysicsCore::createBallJoint(IRigidBody *rb1, IRigidBody *rb2, const vec3f *pos);
IJoint *PhysicsCore::createSliderJoint(IRigidBody *rb1, IRigidBody *rb2, const vec3f *axis);
void PhysicsCore::createCollisionMesh(float *vertices, unsigned int numVertices, unsigned __int16 *indices, int indexCount, const mat44f *worldMatrix, IRigidBody *body, unsigned int group, unsigned int mask, unsigned int space_id);
RayCastHit *PhysicsCore::rayCast(RayCastHit *result, const vec3f *pos, const vec3f *dir, float length);
RayCastHit *PhysicsCore::rayCast(RayCastHit *result, const vec3f *pos, const vec3f *dir, dxGeom *rayc);
void PhysicsCore::setCollisionCallback(ICollisionCallback *callback);
void PhysicsCore::collisionStep();
void PhysicsCore::onCollision(dContactGeom *contacts, int numContacts, dxGeom *g0, dxGeom *g1);
void PhysicsCore::setSliderAxis(IJoint *joint, const vec3f *axis, const vec3f *anchor);
void PhysicsCore::createRayCaster(float length);
void PhysicsCore::setNoCollisionSteps(int steps);
dxSpace *PhysicsCore::getStaticSubSpace(unsigned int index);
dxSpace *PhysicsCore::getDynamicSubSpace(unsigned int index);
void PhysicsCore::resetCollisions();

};