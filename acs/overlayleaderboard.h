#pragma once

class OverlayLeaderboard
{
void OverlayLeaderboard::OverlayLeaderboard(Sim *aSim);
void OverlayLeaderboard::~OverlayLeaderboard();
void OverlayLeaderboard::drawCell(const LeaderboardEntry *entry, int position, const std::wstring *time, float x, float y, SessionType ses_type);
void OverlayLeaderboard::drawVerticalCell(const LeaderboardEntry *entry, int position, const std::wstring *time, float x, float y, SessionType ses_type);
std::wstring *OverlayLeaderboard::filterName(std::wstring *result, const std::wstring *originalName);
void OverlayLeaderboard::renderHUD(float dt);
void OverlayLeaderboard::shutdown();
void OverlayLeaderboard::update(float dt);

};