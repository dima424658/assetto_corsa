#pragma once

class Curve
{
Curve *Curve::operator=(const Curve *__that);
void Curve::Curve(const Curve *__that);
void Curve::Curve();
void Curve::~Curve();
void Curve::addValue(float ref, float val);
int Curve::getCount();
double Curve::getCubicSplineValue(float ref);
double Curve::getMaxReference();
std::pair<float,float> *Curve::getPairAtIndex(std::pair<float,float> *result, int index);
double Curve::getValue(float ref);
void Curve::load(const std::wstring *ifilename);
void Curve::loadEncrypted(const std::wstring *ifilename, const std::wstring *dataFile);
void Curve::print();
void Curve::scale(float v);

};