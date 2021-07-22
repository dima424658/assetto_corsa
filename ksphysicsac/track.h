#pragma once

class Track
{
std::wstring *Track::getDataFolder(std::wstring *result);
void Track::Track(PhysicsEngine *pe, const std::wstring *iname, const std::wstring *config);
void Track::~Track();
unsigned int Track::addSurface(const std::wstring *iname, float *vertices, int numVertices, unsigned __int16 *indices, int indexCount, const SurfaceDef *surfaceDef, unsigned int sector_id);
void Track::addTimeLine(const vec3f *p1, const vec3f *p2, TimeLineType type);
IRayCaster *Track::createRayCaster(float length);
int Track::getSector(float normalizedPosition);
void Track::initDynamicTrack();
void Track::initStartingBounds();
bool Track::rayCast(const vec3f *org, const vec3f *dir, RayCastResult *result, float length);
bool Track::rayCastWithRayCaster(const vec3f *org, const vec3f *dir, RayCastResult *result, float length, IRayCaster *rayCaster);
void Track::setGripLevelExternal(float grip);
void Track::step(float dt);
std::wstring *Track::getName(std::wstring *result);

};