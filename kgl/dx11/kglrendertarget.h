#pragma once

class KGLRenderTarget
{
public:
    KGLRenderTarget(ID3D11Device* device, DXGI_FORMAT fmt, unsigned int iwidth, unsigned int iheight, bool isDepth, int aSamples, int mips);
};