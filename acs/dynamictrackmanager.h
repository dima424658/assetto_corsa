#pragma once

class DynamicTrackManager
{
void DynamicTrackManager(Sim *aSim, const std::wstring *trackDataFolder);
void setGrooveMeshVisibility(bool visible);
void update(float dt);

};