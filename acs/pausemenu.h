#pragma once

class PauseMenu
{
void PauseMenu::PauseMenu(Sim *isim, ksgui::GUI *gui);
void PauseMenu::~PauseMenu();
PauseMenu *PauseMenu::`vector deleting destructor'(unsigned int a2);
void PauseMenu::blankButton(ePauseMenuButtons button, bool value);
ksgui::ActiveButton *PauseMenu::getButtonByName(const std::wstring *name);
void PauseMenu::onVisibleChanged(bool newValue);
// void __userpurge PauseMenu::render(@<ecx>, float a2@<ebp>, int a3@<edi>, int a4@<esi>, float dt);

};