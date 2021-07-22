#pragma once

class CameraDrivableManager
{
// void __userpurge CameraDrivableManager::CameraDrivableManager(@<ecx>, unsigned int a2@<ebx>, Sim *sim, CameraForward *camera);
void CameraDrivableManager::~CameraDrivableManager();
CameraDrivableManager *CameraDrivableManager::`vector deleting destructor'(unsigned int a2);
void CameraDrivableManager::initChaseCamFromINI();
void CameraDrivableManager::lookBack();
char CameraDrivableManager::nextMode();
void CameraDrivableManager::setCurrentCamera(int cameraIndex);
void CameraDrivableManager::setDrivableCameraDefAt(int index, DrivableCameraDef def);
bool CameraDrivableManager::shouldUseInternalSounds();
void CameraDrivableManager::update(float deltaT);
void CameraDrivableManager::updateBonnet(float dt);
void CameraDrivableManager::updateBumper(float dt);
// void __userpurge CameraDrivableManager::updateChase(@<ecx>, int a2@<esi>, float dt);
void CameraDrivableManager::updateDash(float dt);
void CameraDrivableManager::updateLook(float deltaT);

};