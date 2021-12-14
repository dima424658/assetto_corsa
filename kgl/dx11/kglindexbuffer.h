#pragma once

#include <cstdint>
#include <d3d11.h>

class KGLIndexBuffer
{
public:
    KGLIndexBuffer(ID3D11Device* device, unsigned int size, uint16_t* data);

protected:
    ID3D11Buffer* buffer;
};