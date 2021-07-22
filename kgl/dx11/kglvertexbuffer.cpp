#include "kglvertexbuffer.h"
void __userpurge KGLVertexBuffer::KGLVertexBuffer(KGLVertexBuffer *this@<ecx>, int a2@<edi>, int a3@<esi>, ID3D11Device *device, unsigned int size, unsigned int stride, void *data, bool isDynamic)
{
  ID3D11Device *v9; // ecx
  ID3D11Device_vtbl *v10; // eax
  int v11; // eax
  __int64 v13; // [esp+Ch] [ebp-3Ch] BYREF
  int v14; // [esp+14h] [ebp-34h]
  __int128 v15; // [esp+18h] [ebp-30h] BYREF
  __int64 v16; // [esp+28h] [ebp-20h]

  v15 = 0i64;
  v9 = ::device;
  v16 = 0i64;
  this->buffer = 0;
  this->stride = stride;
  if ( isDynamic )
  {
    DWORD1(v15) = 2;
    HIDWORD(v15) = 0x10000;
  }
  else
  {
    DWORD1(v15) = 1;
    HIDWORD(v15) = 0;
  }
  LODWORD(v15) = size;
  DWORD2(v15) = 1;
  LODWORD(v16) = 0;
  v14 = 0;
  v13 = (unsigned int)data;
  v10 = v9->__vftable;
  if ( data )
    v11 = ((int (__stdcall *)(ID3D11Device *, __int128 *, __int64 *, KGLVertexBuffer *, int, int))v10->CreateBuffer)(
            v9,
            &v15,
            &v13,
            this,
            a2,
            a3);
  else
    v11 = ((int (__stdcall *)(ID3D11Device *, __int128 *, _DWORD, KGLVertexBuffer *, int, int))v10->CreateBuffer)(
            v9,
            &v15,
            0,
            this,
            a2,
            a3);
  if ( v11 < 0 )
    _printf("FAILED TO CREATE VERTEX BUFFER size:%d stride:%d dynamic:%d\n", size, stride, isDynamic);
}
