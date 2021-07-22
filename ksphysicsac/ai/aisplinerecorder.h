#pragma once

class AISplineRecorder
{
InterpolatingSpline *AISplineRecorder::getLeftSpline();
// void __userpurge AISplineRecorder::AISplineRecorder(@<ecx>, __m128 a2@<xmm0>, __m128 a3@<xmm3>, __m128 a4@<xmm4>, PhysicsEngine *pe, Track *track);
void AISplineRecorder::beginPitLaneSpline();
void AISplineRecorder::endPitLaneSpline();
AISpline *AISplineRecorder::getBestLapSpline();
double AISplineRecorder::getBrakeHintAtSplinePos(float normalizedPos);
bool AISplineRecorder::getDangerAtSplinePos(float normalizedPos, float *left, float *right);
double AISplineRecorder::getHintAtSplinePos(float normalizedPos);
double AISplineRecorder::getMaxSpeedHintAtSplinePos(float normalizedPos);
AISpline *AISplineRecorder::getPitLaneSpline();
void AISplineRecorder::loadHints();
void AISplineRecorder::loadSideSpline(InterpolatingSpline *is, std::wstring filename);
void AISplineRecorder::onLapCompleted(const OnLapCompletedEvent *message);
void AISplineRecorder::recomputeSidesFromCsv();
// void __userpurge AISplineRecorder::save(@<ecx>, __m128 a2@<xmm0>, bool updateFile);
void AISplineRecorder::startRecording();
void AISplineRecorder::step(float dt);

};