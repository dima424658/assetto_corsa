#pragma once

#include <d3d11.h>

class KGLVertexBuffer
{
    KGLVertexBuffer(ID3D11Device *device, unsigned int size, unsigned int stride, void *data, bool isDynamic);

private:
    ID3D11Buffer* buffer;
    unsigned int stride;
};