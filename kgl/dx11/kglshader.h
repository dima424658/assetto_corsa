#pragma once

class KGLShader
{
void KGLShader::KGLShader(const std::wstring *filename, ID3D11Device *device);
void KGLShader::~KGLShader();
void KGLShader::loadShaderBinary(const std::wstring *filename);
void KGLShader::createVertexShader(ID3D10Blob *blob);
void KGLShader::reflectVars(ID3D10Blob *blob, bool isPS);
void KGLShader::addCBuffer(const std::wstring *name, unsigned int size, unsigned int slot);

};