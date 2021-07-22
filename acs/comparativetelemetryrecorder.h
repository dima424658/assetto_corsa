#pragma once

class ComparativeTelemetryRecorder
{
void ComparativeTelemetryRecorder::ComparativeTelemetryRecorder(CarAvatar *aCar);
void ComparativeTelemetryRecorder::~ComparativeTelemetryRecorder();
ComparativeTelemetryRecorder *ComparativeTelemetryRecorder::`vector deleting destructor'(unsigned int a2);
unsigned int ComparativeTelemetryRecorder::getBestTime();
std::vector<CTData> *ComparativeTelemetryRecorder::getBestTimeData();
void ComparativeTelemetryRecorder::getCTOpponents(std::vector<CTDriver> *opponents);
unsigned int ComparativeTelemetryRecorder::getLastTime();
std::vector<CTData> *ComparativeTelemetryRecorder::getLastTimeData();
// std::vector<CTData> *__userpurge ComparativeTelemetryRecorder::loadCTOpponent@<eax>(@<ecx>, unsigned int a2@<ebx>, std::vector<CTData> *result, std::wstring fileName);
void ComparativeTelemetryRecorder::saveBest();
void ComparativeTelemetryRecorder::shutdown();
void ComparativeTelemetryRecorder::update(float dt);

};