#pragma once

class SetupIOManager
{
void SetupIOManager::SetupIOManager(Sim *aSim);
void SetupIOManager::~SetupIOManager();
std::wstring *SetupIOManager::getPathFromSetupName(std::wstring *result, const std::wstring *setupName, bool strategy);
void SetupIOManager::onVisibleChanged(bool newValue);
void SetupIOManager::refreshSetupListBox();
void SetupIOManager::refreshStatus();
// void __userpurge SetupIOManager::render(@<ecx>, __int64 a2@<esi:edi>, float dt);
void SetupIOManager::resetUI();
void SetupIOManager::setOverrideStatus(bool overrideStatus);
void SetupIOManager::setRemoveStatus(bool removeStatus);
void SetupIOManager::setSelectedTrack(const std::wstring *track);
void SetupIOManager::showStatus(bool show, std::wstring text);

};