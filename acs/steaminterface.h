#pragma once

class SteamInterface
{
void SteamInterface::SteamInterface(Sim *aSim);
void SteamInterface::~SteamInterface();
SteamInterface *SteamInterface::`vector deleting destructor'(unsigned int a2);
void SteamInterface::OnDownloadScore(LeaderboardScoresDownloaded_t *pDownloadLeaderboardResult, bool bIOFailure);
void SteamInterface::OnFindLeaderboard(LeaderboardFindResult_t *pFindLeaderboardResult, bool bIOFailure);
void SteamInterface::OnUploadScore(LeaderboardScoreUploaded_t *pScoreUploadedResult, bool bIOFailure);
void SteamInterface::achievementCheck();
void SteamInterface::achievementCompleted(std::wstring achievementName);
void SteamInterface::addAchievement(std::wstring aName);
void SteamInterface::addAchievements();
void SteamInterface::createLeaderboards(std::wstring carName, std::wstring trackName, std::wstring trackConfig);
void SteamInterface::damageRelatedAchievements();
void SteamInterface::driftAchievements();
void SteamInterface::fetchPlayerImage();
void SteamInterface::generalAchievements();
void SteamInterface::incrementStat(std::wstring name);
// void __userpurge SteamInterface::onUserStatsReceived(@<ecx>, unsigned int a2@<ebx>, UserStatsReceived_t *parameters);
void SteamInterface::onUserStatsStored(UserStatsStored_t *parameters);
void SteamInterface::practiceAchievements();
void SteamInterface::refreshPlayerLeaderboard();
void SteamInterface::resetAchievements();
void SteamInterface::resetPlayerLeaderboard();
void SteamInterface::timeAttackAchievements();
void SteamInterface::update(float dt);

};