#pragma once

class DriftModeComponent
{
BOOL checkExtremeDrifting();
void init(Car *car);
void step(float dt);
void validateDrift();

};