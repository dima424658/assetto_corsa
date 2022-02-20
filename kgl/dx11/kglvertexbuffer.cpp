#include "kglvertexbuffer.h"
KGLVertexBuffer::KGLVertexBuffer(ID3D11Device *device, unsigned int size, unsigned int stride, void *data, bool isDynamic)
  : buffer{nullptr}, stride{stride}
{
  auto bindFlags = isDynamic ? D3D11_USAGE_DYNAMIC : D3D11_USAGE_IMMUTABLE;
  auto accessFlags = isDynamic ? D3D11_CPU_ACCESS_WRITE : 0;
  CD3D11_BUFFER_DESC bufferDesc{size, D3D11_BIND_VERTEX_BUFFER, bindFlags, accessFlags};

  if(FAILED(device->CreateBuffer(&bufferDesc, nullptr, &buffer)))
    printf("FAILED TO CREATE VERTEX BUFFER size:%d stride:%d dynamic:%d\n", size, stride, isDynamic);
}