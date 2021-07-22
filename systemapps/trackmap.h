#pragma once

class TrackMap
{
void TrackMap::TrackMap(ksgui::GUI *a_gui, Sim *a_sim, bool zoomed);
TrackMap *TrackMap::`vector deleting destructor'(unsigned int a2);
void TrackMap::createMap();
void TrackMap::setSize(ComparativeTelemetry *this, float width, float height);
void TrackMap::showMapOnScreen();
// void __userpurge TrackMap::render(@<ecx>, __int64 a2@<esi:edi>, float dt);
void TrackMap::showMapOnScreenZoom(vec3f carPosition, vec3f carDirection);
void TrackMap::~TrackMap();

};