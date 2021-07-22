#pragma once

class CinematicFreeCamera
{
// void __userpurge CinematicFreeCamera::CinematicFreeCamera(@<ecx>, unsigned int a2@<ebx>, std::wstring name, Camera *aCamera, Game *aGame);
void CinematicFreeCamera::~CinematicFreeCamera();
CinematicFreeCamera *CinematicFreeCamera::`vector deleting destructor'(unsigned int a2);
void CinematicFreeCamera::getKeyboardMovement(mat44f *matrix, float dt, float msp);
void CinematicFreeCamera::getMouseLook(mat44f *matrix, float dt, float speed);
void CinematicFreeCamera::setAudioDistanceScale();
void CinematicFreeCamera::setCameraParameterFromUserInput(float *aFov, float *aDofFactor, float deltaT);
void CinematicFreeCamera::setMatrixMovementFromUserInput(mat44f *inputMatrix, float dt);
// void __userpurge CinematicFreeCamera::standardMouseLook(@<ecx>, int a2@<esi>, float dt, float speed);
// void __userpurge CinematicFreeCamera::update(@<ecx>, unsigned int a2@<ebx>, float deltaT);

};