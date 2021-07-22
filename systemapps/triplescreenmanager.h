#pragma once

class TripleScreenManager
{
void TripleScreenManager::TripleScreenManager(Sim *sim);
TripleScreenManager *TripleScreenManager::`vector deleting destructor'(unsigned int a2);
void TripleScreenManager::initGraphicalComponents();
void TripleScreenManager::~TripleScreenManager();
void TripleScreenManager::onSpinnerValueChanged(const ksgui::OnSpinnerValueChanged *ev);
// void __userpurge TripleScreenManager::render(@<ecx>, int a2@<edi>, float dt);
void TripleScreenManager::updateGraphicalInterfaceData();
void TripleScreenManager::drawVirtualDisplay(VirtualDisplay *vd);
// void __userpurge TripleScreenManager::rotateLateralScreen(VirtualDisplay *vd, int rotationVertex);

};