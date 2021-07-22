#pragma once

class ReplayRecorder
{
void ReplayRecorder::ReplayRecorder(CarAvatar *iavatar, ICarPhysicsStateProvider *aPhysics);
void ReplayRecorder::~ReplayRecorder();
ReplayRecorder *ReplayRecorder::`vector deleting destructor'(char *this, unsigned int a2);
ReplayRecorder *ReplayRecorder::`vector deleting destructor'(unsigned int a2);
void ReplayRecorder::clearFrames();
void ReplayRecorder::fetchLapFrames(std::vector<unsigned int> *lapFramesArgument);
void ReplayRecorder::getPhysicsState(CarPhysicsState *ps);
void ReplayRecorder::getWingState(std::vector<WingState> *wingStatuses);
unsigned int ReplayRecorder::load(std::ifstream *in, int aVersion);
void ReplayRecorder::recordFrame(const CarPhysicsState *physicsState);
void ReplayRecorder::save(std::ofstream *out, int cutIn, int cutOut, int cutSize, int pivot);
void ReplayRecorder::setFrameSize(int size);

};