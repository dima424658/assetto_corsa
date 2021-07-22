#include "kglindexbuffer.h"
void KGLIndexBuffer::KGLIndexBuffer(KGLIndexBuffer *this, ID3D11Device *device, unsigned int size, unsigned __int16 *data)
{
  ID3D11Device *v4; // edx
  D3D11_SUBRESOURCE_DATA InitData; // [esp+0h] [ebp-28h] BYREF
  D3D11_BUFFER_DESC bd; // [esp+Ch] [ebp-1Ch] BYREF

  v4 = ::device;
  bd.ByteWidth = size;
  bd.StructureByteStride = 0;
  InitData.SysMemPitch = 0;
  this->buffer = 0;
  bd.Usage = D3D11_USAGE_IMMUTABLE;
  bd.BindFlags = 2;
  bd.CPUAccessFlags = 0;
  bd.MiscFlags = 0;
  InitData.SysMemSlicePitch = 0;
  InitData.pSysMem = data;
  v4->CreateBuffer(v4, &bd, &InitData, &this->buffer);
}
