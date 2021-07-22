#pragma once

class SplashScreen
{
// void __userpurge SplashScreen::SplashScreen(@<ecx>, unsigned int a2@<ebx>, Game *igame);
void SplashScreen::~SplashScreen();
void SplashScreen::addLoadingCar(const std::wstring *carUnixName);
// void __userpurge SplashScreen::loadHints(@<ecx>, unsigned int a2@<ebx>, const std::wstring *carmodel);
// void __userpurge SplashScreen::postRender(@<ecx>, unsigned int a2@<ebx>, int a3@<esi>, __m128 a4@<xmm3>, __m128 a5@<xmm4>, float deltaT);
void SplashScreen::renderHUD(float deltaT);
void SplashScreen::setCurrentMessage(const std::wstring *msg);
// void __userpurge SplashScreen::setOnlinePlayerCar(@<ecx>, unsigned int a2@<ebx>, const std::wstring *model, const std::wstring *config);
void SplashScreen::setServerHints(const std::vector<std::wstring> *ihints);

};