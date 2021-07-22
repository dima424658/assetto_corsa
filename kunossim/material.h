#pragma once

class Material
{
void Material::Material(const std::wstring *iname, GraphicsManager *graphics);
void Material::Material(const Material *mat);
void Material::~Material();
void Material::apply(RenderContext *rc);
void Material::createCBuffers();
int Material::getResourceIndex(const std::wstring *name);
MaterialVar *Material::getVar(const std::wstring *vname);
void Material::initShaderVars(bool updateOptions);
void Material::resetVars();
// void __userpurge Material::setShader(@<ecx>, unsigned int a2@<ebx>, const std::wstring *name);
void Material::setTexture(const std::wstring *rname, const Texture *tex);
void Material::setVar(const std::wstring *name, const vec3f *value);
void Material::setVar(const std::wstring *name, const vec4f *value);
void Material::setVar(const std::wstring *name, float value);

};