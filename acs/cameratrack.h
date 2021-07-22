#pragma once

class CameraTrack
{
std::wstring *CameraTrack::getCameraSetName(std::wstring *result, unsigned int i);
void CameraTrack::CameraTrack(Sim *isim, CameraForward *icamera);
void CameraTrack::~CameraTrack();
CameraTrack *CameraTrack::`vector deleting destructor'(unsigned int a2);
int CameraTrack::getCameraTrackCount();
CameraManager *CameraTrack::loadSet(int index);
std::wstring *CameraTrack::nextSet(std::wstring *result);
void CameraTrack::setAudioDistanceScale();
void CameraTrack::setCurrentCameraSet(unsigned int cameraIndex);
// void __userpurge CameraTrack::update(@<ecx>, int a2@<esi>, float dt);

};