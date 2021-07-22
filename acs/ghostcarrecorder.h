#pragma once

class GhostCarRecorder
{
void GhostCarRecorder::update(TyreTester *this, float dt);
void GhostCarRecorder::GhostCarRecorder(CarAvatar *iavatar, Car *icar, bool isRecording, bool isPlaying);
void GhostCarRecorder::~GhostCarRecorder();
mat44f *GhostCarRecorder::getBodyMatrix(mat44f *result);
std::wstring *GhostCarRecorder::getGhostCarFileName(std::wstring *result, bool onConstructor);
mat44f *GhostCarRecorder::getSuspensionMatrix(mat44f *result, int index);
mat44f *GhostCarRecorder::getTyreMatrix(mat44f *result, int index);
char GhostCarRecorder::loadGhostCarRecording(std::wstring filename);
void GhostCarRecorder::onLapCompleted(const OnLapCompletedEvent *message);
void GhostCarRecorder::onStepComplete(const OnStepCompleteEvent *ev);
char GhostCarRecorder::saveGhostCarRecording();
void GhostCarRecorder::setCurrentFrame(unsigned int frame);
bool GhostCarRecorder::shouldDisplayGhostCar();

};