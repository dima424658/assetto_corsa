#pragma once

class KN5IO
{
void KN5IO::KN5IO(GraphicsManager *graphics);
void KN5IO::~KN5IO();
void KN5IO::addTextureFolder(const std::wstring *folder);
std::wstring *KN5IO::getSkinOverridenTexturePath(std::wstring *result, std::wstring tname);
Node *KN5IO::load(const std::wstring *filename);
void KN5IO::loadBinaryV1(std::ifstream *in, Node *n);
void KN5IO::loadBinaryV2(std::ifstream *in, Node *n);
// void __userpurge KN5IO::loadMaterialsBinary(@<ecx>, unsigned int a2@<ebx>, std::ifstream *in, std::wstring filename);
std::wstring *KN5IO::loadString(std::wstring *result, std::ifstream *in);
void KN5IO::loadTexture(std::ifstream *in);

};