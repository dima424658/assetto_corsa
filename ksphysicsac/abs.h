#pragma once

class ABS
{
void ABS::~ABS();
void ABS::cycleMode(int value);
std::pair<unsigned int,unsigned int> *ABS::getCurrentMode(std::pair<unsigned int,unsigned int> *result);
void ABS::init(Car *acar);
bool ABS::isInAction();
void ABS::step(float td);

};