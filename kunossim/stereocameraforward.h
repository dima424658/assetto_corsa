#pragma once

class StereoCameraForward
{
// void __userpurge StereoCameraForward::StereoCameraForward(@<ecx>, unsigned int a2@<ebx>, int a3@<ebp>, const std::wstring *iname, GraphicsManager *graphics, bool auseBlur, bool isYebis);
void StereoCameraForward::~StereoCameraForward();
StereoCameraForward *StereoCameraForward::`vector deleting destructor'(unsigned int a2);
// mat44f *__userpurge StereoCameraForward::computeCameraMatrix@<eax>(@<ecx>, __int128 a2@<xmm2>, __int128 a3@<xmm3>, mat44f *result, int eyeRenderPose, int eyeRenderPose_4, int eyeRenderPose_8, int eyeRenderPose_12, __int128 eyeRenderPose_16);
void StereoCameraForward::finishRendering();
// mat44f *__userpurge StereoCameraForward::getFinalWorldMatrix@<eax>(@<ecx>, int a2@<ebp>, __int128 a3@<xmm2>, __int128 a4@<xmm3>, mat44f *result);
mat44f *StereoCameraForward::getPerspectiveMatrix(mat44f *result);
mat44f *StereoCameraForward::getViewMatrix(mat44f *result);
void StereoCameraForward::normalRendering(Node *rootNode, float dt);
// ovrPosef_ *__userpurge StereoCameraForward::oculusRenderPass@<eax>(@<ecx>, __int128 a2@<xmm2>, __int128 a3@<xmm3>, ovrPosef_ *result, const unsigned int screenIndex, Node *rootNode, float dt);
// void __userpurge StereoCameraForward::render(@<ecx>, int a2@<ebp>, __int128 a3@<xmm2>, __int128 a4@<xmm3>, Node *blurred, Node *unblurred, Node *shadow, float dt);
void StereoCameraForward::renderMirrorTexture();
// void __userpurge StereoCameraForward::renderNoPP(@<ecx>, __int128 a2@<xmm2>, __int128 a3@<xmm3>, Node *node, float dt);
// void __userpurge StereoCameraForward::renderYebis(@<ecx>, int a2@<esi>, __int128 a3@<xmm2>, __int128 a4@<xmm3>, Node *node, float dt);
void StereoCameraForward::resetHeadPosition();

};