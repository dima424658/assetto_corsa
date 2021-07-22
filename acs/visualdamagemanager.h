#pragma once

class VisualDamageManager
{
void VisualDamageManager(CarAvatar *car);
void ~VisualDamageManager();
void initScratchableParts(INIReader *ini);
void update(float deltaT);

};