#pragma once

class ACGL
{
void ACGL::ACGL(GLRenderer *glRenderer);
void ACGL::~ACGL();
void ACGL::begin(acPrimitiveType primitiveType);
void ACGL::color4f(float r, float g, float b, float a);
void ACGL::drawTexturedQuad(float x, float y, float width, float height, IACTexture *texture);
void ACGL::end();
void ACGL::setOffset(vec2f *off);
void ACGL::texCoord2f(float u, float v);
void ACGL::vertex2f(float x, float y);

};