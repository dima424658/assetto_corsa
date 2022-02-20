#pragma once

#include <d3d11.h>

class KGLCubeMap
{
    KGLCubeMap(ID3D11Device *device, unsigned int size, unsigned int format, unsigned int mips);
    ~KGLCubeMap();

private:
    unsigned int size;
    unsigned int mips;
    ID3D11Texture2D *txDepth;
    ID3D11DepthStencilView *dsvDepthSingle;
    ID3D11Texture2D *txCube;
    ID3D11RenderTargetView *rtvCubeSingle[6];
    ID3D11ShaderResourceView *srvCube;
};