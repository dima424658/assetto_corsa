#pragma once

class RenderWindow
{
void RenderWindow(std::wstring name, VideoSettings *videoSettings);
void ~RenderWindow();
BOOL hasFocus();
void setFocus();
BOOL step();

};