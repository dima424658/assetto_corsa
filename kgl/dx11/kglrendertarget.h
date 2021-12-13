#pragma once

#include <d3d11.h>

class KGLRenderTarget // sizeof == 20U
{
public:
	KGLRenderTarget(ID3D11Device *device, DXGI_FORMAT fmt, unsigned int iwidth, unsigned int iheight, bool isDepth, int aSamples, int mips);

private:
	ID3D11Texture2D* rtTexture;
	ID3D11ShaderResourceView* shaderResourceView;
	ID3D11DepthStencilView* renderTargetViewDepth;
	int width;
	int height;
	int samples;
	ID3D11RenderTargetView* renderTargetView;
};
