#pragma once

class ReplayManager
{
void ReplayManager::ReplayManager(Sim *a_sim, PhysicsAvatar *physicsAvatar);
void ReplayManager::~ReplayManager();
ReplayManager *ReplayManager::`vector deleting destructor'(unsigned int a2);
void ReplayManager::clearSaved(std::wstring session, int maxSize);
void ReplayManager::fastForward(int speed, bool pression);
std::wstring *ReplayManager::getAutoFileName(std::wstring *result);
int ReplayManager::getCarLeaderboardPosition(CarAvatar *avatar);
int ReplayManager::getCurrentFrame();
double ReplayManager::getCurrentSunAngle();
std::vector<Lap> *ReplayManager::getLaps(std::vector<Lap> *result, CarAvatar *car);
std::vector<LeaderboardEntry> *ReplayManager::getLeaderboard(std::vector<LeaderboardEntry> *result);
void ReplayManager::getNormalizedLapChange(unsigned int carIndex, std::vector<float> *argumentLapFrames);
double ReplayManager::getNormalizedPosition();
int ReplayManager::getRecordedFrames();
std::wstring *ReplayManager::getReplayFileName(std::wstring *result, std::wstring session);
bool ReplayManager::isInReplaymode();
// char __userpurge ReplayManager::load@<al>(@<ecx>, __m128 a2@<xmm3>, __m128 a3@<xmm4>, const std::wstring *filename);
void ReplayManager::nextFrame();
void ReplayManager::nextLap();
void ReplayManager::onStepCompleted(const OnPhysicsStepCompleted *ev);
void ReplayManager::pause();
void ReplayManager::photoMode();
void ReplayManager::play();
void ReplayManager::previousLap();
void ReplayManager::resetReplay();
// void __userpurge ReplayManager::rewind(@<ecx>, int speed, __int64 pression);
char ReplayManager::save(std::wstring fn, eSaveReplayDir saveDir);
void ReplayManager::setCurrentFrame(int frame);
double ReplayManager::setCutInPerc(float aPerc);
double ReplayManager::setCutOutPerc(float aPerc);
void ReplayManager::setNormalizedPosition(float percentage);
void ReplayManager::slowMotion(float value);
// void __userpurge ReplayManager::startReplayMode(@<ecx>, int a2@<ebp>, unsigned int rewindSeconds);
void ReplayManager::stopReplayMode();
void ReplayManager::updatePlayState(float deltaT);
void ReplayManager::updateReplayAudio();
void ReplayManager::updateReplayRecorders(int aFrame);

};