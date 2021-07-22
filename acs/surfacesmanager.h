#pragma once

class SurfacesManager
{
void SurfacesManager(TrackAvatar *track);
void ~SurfacesManager();
SurfacesManager *`vector deleting destructor'(unsigned int a2);
SurfaceDef *getSurface(SurfaceDef *result, std::wstring name);
void loadSurfaceDefinitions(std::wstring filename);

};