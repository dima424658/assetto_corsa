#include "kgltexture.h
KGLTexture *KGLTexture::`scalar deleting destructor'(KGLTexture *this, unsigned int a2)
{
  ID3D11ShaderResourceView *v3; // ecx

  v3 = this->shaderResourceView;
  if ( v3 && this->ownsShaderResourceView )
    v3->Release(v3);
  if ( this->fileName._Myres >= 8 )
    operator delete(this->fileName._Bx._Ptr);
  this->fileName._Myres = 7;
  this->fileName._Mysize = 0;
  this->fileName._Bx._Buf[0] = 0;
  operator delete(this);
  return this;
}
void KGLTexture::KGLTexture(KGLTexture *this, const std::wstring *filename, ID3D11Device *device)
{
  ID3D11Device *v4; // ebp
  std::wstring *v5; // ebx
  const std::wstring *v6; // edi
  const std::wstring *v7; // eax
  const std::wstring *v8; // eax
  D3DX11_IMAGE_INFO li; // [esp+18h] [ebp-34h] BYREF
  int v10; // [esp+48h] [ebp-4h]

  v4 = ::device;
  v5 = &this->fileName;
  v6 = filename;
  this->shaderResourceView = 0;
  this->textureFormat = DXGI_FORMAT_UNKNOWN;
  this->fileName._Myres = 7;
  this->fileName._Mysize = 0;
  this->fileName._Bx._Buf[0] = 0;
  v10 = 0;
  this->width = 0;
  this->height = 0;
  this->ownsShaderResourceView = 1;
  this->fileFormat = eUnknown;
  if ( filename->_Myres < 8 )
    v7 = filename;
  else
    v7 = (const std::wstring *)filename->_Bx._Ptr;
  D3DX11GetImageInfoFromFileW(v7, 0, &li, 0);
  switch ( li.ImageFileFormat )
  {
    case D3DX11_IFF_BMP:
      this->fileFormat = eBMP;
      break;
    case D3DX11_IFF_JPG:
      this->fileFormat = eJPG;
      break;
    case D3DX11_IFF_PNG:
      this->fileFormat = ePNG;
      break;
    case D3DX11_IFF_DDS:
      this->fileFormat = eDDS;
      break;
    default:
      break;
  }
  if ( filename->_Myres < 8 )
    v8 = filename;
  else
    v8 = (const std::wstring *)filename->_Bx._Ptr;
  if ( (int)D3DX11CreateShaderResourceViewFromFileW(v4, v8, 0, 0, this, 0) >= 0 )
  {
    KGLTexture::initSize(this);
    if ( v5 != filename )
      std::wstring::assign(v5, filename, 0, 0xFFFFFFFF);
  }
  else
  {
    if ( filename->_Myres >= 8 )
      v6 = (const std::wstring *)filename->_Bx._Ptr;
    _printf("ERROR: D3DX11CreateShaderResourceViewFromFileA failed %S\n", v6->_Bx._Buf);
  }
}
void KGLTexture::KGLTexture(KGLTexture *this, const void *buffer, int size, ID3D11Device *device)
{
  ID3D11Device *v5; // edi
  D3DX11_IMAGE_LOAD_INFO li; // [esp+10h] [ebp-6Ch] BYREF
  KGLTexture *v7; // [esp+44h] [ebp-38h]
  D3DX11_IMAGE_INFO ili; // [esp+48h] [ebp-34h] BYREF
  int v9; // [esp+78h] [ebp-4h]

  v5 = ::device;
  this->shaderResourceView = 0;
  this->textureFormat = DXGI_FORMAT_UNKNOWN;
  this->fileName._Myres = 7;
  this->fileName._Mysize = 0;
  v7 = this;
  this->fileName._Bx._Buf[0] = 0;
  v9 = 0;
  this->width = 0;
  this->height = 0;
  this->ownsShaderResourceView = 1;
  this->fileFormat = eUnknown;
  D3DX11GetImageInfoFromMemory(buffer, size, 0, &ili, 0);
  li.Format = ili.Format;
  li.Width = -1;
  li.pSrcInfo = 0;
  li.BindFlags = 8;
  li.CpuAccessFlags = 0;
  li.Depth = -1;
  li.Filter = -1;
  li.FirstMipLevel = -1;
  li.Height = -1;
  li.MipFilter = 4;
  li.MipLevels = -1;
  li.MiscFlags = 0;
  li.Usage = D3D11_USAGE_IMMUTABLE;
  if ( (int)D3DX11CreateShaderResourceViewFromMemory(v5, buffer, size, &li, 0, this, 0) < 0 )
    _printf("ERROR: D3DX11CreateShaderResourceViewFromMemory failed\n");
  KGLTexture::initSize(this);
}
void KGLTexture::KGLTexture(KGLTexture *this, const void *buffer, DXGI_FORMAT format, unsigned int width, unsigned int height, ID3D11Device *device)
{
  ID3D11Device *v7; // eax
  int v8; // esi
  __int64 v9; // [esp+10h] [ebp-70h] BYREF
  int v10[4]; // [esp+18h] [ebp-68h] BYREF
  __int64 v11; // [esp+28h] [ebp-58h]
  int v12[3]; // [esp+30h] [ebp-50h] BYREF
  ID3D11Device *v13; // [esp+3Ch] [ebp-44h]
  int v14; // [esp+40h] [ebp-40h] BYREF
  int v15[4]; // [esp+44h] [ebp-3Ch] BYREF
  DXGI_FORMAT v16; // [esp+54h] [ebp-2Ch]
  int v17; // [esp+58h] [ebp-28h]
  int v18; // [esp+5Ch] [ebp-24h]
  int v19; // [esp+60h] [ebp-20h]
  int v20; // [esp+64h] [ebp-1Ch]
  int v21; // [esp+68h] [ebp-18h]
  int v22; // [esp+6Ch] [ebp-14h]
  int v23; // [esp+7Ch] [ebp-4h]

  v7 = ::device;
  this->shaderResourceView = 0;
  this->fileFormat = eUnknown;
  this->textureFormat = DXGI_FORMAT_UNKNOWN;
  v13 = v7;
  this->fileName._Myres = 7;
  this->fileName._Mysize = 0;
  this->fileName._Bx._Buf[0] = 0;
  v23 = 0;
  this->width = 0;
  this->height = 0;
  this->ownsShaderResourceView = 1;
  v15[1] = height;
  v12[0] = (int)buffer;
  v8 = (int)v13;
  v12[1] = 4 * width;
  v15[0] = width;
  v15[2] = 1;
  v12[2] = 4 * height * width;
  v15[3] = 1;
  v17 = 1;
  v18 = 0;
  v19 = 0;
  v16 = format;
  v20 = 8;
  v21 = 0;
  v22 = 0;
  if ( v13->CreateTexture2D(
         v13,
         (const D3D11_TEXTURE2D_DESC *)v15,
         (const D3D11_SUBRESOURCE_DATA *)v12,
         (ID3D11Texture2D **)&v14) < 0 )
    _printf("FAILED CREATING  TEXTURE\n");
  (*(void (__stdcall **)(int, char *))(*(_DWORD *)v8 + 160))(v8, (char *)&v9 + 4);
  v11 = 0i64;
  v10[0] = v16;
  v10[2] = 0;
  v10[3] = 1;
  v10[1] = 4;
  if ( (*(int (__stdcall **)(int, int, int *, KGLTexture *))(*(_DWORD *)v8 + 28))(v8, v14, v10, this) < 0 )
    _printf("ERROR: FAILED CreateShaderResourceView\n");
  (*(void (__stdcall **)(int))(*(_DWORD *)v14 + 8))(v14);
}
void KGLTexture::initSize(KGLTexture *this)
{
  ID3D11Texture2D *pTextureInterface; // [esp+1Ch] [ebp-38h] BYREF
  ID3D11Resource *resource; // [esp+20h] [ebp-34h] BYREF
  D3D11_TEXTURE2D_DESC desc; // [esp+24h] [ebp-30h] BYREF

  this->shaderResourceView->GetResource(this->shaderResourceView, &resource);
  pTextureInterface = 0;
  resource->QueryInterface(resource, &_GUID_6f15aaf2_d208_4e89_9ab4_489535d34f9c, (void **)&pTextureInterface);
  pTextureInterface->GetDesc(pTextureInterface, &desc);
  this->width = desc.Width;
  this->height = desc.Height;
  this->textureFormat = desc.Format;
  pTextureInterface->Release(pTextureInterface);
  resource->Release(resource);
}
