#include "cubemaprenderer.h"
void CubeMapRenderer::CubeMapRenderer(CubeMapRenderer *this, GraphicsManager *graphics)
{
  float v3; // xmm2_4
  float v4; // xmm5_4
  float v5; // xmm3_4
  float v6; // xmm1_4
  float v7; // xmm4_4
  float v8; // xmm7_4
  float v9; // xmm0_4
  float v10; // xmm6_4
  float v11; // xmm4_4
  float v12; // xmm7_4
  float v13; // xmm0_4
  float v14; // xmm0_4
  float v15; // xmm7_4
  float v16; // xmm4_4
  float v17; // xmm4_4
  float v18; // xmm0_4
  float v19; // xmm7_4
  float v20; // xmm4_4
  float v21; // xmm0_4
  std::wstring iname; // [esp+10h] [ebp-28h] BYREF
  int v23; // [esp+34h] [ebp-4h]

  this->__vftable = (CubeMapRenderer_vtbl *)&CubeMapRenderer::`vftable';
  this->evOnRenderBegin.handlers._Myfirst = 0;
  this->evOnRenderBegin.handlers._Mylast = 0;
  this->evOnRenderBegin.handlers._Myend = 0;
  v23 = 0;
  this->evOnRenderEnd.handlers._Myfirst = 0;
  this->evOnRenderEnd.handlers._Mylast = 0;
  this->evOnRenderEnd.handlers._Myend = 0;
  this->graphics = graphics;
  LOBYTE(v23) = 1;
  this->cameraMatrix[0].M11 = 0.0;
  this->cameraMatrix[0].M12 = 0.0;
  this->cameraMatrix[0].M13 = 0.0;
  this->cameraMatrix[0].M14 = 0.0;
  this->cameraMatrix[0].M21 = 0.0;
  this->cameraMatrix[0].M22 = 0.0;
  this->cameraMatrix[0].M23 = 0.0;
  this->cameraMatrix[0].M24 = 0.0;
  this->cameraMatrix[0].M31 = 0.0;
  this->cameraMatrix[0].M32 = 0.0;
  this->cameraMatrix[0].M33 = 0.0;
  this->cameraMatrix[0].M34 = 0.0;
  this->cameraMatrix[0].M41 = 0.0;
  this->cameraMatrix[0].M42 = 0.0;
  this->cameraMatrix[0].M43 = 0.0;
  this->cameraMatrix[0].M44 = 0.0;
  this->cameraMatrix[1].M11 = 0.0;
  this->cameraMatrix[1].M12 = 0.0;
  this->cameraMatrix[1].M13 = 0.0;
  this->cameraMatrix[1].M14 = 0.0;
  this->cameraMatrix[1].M21 = 0.0;
  this->cameraMatrix[1].M22 = 0.0;
  this->cameraMatrix[1].M23 = 0.0;
  this->cameraMatrix[1].M24 = 0.0;
  this->cameraMatrix[1].M31 = 0.0;
  this->cameraMatrix[1].M32 = 0.0;
  this->cameraMatrix[1].M33 = 0.0;
  this->cameraMatrix[1].M34 = 0.0;
  this->cameraMatrix[1].M41 = 0.0;
  this->cameraMatrix[1].M42 = 0.0;
  this->cameraMatrix[1].M43 = 0.0;
  this->cameraMatrix[1].M44 = 0.0;
  this->cameraMatrix[2].M11 = 0.0;
  this->cameraMatrix[2].M12 = 0.0;
  this->cameraMatrix[2].M13 = 0.0;
  this->cameraMatrix[2].M14 = 0.0;
  this->cameraMatrix[2].M21 = 0.0;
  this->cameraMatrix[2].M22 = 0.0;
  this->cameraMatrix[2].M23 = 0.0;
  this->cameraMatrix[2].M24 = 0.0;
  this->cameraMatrix[2].M31 = 0.0;
  this->cameraMatrix[2].M32 = 0.0;
  this->cameraMatrix[2].M33 = 0.0;
  this->cameraMatrix[2].M34 = 0.0;
  this->cameraMatrix[2].M41 = 0.0;
  this->cameraMatrix[2].M42 = 0.0;
  this->cameraMatrix[2].M43 = 0.0;
  this->cameraMatrix[2].M44 = 0.0;
  this->cameraMatrix[3].M11 = 0.0;
  this->cameraMatrix[3].M12 = 0.0;
  this->cameraMatrix[3].M13 = 0.0;
  this->cameraMatrix[3].M14 = 0.0;
  this->cameraMatrix[3].M21 = 0.0;
  this->cameraMatrix[3].M22 = 0.0;
  this->cameraMatrix[3].M23 = 0.0;
  this->cameraMatrix[3].M24 = 0.0;
  this->cameraMatrix[3].M31 = 0.0;
  this->cameraMatrix[3].M32 = 0.0;
  this->cameraMatrix[3].M33 = 0.0;
  this->cameraMatrix[3].M34 = 0.0;
  this->cameraMatrix[3].M41 = 0.0;
  this->cameraMatrix[3].M42 = 0.0;
  this->cameraMatrix[3].M43 = 0.0;
  this->cameraMatrix[3].M44 = 0.0;
  this->cameraMatrix[4].M11 = 0.0;
  this->cameraMatrix[4].M12 = 0.0;
  this->cameraMatrix[4].M13 = 0.0;
  this->cameraMatrix[4].M14 = 0.0;
  this->cameraMatrix[4].M21 = 0.0;
  this->cameraMatrix[4].M22 = 0.0;
  this->cameraMatrix[4].M23 = 0.0;
  this->cameraMatrix[4].M24 = 0.0;
  this->cameraMatrix[4].M31 = 0.0;
  this->cameraMatrix[4].M32 = 0.0;
  this->cameraMatrix[4].M33 = 0.0;
  this->cameraMatrix[4].M34 = 0.0;
  this->cameraMatrix[4].M41 = 0.0;
  this->cameraMatrix[4].M42 = 0.0;
  this->cameraMatrix[4].M43 = 0.0;
  this->cameraMatrix[4].M44 = 0.0;
  this->cameraMatrix[5].M11 = 0.0;
  this->cameraMatrix[5].M12 = 0.0;
  this->cameraMatrix[5].M13 = 0.0;
  this->cameraMatrix[5].M14 = 0.0;
  this->cameraMatrix[5].M21 = 0.0;
  this->cameraMatrix[5].M22 = 0.0;
  this->cameraMatrix[5].M23 = 0.0;
  this->cameraMatrix[5].M24 = 0.0;
  this->cameraMatrix[5].M31 = 0.0;
  this->cameraMatrix[5].M32 = 0.0;
  this->cameraMatrix[5].M33 = 0.0;
  this->cameraMatrix[5].M34 = 0.0;
  this->cameraMatrix[5].M41 = 0.0;
  this->cameraMatrix[5].M42 = 0.0;
  this->cameraMatrix[5].M43 = 0.0;
  this->cameraMatrix[5].M44 = 0.0;
  iname._Myres = 7;
  iname._Mysize = 0;
  iname._Bx._Buf[0] = 0;
  std::wstring::assign(&iname, L"CUBEMAP_RENDERER_CAMERA", 0x17u);
  LOBYTE(v23) = 2;
  Camera::Camera(&this->camera, &iname, graphics);
  if ( iname._Myres >= 8 )
    operator delete(iname._Bx._Ptr);
  this->camera.isCubeMapCamera = 1;
  this->camera.maxLayer = 0.0;
  this->cameraMatrix[0].M11 = 1.0;
  this->cameraMatrix[1].M11 = 1.0;
  this->cameraMatrix[0].M12 = 0.0;
  this->cameraMatrix[0].M13 = 0.0;
  this->cameraMatrix[0].M14 = 0.0;
  this->cameraMatrix[0].M21 = 0.0;
  this->cameraMatrix[0].M22 = 1.0;
  this->cameraMatrix[0].M23 = 0.0;
  this->cameraMatrix[0].M24 = 0.0;
  this->cameraMatrix[0].M31 = 0.0;
  this->cameraMatrix[0].M32 = 0.0;
  this->cameraMatrix[0].M33 = 1.0;
  this->cameraMatrix[0].M34 = 0.0;
  this->cameraMatrix[0].M41 = 0.0;
  this->cameraMatrix[0].M42 = 0.0;
  this->cameraMatrix[0].M43 = 0.0;
  this->cameraMatrix[0].M44 = 1.0;
  this->cameraMatrix[1].M12 = 0.0;
  this->cameraMatrix[1].M13 = 0.0;
  this->cameraMatrix[1].M14 = 0.0;
  this->cameraMatrix[1].M21 = 0.0;
  this->cameraMatrix[1].M22 = 1.0;
  this->cameraMatrix[1].M23 = 0.0;
  this->cameraMatrix[1].M24 = 0.0;
  this->cameraMatrix[1].M31 = 0.0;
  this->cameraMatrix[1].M32 = 0.0;
  this->cameraMatrix[1].M33 = 1.0;
  this->cameraMatrix[1].M34 = 0.0;
  this->cameraMatrix[1].M41 = 0.0;
  this->cameraMatrix[1].M42 = 0.0;
  this->cameraMatrix[1].M43 = 0.0;
  this->cameraMatrix[1].M44 = 1.0;
  this->cameraMatrix[2].M11 = 1.0;
  this->cameraMatrix[2].M12 = 0.0;
  this->cameraMatrix[2].M13 = 0.0;
  this->cameraMatrix[2].M14 = 0.0;
  this->cameraMatrix[2].M21 = 0.0;
  this->cameraMatrix[2].M22 = 1.0;
  this->cameraMatrix[2].M23 = 0.0;
  this->cameraMatrix[2].M24 = 0.0;
  this->cameraMatrix[2].M31 = 0.0;
  this->cameraMatrix[2].M32 = 0.0;
  this->cameraMatrix[2].M33 = 1.0;
  this->cameraMatrix[2].M34 = 0.0;
  this->cameraMatrix[2].M41 = 0.0;
  this->cameraMatrix[2].M42 = 0.0;
  this->cameraMatrix[2].M43 = 0.0;
  this->cameraMatrix[2].M44 = 1.0;
  this->cameraMatrix[3].M11 = 1.0;
  this->cameraMatrix[3].M12 = 0.0;
  this->cameraMatrix[3].M13 = 0.0;
  this->cameraMatrix[3].M14 = 0.0;
  this->cameraMatrix[3].M21 = 0.0;
  this->cameraMatrix[3].M22 = 1.0;
  this->cameraMatrix[3].M23 = 0.0;
  this->cameraMatrix[3].M24 = 0.0;
  this->cameraMatrix[3].M31 = 0.0;
  this->cameraMatrix[3].M32 = 0.0;
  this->cameraMatrix[3].M33 = 1.0;
  this->cameraMatrix[3].M34 = 0.0;
  this->cameraMatrix[3].M41 = 0.0;
  v3 = FLOAT_1_0;
  this->cameraMatrix[3].M42 = 0.0;
  this->cameraMatrix[3].M43 = 0.0;
  this->cameraMatrix[3].M44 = 1.0;
  this->cameraMatrix[4].M11 = 1.0;
  this->cameraMatrix[4].M12 = 0.0;
  this->cameraMatrix[4].M13 = 0.0;
  this->cameraMatrix[4].M14 = 0.0;
  this->cameraMatrix[4].M21 = 0.0;
  this->cameraMatrix[4].M22 = 1.0;
  this->cameraMatrix[4].M23 = 0.0;
  this->cameraMatrix[4].M24 = 0.0;
  this->cameraMatrix[4].M31 = 0.0;
  this->cameraMatrix[4].M32 = 0.0;
  this->cameraMatrix[4].M33 = 1.0;
  this->cameraMatrix[4].M34 = 0.0;
  this->cameraMatrix[4].M41 = 0.0;
  this->cameraMatrix[4].M42 = 0.0;
  v4 = FLOAT_N1_0;
  v5 = fsqrt(1.0);
  v6 = 0.0;
  this->cameraMatrix[4].M43 = 0.0;
  this->cameraMatrix[4].M44 = 1.0;
  this->cameraMatrix[5].M11 = 1.0;
  this->cameraMatrix[5].M12 = 0.0;
  this->cameraMatrix[5].M13 = 0.0;
  this->cameraMatrix[5].M14 = 0.0;
  this->cameraMatrix[5].M21 = 0.0;
  this->cameraMatrix[5].M22 = 1.0;
  this->cameraMatrix[5].M23 = 0.0;
  this->cameraMatrix[5].M24 = 0.0;
  this->cameraMatrix[5].M31 = 0.0;
  this->cameraMatrix[5].M32 = 0.0;
  this->cameraMatrix[5].M33 = 1.0;
  this->cameraMatrix[5].M34 = 0.0;
  this->cameraMatrix[5].M41 = 0.0;
  this->cameraMatrix[5].M42 = 0.0;
  this->cameraMatrix[5].M43 = 0.0;
  this->cameraMatrix[5].M44 = 1.0;
  v7 = 0.0;
  v8 = 0.0;
  v9 = FLOAT_N1_0;
  if ( v5 != 0.0 )
  {
    v9 = (float)(1.0 / v5) * -1.0;
    v7 = (float)(1.0 / v5) * 0.0;
    v8 = v7;
  }
  v10 = FLOAT_N0_0;
  this->cameraMatrix[0].M31 = 1.0;
  this->cameraMatrix[0].M32 = -0.0;
  this->cameraMatrix[0].M33 = -0.0;
  this->cameraMatrix[0].M21 = 0.0;
  this->cameraMatrix[0].M22 = 1.0;
  this->cameraMatrix[0].M23 = 0.0;
  this->cameraMatrix[0].M11 = v7;
  v11 = FLOAT_1_0;
  this->cameraMatrix[0].M12 = v8;
  v12 = 0.0;
  this->cameraMatrix[0].M13 = v9;
  v13 = 0.0;
  if ( v5 != 0.0 )
  {
    v11 = 1.0 / v5;
    v13 = (float)(1.0 / v5) * 0.0;
    v12 = v13;
  }
  this->cameraMatrix[1].M31 = -1.0;
  this->cameraMatrix[1].M32 = -0.0;
  this->cameraMatrix[1].M33 = -0.0;
  this->cameraMatrix[1].M21 = 0.0;
  this->cameraMatrix[1].M22 = 1.0;
  this->cameraMatrix[1].M23 = 0.0;
  this->cameraMatrix[1].M11 = v13;
  v14 = 0.0;
  this->cameraMatrix[1].M12 = v12;
  v15 = 0.0;
  this->cameraMatrix[1].M13 = v11;
  v16 = FLOAT_N1_0;
  if ( v5 != 0.0 )
  {
    v14 = (float)(1.0 / v5) * 0.0;
    v16 = (float)(1.0 / v5) * -1.0;
    v15 = v14;
  }
  this->cameraMatrix[2].M31 = -0.0;
  this->cameraMatrix[2].M32 = -1.0;
  this->cameraMatrix[2].M33 = -0.0;
  this->cameraMatrix[2].M21 = 0.0;
  this->cameraMatrix[2].M22 = 0.0;
  this->cameraMatrix[2].M23 = -1.0;
  this->cameraMatrix[2].M11 = v16;
  v17 = FLOAT_N1_0;
  this->cameraMatrix[2].M12 = v14;
  v18 = 0.0;
  this->cameraMatrix[2].M13 = v15;
  v19 = 0.0;
  if ( v5 != 0.0 )
  {
    v18 = (float)(1.0 / v5) * 0.0;
    v17 = (float)(1.0 / v5) * -1.0;
    v19 = v18;
  }
  this->cameraMatrix[3].M31 = -0.0;
  this->cameraMatrix[3].M32 = 1.0;
  this->cameraMatrix[3].M33 = -0.0;
  this->cameraMatrix[3].M21 = 0.0;
  this->cameraMatrix[3].M22 = 0.0;
  this->cameraMatrix[3].M23 = 1.0;
  this->cameraMatrix[3].M11 = v17;
  v20 = 0.0;
  this->cameraMatrix[3].M12 = v18;
  v21 = 0.0;
  this->cameraMatrix[3].M13 = v19;
  if ( v5 != 0.0 )
  {
    v20 = (float)(1.0 / v5) * 0.0;
    v4 = -1.0 * (float)(1.0 / v5);
    v21 = v20;
  }
  this->cameraMatrix[4].M31 = -0.0;
  this->cameraMatrix[4].M32 = -0.0;
  this->cameraMatrix[4].M33 = -1.0;
  this->cameraMatrix[4].M21 = 0.0;
  this->cameraMatrix[4].M22 = 1.0;
  this->cameraMatrix[4].M23 = 0.0;
  this->cameraMatrix[4].M11 = v4;
  this->cameraMatrix[4].M12 = v20;
  this->cameraMatrix[4].M13 = v21;
  if ( v5 != 0.0 )
  {
    v3 = 1.0 / v5;
    v10 = -0.0 * (float)(1.0 / v5);
    v6 = v10;
  }
  this->cameraMatrix[5].M31 = -0.0;
  this->cameraMatrix[5].M32 = -0.0;
  this->cameraMatrix[5].M33 = 1.0;
  this->cameraMatrix[5].M21 = 0.0;
  this->cameraMatrix[5].M22 = 1.0;
  this->cameraMatrix[5].M23 = 0.0;
  this->cameraMatrix[5].M11 = v3;
  this->cameraMatrix[5].M12 = v10;
  this->cameraMatrix[5].M13 = v6;
  this->camera.fov = 90.0;
  this->camera.nearPlane = 0.0099999998;
  this->camera.farPlane = 350.0;
  this->camera.aspectRatio = 1.0;
  this->facesPerFrame = 6;
  this->currentFace = 0;
}
void CubeMapRenderer::~CubeMapRenderer(CubeMapRenderer *this)
{
  this->__vftable = (CubeMapRenderer_vtbl *)&CubeMapRenderer::`vftable';
  Camera::~Camera(&this->camera);
  if ( this->evOnRenderEnd.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnRenderEnd);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnRenderEnd,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnRenderEnd.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnRenderEnd.handlers._Mylast);
    operator delete(this->evOnRenderEnd.handlers._Myfirst);
    this->evOnRenderEnd.handlers._Myfirst = 0;
    this->evOnRenderEnd.handlers._Mylast = 0;
    this->evOnRenderEnd.handlers._Myend = 0;
  }
  if ( this->evOnRenderBegin.handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evOnRenderBegin);
    std::vector<std::pair<void *,std::function<void __cdecl (OnReplayStatusChanged const &)>>>::_Destroy(
      (std::vector<std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> >> *)&this->evOnRenderBegin,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnRenderBegin.handlers._Myfirst,
      (std::pair<void *,std::function<void __cdecl(OnPhysicsStepCompleted const &)> > *)this->evOnRenderBegin.handlers._Mylast);
    operator delete(this->evOnRenderBegin.handlers._Myfirst);
    this->evOnRenderBegin.handlers._Myfirst = 0;
    this->evOnRenderBegin.handlers._Mylast = 0;
    this->evOnRenderBegin.handlers._Myend = 0;
  }
}
CubeMapRenderer *CubeMapRenderer::`scalar deleting destructor'(CubeMapRenderer *this, unsigned int a2)
{
  CubeMapRenderer::~CubeMapRenderer(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CubeMapRenderer::render(CubeMapRenderer *this, CubeMap *cubeMap, Node *root, Camera *sceneCamera)
{
  int v5; // esi
  int v6; // eax
  SkyBox *v7; // eax
  float v8; // xmm1_4
  float v9; // xmm2_4
  GraphicsManager *v10; // ecx
  GraphicsManager *v11; // ecx
  std::pair<void *,std::function<void __cdecl(int const &)> > *v12; // esi
  std::_Func_base<void,int const &> **v13; // ebx
  Node *v14; // [esp-4h] [ebp-4Ch]
  Node *v15; // [esp+18h] [ebp-30h] BYREF
  OnGearRequestEvent message; // [esp+1Ch] [ebp-2Ch] BYREF
  int v17; // [esp+30h] [ebp-18h]
  unsigned int v18; // [esp+34h] [ebp-14h]
  int v19; // [esp+44h] [ebp-4h]

  v15 = root;
  if ( (dword_186EEB0 & 1) == 0 )
  {
    perfCounter_6.name = "CubeMapRenderer::render";
    dword_186EEB0 |= 1u;
    perfCounter_6.group = Render;
    perfCounter_6.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"CubeMapRenderer::render" | 0xFF000000;
  }
  if ( this->facesPerFrame > 0 )
  {
    message.request = eNoGearRequest;
    Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&this->evOnRenderBegin, &message);
  }
  this->graphics->state.overrideNoMS = 1;
  kglSetSamplerPS(this->graphics->samplerStates.samplerLinearSimple, 0);
  GraphicsManager::clearTextureSlot(this->graphics, 10);
  v5 = 0;
  for ( this->graphics->currentCubeMap = 0; v5 < this->facesPerFrame; ++v5 )
  {
    if ( (dword_186EEB0 & 2) == 0 )
    {
      perfCounter_7.name = "CubeMapRenderer::render (pass)";
      dword_186EEB0 |= 2u;
      perfCounter_7.group = Render;
      perfCounter_7.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"CubeMapRenderer::render (pass)" | 0xFF000000;
    }
    CubeMap::beginFace(cubeMap, this->currentFace);
    v6 = this->currentFace << 6;
    v14 = v15;
    *(__m128i *)&this->camera.matrix.M11 = _mm_loadu_si128((const __m128i *)((char *)this->cameraMatrix + v6));
    *(__m128i *)&this->camera.matrix.M21 = _mm_loadu_si128((const __m128i *)((char *)&this->cameraMatrix[0].M21 + v6));
    *(__m128i *)&this->camera.matrix.M31 = _mm_loadu_si128((const __m128i *)((char *)&this->cameraMatrix[0].M31 + v6));
    *(__m128i *)&this->camera.matrix.M41 = _mm_loadu_si128((const __m128i *)((char *)&this->cameraMatrix[0].M41 + v6));
    v7 = sceneCamera->skyBox;
    v8 = sceneCamera->matrix.M42;
    v9 = sceneCamera->matrix.M43;
    this->camera.matrix.M41 = sceneCamera->matrix.M41;
    this->camera.matrix.M42 = v8;
    this->camera.matrix.M43 = v9;
    this->camera.skyBox = v7;
    ((void (*)(Camera *, Node *, _DWORD))this->camera.render)(&this->camera, v14, 0);
    CubeMap::endFace(cubeMap);
    if ( ++this->currentFace >= 6 )
      this->currentFace = 0;
  }
  v18 = 7;
  v17 = 0;
  LOWORD(message.nextGear) = 0;
  std::wstring::assign((std::wstring *)&message.nextGear, L"CUBEMAP", 7u);
  v10 = this->graphics;
  v19 = 0;
  GPUProfiler::triggerQuery(v10->gpuProfiler, (const std::wstring *)&message.nextGear);
  v19 = -1;
  if ( v18 >= 8 )
    operator delete(message.nextGear);
  kglSetRenderTargets(0, 0);
  CubeMap::generateMips(cubeMap, -1);
  CubeMap::apply(cubeMap, 10);
  this->graphics->currentCubeMap = cubeMap;
  kglSetSamplerPS(this->graphics->samplerStates.samplerAniso, 0);
  v18 = 7;
  v17 = 0;
  LOWORD(message.nextGear) = 0;
  std::wstring::assign((std::wstring *)&message.nextGear, L"CUBEMAP", 7u);
  v11 = this->graphics;
  v19 = 1;
  GPUProfiler::triggerQuery(v11->gpuProfiler, (const std::wstring *)&message.nextGear);
  v19 = -1;
  if ( v18 >= 8 )
    operator delete(message.nextGear);
  this->graphics->state.overrideNoMS = 0;
  if ( this->facesPerFrame > 0 )
  {
    v12 = this->evOnRenderEnd.handlers._Myfirst;
    v15 = 0;
    if ( v12 != this->evOnRenderEnd.handlers._Mylast )
    {
      v13 = &v12->second._Impl;
      do
      {
        if ( !*v13 )
        {
          std::_Xbad_function_call();
          JUMPOUT(0x703B32);
        }
        (*v13)->_Do_call(*v13, (const int *)&v15);
        ++v12;
        v13 += 8;
      }
      while ( v12 != this->evOnRenderEnd.handlers._Mylast );
    }
  }
}
void CubeMapRenderer::setCameraNearFarPlanes(CubeMapRenderer *this, float nearp, float farp)
{
  this->camera.nearPlane = nearp;
  this->camera.farPlane = farp;
}
