#pragma once

class ActiveActuator
{
void ~ActiveActuator(CarControlsInput *this);
void ActiveActuator();
double eval(float dt, float currentTravel);

};