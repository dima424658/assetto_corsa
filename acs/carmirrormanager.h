#pragma once

class CarMirrorManager
{
void CarMirrorManager(CarAvatar *icar, const Texture *mirrorTexture);
void ~CarMirrorManager();
void update(float dt);

};