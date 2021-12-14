#pragma once

#include <d3d11.h>

class KGLCBuffer
{
public:
    KGLCBuffer(ID3D11Device* device, unsigned int isize);

protected:
    unsigned int size;
    ID3D11Buffer* buffer;
};