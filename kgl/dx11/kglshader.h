#pragma once

class KGLShader
{
void KGLShader::KGLShader(const std::wstring *filename, ID3D11Device *device);
void KGLShader::~KGLShader();
void KGLShader::loadShaderBinary(const std::wstring *filename);
void KGLShader::createVertexShader(ID3D10Blob *blob);
void KGLShader::reflectVars(ID3D10Blob *blob, bool isPS);
void KGLShader::addCBuffer(const std::wstring *name, unsigned int size, unsigned int slot);
void KGLShader::clearInputLayouts();

};

ID3D10Blob *__thiscall readBlob(const std::wstring *filename);
ID3D11InputLayout *__usercall getInputLayout@<eax>(ID3D11Device *device@<ecx>, void *blob@<edx>, unsigned int blobsize, const int iltype); idb

std::wstring *__thiscall std::wstring::operator=(std::wstring *this, std::wstring *_Right); // idb
std::wstring *__thiscall std::wstring::operator=(std::wstring *this, const std::wstring *_Right); // idb
void __thiscall std::vector<KGLShaderVar>::~vector<KGLShaderVar>(std::vector<KGLShaderVar> *this); // idb
void __thiscall std::vector<KGLShaderVar>::push_back(std::vector<KGLShaderVar> *this, const KGLShaderVar *_Val); // idb
void __thiscall std::vector<KGLShaderTexture>::~vector<KGLShaderTexture>(std::vector<KGLShaderTexture> *this); // idb
void __thiscall std::vector<KGLShaderTexture>::push_back(std::vector<KGLShaderTexture> *this, const KGLShaderTexture *_Val); // idb
void __thiscall std::vector<KGLShaderCBuffer>::~vector<KGLShaderCBuffer>(std::vector<FriendsLeaderboardDisplayer::FriendsLeaderboardElement> *this); // idb
void __thiscall std::vector<KGLShaderCBuffer>::push_back(std::vector<KGLShaderCBuffer> *this, const KGLShaderCBuffer *_Val); // idb
ID3D11InputLayout **__thiscall std::map<int,ID3D11InputLayout *>::operator[](std::map<int,ID3D11InputLayout *> *this, const int *_Keyval); // idb
