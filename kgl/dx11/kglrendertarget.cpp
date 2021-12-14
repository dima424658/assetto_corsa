#include "kglrendertarget.h"

KGLRenderTarget::KGLRenderTarget(ID3D11Device* DXGI_FORMAT fmt, unsigned int iwidth, unsigned int iheight, bool isDepth, int aSamples, int mips)
  : rtTexture{ nullptr },
  shaderResourceView{ nullptr },
  renderTargetViewDepth{ nullptr },
  width{ iwidth },
  height{ iheight },
  samples{ aSamples },
  renderTargetView{ nullptr }
{
  if (isDepth)
  {
    mips = 1;
    fmt = DXGI_FORMAT_R32_TYPELESS;
  }

  D3D11_TEXTURE2D_DESC textureDesc{};
  textureDesc.Width = iwidth;
  textureDesc.Height = iheight;
  textureDesc.MipLevels = mips;
  textureDesc.ArraySize = 1;
  textureDesc.Format = fmt;
  textureDesc.SampleDesc.Count = aSamples;
  textureDesc.SampleDesc.Quality = 0;

  device->CheckMultisampleQualityLevels(fmt, aSamples, &numQualityLevels);

  textureDesc.Usage = D3D11_USAGE_DEFAULT;
  textureDesc.CPUAccessFlags = 0;
  if (isDepth)
  {
    textureDesc.BindFlags = D3D11_BIND_DEPTH_STENCIL | D3D11_BIND_SHADER_RESOURCE;
    textureDesc.MiscFlags = 0;
  }
  else
  {
    textureDesc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
    textureDesc.MiscFlags = mips > 0 ? D3D11_RESOURCE_MISC_GENERATE_MIPS : 0;
  }

  if (isDepth)
  {
    D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilDesc{};
    depthStencilDesc.Format = DXGI_FORMAT_D32_FLOAT;
    depthStencilDesc.ViewDimension = aSamples == 1 ? D3D11_DSV_DIMENSION_TEXTURE2D : D3D11_DSV_DIMENSION_TEXTURE2DMS;
    depthStencilDesc.Flags = 0;

    D3D11_SHADER_RESOURCE_VIEW_DESC shaderResourceViewDesc{};
    shaderResourceViewDesc.Format = DXGI_FORMAT_R32_FLOAT;
    shaderResourceViewDesc.ViewDimension = aSamples == 1 ? D3D11_DSV_DIMENSION_TEXTURE2D : D3D11_DSV_DIMENSION_TEXTURE2DMS;
    shaderResourceViewDesc.Texture2D.MostDetailedMip = 0;
    shaderResourceViewDesc.Texture2D.MipLevels = 1;

    if (device->CreateTexture2D(&textureDesc, nullptr, &rtTexture) < S_OK)
      _printf("ERROR: CreateTexture2D rtTextureDepth failed\n");

    if (device->CreateDepthStencilView(rtTexture, &depthStencilDesc, &renderTargetViewDepth) < S_OK)
      _printf("ERROR: CreateDepthStencilView failed\n");

    if (device->CreateShaderResourceView(rtTexture, &shaderResourceViewDesc, &shaderResourceView) < S_OK)
      _printf("CreateShaderResourceView depth failed\n");
  }
  else
  {
    if (device->CreateTexture2D(&textureDesc, nullptr, &rtTexture) < S_OK)
      _printf("ERROR: CreateTexture2D rtTexture failed\n");

    if (device->CreateRenderTargetView(rtTexture, nullptr, &renderTargetView) < S_OK)
      _printf("ERROR: CreateRenderTargetView failed\n");

    if (device->CreateShaderResourceView(rtTexture, nullptr, &shaderResourceView) < S_OK)
      _printf("CreateShaderResourceView failed\n");
  }
}