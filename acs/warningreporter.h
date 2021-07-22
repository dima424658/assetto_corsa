#pragma once

class WarningReporter
{
// void __userpurge WarningReporter::WarningReporter(@<ecx>, unsigned int a2@<ebx>, Sim *aSim);
void WarningReporter::~WarningReporter();
void WarningReporter::checkAverage(WarningReporter::WarningStatistic *wa, float valueNow, float deltaT);
void WarningReporter::checkProblems(WarningReporter::WarningStatistic *ws, float valueNow, float deltaT);
void WarningReporter::shutdown();
void WarningReporter::update(float deltaT);

};