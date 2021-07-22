#pragma once

class LollipopCrew
{
// void __userpurge LollipopCrew(@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>, CarAvatar *aCar, mat44f matrix, float side, std::wstring skin);
void loadCrewSkin(KN5IO *kn, INIReader *iniS, const std::wstring *section, const std::wstring *key);
void update(float dt);
void updateCurrentPosition(float dt);

};