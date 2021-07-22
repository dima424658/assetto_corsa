#pragma once

class ScreenCapturer
{
void ScreenCapturer::ScreenCapturer(std::wstring name, Sim *aSim);
void ScreenCapturer::~ScreenCapturer();
std::wstring *ScreenCapturer::getPath(std::wstring *result);
void ScreenCapturer::renderHUD(float dt);
void ScreenCapturer::saveScreen();
void ScreenCapturer::takeScreen(const std::wstring *path);

};