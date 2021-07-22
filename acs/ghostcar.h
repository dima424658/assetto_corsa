#pragma once

class GhostCar
{
void GhostCar(CarAvatar *a_car, GhostCarRecorder *gcr);
void assignGhostMaterial(Node *node);
void init3D();
void loadGhostCarParameters();
// void __userpurge update(@<ecx>, int a2@<edi>, float dt);

};