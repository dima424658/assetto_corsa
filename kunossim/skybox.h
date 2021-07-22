#pragma once

class SkyBox
{
// void __userpurge SkyBox::SkyBox(@<ecx>, unsigned int a2@<ebx>, GraphicsManager *graphics);
SkyBox *SkyBox::`vector deleting destructor'(unsigned int a2);
void SkyBox::render(RenderContext *rc);
void SkyBox::renderClouds(RenderContext *rc);
void SkyBox::updateCloudsAnimation(float dt);
void SkyBox::updateCloudsGeneration(const std::wstring *weatherName);

};