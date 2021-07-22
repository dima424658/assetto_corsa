#pragma once

class YebisPP
{
void YebisPP::YebisPP(GraphicsManager *graphics, int width, int height, ID3D11RenderTargetView *rtv);
void YebisPP::~YebisPP();
// void __userpurge YebisPP::applyPostProcessing(@<ecx>, _DWORD *a2@<ebx>, ID3D11ShaderResourceView *srcSRV, DXGI_FORMAT srcFormat, ID3D11ShaderResourceView *srcDepthSRV, ID3D11RenderTargetView *dstRTV, DXGI_FORMAT dstFormat);
// void __userpurge YebisPP::updatePPCameraValues(@<ecx>, int a2@<edi>, int a3@<esi>, float dt, Camera *camera, float a6, float a7, float a8, float a9, vec3f cameraPosition, vec3f cameraTarget, mat44f result, __m128i a13, __m128i a14, __m128i a15, __m128i a16);
void YebisPP::updatePP(bool updateExp);
bool YebisPP::loadPPSet(const std::wstring *name);
char YebisPP::readPPSet(std::wstring name);

};