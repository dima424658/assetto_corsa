#pragma once

class CameraMeshFilter
{
void CameraMeshFilter(Camera *icamera, RenderPassID passid, int amaxLayer);
void ~CameraMeshFilter();
char isVisible(Renderable *mesh, const mat44f *currentMatrix);

};