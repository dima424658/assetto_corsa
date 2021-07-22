#pragma once

class FuelLapEvaluator
{
long double getFuelLaps();
long double getFuelPerLap();
void init(Car *icar);
void setIgnoreLap(bool value);
void step(float dt);

};