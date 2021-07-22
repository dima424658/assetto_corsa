#pragma once

class ESCMenu
{
// void __userpurge ESCMenu::ESCMenu(@<ecx>, unsigned int a2@<ebx>, Sim *aSim, ksgui::GUI *gui);
void ESCMenu::~ESCMenu();
ESCMenu *ESCMenu::`vector deleting destructor'(unsigned int a2);
// ksgui::ActiveButton *__userpurge ESCMenu::addButton@<eax>(@<ecx>, unsigned int a2@<ebx>, std::wstring id, float y);
void ESCMenu::onShutdown();
void ESCMenu::onVisibleChanged(BOOL newValue);
void ESCMenu::render(float dt);
void ESCMenu::selectButton(ksgui::ActiveButton *ab);
void ESCMenu::setDriveButtonEnabled(bool value);
void ESCMenu::setRaceControlScreen();

};