#pragma once

class StartingLights
{
    
void StartingLights(Sim *sim);
void ~StartingLights();

void renderHUD(float deltaT);
void renderLight(float x, float y, vec3f colour);

};