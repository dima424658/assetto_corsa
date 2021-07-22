#pragma once

class StringBlitter3D
{
double StringBlitter3D::getFontSize();
void StringBlitter3D::StringBlitter3D(const std::wstring *name, GraphicsManager *graphics);
void StringBlitter3D::~StringBlitter3D();
void StringBlitter3D::blitString(const std::wstring *s, float scale, eFontAlign align, vec3f offset);
void StringBlitter3D::blitString(const std::wstring *s, mat44f rotationMatrix, float scale, eFontAlign align, vec3f offset);
void StringBlitter3D::blitStringV2(const std::wstring *s, float scale, eFontAlign align, vec3f offset);
double StringBlitter3D::getStringWidth(const std::wstring *s);
void StringBlitter3D::initCoords(const std::wstring *name);
void StringBlitter3D::initTexture(const std::wstring *name);
void StringBlitter3D::setColor(const vec4f *a_color);
void StringBlitter3D::setScaleConst(float s);

};