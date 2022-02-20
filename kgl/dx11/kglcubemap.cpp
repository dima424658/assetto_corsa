#include "kglcubemap.h"

KGLCubeMap::KGLCubeMap(ID3D11Device *device, unsigned int size, unsigned int format, unsigned int mips)
    : size{size}, mips{mips}
{
  static_assert("not implemented");
  
  D3D11_TEXTURE2D_DESC textureDesc;
  textureDesc.Width = size;
  textureDesc.Height = 1;
  textureDesc.MipLevels = mips;
  textureDesc.ArraySize = size;
  textureDesc.Format = DXGI_FORMAT_D16_UNORM;
  textureDesc.Usage = D3D11_USAGE_IMMUTABLE;
  textureDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL;

  if (FAILED(device->CreateTexture2D(&textureDesc, nullptr, &txDepth)))
    printf("ERROR: FAILED TO CREATE CUBE DEPTH %d\n", size);

  D3D11_DEPTH_STENCIL_VIEW_DESC dsvDesc;
  dsvDesc.Format = DXGI_FORMAT_D16_UNORM;
  dsvDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
  dsvDesc.Texture2D.MipSlice = 1;

  if (FAILED(device->CreateDepthStencilView(txDepth, &dsvDesc, &dsvDepthSingle)))
    printf("ERROR: FAILED TO CREATE CUBE DSV SINGLE\n");

  D3D11_TEXTURE2D_DESC txCubeDesc;
  txCubeDesc.Format = DXGI_FORMAT_R16G16B16A16_FLOAT;
  txCubeDesc.SampleDesc.Count = 1;
  txCubeDesc.SampleDesc.Quality = 0;
  txCubeDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE | D3D11_BIND_RENDER_TARGET;
  txCubeDesc.MiscFlags = D3D11_RESOURCE_MISC_GENERATE_MIPS | D3D11_RESOURCE_MISC_TEXTURECUBE;

  if (FAILED(device->CreateTexture2D(txCubeDesc, nullptr, &txCube)))
    printf("ERROR: FAILED TO CREATE CUBE TEXTURE\n");

  for (auto &it : rtvCubeSingle)
  {
    if (FAILED(device->CreateRenderTargetView(nullptr, nullptr, &it)))
      printf("ERROR: FAILED TO CREATE CUBE RTV SINGLE\n");
  }

  if (FAILED(device->CreateShaderResourceView(nullptr, nullptr, srvCube)))
    printf("ERROR: FAILED TO CREATE CUBE SRV\n");
}

KGLCubeMap::~KGLCubeMap()
{
  if (txDepth)
    txDepth->Release();

  if (dsvDepthSingle)
    dsvDepthSingle->Release();

  if (txCube)
    txCube->Release();

  for (auto &it : rtvCubeSingle)
    if (it)
      it->Release();

  if (srvCube)
    srvCube->Release();
}
