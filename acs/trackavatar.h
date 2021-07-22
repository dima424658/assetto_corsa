#pragma once

class TrackAvatar
{
// void __userpurge TrackAvatar::TrackAvatar(@<ecx>, __m128 a2@<xmm0>, __m128 a3@<xmm3>, __m128 a4@<xmm4>, Sim *isim, const std::wstring *iunixName, const std::wstring *config);
void TrackAvatar::~TrackAvatar();
void TrackAvatar::addPhysicsMesh(Mesh *mesh, unsigned int sector_id);
AISpline *TrackAvatar::getAISpline();
std::wstring *TrackAvatar::getConfig(std::wstring *result);
std::wstring *TrackAvatar::getDataFolder(std::wstring *result);
int TrackAvatar::getMaxSlotsAvailable(const std::wstring *setName);
std::wstring *TrackAvatar::getSectorDescription(std::wstring *result, float normalizedPosition);
mat44f *TrackAvatar::getSpawnPosition(mat44f *result, const std::wstring *setName, unsigned int index);
AISplineRecorder *TrackAvatar::getSplineRecorder();
SurfaceDef *TrackAvatar::getSurfaceDescFromMeshName(SurfaceDef *result, std::wstring meshname);
void TrackAvatar::init3D();
void TrackAvatar::initDynamicObjects();
void TrackAvatar::initPitCrew();
void TrackAvatar::initRespawnPositionSet(const std::wstring *setName);
void TrackAvatar::initTimeLines();
void TrackAvatar::processPhysicsNode(Node *node);
void TrackAvatar::setDynamicGrooveVisibility(bool visibility);
void TrackAvatar::update(float dt);
void TrackAvatar::updateDynamicObjects(float dt);

};