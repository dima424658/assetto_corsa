#pragma once

class SetupTab
{
void SetupTab::SetupTab(std::wstring aname, ksgui::GUI *aGui, Sim *sim);
void SetupTab::~SetupTab();
SetupTab *SetupTab::`vector deleting destructor'(unsigned int a2);
void SetupTab::addItem(SetupItemDef *item);
void SetupTab::drawFrame(const ksgui::ksRect *wrect);
std::wstring *SetupTab::getStringToSave(std::wstring *result);
void SetupTab::loadFromINI(INIReader *ini, bool isFixed);
void SetupTab::onVisibleChanged(bool value);
// void __userpurge SetupTab::render(@<ecx>, __int64 a2@<esi:edi>, float dt);
void SetupTab::resetToDefaultValues();
void SetupTab::setValueToSpinner(ksgui::Spinner *sp, bool isFixed, int spinnerValue);

};