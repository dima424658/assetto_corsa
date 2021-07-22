#include "cameraforward.h
void CameraForward::CameraForward(CameraForward *this, const std::wstring *iname, GraphicsManager *graphics, bool auseBlur)
{
  bool v5; // zf
  signed int v6; // ebx
  RenderTarget *v7; // eax
  RenderTarget *v8; // eax
  Shader *v9; // eax
  bool v10; // cf
  Shader *v11; // eax
  Shader *v12; // eax
  Shader *v13; // ecx
  ShaderVariable *v14; // eax
  Shader *v15; // ecx
  ShaderVariable *v16; // eax
  Shader *v17; // ecx
  ShaderVariable *v18; // eax
  Shader *v19; // ecx
  ShaderVariable *v20; // eax
  Shader *v21; // ecx
  ShaderVariable *v22; // eax
  Shader *v23; // ecx
  ShaderVariable *v24; // eax
  Shader *v25; // ecx
  ShaderVariable *v26; // eax
  std::function<void __cdecl(OnPhysicsStepCompleted const &)> v27; // [esp-1Ch] [ebp-60h] BYREF
  GraphicsManager *v28; // [esp-4h] [ebp-48h]
  RenderTarget *v29; // [esp+14h] [ebp-30h]
  CameraForward *v30; // [esp+18h] [ebp-2Ch]
  std::wstring name; // [esp+1Ch] [ebp-28h] BYREF
  int v32; // [esp+40h] [ebp-4h]

  v30 = this;
  CameraShadowMapped::CameraShadowMapped(this, iname, graphics);
  v28 = graphics;
  v32 = 0;
  this->__vftable = (CameraForward_vtbl *)&CameraForward::`vftable';
  this->blurQuality = 8.0;
  this->blurRadialSpeed = 0.0;
  *(_WORD *)&this->useRadialBlur = 256;
  this->lensFlare = 1;
  CubeMapRenderer::CubeMapRenderer(&this->cubeMapRenderer, v28);
  this->cubeMap = 0;
  this->tripleScreenAvailable = 0;
  this->postProcessChain = 0;
  this->rtBlur = 0;
  this->postRenderTargetIndex = 0;
  this->postProcesses._Myfirst = 0;
  this->postProcesses._Mylast = 0;
  this->postProcesses._Myend = 0;
  LOBYTE(v32) = 2;
  this->hdr = 0;
  this->useBlur = auseBlur;
  this->blurShader = 0;
  this->blurShaderRadial = 0;
  this->svRadialSpeed = 0;
  this->svProjInv = 0;
  this->svProj = 0;
  this->svCameraVelocity = 0;
  this->svCameraAngularVelocity = 0;
  this->svQuality = 0;
  this->svFpsCorrection = 0;
  mat44f::mat44f(&this->lastWorldMatrix);
  this->ppFXAA = 0;
  this->currentBlurAngle = 0.0;
  this->postTempTargets[0] = 0;
  this->postTempTargets[1] = 0;
  if ( this->useBlur && graphics->videoSettings.ppHDREnabled )
  {
    v5 = graphics->videoSettings.aaSamples == 1;
    v6 = 2;
    v28 = (GraphicsManager *)28;
    if ( !v5 )
      v6 = 7;
    v7 = (RenderTarget *)operator new(v28);
    v29 = v7;
    LOBYTE(v32) = 3;
    if ( v7 )
      RenderTarget::RenderTarget(
        v7,
        graphics,
        (eRenderTargetFormat)v6,
        graphics->videoSettings.width,
        graphics->videoSettings.height,
        1,
        1,
        1);
    else
      v8 = 0;
    this->rtBlur = v8;
    v5 = graphics->videoSettings.aaSamples == 1;
    LOBYTE(v32) = 2;
    if ( v5 )
    {
      std::wstring::wstring(&name, L"ksPostBlur");
      LOBYTE(v32) = 6;
      v11 = GraphicsManager::getShader(graphics, v6, &name);
      v10 = name._Myres < 8;
      this->blurShader = v11;
      LOBYTE(v32) = 2;
      if ( !v10 )
        operator delete(name._Bx._Ptr);
      std::wstring::wstring(&name, L"ksPostBlurRadial");
      LOBYTE(v32) = 7;
    }
    else
    {
      std::wstring::wstring(&name, L"ksPostBlur_MS");
      LOBYTE(v32) = 4;
      v9 = GraphicsManager::getShader(graphics, v6, &name);
      v10 = name._Myres < 8;
      this->blurShader = v9;
      LOBYTE(v32) = 2;
      if ( !v10 )
        operator delete(name._Bx._Ptr);
      std::wstring::wstring(&name, L"ksPostBlurRadialMS");
      LOBYTE(v32) = 5;
    }
    v12 = GraphicsManager::getShader(graphics, v6, &name);
    v10 = name._Myres < 8;
    LOBYTE(v32) = 2;
    this->blurShaderRadial = v12;
    if ( !v10 )
      operator delete(name._Bx._Ptr);
    std::wstring::wstring(&name, L"matProjectionInv");
    v13 = this->blurShader;
    LOBYTE(v32) = 8;
    v14 = Shader::getVar(v13, &name);
    v10 = name._Myres < 8;
    this->svProjInv = v14;
    LOBYTE(v32) = 2;
    if ( !v10 )
      operator delete(name._Bx._Ptr);
    std::wstring::wstring(&name, L"matProjection");
    v15 = this->blurShader;
    LOBYTE(v32) = 9;
    v16 = Shader::getVar(v15, &name);
    v10 = name._Myres < 8;
    this->svProj = v16;
    LOBYTE(v32) = 2;
    if ( !v10 )
      operator delete(name._Bx._Ptr);
    std::wstring::wstring(&name, L"cameraVelocity");
    v17 = this->blurShader;
    LOBYTE(v32) = 10;
    v18 = Shader::getVar(v17, &name);
    v10 = name._Myres < 8;
    this->svCameraVelocity = v18;
    LOBYTE(v32) = 2;
    if ( !v10 )
      operator delete(name._Bx._Ptr);
    std::wstring::wstring(&name, L"matAngularVelocity");
    v19 = this->blurShader;
    LOBYTE(v32) = 11;
    v20 = Shader::getVar(v19, &name);
    v10 = name._Myres < 8;
    this->svCameraAngularVelocity = v20;
    LOBYTE(v32) = 2;
    if ( !v10 )
      operator delete(name._Bx._Ptr);
    std::wstring::wstring(&name, L"fpsCorrection");
    v21 = this->blurShader;
    LOBYTE(v32) = 12;
    v22 = Shader::getVar(v21, &name);
    v10 = name._Myres < 8;
    this->svFpsCorrection = v22;
    LOBYTE(v32) = 2;
    if ( !v10 )
      operator delete(name._Bx._Ptr);
    std::wstring::wstring(&name, L"quality");
    v23 = this->blurShader;
    LOBYTE(v32) = 13;
    v24 = Shader::getVar(v23, &name);
    v10 = name._Myres < 8;
    this->svQuality = v24;
    LOBYTE(v32) = 2;
    if ( !v10 )
      operator delete(name._Bx._Ptr);
    std::wstring::wstring(&name, L"speed");
    v25 = this->blurShaderRadial;
    LOBYTE(v32) = 14;
    v26 = Shader::getVar(v25, &name);
    v10 = name._Myres < 8;
    this->svRadialSpeed = v26;
    LOBYTE(v32) = 2;
    if ( !v10 )
      operator delete(name._Bx._Ptr);
  }
  CameraForward::setCubemapSize(this, 0x200u);
  v27._Space._Pfn[0] = (void (__cdecl *)())&std::_Func_impl<std::_Callable_obj<_lambda_22f845e23d0702e2524ec6ebab0229fb_,0>,std::allocator<std::_Func_class<void,OnWindowResize const &>>,void,OnWindowResize const &>::`vftable';
  v27._Space._Pfn[1] = (void (__cdecl *)())this;
  v27._Impl = (std::_Func_base<void,OnPhysicsStepCompleted const &> *)&v27;
  LOBYTE(v32) = 2;
  Event<std::wstring>::addHandler((Event<OnPhysicsStepCompleted> *)&graphics->evWindowResize, v27, this);
}
void CameraForward::~CameraForward(CameraForward *this)
{
  RenderTarget *v2; // ecx
  RenderTarget *v3; // ecx
  PostProcess **v4; // esi
  int v5; // ebx
  unsigned int v6; // ebp
  RenderTarget *v7; // ecx
  HDR *v8; // ecx
  CubeMap *v9; // ecx
  std::vector<PostProcess *> *v10; // ebx

  this->__vftable = (CameraForward_vtbl *)&CameraForward::`vftable';
  Event<OnStepCompleteEvent>::removeHandler((Event<vec3f> *)&this->graphics->evWindowResize, this);
  v2 = this->postTempTargets[0];
  if ( v2 )
    ((void (*)(RenderTarget *, int))v2->~RenderTarget)(v2, 1);
  v3 = this->postTempTargets[1];
  if ( v3 )
    ((void (*)(RenderTarget *, int))v3->~RenderTarget)(v3, 1);
  v4 = this->postProcesses._Myfirst;
  v5 = 0;
  v6 = (unsigned int)((char *)this->postProcesses._Mylast - (char *)v4 + 3) >> 2;
  if ( v4 > this->postProcesses._Mylast )
    v6 = 0;
  if ( v6 )
  {
    do
    {
      if ( *v4 )
        ((void (*)(PostProcess *, int))(*v4)->~PostProcess)(*v4, 1);
      ++v5;
      ++v4;
    }
    while ( v5 != v6 );
  }
  v7 = this->rtBlur;
  if ( v7 )
    ((void (*)(RenderTarget *, int))v7->~RenderTarget)(v7, 1);
  v8 = this->hdr;
  if ( v8 )
    ((void (*)(HDR *, int))v8->~HDR)(v8, 1);
  v9 = this->cubeMap;
  if ( v9 )
    ((void (*)(CubeMap *, int))v9->~CubeMap)(v9, 1);
  v10 = &this->postProcesses;
  if ( this->postProcesses._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->postProcesses);
    operator delete(v10->_Myfirst);
    v10->_Myfirst = 0;
    this->postProcesses._Mylast = 0;
    this->postProcesses._Myend = 0;
  }
  CubeMapRenderer::~CubeMapRenderer(&this->cubeMapRenderer);
  CameraShadowMapped::~CameraShadowMapped(this);
}
CameraForward *CameraForward::`vector deleting destructor'(CameraForward *this, unsigned int a2)
{
  CameraForward::~CameraForward(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void __userpurge CameraForward::onResize(CameraForward *this@<ecx>, unsigned int a2@<ebx>, const OnWindowResize *message)
{
  RenderTarget *v4; // ecx
  RenderTarget *v5; // ecx
  HDR *v6; // ecx
  HDR *v7; // eax
  HDR *v8; // eax
  RenderTarget *v9; // ecx
  eRenderTargetFormat v10; // edi
  RenderTarget *v11; // eax
  RenderTarget *v12; // eax

  if ( !this->graphics->videoSettings.ppHDREnabled )
  {
    v4 = this->postTempTargets[0];
    if ( v4 )
      ((void (*)(RenderTarget *, int))v4->~RenderTarget)(v4, 1);
    v5 = this->postTempTargets[1];
    if ( v5 )
      ((void (*)(RenderTarget *, int))v5->~RenderTarget)(v5, 1);
    CameraForward::preparePostRenderTargets(this);
  }
  v6 = this->hdr;
  if ( v6 )
  {
    ((void (*)(HDR *, int))v6->~HDR)(v6, 1);
    v7 = (HDR *)operator new(116);
    if ( v7 )
      HDR::HDR(v7, a2, this->graphics);
    else
      v8 = 0;
    this->hdr = v8;
  }
  v9 = this->rtBlur;
  if ( v9 )
  {
    ((void (*)(RenderTarget *, int))v9->~RenderTarget)(v9, 1);
    v10 = eR16G16B16A16;
    if ( this->graphics->videoSettings.aaSamples != 1 )
      v10 = eR16G16B16A16_MS;
    v11 = (RenderTarget *)operator new(28);
    if ( v11 )
      RenderTarget::RenderTarget(
        v11,
        this->graphics,
        v10,
        this->graphics->videoSettings.width,
        this->graphics->videoSettings.height,
        1,
        1,
        1);
    else
      v12 = 0;
    this->rtBlur = v12;
  }
}
void CameraForward::preparePostRenderTargets(CameraForward *this)
{
  RenderTarget *v2; // eax
  RenderTarget *v3; // eax
  RenderTarget *v4; // eax
  RenderTarget *v5; // eax

  v2 = (RenderTarget *)operator new(28);
  if ( v2 )
    RenderTarget::RenderTarget(
      v2,
      this->graphics,
      eR8G8B8A8,
      this->graphics->videoSettings.width,
      this->graphics->videoSettings.height,
      1,
      0,
      1);
  else
    v3 = 0;
  this->postTempTargets[0] = v3;
  v4 = (RenderTarget *)operator new(28);
  if ( v4 )
  {
    RenderTarget::RenderTarget(
      v4,
      this->graphics,
      eR8G8B8A8,
      this->graphics->videoSettings.width,
      this->graphics->videoSettings.height,
      1,
      0,
      1);
    this->postTempTargets[1] = v5;
  }
  else
  {
    this->postTempTargets[1] = 0;
  }
}
void CameraForward::render(CameraForward *this, Node *blurred, Node *unblurred, Node *shadow, float dt)
{
  HDR *v6; // eax
  CameraForward_vtbl *v7; // eax
  GraphicsManager *v8; // ecx
  HDR *v9; // ecx
  std::wstring name; // [esp+20h] [ebp-28h] BYREF
  int v11; // [esp+44h] [ebp-4h]

  GraphicsManager::clearTextureSlot(this->graphics, 5);
  v6 = this->hdr;
  if ( v6 )
    this->renderTarget = v6->hdrRenderTarget;
  v7 = this->__vftable;
  this->postRenderTargetIndex = 0;
  ((void (*)(CameraForward *, Node *, _DWORD))v7->shadowMapPass)(this, shadow, LODWORD(dt));
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"SHADOW_MAP", 0xAu);
  v8 = this->graphics;
  v11 = 0;
  GPUProfiler::triggerQuery(v8->gpuProfiler, &name);
  v11 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  if ( blurred )
    CubeMapRenderer::render(&this->cubeMapRenderer, this->cubeMap, blurred, this);
  v9 = this->hdr;
  if ( v9 )
    HDR::begin(v9);
  else
    GraphicsManager::setScreenRenderTargets(this->graphics);
  GraphicsManager::beginMainRenderPass(this->graphics);
  if ( this->useBlur )
    CameraForward::renderBlurred(this, blurred, unblurred, shadow, dt);
  else
    ((void (*)(CameraForward *, Node *, _DWORD))this->renderPass)(this, shadow, LODWORD(dt));
  GraphicsManager::endMainRenderPass(this->graphics);
  GraphicsManager::clearTextureSlot(this->graphics, 5);
  GraphicsManager::clearTextureSlot(this->graphics, 3);
}
void CameraForward::renderBlurred(CameraForward *this, Node *blurred, Node *unblurred, Node *transparent, float dt)
{
  GraphicsManager *v6; // ecx
  GraphicsManager *v7; // ecx
  GraphicsManager *v8; // ecx
  GraphicsManager *v9; // ecx
  GraphicsManager *v10; // ecx
  GraphicsManager *v11; // ecx
  RenderTarget *v12; // [esp+4h] [ebp-C8h]
  MaterialFilter materialFilter; // [esp+1Ch] [ebp-B0h] BYREF
  RenderContext rc; // [esp+24h] [ebp-A8h] BYREF
  RenderContext rcTR; // [esp+34h] [ebp-98h] BYREF
  CameraMeshFilter filterTR; // [esp+44h] [ebp-88h] BYREF
  CameraMeshFilter filter; // [esp+54h] [ebp-78h] BYREF
  mat44f id; // [esp+64h] [ebp-68h] BYREF
  std::wstring name; // [esp+A4h] [ebp-28h] BYREF
  int v20; // [esp+C8h] [ebp-4h]

  if ( (dword_186EED0 & 1) == 0 )
  {
    perfCounter_8.name = "CameraForward::renderBlurred";
    dword_186EED0 |= 1u;
    perfCounter_8.group = Render;
    perfCounter_8.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"CameraForward::renderBlurred" | 0xFF000000;
  }
  GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
  CameraMeshFilter::CameraMeshFilter(&filter, this, Opaque, (int)this->maxLayer);
  v20 = 0;
  MaterialFilter::MaterialFilter(&materialFilter);
  v6 = this->graphics;
  v12 = this->rtBlur;
  rc.materialFilter = &materialFilter;
  LOBYTE(v20) = 1;
  rc.meshFilter = &filter;
  rc.graphics = v6;
  rc.camera = this;
  GraphicsManager::setRenderTarget(v6, v12);
  GraphicsManager::setCullMode(this->graphics, eCullFront);
  Camera::renderCamera(this);
  Camera::clearBuffers(this);
  if ( this->skyBox )
  {
    mat44f::mat44f(&id);
    mat44f::loadIdentity(&id);
    GraphicsManager::setDepthMode(this->graphics, eDepthOff);
    GraphicsManager::setWorldMatrix(this->graphics, &id);
    SkyBox::render(this->skyBox, &rc);
    GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
  }
  blurred->render(blurred, &rc);
  Camera::renderCamera(this);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"BLUR_PASS", 9u);
  v7 = this->graphics;
  LOBYTE(v20) = 2;
  GPUProfiler::triggerQuery(v7->gpuProfiler, &name);
  LOBYTE(v20) = 1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  CameraForward::solveBlur(this, dt);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"BLUR_SOLVE", 0xAu);
  v8 = this->graphics;
  LOBYTE(v20) = 3;
  GPUProfiler::triggerQuery(v8->gpuProfiler, &name);
  LOBYTE(v20) = 1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  unblurred->render(unblurred, &rc);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"UNBLUR_PASS", 0xBu);
  v9 = this->graphics;
  LOBYTE(v20) = 4;
  GPUProfiler::triggerQuery(v9->gpuProfiler, &name);
  LOBYTE(v20) = 1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  CameraMeshFilter::CameraMeshFilter(&filterTR, this, Transparent, (int)this->maxLayer);
  v10 = this->graphics;
  rcTR.materialFilter = &materialFilter;
  LOBYTE(v20) = 5;
  rcTR.meshFilter = &filterTR;
  rcTR.graphics = v10;
  rcTR.camera = this;
  GraphicsManager::setDepthMode(v10, eDepthNoWrite);
  transparent->render(transparent, &rcTR);
  GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"TRANSP_PASS", 0xBu);
  v11 = this->graphics;
  LOBYTE(v20) = 6;
  GPUProfiler::triggerQuery(v11->gpuProfiler, &name);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  LOBYTE(v20) = 1;
  CameraMeshFilter::~CameraMeshFilter(&filterTR);
  LOBYTE(v20) = 0;
  MaterialFilter::~MaterialFilter(&materialFilter);
  v20 = -1;
  CameraMeshFilter::~CameraMeshFilter(&filter);
}
void CameraForward::resetHDR(CameraForward *this)
{
  HDR *v1; // ecx

  v1 = this->hdr;
  if ( v1 )
    HDR::reset(v1);
}
void CameraForward::setBloomBaseLevel(CameraForward *this, float bl)
{
  HDR *v2; // eax

  v2 = this->hdr;
  if ( v2 )
    v2->bloomBaseLevel = bl;
}
void CameraForward::setBloomLevel(CameraForward *this, float bl)
{
  HDR *v2; // eax

  v2 = this->hdr;
  if ( v2 )
    v2->bloomLevel = bl;
}
void CameraForward::setCubemapSize(CameraForward *this, unsigned int size)
{
  CubeMap *v3; // ecx
  CubeMap *v4; // eax
  CubeMap *v5; // eax

  v3 = this->cubeMap;
  if ( v3 )
    ((void (*)(CubeMap *, int))v3->~CubeMap)(v3, 1);
  v4 = (CubeMap *)operator new(8);
  if ( v4 )
  {
    CubeMap::CubeMap(v4, size, 1u, 7u);
    this->cubeMap = v5;
  }
  else
  {
    this->cubeMap = 0;
  }
}
void CameraForward::setHighPassThreshold(CameraForward *this, float t)
{
  HDR *v2; // eax

  v2 = this->hdr;
  if ( v2 )
    v2->highPassLevel = t;
}
void CameraForward::setSolveBlurRenderTarget(CameraForward *this)
{
  KGLRenderTarget *v2; // eax

  v2 = kglGetScreenDepthTarget();
  kglSetRenderTargets(this->hdr->hdrRenderTarget->kidColor, v2);
}
void CameraForward::solveBlur(CameraForward *this, float dt)
{
  __int128 v3; // xmm1
  __m128 v4; // xmm2
  __m128 v5; // xmm3
  __m128 v6; // xmm0
  ShaderVariable *v7; // ecx
  ShaderVariable *v8; // ecx
  float v9; // xmm7_4
  float v10; // xmm4_4
  float v11; // xmm4_4
  ShaderVariable *v12; // ecx
  __m128 v13; // xmm4
  __m128 v14; // xmm1
  __m128 v15; // xmm3
  __m128 v16; // xmm0
  float v17; // xmm5_4
  float v18; // xmm1_4
  __m128 v19; // xmm4
  float v20; // xmm2_4
  __m128 v21; // xmm1
  __m128 v22; // xmm3
  float v23; // xmm6_4
  __m128 v24; // xmm0
  float v25; // xmm4_4
  float v26; // xmm1_4
  __m128 v27; // xmm0
  __m128 v28; // xmm3
  float v29; // xmm6_4
  __m128 v30; // xmm2
  float v31; // xmm0_4
  float v32; // xmm3_4
  float v33; // xmm5_4
  float v34; // xmm0_4
  float v35; // xmm2_4
  float v36; // xmm0_4
  ShaderVariable *v37; // ecx
  ShaderVariable *v38; // ecx
  GraphicsManager *v39; // ecx
  GLRenderer *v40; // esi
  float v41; // [esp+18h] [ebp-1ACh]
  float v42; // [esp+18h] [ebp-1ACh]
  float v43; // [esp+18h] [ebp-1ACh]
  float v44; // [esp+1Ch] [ebp-1A8h]
  float v45; // [esp+20h] [ebp-1A4h]
  __int64 v46; // [esp+20h] [ebp-1A4h]
  float v47; // [esp+24h] [ebp-1A0h]
  float v48; // [esp+24h] [ebp-1A0h]
  float v49; // [esp+28h] [ebp-19Ch]
  float v50; // [esp+28h] [ebp-19Ch]
  __m128 v51; // [esp+2Ch] [ebp-198h]
  unsigned __int64 v52; // [esp+2Ch] [ebp-198h]
  unsigned __int64 v53; // [esp+2Ch] [ebp-198h]
  _BYTE v54[12]; // [esp+2Ch] [ebp-198h]
  float v55; // [esp+3Ch] [ebp-188h]
  float v56; // [esp+40h] [ebp-184h]
  mat44f v57; // [esp+44h] [ebp-180h] BYREF
  mat44f v58; // [esp+84h] [ebp-140h] BYREF
  __m128 v59; // [esp+C4h] [ebp-100h]
  float value[3]; // [esp+D8h] [ebp-ECh] BYREF
  __m128 pDeterminant; // [esp+E4h] [ebp-E0h] BYREF
  mat44f result; // [esp+F4h] [ebp-D0h] BYREF
  mat44f v63; // [esp+134h] [ebp-90h] BYREF
  __m128 v64; // [esp+174h] [ebp-50h]
  mat44f matrix; // [esp+184h] [ebp-40h] BYREF

  this->setSolveBlurRenderTarget(this);
  GraphicsManager::setTextureRT(this->graphics, 2u, this->rtBlur);
  GraphicsManager::setDepthTextureRT(this->graphics, 1u, this->rtBlur);
  GraphicsManager::getProjectionMatrix(this->graphics, &result);
  mat44f::mat44f(&v63);
  v3 = *(_OWORD *)&result.M21;
  v4 = *(__m128 *)&result.M31;
  v5 = *(__m128 *)&result.M41;
  v6 = DirectX::XMMatrixInverse(
         &pDeterminant,
         *(__m128 *)&result.M11,
         *(__m128 *)&result.M21,
         *(__m128 *)&result.M31,
         *(__m128 *)&result.M41);
  pDeterminant = v5;
  v64 = v4;
  v51 = (__m128)v3;
  v59 = v6;
  mat44f::mat44f(&v57);
  v7 = this->svProjInv;
  LODWORD(v57.M11) = v59.m128_i32[0];
  LODWORD(v57.M21) = _mm_shuffle_ps(v59, v59, 85).m128_u32[0];
  LODWORD(v57.M22) = _mm_shuffle_ps(v51, v51, 85).m128_u32[0];
  LODWORD(v57.M23) = _mm_shuffle_ps(v64, v64, 85).m128_u32[0];
  LODWORD(v57.M24) = _mm_shuffle_ps(pDeterminant, pDeterminant, 85).m128_u32[0];
  LODWORD(v57.M31) = _mm_shuffle_ps(v59, v59, 170).m128_u32[0];
  LODWORD(v57.M32) = _mm_shuffle_ps(v51, v51, 170).m128_u32[0];
  LODWORD(v57.M33) = _mm_shuffle_ps(v64, v64, 170).m128_u32[0];
  LODWORD(v57.M12) = v3;
  LODWORD(v57.M13) = v64.m128_i32[0];
  LODWORD(v57.M14) = pDeterminant.m128_i32[0];
  LODWORD(v57.M34) = _mm_shuffle_ps(pDeterminant, pDeterminant, 170).m128_u32[0];
  LODWORD(v57.M41) = v59.m128_i32[3];
  v57.M42 = *((float *)&v3 + 3);
  LODWORD(v57.M43) = v64.m128_i32[3];
  LODWORD(v57.M44) = pDeterminant.m128_i32[3];
  ShaderVariable::set(v7, &v57.M11);
  v57.M11 = result.M11;
  v57.M12 = result.M21;
  v57.M13 = result.M31;
  v8 = this->svProj;
  LODWORD(v57.M21) = _mm_shuffle_ps(*(__m128 *)&result.M11, *(__m128 *)&result.M11, 85).m128_u32[0];
  LODWORD(v57.M22) = _mm_shuffle_ps(*(__m128 *)&result.M21, *(__m128 *)&result.M21, 85).m128_u32[0];
  LODWORD(v57.M23) = _mm_shuffle_ps(*(__m128 *)&result.M31, *(__m128 *)&result.M31, 85).m128_u32[0];
  LODWORD(v57.M24) = _mm_shuffle_ps(*(__m128 *)&result.M41, *(__m128 *)&result.M41, 85).m128_u32[0];
  LODWORD(v57.M31) = _mm_shuffle_ps(*(__m128 *)&result.M11, *(__m128 *)&result.M11, 170).m128_u32[0];
  LODWORD(v57.M32) = _mm_shuffle_ps(*(__m128 *)&result.M21, *(__m128 *)&result.M21, 170).m128_u32[0];
  LODWORD(v57.M33) = _mm_shuffle_ps(*(__m128 *)&result.M31, *(__m128 *)&result.M31, 170).m128_u32[0];
  v57.M14 = result.M41;
  LODWORD(v57.M34) = _mm_shuffle_ps(*(__m128 *)&result.M41, *(__m128 *)&result.M41, 170).m128_u32[0];
  v57.M41 = result.M14;
  v57.M42 = result.M24;
  v57.M43 = result.M34;
  v57.M44 = result.M44;
  ShaderVariable::set(v8, &v57.M11);
  GraphicsManager::getViewMatrix(this->graphics, &v58);
  v4.m128_i32[0] = LODWORD(this->matrix.M41);
  *(float *)&v3 = this->matrix.M42;
  v5.m128_i32[0] = LODWORD(this->matrix.M43);
  v9 = this->lastWorldMatrix.M42;
  v47 = (float)((float)((float)(v58.M21 * *(float *)&v3) + (float)(v58.M11 * v4.m128_f32[0]))
              + (float)(v58.M31 * v5.m128_f32[0]))
      + v58.M41;
  v10 = (float)((float)(v58.M22 * *(float *)&v3) + (float)(v58.M12 * v4.m128_f32[0]))
      + (float)(v58.M32 * v5.m128_f32[0]);
  v6.m128_f32[0] = v58.M13 * v4.m128_f32[0];
  v4.m128_i32[0] = LODWORD(this->lastWorldMatrix.M43);
  v41 = v10 + v58.M42;
  v11 = (float)(v58.M23 * *(float *)&v3) + v6.m128_f32[0];
  v6.m128_f32[0] = v58.M33 * v5.m128_f32[0];
  v5.m128_i32[0] = LODWORD(this->lastWorldMatrix.M41);
  v12 = this->svCameraVelocity;
  value[0] = (float)((float)(v47
                           - (float)((float)((float)((float)(v9 * v58.M21) + (float)(v5.m128_f32[0] * v58.M11))
                                           + (float)(v4.m128_f32[0] * v58.M31))
                                   + v58.M41))
                   * 0.0015)
           * (float)(1.0 / dt);
  value[1] = (float)((float)(v41
                           - (float)((float)((float)((float)(v9 * v58.M22) + (float)(v5.m128_f32[0] * v58.M12))
                                           + (float)(v4.m128_f32[0] * v58.M32))
                                   + v58.M42))
                   * 0.0015)
           * (float)(1.0 / dt);
  value[2] = (float)((float)((float)((float)(v11 + v6.m128_f32[0]) + v58.M43)
                           - (float)((float)((float)((float)(v9 * v58.M23) + (float)(v5.m128_f32[0] * v58.M13))
                                           + (float)(v4.m128_f32[0] * v58.M33))
                                   + v58.M43))
                   * 0.0015)
           * (float)(1.0 / dt);
  ShaderVariable::set(v12, value);
  v4.m128_i32[0] = LODWORD(this->matrix.M31) ^ _xmm;
  v13 = _mm_xor_ps((__m128)LODWORD(this->matrix.M32), (__m128)(unsigned int)_xmm);
  v14 = _mm_xor_ps((__m128)LODWORD(this->matrix.M33), (__m128)(unsigned int)_xmm);
  v15 = v13;
  v48 = (float)((float)(v13.m128_f32[0] * v58.M21) + (float)(v4.m128_f32[0] * v58.M11))
      + (float)(v14.m128_f32[0] * v58.M31);
  v16 = v14;
  v15.m128_f32[0] = (float)((float)(v13.m128_f32[0] * v58.M22) + (float)(v4.m128_f32[0] * v58.M12))
                  + (float)(v14.m128_f32[0] * v58.M32);
  v16.m128_f32[0] = v48;
  v59.m128_f32[2] = (float)((float)(v13.m128_f32[0] * v58.M23) + (float)(v4.m128_f32[0] * v58.M13))
                  + (float)(v14.m128_f32[0] * v58.M33);
  v52 = _mm_unpacklo_ps(v16, v15).m128_u64[0];
  v17 = 0.0;
  v18 = fsqrt(
          (float)((float)(v15.m128_f32[0] * v15.m128_f32[0]) + (float)(v48 * v48))
        + (float)(v59.m128_f32[2] * v59.m128_f32[2]));
  if ( v18 == 0.0 )
  {
    v42 = v59.m128_f32[2];
    v44 = *((float *)&v52 + 1);
    v55 = *(float *)&v52;
  }
  else
  {
    v55 = (float)(1.0 / v18) * v48;
    v44 = *((float *)&v52 + 1) * (float)(1.0 / v18);
    v42 = v59.m128_f32[2] * (float)(1.0 / v18);
  }
  v19 = _mm_xor_ps((__m128)LODWORD(this->lastWorldMatrix.M32), (__m128)(unsigned int)_xmm);
  LODWORD(v20) = LODWORD(this->lastWorldMatrix.M31) ^ _xmm;
  v21 = _mm_xor_ps((__m128)LODWORD(this->lastWorldMatrix.M33), (__m128)(unsigned int)_xmm);
  v22 = v19;
  v23 = (float)((float)(v19.m128_f32[0] * v58.M21) + (float)(v20 * v58.M11)) + (float)(v21.m128_f32[0] * v58.M31);
  v24 = v21;
  v22.m128_f32[0] = (float)((float)(v19.m128_f32[0] * v58.M22) + (float)(v20 * v58.M12))
                  + (float)(v21.m128_f32[0] * v58.M32);
  v24.m128_f32[0] = v23;
  v53 = _mm_unpacklo_ps(v24, v22).m128_u64[0];
  v59.m128_f32[2] = (float)((float)(v19.m128_f32[0] * v58.M23) + (float)(v20 * v58.M13))
                  + (float)(v21.m128_f32[0] * v58.M33);
  v25 = *((float *)&v53 + 1);
  v26 = fsqrt(
          (float)((float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v23 * v23))
        + (float)(v59.m128_f32[2] * v59.m128_f32[2]));
  if ( v26 == 0.0 )
  {
    v29 = v59.m128_f32[2];
    v28 = (__m128)(unsigned int)v53;
  }
  else
  {
    v27 = (__m128)LODWORD(FLOAT_1_0);
    v27.m128_f32[0] = 1.0 / v26;
    v28 = v27;
    v25 = *((float *)&v53 + 1) * (float)(1.0 / v26);
    v28.m128_f32[0] = (float)(1.0 / v26) * v23;
    v29 = v59.m128_f32[2] * (float)(1.0 / v26);
  }
  v30 = v28;
  v30.m128_f32[0] = (float)(v28.m128_f32[0] * v42) - (float)(v29 * v55);
  v45 = (float)(v29 * v44) - (float)(v25 * v42);
  *(_QWORD *)v54 = _mm_unpacklo_ps((__m128)LODWORD(v45), v30).m128_u64[0];
  v59.m128_f32[2] = (float)(v25 * v55) - (float)(v28.m128_f32[0] * v44);
  *(float *)&v54[8] = v59.m128_f32[2];
  v31 = fsqrt(
          (float)((float)(v30.m128_f32[0] * v30.m128_f32[0]) + (float)(v45 * v45))
        + (float)(v59.m128_f32[2] * v59.m128_f32[2]));
  if ( v31 == 0.0 )
  {
    v46 = *(_QWORD *)&v54[4];
    v49 = *(float *)v54;
  }
  else
  {
    v49 = (float)(1.0 / v31) * v45;
    *(float *)&v46 = (float)(1.0 / v31) * *(float *)&v54[4];
    *((float *)&v46 + 1) = (float)(1.0 / v31) * v59.m128_f32[2];
  }
  v32 = (float)((float)(v28.m128_f32[0] * v55) + (float)(v25 * v44)) + (float)(v29 * v42);
  if ( v32 < 1.0 )
    v17 = (float)(__libm_sse2_acosf().m128_f32[0] * (float)(1.0 / dt)) * 0.0015;
  if ( v32 < 0.89999998 )
    v17 = (float)((float)(v17 - this->currentBlurAngle) * 0.1) + this->currentBlurAngle;
  this->currentBlurAngle = v17;
  v43 = __libm_sse2_cosf().m128_f32[0];
  v56 = __libm_sse2_sinf().m128_f32[0];
  mat44f::mat44f(&v63);
  v33 = (float)(v49 * *(float *)&v46) * (float)(1.0 - v43);
  v57.M11 = (float)((float)(v49 * v49) * (float)(1.0 - v43)) + v43;
  v57.M21 = (float)(*((float *)&v46 + 1) * v56) + v33;
  v34 = (float)(v49 * *((float *)&v46 + 1)) * (float)(1.0 - v43);
  v57.M12 = v33 - (float)(*((float *)&v46 + 1) * v56);
  v35 = (float)(*(float *)&v46 * v56) + v34;
  v57.M31 = v34 - (float)(*(float *)&v46 * v56);
  v36 = (float)(*(float *)&v46 * *((float *)&v46 + 1)) * (float)(1.0 - v43);
  v57.M13 = v35;
  v50 = v49 * v56;
  v57.M22 = (float)((float)(*(float *)&v46 * *(float *)&v46) * (float)(1.0 - v43)) + v43;
  v57.M32 = v50 + v36;
  v57.M14 = v63.M41;
  v57.M23 = v36 - v50;
  v57.M24 = v63.M42;
  v57.M33 = (float)((float)(*((float *)&v46 + 1) * *((float *)&v46 + 1)) * (float)(1.0 - v43)) + v43;
  v57.M34 = v63.M43;
  v57.M41 = v63.M14;
  v57.M42 = v63.M24;
  v57.M43 = v63.M34;
  v37 = this->svCameraAngularVelocity;
  v57.M44 = 1.0;
  ShaderVariable::set(v37, &v57.M11);
  ShaderVariable::set(this->svQuality, &this->blurQuality);
  v38 = this->svCameraVelocity;
  *(__m128i *)&this->lastWorldMatrix.M11 = _mm_loadu_si128((const __m128i *)&this->matrix);
  *(__m128i *)&this->lastWorldMatrix.M21 = _mm_loadu_si128((const __m128i *)&this->matrix.M21);
  *(__m128i *)&this->lastWorldMatrix.M31 = _mm_loadu_si128((const __m128i *)&this->matrix.M31);
  *(__m128i *)&this->lastWorldMatrix.M41 = _mm_loadu_si128((const __m128i *)&this->matrix.M41);
  CBuffer::commit(v38->buffer);
  mat44f::mat44f(&matrix);
  mat44f::loadIdentity(&matrix);
  GraphicsManager::setWorldMatrix(this->graphics, &matrix);
  GraphicsManager::clearRenderTargetDepth(this->graphics, 1.0);
  v39 = this->graphics;
  v40 = v39->gl;
  GraphicsManager::setBlendMode(v39, eOpaque);
  GraphicsManager::setDepthMode(this->graphics, eDepthLessEqual);
  GLRenderer::fullScreenQuad(v40, this->blurShader);
  GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
  GraphicsManager::clearTextureSlot(this->graphics, 1);
  GraphicsManager::clearTextureSlot(this->graphics, 2);
}
