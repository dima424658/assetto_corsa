#include "camerashadowmapped.h"
void CameraShadowMapped::CameraShadowMapped(CameraShadowMapped *this, const std::wstring *iname, GraphicsManager *gm)
{
  std::vector<ShadowMapSettings> *v4; // ebx
  int v5; // edx
  RenderTarget **v6; // ecx
  unsigned int v7; // esi
  ShadowMapSettings *v8; // esi
  ShadowMapSettings *v9; // edi
  double v10; // st7
  bool v11; // cf
  char v12; // [esp+23h] [ebp-A5h]
  char v13; // [esp+24h] [ebp-A4h]
  std::wstring section; // [esp+2Ch] [ebp-9Ch] BYREF
  std::wstring ifilename; // [esp+44h] [ebp-84h] BYREF
  std::wstring key; // [esp+5Ch] [ebp-6Ch] BYREF
  INIReader lightsINI; // [esp+74h] [ebp-54h] BYREF
  int v18; // [esp+C4h] [ebp-4h]

  v13 = 0;
  Camera::Camera(this, iname, gm);
  v4 = &this->shadowMapSettings;
  this->__vftable = (CameraShadowMapped_vtbl *)&CameraShadowMapped::`vftable';
  v18 = 0;
  this->shadowMapSettings._Myfirst = 0;
  this->shadowMapSettings._Mylast = 0;
  this->shadowMapSettings._Myend = 0;
  this->shadowBias = 0.000002;
  this->shadowRT._Myfirst = 0;
  this->shadowRT._Mylast = 0;
  this->shadowRT._Myend = 0;
  this->shadowMatrices._Myfirst = 0;
  this->shadowMatrices._Mylast = 0;
  this->shadowMatrices._Myend = 0;
  LOBYTE(v18) = 3;
  mat44f::mat44f(&this->stableShadowMatrix);
  std::vector<RenderTarget *>::resize(&this->shadowRT, 3u);
  std::vector<mat44f>::resize(&this->shadowMatrices, 3u);
  std::vector<ShadowMapSettings>::resize(&this->shadowMapSettings, 4u);
  v5 = 0;
  v6 = this->shadowRT._Myfirst;
  v7 = (unsigned int)((char *)this->shadowRT._Mylast - (char *)v6 + 3) >> 2;
  if ( v6 > this->shadowRT._Mylast )
    v7 = 0;
  if ( v7 )
  {
    do
    {
      ++v5;
      *v6++ = 0;
    }
    while ( v5 != v7 );
  }
  this->shadowBias = 0.003;
  CameraShadowMapped::initShadowRenderTargets(this);
  v4->_Myfirst->nearSplit = 0.0;
  v4->_Myfirst->farSplit = 1.8;
  v4->_Myfirst[1].nearSplit = 1.8;
  v4->_Myfirst[1].farSplit = 20.0;
  v4->_Myfirst[2].nearSplit = 20.0;
  v4->_Myfirst[2].farSplit = 180.0;
  v4->_Myfirst[3].nearSplit = 180.0;
  v4->_Myfirst[3].farSplit = 500.0;
  GraphicsManager::setShadowMapBias(
    this->graphics,
    (float)(this->shadowBias * 1.8) * 0.001,
    (float)(this->shadowBias * 18.200001) * 0.001,
    (float)(this->shadowBias * 160.0) * 0.001);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  std::wstring::assign(&ifilename, L"system/cfg/lighting.ini", 0x17u);
  LOBYTE(v18) = 4;
  INIReader::INIReader(&lightsINI, &ifilename);
  LOBYTE(v18) = 6;
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
  ifilename._Myres = 7;
  ifilename._Mysize = 0;
  ifilename._Bx._Buf[0] = 0;
  if ( !lightsINI.ready
    || (section._Myres = 7,
        section._Mysize = 0,
        section._Bx._Buf[0] = 0,
        std::wstring::assign(&section, L"LIGHT", 5u),
        LOBYTE(v18) = 7,
        v13 = 1,
        v12 = 1,
        !INIReader::hasSection(&lightsINI, &section)) )
  {
    v12 = 0;
  }
  v18 = 6;
  if ( (v13 & 1) != 0 && section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  if ( v12 )
  {
    v8 = v4->_Myfirst;
    v9 = this->shadowMapSettings._Mylast;
    if ( v4->_Myfirst != v9 )
    {
      do
      {
        key._Myres = 7;
        key._Mysize = 0;
        key._Bx._Buf[0] = 0;
        std::wstring::assign(&key, L"LIGHT_HEIGHT", 0xCu);
        LOBYTE(v18) = 8;
        section._Myres = 7;
        section._Mysize = 0;
        section._Bx._Buf[0] = 0;
        std::wstring::assign(&section, L"LIGHT", 5u);
        LOBYTE(v18) = 9;
        v10 = INIReader::getFloat(&lightsINI, &section, &key);
        v11 = section._Myres < 8;
        v8->height = v10;
        if ( !v11 )
          operator delete(section._Bx._Ptr);
        section._Myres = 7;
        section._Mysize = 0;
        section._Bx._Buf[0] = 0;
        LOBYTE(v18) = 6;
        if ( key._Myres >= 8 )
          operator delete(key._Bx._Ptr);
        ++v8;
      }
      while ( v8 != v9 );
    }
  }
  LOBYTE(v18) = 3;
  INIReader::~INIReader(&lightsINI);
}
void CameraShadowMapped::~CameraShadowMapped(CameraShadowMapped *this)
{
  RenderTarget **v1; // esi
  std::vector<RenderTarget *> *v2; // ebp
  int v3; // edi
  unsigned int v4; // ebx
  std::vector<mat44f> *v5; // esi
  std::vector<ShadowMapSettings> *v6; // esi

  this->__vftable = (CameraShadowMapped_vtbl *)&CameraShadowMapped::`vftable';
  v1 = this->shadowRT._Myfirst;
  v2 = &this->shadowRT;
  v3 = 0;
  v4 = (unsigned int)((char *)this->shadowRT._Mylast - (char *)v1 + 3) >> 2;
  if ( v1 > this->shadowRT._Mylast )
    v4 = 0;
  if ( v4 )
  {
    do
    {
      if ( *v1 )
        ((void (*)(RenderTarget *, int))(*v1)->~RenderTarget)(*v1, 1);
      ++v3;
      ++v1;
    }
    while ( v3 != v4 );
  }
  v5 = &this->shadowMatrices;
  if ( this->shadowMatrices._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->shadowMatrices);
    operator delete(v5->_Myfirst);
    v5->_Myfirst = 0;
    this->shadowMatrices._Mylast = 0;
    this->shadowMatrices._Myend = 0;
  }
  if ( v2->_Myfirst )
  {
    std::_Container_base0::_Orphan_all(v2);
    operator delete(v2->_Myfirst);
    v2->_Myfirst = 0;
    v2->_Mylast = 0;
    v2->_Myend = 0;
  }
  v6 = &this->shadowMapSettings;
  if ( this->shadowMapSettings._Myfirst )
  {
    std::_Container_base0::_Orphan_all(&this->shadowMapSettings);
    operator delete(v6->_Myfirst);
    v6->_Myfirst = 0;
    this->shadowMapSettings._Mylast = 0;
    this->shadowMapSettings._Myend = 0;
  }
  Camera::~Camera(this);
}
CameraShadowMapped *CameraShadowMapped::`vector deleting destructor'(CameraShadowMapped *this, unsigned int a2)
{
  CameraShadowMapped::~CameraShadowMapped(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void CameraShadowMapped::beginShadowMapPass(CameraShadowMapped *this, int level, RenderContext *rc, const mat44f *cameraMatrix)
{
  CameraShadowMapped *v4; // esi
  GraphicsManager *v5; // eax
  __int64 v6; // xmm5_8
  float v7; // edi
  float v8; // xmm0_4
  int v9; // esi
  __int128 v10; // xmm1
  __int128 v11; // xmm2
  __int128 v12; // xmm3
  RenderTarget *v13; // eax
  vec3f v14; // [esp+8h] [ebp-F8h]
  __int64 v15; // [esp+30h] [ebp-D0h]
  mat44f proj; // [esp+40h] [ebp-C0h] BYREF
  mat44f view; // [esp+80h] [ebp-80h] BYREF
  DirectX::XMMATRIX M2; // [esp+C0h] [ebp-40h] BYREF

  v4 = this;
  GraphicsManager::setCullMode(this->graphics, eCullBack);
  GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
  mat44f::mat44f(&view);
  mat44f::mat44f(&proj);
  v5 = this->graphics;
  v6 = *(_QWORD *)&v5->lightingSettings.lightDirection.x;
  v7 = v5->lightingSettings.lightDirection.z;
  v8 = fsqrt(
         (float)((float)(*(float *)&v6 * *(float *)&v6) + (float)(*((float *)&v6 + 1) * *((float *)&v6 + 1)))
       + (float)(v7 * v7));
  if ( v8 != 0.0 )
  {
    *(float *)&v15 = (float)(1.0 / v8) * *(float *)&v6;
    *((float *)&v15 + 1) = (float)(1.0 / v8) * *((float *)&v6 + 1);
    v6 = v15;
    v7 = (float)(1.0 / v8) * v7;
  }
  *(_QWORD *)&v14.x = v6;
  v14.z = v7;
  CameraShadowMapped::createShadowMapMatrix(
    v4,
    cameraMatrix,
    v4->nearPlane + v4->shadowMapSettings._Myfirst[level].nearSplit,
    v4->shadowMapSettings._Myfirst[level].farSplit + v4->nearPlane,
    v14,
    v4->shadowMapSettings._Myfirst[level].height,
    &view,
    &proj);
  GraphicsManager::setProjectionMatrix(v4->graphics, &proj);
  GraphicsManager::setViewMatrix(v4->graphics, &view, 0);
  v9 = (int)&v4->shadowMatrices._Myfirst[level];
  M2 = (DirectX::XMMATRIX)proj;
  v10 = *(_OWORD *)&view.M21;
  v11 = *(_OWORD *)&view.M31;
  v12 = *(_OWORD *)&view.M41;
  *(__m128 *)v9 = DirectX::XMMatrixMultiply(M2.r, *(__m128 *)&view.M11);
  *(_OWORD *)(v9 + 16) = v10;
  *(_OWORD *)(v9 + 32) = v11;
  *(_OWORD *)(v9 + 48) = v12;
  BoundingFrustum::setMatrix(&this->frustum, &this->shadowMatrices._Myfirst[level]);
  GraphicsManager::setShadowMapTexture(this->graphics, level, 0);
  kglSetRenderTargets(0, this->shadowRT._Myfirst[level]->kidDepth);
  v13 = this->shadowRT._Myfirst[level];
  GraphicsManager::setViewport(this->graphics, 0, 0, v13->width, v13->height);
  kglRenderTargetClear(this->shadowRT._Myfirst[level]->kidDepth, 0, 1.0);
}
void CameraShadowMapped::createShadowMapMatrix(CameraShadowMapped *this, const mat44f *cameraMatrix, float nearp, float farp, vec3f lightDir, float cameraHeight, mat44f *view, mat44f *proj)
{
  GraphicsManager *v9; // eax
  float v10; // xmm1_4
  __m128i fieldOfView; // xmm0
  float aspectRatio; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm3_4
  float v15; // xmm1_4
  float v16; // xmm2_4
  __int128 v17; // xmm1
  __int128 v18; // xmm2
  __int128 v19; // xmm3
  __m128 v20; // xmm6
  __m128 v21; // xmm4
  float v22; // xmm5_4
  unsigned __int64 v23; // xmm2_8
  float v24; // ecx
  float v25; // xmm0_4
  __m128 v26; // xmm0
  const __m128i *v27; // eax
  float v28; // xmm5_4
  float v29; // xmm6_4
  float v30; // xmm4_4
  __m128i v31; // xmm0
  vec3f *v32; // esi
  vec3f *v33; // edx
  float v34; // xmm7_4
  float *v35; // ecx
  float v36; // xmm3_4
  __m128i *v37; // eax
  float v38; // [esp+20h] [ebp-204h]
  unsigned __int64 v39; // [esp+20h] [ebp-204h]
  float v40; // [esp+24h] [ebp-200h]
  vec3f cameraUpVector; // [esp+28h] [ebp-1FCh] BYREF
  float v42; // [esp+34h] [ebp-1F0h]
  vec3f cameraTarget; // [esp+38h] [ebp-1ECh] BYREF
  std::vector<vec3f> corners; // [esp+44h] [ebp-1E0h] BYREF
  float v45; // [esp+50h] [ebp-1D4h]
  mat44f result; // [esp+54h] [ebp-1D0h] BYREF
  mat44f *v47; // [esp+94h] [ebp-190h]
  vec3f cameraPosition; // [esp+98h] [ebp-18Ch] BYREF
  mat44f v49; // [esp+A4h] [ebp-180h] BYREF
  mat44f iviewProj; // [esp+E4h] [ebp-140h] BYREF
  BoundingFrustum v51; // [esp+124h] [ebp-100h] BYREF
  int v52; // [esp+220h] [ebp-4h]

  v47 = proj;
  *(__m128i *)&this->stableShadowMatrix.M11 = _mm_loadu_si128((const __m128i *)cameraMatrix);
  *(__m128i *)&this->stableShadowMatrix.M21 = _mm_loadu_si128((const __m128i *)&cameraMatrix->M21);
  *(__m128i *)&this->stableShadowMatrix.M31 = _mm_loadu_si128((const __m128i *)&cameraMatrix->M31);
  v9 = this->graphics;
  *(__m128i *)&this->stableShadowMatrix.M41 = _mm_loadu_si128((const __m128i *)&cameraMatrix->M41);
  v10 = this->stableShadowMatrix.M42;
  cameraPosition.x = this->stableShadowMatrix.M41;
  v38 = cameraPosition.x;
  fieldOfView = _mm_cvtsi32_si128(v9->videoSettings.height);
  v40 = v10;
  cameraPosition.y = v10;
  aspectRatio = (float)v9->videoSettings.width / _mm_cvtepi32_ps(fieldOfView).m128_f32[0];
  *(float *)fieldOfView.m128i_i32 = this->fov * 0.017453;
  v42 = this->stableShadowMatrix.M43;
  cameraPosition.z = v42;
  mat44f::createPerspective(&result, *(float *)fieldOfView.m128i_i32, aspectRatio, nearp, farp);
  fieldOfView.m128i_i32[0] = LODWORD(this->stableShadowMatrix.M21);
  v13 = this->stableShadowMatrix.M23;
  v14 = this->stableShadowMatrix.M31;
  cameraUpVector.y = this->stableShadowMatrix.M22;
  v15 = this->stableShadowMatrix.M33;
  cameraUpVector.z = v13;
  v16 = this->stableShadowMatrix.M32;
  LODWORD(cameraUpVector.x) = fieldOfView.m128i_i32[0];
  cameraTarget.x = COERCE_FLOAT(LODWORD(v14) ^ _xmm) + v38;
  cameraTarget.y = COERCE_FLOAT(LODWORD(v16) ^ _xmm) + v40;
  cameraTarget.z = COERCE_FLOAT(LODWORD(v15) ^ _xmm) + v42;
  mat44f::createLookAt((__m128)(unsigned int)_xmm, &v49, &cameraPosition, &cameraTarget, &cameraUpVector);
  mat44f::mat44f(&iviewProj);
  v17 = *(_OWORD *)&v49.M21;
  v18 = *(_OWORD *)&v49.M31;
  v19 = *(_OWORD *)&v49.M41;
  *(__m128 *)&iviewProj.M11 = DirectX::XMMatrixMultiply((__m128 *)&result, *(__m128 *)&v49.M11);
  *(_OWORD *)&iviewProj.M21 = v17;
  *(_OWORD *)&iviewProj.M31 = v18;
  *(_OWORD *)&iviewProj.M41 = v19;
  BoundingFrustum::BoundingFrustum(&v51, &iviewProj);
  v52 = 1;
  corners._Myfirst = 0;
  corners._Mylast = 0;
  corners._Myend = 0;
  BoundingFrustum::getCorners(&v51, &corners);
  v20 = (__m128)LODWORD(this->stableShadowMatrix.M31);
  v21 = (__m128)LODWORD(this->stableShadowMatrix.M32);
  v22 = this->stableShadowMatrix.M33;
  *(float *)&v19 = (float)((float)(lightDir.x * v20.m128_f32[0]) + (float)(lightDir.y * v21.m128_f32[0]))
                 + (float)(lightDir.z * v22);
  v20.m128_f32[0] = v20.m128_f32[0] - (float)(lightDir.x * *(float *)&v19);
  v21.m128_f32[0] = v21.m128_f32[0] - (float)(lightDir.y * *(float *)&v19);
  v23 = _mm_unpacklo_ps(v20, v21).m128_u64[0];
  cameraUpVector.z = v22 - (float)(lightDir.z * *(float *)&v19);
  v24 = cameraUpVector.z;
  cameraTarget.z = cameraUpVector.z;
  *(_QWORD *)&cameraTarget.x = v23;
  if ( (float)((float)((float)(v20.m128_f32[0] * v20.m128_f32[0]) + (float)(v21.m128_f32[0] * v21.m128_f32[0]))
             + (float)(cameraUpVector.z * cameraUpVector.z)) == 0.0 )
  {
    cameraUpVector.z = 0.0;
    v24 = 0.0;
    v23 = _mm_unpacklo_ps((__m128)LODWORD(FLOAT_1_0), (__m128)0i64).m128_u64[0];
    *(_QWORD *)&cameraTarget.x = v23;
    cameraTarget.z = 0.0;
  }
  cameraUpVector.z = v24;
  *(_QWORD *)&cameraUpVector.x = v23;
  v25 = fsqrt(
          (float)((float)(cameraTarget.y * cameraTarget.y) + (float)(cameraTarget.x * cameraTarget.x))
        + (float)(cameraTarget.z * cameraTarget.z));
  if ( v25 != 0.0 )
  {
    cameraUpVector.y = cameraUpVector.y * (float)(1.0 / v25);
    cameraUpVector.x = cameraTarget.x * (float)(1.0 / v25);
    v23 = *(_QWORD *)&cameraUpVector.x;
    cameraUpVector.z = cameraUpVector.z * (float)(1.0 / v25);
    v24 = cameraUpVector.z;
  }
  v26 = (__m128)LODWORD(lightDir.y);
  v26.m128_f32[0] = lightDir.y + v40;
  *(_QWORD *)&cameraTarget.x = v23;
  cameraTarget.z = v24;
  cameraUpVector.x = lightDir.x + v38;
  cameraUpVector.y = lightDir.y + v40;
  cameraUpVector.z = lightDir.z + v42;
  v27 = (const __m128i *)mat44f::createLookAt(v26, &v49, &cameraPosition, &cameraUpVector, &cameraTarget);
  v28 = FLOAT_N9999999_0;
  v29 = FLOAT_9999999_0;
  v30 = FLOAT_N999999_0;
  v31 = _mm_loadu_si128(v27);
  v32 = corners._Myfirst;
  v33 = corners._Mylast;
  v34 = FLOAT_999999_0;
  v39 = __PAIR64__(LODWORD(FLOAT_N9999999_0), LODWORD(FLOAT_N999999_0));
  v45 = FLOAT_N9999999_0;
  *(__m128i *)&view->M11 = v31;
  *(__m128i *)&view->M21 = _mm_loadu_si128(v27 + 1);
  *(__m128i *)&view->M31 = _mm_loadu_si128(v27 + 2);
  *(__m128i *)&view->M41 = _mm_loadu_si128(v27 + 3);
  *(__m128i *)&result.M11 = _mm_loadu_si128(v27);
  *(__m128i *)&result.M21 = _mm_loadu_si128(v27 + 1);
  *(__m128i *)&result.M31 = _mm_loadu_si128(v27 + 2);
  *(__m128i *)&result.M41 = _mm_loadu_si128(v27 + 3);
  v42 = FLOAT_9999999_0;
  if ( v32 != v33 )
  {
    v35 = &v32->z;
    do
    {
      v28 = (float)((float)((float)(*(v35 - 2) * result.M11) + (float)(*(v35 - 1) * result.M21))
                  + (float)(*v35 * result.M31))
          + result.M41;
      v30 = (float)((float)((float)(*(v35 - 2) * result.M12) + (float)(*(v35 - 1) * result.M22))
                  + (float)(*v35 * result.M32))
          + result.M42;
      v36 = (float)((float)((float)(*(v35 - 2) * result.M13) + (float)(*(v35 - 1) * result.M23))
                  + (float)(*v35 * result.M33))
          + result.M43;
      if ( v29 > v28 )
        v29 = (float)((float)((float)(*(v35 - 2) * result.M11) + (float)(*(v35 - 1) * result.M21))
                    + (float)(*v35 * result.M31))
            + result.M41;
      if ( v34 > v30 )
        v34 = (float)((float)((float)(*(v35 - 2) * result.M12) + (float)(*(v35 - 1) * result.M22))
                    + (float)(*v35 * result.M32))
            + result.M42;
      if ( v42 > v36 )
        v42 = (float)((float)((float)(*(v35 - 2) * result.M13) + (float)(*(v35 - 1) * result.M23))
                    + (float)(*v35 * result.M33))
            + result.M43;
      if ( v28 <= *((float *)&v39 + 1) )
        v28 = *((float *)&v39 + 1);
      else
        *((float *)&v39 + 1) = v28;
      if ( v30 <= *(float *)&v39 )
        v30 = *(float *)&v39;
      else
        *(float *)&v39 = v30;
      if ( v36 > v45 )
        v45 = v36;
      v35 += 3;
    }
    while ( v35 - 2 != (float *)v33 );
  }
  v37 = (__m128i *)v47;
  result.M14 = 0.0;
  result.M13 = 0.0;
  result.M12 = 0.0;
  result.M24 = 0.0;
  result.M23 = 0.0;
  result.M21 = 0.0;
  result.M33 = -0.001;
  result.M34 = 0.0;
  result.M32 = 0.0;
  result.M31 = 0.0;
  result.M43 = 0.5;
  result.M44 = 1.0;
  LOBYTE(v52) = 0;
  result.M11 = 2.0 / (float)(v28 - v29);
  result.M22 = 2.0 / (float)(v30 - v34);
  result.M41 = (float)(v28 + v29) / (float)(v29 - v28);
  result.M42 = (float)(v30 + v34) / (float)(v34 - v30);
  *(__m128i *)&v47->M11 = _mm_loadu_si128((const __m128i *)&result);
  v37[1] = _mm_loadu_si128((const __m128i *)&result.M21);
  v37[2] = _mm_loadu_si128((const __m128i *)&result.M31);
  v37[3] = _mm_loadu_si128((const __m128i *)&result.M41);
  if ( v32 )
  {
    std::_Container_base0::_Orphan_all(&corners);
    operator delete(corners._Myfirst);
    corners._Myfirst = 0;
    corners._Mylast = 0;
    corners._Myend = 0;
  }
  v52 = -1;
  BoundingFrustum::~BoundingFrustum(&v51);
}
void CameraShadowMapped::initShadowRenderTargets(CameraShadowMapped *this)
{
  RenderTarget **v2; // esi
  RenderTarget **v3; // edi
  int i; // ebx
  RenderTarget *v5; // eax
  RenderTarget *v6; // eax

  v2 = this->shadowRT._Myfirst;
  v3 = this->shadowRT._Mylast;
  for ( i = this->graphics->videoSettings.shadowMapSize; v2 != v3; ++v2 )
  {
    v5 = (RenderTarget *)operator new(28);
    if ( v5 )
      RenderTarget::RenderTarget(v5, this->graphics, eR32F, i, i, 0, 1, 1);
    else
      v6 = 0;
    *v2 = v6;
  }
}
void CameraShadowMapped::render(CameraShadowMapped *this, Node *root, float dt)
{
  KGLRenderTarget *v4; // eax
  KGLRenderTarget *v5; // [esp+8h] [ebp-8h]

  ((void (*)(CameraShadowMapped *, Node *, _DWORD))this->shadowMapPass)(this, root, LODWORD(dt));
  v5 = kglGetScreenDepthTarget();
  v4 = kglGetScreenRenderTarget();
  kglSetRenderTargets(v4, v5);
  ((void (*)(CameraShadowMapped *, Node *, _DWORD))this->renderPass)(this, root, LODWORD(dt));
}
void CameraShadowMapped::renderPass(CameraShadowMapped *this, Node *root, float dt)
{
  GraphicsManager *v4; // ecx
  RenderTarget *v5; // eax
  eAxisRendering v6; // eax
  GraphicsManager *v7; // ecx
  GraphicsManager *v8; // ecx
  GraphicsManager *v9; // ecx
  RenderContext rc; // [esp+Ch] [ebp-B0h] BYREF
  MaterialFilter materialFilter; // [esp+1Ch] [ebp-A0h] BYREF
  RenderContext rcTR; // [esp+24h] [ebp-98h] BYREF
  CameraMeshFilter filterTR; // [esp+34h] [ebp-88h] BYREF
  CameraMeshFilter filter; // [esp+44h] [ebp-78h] BYREF
  mat44f id; // [esp+54h] [ebp-68h] BYREF
  std::wstring name; // [esp+94h] [ebp-28h] BYREF
  int v17; // [esp+B8h] [ebp-4h]

  if ( (dword_186EE20 & 1) == 0 )
  {
    perfCounter_4.name = "CameraShadowMapped::renderPass";
    dword_186EE20 |= 1u;
    perfCounter_4.group = Render;
    perfCounter_4.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"CameraShadowMapped::renderPass" | 0xFF000000;
  }
  GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
  CameraMeshFilter::CameraMeshFilter(&filter, this, Opaque, (int)this->maxLayer);
  v17 = 0;
  MaterialFilter::MaterialFilter(&materialFilter);
  v4 = this->graphics;
  rc.materialFilter = &materialFilter;
  rc.meshFilter = &filter;
  v5 = this->renderTarget;
  LOBYTE(v17) = 1;
  rc.graphics = v4;
  rc.camera = this;
  if ( v5 )
    GraphicsManager::setRenderTarget(v4, v5);
  GraphicsManager::setCullMode(this->graphics, eCullFront);
  Camera::renderCamera(this);
  Camera::clearBuffers(this);
  if ( this->skyBox )
  {
    mat44f::mat44f(&id);
    mat44f::loadIdentity(&id);
    GraphicsManager::setWorldMatrix(this->graphics, &id);
    GraphicsManager::setDepthMode(this->graphics, eDepthOff);
    PvsProcessor::begin(this->graphics->pvsProcessor, &rc, Default, 0, 0);
    SkyBox::render(this->skyBox, &rc);
    PvsProcessor::end(this->graphics->pvsProcessor);
    GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
  }
  PvsProcessor::begin(this->graphics->pvsProcessor, &rc, Default, &this->shadowRT, this->graphics->currentCubeMap);
  root->render(root, &rc);
  PvsProcessor::end(this->graphics->pvsProcessor);
  v6 = this->axisRenderingMode;
  if ( v6 )
    Camera::renderAxis(this, v6 == eAxisBefore3d);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"MAIN_PASS", 9u);
  v7 = this->graphics;
  LOBYTE(v17) = 2;
  GPUProfiler::triggerQuery(v7->gpuProfiler, &name);
  LOBYTE(v17) = 1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  CameraMeshFilter::CameraMeshFilter(&filterTR, this, Transparent, (int)this->maxLayer);
  v8 = this->graphics;
  rcTR.materialFilter = &materialFilter;
  LOBYTE(v17) = 3;
  rcTR.meshFilter = &filterTR;
  rcTR.graphics = v8;
  rcTR.camera = this;
  GraphicsManager::setDepthMode(v8, eDepthNoWrite);
  PvsProcessor::begin(this->graphics->pvsProcessor, &rcTR, Default, 0, 0);
  root->render(root, &rcTR);
  PvsProcessor::end(this->graphics->pvsProcessor);
  GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"TRANS_PASS", 0xAu);
  v9 = this->graphics;
  LOBYTE(v17) = 4;
  GPUProfiler::triggerQuery(v9->gpuProfiler, &name);
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  LOBYTE(v17) = 1;
  CameraMeshFilter::~CameraMeshFilter(&filterTR);
  LOBYTE(v17) = 0;
  MaterialFilter::~MaterialFilter(&materialFilter);
  v17 = -1;
  CameraMeshFilter::~CameraMeshFilter(&filter);
}
void CameraShadowMapped::setShadowMapsSplits(CameraShadowMapped *this, float s1, float s2, float s3, float s4)
{
  this->shadowMapSettings._Myfirst->nearSplit = 0.0;
  this->shadowMapSettings._Myfirst->farSplit = s1;
  this->shadowMapSettings._Myfirst[1].nearSplit = s1;
  this->shadowMapSettings._Myfirst[1].farSplit = s2;
  this->shadowMapSettings._Myfirst[2].nearSplit = s2;
  this->shadowMapSettings._Myfirst[2].farSplit = s3;
  this->shadowMapSettings._Myfirst[3].nearSplit = s3;
  this->shadowMapSettings._Myfirst[3].farSplit = s4;
  GraphicsManager::setShadowMapBias(
    this->graphics,
    (float)(this->shadowBias * s1) * 0.001,
    (float)((float)(s2 - s1) * this->shadowBias) * 0.001,
    (float)((float)(s3 - s2) * this->shadowBias) * 0.001);
}
void __userpurge CameraShadowMapped::shadowMapPass(CameraShadowMapped *this@<ecx>, unsigned int a2@<ebx>, Node *root, float dt)
{
  int v5; // eax
  GraphicsManager *v6; // eax
  int v7; // edi
  __m128i v8; // xmm0
  int v9; // ebx
  RenderContext rc; // [esp+14h] [ebp-84h] BYREF
  CameraMeshFilter filter; // [esp+24h] [ebp-74h] BYREF
  MaterialFilterSM materialFilter; // [esp+34h] [ebp-64h] BYREF
  mat44f matForShadow; // [esp+4Ch] [ebp-4Ch] BYREF
  int v14; // [esp+94h] [ebp-4h]

  if ( (dword_186EE04 & 1) == 0 )
  {
    perfCounter_2.name = "CameraShadowMapped::shadowMapPass";
    dword_186EE04 |= 1u;
    perfCounter_2.group = Render;
    perfCounter_2.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"CameraShadowMapped::shadowMapPass" | 0xFF000000;
  }
  GraphicsManager::setDepthMode(this->graphics, eDepthNormal);
  GraphicsManager::setBlendMode(this->graphics, eOpaque);
  MaterialFilterSM::MaterialFilterSM(&materialFilter, a2, this->graphics);
  v5 = (int)this->maxLayer;
  v14 = 0;
  CameraMeshFilter::CameraMeshFilter(&filter, this, Shadowgen, v5);
  v6 = this->graphics;
  v7 = 0;
  *(__m128i *)&matForShadow.M11 = _mm_loadu_si128((const __m128i *)&this->matrix);
  rc.materialFilter = &materialFilter;
  v8 = _mm_loadu_si128((const __m128i *)&this->matrix.M21);
  LOBYTE(v14) = 1;
  v9 = 0;
  rc.meshFilter = &filter;
  *(__m128i *)&matForShadow.M21 = v8;
  rc.graphics = v6;
  rc.camera = this;
  *(__m128i *)&matForShadow.M31 = _mm_loadu_si128((const __m128i *)&this->matrix.M31);
  *(__m128i *)&matForShadow.M41 = _mm_loadu_si128((const __m128i *)&this->matrix.M41);
  do
  {
    if ( (dword_186EE04 & 2) == 0 )
    {
      perfCounter_3.name = "CameraShadowMapped::shadowMapPass (pass)";
      dword_186EE04 |= 2u;
      perfCounter_3.group = Render;
      perfCounter_3.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"CameraShadowMapped::shadowMapPass (pass)" | 0xFF000000;
    }
    CameraShadowMapped::beginShadowMapPass(this, v7, &rc, &matForShadow);
    PvsProcessor::begin(this->graphics->pvsProcessor, &rc, Particle, 0, 0);
    root->render(root, &rc);
    PvsProcessor::end(this->graphics->pvsProcessor);
    kglSetRenderTargets(0, 0);
    GraphicsManager::setShadowMapTexture(this->graphics, v7, this->shadowRT._Myfirst[v7]);
    GraphicsManager::setShadowMapMatrix(this->graphics, v7++, &this->shadowMatrices._Myfirst[v9++]);
  }
  while ( v7 < 3 );
  LOBYTE(v14) = 0;
  CameraMeshFilter::~CameraMeshFilter(&filter);
  v14 = -1;
  MaterialFilterSM::~MaterialFilterSM(&materialFilter);
}
