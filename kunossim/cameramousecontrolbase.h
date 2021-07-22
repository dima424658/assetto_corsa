#pragma once

class CameraMouseControlBase
{
void CameraMouseControlBase(Camera *camera);
void ~CameraMouseControlBase();
// void __userpurge mouseLook(@<ecx>, int a2@<esi>, float dt, float speed);
void stepKeyboard(float dt, float msp);
void update(float deltaT);

};