#pragma once

class RaceTimingServices
{
void RaceTimingServices::RaceTimingServices(Sim *asim);
void RaceTimingServices::~RaceTimingServices();
RaceTimingServices *RaceTimingServices::`vector deleting destructor'(unsigned int a2);
Lap *RaceTimingServices::getBestLap(Lap *result, CarAvatar *car);
unsigned int RaceTimingServices::getBestSplit(const int *sector, const bool *isGlobal, CarAvatar *car);
int RaceTimingServices::getCarLeaderboardPosition(CarAvatar *car);
void RaceTimingServices::getCurrentLapSplits(CarAvatar *car, std::vector<unsigned int> *currentSplits);
bool RaceTimingServices::getHasCompletedFlag(CarAvatar *car);
CarAvatar *RaceTimingServices::getInstanceBestTime(CarAvatar *car);
int RaceTimingServices::getLapCount(CarAvatar *car);
LapDB *RaceTimingServices::getLapDB(CarAvatar *car);
std::vector<Lap> *RaceTimingServices::getLaps(std::vector<Lap> *result, CarAvatar *car);
Lap *RaceTimingServices::getLastLap(Lap *result, CarAvatar *car);
unsigned int RaceTimingServices::getLastSplit(CarAvatar *car, const int *sector);
std::vector<LeaderboardEntry> *RaceTimingServices::getLeaderboard(std::vector<LeaderboardEntry> *result);
unsigned int RaceTimingServices::getSplit(CarAvatar *car, const int *sector);
int RaceTimingServices::getSplit(CarAvatar *car);
long double RaceTimingServices::getTotalTime(CarAvatar *car);
bool RaceTimingServices::isBestSplit(const int *sector, const int *t, const bool *isGlobal, CarAvatar *car);
void RaceTimingServices::onLapCompleted(const OnLapCompletedEvent *event);
void RaceTimingServices::onNewSession(const OnNewSessionEvent *message);
void RaceTimingServices::onSectorSplit(const OnSectorSplitEvent *event);
void RaceTimingServices::resetCurrentLaps();
void RaceTimingServices::setHasCompletedFlag(CarAvatar *car, bool flag);
void RaceTimingServices::shutdown();
void RaceTimingServices::update(float dt);
void RaceTimingServices::updateLeaderboard();

};