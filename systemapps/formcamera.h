#pragma once

class FormCamera
{
// void __userpurge FormCamera::FormCamera(@<ecx>, unsigned int a2@<ebx>, Sim *a_sim, CameraForwardYebis *camera);
void FormCamera::render(float dt);
void FormCamera::selectCamera(CameraMode mode, int index);
void FormCamera::setCamera();
void FormCamera::decreaseExp();
void FormCamera::increaseExp();
void FormCamera::updateSens();
void FormCamera::elev(int direction);
void FormCamera::move(int direction);
void FormCamera::strafe(int direction);
void FormCamera::rotate(vec3f v, int direction);
void FormCamera::savecameraF1();
void FormCamera::savecameraF6();

};