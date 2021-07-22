#pragma once

class TimeTransponder
{
void TimeTransponder::TimeTransponder();
void TimeTransponder::~TimeTransponder();
void TimeTransponder::addCut();
void TimeTransponder::armFirstLap();
int TimeTransponder::getCuts();
std::vector<unsigned int> *TimeTransponder::getLastLapSplits(std::vector<unsigned int> *result);
TimeLineStatus *TimeTransponder::getStatus(int index);
void TimeTransponder::init(Car *car);
void TimeTransponder::invalidate();
bool TimeTransponder::isInOpenTrackTransition();
char TimeTransponder::isValid();
void TimeTransponder::lap(bool valid);
void TimeTransponder::onTimeLinePassed(int index, bool isFinishLine);
void TimeTransponder::reset();
void TimeTransponder::split(int sectorIndex);
void TimeTransponder::step(float dt);

};