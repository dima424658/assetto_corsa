#include "kglcbuffer.h"

KGLCBuffer::KGLCBuffer(ID3D11Device* device, unsigned int isize)
    : size(isize), buffer(nullptr)
{
    D3D11_BUFFER_DESC cbDesc;
    cbDesc.MiscFlags = 0;
    cbDesc.ByteWidth = isize;
    cbDesc.Usage = D3D11_USAGE_DEFAULT;
    cbDesc.CPUAccessFlags = 0;
    cbDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;

    device->CreateBuffer(&cbDesc, nullptr, &buffer);

    if (!buffer)
        printf("ERROR: CBuffer CreateBuffer failed size=%d\n", size);
}

KGLCBuffer* kglCreateCBuffer(unsigned int size)
{
    ID3D11Device* device;

    return new KGLCBuffer(device, size);
}

void kglCBufferMap(KGLCBuffer* cb, void* data)
{
    ID3D11DeviceContext* immediateContext;

    immediateContext->UpdateSubresource(cb->GetBuffer(), 0, nullptr, data, 0, 0);
}

void kglCBufferBind(KGLCBuffer* cb, unsigned int slot)
{
    ID3D11DeviceContext* immediateContext;

    auto buffer = cb->GetBuffer();
    immediateContext->VSSetConstantBuffers(slot, 1u, &buffer);
    immediateContext->PSSetConstantBuffers(slot, 1u, &buffer);
}