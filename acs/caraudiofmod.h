#pragma once

class CarAudioFMOD
{
void CarAudioFMOD::CarAudioFMOD(CarAvatar *car);
void CarAudioFMOD::~CarAudioFMOD();
CarAudioFMOD *CarAudioFMOD::`vector deleting destructor'(unsigned int a2);
void CarAudioFMOD::computeTransforms(mat44f *carTransform, mat44f *engineTransform, mat44f *backfiresTransform, mat44f *hoodTrasform);
bool CarAudioFMOD::isExternalCamera();
BOOL CarAudioFMOD::isOpponentCar();
void CarAudioFMOD::onCarHit(float normalForce, const vec3f *pos, const vec3f *normal, float impactAngle, float relativeSpeed, const unsigned int colliderCategory);
char CarAudioFMOD::onGearChanged(GearChangeRequestDirection direction);
void CarAudioFMOD::playSurface(int wheelID, std::wstring path, const vec3f *carVelocity);
void CarAudioFMOD::renderAudio(float deltaT);
void CarAudioFMOD::setEventVolumes();
bool CarAudioFMOD::shouldUseInternalSounds();
void CarAudioFMOD::startStopEvents();
void CarAudioFMOD::updateSkids(const vec3f *carVelocity, const vec3f *listenerPosition, float dt);
void CarAudioFMOD::updateSurfaces(const float deltaT, const vec3f *carVelocity);
void CarAudioFMOD::updateTurbo(const float deltaT, const mat44f *engineTransform, const vec3f *carVelocity);
void CarAudioFMOD::updateWheels(const vec3f *carVelocity);

};