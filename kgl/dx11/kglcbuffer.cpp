#include "kglcbuffer.h"

KGLCBuffer::KGLCBuffer(ID3D11Device* device, unsigned int isize)
  : size{ isize }, buffer{ nullptr }
{
  D3D11_BUFFER_DESC cbDesc{};
  cbDesc.ByteWidth = isize;
  cbDesc.Usage = D3D11_USAGE_DEFAULT;
  cbDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
  cbDesc.CPUAccessFlags = 0;
  cbDesc.MiscFlags = 0;
  cbDesc.StructureByteStride = 0;

  device->CreateBuffer(&cbDesc, nullptr, &buffer);
  if (!buffer)
    std::printf("ERROR: CBuffer CreateBuffer failed size=%d\n", size);
}
