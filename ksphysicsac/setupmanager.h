#pragma once

class SetupManager
{
void SetupManager::~SetupManager();
SetupItem *SetupManager::getSetupItem(const std::wstring *name);
void SetupManager::init(Car *acar);
void SetupManager::initItems(bool attached);
char SetupManager::isSetupRespectingRules();
void SetupManager::load(const std::wstring *filename);
void SetupManager::step(float dt);

};