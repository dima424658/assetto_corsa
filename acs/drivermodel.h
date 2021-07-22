#pragma once

class DriverModel
{
void DriverModel::DriverModel(CarAvatar *car, GraphicsManager *graphics, bool a_isHR);
void DriverModel::~DriverModel();
void DriverModel::addNodeHierarchyToHeadHide(Node *n);
void DriverModel::animateHShifter(float dt);
void DriverModel::animatePaddles(float dt);
vec3f *DriverModel::getEyesPosition(vec3f *result);
double DriverModel::getShiftDownPlayerCurrentPosition();
void DriverModel::loadDriverSkin(KN5IO *kn, INIReader *iniS, const std::wstring *section, const std::wstring *key);
void DriverModel::setLockedPosition();
void DriverModel::setVisible(bool v);
void DriverModel::update(float dt);
// void __userpurge DriverModel::updateHeadMovement(@<ecx>, int a2@<edi>, int a3@<esi>, float *dt, float *dynDeltaT, vec3f *accG, int a7, __int128 a8, __int128 a9, mat44f a10, DirectX::XMMATRIX M2, DirectX::XMMATRIX a12, __m128 a13);

};