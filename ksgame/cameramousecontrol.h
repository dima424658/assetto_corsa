#pragma once

class CameraMouseControl
{
void CameraMouseControl(std::wstring name, Camera *camera, Game *igame);
void setAudioDistanceScale();
void update(float deltaT);

};