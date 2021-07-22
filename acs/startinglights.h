#pragma once

class StartingLights
{
void StartingLights(Sim *sim);
void ~StartingLights();
StartingLights *`vector deleting destructor'(unsigned int a2);
void renderHUD(float deltaT);
void renderLight(float x, float y, vec3f colour);

};