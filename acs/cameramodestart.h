#pragma once

class CameraModeStart
{
void CameraModeStart(Sim *sim, CameraTrack *cameraTrack, CameraForward *camera, const std::wstring *trackName, const std::wstring *trackConfig);
void renderHUD(float deltaT);
void update(float deltaT);
void updateCar(float dt);

};