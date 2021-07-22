#include "hdr.h
void __userpurge HDR::HDR(HDR *this@<ecx>, unsigned int a2@<ebx>, GraphicsManager *graphics)
{
  Shader *v4; // eax
  bool v5; // cf
  Shader *v6; // eax
  Shader *v7; // eax
  Shader *v8; // eax
  Shader *v9; // eax
  Shader *v10; // eax
  Shader *v11; // eax
  Shader *v12; // ecx
  ShaderVariable *v13; // eax
  Shader *v14; // ecx
  ShaderVariable *v15; // eax
  Shader *v16; // ecx
  ShaderVariable *v17; // eax
  Shader *v18; // ecx
  ShaderVariable *v19; // eax
  RenderTarget *v20; // eax
  RenderTarget *v21; // eax
  RenderTarget *v22; // eax
  RenderTarget *v23; // eax
  RenderTarget *v24; // eax
  RenderTarget *v25; // eax
  Shader *v26; // eax
  RenderTarget *v27; // eax
  RenderTarget *v28; // eax
  int v29; // eax
  unsigned int v30; // ecx
  unsigned int v31; // ecx
  float v32; // xmm0_4
  RenderTarget *v33; // eax
  RenderTarget *v34; // eax
  RenderTarget *v35; // eax
  RenderTarget *v36; // eax
  RenderTarget *v37; // eax
  RenderTarget *v38; // eax
  RenderTarget *v39; // eax
  RenderTarget *v40; // eax
  RenderTarget *v41; // eax
  RenderTarget *v42; // eax
  RenderTarget *v43; // eax
  RenderTarget *v44; // eax
  RenderTarget *v45; // eax
  RenderTarget *v46; // eax
  RenderTarget *v47; // eax
  double v48; // st7
  double v49; // st7
  double v50; // st7
  int v51; // eax
  int iheight; // [esp+10h] [ebp-B8h]
  int iwidth; // [esp+18h] [ebp-B0h]
  INIReader v54; // [esp+1Ch] [ebp-ACh] BYREF
  std::wstring key; // [esp+60h] [ebp-68h] BYREF
  std::wstring section; // [esp+78h] [ebp-50h] BYREF
  std::wstring name; // [esp+90h] [ebp-38h] BYREF
  float color[4]; // [esp+A8h] [ebp-20h] BYREF
  int v59; // [esp+C4h] [ebp-4h]

  this->__vftable = (HDR_vtbl *)&HDR::`vftable';
  this->graphics = graphics;
  this->frameCount = 0;
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksPostAdaptLum", 0xEu);
  v59 = 0;
  v4 = GraphicsManager::getShader(graphics, a2, &name);
  v5 = name._Myres < 8;
  this->lumaAdapterShader = v4;
  v59 = -1;
  if ( !v5 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksPostCopyLuma", 0xEu);
  v59 = 1;
  v6 = GraphicsManager::getShader(graphics, a2, &name);
  v5 = name._Myres < 8;
  this->shPostCopyLuma = v6;
  v59 = -1;
  if ( !v5 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksPostCopy", 0xAu);
  v59 = 2;
  v7 = GraphicsManager::getShader(graphics, a2, &name);
  v5 = name._Myres < 8;
  this->shPostCopy = v7;
  v59 = -1;
  if ( !v5 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksHighPass", 0xAu);
  v59 = 3;
  v8 = GraphicsManager::getShader(graphics, a2, &name);
  v5 = name._Myres < 8;
  this->shHighPass = v8;
  v59 = -1;
  if ( !v5 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksPostBlurH", 0xBu);
  v59 = 4;
  v9 = GraphicsManager::getShader(graphics, a2, &name);
  v5 = name._Myres < 8;
  this->shPostBlurH = v9;
  v59 = -1;
  if ( !v5 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksPostBlurV", 0xBu);
  v59 = 5;
  v10 = GraphicsManager::getShader(graphics, a2, &name);
  v5 = name._Myres < 8;
  this->shPostBlurV = v10;
  v59 = -1;
  if ( !v5 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksPostToneMap", 0xDu);
  v59 = 6;
  v11 = GraphicsManager::getShader(graphics, a2, &name);
  v5 = name._Myres < 8;
  this->shPostToneMap = v11;
  v59 = -1;
  if ( !v5 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"deltaT", 6u);
  v12 = this->lumaAdapterShader;
  v59 = 7;
  v13 = Shader::getVar(v12, &name);
  v5 = name._Myres < 8;
  this->svDeltaT = v13;
  v59 = -1;
  if ( !v5 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"threshold", 9u);
  v14 = this->shHighPass;
  v59 = 8;
  v15 = Shader::getVar(v14, &name);
  v5 = name._Myres < 8;
  this->svHighPassThreshold = v15;
  v59 = -1;
  if ( !v5 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"bloomLevel", 0xAu);
  v16 = this->shPostToneMap;
  v59 = 9;
  v17 = Shader::getVar(v16, &name);
  v5 = name._Myres < 8;
  this->svBloomLevel = v17;
  v59 = -1;
  if ( !v5 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"baseLevel", 9u);
  v18 = this->shPostToneMap;
  v59 = 10;
  v19 = Shader::getVar(v18, &name);
  v5 = name._Myres < 8;
  this->svBloomBaseLevel = v19;
  v59 = -1;
  if ( !v5 )
    operator delete(name._Bx._Ptr);
  this->bloomBaseLevel = 1.0;
  this->bloomLevel = 1.0;
  this->blurIterations = 4;
  if ( graphics->videoSettings.aaSamples == 1 )
  {
    this->hdrRenderTarget = 0;
    v20 = (RenderTarget *)operator new(28);
    v59 = 11;
    if ( v20 )
      RenderTarget::RenderTarget(
        v20,
        graphics,
        eR16G16B16A16,
        graphics->videoSettings.width,
        graphics->videoSettings.height,
        1,
        1,
        1);
    else
      v21 = 0;
    this->hdrRenderTargetNOMS = v21;
    this->hdrRenderTarget = v21;
    v59 = -1;
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"ksPostFOG", 9u);
    v59 = 12;
  }
  else
  {
    v22 = (RenderTarget *)operator new(28);
    v59 = 13;
    if ( v22 )
      RenderTarget::RenderTarget(
        v22,
        graphics,
        eR16G16B16A16_MS,
        graphics->videoSettings.width,
        graphics->videoSettings.height,
        1,
        1,
        1);
    else
      v23 = 0;
    v59 = -1;
    this->hdrRenderTarget = v23;
    v24 = (RenderTarget *)operator new(28);
    v59 = 14;
    if ( v24 )
      RenderTarget::RenderTarget(
        v24,
        graphics,
        eR16G16B16A16,
        graphics->videoSettings.width,
        graphics->videoSettings.height,
        1,
        1,
        1);
    else
      v25 = 0;
    this->hdrRenderTargetNOMS = v25;
    v59 = -1;
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"ksPostFOG_MS", 0xCu);
    v59 = 15;
  }
  v26 = GraphicsManager::getShader(graphics, a2, &name);
  v5 = name._Myres < 8;
  v59 = -1;
  this->shPostFOG = v26;
  if ( !v5 )
    operator delete(name._Bx._Ptr);
  v27 = (RenderTarget *)operator new(28);
  v59 = 16;
  if ( v27 )
    RenderTarget::RenderTarget(
      v27,
      graphics,
      eR16G16B16A16,
      graphics->videoSettings.width,
      graphics->videoSettings.height,
      1,
      0,
      5);
  else
    v28 = 0;
  this->hdrRenderTargetNOMS_FOG = v28;
  v29 = 0;
  v59 = -1;
  do
  {
    v30 = v29;
    if ( v29 < 0 )
      v30 = -v29;
    ++v29;
    v31 = v30 >> 1;
  }
  while ( v29 < 5 );
  v32 = __libm_sse2_powf(v31).m128_f32[0];
  iwidth = (int)(float)((float)graphics->videoSettings.width / v32);
  iheight = (int)(float)((float)graphics->videoSettings.height / v32);
  v33 = (RenderTarget *)operator new(28);
  v59 = 17;
  if ( v33 )
    RenderTarget::RenderTarget(v33, graphics, eR8G8B8A8, iwidth, iheight, 1, 0, 1);
  else
    v34 = 0;
  v59 = -1;
  this->rtDownsampled = v34;
  v35 = (RenderTarget *)operator new(28);
  v59 = 18;
  if ( v35 )
    RenderTarget::RenderTarget(v35, graphics, eR8G8B8A8, iwidth, iheight, 1, 0, 1);
  else
    v36 = 0;
  v59 = -1;
  this->rtBlurH = v36;
  v37 = (RenderTarget *)operator new(28);
  v59 = 19;
  if ( v37 )
    RenderTarget::RenderTarget(v37, graphics, eR8G8B8A8, iwidth, iheight, 1, 0, 1);
  else
    v38 = 0;
  v59 = -1;
  this->rtBlurV = v38;
  v39 = (RenderTarget *)operator new(28);
  v59 = 20;
  if ( v39 )
    RenderTarget::RenderTarget(v39, graphics, eR16F, 0x200u, 0x200u, 1, 0, 10);
  else
    v40 = 0;
  v59 = -1;
  this->rtDownsampledLuma = v40;
  v41 = (RenderTarget *)operator new(28);
  v59 = 21;
  if ( v41 )
    RenderTarget::RenderTarget(v41, graphics, eR16F, 1u, 1u, 1, 0, 1);
  else
    v42 = 0;
  v59 = -1;
  this->rtAdaptedLum = v42;
  v43 = (RenderTarget *)operator new(28);
  v59 = 22;
  if ( v43 )
    RenderTarget::RenderTarget(v43, graphics, eR16F, 1u, 1u, 1, 0, 1);
  else
    v44 = 0;
  v59 = -1;
  this->rtAdaptedLumLast[0] = v44;
  v45 = (RenderTarget *)operator new(28);
  v59 = 23;
  if ( v45 )
    RenderTarget::RenderTarget(v45, graphics, eR16F, 1u, 1u, 1, 0, 1);
  else
    v46 = 0;
  this->rtAdaptedLumLast[1] = v46;
  v47 = this->rtAdaptedLum;
  *(_OWORD *)color = 0i64;
  v59 = -1;
  kglRenderTargetClear(v47->kidColor, color, 0.0);
  kglRenderTargetClear(this->rtAdaptedLumLast[0]->kidColor, color, 0.0);
  kglRenderTargetClear(this->rtAdaptedLumLast[1]->kidColor, color, 0.0);
  this->highPassLevel = 0.89999998;
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"system/cfg/hdr.ini", 0x12u);
  v59 = 24;
  INIReader::INIReader(&v54, &name);
  LOBYTE(v59) = 26;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  if ( v54.ready )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"HIGH_PASS_LEVEL", 0xFu);
    LOBYTE(v59) = 27;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HDR", 3u);
    LOBYTE(v59) = 28;
    v48 = INIReader::getFloat(&v54, &section, &key);
    v5 = section._Myres < 8;
    this->highPassLevel = v48;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v59) = 26;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"BLOOM_BASE", 0xAu);
    LOBYTE(v59) = 29;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HDR", 3u);
    LOBYTE(v59) = 30;
    v49 = INIReader::getFloat(&v54, &section, &key);
    v5 = section._Myres < 8;
    this->bloomBaseLevel = v49;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v59) = 26;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"BLOOM_LEVEL", 0xBu);
    LOBYTE(v59) = 31;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HDR", 3u);
    LOBYTE(v59) = 32;
    v50 = INIReader::getFloat(&v54, &section, &key);
    v5 = section._Myres < 8;
    this->bloomLevel = v50;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    LOBYTE(v59) = 26;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"BLUR_ITERATIONS", 0xFu);
    LOBYTE(v59) = 33;
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"HDR", 3u);
    LOBYTE(v59) = 34;
    v51 = INIReader::getInt(&v54, &section, &key);
    v5 = section._Myres < 8;
    this->blurIterations = v51;
    if ( !v5 )
      operator delete(section._Bx._Ptr);
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
  }
  v59 = -1;
  INIReader::~INIReader(&v54);
}
void HDR::~HDR(HDR *this)
{
  RenderTarget *v2; // ecx
  RenderTarget *v3; // ecx
  RenderTarget *v4; // ecx
  RenderTarget *v5; // ecx
  RenderTarget *v6; // ecx
  RenderTarget *v7; // ecx
  RenderTarget *v8; // ecx
  RenderTarget *v9; // ecx
  RenderTarget *v10; // ecx
  RenderTarget *v11; // ecx

  v2 = this->hdrRenderTargetNOMS;
  this->__vftable = (HDR_vtbl *)&HDR::`vftable';
  if ( v2 )
    ((void (*)(RenderTarget *, int))v2->~RenderTarget)(v2, 1);
  if ( this->graphics->videoSettings.aaSamples != 1 )
  {
    v3 = this->hdrRenderTarget;
    if ( v3 )
      ((void (*)(RenderTarget *, int))v3->~RenderTarget)(v3, 1);
  }
  v4 = this->hdrRenderTargetNOMS_FOG;
  if ( v4 )
    ((void (*)(RenderTarget *, int))v4->~RenderTarget)(v4, 1);
  v5 = this->rtDownsampled;
  if ( v5 )
    ((void (*)(RenderTarget *, int))v5->~RenderTarget)(v5, 1);
  v6 = this->rtBlurH;
  if ( v6 )
    ((void (*)(RenderTarget *, int))v6->~RenderTarget)(v6, 1);
  v7 = this->rtBlurV;
  if ( v7 )
    ((void (*)(RenderTarget *, int))v7->~RenderTarget)(v7, 1);
  v8 = this->rtDownsampledLuma;
  if ( v8 )
    ((void (*)(RenderTarget *, int))v8->~RenderTarget)(v8, 1);
  v9 = this->rtAdaptedLum;
  if ( v9 )
    ((void (*)(RenderTarget *, int))v9->~RenderTarget)(v9, 1);
  v10 = this->rtAdaptedLumLast[0];
  if ( v10 )
    ((void (*)(RenderTarget *, int))v10->~RenderTarget)(v10, 1);
  v11 = this->rtAdaptedLumLast[1];
  if ( v11 )
    ((void (*)(RenderTarget *, int))v11->~RenderTarget)(v11, 1);
}
HDR *HDR::`vector deleting destructor'(HDR *this, unsigned int a2)
{
  HDR::~HDR(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void HDR::begin(HDR *this)
{
  kglSetRenderTargets(this->hdrRenderTarget->kidColor, this->hdrRenderTarget->kidDepth);
  GraphicsManager::setViewport(
    this->graphics,
    0,
    0,
    this->graphics->videoSettings.width,
    this->graphics->videoSettings.height);
  GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
  RenderTarget::clear(this->hdrRenderTargetNOMS);
  RenderTarget::clear(this->hdrRenderTargetNOMS_FOG);
  RenderTarget::clear(this->rtDownsampledLuma);
  RenderTarget::clear(this->rtDownsampled);
  RenderTarget::clear(this->rtBlurV);
  RenderTarget::clear(this->rtBlurH);
  RenderTarget::clear(this->rtAdaptedLum);
}
void HDR::reset(HDR *this)
{
  RenderTarget::clear(this->rtAdaptedLumLast[0]);
  RenderTarget::clear(this->rtAdaptedLumLast[1]);
}
