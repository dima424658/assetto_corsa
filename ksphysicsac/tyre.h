#pragma once

class Tyre
{
void Tyre::Tyre();
void Tyre::~Tyre();
void Tyre::addGroundContact(const vec3f *pos, const vec3f *normal);
void Tyre::addTyreForceToHub(const vec3f *pos, const vec3f *force);
void Tyre::addTyreForces(const vec3f *pos, const vec3f *normal, SurfaceDef *surfaceDef, float dt);
// void __userpurge Tyre::addTyreForcesV10(@<ecx>, int a2@<edi>, const vec3f *pos, const vec3f *normal, SurfaceDef *surfaceDef, float dt, float a7);
char Tyre::generateCompoundNames();
double Tyre::getCamberedDy(float camberRAD, float dy);
double Tyre::getCorrectedD(float d, float *wear_mult);
double Tyre::getDX(float load);
double Tyre::getDY(float load);
double Tyre::getDynamicK();
mat44f *Tyre::getFinalTyreRotation(mat44f *result);
vec3f *Tyre::getWorldPosition(vec3f *result);
void Tyre::init(ISuspension *ihub, IRayTrackCollisionProvider *rcp, std::wstring dataPath, int index, int carID, Car *car);
void Tyre::initCompounds(const std::wstring *dataPath, int index);
void Tyre::rayCast(const vec3f *org, const vec3f *dir, RayCastResult *res);
void Tyre::reset();
char Tyre::setCompound(int cindex);
// void __userpurge Tyre::step(@<ecx>, float a2@<edi>, float dt);
void Tyre::stepDirtyLevel(float dt, const float hubSpeed);
void Tyre::stepFlatSpot(float dt, float hubVelocity);
void Tyre::stepGrainBlister(float dt, float hubVelocity);
void Tyre::stepRelaxationLength(float svx, float svy, float hubVelocity, float dt);
void Tyre::stepRotationMatrix(float dt);
void Tyre::stepThermalModel(float dt);
void Tyre::stepTyreBlankets(float dt);
void Tyre::updateAngularSpeed(float dt);

};