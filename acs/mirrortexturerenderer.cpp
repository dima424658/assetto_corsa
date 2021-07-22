#include "mirrortexturerenderer.h"
void __userpurge MirrorTextureRenderer::MirrorTextureRenderer(MirrorTextureRenderer *this@<ecx>, unsigned int a2@<ebx>, Sim *sim)
{
  int v4; // eax
  bool v5; // cf
  signed int v6; // edi
  int v7; // ebx
  RenderTarget *v8; // ecx
  RenderTarget *v9; // eax
  RenderTarget *v10; // ecx
  RenderTarget *v11; // eax
  RenderTarget *v12; // ecx
  RenderTarget *v13; // eax
  int v14; // eax
  CameraMirror *v15; // edi
  CameraMirror *v16; // eax
  Game *v17; // eax
  bool v18; // zf
  CameraForward *v19; // eax
  CameraMirror *v20; // ecx
  CameraMirror *v21; // eax
  char v22; // al
  int v23; // eax
  std::wstring v24; // [esp-1Ch] [ebp-16Ch] BYREF
  unsigned int v25; // [esp-4h] [ebp-154h]
  char v26; // [esp+17h] [ebp-139h]
  void *v27; // [esp+18h] [ebp-138h]
  int v28; // [esp+1Ch] [ebp-134h]
  int v29; // [esp+20h] [ebp-130h]
  MirrorTextureRenderer *v30; // [esp+24h] [ebp-12Ch]
  std::wstring key; // [esp+28h] [ebp-128h] BYREF
  std::wstring section; // [esp+40h] [ebp-110h] BYREF
  Texture v33; // [esp+58h] [ebp-F8h] BYREF
  INIReader acini; // [esp+74h] [ebp-DCh] BYREF
  INIReaderDocuments videoINI; // [esp+B8h] [ebp-98h] BYREF
  INIReaderDocuments ini; // [esp+FCh] [ebp-54h] BYREF
  int v37; // [esp+14Ch] [ebp-4h]

  v29 = 0;
  this->texture.kid = 0;
  this->texture.fileName._Myres = 7;
  this->texture.fileName._Mysize = 0;
  v30 = this;
  this->texture.fileName._Bx._Buf[0] = 0;
  v25 = 0;
  *(_WORD *)&this->renderSmoke = 0;
  *(_WORD *)&this->rendering = 0;
  this->camera = 0;
  this->ghostCar = 0;
  this->renderTargetMS = 0;
  this->renderTargetNormal = 0;
  this->nullShadowRenderTarget = 0;
  v37 = 0;
  this->sim = sim;
  v24._Myres = 7;
  v24._Mysize = 0;
  v24._Bx._Buf[0] = 0;
  std::wstring::assign(&v24, L"cfg/video.ini", 0xDu);
  INIReaderDocuments::INIReaderDocuments(&ini, a2, v24, v25);
  LOBYTE(v37) = 1;
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"HQ", 2u);
  LOBYTE(v37) = 2;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"MIRROR", 6u);
  LOBYTE(v37) = 3;
  v4 = INIReader::getInt(&ini, &section, &key);
  v5 = section._Myres < 8;
  this->highQuality = v4 > 0;
  if ( !v5 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v37) = 1;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"SIZE", 4u);
  LOBYTE(v37) = 4;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"MIRROR", 6u);
  LOBYTE(v37) = 5;
  v6 = INIReader::getInt(&ini, &section, &key);
  v28 = v6;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  LOBYTE(v37) = 1;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  v7 = v6 / 4;
  if ( this->highQuality )
  {
    v8 = (RenderTarget *)operator new(28);
    v27 = v8;
    LOBYTE(v37) = 6;
    if ( v8 )
      RenderTarget::RenderTarget(v8, sim->game->graphics, eR16G16B16A16_MS, v6, v6 / 4, 1, 1, 1);
    else
      v9 = 0;
    LOBYTE(v37) = 1;
    this->renderTargetMS = v9;
  }
  v10 = (RenderTarget *)operator new(28);
  v27 = v10;
  LOBYTE(v37) = 7;
  if ( v10 )
    RenderTarget::RenderTarget(v10, sim->game->graphics, eR16G16B16A16, v6, v6 / 4, 1, 1, 1);
  else
    v11 = 0;
  v25 = 28;
  LOBYTE(v37) = 1;
  this->renderTargetNormal = v11;
  v12 = (RenderTarget *)operator new(v25);
  v27 = v12;
  LOBYTE(v37) = 8;
  if ( v12 )
    RenderTarget::RenderTarget(v12, sim->game->graphics, eR32F, 1u, 1u, 0, 1, 1);
  else
    v13 = 0;
  v25 = (unsigned int)this->renderTargetNormal;
  LOBYTE(v37) = 1;
  this->nullShadowRenderTarget = v13;
  Texture::Texture(&v33, (const RenderTarget *)v25);
  this->texture.kid = *(void **)v14;
  LOBYTE(v37) = 9;
  if ( &this->texture.fileName != (std::wstring *)(v14 + 4) )
    std::wstring::assign(&this->texture.fileName, (const std::wstring *)(v14 + 4), 0, 0xFFFFFFFF);
  LOBYTE(v37) = 1;
  OnSetupAppCreated::~OnSetupAppCreated(&v33);
  v15 = (CameraMirror *)operator new(492);
  v27 = v15;
  v16 = 0;
  LOBYTE(v37) = 10;
  if ( v15 )
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MIRROR_CAMERA", 0xDu);
    v29 = 1;
    v17 = sim->game;
    LOBYTE(v37) = 11;
    CameraMirror::CameraMirror(v15, &key, v17->graphics);
  }
  v18 = (v29 & 1) == 0;
  this->camera = v16;
  v37 = 1;
  if ( !v18 && key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  this->camera->renderTarget = this->renderTargetMS;
  v19 = Sim::getSceneCamera(sim);
  v20 = this->camera;
  v25 = 28;
  v24._Myres = (unsigned int)L"system/cfg/assetto_corsa.ini";
  v20->skyBox = v19->skyBox;
  v21 = this->camera;
  section._Myres = 7;
  section._Mysize = 0;
  v21->maxLayer = 0.0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, (const wchar_t *)v24._Myres, v25);
  LOBYTE(v37) = 13;
  INIReader::INIReader(&acini, &section);
  LOBYTE(v37) = 15;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  INIReader::setVerboseMode(&acini, 1);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"MIRRORS", 7u);
  LOBYTE(v37) = 16;
  v22 = INIReader::hasSection(&acini, &key);
  v26 = v22;
  LOBYTE(v37) = 15;
  if ( key._Myres >= 8 )
  {
    operator delete(key._Bx._Ptr);
    v22 = v26;
  }
  if ( v22 )
  {
    v33.fileName._Mysize = 7;
    *(_DWORD *)&v33.fileName._Bx._Alias[12] = 0;
    LOWORD(v33.kid) = 0;
    std::wstring::assign((std::wstring *)&v33, L"FOV", 3u);
    LOBYTE(v37) = 17;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MIRRORS", 7u);
    LOBYTE(v37) = 18;
    this->camera->fov = INIReader::getFloat(&acini, &key, (const std::wstring *)&v33);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v37) = 15;
    if ( v33.fileName._Mysize >= 8 )
      operator delete(v33.kid);
    v33.fileName._Mysize = 7;
    *(_DWORD *)&v33.fileName._Bx._Alias[12] = 0;
    LOWORD(v33.kid) = 0;
    std::wstring::assign((std::wstring *)&v33, L"FAR_PLANE", 9u);
    LOBYTE(v37) = 19;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"MIRRORS", 7u);
    LOBYTE(v37) = 20;
    this->camera->farPlane = INIReader::getFloat(&acini, &key, (const std::wstring *)&v33);
    if ( key._Myres >= 8 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    LOBYTE(v37) = 15;
    if ( v33.fileName._Mysize >= 8 )
      operator delete(v33.kid);
  }
  else
  {
    this->camera->fov = 10.0;
    this->camera->farPlane = 400.0;
  }
  this->camera->aspectRatio = (float)v28 / (float)v7;
  if ( this->highQuality )
    this->camera->farPlane = 800.0;
  v25 = 0;
  v24._Myres = 7;
  v24._Mysize = 0;
  v24._Bx._Buf[0] = 0;
  std::wstring::assign(&v24, L"cfg/video.ini", 0xDu);
  INIReaderDocuments::INIReaderDocuments(&videoINI, v7, v24, v25);
  LOBYTE(v37) = 21;
  if ( videoINI.ready )
  {
    v33.fileName._Mysize = 7;
    *(_DWORD *)&v33.fileName._Bx._Alias[12] = 0;
    LOWORD(v33.kid) = 0;
    std::wstring::assign((std::wstring *)&v33, L"RENDER_SMOKE_IN_MIRROR", 0x16u);
    LOBYTE(v37) = 22;
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"EFFECTS", 7u);
    LOBYTE(v37) = 23;
    v23 = INIReader::getInt(&videoINI, &key, (const std::wstring *)&v33);
    v5 = key._Myres < 8;
    this->renderSmoke = v23 > 0;
    if ( !v5 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    if ( v33.fileName._Mysize >= 8 )
      operator delete(v33.kid);
  }
  LOBYTE(v37) = 15;
  INIReaderDocuments::~INIReaderDocuments(&videoINI);
  LOBYTE(v37) = 1;
  INIReader::~INIReader(&acini);
  LOBYTE(v37) = 0;
  INIReaderDocuments::~INIReaderDocuments(&ini);
}
void MirrorTextureRenderer::~MirrorTextureRenderer(MirrorTextureRenderer *this)
{
  RenderTarget *v2; // ecx
  RenderTarget *v3; // ecx
  CameraMirror *v4; // ecx

  Texture::release(&this->texture);
  v2 = this->renderTargetMS;
  if ( v2 )
    ((void (*)(RenderTarget *, int))v2->~RenderTarget)(v2, 1);
  v3 = this->renderTargetNormal;
  if ( v3 )
    ((void (*)(RenderTarget *, int))v3->~RenderTarget)(v3, 1);
  v4 = this->camera;
  if ( v4 )
    ((void (*)(CameraMirror *, int))v4->~Camera)(v4, 1);
  OnSetupAppCreated::~OnSetupAppCreated(&this->texture);
}
void MirrorTextureRenderer::render(MirrorTextureRenderer *this, float deltaT)
{
  Sim *v3; // eax
  IdealLine *v4; // eax
  const mat44f *v5; // eax
  const mat44f *v6; // eax
  const mat44f *v7; // eax
  GraphicsManager *v8; // eax
  unsigned int v9; // eax
  CarAvatar *v10; // eax
  CameraMirror *v11; // ecx
  CarAvatar *v12; // esi
  Node *v13; // edx
  float v14; // xmm0_4
  CameraMirror *v15; // esi
  __int128 v16; // xmm1
  __int128 v17; // xmm2
  __int128 v18; // xmm3
  __int128 v19; // xmm1
  __int128 v20; // xmm2
  __int128 v21; // xmm3
  Node *v22; // ecx
  RenderTarget *v23; // ecx
  Sim *v24; // eax
  bool v25; // [esp+Eh] [ebp-86h]
  bool v26; // [esp+Fh] [ebp-85h]
  CarAvatar *v27; // [esp+10h] [ebp-84h]
  mat44f v28; // [esp+14h] [ebp-80h] BYREF
  mat44f result; // [esp+54h] [ebp-40h] BYREF

  if ( (dword_186E8E4 & 1) == 0 )
  {
    perfCounter_0.name = "MirrorTextureRenderer::render";
    dword_186E8E4 |= 1u;
    perfCounter_0.group = Render;
    perfCounter_0.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"MirrorTextureRenderer::render" | 0xFF000000;
  }
  v3 = this->sim;
  this->rendering = 1;
  v4 = v3->track->idealLine;
  v26 = v4->isActive;
  v4->isActive = 0;
  RenderTarget::clear(this->nullShadowRenderTarget);
  GraphicsManager::setShadowMapTexture(this->sim->game->graphics, 0, this->nullShadowRenderTarget);
  GraphicsManager::setShadowMapTexture(this->sim->game->graphics, 1, this->nullShadowRenderTarget);
  GraphicsManager::setShadowMapTexture(this->sim->game->graphics, 2, this->nullShadowRenderTarget);
  GraphicsManager::setShadowMapTexture(this->sim->game->graphics, 3, this->nullShadowRenderTarget);
  v5 = mat44f::createIdentity(&result);
  GraphicsManager::setShadowMapMatrix(this->sim->game->graphics, 0, v5);
  v6 = mat44f::createIdentity(&result);
  GraphicsManager::setShadowMapMatrix(this->sim->game->graphics, 1, v6);
  v7 = mat44f::createIdentity(&result);
  GraphicsManager::setShadowMapMatrix(this->sim->game->graphics, 2, v7);
  v8 = this->sim->game->graphics;
  if ( this->renderTargetMS )
  {
    kglSetSamplerPS(v8->samplerStates.samplerAniso, 0);
    GraphicsManager::setRenderTarget(this->sim->game->graphics, this->renderTargetMS);
  }
  else
  {
    kglSetSamplerPS(v8->samplerStates.samplerLinearSimple, 0);
    GraphicsManager::setRenderTarget(this->sim->game->graphics, this->renderTargetNormal);
  }
  GraphicsManager::setViewport(
    this->sim->game->graphics,
    0,
    0,
    this->renderTargetNormal->width,
    this->renderTargetNormal->height);
  v9 = Sim::getFocusedCarIndex(this->sim);
  v10 = Sim::getCar(this->sim, v9);
  v11 = this->camera;
  v12 = v10;
  v27 = v10;
  v13 = v10->bodyTransform;
  *(__m128i *)&v11->matrix.M11 = _mm_loadu_si128((const __m128i *)&v13->matrix);
  *(__m128i *)&v11->matrix.M21 = _mm_loadu_si128((const __m128i *)&v13->matrix.M21);
  *(__m128i *)&v11->matrix.M31 = _mm_loadu_si128((const __m128i *)&v13->matrix.M31);
  *(__m128i *)&v11->matrix.M41 = _mm_loadu_si128((const __m128i *)&v13->matrix.M41);
  CarAvatar::setVisible(v10, 0);
  mat44f::createIdentity(&v28);
  v28.M41 = v12->mirrorPosition.x;
  v28.M42 = v12->mirrorPosition.y;
  v14 = v12->mirrorPosition.z;
  v15 = this->camera;
  v28.M43 = v14;
  v16 = *(_OWORD *)&v15->matrix.M21;
  v17 = *(_OWORD *)&v15->matrix.M31;
  v18 = *(_OWORD *)&v15->matrix.M41;
  *(_OWORD *)&result.M11 = *(_OWORD *)&v15->matrix.M11;
  *(_OWORD *)&result.M21 = v16;
  v19 = *(_OWORD *)&v28.M21;
  *(_OWORD *)&result.M31 = v17;
  v20 = *(_OWORD *)&v28.M31;
  *(_OWORD *)&result.M41 = v18;
  v21 = *(_OWORD *)&v28.M41;
  *(__m128 *)&v15->matrix.M11 = DirectX::XMMatrixMultiply((__m128 *)&result, *(__m128 *)&v28.M11);
  *(_OWORD *)&v15->matrix.M21 = v19;
  *(_OWORD *)&v15->matrix.M31 = v20;
  *(_OWORD *)&v15->matrix.M41 = v21;
  CameraMirror::renderOpaque(this->camera, this->sim->rootNode, deltaT);
  if ( this->highQuality )
  {
    v22 = this->sim->particlesNode;
    v25 = v22->isActive;
    v22->isActive = this->renderSmoke;
    CameraMirror::renderTransparent(this->camera, this->sim->rootNode, deltaT);
    this->sim->particlesNode->isActive = v25;
  }
  else if ( this->renderSmoke )
  {
    CameraMirror::renderTransparent(this->camera, this->sim->particlesNode, deltaT);
  }
  CameraMirror::renderTransparent(this->camera, this->sim->beforeCarsNode, deltaT);
  CarAvatar::setVisible(v27, 1);
  v23 = this->renderTargetMS;
  if ( v23 )
    kglResolveRenderTarget(v23->kidColor, this->renderTargetNormal->kidColor, 1u);
  kglSetSamplerPS(this->sim->game->graphics->samplerStates.samplerAniso, 0);
  v24 = this->sim;
  this->rendering = 0;
  v24->track->idealLine->isActive = v26;
  this->hasBeenRendered = 1;
}
