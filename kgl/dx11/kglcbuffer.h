#pragma once

#include <d3d11.h>

class KGLCBuffer
{
public:
    KGLCBuffer(ID3D11Device* device, unsigned int isize);

    ID3D11Buffer* GetBuffer() const noexcept;
    unsigned int GetSize() const noexcept;

private:
    ID3D11Buffer* buffer;
    unsigned int size;
};

KGLCBuffer* kglCreateCBuffer(unsigned int size);

void kglCBufferMap(KGLCBuffer* cb, void* data);
void kglCBufferBind(KGLCBuffer* cb, unsigned int slot);