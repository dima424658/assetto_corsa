#pragma once

class AudioEngine
{
void AudioEngine::~AudioEngine();
void AudioEngine::addBankRef(const std::wstring *path);
void AudioEngine::addCache(const std::wstring *path);
AudioEvent *AudioEngine::getCachedEvent(const std::wstring *path);
std::wstring *AudioEngine::getDriverInfo(std::wstring *result, int driverIndex);
int AudioEngine::getDriverNum();
vec3f *AudioEngine::getListenerPosition(vec3f *result);
AudioStats *AudioEngine::getPerformanceStats(AudioStats *result);
double AudioEngine::getVolume(const bool target);
bool AudioEngine::hasEvent(const std::wstring *path);
double AudioEngine::listenerDistance(vec3f position);
AudioEngine::GUID *AudioEngine::lookupGUID(AudioEngine::GUID *result, const std::wstring *path);
void AudioEngine::parseGUIDs(const std::wstring *path);
void AudioEngine::rampVolume(const float dt);
void AudioEngine::releaseCachedEvent(AudioEvent *_event);
void AudioEngine::removeBankRef(const std::wstring *path);
void AudioEngine::setDistanceScale(const float scale);
void AudioEngine::setDriver(int driverIndex);
void AudioEngine::setListener(const mat44f *transform, const vec3f *velocity);
// void __userpurge AudioEngine::setVolume(@<ecx>, int a2@<esi>, const float volume);
void AudioEngine::start();
void AudioEngine::stop();
// void __userpurge AudioEngine::update(@<ecx>, int a2@<ebp>, int a3@<edi>, float *a4@<esi>, const float dt);
void AudioEngine::updateProperties();

};