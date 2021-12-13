#pragma once

#include <cstdint>
#include <d3d11.h>

class KGLIndexBuffer
{
void KGLIndexBuffer(ID3D11Device *device, unsigned int size, uint16_t *data);

};