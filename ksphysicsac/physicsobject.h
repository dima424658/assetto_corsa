#pragma once

class PhysicsObject
{
void PhysicsObject(PhysicsEngine *pe, PhysicsObjectDesc *desc, BufferedChannel<mat44f> *chOut);
PhysicsObject *`vector deleting destructor'(unsigned int a2);
mat44f *getWorldMatrix(mat44f *result);
void setWorldMatrix(const mat44f *worldMatrix);

};