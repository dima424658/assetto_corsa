#pragma once

class Font
{
void Font(const std::wstring *fontFamily, eFontType fontType, float size, int italic, int bold);
void Font(eFontType fontType, float size, int italic, int bold);
void blitString(float x, float y, const std::wstring *s, float ascale, eFontAlign align);
void setColor(const vec4f *cc);
void setColor(float r, float g, float b, float a);

};