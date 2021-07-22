#pragma once

class WrongWayIndicator
{
// void __userpurge WrongWayIndicator(@<ecx>, unsigned int a2@<ebx>, CarAvatar *car);
void ~WrongWayIndicator();
void renderHUD(float deltaT);
void resetMeterCounter();
void update(float deltaT);

};