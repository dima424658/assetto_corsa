#pragma once

class ACCameraManager
{
void ACCameraManager::ACCameraManager(Sim *isim, CameraForward *icamera);
void ACCameraManager::~ACCameraManager();
ACCameraManager *ACCameraManager::`vector deleting destructor'(unsigned int a2);
void ACCameraManager::fadeIn(FadeModeDef aFadeMode);
bool ACCameraManager::isCameraOnBoard(CarAvatar *car);
bool ACCameraManager::isVirtualMirrorOn();
void ACCameraManager::loadPreviousSessionUserCamera();
void ACCameraManager::registerToFadeInEvent(std::function<void __cdecl(bool const &)> f, void *sender);
void ACCameraManager::setAudioDistanceScale();
void ACCameraManager::setCameraCarIndex(int index);
void ACCameraManager::setDrivableCarIndex(int index);
void ACCameraManager::setKeyboardInputEnabled(bool value);
void ACCameraManager::setMode(CameraMode imode, bool force, bool pIsRandom);
void ACCameraManager::stepCameraRandom(int lastCarIndex);
void ACCameraManager::update(float deltaT);

};