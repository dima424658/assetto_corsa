#pragma once

class PerformanceMeter
{
void PerformanceMeter::~PerformanceMeter();
PerformanceSplit *PerformanceMeter::getCurrentSplit(PerformanceSplit *result);
BOOL PerformanceMeter::hasData();
void PerformanceMeter::init(Car *car);
void PerformanceMeter::reset();
void PerformanceMeter::step(float dt);

};