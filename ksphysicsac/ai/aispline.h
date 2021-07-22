#pragma once

class AISpline
{
InterpolatingSpline *AISpline::getBaseSpline();
AISpline *AISpline::operator=(const AISpline *__that);
void AISpline::AISpline();
void AISpline::~AISpline();
void AISpline::addPoint(const vec3f *point, const AISplinePayload *payload);
void AISpline::adjustPayloadEndpoint(const int numberOfPoints);
void AISpline::buildGrid();
// void __userpurge AISpline::buildSides(@<ecx>, __m128 a2@<xmm0>, IRayTrackCollisionProvider *track);
// void __userpurge AISpline::calculateNormals(@<ecx>, __m128 a2@<xmm0>, IRayTrackCollisionProvider *track);
void AISpline::calculateRadius(int range);
void AISpline::cleanSpline();
void AISpline::clear();
void AISpline::closeSmooth();
double AISpline::getCornerRadiusAt(float normalizedPosition, float distance, float lateralOffset, float carWidth);
double AISpline::getDistToCornerFwd(float thresholdRadius, float normalizedSplinePosition, float resolution);
double AISpline::getDistToCornerRev(float thresholdRadius, float normalizedSplinePosition, float resolution);
vec3f *AISpline::getLastPoint(vec3f *result);
void AISpline::getPayloadIndices(float pos, unsigned int *i0, unsigned int *i1, float *blend);
vec3f *AISpline::getPointWithOffset(vec3f *result, float pos, float lateralOffset, float carHalfWidth);
vec3f *AISpline::getPointWithOffset(vec3f *result, float pos, float lateralOffset, float carHalfWidth, const AISplinePayload *pl);
void AISpline::getSidesAtPos(float pos, float *sides, unsigned int use_blend);
void AISpline::getSlimPayloadAt(float pos, AISplineSlimPayload *pl);
char AISpline::getStraightDataFromIndex(int index, AIStraightData *data, float radiusThreshold);
double AISpline::getStraightFactor();
void AISpline::initPitlane(IRayTrackCollisionProvider *track);
void AISpline::initStraights(float radiusThreshold);
int AISpline::isInStraight(float normalizedPos);
// void __userpurge AISpline::load(@<ecx>, __m128 a2@<xmm3>, __m128 a3@<xmm4>, const std::wstring *a_filename);
// void __userpurge AISpline::loadFast(@<ecx>, __m128 a2@<xmm3>, __m128 a3@<xmm4>, const std::wstring *a_filename);
// void __userpurge AISpline::loadVersion6(@<ecx>, __m128 a2@<xmm3>, std::ifstream *in);
// void __userpurge AISpline::loadVersion7(@<ecx>, __m128 a2@<xmm3>, __m128 a3@<xmm4>, std::ifstream *in);
AISplinePayload *AISpline::payloadAtPosition(AISplinePayload *result, float pos);
AISplinePayload *AISpline::payloadAtSplineIndex(AISplinePayload *result, const unsigned int index);
int AISpline::pointsCount();
void AISpline::save(std::wstring filen);
void AISpline::setPayloadAtSplineIndex(const unsigned int index, AISplinePayload pl);

};