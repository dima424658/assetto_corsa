#include "cameratriplescreen.h"
void CameraTripleScreen::CameraTripleScreen(CameraTripleScreen *this, const std::wstring *name, GraphicsManager *graphics, int numberOfParticleManagers)
{
  __m128i v5; // xmm1
  float v6; // xmm0_4
  vec2f *v7; // esi
  std::wstring *v8; // edi
  int v9; // ebx
  vec2f *v10; // eax
  bool v11; // cf
  vec2f *v12; // eax
  float v13; // xmm0_4
  std::wstring v14; // [esp-1Ch] [ebp-110h] BYREF
  BOOL v15; // [esp-4h] [ebp-F8h]
  float v16; // [esp+18h] [ebp-DCh]
  void *owner; // [esp+1Ch] [ebp-D8h]
  vec2f result; // [esp+20h] [ebp-D4h] BYREF
  CameraTripleScreen *v19; // [esp+28h] [ebp-CCh]
  vec2f v20; // [esp+2Ch] [ebp-C8h] BYREF
  std::wstring key; // [esp+34h] [ebp-C0h] BYREF
  INIReaderDocuments ini; // [esp+4Ch] [ebp-A8h] BYREF
  std::wstring sections[3]; // [esp+94h] [ebp-60h] BYREF
  int v24; // [esp+F0h] [ebp-4h]

  owner = this;
  v19 = this;
  CameraForwardYebis::CameraForwardYebis(this, (unsigned int)this, name, graphics, 0, 0, numberOfParticleManagers);
  v24 = 0;
  this->__vftable = (CameraTripleScreen_vtbl *)&CameraTripleScreen::`vftable';
  TripleScreenData::TripleScreenData(&this->tripleScreen);
  this->tripleScreenAvailable = 1;
  v5 = _mm_cvtsi32_si128(graphics->videoSettings.height);
  v6 = (float)graphics->videoSettings.width;
  v15 = 0;
  v14._Myres = 7;
  v14._Mysize = 0;
  v14._Bx._Buf[0] = 0;
  v16 = _mm_cvtepi32_ps(v5).m128_f32[0] / (float)(v6 * 0.33333334);
  std::wstring::assign(&v14, L"cfg/triple_screen.ini", 0x15u);
  INIReaderDocuments::INIReaderDocuments(&ini, (unsigned int)this, v14, v15);
  LOBYTE(v24) = 1;
  sections[0]._Myres = 7;
  sections[0]._Mysize = 0;
  sections[0]._Bx._Buf[0] = 0;
  std::wstring::assign(sections, L"LEFT_SCREEN", 0xBu);
  LOBYTE(v24) = 2;
  sections[1]._Myres = 7;
  sections[1]._Mysize = 0;
  sections[1]._Bx._Buf[0] = 0;
  std::wstring::assign(&sections[1], L"CENTER_SCREEN", 0xDu);
  LOBYTE(v24) = 3;
  sections[2]._Myres = 7;
  sections[2]._Mysize = 0;
  sections[2]._Bx._Buf[0] = 0;
  std::wstring::assign(&sections[2], L"RIGHT_SCREEN", 0xCu);
  v7 = &this->tripleScreen.screens[0].right;
  LOBYTE(v24) = 4;
  v8 = sections;
  v9 = 3;
  do
  {
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"LEFT_POINT", 0xAu);
    LOBYTE(v24) = 5;
    v10 = INIReader::getFloat2(&ini, &result, v8, &key);
    v11 = key._Myres < 8;
    LOBYTE(v24) = 4;
    v7[-1] = *v10;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    key._Myres = 7;
    key._Mysize = 0;
    key._Bx._Buf[0] = 0;
    std::wstring::assign(&key, L"RIGHT_POINT", 0xBu);
    LOBYTE(v24) = 6;
    v12 = INIReader::getFloat2(&ini, &v20, v8, &key);
    v11 = key._Myres < 8;
    LOBYTE(v24) = 4;
    *v7 = *v12;
    if ( !v11 )
      operator delete(key._Bx._Ptr);
    ++v8;
    v13 = v7[-1].y - v7->y;
    v7[1].x = fsqrt((float)((float)(v7[-1].x - v7->x) * (float)(v7[-1].x - v7->x)) + (float)(v13 * v13)) * v16;
    v7 = (vec2f *)((char *)v7 + 20);
    --v9;
  }
  while ( v9 );
  v14._Bx._Ptr = (wchar_t *)&std::_Func_impl<std::_Callable_obj<_lambda_0f4951729d63fd321729e1045e37a043_,0>,std::allocator<std::_Func_class<void,bool const &>>,void,bool const &>::`vftable';
  *(_DWORD *)&v14._Bx._Alias[4] = owner;
  v14._Mysize = (unsigned int)&v14;
  LOBYTE(v24) = 4;
  Event<std::wstring>::addHandler(
    (Event<OnPhysicsStepCompleted> *)((char *)owner + 1672),
    (std::function<void __cdecl(OnPhysicsStepCompleted const &)>)v14,
    owner);
  LOBYTE(v24) = 1;
  `eh vector destructor iterator'(sections, 0x18u, 3, (void (*)(void *))std::wstring::~wstring);
  LOBYTE(v24) = 0;
  INIReaderDocuments::~INIReaderDocuments(&ini);
}
CameraTripleScreen *__fastcall CameraTripleScreen::`vector deleting destructor'(CameraTripleScreen *this, PPFX::CTextureUtil *a2, unsigned int a3)
{
  this->__vftable = (CameraTripleScreen_vtbl *)&CameraTripleScreen::`vftable';
  CameraForwardYebis::~CameraForwardYebis(this, a2);
  if ( (a3 & 1) != 0 )
    operator delete(this);
  return this;
}
void CameraTripleScreen::beginVirtualScreenPass(CameraTripleScreen *this, int cameraIndex)
{
  __m128i v3; // xmm0
  float v4; // xmm6_4
  int v5; // ecx
  float v6; // xmm2_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  __m128 v9; // xmm1
  __m128 v10; // xmm3
  __m128 v11; // xmm0
  __m128 v12; // xmm2
  __int128 v13; // xmm1
  __int128 v14; // xmm2
  __int128 v15; // xmm3
  __m128 v16; // xmm0
  __m128 v17; // xmm5
  float v18; // xmm6_4
  float v19; // xmm4_4
  float v20; // eax
  float v21; // xmm2_4
  float v22; // xmm6_4
  float top; // xmm1_4
  int v24; // [esp+10h] [ebp-B0h]
  int v25; // [esp+14h] [ebp-ACh]
  float v26; // [esp+20h] [ebp-A0h]
  float v27; // [esp+20h] [ebp-A0h]
  float v28; // [esp+24h] [ebp-9Ch]
  float v29; // [esp+24h] [ebp-9Ch]
  float v30; // [esp+2Ch] [ebp-94h]
  float v31; // [esp+2Ch] [ebp-94h]
  float v32; // [esp+34h] [ebp-8Ch]
  float v33; // [esp+34h] [ebp-8Ch]
  float v34; // [esp+38h] [ebp-88h]
  float v35; // [esp+38h] [ebp-88h]
  float v36; // [esp+3Ch] [ebp-84h]
  mat44f v37; // [esp+40h] [ebp-80h] BYREF
  DirectX::XMMATRIX M2; // [esp+80h] [ebp-40h] BYREF

  v3 = _mm_loadu_si128((const __m128i *)&this->matrix);
  this->tripleScreen.currentScreen = cameraIndex;
  *(__m128i *)&this->virtualScreenPassOrgMatrix.M11 = v3;
  *(__m128i *)&this->virtualScreenPassOrgMatrix.M21 = _mm_loadu_si128((const __m128i *)&this->matrix.M21);
  *(__m128i *)&this->virtualScreenPassOrgMatrix.M31 = _mm_loadu_si128((const __m128i *)&this->matrix.M31);
  *(__m128i *)&this->virtualScreenPassOrgMatrix.M41 = _mm_loadu_si128((const __m128i *)&this->matrix.M41);
  v4 = FLOAT_1_0;
  if ( __libm_sse2_asinf().m128_f32[0] == 0.0 )
  {
    v35 = this->tripleScreen.screens[cameraIndex].left.x;
    v36 = this->tripleScreen.screens[cameraIndex].left.y;
    v29 = this->tripleScreen.screens[cameraIndex].right.x;
    v20 = this->tripleScreen.screens[cameraIndex].right.y;
  }
  else
  {
    v30 = __libm_sse2_cosf(v24, v25).m128_f32[0];
    v32 = __libm_sse2_sinf(v5).m128_f32[0];
    v26 = 1.0 - v30;
    mat44f::mat44f(&v37);
    v37.M44 = 1.0;
    v6 = (float)(1.0 - v30) * 0.0;
    v37.M22 = (float)(1.0 - v30) + v30;
    v31 = v30 + v6;
    v37.M33 = v31;
    v37.M11 = v31;
    v37.M12 = (float)(v32 * 0.0) + (float)(v26 * 0.0);
    v27 = (float)(v26 * 0.0) - (float)(v32 * 0.0);
    v37.M21 = v27;
    v28 = v6 - v32;
    v37.M13 = v6 - v32;
    v7 = (float)(v32 * 0.0) + v6;
    v37.M31 = v32 + v6;
    v8 = v6 - (float)(v32 * 0.0);
    v33 = v37.M31;
    v9 = *(__m128 *)&this->matrix.M21;
    v10 = *(__m128 *)&this->matrix.M41;
    v37.M23 = v7;
    v34 = v7;
    v11 = *(__m128 *)&this->matrix.M11;
    v37.M32 = v8;
    v12 = *(__m128 *)&this->matrix.M31;
    M2.r[0] = v11;
    M2.r[1] = v9;
    v13 = *(_OWORD *)&v37.M21;
    M2.r[2] = v12;
    v14 = *(_OWORD *)&v37.M31;
    M2.r[3] = v10;
    v15 = *(_OWORD *)&v37.M41;
    v16 = DirectX::XMMatrixMultiply(M2.r, *(__m128 *)&v37.M11);
    v17 = *(__m128 *)&v37.M41;
    *(__m128 *)&this->matrix.M11 = v16;
    *(_OWORD *)&this->matrix.M21 = v13;
    *(_OWORD *)&this->matrix.M31 = v14;
    *(_OWORD *)&this->matrix.M41 = v15;
    *(float *)&v13 = this->tripleScreen.screens[cameraIndex].left.y;
    v18 = v34 * 0.0;
    v19 = _mm_shuffle_ps(v17, v17, 170).m128_f32[0];
    v35 = (float)((float)((float)(this->tripleScreen.screens[cameraIndex].left.x * v31) + (float)(v27 * 0.0))
                + (float)(*(float *)&v13 * v33))
        + v17.m128_f32[0];
    v16.m128_i32[0] = LODWORD(this->tripleScreen.screens[cameraIndex].right.y);
    v36 = (float)((float)((float)(this->tripleScreen.screens[cameraIndex].left.x * v28) + v18)
                + (float)(*(float *)&v13 * v31))
        + v19;
    *(float *)&v15 = (float)(this->tripleScreen.screens[cameraIndex].right.x * v28) + v18;
    v4 = FLOAT_1_0;
    v29 = (float)((float)((float)(this->tripleScreen.screens[cameraIndex].right.x * v31) + (float)(v27 * 0.0))
                + (float)(v16.m128_f32[0] * v33))
        + v17.m128_f32[0];
    v20 = (float)(*(float *)&v15 + (float)(v16.m128_f32[0] * v31)) + v19;
  }
  v21 = this->nearPlane;
  v22 = v4
      / (float)(COERCE_FLOAT(COERCE_UNSIGNED_INT((float)(v36 * (float)(v29 - v35)) - (float)(v35 * (float)(v20 - v36))) & _xmm)
              / fsqrt((float)((float)(v20 - v36) * (float)(v20 - v36)) + (float)((float)(v29 - v35) * (float)(v29 - v35))));
  top = (float)((float)(this->tripleScreen.screens[cameraIndex].height * 0.5) * v21) * v22;
  Camera::renderCameraCustomPerspective(
    this,
    (float)(v21 * v35) * v22,
    (float)(v21 * v29) * v22,
    top,
    COERCE_FLOAT(LODWORD(top) ^ _xmm));
}
void CameraTripleScreen::renderPass(CameraTripleScreen *this, Node *root, float dt)
{
  GraphicsManager *v4; // ecx
  RenderTarget *v5; // eax
  GraphicsManager *v6; // ecx
  int v7; // ebp
  int v8; // ebx
  int v9; // edi
  const mat44f *v10; // eax
  const mat44f *v11; // eax
  const mat44f *v12; // eax
  eAxisRendering v13; // eax
  eAxisRendering v14; // eax
  eAxisRendering v15; // eax
  GraphicsManager *v16; // ecx
  int v17; // ecx
  const mat44f *value; // [esp+Ch] [ebp-F0h]
  const mat44f *valuea; // [esp+Ch] [ebp-F0h]
  const mat44f *valueb; // [esp+Ch] [ebp-F0h]
  MaterialFilter materialFilter; // [esp+24h] [ebp-D8h] BYREF
  RenderContext rc; // [esp+2Ch] [ebp-D0h] BYREF
  int v23; // [esp+3Ch] [ebp-C0h]
  RenderContext rcTR; // [esp+40h] [ebp-BCh] BYREF
  CameraMeshFilter filter; // [esp+50h] [ebp-ACh] BYREF
  mat44f id; // [esp+60h] [ebp-9Ch] BYREF
  CameraMeshFilter filterTR; // [esp+A0h] [ebp-5Ch] BYREF
  mat44f result; // [esp+B0h] [ebp-4Ch] BYREF
  int v29; // [esp+F8h] [ebp-4h]

  if ( this->tripleScreenAvailable )
  {
    GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
    CameraMeshFilter::CameraMeshFilter(&filter, this, Opaque, (int)this->maxLayer);
    v29 = 0;
    MaterialFilter::MaterialFilter(&materialFilter);
    v4 = this->graphics;
    rc.materialFilter = &materialFilter;
    rc.meshFilter = &filter;
    v5 = this->renderTarget;
    LOBYTE(v29) = 1;
    rc.graphics = v4;
    rc.camera = this;
    if ( v5 )
      GraphicsManager::setRenderTarget(v4, v5);
    GraphicsManager::setCullMode(this->graphics, eCullFront);
    Camera::clearBuffers(this);
    v6 = this->graphics;
    v7 = v6->videoSettings.width;
    v23 = v6->videoSettings.height;
    v8 = v23;
    v9 = v7 / 3;
    GraphicsManager::setViewport(v6, 0, 0, v7 / 3, v23);
    this->graphics->videoSettings.width = v7 / 3;
    CameraTripleScreen::beginVirtualScreenPass(this, 0);
    if ( !this->isMirror )
    {
      value = GraphicsManager::getProjectionMatrix(this->graphics, &id);
      v10 = this->getViewMatrix(this, &result);
      mul(this->tripleScreen.currentViewProj, v10, value);
      *(__m128i *)&this->tripleScreen.currentCameraMatrix[0].M11 = _mm_loadu_si128((const __m128i *)&this->matrix);
      *(__m128i *)&this->tripleScreen.currentCameraMatrix[0].M21 = _mm_loadu_si128((const __m128i *)&this->matrix.M21);
      *(__m128i *)&this->tripleScreen.currentCameraMatrix[0].M31 = _mm_loadu_si128((const __m128i *)&this->matrix.M31);
      *(__m128i *)&this->tripleScreen.currentCameraMatrix[0].M41 = _mm_loadu_si128((const __m128i *)&this->matrix.M41);
    }
    if ( this->skyBox )
    {
      mat44f::mat44f(&id);
      mat44f::loadIdentity(&id);
      GraphicsManager::setWorldMatrix(this->graphics, &id);
      SkyBox::render(this->skyBox, &rc);
    }
    *(__m128i *)&this->matrix.M11 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix);
    *(__m128i *)&this->matrix.M21 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M21);
    *(__m128i *)&this->matrix.M31 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M31);
    *(__m128i *)&this->matrix.M41 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M41);
    MaterialFilter::resetMaterialCache((Turbo *)&materialFilter);
    GraphicsManager::setViewport(this->graphics, v7 / 3, 0, v7 / 3, this->graphics->videoSettings.height);
    this->graphics->videoSettings.width = v9;
    CameraTripleScreen::beginVirtualScreenPass(this, 1);
    if ( !this->isMirror )
    {
      valuea = GraphicsManager::getProjectionMatrix(this->graphics, &result);
      v11 = this->getViewMatrix(this, &id);
      mul(&this->tripleScreen.currentViewProj[1], v11, valuea);
      *(__m128i *)&this->tripleScreen.currentCameraMatrix[1].M11 = _mm_loadu_si128((const __m128i *)&this->matrix);
      *(__m128i *)&this->tripleScreen.currentCameraMatrix[1].M21 = _mm_loadu_si128((const __m128i *)&this->matrix.M21);
      *(__m128i *)&this->tripleScreen.currentCameraMatrix[1].M31 = _mm_loadu_si128((const __m128i *)&this->matrix.M31);
      *(__m128i *)&this->tripleScreen.currentCameraMatrix[1].M41 = _mm_loadu_si128((const __m128i *)&this->matrix.M41);
    }
    if ( this->skyBox )
    {
      mat44f::mat44f(&id);
      mat44f::loadIdentity(&id);
      GraphicsManager::setWorldMatrix(this->graphics, &id);
      SkyBox::render(this->skyBox, &rc);
    }
    *(__m128i *)&this->matrix.M11 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix);
    *(__m128i *)&this->matrix.M21 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M21);
    *(__m128i *)&this->matrix.M31 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M31);
    *(__m128i *)&this->matrix.M41 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M41);
    MaterialFilter::resetMaterialCache((Turbo *)&materialFilter);
    GraphicsManager::setViewport(this->graphics, 2 * v9, 0, v7 / 3, this->graphics->videoSettings.height);
    this->graphics->videoSettings.width = v9;
    CameraTripleScreen::beginVirtualScreenPass(this, 2);
    if ( !this->isMirror )
    {
      valueb = GraphicsManager::getProjectionMatrix(this->graphics, &result);
      v12 = this->getViewMatrix(this, &id);
      mul(&this->tripleScreen.currentViewProj[2], v12, valueb);
      *(__m128i *)&this->tripleScreen.currentCameraMatrix[2].M11 = _mm_loadu_si128((const __m128i *)&this->matrix);
      *(__m128i *)&this->tripleScreen.currentCameraMatrix[2].M21 = _mm_loadu_si128((const __m128i *)&this->matrix.M21);
      *(__m128i *)&this->tripleScreen.currentCameraMatrix[2].M31 = _mm_loadu_si128((const __m128i *)&this->matrix.M31);
      *(__m128i *)&this->tripleScreen.currentCameraMatrix[2].M41 = _mm_loadu_si128((const __m128i *)&this->matrix.M41);
    }
    if ( this->skyBox )
    {
      mat44f::mat44f(&id);
      mat44f::loadIdentity(&id);
      GraphicsManager::setWorldMatrix(this->graphics, &id);
      SkyBox::render(this->skyBox, &rc);
    }
    *(__m128i *)&this->matrix.M11 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix);
    *(__m128i *)&this->matrix.M21 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M21);
    *(__m128i *)&this->matrix.M31 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M31);
    *(__m128i *)&this->matrix.M41 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M41);
    MaterialFilter::resetMaterialCache((Turbo *)&materialFilter);
    GraphicsManager::clearRenderTargetDepth(this->graphics, this->clearDepth);
    this->graphics->videoSettings.width = v7;
    this->graphics->videoSettings.height = v8;
    GraphicsManager::setViewport(this->graphics, 0, 0, v7, this->graphics->videoSettings.height);
    GraphicsManager::setViewport(this->graphics, 0, 0, v7 / 3, this->graphics->videoSettings.height);
    this->graphics->videoSettings.width = v9;
    CameraTripleScreen::beginVirtualScreenPass(this, 0);
    root->render(root, &rc);
    v13 = this->axisRenderingMode;
    if ( v13 )
      Camera::renderAxis(this, v13 == eAxisBefore3d);
    *(__m128i *)&this->matrix.M11 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix);
    *(__m128i *)&this->matrix.M21 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M21);
    *(__m128i *)&this->matrix.M31 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M31);
    *(__m128i *)&this->matrix.M41 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M41);
    MaterialFilter::resetMaterialCache((Turbo *)&materialFilter);
    GraphicsManager::setViewport(this->graphics, v7 / 3, 0, v7 / 3, this->graphics->videoSettings.height);
    this->graphics->videoSettings.width = v9;
    CameraTripleScreen::beginVirtualScreenPass(this, 1);
    root->render(root, &rc);
    v14 = this->axisRenderingMode;
    if ( v14 )
      Camera::renderAxis(this, v14 == eAxisBefore3d);
    *(__m128i *)&this->matrix.M11 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix);
    *(__m128i *)&this->matrix.M21 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M21);
    *(__m128i *)&this->matrix.M31 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M31);
    *(__m128i *)&this->matrix.M41 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M41);
    MaterialFilter::resetMaterialCache((Turbo *)&materialFilter);
    GraphicsManager::setViewport(this->graphics, 2 * v9, 0, v7 / 3, this->graphics->videoSettings.height);
    this->graphics->videoSettings.width = v9;
    CameraTripleScreen::beginVirtualScreenPass(this, 2);
    root->render(root, &rc);
    v15 = this->axisRenderingMode;
    if ( v15 )
      Camera::renderAxis(this, v15 == eAxisBefore3d);
    *(__m128i *)&this->matrix.M11 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix);
    *(__m128i *)&this->matrix.M21 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M21);
    *(__m128i *)&this->matrix.M31 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M31);
    *(__m128i *)&this->matrix.M41 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M41);
    MaterialFilter::resetMaterialCache((Turbo *)&materialFilter);
    CameraMeshFilter::CameraMeshFilter(&filterTR, this, Transparent, (int)this->maxLayer);
    v16 = this->graphics;
    rcTR.materialFilter = &materialFilter;
    LOBYTE(v29) = 2;
    rcTR.meshFilter = &filterTR;
    rcTR.graphics = v16;
    rcTR.camera = this;
    GraphicsManager::setDepthMode(v16, eDepthNoWrite);
    GraphicsManager::setViewport(this->graphics, 0, 0, v7 / 3, this->graphics->videoSettings.height);
    this->graphics->videoSettings.width = v9;
    CameraTripleScreen::beginVirtualScreenPass(this, 0);
    root->render(root, &rcTR);
    *(__m128i *)&this->matrix.M11 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix);
    *(__m128i *)&this->matrix.M21 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M21);
    *(__m128i *)&this->matrix.M31 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M31);
    *(__m128i *)&this->matrix.M41 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M41);
    MaterialFilter::resetMaterialCache((Turbo *)&materialFilter);
    GraphicsManager::setViewport(this->graphics, v7 / 3, 0, v7 / 3, this->graphics->videoSettings.height);
    this->graphics->videoSettings.width = v9;
    CameraTripleScreen::beginVirtualScreenPass(this, 1);
    root->render(root, &rcTR);
    *(__m128i *)&this->matrix.M11 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix);
    *(__m128i *)&this->matrix.M21 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M21);
    *(__m128i *)&this->matrix.M31 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M31);
    *(__m128i *)&this->matrix.M41 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M41);
    MaterialFilter::resetMaterialCache((Turbo *)&materialFilter);
    GraphicsManager::setViewport(this->graphics, 2 * v9, 0, v7 / 3, this->graphics->videoSettings.height);
    this->graphics->videoSettings.width = v9;
    CameraTripleScreen::beginVirtualScreenPass(this, 2);
    root->render(root, &rcTR);
    *(__m128i *)&this->matrix.M11 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix);
    *(__m128i *)&this->matrix.M21 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M21);
    *(__m128i *)&this->matrix.M31 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M31);
    *(__m128i *)&this->matrix.M41 = _mm_loadu_si128((const __m128i *)&this->virtualScreenPassOrgMatrix.M41);
    MaterialFilter::resetMaterialCache((Turbo *)&materialFilter);
    v17 = v23;
    this->graphics->videoSettings.width = v7;
    this->graphics->videoSettings.height = v17;
    GraphicsManager::setViewport(this->graphics, 0, 0, v7, this->graphics->videoSettings.height);
    GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
    LOBYTE(v29) = 1;
    CameraMeshFilter::~CameraMeshFilter(&filterTR);
    LOBYTE(v29) = 0;
    MaterialFilter::~MaterialFilter(&materialFilter);
    v29 = -1;
    CameraMeshFilter::~CameraMeshFilter(&filter);
  }
  else
  {
    CameraShadowMapped::renderPass(this, root, dt);
  }
}
