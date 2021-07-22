#pragma once

class TyreSmoke
{
void TyreSmoke(CarAvatar *a_car, int a_tyreIndex);
void ~TyreSmoke();
void onReplayStatusChanged(const OnReplayStatusChanged *message);
void update(float deltaT);

};