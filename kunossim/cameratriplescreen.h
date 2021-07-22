#pragma once

class CameraTripleScreen
{
void CameraTripleScreen(const std::wstring *name, GraphicsManager *graphics, int numberOfParticleManagers);
void beginVirtualScreenPass(int cameraIndex);
void renderPass(Node *root, float dt);

};