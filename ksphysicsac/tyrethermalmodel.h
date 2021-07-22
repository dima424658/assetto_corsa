#pragma once

class TyreThermalModel
{
void TyreThermalModel::TyreThermalModel();
void TyreThermalModel::~TyreThermalModel();
void TyreThermalModel::addThermalCoreInput(float temp);
void TyreThermalModel::addThermalInput(float xpos, float pressureRel, float temp);
void TyreThermalModel::buildTyre();
double TyreThermalModel::getAvgSurfaceTemp();
double TyreThermalModel::getCorrectedD(float d, float camberRAD);
double TyreThermalModel::getCurrentCPTemp(float camber);
void TyreThermalModel::getIMO(float *out);
TyreThermalPatch *TyreThermalModel::getPatchAt(int x, int y);
double TyreThermalModel::getPracticalTemp(float camberRAD);
void TyreThermalModel::init(int a_elements, int a_stripes, Car *car);
void TyreThermalModel::reset();
void TyreThermalModel::setTemperature(float optimumTemp);
void TyreThermalModel::step(float dt, float angularSpeed, float camberRAD);

};