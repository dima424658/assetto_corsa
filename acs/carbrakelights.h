#pragma once

class CarBrakeLights
{
void CarBrakeLights::CarBrakeLights(CarAvatar *acar);
void CarBrakeLights::~CarBrakeLights();
CarBrakeLights *CarBrakeLights::`vector deleting destructor'(unsigned int a2);
bool CarBrakeLights::getFrontLightOn();
int CarBrakeLights::getVars(const Mesh *m);
void CarBrakeLights::loadLights();
void CarBrakeLights::update(float deltaT);

};