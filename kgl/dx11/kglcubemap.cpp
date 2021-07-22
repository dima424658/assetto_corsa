#include "kglcubemap.h"
void KGLCubeMap::KGLCubeMap(KGLCubeMap *this, ID3D11Device *device, unsigned int size, unsigned int format, unsigned int mips)
{
  KGLCubeMap *v5; // esi
  ID3D11Device *v6; // edi
  ID3D11Device_vtbl *v7; // eax
  ID3D11Device_vtbl *v8; // ecx
  ID3D11Device_vtbl *v9; // eax
  int v10; // esi
  ID3D11RenderTargetView **v11; // edi
  int v12; // eax
  int v13; // ecx
  ID3D11Texture2D *v14; // [esp+24h] [ebp-6Ch]
  ID3D11Texture2D *v15; // [esp+24h] [ebp-6Ch]
  int v16; // [esp+40h] [ebp-50h]
  int *v18; // [esp+48h] [ebp-48h]
  _OWORD v19[3]; // [esp+50h] [ebp-40h] BYREF

  v5 = this;
  v6 = ::device;
  this->size = size;
  this->mips = mips;
  v18 = (int *)v6;
  memset(v19, 0, 0x2Cu);
  LODWORD(v19[0]) = size;
  *(_QWORD *)((char *)v19 + 4) = __PAIR64__(mips, size);
  v7 = v6->__vftable;
  HIDWORD(v19[0]) = 1;
  *((_QWORD *)&v19[1] + 1) = 0i64;
  *(_QWORD *)&v19[1] = 0x100000037i64;
  LODWORD(v19[2]) = 64;
  *(_QWORD *)((char *)&v19[2] + 4) = 0i64;
  if ( v7->CreateTexture2D(v6, (const D3D11_TEXTURE2D_DESC *)v19, 0, &v5->txDepth) < 0 )
  {
    _printf("ERROR: FAILED TO CREATE CUBE DEPTH %d\n", size);
    _fflush(0);
  }
  v8 = v6->__vftable;
  v19[0] = 0x300000037ui64;
  *(_QWORD *)&v19[1] = 0i64;
  v14 = v5->txDepth;
  DWORD1(v19[1]) = 1;
  if ( v8->CreateDepthStencilView(v6, v14, (const D3D11_DEPTH_STENCIL_VIEW_DESC *)v19, &this->dsvDepthSingle) < 0 )
  {
    _printf("ERROR: FAILED TO CREATE CUBE DSV SINGLE\n");
    _fflush(0);
  }
  if ( !format || (v16 = 10, format != 1) )
    v16 = 28;
  memset(v19, 0, 0x2Cu);
  LODWORD(v19[0]) = size;
  *(_QWORD *)((char *)v19 + 4) = __PAIR64__(mips, size);
  *(_QWORD *)&v19[1] = (unsigned int)v16 | 0x100000000i64;
  v9 = v6->__vftable;
  HIDWORD(v19[0]) = 6;
  *((_QWORD *)&v19[1] + 1) = 0i64;
  *(_QWORD *)&v19[2] = 40i64;
  DWORD2(v19[2]) = 5;
  if ( v9->CreateTexture2D(v6, (const D3D11_TEXTURE2D_DESC *)v19, 0, &this->txCube) < 0 )
  {
    _printf("ERROR: FAILED TO CREATE CUBE TEXTURE\n");
    _fflush(0);
  }
  v10 = 0;
  v11 = this->rtvCubeSingle;
  *(_QWORD *)&v19[0] = (unsigned int)v16 | 0x500000000i64;
  *((_QWORD *)&v19[0] + 1) = 0i64;
  LODWORD(v19[1]) = 1;
  do
  {
    v12 = *v18;
    HIDWORD(v19[0]) = v10;
    if ( (*(int (__stdcall **)(int *, ID3D11Texture2D *, _OWORD *, ID3D11RenderTargetView **))(v12 + 36))(
           v18,
           this->txCube,
           v19,
           v11) < 0 )
    {
      _printf("ERROR: FAILED TO CREATE CUBE RTV SINGLE\n");
      _fflush(0);
    }
    ++v10;
    ++v11;
  }
  while ( v10 < 6 );
  v19[0] = 0i64;
  *(_QWORD *)&v19[0] = (unsigned int)v16 | 0x900000000i64;
  v13 = *v18;
  HIDWORD(v19[0]) = mips;
  *(_QWORD *)&v19[1] = 0i64;
  v15 = this->txCube;
  DWORD2(v19[0]) = 0;
  if ( (*(int (__stdcall **)(int *, ID3D11Texture2D *, _OWORD *, ID3D11ShaderResourceView **))(v13 + 28))(
         v18,
         v15,
         v19,
         &this->srvCube) < 0 )
    _printf("ERROR: FAILED TO CREATE CUBE SRV\n");
}
void KGLCubeMap::~KGLCubeMap(KGLCubeMap *this)
{
  ID3D11Texture2D *v2; // ecx
  ID3D11DepthStencilView *v3; // ecx
  ID3D11Texture2D *v4; // ecx
  ID3D11RenderTargetView **v5; // esi
  int v6; // edi
  ID3D11ShaderResourceView *v7; // ecx

  v2 = this->txDepth;
  if ( v2 )
    v2->Release(v2);
  v3 = this->dsvDepthSingle;
  if ( v3 )
    v3->Release(this->dsvDepthSingle);
  v4 = this->txCube;
  if ( v4 )
    v4->Release(this->txCube);
  v5 = this->rtvCubeSingle;
  v6 = 6;
  do
  {
    if ( *v5 )
      (*v5)->Release(*v5);
    ++v5;
    --v6;
  }
  while ( v6 );
  v7 = this->srvCube;
  if ( v7 )
    v7->Release(this->srvCube);
}
