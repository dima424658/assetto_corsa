#pragma once

class CameraOnBoardFree
{
// void __userpurge CameraOnBoardFree::CameraOnBoardFree(@<ecx>, unsigned int a2@<ebx>, std::wstring name, Camera *a_camera, Sim *a_sim);
CameraOnBoardFree *CameraOnBoardFree::`vector deleting destructor'(unsigned int a2);
void CameraOnBoardFree::forceThetaPhi(float aTheta, float aPhi, float aRadius);
void CameraOnBoardFree::setIntroMode(bool value);
void CameraOnBoardFree::update(float dt);
vec3f *CameraOnBoardFree::updateSphericalCoord(vec3f *result, float deltaT);
void CameraOnBoardFree::setPosition(const vec3f *pos);

};