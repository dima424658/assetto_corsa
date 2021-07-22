#pragma once

class ReplayInterface
{
void ReplayInterface::ReplayInterface(ReplayManager *aReplayManager, Sim *aSim);
void ReplayInterface::~ReplayInterface();
ReplayInterface *ReplayInterface::`vector deleting destructor'(unsigned int a2);
void ReplayInterface::didFinishedSavingReplay(bool response);
void ReplayInterface::onMouseMove(const OnMouseMoveEvent *message);
void ReplayInterface::onMouseWheelMovedEvent(const OnMouseWheelMovedEvent *message);
void ReplayInterface::onReplayManagerStatusChanged(eReplayStatus status);
void ReplayInterface::onSliderSelection(const ksgui::OnSliderInteraction *message);
void ReplayInterface::onVisibleChanged(bool newValue);
// void __userpurge ReplayInterface::render(@<ecx>, int i@<esi>, float dt);
void ReplayInterface::resetCuts();
void ReplayInterface::updateUIElementPosition(float dt);
void ReplayInterface::updateUIElementPositionPhotoMode(float dt);

};