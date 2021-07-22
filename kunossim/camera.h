#pragma once

class Camera
{
void Camera::Camera(const std::wstring *iname, GraphicsManager *rm);
void Camera::~Camera();
void Camera::clearBuffers();
mat44f *Camera::getFinalWorldMatrix(mat44f *result);
mat44f *Camera::getPerspectiveMatrix(mat44f *result);
mat44f *Camera::getViewMatrix(mat44f *result);
void Camera::moveForward(float d);
void Camera::moveRight(float d);
void Camera::moveUpWorld(float d);
void Camera::render(Node *root, float dt);
void Camera::renderAxis(bool useZBuffer);
void Camera::renderCamera();
void Camera::renderCameraCustomPerspective(float left, float right, float top, float bottom);
// void __userpurge Camera::rotateHeading(@<ecx>, int a2@<esi>, float rads);
// void __userpurge Camera::rotateOnAxis(@<ecx>, int a2@<edi>, int a3@<esi>, const vec3f *axis, float rads);
// void __userpurge Camera::rotatePitch(@<ecx>, int a2@<esi>, float rads);
// void __userpurge Camera::rotateRoll(@<ecx>, int a2@<esi>, float rads);
void Camera::setClearColor(float r, float g, float b, float a);

};