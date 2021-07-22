#pragma once

class SplineLocator
{
void getSides(float *sides, float nsplinepos);
void init(Car *car);
void reset();
void resetToClosestPoint();
void step(float dt);

};