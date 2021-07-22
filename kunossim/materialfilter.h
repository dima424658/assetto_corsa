#pragma once

class MaterialFilter
{
void MaterialFilter();
void ~MaterialFilter();
void apply(const std::shared_ptr<Material> *material, RenderContext *rc);
void resetMaterialCache(Turbo *this);

};