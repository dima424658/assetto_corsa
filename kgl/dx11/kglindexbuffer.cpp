#include "kglindexbuffer.h"

KGLIndexBuffer::KGLIndexBuffer(ID3D11Device* device, unsigned int size, uint16_t* data)
  : buffer{ nullptr }
{
  D3D11_BUFFER_DESC bd;
  bd.ByteWidth = size;
  bd.Usage = D3D11_USAGE_IMMUTABLE;
  bd.BindFlags = D3D11_BIND_INDEX_BUFFER;
  bd.CPUAccessFlags = 0;
  bd.MiscFlags = 0;
  bd.StructureByteStride = 0;

  D3D11_SUBRESOURCE_DATA InitData;
  InitData.pSysMem = data;
  InitData.SysMemPitch = 0;
  InitData.SysMemSlicePitch = 0;

  device->CreateBuffer(&bd, &InitData, &buffer);
}
