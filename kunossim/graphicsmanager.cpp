#include "graphicsmanager.h"
void __userpurge GraphicsManager::GraphicsManager(GraphicsManager *this@<ecx>, __m128 a2@<xmm1>, const VideoSettings *ivideoSettings)
{
  PvsProcessor *v4; // eax
  PvsProcessor *v5; // eax
  std::_Tree_node<std::pair<std::wstring const ,CBuffer *>,void *> *v6; // eax
  float v7; // eax
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm0_4
  float v12; // xmm0_4
  HWND v13; // eax
  int v14; // edi
  int v15; // esi
  int v16; // eax
  int v17; // esi
  int v18; // edi
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  int v22; // eax
  float v23; // xmm1_4
  float v24; // xmm2_4
  float v25; // xmm3_4
  int v26; // eax
  ResourceStore *v27; // eax
  ResourceStore *v28; // eax
  ResourceStore *v29; // ecx
  std::unique_ptr<ResourceStore> *v30; // eax
  ResourceStore *v31; // edx
  ResourceStore_vtbl *v32; // eax
  GPUProfiler *v33; // eax
  GPUProfiler *v34; // eax
  GLRenderer *v35; // eax
  GLRenderer *v36; // eax
  HWND v37; // [esp-Ch] [ebp-114h]
  float bias2; // [esp+24h] [ebp-E4h] BYREF
  float bias1; // [esp+28h] [ebp-E0h] BYREF
  float bias0; // [esp+2Ch] [ebp-DCh] BYREF
  KGLVideoSettings kvs; // [esp+30h] [ebp-D8h] BYREF
  GraphicsManager *v42; // [esp+68h] [ebp-A0h]
  std::wstring Rect; // [esp+6Ch] [ebp-9Ch] BYREF
  std::wstring _Val; // [esp+84h] [ebp-84h] BYREF
  std::wstring filename; // [esp+9Ch] [ebp-6Ch] BYREF
  INIReader ini; // [esp+B4h] [ebp-54h] BYREF
  int v47; // [esp+104h] [ebp-4h]

  v42 = this;
  this->__vftable = (GraphicsManager_vtbl *)&GraphicsManager::`vftable';
  VideoSettings::VideoSettings(&this->videoSettings);
  this->stats.dipCalls = 0;
  this->stats.triangles = 0;
  this->stats.sceneTriangles = 0;
  this->stats.isInMainRenderPass = 0;
  this->stats.sceneDipCalls = 0;
  LightingSettings::LightingSettings(&this->lightingSettings);
  this->renderFlags.maxFrameLatency = 1;
  this->renderFlags.mipLodBias = 0.0;
  this->suspendViewportUpdateOnSetRenderTarget = 0;
  v4 = (PvsProcessor *)operator new(552984);
  if ( v4 )
    PvsProcessor::PvsProcessor(v4);
  else
    v5 = 0;
  this->pvsProcessor = v5;
  this->currentCubeMap = 0;
  this->evWindowResize.handlers._Myfirst = 0;
  this->evWindowResize.handlers._Mylast = 0;
  this->evWindowResize.handlers._Myend = 0;
  v47 = 0;
  this->evWindowPreResize.handlers._Myfirst = 0;
  this->evWindowPreResize.handlers._Mylast = 0;
  this->evWindowPreResize.handlers._Myend = 0;
  this->resourceStore._Myptr = 0;
  RenderState::RenderState(&this->state);
  this->customSunDirection.x = 0.0;
  this->customSunDirection.y = 0.0;
  this->customSunDirection.z = 0.0;
  this->errorStrings._Myfirst = 0;
  this->errorStrings._Mylast = 0;
  this->errorStrings._Myend = 0;
  this->glRenderers._Myfirst = 0;
  this->glRenderers._Mylast = 0;
  this->glRenderers._Myend = 0;
  LODWORD(bias2) = &this->sysBuffers;
  CBuffer::CBuffer(&this->sysBuffers.cbCamera);
  CBuffer::CBuffer(&this->sysBuffers.cbPerObject);
  CBuffer::CBuffer(&this->sysBuffers.cbLighting);
  CBuffer::CBuffer(&this->sysBuffers.cbShadowMap);
  this->cBuffersMap._Myhead = 0;
  this->cBuffersMap._Mysize = 0;
  std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const,int>>>::_Buyheadnode((std::_Tree_alloc<0,std::_Tree_base_types<std::pair<std::wstring const ,TyreCompoundStrategy>> > *)&this->cBuffersMap);
  this->cBuffersMap._Myhead = v6;
  ShaderManager::ShaderManager(&this->shaderManager, this);
  this->useCustomSunDirection = 0;
  a2.m128_f32[0] = 1.0;
  this->exposureMultiplier = 1.0;
  this->suspendViewportUpdateOnSetRenderTarget = 0;
  *(_DWORD *)&Rect._Bx._Alias[8] = 1065353216;
  LOBYTE(v47) = 10;
  *(__m128i *)&this->videoSettings.aaSamples = _mm_loadu_si128((const __m128i *)ivideoSettings);
  *(__m128i *)&this->videoSettings.isFullscreen = _mm_loadu_si128((const __m128i *)&ivideoSettings->isFullscreen);
  *(__m128i *)&this->videoSettings.fpsCapMS = _mm_loadu_si128((const __m128i *)&ivideoSettings->fpsCapMS);
  *(__m128i *)&this->videoSettings.ppHDREnabled = _mm_loadu_si128((const __m128i *)&ivideoSettings->ppHDREnabled);
  v7 = *(float *)&Rect._Bx._Alias[8];
  *(_QWORD *)&this->videoSettings.tripleBuffer = *(_QWORD *)&ivideoSettings->tripleBuffer;
  *(_QWORD *)&this->lightingSettings.lightDirection.x = _mm_unpacklo_ps(a2, (__m128)LODWORD(FLOAT_N1_0)).m128_u64[0];
  this->lightingSettings.lightDirection.z = v7;
  v8 = this->lightingSettings.lightColor.y;
  v9 = this->lightingSettings.lightColor.x;
  v10 = this->lightingSettings.lightColor.z;
  v11 = fsqrt((float)((float)(v9 * v9) + (float)(v8 * v8)) + (float)(v10 * v10));
  if ( v11 != 0.0 )
  {
    this->lightingSettings.lightColor.x = (float)(1.0 / v11) * v9;
    this->lightingSettings.lightColor.y = (float)(1.0 / v11) * v8;
    this->lightingSettings.lightColor.z = (float)(1.0 / v11) * v10;
  }
  this->lightingSettings.angle = 40.0;
  this->multiSampleQuality = 0;
  GraphicsManager::initRenderFlags(this);
  kvs.aaQuality = this->videoSettings.aaQuality;
  kvs.aaSamples = this->videoSettings.aaSamples;
  kvs.anisotropic = this->videoSettings.anisotropic;
  v12 = this->videoSettings.refresh;
  kvs.fpsCap = (int)this->videoSettings.fpsCapMS;
  kvs.hdrPostProcessing = this->videoSettings.ppHDREnabled;
  kvs.height = this->videoSettings.height;
  kvs.isFullscreen = this->videoSettings.isFullscreen;
  kvs.modeIndex = this->videoSettings.dxgiModeIndex;
  kvs.nativeWindow = this->videoSettings.hWnd;
  kvs.shadowMapSize = this->videoSettings.shadowMapSize;
  kvs.vSync = this->videoSettings.vSync;
  kvs.width = this->videoSettings.width;
  kvs.tripleBuffer = this->videoSettings.tripleBuffer;
  kvs.refresh = v12;
  if ( kglInit(&kvs) )
  {
    v13 = GetDesktopWindow();
    GetWindowRect(v13, (LPRECT)&Rect);
    v14 = *(_DWORD *)&Rect._Bx._Alias[12];
    v15 = *(_DWORD *)&Rect._Bx._Alias[8];
    _printf(
      "Could not initialize DirectX11 subsystem, trying safe mode with desktop res %d %d\n",
      *(_DWORD *)&Rect._Bx._Alias[8],
      *(_DWORD *)&Rect._Bx._Alias[12]);
    kvs.aaQuality = 0;
    kvs.aaSamples = 1;
    kvs.anisotropic = 4;
    kvs.isFullscreen = 0;
    v37 = (HWND)this->videoSettings.hWnd;
    kvs.width = v15;
    kvs.height = v14;
    kvs.vSync = 0;
    kvs.tripleBuffer = 0;
    this->videoSettings.width = v15;
    this->videoSettings.height = v14;
    SetWindowPos(v37, 0, 0, 0, v15, v14, 0);
    if ( kglInit(&kvs) )
    {
      _printf("Safe mode initialization failed, exiting\n");
      _exit(1);
    }
  }
  v16 = this->videoSettings.aaSamples;
  if ( v16 != kvs.aaSamples && v16 == 1 )
  {
    std::wstring::wstring(&_Val, L"DirectX 10.0 card detected, AA is not supported and was disabled");
    LOBYTE(v47) = 11;
    std::vector<std::wstring>::push_back(&this->errorStrings, &_Val);
    LOBYTE(v47) = 10;
    if ( _Val._Myres >= 8 )
      operator delete(_Val._Bx._Ptr);
  }
  this->videoSettings.aaQuality = kvs.aaQuality;
  this->videoSettings.aaSamples = kvs.aaSamples;
  GraphicsManager::initCBuffers(this);
  GraphicsManager::initSamplerStates(this);
  v17 = this->videoSettings.height;
  v18 = this->videoSettings.width;
  kglSetViewport(0.0, 0.0, (float)v18, (float)v17);
  bias1 = 1.0 / (float)v18;
  bias0 = 1.0 / (float)v17;
  CBuffer::set(&this->sysBuffers.cbLighting, &bias1, 84, 4);
  CBuffer::set(&this->sysBuffers.cbLighting, &bias0, 88, 4);
  CBuffer::touch(&this->sysBuffers.cbLighting);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"system/cfg/colorCurves.ini", 0x1Au);
  LOBYTE(v47) = 12;
  GraphicsManager::loadLightingSettings(this, &filename);
  LOBYTE(v47) = 10;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  std::wstring::assign(&filename, L"system/cfg/graphics.ini", 0x17u);
  LOBYTE(v47) = 13;
  INIReader::INIReader(&ini, &filename);
  LOBYTE(v47) = 15;
  if ( filename._Myres >= 8 )
    operator delete(filename._Bx._Ptr);
  filename._Myres = 7;
  filename._Mysize = 0;
  filename._Bx._Buf[0] = 0;
  if ( ini.ready )
  {
    _Val._Myres = 7;
    _Val._Mysize = 0;
    _Val._Bx._Buf[0] = 0;
    std::wstring::assign(&_Val, L"SHADOW_MAP_BIAS_0", 0x11u);
    LOBYTE(v47) = 16;
    Rect._Myres = 7;
    Rect._Mysize = 0;
    Rect._Bx._Buf[0] = 0;
    std::wstring::assign(&Rect, L"DX11", 4u);
    LOBYTE(v47) = 17;
    bias0 = INIReader::getFloat(&ini, &Rect, &_Val);
    if ( Rect._Myres >= 8 )
      operator delete(Rect._Bx._Ptr);
    Rect._Myres = 7;
    Rect._Mysize = 0;
    Rect._Bx._Buf[0] = 0;
    LOBYTE(v47) = 15;
    if ( _Val._Myres >= 8 )
      operator delete(_Val._Bx._Ptr);
    _Val._Myres = 7;
    _Val._Mysize = 0;
    _Val._Bx._Buf[0] = 0;
    std::wstring::assign(&_Val, L"SHADOW_MAP_BIAS_1", 0x11u);
    LOBYTE(v47) = 18;
    Rect._Myres = 7;
    Rect._Mysize = 0;
    Rect._Bx._Buf[0] = 0;
    std::wstring::assign(&Rect, L"DX11", 4u);
    LOBYTE(v47) = 19;
    bias1 = INIReader::getFloat(&ini, &Rect, &_Val);
    if ( Rect._Myres >= 8 )
      operator delete(Rect._Bx._Ptr);
    Rect._Myres = 7;
    Rect._Mysize = 0;
    Rect._Bx._Buf[0] = 0;
    LOBYTE(v47) = 15;
    if ( _Val._Myres >= 8 )
      operator delete(_Val._Bx._Ptr);
    _Val._Myres = 7;
    _Val._Mysize = 0;
    _Val._Bx._Buf[0] = 0;
    std::wstring::assign(&_Val, L"SHADOW_MAP_BIAS_2", 0x11u);
    LOBYTE(v47) = 20;
    Rect._Myres = 7;
    Rect._Mysize = 0;
    Rect._Bx._Buf[0] = 0;
    std::wstring::assign(&Rect, L"DX11", 4u);
    LOBYTE(v47) = 21;
    bias2 = INIReader::getFloat(&ini, &Rect, &_Val);
    if ( Rect._Myres >= 8 )
      operator delete(Rect._Bx._Ptr);
    Rect._Myres = 7;
    Rect._Mysize = 0;
    Rect._Bx._Buf[0] = 0;
    LOBYTE(v47) = 15;
    if ( _Val._Myres >= 8 )
      operator delete(_Val._Bx._Ptr);
    v19 = bias0;
    v20 = bias1;
    v21 = bias2;
    v22 = this->videoSettings.shadowMapSize;
    *(_QWORD *)Rect._Bx._Buf = __PAIR64__(LODWORD(bias1), LODWORD(bias0));
    *(float *)&Rect._Bx._Alias[8] = bias2;
    if ( v22 < 2040 )
    {
      v19 = bias0 * 2.0;
      v20 = bias1 * 2.0;
      v21 = bias2 * 2.0;
      *(float *)&Rect._Bx._Ptr = bias0 * 2.0;
      *(float *)&Rect._Bx._Alias[4] = bias1 * 2.0;
      *(float *)&Rect._Bx._Alias[8] = bias2 * 2.0;
    }
    if ( v22 < 1020 )
    {
      *(float *)&Rect._Bx._Ptr = v19 * 2.0;
      *(float *)&Rect._Bx._Alias[4] = v20 * 2.0;
      *(float *)&Rect._Bx._Alias[8] = v21 * 2.0;
    }
  }
  else
  {
    v23 = FLOAT_0_000001;
    v24 = FLOAT_0_000099999997;
    v25 = FLOAT_0_001;
    v26 = this->videoSettings.shadowMapSize;
    *(_QWORD *)Rect._Bx._Buf = __PAIR64__(LODWORD(FLOAT_0_000099999997), LODWORD(FLOAT_0_000001));
    *(float *)&Rect._Bx._Alias[8] = FLOAT_0_001;
    if ( v26 < 2040 )
    {
      v23 = FLOAT_0_000002;
      v24 = FLOAT_0_00019999999;
      v25 = FLOAT_0_0020000001;
      *(_QWORD *)Rect._Bx._Buf = __PAIR64__(LODWORD(FLOAT_0_00019999999), LODWORD(FLOAT_0_000002));
      *(float *)&Rect._Bx._Alias[8] = FLOAT_0_0020000001;
    }
    if ( v26 < 1020 )
    {
      *(float *)&Rect._Bx._Ptr = v23 * 2.0;
      *(float *)&Rect._Bx._Alias[4] = v24 * 2.0;
      *(float *)&Rect._Bx._Alias[8] = v25 * 2.0;
    }
  }
  CBuffer::set(&this->sysBuffers.cbShadowMap, (float *)&Rect._Bx._Ptr, 192, 12);
  *(float *)&v27 = COERCE_FLOAT(operator new(16));
  bias2 = *(float *)&v27;
  LOBYTE(v47) = 22;
  if ( *(float *)&v27 == 0.0 )
  {
    v29 = 0;
  }
  else
  {
    ResourceStore::ResourceStore(v27, this);
    v29 = v28;
  }
  LOBYTE(v47) = 15;
  v30 = &this->resourceStore;
  if ( &this->resourceStore == (std::unique_ptr<ResourceStore> *)&bias2 )
  {
    if ( !v29 )
      goto LABEL_47;
    v32 = v29->__vftable;
  }
  else
  {
    v31 = v30->_Myptr;
    v30->_Myptr = v29;
    if ( !v31 )
      goto LABEL_47;
    v32 = v31->__vftable;
    v29 = v31;
  }
  ((void (*)(ResourceStore *, int))v32->~ResourceStore)(v29, 1);
LABEL_47:
  if ( this->renderFlags.maxFrameLatency > 0 )
    kglSetFrameLatency(this->renderFlags.maxFrameLatency);
  *(float *)&v33 = COERCE_FLOAT(operator new(28));
  bias2 = *(float *)&v33;
  LOBYTE(v47) = 23;
  if ( *(float *)&v33 == 0.0 )
    v34 = 0;
  else
    GPUProfiler::GPUProfiler(v33, this);
  LOBYTE(v47) = 15;
  this->gpuProfiler = v34;
  *(float *)&v35 = COERCE_FLOAT(operator new(220));
  bias2 = *(float *)&v35;
  LOBYTE(v47) = 24;
  if ( *(float *)&v35 == 0.0 )
    v36 = 0;
  else
    GLRenderer::GLRenderer(v35, this, 0x20u, 1);
  this->gl = v36;
  LOBYTE(v47) = 10;
  INIReader::~INIReader(&ini);
}
void GraphicsManager::~GraphicsManager(GraphicsManager *this)
{
  GPUProfiler *v2; // esi
  GLRenderer *v3; // ecx
  GLRenderer **v4; // esi
  std::vector<GLRenderer *> *v5; // ebp
  std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *v6; // edi
  std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *v7; // ecx
  std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *v8; // eax
  bool v9; // zf
  std::vector<std::wstring> *v10; // edi
  std::wstring *v11; // ebp
  std::wstring *i; // esi
  ResourceStore *v13; // ecx
  Event<OnWindowResize> *v14; // ebp
  std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *v15; // eax
  std::pair<void *,std::function<void __cdecl(OnWindowResize const &)> > *v16; // edi
  std::_Func_base<void,OnWindowResize const &> **v17; // esi
  Event<OnWindowResize> *v18; // ebx
  std::pair<void *,std::function<void __cdecl(OnWindowResize const &)> > *v19; // ebp
  std::pair<void *,std::function<void __cdecl(OnWindowResize const &)> > *v20; // edi
  std::_Func_base<void,OnWindowResize const &> **v21; // esi
  std::_Tree_node<std::pair<std::wstring const ,CBuffer *>,void *> *v22; // [esp-4h] [ebp-2Ch]
  std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > > result; // [esp+14h] [ebp-14h] BYREF
  GraphicsManager *v24; // [esp+18h] [ebp-10h]
  int v25; // [esp+24h] [ebp-4h]

  v24 = this;
  this->__vftable = (GraphicsManager_vtbl *)&GraphicsManager::`vftable';
  v2 = this->gpuProfiler;
  v25 = 7;
  if ( v2 )
  {
    GPUProfiler::~GPUProfiler(v2);
    operator delete(v2);
  }
  Font::cleanup();
  v3 = this->gl;
  if ( v3 )
    ((void (*)(GLRenderer *, int))v3->~GLRenderer)(v3, 1);
  ShaderManager::cleanup(&this->shaderManager);
  CBuffer::release(&this->sysBuffers.cbCamera);
  CBuffer::release(&this->sysBuffers.cbLighting);
  CBuffer::release(&this->sysBuffers.cbPerObject);
  CBuffer::release(&this->sysBuffers.cbShadowMap);
  kglDestroySampler(this->samplerStates.samplerAniso);
  kglDestroySampler(this->samplerStates.samplerShadow);
  kglDestroySampler(this->samplerStates.samplerPoint);
  kglDestroySampler(this->samplerStates.samplerPointClamp);
  kglDestroySampler(this->samplerStates.samplerLinearClamp);
  v4 = this->glRenderers._Myfirst;
  v5 = &this->glRenderers;
  v6 = 0;
  v7 = (std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *)((unsigned int)((char *)this->glRenderers._Mylast - (char *)v4 + 3) >> 2);
  if ( v4 > this->glRenderers._Mylast )
    v7 = 0;
  result._Ptr = v7;
  if ( v7 )
  {
    v8 = v7;
    do
    {
      if ( *v4 )
      {
        ((void (*)(GLRenderer *, int))(*v4)->~GLRenderer)(*v4, 1);
        v8 = result._Ptr;
      }
      v6 = (std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *)((char *)v6 + 1);
      ++v4;
    }
    while ( v6 != v8 );
  }
  kglShutdown();
  LOBYTE(v25) = 6;
  ShaderManager::~ShaderManager(&this->shaderManager);
  v22 = this->cBuffersMap._Myhead;
  LOBYTE(v25) = 5;
  std::_Tree<std::_Tmap_traits<std::wstring,int,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,int>>,0>>::erase(
    (std::_Tree<std::_Tmap_traits<std::wstring,TyreCompoundStrategy,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,TyreCompoundStrategy> >,0> > *)&this->cBuffersMap,
    &result,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)v22->_Left,
    (std::_Tree_const_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,TyreCompoundStrategy> > > >)v22);
  operator delete(this->cBuffersMap._Myhead);
  result._Ptr = (std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *)&this->sysBuffers;
  LOBYTE(v25) = 10;
  CBuffer::release(&this->sysBuffers.cbShadowMap);
  LOBYTE(v25) = 9;
  CBuffer::release(&this->sysBuffers.cbLighting);
  LOBYTE(v25) = 8;
  CBuffer::release(&this->sysBuffers.cbPerObject);
  LOBYTE(v25) = 4;
  CBuffer::release(&this->sysBuffers.cbCamera);
  v9 = v5->_Myfirst == 0;
  LOBYTE(v25) = 3;
  if ( !v9 )
  {
    std::_Container_base0::_Orphan_all(&this->glRenderers);
    operator delete(v5->_Myfirst);
    v5->_Myfirst = 0;
    this->glRenderers._Mylast = 0;
    this->glRenderers._Myend = 0;
  }
  v9 = this->errorStrings._Myfirst == 0;
  v10 = &this->errorStrings;
  LOBYTE(v25) = 2;
  if ( !v9 )
  {
    std::_Container_base0::_Orphan_all(&this->errorStrings);
    v11 = this->errorStrings._Mylast;
    for ( i = v10->_Myfirst; i != v11; ++i )
    {
      if ( i->_Myres >= 8 )
        operator delete(i->_Bx._Ptr);
      i->_Myres = 7;
      i->_Mysize = 0;
      i->_Bx._Buf[0] = 0;
    }
    operator delete(v10->_Myfirst);
    v10->_Myfirst = 0;
    this->errorStrings._Mylast = 0;
    this->errorStrings._Myend = 0;
  }
  v13 = this->resourceStore._Myptr;
  LOBYTE(v25) = 1;
  if ( v13 )
    ((void (*)(ResourceStore *, int))v13->~ResourceStore)(v13, 1);
  v9 = this->evWindowPreResize.handlers._Myfirst == 0;
  v14 = &this->evWindowPreResize;
  LOBYTE(v25) = 0;
  if ( !v9 )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)&this->evWindowPreResize);
    v15 = (std::_Tree_node<std::pair<std::wstring const ,TyreCompoundStrategy>,void *> *)this->evWindowPreResize.handlers._Mylast;
    v16 = v14->handlers._Myfirst;
    result._Ptr = v15;
    if ( v16 != (std::pair<void *,std::function<void __cdecl(OnWindowResize const &)> > *)v15 )
    {
      v17 = &v16->second._Impl;
      do
      {
        if ( *v17 )
        {
          ((void (__stdcall *)(bool))(*v17)->_Delete_this)(*v17 != (std::_Func_base<void,OnWindowResize const &> *)(v17 - 4));
          v15 = result._Ptr;
          *v17 = 0;
        }
        ++v16;
        v17 += 8;
      }
      while ( v16 != (std::pair<void *,std::function<void __cdecl(OnWindowResize const &)> > *)v15 );
    }
    operator delete(v14->handlers._Myfirst);
    v14->handlers._Myfirst = 0;
    this->evWindowPreResize.handlers._Mylast = 0;
    this->evWindowPreResize.handlers._Myend = 0;
  }
  v18 = &this->evWindowResize;
  v25 = -1;
  if ( v18->handlers._Myfirst )
  {
    std::_Container_base0::_Orphan_all((std::_Container_base0 *)v18);
    v19 = v18->handlers._Mylast;
    v20 = v18->handlers._Myfirst;
    if ( v18->handlers._Myfirst != v19 )
    {
      v21 = &v20->second._Impl;
      do
      {
        if ( *v21 )
        {
          ((void (__stdcall *)(bool))(*v21)->_Delete_this)(*v21 != (std::_Func_base<void,OnWindowResize const &> *)(v21 - 4));
          *v21 = 0;
        }
        ++v20;
        v21 += 8;
      }
      while ( v20 != v19 );
    }
    operator delete(v18->handlers._Myfirst);
    v18->handlers._Myfirst = 0;
    v18->handlers._Mylast = 0;
    v18->handlers._Myend = 0;
  }
}
GraphicsManager *GraphicsManager::`vector deleting destructor'(GraphicsManager *this, unsigned int a2)
{
  GraphicsManager::~GraphicsManager(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void GraphicsManager::beginMainRenderPass(GraphicsManager *this)
{
  this->stats.isInMainRenderPass = 1;
}
void GraphicsManager::beginScene(GraphicsManager *this)
{
  bool v2; // zf
  KGLRenderTarget *v3; // esi
  KGLRenderTarget *v4; // eax
  int v5; // esi
  int v6; // edi
  float value; // [esp+1Ch] [ebp-8h] BYREF
  float v8; // [esp+20h] [ebp-4h] BYREF

  GPUProfiler::beginFrame(this->gpuProfiler);
  kglSetDefaultState();
  v2 = this->state.blendMode == eOpaque;
  this->state.cullMode = eCullNone;
  this->state.depthState = eDepthNormal;
  if ( !v2 )
  {
    kglSetBlendState(0);
    this->state.blendMode = eOpaque;
  }
  if ( this->videoSettings.aaSamples == 1 || !this->videoSettings.ppHDREnabled )
  {
    v3 = kglGetScreenRenderTarget();
    v4 = kglGetScreenDepthTarget();
    kglSetRenderTargets(v3, v4);
  }
  kglSetSamplerPS(this->samplerStates.samplerAniso, 0);
  kglSetSamplerPS(this->samplerStates.samplerShadow, 1u);
  kglSetSamplerPS(this->samplerStates.samplerPoint, 2u);
  kglSetSamplerPS(this->samplerStates.samplerPointClamp, 4u);
  kglSetSamplerPS(this->samplerStates.samplerLinearShadow, 3u);
  kglSetSamplerPS(this->samplerStates.samplerLinearSimple, 5u);
  v5 = this->videoSettings.height;
  v6 = this->videoSettings.width;
  kglSetViewport(0.0, 0.0, (float)v6, (float)v5);
  value = 1.0 / (float)v6;
  v8 = 1.0 / (float)v5;
  CBuffer::set(&this->sysBuffers.cbLighting, &value, 84, 4);
  CBuffer::set(&this->sysBuffers.cbLighting, &v8, 88, 4);
  CBuffer::touch(&this->sysBuffers.cbLighting);
  this->stats.dipCalls = 0;
  this->stats.triangles = 0;
  this->stats.sceneTriangles = 0;
  this->stats.isInMainRenderPass = 0;
  this->stats.sceneDipCalls = 0;
  GraphicsManager::updateLightingSetttings(this);
}
void GraphicsManager::clearRenderTarget(GraphicsManager *this, const vec4f *color)
{
  kglClearColor(&color->x);
}
void GraphicsManager::clearRenderTargetDepth(GraphicsManager *this, float value)
{
  kglClearDepth(value);
}
void GraphicsManager::clearTextureSlot(GraphicsManager *this, int slot)
{
  GraphicsManager_vtbl **v2; // esi

  v2 = &(&this->__vftable)[slot];
  if ( v2[85] )
    kglSetTexture(slot, 0);
  v2[85] = 0;
}
void GraphicsManager::commitShaderChanges(GraphicsManager *this)
{
  CBuffer::commit(&this->sysBuffers.cbCamera);
  CBuffer::commit(&this->sysBuffers.cbLighting);
  CBuffer::commit(&this->sysBuffers.cbPerObject);
  CBuffer::commit(&this->sysBuffers.cbShadowMap);
}
void GraphicsManager::compile(GraphicsManager *this, Node *root)
{
  CompileContext cc; // [esp+0h] [ebp-8h] BYREF

  cc.graphics = this;
  cc.clearVertices = 0;
  root->compile(root, &cc);
}
GLRenderer *GraphicsManager::createGLRenderer(GraphicsManager *this, unsigned int maxVertices)
{
  GLRenderer *v3; // eax
  unsigned int v4; // eax

  v3 = (GLRenderer *)operator new(220);
  if ( v3 )
    GLRenderer::GLRenderer(v3, this, maxVertices, 0);
  else
    v4 = 0;
  maxVertices = v4;
  std::vector<SpinnerData *>::push_back(
    (std::vector<ICollisionObject *> *)&this->glRenderers,
    (ICollisionObject *const *)&maxVertices);
  return (GLRenderer *)maxVertices;
}
void GraphicsManager::drawPrimitive(GraphicsManager *this, unsigned int indicesCount, unsigned int baseIndex, unsigned int baseVertex, unsigned int numVertices)
{
  kglDrawIndexed(indicesCount, baseIndex, baseVertex);
  ++this->stats.dipCalls;
  this->stats.triangles += indicesCount / 3;
  if ( this->stats.isInMainRenderPass )
  {
    this->stats.sceneTriangles += indicesCount / 3;
    ++this->stats.sceneDipCalls;
  }
}
void GraphicsManager::endMainRenderPass(GraphicsManager *this)
{
  this->stats.isInMainRenderPass = 0;
}
void GraphicsManager::endScene(GraphicsManager *this)
{
  GPUProfiler *v2; // ecx
  std::wstring name; // [esp+8h] [ebp-28h] BYREF
  int v4; // [esp+2Ch] [ebp-4h]

  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"END_FRAME", 9u);
  v2 = this->gpuProfiler;
  v4 = 0;
  GPUProfiler::triggerQuery(v2, &name);
  v4 = -1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  kglSwapBuffers();
  GPUProfiler::endFrame(this->gpuProfiler);
}
SystemCBuffers *GraphicsManager::getCBuffer(GraphicsManager *this, const std::wstring *name)
{
  std::wstring *v2; // edi
  SystemCBuffers *result; // eax

  v2 = (std::wstring *)name;
  if ( !std::wstring::compare((std::wstring *)name, 0, name->_Mysize, L"cbCamera", 8u) )
    return &this->sysBuffers;
  if ( !std::wstring::compare(v2, 0, v2->_Mysize, L"cbLighting", 0xAu) )
    return (SystemCBuffers *)&this->sysBuffers.cbLighting;
  if ( !std::wstring::compare(v2, 0, v2->_Mysize, L"cbShadowMaps", 0xCu) )
    return (SystemCBuffers *)&this->sysBuffers.cbShadowMap;
  if ( std::operator==<wchar_t>(v2, L"cbPerObject") )
    return (SystemCBuffers *)&this->sysBuffers.cbPerObject;
  std::_Tree<std::_Tmap_traits<std::wstring,CBuffer *,std::less<std::wstring>,std::allocator<std::pair<std::wstring const,CBuffer *>>,0>>::find(
    (std::_Tree<std::_Tmap_traits<std::wstring,enum DynamicControllerInput,std::less<std::wstring >,std::allocator<std::pair<std::wstring const ,enum DynamicControllerInput> >,0> > *)&this->cBuffersMap,
    (std::_Tree_iterator<std::_Tree_val<std::_Tree_simple_types<std::pair<std::wstring const ,enum DynamicControllerInput> > > > *)&name,
    v2);
  if ( name == (const std::wstring *)this->cBuffersMap._Myhead )
    result = 0;
  else
    result = (SystemCBuffers *)name[1]._Mysize;
  return result;
}
std::vector<std::wstring> *GraphicsManager::getErrorStrings(GraphicsManager *this, std::vector<std::wstring> *result)
{
  std::vector<std::wstring>::vector<std::wstring>(result, &this->errorStrings);
  return result;
}
vec3f *GraphicsManager::getLDRColor(GraphicsManager *this, vec3f *result, const vec3f *c)
{
  float v3; // xmm4_4
  float v4; // xmm3_4
  float v5; // xmm0_4
  float v6; // xmm5_4
  float v7; // xmm0_4
  __int64 v8; // xmm2_8
  vec3f *v9; // eax
  float v10; // ecx
  unsigned int v11; // [esp+54h] [ebp-1Ch]
  __int64 v12; // [esp+58h] [ebp-18h] BYREF
  vec3f r; // [esp+64h] [ebp-Ch]

  if ( this->videoSettings.ppHDREnabled
    || ((v3 = c->y, v4 = c->z, v3 <= v4) ? (v5 = c->z) : (v5 = c->y),
        (v6 = c->x, c->x <= v5) ? (v3 <= v4 ? (v7 = c->z) : (v7 = c->y)) : (v7 = c->x),
        v7 <= 1.0) )
  {
    v9 = result;
    v10 = c->z;
    *(_QWORD *)&result->x = *(_QWORD *)&c->x;
    result->z = v10;
  }
  else
  {
    HIDWORD(v8) = 0;
    *(float *)&v8 = (float)(1.0 / v7) * v6;
    v12 = v8;
    *(float *)&v11 = (float)(1.0 / v7) * v3;
    r.z = (float)(1.0 / v7) * v4;
    _printf("Converting color: %f %f %f to ldr %f %f %f\n", v6, v3, v4, *(float *)&v8, *(float *)&v11, r.z);
    v9 = result;
    *(_QWORD *)&result->x = _mm_unpacklo_ps((__m128)_mm_loadl_epi64((const __m128i *)&v12), (__m128)v11).m128_u64[0];
    result->z = (float)(1.0 / v7) * v4;
  }
  return v9;
}
double GraphicsManager::getLDRScale(GraphicsManager *this, const vec3f *c)
{
  float v3; // xmm1_4
  float v4; // xmm2_4
  float v5; // xmm0_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm0_4

  if ( this->videoSettings.ppHDREnabled )
    return 1.0;
  v3 = c->y;
  v4 = c->z;
  if ( v3 <= v4 )
    v5 = c->z;
  else
    v5 = c->y;
  v6 = c->x;
  if ( c->x <= v5 )
  {
    if ( v3 <= v4 )
      v7 = c->z;
    else
      v7 = c->y;
  }
  else
  {
    v7 = c->x;
  }
  if ( v7 < 1.0 )
    return 1.0;
  if ( v3 <= v4 )
    v8 = c->z;
  else
    v8 = c->y;
  if ( v6 > v8 )
    return v6;
  if ( v3 <= v4 )
    return v4;
  return v3;
}
mat44f *GraphicsManager::getProjectionMatrix(GraphicsManager *this, mat44f *result)
{
  mat44f *v2; // eax

  v2 = result;
  *(__m128i *)&result->M11 = _mm_loadu_si128((const __m128i *)&this->state.projectionMatrix);
  *(__m128i *)&result->M21 = _mm_loadu_si128((const __m128i *)&this->state.projectionMatrix.M21);
  *(__m128i *)&result->M31 = _mm_loadu_si128((const __m128i *)&this->state.projectionMatrix.M31);
  *(__m128i *)&result->M41 = _mm_loadu_si128((const __m128i *)&this->state.projectionMatrix.M41);
  return v2;
}
Shader *__userpurge GraphicsManager::getShader@<eax>(GraphicsManager *this@<ecx>, unsigned int a2@<ebx>, const std::wstring *name)
{
  Shader *result; // eax

  result = ShaderManager::getShader(&this->shaderManager, a2, name);
  if ( !result )
  {
    _fflush(0);
    _exit(1);
  }
  return result;
}
vec3f *GraphicsManager::getShadowMapBias(GraphicsManager *this, vec3f *result)
{
  result->x = 0.0;
  result->y = 0.0;
  result->z = 0.0;
  CBuffer::get(&this->sysBuffers.cbShadowMap, &result->x, 192, 12);
  return result;
}
mat44f *GraphicsManager::getViewMatrix(GraphicsManager *this, mat44f *result)
{
  mat44f *v2; // eax

  v2 = result;
  *(__m128i *)&result->M11 = _mm_loadu_si128((const __m128i *)&this->state.viewMatrix);
  *(__m128i *)&result->M21 = _mm_loadu_si128((const __m128i *)&this->state.viewMatrix.M21);
  *(__m128i *)&result->M31 = _mm_loadu_si128((const __m128i *)&this->state.viewMatrix.M31);
  *(__m128i *)&result->M41 = _mm_loadu_si128((const __m128i *)&this->state.viewMatrix.M41);
  return v2;
}
mat44f *GraphicsManager::getWorldMatrix(GraphicsManager *this, mat44f *result)
{
  mat44f *v2; // eax

  v2 = result;
  *(__m128i *)&result->M11 = _mm_loadu_si128((const __m128i *)&this->state.worldMatrix);
  *(__m128i *)&result->M21 = _mm_loadu_si128((const __m128i *)&this->state.worldMatrix.M21);
  *(__m128i *)&result->M31 = _mm_loadu_si128((const __m128i *)&this->state.worldMatrix.M31);
  *(__m128i *)&result->M41 = _mm_loadu_si128((const __m128i *)&this->state.worldMatrix.M41);
  return v2;
}
void GraphicsManager::initCBuffers(GraphicsManager *this)
{
  float v2; // xmm0_4
  float exposure; // [esp+8h] [ebp-54h] BYREF
  float minExp; // [esp+Ch] [ebp-50h] BYREF
  float maxExp; // [esp+10h] [ebp-4Ch] BYREF
  float dofFocus; // [esp+14h] [ebp-48h] BYREF
  float dofRange; // [esp+18h] [ebp-44h] BYREF
  float gamma; // [esp+1Ch] [ebp-40h] BYREF
  vec3f lightDir; // [esp+20h] [ebp-3Ch] BYREF
  vec4f ambient; // [esp+2Ch] [ebp-30h] BYREF
  vec4f zenithColor; // [esp+3Ch] [ebp-20h] BYREF
  vec4f horizonColor; // [esp+4Ch] [ebp-10h] BYREF

  CBuffer::init(&this->sysBuffers.cbCamera, 0, 224);
  CBuffer::init(&this->sysBuffers.cbPerObject, 1, 64);
  CBuffer::init(&this->sysBuffers.cbLighting, 2, 160);
  CBuffer::set(&this->sysBuffers.cbLighting, &this->lightingSettings.lightColor.x, 32, 12);
  v2 = fsqrt(2.0);
  lightDir.x = 1.0;
  lightDir.y = -1.0;
  lightDir.z = 0.0;
  if ( v2 != 0.0 )
  {
    lightDir.x = 1.0 / v2;
    lightDir.y = (float)(1.0 / v2) * -1.0;
    lightDir.z = (float)(1.0 / v2) * 0.0;
  }
  CBuffer::set(&this->sysBuffers.cbLighting, &lightDir.x, 0, 12);
  ambient = (vec4f)_xmm;
  CBuffer::set(&this->sysBuffers.cbLighting, &ambient.x, 16, 16);
  zenithColor = (vec4f)_xmm;
  horizonColor = (vec4f)_xmm;
  CBuffer::set(&this->sysBuffers.cbLighting, &zenithColor.x, 64, 16);
  CBuffer::set(&this->sysBuffers.cbLighting, &horizonColor.x, 48, 16);
  exposure = 2.0;
  CBuffer::set(&this->sysBuffers.cbLighting, &exposure, 80, 4);
  minExp = 0.0;
  CBuffer::set(&this->sysBuffers.cbLighting, &minExp, 128, 4);
  maxExp = 10000.0;
  CBuffer::set(&this->sysBuffers.cbLighting, &maxExp, 132, 4);
  dofFocus = 400.0;
  CBuffer::set(&this->sysBuffers.cbLighting, &dofFocus, 136, 4);
  dofRange = 500.0;
  CBuffer::set(&this->sysBuffers.cbLighting, &dofRange, 140, 4);
  gamma = 1.0;
  CBuffer::set(&this->sysBuffers.cbLighting, &gamma, 144, 4);
  CBuffer::init(&this->sysBuffers.cbShadowMap, 3, 208);
  this->sysBuffers.cbCamera.isSystem = 1;
  this->sysBuffers.cbLighting.isSystem = 1;
  this->sysBuffers.cbPerObject.isSystem = 1;
  this->sysBuffers.cbShadowMap.isSystem = 1;
}
void GraphicsManager::initRenderFlags(GraphicsManager *this)
{
  int v2; // eax
  bool v3; // cf
  double v4; // st7
  std::wstring section; // [esp+8h] [ebp-9Ch] BYREF
  std::wstring key; // [esp+20h] [ebp-84h] BYREF
  std::wstring ifilename; // [esp+38h] [ebp-6Ch] BYREF
  INIReader r; // [esp+50h] [ebp-54h] BYREF
  int v9; // [esp+A0h] [ebp-4h]

  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/graphics.ini", 0x17u);
  v9 = 0;
  INIReader::INIReader(&r, &ifilename);
  LOBYTE(v9) = 2;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  INIReader::setVerboseMode(&r, 1);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"MAXIMUM_FRAME_LATENCY", 0x15u);
  LOBYTE(v9) = 3;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"DX11", 4u);
  LOBYTE(v9) = 4;
  v2 = INIReader::getInt(&r, &section, &key);
  v3 = section._Myres < 8;
  this->renderFlags.maxFrameLatency = v2;
  if ( !v3 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v9) = 2;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"MIP_LOD_BIAS", 0xCu);
  LOBYTE(v9) = 5;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"DX11", 4u);
  LOBYTE(v9) = 6;
  v4 = INIReader::getFloat(&r, &section, &key);
  v3 = section._Myres < 8;
  this->renderFlags.mipLodBias = v4;
  if ( !v3 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  v9 = -1;
  INIReader::~INIReader(&r);
}
void GraphicsManager::initSamplerStates(GraphicsManager *this)
{
  ID3D11SamplerState *v2; // eax
  void *v3; // [esp-14h] [ebp-1Ch]

  this->samplerStates.samplerAniso = kglCreateSampler(
                                       0,
                                       0,
                                       this->videoSettings.anisotropic,
                                       this->renderFlags.mipLodBias);
  this->samplerStates.samplerShadow = kglCreateSampler(3u, 1u, 0, 0.0);
  this->samplerStates.samplerPoint = kglCreateSampler(2u, 0, 0, 0.0);
  this->samplerStates.samplerPointClamp = kglCreateSampler(2u, 1u, 0, 0.0);
  this->samplerStates.samplerLinearClamp = kglCreateSampler(1u, 1u, 0, 0.0);
  this->samplerStates.samplerLinearShadow = kglCreateSampler(1u, 0, 0, 0.0);
  v2 = kglCreateSampler(1u, 0, 0, 0.0);
  v3 = this->samplerStates.samplerAniso;
  this->samplerStates.samplerLinearSimple = v2;
  kglSetSamplerPS(v3, 0);
  kglSetSamplerPS(this->samplerStates.samplerShadow, 1u);
  kglSetSamplerPS(this->samplerStates.samplerPoint, 2u);
  kglSetSamplerPS(this->samplerStates.samplerPointClamp, 4u);
  kglSetSamplerPS(this->samplerStates.samplerLinearShadow, 3u);
  kglSetSamplerPS(this->samplerStates.samplerLinearSimple, 5u);
}
void GraphicsManager::loadLightingSettings(GraphicsManager *this, const std::wstring *filename)
{
  int v3; // edi
  vec4f *v4; // eax
  bool v5; // cf
  float v6; // xmm0_4
  __m128 v7; // xmm2
  __m128 v8; // xmm3
  float v9; // xmm1_4
  vec4f *v10; // eax
  float v11; // xmm0_4
  __m128 v12; // xmm2
  __m128 v13; // xmm3
  float v14; // xmm1_4
  vec4f *v15; // eax
  float v16; // xmm0_4
  __m128 v17; // xmm2
  __m128 v18; // xmm3
  float v19; // xmm1_4
  vec4f *v20; // eax
  float v21; // xmm0_4
  __m128 v22; // xmm2
  __m128 v23; // xmm3
  float v24; // xmm1_4
  vec4f *v25; // eax
  float v26; // xmm0_4
  __m128 v27; // xmm3
  __m128 v28; // xmm2
  float v29; // xmm1_4
  vec4f *v30; // eax
  float v31; // xmm0_4
  __m128 v32; // xmm3
  __m128 v33; // xmm2
  float v34; // xmm1_4
  vec4f *v35; // eax
  float v36; // xmm0_4
  __m128 v37; // xmm3
  __m128 v38; // xmm2
  float v39; // xmm1_4
  vec4f *v40; // eax
  float v41; // xmm0_4
  __m128 v42; // xmm3
  __m128 v43; // xmm2
  float v44; // xmm1_4
  vec3f *v45; // eax
  __m128 v46; // xmm2
  __m128 v47; // xmm1
  float v48; // xmm0_4
  vec3f *v49; // eax
  __m128 v50; // xmm2
  __m128 v51; // xmm1
  float v52; // xmm0_4
  vec3f *v53; // eax
  __m128 v54; // xmm2
  __m128 v55; // xmm1
  float v56; // xmm0_4
  vec3f *v57; // eax
  __m128 v58; // xmm2
  __m128 v59; // xmm1
  float v60; // xmm0_4
  vec3f *v61; // eax
  __m128 v62; // xmm2
  __m128 v63; // xmm1
  float v64; // xmm0_4
  vec3f *v65; // eax
  __m128 v66; // xmm2
  __m128 v67; // xmm1
  float v68; // xmm0_4
  vec3f *v69; // eax
  __m128 v70; // xmm2
  __m128 v71; // xmm1
  float v72; // xmm0_4
  vec3f *v73; // eax
  __m128 v74; // xmm2
  __m128 v75; // xmm1
  float v76; // xmm0_4
  double v77; // st7
  float hdr_mult; // [esp+Ch] [ebp-B8h]
  std::wstring v79; // [esp+10h] [ebp-B4h] BYREF
  std::wstring v80; // [esp+28h] [ebp-9Ch] BYREF
  std::wstring section; // [esp+40h] [ebp-84h] BYREF
  std::wstring key; // [esp+58h] [ebp-6Ch] BYREF
  INIReader r; // [esp+70h] [ebp-54h] BYREF
  int v84; // [esp+C0h] [ebp-4h]

  INIReader::INIReader(&r, filename);
  v84 = 0;
  if ( r.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"VERSION", 7u);
    LOBYTE(v84) = 1;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HEADER", 6u);
    LOBYTE(v84) = 2;
    v3 = INIReader::getInt(&r, &section, &key);
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v84) = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    hdr_mult = FLOAT_1_0;
    if ( !this->videoSettings.ppHDREnabled )
    {
      std::wstring::wstring(&v79, L"HDR_OFF_MULT");
      LOBYTE(v84) = 3;
      std::wstring::wstring(&section, L"HEADER");
      LOBYTE(v84) = 4;
      hdr_mult = INIReader::getFloat(&r, &section, &v79);
      if ( section._Myres >= 8 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v84) = 0;
      if ( v79._Myres >= 8 )
        operator delete(v79._Bx._Ptr);
    }
    std::wstring::wstring(&v80, L"HIGH");
    if ( v3 < 2 )
    {
      LOBYTE(v84) = 21;
      std::wstring::wstring(&v79, L"HORIZON");
      LOBYTE(v84) = 22;
      v45 = INIReader::getFloat3(&r, (vec3f *)&section, &v79, &v80);
      v5 = v79._Myres < 8;
      v46 = (__m128)LODWORD(v45->x);
      v47 = (__m128)LODWORD(v45->y);
      v46.m128_f32[0] = v46.m128_f32[0] * 0.0039215689;
      v47.m128_f32[0] = v47.m128_f32[0] * 0.0039215689;
      v48 = v45->z * 0.0039215689;
      *(_QWORD *)&this->lightingSettings.horizonHigh.x = _mm_unpacklo_ps(v46, v47).m128_u64[0];
      *(float *)&key._Bx._Alias[8] = v48;
      this->lightingSettings.horizonHigh.z = v48;
      if ( !v5 )
        operator delete(v79._Bx._Ptr);
      v79._Myres = 7;
      v79._Mysize = 0;
      v79._Bx._Buf[0] = 0;
      LOBYTE(v84) = 0;
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      std::wstring::wstring(&v80, L"LOW");
      LOBYTE(v84) = 23;
      std::wstring::wstring(&v79, L"HORIZON");
      LOBYTE(v84) = 24;
      v49 = INIReader::getFloat3(&r, (vec3f *)&section, &v79, &v80);
      v5 = v79._Myres < 8;
      v50 = (__m128)LODWORD(v49->x);
      v51 = (__m128)LODWORD(v49->y);
      v50.m128_f32[0] = v50.m128_f32[0] * 0.0039215689;
      v51.m128_f32[0] = v51.m128_f32[0] * 0.0039215689;
      v52 = v49->z * 0.0039215689;
      *(_QWORD *)&this->lightingSettings.horizonLow.x = _mm_unpacklo_ps(v50, v51).m128_u64[0];
      *(float *)&key._Bx._Alias[8] = v52;
      this->lightingSettings.horizonLow.z = v52;
      if ( !v5 )
        operator delete(v79._Bx._Ptr);
      v79._Myres = 7;
      v79._Mysize = 0;
      v79._Bx._Buf[0] = 0;
      LOBYTE(v84) = 0;
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      std::wstring::wstring(&v80, L"LOW");
      LOBYTE(v84) = 25;
      std::wstring::wstring(&v79, L"SKY");
      LOBYTE(v84) = 26;
      v53 = INIReader::getFloat3(&r, (vec3f *)&section, &v79, &v80);
      v5 = v79._Myres < 8;
      v54 = (__m128)LODWORD(v53->x);
      v55 = (__m128)LODWORD(v53->y);
      v54.m128_f32[0] = v54.m128_f32[0] * 0.0039215689;
      v55.m128_f32[0] = v55.m128_f32[0] * 0.0039215689;
      v56 = v53->z * 0.0039215689;
      *(_QWORD *)&this->lightingSettings.skyLow.x = _mm_unpacklo_ps(v54, v55).m128_u64[0];
      *(float *)&key._Bx._Alias[8] = v56;
      this->lightingSettings.skyLow.z = v56;
      if ( !v5 )
        operator delete(v79._Bx._Ptr);
      v79._Myres = 7;
      v79._Mysize = 0;
      v79._Bx._Buf[0] = 0;
      LOBYTE(v84) = 0;
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      std::wstring::wstring(&v80, L"HIGH");
      LOBYTE(v84) = 27;
      std::wstring::wstring(&v79, L"SKY");
      LOBYTE(v84) = 28;
      v57 = INIReader::getFloat3(&r, (vec3f *)&section, &v79, &v80);
      v5 = v79._Myres < 8;
      v58 = (__m128)LODWORD(v57->x);
      v59 = (__m128)LODWORD(v57->y);
      v58.m128_f32[0] = v58.m128_f32[0] * 0.0039215689;
      v59.m128_f32[0] = v59.m128_f32[0] * 0.0039215689;
      v60 = v57->z * 0.0039215689;
      *(_QWORD *)&this->lightingSettings.skyHigh.x = _mm_unpacklo_ps(v58, v59).m128_u64[0];
      *(float *)&key._Bx._Alias[8] = v60;
      this->lightingSettings.skyHigh.z = v60;
      if ( !v5 )
        operator delete(v79._Bx._Ptr);
      v79._Myres = 7;
      v79._Mysize = 0;
      v79._Bx._Buf[0] = 0;
      LOBYTE(v84) = 0;
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      std::wstring::wstring(&v80, L"LOW");
      LOBYTE(v84) = 29;
      std::wstring::wstring(&v79, L"SUN");
      LOBYTE(v84) = 30;
      v61 = INIReader::getFloat3(&r, (vec3f *)&section, &v79, &v80);
      v5 = v79._Myres < 8;
      v62 = (__m128)LODWORD(v61->x);
      v63 = (__m128)LODWORD(v61->y);
      v62.m128_f32[0] = v62.m128_f32[0] * 0.0039215689;
      v63.m128_f32[0] = v63.m128_f32[0] * 0.0039215689;
      v64 = v61->z * 0.0039215689;
      *(_QWORD *)&this->lightingSettings.sunLow.x = _mm_unpacklo_ps(v62, v63).m128_u64[0];
      *(float *)&key._Bx._Alias[8] = v64;
      this->lightingSettings.sunLow.z = v64;
      if ( !v5 )
        operator delete(v79._Bx._Ptr);
      v79._Myres = 7;
      v79._Mysize = 0;
      v79._Bx._Buf[0] = 0;
      LOBYTE(v84) = 0;
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      std::wstring::wstring(&v80, L"HIGH");
      LOBYTE(v84) = 31;
      std::wstring::wstring(&v79, L"SUN");
      LOBYTE(v84) = 32;
      v65 = INIReader::getFloat3(&r, (vec3f *)&section, &v79, &v80);
      v5 = v79._Myres < 8;
      v66 = (__m128)LODWORD(v65->x);
      v67 = (__m128)LODWORD(v65->y);
      v66.m128_f32[0] = v66.m128_f32[0] * 0.0039215689;
      v67.m128_f32[0] = v67.m128_f32[0] * 0.0039215689;
      v68 = v65->z * 0.0039215689;
      *(_QWORD *)&this->lightingSettings.sunHigh.x = _mm_unpacklo_ps(v66, v67).m128_u64[0];
      *(float *)&key._Bx._Alias[8] = v68;
      this->lightingSettings.sunHigh.z = v68;
      if ( !v5 )
        operator delete(v79._Bx._Ptr);
      v79._Myres = 7;
      v79._Mysize = 0;
      v79._Bx._Buf[0] = 0;
      LOBYTE(v84) = 0;
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      std::wstring::wstring(&v80, L"LOW");
      LOBYTE(v84) = 33;
      std::wstring::wstring(&v79, L"AMBIENT");
      LOBYTE(v84) = 34;
      v69 = INIReader::getFloat3(&r, (vec3f *)&section, &v79, &v80);
      v5 = v79._Myres < 8;
      v70 = (__m128)LODWORD(v69->x);
      v71 = (__m128)LODWORD(v69->y);
      v70.m128_f32[0] = v70.m128_f32[0] * 0.0039215689;
      v71.m128_f32[0] = v71.m128_f32[0] * 0.0039215689;
      v72 = v69->z * 0.0039215689;
      *(_QWORD *)&this->lightingSettings.ambientLow.x = _mm_unpacklo_ps(v70, v71).m128_u64[0];
      *(float *)&key._Bx._Alias[8] = v72;
      this->lightingSettings.ambientLow.z = v72;
      if ( !v5 )
        operator delete(v79._Bx._Ptr);
      v79._Myres = 7;
      v79._Mysize = 0;
      v79._Bx._Buf[0] = 0;
      LOBYTE(v84) = 0;
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      std::wstring::wstring(&v80, L"HIGH");
      LOBYTE(v84) = 35;
      std::wstring::wstring(&v79, L"AMBIENT");
      LOBYTE(v84) = 36;
      v73 = INIReader::getFloat3(&r, (vec3f *)&section, &v79, &v80);
      v74 = (__m128)LODWORD(v73->x);
      v75 = (__m128)LODWORD(v73->y);
      v74.m128_f32[0] = v74.m128_f32[0] * 0.0039215689;
      v75.m128_f32[0] = v75.m128_f32[0] * 0.0039215689;
      v76 = v73->z * 0.0039215689;
      *(_QWORD *)&this->lightingSettings.ambientHigh.x = _mm_unpacklo_ps(v74, v75).m128_u64[0];
      *(float *)&key._Bx._Alias[8] = v76;
    }
    else
    {
      LOBYTE(v84) = 5;
      std::wstring::wstring(&v79, L"HORIZON");
      LOBYTE(v84) = 6;
      v4 = INIReader::getFloat4(&r, (vec4f *)&section, &v79, &v80);
      v5 = v79._Myres < 8;
      v6 = v4->w;
      v7 = (__m128)LODWORD(v4->y);
      v8 = (__m128)LODWORD(v6);
      v8.m128_f32[0] = (float)((float)(v6 * v4->x) * 0.0039215689) * hdr_mult;
      v7.m128_f32[0] = (float)((float)(v7.m128_f32[0] * v6) * 0.0039215689) * hdr_mult;
      v9 = (float)((float)(v4->z * v6) * 0.0039215689) * hdr_mult;
      *(_QWORD *)&this->lightingSettings.horizonHigh.x = _mm_unpacklo_ps(v8, v7).m128_u64[0];
      *(float *)&key._Bx._Alias[8] = v9;
      this->lightingSettings.horizonHigh.z = v9;
      if ( !v5 )
        operator delete(v79._Bx._Ptr);
      v79._Myres = 7;
      v79._Mysize = 0;
      v79._Bx._Buf[0] = 0;
      LOBYTE(v84) = 0;
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      std::wstring::wstring(&v80, L"LOW");
      LOBYTE(v84) = 7;
      std::wstring::wstring(&v79, L"HORIZON");
      LOBYTE(v84) = 8;
      v10 = INIReader::getFloat4(&r, (vec4f *)&section, &v79, &v80);
      v5 = v79._Myres < 8;
      v11 = v10->w;
      v12 = (__m128)LODWORD(v10->y);
      v13 = (__m128)LODWORD(v11);
      v13.m128_f32[0] = (float)((float)(v11 * v10->x) * 0.0039215689) * hdr_mult;
      v12.m128_f32[0] = (float)((float)(v12.m128_f32[0] * v11) * 0.0039215689) * hdr_mult;
      v14 = (float)((float)(v10->z * v11) * 0.0039215689) * hdr_mult;
      *(_QWORD *)&this->lightingSettings.horizonLow.x = _mm_unpacklo_ps(v13, v12).m128_u64[0];
      *(float *)&key._Bx._Alias[8] = v14;
      this->lightingSettings.horizonLow.z = v14;
      if ( !v5 )
        operator delete(v79._Bx._Ptr);
      v79._Myres = 7;
      v79._Mysize = 0;
      v79._Bx._Buf[0] = 0;
      LOBYTE(v84) = 0;
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      std::wstring::wstring(&v80, L"LOW");
      LOBYTE(v84) = 9;
      std::wstring::wstring(&v79, L"SKY");
      LOBYTE(v84) = 10;
      v15 = INIReader::getFloat4(&r, (vec4f *)&section, &v79, &v80);
      v5 = v79._Myres < 8;
      v16 = v15->w;
      v17 = (__m128)LODWORD(v15->y);
      v18 = (__m128)LODWORD(v16);
      v18.m128_f32[0] = (float)((float)(v16 * v15->x) * 0.0039215689) * hdr_mult;
      v17.m128_f32[0] = (float)((float)(v17.m128_f32[0] * v16) * 0.0039215689) * hdr_mult;
      v19 = (float)((float)(v15->z * v16) * 0.0039215689) * hdr_mult;
      *(_QWORD *)&this->lightingSettings.skyLow.x = _mm_unpacklo_ps(v18, v17).m128_u64[0];
      *(float *)&key._Bx._Alias[8] = v19;
      this->lightingSettings.skyLow.z = v19;
      if ( !v5 )
        operator delete(v79._Bx._Ptr);
      v79._Myres = 7;
      v79._Mysize = 0;
      v79._Bx._Buf[0] = 0;
      LOBYTE(v84) = 0;
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      std::wstring::wstring(&v80, L"HIGH");
      LOBYTE(v84) = 11;
      std::wstring::wstring(&v79, L"SKY");
      LOBYTE(v84) = 12;
      v20 = INIReader::getFloat4(&r, (vec4f *)&section, &v79, &v80);
      v5 = v79._Myres < 8;
      v21 = v20->w;
      v22 = (__m128)LODWORD(v20->y);
      v23 = (__m128)LODWORD(v21);
      v23.m128_f32[0] = (float)((float)(v21 * v20->x) * 0.0039215689) * hdr_mult;
      v22.m128_f32[0] = (float)((float)(v22.m128_f32[0] * v21) * 0.0039215689) * hdr_mult;
      v24 = (float)((float)(v20->z * v21) * 0.0039215689) * hdr_mult;
      *(_QWORD *)&this->lightingSettings.skyHigh.x = _mm_unpacklo_ps(v23, v22).m128_u64[0];
      *(float *)&key._Bx._Alias[8] = v24;
      this->lightingSettings.skyHigh.z = v24;
      if ( !v5 )
        operator delete(v79._Bx._Ptr);
      v79._Myres = 7;
      v79._Mysize = 0;
      v79._Bx._Buf[0] = 0;
      LOBYTE(v84) = 0;
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      std::wstring::wstring(&v80, L"LOW");
      LOBYTE(v84) = 13;
      std::wstring::wstring(&v79, L"SUN");
      LOBYTE(v84) = 14;
      v25 = INIReader::getFloat4(&r, (vec4f *)&section, &v79, &v80);
      v5 = v79._Myres < 8;
      v26 = v25->w;
      v27 = (__m128)LODWORD(v25->x);
      v28 = (__m128)LODWORD(v25->y);
      v27.m128_f32[0] = (float)((float)(v27.m128_f32[0] * v26) * 0.0039215689) * hdr_mult;
      v28.m128_f32[0] = (float)((float)(v28.m128_f32[0] * v26) * 0.0039215689) * hdr_mult;
      v29 = (float)((float)(v25->z * v26) * 0.0039215689) * hdr_mult;
      *(_QWORD *)&this->lightingSettings.sunLow.x = _mm_unpacklo_ps(v27, v28).m128_u64[0];
      *(float *)&key._Bx._Alias[8] = v29;
      this->lightingSettings.sunLow.z = v29;
      if ( !v5 )
        operator delete(v79._Bx._Ptr);
      v79._Myres = 7;
      v79._Mysize = 0;
      v79._Bx._Buf[0] = 0;
      LOBYTE(v84) = 0;
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      std::wstring::wstring(&v80, L"HIGH");
      LOBYTE(v84) = 15;
      std::wstring::wstring(&v79, L"SUN");
      LOBYTE(v84) = 16;
      v30 = INIReader::getFloat4(&r, (vec4f *)&section, &v79, &v80);
      v5 = v79._Myres < 8;
      v31 = v30->w;
      v32 = (__m128)LODWORD(v30->x);
      v33 = (__m128)LODWORD(v30->y);
      v32.m128_f32[0] = (float)((float)(v32.m128_f32[0] * v31) * 0.0039215689) * hdr_mult;
      v33.m128_f32[0] = (float)((float)(v33.m128_f32[0] * v31) * 0.0039215689) * hdr_mult;
      v34 = (float)((float)(v30->z * v31) * 0.0039215689) * hdr_mult;
      *(_QWORD *)&this->lightingSettings.sunHigh.x = _mm_unpacklo_ps(v32, v33).m128_u64[0];
      *(float *)&key._Bx._Alias[8] = v34;
      this->lightingSettings.sunHigh.z = v34;
      if ( !v5 )
        operator delete(v79._Bx._Ptr);
      v79._Myres = 7;
      v79._Mysize = 0;
      v79._Bx._Buf[0] = 0;
      LOBYTE(v84) = 0;
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      std::wstring::wstring(&v80, L"LOW");
      LOBYTE(v84) = 17;
      std::wstring::wstring(&v79, L"AMBIENT");
      LOBYTE(v84) = 18;
      v35 = INIReader::getFloat4(&r, (vec4f *)&section, &v79, &v80);
      v5 = v79._Myres < 8;
      v36 = v35->w;
      v37 = (__m128)LODWORD(v35->x);
      v38 = (__m128)LODWORD(v35->y);
      v37.m128_f32[0] = (float)((float)(v37.m128_f32[0] * v36) * 0.0039215689) * hdr_mult;
      v38.m128_f32[0] = (float)((float)(v38.m128_f32[0] * v36) * 0.0039215689) * hdr_mult;
      v39 = (float)((float)(v35->z * v36) * 0.0039215689) * hdr_mult;
      *(_QWORD *)&this->lightingSettings.ambientLow.x = _mm_unpacklo_ps(v37, v38).m128_u64[0];
      *(float *)&key._Bx._Alias[8] = v39;
      this->lightingSettings.ambientLow.z = v39;
      if ( !v5 )
        operator delete(v79._Bx._Ptr);
      v79._Myres = 7;
      v79._Mysize = 0;
      v79._Bx._Buf[0] = 0;
      LOBYTE(v84) = 0;
      if ( v80._Myres >= 8 )
        operator delete(v80._Bx._Ptr);
      std::wstring::wstring(&v80, L"HIGH");
      LOBYTE(v84) = 19;
      std::wstring::wstring(&v79, L"AMBIENT");
      LOBYTE(v84) = 20;
      v40 = INIReader::getFloat4(&r, (vec4f *)&section, &v79, &v80);
      v41 = v40->w;
      v42 = (__m128)LODWORD(v40->x);
      v43 = (__m128)LODWORD(v40->y);
      v44 = (float)(v40->z * v41) * 0.0039215689;
      v42.m128_f32[0] = (float)((float)(v42.m128_f32[0] * v41) * 0.0039215689) * hdr_mult;
      v43.m128_f32[0] = (float)((float)(v43.m128_f32[0] * v41) * 0.0039215689) * hdr_mult;
      *(_QWORD *)&this->lightingSettings.ambientHigh.x = _mm_unpacklo_ps(v42, v43).m128_u64[0];
      *(float *)&key._Bx._Alias[8] = v44 * hdr_mult;
    }
    v5 = v79._Myres < 8;
    this->lightingSettings.ambientHigh.z = *(float *)&key._Bx._Alias[8];
    if ( !v5 )
      operator delete(v79._Bx._Ptr);
    v79._Myres = 7;
    LOBYTE(v84) = 0;
    v79._Bx._Buf[0] = 0;
    v79._Mysize = 0;
    if ( v80._Myres >= 8 )
      operator delete(v80._Bx._Ptr);
    std::wstring::wstring(&section, L"ANGLE_GAMMA");
    LOBYTE(v84) = 37;
    std::wstring::wstring(&v79, L"HEADER");
    LOBYTE(v84) = 38;
    v77 = INIReader::getFloat(&r, &v79, &section);
    v5 = v79._Myres < 8;
    this->lightingSettings.sunAngleGamma = v77;
    if ( !v5 )
      operator delete(v79._Bx._Ptr);
    v79._Myres = 7;
    v79._Mysize = 0;
    v79._Bx._Buf[0] = 0;
    LOBYTE(v84) = 0;
    if ( section._Myres >= 8 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    GraphicsManager::updateLightingSetttings(this);
  }
  v84 = -1;
  INIReader::~INIReader(&r);
}
void GraphicsManager::onResize(GraphicsManager *this, int width, int height)
{
  OnWindowResize res; // [esp+8h] [ebp-8h] BYREF

  if ( width )
  {
    if ( height )
    {
      this->videoSettings.width = width;
      this->videoSettings.height = height;
      res.width = width;
      res.height = height;
      Event<std::wstring>::trigger(
        (Event<OnGearRequestEvent> *)&this->evWindowPreResize,
        (const OnGearRequestEvent *)&res);
      kglResizeBuffers(width, height);
      Event<std::wstring>::trigger((Event<OnGearRequestEvent> *)&this->evWindowResize, (const OnGearRequestEvent *)&res);
    }
  }
}
void GraphicsManager::overrideSamplerState(GraphicsManager *this, SamplerState sampler)
{
  if ( sampler )
  {
    if ( sampler == eLinearClamped )
      kglSetSamplerPS(this->samplerStates.samplerLinearClamp, 5u);
  }
  else
  {
    kglSetSamplerPS(this->samplerStates.samplerLinearSimple, 5u);
  }
}
void GraphicsManager::resetRenderStates(GraphicsManager *this)
{
  this->state.blendMode = eOpaque;
  kglSetBlendState(0);
  this->state.cullMode = eCullFront;
  kglSetCullState(0);
  this->state.depthState = eDepthNormal;
  kglSetDepthState(0);
  this->state.material = 0;
  this->state.overrideNoMS = 0;
  this->state.shader = 0;
  *(_OWORD *)this->state.textures = 0i64;
  *(_OWORD *)&this->state.textures[4] = 0i64;
  *(_OWORD *)&this->state.textures[8] = 0i64;
  *(_OWORD *)&this->state.textures[12] = 0i64;
  *(_OWORD *)&this->state.textures[16] = 0i64;
  *(_OWORD *)&this->state.textures[20] = 0i64;
  *(_OWORD *)&this->state.textures[24] = 0i64;
  *(_OWORD *)&this->state.textures[28] = 0i64;
}
void GraphicsManager::setBlendMode(GraphicsManager *this, BlendMode mode)
{
  if ( this->state.blendMode != mode )
  {
    kglSetBlendState(mode);
    this->state.blendMode = mode;
  }
}
void GraphicsManager::setCullMode(GraphicsManager *this, CullMode mode)
{
  CullMode v2; // esi

  v2 = mode;
  if ( this->state.overrideNoMS && mode == eCullFront )
    v2 = eCullFrontNoMS;
  if ( v2 != this->state.cullMode )
  {
    kglSetCullState(v2);
    this->state.cullMode = v2;
  }
}
void GraphicsManager::setCustomSunDirection(GraphicsManager *this, vec3f sunDirection)
{
  float v2; // eax

  v2 = sunDirection.z;
  *(_QWORD *)&this->customSunDirection.x = *(_QWORD *)&sunDirection.x;
  this->customSunDirection.z = v2;
}
void GraphicsManager::setDepthMode(GraphicsManager *this, DepthMode mode)
{
  switch ( mode )
  {
    case eDepthNormal:
      if ( this->state.depthState )
      {
        kglSetDepthState(0);
        this->state.depthState = eDepthNormal;
      }
      break;
    case eDepthNoWrite:
      if ( this->state.depthState != eDepthNoWrite )
      {
        kglSetDepthState(1u);
        this->state.depthState = eDepthNoWrite;
      }
      break;
    case eDepthOff:
      if ( this->state.depthState != eDepthOff )
      {
        kglSetDepthState(2u);
        this->state.depthState = eDepthOff;
      }
      break;
    case eDepthLessEqual:
      if ( this->state.depthState != eDepthLessEqual )
      {
        kglSetDepthState(3u);
        this->state.depthState = eDepthLessEqual;
      }
      break;
    default:
      return;
  }
}
void GraphicsManager::setDepthTextureRT(GraphicsManager *this, unsigned int slot, RenderTarget *rt)
{
  if ( rt )
    kglSetTextureRT(slot, rt->kidDepth);
}
void GraphicsManager::setIB(GraphicsManager *this, IndexBuffer *ib)
{
  kglSetIndexBuffer(ib->kid);
}
void GraphicsManager::setProjectionMatrix(GraphicsManager *this, const mat44f *matrix)
{
  mat44f t; // [esp+8h] [ebp-40h] BYREF

  mat44f::mat44f(&t);
  t.M11 = matrix->M11;
  t.M12 = matrix->M21;
  t.M13 = matrix->M31;
  t.M14 = matrix->M41;
  t.M21 = matrix->M12;
  t.M22 = matrix->M22;
  t.M23 = matrix->M32;
  t.M24 = matrix->M42;
  t.M31 = matrix->M13;
  t.M32 = matrix->M23;
  t.M33 = matrix->M33;
  t.M34 = matrix->M43;
  t.M41 = matrix->M14;
  t.M42 = matrix->M24;
  t.M43 = matrix->M34;
  t.M44 = matrix->M44;
  CBuffer::set(&this->sysBuffers.cbCamera, &t.M11, 64, 64);
  *(__m128i *)&this->state.projectionMatrix.M11 = _mm_loadu_si128((const __m128i *)matrix);
  *(__m128i *)&this->state.projectionMatrix.M21 = _mm_loadu_si128((const __m128i *)&matrix->M21);
  *(__m128i *)&this->state.projectionMatrix.M31 = _mm_loadu_si128((const __m128i *)&matrix->M31);
  *(__m128i *)&this->state.projectionMatrix.M41 = _mm_loadu_si128((const __m128i *)&matrix->M41);
}
void GraphicsManager::setRenderTarget(GraphicsManager *this, RenderTarget *rt)
{
  void *v3; // eax
  KGLRenderTarget *v4; // esi
  KGLRenderTarget *v5; // eax

  if ( rt )
  {
    v3 = rt->kidColor;
    if ( v3 )
    {
      if ( rt->kidDepth )
        kglSetRenderTargets(v3, rt->kidDepth);
      else
        kglSetRenderTarget(rt->kidColor);
    }
    else
    {
      kglSetRenderTargets(0, rt->kidDepth);
    }
    if ( !this->suspendViewportUpdateOnSetRenderTarget )
      GraphicsManager::setViewport(this, 0, 0, rt->width, rt->height);
  }
  else
  {
    v4 = kglGetScreenRenderTarget();
    v5 = kglGetScreenDepthTarget();
    kglSetRenderTargets(v4, v5);
    if ( !this->suspendViewportUpdateOnSetRenderTarget )
      GraphicsManager::setViewport(this, 0, 0, this->videoSettings.width, this->videoSettings.height);
  }
}
void GraphicsManager::setSamplerState(GraphicsManager *this)
{
  kglSetSamplerPS(this->samplerStates.samplerAniso, 0);
  kglSetSamplerPS(this->samplerStates.samplerShadow, 1u);
  kglSetSamplerPS(this->samplerStates.samplerPoint, 2u);
  kglSetSamplerPS(this->samplerStates.samplerPointClamp, 4u);
  kglSetSamplerPS(this->samplerStates.samplerLinearShadow, 3u);
  kglSetSamplerPS(this->samplerStates.samplerLinearSimple, 5u);
}
void GraphicsManager::setScreenRenderTargets(GraphicsManager *this)
{
  KGLRenderTarget *v2; // esi
  KGLRenderTarget *v3; // eax
  int v4; // esi
  int v5; // edi
  float value; // [esp+1Ch] [ebp-8h] BYREF
  float v7; // [esp+20h] [ebp-4h] BYREF

  v2 = kglGetScreenRenderTarget();
  v3 = kglGetScreenDepthTarget();
  if ( this->videoSettings.aaSamples == 1 || !this->videoSettings.ppHDREnabled )
    kglSetRenderTargets(v2, v3);
  else
    kglSetRenderTargets(v2, 0);
  v4 = this->videoSettings.height;
  v5 = this->videoSettings.width;
  kglSetViewport(0.0, 0.0, (float)v5, (float)v4);
  value = 1.0 / (float)v5;
  v7 = 1.0 / (float)v4;
  CBuffer::set(&this->sysBuffers.cbLighting, &value, 84, 4);
  CBuffer::set(&this->sysBuffers.cbLighting, &v7, 88, 4);
  CBuffer::touch(&this->sysBuffers.cbLighting);
}
void GraphicsManager::setScreenSpaceMode(GraphicsManager *this)
{
  mat44f id; // [esp+1Ch] [ebp-80h] BYREF
  mat44f ortho; // [esp+5Ch] [ebp-40h] BYREF

  mat44f::mat44f(&id);
  mat44f::loadIdentity(&id);
  mat44f::createOrtho(&ortho, 0.0, (float)this->videoSettings.width, (float)this->videoSettings.height, 0.0, -1.0, 1.0);
  GraphicsManager::setProjectionMatrix(this, &ortho);
  GraphicsManager::setViewMatrix(this, &id, 0);
  GraphicsManager::setWorldMatrix(this, &id);
}
void GraphicsManager::setShader(GraphicsManager *this, Shader *sh)
{
  if ( sh != this->state.shader )
  {
    Shader::apply(sh);
    this->state.shader = sh;
  }
}
void GraphicsManager::setShadowMapBias(GraphicsManager *this, float b0, float b1, float b2)
{
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm2_4
  int v7; // eax
  float sb[3]; // [esp+0h] [ebp-10h] BYREF

  v4 = b0;
  v5 = b1;
  v6 = b2;
  v7 = this->videoSettings.shadowMapSize;
  sb[0] = b0;
  sb[1] = b1;
  sb[2] = b2;
  if ( v7 < 2040 )
  {
    v4 = b0 * 2.0;
    v5 = b1 * 2.0;
    v6 = b2 * 2.0;
    sb[0] = b0 * 2.0;
    sb[1] = b1 * 2.0;
    sb[2] = b2 * 2.0;
  }
  if ( v7 < 1020 )
  {
    sb[0] = v4 * 2.0;
    sb[1] = v5 * 2.0;
    sb[2] = v6 * 2.0;
  }
  CBuffer::set(&this->sysBuffers.cbShadowMap, sb, 192, 12);
}
void GraphicsManager::setShadowMapMatrix(GraphicsManager *this, int level, const mat44f *matrix)
{
  mat44f trm; // [esp+4h] [ebp-40h] BYREF

  mat44f::mat44f(&trm);
  trm.M11 = matrix->M11;
  trm.M12 = matrix->M21;
  trm.M13 = matrix->M31;
  trm.M14 = matrix->M41;
  trm.M21 = matrix->M12;
  trm.M22 = matrix->M22;
  trm.M23 = matrix->M32;
  trm.M24 = matrix->M42;
  trm.M31 = matrix->M13;
  trm.M32 = matrix->M23;
  trm.M33 = matrix->M33;
  trm.M34 = matrix->M43;
  trm.M41 = matrix->M14;
  trm.M42 = matrix->M24;
  trm.M43 = matrix->M34;
  trm.M44 = matrix->M44;
  if ( level )
  {
    if ( level == 1 )
    {
      CBuffer::set(&this->sysBuffers.cbShadowMap, &trm.M11, 64, 64);
    }
    else if ( level == 2 )
    {
      CBuffer::set(&this->sysBuffers.cbShadowMap, &trm.M11, 128, 64);
    }
  }
  else
  {
    CBuffer::set(&this->sysBuffers.cbShadowMap, &trm.M11, 0, 64);
  }
}
void GraphicsManager::setShadowMapTexture(GraphicsManager *this, int level, RenderTarget *rt)
{
  RenderTarget *v3; // esi

  v3 = rt;
  if ( rt )
  {
    kglSetTextureRT(level + 6, rt->kidDepth);
    *(float *)&level = 1.0 / (float)v3->width;
    CBuffer::set(&this->sysBuffers.cbShadowMap, (float *)&level, 204, 4);
  }
  else
  {
    kglSetTexture(level + 6, 0);
  }
}
void GraphicsManager::setTexture(GraphicsManager *this, int slot, const Texture *tex)
{
  void *v4; // eax

  v4 = tex->kid;
  if ( tex->kid )
  {
    if ( v4 != this->state.textures[slot] )
    {
      kglSetTexture(slot, tex->kid);
LABEL_6:
      v4 = tex->kid;
      goto LABEL_7;
    }
  }
  else if ( this->state.textures[slot] )
  {
    kglSetTexture(slot, 0);
    goto LABEL_6;
  }
LABEL_7:
  this->state.textures[slot] = v4;
}
void GraphicsManager::setTextureRT(GraphicsManager *this, unsigned int slot, RenderTarget *rt)
{
  if ( rt )
    kglSetTextureRT(slot, rt->kidColor);
}
void GraphicsManager::setVB(GraphicsManager *this, IVertexBuffer *vb)
{
  kglSetVertexBuffer(vb->kid);
}
void GraphicsManager::setViewMatrix(GraphicsManager *this, const mat44f *matrix, Camera *camera)
{
  SystemCBuffers *v3; // esi
  __int128 v4; // xmm1
  __int128 v5; // xmm2
  __int128 v6; // xmm3
  __m128 v7; // xmm0
  __m128 v8; // xmm1
  __m128 v9; // xmm2
  __m128 v10; // xmm3
  __m128 v11; // xmm0
  __m128 v12; // xmm1
  __m128 v13; // xmm2
  __m128 v14; // xmm3
  __m128 v15; // xmm4
  float value[4]; // [esp+10h] [ebp-110h] BYREF
  mat44f v18; // [esp+20h] [ebp-100h] BYREF
  mat44f v19; // [esp+60h] [ebp-C0h] BYREF
  __m128 v20; // [esp+A0h] [ebp-80h]
  __m128 v21; // [esp+B0h] [ebp-70h]
  __m128 v22; // [esp+C0h] [ebp-60h]
  mat44f v23; // [esp+D0h] [ebp-50h] BYREF
  __m128 pDeterminant; // [esp+110h] [ebp-10h] BYREF

  *(__m128i *)&this->state.viewMatrix.M11 = _mm_loadu_si128((const __m128i *)matrix);
  *(__m128i *)&this->state.viewMatrix.M21 = _mm_loadu_si128((const __m128i *)&matrix->M21);
  *(__m128i *)&this->state.viewMatrix.M31 = _mm_loadu_si128((const __m128i *)&matrix->M31);
  *(__m128i *)&this->state.viewMatrix.M41 = _mm_loadu_si128((const __m128i *)&matrix->M41);
  mat44f::mat44f(&v19);
  v19.M11 = matrix->M11;
  v19.M12 = matrix->M21;
  v19.M13 = matrix->M31;
  v19.M14 = matrix->M41;
  v19.M21 = matrix->M12;
  v19.M22 = matrix->M22;
  v19.M23 = matrix->M32;
  v19.M24 = matrix->M42;
  v19.M31 = matrix->M13;
  v19.M32 = matrix->M23;
  v19.M33 = matrix->M33;
  v19.M34 = matrix->M43;
  v19.M41 = matrix->M14;
  v19.M42 = matrix->M24;
  v19.M43 = matrix->M34;
  v3 = &this->sysBuffers;
  v19.M44 = matrix->M44;
  CBuffer::set(&this->sysBuffers.cbCamera, &v19.M11, 0, 64);
  if ( camera )
  {
    value[0] = camera->matrix.M41;
    value[1] = camera->matrix.M42;
    value[2] = camera->matrix.M43;
    CBuffer::set(&v3->cbCamera, value, 192, 12);
    CBuffer::set(&v3->cbCamera, &camera->nearPlane, 208, 4);
    CBuffer::set(&v3->cbCamera, &camera->farPlane, 212, 4);
    CBuffer::set(&v3->cbCamera, &camera->fov, 216, 4);
  }
  mat44f::mat44f(&v23);
  v4 = *(_OWORD *)&this->state.projectionMatrix.M21;
  v5 = *(_OWORD *)&this->state.projectionMatrix.M31;
  v6 = *(_OWORD *)&this->state.projectionMatrix.M41;
  *(_OWORD *)&v23.M11 = *(_OWORD *)&this->state.projectionMatrix.M11;
  v7 = *(__m128 *)&this->state.viewMatrix.M11;
  *(_OWORD *)&v23.M21 = v4;
  v8 = *(__m128 *)&this->state.viewMatrix.M21;
  *(_OWORD *)&v23.M31 = v5;
  v9 = *(__m128 *)&this->state.viewMatrix.M31;
  *(_OWORD *)&v23.M41 = v6;
  v10 = *(__m128 *)&this->state.viewMatrix.M41;
  v11 = DirectX::XMMatrixMultiply((__m128 *)&v23, v7);
  v20 = v10;
  v21 = v9;
  v22 = v8;
  *(__m128 *)value = v11;
  mat44f::mat44f(&v18);
  mat44f::mat44f(&v23);
  v12 = v22;
  v13 = v21;
  v14 = v20;
  v15 = DirectX::XMMatrixInverse(&pDeterminant, *(__m128 *)value, v22, v21, v20);
  LODWORD(v18.M12) = v12.m128_i32[0];
  LODWORD(v18.M21) = _mm_shuffle_ps(v15, v15, 85).m128_u32[0];
  LODWORD(v18.M11) = v15.m128_i32[0];
  LODWORD(v18.M22) = _mm_shuffle_ps(v12, v12, 85).m128_u32[0];
  LODWORD(v18.M23) = _mm_shuffle_ps(v13, v13, 85).m128_u32[0];
  LODWORD(v18.M24) = _mm_shuffle_ps(v14, v14, 85).m128_u32[0];
  LODWORD(v18.M31) = _mm_shuffle_ps(v15, v15, 170).m128_u32[0];
  LODWORD(v18.M32) = _mm_shuffle_ps(v12, v12, 170).m128_u32[0];
  LODWORD(v18.M33) = _mm_shuffle_ps(v13, v13, 170).m128_u32[0];
  LODWORD(v18.M13) = v13.m128_i32[0];
  LODWORD(v18.M14) = v14.m128_i32[0];
  LODWORD(v18.M34) = _mm_shuffle_ps(v14, v14, 170).m128_u32[0];
  LODWORD(v18.M41) = _mm_shuffle_ps(v15, v15, 255).m128_u32[0];
  LODWORD(v18.M42) = _mm_shuffle_ps(v12, v12, 255).m128_u32[0];
  LODWORD(v18.M43) = _mm_shuffle_ps(v13, v13, 255).m128_u32[0];
  LODWORD(v18.M44) = _mm_shuffle_ps(v14, v14, 255).m128_u32[0];
  CBuffer::set(&v3->cbCamera, &v18.M11, 128, 64);
}
void GraphicsManager::setViewport(GraphicsManager *this, int left, int top, int width, int height)
{
  kglSetViewport((float)left, (float)top, (float)width, (float)height);
  this = (GraphicsManager *)((char *)this + 812);
  *(float *)&top = 1.0 / (float)width;
  *(float *)&left = 1.0 / (float)height;
  CBuffer::set((CBuffer *)this, (float *)&top, 84, 4);
  CBuffer::set((CBuffer *)this, (float *)&left, 88, 4);
  CBuffer::touch((CBuffer *)this);
}
void GraphicsManager::setWorldMatrix(GraphicsManager *this, const mat44f *matrix)
{
  mat44f trm; // [esp+8h] [ebp-40h] BYREF

  *(__m128i *)&this->state.worldMatrix.M11 = _mm_loadu_si128((const __m128i *)matrix);
  *(__m128i *)&this->state.worldMatrix.M21 = _mm_loadu_si128((const __m128i *)&matrix->M21);
  *(__m128i *)&this->state.worldMatrix.M31 = _mm_loadu_si128((const __m128i *)&matrix->M31);
  *(__m128i *)&this->state.worldMatrix.M41 = _mm_loadu_si128((const __m128i *)&matrix->M41);
  mat44f::mat44f(&trm);
  trm.M11 = matrix->M11;
  trm.M12 = matrix->M21;
  trm.M13 = matrix->M31;
  trm.M14 = matrix->M41;
  trm.M21 = matrix->M12;
  trm.M22 = matrix->M22;
  trm.M23 = matrix->M32;
  trm.M24 = matrix->M42;
  trm.M31 = matrix->M13;
  trm.M32 = matrix->M23;
  trm.M33 = matrix->M33;
  trm.M34 = matrix->M43;
  trm.M41 = matrix->M14;
  trm.M42 = matrix->M24;
  trm.M43 = matrix->M34;
  trm.M44 = matrix->M44;
  CBuffer::set(&this->sysBuffers.cbPerObject, &trm.M11, 0, 64);
}
void GraphicsManager::updateLightingSetttings(GraphicsManager *this)
{
  float v2; // eax
  float v3; // xmm0_4
  float v4; // xmm3_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm2_4
  float v8; // xmm2_4
  float v9; // xmm5_4
  __int128 v10; // xmm3
  __int128 v11; // xmm1
  __int128 v12; // xmm2
  __m128 v13; // xmm0
  float v14; // xmm2_4
  float v15; // xmm2_4
  float v16; // xmm7_4
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  __m128 v19; // xmm6
  __m128 v20; // xmm4
  __m128 v21; // xmm1
  unsigned __int64 v22; // xmm2_8
  float v23; // ecx
  float v24; // xmm0_4
  int v25; // ecx
  float v26; // xmm6_4
  float v27; // xmm5_4
  float v28; // xmm2_4
  float v29; // xmm3_4
  float v30; // xmm0_4
  float v31; // xmm1_4
  float v32; // xmm4_4
  float v33; // xmm2_4
  float v34; // xmm4_4
  float v35; // xmm5_4
  float v36; // xmm2_4
  float v37; // xmm3_4
  float v38; // xmm0_4
  float v39; // xmm1_4
  float v40; // xmm4_4
  float v41; // xmm2_4
  float v42; // xmm4_4
  float v43; // xmm2_4
  float v44; // [esp+Ch] [ebp-F4h]
  float v45; // [esp+Ch] [ebp-F4h]
  float v46; // [esp+Ch] [ebp-F4h]
  float v47; // [esp+Ch] [ebp-F4h]
  float v48; // [esp+10h] [ebp-F0h]
  float v49; // [esp+10h] [ebp-F0h]
  float v50; // [esp+10h] [ebp-F0h]
  float v51; // [esp+14h] [ebp-ECh]
  float v52; // [esp+14h] [ebp-ECh]
  float v53; // [esp+14h] [ebp-ECh]
  float v54; // [esp+18h] [ebp-E8h]
  float v55; // [esp+18h] [ebp-E8h]
  float v56; // [esp+1Ch] [ebp-E4h]
  float v57; // [esp+1Ch] [ebp-E4h]
  float v58; // [esp+20h] [ebp-E0h]
  float v59; // [esp+20h] [ebp-E0h]
  float v60[2]; // [esp+24h] [ebp-DCh] BYREF
  float v61; // [esp+2Ch] [ebp-D4h]
  mat44f v62; // [esp+30h] [ebp-D0h] BYREF
  float v63[4]; // [esp+70h] [ebp-90h] BYREF
  float v64[4]; // [esp+80h] [ebp-80h] BYREF
  mat44f v65; // [esp+90h] [ebp-70h] BYREF
  float value[4]; // [esp+D0h] [ebp-30h] BYREF
  __m128 v67; // [esp+E0h] [ebp-20h] BYREF

  if ( this->useCustomSunDirection )
  {
    v2 = this->customSunDirection.z;
    *(_QWORD *)&this->lightingSettings.lightDirection.x = *(_QWORD *)&this->customSunDirection.x;
    this->lightingSettings.lightDirection.z = v2;
  }
  else
  {
    v51 = __libm_sse2_cosf().m128_f32[0];
    v3 = __libm_sse2_sinf().m128_f32[0];
    v44 = 1.0 - v51;
    mat44f::mat44f(&v62);
    v4 = v3;
    v62.M44 = 1.0;
    v5 = v3 * 0.0;
    v62.M11 = (float)(1.0 - v51) + v51;
    v6 = (float)((float)(1.0 - v51) * 0.0) + v51;
    v52 = 0.0;
    v54 = 0.0;
    v62.M22 = v6;
    v62.M33 = v6;
    v62.M12 = v5 + (float)(v44 * 0.0);
    v62.M21 = (float)(v44 * 0.0) - v5;
    v62.M13 = v62.M21;
    v62.M31 = v62.M12;
    v62.M23 = v4 + (float)(v44 * 0.0);
    v62.M32 = (float)(v44 * 0.0) - v4;
    v7 = fsqrt(1.0);
    v45 = FLOAT_1_0;
    if ( v7 != 0.0 )
    {
      v45 = 1.0 / v7;
      v52 = (float)(1.0 / v7) * 0.0;
      v54 = v52;
    }
    v58 = __libm_sse2_cosf().m128_f32[0];
    v48 = __libm_sse2_sinf().m128_f32[0];
    mat44f::mat44f(&v65);
    v65.M44 = 1.0;
    v8 = (float)(v54 * v52) * (float)(1.0 - v58);
    v65.M11 = (float)((float)(v52 * v52) * (float)(1.0 - v58)) + v58;
    v65.M22 = (float)((float)(v54 * v54) * (float)(1.0 - v58)) + v58;
    v65.M33 = (float)((float)(v45 * v45) * (float)(1.0 - v58)) + v58;
    v65.M12 = (float)(v45 * v48) + v8;
    v65.M21 = v8 - (float)(v45 * v48);
    v9 = (float)(v45 * v54) * (float)(1.0 - v58);
    v10 = *(_OWORD *)&v62.M41;
    v65.M13 = (float)((float)(v45 * v52) * (float)(1.0 - v58)) - (float)(v54 * v48);
    v65.M31 = (float)(v54 * v48) + (float)((float)(v45 * v52) * (float)(1.0 - v58));
    v65.M23 = (float)(v52 * v48) + v9;
    v65.M32 = v9 - (float)(v52 * v48);
    v11 = *(_OWORD *)&v62.M21;
    v12 = *(_OWORD *)&v62.M31;
    v13 = DirectX::XMMatrixMultiply((__m128 *)&v65, *(__m128 *)&v62.M11);
    *(_OWORD *)v64 = v10;
    *(_OWORD *)v63 = v12;
    *(_OWORD *)value = v11;
    v67 = v13;
    v53 = 0.0;
    v46 = 0.0;
    v14 = fsqrt(1.0);
    v59 = FLOAT_1_0;
    if ( v14 != 0.0 )
    {
      v59 = 1.0 / v14;
      v46 = (float)(1.0 / v14) * 0.0;
      v53 = v46;
    }
    v55 = __libm_sse2_cosf().m128_f32[0];
    v56 = __libm_sse2_sinf().m128_f32[0];
    mat44f::mat44f(&v62);
    v62.M44 = 1.0;
    v15 = (float)(v59 * v46) * (float)(1.0 - v55);
    v62.M11 = (float)((float)(v46 * v46) * (float)(1.0 - v55)) + v55;
    v62.M22 = (float)((float)(v59 * v59) * (float)(1.0 - v55)) + v55;
    v62.M33 = (float)((float)(v53 * v53) * (float)(1.0 - v55)) + v55;
    v62.M12 = (float)(v53 * v56) + v15;
    v62.M21 = v15 - (float)(v53 * v56);
    v16 = (float)(v53 * v59) * (float)(1.0 - v55);
    v17 = *(__m128 *)v64;
    v62.M13 = (float)((float)(v53 * v46) * (float)(1.0 - v55)) - (float)(v59 * v56);
    v62.M31 = (float)(v59 * v56) + (float)((float)(v53 * v46) * (float)(1.0 - v55));
    v62.M23 = (float)(v46 * v56) + v16;
    v62.M32 = v16 - (float)(v46 * v56);
    v18 = *(__m128 *)v63;
    v19 = *(__m128 *)value;
    v20 = DirectX::XMMatrixMultiply((__m128 *)&v62, v67);
    v49 = (float)((float)((float)(v19.m128_f32[0] * -1.0) + (float)(v20.m128_f32[0] * 0.0))
                + (float)(v18.m128_f32[0] * 0.0))
        + v17.m128_f32[0];
    v21 = _mm_shuffle_ps(v20, v20, 85);
    v21.m128_f32[0] = (float)((float)((float)(v21.m128_f32[0] * 0.0)
                                    + (float)(_mm_shuffle_ps(v19, v19, 85).m128_f32[0] * -1.0))
                            + (float)(_mm_shuffle_ps(v18, v18, 85).m128_f32[0] * 0.0))
                    + _mm_shuffle_ps(v17, v17, 85).m128_f32[0];
    v19.m128_f32[0] = (float)((float)((float)(_mm_shuffle_ps(v19, v19, 170).m128_f32[0] * -1.0)
                                    + (float)(_mm_shuffle_ps(v20, v20, 170).m128_f32[0] * 0.0))
                            + (float)(_mm_shuffle_ps(v18, v18, 170).m128_f32[0] * 0.0))
                    + _mm_shuffle_ps(v17, v17, 170).m128_f32[0];
    v22 = _mm_unpacklo_ps((__m128)LODWORD(v49), v21).m128_u64[0];
    v63[2] = v19.m128_f32[0];
    v23 = v19.m128_f32[0];
    *(_QWORD *)v60 = v22;
    v61 = v19.m128_f32[0];
    v24 = fsqrt(
            (float)((float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v49 * v49))
          + (float)(v19.m128_f32[0] * v19.m128_f32[0]));
    if ( v24 != 0.0 )
    {
      v60[0] = (float)(1.0 / v24) * v49;
      v60[1] = v60[1] * (float)(1.0 / v24);
      v22 = *(_QWORD *)v60;
      v61 = v61 * (float)(1.0 / v24);
      v23 = v61;
    }
    *(_QWORD *)&this->lightingSettings.lightDirection.x = v22;
    this->lightingSettings.lightDirection.z = v23;
  }
  value[0] = this->lightingSettings.lightDirection.x;
  value[1] = this->lightingSettings.lightDirection.y;
  value[2] = this->lightingSettings.lightDirection.z;
  value[3] = 0.0;
  CBuffer::set(&this->sysBuffers.cbLighting, value, 0, 16);
  v26 = __libm_sse2_powf(v25).m128_f32[0];
  v27 = this->lightingSettings.skyHigh.x;
  v28 = (float)((float)(this->lightingSettings.horizonLow.y - this->lightingSettings.horizonHigh.y) * v26)
      + this->lightingSettings.horizonHigh.y;
  v29 = this->lightingSettings.skyHigh.y;
  v30 = (float)((float)(this->lightingSettings.horizonLow.z - this->lightingSettings.horizonHigh.z) * v26)
      + this->lightingSettings.horizonHigh.z;
  v31 = this->lightingSettings.skyHigh.z;
  v64[0] = (float)((float)(this->lightingSettings.horizonLow.x - this->lightingSettings.horizonHigh.x) * v26)
         + this->lightingSettings.horizonHigh.x;
  v32 = this->lightingSettings.skyLow.x - v27;
  v64[1] = v28;
  v33 = this->lightingSettings.skyLow.y;
  v64[2] = v30;
  v34 = (float)(v32 * v26) + v27;
  v35 = this->lightingSettings.sunLow.x;
  v36 = (float)((float)(v33 - v29) * v26) + v29;
  v37 = this->lightingSettings.sunLow.z;
  v38 = (float)((float)(this->lightingSettings.skyLow.z - v31) * v26) + v31;
  v39 = this->lightingSettings.sunHigh.y;
  v63[0] = v34;
  v40 = this->lightingSettings.sunLow.y;
  v63[1] = v36;
  v41 = this->lightingSettings.sunHigh.x;
  v63[2] = v38;
  v57 = (float)((float)(v40 - v39) * v26) + v39;
  v50 = (float)((float)(v35 - v41) * v26) + v41;
  v47 = (float)((float)(v37 - this->lightingSettings.sunHigh.z) * v26) + this->lightingSettings.sunHigh.z;
  v42 = (float)((float)(this->lightingSettings.ambientLow.x - this->lightingSettings.ambientHigh.x) * v26)
      + this->lightingSettings.ambientHigh.x;
  v43 = (float)((float)(this->lightingSettings.ambientLow.y - this->lightingSettings.ambientHigh.y) * v26)
      + this->lightingSettings.ambientHigh.y;
  v61 = (float)((float)(this->lightingSettings.ambientLow.z - this->lightingSettings.ambientHigh.z) * v26)
      + this->lightingSettings.ambientHigh.z;
  v60[0] = v42;
  v60[1] = v43;
  CBuffer::set(&this->sysBuffers.cbLighting, v60, 16, 12);
  v67.m128_f32[0] = v50;
  v67.m128_f32[1] = v57;
  v67.m128_f32[2] = v47;
  v67.m128_i32[3] = 0;
  CBuffer::set(&this->sysBuffers.cbLighting, v67.m128_f32, 32, 16);
  CBuffer::set(&this->sysBuffers.cbLighting, v64, 48, 12);
  CBuffer::set(&this->sysBuffers.cbLighting, v63, 64, 12);
  CBuffer::set(&this->sysBuffers.cbLighting, &this->lightingSettings.fogLinear, 92, 4);
  CBuffer::set(&this->sysBuffers.cbLighting, &this->lightingSettings.fogBlend, 96, 4);
  CBuffer::set(&this->sysBuffers.cbLighting, &this->lightingSettings.fogColor.x, 100, 12);
  CBuffer::set(&this->sysBuffers.cbLighting, &this->lightingSettings.cloudCover, 112, 4);
  CBuffer::set(&this->sysBuffers.cbLighting, &this->lightingSettings.cloudCutoff, 116, 4);
  CBuffer::set(&this->sysBuffers.cbLighting, &this->lightingSettings.cloudColor, 120, 4);
  CBuffer::set(&this->sysBuffers.cbLighting, &this->lightingSettings.cloudOffset, 124, 4);
  CBuffer::set(&this->sysBuffers.cbLighting, &this->lightingSettings.saturation, 144, 4);
  CBuffer::set(&this->sysBuffers.cbLighting, &this->lightingSettings.gameTime, 148, 4);
}
