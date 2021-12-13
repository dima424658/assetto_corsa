#include "kglrendertarget.h"
void KGLRenderTarget::KGLRenderTarget(KGLRenderTarget *this, ID3D11Device *device, DXGI_FORMAT fmt, unsigned int iwidth, unsigned int iheight, bool isDepth, int aSamples, int mips)
{
  ID3D11Device *v8; // esi
  ID3D11Device_vtbl *v10; // eax
  ID3D11Device_vtbl *v11; // eax
  ID3D11Texture2D *v12; // [esp+14h] [ebp-8Ch]
  ID3D11Texture2D *v13; // [esp+14h] [ebp-8Ch]
  ID3D11Device *v14; // [esp+28h] [ebp-78h]
  unsigned int v15; // [esp+2Ch] [ebp-74h] BYREF
  __int128 v16; // [esp+30h] [ebp-70h] BYREF
  __int64 v17; // [esp+40h] [ebp-60h]
  __int128 v18; // [esp+50h] [ebp-50h] BYREF
  __int64 v19; // [esp+60h] [ebp-40h]
  int v20[11]; // [esp+70h] [ebp-30h] BYREF

  v8 = ::device;
  v14 = ::device;
  this->format = fmt;
  this->width = iwidth;
  this->height = iheight;
  this->samples = aSamples;
  this->rtTexture = 0;
  this->renderTargetView = 0;
  this->shaderResourceView = 0;
  this->renderTargetViewDepth = 0;
  memset(v20, 0, sizeof(v20));
  v20[0] = iwidth;
  v20[3] = 1;
  v20[1] = iheight;
  if ( isDepth )
  {
    v20[2] = 1;
    v20[4] = 39;
    v20[5] = aSamples;
    v20[6] = 0;
    v8->CheckMultisampleQualityLevels(v8, fmt, aSamples, &v15);
    v20[6] = 0;
    v20[7] = 0;
    v20[8] = 72;
    v20[9] = 0;
    v20[10] = 0;
    if ( v8->CreateTexture2D(v8, (const D3D11_TEXTURE2D_DESC *)v20, 0, &this->rtTexture) < 0 )
      _printf("ERROR: CreateTexture2D rtTextureDepth failed\n");
    v18 = 0i64;
    v19 = 0i64;
    v12 = this->rtTexture;
    LODWORD(v18) = 40;
    DWORD1(v18) = 2 * (v20[5] != 1) + 3;
    v10 = v8->__vftable;
    HIDWORD(v18) = 0;
    if ( v10->CreateDepthStencilView(v8, v12, (const D3D11_DEPTH_STENCIL_VIEW_DESC *)&v18, &this->renderTargetViewDepth) < 0 )
      _printf("ERROR: CreateDepthStencilView failed\n");
    v16 = 0i64;
    v13 = this->rtTexture;
    v17 = 0i64;
    *(_QWORD *)((char *)&v16 + 4) = 2 * (unsigned int)(v20[5] != 1) + 4;
    v11 = v8->__vftable;
    LODWORD(v16) = 41;
    HIDWORD(v16) = 1;
    if ( v11->CreateShaderResourceView(
           v8,
           v13,
           (const D3D11_SHADER_RESOURCE_VIEW_DESC *)&v16,
           &this->shaderResourceView) < 0 )
      _printf("CreateShaderResourceView depth failed\n");
  }
  else
  {
    v20[2] = mips;
    v20[5] = aSamples;
    v14->CheckMultisampleQualityLevels(v14, fmt, aSamples, &v15);
    v20[4] = this->format;
    v20[6] = 0;
    v20[7] = 0;
    v20[8] = 40;
    v20[9] = 0;
    v20[10] = mips != 1;
    if ( v14->CreateTexture2D(v14, (const D3D11_TEXTURE2D_DESC *)v20, 0, &this->rtTexture) < 0 )
      _printf("ERROR: CreateTexture2D rtTexture failed\n");
    if ( v14->CreateRenderTargetView(v14, this->rtTexture, 0, &this->renderTargetView) < 0 )
      _printf("ERROR: CreateRenderTargetView failed\n");
    if ( v14->CreateShaderResourceView(v14, this->rtTexture, 0, &this->shaderResourceView) < 0 )
      _printf("CreateShaderResourceView failed\n");
  }
}

KGLRenderTarget::KGLRenderTarget(ID3D11Device* device, DXGI_FORMAT fmt, unsigned int iwidth, unsigned int iheight, bool isDepth, int aSamples, int mips)
{

}
