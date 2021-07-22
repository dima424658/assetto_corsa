#pragma once

class CameraCarManager
{
void CameraCarManager(Sim *a_sim, CameraForward *a_camera);
int getCameraCount();
void nextCamera();
void setCurrentCamera(unsigned int cameraIndex);
void update(float dt);

};