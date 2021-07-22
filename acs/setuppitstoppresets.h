#pragma once

class SetupPitstopPresets
{
void SetupPitstopPresets::SetupPitstopPresets(CarAvatar *aCar, QuickMenuPitstop *aPit);
void SetupPitstopPresets::loadFixed(const std::wstring *path);
void SetupPitstopPresets::loadPresets(INIReader *ini);
void SetupPitstopPresets::onVisibleChanged(bool value);
// void __userpurge SetupPitstopPresets::render(@<ecx>, __int64 a2@<esi:edi>, float dt);
void SetupPitstopPresets::savePresets(std::wofstream *file);
void SetupPitstopPresets::syncCarPitstop();
void SetupPitstopPresets::syncSpinners();

};