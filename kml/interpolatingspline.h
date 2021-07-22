#pragma once

class InterpolatingSpline
{
void InterpolatingSpline::InterpolatingSpline();
void InterpolatingSpline::~InterpolatingSpline();
void InterpolatingSpline::addPoint(const vec3f *p, int tag);
void InterpolatingSpline::addSplinePoint(const SplinePoint *p);
void InterpolatingSpline::bezierEndopoint();
void InterpolatingSpline::buildGrid();
vec3f *InterpolatingSpline::calculateCatmullRom(vec3f *result, const float t);
vec3f *InterpolatingSpline::calculateCubicBezier(vec3f *result, const float t);
// vec3f *__userpurge InterpolatingSpline::calculateCubicSpline@<eax>(@<ecx>, __m128 a2@<xmm0>, vec3f *result, const float pos);
vec3f *InterpolatingSpline::calculateLinear(vec3f *result, const float pos);
vec3f *InterpolatingSpline::calculateNthBezier(vec3f *result, const float t);
vec3f *InterpolatingSpline::calculateUniformBSpline(vec3f *result, const float t);
void InterpolatingSpline::clear();
const vec3f *InterpolatingSpline::closestPointIndex(const vec3f *point, float *distance);
const vec3f *InterpolatingSpline::closestPointIndexGrid(const vec3f *position, float *distance);
void InterpolatingSpline::computeSplineLength();
void InterpolatingSpline::filterPointsTooClose(float minDistance);
unsigned int InterpolatingSpline::getLastIndexFromNorm(float t, float *blendToNext);
double InterpolatingSpline::getNormalizedPosition(const unsigned int index);
double InterpolatingSpline::getSignedDistanceFromSpline(const vec3f *p, float splinePosition);
bool InterpolatingSpline::isGridOn();
vec3f *InterpolatingSpline::linearProjection(vec3f *result, const vec3f *point, int closestIndex);
void InterpolatingSpline::loadGrid(std::ifstream *in);
void InterpolatingSpline::popBack();
void InterpolatingSpline::saveGrid(std::ofstream *out);
vec3f *InterpolatingSpline::splineToWorld(vec3f *result, float pos);
double InterpolatingSpline::worldToSpline(const vec3f *pos, int closestIndex);
double InterpolatingSpline::wrapPosition(float pos);

};