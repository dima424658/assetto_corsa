#pragma once

class AppForm
{
// void __userpurge AppForm::AppForm(@<ecx>, unsigned int a2@<ebx>, ACOperatingSystem *iacos, std::wstring form_name);
AppForm *AppForm::`vector deleting destructor'(unsigned int a2);
IACControl *AppForm::addControl();
void AppForm::addEventListener(KeyboardManager *this, IKeyEventListener *l);
void AppForm::render(float dt);
void AppForm::setAutoHideMode(bool mode);
// void __userpurge AppForm::setIcon(@<ecx>, unsigned int a2@<ebx>, const std::wstring *filename);
void AppForm::setWindowSize(int width, int height);

};