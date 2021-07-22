#pragma once

class ThermalObject
{
void ThermalObject();
void ~ThermalObject();
void addHeadSource(float heat);
void step(const float dt, const float ambientTemp, const Speed *speed);

};