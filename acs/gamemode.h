#pragma once

class GameMode
{
void GameMode(std::wstring name, Game *aGame);
void ~GameMode();
void forceConditionAchieved(int conditionIndex, bool achieved);
void setTier(int aTier);
std::wstring *getGUID(std::wstring *result);

};