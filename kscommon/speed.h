#pragma once

class Speed
{
double kmh();
double toSystemDefault();
void Speed(float v);
Speed *operator*(Speed *result, const float v2);

};