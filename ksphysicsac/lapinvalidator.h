#pragma once

class LapInvalidator
{
void init(Car *car);
void onEnterPenaltyZone(int tyre_count, float black_flag_time);
void step(float dt);

};