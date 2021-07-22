#pragma once

class Turbo
{
double getWastegate();
void Turbo(TurboDef *data);
double getBoost();
void setTurboBoostLevel(float value);
void step(float gas, float rpms, float dt);

};