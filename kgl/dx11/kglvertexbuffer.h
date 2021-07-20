#pragma once

class KGLVertexBuffer
{
public:
    KGLVertexBuffer(int a2, int a3, ID3D11Device* device, unsigned int size, unsigned int stride, void* data, bool isDynamic);
};