#pragma once

class CameraForwardYebis
{
void CameraForwardYebis::setPostProcessing();
// void __userpurge CameraForwardYebis::CameraForwardYebis(@<ecx>, unsigned int a2@<ebx>, const std::wstring *iname, GraphicsManager *graphics, bool blur, bool isYebis, int numberOfParticleGenerators);
char CameraForwardYebis::readPPSetOptions(std::wstring name);
char CameraForwardYebis::loadPPSet(std::wstring name);
void CameraForwardYebis::initRenderTargets();
// void __userpurge CameraForwardYebis::onResize(@<ecx>, unsigned int a2@<ebx>, const OnWindowResize *message);
void CameraForwardYebis::render(Node *blurred, Node *unblurred, Node *shadow, float dt);
KGLRenderTarget *CameraForwardYebis::getYebisDestinationRenderTarget();
void CameraForwardYebis::resetYebisStates();
void CameraForwardYebis::setSolveBlurRenderTarget();
void CameraForwardYebis::renderApplyEffect(Node *blurred, Node *unblurred, Node *shadow, float dt);

};