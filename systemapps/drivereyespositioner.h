#pragma once

class DriverEyesPositioner
{
// void __userpurge DriverEyesPositioner::DriverEyesPositioner(@<ecx>, unsigned int a2@<ebx>, CarAvatar *aCar);
void DriverEyesPositioner::saveToDashINI();
void DriverEyesPositioner::saveToINI();
void DriverEyesPositioner::saveSettings();
// void __userpurge DriverEyesPositioner::render(@<ecx>, int a2@<esi>, float dt);
void DriverEyesPositioner::onRenderFinished(const OnNodeRenderEvent *ev);
void DriverEyesPositioner::~DriverEyesPositioner();

};