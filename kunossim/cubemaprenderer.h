#pragma once

class CubeMapRenderer
{
void CubeMapRenderer(GraphicsManager *graphics);
void ~CubeMapRenderer();
void render(CubeMap *cubeMap, Node *root, Camera *sceneCamera);
void setCameraNearFarPlanes(float nearp, float farp);

};