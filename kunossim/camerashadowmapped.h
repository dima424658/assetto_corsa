#pragma once

class CameraShadowMapped
{
void CameraShadowMapped::CameraShadowMapped(const std::wstring *iname, GraphicsManager *gm);
void CameraShadowMapped::~CameraShadowMapped();
CameraShadowMapped *CameraShadowMapped::`vector deleting destructor'(unsigned int a2);
void CameraShadowMapped::beginShadowMapPass(int level, RenderContext *rc, const mat44f *cameraMatrix);
void CameraShadowMapped::createShadowMapMatrix(const mat44f *cameraMatrix, float nearp, float farp, vec3f lightDir, float cameraHeight, mat44f *view, mat44f *proj);
void CameraShadowMapped::initShadowRenderTargets();
void CameraShadowMapped::render(Node *root, float dt);
void CameraShadowMapped::renderPass(Node *root, float dt);
void CameraShadowMapped::setShadowMapsSplits(float s1, float s2, float s3, float s4);
// void __userpurge CameraShadowMapped::shadowMapPass(@<ecx>, unsigned int a2@<ebx>, Node *root, float dt);

};