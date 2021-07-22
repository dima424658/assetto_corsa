#pragma once

class Spline
{
void Spline::Spline();
void Spline::~Spline();
void Spline::addPoint(const vec3f *p, int tag);
void Spline::addSplinePoint(const SplinePoint *p);
void Spline::applyMatrix(const mat44f *m);
double Spline::boundInsideSpline(float value);
void Spline::clear();
unsigned int Spline::closestPointIndex(const vec3f *point, float *distance);
unsigned int Spline::closestPointIndexWithBounds(const vec3f *point, const std::vector<SplineIndexBound> *bounds, float *distance);
std::vector<unsigned int> *Spline::closestPointIndicesFlat(std::vector<unsigned int> *result, const vec3f *point, unsigned int numberOfNeigbours, float *distance);
vec3f *Spline::getPointSmooth(vec3f *result, float v);
vec3f *Spline::getSplineDirection(vec3f *result, const vec3f *point);
bool Spline::isClosed();
double Spline::length();
void Spline::loadFromCSV(std::wstring filename);
vec3f *Spline::pointAt(vec3f *result, unsigned int index);
int Spline::pointsCount();
void Spline::reverse();
void Spline::setPointAt(unsigned int index, vec3f point);
SplinePoint *Spline::splinePointAt(SplinePoint *result, unsigned int index);
int Spline::tagAt(unsigned int index);
int Spline::wrapIndex(int index);

};