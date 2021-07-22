#pragma once

class Shader
{
void Shader::Shader(GraphicsManager *graphics, const std::wstring *ifilename);
void Shader::~Shader();
Shader *Shader::`vector deleting destructor'(unsigned int a2);
void Shader::apply();
ShaderVariable *Shader::getVar(const std::wstring *name);
char Shader::initShaderBinary();
void Shader::reflectVars();

};