#pragma once

class ERS
{
void ERS::ERS();
void ERS::~ERS();
ERS *ERS::`vector deleting destructor'(char *this, unsigned int a2);
double ERS::getCoastTorque();
double ERS::getOutputTorque();
void ERS::init(Car *car);
void ERS::reset();
void ERS::setPowerController(int index);
void ERS::step(float dt);

};