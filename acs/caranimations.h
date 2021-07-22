#pragma once

class CarAnimations
{
void CarAnimations(CarAvatar *aCar);
void ~CarAnimations();
void setDoorOpen(bool mode);
void update(float dt);

};