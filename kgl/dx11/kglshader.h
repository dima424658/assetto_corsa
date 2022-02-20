#pragma once

#include <string>
#include <vector>
#include <fstream>

#include <d3d11.h>
#include <d3d11shader.h>
#include <d3dcompiler.h>

struct KGLShaderTexture
{
  std::wstring name;
  int slot;
};

struct KGLShaderCBuffer
{
  std::wstring cBufferName;
  unsigned int size;
  unsigned int slot;
};

struct KGLShaderVar
{
  std::wstring name;
  std::wstring cBufferName;
  unsigned int cBufferSlot;
  unsigned int size;
  unsigned int offset;
};

class KGLShader
{
public:
    KGLShader(const std::wstring& filename, ID3D11Device* device);
    
    void loadShaderBinary(const std::wstring& filename);
    void createVertexShader(ID3D10Blob* blob);
    void reflectVars(ID3D10Blob* blob, bool isPS);
    void addCBuffer(const std::wstring& name, unsigned int size, unsigned int slot);
    void clearInputLayouts();

protected:
  ID3D11VertexShader *vs;
  ID3D11PixelShader *ps;
  ID3D11InputLayout *inputLayout;

  bool isAlphaTested;
  int ilType;

  std::wstring fileName;
  std::vector<KGLShaderVar> vars;
  std::vector<KGLShaderTexture> textures;
  std::vector<KGLShaderCBuffer> cBuffers;

  ID3D11Device *device;
};

ID3D10Blob* readBlob(const std::wstring& filename);
ID3D11InputLayout* getInputLayout(ID3D11Device* device, void* blob, unsigned int blobsize, const int iltype);