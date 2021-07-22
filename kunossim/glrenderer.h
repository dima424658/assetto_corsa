#pragma once

class GLRenderer
{
void GLRenderer::GLRenderer(GraphicsManager *r, unsigned int maxVertices, bool withFullScreenQuad);
void GLRenderer::~GLRenderer();
GLRenderer *GLRenderer::`vector deleting destructor'(unsigned int a2);
void GLRenderer::begin(eGLPrimitiveType type, Shader *ishader);
void GLRenderer::color3f(float r, float g, float b);
void GLRenderer::color4f(const vec4f *v);
void GLRenderer::color4f(float r, float g, float b, float a);
void GLRenderer::end();
void GLRenderer::fullScreenQuad(Shader *ishader);
void GLRenderer::quad(float x, float y, float width, float height, bool textured, Shader *shader);
void GLRenderer::quadCentred(float x, float y, float width, float height, bool textured, Shader *shader);
// void __userpurge GLRenderer::quadCentredRotated(@<ecx>, int a2@<esi>, float x, float y, float width, float height, float rotationRAD, bool textured, Shader *shader);
void GLRenderer::spline(const Spline *spline);
void GLRenderer::texCoord2f(float u, float v);
void GLRenderer::vertex3fv(const float *v);
void GLRenderer::vertex3f(float x, float y, float z);

};