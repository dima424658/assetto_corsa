#pragma once

class TractionControl
{
void ~TractionControl();
void cycleMode(int value);
std::pair<unsigned int,unsigned int> *getCurrentMode(std::pair<unsigned int,unsigned int> *result);
void init(Car *acar);
void step(float dt);

};