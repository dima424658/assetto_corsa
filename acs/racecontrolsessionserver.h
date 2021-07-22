#pragma once

class RaceControlSessionServer
{
void RaceControlSessionServer(Sim *aSim);
void ~RaceControlSessionServer();
// void __userpurge render(@<ecx>, int a2@<esi>, float dt);
void setBackground(ksgui::ksRect *wrect, bool *isDark, GLRenderer *gl);

};