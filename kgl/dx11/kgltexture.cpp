#include "kgltexture.h"

KGLTexture::KGLTexture(const std::wstring &filename, ID3D11Device *device)
    : shaderResourceView{nullptr}, width{0}, height{0}, ownsShaderResourceView{true}
{
  D3DX11_IMAGE_INFO li;
  D3DX11GetImageInfoFromFile(filename.c_str(), nullptr, &li, nullptr);

  switch (li.ImageFileFormat)
  {
  case D3DX11_IFF_BMP:
    fileFormat = ImageFileFormat::eBMP;
    break;
  case D3DX11_IFF_JPG:
    fileFormat = ImageFileFormat::eJPG;
    break;
  case D3DX11_IFF_PNG:
    fileFormat = ImageFileFormat::ePNG;
    break;
  case D3DX11_IFF_DDS:
    fileFormat = ImageFileFormat::eDDS;
    break;
  default:
    break;
  }

  if (FAILED(D3DX11CreateShaderResourceViewFromFile(device, filename.c_str(), nullptr, nullptr, &shaderResourceView, nullptr)))
  {
    std::printf("ERROR: D3DX11CreateShaderResourceViewFromFileA failed %S\n", filename.c_str());
  }
  else
  {
    initSize();
    fileName = filename;
  }
}

KGLTexture::KGLTexture(const void *buffer, int size, ID3D11Device *device)
    : ownsShaderResourceView{true}
{
  D3DX11_IMAGE_LOAD_INFO li{};
  D3DX11_IMAGE_INFO ili;

  D3DX11GetImageInfoFromMemory(buffer, size, nullptr, &ili, nullptr);

  li.Format = ili.Format;
  li.pSrcInfo = nullptr;
  li.BindFlags = D3D11_BIND_SHADER_RESOURCE;
  li.CpuAccessFlags = 0;
  li.MipFilter = D3DX11_FILTER_TRIANGLE;
  li.MiscFlags = 0;
  li.Usage = D3D11_USAGE_IMMUTABLE;
  if (FAILED(D3DX11CreateShaderResourceViewFromMemory(device, buffer, size, &li, nullptr, &shaderResourceView, nullptr)))
    printf("ERROR: D3DX11CreateShaderResourceViewFromMemory failed\n");

  initSize();
}

KGLTexture::KGLTexture(const void *buffer, DXGI_FORMAT format, unsigned int width, unsigned int height, ID3D11Device *device)
    : ownsShaderResourceView{true}
{
  CD3D11_TEXTURE2D_DESC textureDesc{format, width, height, 1, 1};
  D3D11_SUBRESOURCE_DATA subresourceData{buffer, 4 * width, 4 * width * height};
  ID3D11Texture2D *pTextureInterface;

  if (FAILED(device->CreateTexture2D(&textureDesc, &subresourceData, &pTextureInterface)))
    printf("FAILED CREATING  TEXTURE\n");

  //(*(void(__stdcall **)(int, char *))(*(_DWORD *)device + 160))(device, (char *)&v9 + 4);
  CD3D11_SHADER_RESOURCE_VIEW_DESC srvDesc(D3D11_SRV_DIMENSION_TEXTURE2D, format, 0, 1);
  
  if (FAILED(device->CreateShaderResourceView(pTextureInterface, &srvDesc, &shaderResourceView)))
    printf("ERROR: FAILED CreateShaderResourceView\n");

  //(*(void(__stdcall **)(int))(*(_DWORD *)pTextureInterface + 8))(pTextureInterface);
}

void KGLTexture::initSize()
{
  ID3D11Texture2D *pTextureInterface = nullptr;
  ID3D11Resource *resource;
  D3D11_TEXTURE2D_DESC desc;

  // shaderResourceView->GetResource(reinterpret_cast<ID3D11Resource**>(&pTextureInterface)) ???
  shaderResourceView->GetResource(&resource);
  resource->QueryInterface(IID_ID3D11Texture2D, reinterpret_cast<void **>(&pTextureInterface));

  pTextureInterface->GetDesc(&desc);

  width = desc.Width;
  height = desc.Height;
  textureFormat = desc.Format;

  pTextureInterface->Release();
  resource->Release();
}
