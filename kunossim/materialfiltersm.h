#pragma once

class MaterialFilterSM
{
// void __userpurge MaterialFilterSM(@<ecx>, unsigned int a2@<ebx>, GraphicsManager *graphics);
void ~MaterialFilterSM();
void apply(const std::shared_ptr<Material> *material, RenderContext *rc);

};