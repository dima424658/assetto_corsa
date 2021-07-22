#pragma once

class CameraForward
{
void CameraForward::render(TyreTester *this, float erp, float cfm);
void CameraForward::CameraForward(const std::wstring *iname, GraphicsManager *graphics, bool auseBlur);
void CameraForward::~CameraForward();
CameraForward *CameraForward::`vector deleting destructor'(unsigned int a2);
// void __userpurge CameraForward::onResize(@<ecx>, unsigned int a2@<ebx>, const OnWindowResize *message);
void CameraForward::preparePostRenderTargets();
void CameraForward::render(Node *blurred, Node *unblurred, Node *shadow, float dt);
void CameraForward::renderBlurred(Node *blurred, Node *unblurred, Node *transparent, float dt);
void CameraForward::resetHDR();
void CameraForward::setBloomBaseLevel(float bl);
void CameraForward::setBloomLevel(float bl);
void CameraForward::setCubemapSize(unsigned int size);
void CameraForward::setHighPassThreshold(float t);
void CameraForward::setSolveBlurRenderTarget();
void CameraForward::solveBlur(float dt);

};