#pragma once

#include <cstdint>


int kglInitFonts(IDWriteFactory *this);
int printSwapChainDesc();
int kglInit(KGLVideoSettings *vs);
void kglSetFontLocale(wchar_t *newloc);
unsigned int kglShutdown();

ID3D11Texture2D *kglGetRenderTargetTexture(void *renderTargetKID);
ID3D11Device *kglGetNativeDevice();
ID3D11DeviceContext *kglGetNativeContext();
ID3D11ShaderResourceView *kglGetRenderTargetShaderResourceView(void *renderTargetKID);
ID3D11RenderTargetView *kglGetRenderTargetView(void *renderTargetKID);

void kglSaveScreenCapture(const wchar_t *filename, unsigned int imageFormat, int a3);
int kglSetDefaultState();
void kglCreateCubeMap(unsigned int size, unsigned int format, unsigned int mips);
void *kglCreateTextureFromRT(void *rt);
void kglDestroyCubeMap(void *cm);
void kglCubeMapBeginFace(void *cm, unsigned int face);
ID3D11SamplerState *kglCreateSampler(unsigned int filter, unsigned int wrapmode, unsigned int anisotropic, float lodBias);
void kglDestroySampler(void *s);
void kglSetSamplerPS(void *s, unsigned int slot);
void kglSetRenderTarget(void *rt);
void kglRenderTargetClear(void *rt, float *color, float depth);
void kglSetRenderTargetNative(void *color, void *depth);
void kglSetRenderTargets(void *rt, void *depth);
void kglSetTextureRT(unsigned int slot, void *rt);
void kglSetViewport(float left, float top, float width, float height);
KGLRenderTarget *kglGetScreenRenderTarget();
KGLRenderTarget *kglGetScreenDepthTarget();
void kglClearColor(const float *color);
void kglClearDepth(float value);
void kglSetBlendState(unsigned int mode);
void kglSetDepthState(unsigned int mode);
void kglSetCullState(unsigned int mode);
int kglSwapBuffers();
int kglCreateTextureFromFile(const wchar_t *filename);
void kglCreateTextureFromBufferWithFormat(const void *buffer, unsigned int aFormat, unsigned int width, unsigned int height);
void kglCreateTextureFromBuffer(const void *buffer, unsigned int size);
void kglDestroyTexture(void *tx);

void kglSetTextureCubeMap(void *cm, unsigned int slot);
void kglCubeMapGenerateMips(void *cm, unsigned int face);
void kglSetPrimitiveType(unsigned int ptype);
void kglSetTexture(unsigned int slot, void *tx);
void kglResizeBuffers(unsigned int width, unsigned int height);
int kglSetFrameLatency(int lat);
void kglRenderTargetSaveToFile(void *rt, const wchar_t *filename);
void kglResolveRenderTarget(void *src, void *dst, unsigned int format);
unsigned int kglTextureGetWidth(void *tx);
unsigned int kglTextureGetHeight(void *tx);
void kglCreateRenderTarget(int width, int height, unsigned int format, int samples, int mips);
void kglCreateRenderTargetDepth(int width, int height, int samples, int mips);
void kglDestroyRenderTarget(void *rt);
void kglCreateCBuffer(unsigned int size);
void kglDestroyCBuffer(void *cb);
// unsigned int __usercall kglCreateFont@<eax>(int a1@<esi>, const wchar_t *faceName, unsigned int italic, unsigned int bold);
void kglBlitStringWide(void *f, float x, float y, const wchar_t *message, float scale, unsigned int align, unsigned int color);
void kglCBufferMap(void *cb, void *data);
void kglCBufferBind(void *cb, unsigned int slot);
int kglCreateShader(const wchar_t *filename);
void kglDestroyShader(void *sh);
void kglSetShader(void *sh);
int kglShaderGetVarsCount(void *sh);
int kglShaderGetParam(void *sh, unsigned int sp);
void kglShaderGetVarDescAtIndex(void *sh, unsigned int index, KGLShaderVarDesc *desc);
int kglShaderGetCBuffersCount(void *sh);
void kglShaderGetCBufferDescAtIndex(void *sh, unsigned int index, KGLShaderCBufferDesc *desc);
int kglShaderGetTexturesCount(void *sh);
void kglShaderGetTextureDescAtIndex(void *sh, unsigned int index, KGLShaderTextureDesc *desc);

void kglCreateVertexBuffer(int a1@<edi>, int a2@<esi>, unsigned int size, unsigned int stride, void *data);
void kglCreateDynamicVertexBuffer(int a1@<edi>, int a2@<esi>, unsigned int size, unsigned int stride, void *data);

void kglVertexBufferMapNoOverwrite(void *vb, void *data, unsigned int offset, unsigned int size);
void kglVertexBufferMap(void *vb, void *data, unsigned int size);
void kglDestroyVertexBuffer(void *vb);
void kglSetVertexBuffer(void *vb);
void kglCreateIndexBuffer(unsigned int size, unsigned __int16 *data);
void kglSetIndexBuffer(void *vb);
void kglDrawIndexed(unsigned int indicesCount, unsigned int baseIndex, unsigned int baseVertex);
void kglDraw(unsigned int verticesCount, unsigned int baseVertex);
int createDeviceAndSwapChain();
int initDX11();
int kglInitGPUQuerySupport();
char getDisplayModeDesc(char a1);
int createDepthBuffer();
HRESULT initBlendStates();
HRESULT initCullStates();
std::vector<std::wstring> *kglGetVideoModesList(std::vector<std::wstring> *result);
int kglQueryFrameBegin();
int kglQueryFrameEnd();
ID3D11Query *kglNewTimestampQuery();
void kglReleaseTimestampQuery(void *kid);
void kglTriggerTimestampQuery(void *kid);
HRESULT kglQueryFetchBegin();
double kglQueryFetchTimestamp(void *kid);
void kglSetVSync(int count);
KGLDeviceDesc *kglGetDeviceDesc(KGLDeviceDesc *result);

ID3D11InputLayout *__usercall getInputLayout@<eax>(ID3D11Device *device@<ecx>, void *blob@<edx>, unsigned int blobsize, const int iltype); idb