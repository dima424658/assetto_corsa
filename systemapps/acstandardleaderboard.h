#pragma once

class ACStandardLeaderboard
{
void ACStandardLeaderboard::ACStandardLeaderboard(Sim *aSim, int numberOfRows, bool aFocusOnPlayer);
void ACStandardLeaderboard::~ACStandardLeaderboard();
void ACStandardLeaderboard::onVisibleChanged(BOOL newValue);
void ACStandardLeaderboard::setLastSession();
void ACStandardLeaderboard::render(float dt);
ACStandardLeaderboard::RowInfo *ACStandardLeaderboard::retrieveRowInfo(ACStandardLeaderboard::RowInfo *result, const std::vector<LeaderboardEntry> *lb, const int leaderboardIndex);
void ACStandardLeaderboard::printLBCar(int rowIndex, const LeaderboardEntry *lb, int time, int gap, ksgui::ksRect wrect);
char ACStandardLeaderboard::onMouseDown(const OnMouseDownEvent *message);

};