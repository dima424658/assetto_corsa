#include "skybox.h"
void __userpurge SkyBox::SkyBox(SkyBox *this@<ecx>, unsigned int a2@<ebx>, GraphicsManager *graphics)
{
  std::shared_ptr<Material> *v4; // eax
  std::_Ref_count_base *v5; // edi
  Mesh *v6; // eax
  GraphicsManager *v7; // edi
  GraphicsManager *v8; // ecx
  const std::wstring *v9; // eax
  Shader *v10; // eax
  bool v11; // cf
  Shader *v12; // eax
  double v13; // st7
  _BYTE v14[28]; // [esp+4h] [ebp-11Ch] BYREF
  GraphicsManager *v15; // [esp+30h] [ebp-F0h] BYREF
  std::shared_ptr<Material> result; // [esp+34h] [ebp-ECh] BYREF
  SkyBox *v17; // [esp+3Ch] [ebp-E4h]
  std::wstring name; // [esp+40h] [ebp-E0h] BYREF
  std::wstring key; // [esp+58h] [ebp-C8h] BYREF
  std::wstring v20; // [esp+70h] [ebp-B0h] BYREF
  INIReaderDocuments ini; // [esp+88h] [ebp-98h] BYREF
  INIReader graphicsINI; // [esp+CCh] [ebp-54h] BYREF
  int v23; // [esp+11Ch] [ebp-4h]

  this->__vftable = (SkyBox_vtbl *)&SkyBox::`vftable';
  this->mesh = 0;
  this->graphics = graphics;
  this->commonBoundingSphere.center.x = 0.0;
  this->commonBoundingSphere.center.y = 0.0;
  this->commonBoundingSphere.center.z = 0.0;
  this->commonBoundingSphere.radius = 0.0;
  this->cloudsShader = 0;
  this->cubemapSkyShader = 0;
  this->skyboxGain = 1.0;
  this->settings.cloudWidth = 4.0;
  this->settings.cloudHeight = 2.0;
  this->settings.cloudRadius = 4.0;
  this->settings.baseSpeedMult = 0.0099999998;
  this->settings.numberOfClouds = 100;
  v17 = this;
  v15 = graphics;
  this->cloudTextures._Myfirst = 0;
  this->cloudTextures._Mylast = 0;
  this->cloudTextures._Myend = 0;
  v23 = 0;
  this->clouds._Myfirst = 0;
  this->clouds._Mylast = 0;
  this->clouds._Myend = 0;
  LOBYTE(v23) = 1;
  *(_DWORD *)&v14[24] = 7;
  *(_DWORD *)&v14[20] = 0;
  *(_WORD *)&v14[4] = 0;
  std::wstring::assign((std::wstring *)&v14[4], L"SkyBox", 6u);
  this->mesh = ShapeBuilder::buildHemiSphere(10.0, 12, *(std::wstring *)&v14[4]);
  v4 = std::make_shared<Material,wchar_t const (&)[19],GraphicsManager * &>(
         &result,
         (const wchar_t (*)[16])L"SKYBOX MATERIAL",
         &v15);
  std::shared_ptr<Material>::operator=(&this->mesh->material, v4);
  v5 = result._Rep;
  if ( result._Rep )
  {
    a2 = -1;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)&result._Rep->_Uses, 0xFFFFFFFF) )
    {
      v5->_Destroy(v5);
      a2 = _InterlockedDecrement((volatile signed __int32 *)&v5->_Weaks);
      if ( !a2 )
        v5->_Delete_this(v5);
    }
  }
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksSky", 5u);
  v6 = this->mesh;
  LOBYTE(v23) = 2;
  Material::setShader(v6->material._Ptr, a2, &name);
  LOBYTE(v23) = 1;
  if ( name._Myres >= 8 )
    operator delete(name._Bx._Ptr);
  v7 = v15;
  v8 = v15;
  this->mesh->material._Ptr->depthMode = eDepthOff;
  this->mesh->material._Ptr->blendMode = eOpaque;
  this->mesh->noCull = 1;
  GraphicsManager::compile(v8, this->mesh);
  *(_DWORD *)&v14[24] = 0;
  *(_DWORD *)&v14[20] = 7;
  *(_DWORD *)&v14[16] = 0;
  *(_WORD *)v14 = 0;
  std::wstring::assign((std::wstring *)v14, L"cfg/race.ini", 0xCu);
  INIReaderDocuments::INIReaderDocuments(&ini, a2, *(std::wstring *)v14, v14[24]);
  LOBYTE(v23) = 3;
  if ( ini.ready )
  {
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"WEATHER", 7u);
    LOBYTE(v23) = 4;
    LOBYTE(a2) = INIReader::hasSection(&ini, &name);
    LOBYTE(v23) = 3;
    if ( name._Myres >= 8 )
      operator delete(name._Bx._Ptr);
    if ( (_BYTE)a2 )
    {
      std::wstring::wstring(&key, L"NAME");
      LOBYTE(v23) = 5;
      std::wstring::wstring(&name, L"WEATHER");
      LOBYTE(v23) = 6;
      v9 = INIReader::getString(&ini, &v20, &name, &key);
      LOBYTE(v23) = 7;
      SkyBox::updateCloudsGeneration(this, v9);
      if ( v20._Myres >= 8 )
        operator delete(v20._Bx._Ptr);
      v20._Myres = 7;
      v20._Mysize = 0;
      v20._Bx._Buf[0] = 0;
      if ( name._Myres >= 8 )
        operator delete(name._Bx._Ptr);
      name._Myres = 7;
      name._Mysize = 0;
      name._Bx._Buf[0] = 0;
      LOBYTE(v23) = 3;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
  }
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksClouds", 8u);
  LOBYTE(v23) = 8;
  v10 = GraphicsManager::getShader(v7, a2, &name);
  v11 = name._Myres < 8;
  this->cloudsShader = v10;
  LOBYTE(v23) = 3;
  if ( !v11 )
    operator delete(name._Bx._Ptr);
  name._Myres = 7;
  name._Mysize = 0;
  name._Bx._Buf[0] = 0;
  std::wstring::assign(&name, L"ksSkyCubemap", 0xCu);
  LOBYTE(v23) = 9;
  v12 = GraphicsManager::getShader(v7, a2, &name);
  v11 = name._Myres < 8;
  this->cubemapSkyShader = v12;
  LOBYTE(v23) = 3;
  if ( !v11 )
    operator delete(name._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  std::wstring::assign(&key, L"system/cfg/graphics.ini", 0x17u);
  LOBYTE(v23) = 10;
  INIReader::INIReader(&graphicsINI, &key);
  LOBYTE(v23) = 12;
  if ( key._Myres >= 8 )
    operator delete(key._Bx._Ptr);
  key._Myres = 7;
  key._Mysize = 0;
  key._Bx._Buf[0] = 0;
  if ( graphicsINI.ready )
  {
    v20._Myres = 7;
    v20._Mysize = 0;
    v20._Bx._Buf[0] = 0;
    std::wstring::assign(&v20, L"SKYBOX_REFLECTION_GAIN", 0x16u);
    LOBYTE(v23) = 13;
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    std::wstring::assign(&name, L"DX11", 4u);
    LOBYTE(v23) = 14;
    v13 = INIReader::getFloat(&graphicsINI, &name, &v20);
    v11 = name._Myres < 8;
    this->skyboxGain = v13;
    if ( !v11 )
      operator delete(name._Bx._Ptr);
    name._Myres = 7;
    name._Mysize = 0;
    name._Bx._Buf[0] = 0;
    if ( v20._Myres >= 8 )
      operator delete(v20._Bx._Ptr);
  }
  LOBYTE(v23) = 3;
  INIReader::~INIReader(&graphicsINI);
  LOBYTE(v23) = 1;
  INIReaderDocuments::~INIReaderDocuments(&ini);
}
SkyBox *SkyBox::`vector deleting destructor'(SkyBox *this, unsigned int a2)
{
  Mesh *v3; // ecx

  this->__vftable = (SkyBox_vtbl *)&SkyBox::`vftable';
  v3 = this->mesh;
  if ( v3 )
    ((void (*)(Mesh *, int))v3->~Node)(v3, 1);
  std::vector<SkyBox::CloudBillboard>::_Tidy(&this->clouds);
  std::vector<Texture>::_Tidy(&this->cloudTextures);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
void SkyBox::render(SkyBox *this, RenderContext *rc)
{
  SkyBox *v2; // esi
  GraphicsManager *v3; // edx
  __m128 v4; // xmm3
  __m128 v5; // xmm1
  float v6; // xmm0_4
  float v7; // xmm2_4
  GraphicsManager *v8; // ecx
  float v9; // xmm2_4
  __m128 v10; // xmm3
  __m128 v11; // xmm1
  float v12; // xmm0_4
  GraphicsManager *v13; // ecx
  float v14; // xmm2_4
  __m128 v15; // xmm3
  __m128 v16; // xmm1
  float v17; // xmm0_4
  GraphicsManager *v18; // ecx
  float v19; // xmm2_4
  __m128 v20; // xmm3
  __m128 v21; // xmm1
  float v22; // xmm0_4
  GraphicsManager *v23; // ecx
  float v24; // xmm2_4
  __m128 v25; // xmm3
  __m128 v26; // xmm1
  float v27; // xmm0_4
  GraphicsManager *v28; // ecx
  float v29; // xmm2_4
  __m128 v30; // xmm3
  __m128 v31; // xmm1
  float v32; // xmm0_4
  GraphicsManager *v33; // ecx
  float v34; // xmm2_4
  __m128 v35; // xmm3
  __m128 v36; // xmm1
  float v37; // xmm0_4
  Material *v38; // ecx
  Shader *v39; // ebx
  Mesh *v40; // ecx
  LightingSettings os; // [esp+20h] [ebp-B8h] BYREF

  v2 = this;
  if ( (dword_186EE9C & 1) == 0 )
  {
    perfCounter_5.name = "SkyBox::render";
    dword_186EE9C |= 1u;
    perfCounter_5.group = Render;
    perfCounter_5.color = ((unsigned int)&loc_7F7F7E + 1) & (unsigned int)"SkyBox::render" | 0xFF000000;
  }
  if ( rc->camera->isCubeMapCamera )
  {
    v3 = this->graphics;
    v4 = (__m128)LODWORD(v3->lightingSettings.ambientHigh.x);
    v5 = (__m128)LODWORD(v3->lightingSettings.ambientHigh.y);
    v6 = v3->lightingSettings.ambientHigh.z;
    qmemcpy(&os, &v3->lightingSettings, sizeof(os));
    v7 = this->skyboxGain;
    v4.m128_f32[0] = v4.m128_f32[0] * v7;
    v5.m128_f32[0] = v5.m128_f32[0] * v7;
    *(_QWORD *)&v3->lightingSettings.ambientHigh.x = _mm_unpacklo_ps(v4, v5).m128_u64[0];
    v3->lightingSettings.ambientHigh.z = v6 * v7;
    v8 = this->graphics;
    v9 = this->skyboxGain;
    v10 = (__m128)LODWORD(v9);
    v10.m128_f32[0] = v9 * v8->lightingSettings.ambientLow.x;
    v11 = (__m128)LODWORD(v8->lightingSettings.ambientLow.y);
    v11.m128_f32[0] = v11.m128_f32[0] * v9;
    v12 = v8->lightingSettings.ambientLow.z * v9;
    *(_QWORD *)&v8->lightingSettings.ambientLow.x = _mm_unpacklo_ps(v10, v11).m128_u64[0];
    v8->lightingSettings.ambientLow.z = v12;
    v13 = this->graphics;
    v14 = this->skyboxGain;
    v15 = (__m128)LODWORD(v13->lightingSettings.horizonHigh.x);
    v16 = (__m128)LODWORD(v13->lightingSettings.horizonHigh.y);
    v15.m128_f32[0] = v15.m128_f32[0] * v14;
    v16.m128_f32[0] = v16.m128_f32[0] * v14;
    v17 = v13->lightingSettings.horizonHigh.z * v14;
    *(_QWORD *)&v13->lightingSettings.horizonHigh.x = _mm_unpacklo_ps(v15, v16).m128_u64[0];
    v13->lightingSettings.horizonHigh.z = v17;
    v18 = this->graphics;
    v19 = this->skyboxGain;
    v20 = (__m128)LODWORD(v18->lightingSettings.horizonLow.x);
    v21 = (__m128)LODWORD(v18->lightingSettings.horizonLow.y);
    v20.m128_f32[0] = v20.m128_f32[0] * v19;
    v21.m128_f32[0] = v21.m128_f32[0] * v19;
    v22 = v18->lightingSettings.horizonLow.z * v19;
    *(_QWORD *)&v18->lightingSettings.horizonLow.x = _mm_unpacklo_ps(v20, v21).m128_u64[0];
    v18->lightingSettings.horizonLow.z = v22;
    v23 = this->graphics;
    v24 = this->skyboxGain;
    v25 = (__m128)LODWORD(v23->lightingSettings.lightColor.x);
    v26 = (__m128)LODWORD(v23->lightingSettings.lightColor.y);
    v25.m128_f32[0] = v25.m128_f32[0] * v24;
    v26.m128_f32[0] = v26.m128_f32[0] * v24;
    v27 = v23->lightingSettings.lightColor.z * v24;
    *(_QWORD *)&v23->lightingSettings.lightColor.x = _mm_unpacklo_ps(v25, v26).m128_u64[0];
    v23->lightingSettings.lightColor.z = v27;
    v28 = this->graphics;
    v29 = this->skyboxGain;
    v30 = (__m128)LODWORD(v28->lightingSettings.skyLow.x);
    v31 = (__m128)LODWORD(v28->lightingSettings.skyLow.y);
    v30.m128_f32[0] = v30.m128_f32[0] * v29;
    v31.m128_f32[0] = v31.m128_f32[0] * v29;
    v32 = v28->lightingSettings.skyLow.z * v29;
    *(_QWORD *)&v28->lightingSettings.skyLow.x = _mm_unpacklo_ps(v30, v31).m128_u64[0];
    v28->lightingSettings.skyLow.z = v32;
    v33 = this->graphics;
    v34 = this->skyboxGain;
    v35 = (__m128)LODWORD(v34);
    v36 = (__m128)LODWORD(v33->lightingSettings.skyHigh.y);
    v35.m128_f32[0] = v34 * v33->lightingSettings.skyHigh.x;
    v36.m128_f32[0] = v36.m128_f32[0] * v34;
    v37 = v33->lightingSettings.skyHigh.z * v34;
    *(_QWORD *)&v33->lightingSettings.skyHigh.x = _mm_unpacklo_ps(v35, v36).m128_u64[0];
    v33->lightingSettings.skyHigh.z = v37;
    v38 = this->mesh->material._Ptr;
    v39 = v38->shader;
    v38->shader = this->cubemapSkyShader;
    GraphicsManager::updateLightingSetttings(this->graphics);
    this->mesh->render(this->mesh, rc);
    qmemcpy(&this->graphics->lightingSettings, &os, sizeof(this->graphics->lightingSettings));
    GraphicsManager::updateLightingSetttings(this->graphics);
    this->mesh->material._Ptr->shader = v39;
    SkyBox::renderClouds(this, rc);
  }
  else
  {
    v40 = this->mesh;
    if ( v40 )
      v40->render(v40, rc);
    SkyBox::renderClouds(v2, rc);
  }
}
void SkyBox::renderClouds(SkyBox *this, RenderContext *rc)
{
  SkyBox *v2; // esi
  GraphicsManager *v3; // eax
  SkyBox::CloudBillboard *v4; // edi
  SkyBox::CloudBillboard *v5; // esi
  Camera *v6; // eax
  float v7; // xmm0_4
  __m128 v8; // xmm2
  Camera *v9; // eax
  __int64 v10; // xmm1_8
  __m128 v11; // xmm3
  __m128 v12; // xmm2
  __m128 v13; // xmm6
  float v14; // xmm7_4
  float v15; // xmm2_4
  float v16; // xmm0_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm2_4
  float v20; // xmm0_4
  __m128 v21; // xmm1
  __m128 v22; // xmm0
  float v23; // xmm5_4
  float v24; // xmm6_4
  float v25; // xmm3_4
  float v26; // xmm2_4
  float v27; // xmm4_4
  unsigned int v28; // xmm0_4
  BoundingFrustum *v29; // ecx
  GLRenderer *v30; // [esp+24h] [ebp-ACh]
  float v31; // [esp+28h] [ebp-A8h]
  float v32; // [esp+28h] [ebp-A8h]
  float v33; // [esp+28h] [ebp-A8h]
  float v34; // [esp+2Ch] [ebp-A4h]
  float v35; // [esp+2Ch] [ebp-A4h]
  float v36; // [esp+2Ch] [ebp-A4h]
  float v37; // [esp+30h] [ebp-A0h]
  float v38; // [esp+30h] [ebp-A0h]
  float v40; // [esp+38h] [ebp-98h]
  float v41; // [esp+38h] [ebp-98h]
  float v42; // [esp+3Ch] [ebp-94h]
  float v43; // [esp+3Ch] [ebp-94h]
  sphere *s; // [esp+40h] [ebp-90h]
  unsigned __int64 v45; // [esp+44h] [ebp-8Ch]
  mat44f matrix; // [esp+50h] [ebp-80h] BYREF
  __int64 v47; // [esp+90h] [ebp-40h] BYREF
  __m128i v48; // [esp+98h] [ebp-38h] BYREF
  unsigned int v49; // [esp+B0h] [ebp-20h]
  float v50; // [esp+BCh] [ebp-14h]
  __m128 v51; // [esp+C0h] [ebp-10h]

  v2 = this;
  if ( this->clouds._Myfirst != this->clouds._Mylast )
  {
    GraphicsManager::setCullMode(this->graphics, eCullFront);
    GraphicsManager::setDepthMode(v2->graphics, eDepthOff);
    GraphicsManager::setBlendMode(v2->graphics, eAlphaBlend);
    v3 = v2->graphics;
    v4 = v2->clouds._Mylast;
    v5 = v2->clouds._Myfirst;
    v30 = v3->gl;
    if ( v5 != v4 )
    {
      s = &this->commonBoundingSphere;
      do
      {
        v6 = rc->camera;
        *(__m128i *)&matrix.M11 = _mm_loadu_si128((const __m128i *)&v6->matrix);
        *(__m128i *)&matrix.M21 = _mm_loadu_si128((const __m128i *)&v6->matrix.M21);
        *(__m128i *)&matrix.M31 = _mm_loadu_si128((const __m128i *)&v6->matrix.M31);
        v48 = _mm_loadu_si128((const __m128i *)&v6->matrix.M41);
        *(__m128i *)&matrix.M41 = v48;
        v34 = v5->radius_mt * __libm_sse2_sinf().m128_f32[0];
        v40 = __libm_sse2_cosf().m128_f32[0] * v34;
        v31 = __libm_sse2_cosf().m128_f32[0] * v5->radius_mt;
        v7 = __libm_sse2_sinf().m128_f32[0];
        v8 = (__m128)_mm_loadu_si128(&v48);
        v9 = rc->camera;
        HIDWORD(v10) = v8.m128_i32[1];
        v11 = _mm_shuffle_ps(v8, v8, 85);
        *(float *)&v10 = v8.m128_f32[0] + v40;
        v11.m128_f32[0] = v11.m128_f32[0] + v31;
        v12 = _mm_shuffle_ps(v8, v8, 170);
        v12.m128_f32[0] = v12.m128_f32[0] + COERCE_FLOAT(COERCE_UNSIGNED_INT(v7 * v34) ^ _xmm);
        LODWORD(matrix.M41) = v10;
        LODWORD(matrix.M42) = v11.m128_i32[0];
        v13 = v11;
        v47 = v10;
        LODWORD(matrix.M43) = v12.m128_i32[0];
        v13.m128_f32[0] = v11.m128_f32[0] - v9->matrix.M42;
        v14 = *(float *)&v10 - v9->matrix.M41;
        v48 = (__m128i)v12;
        v15 = v12.m128_f32[0] - v9->matrix.M43;
        v51 = v11;
        v32 = v13.m128_f32[0];
        v41 = v15;
        v16 = fsqrt((float)((float)(v13.m128_f32[0] * v13.m128_f32[0]) + (float)(v14 * v14)) + (float)(v15 * v15));
        if ( v16 != 0.0 )
        {
          v15 = v15 * (float)(1.0 / v16);
          v13.m128_f32[0] = v13.m128_f32[0] * (float)(1.0 / v16);
          v14 = v14 * (float)(1.0 / v16);
          v32 = v13.m128_f32[0];
          v41 = v15;
        }
        v35 = v13.m128_f32[0] * 0.0;
        v17 = (float)(v14 * -1.0) - (float)(v13.m128_f32[0] * 0.0);
        v18 = (float)(v13.m128_f32[0] * 0.0) - (float)(v15 * -1.0);
        v42 = v14 * 0.0;
        v37 = v15 * 0.0;
        v19 = (float)(v15 * 0.0) - (float)(v14 * 0.0);
        v20 = fsqrt((float)((float)(v19 * v19) + (float)(v18 * v18)) + (float)(v17 * v17));
        if ( v20 != 0.0 )
        {
          v17 = v17 * (float)(1.0 / v20);
          v18 = v18 * (float)(1.0 / v20);
          v19 = (float)(1.0 / v20) * v19;
        }
        if ( v18 == 0.0 && v19 == 0.0 && v17 == 0.0 )
        {
          v21 = (__m128)LODWORD(v37);
          v22 = v13;
          v22.m128_f32[0] = v13.m128_f32[0] - v37;
          v21.m128_f32[0] = v37 - v14;
          v50 = v42 - v35;
          v45 = _mm_unpacklo_ps(v22, v21).m128_u64[0];
          v19 = *((float *)&v45 + 1);
          v18 = *(float *)&v45;
          v17 = v42 - v35;
        }
        v23 = (float)(v17 * v13.m128_f32[0]) - (float)(v19 * v41);
        v24 = (float)(v18 * v41) - (float)(v17 * v14);
        v25 = v32;
        v26 = (float)(v19 * v14) - (float)(v18 * v32);
        v27 = fsqrt((float)((float)(v24 * v24) + (float)(v23 * v23)) + (float)(v26 * v26));
        if ( v27 != 0.0 )
        {
          v26 = v26 * (float)(1.0 / v27);
          v23 = (float)(1.0 / v27) * v23;
          v24 = v24 * (float)(1.0 / v27);
        }
        v33 = (float)(v26 * v32) - (float)(v24 * v41);
        v36 = (float)(v23 * v41) - (float)(v26 * v14);
        v38 = (float)(v24 * v14) - (float)(v23 * v25);
        v43 = fsqrt(
                (float)((float)(v36 * v36)
                      + (float)((float)((float)(v26 * v25) - (float)(v24 * v41))
                              * (float)((float)(v26 * v25) - (float)(v24 * v41))))
              + (float)(v38 * v38));
        if ( v43 != 0.0 )
        {
          v33 = (float)(1.0 / v43) * v33;
          v36 = (float)(1.0 / v43) * v36;
          v38 = (float)(1.0 / v43) * v38;
        }
        LODWORD(matrix.M31) = LODWORD(v14) ^ _xmm;
        LODWORD(matrix.M32) = LODWORD(v25) ^ _xmm;
        matrix.M11 = v33;
        matrix.M12 = v36;
        matrix.M13 = v38;
        v28 = _mm_loadu_si128(&v48).m128i_u32[0];
        LODWORD(matrix.M33) = LODWORD(v41) ^ _xmm;
        v49 = v28;
        *(_QWORD *)&s->center.x = _mm_unpacklo_ps((__m128)_mm_loadl_epi64((const __m128i *)&v47), v51).m128_u64[0];
        LODWORD(this->commonBoundingSphere.center.z) = v28;
        v29 = &rc->camera->frustum;
        matrix.M21 = v23;
        matrix.M22 = v24;
        matrix.M23 = v26;
        if ( BoundingFrustum::intersect(v29, s) )
        {
          GraphicsManager::setWorldMatrix(this->graphics, &matrix);
          GraphicsManager::setTexture(this->graphics, 0, &v5->texture);
          GLRenderer::begin(v30, eQuads, this->cloudsShader);
          GLRenderer::color4f(v30, 0.0, -1.0, 0.0, 0.0);
          GLRenderer::texCoord2f(v30, 0.0, 1.0);
          GLRenderer::vertex3f(v30, this->settings.cloudWidth * -0.5, this->settings.cloudHeight * -0.5, 0.0);
          GLRenderer::texCoord2f(v30, 1.0, 1.0);
          GLRenderer::vertex3f(v30, this->settings.cloudWidth * 0.5, this->settings.cloudHeight * -0.5, 0.0);
          GLRenderer::texCoord2f(v30, 1.0, 0.0);
          GLRenderer::vertex3f(v30, this->settings.cloudWidth * 0.5, this->settings.cloudHeight * 0.5, 0.0);
          GLRenderer::texCoord2f(v30, 0.0, 0.0);
          GLRenderer::vertex3f(v30, this->settings.cloudWidth * -0.5, this->settings.cloudHeight * 0.5, 0.0);
          GLRenderer::end(v30);
        }
        ++v5;
      }
      while ( v5 != v4 );
    }
  }
}
void SkyBox::updateCloudsAnimation(SkyBox *this, float dt)
{
  SkyBox::CloudBillboard *v2; // edx
  SkyBox::CloudBillboard *i; // eax

  v2 = this->clouds._Mylast;
  for ( i = this->clouds._Myfirst; i != v2; ++i )
    i->phi_rad = (float)(i->speedMult * dt) + i->phi_rad;
}
void SkyBox::updateCloudsGeneration(SkyBox *this, const std::wstring *weatherName)
{
  SkyBox *v2; // edi
  const std::wstring *v3; // eax
  std::vector<SkyBox::CloudBillboard> *v4; // esi
  SkyBox::CloudBillboard *v5; // edi
  SkyBox::CloudBillboard *v6; // esi
  int v7; // eax
  Texture *v8; // esi
  Texture *v9; // edi
  std::wstring *v10; // eax
  char v11; // al
  double v12; // st7
  bool v13; // cf
  double v14; // st7
  double v15; // st7
  double v16; // st7
  double v17; // st7
  std::wstring *v18; // esi
  std::wstring *v19; // edi
  SkyBox *v20; // edi
  float v21; // xmm2_4
  int v22; // eax
  int v23; // eax
  float v24; // xmm0_4
  wchar_t *v25; // xmm0_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm1_4
  unsigned int v29; // eax
  Texture *v30; // ecx
  const std::wstring *v31; // eax
  SkyBox::CloudBillboard *v32; // eax
  SkyBox::CloudBillboard *v33; // ecx
  std::wstring *v34; // eax
  int v35; // ecx
  _DWORD *v36; // edx
  std::wstring *v37; // ecx
  std::wstring *v38; // eax
  std::wstring *v39; // ecx
  __m128 v40; // xmm1
  __m128 v41; // xmm0
  int v42; // xmm2_4
  std::wstring *v43; // edi
  std::wstring *v44; // esi
  std::wstring *v45; // [esp-4h] [ebp-148h]
  int v46; // [esp+0h] [ebp-144h]
  int v47; // [esp+4h] [ebp-140h]
  std::vector<SkyBox::CloudBillboard> *v48; // [esp+Ch] [ebp-138h]
  std::vector<std::wstring> v49; // [esp+10h] [ebp-134h] BYREF
  SkyBox *v50; // [esp+1Ch] [ebp-128h]
  std::wstring *v51; // [esp+20h] [ebp-124h]
  char v52; // [esp+27h] [ebp-11Dh]
  std::vector<Texture> *v53; // [esp+28h] [ebp-11Ch]
  std::wstring *_Right; // [esp+2Ch] [ebp-118h]
  Texture _Val; // [esp+30h] [ebp-114h] BYREF
  INIReader v56; // [esp+4Ch] [ebp-F8h] BYREF
  std::wstring ifilename; // [esp+90h] [ebp-B4h] BYREF
  std::wstring filename; // [esp+A8h] [ebp-9Ch] BYREF
  std::wstring result; // [esp+C0h] [ebp-84h] BYREF
  std::_String_val<std::_Simple_types<wchar_t> >::_Bxty v60; // [esp+D8h] [ebp-6Ch] BYREF
  Texture v61; // [esp+E8h] [ebp-5Ch] BYREF
  std::wstring key; // [esp+104h] [ebp-40h] BYREF
  std::wstring section; // [esp+11Ch] [ebp-28h] BYREF
  int v64; // [esp+140h] [ebp-4h]

  v2 = this;
  v50 = this;
  v3 = weatherName;
  _Right = (std::wstring *)weatherName;
  if ( weatherName->_Myres >= 8 )
    v3 = (const std::wstring *)weatherName->_Bx._Ptr;
  _printf("Update Clouds Generation to %ls \n", v3->_Bx._Buf);
  v4 = &v2->clouds;
  v48 = &v2->clouds;
  std::_Container_base0::_Orphan_all(&v2->clouds);
  if ( v2->clouds._Myfirst != v2->clouds._Mylast )
  {
    v5 = v4->_Myfirst;
    v6 = v4->_Mylast;
    do
    {
      OnSetupAppCreated::~OnSetupAppCreated(&v5->texture);
      ++v5;
    }
    while ( v5 != v6 );
    v4 = v48;
    v2 = v50;
  }
  v4->_Mylast = v4->_Myfirst;
  v53 = &v2->cloudTextures;
  std::_Container_base0::_Orphan_all(&v2->cloudTextures);
  v7 = (int)v2->cloudTextures._Mylast;
  v8 = v2->cloudTextures._Myfirst;
  v51 = (std::wstring *)v7;
  if ( v8 != (Texture *)v7 )
  {
    v9 = (Texture *)v7;
    do
      OnSetupAppCreated::~OnSetupAppCreated(v8++);
    while ( v8 != v9 );
    v2 = v50;
  }
  v45 = _Right;
  v2->cloudTextures._Mylast = v2->cloudTextures._Myfirst;
  v10 = std::operator+<wchar_t>(&result, L"content/weather/", v45);
  v64 = 0;
  std::operator+<wchar_t>(&ifilename, v10, L"/weather.ini");
  LOBYTE(v64) = 2;
  if ( result._Myres >= 8 )
    operator delete(result._Bx._Ptr);
  result._Myres = 7;
  result._Bx._Buf[0] = 0;
  result._Mysize = 0;
  INIReader::INIReader(&v56, &ifilename);
  LOBYTE(v64) = 3;
  if ( v56.ready )
  {
    section._Myres = 7;
    section._Mysize = 0;
    section._Bx._Buf[0] = 0;
    std::wstring::assign(&section, L"CLOUDS", 6u);
    LOBYTE(v64) = 4;
    v11 = INIReader::hasSection(&v56, &section);
    v52 = v11;
    LOBYTE(v64) = 3;
    if ( section._Myres >= 8 )
    {
      operator delete(section._Bx._Ptr);
      v11 = v52;
    }
    if ( v11 )
    {
      std::wstring::wstring(&key, L"HEIGHT");
      LOBYTE(v64) = 5;
      std::wstring::wstring(&section, L"CLOUDS");
      LOBYTE(v64) = 6;
      v12 = INIReader::getFloat(&v56, &section, &key);
      v13 = section._Myres < 8;
      v2->settings.cloudHeight = v12;
      if ( !v13 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v64) = 3;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"WIDTH");
      LOBYTE(v64) = 7;
      std::wstring::wstring(&section, L"CLOUDS");
      LOBYTE(v64) = 8;
      v14 = INIReader::getFloat(&v56, &section, &key);
      v13 = section._Myres < 8;
      v2->settings.cloudWidth = v14;
      if ( !v13 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v64) = 3;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"RADIUS");
      LOBYTE(v64) = 9;
      std::wstring::wstring(&section, L"CLOUDS");
      LOBYTE(v64) = 10;
      v15 = INIReader::getFloat(&v56, &section, &key);
      v13 = section._Myres < 8;
      v2->settings.cloudRadius = v15;
      if ( !v13 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v64) = 3;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"NUMBER");
      LOBYTE(v64) = 11;
      std::wstring::wstring(&section, L"CLOUDS");
      LOBYTE(v64) = 12;
      v16 = INIReader::getFloat(&v56, &section, &key);
      v13 = section._Myres < 8;
      *(float *)&_Right = v16 * (float)((float)v2->graphics->videoSettings.worldDetail * 0.2);
      v2->settings.numberOfClouds = (int)*(float *)&_Right;
      if ( !v13 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v64) = 3;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      std::wstring::wstring(&key, L"BASE_SPEED_MULT");
      LOBYTE(v64) = 13;
      std::wstring::wstring(&section, L"CLOUDS");
      LOBYTE(v64) = 14;
      v17 = INIReader::getFloat(&v56, &section, &key);
      v13 = section._Myres < 8;
      v2->settings.baseSpeedMult = v17;
      if ( !v13 )
        operator delete(section._Bx._Ptr);
      section._Myres = 7;
      section._Mysize = 0;
      section._Bx._Buf[0] = 0;
      LOBYTE(v64) = 3;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
    }
  }
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  std::wstring::assign(&section, L"content/texture/clouds/*.dds", 0x1Cu);
  LOBYTE(v64) = 15;
  Path::getFiles(&v49, &section);
  LOBYTE(v64) = 17;
  if ( section._Myres >= 8 )
    operator delete(section._Bx._Ptr);
  v18 = v49._Myfirst;
  v19 = v49._Mylast;
  section._Myres = 7;
  section._Mysize = 0;
  section._Bx._Buf[0] = 0;
  if ( v49._Myfirst != v49._Mylast )
  {
    do
    {
      key._Myres = 7;
      key._Mysize = 0;
      key._Bx._Buf[0] = 0;
      std::wstring::assign(&key, v18, 0, 0xFFFFFFFF);
      LOBYTE(v64) = 18;
      std::operator+<wchar_t>(&filename, L"content/texture/clouds/", &key);
      LOBYTE(v64) = 19;
      ResourceStore::getTexture(v50->graphics->resourceStore._Myptr, &_Val, &filename, 0);
      LOBYTE(v64) = 20;
      std::vector<Texture>::push_back(v53, &_Val);
      LOBYTE(v64) = 19;
      OnSetupAppCreated::~OnSetupAppCreated(&_Val);
      if ( filename._Myres >= 8 )
        operator delete(filename._Bx._Ptr);
      LOBYTE(v64) = 17;
      if ( key._Myres >= 8 )
        operator delete(key._Bx._Ptr);
      ++v18;
    }
    while ( v18 != v19 );
    v18 = v49._Myfirst;
  }
  v20 = v50;
  v21 = FLOAT_0_5;
  v53 = 0;
  if ( v50->settings.numberOfClouds )
  {
    while ( 1 )
    {
      v61.kid = 0;
      v61.fileName._Myres = 7;
      v60 = 0i64;
      v61.fileName._Mysize = 0;
      v61.fileName._Bx._Buf[0] = 0;
      LOBYTE(v64) = 21;
      *(float *)&v60._Alias[4] = (float)((float)((float)((float)((float)((float)_rand() * 0.000030518509) - 0.5) * 10.0)
                                               + (float)(360.0 / (float)v20->settings.numberOfClouds))
                                       * 0.017453)
                               * (float)(unsigned int)v53;
      v22 = _rand();
      v53 = (std::vector<Texture> *)((char *)v53 + 1);
      *(float *)&_Right = (float)v22 * 0.000030518509;
      v23 = _rand();
      v24 = (double)((unsigned int)v53 % 5) + 0.0;
      *(float *)&v25 = ((float)((float)((float)((float)v23 * 0.000030518509) - 0.5) * 5.0) + 15.0)
                     * 0.01745299994945526
                     * v24
                     + ((float)(*(float *)&_Right - 0.5) * 30.0 + 20.0) * 0.01745299994945526;
      v60._Ptr = v25;
      v26 = 1.0 - __libm_sse2_cosf(v46, v47).m128_f32[0];
      v27 = v20->settings.baseSpeedMult;
      *(float *)&v60._Alias[8] = (float)(v26 * 4.0) + v20->settings.cloudRadius;
      if ( v27 == 0.0 )
      {
        *(_DWORD *)&v60._Alias[12] = 0;
      }
      else
      {
        v28 = v20->settings.baseSpeedMult * (float)((float)_rand() * 0.000030518509);
        if ( v28 <= 1.0 )
        {
          if ( v28 >= 0.00050000002 )
            *(float *)&v60._Alias[12] = v28;
          else
            *(_DWORD *)&v60._Alias[12] = 973279855;
        }
        else
        {
          *(_DWORD *)&v60._Alias[12] = 1065353216;
        }
      }
      v29 = (unsigned int)(float)((float)(unsigned int)(v20->cloudTextures._Mylast - v20->cloudTextures._Myfirst)
                                * (float)((float)_rand() * 0.000030518509));
      v30 = v20->cloudTextures._Myfirst;
      v61.kid = v30[v29].kid;
      v31 = &v30[v29].fileName;
      if ( &v61.fileName != v31 )
        std::wstring::assign(&v61.fileName, v31, 0, 0xFFFFFFFF);
      v32 = v48->_Mylast;
      if ( &v60 >= (std::_String_val<std::_Simple_types<wchar_t> >::_Bxty *)v32
        || v48->_Myfirst > (SkyBox::CloudBillboard *)&v60 )
      {
        if ( v32 == v48->_Myend )
          std::vector<SkyBox::CloudBillboard>::_Reserve(v48, 1u);
        v39 = (std::wstring *)v48->_Mylast;
        _Right = v39;
        v51 = v39;
        LOBYTE(v64) = 23;
        if ( !v39 )
          goto LABEL_67;
        v39->_Bx = v60;
        v39->_Mysize = (unsigned int)v61.kid;
        v37 = (std::wstring *)&v39->_Myres;
        v37->_Myres = 7;
        v37->_Mysize = 0;
        v37->_Bx._Buf[0] = 0;
        v38 = &v61.fileName;
      }
      else
      {
        v33 = v48->_Mylast;
        v34 = (std::wstring *)(((char *)&v60 - (char *)v48->_Myfirst) / 44);
        _Right = v34;
        if ( v33 == v48->_Myend )
        {
          std::vector<SkyBox::CloudBillboard>::_Reserve(v48, 1u);
          v34 = _Right;
        }
        v35 = (int)v48->_Mylast;
        _Right = (std::wstring *)v35;
        v51 = (std::wstring *)v35;
        v36 = (_DWORD *)&v48->_Myfirst[(_DWORD)v34].theta_rad;
        LOBYTE(v64) = 22;
        if ( !v35 )
          goto LABEL_67;
        *(_DWORD *)v35 = *v36;
        *(_DWORD *)(v35 + 4) = v36[1];
        *(_DWORD *)(v35 + 8) = v36[2];
        *(_DWORD *)(v35 + 12) = v36[3];
        *(_DWORD *)(v35 + 16) = v36[4];
        v37 = (std::wstring *)(v35 + 20);
        v37->_Myres = 7;
        v37->_Mysize = 0;
        v37->_Bx._Buf[0] = 0;
        v38 = (std::wstring *)(v36 + 5);
      }
      std::wstring::assign(v37, v38, 0, 0xFFFFFFFF);
LABEL_67:
      ++v48->_Mylast;
      LOBYTE(v64) = 17;
      OnSetupAppCreated::~OnSetupAppCreated(&v61);
      if ( (unsigned int)v53 >= v20->settings.numberOfClouds )
      {
        v18 = v49._Myfirst;
        v21 = FLOAT_0_5;
        break;
      }
    }
  }
  v40 = (__m128)LODWORD(v20->settings.cloudHeight);
  v41 = (__m128)LODWORD(v20->settings.cloudWidth);
  v40.m128_f32[0] = v40.m128_f32[0] * v21;
  v41.m128_f32[0] = v41.m128_f32[0] * v21;
  if ( v40.m128_f32[0] <= v41.m128_f32[0] )
    v42 = v41.m128_i32[0];
  else
    v42 = v40.m128_i32[0];
  section._Myres = 0;
  *(_QWORD *)&v20->commonBoundingSphere.center.x = _mm_unpacklo_ps(v41, v40).m128_u64[0];
  LODWORD(v20->commonBoundingSphere.radius) = v42;
  v20->commonBoundingSphere.center.z = 0.0;
  LOBYTE(v64) = 3;
  if ( v18 )
  {
    std::_Container_base0::_Orphan_all(&v49);
    v43 = v49._Mylast;
    v44 = v49._Myfirst;
    if ( v49._Myfirst != v49._Mylast )
    {
      do
      {
        if ( v44->_Myres >= 8 )
          operator delete(v44->_Bx._Ptr);
        v44->_Myres = 7;
        v44->_Mysize = 0;
        v44->_Bx._Buf[0] = 0;
        ++v44;
      }
      while ( v44 != v43 );
      v44 = v49._Myfirst;
    }
    operator delete(v44);
    v49._Myfirst = 0;
    v49._Mylast = 0;
    v49._Myend = 0;
  }
  LOBYTE(v64) = 2;
  INIReader::~INIReader(&v56);
  if ( ifilename._Myres >= 8 )
    operator delete(ifilename._Bx._Ptr);
}
