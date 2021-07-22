#pragma once

class PIDController
{
void PIDController();
double eval(float targetv, float currentv, float dt);
void reset();
void setPID(float p, float i, float d);

};