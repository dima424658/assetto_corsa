#pragma once

class SetupScreen
{
void SetupScreen::SetupScreen(Sim *sim);
void SetupScreen::~SetupScreen();
SetupScreen *SetupScreen::`vector deleting destructor'(unsigned int a2);
double SetupScreen::getFixedFuel();
SetupTab *SetupScreen::getSetupTab(std::wstring name);
bool SetupScreen::isFixedFuel();
void SetupScreen::loadINI();
// bool __userpurge SetupScreen::loadSetupAbsolutePath@<al>(@<ecx>, unsigned int i@<ebx>, const std::wstring *loadPath, BOOL isFixed);
char SetupScreen::needToSave();
void SetupScreen::render(float dt);
void SetupScreen::resetTabsValueToDefault();
char SetupScreen::saveSetupAbsolutePath(const std::wstring *savePath);
void SetupScreen::switchVisibility();

};