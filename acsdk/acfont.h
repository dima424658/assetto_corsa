#pragma once

class ACFont
{
void ACFont(Font *ifont, vec2f *off);
void ~ACFont();
void blitString(float x, float y, const std::wstring *message, acFontAlign align);
void setColor(float r, float g, float b);
void setScale(float scale);

};